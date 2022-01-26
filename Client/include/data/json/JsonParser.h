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

    static pair<DataArray *, int> parseArray(string input) {
        auto *array = new DataArray;
        Token token;
        unsigned long length = input.length();
        do {
            token = JsonToken::getNextToken(input);
            input = input.substr(token.position); // On avance à la fin de ce token

            if (token.type == TOKEN::ARRAY_CLOSE || token.type == TOKEN::UNKNOWN) {
                break;
            }

            switch (token.type) {
                case TOKEN::STRING: {
                    array->add(new DataPrimitive(token.value));
                    input = input.substr(token.position); // On avance à la fin de la valeur
                    break;
                }
                case TOKEN::CURLY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                    pair<DataObject *, int> res = parseObject(input);
                    array->add(res.first);
                    input = input.substr(res.second + 1); // On avance à la fin de l'objet

                    break;
                }
                case TOKEN::ARRAY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                    pair<DataArray *, int> res = parseArray(input);
                    array->add(res.first);
                    input = input.substr(res.second + 1); // On avance à la fin de la liste

                    break;
                }
                default:
                    break;
            }

        } while (token.type != TOKEN::ARRAY_CLOSE && token.type != TOKEN::UNKNOWN);

        return {array, length - input.length()};
    }

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



