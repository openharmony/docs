# Overlay


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| overlay | title: string,<br/>options: {<br/>align?: [Alignment](ts-appendix-enums.md#alignment-enums),<br/>offset?: {x: number, y: number}<br/>} | {<br/>align: Alignment.Center,<br/>offset: {0, 0}<br/>} | Mask added to the component. The mask has the same layout as the component. |


## Example


```
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
