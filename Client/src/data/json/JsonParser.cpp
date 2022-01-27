//
// Created by Nathan David on 26/01/2022.
//

#include "data/json/JsonParser.h"

pair<DataObject *, int> JsonParser::parseObject(string input) {
    auto *object = new DataObject();
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
                object->put(key, new DataPrimitive(token.value));
                input = input.substr(token.position); // On avance à la fin de la valeur
                break;
            }
            case TOKEN::CURLY_OPEN: {
                input = input.substr(
                        JsonToken::getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                pair<DataObject *, int> res = parseObject(input);
                object->put(key, res.first);
                input = input.substr(res.second + 1); // On avance à la fin de la liste

                break;
            }
            case TOKEN::ARRAY_OPEN: {
                input = input.substr(
                        JsonToken::getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                pair<DataArray *, int> res = parseArray(input);
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

string JsonParser::toString(const DataObject *object) const {
    string res = "{";

    for (const auto &it: object->getChildren()) {
        DataElement *element = it.second;
        res += '"' + it.first + "\":";
        res += element->toString();

        res += ",";
    }

    if (res.length() > 1)
        res.pop_back();

    res += "}";
    return res;
}

string JsonParser::toString(const DataArray *array) const {
    string res = "[";

    for (auto it: *array) {
        DataElement *element = it;
        res += element->toString();

        res += ",";
    }


    if (res.length() > 1)
        res.pop_back();

    res += "]";
    return res;
}

string JsonParser::toString(const DataPrimitive *primitive) const {
    return '"' + primitive->getAsString() + '"';
}
