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

    DataArray() : DataElement(ARRAY) {}

    DataArray(const DataArray &copy) : DataElement(ARRAY) {
        for (const auto &it: copy.elements) { add(it); }
    }

    ~DataArray() override {
        elements.clear();
    }

    DataArray *clone() const override {
        return new DataArray(*this);
    }

    void add(const DataElement &element) {
        DataElement *clone = element.clone();
        clone->setParent(this);
        elements.push_back(clone);
    }

    void add(DataElement *element) {
        add(*element);
    }

    string toString() const override;
    string serialize(const Parser &parser) const override;


    auto begin() { return &elements[0]; }
    auto end() { return &elements[elements.size()]; }
    auto begin() const { return &elements[0]; }
    auto end() const { return &elements[elements.size()]; }
};



