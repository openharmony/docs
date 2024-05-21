# Image

The **\<Image>** component is usually used to display images in applications. It supports images in PNG, JPG, JPEG, BMP, SVG, WEBP, or GIF format from the following data sources: [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7), [ResourceStr](ts-types.md#resourcestr), or [DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor).

> **NOTE**
>
> - This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
> 
> - To use shortcut keys to copy the **\<Image>** component, the component must be [in focus](../../../ui/arkts-common-events-focus-event.md#setting-whether-a-component-is-focusable). By default, the **\<Image>** component is not focusable. To enable it to gain focus, set both the [focusable](ts-universal-attributes-focus.md#focusable) and [focusable](ts-universal-attributes-focus.md#focusable) attributes to **true**.
> 
>  - For SVG images, only the following tags are included in the supported list: **svg**, **rect**, **circle**, **ellipse**, **path**, **line**, **polyline**, **polygon**, **feFlood**, **feBlend**, **feColorMatrix**, **feGaussianBlur**, **feComposite**, **filter**, **mask**, and **use**.

## Required Permissions

To use online images, the application requires the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../../security/AccessToken/declare-permissions.md).


## Child Components

Not supported


## APIs

Image(src: PixelMap | ResourceStr | DrawableDescriptor)

Obtains an image from the specified source for subsequent rendering and display.

If the **\<Image>** component fails to obtain the image or the obtained image size is 0, the **\<Image>** component is automatically resized to 0 and does not follow the layout constraints of its parent component.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name | Type                                    | Mandatory  | Description                                    |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| src  | [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) \| [ResourceStr](ts-types.md#resourcestr)\| [DrawableDescriptor](../js-apis-arkui-drawableDescriptor.md#drawabledescriptor) | Yes   | Data source of the image. Local and online sources are supported. For details about how to reference an image, see [Loading Image Resources](../../../ui/arkts-graphics-display.md#loading-image-resources).<br>1. **PixelMap**: an array of pixels storing graphical information. This type is usually used in image editing scenarios.<br>2. **ResourceStr**: a string or a **Resource** object.<br>The string format can be used to load local images and, more frequently, online images. When using an image referenced using a relative path, for example, **Image("common/test.jpg")**, the **\<Image>** component cannot be called across bundles or modules. If an image needs to be used globally, you are advised to use the **Resource** format. The following types of strings are supported:<br>- Base64 strings in the format of data:image/[png\|jpeg\|bmp\|webp];base64,[base64 data], where **[base64 data]** is a Base64 string.<br>- Strings with the **file://** prefix, that is, [application sandbox URIs](../../apis-core-file-kit/js-apis-file-fileuri.md#constructor10): **file://\<bundleName>/\<sandboxPath>**, which are used to access the images in the **files** folder in the installation directory of the application. Ensure that the application has the read permission to the files in the specified path.<br>The **Resource** format allows for access across bundles and modules. It is recommended for accessing local images.<br>3. **DrawableDescriptor**: an object created when the passed resource ID or name belongs to a common image.<br>**NOTE**<br>- ArkTS widgets support GIF animations, but the animations only play once on display.<br>- ArkTS widgets do not support the strings with the **http:/\/** or **file:/\/** prefix.<br>- ArkTS widgets do not support the [PixelMap](../../apis-image-kit/js-apis-image.md#pixelmap7) type.<br>- When a local image is being loaded, any modification or replacement of it may cause application crash. Therefore, to overwrite an image file, delete the file first and then create one with the same name.<br>- Online images must support the RFC 9113 standard to be successfully loaded.<br>- This attribute can be used to download online images of 20 MB or smaller. To download larger online images, you can use [HTTP](../../../network/http-request.md).<br>- To display an SVG image that does not have the native size, you must set the width and height for the **\<Image>** component.|

## Attributes

For details about how to use the attributes, see [Setting Attributes](../../../ui/arkts-graphics-display.md#setting-attributes). In addition to the [universal attributes](ts-universal-attributes-size.md), the following attributes are supported.

| Name                          | Type                                    | Description                                      |
| ---------------------------- | ---------------------------------------- | ---------------------------------------- |
| alt                          | string \| [Resource](ts-types.md#resource)      | Placeholder image displayed during loading. Local images (in PNG, JPG, BMP, SVG, or GIF format) are supported. Online images are not supported.<br>Default value: **null**<br>Since API version 9, this API is supported in ArkTS widgets.|
| objectFit                    | [ImageFit](ts-appendix-enums.md#imagefit)       | How the image is resized to fit its container.<br>Default value: **ImageFit.Cover**<br>Since API version 9, this API is supported in ArkTS widgets.|
| objectRepeat                 | [ImageRepeat](ts-appendix-enums.md#imagerepeat) | How the image is repeated. When set to repeat, the image is repeated from the center to edges. The last image will be clipped if it does not fit in the component.<br>Default value: **ImageRepeat.NoRepeat**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| interpolation                | [ImageInterpolation](#imageinterpolation)       | Interpolation effect of the image, which can alleviate aliasing that occurs when the image is zoomed.<br>Default value: **ImageInterpolation.Low**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| renderMode                   | [ImageRenderMode](#imagerendermode)             | Rendering mode of the image, which can be **Original** or **Template** (monochrome).<br>Default value: **ImageRenderMode.Original**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| sourceSize                   | {<br>width: number,<br>height: number<br>}      | Decoding size of the image. This attribute can be used to reduce the image resolution when the image display size needs to be smaller than the component size. When used together with **ImageFit.None**, it can display a small image in the component.<br>Unit: vp<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute works only when the target size is smaller than the source size.<br>This attribute is not applicable to SVG images.<br>This attribute is not applicable to **PixelMap** objects.|
| matchTextDirection           | boolean                                         | Whether to display the image in the system language direction. When this parameter is set to true, the image is horizontally flipped in the right-to-left (RTL) language context.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fitOriginalSize              | boolean                                         | Whether to fit the component to the original size of the image source when the component size is not set.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.|
| fillColor                    | [ResourceColor](ts-types.md#resourcecolor)      | Fill color to be superimposed on the image.<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute applies only to an SVG image. Once set, the fill color will replace that of the SVG image. To set the fill color for a PNG image, use [colorFilter](#colorfilter9).|
| autoResize                   | boolean                                         | Whether to resize the image source based on the size of the display area during image decoding. This resizing can help reduce the memory usage. For example, if the size of the original image is 1920 x 1080 and the size of the display area is 200 x 200, you can set this attribute to **true** so that the image is downsampled to 200 x 200.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>As downsampling images results in some loss of information, it may reduce the image quality, causing issues such as aliasing. To retain the original image quality, set **autoResize** to **false**, but this may increase the memory usage.<br>If the original image size does not match the display size, the image may be distorted or blurred. Recommended configuration for the optimal definition:<br>When the image is scaled down: .autoResize(false) + .interpolation(.Medium)<br>When the image is scaled up: .interpolation(.High)|
| syncLoad<sup>8+</sup>        | boolean                                         | Whether to load the image synchronously. By default, the image is loaded asynchronously. During synchronous loading, the UI thread is blocked and the placeholder image is not displayed.<br>Default value: **false**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>When loading a small image, you are advised to set **syncLoad** to **true** so that the image loading can be quickly completed on the main thread.|
| copyOption<sup>9+</sup>      | [CopyOptions](ts-appendix-enums.md#copyoptions9)| Whether the image can be copied.<br>When **copyOption** is set to a value other than **CopyOptions.None**, the image can be copied in various manners, such as long pressing, right-clicking, or pressing Ctrl+C.<br>Default value: **CopyOptions.None**<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>SVG images cannot be copied.|
| colorFilter<sup>9+</sup>     | [ColorFilter](ts-types.md#colorfilter9)         | Color filter of the image. The input parameter is a 4 x 5 RGBA transformation matrix.<br>The first row of the matrix represents a vector value of R (red), the second row represents a vector value of G (green), the third row represents a vector value of B (blue), and the fourth row represents a vector value of A (alpha). The four rows represent different RGBA vector values.<br>If the matrix contains entries of 1 on the diagonal and entries of 0 in other places, the original color of the image is retained.<br> **Calculation rule:**<br>If the input filter matrix is as follows:<br>![image-matrix-1](figures/image-matrix-1.jpg)<br>Wherein the color is [R, G, B, A].<br>Then the color after filtering is [R', G', B', A'].<br>![image-matrix-2](figures/image-matrix-2.jpg)<br>Since API version 9, this API is supported in ArkTS widgets.<br>**NOTE**<br>This attribute is not applicable to SVG images.|
| draggable<sup>9+</sup>       | boolean                                         | Whether the image is draggable. The value **true** means that the image is draggable, and **false** means the opposite.<br>Default value: **false**<br>**NOTE**<br>The default value is **false** in API version 9 and **true** in API version 10.|
| enableAnalyzer<sup>11+</sup> | boolean                                         | Whether to enable the AI analyzer. The value **true** means to enable the AI analyzer.<br>This attribute cannot be used together with the [overlay](ts-universal-attributes-overlay.md) attribute. If they are set at the same time, the **CustomBuilder** attribute in **overlay** has no effect.<br>Default value: **false**<br>**NOTE**<br> This feature depends on device capabilities.<br> Images to be analyzed must be static, non-vector images. That is, SVG and GIF images cannot be analyzed. [Pixel maps](../../apis-image-kit/js-apis-image.md#pixelmap7) in [RGBA_8888](../../apis-image-kit/js-apis-image.md#pixelmapformat7) format can be passed in for analysis. For details, see [Example 4](#example-4).<br> The placeholder images (specified by **alt**) cannot be analyzed. An image can be analyzed only when **objectRepeat** is set to **ImageRepeat.NoRepeat** and [obscured](ts-universal-attributes-obscured.md) is disabled.<br> Analysis is performed based on the complete original image. If the **clip**, **margin**, **borderRadius**, **position**, or **objectFit** attribute is set, the image is not displayed completely. If **renderMode** is used to apply a mask, analysis is still performed based on the complete original image.<br> The **copyOption** attribute does not affect the AI analyzer.|
| resizable<sup>11+</sup>      | [ResizableOptions](#resizableoptions11)         | Resizable image options.<br> **NOTE**<br> 1. Resizing is effective for drag previews and placeholder images.<br>2. When [ResizableOptions](#resizableoptions11) is set to a valid value, the **objectRepeat** setting does not take effect.<br>3. When the sum of the values of **top** and **bottom** is greater than the original image height or the sum of the values of **left** and **right** is greater than the original image width, the [ResizableOptions](#resizableoptions11) setting does not take effect.<br>|

## ImageInterpolation

Since API version 9, this API is supported in ArkTS widgets.

| Name    | Description                        |
| ------ | -------------------------- |
| None   | No image interpolation.                  |
| High   | High quality interpolation. This mode produces scaled images of the highest possible quality, but may require more image rendering time.|
| Medium | Medium quality interpolation.                    |
| Low    | Low quality interpolation.                    |

## ImageRenderMode

Since API version 9, this API is supported in ArkTS widgets.

| Name      | Description     |
| -------- | ------- |
| Original | Render image pixels as they are in the original source image.|
| Template | Render image pixels to create a monochrome template image.|

## ResizableOptions<sup>11+</sup>

Defines the resizable image options.

| Name  | Type                                   | Description                                      |
| ----- | ------------------------------------- | ---------------------------------------- |
| slice | [EdgeWidths](#edgewidths) | Edge widths in different directions of a component.<br>**NOTE**<br>This parameter takes effect only when values of **bottom** and **right** are both greater than 0.|

## EdgeWidths

| Name| Type| Mandatory| Description|
| --------- |-----------|-----------|-----------|
|  top    |  number  |  No | Width of the top edge of the component.<br>Default value: **0**<br>Unit: vp|
|  right  |  number  |  No | Width of the right edge of the component.<br>Default value: **0**<br>Unit: vp|
|  bottom |  number  |  No | Width of the bottom edge of the component.<br>Default value: **0**<br>Unit: vp|
|  left   |  number  |  No | Width of the left edge of the component.<br>Default value: **0**<br>Unit: vp|

![edgewidths](figures/edgewidths.png)

## Events

In addition to the [universal events](ts-universal-events-click.md), the following events are supported.

### onComplete

onComplete(callback: (event?: { width: number, height: number, componentWidth: number, componentHeight: number, loadingStatus: number,contentWidth: number, contentHeight: number, contentOffsetX: number, contentOffsetY: number}) =&gt; void) }) =&gt; void)

Triggered when an image is successfully loaded or decoded. The size of the loaded image is returned.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name                         | Type    | Description                                      |
| ---------------------------- | ------ | ---------------------------------------- |
| width                        | number | Width of the image.<br>Unit: pixel                         |
| height                       | number | Height of the image.<br>Unit: pixel                         |
| componentWidth               | number | Width of the component.<br>Unit: pixel                         |
| componentHeight              | number | Height of the component.<br>Unit: pixel                         |
| loadingStatus                | number | Loading status of the image.<br>**NOTE**<br>If the return value is **0**, the image is successfully loaded. If the return value is **1**, the image is successfully decoded.|
| contentWidth<sup>10+</sup>   | number | Actual rendered width of the image.<br>Unit: pixel<br>**NOTE**<br>This parameter is valid only when the return value of **loadingStatus** is **1**.|
| contentHeight<sup>10+</sup>  | number | Actual rendered height of the image.<br>Unit: pixel<br>**NOTE**<br>This parameter is valid only when the return value of **loadingStatus** is **1**.|
| contentOffsetX<sup>10+</sup> | number | Offset of the rendered content relative to the component on the x-axis.<br>Unit: pixel<br>**NOTE**<br>This parameter is valid only when the return value of **loadingStatus** is **1**.|
| contentOffsetY<sup>10+</sup> | number | Offset of the rendered content relative to the component on the y-axis<br>Unit: pixel<br>**NOTE**<br>This parameter is valid only when the return value of **loadingStatus** is **1**.|


### onError<sup>9+</sup>

onError(callback: [ImageErrorCallback](#imageerrorcallback9))

Triggered when an error occurs during image loading.

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name     | Type                                      | Description           |
| -------- | ---------------------------------------- | ------------- |
| callback | [ImageErrorCallback](#imageerrorcallback9) | Triggered when an error occurs during image loading.|

### onFinish

onFinish(event: () =&gt; void)

Triggered when the animation playback in the loaded SVG image is complete. If the animation is an infinite loop, this callback is not triggered.

Only SVG images are supported.

Since API version 9, this API is supported in ArkTS widgets.

## ImageErrorCallback<sup>9+</sup>

type ImageErrorCallback = (error: [ImageError](#imageerror9)) => void

Triggered when an error occurs during image loading.

| Name  | Type                        | Description               |
| ----- | -------------------------- | ----------------- |
| error | [ImageError](#imageerror9) | Return object that triggers the callback for when an error occurs during image loading.|

## ImageError<sup>9+</sup>

Describes the return object that triggers the callback for when an error occurs during image loading.

| Name            | Type    | Description             |
| --------------- | ------ | --------------- |
| componentWidth  | number | Width of the component.<br>Unit: pixel|
| componentHeight | number | Height of the component.<br>Unit: pixel|
| message         | string | Error information.          |

## Example

### Example 1

This example demonstrates how to load images of basic types.

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

### Example 2

The default timeout is 5 minutes for loading online images. When using an online image, you are advised to use **alt** to configure a placeholder image displayed during loading. If more flexible network configuration is required, you can use [HTTP](../../../network/http-request.md) to send a network request, and then decode the returned data into a **PixelMap** object in the **\<Image>** component. For details about image development, see [Introduction to Image Kit](../../../media/image/image-overview.md).

To use online images, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../../security/AccessToken/declare-permissions.md).

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


### Example 3

This example shows how to add events to an image.

```ts
@Entry
@Component
struct ImageExample3 {
  private imageOne: Resource = $r('app.media.earth');
  private imageTwo: Resource = $r('app.media.star');
  private imageThree: Resource = $r('app.media.moveStar');
  @State src: Resource = this.imageOne
  @State src2: Resource = this.imageThree
  build(){
    Column(){
      // Add a click event so that a specific image is loaded upon clicking.
      Image(this.src)
        .width(100)
        .height(100)
        .onClick(() => {
          this.src = this.imageTwo
        })

      // When the image to be loaded is in SVG format:
      Image(this.src2)
        .width(100)
        .height(100)
        .onClick(() => {
          // Load another image when the SVG image has finished its animation.
          this.src2 = this.imageOne
        })
    }.width('100%').height('100%')
  }
}
```

![en-us_image_0000001607845173](figures/en-us_image_0000001607845173.gif)

### Example 4

In this example, the AI image analyzer is enabled for pixel maps.

```ts
import image from '@ohos.multimedia.image'
@Entry
@Component
struct ImageExample4 {
  @State imagePixelMap: image.PixelMap | undefined = undefined

  async aboutToAppear() {
    this.imagePixelMap = await this.getPixmapFromMedia($r('app.media.app_icon'))
  }

  build() {
    Column() {
      Image(this.imagePixelMap)
        .enableAnalyzer(true)
        .width(200)
        .height(200)
    }
  }
  private async getPixmapFromMedia(resource: Resource) {
    let unit8Array = await getContext(this)?.resourceManager?.getMediaContent({
      bundleName: resource.bundleName,
      moduleName: resource.moduleName,
      id: resource.id
    })
    let imageSource = image.createImageSource(unit8Array.buffer.slice(0, unit8Array.buffer.byteLength))
    let createPixelMap: image.PixelMap = await imageSource.createPixelMap({
      desiredPixelFormat: image.PixelMapFormat.RGBA_8888
    })
    await imageSource.release()
    return createPixelMap
  }
}
```

### Example 5

This example shows how to resize an image in different directions.

```ts
@Entry
@Component
struct Index {
  @State top: number = 40
  @State bottom: number = 5
  @State left: number = 40
  @State right: number = 10

  build() {
    Column({ space: 5 }) {
      // Original image effect
      Image($r("app.media.sky"))
        .width(200).height(200)
        .border({ width: 2, color: Color.Pink })
        .objectFit(ImageFit.Contain)

      // Set the resizable attribute to resize the image in different directions.
      Image($r("app.media.sky"))
        .resizable({
          slice: {
            left: this.left,
            right: this.right,
            top: this.top,
            bottom: this.bottom
          }
        })
        .width(200)
        .height(200)
        .border({ width: 2, color: Color.Pink })
        .objectFit(ImageFit.Contain)

      Row() {
        Button("add top to " + this.top).fontSize(10)
          .onClick(() => {
            this.top += 2
          })
        Button("add bottom to " + this.bottom).fontSize(10)
          .onClick(() => {
            this.bottom += 2
          })
      }

      Row() {
        Button("add left to " + this.left).fontSize(10)
          .onClick(() => {
            this.left += 2
          })
        Button("add right to " + this.right).fontSize(10)
          .onClick(() => {
            this.right += 2
          })
      }

    }
    .justifyContent(FlexAlign.Start).width('100%').height('100%')
  }
}
```

![imageResizable](figures/imageResizable.gif)
