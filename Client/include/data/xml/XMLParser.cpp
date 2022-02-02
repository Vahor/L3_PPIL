//
// Created by Nathan David on 02/02/2022.
//

#include "XMLParser.h"
#include "XMLToken.h"


pair<DataArray, int> XMLParser::parseArray(string input) {
    throw std::runtime_error("XMLParser::parseArray not implemented");
//    auto array = DataArray();
//    unsigned long length = input.length();
//    return {array, length - input.length()};
}

pair<DataObject, int> XMLParser::parseObject(string input) {
    throw std::runtime_error("XMLParser::parseObject not implemented");
//    auto object = DataObject();
//    TokenXML token;
//    unsigned long length = input.length();
//
//    do {
//        // Pour la clé du token on récupère le token actuel
//        token = XMLToken::getNextToken(input);
//        input = input.substr(token.position); // On avance à la fin de ce token
//        string key = token.key;
//
//
//        if (token.type == TYPE::CLOSE || token.type == TYPE::UNKNOWN) {
//            break;
//        }
//
//        input = input.substr(XMLToken::getNextTokenPosition(input, '>') + 1); // On avance au début de ce token
//
//        cout << "> ===" << endl;
//        cout << input << endl;
//        cout << "key : " << token.key << endl;
//        cout << "value : " << token.value << endl;
//        cout << "type : " << token._type << endl;
//        cout << "key : " << key << endl;
//        cout << "< ===" << endl;
//
//
//        switch (token.type) {
//            case TYPE::OBJECT: {
//                pair<DataObject, int> res = parseObject(input);
//                object.put(key, res.first);
//                break;
//            }
//            case TYPE::PRIMITIVE: {
//                object.put(key, DataPrimitive(token.value));
//                break;
//            }
//            case TYPE::ARRAY: {
//                pair<DataArray, int> res = parseArray(input);
//                object.put(key, res.first);
//            }
//            default:
//                break;
//        }
//    } while (token.type != TYPE::CLOSE && token.type != TYPE::UNKNOWN);
//
//
//    return {object, length - input.length()};
}

string XMLParser::serialize(const DataObject *object) const {
    string res;

    DataElement *parent = object->getParent();
    if (parent == nullptr) {
        res += "<root type=\"root\">";
    }

    for (const auto &it: object->getChildren()) {
        DataElement *element = it.second;
        res += '<' + it.first + " type=\"" + element->getType() + "\">";
        res += element->serialize(*this);

        res += "</" + it.first + ">";
    }

    if (parent == nullptr) {
        res += "</root>";
    }

    return res;
}
string XMLParser::serialize(const DataArray *array) const {
    string res;

    for (auto it: *array) {
        DataElement *element = it;
        res += element->serialize(*this);
    }

    return res;
}
string XMLParser::serialize(const DataPrimitive *primitive) const {
    return '"' + primitive->getAsString() + '"';
}
