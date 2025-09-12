# @ohos.multimedia.avVolumePanel (Volume Panel)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

The module provides the capability of displaying the system volume panel for users to adjust the volume.

An application cannot directly adjust the system volume. However, it can invoke the system volume panel for users to adjust the volume. When the user adjusts the volume, a volume prompt UI is displayed to explicitly notify the user that the system volume changes.


> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The sample effect is subject to the real device in use. Currently, DevEco Studio Previewer cannot display the actual volume or adjust the volume.
> - **Device restrictions**
>   - On wearable devices, the module can be used to adjust the system volume, but no UI is displayed. You need to design the UI by yourself.

## Modules to Import

```js
import { AVVolumePanel } from '@kit.AudioKit';
```

## Properties

The [universal properties](../apis-arkui/arkui-ts/ts-component-general-attributes.md) are supported.

## AVVolumePanel

AVVolumePanel({volumeLevel?: number, volumeParameter?: AVVolumePanelParameter})

Volume panel, which can be used to display the volume adjustment panel in your application.

**Decorator**: [@Component](../../ui/state-management/arkts-create-custom-components.md)

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name| Type| Mandatory| Decorator | Description                                                                                                                                                                                                   |
| -------- | -------- | -------- |--------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|volumeLevel | number | No| \@Prop | Target volume.<br>The value must be between the minimum volume and the maximum volume supported by the device.<br>If the value is greater than the maximum volume supported, the maximum volume is used.<br>If the value is less than the minimum volume supported, the minimum volume is used.<br>For details about how to obtain the maximum value, minimum value, and current value, see [AudioVolumeGroupManager](../apis-audio-kit/arkts-apis-audio-AudioVolumeGroupManager.md).|
|volumeParameter | [AVVolumePanelParameter](#avvolumepanelparameter)  | No| \@Prop |Custom parameter of the volume panel.<br>If this parameter is not set, the volume bar appears at the system default location.|

## AVVolumePanelParameter

Describes the volume panel parameters.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Audio.Volume

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
|position | [Position](../apis-arkui/arkui-ts/ts-types.md#position) | No| Position of the volume panel.<br>If this parameter is not set, the volume bar appears at the system default location.<br>If this parameter is set to a position within the screen, the volume bar appears at the specified location.<br>If this parameter is set to a position outside the screen, such as (-1, -1), the system volume bar is not displayed. In this case, you should consider implementing a custom volume bar.|

## Events

The [universal events](../apis-arkui/arkui-ts/ts-component-general-events.md) are supported.

## How to Use

1. When customizing the volume bar, you are advised to use the volume change listener of the audio framework to obtain the volume type (**volumeEvent.volumeType**), volume level (**volumeEvent.volume**), and whether to display the volume bar (**volumeEvent.updateUi**). The applications can determine whether to handle the current data and display their custom volume bar. For details, see [Volume Change Callback](arkts-apis-audio-AudioVolumeManager.md#onstreamvolumechange20).
2. To ensure users are aware of volume changes, applications are not allowed to adjust the volume in the background. The system will take corresponding control measures.

## Example

To see how the volume panel works, refer to the sample code below. To experience the volume adjustment, you'll need to change the **volume** value or press the volume buttons.

```ts
import { AVVolumePanel } from '@kit.AudioKit';

@Entry
@Component
struct Index {

  @State volume: number = 0;

  build() {
    Row() {
      Column() {
        AVVolumePanel({
          volumeLevel: this.volume,
          volumeParameter: {
            position: {
              x: 100,
              y: 200
            }
          }
        })
      }
    }.width('50%').height('50%')
  }
}
```
