# GridItem

The **\<GridItem>** component provides a single item in a grid.

>  **NOTE**
>
>  This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components

Supported


## APIs

GridItem()


## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| rowStart | number | Start row number of the component.|
| rowEnd | number | End row number of the component.|
| columnStart | number | Start column number of the component.|
| columnEnd | number | End column number of the component.|
| forceRebuild<sup>(deprecated)</sup> | boolean | Whether to re-create the component when it is being built.<br>This API is deprecated since API version 9. Whether to re-create the component is automatically determined based on the component attributes and child component changes. No manual configuration is required.<br>Default value: **false**|
| selectable<sup>8+</sup> | boolean | Whether the current grid item is selectable by the mouse.<br>> **NOTE**<br>> This attribute takes effect only when mouse frame selection is enabled for the parent **\<Grid>** container.<br>Default value: **true**|


## Events

| Name| Description|
| -------- | -------- |
| onSelect(event: (isSelected: boolean) =&gt; void)<sup>8+</sup> | Triggered when the selected state of the grid item changes.<br>**isSelected**: Returns **true** if the grid item is selected by the mouse; returns **false** otherwise.|


## Example

```ts
// xxx.ets
@Entry
@Component
struct GridItemExample {
  @State numbers: string[] = Array.apply(null, { length: 16 }).map(function (item, i) {
    return i.toString()
  })

  build() {
    Column() {
      Grid() {
        GridItem() {
          Text('4')
            .fontSize(16)
            .backgroundColor(0xFAEEE0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.rowStart(1).rowEnd(4)

        ForEach(this.numbers, (item) => {
          GridItem() {
            Text(item)
              .fontSize(16)
              .backgroundColor(0xF9CF93)
              .width('100%')
              .height('100%')
              .textAlign(TextAlign.Center)
          }
        }, item => item)

        GridItem() {
          Text('5')
            .fontSize(16)
            .backgroundColor(0xDBD0C0)
            .width('100%')
            .height('100%')
            .textAlign(TextAlign.Center)
        }.columnStart(1).columnEnd(5)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .width('90%').height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![en-us_image_0000001256858433](figures/en-us_image_0000001256858433.gif)
