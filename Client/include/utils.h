//
// Created by Nathan David on 10/01/2022.
//

#pragma once

#include <vector>
#include <string>

using std::string;
using std::vector;

static vector<string> split(const string &input, const char &delimiter) {
    vector<string> args;
    string current;

    for (auto x: input) {
        if (x != delimiter)
            current += x;
        else {
            args.push_back(current);
            current = "";
        }
    }

    if (!current.empty())
        args.push_back(current);

    return args;
}