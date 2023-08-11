# Image

The **\<Image>** component is usually used to display images in applications. It supports images in PNG, JPG, BMP, SVG, or GIF format from the following data sources: string, [PixelMap](../apis/js-apis-image.md#pixelmap7), or [Resource](ts-types.md#resource).

> **NOTE**
>
> This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


## Required Permissions

To use online images, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).


## Child Components

Not supported


## APIs

Image(src: string | PixelMap | Resource)

Obtains an image from the specified source for subsequent rendering and display.

If the **\<Image>** component fails to obtain the image or the obtained image size is 0, the **\<Image>** component is automatically resized to 0 and does not follow the layout constraints of its parent component.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name | Type                                    | Mandatory  | Description                                    |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| src  |  string \| [PixelMap](../apis/js-apis-image.md#pixelmap7) \| [Resource](ts-types.md#resource) | Yes   | Image source. Both local and online images are supported.<br>When using an image referenced using a relative path, for example, **Image("common/test.jpg")**, the **\<Image>** component cannot be called across bundles or modules. Therefore, you are advised to use **\$r** to reference image resources that need to be used globally.<br>- The following image formats are supported: PNG, JPG, BMP, SVG, GIF.<br>\- Base64 strings are supported. The value format is data:image/[png\|jpeg\|bmp\|webp];base64,[base64 data], where [base64 data] is a Base64 string.<br/>\- Strings with the **datashare://** prefix are supported, which are used to access the image path provided by a Data ability.<br/>\- Strings with the **file:///data/storage** prefix are supported, which are used to read image resources in the **files** folder in the installation directory of the current application. Ensure that the application has the read permission to the files in the specified path.<br/>**NOTE**<br/>- ArkTS widgets support GIF animations, but the animations only play once on display.<br/>- ArkTS widgets do not support the strings with the **http://**, **datashare://**, or **file:///data/storage** prefix.<br>- ArkTS widgets do not support the [PixelMap](../apis/js-apis-image.md#pixelmap7) type. |

## Attributes

For details about how to use attributes, see [Setting Attributes](../../ui/arkts-graphics-display.md#setting-attributes). In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                            | Type                                               | Description                                                        |
| -------------------------------- | ------------------------------------------------------- | ------------------------------------------------------------ |
| alt                              | string \| [Resource](ts-types.md#resource)         | Placeholder image displayed during loading. Local images (in PNG, JPG, BMP, SVG, or GIF format) are supported. Online images are not supported.<br>Default value: **null**<br>Since API version 9, this API is supported in ArkTS widgets.|
| objectFit                        | [ImageFit](ts-appendix-enums.md#imagefit)               | Image scale mode.<br>Default value: **ImageFit.Cover**<br>Since API version 9, this API is supported in ArkTS widgets.|
| objectRepeat                     | [ImageRepeat](ts-appendix-enums.md#imagerepeat)         | How the image is repeated. When set to repeat, the image is repeated from the center to edges. The last image will be clipped if it does not fit in the component.<br>Default value: **ImageRepeat.NoRepeat**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| interpolation                    | [ImageInterpolation](#imageinterpolation)               | Interpolation effect of the image. This attribute is intended to alleviate aliasing that occurs when a low-definition image is zoomed in.<br>Default value: **ImageInterpolation.None**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images or **PixelMap** objects. |
| renderMode                       | [ImageRenderMode](#imagerendermode)                     | Rendering mode of the image, which can be **Original** or **Template** (monochrome).<br>Default value: **ImageRenderMode.Original**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| sourceSize                       | {<br>width: number,<br>height: number<br>} | Decoding size of the image. This attribute can be used to reduce the image resolution when the image display size needs to be smaller than the component size. When used together with **ImageFit.None**, it can display a small image in the component.<br>Unit: px<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute works only when the target size is smaller than the source size.<br>This attribute is not applicable to SVG images.<br>This attribute is not applicable to **PixelMap** objects.|
| matchTextDirection               | boolean                                                 | Whether to display the image in the system language direction. When this parameter is set to true, the image is horizontally flipped in the right-to-left (RTL) language context.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fitOriginalSize                  | boolean                                                 | Whether to fit the component to the original size of the image source when the component size is not set.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fillColor                        | [ResourceColor](ts-types.md#resourcecolor)              | Fill color to be superimposed on the image.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute only applies to an SVG image. Once set, the fill color will replace that of the SVG image.|
| autoResize                       | boolean                                                 | Whether to resize the image source used for drawing based on the size of the display area during image decoding. This resizing can help reduce the memory usage. For example, if the size of the original image is 1920 x 1080 and the size of the display area is 200 x 200, you can set this attribute to **true** so that the image is automatically decoded to 200 x 200.<br>Default value: **true**<br>Since API version 9, this API is supported in ArkTS widgets.|
| syncLoad<sup>8+</sup>            | boolean                                                 | Whether to load the image synchronously. By default, the image is loaded asynchronously. During synchronous loading, the UI thread is blocked and the placeholder image is not displayed.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>When loading a small image, you are advised to set **syncLoad** to **true** so that the image loading can be quickly completed on the main thread.|
| copyOption<sup>9+</sup>          | [CopyOptions](ts-appendix-enums.md#copyoptions9)        | Whether the image can be copied.<br>When **copyOption** is set to a value other than **CopyOptions.None**, the image can be copied in various manners, such as long pressing, right-clicking, or pressing Ctrl+C.<br>Default value: **CopyOptions.None**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>SVG images cannot be copied.|
| colorFilter<sup>9+</sup>         | [ColorFilter](ts-types.md#colorfilter9)                 | Color filter of the image. The input parameter is a 4 x 5 RGBA transformation matrix.<br>The first row of the matrix represents a vector value of R (red), the second row represents a vector value of G (green), the third row represents a vector value of B (blue), and the fourth row represents a vector value of A (alpha). The four rows represent different RGBA vector values.<br>The RGBA values are floating-point numbers between 0 and 1. When the diagonal value of the matrix is 1, the original color of the image is retained.<br> **Calculation rule:**<br>If the input filter matrix is as follows:<br>![image-matrix-1](figures/image-matrix-1.jpg)<br>Wherein the color is [R, G, B, A].<br>Then the color after filtering is [R', G', B', A'].<br>![image-matrix-2](figures/image-matrix-2.jpg)<br>Since API version 9, this API is supported in ArkTS widgets. |
| draggable<sup>9+</sup> | boolean                                  | Whether the image is draggable. This attribute cannot be used together with the [onDragStart](ts-universal-events-drag-drop.md) event.<br>Default value: **false** |

>  **NOTE**
>
>  - To use shortcut keys to copy the **\<Image>** component, the component must be [in focus](../../ui/arkts-common-events-focus-event.md#setting-whether-a-component-is-focusable). By default, the **\<Image>** component is not focusable. To enable it to gain focus, set both the [focusable](ts-universal-attributes-focus.md) and [focusOnTouch](ts-universal-attributes-focus.md) attributes to **true**.
>  - For SVG images, only the following tags are included in the supported list: **svg**, **rect**, **circle**, **ellipse**, **path**, **line**, **polyline**, and **polygon**.

## ImageInterpolation

Since API version 9, this API is supported in ArkTS widgets.

| Name  | Description                                                |
| ------ | ---------------------------------------------------- |
| None   | No image interpolation.                                    |
| High   | High quality interpolation. This mode produces the highest possible quality scaled images, but may require more image rendering time.|
| Medium | Medium quality interpolation.                                        |
| Low    | Low quality interpolation.                                        |

## ImageRenderMode

Since API version 9, this API is supported in ArkTS widgets.

| Name    | Description          |
| -------- | -------------- |
| Original | Render image pixels as they are in the original source image.|
| Template | Render image pixels to create a monochrome template image.|

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onComplete

onComplete(callback: (event?: { width: number, height: number, componentWidth: number, componentHeight: number, loadingStatus: number }) =&gt; void)

Triggered when an image is successfully loaded or decoded. The size of the loaded image is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name                      | Type  | Description                                                        |
| ---------------------------- | ------ | ------------------------------------------------------------ |
| width                        | number | Width of the image.<br>Unit: pixel                                   |
| height                       | number | Height of the image.<br>Unit: pixel                                   |
| componentWidth               | number | Width of the component.<br>Unit: pixel                                   |
| componentHeight              | number | Height of the component.<br>Unit: pixel                                   |
| loadingStatus                | number | Loading status of the image.<br>**NOTE**<br>If the return value is **0**, the image is successfully loaded. If the return value is **1**, the image is successfully decoded.|


### onError

onError(callback: (event?: { componentWidth: number, componentHeight: number , message: string }) =&gt; void)

Triggered when an error occurs during image loading.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name              | Type  | Description                     |
| -------------------- | ------ | ------------------------- |
| componentWidth       | number | Width of the component.<br>Unit: pixel|
| componentHeight      | number | Height of the component.<br>Unit: pixel|
| message<sup>9+</sup> | string | Error information.               |


### onFinish

onFinish(event: () =&gt; void)

Triggered when the animation playback in the loaded SVG image is complete. If the animation is an infinite loop, this callback is not triggered.

Only SVG images are supported.

Since API version 9, this API is supported in ArkTS widgets.

## Example

### Loading Images of Basic Types


```ts
@Entry
@Component
struct ImageExample1 {
  build() {
    Column() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start }) {
        Row() {
          // Load a PNG image.
          Image($r('app.media.ic_camera_master_ai_leaf'))
            .width(110).height(110).margin(15)
            .overlay('png', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // Load a GIF image.
          Image($r('app.media.loading'))
            .width(110).height(110).margin(15)
            .overlay('gif', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
        Row() {
          // Load an SVG image.
          Image($r('app.media.ic_camera_master_ai_clouded'))
            .width(110).height(110).margin(15)
            .overlay('svg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
          // Load a JPG image.
          Image($r('app.media.ic_public_favor_filled'))
            .width(110).height(110).margin(15)
            .overlay('jpg', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        }
      }
    }.height(320).width(360).padding({ right: 10, top: 10 })
  }
}
```

![en-us_image_0000001592882500](figures/en-us_image_0000001592882500.gif)

### Loading Online Images

The default network timeout period is 5 minutes for loading online images. When using an online image, you are advised to use **alt** to configure the placeholder image displayed during loading. If more flexible network configuration is required, you can use the [HTTP](../../connectivity/http-request.md) tool to send a network request, and then decode the returned data into a **PixelMap** object in the **\<Image>** component. For details about image development, see [Image Processing](../../media/image-overview.md).

To use online images, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/accesstoken-guidelines.md).

```ts
@Entry
@Component
struct ImageExample2 {
  build() {
    Column({ space: 10 }) {
      Image("https://www.example.com/xxx.png")// Enter an image URL.
        .alt($r('app.media.icon'))// Use alt to set a placeholder image displayed during image loading.
        .width(100)
        .height(100)
    }
  }
}
```


### Adding Events to an Image


```ts
@Entry
@Component
struct ImageExample3 {
  @State widthValue: number = 0;
  @State heightValue: number = 0;
  private on: Resource = $r('app.media.image_on');
  private off: Resource = $r('app.media.image_off');
  private on2off: Resource = $r('app.media.image_on2off');
  private off2on: Resource = $r('app.media.image_off2on');
  @State src: Resource = this.on;

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
            // Obtain the size of an image after the image loading is complete.
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
        // Add a click event so that a specific image is loaded upon clicking.
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

![en-us_image_0000001607845173](figures/en-us_image_0000001607845173.gif)
