//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"

class ExitCommand : public CliCommand {

public:

    void execute(Cli *cli, list<string> args) const override {
        cli->setEnabled(false);
    }

    string showHelp() const override {
        return "Quit the program";
    }
};
