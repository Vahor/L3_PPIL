//
// Created by Nathan David on 02/02/2022.
//

#include "shapes/Polygon.h"

DataElement *Polygon::toDataElement0(bool ignoreGroup) const {
    auto *object = new DataObject();

    auto data = DataObject();
    auto pointsArray = DataArray();

    for (Point2D *point: points) {
        pointsArray.add(point->toDataElement(ignoreGroup));
    }

    data.put("points", pointsArray);
    object->put("POLYGON", data);

    return object;
}
string Polygon::toString() const {
    string res = "Polygon[points=[";
    for (auto *point: points) {
        res += point->toString();
        res += ",";
    }

    if (!points.empty())
        // On garde la dernière ","
        res.pop_back();

    res += "],";
    res += Shape::getMetaString();
    res += "]";
    return res;
}
Point2D *Polygon::getCenter() const {
    double sumX = 0;
    double sumY = 0;
    auto size = (double) points.size();
    for (Point2D *point: points) {
        sumX += point->getX();
        sumY += point->getY();
    }
    return new Point2D(sumX / size, sumY / size);
}
double Polygon::getArea() const {
    // Décomposition en triangles
    // Puis somme des aires des triangles
    double res = 0;
    // forme ABCDE
    // on a triangles : ABC ACD ADE
    if (points.size() < 3) return res;

    Point2D *anchor = points[0];
    for (int i = 1; i < points.size() - 1; i++) {
        res += Triangle(anchor, points[i], points[i + 1]).getArea();
    }

    return res;
}
