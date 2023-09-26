# Foreground Blur

You can apply foreground blur effects to a component.

>  **NOTE**
>
>  This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## Attributes
| Name| Type| Description|
| -------- | -------- | -------- |
| foregroundBlurStyle | value:[BlurStyle](ts-appendix-enums.md#blurstyle9),<br>options?:[ForegroundBlurStyleOptions](#foregroundblurstyleoptions10) | Foreground blur style applied to the component.<br>**value**: settings of the foreground blur style, including the blur radius, mask color, mask opacity, saturation, and brightness.<br>**options**: foreground blur options. This parameter is optional.|

## ForegroundBlurStyleOptions

| Name                       | Type                                               | Mandatory| Description                                                        |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | No  | Color mode used for the foreground blur.<br>Default value: **ThemeColorMode.System**|
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10)   | No  | Adaptive color mode.<br>Default value: **AdaptiveColor.Default**|
| scale | number   | No  | Foreground blur scale. This API is a system API.<br>Default value: **1.0**<br>Value range: [0.0, 1.0]<br>|

## Example

### Example 1

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

![en-us_image_background_blur_style](figures/en-us_image_foreground_blur_style.png)
