package fr.nathan.mim.render.shape.actions.meta;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;

public abstract class MetaHandler extends ACORHandler<MetaHandler.Parameters, Void> {

    public MetaHandler(Handler<Parameters, Void> next) {
        super(next);
    }

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
