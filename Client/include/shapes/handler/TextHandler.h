//
// Created by Nathan David on 03/12/2021.
//

#pragma once

#include "shapes/Text.h"
#include "shapes/Shape.h"
#include "handler/CORHandler.h"

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


        double radians = object->get("radians")->getAsPrimitive()->getAsDouble();

        return new Text(Point2D(x, y), size, value, radians);
    }

public:
    explicit TextHandler(Handler<DataObject, Shape *> *suivant) : CORHandler(suivant) {}
};



