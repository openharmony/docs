# Text Measurement (C/C++)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=8e9d3b746529fedba672cd46a96d4746984bcb6c translatedAt=2026-08-15T01:52:00.573Z pushedAt=2026-08-15T08:35:47.980Z -->

## Overview

Text measurement refers to the process of evaluating the size and layout of text and calculating the space (such as the width, height, and other related information) occupied by the text in a given font and style during graphics drawing. Text measurement helps manage typography, layout, rendering, and adjustments for text position and size. It ensures precise UI layouts and presentations align with design goals.

The following text measurement capabilities are supported:

- **Measurement of text width**: measures the horizontal length of the given text in a specific font, size, and style.

- **Measurement of text height**: measures the vertical height of the given text, which usually involves the ascender and descender of the font.

- **Measurement of line spacing**: measures the vertical distance between multiple lines of text, which is usually related to the line spacing of the font.

- **Measurement of character spacing**: measures the horizontal distance between individual characters, which is usually related to the glyph and font design.

- **Layout in a constrained area**: lays out text within a constrained width and height area, and obtains the actual layout dimensions and the adapted string range.

- **Character position query**: obtains the character position corresponding to screen coordinates, which can be used for interactive scenarios such as text selection and cursor positioning.

- **Character and glyph range query**: converts between glyph ranges and character ranges, used for mapping between glyph and character indices in scenarios such as text editing and selection highlighting.

## Available APIs

The following table lists the common APIs for text measurement. For details, see [drawing_text_typography.h](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md).

| Name| Description|
| -------- | -------- |
| double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography\* typography) | Obtains the width of the longest line. You are advised to round up the return value in actual use. |
| double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography\* typography) | Obtains the width of the longest line, including its indentation. You are advised to round up the return value in actual use. |
| size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography\* typography) | Obtains the number of lines. |
| OH_Drawing_LineMetrics\* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography\* typography) | Obtains the metrics about a certain line in a paragraph, including the height, width, and start coordinates of a line. |
| double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle\* style) | Obtains the letter spacing of a text style. |

## How to Develop

1. Add the following library to the `src/main/cpp/CMakeLists.txt` file of the project.

   ```c++
   libnative_drawing.so
   ```

