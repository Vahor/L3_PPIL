package fr.nathan.mim.render.renderer.actions.renderer;

import fr.nathan.mim.api.data.DataObject;
import fr.nathan.mim.api.handler.ACORHandler;
import fr.nathan.mim.api.handler.Handler;
import fr.nathan.mim.render.renderer.Renderable;
import lombok.Getter;
import lombok.ToString;

public abstract class RendererHandler extends ACORHandler<RendererHandler.Parameters, Renderable> {

    public RendererHandler(Handler<Parameters, Renderable> next) {
        super(next);
    }

    @ToString
    public static class Parameters {

        @Getter
        private final DataObject object;
        @Getter
        private final Renderable currentRenderable;

        public Parameters(DataObject object, Renderable currentRenderable) {
            this.object            = object;
            this.currentRenderable = currentRenderable;
        }
    }
}
