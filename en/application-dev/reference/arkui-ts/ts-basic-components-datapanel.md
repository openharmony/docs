# DataPanel

The **\<DataPanel>** component displays proportions in a chart.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.




## Child Components

Not supported


## APIs

DataPanel(options:{values: number[], max?: number, type?: DataPanelType})

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name           | Type  | Mandatory | Description|
| ----------------- | -------- | ----- | -------- |
| values            | number[]   | Yes   | Data value list. A maximum of nine values are supported. If more than nine values are set, only the first nine ones are used. A value less than 0 evaluates to the value **0**. |
| max               | number     | No   |   - When set to a value greater than 0, this parameter indicates the maximum value in the **values** list.<br>- When set to a value equal to or smaller than 0, this parameter indicates the sum of values in the **values** list. The values are displayed in proportion.<br>Default value: **100**|
| type<sup>8+</sup> | [DataPanelType](#datapaneltype) | No| Type of the data panel (dynamic modification is not supported).<br>Default value: **DataPanelType.Circle**|


## DataPanelType

Since API version 9, this API is supported in ArkTS widgets.

| Name| Description|
| -------| ------------ |
| Line   | Line data panel.|
| Circle | Circle data panel.|


## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.


| Name         | Type| Mandatory| Description|
| ------------- | ------- | ---- | -------- |
| closeEffect | boolean | Yes| Whether to disable the rotation effect for the component.<br>Default value: **false**.|
| valueColors<sup>10+</sup>   | Array<[ResourceColor](ts-types.md#resourcecolor) \| [LinearGradient](#lineargradient10)> | Yes| Array of data segment colors. A value of the **ResourceColor** type indicates a solid color, and A value of the **LinearGradient** type indicates a color gradient.|
| trackBackgroundColor<sup>10+</sup> | [ResourceColor](ts-types.md#resourcecolor) | Yes| Background color.|
| strokeWidth<sup>10+</sup> | [Length](ts-types.md#Length) | Yes| Stroke width of the border.|
| trackShadow<sup>10+</sup> | [DataPanelShadowOption](#datapanelshadowoption10) | Yes| Shadow style. If this attribute is not set, the shadow effect is disabled.|


## DataPanelShadowOption<sup>10+</sup>
| Name         | Type| Mandatory| Description|
| ------------- | ------- | ---- | -------- |
| radius | number \| [Resource](ts-types.md#resource)| No| Shadow blur radius.<br>Default value: **5vp**|
| colors | Array<[ResourceColor](ts-types.md#resourcecolor) \| [LinearGradient](#lineargradient10)> | No| Array of shadow colors for data segments.<br>Default value: same as the value of **valueColors**.|
| offsetX | number \| [Resource](ts-types.md#resource)| No| Offset on the x-axis.<br>Default value: **5vp**|
| offsetY | number \| [Resource](ts-types.md#resource)| No| Offset on the y-axis.<br>Default value: **5vp**|

## LinearGradient<sup>10+</sup>

Describes the linear gradient.

LinearGradient(colorStops: ColorStop[])

| Name         | Type| Mandatory| Description|
| ------------- | ------- | ---- | -------- |
| colorStops | [ColorStop](#colorstop10)[] | Yes| Gradient colors and color stops.|


## ColorStop<sup>10+</sup>

Describes the gradient color stop.

| Name         | Type| Mandatory| Description|
| ------------- | ------- | ---- | -------- |
| color | [ResourceColor](ts-types.md#resourcecolor) | Yes| Color value.|
| offset | [Length](ts-types.md#Length) | Yes| Gradient color stop (proportion value between 0 and 1).|



## Example

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
            Text('Used: 98 GB/128 GB') .fontSize(8.17).lineHeight(11.08).fontWeight(500).opacity(0.6)
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
