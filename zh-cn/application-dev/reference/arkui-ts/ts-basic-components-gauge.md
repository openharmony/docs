# Gauge

数据量规图表组件，用于将数据展示为环形图表。


>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

可以包含单个子组件。

> **说明：**
>
> 建议使用文本组件构建当前数值文本和辅助文本。
>
> 若子组件宽高为百分比形式，则基准范围为以外圆环做为内切圆的矩形。


## 接口

Gauge(options:{value: number, min?: number, max?: number})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 参数描述 |
| -------- | -------- | -------- | -------- |
| value | number | 是 | 量规图的当前数据值，即图中指针指向位置。用于组件创建时量规图初始值的预置。<br/>**说明：** <br/>value不在min和max范围内时使用min作为默认值。 |
| min | number | 否 | 当前数据段最小值。<br/>默认值：0 |
| max | number | 否 | 当前数据段最大值。<br/>默认值：100<br/>**说明：** <br/>max小于min时使用默认值0和100。<br/>max和min支持负数。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| value | number | 设置量规图的数据值，可用于动态修改量规图的数据值。<br/>默认值：0<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| startAngle | number | 设置起始角度位置，时钟0点为0度，顺时针方向为正角度。<br/>默认值：0<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| endAngle | number | 设置终止角度位置，时钟0点为0度，顺时针方向为正角度。<br/>默认值：360<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| colors | [ResourceColor<sup>11+</sup>](ts-types.md#resourcecolor) \| [LinearGradient<sup>11+</sup>](ts-basic-components-datapanel.md#lineargradient10对象说明) \| Array&lt;[ColorStop](#colorstop)&gt; | 设置量规图的颜色，支持分段颜色设置。<br/>API version 9 默认值：Color.Black<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 <br/>从API version 11开始，该接口使用以下规则：<br/> 参数类型为ResourceColor，则圆环类型为单色环。<br/> 参数类型为LinearGradient，则圆环类型为渐变环。<br/> 参数类型为数组，则圆环类型为分段渐变环。<br/> 分段渐变环最大显示段数为9段，若多于9段，则多于部分不显示。<br/>API version 11默认值：<br>若不传颜色，或者数组为空，无法确定圆环类型及颜色，则圆环颜色为0xFF64BB5C、0xFFF7CE00、0xFFE84026的渐变环。<br/>若传入颜色，但颜色值有误，则该颜色为黑色。 |
| strokeWidth | Length | 设置环形量规图的环形厚度。<br/>默认值：4<br/>单位：vp<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>设置小于0的值时，按默认值显示。<br/>不支持百分比。 |
| description<sup>11+</sup> | [CustomBuilder](ts-types.md#custombuilder8) | 设置说明文本。<br/>**说明：** <br/>@Builder中内由开发者自定义，建议使用文本或者图片。<br/>若自定义部分的宽高为百分比形式，则基准范围为圆环直径的44.4%*25.4%的矩形（图片为28.6%*28.6%），距离圆环底部0vp，左右居中。<br/>设置null则不显示内容。<br/>不设置则依赖是否设置数据最大最小值。<br/>若设置最大最小值或者只设置其中一个，则显示最大最小值。<br/>若未设置最大最小值，则不显示内容。<br/>最大最小值显示在圆环底部，位置不可移动，若圆环开口角度设置不恰当，存在圆环遮挡文字的情况。|
| trackShadow<sup>11+</sup> | [GuageShadowOptions](#guageshadowoptions11对象说明) | 设置阴影样式。<br/>**说明：** <br/>阴影颜色与圆环颜色一致。<br/>设置null为不开启投影。|
| indicator<sup>11+</sup> | [GaugeIndicatorOptions](#gaugeindicatoroptions11对象说明) | 设置指针样式。<br/>**说明：** <br/>设置null则不显示指针。|

## ColorStop

颜色断点类型，用于描述渐进色颜色断点。

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称      | 类型定义             | 描述                                                         |
| --------- | -------------------- | ------------------------------------------------------------ |
| ColorStop | [[ResourceColor](ts-types.md#resourcecolor) \| [LinearGradient<sup>11+</sup>](ts-basic-components-datapanel.md#lineargradient10对象说明),&nbsp;number] | 描述渐进色颜色断点类型，第一个参数为颜色值，若设置为非颜色类型，则置为黑色。第二个参数为颜色所占比重，若设置为负数或是非数值类型，则将比重置为0。 |

## GuageShadowOptions<sup>11+</sup>对象说明
| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| radius | number \| [Resource](ts-types.md#resource类型) | 否 | 投影模糊半径。 <br/>默认值：5<br/>单位：vp <br/>**说明：** <br/>设置小于等于0的值时，按默认值显示。|
| offsetX | number \| [Resource](ts-types.md#resource类型) | 否 | X轴的偏移量。 <br/>默认值：5<br/>单位：vp |
| offsetY | number \| [Resource](ts-types.md#resource类型) | 否 | Y轴的偏移量。 <br/>默认值：5<br/>单位：vp |

## GaugeIndicatorOptions<sup>11+</sup>对象说明
| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| icon | [Resource](ts-types.md#resource类型) | 否 | 图标资源路径。<br/>**说明：** <br/>不配置则使用默认的三角形样式指针。<br/>支持使用svg格式的图标，若使用其他格式，则使用默认的三角形样式指针。 |
| space | [Dimension](ts-types.md#dimension10) | 否 | 指针距离圆环外边的间距。(不支持百分比) <br/>默认值：8<br/>单位：vp <br/>**说明：** <br/> 对于默认的三角形样式指针，间距为黑色三角形到圆环外边的间距。<br/> 若设置值小于0，则使用默认值。<br/>若设置值大于圆环半径，则使用默认值。|

## 示例


```ts
// xxx.ets
@Entry
@Component
struct GaugeExample {
  build() {
    Column({ space: 20 }) {
      // 使用默认的min和max为0-100，角度范围默认0-360，value值设置
      // 参数中设置当前值为75
      Gauge({ value: 75 })
        .width(200).height(200)
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1]])
      
      // 参数设置当前值为75，属性设置值为25，属性设置优先级高
      Gauge({ value: 75 })
        .value(25) // 属性和参数都设置时以属性为准
        .width(200).height(200)
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1]])
      
      // 210--150度环形图表
      Gauge({ value: 30, min: 0, max: 100 })
        .startAngle(210)
        .endAngle(150)
        .colors([[0x317AF7, 0.1], [0x5BA854, 0.2], [0xE08C3A, 0.3], [0x9C554B, 0.4]])
        .strokeWidth(20)
        .width(200)
        .height(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![gauge](figures/gauge-image.png)
