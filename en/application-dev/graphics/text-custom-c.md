# Drawing and Displaying Custom Text (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @KejiePeng-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=983fa161ee12961fd07ba0428e932a03e0d706d9 translatedAt=2026-08-03T11:23:15.659Z pushedAt=2026-08-04T07:39:23.376Z -->

In complex text layout scenarios, when the standard text components provided by the system cannot meet specific visual or interaction requirements, you can use the underlying text drawing capability provided by ArkGraphics 2D to directly control the canvas and text style to implement refined control over the text appearance and layout. This capability applies to scenarios that require highly customized text rendering effects, such as artistic fonts, complex rich text orchestration, or special dynamic text effects.

As a core component of the graphics system, the font engine is responsible for converting character codes into visual glyphs and accurately calculating the layout and position of each glyph, providing underlying support for custom text drawing. Through the text measurement API, you can obtain the accurate size of the text, which is the basis for precise layout (such as center display).

## Text Shaping

### When to Use

Text shaping is a key capability provided by the font engine. It allows you to directly obtain the underlying glyph information (such as advance and direction measurement information) of the text without going through the default text layout process. This enables you to implement completely customized layout logic, drawing operations, and line break policies based on the raw data.

This capability applies to the following scenarios:

- Custom rich text rendering: implements image-text mixed layout and multi-style text display in social media, news clients, and similar applications.

- Cross-platform consistent layout requirements: ensures consistent visual display of text across different platforms and devices.

- Refined layout management: implements artistic layout and dynamic text layout, which are difficult to achieve with standard system text components.

### Available APIs

The following table lists the common APIs used for text shaping. For details about the APIs, see [drawing_text_typography.h](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md) and [drawing_text_blob.h](../reference/apis-arkgraphics2d/capi-drawing-text-blob-h.md).

| API| Description| 
| -------- | -------- |
| OH_Drawing_LineTypography* OH_Drawing_CreateLineTypography(OH_Drawing_TypographyCreate* handler) | Creates a pointer to an **OH_Drawing_LineTypography** object, which stores the text content and style and can be used to compute typography details for individual lines of text.| 
| OH_Drawing_TextLine* OH_Drawing_LineTypographyCreateLine(OH_Drawing_LineTypography* lineTypography,size_t startIndex, size_t count) | Creates a pointer to an **OH_Drawing_TextLine** object based on the text content in a specified range.| 
| OH_Drawing_Array* OH_Drawing_TextLineGetGlyphRuns(OH_Drawing_TextLine* line) | Obtains the array of glyph runs in a text line object.| 
| OH_Drawing_Array* OH_Drawing_GetRunGlyphs(OH_Drawing_Run* run, int64_t start, int64_t length) | Obtains an array of glyphs within the specified range of a run.| 
| OH_Drawing_Font* OH_Drawing_GetRunFont(OH_Drawing_Run* run) | Obtains the font object of a run.| 
| OH_Drawing_Array* OH_Drawing_GetRunGlyphAdvances(OH_Drawing_Run* run, uint32_t start, uint32_t length) | Obtains the glyph advance array of a run.| 
| OH_Drawing_TextBlobBuilder* OH_Drawing_TextBlobBuilderCreate(void) | Creates an **OH_Drawing_TextBlobBuilder** object.| 
| OH_Drawing_TextBlob* OH_Drawing_TextBlobBuilderMake(OH_Drawing_TextBlobBuilder* textBlobBuilder) | Makes an **OH_Drawing_TextBlob** object from an **OH_Drawing_TextBlobBuilder**.| 
| void OH_Drawing_CanvasDrawTextBlob(OH_Drawing_Canvas* canvas, const OH_Drawing_TextBlob* textBlob, float x, float y) | Draws a text blob.| 

### How to Develop

Starting from API version 18, text shaping results can be obtained. API version 20 and later add support for obtaining text layout direction and text glyph advance. The key code is as follows.

1. Add the following library to the **src/main/cpp/CMakeLists.txt** file of the project.

   ```c++
   libnative_drawing.so
   ```

2. Import the required header files.

   ```c++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_text_blob.h>
   #include <native_drawing/drawing_text_line.h>
   #include <native_drawing/drawing_text_run.h>
   #include <native_drawing/drawing_text_lineTypography.h>
   #include <native_drawing/drawing_rect.h>
   #include <native_drawing/drawing_point.h>
   ```

3. Create a paragraph style and use **ParagraphBuilder** to generate a paragraph instance.

   <!-- @[complex_text_c_independent_shaping_text_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKComplexText1/entry/src/main/cpp/samples/draw_text_impl.cpp) -->

   ``` C++
   // Create a TypographyStyle object, which is required for creating TypographyCreate.
   OH_Drawing_TypographyStyle *typoStyle = OH_Drawing_CreateTypographyStyle();
   // Set the text color, size, and weight. If TextStyle is not set, the default TextStyle in TypographyStyle is used.
   OH_Drawing_TextStyle *txtStyle = OH_Drawing_CreateTextStyle();
   OH_Drawing_SetTextStyleFontSize(txtStyle, DIV_TEN(width_));
   
   // Create a FontCollection object to manage the font matching logic.
   OH_Drawing_FontCollection *fc = OH_Drawing_CreateSharedFontCollection();
   // Use the FontCollection object and the TypographyStyle object to create a TypographyCreate object, which is used to create a Typography object.
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typoStyle, fc);
   ```

