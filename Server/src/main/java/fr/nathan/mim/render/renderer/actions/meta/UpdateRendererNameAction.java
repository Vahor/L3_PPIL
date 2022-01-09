package fr.nathan.mim.render.renderer.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderer;

public class UpdateRendererNameAction extends ACORHandler<Pair<DataObject, Renderer>, Renderer> {

    public UpdateRendererNameAction(Handler<Pair<DataObject, Renderer>, Renderer> next) {
        super(next);
    }

    @Override
    protected Renderer parse(Pair<DataObject, Renderer> input) {
        if (input.getFirst().has("name")) {
            input.getSecond().setTitle(input.getFirst().get("name").getAsPrimitive().getAsString());
        }
        return null;
    }
}

