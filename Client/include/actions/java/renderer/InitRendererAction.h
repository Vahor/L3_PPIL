//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "RendererAction.h"

#include <utility>

class InitRendererAction : public RendererAction {

    string framework;
    int height;
    int width;

public:
    explicit InitRendererAction(string framework, int height, int width) : framework(std::move(framework)),
                                                                           height(height), width(width) {}

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        // todo : Suivre ce principe pour les autres packets
        //  Comme on utilise un clone on n'a pas besoin de faire un pointeur

        auto init = DataObject();
        init.put("framework", DataPrimitive(framework));
        init.put("width", DataPrimitive(width));
        init.put("height", DataPrimitive(height));

        meta->put("INIT", init);

        return meta;
    }

};

