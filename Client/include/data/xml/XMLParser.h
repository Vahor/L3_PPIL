//
// Created by Nathan David on 02/02/2022.
//

#pragma once

#include "data/DataPrimitive.h"
#include "data/DataObject.h"
#include "data/DataArray.h"
#include "data/Parser.h"


class XMLParser : public Parser {

    static pair<DataArray, int> parseArray(string input);

    static pair<DataObject, int> parseObject(string input);

public:

    DataObject parse(const string &input) const override {
        return parseObject(input).first;  // racine à JsonObject de base
    }

    string supportedExtensions() const override {
        return "xml";
    }

    string serialize(const DataObject *object) const override;
    string serialize(const DataArray *array) const override;
    string serialize(const DataPrimitive *primitive) const override;
};

