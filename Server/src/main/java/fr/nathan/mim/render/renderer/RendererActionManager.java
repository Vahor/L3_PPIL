package fr.nathan.mim.render.renderer;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.actions.meta.UpdateRendererNameAction;
import fr.nathan.mim.render.renderer.actions.meta.UpdateRendererSizeAction;
import fr.nathan.mim.render.renderer.actions.renderer.InitRendererAction;

public class RendererActionManager {

    private Handler<DataObject, Renderer> rendererHandler;
    private Handler<Pair<DataObject, Renderer>, Renderer> metaHandler;

    public RendererActionManager() {
        initShapeHandler();
        initMetaHandler();
    }

    void initShapeHandler() {
        rendererHandler = new InitRendererAction(rendererHandler);
    }

    void initMetaHandler() {
        metaHandler = new UpdateRendererNameAction(metaHandler);
        metaHandler = new UpdateRendererSizeAction(metaHandler);
    }

    public Renderer handleAction(DataObject object, Renderer currentRenderer) {
        System.out.println("RendererActionManager.handleAction");
        System.out.println("object = " + object);

        // Si les informations de l'action ne demandent pas à créer un nouveau renderer.
        // On utilise celui existant.
        Renderer renderer = rendererHandler.solve(object);
        if (renderer == null)
            renderer = currentRenderer;

        if (object.has("meta")) {
            DataObject elementMeta = object.get("meta").getAsObject();
            metaHandler.solve(new Pair<>(elementMeta, renderer));
        }

        return renderer;
    }
}
