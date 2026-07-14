# 文本测量（ArkTS）
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @gmiao522-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->

## 场景介绍

文本测量指的是在图形绘制中，对文本的尺寸和布局进行评估，计算文本在给定字体和样式下占用的空间（例如宽度、高度和其他相关信息）的过程。文本测量用于文本排版、布局、渲染以及调整文本显示的位置和大小等场景，便于更精准地控制与调整界面的布局和呈现，以达到设计预期。

当前主要支持以下方面的文本测量能力：


- **文本宽度**：测量给定文本在特定字体、大小和样式下的水平长度。

- **文本高度**：测量给定文本的垂直高度，通常涉及文本的上升线、下降线等。

- **行间距**：测量多行文本之间的垂直距离，通常与文本的行距相关。

- **字符间距**：测量单个字符之间的水平距离，通常与字形和字体设计有关。

- **限制区域排版**：在限定宽高区域内排版文本，获取实际排版尺寸和适配的字符串范围。

- **字符位置查询**：根据屏幕坐标获取对应的字符位置，可用于文本选择、光标定位等交互场景。

- **字符和字形范围查询**：在字形范围与字符范围之间进行相互转换，用于文本编辑、选择高亮等场景中字形与字符索引的映射。


## 接口说明

文本测量中常用接口如下表所示，详细接口说明参考[@ohos.graphics.text (文本模块)](../reference/apis-arkgraphics2d/js-apis-graphics-text.md)。

| 接口名 | 描述 |
| -------- | -------- |
| getLongestLine(): number | 获取当前段落最长行的宽度，建议实际使用时将返回值向上取整。 |
| getLongestLineWithIndent(): number | 获取当前段落最长行的宽度（该宽度包含当前行缩进的宽度），建议实际使用时将返回值向上取整。 |
| getTextLines(): Array&lt;TextLine&gt; | 获取当前段落文本行对象数组。 |
| getLineMetrics(): Array&lt;LineMetrics&gt; | 获取段落所有行的度量信息。包含行的高度、宽度、起始坐标等信息。 |
| getLineMetrics(lineNumber: number): LineMetrics \| undefined | 获取段落指定行的度量信息。包含行的高度、宽度、起始坐标等信息。超出当前段落排版后最大行数后返回undefined。 |


## 开发步骤

