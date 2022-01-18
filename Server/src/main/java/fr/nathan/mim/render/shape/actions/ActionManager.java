package fr.nathan.mim.render.shape.actions;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.shape.Meta;
import fr.nathan.mim.render.shape.actions.meta.BorderColorHandler;
import fr.nathan.mim.render.shape.actions.meta.ColorHandler;
import fr.nathan.mim.render.shape.actions.meta.MetaHandler;
import fr.nathan.mim.render.shape.actions.shapes.CircleHandler;
import fr.nathan.mim.render.shape.actions.shapes.PolygonHandler;
import fr.nathan.mim.render.shape.actions.shapes.ShapeHandler;
import fr.nathan.mim.render.shape.actions.shapes.TextHandler;
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
    }

    void initMetaHandler() {
        metaHandler = new BorderColorHandler(metaHandler);
        metaHandler = new ColorHandler(metaHandler);
    }

    public void handleAction(DataObject object, Renderable renderable) {
        Meta meta = new Meta();

        if (object.has("meta")) {
            DataObject elementMeta = object.get("meta").getAsObject();
            metaHandler.solve(new MetaHandler.Parameters(elementMeta, meta));
        }

        Shape shape = shapeHandler.solve(new ShapeHandler.Parameters(object, meta));

        renderable.drawShape(shape);
    }

}
