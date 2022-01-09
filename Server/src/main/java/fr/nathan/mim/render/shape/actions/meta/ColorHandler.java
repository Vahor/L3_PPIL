package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.Constants;
import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;

import java.awt.*;

public class ColorHandler extends ACORHandler<Pair<DataObject, AShape>, AShape> {

    public ColorHandler(Handler<Pair<DataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<DataObject, AShape> input) {
        if (input.getFirst().has("color")) {
            DataObject color = input.getFirst().get("color").getAsObject();
            input.getSecond().setColor(new Color(
                    color.get("r").getAsPrimitive().getAsInt(),
                    color.get("g").getAsPrimitive().getAsInt(),
                    color.get("b").getAsPrimitive().getAsInt(),
                    color.get("a").getAsPrimitive().getAsInt()
            ));
        }
        else input.getSecond().setColor(Constants.TRANSPARENT_COLOR);
        return null;
    }
}
