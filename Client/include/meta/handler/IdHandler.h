//
// Created by Nathan David on 11/12/2021.
//

#pragma once


#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class IdHandler : public CORHandler<pair<DataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<DataObject *, Shape *> &source) const override {
        if (source.first->has("id")) {
            source.second->setId(source.first->get("id")->getAsPrimitive()->getAsInt());
        }
        return nullptr;
    }


public:
    explicit IdHandler(Handler<pair<DataObject *, Shape *>, Shape *> *suivant) : CORHandler(suivant) {}

};


