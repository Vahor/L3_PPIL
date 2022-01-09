//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"
#include "api/shape/Shape.h"

class DrawShapeAction : public Action {

    Shape *shape;
public:

    explicit DrawShapeAction(Shape &shape) : shape(&shape) {}

    void execute(const Client *client) const override {
        client->send(shape->serialize()->toString());
    }


};

