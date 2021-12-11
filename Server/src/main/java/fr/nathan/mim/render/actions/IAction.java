package fr.nathan.mim.render.actions;

import fr.nathan.mim.api.data.ADataObject;
import fr.nathan.mim.render.Renderer;

public interface IAction {

    String getCodeName();
    boolean execute(ADataObject data, Renderer renderer);
}
