# ImageBitmap对象

ImageBitmap对象可以存储canvas渲染的像素数据。

>  **说明：**
>
>  从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

ImageBitmap(src: string)

从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名 | 参数类型 | 必填 | 默认值 | 参数描述                                                     |
| ------ | -------- | ---- | ------ | ------------------------------------------------------------ |
| src    | string   | 是   | -      | 图片的数据源<br/>**说明：**<br/>- ArkTS卡片上不支持`http://`等网络相关路径前缀、`datashare://`路径前缀以及`file://data/storage`路径前缀的字符串 |



## 属性

| 属性 | 类型 | 描述 |
| -------- | -------- | -------- |
| width | number | ImageBitmap的像素宽度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| height | number | ImageBitmap的像素高度。<br/>从API version 9开始，该接口支持在ArkTS卡片中使用。 |

**示例：**

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

  ![zh-cn_image_0000001194352442](figures/zh-cn_image_0000001194352442.png)



## 方法


### close

close()

释放ImageBitmap对象相关联的所有图形资源，并讲ImageBitmap对象的宽高置为0。

从API version 9开始，该接口支持在ArkTS卡片中使用。