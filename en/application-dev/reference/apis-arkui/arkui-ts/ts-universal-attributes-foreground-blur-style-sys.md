# Foreground Blur (System API)

You can apply foreground blur effects to a component.

>  **NOTE**
>
>  This attribute is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This topic describes only system APIs provided by the module. For details about its public APIs, see [Foreground Blur](ts-universal-attributes-foreground-blur-style.md).

## BlurStyleOptions

| Name                       | Type                                               | Mandatory| Description                                                        |
| --------------------------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| scale | number   | No  | Foreground blur scale. This API is a system API.<br>Default value: **1.0**<br>Value range: [0.0, 1.0] |

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
