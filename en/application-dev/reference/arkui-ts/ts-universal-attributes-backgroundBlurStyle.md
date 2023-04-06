# Background Blur

You can apply background blur effects to a component.

>  **NOTE**
> 
>  The APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
>  The APIs provided by this module are system APIs.

## Attributes

| Name                 | Parameter                    | Description                    |
| -------------------- | ----------------------- | ------------------------ |
| backgroundBlurStyle  | value:[BlurStyle](ts-appendix-enums.md#blurstyle9),<br>options<sup>10+</sup>?:[BackgroundBlurStyleOptions](#backgroundblurstyleoptions10) | Background blur style applied between the content and the background.<br>**value**: settings of the background blur style, including the blur radius, mask color, mask opacity, and saturation.<br>**options**: background blur options. This parameter is optional.<br>This API is supported in ArkTS widgets.|
 
## BackgroundBlurStyleOptions<sup>10+</sup>

| Name| Type| Mandatory| Description|
| ----------- | ------| ------ | ------ |
| colorMode<sup>10+</sup> | [ThemeColorMode](ts-appendix-enums.md#themecolormode10) | No| Color mode used for the background blur.<br>Default value: **ThemeColorMode.System**|
| adaptiveColor<sup>10+</sup> | [AdaptiveColor](ts-appendix-enums.md#adaptivecolor10) | No| Adaptive color mode.<br>Default value: **AdaptiveColor.Default**|

## Example

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
![en-us_image_background_blur_style](figures/en-us_image_background_blur_style.png)
