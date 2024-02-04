# 组件内容模糊

为当前组件添加内容模糊效果。

>  **说明：**
>
>  从API Version 10开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  当前页面仅包含本模块的系统接口，其他公开接口参见[组件内容模糊](ts-universal-attributes-foreground-blur-style.md)。

## BlurStyleOptions

| 名称                        | 参数类型                                                | 必填 | 描述                                                         |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| scale | number   | 否   | 内容模糊效果程度。此参数为系统接口。<br/>默认值：1.0 <br/>取值范围：[0.0, 1.0]<br/>|

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