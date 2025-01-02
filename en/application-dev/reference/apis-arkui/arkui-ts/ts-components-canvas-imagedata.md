# ImageData

An **ImageData** object stores pixel data rendered on a canvas.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

constructor(width: number, height: number, data?: Uint8ClampedArray, unit?: LengthMetricsUnit);

A constructor used to create an **ImageData** object. To ensure successful drawing, make sure the object's area does not exceed 16000 x 16000, with its width and height not greater than 16384 px. If the created area exceeds 536870911 px, the returned width and height are both 0 px, and **data** is **undefined**.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**
| Name| Type | Mandatory | Description|
| ------ | ----- | ----- | ----- |
| width | number |Yes| Width of the rectangle.<br>Default unit: vp|
| height | number |Yes| Height of the rectangle.<br>Default unit: vp|
| data | Uint8ClampedArray |No| A one-dimensional array of color values. The values range from 0 to 255.|
| unit<sup>12+</sup>  | [LengthMetricsUnit](../js-apis-arkui-graphics.md#lengthmetricsunit12) | No  |  Unit mode of the **ImageData** object. The value cannot be dynamically changed once set. The configuration method is the same as that of [CanvasRenderingContext2D](ts-canvasrenderingcontext2d.md#lengthmetricsunit12).<br>Default value: **DEFAULT**|

## Attributes

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type  | Read Only| Optional| Description|
| ------ | -------- | --------- | ---------- | ------------------------------ |
| width | number | Yes| No| Actual width of the rectangle on the canvas.<br>The unit is px.|
| height | number | Yes| No| Actual height of the rectangle on the canvas.<br>The unit is px.|
| data | Uint8ClampedArray | Yes| No| A one-dimensional array of color values. The values range from 0 to 255.|

>  **NOTE**
>
>  You can use the [px2vp](ts-pixel-units.md#pixel-unit-conversion) API to convert the unit.

**Example**

This example shows how to use the **getImageData** API to obtain an **ImageData** object.

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct Translate {
    private settings: RenderingContextSettings = new RenderingContextSettings(true)
    private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
    private img:ImageBitmap = new ImageBitmap("common/images/1234.png")

    build() {
      Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
        Canvas(this.context)
          .width('100%')
          .height('100%')
          .backgroundColor('#ffff00')
          .onReady(() =>{
            this.context.drawImage(this.img,0,0,130,130)
            let imagedata = this.context.getImageData(50,50,130,130)
            this.context.putImageData(imagedata,150,150)
          })
      }
      .width('100%')
      .height('100%')
    }
  }
  ```

  ![en-us_image_000000127777780](figures/en-us_image_000000127777780.png)
