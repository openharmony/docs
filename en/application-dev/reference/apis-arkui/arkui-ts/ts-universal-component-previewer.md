# Component Preview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @huyisuo-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

Component preview enables you to preview the UI effect of individual custom components.

>  **NOTE**
>
>  The initial APIs of this module are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.
>
>  For details about usage, see [Component Preview](../../../ui/ui-ide-previewer.md#component-preview).

## @Preview Decorator

The @Preview decorator decorates custom components for preview.

>  **NOTE**
>
>  This API is supported in ArkTS widgets, though component preview itself is not supported in ArkTS widgets.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## PreviewParams<sup>9+</sup>

Implements a configuration object for @Preview parameters.

Defines preview device attributes such as device type and screen state.

**Widget capability**: This API can be used in ArkTS widgets since API version 9.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| title | string | No| Name of the component module to preview. Default value: custom component name.|
| width| number | No| Width of the preview device, in px. Default value: **1080**.|
| height | number | No| Height of the preview device, in px. Default value: **2340**.|
| locale| string | No|  Device language (for example, **zh_CN** and **en_US**). Default value: **zh_CN**.|
| colorMode | string | No| Brightness mode. Options: **light** (default), **dark**.|
| deviceType | string | No| Device type for preview rendering. Default value: **Phone**.|
| dpi | number | No| DPI of the preview device. Default value: **480**.|
| orientation | string | No| Screen orientation of the preview device. Options: **portrait** (default), **landscape**.|
| roundScreen | boolean | No| Whether the preview screen is circular. Default value: **false**. **true**: circular. **false**: non-circular.|

## Example

This example demonstrates @Preview usage with and without parameters.

```ts
@Entry
@Preview
@Component
struct Index {
  @State message: string = 'default Preview';

  build() {
    RelativeContainer() {
      Text(this.message)
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
    }
    .height('100%')
    .width('100%')
  }
}

@Preview({
  title: 'PreviewParams',
  width: 540,
  height: 1170
})
@Component
struct Test {
  @State message: string = 'PreviewParams';

  build() {
    RelativeContainer() {
      Text(this.message)
        .fontSize(40)
        .fontWeight(FontWeight.Bold)
    }
    .height('100%')
    .width('100%')
  }
}
```
