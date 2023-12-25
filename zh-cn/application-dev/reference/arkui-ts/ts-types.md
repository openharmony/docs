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

## RectResult<sup>10+</sup>

位置和尺寸类型，用于描述组件的位置和宽高。

| 参数      | 类型     | 描述 |
| ------- | ------ | ----------------------- |
| x     | number | 水平方向横坐标。|
| y     | number | 竖直方向纵坐标。|
| width | number | 内容宽度大小。|
| height | number | 内容高度大小。|

## ResourceColor

颜色类型，用于描述资源颜色类型。

| 类型                                  | 说明                                       |
| ----------------------------------- | ---------------------------------------- |
| [Color](ts-appendix-enums.md#color) | 颜色枚举值。                                   |
| number                              | HEX格式颜色，支持rgb。示例：0xffffff。               |
| string                              | rgb或者argb格式颜色。示例：'#ffffff', '#ff000000', 'rgb(255, 100, 255)', 'rgba(255, 100, 255, 0.5)'。 |
| [Resource](#resource)               | 使用引入资源的方式，引入系统资源或者应用资源中的颜色。              |

## ColoringStrategy<sup>10+</sup>

智能取色枚举类型，用于设置前景色。

| 名称     | 描述              |
| ------ | --------------- |
| INVERT | 设置前景色为控件背景色的反色。 |
| AVERAGE| 设置控件背景阴影色为控件背景阴影区域的平均色。 |
| PRIMARY| 设置控件背景阴影色为控件背景阴影区域的主色。 |

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
| family | string \| [Resource](#resource)          | 否    | 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, HarmonyOS Sans'。当前支持'HarmonyOS Sans'字体和[注册自定义字体](../apis/js-apis-font.md)。 |
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
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)  \| [EdgeStyles](#EdgeStyles9)<sup>9+</sup>| 否    | 边框样式。   |

## ColorFilter<sup>9+</sup>

创建具有4*5矩阵的颜色过滤器。

| 名称          | 类型       | 必填   | 描述                                       |
| ----------- | -------- | ---- | ---------------------------------------- |
| constructor | number[] | 是    | 创建具有4\*5矩阵的颜色过滤器, 入参为[m\*n]位于m行和n列中矩阵值, 矩阵是行优先的。 |


## CustomBuilder<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | 生成用户自定义组件，在使用时结合@Builder使用。具体用法见[@Builder](../../quick-start/arkts-builder.md#builder)。 |

## PixelStretchEffectOptions<sup>10+</sup>

像素扩展属性集合,用于描述像素扩展的信息。

| 名称     | 类型                | 必填   | 说明             |
| ------ | ----------------- | ---- | -------------- |
| left   | [Length](#length) | 否    | 组件图像左边沿像素扩展距离。 |
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
| [VP](#vp10)                | 需要指定数字或vp像素单位，如10或'10vp'。 |
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
| {number}vp\|number | 需要指定数字或vp像素单位，如10或'10vp'。 |

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

## SwiperAnimationEvent<sup>10+</sup>

Swiper组件动画相关信息集合。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| currentOffset | number | Swiper当前显示元素在主轴方向上，相对于Swiper起始位置的位移。单位VP，默认值为0。|
| targetOffset | number | Swiper动画目标元素在主轴方向上，相对于Swiper起始位置的位移。单位VP，默认值为0。|
| velocity | number | Swiper离手动画开始时的离手速度。单位VP/S，默认值为0。|

## TabsAnimationEvent<sup>11+</sup>

Tabs组件动画相关信息集合。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| currentOffset | number | Tabs当前显示元素在主轴方向上，相对于Tabs起始位置的位移。单位VP，默认值为0.|
| targetOffset | number | Tabs动画目标元素在主轴方向上，相对于Tabs起始位置的位移。单位VP，默认值为0.|
| velocity | number | Tabs离手动画开始时的离手速度。单位VP/S，默认值为0.|

## SafeAreaType<sup>10+</sup>

扩展安全区域的枚举类型。

| 名称     | 描述                                       |
| -------- | ------------------------------------------ |
| SYSTEM   | 系统默认非安全区域，包括状态栏、导航栏。   |
| CUTOUT   | 设备的非安全区域，例如刘海屏或挖孔屏区域。 |
| KEYBOARD | 软键盘区域。                               |

## SafeAreaEdge<sup>10+</sup>

扩展安全区域的方向。

| 名称   | 描述       |
| ------ | ---------- |
| TOP    | 上方区域。 |
| BOTTOM | 下方区域。 |
| START  | 前部区域。 |
| END    | 尾部区域。 |

## KeyboardAvoidMode<sup>11+</sup>

配置键盘避让时页面的避让模式。

| 名称   | 描述       |
| ------ | ---------- |
| OFFSET | 上抬模式。 |
| RESIZE | 压缩模式。 |

## TouchPoint<sup>11+</sup>

配置跟手点坐标，不配置时，默认居中。

| 名称   | 描述       |
| ------ | ---------- |
| X | 跟手点X轴坐标。 |
| Y | 跟手点Y轴坐标。 |

## TabContentAnimatedTransition<sup>11+</sup>

Tabs自定义切换动画相关信息。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| timeout | number | Tabs自定义切换动画超时时间。从自定义动画开始切换计时，如果到达该时间后，开发者仍未调用[TabContentTransitionProxy](#tabcontenttransitionproxy11)的finishTransition接口通知Tabs组件自定义动画结束，那么组件就会认为此次自定义动画已结束，直接执行后续操作。单位ms，默认值为1000.|
| transition | (proxy: [TabContentTransitionProxy](#tabcontenttransitionproxy11)) => void | 自定义切换动画具体内容。|

## TabContentTransitionProxy<sup>11+</sup>

Tabs自定义切换动画执行过程中，返回给开发者的proxy对象。开发者可通过该对象获取自定义动画的起始和目标页面信息，同时，也可以通过调用该对象的finishTransition接口通知Tabs组件自定义动画已结束。

| 名称            | 类型定义                   | 描述                                       |
| ------------- | ---------------------- | ---------------------------------------- |
| from | number | 自定义动画起始页面对应的index值。|
| to | number | 自定义动画目标页面对应的index值。|
| finishTransition() | void | 通知Tabs组件，此次自定义动画已结束。|
