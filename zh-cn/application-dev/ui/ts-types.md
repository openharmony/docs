# 类型定义

## Resource

资源引用类型，用于设置组件属性的值。

可以通过`$r`或者`$rawfile`创建Resource类型对象，不可以修改Resource中的各属性的值。

- `$r('belonging.type.name')`

  belonging：系统资源或者应用资源，相应的取值为'sys'和'app'；

  type：资源类型，支持'color'、'float'、'string'、'media'等；

  name：资源名称，在资源定义时确定。

- `$rawfile('filename')`

  filename：工程中resources/rawfile目录下的文件名称。

## Length

长度类型，用于描述尺寸单位。

| 类型     | 说明                                                         |
| -------- | ------------------------------------------------------------ |
| string   | 需要显式指定像素单位，如'10px'，也可设置百分比字符串，如'100%'。 |
| number   | 默认单位vp。                                                 |
| Resource | 使用引入资源的方式，引入系统资源或者应用资源中的尺寸。           |

## ResourceStr<sup>8+</sup>

字符串类型，用于描述字符串入参可以使用的类型。

| 类型     | 说明                                                 |
| -------- | --------------------------------------------------- |
| string   | 字符串类型。                                         |
| Resource | 使用引入资源的方式，引入系统资源或者应用资源中的字符串。 |

## Padding

内边距类型，用于描述组件不同方向的内边距。

  | 名称     | 类型     | 必填 | 说明                    |
  | ------- | ------   | ---- |------------------------ |
  | top     | Length   |  否  | 组件内元素距组件顶部的尺寸。   |
  | right   | Length   |  否  | 组件内元素距组件右边界的尺寸。 |
  | bottom  | Length   |  否  | 组件内元素距组件底部的尺寸。   |
  | left    | Length   |  否  | 组件内元素距组件左边界的尺寸。 |

## Margin

外边距类型，用于描述组件不同方向的外边距。

  | 名称     | 类型     | 必填 | 说明                    |
  | ------- | ------   | ---- |------------------------ |
  | top     | Length   |  否  | 组件外元素距组件顶部的尺寸。   |
  | right   | Length   |  否  | 组件外元素距组件右边界的尺寸。 |
  | bottom  | Length   |  否  | 组件外元素距组件底部的尺寸。   |
  | left    | Length   |  否  | 组件外元素距组件左边界的尺寸。 |

## EdgeWidths<sup>9+</sup>

边框宽度类型，用于描述组件边框不同方向的宽度。

  | 名称     | 类型     | 必填 | 说明                 |
  | ------- | ------   | ---- |--------------------- |
  | top     | Length   |  否  | 组件上边框宽度。      |
  | right   | Length   |  否  | 组件右边框宽度。      |
  | bottom  | Length   |  否  | 组件下边框宽度。      |
  | left    | Length   |  否  | 组件左边框宽度。      |

## BorderRadiuses<sup>9+</sup>

圆角类型，用于描述组件边框圆角半径。

  | 名称        | 类型     | 必填 | 说明                 |
  | ----------- | ------  | ---- |--------------------- |
  | topLeft     | Length   |  否  | 组件左上角圆角半径。      |
  | topRight    | Length   |  否  | 组件右上角圆角半径。      |
  | bottomLeft  | Length   |  否  | 组件左下角圆角半径。      |
  | bottomRight | Length   |  否  | 组件右下角圆角半径。      |

## EdgeColors<sup>9+</sup>

边框颜色，用于描述组件边框四条边的颜色。

  | 名称     | 类型            | 必填 | 说明                 |
  | ------- | --------------- | ---- |--------------------- |
  | top     | ResourceColor   |  否  | 组件上边框颜色。      |
  | right   | ResourceColor   |  否  | 组件右边框颜色。      |
  | bottom  | ResourceColor   |  否  | 组件下边框颜色。      |
  | left    | ResourceColor   |  否  | 组件左边框颜色。      |

## EdgeStyles<sup>9+</sup>

边框样式，用于描述组件边框四条边的样式。

  | 名称     | 类型          | 必填 | 说明                 |
  | ------- | ------------- | ---- |--------------------- |
  | top     | BorderStyle   |  否  | 组件上边框样式。      |
  | right   | BorderStyle   |  否  | 组件右边框样式。      |
  | bottom  | BorderStyle   |  否  | 组件下边框样式。      |
  | left    | BorderStyle   |  否  | 组件左边框样式。      |


## Offset

