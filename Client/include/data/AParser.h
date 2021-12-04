//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_APARSER_H
#define CLIENT_APARSER_H

#include "data/ADataObject.h"

class AParser {

public:
    virtual ADataObject *parse(string input) const = 0;

};


#endif //CLIENT_APARSER_H
