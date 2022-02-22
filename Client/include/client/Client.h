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

    /**
     * Ouvre la connexion vers le serveur de dessin.
     *
     * @param address IP addresse du serveur de dessin
     * @param port port du serveur de dessin
     */
    virtual void connect(const string &address, int port) = 0;

    /**
     * Envoie une chaine de caractere vers le serveur de dessin.
     *
     * @param data Message à envoyer
     * @return true si le message a été envoyé, false autrement
     */
    virtual bool send(const string &data) const = 0;

    /**
     * Ferme la connexion avec le serveur de dessin.
     */
    virtual void disconnect() const = 0;

    /**
     * Force une tentative de reconnexion avec le serveur de dessin
     *
     * @see Client.disconnect
     * @see Client.connect
     */
    virtual void reconnect() {
        disconnect();
        connect(address, port);
    }


    const string &getAddress() const { return address; }
    int getPort() const { return port; }


};


