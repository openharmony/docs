# 文本测量（C/C++）
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

- **文本高度**：测量给定文本的垂直高度，通常涉及字体的上升线、下降线等。

- **行间距**：测量多行文本之间的垂直距离，通常与字体的行距相关。

- **字符间距**：测量单个字符之间的水平距离，通常与字形和字体设计有关。

- **限制区域排版**：在限定宽高区域内排版文本，获取实际排版尺寸和适配的字符串范围。

- **字符位置查询**：根据屏幕坐标获取对应的字符位置，可用于文本选择、光标定位等交互场景。

- **字符和字形范围查询**：在字形范围与字符范围之间进行相互转换，用于文本编辑、选择高亮等场景中字形与字符索引的映射。


## 接口说明

文本测量中常用接口如下表所示，详细接口说明参考[drawing_text_typography.h](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md)。

| 接口名 | 描述 | 
| -------- | -------- |
| double OH_Drawing_TypographyGetLongestLine(OH_Drawing_Typography\* typography) | 获取最长行的宽度，建议实际使用时将返回值向上取整。 | 
| double OH_Drawing_TypographyGetLongestLineWithIndent(OH_Drawing_Typography\* typography) | 获取最长行的宽度（该宽度包含当前行缩进的宽度），建议实际使用时将返回值向上取整。 | 
| size_t OH_Drawing_TypographyGetLineCount(OH_Drawing_Typography\* typography) | 获取文本行数。 | 
| OH_Drawing_LineMetrics\* OH_Drawing_TypographyGetLineMetrics(OH_Drawing_Typography\* typography) | 获取段落行的度量信息。包含行的高度、宽度、起始坐标等信息。 | 
| double OH_Drawing_TextStyleGetLetterSpacing(OH_Drawing_TextStyle\* style) | 获取文本的字符间距。 | 


## 开发步骤

1. 在工程的`src/main/cpp/CMakeLists.txt`文件中添加以下lib。
   ```c++
   libnative_drawing.so
   ```

