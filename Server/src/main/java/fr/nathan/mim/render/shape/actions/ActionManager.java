package fr.nathan.mim.render.shape.actions;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.shape.Meta;
import fr.nathan.mim.render.shape.UnknownShapeException;
import fr.nathan.mim.render.shape.actions.meta.BorderColorHandler;
import fr.nathan.mim.render.shape.actions.meta.ColorHandler;
import fr.nathan.mim.render.shape.actions.meta.MetaHandler;
import fr.nathan.mim.render.shape.actions.shapes.*;
import fr.nathan.mim.render.shape.shapes.Shape;

public class ActionManager {

    private ShapeHandler shapeHandler;
    private MetaHandler metaHandler;

    public ActionManager() {
        initShapeHandler();
        initMetaHandler();
    }

    void initShapeHandler() {
        shapeHandler = new PolygonHandler(shapeHandler);
        shapeHandler = new CircleHandler(shapeHandler);
        shapeHandler = new TextHandler(shapeHandler);
        shapeHandler = new LineHandler(shapeHandler);
    }

    void initMetaHandler() {
        metaHandler = new BorderColorHandler(metaHandler);
        metaHandler = new ColorHandler(metaHandler);
    }

    /**
     * Dessine une forme à partir d'un DataObject
     *
     * @param object Source de donnée où on récupère les informations sur la forme
     * @param renderable Instance où la forme sera dessinée
     * @throws UnknownShapeException
     *  Si l'objet ne correspond à aucune forme supportée par le ShapeHandler
     */
    public void handleAction(DataObject object, Renderable renderable) throws UnknownShapeException {

        Shape shape = shapeHandler.solve(new ShapeHandler.Parameters(object));
        if(shape == null){
            throw new UnknownShapeException(object.toString());
        }

        Meta meta = new Meta();

        // Si l'objet contient une partie de métadonnée, on va l'interpréter
        if (object.has("meta")) {
            DataObject elementMeta = object.get("meta").getAsObject();
            metaHandler.solve(new MetaHandler.Parameters(elementMeta, meta));
        }

        shape.setMeta(meta);

        renderable.drawShape(shape);
    }

}
