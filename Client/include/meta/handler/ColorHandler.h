//
// Created by Nathan David on 05/12/2021.
//

#pragma once

#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class ColorHandler : public CORHandler<pair<DataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<DataObject *, Shape *> &source) const override {
        if (source.first->has("color")) {
            DataObject *color = source.first->get("color")->getAsObject();
            source.second->setColor(new Color(
                    color->get("r")->getAsPrimitive()->getAsInt(),
                    color->get("g")->getAsPrimitive()->getAsInt(),
                    color->get("b")->getAsPrimitive()->getAsInt(),
                    color->get("a")->getAsPrimitive()->getAsInt()
            ));
        }
        return nullptr;
    }


public:
    explicit ColorHandler(Handler<pair<DataObject *, Shape *>, Shape *> *suivant) : CORHandler(suivant) {}

};



