//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "data/DataImpl.h"
#include <utility>

class InitRendererAction : public Action {

public:
    explicit InitRendererAction() = default;

    void execute(const Client *client) const override {
        auto *object = new DataObjectImpl();
        auto *data = new DataObjectImpl();

        data->put("INIT", new DataPrimitiveImpl(true));
        object->put("RENDERER", data);

        client->send(object->toString());
    }

};

