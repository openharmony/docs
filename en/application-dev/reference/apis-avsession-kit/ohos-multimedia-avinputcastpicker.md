# @ohos.multimedia.avInputCastPicker (AVInputCastPicker)
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

The module provides the functionality to create an **AVInputCastPicker** component, which offers a unified entry for discovering and connecting recording devices.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 20. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The Preview in DevEco Studio does not support actual recording device selection. To see the real effect, test on a real device.<!--Del-->
> - This component can only be used from the recording device selection screen, which needs to be implemented by OEM vendors.
> - This component can only be used on PCs.<!--DelEnd-->

## Modules to Import

```js
import { AVInputCastPicker } from '@kit.AVSessionKit';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-component-general-attributes.md) are supported.

## AVInputCastPicker

```
AVInputCastPicker({
  customPicker?: CustomBuilder;
  onStateChange?: OnPickerStateCallback;
})
```

Implements an **AVInputCastPicker** component, which can be used to switch audio input devices.

This component is a custom component. Some basic knowledge of [@Component](../../ui/state-management/arkts-create-custom-components.md#component) will be helpful in using the component.

**Decorator**: [@Component](../../ui/state-management/arkts-create-custom-components.md#component)

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVInputCast

**Parameters**

| Name| Type| Mandatory| Decorator| Description|
| -------- | -------- | -------- | -------- | -------- |
| customPicker | [CustomBuilder](../apis-arkui/arkui-ts/ts-types.md#custombuilder8) | No| @Prop | Custom style. You are advised to customize a component style so that the component can be displayed quickly.|
| onStateChange | [OnPickerStateCallback](#onpickerstatecallback) | No| - | Callback invoked when the device list state changes.|

## OnPickerStateCallback
type OnPickerStateCallback = (state: AVCastPickerState) => void

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.Multimedia.AVSession.AVInputCast

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| state | [AVCastPickerState](js-apis-avCastPickerParam.md#avcastpickerstate11) | Yes| Device list state.|

## Events

The [universal events](../apis-arkui/arkui-ts/ts-component-general-events.md) are supported.

## Example

The following is an example of using **AVCastPicker**:

```ts
import { AVCastPickerState, AVInputCastPicker } from '@kit.AVSessionKit';

@Entry
@Component
struct Index {

  @State pickerImage: ResourceStr = $r('app.media.castPicker'); // Custom resources.

  private onStateChange(state: AVCastPickerState) {
    if (state == AVCastPickerState.STATE_APPEARING) {
      console.info('The picker starts showing.');
    } else if (state == AVCastPickerState.STATE_DISAPPEARING) {
      console.info('The picker finishes presenting.');
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
        AVInputCastPicker({
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
