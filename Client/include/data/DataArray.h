//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include <vector>
#include <iostream>

#include "DataElement.h"

using std::vector;

class DataArray : public DataElement {

protected:
    vector<DataElement *> elements;

public:

    DataArray() = default;

    DataArray(const DataArray &copy) {
        //cout << "copy ADataArray" << endl;
        for (const auto &it: copy.elements) { add(it); }
    }

    virtual ~DataArray() {
        elements.clear();
        // todo
    }

    DataArray *clone() const override {
        return new DataArray(*this);
    }

    void add(DataElement *element) {
        elements.push_back(element->clone());
    }

    string toString() const override;


    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }
};



