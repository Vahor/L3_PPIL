//
// Created by Nathan David on 04/12/2021.
//
#pragma once


#include "DataElement.h"

class DataObject : public DataElement {

protected:
    map<string, DataElement *> children;

public:

    DataObject() = default;

    explicit DataObject(const DataObject *copy) {
        for (const auto &it: copy->children) { put(it.first, it.second); }
    }

    virtual ~DataObject() {
        cerr << "delete ADataObject" << endl;
        // todo
    }

    bool has(const string &key) const {
        return children.count(key);
    }

    void put(const string &key, const DataElement *json) {
        children[key] = json->clone();
    }

    DataElement *get(const string &key) const {
        return children.at(key);
    }



};


