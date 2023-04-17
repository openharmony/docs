# 组件背景模糊

为当前组件添加背景模糊效果。

>  **说明：**
> 
>  从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  此接口为系统接口。

## 属性

| 名称                  | 参数                     | 描述                     |
| -------------------- | ----------------------- | ------------------------ |
| backgroundBlurStyle  | value:[BlurStyle](ts-appendix-enums.md#blurstyle9),<br/>options<sup>10+</sup>?:[BackgroundBlurStyleOptions](#backgroundblurstyleoptions10对象说明) | 为当前组件提供一种在背景和内容之间的模糊能力。<br/>value: 背景模糊样式。模糊样式中封装了模糊半径、蒙版颜色、蒙版透明度、饱和度四个参数。<br/>options: 可选参数，背景模糊选项。<br/>该接口支持在ArkTS卡片中使用。 |
 
## BackgroundBlurStyleOptions<sup>10+</sup>对象说明

| 名称 | 参数类型 | 必填 | 描述 |
| ----------- | ------| ------ | ------ |
| colorMode<sup>10+</sup> | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | 否 | 背景模糊效果使用的深浅色模式。<br/>默认值：ThemeColorMode.System |
| adaptiveColor<sup>10+</sup> | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10) | 否 | 背景模糊效果使用的取色模式。<br/>默认值：AdaptiveColor.Default |

## 示例

```ts
// xxx.ets
@Entry
@Component
struct BackgroundBlurStyleDemo {
  build() {
    Column() {
      Row() {
        Text("Thin Material")
      }
      .width('50%')
      .height('50%')
      .backgroundBlurStyle(BlurStyle.Thin, { colorMode: ThemeColorMode.Light, adaptiveColor: AdaptiveColor.Default })
      .position({ x: '15%', y: '30%' })
    }
    .height('100%')
    .width('100%')
    .backgroundImage($r('app.media.bg'))
    .backgroundImageSize(ImageSize.Cover)
  }
}
```
![zh-cn_image_background_blur_style](figures/zh-cn_image_background_blur_style.png)
