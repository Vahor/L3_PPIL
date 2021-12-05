//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_CIRCLEHANDLER_H
#define CLIENT_CIRCLEHANDLER_H

#include "shapes/Circle.h"
#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class CircleHandler : public ACORHandler<ADataObject, Shape *> {


protected:

    Shape *parse(const ADataObject &source) const override {
        if(!source.has("CIRCLE")) return nullptr;

        ADataObject *circle = source.get("CIRCLE")->getAsObject();

        int diameter = circle->get("diameter")->getAsPrimitive()->getAsInt();
        int x = circle->get("x")->getAsPrimitive()->getAsInt();
        int y = circle->get("y")->getAsPrimitive()->getAsInt();

        return new Circle(x, y, diameter);
    }

public:
    explicit CircleHandler(Handler<ADataObject, Shape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_CIRCLEHANDLER_H
