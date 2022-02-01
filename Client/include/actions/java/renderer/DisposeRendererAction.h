//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"
#include "actions/java/renderer/RendererAction.h"


class DisposeRendererAction : public RendererAction {

public:
    explicit DisposeRendererAction() = default;

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        meta->put("DISPOSE", DataPrimitive(true));

        return meta;
    }
};



