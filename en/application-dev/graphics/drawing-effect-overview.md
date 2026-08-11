# Overview of Drawing Effects

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=aa0a67ae9790115e74a1e29268966a05ae945ba8 translatedAt=2026-08-03T11:18:49.739Z pushedAt=2026-08-04T06:15:53.051Z -->

After a canvas is created, it has default fill and stroke effects. You can directly draw primitives. However, the default effects cannot meet requirements in most cases. For example, the default color is black, and only black graphics can be drawn. The default effects do not include blurring or gradient effects. For more effects, such as red graphics, blurring effects, or gradient effects, you need to set a custom brush or pen for the canvas.

A brush is used to implement the fill effect for the internal area of a graphic. The basic effects include the fill color and anti-aliasing.

A pen is used to implement the stroke effect for the outline of a graphic. The basic effects include the stroke color, width, line connection mode, and line endpoint style.

In addition, the brush and pen can implement more complex effects, such as:

- Blend mode

- Path effect (dashed line)

- Shader effect (linear gradient, radial gradient)

- Filtering effect (blurring)

You can set either a brush or a pen, or both or neither. If neither is set, the default black brush is used.