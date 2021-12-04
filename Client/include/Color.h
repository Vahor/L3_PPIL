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

public:
    // Default BLACK
    Color(): red(0), green(0), blue(0){}

    Color(int red, int green, int blue): red(red), green(green), blue(blue){
        put("r", new JsonPrimitive(to_string(red)));
        put("g", new JsonPrimitive(to_string(green)));
        put("b", new JsonPrimitive(to_string(blue)));
    }

    static Color BLACK;
    static Color BLUE;
    static Color RED;
    static Color GREEN;
    static Color YELLOW;
    static Color CYAN;
    static Color ORANGE;


};


#endif //CLIENT_COLOR_H
