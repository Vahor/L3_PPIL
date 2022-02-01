//
// Created by Nathan David on 02/12/2021.
//
#pragma once


#include "data/DataPrimitive.h"
#include "data/DataObject.h"
#include "data/DataArray.h"
#include "data/json/JsonToken.h"
#include "data/Parser.h"

class JsonParser : public Parser {

    static pair<DataArray *, int> parseArray(string input);

    static pair<DataObject *, int> parseObject(string input);

public:

    DataObject *parse(string input) const override {
        return parseObject(input.substr(1)).first;  // racine à JsonObject de base
    }

    string supportedExtensions() const override {
        return "json";
    }

    string toString(const DataObject *object) const override;
    string toString(const DataArray *array) const override;
    string toString(const DataPrimitive *primitive) const override;

};



