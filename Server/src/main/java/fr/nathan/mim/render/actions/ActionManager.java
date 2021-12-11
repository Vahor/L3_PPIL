package fr.nathan.mim.render.actions;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.api.data.json.JsonParser;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.meta.BorderColorHandler;
import fr.nathan.mim.render.actions.meta.ColorHandler;
import fr.nathan.mim.render.actions.meta.IdHandler;
import fr.nathan.mim.render.actions.meta.ZIndexHandler;
import fr.nathan.mim.render.actions.shapes.CircleHandler;
import fr.nathan.mim.render.shapes.AShape;

public class ActionManager {

    private final JsonParser parser = new JsonParser();

    private Handler<ADataObject, AShape> shapeHandler;
    private Handler<Pair<ADataObject, AShape>, AShape> metaHandler;

    public ActionManager() {
        initShapeHandler();
        initMetaHandler();
    }

    void initShapeHandler() {
        shapeHandler = new CircleHandler(shapeHandler);
    }

    void initMetaHandler() {
        metaHandler = new IdHandler(metaHandler);
        metaHandler = new BorderColorHandler(metaHandler);
        metaHandler = new ColorHandler(metaHandler);
        metaHandler = new ZIndexHandler(metaHandler);
//        metaHandler = new VisibilityHandler(metaHandler);
//        metaHandler = new NameHandler(metaHandler);
//        metaHandler = new ShowNameHandler(metaHandler);
    }

    public void handleAction(String rawData, Renderer currentRenderer) {

        ADataObject object = parser.parse(rawData).getAsObject();

        AShape shape = tryGetShape(object, currentRenderer);
        if (shape == null)
            shape = shapeHandler.solve(object);

        if (shape != null) {
            if (object.has("meta")) {
                ADataObject elementMeta = object.get("meta").getAsObject();
                metaHandler.solve(new Pair<>(elementMeta, shape));
            }

            if (!shape.isRendered()) currentRenderer.addShape(shape);
        }

    }

    public AShape tryGetShape(ADataObject object, Renderer currentRenderer) {
        if (object.has("meta")) {
            ADataObject elementMeta = object.get("meta").getAsObject();
            if (elementMeta.has("id")) {
                return currentRenderer.getById(elementMeta.get("id").getAsPrimitive().getAsInt());
            }
        }
        return null;
    }
}
