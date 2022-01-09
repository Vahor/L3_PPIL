//
// Created by Nathan David on 05/12/2021.
//

#pragma once

#include "api/shape/Shape.h"
#include "api/handler/CORHandler.h"

class VisibilityHandler : public CORHandler<pair<DataObject *, Shape *>, Shape *> {

protected:

    Shape *parse(const pair<DataObject *, Shape *> &source) const override {
        if (source.first->has("visible")) {
            bool visible = source.first->get("visible")->getAsPrimitive()->getAsBoolean();
            source.second->setVisible(visible);
        }
        return nullptr;
    }


public:
    explicit VisibilityHandler(Handler<pair<DataObject *, Shape *>, Shape *> *suivant) : CORHandler(suivant) {}
};



