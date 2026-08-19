# 自定义文本绘制与显示（ArkTS）
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @oh_wangxk; @KejiePeng-->
<!--Designer: @liumingxiang-->
<!--Tester: @yhl0101-->
<!--Adviser: @ge-yafang-->

在复杂的文本排版场景中，当系统提供的标准文本组件无法满足特定的视觉或交互需求时，开发者可以利用ArkGraphics 2D提供的底层文本绘制能力，通过直接控制画布（Canvas）和文本样式，实现对文本外观、布局的精细控制。这种能力适用于需要高度定制化文本渲染效果的场景，例如艺术字体、复杂的富文本编排或特殊的动态文字效果。

字体引擎作为图形系统中的核心组件，负责将字符代码转换为可视化的字形，并精确计算每个字形的布局和位置，为自定义文本绘制提供底层支持。通过文本测量接口，开发者可以获取文本的精确尺寸，这是实现精准布局（如居中显示）的基础。

## 文本塑形

### 场景介绍
文本塑形是字体引擎提供的一项关键能力，它允许开发者不经过系统默认的文本排版流程，直接获取文本的底层字形信息（如宽度、方向等测量信息）。这使得开发者能够基于这些原始数据，实现完全自定义的排版逻辑、绘制操作以及断行策略。

这种能力适用于以下场景：

- 自定义富文本渲染：例如在社交媒体、新闻客户端等应用中，需要实现图文混排、多样式文本混合显示。

- 跨平台一致性排版需求应用：确保文本在不同平台或设备上呈现一致的视觉效果。

- 精细化排版管理：如实现艺术排版、动态文字布局等系统标准文本组件难以达到的效果。

### 接口说明
文本塑形中常用接口如下表所示，详细接口说明参考[@ohos.graphics.text (文本模块)](../reference/apis-arkgraphics2d/js-apis-graphics-text.md)、[TextBlob](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-TextBlob.md)和[drawTextBlob](../reference/apis-arkgraphics2d/arkts-apis-graphics-drawing-Canvas.md#drawtextblob)。

| 接口名 | 描述 | 
| -------- | -------- |
| buildLineTypeset(): LineTypeset | 构建行排版器。 | 
| createLine(startIndex: number, count: number): TextLine | 根据指定的排版区间生成文本行对象。 | 
| getGlyphRuns(): Array&lt;Run&gt; | 获取文本行的排版单元数组。 | 
| getGlyphs(): Array&lt;number&gt; | 获取该排版单元中每个字符的字形序号。 | 
| getFont(): drawing.Font | 获取排版单元的字体属性对象。 | 
| getAdvances(range: Range): Array&lt;common2D.Point&gt; | 获取该排版单元指定范围内每个字形的字形宽度数组。 | 
| static makeFromRunBuffer(pos: Array&lt;TextBlobRunBuffer&gt;, font: Font, bounds?: common2D.Rect): TextBlob | 基于RunBuffer信息创建TextBlob对象。 | 
| drawTextBlob(blob: TextBlob, x: number, y: number): void | 绘制一段文字。若构造blob的字体不支持待绘制字符，则该部分字符无法绘制。 | 


### 开发步骤
从API version 18开始，支持获取文字塑形结果能力。从API version 20开始，支持获取文字排版方向和文字字形宽度。关键代码如下：

1. 导入依赖的相关模块。

   ```ts
   import { text } from '@kit.ArkGraphics2D'
   import { drawing } from '@kit.ArkGraphics2D'
   import { common2D } from '@kit.ArkGraphics2D'
   ```

2. 创建段落样式，并构造段落生成器ParagraphBuilder实例。
   <!-- @[arkts_independent_shaping_text_paragraph_builder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/ComplexTextDrawing/entry/src/main/ets/pages/shape/IndependentShaping.ets) -->
   
   ``` TypeScript
   let myTextStyle: text.TextStyle = {
     // 文本大小
     fontSize: 60
   };
   let myParagraphStyle: text.ParagraphStyle = {
     textStyle: myTextStyle,
   };
   let fontCollection = text.FontCollection.getGlobalInstance();
   let paragraphBuilder = new text.ParagraphBuilder(myParagraphStyle, fontCollection);
   ```

3. 添加文本内容。
   <!-- @[arkts_independent_shaping_text_add_text](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/ComplexTextDrawing/entry/src/main/ets/pages/shape/IndependentShaping.ets) -->
   
   ``` TypeScript
   paragraphBuilder.addText('Hello World');
   ```

4. 创建行对象。获取行中所有文字的塑形结果。使用createLine()方法创建一个单行对象，通过行对象getGlyphRuns()方法获取相同样式的文字单元。
   <!-- @[arkts_independent_shaping_text_get_glyph_runs](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/ComplexTextDrawing/entry/src/main/ets/pages/shape/IndependentShaping.ets) -->
   
   ``` TypeScript
   // 生成行
   let lineTypeSet: text.LineTypeset = paragraphBuilder.buildLineTypeset()
   let textLine: text.TextLine = lineTypeSet.createLine(0, 11);
   
   // 获取塑形结果
   let runs: text.Run[] = textLine.getGlyphRuns();
   ```

5. 该步骤是文本塑形流程中的自定义绘制环节。通过调用getGlyphs()方法获取文本中每个字符对应的字形序号，再结合getFont()方法获取的字体对象，即可唯一确定每个字形的具体图形信息。从 API version 20 开始，新增的getAdvances()方法能够返回一个数组，包含范围内每个字形的字形宽度。依赖这些精确的测量数据，开发者可以自由地计算并定义每个字形的绘制位置，从而实现复杂的文本布局效果，如自定义字符间距、垂直偏移或特殊排版。
   <!-- @[arkts_independent_shaping_text_drawing](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/ComplexTextDrawing/entry/src/main/ets/pages/shape/IndependentShaping.ets) -->
   
   ``` TypeScript
   let x: number = 0;
   let y: number = 0;
   for (let index = 0; index < runs.length; index++) {
     const run = runs[index];
     // 绘制字形
     let glyphs: number[] = run.getGlyphs();
     let font: drawing.Font = run.getFont();
     let advances: common2D.Point[] = run.getAdvances({ start: 0, end: 0 });
   
     // 创建字形buffer，通过drawing接口进行字形独立绘制
     let runBuffer: drawing.TextBlobRunBuffer[] = [];
     for (let i = 0; i < glyphs.length; i++) {
       runBuffer.push({ glyph: glyphs[i], positionX: x, positionY: y });
       x += advances[i].x + 10;
       y += advances[i].y + 30;
     }
     let textBlob: drawing.TextBlob = drawing.TextBlob.makeFromRunBuffer(runBuffer, font, null);
     // 自定义绘制一串具有相同属性的一系列连续字形
     canvas.drawTextBlob(textBlob, 20, 100);
   }
   ```

效果展示：

![ts_independent_shaping.png](figures/ts_independent_shaping.png)