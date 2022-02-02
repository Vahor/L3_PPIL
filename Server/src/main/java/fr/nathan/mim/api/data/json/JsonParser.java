package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.*;

import java.util.Map;

public class JsonParser extends Parser {

    @Override
    public DataObject parse(String input) {
        return parseObject(input.substring(1)).getFirst();
    }

    private Pair<DataArray, Integer> parseArray(String input) {
        DataArray array = new DataArray();
        JsonTokenParser token;
        long length = input.length();
        do {
            token = JsonTokenParser.getNextToken(input);
            input = input.substring(token.getPosition()); // On avance à la fin de ce token

            if (token.getType() == JsonToken.ARRAY_CLOSE || token.getType() == JsonToken.UNKNOWN) {
                break;
            }

            switch (token.getType()) {
                case STRING: {
                    array.add(new DataPrimitive(token.getValue()));
                    input = input.substring(token.getPosition()); // On avance à la fin de la valeur
                    break;
                }
                case CURLY_OPEN: {
                    input = input.substring(
                            JsonTokenParser.getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                    Pair<DataObject, Integer> res = parseObject(input);
                    array.add(res.getFirst());
                    input = input.substring(res.getSecond() + 1); // On avance à la fin de l'objet

                    break;
                }
                case ARRAY_OPEN: {
                    input = input.substring(JsonTokenParser.getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                    Pair<DataArray, Integer> res = parseArray(input);
                    array.add(res.getFirst());
                    input = input.substring(res.getSecond() + 1); // On avance à la fin de la liste

                    break;
                }
            }

        } while (token.getType() != JsonToken.ARRAY_CLOSE && token.getType() != JsonToken.UNKNOWN);

        return new Pair<>(array, (int) length - input.length());
    }

    private Pair<DataObject, Integer> parseObject(String input) {

        DataObject object = new DataObject();
        JsonTokenParser token;
        long length = input.length();
        do {
            // Pour la clé du token on récupère le token actuel
            token = JsonTokenParser.getNextToken(input);
            input = input.substring(token.getPosition()); // On avance à la fin de ce token
            String key = token.getValue();

            if (token.getType() == JsonToken.CURLY_CLOSE || token.getType() == JsonToken.UNKNOWN) {
                break;
            }

            // Pour récupérer la valeur, on va voir le prochain token
            token = JsonTokenParser.getNextToken(input);
            switch (token.getType()) {
                case STRING: {
                    object.put(key, new DataPrimitive(token.getValue()));
                    input = input.substring(token.getPosition()); // On avance à la fin de la valeur
                    break;
                }
                case CURLY_OPEN: {
                    input = input.substring(
                            JsonTokenParser.getNextTokenPosition(input, '{') + 1); // On avance au début de ce token
                    Pair<DataObject, Integer> res = parseObject(input);
                    object.put(key, res.getFirst());
                    input = input.substring(res.getSecond() + 1); // On avance à la fin de la liste

                    break;
                }
                case ARRAY_OPEN: {
                    input = input.substring(
                            JsonTokenParser.getNextTokenPosition(input, '[') + 1); // On avance au début de ce token
                    Pair<DataArray, Integer> res = parseArray(input);
                    object.put(key, res.getFirst());
                    input = input.substring(res.getSecond() + 1); // On avance à la fin de la liste

                    break;
                }
            }

        } while (token.getType() != JsonToken.CURLY_CLOSE && token.getType() != JsonToken.UNKNOWN);

        return new Pair<>(object, (int) length - input.length());
    }

    //////

    @Override
    public String toString(DataObject object) {
        StringBuilder res = new StringBuilder("{");

        for (Map.Entry<String, DataElement> entry : object.getChildren().entrySet()) {
            res.append('"').append(entry.getKey()).append("\":");
            res.append(entry.getValue().toString());
            res.append(",");
        }

        if (res.length() > 1)
            res.setLength(res.length() - 1);

        res.append("}");
        return res.toString();
    }

    @Override
    public String toString(DataArray array) {
        StringBuilder res = new StringBuilder("[");

        for (DataElement element : array.getElements()) {
            res.append(element.toString());
            res.append(",");
        }


        if (res.length() > 1)
            res.setLength(res.length() - 1);

        res.append("]");
        return res.toString();
    }

    @Override
    public String toString(DataPrimitive primitive) {
        return '"' + primitive.getAsString() + '"';
    }
}
