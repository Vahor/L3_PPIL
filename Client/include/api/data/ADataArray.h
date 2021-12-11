//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_ADATAARRAY_H
#define CLIENT_ADATAARRAY_H

#include <vector>
#include <iostream>

#include "ADataElement.h"

class ADataArray : public ADataElement {

protected:
    std::vector<ADataElement *> elements;

public:
    ADataArray(const ADataArray &copy) {
        //cout << "copy ADataArray" << endl;
        for (const auto &it: copy.elements) { add(it); }
    }

    ADataArray() = default;

    virtual ~ADataArray() {
        std::cerr << "delete JsonArray" << std::endl;
        // todo
    }

    void add(ADataElement *element) {
        elements.push_back(element->clone());
    }


    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }
};


#endif //CLIENT_ADATAARRAY_H
