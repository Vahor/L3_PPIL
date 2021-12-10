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
    std::vector<ADataElement*> children;

public:
    ADataArray(const ADataArray &copy) {
        //cout << "copy ADataArray" << endl;
        for (const auto &it: copy.children) { add(it); }
    }

    ADataArray() = default;

    virtual ~ADataArray(){
        std::cerr << "delete JsonArray" << std::endl;
        // todo
    }

    void add(ADataElement *element) {
        children.push_back(element->clone());
    }


    auto begin() { return &children[0]; }
    auto end() { return &children[children.size()]; }
    auto begin() const { return &children[0]; }
    auto end() const { return &children[children.size()]; }
};


#endif //CLIENT_ADATAARRAY_H
