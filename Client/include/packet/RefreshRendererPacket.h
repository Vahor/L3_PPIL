//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_REFRESHRENDERERPACKET_H
#define CLIENT_REFRESHRENDERERPACKET_H

#include "packet/Packet.h"

class RefreshRendererPacket : public Packet {

    std::string toString() const {
        return "REFRESH";
    }
};


#endif //CLIENT_REFRESHRENDERERPACKET_H
