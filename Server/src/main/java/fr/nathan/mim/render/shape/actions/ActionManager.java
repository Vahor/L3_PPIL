package fr.nathan.mim.render.shape.actions;

import fr.nathan.mim.api.Pair;
import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderer;
import fr.nathan.mim.render.shape.actions.meta.BorderColorHandler;
import fr.nathan.mim.render.shape.actions.meta.ColorHandler;
import fr.nathan.mim.render.shape.actions.meta.IdHandler;
import fr.nathan.mim.render.shape.actions.meta.ZIndexHandler;
import fr.nathan.mim.render.shape.actions.shapes.CircleHandler;
import fr.nathan.mim.render.shape.actions.shapes.PolygonHandler;
import fr.nathan.mim.render.shape.actions.shapes.TextHandler;
import fr.nathan.mim.render.shape.shapes.AShape;

public class ActionManager {

    private Handler<DataObject, AShape> shapeHandler;
    private Handler<Pair<DataObject, AShape>, AShape> metaHandler;

    public ActionManager() {
        initShapeHandler();
        initMetaHandler();
    }

    void initShapeHandler() {
        shapeHandler = new PolygonHandler(shapeHandler);
        shapeHandler = new CircleHandler(shapeHandler);
        shapeHandler = new TextHandler(shapeHandler);
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

    public void handleAction(DataObject object, Renderer currentRenderer) {
        System.out.println("ActionManager.handleAction");
        System.out.println("object = " + object);

        // On essaie de récupérer la forme si elle existe déjà.
        // Exemple : si on veut modifier la couleur d'un cercle, on envoie rouge et l'id.
        // On ne va pas recréer l'objet entier
        AShape shape = tryGetShape(object, currentRenderer);
        if (shape == null)
            shape = shapeHandler.solve(object);

        // Une fois la forme récupérée ou créé. On applique la modification meta
        if (shape != null) {
            if (object.has("meta")) {
                DataObject elementMeta = object.get("meta").getAsObject();
                metaHandler.solve(new Pair<>(elementMeta, shape));
            }

            if (!shape.isRendered()) currentRenderer.addShape(shape);
        }

    }

    public AShape tryGetShape(DataObject object, Renderer currentRenderer) {
        if (object.has("meta")) {
            DataObject elementMeta = object.get("meta").getAsObject();
            if (elementMeta.has("id")) {
                return currentRenderer.getById(elementMeta.get("id").getAsPrimitive().getAsInt());
            }
        }
        return null;
    }
}
