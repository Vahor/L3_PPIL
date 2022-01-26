//
// Created by Nathan David on 11/12/2021.
//

#pragma once

#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class BorderColorHandler : public CORHandler<pair<DataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<DataObject *, Shape *> &source) const override {
        if (source.first->has("borderColor")) {
            DataObject *color = source.first->get("borderColor")->getAsObject();
            source.second->setBorderColor(new Color(
                    color->get("r")->getAsPrimitive()->getAsInt(),
                    color->get("g")->getAsPrimitive()->getAsInt(),
                    color->get("b")->getAsPrimitive()->getAsInt(),
                    color->get("a")->getAsPrimitive()->getAsInt()
            ));
        }
        return nullptr;
    }


public:
    explicit BorderColorHandler(Handler<pair<DataObject *, Shape *>, Shape *> *suivant) : CORHandler(suivant) {}


};



