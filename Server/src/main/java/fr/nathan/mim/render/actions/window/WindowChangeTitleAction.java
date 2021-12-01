package fr.nathan.mim.render.actions.window;

import com.google.gson.JsonObject;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.IAction;

public class WindowChangeTitleAction implements IAction {

    @Override
    public String getCodeName() { return "W_TITLE"; }

    @Override
    public boolean execute(JsonObject data, Renderer renderer) {
        //renderer.setTitle(data.get("title").getAsString());
        return true;
    }
}
