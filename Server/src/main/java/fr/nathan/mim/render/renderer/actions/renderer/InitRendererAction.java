package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.renderer.RenderableImplSwing;

public class InitRendererAction extends RendererHandler {

    public InitRendererAction(Handler<Parameters, Renderable> next) {super(next);}

    @Override
    protected Renderable parse(Parameters input) {
        if (!input.getObject().has("INIT")) return null;

        Renderable renderable = null;
        try {
            String framework = input.getObject().get("INIT").getAsPrimitive().getAsString();

            // Il n'y aura pas énormément de frameworks différents possibles
            // Mais dans le cas où il y en a trop, il suffira de faire une classe InitRenderer par framework
            // Et de suivre le même principe que les autres RendererHandler
            switch (framework) {
                case "swing":
                    renderable = new RenderableImplSwing(900, 500);
                    break;
                default:
                    throw new IllegalArgumentException("No match found for framework: " + framework);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        return renderable;
    }
}

