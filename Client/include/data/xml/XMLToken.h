//
// Created by Nathan David on 02/02/2022.
//

#pragma once

#include <string>
#include <iostream>

using std::string;

enum class TYPE {
    ROOT,
    OBJECT,
    PRIMITIVE,
    ARRAY,
    CLOSE,
    UNKNOWN,
};

struct TokenXML {
    TYPE type;
    int position;
    string key;
    string _type;
    string value;
};

class XMLToken {

public:

    /**
     *
     * @param start
     * @param str
     * @return Token
     */
    static TokenXML getNextToken(const string &str) {

        struct TokenXML token = {TYPE::UNKNOWN};
        unsigned long maxLength = str.length();
        int i;
        for (i = 0; i < maxLength; i++) {
            char c = str[i];
            if (c == '"') {
                token.type = TYPE::PRIMITIVE;
                token.value = "";
                i++;
                do {
                    if (i != maxLength - 1) {
                        c = str[i++];
                        if (c != '"')
                            token.value += c;
                    }
                } while (c != '"');
                break;
            } else if (c == '<') {

                // Get key
                token.key = "";
                i++;
                do {
                    if (i != maxLength - 1) {
                        c = str[i++];
                        if (c == '/') {
                            token.type = TYPE::CLOSE;
                            return token;
                        }
                        if (c != ' ')
                            token.key += c;
                    }
                } while (c != ' ');

                // Get type
                // Go after type="
                for (; str[i] != '"'; i++);
                i++; // go after "

                string type;
                do {
                    if (i != maxLength - 1) {
                        c = str[i++];
                        if (c != '"')
                            type += c;
                    }
                } while (c != '"');
                token._type = type;

                if (type == "root")
                    token.type = TYPE::ROOT;
                else if (type == "primitive")
                    token.type = TYPE::PRIMITIVE;
                else if (type == "object")
                    token.type = TYPE::OBJECT;
                else if (type == "array")
                    token.type = TYPE::ARRAY;

                break;
            }
        }


        token.position = i;

        return token;
    }

    static int getNextTokenPosition(const string &str, const char test) {

        unsigned long maxLength = str.length();
        int i;
        for (i = 0; i < maxLength; i++) {
            if (str[i] == test) break;
        }
        return i;
    }
};
