//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include "DataElement.h"
#include <map>
#include <iostream>

using namespace std;

class DataObject : public DataElement {

protected:
    map<string, DataElement *> children;

public:

    DataObject() = default;

    explicit DataObject(const DataObject *copy) {
        for (const auto &it: copy->children) { put(it.first, it.second); }
    }

    DataObject *clone() const override {
        return new DataObject(*this);
    }

    virtual ~DataObject() {
        children.clear();
    }

    bool has(const string &key) const {
        return children.count(key);
    }

    void put(const string &key, const DataElement &element) {
        children[key] = element.clone();
    }

    void put(const string &key, const DataElement *element) {
        if (element == nullptr) return;
        children[key] = element->clone();
    }

    DataElement *get(const string &key) const {
        return children.at(key);
    }

    string toString() const override;
    string serialize(const Parser &parser) const override;

    const map<string, DataElement *> &getChildren() const {
        return children;
    }


};



