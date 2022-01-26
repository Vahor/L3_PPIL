//
// Created by Nathan David on 11/12/2021.
//

#pragma once

#include <string>
#include "client/Client.h"

class Action {

public:
    virtual void execute() const = 0;
};



