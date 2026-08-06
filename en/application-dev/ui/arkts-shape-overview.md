# Geometric Shape Drawing Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi; @hehongyang3-->
<!--Designer: @fenglinbailu; @hehongyang3-->
<!--Tester: @liuli0427; @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=05f43ca6db091467fec495030511fa24008c6cb3 translatedAt=2026-08-04T06:37:26.133Z pushedAt=2026-08-04T08:26:16.597Z -->

There are two methods for drawing geometric shapes: (1) by directly drawing them using the [Shape](../reference/apis-arkui/arkui-ts/ts-drawing-components-shape.md) component; (2) by clipping a component into a geometric shape using the shape clipping attribute [clipShape](../reference/apis-arkui/arkui-ts/ts-universal-attributes-sharp-clipping.md#clipshape12).

## When to Use

| Method|Use Case |
| ----------| ----------------------------------- |
| [Drawing geometric shapes (Shape)](arkts-geometric-shape-drawing.md)| Create components of a specified shape and draw geometric graphics directly on the page.|
| [Shape clipping (clipShape)](arkts-clip-shape.md)| Clip a component into a specified geometric shape.|

## Constraints

* For the **Shape** component: You can use the [Shape](../reference/apis-arkui/arkui-ts/ts-drawing-components-shape.md) component as a parent container to achieve SVG-like effects, or use its various child components independently for drawing.

* For the **clipShape** attribute: Clipping does not prevent the clipped area from responding to bound gesture events.