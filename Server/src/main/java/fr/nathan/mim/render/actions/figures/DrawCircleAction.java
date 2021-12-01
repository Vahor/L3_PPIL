package fr.nathan.mim.render.actions.figures;

import com.google.gson.JsonObject;
import fr.nathan.mim.render.Renderer;
import fr.nathan.mim.render.actions.IAction;
import fr.nathan.mim.render.geom.Point2D;
import fr.nathan.mim.render.shapes.Circle;

import java.awt.*;

public class DrawCircleAction implements IAction {

    @Override
    public String getCodeName() {return "D_CIRCLE";}

    @Override
    public boolean execute(JsonObject data, Renderer renderer) {
        // Pour dessiner un cercle on a besoin d'un point central
        // Et d'un rayon

        try {
            double x = data.get("x").getAsDouble();
            double y = data.get("y").getAsDouble();
            double diameter = data.get("diameter").getAsDouble();

            Circle circle = new Circle(new Point2D(x, y), diameter);
            if(data.has("color")) {
                JsonObject color = data.get("color").getAsJsonObject();
                circle.setColor(new Color(
                        color.get("red").getAsInt(),
                        color.get("green").getAsInt(),
                        color.get("blue").getAsInt()));
            }
            renderer.addShape(circle);

            return true;
        } catch (Exception e) {
            e.printStackTrace();
            return false;
        }
    }
}
