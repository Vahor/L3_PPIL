package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.renderer.RenderableImplSwing;

import java.awt.*;

public class InitRendererAction extends RendererHandler {

    public InitRendererAction(Handler<Parameters, Renderable> next) {super(next);}

    @Override
    protected Renderable parse(Parameters input) {
        if (!input.getObject().has("INIT")) return null;

        Renderable renderable = null;
        try {
            DataObject object = input.getObject().get("INIT").getAsObject();
            String framework = object.get("framework").getAsPrimitive().getAsString();
            DataObject backgroundColorObject = object.get("backgroundColor").getAsObject();

            int height = object.get("height").getAsPrimitive().getAsInt();
            int width = object.get("width").getAsPrimitive().getAsInt();

            Color backgroundColor = new Color(
                        backgroundColorObject.get("r").getAsPrimitive().getAsInt(),
                        backgroundColorObject.get("g").getAsPrimitive().getAsInt(),
                        backgroundColorObject.get("b").getAsPrimitive().getAsInt(),
                        backgroundColorObject.get("a").getAsPrimitive().getAsInt()
                );


            // Il n'y aura pas énormément de frameworks différents possibles
            // Mais dans le cas où il y en a trop, il suffira de faire une classe InitRenderer par framework
            // Et de suivre le même principe que les autres RendererHandler
            switch (framework) {
                case "swing":
                    renderable = new RenderableImplSwing(width, height, backgroundColor);
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

