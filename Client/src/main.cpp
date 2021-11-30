#include "client/TCPClient.h"

int main() {
    TCPClient client("127.0.0.1", 10000);
    for (int i = 0; i <5;i++){
        client.send("CHANGE_NAME=" + to_string(i) + "\n");
        client.send("STOP\n");
    }
    return 0;
}
