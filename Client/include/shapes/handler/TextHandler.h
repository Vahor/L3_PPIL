//
// Created by Nathan David on 03/12/2021.
//

#pragma once

#include "shapes/Text.h"
#include "api/shape/Shape.h"
#include "api/handler/CORHandler.h"

class TextHandler : public CORHandler<DataObject, Shape *> {


protected:

    Shape *parse(const DataObject &input) const override {
        if (!input.has("TEXT")) return nullptr;

        DataObject *object = input.get("TEXT")->getAsObject();


        DataObject *position = object->get("position")->getAsObject();

        double x = position->get("x")->getAsPrimitive()->getAsDouble();
        double y = position->get("y")->getAsPrimitive()->getAsDouble();

        int size = object->get("size")->getAsPrimitive()->getAsInt();
        string value = object->get("value")->getAsPrimitive()->getAsString();


        double angle = object->get("angle")->getAsPrimitive()->getAsDouble();

        return new Text({x, y}, size, value, angle);
    }

public:
    explicit TextHandler(Handler<DataObject, Shape *> *suivant) : CORHandler(suivant) {}
};



