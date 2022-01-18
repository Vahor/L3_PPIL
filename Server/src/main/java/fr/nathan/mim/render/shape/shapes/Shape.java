package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;
import lombok.Setter;

import java.awt.*;

public abstract class Shape {

    @Getter @Setter
    protected Meta meta;
    protected Shape(Meta meta) {this.meta = meta;}

    public abstract void draw(Graphics g);
}
