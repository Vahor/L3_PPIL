//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include <string>
#include <ostream>

class DataObject;

class DataArray;

class DataPrimitive;

class Parser;

using std::string;

class DataElement {

public:

    virtual DataElement *clone() const = 0;

    virtual ~DataElement() = default;

    virtual DataObject *getAsObject() const;
    virtual DataArray *getAsArray() const;
    virtual DataPrimitive *getAsPrimitive() const;

    virtual string serialize(const Parser &parser) const = 0;
    virtual string toString() const = 0;

    explicit operator string() const { return toString(); }
    friend std::ostream &operator<<(std::ostream &os, const DataElement &element);
};



