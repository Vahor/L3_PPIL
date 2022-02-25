//
// Created by Nathan David on 11/12/2021.
//
#pragma once

#include "actions/Action.h"
#include "RendererAction.h"

#include <utility>

class InitRendererAction : public RendererAction {

    string framework;
    const Scene *scene;

public:
    explicit InitRendererAction(string framework, const Scene *scene) : framework(std::move(framework)),
                                                                        scene(scene) {}

    DataObject *getMetaData() const override {
        auto *meta = new DataObject();

        auto init = DataObject();
        init.put("framework", DataPrimitive(framework));
        init.put("width", DataPrimitive(scene->getWidth()));
        init.put("height", DataPrimitive(scene->getHeight()));
        init.put("backgroundColor", scene->getBackgroundColor());

        meta->put("INIT", init);

        return meta;
    }

};

