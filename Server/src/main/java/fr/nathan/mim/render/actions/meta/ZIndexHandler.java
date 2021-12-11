package fr.nathan.mim.render.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shapes.AShape;

import java.awt.*;

public class ZIndexHandler extends ACORHandler<Pair<ADataObject, AShape>, AShape> {

    public ZIndexHandler(Handler<Pair<ADataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<ADataObject, AShape> input) {
        if (input.getFirst().has("zIndex")) {
            input.getSecond().setZIndex(input.getFirst().get("zIndex").getAsPrimitive().getAsInt());
        }
        return null;
    }
}
