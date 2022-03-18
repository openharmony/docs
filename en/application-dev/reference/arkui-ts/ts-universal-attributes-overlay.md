# Overlay


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

None


## Attributes


| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| overlay | title:&nbsp;string,<br/>options:&nbsp;{<br/>align?:&nbsp;[Alignment](ts-appendix-enums.md#alignment-enums),<br/>offset?:&nbsp;{x:&nbsp;number,&nbsp;y:&nbsp;number}<br/>} | {<br/>align:&nbsp;Alignment.Center,<br/>offset:&nbsp;{0,&nbsp;0}<br/>} | Mask&nbsp;added&nbsp;to&nbsp;the&nbsp;component.&nbsp;The&nbsp;mask&nbsp;has&nbsp;the&nbsp;same&nbsp;layout&nbsp;as&nbsp;the&nbsp;component. |


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
