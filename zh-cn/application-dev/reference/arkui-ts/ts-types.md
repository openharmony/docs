# 类型定义

>**说明：**
>
>本模块首批接口从API version 7开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。

## Resource

资源引用类型，用于设置组件属性的值。

可以通过`$r`或者`$rawfile`创建Resource类型对象，不可以修改Resource中的各属性的值。

- `$r('belonging.type.name')`

  belonging：系统资源或者应用资源，相应的取值为'sys'和'app'；

  type：资源类型，支持'boolean'、'color'、'float'、'intarray'、'integer'、'pattern'、'plural'、'strarray'、'string'、'media'；

  name：资源名称，在资源定义时确定。

- `$rawfile('filename')`

  filename：工程中resources/rawfile目录下的文件名称。

  **说明：** 在引用资源类型时，注意其数据类型要与属性方法本身的类型一致，例如某个属性方法支持设置string | Resource，那么在使用Resource引用类型时，其数据类型也应当为string。

## Length

长度类型，用于描述尺寸单位。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| string                | 需要显式指定像素单位，如'10px'，也可设置百分比字符串，如'100%'。 |
| number                | 默认单位vp。                                |
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的尺寸。               |

## ResourceStr

字符串类型，用于描述字符串入参可以使用的类型。

| 类型                    | 说明                        |
| --------------------- | ------------------------- |
| string                | 字符串类型。                    |
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的字符串。 |

## Padding

内边距类型，用于描述组件不同方向的内边距。

