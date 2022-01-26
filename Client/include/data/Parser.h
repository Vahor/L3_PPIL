//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include "DataObject.h"

class Parser {

public:
    virtual DataObject *parse(string input) const = 0;
    virtual string supportedExtensions() const = 0;

    virtual string toString(const DataObject *object) const = 0;
    virtual string toString(const DataArray *array) const = 0;
    virtual string toString(const DataPrimitive *primitive) const = 0;
};

