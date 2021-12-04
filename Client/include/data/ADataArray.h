//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_ADATAARRAY_H
#define CLIENT_ADATAARRAY_H

#include <vector>

#include "data/ADataElement.h"
using namespace std;

class ADataArray : public ADataElement {

protected:
    vector<ADataElement*> children;

public:
    ADataArray(const ADataArray &copy) {
        //cout << "copy ADataArray" << endl;
        for (const auto &it: copy.children) { add(it); }
    }

    ADataArray() {}

    ~ADataArray(){
        //cout << "delete JsonArray" << endl;
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
