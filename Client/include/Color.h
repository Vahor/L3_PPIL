//
// Created by Nathan David on 01/12/2021.
//
#pragma once

#include <string>
#include "data/DataObject.h"
#include "data/DataPrimitive.h"

class Color : public DataObject {

    // Utilisation du char, car une couleur est entre 0 et 255, comme le char
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;

public:
    // Default TRANSPARENT
    Color() : Color(0, 0, 0, 0) {}

    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : red(red), green(green),
                                                                                             blue(blue), alpha(alpha) {
        put("r", new DataPrimitive(to_string(red)));
        put("g", new DataPrimitive(to_string(green)));
        put("b", new DataPrimitive(to_string(blue)));
        put("a", new DataPrimitive(to_string(alpha)));
    }

    static Color *TRANSPARENT;
    static Color *WHITE;
    static Color *BLACK;
    static Color *BLUE;
    static Color *RED;
    static Color *GREEN;
    static Color *YELLOW;
    static Color *CYAN;
    static Color *ORANGE;

    inline bool operator==(const Color &other) const {
        return red == other.red &&
               green == other.green &&
               blue == other.blue &&
               alpha == other.alpha;
    }
    inline bool operator!=(const Color &other) const {
        return !(*this == other);
    }


};
