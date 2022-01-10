//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include <vector>
#include <iostream>

#include "DataElement.h"

class DataArray : public DataElement {

protected:
    std::vector<DataElement *> elements;

public:
    DataArray(const DataArray &copy) {
        //cout << "copy ADataArray" << endl;
        for (const auto &it: copy.elements) { add(it); }
    }

    DataArray() = default;

    virtual ~DataArray() {
        std::cerr << "delete DataArray" << std::endl;
        // todo
    }

    void add(DataElement *element) {
        elements.push_back(element->clone());
    }


    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }
};



