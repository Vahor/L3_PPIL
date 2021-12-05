//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_JSONARRAY_H
#define CLIENT_JSONARRAY_H

#include <iostream>
#include <string>

using namespace std;

#include "api/data/ADataArray.h"

class JsonArray : public ADataArray {

public:

    JsonArray *clone() const override {
        return new JsonArray(*this);
    }

    string toString() const override {
        string res = "[";

        for (auto it = children.begin(); it != children.end(); ++it) {
            ADataElement* element = *it;
            res += element->toString();

            if(std::next(it) != children.end()) {
                res += ",";
            }
        }

        res += "]";
        return res;
    }


};


#endif //CLIENT_JSONARRAY_H
