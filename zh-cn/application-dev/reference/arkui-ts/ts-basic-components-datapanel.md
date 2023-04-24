# DataPanel

数据面板组件，用于将多个数据占比情况使用占比图进行展示。

>  **说明：**
>
> 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。




## 子组件

无


## 接口

DataPanel(options:{values: number[], max?: number, type?: DataPanelType})

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数:**

| 参数名            | 参数类型   | 必填  | 参数描述 |
| ----------------- | -------- | ----- | -------- |
| values            | number[]   | 是    | 数据值列表，最多包含9个数据，大于9个数据则取前9个数据。若数据值小于0则置为0。 |
| max               | number     | 否    |   -&nbsp;max大于0，表示数据的最大值。<br/>-&nbsp;max小于等于0，max等于value数组各项的和，按比例显示。<br/>默认值：100 |
| type<sup>8+</sup> | [DataPanelType](#datapaneltype枚举说明) | 否 | 数据面板的类型（不支持动态修改）。<br/>默认值：DataPanelType.Circle |


## DataPanelType枚举说明

从API version 9开始，该接口支持在ArkTS卡片中使用。

| 名称 | 描述 |
| -------| ------------ |
| Line   | 线型数据面板。 |
| Circle | 环形数据面板。 |


## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：


| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| closeEffect | boolean | 是 | 关闭数据占比图表旋转动效。<br/>默认值：false。|
| valueColors<sup>10+</sup>   | Array<[ResourceColor](ts-types.md#resourcecolor) \| [LinearGradient](#lineargradient10)> | 是 | 各数据段颜色，ResourceColor为纯色，LinearGradient为渐变色。|
| trackBackgroundColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | 是 | 底板颜色。|
| strokeWidth<sup>10+</sup> | [Length](ts-types.md#Length) | 是 | 圆环粗细。 |
| trackShadow<sup>10+</sup> | [DataPanelShadowOption](#datapanelshadowoption10) | 是 | 投影样式，不设置为不开启投影。|


## DataPanelShadowOption<sup>10+</sup>
| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| radius | number \| [Resource](ts-types.md#resource类型) | 否 | 阴影模糊半径。 若数据值小于等于0则置为默认值。<br/>默认值：5vp。 |
| colors | Array<[ResourceColor](ts-types.md#resourcecolor) \| [LinearGradient](#lineargradient10)> | 否 | 各数据段阴影的颜色。 <br/>默认值：与valueColors值相同。 |
| offsetX | number \| [Resource](ts-types.md#resource类型) | 否 | X轴的偏移量。 <br/>默认值：5vp。 |
| offsetY | number \| [Resource](ts-types.md#resource类型) | 否 | Y轴的偏移量。 <br/>默认值：5vp。 |

## LinearGradient<sup>10+</sup>

线性渐变颜色描述。

LinearGradient(colorStops: ColorStop[])

| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| colorStops | [ColorStop](#colorstop10)[] | 是 | 存储渐变颜色和渐变点。|


## ColorStop<sup>10+</sup>

颜色断点类型，用于描述渐进色颜色断点。

| 名称          | 参数类型 | 必填 | 描述 |
| ------------- | ------- | ---- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | 是 | 颜色值。|
| offset | [Length](ts-types.md#Length) | 是 | 渐变色断点（0~1之间的比例值，若数据值小于0则置为0，若数据值大于1则置为1）。|



## 示例

```ts
// xxx.ets
@Entry
@Component
struct DataPanelExample {
  public valueArr: number[] = [10, 10, 10, 10, 10, 10, 10, 10, 10]

  build() {
    Column({ space: 5 }) {
      Row() {
        Stack() {
          DataPanel({ values: [25], max: 100, type: DataPanelType.Circle }).width(168).height(168)
          Column() {
            Text('30').fontSize(35).fontColor('#182431')
            Text('1.0.0').fontSize(9.33).lineHeight(12.83).fontWeight(500).opacity(0.6)
          }

          Text('%')
            .fontSize(9.33)
            .lineHeight(12.83)
            .fontWeight(500)
            .opacity(0.6)
            .position({ x: 104.42, y: 78.17 })
        }.margin({ right: 44 })

        Stack() {
          DataPanel({ values: [50, 12, 8, 5], max: 100, type: DataPanelType.Circle }).width(168).height(168)
          Column() {
            Text('75').fontSize(35).fontColor('#182431')
            Text('已使用98GB/128GB').fontSize(8.17).lineHeight(11.08).fontWeight(500).opacity(0.6)
          }

          Text('%')
            .fontSize(9.33)
            .lineHeight(12.83)
            .fontWeight(500)
            .opacity(0.6)
            .position({ x: 104.42, y: 78.17 })
        }
      }.margin({ bottom: 59 })

      DataPanel({ values: this.valueArr, max: 100, type: DataPanelType.Line }).width(300).height(10)
    }.width('100%').margin({ top: 5 })
  }
}
```

![dataPanel](figures/dataPanel.PNG)