2. Import the required header files.

   <!-- @[c_text_metrics_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_text_declaration.h>
   ```

3. Create a paragraph generator **ParagraphBuilder** and set the paragraph style.

   <!-- @[c_text_metrics_create_paragraph](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Create a text style, set the text color to black, and set the font size to 50.
   OH_Drawing_TextStyle *myTextStyle = OH_Drawing_CreateTextStyle();
   OH_Drawing_SetTextStyleColor(myTextStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   OH_Drawing_SetTextStyleFontSize(myTextStyle, 50.0);
   // Create a paragraph style object to set the typography style.
   OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
   // Set the alignment mode of the paragraph style to left alignment.
   OH_Drawing_SetTypographyTextAlign(typographyStyle, TEXT_ALIGN_LEFT);
   // Create a paragraph generator.
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // Set the text style in the paragraph generator.
   OH_Drawing_TypographyHandlerPushTextStyle(handler, myTextStyle);
   // Add the text content to the paragraph generator.
   const char *text = "Text metrics for typography measurement";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // Generate a paragraph using the paragraph generator.
   OH_Drawing_Typography *typography = OH_Drawing_CreateTypography(handler);
   ```

4. Call the layout API and set the paragraph layout width to perform text shaping and layout on the paragraph.

   <!-- @[c_text_metrics_layout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Shape the paragraph and set the width to maxWidth.
   OH_Drawing_TypographyLayout(typography, maxWidth);
   ```

5. Call the paragraph measurement API to obtain the desired data.

   <!-- @[c_text_metrics_get_all_case](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) --> 

   ``` C++
   // Case 1: Obtain the width of the longest line after typography.
   double longestLine = OH_Drawing_TypographyGetLongestLine(typography);
   DRAWING_LOGI("longestLine: %{public}f", longestLine);
   
   // Case 2: Obtain the number of lines in the paragraph after typography.
   size_t lineCnt = OH_Drawing_TypographyGetLineCount(typography);
   DRAWING_LOGI("lineCnt: %{public}zu", lineCnt);
   
   // Case 3: Obtain the metrics of each line in the paragraph.
   OH_Drawing_LineMetrics *lineMetrics = OH_Drawing_TypographyGetLineMetrics(typography);
   int lineMetricsSize = OH_Drawing_LineMetricsGetSize(lineMetrics);
   for (int i = 0; i < lineMetricsSize; ++i) {
   // lineMetrics is the text metrics measured after typography.
   double curLineAscender = -lineMetrics[i].ascender;
   double curLineWidth = lineMetrics[i].width;
       DRAWING_LOGI("Line %{public}d lineMetrics ascender: %{public}f", i + 1, curLineAscender);
       DRAWING_LOGI("Line %{public}d lineMetrics width: %{public}f", i + 1, curLineWidth);
   }
   
   // Case 4: Obtain the width of the longest line in the paragraph and the width of the longest line with indentation.
   double longestLineWithIndent = OH_Drawing_TypographyGetLongestLineWithIndent(typography);
   DRAWING_LOGI("longestLineWithIndent: %{public}f", longestLineWithIndent);
   
   OH_Drawing_Font_Metrics fontMetrics;
   // Obtain the font metrics of a text style.
   bool result = OH_Drawing_TextStyleGetFontMetrics(typography, myTextStyle, &fontMetrics);
   DRAWING_LOGI("result: %{public}d, fontMetrics ascent: %{public}f", result, fontMetrics.ascent);
   // Obtain the line metrics in a typography object. This API must be called after OH_Drawing_TypographyLayout is called.
   OH_Drawing_LineMetrics lineMetric;
   OH_Drawing_TypographyGetLineMetricsAt(typography, 0, &lineMetric);
   DRAWING_LOGI("Line 1 lineMetrics ascender: %{public}f", -lineMetric.ascender);
   ```

6. Starting from API version 24, you can lay out text within a constrained width and height area and obtain the layout result.

   Use [OH_Drawing_TypographyLayoutWithConstraintsWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographylayoutwithconstraintswithbuffer) to perform layout within specified width and height constraints. The returned result includes the actual layout dimensions (**OH_Drawing_RectSize**) and the adapted string range.

   <!-- @[c_text_metrics_layout_with_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Set the width and height of the constraint area.
   OH_Drawing_RectSize constraintsRect;
   constraintsRect.width = 500.0;
   constraintsRect.height = 200.0;
   OH_Drawing_Array *fitStrRangeArr = nullptr;
   size_t fitStrRangeArrayLen = 0;
   // Lay out text within the constraint area and return the actual layout size.
   OH_Drawing_RectSize actualSize = OH_Drawing_TypographyLayoutWithConstraintsWithBuffer(typography,
       constraintsRect, &fitStrRangeArr, &fitStrRangeArrayLen);
   DRAWING_LOGI("actualSize width: %{public}f, height: %{public}f", actualSize.width, actualSize.height);
   DRAWING_LOGI("fitStrRangeArrayLen: %{public}zu", fitStrRangeArrayLen);
   // Traverse the array of fitted string ranges.
   for (size_t i = 0; i < fitStrRangeArrayLen; ++i) {
       OH_Drawing_Range *range = OH_Drawing_GetRangeByArrayIndex(fitStrRangeArr, i);
       if (range != nullptr) {
           DRAWING_LOGI("fitStrRange[%{public}zu] start: %{public}zu, end: %{public}zu",
               i, OH_Drawing_GetStartFromRange(range), OH_Drawing_GetEndFromRange(range));
       }
   }
   // Release the array of fitted string ranges.
   OH_Drawing_ReleaseArrayBuffer(fitStrRangeArr);
   ```

7. Starting from API version 24, you can obtain character position information based on coordinates.

   Use [OH_Drawing_TypographyGetCharacterPositionAtCoordinateWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetcharacterpositionatcoordinatewithbuffer) to obtain the character position under a specified encoding type. The returned **OH_Drawing_PositionAndAffinity** contains the position index and affinity information.

   <!-- @[c_text_metrics_char_position_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Obtain the character position based on coordinates, using UTF-8 encoding.
   OH_Drawing_PositionAndAffinity *charPos =
       OH_Drawing_TypographyGetCharacterPositionAtCoordinateWithBuffer(
           typography, 100.0, 30.0, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
   if (charPos != nullptr) {
       size_t charPosition = OH_Drawing_GetPositionFromPositionAndAffinity(charPos);
       int affinity = OH_Drawing_GetAffinityFromPositionAndAffinity(charPos);
       DRAWING_LOGI("charPosition (UTF-8 byte offset): %{public}zu, affinity: %{public}d",
           charPosition, affinity);
       OH_Drawing_DestroyPositionAndAffinity(charPos);
   }
   ```

8. Starting from API version 24, you can convert between glyph ranges and character ranges.

   Use [OH_Drawing_TypographyGetCharacterRangeForGlyphRangeWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetcharacterrangeforglyphrangewithbuffer) to obtain the corresponding character range based on a glyph range.

   <!-- @[c_text_metrics_glyph_info_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Obtain the corresponding character range based on the glyph range [0, 5).
   OH_Drawing_Range *actualGlyphRange = nullptr;
   OH_Drawing_Range *charRange =
       OH_Drawing_TypographyGetCharacterRangeForGlyphRangeWithBuffer(
           typography, 0, 5, &actualGlyphRange, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
   if (charRange != nullptr) {
       DRAWING_LOGI("charRange start: %{public}zu, end: %{public}zu",
           OH_Drawing_GetStartFromRange(charRange), OH_Drawing_GetEndFromRange(charRange));
       OH_Drawing_ReleaseRangeBuffer(charRange);
   }
   if (actualGlyphRange != nullptr) {
       DRAWING_LOGI("actualGlyphRange start: %{public}zu, end: %{public}zu",
           OH_Drawing_GetStartFromRange(actualGlyphRange), OH_Drawing_GetEndFromRange(actualGlyphRange));
       OH_Drawing_ReleaseRangeBuffer(actualGlyphRange);
   }
   ```

   Use [OH_Drawing_TypographyGetGlyphRangeForCharacterRangeWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphrangeforcharacterrangewithbuffer) to obtain the corresponding glyph range based on a character range.

   <!-- @[c_text_metrics_glyph_info_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // Obtain the corresponding glyph range based on the character range [0, 10).
   OH_Drawing_Range *actualCharRange = nullptr;
   OH_Drawing_Range *glyphRange =
       OH_Drawing_TypographyGetGlyphRangeForCharacterRangeWithBuffer(
           typography, 0, 10, &actualCharRange, OH_Drawing_TextEncoding::TEXT_ENCODING_UTF8);
   if (glyphRange != nullptr) {
       DRAWING_LOGI("glyphRange start: %{public}zu, end: %{public}zu",
           OH_Drawing_GetStartFromRange(glyphRange), OH_Drawing_GetEndFromRange(glyphRange));
       OH_Drawing_ReleaseRangeBuffer(glyphRange);
   }
   if (actualCharRange != nullptr) {
       DRAWING_LOGI("actualCharRange start: %{public}zu, end: %{public}zu",
           OH_Drawing_GetStartFromRange(actualCharRange), OH_Drawing_GetEndFromRange(actualCharRange));
       OH_Drawing_ReleaseRangeBuffer(actualCharRange);
   }
   ```