//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"
#include "actions/java/renderer/RendererAction.h"


class DisposeRendererAction : public RendererAction {

public:
    explicit DisposeRendererAction() = default;

    DataObjectImpl *getMetaData() const override {
        auto *meta = new DataObjectImpl();

        meta->put("DISPOSE", new DataPrimitiveImpl(true));

        return meta;
    }
};



