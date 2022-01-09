package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.shapes.AShape;

public class IdHandler extends ACORHandler<Pair<DataObject, AShape>, AShape> {

    public IdHandler(Handler<Pair<DataObject, AShape>, AShape> next) {
        super(next);
    }

    @Override
    protected AShape parse(Pair<DataObject, AShape> input) {
        if (input.getFirst().has("id")) {
            input.getSecond().setId(input.getFirst().get("id").getAsPrimitive().getAsInt());
        }
        return null;
    }
}
