# Basic Drawing Effects (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @hangmengxin-->
<!--Designer: @wanyanglan-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=740dcdea7b2e0f63c4b99baa0eb4f2e92e763430 translatedAt=2026-08-03T11:16:00.494Z pushedAt=2026-08-04T02:00:50.158Z -->

## Overview

You can set some basic effects, such as the fill color, anti-aliasing, stroke, and line connection style.

You can set the basic fill effect using a brush and set the basic stroke effect using a pen.

## Fill Effect

You can set the basic fill color using a brush and use the brush to implement more complex drawing effects, such as the blend mode, shader effect, and filter effect. For details, see [Complex Drawing Effects](complex-drawing-effect-c.md).

### Available APIs

The following table lists the APIs for setting the drawing effect using a brush. For details, see [drawing_brush](../reference/apis-arkgraphics2d/capi-drawing-brush-h.md).

| API| Description|
| -------- | -------- |
| OH_Drawing_Brush\* OH_Drawing_BrushCreate (void) | Creates a brush object.|
| void OH_Drawing_CanvasAttachBrush (OH_Drawing_Canvas\*, const OH_Drawing_Brush\*) | Attaches a brush to a canvas so that the canvas can use the style and color of the brush to fill in a shape.|
| void OH_Drawing_BrushSetColor (OH_Drawing_Brush\* , uint32_t color) | Sets the color for a brush. The color is used by the brush to fill in a shape.|
| void OH_Drawing_BrushSetAntiAlias (OH_Drawing_Brush\* , bool) | Enables or disables anti-aliasing for a brush. Anti-aliasing makes the pixels around the shape edges semi-transparent, delivering a smoother effect.|
| void OH_Drawing_CanvasDetachBrush (OH_Drawing_Canvas\*) | Removes the brush from the canvas. After the execution, the canvas does not use the previously set brush and is restored to the default fill effect.|
| void OH_Drawing_BrushDestroy (OH_Drawing_Brush\*) | Destroys a brush object and reclaims the memory occupied by it. |

### How to Develop

