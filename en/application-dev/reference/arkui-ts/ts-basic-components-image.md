# Image

The **\<Image>** component is used to render and display local and online images.

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

To use online images, you need to add the **ohos.permission.INTERNET** permission to the corresponding abilities in the **config.json** (for the FA model) or **module.json5** file (for the stage model).

```
"abilities": [
  {
    ...
    "permissions": ["ohos.permission.INTERNET"],
    ...
  }
] 
```


## Child Components

Not supported


## APIs

Image(src: string | PixelMap | Resource)

Obtains an image from the specified source for subsequent rendering and display.

**Parameters**

| Name| Type                                                    | Mandatory| Default Value| Description                                                    |
| ------ | ------------------------------------------------------------ | ---- | ------ | ------------------------------------------------------------ |
| src    | string \| [PixelMap](../apis/js-apis-image.md#pixelmap7) \| [Resource](../../ui/ts-types.md) | Yes  | -      | Image source. Both local and online images are supported.<br>When using resources referenced using a relative path, for example, `Image("common/test.jpg")`, the **\<Image>** component cannot be called across bundles or modules. Therefore, you are advised to use `$r` to reference image resources that need to be used globally.<br>\- The following image formats are supported: PNG, JPG, BMP, SVG, GIF.<br>\- Base64 strings are supported. The value format is `data:image/[png\|jpeg\|bmp\|webp];base64,[base64 data]`, where `[base64 data]` is a Base64 string.<br/>\- The value can also be a path starting with `dataability://`, which is used to access the image path provided by a Data ability. |

## Attributes

In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                  | Type                                    | Default Value                     | Description                                      |
| --------------------- | ---------------------------------------- | ------------------------ | ---------------------------------------- |
| alt                   | string \| [Resource](../../ui/ts-types.md) | -                        | Placeholder image displayed during loading. Both local and Internet URIs are supported.                  |
| objectFit             | ImageFit                                                | Cover          | Image scale type.                              |
| objectRepeat          | [ImageRepeat](ts-appendix-enums.md#imagerepeat) | NoRepeat                 | Whether the image is repeated.<br>**NOTE**<br>This attribute is not applicable to SVG images. |
| interpolation         | ImageInterpolation                                      | None  | Interpolation effect of the image. This attribute is valid only when the image is zoomed in.<br>**NOTE**<br>This attribute is not applicable to SVG images or **PixelMap** objects. |
| renderMode            | ImageRenderMode                                         | Original | Rendering mode of the image.<br>**NOTE**<br>This attribute is not applicable to SVG images. |
| sourceSize            | {<br>width: number,<br>height: number<br>} | -                        | Decoding size of the image. The original image is decoded into an image of the specified size, in px.<br>**NOTE**<br>This attribute is not applicable to **PixelMap** objects. |
| syncLoad<sup>8+</sup> | boolean                                  | false                    | Whether to load images synchronously. By default, images are loaded asynchronously. During synchronous loading, the UI thread is blocked and the placeholder diagram is not displayed. |

## ImageFit

| Name       | Description                              |
| --------- | -------------------------------- |
| Cover     | The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries. |
| Contain   | The image is scaled with its aspect ratio retained for the content to be completely displayed within the display boundaries.   |
| Fill      | The image is scaled to fill the display area, and its aspect ratio is not retained.        |
| None      | The image is displayed in its original size. Generally, this enum is used together with the **objectRepeat** attribute.|
| ScaleDown | The image is displayed with its aspect ratio retained, in a size smaller than or equal to the original size.             |

## ImageInterpolation

| Name    | Description                       |
| ------ | ------------------------- |
| None   | Interpolation image data is not used.               |
| High   | The interpolation image data is used at the high level, which may affect the image rendering speed.|
| Medium | The interpolation image data is used at the medium level.             |
| Low    | The interpolation image data is used at the low level.             |

## ImageRenderMode

| Name      | Description                   |
| -------- | --------------------- |
| Original | The image is rendered based on the original image, including the color.       |
| Template | The image is rendered as a template image, and its color is ignored.|

## Events


| Name                                      | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| onComplete(callback: (event?: { width: number, height: number, componentWidth: number,<br> componentHeight: number, loadingStatus: number }) =&gt; void) | Triggered when an image is successfully loaded. The size of the loaded image is returned.<br>- **width**: width of the image, in pixels.<br>- **height**: height of the image, in pixels.<br>- **componentWidth**: width of the container component, in pixels.<br>- **componentHeight**: height of the container component, in pixels.<br>- **loadingStatus**: image loading status.<br>|
| onError(callback: (event?: { componentWidth: number, componentHeight: number }) =&gt; void) | Triggered when an exception occurs during image loading.<br>- **componentWidth**: width of the container component, in pixels.<br>- **componentHeight**: height of the container component, in pixels.<br>|
| onFinish(event: () =&gt; void) | Triggered when the animation playback in the loaded SVG image is complete. If the animation is an infinite loop, this callback is not triggered.|


## Example

```ts
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

```ts
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

```ts
// Image3
@Entry
@Component
struct ImageExample3 {
  @State widthValue: number = 0
  @State heightValue: number = 0
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
              this.widthValue = msg.width
              this.heightValue = msg.height
            })
            .onError(() => {
              console.log('load image fail')
            })
            .overlay('\nwidth: ' + String(this.widthValue) + ' height: ' + String(this.heightValue), {
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
