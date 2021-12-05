//
// Created by Nathan David on 05/12/2021.
//

#ifndef CLIENT_POLYGONHANDLER_H
#define CLIENT_POLYGONHANDLER_H

#include "shapes/Circle.h"
#include "api/shape/Shape.h"
#include "api/handler/ACORHandler.h"

class PolygonHandler : public ACORHandler<ADataObject, Shape*> {

protected:

    Shape *parse(const ADataObject &source) const override {
        string type = source.get("type")->getAsPrimitive()->getAsString();
        ADataObject *circle = source.get("CIRCLE")->getAsObject();

        int diameter = circle->get("diameter")->getAsPrimitive()->getAsInt();
        int x = circle->get("x")->getAsPrimitive()->getAsInt();
        int y = circle->get("y")->getAsPrimitive()->getAsInt();

        ADataObject *color = circle->get("color")->getAsObject();

        auto *res = new Circle(x, y, diameter);
        res->setColor(Color(
                color->get("r")->getAsPrimitive()->getAsInt(),
                color->get("g")->getAsPrimitive()->getAsInt(),
                color->get("b")->getAsPrimitive()->getAsInt()
        ));
        return res;
    }

};


#endif //CLIENT_POLYGONHANDLER_H
