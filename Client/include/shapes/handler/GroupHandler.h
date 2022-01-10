//
// Created by Nathan David on 11/12/2021.
//

#pragma once

#include "shapes/Circle.h"
#include "shapes/Shape.h"
#include "handler/CORHandler.h"

class GroupHandler : public CORHandler<DataObject, Shape *> {


protected:

    Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler = nullptr;

    Shape *parse(const DataObject &input) const override {
        if (!input.has("GROUP")) return nullptr;

        auto *group = new ShapeGroup;
        DataArray *items = input.get("GROUP")->getAsObject()->get("items")->getAsArray();
        for (DataElement *element: *items) {
            Shape *shape = Shape::parse(*element->getAsObject(), this, metaHandler);
            if (shape != nullptr) group->addShape(shape);
        }


        return group;
    }

public:
    explicit GroupHandler(Handler<DataObject, Shape *> *suivant,
                          Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler
    ) : CORHandler(suivant), metaHandler(metaHandler) {}
};


