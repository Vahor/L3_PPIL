//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_ASCENE_H
#define CLIENT_ASCENE_H

#include <string>
#include <vector>
#include "api/shape/Shape.h"
#include "api/handler/Handler.h"

using namespace std;

class AScene {


    string name;
    int height = 500;
    int width = 900;
    vector<Shape *> shapes;

protected:
    void add2(Shape *shape) {
        shapes.push_back(shape->clone());
    }

public:
    AScene() = default;

    AScene(const AScene &copy) {
        for (auto &shape: copy.shapes) {
            add(shape);
        }
        this->name = copy.name;
        this->height = copy.height;
        this->width = copy.width;
    }

    static AScene *parse(const ADataObject &object,
                         const Handler<ADataObject, Shape *> *shapeHandler,
                         const Handler<pair<ADataObject *, Shape *>, Shape *> *metaHandler
    ) {

        ADataObject *window = object.get("window")->getAsObject();
        auto *scene = new AScene();

        scene->setName(window->get("name")->getAsPrimitive()->getAsString());
        scene->setHeight(window->get("height")->getAsPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsPrimitive()->getAsInt());

        ADataArray *items = object.get("items")->getAsArray();
        for (ADataElement *element: *items) {
            ADataObject *elementObject = element->getAsObject();
            Shape *shape = shapeHandler->solve(*element->getAsObject());
            if (shape != nullptr) {
                if (elementObject->has("meta")) {
                    ADataObject *elementMeta = elementObject->get("meta")->getAsObject();
                    metaHandler->solve({elementMeta, shape});
                }
                scene->add2(shape);
            }
        }

        return scene;
    }

    virtual ~AScene() {
        cerr << "delete AScene" << endl;
        // todo
    }

    virtual AScene *clone() const {
        return new AScene(*this);
    }

    virtual ADataElement *serialize() const {

        auto *object = new DataObjectImpl();
        auto *window = new DataObjectImpl();
        auto *items = new DataArrayImpl();

        window->put("name", new DataPrimitiveImpl(getName()));
        window->put("height", new DataPrimitiveImpl(getHeight()));
        window->put("width", new DataPrimitiveImpl(getWidth()));

        for (auto &shape: shapes) {
            items->add(shape->serialize());
        }

        object->put("window", window);
        object->put("items", items);

        return object;
    };

    void add(Shape *shape) {
        add2(shape->clone());
    }

    // Setters
    void setHeight(int _height) { this->height = _height; }
    void setWidth(int _width) { this->width = _width; }
    void setName(const string &_name) { this->name = _name; }

    // Getters
    string getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }


    // Iterator

    auto begin() { return &shapes[0]; }
    auto end() { return &shapes[shapes.size()]; }
    auto begin() const { return &shapes[0]; }
    auto end() const { return &shapes[shapes.size()]; }

};


#endif //CLIENT_ASCENE_H
