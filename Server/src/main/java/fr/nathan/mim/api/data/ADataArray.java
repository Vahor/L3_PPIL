package fr.nathan.mim.api.data;

import java.util.ArrayList;
import java.util.List;

public abstract class ADataArray extends ADataElement {

    protected List<ADataElement> elements;

    public ADataArray(ADataArray copy) {
        elements = new ArrayList<>(copy.elements.size());
        copy.elements.forEach(this::add);
    }

    public ADataArray() {elements = new ArrayList<>();}

    public void add(ADataElement element) {
        elements.add(element.clone());
    }
}
