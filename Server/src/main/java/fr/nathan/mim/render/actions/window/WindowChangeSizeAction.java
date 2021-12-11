package fr.nathan.mim.render.actions.window;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.IAction;

public class WindowChangeSizeAction implements IAction {

    @Override
    public String getCodeName() {return "W_SIZE";}

    @Override
    public boolean execute(ADataObject data, Renderer renderer) {
        int height = data.get("height").getAsPrimitive().getAsInt();
        int width = data.get("width").getAsPrimitive().getAsInt();
        if (height != -1)
            renderer.setInitialHeight(Math.max(1, height));
        if (width != -1)
            renderer.setInitialWidth(Math.max(1, width));

        return true;
    }
}
