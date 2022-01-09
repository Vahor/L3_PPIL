//
// Created by Nathan David on 02/12/2021.
//
#pragma once


#include "data/json/JsonObject.h"
#include "data/json/JsonArray.h"
#include "data/json/JsonPrimitive.h"
#include "data/json/JsonToken.h"
#include "api/data/AParser.h"

class JsonParser : public AParser {

    static pair<JsonArray *, int> parseArray(string input) {
        auto *array = new JsonArray;
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
                    array->add(new JsonPrimitive(token.value));
                    input = input.substr(token.position); // On avance à la fin de la valeur
                    break;
                }
                case TOKEN::CURLY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                    pair<JsonObject *, int> res = parseObject(input);
                    array->add(res.first);
                    input = input.substr(res.second + 1); // On avance à la fin de l'objet

                    break;
                }
                case TOKEN::ARRAY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                    pair<JsonArray *, int> res = parseArray(input);
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

    static pair<JsonObject *, int> parseObject(string input) {

        auto *object = new JsonObject();
        Token token;
        unsigned long length = input.length();
        do {
            // Pour la clé du token on récupère le token actuel
            token = JsonToken::getNextToken(input);
            input = input.substr(token.position); // On avance à la fin de ce token
            string key = token.value;

            if (token.type == TOKEN::CURLY_CLOSE || token.type == TOKEN::UNKNOWN) {
                break;
            }

            // Pour récupérer la valeur, on va voir le prochain token
            token = JsonToken::getNextToken(input);

            switch (token.type) {
                case TOKEN::STRING: {
                    object->put(key, new JsonPrimitive(token.value));
                    input = input.substr(token.position); // On avance à la fin de la valeur
                    break;
                }
                case TOKEN::CURLY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                    pair<JsonObject *, int> res = parseObject(input);
                    object->put(key, res.first);
                    input = input.substr(res.second + 1); // On avance à la fin de la liste

                    break;
                }
                case TOKEN::ARRAY_OPEN: {
                    input = input.substr(
                            JsonToken::getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                    pair<JsonArray *, int> res = parseArray(input);
                    object->put(key, res.first);
                    input = input.substr(res.second + 1); // On avance à la fin de la liste

                    break;
                }
                default:
                    break;
            }


        } while (token.type != TOKEN::CURLY_CLOSE && token.type != TOKEN::UNKNOWN);

        return {object, length - input.length()};
    }

public:

    virtual JsonObject *parse(string input) const {
        return parseObject(input.substr(1)).first;  // racine à JsonObject de base
    }

};



