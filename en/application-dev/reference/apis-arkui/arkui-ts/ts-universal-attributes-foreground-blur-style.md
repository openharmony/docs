# Foreground Blur

You can apply foreground blur effects to a component.

>  **NOTE**
>
>  This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## foregroundBlurStyle

foregroundBlurStyle(value: BlurStyle, options?: ForegroundBlurStyleOptions)

Applies a foreground blur style to the component.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value   | [BlurStyle](ts-appendix-enums.md#blurstyle9)                 | Yes  | Settings of the foreground blur style, including the blur radius, mask color, mask opacity, saturation, and brightness.|
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions) | No  | Foreground blur options.                                    |

## ForegroundBlurStyleOptions
Inherited from [BlurStyleOptions](#blurstyleoptions).

## BlurStyleOptions

| Name                       | Type                                               | Mandatory| Description                                                        |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | No  | Color mode used for the foreground blur.<br>Default value: **ThemeColorMode.System**|
| adaptiveColor | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10)   | No  | Adaptive color mode.<br>Default value: **AdaptiveColor.Default**|
| blurOptions<sup>11+</sup> | [BlurOptions](ts-appendix-enums.md#bluroptions11)         | No   | Grayscale blur parameters.          |




## Example

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
