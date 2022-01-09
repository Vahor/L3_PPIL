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

    DataObjectImpl *getMetaData() const override {
        auto *meta = new DataObjectImpl();
        auto *size = new DataObjectImpl();

        size->put("width", new DataPrimitiveImpl(width));
        size->put("height", new DataPrimitiveImpl(height));
        meta->put("size", size);

        return meta;
    }

};

