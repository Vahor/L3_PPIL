//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_SHAPEHANDLER_H
#define CLIENT_SHAPEHANDLER_H

#include "shapes/Circle.h"
#include "shapes/Shape.h"
#include "json/JsonArray.h"
#include "handler/ACORHandler.h"

class ShapeHandler : public ACORHandler<JsonObject, Shape *> {

protected:

    Shape *parse(const JsonObject &line) const override {
        JsonObject circle = line.get("CIRCLE")->getAsJsonObject();

        int diameter = circle.get("diameter")->getAsJsonPrimitive()->getAsInt();
        int x = circle.get("x")->getAsJsonPrimitive()->getAsInt();
        int y = circle.get("y")->getAsJsonPrimitive()->getAsInt();

        return new Circle(x, y, diameter);
    }
};


#endif //CLIENT_SHAPEHANDLER_H
