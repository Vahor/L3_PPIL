package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderer;

public class InitRendererAction extends ACORHandler<DataObject, Renderer> {

    public InitRendererAction(Handler<DataObject, Renderer> shapeHandler) {super(shapeHandler);}

    @Override
    protected Renderer parse(DataObject input) {
        if (!input.has("INIT")) return null;

        // Taille par défaut si on ne reçoit aucun packet pour modifier la taille par la suite
        Renderer renderer = new Renderer(500, 500);
        renderer.setVisible(true);
        return renderer;
    }
}

