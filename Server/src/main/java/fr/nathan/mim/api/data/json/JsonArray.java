package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.ADataArray;
import fr.nathan.mim.api.data.ADataElement;

public class JsonArray extends ADataArray {

    public JsonArray(JsonArray jsonArray) {super(jsonArray);}
    public JsonArray()                    {}

    @Override
    public ADataElement clone() {return new JsonArray(this);}

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("[");

        for (int i = 0; i < elements.size(); i++) {
            ADataElement element = elements.get(i);
            res.append(element.toString());

            if ((i + 1) != elements.size()) {
                res.append(",");
            }
        }

        res.append("]");
        return res.toString();
    }
}
