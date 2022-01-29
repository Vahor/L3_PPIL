//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "scene/SceneDao.h"

class ShapeCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {

        if (args.size() < 2) {
            cerr << "Usage : shape <id> <rotate/translate/area> [args...]" << endl;
            return;
        }

        SceneDao *dao = SceneDao::getInstance();
        Scene *scene = dao->getCurrentScene();
        if (scene == nullptr) {
            cerr << "Nothing to edit" << endl;
            return;
        }


        Shape *shape = scene->getShapeById(stoi(args[0]));

        if (shape == nullptr) {
            cerr << "No shape found with id " << args[0] << endl;
            return;
        }

        // Il n'y a pas des milions de transformations, les if vont bien
        cout << "Editing shape \n"
             << "from : \n"
             << shape->toString() << endl;
        if (args[1] == "area") {
            cout << "Area : " << shape->getArea() << endl;


        } else if (args[1] == "translate") {
            if (args.size() != 4) {
                cerr << "Usage : shape <id> <translate> <x> <y>" << endl;
                return;
            }

            int x = stoi(args[2]);
            int y = stoi(args[3]);
            shape->translate(x, y);
            cout << "Translate : " << "x : " << to_string(x) << " y : " << to_string(y) << endl;


        } else if (args[1] == "rotate") {
            if (args.size() < 3) {
                cerr << "Usage : shape <id> <rotate> <deg> [x] [y]" << endl;
                return;
            }

            double deg = stoi(args[2]) % 360;
            // convert to radians
            double rad = deg * M_PI / 180;

            if (args.size() == 5) {
                double x = stoi(args[3]);
                double y = stoi(args[4]);
                shape->rotate(Point2D(x, y), rad);
            } else {
                shape->rotateSelf(rad);
            }

            cout << "Rotate : " << "deg : " << to_string(deg) << endl;
        }


        cout << "to : \n"
             << shape->toString() << endl;

    }

    string showHelp() const override {
        return "Edit shapes in scene";
    }
};
