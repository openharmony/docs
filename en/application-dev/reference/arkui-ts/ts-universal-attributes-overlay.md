# Overlay

You can set overlay text for a component.

>  **NOTE**
>
> The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name      | Type                         | Description                      |
| ------- | ----------------------------- | ------------------------- |
| overlay | value: string,<br/>options?: {<br/>align?: [Alignment](ts-appendix-enums.md#alignment), <br/>offset?: {x?: number, y?: number}<br/>} | Overlay added to the component. The overlay has the same layout as the component.<br>Default value:<br>{<br>align: Alignment.Center,<br>offset: {0, 0}<br>} |


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
            .overlay("Winter is a beautiful season, especially when it snows.", { align: Alignment.Bottom, offset: { x: 0, y: -15 } })
        }.border({ color: Color.Black, width: 2 })
      }.width('100%')
    }.padding({ top: 20 })
  }
}
```

![en-us_image_0000001212058472](figures/en-us_image_0000001212058472.png)
