# Shadow Effect

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=1305e003ab647fafbdf9b61b3e1c6def27ab7851 translatedAt=2026-08-04T06:37:52.438Z pushedAt=2026-08-04T08:53:35.599Z -->

The [shadow](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadow) API applies a shadow effect to the current component. This API supports two types of parameters, and you can configure [ShadowOptions](../reference/apis-arkui/arkui-ts/ts-universal-attributes-image-effect.md#shadowoptions) to customize the shadow effect. In ShadowOptions mode, no shadow effect is produced when the alpha value of color is 0.

> **NOTE**
>
> For the radius parameter of ShadowOptions, before API version 26.0.0, the valid range is [0, +∞). When the value is set to 0, no shadow is drawn (values less than 0 are treated as 0). Starting from API version 26.0.0, the valid range changes to (-∞, +∞), and no shadow is drawn when the value is less than 0.

<!-- @[shadow_option](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/Shadow/entry/src/main/ets/pages/Shadow.ets) -->

``` TypeScript
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

![en-us_image_0000001598502322](figures/Shadow-Effect.png)