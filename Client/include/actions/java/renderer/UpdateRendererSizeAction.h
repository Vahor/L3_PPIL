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

        auto size = DataObject();

        size.put("width", DataPrimitive(width));
        size.put("height", DataPrimitive(height));

        meta->put("size", size);

        return meta;
    }

};

