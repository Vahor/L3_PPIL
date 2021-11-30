#ifndef CLIENT_TCPCLIENT_H
#define CLIENT_TCPCLIENT_H

#include <string>
#include <iostream>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

class TCPClient {

    int sock;

    string address;
    int port;


public:

    TCPClient(const string& address, int port) :port(port), address(address)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1){
            cerr << "Could not create socket" << endl;
            return;
        }

        struct sockaddr_in server;
        inet_pton(AF_INET, address.c_str(), &server.sin_addr.s_addr);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        if (connect(sock, (const sockaddr*)&server, sizeof(server)) != 0)
        {

            cerr << "Connection failed: " << to_string(errno) << endl;
            cerr << "address: " << address << endl;
            cerr << "port: " << to_string(port) << endl;
            return;
        }
    }

    bool send(const string& data) const;
    void close() const {
        ::close(sock);
    }

};


#endif //CLIENT_TCPCLIENT_H
