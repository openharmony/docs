# Image


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The **&lt;Image&gt;** component is used to render and display images.


## Required Permissions

ohos.permission.INTERNET (using Internet images)


## Child Components

None


## APIs

Image(value: {uri: string | PixelMap})

- Parameters
    | Name | Type | Mandatory | Default&nbsp;Value | Description | 
  | -------- | -------- | -------- | -------- | -------- |
  | uri | string | Yes | - | Image&nbsp;URI.&nbsp;Both&nbsp;local&nbsp;and&nbsp;Internal&nbsp;URIs&nbsp;are&nbsp;supported. | 


## Attributes

| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| alt | string | - | Placeholder&nbsp;image&nbsp;displayed&nbsp;during&nbsp;loading.&nbsp;Both&nbsp;local&nbsp;and&nbsp;Internal&nbsp;URIs&nbsp;are&nbsp;supported. |
| objectFit | ImageFit | ImageFit.Cover | Image&nbsp;scale&nbsp;type. |
| objectRepeat | [ImageRepeat](ts-appendix-enums.md#imagerepeat enums) | ImageRepeat.NoRepeat | Whether&nbsp;the&nbsp;image&nbsp;is&nbsp;repeated.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;-&nbsp;This&nbsp;attribute&nbsp;is&nbsp;not&nbsp;applicable&nbsp;to&nbsp;SVG&nbsp;images. |
| interpolation | ImageInterpolation | ImageInterpolation.None | Interpolation&nbsp;effect&nbsp;of&nbsp;the&nbsp;image.&nbsp;This&nbsp;attribute&nbsp;is&nbsp;valid&nbsp;only&nbsp;when&nbsp;the&nbsp;image&nbsp;is&nbsp;zoomed&nbsp;in.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;-&nbsp;This&nbsp;attribute&nbsp;is&nbsp;not&nbsp;applicable&nbsp;to&nbsp;SVG&nbsp;images.<br/>>&nbsp;<br/>>&nbsp;-&nbsp;This&nbsp;attribute&nbsp;is&nbsp;not&nbsp;applicable&nbsp;to&nbsp;a&nbsp;**PixelMap**&nbsp;object. |
| renderMode | ImageRenderMode | ImageRenderMode.Original | Rendering&nbsp;mode&nbsp;of&nbsp;the&nbsp;image.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;-&nbsp;This&nbsp;attribute&nbsp;is&nbsp;not&nbsp;applicable&nbsp;to&nbsp;SVG&nbsp;images. |
| sourceSize | {<br/>width:&nbsp;number,<br/>height:&nbsp;number<br/>} | - | Decoding&nbsp;size&nbsp;of&nbsp;the&nbsp;image.&nbsp;The&nbsp;original&nbsp;image&nbsp;is&nbsp;decoded&nbsp;into&nbsp;an&nbsp;image&nbsp;of&nbsp;the&nbsp;specified&nbsp;size.&nbsp;If&nbsp;the&nbsp;value&nbsp;is&nbsp;of&nbsp;the&nbsp;number&nbsp;type,&nbsp;the&nbsp;unit&nbsp;px&nbsp;is&nbsp;used.<br/>>&nbsp;![icon-note.gif](public_sys-resources/icon-note.gif)&nbsp;**NOTE：**<br/>>&nbsp;This&nbsp;attribute&nbsp;is&nbsp;not&nbsp;applicable&nbsp;to&nbsp;a&nbsp;**PixelMap**&nbsp;object. |
| syncLoad<sup>8+</sup> | boolean | false | Whether&nbsp;to&nbsp;load&nbsp;images&nbsp;synchronously.&nbsp;By&nbsp;default,&nbsp;images&nbsp;are&nbsp;loaded&nbsp;asynchronously.&nbsp;During&nbsp;synchronous&nbsp;loading,&nbsp;the&nbsp;UI&nbsp;thread&nbsp;is&nbsp;blocked&nbsp;and&nbsp;the&nbsp;placeholder&nbsp;diagram&nbsp;is&nbsp;not&nbsp;displayed. |

- ImageFit enums
    | Name | Description | 
  | -------- | -------- |
  | Cover | The&nbsp;image&nbsp;is&nbsp;scaled&nbsp;with&nbsp;its&nbsp;aspect&nbsp;ratio&nbsp;retained&nbsp;for&nbsp;both&nbsp;sides&nbsp;to&nbsp;be&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;the&nbsp;display&nbsp;boundaries. | 
  | Contain | The&nbsp;image&nbsp;is&nbsp;scaled&nbsp;with&nbsp;its&nbsp;aspect&nbsp;ratio&nbsp;retained&nbsp;for&nbsp;the&nbsp;content&nbsp;to&nbsp;be&nbsp;completely&nbsp;displayed&nbsp;within&nbsp;the&nbsp;display&nbsp;boundaries. | 
  | Fill | The&nbsp;video&nbsp;content&nbsp;is&nbsp;resized&nbsp;to&nbsp;fill&nbsp;the&nbsp;display&nbsp;area&nbsp;while&nbsp;retaining&nbsp;its&nbsp;aspect&nbsp;ratio. | 
  | None | The&nbsp;original&nbsp;size&nbsp;is&nbsp;retained.&nbsp;Generally,&nbsp;this&nbsp;enum&nbsp;is&nbsp;used&nbsp;together&nbsp;with&nbsp;the&nbsp;**objectRepeat**&nbsp;attribute. | 
  | ScaleDown | The&nbsp;image&nbsp;content&nbsp;is&nbsp;displayed&nbsp;with&nbsp;its&nbsp;aspect&nbsp;ratio&nbsp;retained.&nbsp;The&nbsp;size&nbsp;is&nbsp;smaller&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;the&nbsp;original&nbsp;size. | 

- ImageInterpolation enums
    | Name | Description | 
  | -------- | -------- |
  | None | Interpolation&nbsp;image&nbsp;data&nbsp;is&nbsp;not&nbsp;used. | 
  | High | The&nbsp;interpolation&nbsp;image&nbsp;data&nbsp;is&nbsp;used&nbsp;at&nbsp;the&nbsp;high&nbsp;level.&nbsp;The&nbsp;use&nbsp;of&nbsp;the&nbsp;interpolation&nbsp;image&nbsp;data&nbsp;may&nbsp;affect&nbsp;the&nbsp;image&nbsp;rendering&nbsp;speed. | 
  | Medium | The&nbsp;interpolation&nbsp;image&nbsp;data&nbsp;is&nbsp;used&nbsp;at&nbsp;the&nbsp;medium&nbsp;level. | 
  | Low | The&nbsp;interpolation&nbsp;image&nbsp;data&nbsp;is&nbsp;used&nbsp;at&nbsp;the&nbsp;low&nbsp;level. | 

- ImageRenderMode enums
    | Name | Description | 
  | -------- | -------- |
  | Original | The&nbsp;image&nbsp;is&nbsp;rendered&nbsp;based&nbsp;on&nbsp;the&nbsp;original&nbsp;image,&nbsp;including&nbsp;the&nbsp;color. | 
  | Template | The&nbsp;image&nbsp;is&nbsp;rendered&nbsp;as&nbsp;a&nbsp;template&nbsp;image,&nbsp;and&nbsp;its&nbsp;color&nbsp;is&nbsp;ignored. | 


## Events

  | Name | Description | 
| -------- | -------- |
| onComplete(callback:&nbsp;(event?:&nbsp;{&nbsp;width:&nbsp;number,&nbsp;height:&nbsp;number,&nbsp;componentWidth:&nbsp;number,&nbsp;componentHeight:&nbsp;number,&nbsp;loadingStatus:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void) | Triggered&nbsp;when&nbsp;an&nbsp;image&nbsp;is&nbsp;successfully&nbsp;loaded.&nbsp;The&nbsp;loaded&nbsp;image&nbsp;is&nbsp;returned. | 
| onError(callback:&nbsp;(event?:&nbsp;{&nbsp;componentWidth:&nbsp;number,&nbsp;componentHeight:&nbsp;number&nbsp;})&nbsp;=&gt;&nbsp;void) | An&nbsp;exception&nbsp;occurs&nbsp;during&nbsp;image&nbsp;loading. | 
| onFinish(callback:&nbsp;()&nbsp;=&gt;&nbsp;void) | If&nbsp;the&nbsp;source&nbsp;file&nbsp;to&nbsp;be&nbsp;loaded&nbsp;is&nbsp;an&nbsp;SVG&nbsp;image,&nbsp;this&nbsp;callback&nbsp;is&nbsp;invoked&nbsp;when&nbsp;the&nbsp;SVG&nbsp;animation&nbsp;playback&nbsp;is&nbsp;complete.&nbsp;If&nbsp;the&nbsp;animation&nbsp;is&nbsp;an&nbsp;infinite&nbsp;loop,&nbsp;this&nbsp;callback&nbsp;is&nbsp;not&nbsp;triggered. | 


## Example


```
// Image1
@Entry
@Component
struct ImageExample1 {
  private on: string = 'www.example.com' 
  @State src: string = this.on

  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Text('default').fontSize(16).fontColor(0xcccccc).height(30)
        Row({ space: 5 }) {
          Image($r('app.media.ic_png'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.ic_gif'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.ic_svg'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row({ space: 5 }) {
          Image($r('app.media.img_example'))
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image(this.src)
            .width(110).height(110).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .overlay('network', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }.margin({ top: 25, bottom: 10 })
      }

      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Text('objectFit').fontSize(16).fontColor(0xcccccc).height(30)
        Row({ space: 5 }) {
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.None).width(110).height(110)
            .overlay('None', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Fill).width(110).height(110)
            .overlay('Fill', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Cover).width(110).height(110)
            .overlay('Cover', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row({ space: 5 }) {
          Image($r('app.media.img_example_w250'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.Contain).width(110).height(110)
            .overlay('Contain', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          Image($r('app.media.img_example_w250'))
            .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
            .objectFit(ImageFit.ScaleDown).width(110).height(110)
            .overlay('ScaleDown', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }.margin({ top: 25 })
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![en-us_image_0000001211898484](figures/en-us_image_0000001211898484.gif)


```
// Image2
@Entry
@Component
struct ImageExample2 {
  @State width: number = 100
  @State height: number = 100

  build() {
    Column({ space: 10 }) {
      Text('renderMode').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Row({ space: 50 }) {
        Image($r('app.media.img_example'))
          .renderMode(ImageRenderMode.Original).width(100).height(100)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('Original', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_example'))
          .renderMode(ImageRenderMode.Template).width(100).height(100)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('Template', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }

      Text('alt').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Image('')
        .alt($r('app.media.Image_none'))
        .width(100).height(100).border({ width: 1 }).borderStyle(BorderStyle.Dashed)

      Text('sourceSize').fontSize(12).fontColor(0xcccccc).width('96%')
      Row({ space: 50 }) {
        Image($r('app.media.img_example'))
          .sourceSize({
            width: 150,
            height: 150
          })
          .objectFit(ImageFit.ScaleDown).width('25%').aspectRatio(1)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('w:150 h:150', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_example'))
          .sourceSize({
            width: 200,
            height: 200
          })
          .objectFit(ImageFit.ScaleDown).width('25%').aspectRatio(1)
          .border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .overlay('w:200 h:200', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }

      Text('objectRepeat').fontSize(12).fontColor(0xcccccc).width('96%').height(30)
      Row({ space: 5 }) {
        Image($r('app.media.ic_health_heart'))
          .width(120).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.XY).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.XY', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.ic_health_heart'))
          .width(110).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.Y).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.Y', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.ic_health_heart'))
          .width(110).height(125).border({ width: 1 }).borderStyle(BorderStyle.Dashed)
          .objectRepeat(ImageRepeat.X).objectFit(ImageFit.ScaleDown)
          .overlay('ImageRepeat.X', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }
    }.height(150).width('100%').padding({ right: 10 })
  }
}
```

![en-us_image_0000001212058474](figures/en-us_image_0000001212058474.png)


```
// Image3
@Entry
@Component
struct ImageExample3 {
  @State width: number = 0
  @State height: number = 0
  private on: Resource = $r('app.media.wifi_on')
  private off: Resource = $r('app.media.wifi_off')
  private on2off: Resource = $r('app.media.wifi_on2off')
  private off2on: Resource = $r('app.media.wifi_off2on')
  @State src: Resource = this.on

  build() {
    Column() {
      Row({ space: 20 }) {
        Column() {
          Image($r('app.media.img_example1'))
            .alt($r('app.media.ic_public_picture'))
            .sourceSize({
              width: 900,
              height: 900
            })
            .objectFit(ImageFit.Cover)
            .height(180).width(180)
            .onComplete((msg: { width: number,height: number }) => {
              this.width = msg.width
              this.height = msg.height
            })
            .onError(() => {
              console.log('load image fail')
            })
            .overlay('\nwidth: ' + String(this.width) + ' height: ' + String(this.height), {
              align: Alignment.Bottom,
              offset: { x: 0, y: 20 }
            })
        }

        Image(this.src)
          .width(120).height(120)
          .onClick(() => {
            if (this.src == this.on || this.src == this.off2on) {
              this.src = this.on2off
            } else {
              this.src = this.off2on
            }
          })
          .onFinish(() => {
            if (this.src == this.off2on) {
              this.src = this.on
            } else {
              this.src = this.off
            }
          })
      }
    }.width('100%')
  }
}
```

![en-us_image_0000001256858397](figures/en-us_image_0000001256858397.gif)
