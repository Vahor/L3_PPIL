//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_CIRCLEHANDLER_H
#define CLIENT_CIRCLEHANDLER_H

#include "shapes/Circle.h"
#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class CircleHandler : public ACORHandler<ADataObject, AShape *> {


protected:

    AShape *parse(const ADataObject &input) const override {
        if (!input.has("CIRCLE")) return nullptr;

        ADataObject *object = input.get("CIRCLE")->getAsObject();

        double diameter = object->get("diameter")->getAsPrimitive()->getAsDouble();

        ADataObject *position = object->get("position")->getAsObject();

        double x = position->get("x")->getAsPrimitive()->getAsDouble();
        double y = position->get("y")->getAsPrimitive()->getAsDouble();

        return new Circle({x, y}, diameter);
    }

public:
    explicit CircleHandler(Handler<ADataObject, AShape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_CIRCLEHANDLER_H
