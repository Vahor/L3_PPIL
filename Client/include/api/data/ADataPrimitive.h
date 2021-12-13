//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_ADATAPRIMITIVE_H
#define CLIENT_ADATAPRIMITIVE_H

#include <string>
#include <utility>
#include "ADataElement.h"

using namespace std;

class ADataPrimitive : public ADataElement {

protected:
    string value;

public:

    explicit ADataPrimitive(string value) : value(std::move(value)) {}
    explicit ADataPrimitive(int value) : value(to_string(value)) {}
    explicit ADataPrimitive(bool value) : value(value ? "true" : "false") {}
    explicit ADataPrimitive(double value) : value(to_string(value)) {}

    bool getAsBoolean() const { return value == "true"; }
    int getAsInt() const { return stoi(value); }
    double getAsDouble() const { return stod(value); }
    string getAsString() const { return value; }
};


#endif //CLIENT_ADATAPRIMITIVE_H