1. Call **OH_Drawing_BrushCreate()** to create a brush object.

   <!-- @[ndk_graphics_draw_create_brush](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Create a brush object.
   OH_Drawing_Brush* brush = OH_Drawing_BrushCreate();
   ```

2. (Optional) Use the brush to set the basic drawing effect. You can select one or more of the following effects:

   - You can call **OH_Drawing_BrushSetColor()** to set the fill color.

      <!-- @[ndk_graphics_draw_brush_set_color](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set the fill color to red.
      uint32_t color = 0xffff0000;
      OH_Drawing_BrushSetColor(brush, color);
      ```

      **color** is a 32-bit (ARGB) variable, for example, **0xffff0000**.

   - You can call **OH_Drawing_BrushSetAntiAlias()** to enable the anti-aliasing effect to smooth the edges of the graphics.

      <!-- @[ndk_graphics_draw_brush_set_antialias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Enable the anti-aliasing effect.
      OH_Drawing_BrushSetAntiAlias(brush, true);
      ```

3. Call **OH_Drawing_CanvasAttachBrush()** to set a brush for the canvas. This API takes two parameters: (1) **Canvas** object, which must be created or obtained. For details, see [Obtaining a Canvas and Displaying Drawing Results (C/C++)](canvas-get-result-draw-c.md); (2) brush object to be set. The canvas uses the brush style and color to fill the shape.

   <!-- @[ndk_graphics_draw_canvas_attach_brush](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Set the brush of the canvas.
   OH_Drawing_CanvasAttachBrush(canvas, brush);
   ```

4. Draw primitives as required. For details, see [Drawing Primitives](primitive-drawing-overview.md).

5. If no fill effect is required, you can use **OH_Drawing_CanvasDetachBrush()** to remove the brush. The input parameter is the **Canvas** object.

   <!-- @[ndk_graphics_draw_canvas_detach_brush](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Remove the brush from the canvas.
   OH_Drawing_CanvasDetachBrush(canvas);
   ```

6. When the brush is no longer needed, destroy the brush object using **OH_Drawing_BrushDestroy()**.

   <!-- @[ndk_graphics_draw_brush_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Destroy objects.
   OH_Drawing_BrushDestroy(brush);
   ```

## Stroke Effect

You can set the basic stroke color using a pen and use the pen to implement more complex drawing effects, such as the blend mode, path effect, shader effect, and filter effect. For details, see [Complex Drawing Effects](complex-drawing-effect-c.md).

### Available APIs

The following table lists the APIs for setting the drawing effect using a pen. For details, see [drawing_pen](../reference/apis-arkgraphics2d/capi-drawing-pen-h.md).

| API| Description|
| -------- | -------- |
| OH_Drawing_Pen\* OH_Drawing_PenCreate (void) | Creates a pen object.|
| void OH_Drawing_CanvasAttachPen (OH_Drawing_Canvas\* , const OH_Drawing_Pen\* ) | Attaches a pen to a canvas so that the canvas can use the style and color of the pen to outline a shape.|
| void OH_Drawing_PenSetColor (OH_Drawing_Pen\* , uint32_t color) | Sets the color for a pen. The color is used by the pen to outline a shape.|
| void OH_Drawing_PenSetWidth (OH_Drawing_Pen\* , float width) | Sets the width for a pen. The value **0** is treated as an unusually thin width. During drawing, the width of 0 is always drawn as 1 pixel wide, regardless of any scaling applied to the canvas. Negative values are also regarded as the value **0** during the drawing process.|
| void OH_Drawing_PenSetAntiAlias (OH_Drawing_Pen\* , bool ) | Enables or disables anti-aliasing for a pen. Anti-aliasing makes the pixels around the shape edges semi-transparent.|
| void OH_Drawing_PenSetCap (OH_Drawing_Pen\* , OH_Drawing_PenLineCapStyle) | Sets the line cap style for a pen.|
| void OH_Drawing_PenSetJoin (OH_Drawing_Pen\* , OH_Drawing_PenLineJoinStyle) | Sets the line join style for a pen.|
| void OH_Drawing_CanvasDetachPen (OH_Drawing_Canvas\*) | Removes the pen from the canvas. After the execution, the canvas does not outline the shape and is restored to the default fill effect.|
| void OH_Drawing_PenDestroy (OH_Drawing_Pen\*) | Destroys a pen object and reclaims the memory occupied by the object. |

### How to Develop

1. Call **OH_Drawing_PenCreate()** to create a pen object.

   <!-- @[ndk_graphics_draw_create_drawing_pen](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Create a pen object.
   OH_Drawing_Pen* pen = OH_Drawing_PenCreate();
   ```

2. Use the pen to set specific stroke effects (you can choose one or more of the following effects).

   - You can call **OH_Drawing_PenSetColor()** to set the pen color, which is used to outline a shape.

      <!-- @[ndk_graphics_draw_pen_set_color](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set the pen color to red.
      uint32_t color = 0xffff0000;
      OH_Drawing_PenSetColor(pen, color);
      ```

      **color** is a 32-bit (ARGB) variable, for example, **0xffff0000**.

   - You can call **OH_Drawing_PenSetWidth()** to set the pen width.

      <!-- @[ndk_graphics_draw_pen_set_stroke_width](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set the pen width to 50 pixels.
      float width = 50.0;
      OH_Drawing_PenSetWidth(pen, width);
      ```

      **width** indicates the pixel value of the pen width.

   - You can call **OH_Drawing_PenSetAntiAlias()** to set anti-aliasing for the pen to make the drawing edge smoother.

      <!-- @[ndk_graphics_draw_pen_set_antialias](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set anti-aliasing for the pen.
      OH_Drawing_PenSetAntiAlias(pen, true);
      ```

   - You can call **OH_Drawing_PenSetCap()** to set the pen cap style.

      <!-- @[ndk_graphics_draw_pen_set_cap_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set the pen cap style.
      OH_Drawing_PenSetCap(pen, OH_Drawing_PenLineCapStyle::LINE_ROUND_CAP);
      ```

      The options of **OH_Drawing_PenLineCapStyle** are as follows.

      | Line Cap Style| Description| Effect|
      | -------- | -------- | -------- |
      | LINE_FLAT_CAP | No cap style. Both ends of the line segment are cut off square.| ![Screenshot_20241130143725824](figures/Screenshot_20241130143725824.jpg) |
      | LINE_SQUARE_CAP | Square cap style. Both ends have a square, the height of which is half of the width of the line segment, with the same width.| ![Screenshot_20241130143837975](figures/Screenshot_20241130143837975.jpg) |
      | LINE_ROUND_CAP | Round cap style. Both ends have a semicircle centered, the diameter of which is the same as the width of the line segment.| ![Screenshot_20241130143949934](figures/Screenshot_20241130143949934.jpg) |

   - You can call **OH_Drawing_PenSetJoin()** to set the pen join style.

      <!-- @[ndk_graphics_draw_pen_set_join_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

      ``` C++
      // Set the pen join style.
      OH_Drawing_PenSetJoin(pen, OH_Drawing_PenLineJoinStyle::LINE_BEVEL_JOIN);
      ```

      The options of **OH_Drawing_PenLineJoinStyle** are as follows.

      | Join Style| Description| Effect|
      | -------- | -------- | -------- |
      | LINE_MITER_JOIN | Miter | ![LINE-MITER-JOIN](figures/LINE-MITER-JOIN.png) |
      | LINE_ROUND_JOIN | Round | ![LINE-ROUND-JOIN](figures/LINE-ROUND-JOIN.png) |
      | LINE_BEVEL_JOIN | Bevel | ![LINE-BEVEL-JOIN](figures/LINE-BEVEL-JOIN.png) |

3. Call **OH_Drawing_CanvasAttachPen()** to attach the pen to the canvas. This API accepts two parameters: one is the canvas object. Ensure that you have created or obtained the canvas. For details, see [Obtaining a Canvas and Displaying Drawing Results (C/C++)](canvas-get-result-draw-c.md). The other parameter is the pen object to set. The canvas will use the configured pen style and color to draw graphics outlines.

   <!-- @[ndk_graphics_draw_canvas_attach_pen](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Attach the pen to the canvas.
   OH_Drawing_CanvasAttachPen(canvas, pen);
   ```

4. Draw primitives as required. For details, see [Drawing Primitives](primitive-drawing-overview.md).

5. If no stroke effect is required, you can use **OH_Drawing_CanvasDetachPen()** to remove the pen. The input parameter is the **Canvas** object. Ensure that the canvas has been created or obtained. For details, see [Obtaining a Canvas and Displaying Drawing Results (C/C++)](canvas-get-result-draw-c.md).

   <!-- @[ndk_graphics_draw_canvas_detach_pen](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Remove the pen from the canvas.
   OH_Drawing_CanvasDetachPen(canvas);
   ```

6. When the pen is no longer needed for stroke, destroy the pen object using **OH_Drawing_PenDestroy()**.

   <!-- @[ndk_graphics_draw_pen_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw/entry/src/main/cpp/samples/sample_graphics.cpp) -->

   ``` C++
   // Destroy objects.
   OH_Drawing_PenDestroy(pen);
   ```

<!--RP1-->

## Samples

The following samples are provided to help you better understand how to use the **Drawing** APIs (C/C++) for development:

- [NDKGraphicsDraw (API20)](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkGraphics2D/Drawing/NDKGraphicsDraw)

<!--RP1End-->