# Gauge

数据量规图表组件，用于将数据展示为环形图表。


>  **说明：**
>
>  该组件从API Version 8开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无


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
| colors | Array&lt;[ColorStop](#colorstop)&gt; | 设置量规图的颜色，支持分段颜色设置。<br/>默认值：Color.Black<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| strokeWidth | Length | 设置环形量规图的环形厚度。<br/>默认值：4<br/>单位：vp<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。<br/>**说明：** <br/>设置小于0的值时，按默认值显示。<br/>不支持百分比。 |

## ColorStop

颜色断点类型，用于描述渐进色颜色断点。

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称      | 类型定义             | 描述                                                         |
| --------- | -------------------- | ------------------------------------------------------------ |
| ColorStop | [[ResourceColor](ts-types.md#resourcecolor),&nbsp;number] | 描述渐进色颜色断点类型，第一个参数为颜色值，若设置为非颜色类型，则置为黑色。第二个参数为颜色所占比重，若设置为负数或是非数值类型，则将比重置为0。 |


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
