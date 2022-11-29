# ImageData对象

ImageData对象可以存储canvas渲染的像素数据。

>  **说明：**
> 
> 从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。



## 属性

| 属性 | 类型 | 描述 |
| -------- | -------- | -------- |
| width | number | 矩形区域实际像素宽度。 |
| height | number | 矩形区域实际像素高度。 |
| data | Uint8ClampedArray | 一维数组，保存了相应的颜色数据，数据值范围为0到255。</br> **说明：** 需要注意的是，width和height是vp单位表示的，而data是以px为单位的二维数组转换得到的一维数组，因此需要使用vp2px接口得到原二维data数组的实际width和height。 |

**示例：**

  ```ts
  // xxx.ets
@Entry
@Component
struct Translate {
  private settings: RenderingContextSettings = new RenderingContextSettings(true)
  private context: CanvasRenderingContext2D = new CanvasRenderingContext2D(this.settings)
  private img:ImageBitmap = new ImageBitmap("/common/images/1234.png")

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Canvas(this.context)
        .width('100%')
        .height('100%')
        .backgroundColor('#ffff00')
        .onReady(() =>{
          this.context.drawImage(this.img,0,0,130,130)
          var imagedata = this.context.getImageData(50,50,130,130)
          this.context.putImageData(imagedata,150,150)
        })
    }
    .width('100%')
    .height('100%')
  }
}
  ```

  ![zh-cn_image_000000127777780](figures/zh-cn_image_000000127777780.png)

