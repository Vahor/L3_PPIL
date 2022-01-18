package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.renderer.RenderableImpl;

public class InitRendererAction extends RendererHandler {

    public InitRendererAction(Handler<Parameters, Renderable> next) {super(next);}

    @Override
    protected RenderableImpl parse(Parameters input) {
        if (!input.getObject().has("INIT")) return null;

        RenderableImpl renderable = null;
        try {
            // Taille par défaut si on ne reçoit aucun packet pour modifier la taille par la suite
            renderable = new RenderableImpl(900, 500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return renderable;
    }
}

