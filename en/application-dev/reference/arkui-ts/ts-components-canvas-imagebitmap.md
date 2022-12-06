# ImageBitmap

An **ImageBitmap** object stores pixel data rendered on a canvas.

> **NOTE**
> 
> The APIs of this module are supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.



## Attributes

| Name| Type| Description|
| -------- | -------- | -------- |
| width | number | Pixel width of the **ImageBitmap** object.|
| height | number | Pixel height of the **ImageBitmap** object.|

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

Releases all graphics resources associated with this **ImageBitmap** object. This API is a void API.
