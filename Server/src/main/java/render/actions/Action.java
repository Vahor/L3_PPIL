package render.actions;

import render.Renderer;

public enum Action {

    CHANGE_NAME {
        @Override
        public boolean execute(String data, Renderer renderer) {
            renderer.setTitle(data);
            return true;
        }
    }

    ;
    public boolean execute(String data, Renderer renderer) {
        return true;
    }
}
