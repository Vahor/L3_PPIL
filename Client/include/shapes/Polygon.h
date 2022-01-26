//
// Created by Nathan David on 13/12/2021.
//

#pragma once


#include "shapes/Shape.h"
#include "Point2D.h"
#include <cmath>
#include <vector>

class Polygon : public Shape {

    std::vector<Point2D *> points;

public:

    Polygon() : Shape() {}
    ~Polygon() override {
        cerr << "Todo PolyGon destruct" << endl;
    }

    void addPoint(const Point2D *point) {
        points.push_back(point->clone());
    }

    void removePoint(const Point2D *point) {
        points.erase(std::find(points.begin(), points.end(), point));
    }

    DataElement *serialize0(bool ignoreGroup) const override {
        auto *object = new DataObject();

        auto *data = new DataObject();
        auto *pointsArray = new DataArray();

        for (Point2D *point: points) {
            pointsArray->add(point->serialize());
        }

        data->put("points", pointsArray);
        object->put("POLYGON", data);

        return object;
    }

    string toString() const override {
        string res = "Polygon[";
        for (auto *point: points) {
            res += point->toString();
            res += ","; // On garde la dernière "," pour le Shape::_toString()
        }

        res += Shape::_toString();
        res += "]";
        return res;
    }

    Polygon *clone() const override {
        return new Polygon(*this);
    }

    Point2D *getCenter() const override {
        double sumX = 0;
        double sumY = 0;
        auto size = (double) points.size();
        for (Point2D *point: points) {
            sumX += point->getX();
            sumY += point->getY();
        }
        return new Point2D(sumX / size, sumY / size);
    }

    double getArea() const override {
        return 0;
    }

    void scale(int scale) override {
        // todo
    }

    void translate(double x, double y) override {
        for (Point2D *point: points) {
            point->setX(point->getX() + x);
            point->setY(point->getY() + y);
        }
    }

    void rotate(const Point2D &center, double deg) override {
        for (Point2D *point: points) {
            point->rotate(center, deg);
        }
    }
};


