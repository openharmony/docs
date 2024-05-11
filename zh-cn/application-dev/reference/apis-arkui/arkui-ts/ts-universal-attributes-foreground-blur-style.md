# 组件内容模糊

为当前组件添加内容模糊效果。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## foregroundBlurStyle

foregroundBlurStyle(value: BlurStyle, options?: ForegroundBlurStyleOptions)

为当前组件提供内容模糊能力。

**元服务API：** 从API version 11开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [BlurStyle](ts-appendix-enums.md#blurstyle9)                 | 是   | 内容模糊样式。 |
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions对象说明) | 否   | 可选参数，内容模糊选项。                                     |

## ForegroundBlurStyleOptions对象说明
继承自[BlurStyleOptions](#blurstyleoptions)

**元服务API：** 从API version 12开始，该接口支持在元服务中使用。

## BlurStyleOptions

| 名称                        | 参数类型                                                | 必填 | 描述                                                         |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | 否   | 内容模糊效果使用的深浅色模式。<br/>默认值：ThemeColorMode.System<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10)   | 否   | 内容模糊效果使用的取色模式。<br/>默认值：AdaptiveColor.Default<br/>**元服务API：** 从API version 11开始，该接口支持在元服务中使用。 |
| blurOptions<sup>11+</sup> | [BlurOptions](ts-appendix-enums.md#bluroptions11)         | 否    | 灰阶模糊参数。<br/>默认值：grayScale: [0,0] <br/>**元服务API：** 从API version 12开始，该接口支持在元服务中使用。|
| scale<sup>12+</sup> | number   | 否   | 内容模糊效果程度。<br/>默认值：1.0 <br/>取值范围：[0.0, 1.0] |


## 示例

```ts
// xxx.ets
@Entry
@Component
struct ForegroundBlurStyleDemo {
  build() {
    Column() {
      Text('Thin Material').fontSize(30).fontColor(0xCCCCCC)
      Image($r('app.media.bg'))
        .width(300)
        .height(350)
        .foregroundBlurStyle(BlurStyle.Thin, { colorMode: ThemeColorMode.LIGHT, adaptiveColor: AdaptiveColor.DEFAULT, scale: 1.0 })
    }
    .height('100%')
    .width('100%')
  }
}
```

![zh-cn_image_background_blur_style](figures/zh-cn_image_foreground_blur_style.png)