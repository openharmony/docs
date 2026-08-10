# 输入框类组件通用接口 
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiaxiaguang-->
<!--Designer: @xiangyuan6-->
<!--Tester: @jiaoaozihao-->
<!--Adviser: @Brilliantry_Rui-->

为[TextInput](ts-basic-components-textinput.md)、[TextArea](ts-basic-components-textarea.md)组件提供获取文本和光标信息、插入和删除文本、设置计数器以及文本装饰线的能力，适用于需要通过程序化方式控制输入框文本内容和光标位置的场景。

为[Search](ts-basic-components-search.md)组件提供获取文本和光标信息、插入和删除文本以及设置文本装饰线的能力。

>  **说明：**
>
> - 从API version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

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
| [RectResult](ts-universal-attributes-on-child-touch-test.md#rectresult) | 获取已编辑文本内容区域相对组件的位置和大小。<br>当controller未绑定组件或绑定controller的组件被释放时，返回undefined。 |

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
| number| 已编辑文本内容行数。<br>当controller未绑定组件或绑定controller的组件被释放时，返回undefined。 |

### getCaretOffset<sup>11+</sup>

getCaretOffset(): CaretOffset

返回当前光标所在位置信息。

> **说明：**
>
> - 在当前帧更新光标位置同时调用该接口，该接口不生效。
> - 在Search组件中，返回的位置信息是相对Search组件中搜索图标的偏移值。
> - 在Search组件中，不输入文本时，返回值中有相对Search组件的位置信息。
> - 返回值中的位置信息是光标相对于可编辑组件的位置。
> - 当无法获取光标位置时（例如[TextInputController](ts-basic-components-textinput.md#textinputcontroller8)未与[TextInput](ts-basic-components-textinput.md)组件绑定时），该接口返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| [CaretOffset](#caretoffset11对象说明) | 光标相对输入框的位置。<br>当controller未绑定组件或绑定controller的组件被释放时，返回undefined。 |

### addText<sup>15+</sup>

addText(text: string, textOperationOptions?: TextContentControllerOptions): number

在已编辑文本的指定位置插入文本，默认插入至文本末尾。

拖拽文本的状态下不生效。

`addText`仅影响应用内部的UI表现，不影响输入法应用的内部逻辑。预上屏状态由输入法管理，应用层调用`addText`/`deleteText`会破坏输入法的状态管理，因此应避免在预上屏状态下调用`addText`。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| text | string | 是    | 插入的文本内容。 |
| textOperationOptions   | [TextContentControllerOptions](#textcontentcontrolleroptions15) | 否    | 插入文本的配置选项，用于自定义插入位置等参数。当需要在指定位置插入文本时传入此参数，不设置时默认插入文本至末尾。 |

**返回值：**

| 类型  | 说明       |
| ----- | -------- |
| number| 插入文本后光标的位置。 |

### setStyledPlaceholder<sup>22+</sup>

setStyledPlaceholder(styledString: StyledString): void

设置属性字符串样式的占位文本，触发绑定或更新。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| styledString | [StyledString](ts-universal-styled-string.md#styledstring) | 是 | 设置属性字符串样式的Placeholder，其优先级高于纯文本的placeholder属性。<br>Placeholder不支持属性字符串事件、手势、超链接跳转。|

### deleteText<sup>15+</sup>

deleteText(range?: TextRange): void

删除已编辑文本的指定区域的内容。

拖拽文本的状态下不生效。

`deleteText`仅影响应用内部的UI表现，不影响输入法应用的内部逻辑。预上屏状态由输入法管理，应用层调用`addText`/`deleteText`会破坏输入法的状态管理，因此应避免在预上屏状态下调用`deleteText`。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**与[deleteBackward](#deletebackward23)的差异：**
- deleteText支持范围删除，可删除任意指定区域的文本；deleteBackward模拟用户删除操作，删除光标前一个字符或已选中文本。
- deleteText在预上屏状态下应避免调用，deleteBackward在预上屏场景下不支持使用。
- 建议根据删除需求选择：需要删除指定范围文本时使用deleteText，需要删除光标前字符时使用deleteBackward。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| range | [TextRange](ts-text-common.md#textrange12) | 否    | 删除文本的范围，包括删除文本的起始位置和终止位置。<br>起始位置应小于等于结束位置，否则接口调用无效。起始位置小于0视为0，结束位置大于文本长度视为文本长度。<br>未指定删除范围时，默认将删除全部文本。未指定删除文本的起始位置，则默认从下标0开始删除；未指定删除文本的终止位置，则默认以文本末尾作为删除的结束点。 |

### getSelection<sup>15+</sup>

getSelection(): TextRange

返回当前文本的选择范围。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**返回值：**

| 类型                      | 说明               |
| ----------------------- | ---------------- |
| [TextRange](ts-text-common.md#textrange12) | 文本当前的选择范围，未选中返回光标位置。<br>当controller未绑定组件或绑定controller的组件被释放时，返回undefined。 |

### clearPreviewText<sup>17+</sup>

clearPreviewText(): void

通知输入法清除当前的预上屏文本内容。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**原子化服务API：** 从API version 17开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### deleteBackward<sup>23+</sup>

deleteBackward(): void

删除基础控制器`controller`绑定的文本输入框内光标前的一个字符。如果在调用此功能前已用鼠标或键盘选中了部分文本，则删除被选中的文本。

拖拽文本的状态下不生效。

`deleteBackward`仅影响应用内部的UI表现，不影响输入法应用的内部逻辑，不支持在预上屏场景下使用。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### scrollToVisible<sup>23+</sup>

scrollToVisible(range?: TextRange): void

将起始索引与结束索引传递给与其绑定的输入框（TextInput、TextArea、Search）组件，并将此范围内的文字滚动到可视区域。

> **说明：**
>
> 当controller未绑定组件或绑定controller的组件被释放时，该接口不生效。

**原子化服务API：** 从API version 23开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型   | 必填   | 说明  |
| ------- | ------ | ---- | ----- |
| range | [TextRange](ts-text-common.md#textrange12) | 否    | 滚动到可视区域的文本范围，包括文本起始位置和终止位置。<br>起始位置应小于等于结束位置，否则接口调用无效。起始位置小于0视为0，结束位置大于全文长度视为全文长度。<br>未指定范围时，默认为全部文本。未指定起始位置，默认起始位置为0；未指定结束位置，默认结束位置为全文长度。 |

## InputCounterOptions<sup>11+</sup>对象说明

计数器的配置项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| thresholdPercentage | number  | 否 | 是 | 可输入字符数占最大字符限制的百分比值。字符计数器显示的样式为当前输入字符数/最大字符数。当输入字符数大于最大字符数乘百分比值时，显示字符计数器。有效值区间为[1,100]，数值为小数时，向下取整，如果设置的number超出有效值区间内，不显示字符计数器。设置为undefined时，显示字符计数器，但此参数不生效。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| highlightBorder     | boolean | 否  | 是 | 如果用户设置计数器时不设置InputCounterOptions，那么当前输入字符数达到最大字符数时，边框和计数器下标将变为红色。如果用户设置显示字符计数器同时thresholdPercentage参数数值在有效区间内，那么当输入字符数超过最大字符数时，边框和计数器下标将变成红色。如果此参数为true，则显示红色边框，参数为false则不显示。<br>默认值：true<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。|
| counterTextColor<sup>22+</sup> | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 否 | 是 | 设置组件中字符计数器的文本颜色。当用户输入字符数大于最大字符数乘百分比值时，计数器会显示当前输入的字符数，并且计数器的文本颜色为counterTextColor指定的颜色。如果不设置counterTextColor，则计数器的文本颜色为默认颜色，默认颜色为灰色。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。|
| counterTextOverflowColor<sup>22+</sup> | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | 否 | 是 | 设置组件中字符计数器在溢出时的文本颜色。当用户输入的字符数超过最大字符数时，计数器的文本颜色和边框的颜色会切换为counterTextOverflowColor指定的颜色，以提醒用户输入已超出限制。如果不设置counterTextOverflowColor，则计数器和边框在溢出时的文本颜色为默认颜色，默认颜色为红色。<br>**说明：**<br>当设置了[InputCounterOptions](#inputcounteroptions11对象说明)的highlightBorder属性时，边框颜色才会被同步更改。<br>**原子化服务API：** 从API version 22开始，该接口支持在原子化服务中使用。|

## CaretOffset<sup>11+</sup>对象说明

光标相对输入框的位置信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| index | number | 否 | 否 | 光标所在位置的索引值，从0开始计数，取值范围为[0, 文本长度]。    |
| x     | number | 否 | 否 | 光标相对输入框的x坐标值，单位px。 |
| y     | number | 否 | 否 | 光标相对输入框的y坐标值，单位px。 |

## TextDecorationOptions<sup>12+</sup>对象说明

文本装饰线的配置项。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| type  | [TextDecorationType](ts-appendix-enums.md#textdecorationtype) | 否   | 否 | 设置文本装饰线类型。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| color  | &nbsp;[ResourceColor](ts-types.md#resourcecolor) | 否   | 是 | 设置文本装饰线颜色。<br>默认值：Color.Black。 <br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| style | [TextDecorationStyle](ts-appendix-enums.md#textdecorationstyle12) | 否   | 是 | 设置文本装饰线样式。<br>默认值：TextDecorationStyle.SOLID。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| thicknessScale | number | 否   | 是 | 设置文本装饰线的粗细缩放比例。<br>默认值：1.0 <br>取值范围：[0, +∞) <br>**说明：** 负值按默认值处理。<br>**起始版本：** 26.0.0<br>**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。 |

## SelectionOptions<sup>12+</sup>对象说明

setTextSelection选中文字时的配置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型    |     只读    |     可选    |     说明    |
| -------- | ------- | ----------- | ----------- | ----------- |
| menuPolicy | [MenuPolicy](#menupolicy12) | 否   | 是 | 菜单弹出的策略。 默认值：MenuPolicy.DEFAULT。|

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

type SymbolGlyphModifier = import('../api/arkui/SymbolGlyphModifier').SymbolGlyphModifier

SymbolGlyphModifier类型，用于设置自定义图标小符号。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型  | 说明       |
| ----- | -------- |
| import('../api/arkui/SymbolGlyphModifier').[SymbolGlyphModifier](ts-universal-attributes-attribute-symbolglyphmodifier.md#symbolglyphmodifier) | SymbolGlyphModifier对象，用于设置自定义图标小符号。 |

## TextContentControllerOptions<sup>15+</sup>

用于设置输入框插入字符时的配置选项。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 只读 | 可选 | 说明       |
| --------- | ------ | ---- | ---- | ---------- |
| offset | number | 否   | 是   | 插入文本的位置，取值范围[0, 文本长度]。超出范围时自动修正到有效边界位置。<br>**说明：**<br>当需要在指定位置（而非末尾）插入文本时传入此参数。不传入时默认插入到文本末尾。 |