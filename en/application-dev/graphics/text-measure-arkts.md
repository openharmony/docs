# Text Measurement (ArkTS)

<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=bf8f4e66ff4670425bebf86f62c06d3a07dae9d4 translatedAt=2026-08-03T11:23:46.768Z pushedAt=2026-08-04T07:42:16.906Z -->

## Overview

Text measurement refers to the process of evaluating the size and layout of text and calculating the space (such as the width, height, and other related information) occupied by the text in a given font and style during graphics drawing. Text measurement helps manage typography, layout, rendering, and adjustments for text position and size. It ensures precise UI layouts and presentations align with design goals.

The following text measurement capabilities are supported:

- **Measurement of text width**: measures the horizontal length of the given text in a specific font, size, and style.

- **Measurement of text height**: measures the vertical height of the given text, which usually involves the ascender and descender of the text.

- **Measurement of line spacing**: measures the vertical distance between multiple lines of text, which is usually related to the line spacing of the text.

- **Measurement of character spacing**: measures the horizontal distance between individual characters, which is usually related to the glyph and font design.

- **Layout with constraints**: lays out text within a constrained width and height area, and obtains the actual layout dimensions and the adapted string range.

- **Character position query**: obtains the corresponding character position based on screen coordinates, which can be used for interactive scenarios such as text selection and cursor positioning.

- **Character and glyph range query**: converts between glyph ranges and character ranges, enabling mapping between glyph and character indices in scenarios such as text editing and selection highlighting.

## Available APIs

The following table lists the common APIs used for text measurement. For details about the APIs, see [@ohos.graphics.text (Text)](../reference/apis-arkgraphics2d/js-apis-graphics-text.md).

| Name| Description| 
| -------- | -------- |
| getLongestLine(): number | Obtains the width of the longest line of a paragraph. You are advised to round up the return value in actual use.| 
| getLongestLineWithIndent(): number | Obtains the width of the longest line of a paragraph, including its indentation. You are advised to round up the return value in actual use.| 
| getTextLines(): Array&lt;TextLine&gt; | Obtains the array of text line objects of a paragraph.| 
| getLineMetrics(): Array&lt;LineMetrics&gt; | Obtains the metrics about all lines in a paragraph, including the height, width, and start coordinates of a line.| 
| getLineMetrics(lineNumber: number): LineMetrics \| undefined | Obtains the metrics about a certain line in a paragraph, including the height, width, and start coordinates of a line. It returns **undefined** when the input line number goes beyond the maximum number of lines that the current paragraph has after typography.| 

## How to Develop

