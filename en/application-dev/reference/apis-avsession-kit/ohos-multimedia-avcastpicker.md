# @ohos.multimedia.avCastPicker (AVCastPicker)

The **AVCastPicker** component provides a unified entry for device discovery and connection.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device. The preview is not yet available in DevEco Studio Previewer.<!--Del-->
> - This component can only be used from the device selection screen, which needs to be implemented by OEM vendors.<!--DelEnd-->
> <!--RP2--><!--RP2End-->

## Modules to Import

```js
import { AVCastPicker } from '@kit.AVSessionKit';
```

## AVCastPicker

AVCastPicker()

Implements an **AVCastPicker** component, which can be used to cast audio and video onto other devices.

This component is a custom component. Some basic knowledge of [@Component](../../quick-start/arkts-create-custom-components.md#component) will be helpful in using the component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

## Attributes

In addition to the [universal attributes](../apis-arkui/arkui-ts/ts-component-general-attributes.md), the following attributes are supported.

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| normalColor<sup>11+</sup> | Color &#124; number &#124; string | No| @Prop | Color of the component in normal state.<br>If this parameter is left unspecified, the color setting in **colorMode** is used.|
| activeColor<sup>11+</sup> | Color &#124; number &#124; string | No| @Prop | Color of the component when audio and video are successfully casted to another device. If this parameter is left unspecified, the system preferentially matches the color based on **normalColor**. If **normalColor** is also left unspecified, the color setting in **colorMode** is used.|
| pickerStyle<sup>12+</sup> | [AVCastPickerStyle](js-apis-avCastPickerParam.md#avcastpickerstyle12) | No| @Prop | Style of the component.<br>- When **sessionType** is set to **audio** or **video**, the default value is **STYLE_PANEL**.<br>- When **sessionType** is set to **voice_call** or **video_call**, the default value is **STYLE_MENU** and the value cannot be changed to **STYLE_PANEL**.|
| colorMode<sup>12+</sup> | [AVCastPickerColorMode](js-apis-avCastPickerParam.md#avcastpickercolormode12) | No|  @Prop | Display mode. The default value is **AUTO**.<br>- When **colorMode** is set to **AUTO**, the default system color in dark/light color mode is used.<br>- When **colorMode** is set to **DARK** or **LIGHT**, the preset system color of the corresponding mode is used.|
| sessionType<sup>12+</sup> | string | No| @Prop | Session type. For details, see [AVSessionType](js-apis-avsession.md#avsessiontype10). The default value is **AVSessionType** created by the application.|
| customPicker<sup>12+</sup> | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | No| @Prop | Custom style. You are advised to customize a component style so that the component can be displayed quickly.|
| onStateChange<sup>11+</sup> | (state: [AVCastPickerState](js-apis-avCastPickerParam.md)) => void | No| @Prop | Callback invoked when the casting state changes.|

## Events

The [universal events](../apis-arkui/arkui-ts/ts-component-general-events.md) are supported.

## Example

The following is an example of using **AVCastPicker**:
<!--RP1--><!--RP1End-->

```ts
import { AVCastPickerState, AVCastPicker } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {

  @State pickerImage: ResourceStr = $r('app.media.castPicker'); // Custom resources.

  private onStateChange(state: AVCastPickerState) {
    if (state == AVCastPickerState.STATE_APPEARING) {
      console.log('The picker starts showing.');
    } else if (state == AVCastPickerState.STATE_DISAPPEARING) {
      console.log('The picker finishes presenting.');
    }
  }

  @Builder
  customPickerBuilder(): void {
    Image(this.pickerImage)
      .width('100%')
      .height('100%')
      .fillColor(Color.Black)
  }

  build() {
    Row() {
      Column() {
        AVCastPicker({
          normalColor: Color.Red,
          customPicker: () => this.customPickerBuilder(),
          onStateChange: this.onStateChange
        })
          .width('40vp')
          .height('40vp')
          .border({ width: 1, color: Color.Red })
      }.height('50%')
    }.width('50%')
  }
}
```

 <!--no_check--> 