package fr.nathan.mim.render.shape.actions.shapes;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.Meta;
import fr.nathan.mim.render.shape.shapes.Shape;
import lombok.ToString;
import lombok.Getter;

public abstract class ShapeHandler extends ACORHandler<ShapeHandler.Parameters, Shape> {

    public ShapeHandler(Handler<Parameters, Shape> next) {
        super(next);
    }

    @ToString
    public static class Parameters {

        @Getter
        private final DataObject object;
        @Getter
        private final Meta meta;

        public Parameters(DataObject object, Meta meta) {
            this.object = object;
            this.meta   = meta;
        }
    }
}
