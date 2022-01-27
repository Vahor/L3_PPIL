//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include <utility>
#include "RendererAction.h"

class UpdateRendererSizeAction : public RendererAction {
    const int width;
    const int height;

public:
    explicit UpdateRendererSizeAction(int width, int height) : width(width), height(height) {}

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();
        auto *size = new DataObject();

        size->put("width", new DataPrimitive(width));
        size->put("height", new DataPrimitive(height));
        meta->put("size", size);

        return meta;
    }

};

