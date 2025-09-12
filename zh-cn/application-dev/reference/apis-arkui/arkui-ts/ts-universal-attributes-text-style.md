# 输入框类组件通用接口 
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @kangshihui-->
<!--Designer: @pssea-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @HelloCrease-->

为[TextInput](ts-basic-components-textinput.md)、[TextArea](ts-basic-components-textarea.md)组件提供获取文本和光标信息、插入和删除文本、设置计数器以及文本装饰线的能力。
为[Search](ts-basic-components-search.md)组件提供获取文本和光标信息、插入和删除文本以及设置文本装饰线的能力。

>  **说明：**
>
>  从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## TextContentControllerBase

TextInput、TextArea、Search的基础控制器。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### getTextContentRect

getTextContentRect(): RectResult

获取已编辑文本内容区域相对于组件的位置和大小，返回值的单位为像素。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型       | 说明       |
| -------------------  | -------- |
| [RectResult](ts-universal-attributes-on-child-touch-test.md#rectresult) | 获取已编辑文本内容区域相对组件的位置和大小。 |

> **说明：**
>
> - 初始不输入文本时，返回值中有相对组件的位置信息，大小为0。
> - 返回值中的位置信息是第一个字符相对于可编辑组件的位置。
> - 在Search组件中，返回的位置信息是相对Search组件中搜索图标的偏移值。
> - 有输入时，返回信息中的宽度是组件编辑区域的固定宽度。

### getTextContentLineCount

getTextContentLineCount(): number

获取已编辑文本内容的行数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型  | 说明       |
| ----- | -------- |
| number| 已编辑文本内容行数。 |

### getCaretOffset<sup>11+</sup>

getCaretOffset(): CaretOffset

返回当前光标所在位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| [CaretOffset](#caretoffset11对象说明) | 光标相对输入框的位置。 |

> **说明：**
>
> - 在当前帧更新光标位置同时调用该接口，该接口不生效。
> - 在Search组件中，返回的位置信息是相对Search组件中搜索图标的偏移值。
> - 在Search组件中，不输入文本时，返回值中有相对Search组件的位置信息。
> - 返回值中的位置信息是光标相对于可编辑组件的位置。

### addText<sup>15+</sup>

addText(text: string, textOperationOptions?: TextContentControllerOptions): number

在已编辑文本的指定位置插入文本，默认插入至文本末尾。
拖拽文本的状态下不生效。

`addText`仅影响应用内部的UI表现，不影响输入法应用的内部逻辑，不推荐在预上屏状态下调用。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| text | string | 是    | 插入的文本内容。 |
| textOperationOptions   | [TextContentControllerOptions](#textcontentcontrolleroptions15) | 否    | 插入文本的配置选项，不设置时默认插入文本至末尾。 |

**返回值：**

| 类型  | 说明       |
| ----- | -------- |
| number| 插入文本后光标的位置。 |

### deleteText<sup>15+</sup>

deleteText(range?: TextRange): void

删除已编辑文本的指定区域的内容。
拖拽文本的状态下不生效。

`deleteText`仅影响应用内部的UI表现，不影响输入法应用的内部逻辑，不推荐在预上屏状态下调用。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| range | [TextRange](ts-text-common.md#textrange12) | 否    | 删除文本的范围，包括删除文本的起始位置和终止位置。<br>未指定删除范围时，默认将删除全部文本。未指定删除文本的起始位置，则默认从下标0开始删除；未指定删除文本的终止位置，则默认以文本末尾作为删除的结束点。 |

### getSelection<sup>15+</sup>

getSelection(): TextRange

返回当前文本的选择范围。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| [TextRange](ts-text-common.md#textrange12) | 文本当前的选择范围，未选中返回光标位置。 |

### clearPreviewText<sup>17+</sup>

clearPreviewText(): void

通知输入法清除当前的预上屏文本内容。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## InputCounterOptions<sup>11+</sup>对象说明

计数器的配置项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| thresholdPercentage | number  | 否 | 是 | thresholdPercentage是可输入字符数占最大字符限制的百分比值。字符计数器显示的样式为当前输入字符数/最大字符数。当输入字符数大于最大字符数乘百分比值时，显示字符计数器。thresholdPercentage值的有效值区间为[1,100]，数值为小数时，向下取整，如果设置的number超出有效值区间内，不显示字符计数器。thresholdPercentage设置为undefined，显示字符计数器，但此参数不生效。 |
| highlightBorder     | boolean | 否  | 是 | 如果用户设置计数器时不设置InputCounterOptions，那么当前输入字符数达到最大字符数时，边框和计数器下标将变为红色。如果用户设置显示字符计数器同时thresholdPercentage参数数值在有效区间内，那么当输入字符数超过最大字符数时，边框和计数器下标将变成红色。如果此参数为true，则显示红色边框。计数器默认显示红色边框。 |

## CaretOffset<sup>11+</sup>对象说明

光标相对输入框的位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| index | number | 否 | 否 | 光标所在位置的索引值。    |
| x     | number | 否 | 否 | 光标相对输入框的x坐标位值，单位px。 |
| y     | number | 否 | 否 | 光标相对输入框的y坐标位值，单位px。 |

## TextDecorationOptions<sup>12+</sup>对象说明

文本装饰线的配置项。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| type  | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | 否   | 否 | 设置文本装饰线类型。 |
| color  | &nbsp;[ResourceColor](ts-types.md#resourcecolor) | 否   | 是 | 设置文本装饰线颜色。 |
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | 否   | 是 | 设置文本装饰线样式。 |

## SelectionOptions<sup>12+</sup>对象说明

setTextSelection选中文字时的配置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| menuPolicy | [MenuPolicy](#menupolicy12) | 否   | 是 | 菜单弹出的策略。 |

## MenuPolicy<sup>12+</sup>

菜单弹出的策略。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称    | 值   | 说明                               |
| ------- | ---- | ---------------------------------- |
| DEFAULT | 0    | 按照底层默认逻辑决定是否弹出菜单。 |
| HIDE    | 1    | 始终不弹出菜单。                   |
| SHOW    | 2    | 始终弹出菜单。                     |

## SymbolGlyphModifier<sup>12+</sup>

type SymbolGlyphModifier = SymbolGlyphModifier

SymbolGlyphModifier类型，用于设置自定义图标小符号。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型  | 说明       |
| ----- | -------- |
| [SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | 返回当前的SymbolGlyphModifier。 |

## TextContentControllerOptions<sup>15+</sup>

用于设置输入框插入字符时的配置选项。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 只读 | 可选 | 说明       |
| --------- | ------ | ---- | ---- | ---------- |
| offset | number | 否   | 是   | 插入文本的位置。 |