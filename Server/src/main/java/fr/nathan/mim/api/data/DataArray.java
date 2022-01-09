package fr.nathan.mim.api.data;

import java.util.ArrayList;
import java.util.List;

public abstract class DataArray extends DataElement {

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
}
