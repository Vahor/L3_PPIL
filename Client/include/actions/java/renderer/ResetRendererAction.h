//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "RendererAction.h"
#include "data/DataObject.h"
#include "data/DataPrimitive.h"

#include <utility>

class ResetRendererAction : public RendererAction {

public:

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        meta->put("RESET", DataPrimitive(true));

        return meta;
    }

};

