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

    ~ShapeGroup() override {
        for (const auto &item: elements)
            item->setGroup(nullptr);
        elements.clear();
    }

    ShapeGroup() : Shape() {}
    ShapeGroup(const ShapeGroup &copy) : Shape(copy) {
        for (const auto &it: copy.elements) { addShape(it->clone()); }
    }

    /**
     * Ajoute une forme dans ce groupe.<br />
     * Et enregistre une referencence du groupe sur la forme.
     *
     * @param shape La forme à ajouter dans le groupe
     */
    void addShape(Shape *shape) {
        elements.push_back(shape);
        shape->setGroup(this);
    }

    /**
     * Retire une forme de ce groupe.<br />
     * Et retire la referencence du groupe sur la forme.
     *
     * @param shape La forme à retirer de ce le groupe
     */
    void removeShape(Shape *shape) {
        elements.erase(std::find(elements.begin(), elements.end(), shape));
        shape->resetGroup();
    }

    DataElement *toDataElement0(bool ignoreGroup) const override;

    string toString() const override {
        string res = "ShapeGroup[items=[";
        for (auto *shape: elements) {
            res += "\n\t";
            res += shape->toString();
        }
        res += "\n]," + Shape::getMetaString();
        res += "]";
        return res;
    }

    ShapeGroup *clone() const override {
        return new ShapeGroup(*this);
    }

    size_t size() const {
        return elements.size();
    }

    Point2D *getCenter() const override;

    double getArea() const override {
        double res = 0;
        for (Shape *shape: elements) {
            res += shape->getArea();
        }
        return res;
    }

    void zoom(const Point2D &center, double scale) override {
        for (Shape *shape: elements) {
            shape->zoom(center, scale);
        }
    }

    void scale(double scale) override {
        for (Shape *shape: elements) {
            shape->scale(scale);
        }
    }

    void translate(double x, double y) override {
        for (Shape *shape: elements) {
            shape->translate(x, y);
        }
    }

    void rotate(const Point2D &center, double radians) override {
        for (Shape *shape: elements) {
            shape->rotate(center, radians);
        }
    }


    // Iterator

    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }

};


