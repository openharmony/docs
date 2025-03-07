# @ohos.multimedia.cameraPicker (Camera Picker)

The cameraPicker module provides APIs for an application to select the system camera to take photos or record videos, depending on the media type specified by the application. The APIs of this module must be called in a UIAbility of the page type. Otherwise, the camera picker cannot be started.

The camera picker must be called in release mode. If it is called in debug mode, an exception occurs.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { cameraPicker as picker } from '@kit.CameraKit';
```

## pick

pick(context: Context, mediaTypes: Array\<PickerMediaType\>, pickerProfile: PickerProfile): Promise\<PickerResult\>

Starts the camera picker and enters the corresponding mode based on the media type. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name         | Type                                             | Mandatory| Description                          |
| -------------- |-------------------------------------------------| ---- | ---------------------------- |
| context        | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Application context.                  |
| mediaTypes     | Array\<[PickerMediaType](#pickermediatype)\>    | Yes  | Media type.                   |
| pickerProfile  | [PickerProfile](#pickerprofile)                 | Yes  | Profile of the camera picker.           |

**Return value**

| Type                                            | Description                                                                                  |
| ----------------------------------------------- | -------------------------------------------------------------------------------------- |
| Promise\<PickerResult\>                         | Promise used to return the result, which is specified by [PickerResult](#pickerresult).          |


**Example**

```ts
import { cameraPicker as picker } from '@kit.CameraKit';
import { camera } from '@kit.CameraKit';
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let mContext = getContext(this) as common.Context;

async function demo() {
  try {
    let pickerProfile: picker.PickerProfile = {
      cameraPosition: camera.CameraPosition.CAMERA_POSITION_BACK
    };
    let pickerResult: picker.PickerResult = await picker.pick(mContext,
      [picker.PickerMediaType.PHOTO, picker.PickerMediaType.VIDEO], pickerProfile);
    console.log("the pick pickerResult is:" + JSON.stringify(pickerResult));
  } catch (error) {
    let err = error as BusinessError;
    console.error(`the pick call failed. error code: ${err.code}`);
  }
}
```

## PickerMediaType

Enumerates the media types displayed in the camera picker.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name            | Value   | Description    |
| ----------------| ----  | ---------|
| PHOTO           | photo | Photo mode. |
| VIDEO           | video | Record mode. |


## PickerProfile

Defines the configuration information about the camera picker.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                              | Mandatory  | Description        |
| -------------- | --------------------------------- | ----- | ------------ |
| cameraPosition       | [camera.CameraPosition](js-apis-camera.md#cameraposition) | Yes   | Camera position.  |
| saveUri        | string                            | No   | URI for saving the configuration information.|
| videoDuration  | number                            | No   | Maximum recording duration.|


## PickerResult

Defines the processing result of the camera picker.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                               | Mandatory | Description                           |
| -------------- | ---------------------------------- | ----- | -------------------------------- |
| resultCode     | number                             | Yes   | Result code. The value **0** means that the processing is successful, and **-1** means that the processing fails.|
| resultUri      | string                             | Yes   | URI of the result. If **saveUri** is empty, **resultUri** is a public media path. If **saveUri** is not empty and the application has the write permission on the URI, the value of **resultUri** is the same as that of **saveUri**. If **saveUri** is not empty and the application does not have the write permission on the URI, **resultUri** cannot be obtained.|
| mediaType      | [PickerMediaType](#pickermediatype)| Yes   | Media type.                 |
