//
// Created by Nathan David on 02/12/2021.
//

#pragma once

#include <string>
#include <vector>
#include "actions/Visitor.h"
#include "handler/Handler.h"
#include "client/Client.h"

#include "data/DataObject.h"
#include "data/DataArray.h"
#include "data/DataPrimitive.h"

#include "shapes/Shape.h"
#include "shapes/ShapeGroup.h"

using namespace std;

class Scene : public Serializable {

    string name;
    int height = 500;
    int width = 900;
    vector<Shape *> shapes;

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
            if (shape != nullptr) scene->add(shape);
        }

        return scene;
    }

    virtual ~Scene() {
        shapes.clear();
    }

    virtual Scene *clone() const {
        return new Scene(*this);
    }

    DataElement *serialize0(bool ignoreGroup) const override {

        auto *object = new DataObject();
        auto *window = new DataObject();

        window->put("name", new DataPrimitive(getName()));
        window->put("height", new DataPrimitive(getHeight()));
        window->put("width", new DataPrimitive(getWidth()));

        auto *items = new DataArray();
        for (auto &shape: shapes) {
            items->add(shape->serialize(ignoreGroup));
        }

        object->put("window", window);
        object->put("items", items);

        return object;
    };

    void add(Shape *shape) {
        shapes.push_back(shape->clone());
    }

    virtual void draw(Visitor &visitor) const {
        visitor.drawScene(this);
    }

    Shape *getShapeById(int id) {
        for (Shape *shape: shapes) {
            if (auto *group = dynamic_cast<const ShapeGroup *>(shape)) {
                if (group->getId() == id) return shape;
                for (Shape *inGroupShape: *group) {
                    if (inGroupShape->getId() == id) return inGroupShape;
                }
            } else {
                if (shape->getId() == id) return shape;
            }
        }
        return nullptr;
    }

    // Setters
    void setHeight(int _height) { this->height = _height; }
    void setWidth(int _width) { this->width = _width; }
    void setName(const string &_name) { this->name = _name; }

    // Getters
    const string &getName() const { return name; }
    int getHeight() const { return height; }
    int getWidth() const { return width; }

    double getArea() const {
        double res = 0;
        for (auto shape: shapes) {
            res += shape->getArea();
        }
        return res;
    }



    // Iterator

    auto begin() { return &shapes[0]; }
    auto end() { return &shapes[shapes.size()]; }
    auto begin() const { return &shapes[0]; }
    auto end() const { return &shapes[shapes.size()]; }

};