1. Import the required module.

   <!-- @[ts_text_metrics_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   import { text, drawing } from '@kit.ArkGraphics2D';
   ```

2. Create a paragraph style and use **ParagraphBuilder** to generate a paragraph instance.

   <!-- @[ts_text_metrics_create_paragraphBuilder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Set the text style.
   let myTextStyle: text.TextStyle = {
     color: {
       alpha: 255,
       red: 255,
       green: 0,
       blue: 0
     },
     fontSize: 100
   };
   // Create a paragraph style object to set the typography style.
   let myParagraphStyle: text.ParagraphStyle = {
     textStyle: myTextStyle,
     wordBreak: text.WordBreak.NORMAL
   };
   // Create a paragraph generator.
   let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, new text.FontCollection());
   ```

3. Set the text style, add text content, and generate paragraph text for subsequent text drawing and display.

   <!-- @[ts_text_metrics_create_paragraph](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Set the text style in the paragraph generator.
   paragraphBuilder.pushStyle(myTextStyle);
   // Set the text content in the paragraph generator.
   paragraphBuilder.addText("Text measurement test");
   // Generate a paragraph using the paragraph generator.
   let paragraph = paragraphBuilder.build();
   ```

4. Call the measurement APIs to obtain the desired information.

   <!-- @[ts_text_metrics_get_all_case](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // Shape the paragraph and set the width to 1000.
   paragraph.layoutSync(1000);
   // Case 1: Obtain the width of the longest line after typography.
   let longestLineWidth = paragraph.getLongestLine();
   console.info("longestLineWidth = " + longestLineWidth);
   
   // Case 2: Obtain the width of the longest line after typography (including indentation).
   let longestLineWithIndentWidth = paragraph.getLongestLineWithIndent();
   console.info("longestLineWithIndentWidth = " + longestLineWithIndentWidth);
   
   // Case 3: Obtain all line objects after typography.
   let textLines = paragraph.getTextLines();
   for (let index = 0; index < textLines.length; index++) {
     const textline = textLines[index];
     let curLineRange = textline.getTextRange();
     let curLineGlyCnt = textline.getGlyphCount();
     console.info("MetricsMSG: line " + (index + 1) + "TextRange start: " + curLineRange.start + " TextRange end: " + curLineRange.end);
     console.info("MetricsMSG: line" + (index + 1) + "glyph count: " + curLineGlyCnt);
   }
   
   // Case 4: Obtain the metrics of a certain line after typography.
   let lineCnt = paragraph.getLineCount();
   for (let index = 0; index < lineCnt; index++) {
     let lineMetrics = paragraph.getLineMetrics(index);
     if (lineMetrics) {
       console.info("MetricsMSG: line" + (index + 1) + "lineMetrics width: " + lineMetrics.width);
       console.info("MetricsMSG: line" + (index + 1) + "lineMetrics start index: " + lineMetrics.startIndex + ", end index: " +
       lineMetrics.endIndex);
     }
   }
   
   // Case 5: Obtain the metrics array of all lines after typography.
   let allLineMetrics = paragraph.getLineMetrics();
   console.info("MetricsMSG: line 1 lineMetrics width: " + allLineMetrics[0].width);
   ```

5. Starting from API version 24, you can lay out text within a constrained width and height area and obtain the layout result.

   Use [layoutWithConstraints()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#layoutwithconstraints24) to lay out text within the specified width and height constraints. The returned result includes the actual layout dimensions (**correctRect**) and the adapted string range (**fitStrRange**).

   <!-- @[ts_text_metrics_layout_with_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case6: Layout text within a constrained width and height area, and obtain the layout result.
   let constraint: text.TextRectSize = { width: 600, height: 200 };
   let layoutResult: text.TextLayoutResult = paragraph.layoutWithConstraints(constraint);
   // Obtain the actual dimensions after layout.
   console.info("MetricsMSG: correctRect width: " + layoutResult.correctRect.width +
     ", height: " + layoutResult.correctRect.height);
   // Obtain the fitted string range.
   for (let i = 0; i < layoutResult.fitStrRange.length; i++) {
     console.info("MetricsMSG: fitStrRange[" + i + "] start: " + layoutResult.fitStrRange[i].start +
       ", end: " + layoutResult.fitStrRange[i].end);
   }
   ```

6. Starting from API version 24, you can obtain character position information based on coordinates.

   Use [getCharacterPositionAtCoordinate()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getcharacterpositionatcoordinate24) to obtain the character position under the specified encoding type. The returned **PositionWithAffinity** contains the character index and affinity information.

   <!-- @[ts_text_metrics_get_character_position](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case8: Obtain the character position based on coordinates (with encoding type specified).
   let charPos: text.PositionWithAffinity =
     paragraph.getCharacterPositionAtCoordinate(100, 50, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   console.info("MetricsMSG: charPos position: " + charPos.position +
     ", affinity: " + charPos.affinity);
   ```

7. Starting from API version 24, you can convert between glyph ranges and character ranges.

   Use [getCharacterRangeForGlyphRange()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getcharacterrangeforglyphrange24) to obtain the corresponding character range based on a glyph range, and use [getGlyphRangeForCharacterRange()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getglyphrangeforcharacterrange24) to obtain the corresponding glyph range based on a character range. The returned array contains two elements: the first is the target range, and the second is the actual range. Both UTF-8 and UTF-16 encoding types are supported.

   <!-- @[ts_text_metrics_glyph_character_range](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case9: Obtain the character range based on the glyph range.
   let glyphRange: text.Range = { start: 0, end: 2 };
   let glyphToCharRanges: Array<text.Range> =
     paragraph.getCharacterRangeForGlyphRange(glyphRange, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   // The first element of the returned array is the character range, and the second is the actual glyph range.
   console.info("MetricsMSG: charRange start: " + glyphToCharRanges[0].start +
     ", end: " + glyphToCharRanges[0].end);
   console.info("MetricsMSG: actualGlyphRange start: " + glyphToCharRanges[1].start +
     ", end: " + glyphToCharRanges[1].end);
   // case10: Obtain the glyph range based on the character range.
   let charRange: text.Range = { start: 0, end: 2 };
   let charToGlyphRanges: Array<text.Range> =
     paragraph.getGlyphRangeForCharacterRange(charRange, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   // The first element of the returned array is the glyph range, and the second is the actual character range.
   console.info("MetricsMSG: glyphRange start: " + charToGlyphRanges[0].start +
     ", end: " + charToGlyphRanges[0].end);
   console.info("MetricsMSG: actualCharRange start: " + charToGlyphRanges[1].start +
     ", end: " + charToGlyphRanges[1].end);
   ```