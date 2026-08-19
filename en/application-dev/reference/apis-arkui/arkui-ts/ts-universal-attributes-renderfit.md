# Render Fit
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @CCFFWW-->
<!--Designer: @CCFFWW-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

The **renderFit** attribute sets how the final state of a component's content is rendered during its width and height animation process.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.

## renderFit

renderFit(fitMode: RenderFit): T

Sets how the final state of the component's content is rendered during its width and height animation process. If it is not set via this API, the content size at the end of the animation is maintained, and the content always remains top-left aligned with the component.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Parameters**

| Name | Type                           | Mandatory| Description                                                        |
| ------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| fitMode | [RenderFit](ts-appendix-enums.md#renderfit10) | Yes  | Sets how the final state of the component's content is rendered during its width and height animation process.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

## renderFit<sup>18+</sup>

renderFit(fitMode: Optional\<RenderFit>): T

Sets how the final state of the component's content is rendered during its width and height animation process. If it is not set via this API, the content size at the end of the animation is maintained, and the content always remains top-left aligned with the component. Compared to [renderFit](#renderfit), this API supports the **undefined** type for the **fitMode** parameter.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Widget capability**: This API can be used in ArkTS widgets since API version 18.

**Parameters**

| Name | Type                                      | Mandatory| Description                                                        |
| ------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| fitMode | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<[RenderFit](ts-appendix-enums.md#renderfit10)> | Yes  | Sets how the final state of the component's content is rendered during its width and height animation process.<br>If **fitMode** is set to **undefined**, the default value is used, which is equivalent to **RenderFit.TOP_LEFT**.|

**Return value**

| Type| Description|
| -------- | -------- |
| T | Current component.|

>  **NOTE**
>
>  For the [XComponent](./ts-basic-components-xcomponent.md) component of the TEXTURE or SURFACE type, if the **renderFit** attribute is not set, it defaults to **RenderFit.RESIZE_FILL**.
>
> For the [XComponent](./ts-basic-components-xcomponent.md) component of the SURFACE type with an opaque black background color: In versions earlier than API version 18, the **renderFit** attribute only supports **RenderFit.RESIZE_FILL**; since API version 18, the **renderFit** attribute supports all its available enum values.
>
>  For the **XComponent** component created using the [ArkUI NDK API](../../../ui/ndk-access-the-arkts-page.md), the [getAttribute](../capi-arkui-nativemodule-arkui-nativenodeapi-1.md#getattribute) function is not supported for obtaining the **renderFit** attribute value.

## Example

This example demonstrates how to set different content fill modes for a component during width and height animations through the **renderFit** attribute.

```ts
// xxx.ets
@Entry
@Component
struct RenderFitExample {
  @State width1: number = 100;
  @State height1: number = 30;
  flag: boolean = true;

  build() {
    Column() {
      Text("Hello")
        .width(this.width1)
        .height(this.height1)
        .borderWidth(1)
        .textAlign(TextAlign.Start)
        .renderFit(RenderFit.LEFT)// The component's content stays at the final size and always aligned with the left of the component.
        .margin(20)

      Text("Hello")
        .width(this.width1)
        .height(this.height1)
        .textAlign(TextAlign.Center)
        .borderWidth(1)
        .renderFit(RenderFit.CENTER)// The component's content stays at the final size and always aligned with the center of the component.
        .margin(20)

      Button("animate")
        .onClick(() => {
          this.getUIContext()?.animateTo({ curve: Curve.Ease }, () => {
            if (this.flag) {
              this.width1 = 150;
              this.height1 = 50;
            } else {
              this.width1 = 100;
              this.height1 = 30;
            }
            this.flag = !this.flag;
          })
        })
    }.width("100%").height("100%").alignItems(HorizontalAlign.Center)
  }
}
```

![renderfit](figures/renderfit.gif)
