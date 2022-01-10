//
// Created by Nathan David on 04/12/2021.
//
#pragma once


class DataObject;

class DataArray;

class DataPrimitive;

#include <string>

class DataElement {

public:

    virtual DataElement *clone() const = 0;

    virtual DataObject *getAsObject() const { return (DataObject *) this; }

    virtual DataArray *getAsArray() const { return (DataArray *) this; }

    virtual DataPrimitive *getAsPrimitive() const { return (DataPrimitive *) this; }

    virtual std::string toString() const = 0;

    explicit operator std::string() const { return toString(); }
};



