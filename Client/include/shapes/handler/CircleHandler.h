//
// Created by Nathan David on 03/12/2021.
//

#pragma once

#include "shapes/Circle.h"
#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class CircleHandler : public CORHandler<DataObject, Shape *> {


protected:

    Shape *parse(const DataObject &input) const override {
        if (!input.has("CIRCLE")) return nullptr;

        DataObject *object = input.get("CIRCLE")->getAsObject();

        double diameter = object->get("diameter")->getAsPrimitive()->getAsDouble();

        DataObject *position = object->get("position")->getAsObject();

        double x = position->get("x")->getAsPrimitive()->getAsDouble();
        double y = position->get("y")->getAsPrimitive()->getAsDouble();

        return new Circle({x, y}, diameter);
    }

public:
    explicit CircleHandler(Handler<DataObject, Shape *> *suivant) : CORHandler(suivant) {}
};



