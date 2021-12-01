package fr.nathan.mim.render.actions;

import fr.nathan.mim.render.actions.figures.DrawCircleAction;
import fr.nathan.mim.render.actions.window.WindowChangeSizeAction;
import fr.nathan.mim.render.actions.window.WindowChangeTitleAction;

import java.util.HashMap;

public class ActionManager {

    private final HashMap<String, IAction> actions = new HashMap<>();

    public ActionManager() {
        addAction(new WindowChangeTitleAction());
        addAction(new DrawCircleAction());
        addAction(new WindowChangeSizeAction());
    }

    private void addAction(IAction action) {
        actions.put(action.getCodeName(), action);
    }

    public IAction getActionByName(String name) {
        return actions.get(name);
    }
}
