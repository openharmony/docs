# 组件内容模糊

为当前组件添加内容模糊效果。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 属性
| 名称 | 参数类型 | 描述 |
| -------- | -------- | -------- |
| foregroundBlurStyle | value:[BlurStyle](ts-appendix-enums.md#blurstyle9),<br/>options?:[ForegroundBlurStyleOptions](#foregroundblurstyleoptions10对象说明) | 为当前组件提供内容模糊能力。<br/>value: 内容模糊样式。模糊样式由模糊半径、蒙版颜色、蒙版透明度、饱和度、亮度五个参数组成。<br/>options: 可选参数，内容模糊选项。 |

## ForegroundBlurStyleOptions对象说明

| 名称                        | 参数类型                                                | 必填 | 描述                                                         |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | 否   | 内容模糊效果使用的深浅色模式。<br/>默认值：ThemeColorMode.System |
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10)   | 否   | 内容模糊效果使用的取色模式。<br/>默认值：AdaptiveColor.Default |
| scale | number   | 否   | 内容模糊效果程度。此参数为系统接口。<br/>默认值：1.0 <br/>取值范围：[0.0, 1.0]<br/>|

## 示例

### 示例1

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