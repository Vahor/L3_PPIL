//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "actions/DrawSceneAction.h"

class LoadCommand : public CliCommand {

    const Client *client;

public:
    explicit LoadCommand(const Client *client) : client(client) {}

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
            Scene *scene = dao->get(path);

            DrawSceneAction(*scene).execute(client);
        } catch (const std::exception &e) {
            cerr << e.what() << endl;
        }
    }

    string showHelp() const override {
        return "Load scene\n"
               "\tUsage: load <path>";
    }
};
