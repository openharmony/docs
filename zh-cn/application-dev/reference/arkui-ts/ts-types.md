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
| [Resource](#resource) | 使用引入资源的方式，引入系统资源或者应用资源中的尺寸。           |

## ResourceStr<sup>8+</sup>

字符串类型，用于描述字符串入参可以使用的类型。

| 类型     | 说明                                                 |
| -------- | --------------------------------------------------- |
| string   | 字符串类型。                                         |
| [Resource](#resource) | 使用引入资源的方式，引入系统资源或者应用资源中的字符串。 |

## Padding

内边距类型，用于描述组件不同方向的内边距。

  | 名称     | 类型     | 必填 | 说明                    |
  | ------- | ------   | ---- |------------------------ |
  | top     | [Length](#length)   |  否  | 组件内元素距组件顶部的尺寸。   |
  | right   | [Length](#length)   |  否  | 组件内元素距组件右边界的尺寸。 |
  | bottom  | [Length](#length)   |  否  | 组件内元素距组件底部的尺寸。   |
  | left    | [Length](#length)   |  否  | 组件内元素距组件左边界的尺寸。 |

## Margin

外边距类型，用于描述组件不同方向的外边距。

  | 名称     | 类型     | 必填 | 说明                    |
  | ------- | ------   | ---- |------------------------ |
  | top     | [Length](#length)   |  否  | 组件外元素距组件顶部的尺寸。   |
  | right   | [Length](#length)   |  否  | 组件外元素距组件右边界的尺寸。 |
  | bottom  | [Length](#length)   |  否  | 组件外元素距组件底部的尺寸。   |
  | left    | [Length](#length)   |  否  | 组件外元素距组件左边界的尺寸。 |

## Offset

相对布局完成位置坐标偏移量。

  | 名称     | 类型     | 必填 | 说明                 |
  | -------- | ------  | ---- |--------------------- |
  | dx       | [Length](#length)   |  是  | 水平方向偏移量。      |
  | dy       | [Length](#length)   |  是  | 竖直方向偏移量。      |

## ResourceColor<sup>8+</sup>

颜色类型，用于描述资源颜色类型。

| 类型     | 说明                    |
| -------- | ----------------------- |
| [Color](ts-appendix-enums.md#color)    | 颜色枚举值。             |
| number   | HEX格式颜色。            |
| string   | rgb或者rgba格式颜色。     |
| [Resource](#resource) | 使用引入资源的方式，引入系统资源或者应用资源中的颜色。 |

## Font

设置文本样式。

| 名称   | 类型                           | 必填 | 说明                                                         |
| ------ | ------------------------------ | ---- | ------------------------------------------------------------ |
| size   | [Length](#length)       | 否   | 设置文本尺寸，Length为number类型时，使用fp单位。             |
| weight | [FontWeight](ts-appendix-enums.md#fontweight) \| number \| string                          | 否   | 设置文本的字体粗细，number类型取值[100, 900]，取值间隔为100，默认为400，取值越大，字体越粗。 |
| family | string \| [Resource](#resource) | 否   | 设置文本的字体列表。使用多个字体，使用','进行分割，优先级按顺序生效。例如：'Arial, sans-serif'。 |
| style  | [FontStyle](ts-appendix-enums.md#fontstyle)       | 否   | 设置文本的字体样式。                          |

## Area<sup>8+</sup>

区域类型，用于存储元素所占区域信息

| 名称           | 类型      | 必填  | 说明                                              |
| -------------- | -------- | ----- |------------------------------------------------- |
| width          | [Length](#length)    |  是   |目标元素的宽度，作为返回值时，类型为number，单位vp。  |
| height         | [Length](#length)    |  是   |目标元素的高度，作为返回值时，类型为number，单位vp。  |
| position       | [Position](#position8) |  是   |目标元素左上角相对父元素左上角的位置。                |
| globalPosition | [Position](#position8) |  是   |目标元素左上角相对页面左上角的位置。                  |


## Position<sup>8+</sup>

位置类型，用于表示一个坐标点。

| 名称   | 类型    | 必填 | 说明                                        |
| ----- | ------- | ---- | ------------------------------------------- |
| x     | [Length](#length)  | 否   | x轴坐标，作为返回值时，类型为number，单位vp。   |
| y     | [Length](#length)  | 否   | y轴坐标，作为返回值时，类型为number，单位vp。   |

## ConstraintSizeOptions

设置约束尺寸，组件布局时，进行尺寸范围限制。

| 名称      | 类型      | 必填  | 说明           |
| --------- | -------- | ---- | -------------- |
| minWidth  | [Length](#length)   |  否  | 元素最小宽度。  |
| maxWidth  | [Length](#length)   |  否  | 元素最大宽度。  |
| minHeight | [Length](#length)   |  否  | 元素最小高度。  |
| maxHeight | [Length](#length)   |  否  | 元素最大高度。  |

## SizeOptions

设置宽高尺寸。

| 名称    | 类型      | 必填 | 说明            |
| ------- | -------- | ---- | -------------- |
| width   | [Length](#length)   |  否  | 元素宽度。      |
| height  | [Length](#length)   |  否  | 元素高度。      |


## BorderOptions

边框属性集合，用于描述边框相关信息。

| 名称   | 类型           | 必填  | 说明       |
| ------ | ------------- | ---- | ----------- |
| width  | [Length](#length)        |  否  | 边框宽度。   |
| color  | [ResourceColor](#resourcecolor8) |  否  | 边框颜色。   |
| radius | [Length](#length)        |  否  | 边框圆角半径。   |
| style  | [BorderStyle](ts-appendix-enums.md#borderstyle)   |  否  | 边框样式。   |

## CustomBuilder<sup>8+</sup>

组件属性方法参数可使用CustomBuilder类型来自定义UI描述。

| 名称          | 类型定义               | 描述                                                         |
| ------------- | ---------------------- | ------------------------------------------------------------ |
| CustomBuilder | ()&nbsp;=&gt;&nbsp;any | 这种方法类型必须使用@Builder装饰器修饰。具体用法见[@Builder](../../ui/ts-component-based-builder.md)。 |

