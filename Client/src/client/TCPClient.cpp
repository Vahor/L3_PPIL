#include "client/TCPClient.h"

TCPClient *TCPClient::instance_ = {nullptr};

bool TCPClient::send(const string &data) const {
    if (sock == -1) return false;

    string packet = data;
    packet += "\n";

    cout << packet << endl;

    if (::send(sock, packet.c_str(), strlen(packet.c_str()), 0) < 0) {
        cerr << "Send failed : " << packet << endl;
        return false;
    }

    return true;
}


TCPClient *TCPClient::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new TCPClient();
    }
    return instance_;
}