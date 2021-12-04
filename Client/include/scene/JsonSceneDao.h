//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_JSONSCENEDAO_H
#define CLIENT_JSONSCENEDAO_H

#include "api/dao/Dao.h"
#include "scene/JsonScene.h"
#include "shapes/handler/ShapeHandler.h"
#include "data/json/JsonParser.h"
#include <fstream>

class JsonSceneDao : public Dao<JsonScene, string> {


    Handler<ADataObject, Shape *> *handler;

    fstream getFileStream(string path, ios_base::openmode mode) const{
        fstream inputFile(path, mode);
        if (!inputFile.is_open()) {
            // todo exception
            cerr << "Le fichier " << path << " n'existe pas" << endl;
        }
        return inputFile;
    }


public:

    JsonSceneDao() {
        handler = new ShapeHandler();
    }

    /**
     *
     * @param id nom de la scene a charger dans le dossier
     * @return La scene correspondante si elle existe.
     *  nullptr sinon
     */
    virtual JsonScene *get(string path) const {
        fstream inputFile = getFileStream(path, ios::in);
        JsonParser parser;
        string jsonFile = string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

        JsonObject *object = parser.parse(jsonFile);
        inputFile.close();
        return JsonScene::parse(*object, handler);
    }

    virtual void save(string path, JsonScene *data) const {
        fstream inputFile = getFileStream(path, ios::out);
        inputFile << data->serialize()->toString();
        inputFile.close();

    }


};


#endif //CLIENT_JSONSCENEDAO_H
