# Drawing and Displaying Simple Text (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=8e9d3b746529fedba672cd46a96d4746984bcb6c translatedAt=2026-08-15T01:51:33.750Z pushedAt=2026-08-15T08:29:10.088Z -->

## Overview

In a simple user interface, only a few lines of static text need to be displayed, such as the text on a label, button, menu item, or status bar. In this case, you only need to select a proper font, size, and color to complete the rendering.

## Available APIs

The following table lists the APIs for simple text drawing. For details, see [drawing_text_typography.h](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md).

| API Definition| Description|
| -------- | -------- |
| OH_Drawing_TextStyle\* OH_Drawing_CreateTextStyle(void) | Creates an **OH_Drawing_TextStyle** object.|
| void OH_Drawing_SetTextStyleFontSize(OH_Drawing_TextStyle\* style, double fontSize) | Sets the font size for a text style.|
| void OH_Drawing_SetTextStyleFontWeight(OH_Drawing_TextStyle\* style, int fontWeight) | Sets the font weight. |

## How to Develop

1. Create a canvas object. For details about how to create a canvas object, see [Obtaining a Canvas and Displaying Drawing Results (C/C++)](canvas-get-result-draw-c.md).

2. Initialize the paragraph style and set the text alignment to center alignment.

   <!-- @[drawing_simple_text_c_create_typographyStyle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKDrawingSimpleText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Create a TypographyStyle object, which is required for creating Typography.
   OH_Drawing_TypographyStyle *typoStyle = OH_Drawing_CreateTypographyStyle();
   // Set the text alignment mode to center.
   OH_Drawing_SetTypographyTextAlign(typoStyle, TEXT_ALIGN_CENTER);
   ```

3. Initialize the text style. Here, the font color is set to pure black, the font size to **60**, and the font weight to **400**.

   <!-- @[drawing_simple_text_c_create_textStyle](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKDrawingSimpleText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Set the text color, size, and weight. If TextStyle is not set, the default TextStyle in TypographyStyle is used.
   OH_Drawing_TextStyle *txtStyle = OH_Drawing_CreateTextStyle();
   OH_Drawing_SetTextStyleColor(txtStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   OH_Drawing_SetTextStyleFontSize(txtStyle, 60);
   OH_Drawing_SetTextStyleFontWeight(txtStyle, FONT_WEIGHT_400);
   ```

4. Initialize the paragraph object and add text.

   <!-- @[drawing_simple_text_c_create_typography](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKDrawingSimpleText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Create a FontCollection object to manage the font matching logic.
   OH_Drawing_FontCollection *fc = OH_Drawing_CreateFontCollection();
   // Use the FontCollection object and the created TypographyStyle object to create a TypographyCreate object, which is used to create a Typography object.
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typoStyle, fc);
   
   // Add the created TextStyle object to handler.
   OH_Drawing_TypographyHandlerPushTextStyle(handler, txtStyle);
   // Add text to handler.
   const char *text = "Hello World Drawing\n";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   
   OH_Drawing_Typography *typography = OH_Drawing_CreateTypography(handler);
   ```

5. Layout the paragraph and draw the text.

   <!-- @[drawing_simple_text_c_layout_and_paint](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKDrawingSimpleText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Set the maximum width.
   double maxWidth = width_;
   OH_Drawing_TypographyLayout(typography, maxWidth);
   // Draw the text on the canvas.
   OH_Drawing_TypographyPaint(typography, cCanvas_, 0, 100);
   ```

6. Release the memory.

   <!-- @[drawing_simple_text_c_destroy](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKDrawingSimpleText/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Release the memory.
   OH_Drawing_DestroyTypographyStyle(typoStyle);
   OH_Drawing_DestroyTextStyle(txtStyle);
   OH_Drawing_DestroyFontCollection(fc);
   OH_Drawing_DestroyTypographyHandler(handler);
   OH_Drawing_DestroyTypography(typography);
   ```

## Effect

![Simple text drawing](figures/Simple-text-drawing.png)