//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "data/DataImpl.h"
#include "actions/Action.h"

class RendererAction : public Action {

protected:
    virtual DataObjectImpl *getMetaData() const = 0;
public:
    void execute(const Client *client) const override {
        auto *object = new DataObjectImpl();
        auto *data = new DataObjectImpl();

        data->put("meta", getMetaData());
        object->put("RENDERER", data);

        client->send(object->toString());
    }
};