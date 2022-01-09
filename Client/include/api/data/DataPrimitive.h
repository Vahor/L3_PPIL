//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include <string>
#include <utility>
#include "DataElement.h"

using namespace std;

class DataPrimitive : public DataElement {

protected:
    string value;

public:

    explicit DataPrimitive(string value) : value(std::move(value)) {}
    explicit DataPrimitive(int value) : value(to_string(value)) {}
    explicit DataPrimitive(bool value) : value(value ? "true" : "false") {}
    explicit DataPrimitive(double value) : value(to_string(value)) {}

    bool getAsBoolean() const { return value == "true"; }
    int getAsInt() const { return stoi(value); }
    double getAsDouble() const { return stod(value); }
    string getAsString() const { return value; }
};



