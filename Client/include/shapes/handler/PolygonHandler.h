//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_POLYGONHANDLER_H
#define CLIENT_POLYGONHANDLER_H

#include "shapes/Polygon.h"
#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class PolygonHandler : public ACORHandler<ADataObject, AShape *> {

protected:

    AShape *parse(const ADataObject &input) const override {
        if (!input.has("POLYGON")) return nullptr;
        ADataObject *object = input.get("POLYGON")->getAsObject();

        auto *polygon = new Polygon();

        ADataArray *points = object->get("points")->getAsArray();

        for (ADataElement *element: *points) {
            double x = element->getAsObject()->get("x")->getAsPrimitive()->getAsDouble();
            double y = element->getAsObject()->get("y")->getAsPrimitive()->getAsDouble();
            polygon->addPoint(new Point2D(x, y));
        }

        return polygon;
    }


public:
    explicit PolygonHandler(Handler<ADataObject, AShape *> *suivant) : ACORHandler(suivant) {}

};


#endif //CLIENT_POLYGONHANDLER_H
