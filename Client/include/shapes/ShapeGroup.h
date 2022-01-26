//
// Created by Nathan David on 26/01/2022.
//

#pragma once

#include "Shape.h"
#include "data/DataArray.h"
#include <vector>

class ShapeGroup : public Shape {

    std::vector<Shape *> elements;

public:

    ShapeGroup() : Shape() {}
    ShapeGroup(const ShapeGroup &copy) : Shape(copy) {
        for (const auto &it: copy.elements) { addShape(it->clone()); }
    }

    void addShape(Shape *shape) {
        elements.push_back(shape);
        shape->setGroup(this);
    }

    void removeShape(Shape *shape) {
        elements.erase(std::find(elements.begin(), elements.end(), shape));
    }

    DataElement *serialize0(bool ignoreGroup) const override {
        auto *object = new DataObject();

        auto *data = new DataObject();
        auto *items = new DataArray();

        for (Shape *shape: elements) {
            items->add(shape->serialize(ignoreGroup));
        }

        data->put("items", items);

        object->put("GROUP", data);

        return object;
    }

    string toString() const override {
        string res = "ShapeGroup[";
        for (auto *shape: elements) {
            res += "\n\t\t";
            res += shape->toString();
        }
        if (!elements.empty())
            res += "\n\t";
        res += "]";
        return res;
    }

    ShapeGroup *clone() const override {
        return new ShapeGroup(*this);
    }

    Point2D *getCenter() const override {
        return new Point2D(0, 0); // todo
    }

    double getArea() const override {
        double res = 0;
        for (Shape *shape: elements) {
            res += shape->getArea();
        }
        return res;
    }

    void scale(int scale) override {
        for (Shape *shape: elements) {
            shape->scale(scale);
        }
    }

    void translate(double x, double y) override {
        for (Shape *shape: elements) {
            shape->translate(x, y);
        }
    }

    void rotate(const Point2D &center, double deg) override {
        for (Shape *shape: elements) {
            shape->rotate(center, deg);
        }
    }


    // Iterator

    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }

};


