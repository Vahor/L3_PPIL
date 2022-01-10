#pragma once


#include <string>
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "client/Client.h"
#include "actions/Action.h"

using namespace std;

class TCPClient : public Client {

    int sock;

    string address;
    int port;


public:

    TCPClient(const string &address, int port) : port(port), address(address) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            throw std::runtime_error("Could not create socket");
        }

        struct sockaddr_in server{};
        inet_pton(AF_INET, address.c_str(), &server.sin_addr.s_addr);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (connect(sock, (const sockaddr *) &server, sizeof(server)) != 0) {

            cerr << "Connection failed: " << to_string(errno) << endl;
            cerr << "address: " << address << endl;
            cerr << "port: " << to_string(port) << endl;
            throw std::runtime_error("Connection failed");
        }
    }

    bool send(const string &data) const override;
    void close() const override {
        ::close(sock);
    }

};



