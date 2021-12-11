package fr.nathan.mim.render.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shapes.AShape;

import java.awt.*;

public class IdHandler extends ACORHandler<Pair<ADataObject, AShape>, AShape> {

    public IdHandler(Handler<Pair<ADataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<ADataObject, AShape> input) {
        if (input.getFirst().has("id")) {
            input.getSecond().setId(input.getFirst().get("id").getAsPrimitive().getAsInt());
        }
        return null;
    }
}
