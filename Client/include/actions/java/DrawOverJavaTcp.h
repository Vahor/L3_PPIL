//
// Created by Nathan David on 26/01/2022.
//

#pragma once

#include <utility>

#include "scene/Scene.h"
#include "shapes/Shape.h"

#include "client/TCPClient.h"
#include "actions/java/renderer/InitRendererAction.h"
#include "actions/java/renderer/UpdateRendererNameAction.h"
#include "actions/java/renderer/UpdateRendererSizeAction.h"
#include "actions/java/renderer/DisposeRendererAction.h"
#include "actions/java/renderer/ResetRendererAction.h"

class DrawOverJavaTcp : public Visitor {

    string framework;
    bool reset;

public:
    explicit DrawOverJavaTcp(string framework, bool reset = false) : framework(std::move(framework)), reset(reset) {}

    void setReset(bool b) {
        this->reset = b;
    }

    void drawScene(const Scene *scene) const override {
        cout << "DrawOverJavaTcp" << endl;
        if (reset)
            ResetRendererAction().execute();
        else {
            InitRendererAction(framework).execute();
            usleep(500 * 1000);
            UpdateRendererNameAction(scene->getName()).execute();
            UpdateRendererSizeAction(scene->getWidth(), scene->getHeight()).execute();
        }
        usleep(500 * 1000);

        for (auto shape: *scene) {
            drawShape(shape);
            usleep(5 * 1000); // delay 5ms to allow swing draw
        }

        //usleep(400 * 1000);

        DisposeRendererAction().execute();
    }

    void drawShape(const Shape *shape) const override {
        if (auto *group = dynamic_cast<const ShapeGroup *>(shape)) {
            for (auto s: *group) {
                drawShape(s);
            }
        } else {
            TCPClient *client = TCPClient::getInstance();
            client->send(shape->serialize(false)->toString());
        }
    }
};
