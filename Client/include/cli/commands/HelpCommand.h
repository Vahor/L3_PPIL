//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include <map>

class HelpCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {
        cout << "Commands available:" << endl;
        map<string, CliCommand *> commands = cli->getCommands();

        for (auto &it: commands) {
            cout << "\t- " << it.first << endl;
            string commandHelp = it.second->showHelp();
            vector<string> helpLines = split(commandHelp, '\n');
            for (const auto &line: helpLines) {
                cout << "\t\t" << line << endl;
            }
        }

    }

    string showHelp() const override {
        return "Show this help message";
    }
};
