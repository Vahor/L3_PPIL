//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "actions/DrawSceneAction.h"
#include "scene/SceneDao.h"

class SaveCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {
        if (args.empty()) {
            cerr << "No arguments" << endl;
            return;
        }

        string path = args[0];
        string format;

        if (args.size() == 1) {
            vector<string> splittedArgs = split(path, '.');
            format = splittedArgs.back();
        } else { // if args.size() > 1
            format = args[1];
        }

        try {
            SceneDao *dao = SceneDao::getInstance();
            dao->setParser(format);

            Scene *scene = dao->getCurrentScene();
            if (scene == nullptr) {
                cerr << "Nothing to save" << endl;
                return;
            }

            dao->save(path, dao->getCurrentScene());

            cout << "Current scene saved to " << path << endl;
        } catch (const std::exception &e) {
            cerr << e.what() << endl;
        }

    }

    string showHelp() const override {
        return "Save current Scene\n"
               "\tUsage: save <path> [format]";
    }
};