2. 导入依赖的相关头文件。

   <!-- @[c_text_metrics_include](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   #include <native_drawing/drawing_font_collection.h>
   #include <native_drawing/drawing_text_typography.h>
   #include <native_drawing/drawing_text_declaration.h>
   ```

3. 创建段落生成器ParagraphBuilder，并设置段落样式。

   <!-- @[c_text_metrics_create_paragraph](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 创建文本样式，设置文本颜色为黑色并设置字体大小为50
   OH_Drawing_TextStyle *myTextStyle = OH_Drawing_CreateTextStyle();
   OH_Drawing_SetTextStyleColor(myTextStyle, OH_Drawing_ColorSetArgb(0xFF, 0x00, 0x00, 0x00));
   OH_Drawing_SetTextStyleFontSize(myTextStyle, 50.0);
   // 创建一个段落样式对象，以设置排版风格
   OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
   // 设置段落样式的对齐方式为左对齐
   OH_Drawing_SetTypographyTextAlign(typographyStyle, TEXT_ALIGN_LEFT);
   // 创建一个段落生成器
   OH_Drawing_TypographyCreate *handler = OH_Drawing_CreateTypographyHandler(typographyStyle, fontCollection);
   // 在段落生成器中设置文本样式
   OH_Drawing_TypographyHandlerPushTextStyle(handler, myTextStyle);
   // 在段落生成器中添加文本内容
   const char *text = "排版测量的文字度量信息";
   OH_Drawing_TypographyHandlerAddText(handler, text);
   // 通过段落生成器生成段落
   OH_Drawing_Typography *typography = OH_Drawing_CreateTypography(handler);
   ```

4. 调用排版接口并设置段落排版宽度，对段落进行塑形排版。

   <!-- @[c_text_metrics_layout](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->
   
   ``` C++
   // 对段落进行塑形排版，设置排版宽度为maxWidth
   OH_Drawing_TypographyLayout(typography, maxWidth);
   ```

5. 调用段落测量信息获取接口，获取指定数据。

   <!-- @[c_text_metrics_get_all_case](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) --> 
   
   ``` C++
   // case1: 获取排版后最长行行宽
   double longestLine = OH_Drawing_TypographyGetLongestLine(typography);
   DRAWING_LOGI("longestLine: %{public}f", longestLine);
   
   // case2:获取排版后段落行数
   size_t lineCnt = OH_Drawing_TypographyGetLineCount(typography);
   DRAWING_LOGI("lineCnt: %{public}zu", lineCnt);
   
   // case3:获取段落每行的度量信息
   OH_Drawing_LineMetrics *lineMetrics = OH_Drawing_TypographyGetLineMetrics(typography);
   int lineMetricsSize = OH_Drawing_LineMetricsGetSize(lineMetrics);
   for (int i = 0; i < lineMetricsSize; ++i) {
   // lineMetrics为经过排版测量的文字度量信息
   double curLineAscender = -lineMetrics[i].ascender;
   double curLineWidth = lineMetrics[i].width;
       DRAWING_LOGI("第%{public}d行 lineMetrics ascender: %{public}f", i + 1, curLineAscender);
       DRAWING_LOGI("第%{public}d行 lineMetrics width: %{public}f", i + 1, curLineWidth);
   }
   
   // case4:获取段落最长行宽度与带缩进最长行行宽
   double longestLineWithIndent = OH_Drawing_TypographyGetLongestLineWithIndent(typography);
   DRAWING_LOGI("longestLineWithIndent: %{public}f", longestLineWithIndent);
   
   OH_Drawing_Font_Metrics fontMetrics;
   // 获取文本字体属性
   bool result = OH_Drawing_TextStyleGetFontMetrics(typography, myTextStyle, &fontMetrics);
   DRAWING_LOGI("result: %{public}d, fontMetrics ascent: %{public}f", result, fontMetrics.ascent);
   // 获取排版对象的指定行位置信息，该接口需要在OH_Drawing_TypographyLayout接口调用之后调用
   OH_Drawing_LineMetrics lineMetric;
   OH_Drawing_TypographyGetLineMetricsAt(typography, 0, &lineMetric);
   DRAWING_LOGI("第1行 lineMetrics ascender: %{public}f", -lineMetric.ascender);
   ```

6. 从API version 24开始支持在限定宽高区域内排版文本，获取排版结果。

   使用[OH_Drawing_TypographyLayoutWithConstraintsWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographylayoutwithconstraintswithbuffer)接口可以在指定的宽高约束内进行排版，返回的结果包含实际排版尺寸（OH_Drawing_RectSize）和适配的字符串范围。

   <!-- @[c_text_metrics_layout_with_constraints](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // 设置限定区域的宽高
   OH_Drawing_RectSize constraintsRect;
   constraintsRect.width = 500.0;
   constraintsRect.height = 200.0;
   OH_Drawing_Array *fitStrRangeArr = nullptr;
   size_t fitStrRangeArrayLen = 0;
   // 在限定区域内排版文本，返回实际排版尺寸
   OH_Drawing_RectSize actualSize = OH_Drawing_TypographyLayoutWithConstraintsWithBuffer(typography,
       constraintsRect, &fitStrRangeArr, &fitStrRangeArrayLen);
   DRAWING_LOGI("actualSize width: %{public}f, height: %{public}f", actualSize.width, actualSize.height);
   DRAWING_LOGI("fitStrRangeArrayLen: %{public}zu", fitStrRangeArrayLen);
   // 遍历适配字符串范围数组
   for (size_t i = 0; i < fitStrRangeArrayLen; ++i) {
       OH_Drawing_Range *range = OH_Drawing_GetRangeByArrayIndex(fitStrRangeArr, i);
       if (range != nullptr) {
           DRAWING_LOGI("fitStrRange[%{public}zu] start: %{public}zu, end: %{public}zu",
               i, OH_Drawing_GetStartFromRange(range), OH_Drawing_GetEndFromRange(range));
       }
   }
   // 释放适配字符串范围数组
   OH_Drawing_ReleaseArrayBuffer(fitStrRangeArr);
   ```

7. 从API version 24开始支持根据坐标获取字符位置信息。

   使用[OH_Drawing_TypographyGetCharacterPositionAtCoordinateWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetcharacterpositionatcoordinatewithbuffer)获取指定编码类型下的字符位置。返回的`OH_Drawing_PositionAndAffinity`包含位置索引和亲和度信息。

   <!-- @[c_text_metrics_char_position_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // 根据坐标获取字符位置，使用UTF-8编码
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

8. 从API version 24开始支持字形范围与字符范围的相互转换。

   使用[OH_Drawing_TypographyGetCharacterRangeForGlyphRangeWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetcharacterrangeforglyphrangewithbuffer)根据字形范围获取对应的字符范围。

   <!-- @[c_text_metrics_glyph_info_step1](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // 根据字形范围[0, 5)获取对应的字符范围
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

   使用[OH_Drawing_TypographyGetGlyphRangeForCharacterRangeWithBuffer](../reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_typographygetglyphrangeforcharacterrangewithbuffer)根据字符范围获取对应的字形范围。

   <!-- @[c_text_metrics_glyph_info_step2](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkGraphics2D/TextEngine/NDKTextMeasurement/entry/src/main/cpp/samples/sample_bitmap.cpp) -->

   ``` C++
   // 根据字符范围[0, 10)获取对应的字形范围
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