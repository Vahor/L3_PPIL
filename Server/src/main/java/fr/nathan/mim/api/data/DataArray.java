package fr.nathan.mim.api.data;

import fr.nathan.mim.Main;

import java.util.ArrayList;
import java.util.List;

public class DataArray extends DataElement {

    protected List<DataElement> elements;

    public DataArray(DataArray copy) {
        elements = new ArrayList<>(copy.elements.size());
        copy.elements.forEach(this::add);
    }

    public DataArray() {elements = new ArrayList<>();}

    public void add(DataElement element) {
        elements.add(element.clone());
    }

    public List<DataElement> getElements() {
        return elements;
    }

    @Override
    public DataArray clone() {return new DataArray(this);}

    @Override
    public String toString() {
        return Main.currentParser.toString(this);
    }
}
