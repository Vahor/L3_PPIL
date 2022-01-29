//
// Created by Nathan David on 04/12/2021.
//

#pragma once

#include "dao/Dao.h"
#include "scene/Scene.h"
#include "data/json/JsonParser.h"
#include <fstream>

#include "shapes/Shape.h"
#include "shapes/handler/PolygonHandler.h"
#include "shapes/handler/GroupHandler.h"
#include "shapes/handler/CircleHandler.h"
#include "shapes/handler/TextHandler.h"

#include "meta/handler/ColorHandler.h"
#include "meta/handler/BorderColorHandler.h"
#include "meta/handler/IdHandler.h"

class SceneDao : public Dao<Scene, string> {

    Parser *parser = nullptr;
    Handler<DataObject, Shape *> *shapeHandler = nullptr;
    Handler<pair<DataObject *, Shape *>, Shape *> *metaHandler = nullptr;
    Scene *currentScene = nullptr;

    static fstream getFileStream(string &path, ios_base::openmode mode) {
        fstream inputFile(path, mode);
        if (!inputFile.is_open()) {
            throw std::runtime_error("Le fichier " + path + " n'existe pas");
        }
        return inputFile;
    }

    void initShapeHandler() {
        shapeHandler = new PolygonHandler(shapeHandler);
        shapeHandler = new CircleHandler(shapeHandler);
        shapeHandler = new TextHandler(shapeHandler);
        shapeHandler = new GroupHandler(shapeHandler, metaHandler);
    }

    void initMetaHandler() {
        metaHandler = new ColorHandler(metaHandler);
        metaHandler = new BorderColorHandler(metaHandler);
        metaHandler = new IdHandler(metaHandler);
    }


    static SceneDao *instance_;

    bool isParserAlreadyActive(const string &format) {
        return parser != nullptr && parser->supportedExtensions() == format;
    }


protected:
    ~SceneDao() = default;

    SceneDao() {
        initMetaHandler();
        initShapeHandler();
        parser = new JsonParser; // default
    }


public:

    SceneDao(SceneDao &o) = delete;
    void operator=(const SceneDao &) = delete;

    /**
     *  Récupère le fichier depuis {path} et le transforme en un JsonScene
     *
     * @param id nom de la scene a charger dans le dossier
     * @return La scene correspondante si elle existe.
     *  nullptr sinon
     */
    Scene *get(string path) override {
        fstream inputFile = getFileStream(path, ios::in);
        string jsonFile = string((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

        DataObject *object = parser->parse(jsonFile);
        inputFile.close();
        Scene *scene = get(*object);
        return scene;
    }

    Scene *get(const DataObject &object) const {
        return Scene::parse(object, shapeHandler, metaHandler);
    }

    /**
     * Sauvegarde {data} dans un fichier situé en {path}.
     * Créé le fichier si il n'existe pas, et remplace son contenu.
     *
     * @param path Chemin vers le fichier à sauvegarder
     * @param data Donnés à sauvegarder
     */
    void save(string path, Scene *data) override {
        fstream inputFile = getFileStream(path, ios::out);
        inputFile << data->serialize(true)->toString();
        inputFile.close();
    }

    /**
     * Modifie le type de parser à utiliser
     *
     * @param format Extension de fichier qui doit être supportée par le parser
     */
    void setParser(const string &format) {
        if (isParserAlreadyActive(format)) return;

        // On sait qu'il n'y aura pas une infinité de formats,
        // un simple if else est suffisant ici
        if (format == "json") {
            parser = new JsonParser();
        } else {
            throw std::runtime_error("Unknown format '" + format + "'");
        }
    }

    Parser *getParser() const {
        return parser;
    }

    Scene *getCurrentScene() const { return currentScene; };
    void setCurrentScene(Scene *v) { this->currentScene = v; }

    static SceneDao *getInstance();

};




