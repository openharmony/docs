# 阴影
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @yangfan229-->
<!--Tester: @lxl007-->
<!--Adviser: @HelloCrease-->


阴影接口[shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow)可以为当前组件添加阴影效果，该接口支持两种类型参数，开发者可配置[ShadowOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions对象说明)自定义阴影效果。ShadowOptions模式下，当radius = 0 或者 color 的透明度为0时，无阴影效果。



```ts
@Entry
@Component
struct ShadowOptionDemo {
  build() {
    Row() {
      Column() {
        Column() {
          Text('shadowOption').fontSize(12)
        }
        .width(100)
        .aspectRatio(1)
        .margin(10)
        .justifyContent(FlexAlign.Center)
        .backgroundColor(Color.White)
        .borderRadius(20)
        .shadow({ radius: 10, color: Color.Gray })

        Column() {
          Text('shadowOption').fontSize(12)
        }
        .width(100)
        .aspectRatio(1)
        .margin(10)
        .justifyContent(FlexAlign.Center)
        .backgroundColor('#a8a888')
        .borderRadius(20)
        .shadow({
          radius: 10,
          color: Color.Gray,
          offsetX: 20,
          offsetY: 20
        })
      }
      .width('100%')
      .height('100%')
      .justifyContent(FlexAlign.Center)
    }
    .height('100%')
  }
}
```



![zh-cn_image_0000001598502322](figures/zh-cn_image_0000001598502322.png)
