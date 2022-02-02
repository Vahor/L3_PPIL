//
// Created by Nathan David on 04/12/2021.
//

#include "../lib/SimpleTest.h"

#include "scene/SceneDao.h"
#include "data/json/JsonParser.h"
#include "scene/Scene.h"
#include <string>
#include <algorithm>

using namespace std;

class JSON_PARSER {

public:


    static void runTest(SimpleTest &test) {
        SimpleTest::divider("JSON_PARSER");

        JsonParser parser;
        testString(test, parser, R"({"WINDOW":{"meta":{"INIT":{"framework":"swing","height":"500","width":"1000"}}}})");
        testString(test, parser, R"({})");
        testString(test, parser, R"({"test":"1"})");
    }

    static void testString(SimpleTest &test, JsonParser &parser, const string &s) {

        DataElement *object = parser.parse(s);
        test.assertTrue(object != nullptr, "Not null");
        test.assertTrue(object->serialize(parser) == s, "Equals");
    }
};

