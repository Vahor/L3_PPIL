#include "client/TCPClient.h"

bool TCPClient::send(const string &data) const {
    if (sock == -1)return false;

    string packet = data;
    packet += "\n";

    if (::send(sock, packet.c_str(), strlen(packet.c_str()), 0) < 0) {
        cout << "Send failed : " << packet << endl;
        return false;
    }

    return true;
}
