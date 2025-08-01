# Text组件的文本绘制与显示
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hddgzw-->
<!--SE: @pssea-->
<!--TSE: @jiaoaozihao-->
部分框架或应用具备自研的文字排版能力，在移植时，这些能力会被对接到[方舟2D图形服务的文本引擎](../graphics/complex-text-c.md)。为了避免开发者重复开发文本组件，Text组件提供了接口[NODE_TEXT_CONTENT_WITH_STYLED_STRING](../../application-dev/reference/apis-arkui/capi-native-node-h.md#arkui_nodeattributetype)，可以直接渲染方舟文本引擎生成的文本。

以下场景基于[接入ArkTS页面章节](../ui/ndk-access-the-arkts-page.md)，阐述了如何创建字体引擎文本，并利用Text组件进行渲染显示。

> **说明：**
>
> 涉及字体引擎的接口，需在CMakeLists.txt中添加`target_link_libraries(entry PUBLIC libnative_drawing.so)`，否则链接阶段会报错。

## 创建Text组件

由于文本样式通过字体引擎接口设置，创建文本组件时无需配置文字颜色、字体大小等样式属性。但仍需设置基础的通用属性，例如宽度、高度。
```c++
ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
    OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
if (nodeApi == nullptr) {
    return;
}
ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
// 设置宽度
ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
// 设置高度
ArkUI_NumberValue textHeight[] = {{.f32 = 100}};
ArkUI_AttributeItem textHeightItem = {.value = textHeight, .size = 1};
nodeApi->setAttribute(text, NODE_HEIGHT, &textHeightItem);
```
## 设置段落与文本样式

- 设置段落样式

    段落样式定义了一段文字的整体属性，例如最大显示行数、文字方向等。以下代码示例设置了文字居中，最大行数限制为10。
    
    > **说明：**
    > 
    > `OH_Drawing_`前缀的接口由方舟字体引擎提供，参考[简单文本绘制与显示（C/C++)](../graphics/simple-text-c.md)、[复杂文本绘制与显示（C/C++）](../graphics/complex-text-c.md)。
    ```c++
    OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
    OH_Drawing_SetTypographyTextAlign(typographyStyle, OH_Drawing_TextAlign::TEXT_ALIGN_CENTER);
    OH_Drawing_SetTypographyTextMaxLines(typographyStyle, 10);
    ```
- 设置文本样式

    不同内容的文本可以设置不同的文本样式，但必须按照以下三个接口的调用顺序进行设置，否则将无法生效。

    1. `OH_ArkUI_StyledString_PushTextStyle`：将文字样式推入栈中。
    2. `OH_ArkUI_StyledString_AddText`：添加要修改样式的文字内容。
    3. `OH_ArkUI_StyledString_PopTextStyle`：将文字样式弹出栈。

    > **说明：**
    > 
    > `OH_ArkUI_StyledString_`前缀的接口由Text组件提供。
    >
    > `OH_Drawing_`前缀的接口由方舟字体引擎提供，参考[简单文本绘制与显示（C/C++)](../graphics/simple-text-c.md)、[复杂文本绘制与显示（C/C++）](../graphics/complex-text-c.md)。

    `OH_Drawing_CreateTextStyle`创建文本样式。设置“Hello”字体大小28px，颜色为0xFF707070。设置“World!”字体大小为28px，颜色为0xFF2787D9。
    ```c++
    ArkUI_StyledString *styledString = OH_ArkUI_StyledString_Create(typographyStyle,OH_Drawing_CreateFontCollection());

    OH_Drawing_TextStyle *helloStyle = OH_Drawing_CreateTextStyle();
    // 设置字体大小
    OH_Drawing_SetTextStyleFontSize(helloStyle, 28);
    // 设置颜色
    OH_Drawing_SetTextStyleColor(helloStyle, OH_Drawing_ColorSetArgb(0xFF, 0x70, 0x70, 0x70));
    OH_ArkUI_StyledString_PushTextStyle(styledString, helloStyle);
    OH_ArkUI_StyledString_AddText(styledString, "Hello");
    OH_ArkUI_StyledString_PopTextStyle(styledString);

    OH_Drawing_TextStyle *worldTextStyle = OH_Drawing_CreateTextStyle();
    OH_Drawing_SetTextStyleFontSize(worldTextStyle, 28);
    OH_Drawing_SetTextStyleColor(worldTextStyle, OH_Drawing_ColorSetArgb(0xFF, 0x27,0x87, 0xD9));
    OH_ArkUI_StyledString_PushTextStyle(styledString, worldTextStyle);
    OH_ArkUI_StyledString_AddText(styledString, "World!");
    OH_ArkUI_StyledString_PopTextStyle(styledString);
    ```
## 添加占位
占位在文字中间保留指定大小的空白区域，此区域内不绘制文字，但仍然参与文字的布局测量。因此，其大小会影响文字的排版。
> **说明：**
> 
> 占位与文本的相对位置由 `OH_ArkUI_StyledString_AddPlaceholder` 执行顺序决定。

```c++
OH_Drawing_PlaceholderSpan placeHolder{
    .width = 100,
    .height = 100,
};
OH_ArkUI_StyledString_AddPlaceholder(styledString, placeHolder);
```
## 文本布局与绘制
- 文本布局

    文字的样式和内容设置完成后，需调用字体引擎接口`OH_Drawing_TypographyLayout`对文本进行布局，传入指定的宽度，该宽度表示文字的最大值。
    
    > **说明：** 
    >
    > 未经过布局的文本无法显示。

    ```c++
    OH_Drawing_Typography *typography = OH_ArkUI_StyledString_CreateTypography(styledString);
    OH_Drawing_TypographyLayout(typography, 400);
    ```

