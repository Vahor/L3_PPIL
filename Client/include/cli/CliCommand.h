//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include <string>
#include <list>
#include "handler/Handler.h"
#include "Cli.h"

class Cli;

class CliCommand {

public:
    virtual ~CliCommand() = default;

    virtual void execute(Cli *cli, list <string> args) const = 0;

    virtual string showHelp() const = 0;

};
