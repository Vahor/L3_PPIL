//
// Created by Nathan David on 02/12/2021.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "api/data/DataArray.h"

class JsonArray : public DataArray {

public:

    JsonArray *clone() const override {
        return new JsonArray(*this);
    }

    string toString() const override {
        string res = "[";

        for (auto it = elements.begin(); it != elements.end(); ++it) {
            DataElement *element = *it;
            res += element->toString();

            if (std::next(it) != elements.end()) {
                res += ",";
            }
        }

        res += "]";
        return res;
    }


};



