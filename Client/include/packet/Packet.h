//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_PACKET_H
#define CLIENT_PACKET_H

#include <string>

class Packet {


public:
    virtual std::string toString() const = 0;
};


#endif //CLIENT_PACKET_H
