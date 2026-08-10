# Using the Text Component

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=58aa1a9b8318e579a2b513b7ba023ee57b8ecdda translatedAt=2026-08-05T10:11:35.712Z pushedAt=2026-08-06T06:16:48.712Z -->

The [ArkUI](arkui-overview.md) development framework provides the **Text** component in the [NDK](../napi/ndk-development-overview.md) APIs to display the text content. The **Text** component supports various style settings, including the font, color, alignment mode, and text effect. It also supports multiple child components, such as [Span](#adding-span), [ImageSpan](#adding-imagespan), and [StyledString](./ndk-styled-string.md), to implement complex text display effects.

> **NOTE**
>
> - This section demonstrates core API usage only. For the complete sample project, see <!--RP1-->[native_node_sample](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/ArkUISample/native_node_sample/)<!--RP1End-->.
>
> - Before development, you need to integrate with the ArkTS pages. For details, see [Integrating with ArkTS Pages](./ndk-access-the-arkts-page.md).

## Creating the Text Component

The **Text** component is a basic component for displaying text content. It supports multiple style settings and child components.

### Creating Basic Text

The [createNode](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#createnode) API creates the **Text** component. The node type is **ARKUI_NODE_TEXT**.

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

### Setting the Text Content

- Set the basic text content of the **Text** component through the [NODE_TEXT_CONTENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_content) attribute.

  <!-- @[text_content](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  const char *textContent = "this is text 2 this is text 2 this is text 2!!!! ";
  ArkUI_AttributeItem contentItem = {.string = textContent};
  Manager::nodeAPI_->setAttribute(text2, NODE_TEXT_CONTENT, &contentItem);
  ```

- Set the text content through the [NODE_TEXT_CONTENT_WITH_STYLED_STRING](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_content_with_styled_string) attribute.

  **StyledString** provides more advanced text layout capabilities, allowing you to set different styles for different parts of the text, including font size, color, and placeholders. For details about how to use **StyledString**, see [Using Styled Strings](./ndk-styled-string.md).

## Setting the Text Style

The **Text** component supports various style settings, including the font, color, and alignment mode.

### Setting Font Attributes

Set basic attributes such as font size, weight, and style through the following attributes.

**Table 1** Font attributes

| Attribute| Description|
|------|------|
| [NODE_FONT_SIZE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_size) | Sets the font size. |
| [NODE_FONT_WEIGHT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_weight) | Sets the font weight. |
| [NODE_FONT_STYLE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_style) | Sets the font style. |
| [NODE_FONT_FAMILY](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_font_family) | Sets the font families. |

<!-- @[text_font_properties](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) --> 

``` C++
// Set the font size to 28 and text color to 0xFFFF0000 (red).
ArkUI_NumberValue fontSize[] = {{.f32 = VALUE_28}};
ArkUI_AttributeItem fontSizeItem = {.value = fontSize, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_SIZE, &fontSizeItem);
ArkUI_NumberValue fontColor = {.u32 = 0xFFFF0000};
ArkUI_AttributeItem fontColorItem = {.value = &fontColor, .size = VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_COLOR, &fontColorItem);

// Set the font style to italic (ARKUI_FONT_STYLE_ITALIC).
ArkUI_NumberValue fontStyleVal = {.i32 = ARKUI_FONT_STYLE_ITALIC};
ArkUI_AttributeItem fontStyleItem = {&fontStyleVal, VALUE_1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_STYLE, &fontStyleItem);

// Set the font weight to bold (ARKUI_FONT_WEIGHT_W800).
ArkUI_NumberValue fontWeightVal = {.i32 = ARKUI_FONT_WEIGHT_W800};
ArkUI_AttributeItem textWeightItem = {.value = &fontWeightVal, .size = 1};
Manager::nodeAPI_->setAttribute(text2, NODE_FONT_WEIGHT, &textWeightItem);
```

### Setting Text Alignment

Set the horizontal and vertical alignment of the text through the following attributes.

**Table 2** Text alignment attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_ALIGN](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_align) | Sets the horizontal text alignment. |
| [NODE_TEXT_VERTICAL_ALIGN](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_vertical_align) | Sets the vertical text alignment. |

- Set horizontal alignment of the text.

  <!-- @[text_align](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set horizontal alignment to center alignment (ARKUI_TEXT_ALIGNMENT_CENTER).
  ArkUI_NumberValue intVal_0 = {.i32 = ARKUI_TEXT_ALIGNMENT_CENTER};
  ArkUI_AttributeItem textAlignItem = {&intVal_0, VALUE_1};
  Manager::nodeAPI_->setAttribute(text14, NODE_TEXT_ALIGN, &textAlignItem);
  ```

- Set vertical alignment of the text.

  <!-- @[text_verticalAlign](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set vertical alignment to baseline-based alignment (ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE).
  ArkUI_NumberValue vAlignVal = {.i32 = ARKUI_TEXT_VERTICAL_ALIGNMENT_BASELINE};
  ArkUI_AttributeItem vAlignItem = {&vAlignVal, VALUE_1};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_VERTICAL_ALIGN, &vAlignItem);
  ```

### Setting the Text Decoration and Effect

Set effects such as text decoration lines and shadows through the following attributes.

**Table 3** Text decoration and effect attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_DECORATION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_decoration) | Sets the text decoration line. |
| [NODE_TEXT_TEXT_SHADOW](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_text_shadow) | Sets the text shadow effect. |

- Set the text decoration.

  <!-- @[text_decoration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set the text decoration type to underline (ARKUI_TEXT_DECORATION_TYPE_UNDERLINE) and the text decoration style to single solid line (ARKUI_TEXT_DECORATION_STYLE_SOLID).
  ArkUI_NumberValue textDecoration[] = {
      {.i32 = ARKUI_TEXT_DECORATION_TYPE_UNDERLINE}, {.u32 = 0xFFFF0000}, {.i32 = ARKUI_TEXT_DECORATION_STYLE_SOLID}};
  ArkUI_AttributeItem textDecorationItem = {.value = textDecoration, .size = VALUE_3};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_DECORATION, &textDecorationItem);
  ```

- Set the text shadow.

  <!-- @[text_shadow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set the text shadow attribute.
  ArkUI_NumberValue textShadow[] = {
      {.f32 = VALUE_5}, {.i32 = ARKUI_SHADOW_TYPE_BLUR}, {.u32 = 0xFF0000FF}, {.f32 = VALUE_5}, {.f32 = VALUE_5}};
  ArkUI_AttributeItem textShadowItem = {textShadow, VALUE_5};
  Manager::nodeAPI_->setAttribute(text4, NODE_TEXT_TEXT_SHADOW, &textShadowItem);
  ```

## Setting the Text Layout

The Text component supports various text layout settings, including line wrapping, line height, and ellipsis.

### Setting Text Line Wrapping

Set the line break rule of the text through the [NODE_TEXT_WORD_BREAK](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_word_break) attribute.

<!-- @[text_word_break](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) --> 

``` C++
// Set the line break rule to allowing word breaks between any two characters.
ArkUI_NumberValue wordBreakVal = {.i32 = ARKUI_WORD_BREAK_BREAK_ALL};
ArkUI_AttributeItem wordBreakItem = {&wordBreakVal, VALUE_1};
Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_WORD_BREAK, &wordBreakItem);
```

### Setting Line Height Attributes

Set attributes such as line height and line height multiplier through the following attributes.

Since API version 22, the **Text** component supports setting the line height using a multiplier.

**Table 4** Line height attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_LINE_HEIGHT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_line_height) | Sets the line height. |
| [NODE_TEXT_LINE_HEIGHT_MULTIPLE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_line_height_multiple) | Sets the line height multiple. Supported since API version 22. |
| [NODE_TEXT_HALF_LEADING](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_half_leading) | Sets the text to be vertically centered. |

- Set the line height.

  <!-- @[text_line_height](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set the text line height.
  ArkUI_NumberValue lineHeight = {.f32 = VALUE_50};
  ArkUI_AttributeItem lineHeightItem = {&lineHeight, VALUE_1};
  Manager::nodeAPI_->setAttribute(text4, NODE_TEXT_LINE_HEIGHT, &lineHeightItem);
  ```

- Line height multiplier.

  <!-- @[text_line_height_multiple](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set the line height multiplier.
  ArkUI_NumberValue value[] = {{.f32 = 2.0}};
  ArkUI_AttributeItem item = {value, sizeof(value)/ sizeof(ArkUI_NumberValue)};
  Manager::nodeAPI_->setAttribute(text9, NODE_TEXT_LINE_HEIGHT_MULTIPLE, &item);
  ```

### Setting Text Ellipsis

Set the ellipsis mode for text overflow through the following attributes.

**Table 5** Text ellipsis attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_MAX_LINES](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_max_lines) | Sets the maximum number of lines. |
| [NODE_TEXT_OVERFLOW](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_overflow) | Sets the text overflow mode. |
| [NODE_TEXT_ELLIPSIS_MODE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_ellipsis_mode) | Sets the ellipsis mode. |

<!-- @[text_ellipsis_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// Set the maximum number of lines.
ArkUI_NumberValue maxLinesValue[] = {{.i32 = VALUE_3} };
ArkUI_AttributeItem maxLinesItem = {maxLinesValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_MAX_LINES, &maxLinesItem);

// Set the text overflow handling method to ellipsis.
ArkUI_NumberValue textOverFlowValue[] = { {.i32 = ARKUI_TEXT_OVERFLOW_ELLIPSIS} };
ArkUI_AttributeItem textOverFlowItem = {textOverFlowValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_OVERFLOW, &textOverFlowItem);

// Set the ellipsis style to an ellipsis at the start of the line of text.
ArkUI_NumberValue ellipsisModeValue1[] = { {.i32 = ARKUI_ELLIPSIS_MODE_MULTILINE_START} };
ArkUI_AttributeItem ellipsisModeItem1 = {ellipsisModeValue1, VALUE_1};
Manager::nodeAPI_->setAttribute(text20, NODE_TEXT_ELLIPSIS_MODE, &ellipsisModeItem1);
```

### Setting Trailing Space Optimization at the End of Each Line

Set whether to optimize trailing spaces at the end of each line through the following attributes. Since API version 20, the **Text** component supports setting whether to optimize trailing spaces at the end of each line.

**Table 6** Trailing space handling attributes for each line

| Attribute| Description|
|------|------|
| [NODE_TEXT_OPTIMIZE_TRAILING_SPACE](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_optimize_trailing_space) | Whether to optimize trailing spaces at the end of each line. Supported since API version 20. |

<!-- @[text_optimize_trailing_space](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
ArkUI_NumberValue optimizeValue = {.i32 = true};
ArkUI_AttributeItem optimizeTrailingSpaceItem = {&optimizeValue, VALUE_1};
Manager::nodeAPI_->setAttribute(text14, NODE_TEXT_OPTIMIZE_TRAILING_SPACE, &optimizeTrailingSpaceItem);
```

### Setting the First Line Indent and Punctuation Compression

Set the first line indent and line start punctuation compression through the following attributes. Since API version 23, the **Text** component supports setting line start punctuation compression.

**Table 7** First line indent and punctuation compression attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_INDENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_indent) | Sets the first-line indent. |
| [NODE_TEXT_COMPRESS_LEADING_PUNCTUATION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_compress_leading_punctuation) | Sets the line-start punctuation compression. Supported since API version 23. |

- Set the first line indent.

  <!-- @[text_indent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set the first line indent.
  ArkUI_NumberValue indentVal = {.f32 = VALUE_30};
  ArkUI_AttributeItem indentItem = {&indentVal, VALUE_1};
  Manager::nodeAPI_->setAttribute(text3, NODE_TEXT_INDENT, &indentItem);
  ```

- Set the leading punctuation compression.

  <!-- @[text_compress_leading_punctuation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  // Set leading punctuation compression.
  ArkUI_NumberValue value0[] = {{.i32 = true}};
  ArkUI_AttributeItem item0 = {value0, sizeof(value0)/ sizeof(ArkUI_NumberValue)};
  Manager::nodeAPI_->setAttribute(text11, NODE_TEXT_COMPRESS_LEADING_PUNCTUATION, &item0);
  ```

### Setting the Trailing Indent

Set the trailing indent of the text through the following attributes. Since API version 26.0.0, the **Text** component supports setting the trailing indent of the text.

**Table 8** Trailing indent attributes

| Name | Description |
|------|------|
| [NODE_TEXT_TAIL_INDENTS](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_tail_indents) | Sets the trailing indent of the text. |

<!-- @[text_tail_indents](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

  ``` C++
  ArkUI_NumberValue multiValues[] = { { .f32 = 0.0f }, { .f32 = 50.0f }, { .f32 = 100.0f } };
  ArkUI_AttributeItem tailIndentItem2 = { .value = multiValues, .size = 3 };
  Manager::nodeAPI_->setAttribute(text2, NODE_TEXT_TAIL_INDENTS, &tailIndentItem2);
  ```

## Adding Child Components

The **Text** component supports multiple child components to implement complex effects such as the mixed text and image layout.

### Adding Span

The [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) API adds a text child component to **Text** to display inline text. A **Span** component is only visible when embedded within a **Text** component. Using a **Span** independently displays no content.

<!-- @[text_add_span](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// Display Span only as a child component of Text.
ArkUI_NodeHandle span = Manager::nodeAPI_->createNode(ARKUI_NODE_SPAN);
const char *spanContent = "This is a span";
ArkUI_AttributeItem spanContentItem = {.string = spanContent};
Manager::nodeAPI_->setAttribute(span, NODE_SPAN_CONTENT, &spanContentItem);
if (span != nullptr) {
    // Set the background style of Span.
    ArkUI_NumberValue spanBackground[] = {
        {.u32 = 0xFFE8F4F5}, // Set the background color.
        {.f32 = 5.0f},       // Set the radius of the upper left corner.
        {.f32 = 5.0f},       // Set the radius of the upper right corner.
        {.f32 = 5.0f},       // Set the radius of the lower left corner.
        {.f32 = 5.0f}        // Set the radius of the lower right corner.
    };
    ArkUI_AttributeItem spanBackgroundItem = {.value = spanBackground, .size = VALUE_5};
    Manager::nodeAPI_->setAttribute(span, NODE_SPAN_TEXT_BACKGROUND_STYLE, &spanBackgroundItem);

    // Set the text baseline offset attribute.
    ArkUI_NumberValue baselineOffsetVal = {.f32 = VALUE_10};
    ArkUI_AttributeItem baselineOffsetItem = {&baselineOffsetVal, VALUE_1};
    Manager::nodeAPI_->setAttribute(span, NODE_SPAN_BASELINE_OFFSET, &baselineOffsetItem);
    // Set the font weight.
    ArkUI_NumberValue fontWeight = {.i32 = ARKUI_FONT_WEIGHT_W500};
    ArkUI_AttributeItem fontWeightItem = {&fontWeight, VALUE_1};
    Manager::nodeAPI_->setAttribute(span, NODE_IMMUTABLE_FONT_WEIGHT, &fontWeightItem);
    ArkUI_NumberValue fontWeight1 = {.i32 = ARKUI_FONT_WEIGHT_W500};
    ArkUI_AttributeItem fontWeight1Item = {&fontWeight1, VALUE_1};
    Manager::nodeAPI_->setAttribute(text, NODE_IMMUTABLE_FONT_WEIGHT, &fontWeight1Item);
    // Long press on the Span component to trigger the callback.
    Manager::nodeAPI_->registerNodeEvent(span, NODE_TEXT_SPAN_ON_LONG_PRESS, EVENT_SPAN_LONG_PRESS, nullptr);
    Manager::nodeAPI_->registerNodeEventReceiver(&OnEventReceive);
}
Manager::nodeAPI_->addChild(text, span);
```

### Adding ImageSpan

The [addChild](../reference/apis-arkui/capi-arkui-nativemodule-arkui-nativenodeapi-1.md#addchild) API adds an image child component to **Text**.

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
    // Set NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT.
    ArkUI_NumberValue verticalAlignment = {.i32 = ARKUI_IMAGE_SPAN_ALIGNMENT_BOTTOM};
    ArkUI_AttributeItem verticalAlignmentItem = {&verticalAlignment, VALUE_1};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_VERTICAL_ALIGNMENT, &verticalAlignmentItem);
    // Set the placeholder image attribute of the ImageSpan component.
    ArkUI_AttributeItem spanAlt = {.string = "/resources/base/media/startIcon.png"};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_ALT, &spanAlt);
    // Set the baseline offset attribute of the ImageSpan component.
    ArkUI_NumberValue baselineOffset = {.f32 = VALUE_10};
    ArkUI_AttributeItem baselineOffsetItem = {&baselineOffset, VALUE_1};
    Manager::nodeAPI_->setAttribute(imageSpan, NODE_IMAGE_SPAN_BASELINE_OFFSET, &baselineOffsetItem);
    Manager::nodeAPI_->addChild(text6, imageSpan);
}
```

## Setting Advanced Text Effects

The **Text** component supports various advanced text effects, such as gradient and marquee.

### Setting the Gradient Effect

Set the gradient color effect through the following attributes. Since API version 20, the **Text** component supports setting the gradient color effect.

**Table 9** Gradient effect attributes

| Attribute| Description|
|------|------|
| [NODE_TEXT_LINEAR_GRADIENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_linear_gradient) | Sets linear gradient. Supported since API version 20. |
| [NODE_TEXT_RADIAL_GRADIENT](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_radial_gradient) | Sets radial gradient. Supported since API version 20. |

<!-- @[text_linear_gradient](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// Set the color and position of a gradient stop.
float stops[] = { 0.0f, 0.5f };
uint32_t colors[] = { 0xFFFFFF00, 0xFF0000FF };
ArkUI_ColorStop colorStop = { colors, stops, VALUE_2 };
ArkUI_ColorStop *colorStopPtr = &colorStop;

// Set the linear gradient.
ArkUI_NumberValue linearGradient[] = {
    {.f32 = FLOAT_50}, {.f32 = FLOAT_50}, {.f32 = FLOAT_50}};
ArkUI_AttributeItem linearGradientItem = {
    linearGradient, sizeof(linearGradient) / sizeof(ArkUI_NumberValue)};
linearGradientItem.object = reinterpret_cast<void *>(colorStopPtr);
Manager::nodeAPI_->setAttribute(text5, NODE_TEXT_LINEAR_GRADIENT, &linearGradientItem);
```

### Setting the Marquee Effect

Since API version 23, the **Text** component supports setting the marquee effect through the [NODE_TEXT_MARQUEE_OPTIONS](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_marquee_options) attribute.

<!-- @[text_marquee_options](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// Create a marquee option.
ArkUI_TextMarqueeOptions* marqueeOptions = OH_ArkUI_TextMarqueeOptions_Create();
OH_ArkUI_TextMarqueeOptions_SetStart(marqueeOptions, true);
OH_ArkUI_TextMarqueeOptions_SetStep(marqueeOptions, 5.0f);
OH_ArkUI_TextMarqueeOptions_SetSpacing(marqueeOptions, 30.0f);
OH_ArkUI_TextMarqueeOptions_SetFromStart(marqueeOptions, true);
OH_ArkUI_TextMarqueeOptions_SetDelay(marqueeOptions, VALUE_400);
OH_ArkUI_TextMarqueeOptions_SetUpdatePolicy(marqueeOptions,
    ArkUI_MarqueeUpdatePolicy::ARKUI_MARQUEEUPDATEPOLICY_PRESERVEPOSITION);
// Apply the effect to the Text component.
ArkUI_AttributeItem marqueeOptions_item = {
    .object = marqueeOptions
};
Manager::nodeAPI_->setAttribute(text18, NODE_TEXT_MARQUEE_OPTIONS, &marqueeOptions_item);
OH_ArkUI_TextMarqueeOptions_Dispose(marqueeOptions);
```

### Setting the Text Direction

Since API version 23, the **Text** component supports setting the text direction through the [NODE_TEXT_DIRECTION](../reference/apis-arkui/capi-native-node-h-nodeattributetype-text.md#node_text_direction) attribute.

<!-- @[text_direction](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/native_node_sample/entry/src/main/cpp/TextMaker.cpp) -->

``` C++
// Set the text direction to right-to-left.
ArkUI_NumberValue directionValue[] = {{.i32 = ARKUI_TEXT_DIRECTION_RTL}};
ArkUI_AttributeItem direction_item = {directionValue, sizeof(directionValue) / sizeof(ArkUI_NumberValue)};
Manager::nodeAPI_->setAttribute(text19, NODE_TEXT_DIRECTION, &direction_item);
```