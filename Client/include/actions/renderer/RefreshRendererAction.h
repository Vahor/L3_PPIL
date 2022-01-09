//
// Created by Nathan David on 11/12/2021.
//
#pragma once


#include "actions/Action.h"

class RefreshRendererAction : public Action {

public:
    void execute(const Client *client) const override {
        client->send("REFRESH");
    }
};



