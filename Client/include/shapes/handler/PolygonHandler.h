//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_POLYGONHANDLER_H
#define CLIENT_POLYGONHANDLER_H

#include "shapes/Circle.h"
#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class PolygonHandler : public ACORHandler<ADataObject, AShape *> {

protected:

    AShape *parse(const ADataObject &input) const override {
        if (!input.has("POLYGON")) return nullptr;
        ADataObject *object = input.get("POLYGON")->getAsObject();

        int diameter = object->get("diameter")->getAsPrimitive()->getAsInt();

        ADataObject *position = object->get("position")->getAsObject();

        double x = position->get("x")->getAsPrimitive()->getAsDouble();
        double y = position->get("y")->getAsPrimitive()->getAsDouble();

        return new Circle({x, y}, diameter);
    }


public:
    explicit PolygonHandler(Handler<ADataObject, AShape *> *suivant) : ACORHandler(suivant) {}

};


#endif //CLIENT_POLYGONHANDLER_H
