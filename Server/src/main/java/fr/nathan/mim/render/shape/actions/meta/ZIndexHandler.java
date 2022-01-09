package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;

public class ZIndexHandler extends ACORHandler<Pair<DataObject, AShape>, AShape> {

    public ZIndexHandler(Handler<Pair<DataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<DataObject, AShape> input) {
        if (input.getFirst().has("zIndex")) {
            input.getSecond().setZIndex(input.getFirst().get("zIndex").getAsPrimitive().getAsInt());
        }
        return null;
    }
}
