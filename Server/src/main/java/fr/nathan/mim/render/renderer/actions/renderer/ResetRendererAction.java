package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;

public class ResetRendererAction extends RendererHandler {

    public ResetRendererAction(Handler<Parameters, Renderable> next) {super(next);}

    @Override
    protected Renderable parse(Parameters input) {
        if (!input.getObject().has("RESET")) return null;

        input.getCurrentRenderable().resetGraphics();
        input.getCurrentRenderable().resetScene();
        return null;
    }
}

