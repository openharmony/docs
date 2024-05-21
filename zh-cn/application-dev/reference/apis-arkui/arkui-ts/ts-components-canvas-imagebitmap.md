# ImageBitmap

ImageBitmap对象可以存储canvas渲染的像素数据。

>  **说明：**
>
>  从 API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 接口

ImageBitmap(src: string, unit?: LengthMetricsUnit)

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**参数：**

| 参数名  | 参数类型   | 必填   | 默认值  | 参数描述                                     |
| ---- | ------ | ---- | ---- | ---------------------------------------- |
| src  | string | 是    | -    | 图片的数据源支持本地图片。<br>1、string格式用于加载本地图片，例如ImageBitmap("common/images/example.jpg")，type为"entry"和"feature"类型的Module，其图片加载路径的起点为当前Module的ets文件夹，type为"har"和"shared"类型的Module，其图片加载路径的起点为当前构建的"entry"或"feature"类型Module的ets文件夹。<br/>2、支持本地图片类型：bmp、jpg、png、svg和webp类型。<br/>**说明：**<br/>- ArkTS卡片上不支持`http://`等网络相关路径前缀、`datashare://`路径前缀以及`file://data/storage`路径前缀的字符串。 |
| unit<sup>12+</sup>  | [LengthMetricsUnit](ts-canvasrenderingcontext2d.md#lengthmetricsunit12) | 否 | DEFAULT  | 用来配置ImageBitmap对象的单位模式，配置后无法动态更改，配置方法同CanvasRenderingContext2D。<br> DEFAULT: vp模式 <br> PX: px模式 |


## 属性

| 属性     | 类型     | 描述                                       |
| ------ | ------ | ---------------------------------------- |
| width | number | 只读属性，ImageBitmap的像素宽度，默认单位为vp。<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| height | number | 只读属性，ImageBitmap的像素高度，默认单位为vp。<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |

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

释放ImageBitmap对象相关联的所有图形资源，并将ImageBitmap对象的宽高置为0。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。