# DataPanel


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;DataPanel&gt;** component displays proportions in a chart.


## Required Permissions

None


## Child Components

None


## APIs

DataPanel(value:{values: number[], max?: number, type?: DataPanelType})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | values | number[] | Yes | - | Value&nbsp;list.&nbsp;A&nbsp;maximum&nbsp;of&nbsp;nine&nbsp;values&nbsp;are&nbsp;supported. | 
  | max | number | No | 100 | -&nbsp;When&nbsp;set&nbsp;to&nbsp;a&nbsp;value&nbsp;greater&nbsp;than&nbsp;0,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;maximum&nbsp;value&nbsp;in&nbsp;the&nbsp;**values**&nbsp;list.<br/>-&nbsp;When&nbsp;set&nbsp;to&nbsp;a&nbsp;value&nbsp;equal&nbsp;to&nbsp;or&nbsp;smaller&nbsp;than&nbsp;0,&nbsp;this&nbsp;parameter&nbsp;indicates&nbsp;the&nbsp;sum&nbsp;of&nbsp;values&nbsp;in&nbsp;the&nbsp;**values**&nbsp;list.&nbsp;The&nbsp;values&nbsp;are&nbsp;displayed&nbsp;in&nbsp;proportion. | 
  | type<sup>8+</sup> | DataPanelType | No | DataPanelType.Circle | Type&nbsp;of&nbsp;the&nbsp;data&nbsp;panel. | 


- DataPanelType enums
    | Name | Description | 
  | -------- | -------- |
  | Line | Line&nbsp;data&nbsp;panel. | 
  | Circle | Circle&nbsp;data&nbsp;panel. |


## Example


```
@Entry
@Component
struct DataPanelExample {
  public values1: number[] = [10, 10, 10, 10, 10, 10, 10, 10, 10]

  build() {
    Column({ space: 5 }) {
      Text('Circle').fontSize(9).fontColor(0xCCCCCC).margin({ top: 20, right: '80%' })
      DataPanel({ values: this.values1, max: 100, type: DataPanelType.Circle }).width(200).height(200)

      Text('Line').fontSize(9).fontColor(0xCCCCCC).margin({ bottom: 20, right: '80%' })
      DataPanel({ values: this.values1, max: 100, type: DataPanelType.Line }).width(300).height(10)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001211898476](figures/en-us_image_0000001211898476.jpg)
