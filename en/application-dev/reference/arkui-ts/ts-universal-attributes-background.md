# Background

You can set the background for a component.

>  **NOTE**
>
>  The APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes

| Name                              | Type                                    | Description                                      |
| -------------------------------- | ---------------------------------------- | ---------------------------------------- |
| background<sup>10+</sup>         | builder: [CustomBuilder](ts-types.md#custombuilder8),<br>options?: {align?:[Alignment](ts-appendix-enums.md#alignment)} | Background color of the component.<br>**builder**: custom background.<br>**align**: alignment mode between the custom background and the component.<br>If **background**, **backgroundColor**, and **backgroundImage** are set at the same time, they will all take effect, with **background** at the top layer.<br>**NOTE**<br>The custom background takes some time to render, during which it cannot respond to events, or be dynamically updated. This attribute cannot be nested or be previewed in the previewer.|
| backgroundColor                  | [ResourceColor](ts-types.md#resourcecolor) | Background color of the component.<br>Since API version 9, this API is supported in ArkTS widgets.|
| backgroundImage                  | src: [ResourceStr](ts-types.md#resourcestr),<br>repeat?: [ImageRepeat](ts-appendix-enums.md#imagerepeat) | **src**: image address, which can be the address of an Internet or a local image or a Base64 encoded image. SVG images are not supported.<br>**repeat**: whether the background image is repeated. By default, the background image is not repeated. If the set image has a transparent background and **backgroundColor** is set, the image is overlaid on the background color.<br>Since API version 9, this API is supported in ArkTS widgets.|
| backgroundImageSize              | {<br>width?: [Length](ts-types.md#length),<br>height?: [Length](ts-types.md#length)<br>} \| [ImageSize](ts-appendix-enums.md#imagesize) | Width and height of the background image. If the input is a **{width: Length, height: Length}** object and only one attribute is set, the other attribute is the set value multiplied by the original aspect ratio of the image. By default, the original image aspect ratio remains unchanged.<br>The value range of **width** and **height** is [0, +∞).<br>Default value: **ImageSize.Auto**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>A value less than 0 evaluates to the value **0**. If **height** is set but **width** is not, the image width is adjusted based on the original aspect ratio of the image.|
| backgroundImagePosition          | [Position](ts-types.md#position8) \| [Alignment](ts-appendix-enums.md#alignment) | Position of the background image in the component, that is, the coordinates relative to the upper left corner of the component.<br>Default value:<br>{<br>x: 0,<br>y: 0<br>} <br> When **x** and **y** are set in percentage, the offset is calculated based on the width and height of the component.<br>Since API version 9, this API is supported in ArkTS widgets.|
| backgroundBlurStyle<sup>9+</sup> | value:[BlurStyle](ts-appendix-enums.md#blurstyle9),<br>options<sup>10+</sup>?:[BackgroundBlurStyleOptions](#backgroundblurstyleoptions10) | Background blur style applied between the content and the background.<br>**value**: settings of the background blur style, including the blur radius, mask color, mask opacity, saturation, and brightness.<br>**options**: background blur options. Optional.<br>This API is supported in ArkTS widgets.|
| backgroundEffect<sup>11+</sup>  | blurOptions:[BackgroundEffectOptions](ts-appendix-enums.md#backgroundbrightnessoptions11)  |  Background effect, including saturation, brightness, and color. |

## BackgroundBlurStyleOptions<sup>10+</sup>

| Name           | Type                                    | Mandatory  | Description                                      |
| ------------- | ---------------------------------------- | ---- | ---------------------------------------- |
| colorMode     | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | No   | Color mode used for the background blur.<br>Default value: **ThemeColorMode.System**|
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10) | No   | Adaptive color mode.<br>Default value: **AdaptiveColor.Default**|
| scale         | number                                   | No   | Blurredness of the background material. This API is a system API.<br>Default value: **1.0**<br>Value range: [0.0, 1.0]<br>|
| blurOptions<sup>11+</sup> | [BlurOptions](ts-appendix-enums.md#bluroptions11)         | No   | Grayscale blur parameters.          |

## Example

### Example 1

```ts
// xxx.ets
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

### Example 2

```ts
// xxx.ets
@Entry
@Component
struct BackgroundBlurStyleDemo {
  build() {
    Column() {
      Row() {
        Text("Thin Material")
      }
      .width('50%')
      .height('50%')
      .backgroundBlurStyle(BlurStyle.Thin, { colorMode: ThemeColorMode.LIGHT, adaptiveColor: AdaptiveColor.DEFAULT, scale: 1.0 })
      .position({ x: '15%', y: '30%' })
    }
    .height('100%')
    .width('100%')
    .backgroundImage($r('app.media.bg'))
    .backgroundImageSize(ImageSize.Cover)
  }
}
```

![en-us_image_background_blur_style](figures/en-us_image_background_blur_style.png)

### Example 3

```ts
// xxx.ets
@Entry
@Component
struct BackgroundExample {
  @Builder renderBackground() {
    Column() {
      Progress({value : 50})
    }
  }

  build() {
    Column() {
      Text("content")
        .width(100)
        .height(40)
        .fontColor("#FFF")
        .position({x:50, y:80})
        .textAlign(TextAlign.Center)
        .backgroundColor(Color.Green)
    }
    .width(200).height(200)
    .background(this.renderBackground)
    .backgroundColor(Color.Gray)
  }
}
```

![en-us_image_background](figures/en-us_image_background.png)
