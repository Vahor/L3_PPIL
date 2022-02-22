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

    static pair<DataArray, int> parseArray(string input);

    static pair<DataObject, int> parseObject(string input);

public:

    DataObject parse(const string &input) const override {
        return parseObject(input.substr(1)).first;  // racine à JsonObject de base
    }

    string supportedExtension() const override {
        return "json";
    }

    string serialize(const DataObject *object) const override;
    string serialize(const DataArray *array) const override;
    string serialize(const DataPrimitive *primitive) const override;

};



