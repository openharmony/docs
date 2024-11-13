# @ohos.multimedia.avVolumePanel (Volume Panel)

The avVolumePanel module provides the capability of displaying the system volume panel for users to adjust the volume.

An application cannot directly adjust the system volume. However, it can invoke the system volume panel for users to adjust the volume. When the user adjusts the volume, a volume prompt UI is displayed to explicitly notify the user that the system volume changes.


> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The sample effect is subject to the real device in use. Currently, DevEco Studio Previewer cannot display the actual volume or adjust the volume.
> <!--RP1--><!--RP1End-->

## Modules to Import

```js
import { AVVolumePanel } from '@kit.AudioKit';
```
## Attributes

The [universal attributes](../apis-arkui/arkui-ts/ts-universal-attributes-size.md) are supported.

## AVVolumePanel

AVVolumePanel({volumeLevel?: number, volumeParameter?: AVVolumePanelParameter})

Volume panel, which can be used to display the volume adjustment panel in your application.

**Decorator**: [@Component](../../quick-start/arkts-create-custom-components.md)

**System capability**: SystemCapability.Multimedia.Audio.Volume

## Attributes

In addition to the [universal attributes](../apis-arkui/arkui-ts/ts-universal-attributes-size.md), the following attributes are supported.

**Parameters**

| Name| Type| Mandatory| Decorator| Description                                                                                                                                                                                                   |
| -------- | -------- | -------- | -------- |-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|volumeLevel | number | No| @Prop | Target volume. The value must be between the minimum volume and the maximum volume supported by the device. If the value is greater than the maximum volume supported, the maximum volume is used. If the value is less than the minimum volume supported, the minimum volume is used. For details about how to obtain the maximum and minimum volume values, see [AudioVolumeGroupManager](../apis-audio-kit/js-apis-audio.md#audiovolumegroupmanager9).|
|volumeParameter | [AVVolumePanelParameter](#avvolumepanelparameter)  | No|  @Prop | Custom parameter of the volume panel. If this parameter is not passed in, the system volume bar is invoked.                                                                                                                                                                     |

## AVVolumePanelParameter

| Name| Type| Mandatory| Description
| -------- | -------- | -------- | -------- |
|position | [Position](../apis-arkui/arkui-ts/ts-types.md#position) | No| Position of the volume panel.|

## Events

The [universal events](../apis-arkui/arkui-ts/ts-universal-events-click.md) are supported.

## Example

Refer to the sample code below to develop a volume panel:

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