相对布局完成位置坐标偏移量。

  | 名称     | 类型     | 必填 | 说明                 |
  | -------- | ------  | ---- |--------------------- |
  | dx       | Length   |  是  | 水平方向偏移量。      |
  | dy       | Length   |  是  | 竖直方向偏移量。      |

## ResourceColor<sup>8+</sup>

颜色类型，用于描述资源颜色类型。

| 类型     | 说明                    |
| -------- | ----------------------- |
| [Color](../reference/arkui-ts/ts-appendix-enums.md#color)    | 颜色枚举值。             |
| number   | HEX格式颜色。            |
| string   | rgb或者rgba格式颜色。     |
| Resource | 使用引入资源的方式，引入系统资源或者应用资源中的颜色。 |

## LengthConstrain

长度约束，用于对组件最大、最小长度做限制。

  | 名称      | 类型     | 必填 | 说明            |
  | --------- | ------  | ---- |---------------- |
  | minLength | Length   |  是  | 组件最小长度。   |
  | maxLength | Length   |  是  | 组件最大长度。   |


## Font

设置文本样式。

| 名称   | 类型                           | 必填 | 说明                                                         |
| ------ | ------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Length](#length)       | 否   | 设置文本尺寸，Length为number类型时，使用fp单位。             |
| weight | [FontWeight](../reference/arkui-ts/ts-appendix-enums.md#fontweight) \| number \| string                          | 否   | 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。 |
| family | string \| [Resource](#resource) | 否   | 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。 |
| style  | [FontStyle](../reference/arkui-ts/ts-appendix-enums.md#fontstyle)       | 否   | 设置文本的字体样式。                          |

## Area<sup>8+</sup>

区域类型，用于存储元素所占区域信息

| 名称           | 类型      | 说明                                              |
| -------------- | -------- | ------------------------------------------------- |
| width          | [Length](#length)    | 目标元素的宽度，作为返回值时，类型为number，单位vp。  |
| height         | [Length](#length)    | 目标元素的高度，作为返回值时，类型为number，单位vp。  |
| position       | [Position](#position8) | 目标元素左上角相对父元素左上角的位置。                |
| globalPosition | [Position](#position8) | 目标元素左上角相对页面左上角的位置。                  |


## Position<sup>8+</sup>

位置类型，用于表示一个坐标点。

| 名称   | 类型    | 必填 | 说明                                        |
| ----- | ------- | ---- | ------------------------------------------- |
| x     | Length  | 否   | x轴坐标，作为返回值时，类型为number，单位vp。   |
| y     | Length  | 否   | y轴坐标，作为返回值时，类型为number，单位vp。   |

## ConstraintSizeOptions

设置约束尺寸，组件布局时，进行尺寸范围限制。

| 名称      | 类型      | 必填  | 说明           |
| --------- | -------- | ---- | -------------- |
| minWidth  | Length   |  否  | 元素最小宽度。  |
| maxWidth  | Length   |  否  | 元素最大宽度。  |
| minHeight | Length   |  否  | 元素最小高度。  |
| maxHeight | Length   |  否  | 元素最大高度。  |

## SizeOptions

设置宽高尺寸。

| 名称    | 类型      | 必填 | 说明            |
| ------- | -------- | ---- | -------------- |
| width   | Length   |  否  | 元素宽度。      |
| height  | Length   |  否  | 元素高度。      |


## BorderOptions

边框属性集合，用于描述边框相关信息。

| 名称   | 类型                     | 必填  | 说明       |
| ------ | ----------------------- | ---- | ----------- |
| width  | Length  \| EdgeWidths<sup>9+</sup>  |  否  | 边框宽度。   |
| color  | ResourceColor \| EdgeColors<sup>9+</sup> |  否  | 边框颜色。   |
| radius | Length \| BorderRadiuses<sup>9+</sup>  |  否  | 边框圆角半径。   |
| style  | [BorderStyle](../reference/arkui-ts/ts-appendix-enums.md#borderstyle)  \| EdgeStyles<sup>9+</sup> |  否  | 边框样式。   |

## ColorFilter<sup>9+</sup>

创建具有4*5矩阵的颜色过滤器。

| 名称        | 类型      | 必填   | 描述                                                         |
| ----------- | -------- | ------ | --------------------------------------------------------------- |
| constructor | number[] | 是     | 创建具有4*5矩阵的颜色过滤器, 入参为[m*n]位于m行和n列中矩阵值, 矩阵是行优先的。  |


## CustomBuilder<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称          | 类型定义               | 描述                                                         |
| ------------- | ---------------------- | ------------------------------------------------------------ |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | 这种方法类型必须使用@Builder装饰器修饰。具体用法见[@Builder](ts-component-based-builder.md)。 |

