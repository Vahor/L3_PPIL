//
// Created by Nathan David on 02/12/2021.
//

#pragma once

#include <string>
#include <vector>
#include "shapes/Shape.h"
#include "handler/Handler.h"
#include "client/Client.h"

using std::string;
using std::vector;

class Scene : public Serializable {


    string name;
    int height = 500;
    int width = 900;
    vector<Shape *> shapes;

protected:
    void add2(Shape *shape) {
        if (shape->getId() == 0) shape->setId(Shape::nextId());
        shapes.push_back(shape->clone());
    }

public:
    Scene() = default;

    Scene(const Scene &copy) {
        for (auto &shape: copy.shapes) {
            add(shape);
        }
        this->name = copy.name;
        this->height = copy.height;
        this->width = copy.width;
    }

    static Scene *parse(const DataObject &object,
                        const Handler<DataObject, Shape *> *shapeHandler,
                        const Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler
    ) {

        DataObject *window = object.get("window")->getAsObject();
        auto *scene = new Scene();

        scene->setName(window->get("name")->getAsPrimitive()->getAsString());
        scene->setHeight(window->get("height")->getAsPrimitive()->getAsInt());
        scene->setWidth(window->get("width")->getAsPrimitive()->getAsInt());

        DataArray *items = object.get("items")->getAsArray();
        for (DataElement *element: *items) {
            DataObject *elementObject = element->getAsObject();
            Shape *shape = Shape::parse(*elementObject, shapeHandler, metaHandler);
            if (shape != nullptr) scene->add2(shape);
        }

        return scene;
    }

    virtual ~Scene() {
        cerr << "delete AScene" << endl;
        // todo
    }

    virtual Scene *clone() const {
        return new Scene(*this);
    }

    DataElement *serialize0(bool ignoreGroup) const override {

        auto *object = new DataObjectImpl();
        auto *window = new DataObjectImpl();
        auto *items = new DataArrayImpl();

        window->put("name", new DataPrimitiveImpl(getName()));
        window->put("height", new DataPrimitiveImpl(getHeight()));
        window->put("width", new DataPrimitiveImpl(getWidth()));

        for (auto &shape: shapes) {
            items->add(shape->serialize(ignoreGroup));
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
    const string &getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }



    // Iterator

    auto begin() { return &shapes[0]; }
    auto end() { return &shapes[shapes.size()]; }
    auto begin() const { return &shapes[0]; }
    auto end() const { return &shapes[shapes.size()]; }

};



