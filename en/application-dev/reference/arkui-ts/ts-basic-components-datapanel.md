# DataPanel

The **\<DataPanel>** component displays proportions in a chart.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.




## Child Components

Not supported


## APIs

DataPanel(options:{values: number[], max?: number, type?: DataPanelType})

**Parameters**

| Name           | Type  | Mandatory | Description|
| ----------------- | -------- | ----- | -------- |
| values            | number[]   | Yes   | Data value list. A maximum of nine values are supported. If more than nine values are set, only the first nine ones are used. If the value is less than 0, the value 0 is used.|
| max               | number     | No   |   - When set to a value greater than 0, this parameter indicates the maximum value in the **values** list.<br>- When set to a value equal to or smaller than 0, this parameter indicates the sum of values in the **values** list. The values are displayed in proportion.<br>Default value: **100**|
| type<sup>8+</sup> | [DataPanelType](#datapaneltype) | No| Type of the data panel.<br>Default value: **DataPanelType.Circle**|


## DataPanelType
| Name| Description|
| -------| ------------ |
| Line   | Line data panel.|
| Circle | Circle data panel.|


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
