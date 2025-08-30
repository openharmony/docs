# 基础类型定义
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiangtao92-->
<!--Designer: @piggyguy-->
<!--Tester: @songyanhong-->
<!--Adviser: @HelloCrease-->

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## Resource

资源引用类型，用于设置组件属性的值。各类资源文件，需要放入特定子目录中存储管理，资源目录的示例请参考[资源分类](../../../quick-start/resource-categories-and-access.md#资源分类)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

可以通过`$r`或者`$rawfile`创建Resource类型对象，不可以修改Resource中的各属性的值。

- `$r('belonging.type.name')`

  belonging：系统资源或者应用资源，相应的取值为'sys'和'app'；

  type：资源类型，支持'boolean'、'color'、'float'、'intarray'、'integer'、'pattern'、'plural'、'strarray'、'string'、'media'；

  name：资源名称，在资源定义时确定。

- `$rawfile('filename')`

  filename：工程中resources/rawfile目录下的文件名称。

>  **说明：**
>
>  引用资源类型时，需确保资源类型对象内的数据类型与当前以资源类型作为参数的属性方法本身的类型一致。例如某个属性方法支持设置string | Resource，那么在使用Resource引用类型时，其数据类型也应当为string。
>
>  引用资源类型时，需确保资源类型对象用法为当前支持的用法，否则当前以资源类型作为参数的属性效果将和不设置该属性相同。

## Length

长度类型，用于描述尺寸单位。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| string                | 需要显式指定[像素单位](ts-pixel-units.md)，如'10px'，也可设置百分比字符串，如'100%'。<br/>**说明：** <br/>不指定像素单位时，默认单位vp，如'10'，等同于10。 |
| number                | 默认单位vp。                                |
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的尺寸。               |

## ResourceStr

字符串类型，用于描述字符串入参可以使用的类型。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| string                | 字符串类型。                    |
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的字符串。 |

## Padding

内边距类型，用于描述组件不同方向的内边距。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| top    | [Length](#length) | 否 | 是    | 上内边距，组件内元素距组件顶部的尺寸。  |
| right  | [Length](#length) | 否 | 是    | 右内边距，组件内元素距组件右边界的尺寸。 |
| bottom | [Length](#length) | 否 | 是    | 下内边距，组件内元素距组件底部的尺寸。  |
| left   | [Length](#length) | 否 | 是    | 左内边距，组件内元素距组件左边界的尺寸。 |

## LocalizedPadding<sup>12+</sup>

内边距类型，用于描述组件不同方向的内边距。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 | 是    | 上内边距，组件内元素距组件顶部的尺寸。  |
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 | 是    | 右内边距，组件内元素距组件右边界的尺寸。<br />从右至左显示语言模式下为<br />左内边距，组件内元素距组件左边界的尺寸。 |
| bottom | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 | 是    | 下内边距，组件内元素距组件底部的尺寸。  |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 | 是    | 左内边距，组件内元素距组件左边界的尺寸。<br />从右至左显示语言模式下为<br />右内边距，组件内元素距组件右边界的尺寸。 |

## Margin

外边距类型，用于描述组件不同方向的外边距。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                | 只读  |  可选   | 说明                   |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | 否   |  是 | 上外边距，组件顶部距组件外元素的尺寸。  |
| right  | [Length](#length) | 否   |  是 | 右外边距，组件右边界距组件外元素的尺寸。 |
| bottom | [Length](#length) | 否   |  是 | 下外边距，组件底部距组件外元素的尺寸。  |
| left   | [Length](#length) | 否   |  是 | 左外边距，组件左边界距组件外元素的尺寸。 |

## LocalizedMargin<sup>12+</sup>

外边距类型，用于描述组件不同方向的外边距。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                | 只读  |  可选   | 说明                   |
| ------ | ----------------- | ---- | -------------------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否  | 是  | 上外边距，组件顶部距组件外元素的尺寸。  |
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否   | 是 | 右外边距，组件右边界距组件外元素的尺寸。<br />从右至左显示语言模式下为<br />左外边距，组件左边界距组件外元素的尺寸。 |
| bottom | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否   | 是 | 下外边距，组件底部距组件外元素的尺寸。  |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否  | 是  | 左外边距，组件左边界距组件外元素的尺寸。<br />从右至左显示语言模式下为<br />右外边距，组件右边界距组件外元素的尺寸。 |

## EdgeWidths<sup>9+</sup>

边框宽度类型，用于描述组件边框不同方向的宽度。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| top    | [Length](#length) | 否|是    | 组件上边框宽度。 |
| right  | [Length](#length) | 否|是    | 组件右边框宽度。 |
| bottom | [Length](#length) | 否|是    | 组件下边框宽度。 |
| left   | [Length](#length) | 否|是    | 组件左边框宽度。 |

## LocalizedEdgeWidths<sup>12+</sup>

边框宽度类型，用于描述组件边框不同方向的宽度。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 |是   | 组件上边框宽度。 |
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 |是   | 组件右边框宽度。<br />从右至左显示语言模式下为组件左边框宽度。 |
| bottom | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 |是   | 组件下边框宽度。 |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否 |是   | 组件左边框宽度。<br />从右至左显示语言模式下为组件右边框宽度。 |

## BorderRadiuses<sup>9+</sup>

圆角类型，用于描述组件边框圆角半径。
引用该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| topLeft     | [Length](#length) | 否|是    | 组件左上角圆角半径。 |
| topRight    | [Length](#length) | 否|是    | 组件右上角圆角半径。 |
| bottomLeft  | [Length](#length) | 否|是    | 组件左下角圆角半径。 |
| bottomRight | [Length](#length) | 否|是    | 组件右下角圆角半径。 |

## LocalizedBorderRadiuses<sup>12+</sup>

圆角类型，用于描述组件边框圆角半径。
引用该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| topStart    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否|是    | 组件左上角圆角半径。<br />从右至左显示语言模式下为组件右上角圆角半径。 |
| topEnd      | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否|是    | 组件右上角圆角半径。<br />从右至左显示语言模式下为组件左上角圆角半径。 |
| bottomStart | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否|是    | 组件左下角圆角半径。<br />从右至左显示语言模式下为组件右下角圆角半径。 |
| bottomEnd   | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否|是    | 组件右下角圆角半径。<br />从右至左显示语言模式下为组件左下角圆角半径。 |

## EdgeColors<sup>9+</sup>

边框颜色，用于描述组件边框四条边的颜色。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| top    | [ResourceColor](#resourcecolor) | 否|是    | 组件上边框颜色。 |
| right  | [ResourceColor](#resourcecolor) | 否|是    | 组件右边框颜色。 |
| bottom | [ResourceColor](#resourcecolor) | 否|是    | 组件下边框颜色。 |
| left   | [ResourceColor](#resourcecolor) | 否|是    | 组件左边框颜色。 |

## LocalizedEdgeColors<sup>12+</sup>

边框颜色，用于描述组件边框四条边的颜色。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| top    | [ResourceColor](#resourcecolor) | 否|是    | 组件上边框颜色。 |
| end    | [ResourceColor](#resourcecolor) | 否|是    | 组件右边框颜色。<br />从右至左显示语言模式下为组件左边框颜色。 |
| bottom | [ResourceColor](#resourcecolor) | 否|是    | 组件下边框颜色。 |
| start  | [ResourceColor](#resourcecolor) | 否|是    | 组件左边框颜色。<br />从右至左显示语言模式下为组件右边框颜色。 |

## EdgeStyles<sup>9+</sup>

边框样式，用于描述组件边框四条边的样式。
引入该对象时，至少传入一个参数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否|是    | 组件上边框样式。 |
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否|是    | 组件右边框样式。 |
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否|是    | 组件下边框样式。 |
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否|是    | 组件左边框样式。 |

## Offset

相对布局完成位置坐标偏移量。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型                | 只读  |  可选   | 说明       |
| ---- | ----------------- | ---- | -------- |
| dx   | [Length](#length) | 否  |  否    | 水平方向偏移量。 |
| dy   | [Length](#length) | 否  |  否    | 竖直方向偏移量。 |

## RectResult<sup>10+</sup>

位置和尺寸类型，用于描述组件的位置和宽高。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 只读 | 可选  | 说明 |
| ------- | ------ | ----- | -------- | ---------- |
| x     | number | 否 | 否 | 水平方向横坐标。|
| y     | number |  否 | 否 | 竖直方向纵坐标。|
| width | number | 否 | 否 | 内容宽度大小。|
| height | number | 否 | 否 | 内容高度大小。|

## ResourceColor

type ResourceColor = [Color](ts-appendix-enums.md#color) | number | string | [Resource](#resource)

颜色类型，用于描述资源颜色类型。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                                | 说明                                                         |
| ----------------------------------- | ------------------------------------------------------------ |
| [Color](ts-appendix-enums.md#color) | 颜色枚举值。                                                 |
| number                              | HEX格式颜色，支持rgb或者argb。示例：0xffffff，0xffff0000。number无法识别传入位数，格式选择依据值的大小，例如0x00ffffff作rgb格式解析 |
| string                              | rgb或者argb格式颜色。示例：'#ffffff'，'#ff000000'，'rgb(255, 100, 255)'，'rgba(255, 100, 255, 0.5)'。 |
| [Resource](#resource)               | 使用引入资源的方式，引入系统资源或者应用资源中的颜色。       |

## LengthConstrain

长度约束，用于对组件最大、最小长度做限制。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                | 只读  |  可选   | 说明      |
| --------- | ----------------- | ---- | ------- |
| minLength | [Length](#length) | 否  |  否    | 组件最小长度。 |
| maxLength | [Length](#length) | 否  |  否    | 组件最大长度。 |


## Font

设置文本样式。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型                                                         | 只读  |  可选 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Length](#length)                                            | 否   |  是  | 设置文本尺寸，Length为number类型时，使用fp单位。不支持设置百分比字符串。<br>默认值：16.0 |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | 否  |  是 | 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，取值越大，字体越粗。<br>默认值：400 \| FontWeight.Normal |
| family | string \| [Resource](#resource)                              | 否   |  是  | 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, HarmonyOS Sans'。当前支持'HarmonyOS Sans'字体和注册自定义字体[loadFontSync](../../apis-arkgraphics2d/js-apis-graphics-text.md#loadfontsync)。 |
| style  | [FontStyle](ts-appendix-enums.md#fontstyle)                  | 否   |  是  | 设置文本的字体样式。<br>默认值：FontStyle.Normal             |

## Area<sup>8+</sup>

区域类型，用于存储元素所占的区域信息。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称             | 类型                     | 说明                             |
| -------------- | ---------------------- | ------------------------------ |
| width          | [Length](#length)      | 目标元素的宽度。<br/>单位：vp |
| height         | [Length](#length)      | 目标元素的高度。<br/>单位：vp |
| position       | [Position](#position) | 目标元素左上角相对父元素左上角的位置。            |
| globalPosition | [Position](#position) | 目标元素左上角相对页面左上角的位置。             |

## Position

位置类型，用于表示一个坐标点。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型                | 只读  |  可选   | 说明                          |
| ---- | ----------------- | ---- | --------------------------- |
| x    | [Length](#length) | 否   |  是 | x轴坐标。<br/>单位：vp |
| y    | [Length](#length) | 否   |  是 | y轴坐标。<br/>单位：vp |

## LocalizedPosition<sup>12+</sup>

位置类型，用于表示一个坐标点。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型                | 只读  |  可选   | 说明                          |
| ---- | ----------------- | ---- | --------------------------- |
| start  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否  |  是  | LTR模式时x轴相对左边坐标，RTL模式x轴相对右边坐标。  |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否   |  是 | y轴坐标。 |

## Edges<sup>12+</sup>

位置类型，表示相对四边的偏移量。同时设置top和bottom，仅top生效；同时设置left和right，仅left生效。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型     | 只读  |  可选   | 说明                          |
| ---- | ------ | ---- | --------------------------- |
| top    | [Dimension](#dimension10) | 否  | 是  | 相对顶边的偏移量。 |
| bottom    | [Dimension](#dimension10) | 否  | 是  | 相对底边的偏移量。 |
| left    | [Dimension](#dimension10) | 否   | 是 | 相对左边的偏移量。 |
| right    | [Dimension](#dimension10) | 否  |  是  | 相对右边的偏移量。 |

## LocalizedEdges<sup>12+</sup>

位置类型，表示相对四边的偏移量。同时设置top和bottom，仅top生效；同时设置start和end，仅start生效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型     | 只读  |  可选   | 说明                          |
| ---- | ------ | ---- | --------------------------- |
| top    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否  |  是  | 相对顶边的偏移量。 |
| bottom    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否   | 是 | 相对底边的偏移量。 |
| start    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否   | 是 | LTR模式时相对左边的偏移量，RTL模式时相对右边的偏移量。|
| end    | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否  |  是  | LTR模式时相对右边的偏移量，RTL模式时相对左边的偏移量。 |

## ConstraintSizeOptions

约束尺寸类型，用于描述组件布局时对尺寸大小的范围限制。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| minWidth  | [Length](#length) | 否|是    | 元素最小宽度。 |
| maxWidth  | [Length](#length) | 否|是    | 元素最大宽度。 |
| minHeight | [Length](#length) | 否|是    | 元素最小高度。 |
| maxHeight | [Length](#length) | 否|是    | 元素最大高度。 |

>  **说明：**
>
>  在[Row](./ts-container-row.md)、[Column](./ts-container-column.md)、[RelativeContainer](./ts-container-relativecontainer.md)组件中，width、height设置auto表示自适应子组件。在[TextInput](./ts-basic-components-textinput.md)组件中，width设置auto表示自适应文本宽度。

## SizeOptions

宽高尺寸类型，用于描述组件布局时的宽高尺寸大小。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| width  | [Length](#length) | 否 |是   | 元素宽度。 |
| height | [Length](#length) | 否 |是   | 元素高度。 |


## BorderOptions

边框属性集合，用于描述边框相关信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| width  | [Length](ts-types.md#length)&nbsp;\|&nbsp;[EdgeWidths](./ts-types.md#edgewidths9)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeWidths](./ts-types.md#localizededgewidths12)<sup>12+</sup> | 否|是   | 设置边框宽度。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。     |
| color  | [ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](./ts-types.md#edgecolors9)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedEdgeColors](#localizededgecolors12)<sup>12+</sup> | 否|是   | 设置边框颜色。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。     |
| radius | [Length](ts-types.md#length)&nbsp;\|&nbsp;[BorderRadiuses](#borderradiuses9)<sup>9+</sup>&nbsp;\|&nbsp;[LocalizedBorderRadiuses](#localizedborderradiuses12)<sup>12+</sup> | 否|是   | 设置边框圆角半径。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)&nbsp;\|&nbsp;[EdgeStyles](#edgestyles9)<sup>9+</sup> | 否|是   | 设置边框样式。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。    |
| dashGap<sup>12+</sup>  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9)&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12) | 否|是  | 设置虚线的线段间距，仅在边框样式为虚线时生效。<br/>不支持设置百分比。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 该接口不支持在ArkTS卡片中使用。|
| dashWidth<sup>12+</sup>  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)&nbsp;\|&nbsp;[EdgeWidths](#edgewidths9)&nbsp;\|&nbsp;[LocalizedEdgeWidths](#localizededgewidths12) | 否|是   | 设置虚线的线段长度，仅在边框样式为虚线时生效。<br/>不支持设置百分比。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br/>**卡片能力：** 该接口不支持在ArkTS卡片中使用。     |

## ColorFilter<sup>9+</sup>

创建具有4*5矩阵的颜色过滤器。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型       | 必填   | 描述                                       |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | 是    | 创建具有4\*5矩阵的颜色过滤器，入参为[m\*n]位于m行和n列中矩阵值，矩阵是行优先的。 |


## CustomBuilder<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | (()&nbsp;=&gt;&nbsp;any) \| void | 生成用户自定义组件，在使用时结合[@Builder](../../../ui/state-management/arkts-builder.md)使用。 |

## MarkStyle<sup>10+</sup>对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                       | 只读  |  可选 | 默认值      | 描述                                                         |
| ----------- | ------------------------------------------ | ---- | ----------- | ------------------------------------------------------------ |
| strokeColor | [ResourceColor](ts-types.md#resourcecolor) | 否  |  是  | Color.White | 内部图标颜色。                                               |
| size        | [Length](ts-types.md#length)               | 否  |  是  | -           | 内部图标大小，单位vp。默认大小与多选框组件宽度相同。<br />不支持百分比形式设置。设置为非法值时，按照默认值处理。 |
| strokeWidth | [Length](ts-types.md#length)               | 否  |  是  | 2           | 内部图标粗细，单位vp。不支持设置百分比。设置为非法值时，按照默认值处理。 |

## ModalTransition<sup>10+</sup>

全屏模态转场方式枚举类型，用于设置全屏模态转场类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 描述           |
| ------- | ------------ |
| NONE    | 全屏模态无转场动画。   |
| DEFAULT | 全屏模态上下切换动画。  |
| ALPHA   | 全屏模态透明度渐变动画。 |

## OutlineOptions<sup>11+</sup>对象说明

外描边选项设置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

| 名称   | 类型                   | 只读   |   可选                             | 说明                                                         |
| ------ | ----------------------|----------------- | --------------------- | ------------------------------------------------------------ |
| width  | [Dimension](#dimension10)&nbsp;\|&nbsp;[EdgeOutlineWidths](#edgeoutlinewidths11对象说明)| 否 | 是 | 设置外描边宽度，不支持百分比。<br/>默认值：0，外描边效果中width为必设项，否则不显示外描边。 |
| color  | [ResourceColor](#resourcecolor)&nbsp;\|&nbsp;[EdgeColors](#edgecolors9)&nbsp;\|&nbsp;[LocalizedEdgeColors](#localizededgecolors12)<sup>12+</sup> | 否 | 是 | 设置外描边颜色。<br/>默认值：Color.Black                   |
| radius | [Dimension](#dimension10)&nbsp;\|&nbsp;[OutlineRadiuses](#outlineradiuses11对象说明)| 否 | 是 | 设置外描边圆角半径，不支持百分比。<br/>默认值：0<br/>最大生效值：组件width/2 + outlineWidth或组件height/2 + outlineWidth。 |
| style  | [OutlineStyle](ts-universal-attributes-outline.md#outlinestyle11枚举说明)&nbsp;\|&nbsp;[EdgeOutlineStyles](#edgeoutlinestyles11对象说明)| 否 | 是 | 设置外描边样式。<br/>默认值：OutlineStyle.SOLID            |

## EdgeOutlineWidths<sup>11+</sup>对象说明

引入该对象时，至少传入一个参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

| 名称     | 类型                         | 只读 | 可选   | 说明      |
| ------ | ---------------------------- | -- | -- | ------- |
| left   | [Dimension](#dimension10) | 否 | 是   | 左侧外描边宽度。 |
| right  | [Dimension](#dimension10) | 否 | 是    | 右侧外描边宽度。 |
| top    | [Dimension](#dimension10) | 否 | 是   | 上侧外描边宽度。 |
| bottom | [Dimension](#dimension10) | 否 | 是  | 下侧外描边宽度。 |

## OutlineRadiuses<sup>11+</sup>对象说明

引用该对象时，至少传入一个参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                         | 只读 | 可选   | 说明       |
| ----------- | -------------------- | -------- | ---- | -------- |
| topLeft     | [Dimension](ts-types.md#dimension10) | 否 | 是   | 左上角圆角半径。 |
| topRight    | [Dimension](ts-types.md#dimension10) | 否 | 是   | 右上角圆角半径。 |
| bottomLeft  | [Dimension](ts-types.md#dimension10) | 否 | 是   | 左下角圆角半径。 |
| bottomRight | [Dimension](ts-types.md#dimension10) | 否 | 是   | 右下角圆角半径。 |

## EdgeOutlineStyles<sup>11+</sup>对象说明

引入该对象时，至少传入一个参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 11开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                     | 只读 | 可选  | 说明      |
| ------ | ---------------------------------------- | -- | -- | ------- |
| left   | [OutlineStyle](ts-universal-attributes-outline.md#outlinestyle11枚举说明) | 否 | 是   | 左侧外描边样式。 |
| right  | [OutlineStyle](ts-universal-attributes-outline.md#outlinestyle11枚举说明) | 否 | 是   | 右侧外描边样式。 |
| top    | [OutlineStyle](ts-universal-attributes-outline.md#outlinestyle11枚举说明) | 否 | 是   | 上侧外描边样式。 |
| bottom | [OutlineStyle](ts-universal-attributes-outline.md#outlinestyle11枚举说明) | 否  | 是  | 下侧外描边样式。 |

## Dimension<sup>10+</sup>

长度类型，用于描述尺寸单位。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| [PX](#px10)               | 需要指定以px像素单位，如'10px'。 |
| [VP](#vp10)                | 需要指定数字或vp像素单位，如10或'10vp'。 |
| [FP](#fp10)                | 需要指定以fp像素单位，如'10fp'。|
| [LPX](#lpx10)              | 需要指定以lpx像素单位，如'10lpx'。|
| [Percentage](#percentage10)        | 需要指定以%像素单位，如'10%'。|
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的尺寸。|

## PX<sup>10+</sup>

长度类型，用于描述以px像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}px               | 需要指定以px像素单位，如'10px'。 |

## VP<sup>10+</sup>

长度类型，用于描述以vp像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}vp\|number | 需要指定数字或vp像素单位，如10或'10vp'。 |

## FP<sup>10+</sup>

长度类型，用于描述以fp像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}fp               | 需要指定以fp像素单位，如'10fp'。 |

## LPX<sup>10+</sup>

长度类型，用于描述以lpx像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}lpx               | 需要指定以lpx像素单位，如'10lpx'。 |

## Percentage<sup>10+</sup>

长度类型，用于描述以%像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}%               | 需要指定以%像素单位，如'10%'。 |

## Degree<sup>10+</sup>

角度类型，用于描述以deg像素单位为单位的长度。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}deg               | 需要指定以deg像素单位，如'10deg'。 |

## TouchPoint<sup>11+</sup>

配置跟手点坐标，不配置时，默认居中。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型定义 | 描述       |
| ------ | ----------------------| ---------- |
| X | [Dimension](#dimension10) | 跟手点X轴坐标。 |
| Y | [Dimension](#dimension10) | 跟手点Y轴坐标。 |

## VoidCallback<sup>12+</sup>

type VoidCallback：() => void;

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## Callback<sup>12+</sup>

Callback<T,V = void> = (data: T) => V;

带参数的函数回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## HoverCallback<sup>12+</sup>

hover事件的回调类型。

type HoverCallback = (isHover: boolean, event: HoverEvent)=> void

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名            | 类型            | 只读   |   可选         | 说明                                       |
| ------------- | ---------------------- | ---------------------| --------------------------------------- |
| isHover | boolean |  否  |  否  |是否处于hover状态，true表示处于hover状态，false表示不在hover状态。 |
| event | [HoverEvent](ts-universal-events-hover.md#hoverevent10对象说明) |  否  |  否   |  获取鼠标或手写笔悬浮的位置坐标。 |

## VisibleAreaEventOptions<sup>12+</sup>

关于区域变化相关的参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型                                                | 只读 | 可选 | 说明                                                         |
| ------ | --------------------------------------------------- | ---- | ------------------------------------------------------------ |
| ratios | Array&lt;number&gt;                                 | 否 | 否   | 阈值数组。其中，每个阈值代表组件可见面积（即组件在屏幕显示区的面积，只计算父组件内的面积，超出父组件部分不会计算）与组件自身面积的比值。每个阈值的取值范围为[0.0, 1.0]，如果开发者设置的阈值超出该范围，则会实际取值0.0或1.0。 |
| expectedUpdateInterval | number | 否 | 是 | 定义了开发者期望的计算间隔，单位为ms。默认值：1000|

## VisibleAreaChangeCallback<sup>12+</sup>

组件可见区域变化事件的回调类型。

type VisibleAreaChangeCallback = (isExpanding: boolean, currentRatio: number) => void;

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型               | 只读  |  可选       | 说明                                       |
| ------------- | ------------------   | -------------   | ---------------------- |
| isExpanding | boolean | 否 | 否 | 视组件的可见面积与自身面积的比值与上一次回调相比的情况而定，比值变大为true，比值变小为false。 |
| currentRatio | number | 否 | 否 | 触发回调时，组件可见面积与自身面积的比值。 |

## DividerStyleOptions<sup>12+</sup>

分割线样式属性集合, 用于描述分割线相关信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型                                      | 只读 | 可选 | 说明              |
| ------ | --------------------------------------- |---|-----------------|
| strokeWidth  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup>  | 否 | 是 | 分割线的线宽。         |
| color  | [ResourceColor](#resourcecolor) | 否  | 是 | 分割线的颜色。         |
| startMargin | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup> | 否  | 是 | 分割线与菜单侧边起始端的距离。 |
| endMargin  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)<sup>12+</sup>| 否  | 是 | 分割线与菜单侧边结束端的距离。 |
| mode  | [DividerMode](ts-appendix-enums.md#dividermode19枚举说明)<sup>19+</sup>| 否  | 是 | 设置分割线模式。 |

## ChainWeightOptions<sup>14+</sup>对象说明

链中组件的布局权重。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名   | 类型     | 描述             |
| ----- | ------ | -------------- |
| horizontal | number | 组件在竖直方向的布局权重，设置大于0的数字时生效。 <br> 默认值：0 <br> 异常值：0  |
| vertical     | number | 组件在水平方向的布局权重，设置大于0的数字时生效。 <br> 默认值：0 <br> 异常值：0 |

## Configuration

数据类型。用于设置颜色模式和字体缩放倍数。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称      | 类型   | 只读 | 可选 | 说明       |
| --------- | ------ | ---- | ---- | ---------- |
| colorMode | string | 是   | 否   | 颜色模式。 |
| fontScale | number | 是   | 否   | 字体缩放。 |

## AccessibilityOptions<sup>14+</sup>对象说明

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                   | 类型    | 只读 | 可选 | 说明                                                         |
| ---------------------- | ------- | ---- | ---- | ------------------------------------------------------------ |
| accessibilityPreferred | boolean | 否 | 是   | 若accessibilityPreferred设置为true，则深度遍历每个子节点时优先选择该子节点的无障碍文本accessibilityText。<br/>若无障碍文本为空则选择本身Text文本，最终将拼接完成的文本设置给accessibilityText与Text都为空的父节点。<br/>若accessibilityPreferred设置为false，表示不启用此功能。<br/>默认值：false |

## ScrollBarMargin<sup>20+</sup>对象说明

滚动条边距。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称  | 类型                                                         | 只读 | 可选 | 说明                                   |
| ----- | ------------------------------------------------------------ | ---- | -- | -------------------------------------- |
| start | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否   | 是 | 滚动条起始边距。<br/>默认值：0，单位：vp |
| end   | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否   | 是 | 滚动条末尾边距。<br/>默认值：0，单位：vp |

## DirectionalEdgesT\<T><sup>12+</sup>

边缘宽度类型，用于描述组件边缘不同方向的宽度。支持全球化。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称   | 类型 |只读|可选| 说明             |
| ------ | ---- |------|------| ---------------- |
| start   | T    |否|否| 起始边缘的属性。在LTR的方向下，为左边缘，在RTL的方向下，为右边缘。 |
| end    | T    | 否|否|终止边缘的属性。在LTR的方向下，为右边缘，在RTL的方向下，为左边缘。 |
| top  | T    | 否|否|顶部边缘的属性。 |
| bottom | T    | 否|否|底部边缘的属性。 |

## bias对象说明

设置组件在锚点约束下的偏移参数。
<br/>以水平方向Bias为例，其值为组件到左锚点的距离 D<sub>start</sub>与组件到水平方向锚点间总距离 D<sub>start</sub> +  D<sub>end</sub>的比值。镜像语言下，D<sub>start</sub>为组件到右锚点的距离。下图中D<sub>width</sub>表示组件宽度。
<br/>![bias_horizontal_example.png](figures/bias_horizontal_example.png)
<br/>竖直方向同理，其值为组件到上锚点的距离D<sub>top</sub>与组件到竖直方向锚点间总距离D<sub>top</sub> + D<sub>bottom</sub>的比值。下图中D<sub>height</sub>表示组件高度。
<br/>![bias_vertical_example.png](figures/bias_vertical_example.png)


**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| horizontal  | number | &nbsp;否 |是 | 水平方向上的bias值。<br/>当子组件的width属性有正确值并且有2个水平方向的锚点时生效，设置的值必须大于等于0。<br/>默认值：&nbsp;0.5 |
| vertical  | number | &nbsp;否 |是 | 垂直方向上的bias值。<br/>当子组件的height属性有正确值并且有2个垂直方向的锚点时生效，设置的值必须大于等于0。<br/>默认值：&nbsp;0.5 |