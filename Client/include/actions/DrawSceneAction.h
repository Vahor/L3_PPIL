//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"
#include "scene/Scene.h"
#include "actions/renderer/UpdateRendererNameAction.h"
#include "actions/renderer/UpdateRendererSizeAction.h"
#include "actions/renderer/InitRendererAction.h"
#include "actions/renderer/DisposeRendererAction.h"
#include "DrawShapeAction.h"

class DrawSceneAction : public Action {

    Scene *scene;

public:

    explicit DrawSceneAction(Scene &scene) : scene(&scene) {}

    void execute(const Client *client) const override {
        InitRendererAction().execute(client);
        usleep(300 * 1000);
        UpdateRendererNameAction(scene->getName()).execute(client);
        UpdateRendererSizeAction(scene->getWidth(), scene->getHeight()).execute(client);
        usleep(300 * 1000);

        for (auto shape: *scene) {
            DrawShapeAction(*shape).execute(client);
        }

        usleep(200 * 1000);

        DisposeRendererAction().execute(client);
    }

};



