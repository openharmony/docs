# 使用Text组件
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

[ArkUI](arkui-overview.md)开发框架在[NDK](../napi/ndk-development-overview.md)接口中提供了Text组件，用于显示文本内容。Text组件支持丰富的样式设置，包括字体、颜色、对齐方式、文字效果等，还支持多种子组件，如[Span](#添加span)、[ImageSpan](#添加imagespan)、[StyledString](./ndk-styled-string.md)等，用于实现复杂的文本显示效果。

> **说明：**
>
> - 本篇示例仅提供核心接口的调用方法，完整的示例工程请参考<!--RP1-->[native_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/native_node_sample/)<!--RP1End-->。
>
> - 开发前需要先接入ArkTS页面，具体请参考[接入ArkTS页面](./ndk-access-the-arkts-page.md)。

## 创建文本组件

Text组件是显示文本内容的基础组件，支持多种样式设置和子组件。

### 创建基础文本

使用[createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode)接口创建Text组件，节点类型为ARKUI_NODE_TEXT。

<!-- @[text_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
ArkUI_NodeHandle text = Manager::nodeAPI_->createNode(ARKUI_NODE_TEXT);
ArkUI_NumberValue textWidth[] = {{.f32 = VALUE_300}};
ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text, NODE_WIDTH, &textWidthItem);
ArkUI_NumberValue textHeight[] = {{.f32 = VALUE_30}};
ArkUI_AttributeItem textHeightItem = {.value = textHeight, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text, NODE_HEIGHT, &textHeightItem);
```

### 设置文本内容

- 通过[NODE_TEXT_CONTENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_content)属性设置Text组件的基本文本内容。

  <!-- @[text_content](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  const char *textContent = "this is text 2 this is text 2 this is text 2!!!! ";
  ArkUI_AttributeItem contentItem = {.string = textContent};
  Manager::nodeAPI_->setAttribute(text2, NODE_TEXT_CONTENT, &contentItem);
  ```

- 通过[NODE_TEXT_CONTENT_WITH_STYLED_STRING](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_content_with_styled_string)属性设置文本内容。

  StyledString提供了更高级的文本排版功能，支持为文本的不同部分设置不同样式，包括字体大小、颜色、占位符等。关于StyledString的详细使用方法，请参考[使用属性字符串](./ndk-styled-string.md)文档。

## 设置文本样式

Text组件支持丰富的文本样式设置，包括字体、颜色、对齐方式等。

### 设置字体属性

通过如下属性设置字体大小、粗细、样式等基本属性。

**表1** 字体属性

| 属性 | 说明 |
|------|------|
| [NODE_FONT_SIZE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_size) | 设置字体大小。 |
| [NODE_FONT_WEIGHT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_weight) | 设置字体粗细。 |
| [NODE_FONT_STYLE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_style) | 设置字体样式。 |
| [NODE_FONT_FAMILY](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_family) | 设置字体列表。 |

<!-- @[text_font_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) --> 

``` C++
// 设置文字大小：28、文字颜色：0xFFFF0000（红色）
ArkUI_NumberValue fontSize[] = {{.f32 = VALUE_28}};
ArkUI_AttributeItem fontSizeItem = {.value = fontSize, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_SIZE, &fontSizeItem);
ArkUI_NumberValue fontColor = {.u32 = 0xFFFF0000};
ArkUI_AttributeItem fontColorItem = {.value = &fontColor, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_COLOR, &fontColorItem);

// 字体样式：斜体样式（ARKUI_FONT_STYLE_ITALIC）
ArkUI_NumberValue fontStyleVal = {.i32 = ARKUI_FONT_STYLE_ITALIC};
ArkUI_AttributeItem fontStyleItem = {&fontStyleVal, VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_STYLE, &fontStyleItem);

// 字重：Bold（ARKUI_FONT_WEIGHT_W800）
ArkUI_NumberValue fontWeightVal = {.i32 = ARKUI_FONT_WEIGHT_W800};
ArkUI_AttributeItem textWeightItem = {.value = &fontWeightVal, .size = 1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_WEIGHT, &textWeightItem);
```

### 设置文本对齐

通过如下属性设置文本的水平对齐方式和垂直对齐方式。

**表2** 文本对齐属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_ALIGN](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_align) | 设置文本水平对齐。 |
| [NODE_TEXT_VERTICAL_ALIGN](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_vertical_align) | 设置文本垂直对齐。 |
- 设置文本水平对齐。
  <!-- @[text_align](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 水平对齐：居中对齐（ARKUI_TEXT_ALIGNMENT_CENTER）
  ArkUI_NumberValue intVal_0 = {.i32 = ARKUI_TEXT_ALIGNMENT_CENTER};
  ArkUI_AttributeItem textAlignItem = {&intVal_0, VALUE_1};
  Manager::nodeAPI_->setAttribute(text14, NODE_TEXT_ALIGN, &textAlignItem);
  ```
- 设置文本垂直对齐。
  <!-- @[text_verticalAlign](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 垂直对齐：基线对齐（ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE）
  ArkUI_NumberValue vAlignVal = {.i32 = ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE};
  ArkUI_AttributeItem vAlignItem = {&vAlignVal, VALUE_1};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_VERTICAL_ALIGN, &vAlignItem);
  ```

### 设置文本装饰线和效果

通过如下属性设置文本装饰线、阴影等效果。

**表3** 文本装饰线和效果属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_DECORATION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_decoration) | 设置文本装饰线。 |
| [NODE_TEXT_TEXT_SHADOW](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_text_shadow) | 设置文字阴影效果。 |
- 设置文本装饰线。
  <!-- @[text_decoration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 设置文本装饰线类型：下划线装饰（ARKUI_TEXT_DECORATION_TYPE_UNDERLINE）。文本装饰线样式：单实线（ARKUI_TEXT_DECORATION_STYLE_SOLID）。
  ArkUI_NumberValue textDecoration[] = {
      {.i32 = ARKUI_TEXT_DECORATION_TYPE_UNDERLINE}, {.u32 = 0xFFFF0000}, {.i32 = ARKUI_TEXT_DECORATION_STYLE_SOLID}};
  ArkUI_AttributeItem textDecorationItem = {.value = textDecoration, .size = VALUE_3};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_DECORATION, &textDecorationItem);
  ```
- 设置文字阴影效果。
  <!-- @[text_shadow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 文字阴影效果属性
  ArkUI_NumberValue textShadow[] = {
      {.f32 = VALUE_5}, {.i32 = ARKUI_SHADOW_TYPE_BLUR}, {.u32 = 0xFF0000FF}, {.f32 = VALUE_5}, {.f32 = VALUE_5}};
  ArkUI_AttributeItem textShadowItem = {textShadow, VALUE_5};
  Manager::nodeAPI_->setAttribute(text4, NODE_TEXT_TEXT_SHADOW, &textShadowItem);
  ```

