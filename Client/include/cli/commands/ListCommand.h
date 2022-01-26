//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "scene/SceneDao.h"

class ListCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {
        SceneDao *dao = SceneDao::getInstance();
        Scene *scene = dao->getCurrentScene();
        if (scene == nullptr) {
            cerr << "Nothing to list" << endl;
            return;
        }

        cout << "CurrentScene:" << endl;
        cout << "Name: " << scene->getName() << endl;
        cout << "Width: " << scene->getWidth() << endl;
        cout << "Height: " << scene->getHeight() << endl;
        for (auto &shape: *scene) {
            if (shape->isInGroup())continue;
            cout << "\t" << shape->toString() << endl;
        }
    }

    string showHelp() const override {
        return "List every shapes in scene";
    }
};
