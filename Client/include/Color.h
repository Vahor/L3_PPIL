//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_COLOR_H
#define CLIENT_COLOR_H

#include <string>
#include "json/JsonObject.h"
#include "json/JsonPrimitive.h"

using namespace std;

class Color : public JsonObject {

    int red;
    int green;
    int blue;

private:
    Color(int red, int green, int blue): red(red), green(green), blue(blue){
        addChildren("red", new JsonPrimitive(to_string(red)));
        addChildren("green", new JsonPrimitive(to_string(green)));
        addChildren("blue", new JsonPrimitive(to_string(blue)));
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
