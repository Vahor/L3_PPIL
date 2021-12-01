package fr.nathan.mim.render.actions.window;

import com.google.gson.JsonObject;
import fr.nathan.mim.Constants;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.IAction;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class WindowChangeSizeAction implements IAction {

    @Override
    public String getCodeName() {return "W_SIZE";}

    @Override
    public boolean execute(JsonObject data, Renderer renderer) {
        int height = data.get("height").getAsInt();
        int width = data.get("width").getAsInt();
        if (height != -1)
            renderer.setInitialHeight(Math.max(1, height));
        if (width != -1)
            renderer.setInitialWidth(Math.max(1, width));

        return true;
    }
}
