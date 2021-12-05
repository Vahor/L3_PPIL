//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_JSONSCENEDAO_H
#define CLIENT_JSONSCENEDAO_H

#include "api/dao/Dao.h"
#include "scene/JsonScene.h"
#include "shapes/handler/PolygonHandler.h"
#include "shapes/handler/CircleHandler.h"
#include "meta/handler/VisibilityHandler.h"
#include "meta/handler/ColorHandler.h"
#include "meta/handler/NameHandler.h"
#include "meta/handler/ShowNameHandler.h"
#include "data/json/JsonParser.h"
#include <fstream>

class JsonSceneDao : public Dao<JsonScene, string> {


    Handler<ADataObject, Shape*> *shapeHandler = nullptr;
    Handler<pair<ADataObject *, Shape *>, Shape *> *metaHandler  = nullptr;

    static fstream getFileStream(string &path, ios_base::openmode mode) {
        fstream inputFile(path, mode);
        if (!inputFile.is_open()) {
            // todo exception
            cerr << "Le fichier " << path << " n'existe pas" << endl;
        }
        return inputFile;
    }

    void initShapeHandler() {
        shapeHandler = new PolygonHandler(shapeHandler);
        shapeHandler = new CircleHandler(shapeHandler);
    }

    void initMetaHandler() {
        metaHandler = new ColorHandler(metaHandler);
        metaHandler = new VisibilityHandler(metaHandler);
        metaHandler = new NameHandler(metaHandler);
        metaHandler = new ShowNameHandler(metaHandler);
    }


public:

    JsonSceneDao() {
        initShapeHandler();
        initMetaHandler();
    }

    /**
     *  Récumère le fichier depuis {path} et le transforme en un JsonScene
     *
     * @param id nom de la scene a charger dans le dossier
     * @return La scene correspondante si elle existe.
     *  nullptr sinon
     */
    JsonScene *get(string path) const override {
        fstream inputFile = getFileStream(path, ios::in);
        JsonParser parser;
        string jsonFile = string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

        JsonObject *object = parser.parse(jsonFile);
        inputFile.close();
        return JsonScene::parse(*object, shapeHandler, metaHandler);
    }

    /**
     * Sauvegarde {data} dans un fichier situé en {path}.
     * Créé le fichier si il n'existe pas, et remplace son contenu.
     *
     * @param path Chemin vers le fichier à sauvegarder
     * @param data Donnés à sauvegarder
     */
    void save(string path, JsonScene *data) const override {
        fstream inputFile = getFileStream(path, ios::out);
        inputFile << data->serialize()->toString();
        inputFile.close();

    }


};


#endif //CLIENT_JSONSCENEDAO_H
