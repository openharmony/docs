# ImageBitmap

An **ImageBitmap** object stores pixel data rendered on a canvas.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

ImageBitmap(src: string, unit?: LengthMetricsUnit)

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type  | Mandatory | Description                                   |
| ---- | ------ | ---- | ---------------------------------------- |
| src  | string | Yes | Image source. Local images are supported.<br>1. The string format is used to load local images, for example, **ImageBitmap("common/images/example.jpg")**. For entry and feature modules, the start point of the image path for loading is the **ets** folder of the module. For HAR and shared modules, the start point is the **ets** folder of the entry or feature module into which they are built.<br>2. Supported image formats: bmp, jpg, png, svg, and webp.<br>**NOTE**<br>- ArkTS widgets do not support the strings with the **http://**, **datashare://**, or **file://data/storage**. |
| unit<sup>12+</sup>  | [LengthMetricsUnit](../js-apis-arkui-graphics.md#lengthmetricsunit12) | No | Unit mode of the **ImageBitmap** object. The value cannot be dynamically changed once set. The configuration method is the same as that of [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md#lengthmetricsunit12).<br>Default value: **DEFAULT** |


## Attributes

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type | Read Only | Optional | Description |
| ------ | ------ | ----- | -------- | --------------------------- |
| width | number | Yes | No | Pixel width of the **ImageBitmap** object.<br>Default unit: vp |
| height | number | Yes | No | Pixel height of the **ImageBitmap** object.<br>Default unit: vp |

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct ImageExample {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("common/images/example.jpg")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() => {
            this.context.drawImage(this.img, 0, 0, 500, 500, 0, 0, 400, 200)
            this.img.close()
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_0000001194352442](figures/en-us_image_0000001194352442.png)



## Methods

### close

close(): void

Releases all graphics resources associated with this **ImageBitmap** object and sets its width and height to **0**. For the sample code, see the code for creating an **ImageBitmap** object.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full