## 设置文本布局

Text组件支持多种文本布局设置，包括换行、行高、省略等。

### 设置文本换行

通过[NODE_TEXT_WORD_BREAK](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_word_break)属性设置文本的断行规则。

<!-- @[text_word_break](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) --> 

``` C++
// 设置断行规则：任意字符间断行
ArkUI_NumberValue wordBreakVal = {.i32 = ARKUI_WORD_BREAK_BREAK_ALL};
ArkUI_AttributeItem wordBreakItem = {&wordBreakVal, VALUE_1};
Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_WORD_BREAK, &wordBreakItem);
```

### 设置行高相关属性

通过如下属性设置文本的行高、行高倍数等属性。

从API version 22开始，Text组件支持使用倍数模式设置行高。

**表4** 行高属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_LINE_HEIGHT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_line_height) | 设置行高。 |
| [NODE_TEXT_LINE_HEIGHT_MULTIPLE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_line_height_multiple) | 设置行高倍数。从API version 22开始支持。 |
| [NODE_TEXT_HALF_LEADING](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_half_leading) | 设置文本垂直居中。 |
- 设置文本行高。
  <!-- @[text_line_height](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 设置文本行高
  ArkUI_NumberValue lineHeight = {.f32 = VALUE_50};
  ArkUI_AttributeItem lineHeightItem = {&lineHeight, VALUE_1};
  Manager::nodeAPI_->setAttribute(text4, NODE_TEXT_LINE_HEIGHT, &lineHeightItem);
  ```
- 设置行高倍数。
  <!-- @[text_line_height_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 设置行高倍数
  ArkUI_NumberValue value[] = {{.f32 = 2.0}};
  ArkUI_AttributeItem item = {value, sizeof(value)/ sizeof(ArkUI_NumberValue)};
  Manager::nodeAPI_->setAttribute(text9, NODE_TEXT_LINE_HEIGHT_MULTIPLE, &item);
  ```

### 设置文本省略

通过如下属性设置文本溢出时的省略模式。

**表5** 文本省略属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_MAX_LINES](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_max_lines) | 设置最大行数。 |
| [NODE_TEXT_OVERFLOW](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_overflow) | 设置文本溢出方式。 |
| [NODE_TEXT_ELLIPSIS_MODE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_ellipsis_mode) | 设置省略模式。 |

