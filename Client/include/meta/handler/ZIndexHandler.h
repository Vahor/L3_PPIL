//
// Created by Nathan David on 11/12/2021.
//

#pragma once


#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class ZIndexHandler : public CORHandler<pair<DataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<DataObject *, Shape *> &source) const override {
        if (source.first->has("zIndex")) {
            source.second->setZIndex(source.first->get("zIndex")->getAsPrimitive()->getAsInt());
        }
        return nullptr;
    }


public:
    explicit ZIndexHandler(Handler<pair<DataObject *, Shape *>, Shape *> *suivant) : CORHandler(suivant) {}


};



