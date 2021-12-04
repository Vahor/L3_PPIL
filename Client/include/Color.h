//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_COLOR_H
#define CLIENT_COLOR_H

#include <string>
#include "data/json/JsonObject.h"
#include "data/json/JsonPrimitive.h"

using namespace std;

class Color : public JsonObject {

    int red;
    int green;
    int blue;

private:
    Color(int red, int green, int blue): red(red), green(green), blue(blue){
        put("red", new JsonPrimitive(to_string(red)));
        put("green", new JsonPrimitive(to_string(green)));
        put("blue", new JsonPrimitive(to_string(blue)));
    }

public:

    static Color* BLACK;
    static Color* BLUE;
    static Color* RED;
    static Color* GREEN;
    static Color* YELLOW;
    static Color* CYAN;
    static Color* ORANGE;


};


#endif //CLIENT_COLOR_H
