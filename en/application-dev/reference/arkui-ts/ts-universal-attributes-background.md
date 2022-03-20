# Background


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


The attributes in this topic are used to set the background color of a component.


## Required Permissions

None


## Attributes


| Name | Type | Default Value | Description |
| -------- | -------- | -------- | -------- |
| backgroundColor | Color | - | Background color of a component. |
| backgroundImage | src: string,<br/>repeat?: [ImageRepeat](ts-appendix-enums.md#imagerepeat-enums) | - | **src**: image address, which can be the address of an Internet or a local image. (SVG images are not supported.)<br/>**repeat**: whether the background image is repeatedly used. By default, the background image is not repeatedly used. |
| backgroundImageSize | {<br/>width?: Length,<br/>height?: Length<br/>} \| ImageSize | Auto | Width and height of the background image. When the input is a **{width: Length, height: Length}** object, if only one attribute is set, the other attribute is the set value multiplied by the original aspect ratio of the image. By default, the original image aspect ratio remains unchanged. |
| backgroundImagePosition | {<br/>x?: Length,<br/>y?: Length<br/>} \| [Alignment](ts-appendix-enums.md#alignment-enums) | {<br/>x: 0,<br/>y: 0<br/>} | Position of the background image in the component. |


- ImageSize enums
    | Name | Description | 
  | -------- | -------- |
  | Cover | Default value. The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries. | 
  | Contain | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries. | 
  | Auto | The original image aspect ratio is retained. | 


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
