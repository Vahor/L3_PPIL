#pragma once

#include <cstdint>
#include <string>
#include <iostream>

using namespace std;

class SimpleTest {
private:
    static float calculate_percent(size_t a, size_t b);
    void printTestResult(bool val, string &s) const;
    static void separator() {
        cout << "--------------------------------------------------------------------" << endl;
    }
    size_t pass;        // number of passes
    size_t fail;        // number of fails
    size_t n;            // number of tests

public:
    void assertTrue(bool check, string s);
    static void divider(const string &s) {
        separator();
        cout << s << std::endl;
        separator();
    }

    void stop() const;
}; // end



