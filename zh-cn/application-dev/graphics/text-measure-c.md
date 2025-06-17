# 文本测量（C/C++）

## 场景介绍

文本测量指的是在图形绘制中，对文本的尺寸和布局进行评估，计算文本在给定字体和样式下占用的空间（例如宽度、高度和其他相关信息）的过程。文本测量用于文本排版、布局、渲染以及调整文本显示的位置和大小等场景，便于对界面的布局和呈现更好地把控和调整，以达到设计预期。

当前主要支持以下方面的文本测量能力：

- **文本宽度**：测量给定文本在特定字体、大小和样式下的水平长度。

- **文本高度**：测量给定文本的垂直高度，通常涉及字体的上升线、下降线等。

- **行间距**：测量多行文本之间的垂直距离，通常与字体的行距相关。

- **字符间距**：测量单个字符之间的水平距离，通常与字形和字体设计有关。


## 接口说明

文本测量中常用接口如下表所示，详细接口说明参考[drawing_text_typography.h](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md)。

| 接口名 | 描述 | 
| -------- | -------- |
| doubleOH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography\*) | 获取最长行的宽度，建议实际使用时将返回值向上取整。 | 
| double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography\*) | 获取最长行的宽度（该宽度包含当前行缩进的宽度），建议实际使用时将返回值向上取整。 | 
| size_t OH_Drawing_TypographyGetLineCount (OH_Drawing_Typography\* ) | 获取文本行数。 | 
| OH_Drawing_LineMetrics\* OH_Drawing_TypographyGetLineMetrics (OH_Drawing_Typography\* ) | 获取段落行的度量信息。包含行的高度、宽度、起始坐标等信息。 | 
| double OH_Drawing_TextStyleGetLetterSpacing (OH_Drawing_TextStyle \*) | 获取文本的字符间距。 | 


## 开发步骤

1. 导入依赖的相关头文件。

   ```c++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_declaration.h>
   #include <native_drawing/drawing_text_typography.h>
   ```

2. 创建段落生成器PargraphBuilder，并设置段落样式。

   ```c++
   // 创建段落样式
   OH_Drawing_TypographyStyle *typoStyle = OH_Drawing_CreateTypographyStyle();
   // 创建段落生成器
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typoStyle, OH_Drawing_CreateFontCollection());
   // 创建文本样式，并设置字体大小为50
   OH_Drawing_TextStyle *txtStyle = OH_Drawing_CreateTextStyle();
   OH_Drawing_SetTextStyleFontSize(txtStyle, 50);
   OH_Drawing_TypographyHandlerPushTextStyle(handler, txtStyle);
   // 向构造器中添加文本
   const char *text = "排版测量的文字度量信息";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // 通过生成器构造段落
   OH_Drawing_Typography *typography = OH_Drawing_CreateTypography(handler);
   ```

3. 调用排版接口并设置段落排版宽度，对段落进行塑型排版。

   ```c++
   // 对段落进行塑性排版，设置排版宽度1000
   OH_Drawing_TypographyLayout(typography, 1000);
   ```

4. 调用段落测量信息获取接口，获取指定数据。

   ```c++
   // case1: 获取排版后最长行行宽
   double longestLine = OH_Drawing_TypographyGetLongestLine(typography);
   
   // case2:获取排版后段落行数
   size_t lineCnt = OH_Drawing_TypographyGetLineCount(typography);
   
   // case3:获取段落每行的度量信息
   OH_Drawing_LineMetrics* lineMetrics = OH_Drawing_TypographyGetLineMetrics(typography);
   int lineCnt = OH_Drawing_LineMetricsGetSize(lineMetrics);
   for (int i = 0; i < lineCnt; ++i) {
       // lineMetrics为经过排版测量的文字度量信息
       double curLineAscender = lineMetrics[i].ascender;
       double curLineWidth = lineMetrics[i].width;
   }
   
   // case4:获取段落最长行宽度与带缩进最长行行宽
   double longestLine = OH_Drawing_TypographyGetLongestLine(typography);
   double longestLineWithIndent = OH_Drawing_TypographyGetLongestLineWithIndent(typography);
   ```

