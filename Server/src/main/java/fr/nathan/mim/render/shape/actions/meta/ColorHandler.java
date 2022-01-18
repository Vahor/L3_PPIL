package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.Constants;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.Handler;

import java.awt.*;

public class ColorHandler extends MetaHandler {

    public ColorHandler(Handler<MetaHandler.Parameters, Void> next) {
        super(next);
    }

    @Override
    protected Void parse(Parameters input) {
        if (input.getObject().has("color")) {
            DataObject color = input.getObject().get("color").getAsObject();
            input.getMeta().setColor(new Color(
                    color.get("r").getAsPrimitive().getAsInt(),
                    color.get("g").getAsPrimitive().getAsInt(),
                    color.get("b").getAsPrimitive().getAsInt(),
                    color.get("a").getAsPrimitive().getAsInt()
            ));
        }
        else input.getMeta().setColor(Constants.TRANSPARENT_COLOR);

        return null;
    }
}
