//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "RendererAction.h"
#include <utility>

class UpdateRendererNameAction : public RendererAction {
    const string name;

public:
    explicit UpdateRendererNameAction(string name) : name(std::move(name)) {}

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        meta->put("name", new DataPrimitive(name));

        return meta;
    }

};

