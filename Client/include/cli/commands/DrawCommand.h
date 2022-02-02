//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "scene/SceneDao.h"
#include "actions/java/DrawOverJavaTcp.h"

class DrawCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {
        if (args.empty()) {
            cerr << "No framework specified" << endl;
            return;
        }

        SceneDao *dao = SceneDao::getInstance();
        Scene *scene = dao->getCurrentScene();

        if (scene == nullptr) {
            cerr << "Nothing to draw" << endl;
            return;
        }

        string framework = args[0];

        DrawOverJavaTcp visitor(framework);
        scene->draw(visitor);
        cout << scene->getName() << " has been drawn" << endl;
    }

    string showHelp() const override {
        return "Draw current scene using visitor";
    }
};
