//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include <map>

class HelpCommand : public CliCommand {

public:

    void execute(Cli *cli, list<string> args) const override {
        cout << "Commands available:" << endl;
        map<string, CliCommand *> commands = cli->getCommands();

        for (auto &it: commands) {
            cout << "\t- " << it.first << endl;
            cout << "\t\t" << it.second->showHelp() << endl;
        }

    }

    string showHelp() const override {
        return "Show this help message";
    }
};