4. Set the text style and add text content.

   <!-- @[complex_text_c_independent_shaping_text_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKComplexText1/entry/src/main/cpp/samples/draw_text_impl.cpp) -->

   ``` C++
   // Add text to handler.
   OH_Drawing_TypographyHandlerPushTextStyle(handler, txtStyle);
   OH_Drawing_TypographyHandlerAddText(handler, "Hello World");
   ```

5. Create a line object and obtain the shaping results of all texts in the line.

Use the **OH_Drawing_LineTypographyCreateLine()** method to create a single-line object, and use the **OH_Drawing_TextLineGetGlyphRuns()** method of the line object to obtain text runs with the same style.

   <!-- @[complex_text_c_independent_shaping_text_step3](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKComplexText1/entry/src/main/cpp/samples/draw_text_impl.cpp) -->

   ``` C++
   // Create a Typography object based on the handler.
   OH_Drawing_LineTypography *lineTypography = OH_Drawing_CreateLineTypography(handler);
   // Create a TextLine object by extracting characters in the range of (0, 11).
   OH_Drawing_TextLine *textLine = OH_Drawing_LineTypographyCreateLine(lineTypography, 0, 11);
   
   // Obtain the text shaping results.
   OH_Drawing_Array *runs = OH_Drawing_TextLineGetGlyphRuns(textLine);
   ```

6. This step is the custom drawing phase in the text shaping process. Call the **OH_Drawing_GetRunGlyphs()** method to obtain the glyph index of each character in the text, and then use the font object obtained from the **OH_Drawing_GetRunFont()** method to uniquely determine the specific graphical information of each glyph.

Starting from API version 20, the newly added **OH_Drawing_GetRunGlyphAdvances()** method returns an array containing the recommended advance width and height for each glyph during drawing. With these precise measurement data, you can freely calculate and define the drawing position of each glyph, enabling complex text layout effects such as custom character spacing, vertical offset, or special typesetting.

   <!-- @[complex_text_c_independent_shaping_text_step4](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKComplexText1/entry/src/main/cpp/samples/draw_text_impl.cpp) -->

   ``` C++
   size_t runsLength = OH_Drawing_GetDrawingArraySize(runs);
   for (int i = 0; i < runsLength; i++) {
       OH_Drawing_Run *run = OH_Drawing_GetRunByIndex(runs, i);
       // Obtain all glyph data.
       OH_Drawing_Array *glyphs = OH_Drawing_GetRunGlyphs(run, 0, 0);
       size_t glyphsLength = OH_Drawing_GetDrawingArraySize(glyphs);
       // Obtain the font of the run.
       OH_Drawing_Font *font = OH_Drawing_GetRunFont(run);
       OH_Drawing_Array *advances = OH_Drawing_GetRunGlyphAdvances(run, 0, 0);
   
       OH_Drawing_TextBlobBuilder *builder = OH_Drawing_TextBlobBuilderCreate();
       // Create a 20 x 20 rectangle.
       OH_Drawing_Rect *rect = OH_Drawing_RectCreate(0, 0, 20, 20);
       const OH_Drawing_RunBuffer *buffer = OH_Drawing_TextBlobBuilderAllocRunPos(builder, font, glyphsLength, rect);
   
       // Create a glyph buffer and draw glyphs independently using the drawing API.
       int x = 0;
       int y = 0;
       for (int index = 0; index < glyphsLength; index++) {
           buffer->glyphs[index] = OH_Drawing_GetRunGlyphsByIndex(glyphs, index);
           // Set the glyph position.
           buffer->pos[index * TWO_INT] = x;
           buffer->pos[index * TWO_INT + 1] = y;
   
           OH_Drawing_Point *advance = OH_Drawing_GetRunGlyphAdvanceByIndex(advances, index);
           float pos = 0;
           OH_Drawing_PointGetX(advance, &pos);
           x += pos + 10; // Set horizontal spacing of 10 px between each glyph.
           y += 30; // Vertical spacing of 30px between glyphs.
       }
   
       // Draw a series of consecutive glyphs with the same properties.
       OH_Drawing_TextBlob *textBlob = OH_Drawing_TextBlobBuilderMake(builder);
       // Draw the text on the canvas (20,100).
       OH_Drawing_CanvasDrawTextBlob(cCanvas_, textBlob, 20, 100);
   
       // Release the memory.
       OH_Drawing_TextBlobDestroy(textBlob);
       OH_Drawing_FontDestroy(font);
       OH_Drawing_DestroyRunGlyphAdvances(advances);
       OH_Drawing_DestroyRunGlyphs(glyphs);
       OH_Drawing_TextBlobBuilderDestroy(builder);
       OH_Drawing_RectDestroy(rect);
   }
   ```

7. Release the memory.

   <!-- @[complex_text_c_independent_shaping_text_step5](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKComplexText1/entry/src/main/cpp/samples/draw_text_impl.cpp) -->

   ``` C++
   // Release the memory.
   OH_Drawing_DestroyTypographyStyle(typoStyle);
   OH_Drawing_DestroyTextStyle(txtStyle);
   OH_Drawing_DestroyFontCollection(fc);
   OH_Drawing_DestroyTypographyHandler(handler);
   OH_Drawing_DestroyLineTypography(lineTypography);
   OH_Drawing_DestroyTextLine(textLine);
   OH_Drawing_DestroyRuns(runs);
   ```

Effect demonstration:

![ndk_independent_shaping.png](figures/ndk_independent_shaping.png)