# RichEditor (System API)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @carnivore233-->
<!--Designer: @xiangyuan6-->
<!--Tester: @mateng_Holtens-->
<!--Adviser: @Brilliantry_Rui-->

**RichEditor** is a component that supports interactive text editing and mixture of text and imagery.

>  **NOTE**
>
>  This component is supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
>  This topic describes only system APIs provided by the module. For details about its public APIs, see [RichEditor](ts-basic-components-richeditor.md).
> 
## RichEditorBuilderSpanOptions<sup>11+</sup>

Defines the options for adding a builder span.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name    | Type    | Mandatory  | Description                                   |
| ------ | ------ | ---- | ------------------------------------- |
| dragBackgroundColor<sup>18+</sup> | [ColorMetrics](../js-apis-arkui-graphics.md#colormetrics12) | No   | Background color of the builder when it is dragged independently. If no valid value is specified, the default color is used. |
| isDragShadowNeeded<sup>18+</sup> | boolean | No   | Whether to apply a shadow when the builder is dragged independently. If no valid value is specified, a shadow is applied. The value **true** means to apply a shadow, and **false** means the opposite.<br>Default value: **true**|

## RichEditorGesture<sup>11+</sup>

Defines the callback for user interactions.

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name         | Type        | Mandatory  | Description           |
| ----------- | ---------- | ---- | ------------- |
| onDoubleClick<sup>14+</sup> | Callback\<[GestureEvent](ts-gesture-common.md#gestureevent)\>  | No   | [GestureEvent](ts-gesture-common.md#gestureevent) indicates the double-tap event.<br>Callback event when the double-tap is complete.|

## RichEditorChangeValue<sup>12+</sup>

**System API**: This is a system API.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| changeReason<sup>20+</sup> | [TextChangeReason](ts-text-common-sys.md#textchangereason20) | No| Reason why the component content changes.|

## Example

### Example 1: Obtaining the Reason for Component Content Changes
This example demonstrates how to use the **changeReason** returned by the **onWillChange** API to determine the reason of component content changes. This feature is supported since API version 20.

```ts
@Entry
@Component
struct RichEditorExample {
  controller: RichEditorController = new RichEditorController()
  options: RichEditorOptions = { controller: this.controller }

  build() {
    Column() {
      RichEditor(this.options)
        .height('25%')
        .width('100%')
        .border({ width: 1, color: Color.Blue })
        .onWillChange((value: RichEditorChangeValue) => {
          console.info('onWillChange, changeReason=' + value.changeReason)
          return true
        })
    }
  }
}
```

### Example 2: Setting the Drag Preview and Drag Shadow for a Custom Layout
In API version 18 and later versions, you can use the [dragBackgroundColor](#richeditorbuilderspanoptions11) and [isDragShadowNeeded](#richeditorbuilderspanoptions11) parameters in the **addBuilderSpan** API to set parameters for the drag preview and drag shadow for a custom layout.

```ts
// xxx.ets
import { ColorMetrics } from '@kit.ArkUI';

@Entry
@Component
struct richEditorNew03 {
  controller: RichEditorController = new RichEditorController();
  options: RichEditorOptions = { controller: this.controller }
  build() {
    Column({ space: 10 }) {
      Column() {
        RichEditor(this.options)
          .onReady(() => {
            this.controller.addBuilderSpan(() => {
              this.placeholderBuilder()
            }, {
              offset: -1,
              dragBackgroundColor: ColorMetrics.rgba(0xff, 0x80, 0, 0xff),
              isDragShadowNeeded: false
            })
            this.controller.addBuilderSpan(() => {
              this.placeholderBuilder()
            }, {
              offset: -1,
              dragBackgroundColor: ColorMetrics.resourceColor("#ffff0000")
                .blendColor(ColorMetrics.resourceColor("#ff00ff00")),
              isDragShadowNeeded: true
            })
            this.controller.addBuilderSpan(() => {
              this.placeholderBuilder()
            }, { offset: -1 })
          })
          .borderWidth(1)
          .width("100%")
          .height("50%")
          .margin(50)
      }
      .width('100%')
      .margin({top:100})
    }
  }

  @Builder
  placeholderBuilder() {
    Row() {
      Text('This is a BuilderSpan, not plain text content')
        .fontSize(22)
        .copyOption(CopyOptions.InApp)
    }
  }
}
```
<!--Del-->![StyledString] (figures/builderspan_drag_config.gif)
<!--DelEnd-->
