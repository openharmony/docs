# ImageData对象

ImageData对象可以存储canvas渲染的像素数据。

>  **说明：**
> 
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 属性

| 属性 | 类型 | 描述 |
| -------- | -------- | -------- |
| width | number | 矩形区域实际像素宽度，单位为px。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| height | number | 矩形区域实际像素高度，单位为px。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| data | Uint8ClampedArray | 一维数组，保存了相应的颜色数据，数据值范围为0到255。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

>  **说明：**
> 
> 可使用[px2vp](ts-pixel-units.md)接口进行单位转换。

**示例：**

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

  ![zh-cn_image_000000127777780](figures/zh-cn_image_000000127777780.png)

