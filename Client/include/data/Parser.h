//
// Created by Nathan David on 04/12/2021.
//
#pragma once

#include "DataObject.h"

class Parser {

public:
    /**
     * Transforme une chaine de caracteres en un DataObject
     *
     * @param input L'information à transformer
     * @return Un DataObject correspondant à l'entrée
     */
    virtual DataObject parse(const string &input) const = 0;
    /**
     * Extension supportée par ce Parser
     * @return Une chaine de caractère correspondant à une extension de fichier que ce parser supporte.
     */
    virtual string supportedExtension() const = 0;

    /**
     * Transforme un DataObject en une chaine de caractere.<br/>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param object L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entrée
     */
    virtual string serialize(const DataObject *object) const = 0;

    /**
     * Transforme un DataArray en une chaine de caractere.<br/>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param array L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entrée
     */
    virtual string serialize(const DataArray *array) const = 0;

    /**
     * Transforme un DataPrimitive en une chaine de caractere.<br/>
     * Cette chaine est utilisable par {@link Parser#parse(String)}
     *
     * @param primitive L'information à transformer
     * @return Une chaine de caractere correspondant à l'objet entrée
     */
    virtual string serialize(const DataPrimitive *primitive) const = 0;
};

