# Gauge


The **\<Gauge>** component is used to display data in a ring chart.

>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Child Components

Not supported


## APIs

Gauge(options:{value: number, min?: number, max?: number})

- Parameters
    | Name| Type| Mandatory| Default Value| Description|
  | -------- | -------- | -------- | -------- | -------- |
  | value | number | Yes| - | Current data value.|
  | min | number | No| 0 | Minimum value of the current data segment.|
  | max | number | No| 100 | Maximum value of the current data segment.|


## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| value | number | 0 | Value of the chart.|
| startAngle | number | -150 | Start angle of the chart. The value 0 indicates 0 degrees, and a positive value indicates the clockwise direction.|
| endAngle | number | 150 | End angle of the chart. The value 0 indicates 0 degrees, and a positive value indicates the clockwise direction.|
| colors | Array&lt;ColorStop&gt; | - | Colors of the chart. Colors can be set for individual segments.|
| strokeWidth | Length | - | Stroke width of the chart.|

## ColorStop

Describes a gradient stop.

| Name     | Type            | Description                                                        |
| --------- | -------------------- | ------------------------------------------------------------ |
| ColorStop | [[ResourceColor](../../ui/ts-types.md#resourcecolor8), number] | Type of the gradient stop. The first parameter specifies the color, and the second parameter specifies the offset, which ranges from 0 to 1.|


## Example


```ts
// xxx.ets
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
