//
// Created by Nathan David on 01/12/2021.
//

#pragma once

#include "data/DataPrimitive.h"

using namespace std;


class JsonPrimitive : public DataPrimitive {


public:
    JsonPrimitive(const JsonPrimitive &value) : DataPrimitive(value.value) {}
    explicit JsonPrimitive(const string &value) : DataPrimitive(value) {}
    explicit JsonPrimitive(int value) : DataPrimitive(value) {}
    explicit JsonPrimitive(bool value) : DataPrimitive(value) {}
    explicit JsonPrimitive(double value) : DataPrimitive(value) {}

    JsonPrimitive *clone() const override {
        return new JsonPrimitive(*this);
    }

    string toString() const override {
        return '"' + value + '"';
    }

};



