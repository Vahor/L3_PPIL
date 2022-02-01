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
            InitRendererAction(framework, scene->getHeight(), scene->getWidth()).execute();
            UpdateRendererNameAction(scene->getName()).execute();

            usleep(200 * 1000); // delay 200ms to allow swing init
        }


        for (auto shape: *scene) {
            drawShape(shape);
            usleep(5 * 1000); // delay 5ms to allow swing draw
        }

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
