//
// Created by Nathan David on 04/12/2021.
//

#ifndef CLIENT_SCENEDAO_H
#define CLIENT_SCENEDAO_H

#include "api/dao/Dao.h"
#include "scene/AScene.h"
#include "data/json/JsonParser.h"
#include <fstream>

#include "shapes/handler/PolygonHandler.h"
#include "shapes/handler/GroupHandler.h"
#include "shapes/handler/CircleHandler.h"

#include "meta/handler/VisibilityHandler.h"
#include "meta/handler/ColorHandler.h"
#include "meta/handler/BorderColorHandler.h"
#include "meta/handler/ZIndexHandler.h"
#include "meta/handler/IdHandler.h"

class SceneDao : public Dao<AScene, string> {


    Handler<ADataObject, AShape *> *shapeHandler = nullptr;
    Handler<pair<ADataObject *, AShape *>, AShape *> *metaHandler = nullptr;

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
        shapeHandler = new GroupHandler(shapeHandler, metaHandler);
    }

    void initMetaHandler() {
        metaHandler = new ColorHandler(metaHandler);
        metaHandler = new BorderColorHandler(metaHandler);
        metaHandler = new VisibilityHandler(metaHandler);
        metaHandler = new ZIndexHandler(metaHandler);
        metaHandler = new IdHandler(metaHandler);
    }


public:

    SceneDao() {
        initMetaHandler();
        initShapeHandler();
    }

    /**
     *  Récumère le fichier depuis {path} et le transforme en un JsonScene
     *
     * @param id nom de la scene a charger dans le dossier
     * @return La scene correspondante si elle existe.
     *  nullptr sinon
     */
    AScene *get(string path) const override {
        fstream inputFile = getFileStream(path, ios::in);
        JsonParser parser;
        string jsonFile = string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

        ADataObject *object = parser.parse(jsonFile);
        inputFile.close();
        return get(*object);
    }

    AScene *get(const ADataObject &object) const {
        return AScene::parse(object, shapeHandler, metaHandler);
    }

    /**
     * Sauvegarde {data} dans un fichier situé en {path}.
     * Créé le fichier si il n'existe pas, et remplace son contenu.
     *
     * @param path Chemin vers le fichier à sauvegarder
     * @param data Donnés à sauvegarder
     */
    void save(string path, AScene *data) const override {
        fstream inputFile = getFileStream(path, ios::out);
        inputFile << data->serialize()->toString();
        inputFile.close();
    }


};


#endif //CLIENT_SCENEDAO_H