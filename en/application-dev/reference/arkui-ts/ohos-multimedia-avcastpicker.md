# @ohos.multimedia.avCastPicker (AVCastPicker)

The **AVCastPicker** component provides a unified entry for device discovery and connection.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.
> - This component can only be used from the device selection screen, which needs to be implemented by OEM vendors.

## Modules to Import

```js
import AVCastPicker from '@ohos.multimedia.avCastPicker';
```

## APIs

AVCastPicker()

Implements an **AVCastPicker** component, which can be used to cast audio and video onto other devices.

This component is a custom component. Some basic knowledge of [@Component](../../quick-start/arkts-create-custom-components.md) will be helpful in using the component.

**System capability**: SystemCapability.Multimedia.AVSession.AVCast

## Attributes

The [universal attributes](ts-universal-attributes-size.md) are supported.

## Events

The [universal events](ts-universal-events-click.md) are supported.

## Example

The following is an example of using **AVCastPicker**:

```ts
import AVCastPicker from '@ohos.multimedia.avCastPicker'

@Entry
@Component
struct Index {
  build() {
    Row() {
      Column() {
        AVCastPicker()
          .width('40vp')
          .height('40vp')
          .border({ width: 1, color: Color.Red })
      }.height('50%')
    }.width('50%')
  }
}
```
