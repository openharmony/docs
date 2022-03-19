# Gauge


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


Data gauge chart widget, which is used to display data in a ring chart.


## Required Permissions

None


## Child Component

N/A


## APIs

Gauge(value:{value: number, min?: number, max?: number})

- Parameter
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes | - | Current&nbsp;data&nbsp;value. | 
  | min | number | No | 0 | Minimum&nbsp;value&nbsp;of&nbsp;the&nbsp;current&nbsp;data&nbsp;segment. | 
  | max | number | No | 100 | Maximum&nbsp;value&nbsp;of&nbsp;the&nbsp;current&nbsp;data&nbsp;segment. | 


## Attributes

  | Name | Type | Default&nbsp;Value | Description | 
| -------- | -------- | -------- | -------- |
| value | number | 0 | Sets&nbsp;the&nbsp;value&nbsp;of&nbsp;the&nbsp;current&nbsp;data&nbsp;chart. | 
| startAngle | Angle | -150 | Set&nbsp;the&nbsp;start&nbsp;angle.&nbsp;Clock&nbsp;0&nbsp;indicates&nbsp;0&nbsp;degree,&nbsp;and&nbsp;the&nbsp;clockwise&nbsp;direction&nbsp;indicates&nbsp;the&nbsp;positive&nbsp;angle. | 
| endAngle | Angle | 150 | Sets&nbsp;the&nbsp;end&nbsp;angle&nbsp;position.&nbsp;The&nbsp;clock&nbsp;0&nbsp;point&nbsp;is&nbsp;0&nbsp;degree,&nbsp;and&nbsp;the&nbsp;clockwise&nbsp;direction&nbsp;is&nbsp;the&nbsp;positive&nbsp;angle. | 
| colors | Color&nbsp;\|&nbsp;Array&lt;ColorStop&gt; | - | Set&nbsp;the&nbsp;color&nbsp;of&nbsp;the&nbsp;chart.&nbsp;You&nbsp;can&nbsp;set&nbsp;the&nbsp;pure&nbsp;color&nbsp;or&nbsp;segmental&nbsp;gradient&nbsp;color. | 
| strokeWidth | Length | - | Sets&nbsp;the&nbsp;ring&nbsp;thickness&nbsp;of&nbsp;a&nbsp;ring&nbsp;chart. | 


## Example


```
@Entry
@Component
struct GaugeExample {
  build() {
    Column() {
      Gauge({ value: 50, min: 0, max: 100 })
        .startAngle(210).endAngle(150)
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1], [0xD94838, 1]])
        .strokeWidth(20)
        .width(200).height(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001174422916](figures/en-us_image_0000001174422916.png)
