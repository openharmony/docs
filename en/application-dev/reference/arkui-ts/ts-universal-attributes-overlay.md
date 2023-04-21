# Overlay

You can set overlay text for a component.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name| Type| Default Value| Description|
| -------- | -------- | -------- | -------- |
| overlay | value: string,<br>options?: {<br>align?: [Alignment](ts-appendix-enums.md#alignment), <br>offset?: {x?: number, y?: number}<br>} | {<br>align: Alignment.Center,<br>offset: {0, 0}<br>} | Overlay added to the component.<br> **value**: mask text.<br>**options**: text positioning. **align** indicates the location of the text relative to the component. **[offset](ts-universal-attributes-location.md)** indicates the offset of the text relative to the upper left corner of itself. By default, the text is in the upper left corner of the component.<br>If both **align** and **offset** are set, the text is first positioned relative to the component, and then offset relative to the upper left corner of itself.<br>Since API version 9, this API is supported in ArkTS widgets.|

## Example

```ts
// xxx.ets
@Entry
@Component
struct OverlayExample {
  build() {
    Column() {
      Column() {
        Text('floating layer')
          .fontSize(12).fontColor(0xCCCCCC).maxLines(1)
        Column() {
          Image($r('app.media.img'))
            .width(240).height(240)
            .overlay("Winter is a beautiful season, especially when it snows.", {
              align: Alignment.Bottom,
              offset: { x: 0, y: -15 }
            })
        }.border({ color: Color.Black, width: 2 })
      }.width('100%')
    }.padding({ top: 20 })
  }
}
```

![en-us_image_0000001212058472](figures/en-us_image_0000001212058472.png)
