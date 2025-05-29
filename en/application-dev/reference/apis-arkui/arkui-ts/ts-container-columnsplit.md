# ColumnSplit

The **ColumnSplit** component lays out child components vertically and inserts a horizontal divider between every two child components.

>  **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
## Child Components

Supported

This component limits the height of its child components through dividers. During initialization, the divider positions are calculated based on the height of its child components. After initialization, changes to the height of the child components do not take effect. Still, the space occupied by the child components can be changed by dragging the dividers between them.

After initialization, if, due to dynamic changes to the [margin](ts-universal-attributes-size.md#margin), [border](ts-universal-attributes-border.md#border), or [padding](ts-universal-attributes-size.md#padding) attributes, the size of the child components is greater than the allowable distance between adjacent dividers, dividers cannot be dragged to adjust the height of the child components.
## APIs

ColumnSplit()

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Attributes

### resizeable

resizeable(value: boolean)

Sets whether the divider can be dragged.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type   | Mandatory| Description                                |
| ------ | ------- | ---- | ------------------------------------ |
| value  | boolean | Yes  | Whether the divider can be dragged.<br>Default value: **false**|

### divider<sup>10+</sup>

divider(value: ColumnSplitDividerStyle | null)

Margin of the divider.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ColumnSplitDividerStyle](#columnsplitdividerstyle10) \| null | Yes  | Margin of the divider.<br>Default value: **null**, indicating that the top and bottom margins of the divider are 0. **DividerStyle**: distance between the divider and the child component above or below it.|

## ColumnSplitDividerStyle<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       | Type     | Mandatory| Description                      |
| ----------- | ------------- | ---- |--------------------------|
| startMargin | [Dimension](ts-types.md#dimension10)       | No  | Distance between the divider and the child component above it.<br>Default value: **0**|
| endMargin   | [Dimension](ts-types.md#dimension10)       | No  | Distance between the divider and the child component below it.<br>Default value: **0**|

>  **NOTE**
>
> Similar to [RowSplit](ts-container-rowsplit.md#rowsplit), the divider of **ColumnSplit** can change the height of the upper and lower child components, but only to the extent that the resultant height falls within the maximum and minimum heights of the child components.
>
> Universal attributes such as [clip](ts-universal-attributes-sharp-clipping.md#clip12) and [margin](ts-universal-attributes-size.md#margin) are supported. If **clip** is not set, the default value **true** is used.


## Example

This example demonstrates the basic usage of **ColumnSplit**, which allows you to create draggable, vertically laid-out child components.

```ts
// xxx.ets
@Entry
@Component
struct ColumnSplitExample {
  build() {
    Column(){
      Text('The secant line can be dragged').fontSize(9).fontColor(0xCCCCCC).width('90%')
      ColumnSplit() {
        Text('1').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('2').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('3').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
        Text('4').width('100%').height(50).backgroundColor(0xD2B48C).textAlign(TextAlign.Center)
        Text('5').width('100%').height(50).backgroundColor(0xF5DEB3).textAlign(TextAlign.Center)
      }
      .borderWidth(1)
      .resizeable(true) // The divider can be dragged.
      .width('90%').height('60%')
    }.width('100%')
  }
}
```

![en-us_image_0000001219982708](figures/en-us_image_0000001219982708.gif)
