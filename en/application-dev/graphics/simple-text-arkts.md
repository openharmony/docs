# Drawing and Displaying Simple Text (ArkTS)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=983fa161ee12961fd07ba0428e932a03e0d706d9 translatedAt=2026-08-03T11:23:41.953Z pushedAt=2026-08-04T07:17:25.767Z -->

## Overview

In a simple user interface, only a few lines of static text need to be displayed, such as the text on a label, button, menu item, or status bar. In this case, you only need to select a proper font, size, and color to complete the rendering.

## Related Attributes

In this scenario, the following text style attributes are involved. For details, see [TextStyle](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#textstyle).

- **color**: font color. The default value is white. Note that the font color must be different from the canvas color to ensure that the text can be properly displayed.

- **fontSize**: font size, in units of px. The value is a floating point number. The default value is **14.0**.

## How to Develop

1. Obtain the canvas object through **context**.

   <!-- @[arkts_drawing_simple_text_create_canvas](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/SimpleTextDrawing/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let canvas = context.canvas;
   ```

   <!-- -->

2. Initialize the text style. Here, set the font color to red and the font size to 100 px.

   <!-- @[arkts_drawing_simple_text_create_text_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/SimpleTextDrawing/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Initialize the text style.
   let myTextStyle: text.TextStyle = {
     // Text color.
     color: {
       alpha: 255,
       red: 255,
       green: 0,
       blue: 0
     },
     // Text size.
     fontSize: 100
   };
   ```

   <!-- -->

3. Initialize the paragraph style.

   <!-- @[arkts_drawing_simple_text_create_paragraph_style](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/SimpleTextDrawing/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let myParagraphStyle: text.ParagraphStyle = {
     textStyle: myTextStyle,
   };
   ```

   <!-- -->

4. Initialize the paragraph object and add text.

   <!-- @[arkts_drawing_simple_text_builder_add_text](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/SimpleTextDrawing/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   let fontCollection = text.FontCollection.getGlobalInstance();
   let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
   // Push the text style.
   paragraphBuilder.pushStyle(myTextStyle);
   // Add text.
   paragraphBuilder.addText("Hello World");
   ```

   <!-- -->

5. Layout the paragraph and draw the text.

   <!-- @[arkts_drawing_simple_text_layout_paint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/SimpleTextDrawing/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Generate a paragraph.
   let paragraph = paragraphBuilder.build();
   // Layout.
   paragraph.layoutSync(1250);
   // Draw the text.
   paragraph.paint(canvas, 0, 100);
   ```

## Effect

![image_0000002246603717](figures/simpleText.PNG)