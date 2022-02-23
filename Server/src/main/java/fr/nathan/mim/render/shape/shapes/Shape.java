package fr.nathan.mim.render.shape.shapes;

import fr.nathan.mim.render.renderer.Renderable;
import fr.nathan.mim.render.shape.Meta;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@ToString(of = {"meta"})
public abstract class Shape {

    @Getter @Setter
    protected Meta meta;

    /**
     * Execute la méthode de dessin correspondante dans le visitor.
     * @param renderable Implémentation de dessin.
     */
    public abstract void draw(Renderable renderable);
}
