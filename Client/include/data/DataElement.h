//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include <string>
#include <ostream>
#include <utility>

class DataObject;

class DataArray;

class DataPrimitive;

class Parser;

using std::string;

enum Type {
    OBJECT,
    ARRAY,
    PRIMITIVE
};
static const string enumStr[] = {"OBJECT", "ARRAY", "PRIMITIVE"};

string typeToString(Type type);

class DataElement {

    Type type;
    DataElement *parent = nullptr;

public:

    explicit DataElement(Type type) : type(type) {}

    virtual DataElement *clone() const = 0;

    virtual ~DataElement() = default;

    virtual DataObject *getAsObject() const;
    virtual DataArray *getAsArray() const;
    virtual DataPrimitive *getAsPrimitive() const;

    Type getType() const { return type; }

    DataElement *getParent() const { return parent; }
    void setParent(DataElement *p) { this->parent = p; }

    /**
    * Transforme l'objet en une chaine de caractere
     * à l'aide du parser.
     *
     * @see Parser.serialize(DataElement* element)
    *
    * @return Une chaine de caractere correspondant à l'objet
    */
    virtual string serialize(const Parser &parser) const = 0;

    /**
    * Transforme l'objet en une chaine de caractere
    * compréhensible par un humain.
    *
    * @return Une chaine de caractere correspondant à l'objet
    */
    virtual string toString() const = 0;

    explicit operator string() const { return toString(); }
    friend std::ostream &operator<<(std::ostream &os, const DataElement &element);
};



