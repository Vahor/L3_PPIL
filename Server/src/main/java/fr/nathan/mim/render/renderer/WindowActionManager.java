package fr.nathan.mim.render.renderer;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.actions.meta.UpdateRendererNameAction;
import fr.nathan.mim.render.renderer.actions.meta.UpdateRendererSizeAction;
import fr.nathan.mim.render.renderer.actions.renderer.DisposeRendererAction;
import fr.nathan.mim.render.renderer.actions.renderer.InitRendererAction;
import fr.nathan.mim.render.renderer.actions.renderer.RendererHandler;
import fr.nathan.mim.render.renderer.actions.renderer.ResetRendererAction;

public class WindowActionManager {

    private RendererHandler rendererHandler;
    private Handler<Pair<DataObject, Renderable>, Renderable> metaHandler;

    public WindowActionManager() {
        initShapeHandler();
        initMetaHandler();
    }

    void initShapeHandler() {
        rendererHandler = new InitRendererAction(rendererHandler);
        rendererHandler = new ResetRendererAction(rendererHandler);
        rendererHandler = new DisposeRendererAction(rendererHandler);
    }

    void initMetaHandler() {
        metaHandler = new UpdateRendererNameAction(metaHandler);
        metaHandler = new UpdateRendererSizeAction(metaHandler);
    }

    public Renderable handleAction(DataObject object, Renderable currentDrawing) {
        DataObject elementMeta = object.get("meta").getAsObject();

        // Si les informations de l'action ne demandent pas à créer un nouveau renderer.
        // On utilise celui existant.
        Renderable drawing = rendererHandler.solve(new RendererHandler.Parameters(elementMeta, currentDrawing));
        if (drawing == null)
            drawing = currentDrawing;

        metaHandler.solve(new Pair<>(elementMeta, drawing));

        return drawing;
    }
}
