package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;

public class DisposeRendererAction extends RendererHandler {

    public DisposeRendererAction(Handler<Parameters, Renderable> next) {super(next);}

    @Override
    protected Renderable parse(Parameters input) {
        if (!input.getObject().has("DISPOSE")) return null;

        input.getCurrentRenderable().disposeBuffer();

        return null;
    }
}

