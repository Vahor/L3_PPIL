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

    ADataPrimitive(string value) : value(std::move(value)) {}
    ADataPrimitive(int value) : value(to_string(value)) {}
    ADataPrimitive(bool value) : value(value ? "true" : "false") {}
    ADataPrimitive(double value) : value(to_string(value)) {}

    int getAsInt() const { return stoi(value); }
    string getAsString() const { return value; }


    ADataPrimitive * getAsPrimitive() const override {
        return (ADataPrimitive *) this;
    }
};


#endif //CLIENT_ADATAPRIMITIVE_H