- 文本绘制

    文本绘制由字体引擎与图形交互完成，无需额外设置。Text组件会在ArkUI渲染机制下，在组件触发绘制时调用字体引擎绘制接口。此处仅需将已创建的StyledString对象传递给已创建的Text组件。
    ```c++
    ArkUI_AttributeItem styledStringItem = {.object = styledString};
    nodeApi->setAttribute(text, NODE_TEXT_CONTENT_WITH_STYLED_STRING, &styledStringItem);
    ```

## 销毁对象

Text组件不对本文涉及的任何对象的生命周期进行管理，需由开发者自行负责。字体引擎接口均配有相应的销毁方法。

上述涉及的字体引擎接口都有对应的销毁方法。

`OH_Drawing_DestroyTextStyle(OH_Drawing_TextStyle *style)`：销毁文本样式对象。

`OH_Drawing_DestroyTypographyStyle(OH_Drawing_TypographyStyle *style)`：销毁段落样式对象。

更多字体引擎销毁API参考[简单文本绘制与显示（C/C++)](../graphics/simple-text-c.md)、[复杂文本绘制与显示（C/C++）](../graphics/complex-text-c.md)。

Text组件提供`OH_ArkUI_StyledString_Destroy`：销毁属性字符串对象。

## 完整示例
```c++
void CreateNativeNode() {
    ArkUI_NativeNodeAPI_1 *nodeApi = reinterpret_cast<ArkUI_NativeNodeAPI_1 *>(
        OH_ArkUI_QueryModuleInterfaceByName(ARKUI_NATIVE_NODE, "ArkUI_NativeNodeAPI_1"));
    if (nodeApi == nullptr) {
        return;
    }
    // 创建一个Column容器组件
    ArkUI_NodeHandle column = nodeApi->createNode(ARKUI_NODE_COLUMN);
    ArkUI_NumberValue colWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem widthItem = {.value = colWidth, .size = 1};
    nodeApi->setAttribute(column, NODE_WIDTH, &widthItem);
    // 创建Text组件
    ArkUI_NodeHandle text = nodeApi->createNode(ARKUI_NODE_TEXT);
    ArkUI_NumberValue textWidth[] = {{.f32 = 300}};
    ArkUI_AttributeItem textWidthItem = {.value = textWidth, .size = 1};
    nodeApi->setAttribute(text, NODE_WIDTH, &textWidthItem);
    
    ArkUI_NumberValue textHeight[] = {{.f32 = 100}};
    ArkUI_AttributeItem textHeightItem = {.value = textHeight, .size = 1};
    nodeApi->setAttribute(text, NODE_HEIGHT, &textHeightItem);
    
    ArkUI_NumberValue borderWidth[] = {{.f32 = 1}};
    ArkUI_AttributeItem borderWidthItem = {.value = borderWidth, .size = 1};
    nodeApi->setAttribute(text, NODE_BORDER_WIDTH, &borderWidthItem);
    
    // typographyStyle表示段落样式。
    OH_Drawing_TypographyStyle *typographyStyle = OH_Drawing_CreateTypographyStyle();
    // 文字居中显示
    OH_Drawing_SetTypographyTextAlign(typographyStyle, OH_Drawing_TextAlign::TEXT_ALIGN_CENTER);
    OH_Drawing_SetTypographyTextMaxLines(typographyStyle, 10);
    ArkUI_StyledString *styledString = OH_ArkUI_StyledString_Create(typographyStyle, OH_Drawing_CreateFontCollection());
    // 创建文本样式，设置字体和颜色。
    OH_Drawing_TextStyle *textStyle = OH_Drawing_CreateTextStyle();
    OH_Drawing_SetTextStyleFontSize(textStyle, 28);
    OH_Drawing_SetTextStyleColor(textStyle, OH_Drawing_ColorSetArgb(0xFF, 0x70, 0x70, 0x70));
    // 文本样式的设置有顺序。
    OH_ArkUI_StyledString_PushTextStyle(styledString, textStyle);
    OH_ArkUI_StyledString_AddText(styledString, "Hello");
    OH_ArkUI_StyledString_PopTextStyle(styledString);
    // 在Hello和World中间插入100x100的占位。
    OH_Drawing_PlaceholderSpan placeHolder{
        .width = 100,
        .height = 100,
    };
    OH_ArkUI_StyledString_AddPlaceholder(styledString, &placeHolder);
    OH_Drawing_TextStyle *worldTextStyle = OH_Drawing_CreateTextStyle();
    OH_Drawing_SetTextStyleFontSize(worldTextStyle, 28);
    OH_Drawing_SetTextStyleColor(worldTextStyle, OH_Drawing_ColorSetArgb(0xFF, 0x27, 0x87, 0xD9));
    OH_ArkUI_StyledString_PushTextStyle(styledString, worldTextStyle);
    OH_ArkUI_StyledString_AddText(styledString, "World!");
    OH_ArkUI_StyledString_PopTextStyle(styledString);
    OH_Drawing_Typography *typography = OH_ArkUI_StyledString_CreateTypography(styledString);
    OH_Drawing_TypographyLayout(typography, 400);
    ArkUI_AttributeItem styledStringItem = {.object = styledString};
    nodeApi->setAttribute(text, NODE_TEXT_CONTENT_WITH_STYLED_STRING, &styledStringItem);

    OH_ArkUI_StyledString_Destroy(styledString);
    // Text作为Column子组件
    nodeApi->addChild(column, text);
    // Column作为XComponent子组件
    OH_NativeXComponent_AttachNativeRootNode(xComponent, column);
}
```

![ndk_text_styled_string](figures/ndk_text_styled_string.png)