<!-- @[text_ellipsis_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// 设置最大行数
ArkUI_NumberValue maxLinesValue[] = {{.i32 = VALUE_3} };
ArkUI_AttributeItem maxLinesItem = {maxLinesValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_MAX_LINES, &maxLinesItem);

// 设置文本溢出：省略号
ArkUI_NumberValue textOverFlowValue[] = { {.i32 = ARKUI_TEXT_OVERFLOW_ELLIPSIS} };
ArkUI_AttributeItem textOverFlowItem = {textOverFlowValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_OVERFLOW, &textOverFlowItem);

// 设置省略模式：省略行首内容
ArkUI_NumberValue ellipsisModeValue1[] = { {.i32 = ARKUI_ELLIPSIS_MODE_MULTILINE_START} };
ArkUI_AttributeItem ellipsisModeItem1 = {ellipsisModeValue1, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_ELLIPSIS_MODE, &ellipsisModeItem1);
```

### 设置文本结尾空格优化

通过如下属性设置每行结尾空格是否优化。从API version 20开始，Text组件支持设置每行结尾空格是否优化处理。

**表6** 每行结尾空格处理属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_OPTIMIZE_TRAILING_SPACE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_optimize_trailing_space) | 设置每行结尾空格是否优化。从API version 20开始支持。 |

<!-- @[text_optimize_trailing_space](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
ArkUI_NumberValue optimizeValue = {.i32 = true};
ArkUI_AttributeItem optimizeTrailingSpaceItem = {&optimizeValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text14, NODE_TEXT_OPTIMIZE_TRAILING_SPACE, &optimizeTrailingSpaceItem);
```

### 设置首行缩进和标点压缩

通过如下属性设置首行缩进和行首标点压缩。从API version 23开始，Text组件支持设置行首标点压缩。

**表7** 首行缩进和标点压缩属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_INDENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_indent) | 设置首行缩进。 |
| [NODE_TEXT_COMPRESS_LEADING_PUNCTUATION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_compress_leading_punctuation) | 设置行首标点压缩。从API version 23开始支持。 |
- 设置首行缩进。
  <!-- @[text_indent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 设置首行缩进
  ArkUI_NumberValue indentVal = {.f32 = VALUE_30};
  ArkUI_AttributeItem indentItem = {&indentVal, VALUE_1};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_INDENT, &indentItem);
  ```
- 设置行首标点压缩。
  <!-- @[text_compress_leading_punctuation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->
  
  ``` C++
  // 设置行首标点压缩
  ArkUI_NumberValue value0[] = {{.i32 = true}};
  ArkUI_AttributeItem item0 = {value0, sizeof(value0)/ sizeof(ArkUI_NumberValue)};
  Manager::nodeAPI_->setAttribute(text11, NODE_TEXT_COMPRESS_LEADING_PUNCTUATION, &item0);
  ```

### 设置文本尾部缩进

通过如下属性设置文本尾部缩进。从API版本26.0.0开始，Text组件支持设置文本尾部缩进。

**表8** 文本尾部缩进属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_TAIL_INDENTS](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_tail_indents) | 设置文本尾部缩进。 |

<!-- @[text_tail_indents](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  ArkUI_NumberValue multiValues[] = { { .f32 = 0.0f }, { .f32 = 50.0f }, { .f32 = 100.0f } };
  ArkUI_AttributeItem tailIndentItem2 = { .value = multiValues, .size = 3 };
  Manager::nodeAPI_->setAttribute(text2, NODE_TEXT_TAIL_INDENTS, &tailIndentItem2);
  ```

