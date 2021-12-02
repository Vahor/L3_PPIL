//
// Created by Nathan David on 02/12/2021.
//

#ifndef CLIENT_JSONTOKEN_H
#define CLIENT_JSONTOKEN_H

enum class TOKEN {
    CURLY_OPEN,
    CURLY_CLOSE,
    STRING,
    ARRAY_OPEN,
    ARRAY_CLOSE,
    UNKNOWN
};

struct Token {
    TOKEN type;
    string value;
    int position;
};

class JsonToken {

public:

    /**
     *
     * @param start
     * @param str
     * @return Token
     */
    static Token getNextToken( const string &str) {

        struct Token token = {TOKEN::UNKNOWN};
        unsigned long maxLength = str.length();
        int i;
        for (i = 0; i < maxLength; i++) {
            char c = str[i];
            if (c == '{') {
                token.type = TOKEN::CURLY_OPEN;
                break;
            } else if (c == '}') {
                token.type = TOKEN::CURLY_CLOSE;
                break;
            } else if (c == '[') {
                token.type = TOKEN::ARRAY_OPEN;
                break;
            } else if (c == ']') {
                token.type = TOKEN::ARRAY_CLOSE;
                break;
            } else if (c == '"') {
                token.type = TOKEN::STRING;
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
            }
        }
        token.position = i;

        return token;
    }
};


#endif //CLIENT_JSONTOKEN_H
