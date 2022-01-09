//
// Created by Nathan David on 13/12/2021.
//

#pragma once


#include "api/shape/Shape.h"
#include "api/Point2D.h"
#include "data/DataImpl.h"
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

    DataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        auto *pointsArray = new DataArrayImpl();

        for (Point2D *point: points) {
            pointsArray->add(point->serialize());
        }

        data->put("points", pointsArray);
        object->put("POLYGON", data);

        Shape::addMetaData(object);

        return object;
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