## 添加子组件

Text组件支持添加多种子组件，实现图文混排等复杂效果。

### 添加Span

通过[addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild)在Text中添加文本子组件，用于展示行内文本。Span组件需嵌入在Text组件中才能显示，单独使用时不会显示任何内容。

<!-- @[text_add_span](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// span仅作为text的子组件形式展示
ArkUI_NodeHandle span = Manager::nodeAPI_->createNode(ARKUI_NODE_SPAN);
const char *spanContent = "This is a span";
ArkUI_AttributeItem spanContentItem = {.string = spanContent};
Manager::nodeAPI_->setAttribute(span, NODE_SPAN_CONTENT, &spanContentItem);
if (span != nullptr) {
    // 设置Span背景样式
    ArkUI_NumberValue spanBackground[] = {
        {.u32 = 0xFFE8F4F5}, // 背景颜色
        {.f32 = 5.0f},       // 左上角半径
        {.f32 = 5.0f},       // 右上角半径
        {.f32 = 5.0f},       // 左下角半径
        {.f32 = 5.0f}        // 右下角半径
    };
    ArkUI_AttributeItem spanBackgroundItem = {.value = spanBackground, .size = VALUE_5};
    Manager::nodeAPI_->setAttribute(span, NODE_SPAN_TEXT_BACKGROUND_STYLE, &spanBackgroundItem);

    // 文本基线的偏移量属性
    ArkUI_NumberValue baselineOffsetVal = {.f32 = VALUE_10};
    ArkUI_AttributeItem baselineOffsetItem = {&baselineOffsetVal, VALUE_1};
    Manager::nodeAPI_->setAttribute(span, NODE_SPAN_BASELINE_OFFSET, &baselineOffsetItem);
    // 设置字体粗细
    ArkUI_NumberValue fontWeight = {.i32 = ARKUI_FONT_WEIGHT_W500};
    ArkUI_AttributeItem fontWeightItem = {&fontWeight, VALUE_1};
    Manager::nodeAPI_->setAttribute(span, NODE_IMMUTABLE_FONT_WEIGHT, &fontWeightItem);
    ArkUI_NumberValue fontWeight1 = {.i32 = ARKUI_FONT_WEIGHT_W500};
    ArkUI_AttributeItem fontWeight1Item = {&fontWeight1, VALUE_1};
    Manager::nodeAPI_->setAttribute(text, NODE_IMMUTABLE_FONT_WEIGHT, &fontWeight1Item);
    // 长按span组件，触发回调
    Manager::nodeAPI_->registerNodeEvent(span, NODE_TEXT_SPAN_ON_LONG_PRESS, EVENT_SPAN_LONG_PRESS, nullptr);
    Manager::nodeAPI_->registerNodeEventReceiver(&OnEventReceive);
}
Manager::nodeAPI_->addChild(text, span);
```

### 添加ImageSpan

通过[addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild)在文本中添加图片子组件。

<!-- @[text_add_imagespan](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
void setText6(ArkUI_NodeHandle &text6)
{
    // ImageSpan
    ArkUI_NodeHandle imageSpan = Manager::nodeAPI_->createNode(ARKUI_NODE_IMAGE_SPAN);
    ArkUI_AttributeItem spanUrl = {.string = "/resources/base/media/background.png"};
    ArkUI_NumberValue widthVal[VALUE_1]{};
    widthVal[VALUE_0].f32 = 100.f;
    ArkUI_AttributeItem width = {.value = widthVal, .size = VALUE_1};
    ArkUI_NumberValue heightVal[VALUE_1]{};
    heightVal[VALUE_0].f32 = 100.f;
    ArkUI_AttributeItem height = {.value = heightVal, .size = VALUE_1};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_WIDTH, &width);
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_HEIGHT, &height);
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_SRC, &spanUrl);
    // 设置 NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT
    ArkUI_NumberValue verticalAlignment = {.i32 = ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM};
    ArkUI_AttributeItem verticalAlignmentItem = {&verticalAlignment, VALUE_1};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT, &verticalAlignmentItem);
    // imageSpan组件占位图地址属性
    ArkUI_AttributeItem spanAlt = {.string = "/resources/base/media/startIcon.png"};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_ALT, &spanAlt);
    // 设置imageSpan组件的基线偏移量属性
    ArkUI_NumberValue baselineOffset = {.f32 = VALUE_10};
    ArkUI_AttributeItem baselineOffsetItem = {&baselineOffset, VALUE_1};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_BASELINE_OFFSET, &baselineOffsetItem);
    Manager::nodeAPI_->addChild(text6, imageSpan);
}
```

## 设置高级文本效果

Text组件支持多种高级文本效果，如渐变、跑马灯等。

### 设置渐变效果

通过如下属性设置渐变颜色效果。从API version 20开始，Text组件支持设置渐变颜色效果。

**表9** 渐变效果属性

| 属性 | 说明 |
|------|------|
| [NODE_TEXT_LINEAR_GRADIENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_linear_gradient) | 设置线性渐变。从API version 20开始支持。 |
| [NODE_TEXT_RADIAL_GRADIENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_radial_gradient) | 设置径向渐变。从API version 20开始支持。 |

<!-- @[text_linear_gradient](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// 设置渐变颜色和位置
float stops[] = { 0.0f, 0.5f };
uint32_t colors[] = { 0xFFFFFF00, 0xFF0000FF };
ArkUI_ColorStop colorStop = { colors, stops, VALUE_2 };
ArkUI_ColorStop *colorStopPtr = &colorStop;

// 设置线性渐变
ArkUI_NumberValue linearGradient[] = {
    {.f32 = FLOAT_50}, {.f32 = FLOAT_50}, {.f32 = FLOAT_50}};
ArkUI_AttributeItem linearGradientItem = {
    linearGradient, sizeof(linearGradient) / sizeof(ArkUI_NumberValue)};
linearGradientItem.object = reinterpret_cast<void *>(colorStopPtr);
Manager::nodeAPI_->setAttribute(text5, NODE_TEXT_LINEAR_GRADIENT, &linearGradientItem);
```

### 设置跑马灯效果

从API version 23开始，Text组件支持通过[NODE_TEXT_MARQUEE_OPTIONS](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_marquee_options)属性设置跑马灯效果。

<!-- @[text_marquee_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// 创建跑马灯选项
ArkUI_TextMarqueeOptions* marqueeOptions = OH_ArkUI_TextMarqueeOptions_Create();
OH_ArkUI_TextMarqueeOptions_SetStart(marqueeOptions, true);
OH_ArkUI_TextMarqueeOptions_SetStep(marqueeOptions, 5.0f);
OH_ArkUI_TextMarqueeOptions_SetSpacing(marqueeOptions, 30.0f);
OH_ArkUI_TextMarqueeOptions_SetFromStart(marqueeOptions, true);
OH_ArkUI_TextMarqueeOptions_SetDelay(marqueeOptions, VALUE_400);
OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy(marqueeOptions,
    ArkUI_MarqueeUpdatePolicy::ARKUI_MARQUEEUPDATEPOLICY_PRESERVEPOSITION);
// 设置到Text组件
ArkUI_AttributeItem marqueeOptions_item = {
    .object = marqueeOptions
};
Manager::nodeAPI_->setAttribute(text18, NODE_TEXT_MARQUEE_OPTIONS, &marqueeOptions_item);
OH_ArkUI_TextMarqueeOptions_Dispose(marqueeOptions);
```

### 设置文本方向

从API version 23开始，Text组件支持通过[NODE_TEXT_DIRECTION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_direction)属性设置文本方向。

<!-- @[text_direction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// 设置文本方向为从右到左
ArkUI_NumberValue directionValue[] = {{.i32 = ARKUI_TEXT_DIRECTION_RTL}};
ArkUI_AttributeItem direction_item = {directionValue, sizeof(directionValue) / sizeof(ArkUI_NumberValue)};
Manager::nodeAPI_->setAttribute(text19, NODE_TEXT_DIRECTION, &direction_item);
```