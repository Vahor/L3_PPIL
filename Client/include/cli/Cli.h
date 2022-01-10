//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include <string>
#include <iostream>
#include "handler/Handler.h"
#include "cli/CliCommand.h"
#include <map>
#include <list>

#include <readline/readline.h>
#include <readline/history.h>

using namespace std;

class Cli {

    const char *prefix = "? ";
    bool enabled = true;

    map<string, CliCommand *> commands;

    static list<string> splitAgs(const string &input) {
        list<string> args;
        string current;

        for (auto x: input) {
            if (x != ' ')
                current += x;
            else {
                args.push_back(current);
                cout << "arg : " << current << endl;
                current = "";
            }
        }

        if (!current.empty())
            args.push_back(current);

        return args;
    }

    static Cli *instance_;

protected:
    ~Cli() = default;
    Cli() = default;

public:

    Cli(Cli &o) = delete;
    void operator=(const Cli &) = delete;


    void addCommand(const string &name, CliCommand *command) {
        commands[name] = command;
    }

    void setPrefix(const char *v) { this->prefix = v; }
    void setEnabled(bool v) { this->enabled = v; }
    map<string, CliCommand *> getCommands() { return commands; }

    void init() {
        const char *line;
        while (enabled) {
            line = readline(prefix);
            if (*line) {
                add_history(line);
                list<string> args = splitAgs(line);

                // La liste n'est pas vide à ce moment
                string command = args.front();
                if (commands.count(command)) {
                    CliCommand *cliCommand = commands[command];
                    cliCommand->execute(this, args);
                } else {
                    cout << "Unknown command " << command << endl;
                }
                delete line;
            }

        }
    }

    static Cli *getInstance();

};

Cli *Cli::instance_ = {nullptr};

Cli *Cli::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new Cli();
    }
    return instance_;
}
