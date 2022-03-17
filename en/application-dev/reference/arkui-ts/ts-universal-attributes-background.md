# Background


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE：**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes in this topic are used to set the background color of a component.


## Required Permissions

None


## Attributes


| Name | Type | Default&nbsp;Value | Description |
| -------- | -------- | -------- | -------- |
| backgroundColor | Color | - | Background&nbsp;color&nbsp;of&nbsp;a&nbsp;component. |
| backgroundImage | src:&nbsp;string,<br/>repeat?:&nbsp;[ImageRepeat](ts-appendix-enums.md#imagerepeat-enums) | - | **src**:&nbsp;image&nbsp;address,&nbsp;which&nbsp;can&nbsp;be&nbsp;the&nbsp;address&nbsp;of&nbsp;an&nbsp;Internet&nbsp;or&nbsp;a&nbsp;local&nbsp;image.&nbsp;(SVG&nbsp;images&nbsp;are&nbsp;not&nbsp;supported.)<br/>**repeat**:&nbsp;whether&nbsp;the&nbsp;background&nbsp;image&nbsp;is&nbsp;repeatedly&nbsp;used.&nbsp;By&nbsp;default,&nbsp;the&nbsp;background&nbsp;image&nbsp;is&nbsp;not&nbsp;repeatedly&nbsp;used. |
| backgroundImageSize | {<br/>width?:&nbsp;Length,<br/>height?:&nbsp;Length<br/>}&nbsp;\|&nbsp;ImageSize | Auto | Width&nbsp;and&nbsp;height&nbsp;of&nbsp;the&nbsp;background&nbsp;image.&nbsp;When&nbsp;the&nbsp;input&nbsp;is&nbsp;a&nbsp;**{width:&nbsp;Length,&nbsp;height:&nbsp;Length}**&nbsp;object,&nbsp;if&nbsp;only&nbsp;one&nbsp;attribute&nbsp;is&nbsp;set,&nbsp;the&nbsp;other&nbsp;attribute&nbsp;is&nbsp;the&nbsp;set&nbsp;value&nbsp;multiplied&nbsp;by&nbsp;the&nbsp;original&nbsp;aspect&nbsp;ratio&nbsp;of&nbsp;the&nbsp;image.&nbsp;By&nbsp;default,&nbsp;the&nbsp;original&nbsp;image&nbsp;aspect&nbsp;ratio&nbsp;remains&nbsp;unchanged. |
| backgroundImagePosition | {<br/>x?:&nbsp;Length,<br/>y?:&nbsp;Length<br/>}&nbsp;\|&nbsp;[Alignment](ts-appendix-enums.md#alignment-enums) | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | Position&nbsp;of&nbsp;the&nbsp;background&nbsp;image&nbsp;in&nbsp;the&nbsp;component. |


- ImageSize enums
    | Name | Description | 
  | -------- | -------- |
  | Cover | Default&nbsp;value.&nbsp;The&nbsp;image&nbsp;is&nbsp;scaled&nbsp;with&nbsp;its&nbsp;aspect&nbsp;ratio&nbsp;retained&nbsp;for&nbsp;both&nbsp;sides&nbsp;to&nbsp;be&nbsp;greater&nbsp;than&nbsp;or&nbsp;equal&nbsp;to&nbsp;the&nbsp;display&nbsp;boundaries. | 
  | Contain | The&nbsp;image&nbsp;is&nbsp;scaled&nbsp;with&nbsp;its&nbsp;aspect&nbsp;ratio&nbsp;retained&nbsp;for&nbsp;the&nbsp;content&nbsp;to&nbsp;be&nbsp;completely&nbsp;displayed&nbsp;within&nbsp;the&nbsp;display&nbsp;boundaries. | 
  | Auto | The&nbsp;original&nbsp;image&nbsp;aspect&nbsp;ratio&nbsp;is&nbsp;retained. | 


## Example


```
@Entry
@Component
struct BackgroundExample {
  build() {
    Column({ space: 5 }) {
      Text('background color').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row().width('90%').height(50).backgroundColor(0xE5E5E5).border({ width: 1 })

      Text('background image repeat along X').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.X)
        .backgroundImageSize({ width: '250px', height: '140px' })
        .width('90%')
        .height(70)
        .border({ width: 1 })

      Text('background image repeat along Y').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.Y)
        .backgroundImageSize({ width: '500px', height: '120px' })
        .width('90%')
        .height(100)
        .border({ width: 1 })

      Text('background image size').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%').height(150)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 500 })
        .border({ width: 1 })

      Text('background fill the box(Cover)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // Occupy all the space of the container, without ensuring that the image is completely displayed.
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Cover)
        .border({ width: 1 })

      Text('background fill the box(Contain)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // Maximize the image while ensuring that it can be completely displayed.
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Contain)
        .border({ width: 1 })

      Text('background image position').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 560 })
        .backgroundImagePosition({ x: -500, y: -300 })
        .border({ width: 1 })
    }
    .width('100%').height('100%').padding({ top: 5 })
  }
}
```

![en-us_image_0000001211898502](figures/en-us_image_0000001211898502.png)
