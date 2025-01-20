# Foreground Blur

You can apply foreground blur effects to a component.

>  **NOTE**
>
>  This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## foregroundBlurStyle

foregroundBlurStyle(value: BlurStyle, options?: ForegroundBlurStyleOptions)

Applies a foreground blur style to the component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                    |
| ------- | ------------------------------------------------------------ | ---- | ------------------------ |
| value   | [BlurStyle](ts-universal-attributes-background.md#blurstyle9) | Yes  | Settings of the foreground blur style.          |
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions) | No  | Foreground blur options.|

## foregroundBlurStyle<sup>16+</sup>

foregroundBlurStyle(style: Optional\<BlurStyle>, options?: ForegroundBlurStyleOptions)

Applies a foreground blur style to the component. Compared to [foregroundBlurStyle](#foregroundblurstyle), the **style** parameter supports the **undefined** type.

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style   | Optional\<[BlurStyle](ts-universal-attributes-background.md#blurstyle9)> | Yes  | Settings of the foreground blur style,<br>If **style** is set to **undefined**, no blur is applied.|
| options | [ForegroundBlurStyleOptions](#foregroundblurstyleoptions) | No  | Foreground blur options.                                    |

## ForegroundBlurStyleOptions
Inherited from [BlurStyleOptions](#blurstyleoptions).

**Atomic service API**: This API can be used in atomic services since API version 12.

## BlurStyleOptions

| Name                       | Type                                               | Mandatory| Description                                                        |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| colorMode     | [ThemeColorMode](ts-container-with-theme.md#themecolormode10) | No  | Color mode used for the foreground blur.<br>Default value: **ThemeColorMode.SYSTEM**<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| adaptiveColor | [AdaptiveColor](#adaptivecolor10)   | No  | Adaptive color mode.<br>Default value: **AdaptiveColor.DEFAULT**<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| blurOptions<sup>11+</sup> | [BlurOptions](#bluroptions11)         | No   | Grayscale blur parameters.<br>Default value: **grayscale: [0,0]**<br>**Atomic service API**: This API can be used in atomic services since API version 12.|
| scale<sup>12+</sup> | number   | No  | Foreground blur scale.<br>Default value: **1.0**<br>Value range: [0.0, 1.0]<br>**Atomic service API**: This API can be used in atomic services since API version 12.|

## AdaptiveColor<sup>10+</sup>

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Description                       |
| ------- | ------------------------- |
| DEFAULT | Adaptive color mode is not used. The default color is used as the mask color. Using a mode other than **DEFAULT** can be more time-consuming.   |
| AVERAGE | Adaptive color mode is used. The average color value of the color picking area is used as the mask color.|

## BlurOptions<sup>11+</sup>
Grayscale blur parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name       |   Type  |   Mandatory| Description                       |
| ----        |  ----   |   ---- | --------------------------  |
| grayscale   |  [number, number]   |   Yes  |  Grayscale blur, with two parameters in the value range of [0, 127]. The color gradation of the black and white in the image is adjusted to create different shades of gray. The first parameter indicates the brightness of the black color, and the second parameter indicates the darkness of the white color. A larger value indicates a more obvious adjustment effect (the black and white colors become grayer). For example, if the value specified is (20,20), the RGB value [0, 0, 0] (black) is converted to [20, 20, 20], RGB value [255, 255, 255] (white) is converted to [235, 235, 235] (255-20), and the color pixels remain unchanged.|


## Example

This example demonstrates how to apply content blur to an image using **foregroundBlurStyle**.

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
