package fr.nathan.mim.render.renderer.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;

public class UpdateRendererNameAction extends ACORHandler<Pair<DataObject, Renderable>, Renderable> {

    public UpdateRendererNameAction(Handler<Pair<DataObject, Renderable>, Renderable> next) {
        super(next);
    }

    @Override
    protected Renderable parse(Pair<DataObject, Renderable> input) {
        if (input.getFirst().has("name")) {
            input.getSecond().setTitle(input.getFirst().get("name").getAsPrimitive().getAsString());
        }
        return null;
    }
}

