//
// Created by Nathan David on 05/12/2021.
//

#pragma once

#include "shapes/Polygon.h"
#include "api/shape/Shape.h"
#include "api/handler/CORHandler.h"

class PolygonHandler : public CORHandler<DataObject, Shape *> {

protected:

    Shape *parse(const DataObject &input) const override {
        if (!input.has("POLYGON")) return nullptr;
        DataObject *object = input.get("POLYGON")->getAsObject();

        auto *polygon = new Polygon();

        DataArray *points = object->get("points")->getAsArray();

        for (DataElement *element: *points) {
            double x = element->getAsObject()->get("x")->getAsPrimitive()->getAsDouble();
            double y = element->getAsObject()->get("y")->getAsPrimitive()->getAsDouble();
            polygon->addPoint(new Point2D(x, y));
        }

        return polygon;
    }


public:
    explicit PolygonHandler(Handler<DataObject, Shape *> *suivant) : CORHandler(suivant) {}

};



