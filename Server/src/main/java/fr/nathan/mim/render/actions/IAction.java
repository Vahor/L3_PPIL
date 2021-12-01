package fr.nathan.mim.render.actions;

import com.google.gson.JsonObject;
import fr.nathan.mim.render.Renderer;

public interface IAction {

    String getCodeName();
    boolean execute(JsonObject data, Renderer renderer);
}
