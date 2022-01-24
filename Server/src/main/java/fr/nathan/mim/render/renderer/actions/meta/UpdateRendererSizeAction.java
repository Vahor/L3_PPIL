package fr.nathan.mim.render.renderer.actions.meta;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;

public class UpdateRendererSizeAction extends ACORHandler<Pair<DataObject, Renderable>, Renderable> {

    public UpdateRendererSizeAction(Handler<Pair<DataObject, Renderable>, Renderable> next) {
        super(next);
    }

    @Override
    protected Renderable parse(Pair<DataObject, Renderable> input) {
        if (input.getFirst().has("size")) {

            DataObject size = input.getFirst().get("size").getAsObject();
            int width = size.get("width").getAsPrimitive().getAsInt();
            int height = size.get("height").getAsPrimitive().getAsInt();

            input.getSecond().setSize(width, height);
        }
        return null;
    }
}

