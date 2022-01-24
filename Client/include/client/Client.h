//
// Created by Nathan David on 09/01/2022.
//
#pragma once


#include <string>

using std::string;

class Client {

protected:

    string address;
    int port;

public:

    virtual void connect(const string &address, int port) = 0;
    virtual bool send(const string &data) const = 0;
    virtual void close() const = 0;

    const string &getAddress() const { return address; }
    int getPort() const { return port; }


};


