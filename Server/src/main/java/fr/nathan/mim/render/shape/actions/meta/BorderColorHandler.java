package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.Constants;
import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;

import java.awt.*;

public class BorderColorHandler extends ACORHandler<Pair<DataObject, AShape>, AShape> {

    public BorderColorHandler(Handler<Pair<DataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<DataObject, AShape> input) {
        if (input.getFirst().has("borderColor")) {
            DataObject color = input.getFirst().get("borderColor").getAsObject();
            input.getSecond().setBorderColor(new Color(
                    color.get("r").getAsPrimitive().getAsInt(),
                    color.get("g").getAsPrimitive().getAsInt(),
                    color.get("b").getAsPrimitive().getAsInt(),
                    color.get("a").getAsPrimitive().getAsInt()
            ));
        }
        else input.getSecond().setBorderColor(Constants.TRANSPARENT_COLOR);
        return null;
    }
}
