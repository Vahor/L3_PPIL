//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_COLOR_H
#define CLIENT_COLOR_H

#include <string>
#include "data/DataImpl.h"

using namespace std;

class Color : public DataObjectImpl {

    int red;
    int green;
    int blue;

public:
    // Default BLACK
    Color(): red(0), green(0), blue(0){}

    Color(int red, int green, int blue): red(red), green(green), blue(blue){
        put("r", new DataPrimitiveImpl(to_string(red)));
        put("g", new DataPrimitiveImpl(to_string(green)));
        put("b", new DataPrimitiveImpl(to_string(blue)));
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
