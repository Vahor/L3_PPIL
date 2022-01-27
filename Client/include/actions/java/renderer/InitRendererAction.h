//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "RendererAction.h"

#include <utility>

class InitRendererAction : public RendererAction {

    string framework;

public:
    explicit InitRendererAction(string framework) : framework(std::move(framework)) {}

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        meta->put("INIT", new DataPrimitive(framework));

        return meta;
    }

};

