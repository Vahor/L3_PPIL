//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_ADATAELEMENT_H
#define CLIENT_ADATAELEMENT_H

class ADataObject;

class ADataArray;

class ADataPrimitive;

#include <string>

class ADataElement {

public:

    virtual ADataElement *clone() const = 0;

    virtual ADataObject *getAsObject() const { return (ADataObject *) this; }

    virtual ADataArray *getAsArray() const { return (ADataArray *) this; }

    virtual ADataPrimitive *getAsPrimitive() const { return (ADataPrimitive *) this; }

    virtual std::string toString() const = 0;

    explicit operator std::string() const { return toString(); }
};


#endif //CLIENT_ADATAELEMENT_H