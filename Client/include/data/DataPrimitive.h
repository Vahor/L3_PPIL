//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include <string>
#include <utility>

#include "DataElement.h"

using std::string;
using std::to_string;

class DataPrimitive : public DataElement {

protected:
    string value;

public:

    DataPrimitive(const DataPrimitive &copy) : DataElement(PRIMITIVE) {
        this->value = copy.value;
    }

    explicit DataPrimitive(string value) : DataElement(PRIMITIVE), value(std::move(value)) {}
    explicit DataPrimitive(int value) : DataElement(PRIMITIVE), value(to_string(value)) {}
    explicit DataPrimitive(bool value) : DataElement(PRIMITIVE), value(value ? "true" : "false") {}
    explicit DataPrimitive(double value) : DataElement(PRIMITIVE), value(to_string(value)) {}


    DataPrimitive *clone() const override {
        return new DataPrimitive(*this);
    }

    bool getAsBoolean() const { return value == "true"; }
    int getAsInt() const { return stoi(value); }
    double getAsDouble() const { return stod(value); }
    const string &getAsString() const { return value; }

    string toString() const override;
    string serialize(const Parser &parser) const override;
};



