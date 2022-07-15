# 背景设置

>  **说明：**
> 从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


设置组件的背景色。


## 权限列表

无


## 属性


| 名称 | 参数类型 | 默认值 | 描述 |
| -------- | -------- | -------- | -------- |
| backgroundColor | [ResourceColor](../../ui/ts-types.md) | - | 设置组件的背景色。 |
| backgroundImage | src:&nbsp;[ResourceStr](../../ui/ts-types.md),<br/>repeat?:&nbsp;[ImageRepeat](ts-appendix-enums.md#imagerepeat枚举说明) | - | src参数：图片地址，支持网络图片资源和本地图片资源地址(不支持svg类型的图片)。<br/>repeat参数：设置背景图片的重复样式，默认不重复。 |
| backgroundImageSize | {<br/>width?:&nbsp;Length,<br/>height?:&nbsp;Length<br/>}&nbsp;\|&nbsp;ImageSize | Auto | 设置背景图像的高度和宽度。当输入为{width:&nbsp;Length,&nbsp;height:&nbsp;Length}对象时，如果只设置一个属性，则第二个属性保持图片原始宽高比进行调整。默认保持原图的比例不变。 |
| backgroundImagePosition | {<br/>x?:&nbsp;Length,<br/>y?:&nbsp;Length<br/>}&nbsp;\|&nbsp;[Alignment](ts-appendix-enums.md#alignment枚举说明) | {<br/>x:&nbsp;0,<br/>y:&nbsp;0<br/>} | 设置背景图在组件中显示位置。 |


- ImageSize枚举说明
  | 类型 | 描述 | 
  | -------- | -------- |
  | Cover | 默认值，保持宽高比进行缩小或者放大，使得图片两边都大于或等于显示边界。 | 
  | Contain | 保持宽高比进行缩小或者放大，使得图片完全显示在显示边界内。 | 
  | Auto | 保持原图的比例不变。 | 


## 示例

```ts
// xxx.ets
@Entry
@Component
struct BackgroundExample {
  build() {
    Column({ space: 5 }) {
      Text('background color').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row().width('90%').height(50).backgroundColor(0xE5E5E5).border({ width: 1 })

      Text('background image repeat along X').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.X)
        .backgroundImageSize({ width: '250px', height: '140px' })
        .width('90%')
        .height(70)
        .border({ width: 1 })

      Text('background image repeat along Y').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .backgroundImage('/comment/bg.jpg', ImageRepeat.Y)
        .backgroundImageSize({ width: '500px', height: '120px' })
        .width('90%')
        .height(100)
        .border({ width: 1 })

      Text('background image size').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%').height(150)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 500 })
        .border({ width: 1 })

      Text('background fill the box(Cover)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // 不保准图片完整的情况下占满盒子
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Cover)
        .border({ width: 1 })

      Text('background fill the box(Contain)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      // 保准图片完整的情况下放到最大
      Row()
        .width(200)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize(ImageSize.Contain)
        .border({ width: 1 })

      Text('background image position').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(50)
        .backgroundImage('/comment/bg.jpg', ImageRepeat.NoRepeat)
        .backgroundImageSize({ width: 1000, height: 560 })
        .backgroundImagePosition({ x: -500, y: -300 })
        .border({ width: 1 })
    }
    .width('100%').height('100%').padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001219982703](figures/zh-cn_image_0000001219982703.png)
