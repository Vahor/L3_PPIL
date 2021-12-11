//
// Created by Nathan David on 11/12/2021.
//

#ifndef CLIENT_DRAWSHAPEPACKET_H
#define CLIENT_DRAWSHAPEPACKET_H

#include "packet/Packet.h"
#include "api/shape/AShape.h"

class DrawShapePacket : public Packet {

    AShape *shape;
public:

    explicit DrawShapePacket(AShape &shape) : shape(&shape) {}
    explicit DrawShapePacket(AShape *shape) : shape(shape) {}

    std::string toString() const {
        return shape->serialize()->toString();
    }


};


#endif //CLIENT_DRAWSHAPEPACKET_H
