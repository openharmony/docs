# Gauge

The **\<Gauge>** component is used to display data in a ring chart.


>  **NOTE**
>
>  This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Not supported


## APIs

Gauge(options:{value: number, min?: number, max?: number})

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Current data value.|
| min | number | No| Minimum value of the current data segment.<br>Default value: **0**|
| max | number | No| Maximum value of the current data segment.<br>Default value: **100**|

## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| value | number | Value of the chart.<br>Default value: **0**|
| startAngle | number | Start angle of the chart. The value 0 indicates 0 degrees, and a positive value indicates the clockwise direction.<br>Default value: **-150**|
| endAngle | number | End angle of the chart. The value 0 indicates 0 degrees, and a positive value indicates the clockwise direction.<br>Default value: **150**|
| colors | Array&lt;ColorStop&gt; | Colors of the chart. Colors can be set for individual segments.|
| strokeWidth | [Length](ts-types.md#length) | Stroke width of the chart.|

## ColorStop

Describes a gradient stop.

| Name     | Type            | Description                                                        |
| --------- | -------------------- | ------------------------------------------------------------ |
| ColorStop | [[ResourceColor](ts-types.md#resourcecolor8), number] | Type of the gradient stop. The first parameter specifies the color, and the second parameter specifies the offset, which ranges from 0 to 1.|


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
