//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_ADATAOBJECT_H
#define CLIENT_ADATAOBJECT_H

#include "ADataElement.h"

class ADataObject : public ADataElement {

protected:
    map<string, ADataElement *> children;

public:

    ADataObject() {}

    ADataObject(const ADataObject *copy) {
        //cout << "copy ADataObject" << endl;
        for (const auto &it: copy->children) { put(it.first, it.second); }
    }

    virtual ~ADataObject() {
        //cout << "delete ADataObject" << endl;
        // todo
    }

    void put(const string &key, ADataElement *json) {
        children[key] = json->clone();
    }

    ADataElement *get(const string &key) const {
        return children.at(key);
    }



};


#endif //CLIENT_ADATAOBJECT_H
