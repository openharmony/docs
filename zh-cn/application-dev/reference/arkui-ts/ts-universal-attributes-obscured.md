# 隐私遮罩

用于对组件内容进行隐私遮罩处理。

>  **说明：**
>
> 从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 属性


| 名称    | 参数类型                                     | 描述                                  |
| -----| ------------------------------------------ | ------------------------------------ |
| obscured | Array<[ObscuredReasons](ts-appendix-enums.md#obscuredreasons10)> | 设置组件内容的遮罩类型。<br>默认值：[]<br/>该接口支持在ArkTS卡片中使用。<br/>仅支持[Image](ts-basic-components-image.md)组件和[Text](ts-basic-components-text.md)组件的隐私遮罩处理。<br/>**说明：**<br/>如需在图片加载过程中显示隐私遮罩，需要设置Image组件的宽度和高度。 |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct ObscuredExample {
  build() {
    Row() {
      Column() {
        Text('Text not set obscured attribute').fontSize(10).fontColor(Color.Black)
        Text('This is an example for text obscured attribute.')
          .fontSize(30)
          .width('600px')
          .fontColor(Color.Black)
          .border({ width: 1 })
        Text('Image not set obscured attribute').fontSize(10).fontColor(Color.Black)
        Image($r('app.media.icon'))
          .width('200px')
          .height('200px')
        Text('Text set obscured attribute').fontSize(10).fontColor(Color.Black)
        Text('This is an example for text obscured attribute.')
          .fontSize(30)
          .width('600px')
          .fontColor(Color.Black)
          .border({ width: 1 })
          .obscured([ObscuredReasons.PLACEHOLDER])
        Text('Image set obscured attribute').fontSize(10).fontColor(Color.Black)
        Image($r('app.media.icon'))
          .width('200px')
          .height('200px')
          .obscured([ObscuredReasons.PLACEHOLDER])
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

![obscured](figures/obscured.png)

