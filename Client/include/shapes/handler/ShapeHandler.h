//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_SHAPEHANDLER_H
#define CLIENT_SHAPEHANDLER_H

#include "shapes/Circle.h"
#include "shapes/Shape.h"
#include "handler/ACORHandler.h"

class ShapeHandler : public ACORHandler<ADataObject, Shape *> {

protected:

    Shape *parse(const ADataObject &line) const override {
        ADataObject* circle = line.get("CIRCLE")->getAsObject();

        int diameter = circle->get("diameter")->getAsPrimitive()->getAsInt();
        int x = circle->get("x")->getAsPrimitive()->getAsInt();
        int y = circle->get("y")->getAsPrimitive()->getAsInt();

        return new Circle(x, y, diameter);
    }
};


#endif //CLIENT_SHAPEHANDLER_H
