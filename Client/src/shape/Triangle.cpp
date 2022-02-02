//
// Created by Nathan David on 02/02/2022.
//


#include "shapes/Triangle.h"

DataElement *Triangle::toDataElement0(bool ignoreGroup) const {
    auto *object = new DataObject();

    auto data = DataObject();
    auto pointsArray = DataArray();

    for (Point2D *point: points) {
        pointsArray.add(point->toDataElement(ignoreGroup));
    }

    data.put("points", pointsArray);
    object->put("TRIANGLE", data);

    return object;
}

string Triangle::toString() const {
    string res = "Triangle[";
    for (auto *point: points) {
        res += point->toString();
        res += ","; // On garde la dernière "," pour le Shape::_toString()
    }

    res += Shape::getMetaString();
    res += "]";
    return res;
}

Point2D *Triangle::getCenter() const {
    double sumX = 0;
    double sumY = 0;
    for (Point2D *point: points) {
        sumX += point->getX();
        sumY += point->getY();
    }
    return new Point2D(sumX / 3, sumY / 3);
}
