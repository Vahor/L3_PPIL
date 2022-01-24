//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "cli/CliCommand.h"
#include "client/TCPClient.h"

class ReconnectCommand : public CliCommand {

public:

    void execute(Cli *cli, vector<string> args) const override {
        Client *client = TCPClient::getInstance();
        client->reconnect();
    }

    string showHelp() const override {
        return "Reconnect to TCP server";
    }
};