| 名称     | 类型                | 必填   | 说明                   |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | 否    | 上内边距，组件内元素距组件顶部的尺寸。  |
| right  | [Length](#length) | 否    | 右内边距，组件内元素距组件右边界的尺寸。 |
| bottom | [Length](#length) | 否    | 下内边距，组件内元素距组件底部的尺寸。  |
| left   | [Length](#length) | 否    | 左内边距，组件内元素距组件左边界的尺寸。 |

## Margin

外边距类型，用于描述组件不同方向的外边距。

| 名称     | 类型                | 必填   | 说明                   |
| ------ | ----------------- | ---- | -------------------- |
| top    | [Length](#length) | 否    | 上外边距，组件顶部距组件外元素的尺寸。  |
| right  | [Length](#length) | 否    | 右外边距，组件右边界距组件外元素的尺寸。 |
| bottom | [Length](#length) | 否    | 下外边距，组件底部距组件外元素的尺寸。  |
| left   | [Length](#length) | 否    | 左外边距，组件左边界距组件外元素的尺寸。 |

## EdgeWidths<sup>9+</sup>

边框宽度类型，用于描述组件边框不同方向的宽度。

| 名称     | 类型                | 必填   | 说明       |
| ------ | ----------------- | ---- | -------- |
| top    | [Length](#length) | 否    | 组件上边框宽度。 |
| right  | [Length](#length) | 否    | 组件右边框宽度。 |
| bottom | [Length](#length) | 否    | 组件下边框宽度。 |
| left   | [Length](#length) | 否    | 组件左边框宽度。 |

## BorderRadiuses<sup>9+</sup>

圆角类型，用于描述组件边框圆角半径。

| 名称          | 类型                | 必填   | 说明         |
| ----------- | ----------------- | ---- | ---------- |
| topLeft     | [Length](#length) | 否    | 组件左上角圆角半径。 |
| topRight    | [Length](#length) | 否    | 组件右上角圆角半径。 |
| bottomLeft  | [Length](#length) | 否    | 组件左下角圆角半径。 |
| bottomRight | [Length](#length) | 否    | 组件右下角圆角半径。 |

## EdgeColors<sup>9+</sup>

边框颜色，用于描述组件边框四条边的颜色。

| 名称     | 类型                              | 必填   | 说明       |
| ------ | ------------------------------- | ---- | -------- |
| top    | [ResourceColor](#resourcecolor) | 否    | 组件上边框颜色。 |
| right  | [ResourceColor](#resourcecolor) | 否    | 组件右边框颜色。 |
| bottom | [ResourceColor](#resourcecolor) | 否    | 组件下边框颜色。 |
| left   | [ResourceColor](#resourcecolor) | 否    | 组件左边框颜色。 |

## EdgeStyles<sup>9+</sup>

边框样式，用于描述组件边框四条边的样式。

| 名称     | 类型                                       | 必填   | 说明       |
| ------ | ---------------------------------------- | ---- | -------- |
| top    | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 组件上边框样式。 |
| right  | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 组件右边框样式。 |
| bottom | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 组件下边框样式。 |
| left   | [BorderStyle](ts-appendix-enums.md#borderstyle) | 否    | 组件左边框样式。 |


## Offset

相对布局完成位置坐标偏移量。

| 名称   | 类型                | 必填   | 说明       |
| ---- | ----------------- | ---- | -------- |
| dx   | [Length](#length) | 是    | 水平方向偏移量。 |
| dy   | [Length](#length) | 是    | 竖直方向偏移量。 |

## ResourceColor

颜色类型，用于描述资源颜色类型。

| 类型                                  | 说明                                       |
| ----------------------------------- | ---------------------------------------- |
| [Color](ts-appendix-enums.md#color) | 颜色枚举值。                                   |
| number                              | HEX格式颜色，支持rgb。示例：0xffffff。               |
| string                              | rgb或者argb格式颜色。示例：'#ffffff', '#ff000000', 'rgb(255, 100, 255)', 'rgba(255, 100, 255, 0.5)'。 |
| [Resource](#resource)               | 使用引入资源的方式，引入系统资源或者应用资源中的颜色。              |

## ColoringStrategy

智能取色枚举类型，用于设置前景色。

| 名称     | 描述              |
| ------ | --------------- |
| INVERT | 设置前景色为控件背景色的反色。 |

## LengthConstrain

长度约束，用于对组件最大、最小长度做限制。

| 名称        | 类型                | 必填   | 说明      |
| --------- | ----------------- | ---- | ------- |
| minLength | [Length](#length) | 是    | 组件最小长度。 |
| maxLength | [Length](#length) | 是    | 组件最大长度。 |


## Font

设置文本样式。

| 名称     | 类型                                       | 必填   | 说明                                       |
| ------ | ---------------------------------------- | ---- | ---------------------------------------- |
| size   | [Length](#length)                        | 否    | 设置文本尺寸，Length为number类型时，使用fp单位。不支持设置百分比字符串。<br>默认值：16.0  |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string | 否    | 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，取值越大，字体越粗。<br>默认值：400 \| FontWeight.Normal |
| family | string \| [Resource](#resource)          | 否    | 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, HarmonyOS Sans'。当前只支持'HarmonyOS Sans'字体。 |
| style  | [FontStyle](ts-appendix-enums.md#fontstyle) | 否    | 设置文本的字体样式。<br>默认值：FontStyle.Normal                               |

## Area<sup>8+</sup>

区域类型，用于存储元素所占区域信息

| 名称             | 类型                     | 说明                             |
| -------------- | ---------------------- | ------------------------------ |
| width          | [Length](#length)      | 目标元素的宽度，作为返回值时，类型为number，单位vp。 |
| height         | [Length](#length)      | 目标元素的高度，作为返回值时，类型为number，单位vp。 |
| position       | [Position](#position8) | 目标元素左上角相对父元素左上角的位置。            |
| globalPosition | [Position](#position8) | 目标元素左上角相对页面左上角的位置。             |

## Position<sup>8+</sup>

位置类型，用于表示一个坐标点。

| 名称   | 类型                | 必填   | 说明                          |
| ---- | ----------------- | ---- | --------------------------- |
| x    | [Length](#length) | 否    | x轴坐标，作为返回值时，类型为number，单位vp。 |
| y    | [Length](#length) | 否    | y轴坐标，作为返回值时，类型为number，单位vp。 |

## ConstraintSizeOptions

设置约束尺寸，组件布局时，进行尺寸范围限制。

| 名称        | 类型                | 必填   | 说明      |
| --------- | ----------------- | ---- | ------- |
| minWidth  | [Length](#length) | 否    | 元素最小宽度。 |
| maxWidth  | [Length](#length) | 否    | 元素最大宽度。 |
| minHeight | [Length](#length) | 否    | 元素最小高度。 |
| maxHeight | [Length](#length) | 否    | 元素最大高度。 |

## SizeOptions

设置宽高尺寸。

| 名称     | 类型                | 必填   | 说明    |
| ------ | ----------------- | ---- | ----- |
| width  | [Length](#length) | 否    | 元素宽度。 |
| height | [Length](#length) | 否    | 元素高度。 |


## BorderOptions

边框属性集合，用于描述边框相关信息。

| 名称     | 类型                                       | 必填   | 说明      |
| ------ | ---------------------------------------- | ---- | ------- |
| width  | [Length](#length)  \| [EdgeWidths](#edgewidths9)<sup>9+</sup> | 否    | 边框宽度。   |
| color  | [ResourceColor](#resourcecolor) \| [EdgeColors](#edgecolors9)<sup>9+</sup> | 否    | 边框颜色。   |
| radius | [Length](#length) \| [BorderRadiuses](#borderradiuses9)<sup>9+</sup> | 否    | 边框圆角半径。 |
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)  \| EdgeStyles<sup>9+</sup> | 否    | 边框样式。   |

## ColorFilter<sup>9+</sup>

创建具有4*5矩阵的颜色过滤器。

| 名称          | 类型       | 必填   | 描述                                       |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | 是    | 创建具有4\*5矩阵的颜色过滤器, 入参为[m\*n]位于m行和n列中矩阵值, 每个值的有效范围是[0, 1], 矩阵是行优先的。 |


## CustomBuilder<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | 该方法类型必须使用@Builder装饰器修饰。具体用法见[@Builder](../../quick-start/arkts-builder.md#builder)。 |

## PixelStretchEffectOptions<sup>10+</sup>

像素扩展属性集合,用于描述像素扩展的信息。

| 名称     | 类型                | 必填   | 说明             |
| ------ | ----------------- | ---- | -------------- |
| left   | [Length](#length) | 否    | 组件图像左边沿扩展距离。   |
| right  | [Length](#length) | 否    | 组件图像右边沿像素扩展距离。 |
| top    | [Length](#length) | 否    | 组件图像上边沿像素扩展距离。 |
| bottom | [Length](#length) | 否    | 组件图像下边沿像素扩展距离。 |

## ModalTransition<sup>10+</sup>

全屏模态转场方式枚举类型，用于设置全屏模态转场类型。

| 名称      | 描述           |
| ------- | ------------ |
| NONE    | 全屏模态无转场动画。   |
| DEFAULT | 全屏模态上下切换动画。  |
| ALPHA   | 全屏模态透明度渐变动画。 |

## Dimension<sup>10+</sup>

长度类型，用于描述尺寸单位。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| [PX](#px10)               | 需要指定以px像素单位，如'10px'。 |
| [VP](#vp10)                | 需要指定以vp像素单位，如'10vp'。|
| [FP](#fp10)                | 需要指定以fp像素单位，如'10fp'。|
| [LPX](#lpx10)              | 需要指定以lpx像素单位，如'10lpx'。|
| [Percentage](#percentage10)        | 需要指定以%像素单位，如'10%'。|
| [Resource](#resource) | 资源引用类型，引入系统资源或者应用资源中的尺寸。|

## PX<sup>10+</sup>

长度类型，用于描述以px像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}px               | 需要指定以px像素单位，如'10px'。 |

## VP<sup>10+</sup>

长度类型，用于描述以vp像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}vp               | 需要指定以vp像素单位，如'10vp'。 |

## FP<sup>10+</sup>

长度类型，用于描述以fp像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}fp               | 需要指定以fp像素单位，如'10fp'。 |

## LPX<sup>10+</sup>

长度类型，用于描述以lpx像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}lpx               | 需要指定以lpx像素单位，如'10lpx'。 |

## Percentage<sup>10+</sup>

长度类型，用于描述以%像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}%               | 需要指定以%像素单位，如'10%'。 |

## Degree<sup>10+</sup>

角度类型，用于描述以deg像素单位为单位的长度。

| 类型                    | 说明                                     |
| --------------------- | -------------------------------------- |
| {number}deg               | 需要指定以deg像素单位，如'10deg'。 |