#include "client/TCPClient.h"

bool TCPClient::send(const string &data) const {
    if (sock == -1)return false;

    if (::send(sock, data.c_str(), strlen(data.c_str()), 0) < 0) {
        cout << "Send failed : " << data << endl;
        return false;
    }

    return true;
}
