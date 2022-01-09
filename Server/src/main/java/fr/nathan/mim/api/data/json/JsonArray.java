package fr.nathan.mim.api.data.json;

import fr.nathan.mim.api.data.DataArray;
import fr.nathan.mim.api.data.DataElement;

public class JsonArray extends DataArray {

    public JsonArray(JsonArray jsonArray) {super(jsonArray);}
    public JsonArray()                    {}

    @Override
    public DataElement clone() {return new JsonArray(this);}

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder("[");

        for (int i = 0; i < elements.size(); i++) {
            DataElement element = elements.get(i);
            res.append(element.toString());

            if ((i + 1) != elements.size()) {
                res.append(",");
            }
        }

        res.append("]");
        return res.toString();
    }
}
