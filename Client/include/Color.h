//
// Created by Nathan David on 01/12/2021.
//

#ifndef CLIENT_COLOR_H
#define CLIENT_COLOR_H

#include <string>
#include "data/DataImpl.h"

using namespace std;

class Color : public DataObjectImpl {

    // Utilisation du char car une couleur est entre 0 et 255, comme les char
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;

public:
    // Default BLACK
    Color() : Color(0, 0, 0, 0) {}

    Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) : red(red), green(green),
                                                                                             blue(blue), alpha(alpha) {
        put("r", new DataPrimitiveImpl(to_string(red)));
        put("g", new DataPrimitiveImpl(to_string(green)));
        put("b", new DataPrimitiveImpl(to_string(blue)));
        put("a", new DataPrimitiveImpl(to_string(alpha)));
    }

    static Color TRANSPARENT;
    static Color WHITE;
    static Color BLACK;
    static Color BLUE;
    static Color RED;
    static Color GREEN;
    static Color YELLOW;
    static Color CYAN;
    static Color ORANGE;


};


#endif //CLIENT_COLOR_H
