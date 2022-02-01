//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include "actions/Action.h"
#include "client/TCPClient.h"


class RendererAction : public Action {

protected:
    virtual DataObject *getMetaData() const = 0;
public:

    void execute() const override {
        TCPClient *client = TCPClient::getInstance();

        auto object = DataObject();
        auto data = DataObject();
        auto meta = getMetaData();

        data.put("meta", meta);
        object.put("WINDOW", data);

        client->send(object.toString());

        delete meta;
    }
};