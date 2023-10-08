# ImageBitmap

An **ImageBitmap** object stores pixel data rendered on a canvas.

>  **NOTE**
>
>  The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## APIs

ImageBitmap(src: string)

Since API version 9, this API is supported in ArkTS widgets.

**Parameters**

| Name| Type| Mandatory| Default Value| Description                                                    |
| ------ | -------- | ---- | ------ | ------------------------------------------------------------ |
| src    | string   | Yes  | -      | Image source. Local images are supported.<br>1. The string format is used to load local images, for example, ImageBitmap("common/images/example.jpg"). The start point of the image loading path is the **ets** folder.<br>2. Supported image formats: bmp, jpg, png, svg, and webp.<br>**NOTE**<br>ArkTS widgets do not support the strings with the **http://**, **datashare://**, or **file://data/storage**.|



## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| width | number | Pixel width of the **ImageBitmap** object. The current value is **0**.<br>Since API version 9, this API is supported in ArkTS widgets.|
| height | number | Pixel height of the **ImageBitmap** object. The current value is **0**.<br>Since API version 9, this API is supported in ArkTS widgets.|

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
          .onReady(() =>{
            this.context.drawImage( this.img,0,0,500,500,0,0,400,200)
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

close()

Releases all graphics resources associated with this **ImageBitmap** object and sets its width and height to **0**.

Since API version 9, this API is supported in ArkTS widgets.
