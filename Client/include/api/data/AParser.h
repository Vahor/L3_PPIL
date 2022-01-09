//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include "DataObject.h"

class AParser {

public:
    virtual DataObject *parse(string input) const = 0;
};