1. 导入依赖的相关模块。

   <!-- @[ts_text_metrics_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   import { text, drawing } from '@kit.ArkGraphics2D';
   ```

2. 创建段落样式，并构造段落生成器ParagraphBuilder实例。

   <!-- @[ts_text_metrics_create_paragraphBuilder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 设置文本样式
   let myTextStyle: text.TextStyle = {
     color: {
       alpha: 255,
       red: 255,
       green: 0,
       blue: 0
     },
     fontSize: 100
   };
   // 创建一个段落样式对象，以设置排版风格
   let myParagraphStyle: text.ParagraphStyle = {
     textStyle: myTextStyle,
     wordBreak: text.WordBreak.NORMAL
   };
   // 创建一个段落生成器
   let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, new text.FontCollection());
   ```

3. 设置文本样式，添加文本内容，并生成段落文本用于后续文本的绘制显示。

   <!-- @[ts_text_metrics_create_paragraph](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 在段落生成器中设置文本样式
   paragraphBuilder.pushStyle(myTextStyle);
   // 在段落生成器中设置文本内容
   paragraphBuilder.addText("文本测量测试");
   // 通过段落生成器生成段落
   let paragraph = paragraphBuilder.build();
   ```

4. 调用测量相关接口，获取指定的测量信息。

   <!-- @[ts_text_metrics_get_all_case](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->
   
   ``` TypeScript
   // 对段落进行塑形排版，设置排版宽度为1000
   paragraph.layoutSync(1000);
   // case1: 获取排版后最长行行宽
   let longestLineWidth = paragraph.getLongestLine();
   console.info("longestLineWidth = " + longestLineWidth);
   
   // case2: 获取排版后最长行行宽(包含缩进)
   let longestLineWithIndentWidth = paragraph.getLongestLineWithIndent();
   console.info("longestLineWithIndentWidth = " + longestLineWithIndentWidth);
   
   // case3: 获取排版后所有行对象
   let textLines = paragraph.getTextLines();
   for (let index = 0; index < textLines.length; index++) {
     const textline = textLines[index];
     let curLineRange = textline.getTextRange();
     let curLineGlyCnt = textline.getGlyphCount();
     console.info("MetricsMSG: 第" + (index + 1) + "行 TextRange start: " + curLineRange.start + " TextRange end: " + curLineRange.end);
     console.info("MetricsMSG: 第" + (index + 1) + "行字形数量为: " + curLineGlyCnt);
   }
   
   // case4: 获取排版后指定行对应的度量信息
   let lineCnt = paragraph.getLineCount();
   for (let index = 0; index < lineCnt; index++) {
     let lineMetrics = paragraph.getLineMetrics(index);
     if (lineMetrics) {
       console.info("MetricsMSG: 第" + (index + 1) + "行 lineMetrics width: " + lineMetrics.width);
       console.info("MetricsMSG: 第" + (index + 1) + "行 lineMetrics start index: " + lineMetrics.startIndex + ", end index: " +
       lineMetrics.endIndex);
     }
   }
   
   // case5: 获取排版后所有行度量信息数组
   let allLineMetrics = paragraph.getLineMetrics();
   console.info("MetricsMSG: 第1行 lineMetrics width: " + allLineMetrics[0].width);
   ```

5. 从API version 24开始支持在限定宽高区域内排版文本，获取排版结果。

   使用[layoutWithConstraints()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#layoutwithconstraints24)接口可以在指定的宽高约束内进行排版，返回的结果包含实际排版尺寸（correctRect）和适配的字符串范围（fitStrRange）。

   <!-- @[ts_text_metrics_layout_with_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case6: 在限定宽高区域内排版文本，获取排版结果
   let constraint: text.TextRectSize = { width: 600, height: 200 };
   let layoutResult: text.TextLayoutResult = paragraph.layoutWithConstraints(constraint);
   // 获取排版后的实际尺寸
   console.info("MetricsMSG: correctRect width: " + layoutResult.correctRect.width +
     ", height: " + layoutResult.correctRect.height);
   // 获取适配的字符串范围
   for (let i = 0; i < layoutResult.fitStrRange.length; i++) {
     console.info("MetricsMSG: fitStrRange[" + i + "] start: " + layoutResult.fitStrRange[i].start +
       ", end: " + layoutResult.fitStrRange[i].end);
   }
   ```

6. 从API version 24开始支持根据坐标获取字符位置信息。

   使用[getCharacterPositionAtCoordinate()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getcharacterpositionatcoordinate24)获取指定编码类型下的字符位置。返回的PositionWithAffinity包含字符索引和亲和度信息。

   <!-- @[ts_text_metrics_get_character_position](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case8: 根据坐标获取字符位置（指定编码类型）
   let charPos: text.PositionWithAffinity =
     paragraph.getCharacterPositionAtCoordinate(100, 50, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   console.info("MetricsMSG: charPos position: " + charPos.position +
     ", affinity: " + charPos.affinity);
   ```

7. 从API version 24开始支持字形范围与字符范围的相互转换。

   使用[getCharacterRangeForGlyphRange()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getcharacterrangeforglyphrange24)根据字形范围获取对应的字符范围，使用[getGlyphRangeForCharacterRange()](../reference/apis-arkgraphics2d/js-apis-graphics-text.md#getglyphrangeforcharacterrange24)根据字符范围获取对应的字形范围。返回的数组包含两个元素，第一个是目标范围，第二个是实际范围。编码类型支持UTF-8和UTF-16。

   <!-- @[ts_text_metrics_glyph_character_range](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/TextMetrics/entry/src/main/ets/pages/Index.ets) -->

   ``` TypeScript
   // case9: 根据字形范围获取字符范围
   let glyphRange: text.Range = { start: 0, end: 2 };
   let glyphToCharRanges: Array<text.Range> =
     paragraph.getCharacterRangeForGlyphRange(glyphRange, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   // 返回数组第一个为字符范围，第二个为实际字形范围
   console.info("MetricsMSG: charRange start: " + glyphToCharRanges[0].start +
     ", end: " + glyphToCharRanges[0].end);
   console.info("MetricsMSG: actualGlyphRange start: " + glyphToCharRanges[1].start +
     ", end: " + glyphToCharRanges[1].end);
   // case10: 根据字符范围获取字形范围
   let charRange: text.Range = { start: 0, end: 2 };
   let charToGlyphRanges: Array<text.Range> =
     paragraph.getGlyphRangeForCharacterRange(charRange, drawing.TextEncoding.TEXT_ENCODING_UTF16);
   // 返回数组第一个为字形范围，第二个为实际字符范围
   console.info("MetricsMSG: glyphRange start: " + charToGlyphRanges[0].start +
     ", end: " + charToGlyphRanges[0].end);
   console.info("MetricsMSG: actualCharRange start: " + charToGlyphRanges[1].start +
     ", end: " + charToGlyphRanges[1].end);
   ```
