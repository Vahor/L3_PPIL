//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_JSONPARSER_H
#define CLIENT_JSONPARSER_H

#include "json/JsonObject.h"
#include "json/JsonArray.h"
#include "json/JsonToken.h"

class JsonParser {

    static string getTokenName(TOKEN &token) {
        switch (token) {
            case TOKEN::CURLY_OPEN:
                return "CURLY_OPEN";
            case TOKEN::CURLY_CLOSE:
                return "CURLY_CLOSE";
            case TOKEN::STRING:
                return "STRING";
            case TOKEN::ARRAY_OPEN:
                return "ARRAY_OPEN";
            case TOKEN::ARRAY_CLOSE:
                return "ARRAY_CLOSE";
            case TOKEN::UNKNOWN:
                return "UNKNOWN";
        }
    }

    static pair<JsonArray *, int> parseArray(string input) {
        auto *array = new JsonArray();
        Token token;
        unsigned long length = input.length();
        do {
            token = JsonToken::getNextToken(input);
            input = input.substr(token.position); // On avance à la fin de ce token


            if(token.type == TOKEN::ARRAY_CLOSE || token.type == TOKEN::UNKNOWN) {
                break;
            }

            switch (token.type) {
                case TOKEN::STRING: {
                    array->add(new JsonPrimitive(token.value));
                    break;
                }
                case TOKEN::CURLY_OPEN: {
                    pair<JsonObject *, int> res = parseObject(input.substr(token.position));
                    array->add(res.first);
                    input = input.substr(res.second); // On avance à la fin de l'objet
                    input = input.substr(JsonToken::getNextTokenPosition(input, '}')); // On avance à la fin de ce token

                    break;
                }
                case TOKEN::ARRAY_OPEN: {
                    pair<JsonArray *, int> res = parseArray(input.substr(token.position));
                    array->add(res.first);
                    input = input.substr(res.second); // On avance à la fin de la liste
                    input = input.substr(JsonToken::getNextTokenPosition(input, ']')); // On avance à la fin de ce token

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

            if(token.type == TOKEN::CURLY_CLOSE || token.type == TOKEN::UNKNOWN) {
                break;
            }

            // Pour récupérer la valeur, on va voir le prochain token
            token = JsonToken::getNextToken(input);

            switch (token.type) {
                case TOKEN::STRING: {
                    object->put(key, new JsonPrimitive(token.value));
                    input = input.substr(token.position + 1); // On avance à la fin de la valeur
                    break;
                }
                case TOKEN::CURLY_OPEN: {
                    pair<JsonObject *, int> res = parseObject(input.substr(token.position));
                    object->put(key, res.first);
                    input = input.substr(res.second); // On avance à la fin de l'objet
                    input = input.substr(JsonToken::getNextTokenPosition(input, '}')); // On avance à la fin de ce token

                    break;
                }
                case TOKEN::ARRAY_OPEN: {
                    pair<JsonArray *, int> res = parseArray(input.substr(token.position));
                    object->put(key, res.first);
                    input = input.substr(res.second); // On avance à la fin de la liste
                    input = input.substr(JsonToken::getNextTokenPosition(input, ']')); // On avance à la fin de ce token

                    break;
                }
                default:
                    break;
            }


        } while (token.type != TOKEN::CURLY_CLOSE && token.type != TOKEN::UNKNOWN);

        return {object, length - input.length()};
    }

public:

    static JsonObject *parse(const string &input) {
        return parseObject(input.substr(1)).first;  // racine à JsonObject de base
    }

};


#endif //CLIENT_JSONPARSER_H
