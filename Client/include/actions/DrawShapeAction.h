//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"
#include "shapes/Shape.h"

class DrawShapeAction : public Action {

    Shape *shape;

public:

    explicit DrawShapeAction(Shape &shape) : shape(&shape) {}

    void execute(const Client *client) const override {
        if (auto *group = dynamic_cast<ShapeGroup *>(shape)) {
            for (auto s: *group) {
                DrawShapeAction(*s).execute(client);
            }
        } else {
            client->send(shape->serialize(false)->toString());
        }
    }


};

