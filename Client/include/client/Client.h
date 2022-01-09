//
// Created by Nathan David on 09/01/2022.
//
#pragma once


#include <string>

class Client {

public:

    virtual bool send(const std::string &data) const = 0;
    virtual void close() const = 0;
};


