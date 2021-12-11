//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_INITRENDERERPACKET_H
#define CLIENT_INITRENDERERPACKET_H

#include "packet/Packet.h"

class InitRendererPacket : public Packet {

    std::string toString() const {
        return "INIT";
    }
};


#endif //CLIENT_INITRENDERERPACKET_H
