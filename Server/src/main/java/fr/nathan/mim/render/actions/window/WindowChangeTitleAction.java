package fr.nathan.mim.render.actions.window;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.IAction;

public class WindowChangeTitleAction implements IAction {

    @Override
    public String getCodeName() { return "W_TITLE"; }

    @Override
    public boolean execute(ADataObject data, Renderer renderer) {
        //renderer.setTitle(data.get("title").getAsString());
        return true;
    }
}
