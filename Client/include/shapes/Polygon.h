//
// Created by Nathan David on 13/12/2021.
//

#ifndef CLIENT_POLYGON_H
#define CLIENT_POLYGON_H


#include "api/shape/AShape.h"
#include "api/Point2D.h"
#include "data/DataImpl.h"
#include <cmath>
#include <vector>

class Polygon : public AShape {

    std::vector<Point2D *> points;

public:

    Polygon() : AShape() {}
    ~Polygon() {
        cerr << "Todo PolyGon destruct" << endl;
    }

    void addPoint(const Point2D *point) {
        points.push_back(point->clone());
    }

    void removePoint(const Point2D *point) {
        points.erase(std::find(points.begin(), points.end(), point));
    }

    ADataElement *serialize() const override {
        auto *object = new DataObjectImpl();

        auto *data = new DataObjectImpl();
        auto *pointsArray = new DataArrayImpl();

        for (Point2D *point: points) {
            pointsArray->add(point->serialize());
        }

        data->put("points", pointsArray);
        object->put("POLYGON", data);

        AShape::addMetaData(object);

        return object;
    }

    Polygon *clone() const override {
        return new Polygon(*this);
    }

    double getArea() const override {
        return 0;
    }
};

#endif //CLIENT_POLYGON_H
