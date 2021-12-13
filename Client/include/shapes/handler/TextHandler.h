//
// Created by Nathan David on 03/12/2021.
//

#ifndef CLIENT_TEXTHANDLER_H
#define CLIENT_TEXTHANDLER_H

#include "shapes/Text.h"
#include "api/shape/AShape.h"
#include "api/handler/ACORHandler.h"

class TextHandler : public ACORHandler<ADataObject, AShape *> {


protected:

    AShape *parse(const ADataObject &input) const override {
        if (!input.has("TEXT")) return nullptr;

        ADataObject *object = input.get("TEXT")->getAsObject();


        ADataObject *position = object->get("position")->getAsObject();

        double x = position->get("x")->getAsPrimitive()->getAsDouble();
        double y = position->get("y")->getAsPrimitive()->getAsDouble();

        int size = object->get("size")->getAsPrimitive()->getAsInt();
        string value = object->get("value")->getAsPrimitive()->getAsString();

        return new Text({x, y}, size, value);
    }

public:
    explicit TextHandler(Handler<ADataObject, AShape *> *suivant) : ACORHandler(suivant) {}
};


#endif //CLIENT_TEXTHANDLER_H
