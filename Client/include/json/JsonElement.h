//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_JSONELEMENT_H
#define CLIENT_JSONELEMENT_H

#include <string>
#include <utility>
using namespace std;

class JsonElement {

public:

    virtual string toString() const = 0;
    virtual JsonElement* clone() const = 0;

    explicit operator string() const {
        return toString();
    }


};


#endif //CLIENT_JSONELEMENT_H
