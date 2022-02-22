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

    /**
     * Execute la commande
     *
     * @param cli Reférence sur le Cli
     * @param args Liste des arguments que l'utilisateurs à envoyé.
     */
    virtual void execute(Cli *cli, vector<string> args) const = 0;

    /**
     * Informations expliquant comment utiliser cette commande.
     *
     * @return Une chaine de caractere correspondant aux explications
     */
    virtual string showHelp() const = 0;

};
