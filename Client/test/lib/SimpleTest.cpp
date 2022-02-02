#include <iostream>
#include <cmath>
#include "SimpleTest.h"

void SimpleTest::assertTrue(const bool check, std::basic_string<char> s) {
    ++n;
    if (check) {
        ++pass;
        printTestResult(true, s);
    } else {
        ++fail;
        printTestResult(false, s);
    }
} // end

/**
 * Print pass and fail at the end of the tests.
 */
void SimpleTest::stop() const {
    separator();
    std::cout << "RESULTS" << endl;
    separator();
    cout << "Pass: " << pass << endl;
    cout << "Fail: " << fail << endl;
    cout << "Total: " << n << endl;
    cout << "Pass/Total: " << pass << "/" << n << " (" << calculate_percent(pass, n) << "%)" << endl;
    cout << "Fail/Total: " << fail << "/" << n << " (" << calculate_percent(fail, n) << "%)" << endl;
    separator();
} // end

/**
 * Calculate percentage to indicate testing.
 * @param a 		as the numerator
 * @param b 		as the denominator
 * @return 			rounded percentage
 */
float SimpleTest::calculate_percent(size_t a, size_t b) {
    return round((static_cast<float>(a) / static_cast<float>(b)) * 100.0f);
} // end

/**
 * Print pass or fail
 * @param val 			whether the test has passed or failed
 * @param s 			as the string to describe the test
 */
void SimpleTest::printTestResult(bool val, string &s) const {
    string mod = "\033[";
    string pf = mod + "31m FAIL ";
    if (val) pf = mod + "32m PASS ";

    cout << pf << "[" << n << "] " << s << "\033[0m"  << endl;
} // end

