//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "data/DataImpl.h"
#include "RendererAction.h"

class InitRendererAction : public RendererAction {

public:
    explicit InitRendererAction() = default;

    DataObjectImpl *getMetaData() const override {
        auto *meta = new DataObjectImpl();

        meta->put("INIT", new DataPrimitiveImpl(true));

        return meta;
    }

};

