# @ohos.multimedia.camera (Camera Management)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```js
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

Obtains a **CameraManager** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](js-apis-inner-app-context.md)      | Yes  | Application context.                  |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](#cameramanager)           | **CameraManager** instance obtained.                  |

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```js
let cameraManager = camera.getCameraManager(context);
```

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.    |
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.      |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.    |

## Profile

Defines the camera profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| format   | [CameraFormat](#cameraformat) | Yes | Output format.     |
| size     | [Size](#size)                 | Yes | Resolution.      |

## FrameRateRange

Defines the frame rate range.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Mandatory| Description        |
| -------- | ----------------------------- |---- | ------------- |
| min      | number                        | Yes | Minimum frame rate.     |
| max      | number                        | Yes | Maximum frame rate.     |

## VideoProfile

Defines the video profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Mandatory| Description       |
| ------------------------- | ----------------------------------------- | --- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | Yes | Frame rate range.  |

## CameraOutputCapability

Defines the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                              | Mandatory| Description               |
| ----------------------------- | -------------------------------------------------- | --- |------------------- |
| previewProfiles               | Array<[Profile](#profile)\>                        | Yes | Supported preview profiles.   |
| photoProfiles                 | Array<[Profile](#profile)\>                        | Yes | Supported shooting profiles.   |
| videoProfiles                 | Array<[VideoProfile](#videoprofile)\>              | Yes | Supported video recording profiles.   |
| supportedMetadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Supported metadata object types.|

## CameraErrorCode

Enumerates the camera error codes, which are returned when an API call is incorrect or the **on()** API is used to listen for the error status.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description           |
| ------------------------- | ---- | ------------    |
| INVALID_ARGUMENT       | 7400101    | A parameter is missing or the parameter type is incorrect.  |
| OPERATION_NOT_ALLOWED    | 7400102    | The operation is not allowed.    |
| SESSION_NOT_CONFIG    | 7400103    | The session is not configured.      |
| SESSION_NOT_RUNNING  | 7400104    | The session is not running.   |
| SESSION_CONFIG_LOCKED  | 7400105    | The session configuration is locked.    |
| DEVICE_SETTING_LOCKED  | 7400106    | The device setting is locked.    |
| CONFILICT_CAMERA  | 7400107    | The device is already started.    |
| DEVICE_DISABLED  | 7400108    | The camera is disabled for security reasons.    |
| SERVICE_FATAL_ERROR  | 7400201    | An error occurs in the camera service.    |

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use **getCameraManager** to obtain a **CameraManager** instance.

### getSupportedCameras

getSupportedCameras(): Array<CameraDevice\>

Obtains supported cameras. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
|  Array<[CameraDevice](#cameradevice)>            | An array of supported cameras.                  |

**Example**

```js
let cameras = cameraManager.getSupportedCameras();

```

### getSupportedOutputCapability

getSupportedOutputCapability(cameraDevice:CameraDevice): CameraOutputCapability

Obtains the output capability supported by a camera. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | Yes| Target camera, which is obtained through **getSupportedCameras**.      |

**Return value**

| Type                                            | Description                          |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | Camera output capability obtained.                  |

**Example**

```js
let cameraDevice = cameras[0];
let cameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);

```

### isCameraMuted

isCameraMuted(): boolean

Checks whether the camera is muted.

Before calling the API, ensure that the camera can be muted. You can use [isCameraMuteSupported](#iscameramutesupported) to check whether the camera can be muted.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                                        |
| ---------- | -------------------------------------------- |
| boolean    | Returns **true** if the camera is muted; returns **false** otherwise.|

**Example**

```js
let ismuted = cameraManager.isCameraMuted();
```

### isCameraMuteSupported

isCameraMuteSupported(): boolean

Checks whether the camera can be muted.

This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the camera can be muted; returns **false** otherwise.|

**Example**

```js
let ismutesuppotred = cameraManager.isCameraMuteSupported();
```

### muteCamera

muteCamera(mute: boolean): void

Mutes or unmutes the camera.

This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                             | Mandatory | Description       |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  Yes |  Whether to mute the camera. The value **true** means to mute the camera, and **false** means the opposite. |

**Example**

```js
let mute = true;
cameraManager.muteCamera(mute);
```

### createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

Creates a **CameraInput** instance with the specified **CameraDevice** object. This API returns the result synchronously.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| cameraDevice   | [CameraDevice](#cameradevice)         | Yes  | Target **CameraDevice** object, which is obtained through **getSupportedCameras**.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let cameraDevice = cameras[0];
let cameraInput;
try {
	cameraInput = cameraManager.createCameraInput(cameraDevice);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType): CameraInput

Creates a **CameraInput** instance with the specified camera position and type. This API returns the result synchronously.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](#cameraposition)           | Yes  | Camera position, which is obtained through **getSupportedCameras**. This API obtains a **CameraDevice** object, which contains the camera position information. |
| type     | [CameraType](#cameratype)                   | Yes  | Camera type, which is obtained through **getSupportedCameras**. This API obtains a **CameraDevice** object, which contains the camera type information. |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | **CameraInput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let cameraDevice = cameras[0];
let position = cameraDevice.cameraPosition;
let type = cameraDevice.cameraType;
let cameraInput;
try {
    cameraInput = cameraManager.createCameraInput(position, type);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput

Creates a **PreviewOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | Yes  | Supported preview profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string | Yes  | Surface ID, which is obtained from [XComponent](../arkui-ts/ts-basic-components-xcomponent.md) or [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | **PreviewOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let profile = cameraOutputCapability.previewProfiles[0];
let previewOutput;
try {
    previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

Creates a **PhotoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported shooting profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string            | Yes  | Surface ID, which is obtained from [ImageReceiver](js-apis-image.md#imagereceiver9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | **PhotoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let profile = cameraOutputCapability.photoProfiles[0];
let photoOutput;
try {
    photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput

Creates a **VideoOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                             |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](#videoprofile)               | Yes  | Supported video recording profiles, which are obtained through **getSupportedOutputCapability**.|
| surfaceId| string          | Yes  | Surface ID, which is obtained from [VideoRecorder](js-apis-media.md#videorecorder9).|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | **VideoOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let profile = cameraOutputCapability.videoProfiles[0];
let videoOutput;
try {
    videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>): MetadataOutput

Creates a **MetadataOutput** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Metadata object types, which are obtained through **getSupportedOutputCapability**.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [MetadataOutput](#metadataoutput)   | **MetadataOutput** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**Example**

```js
let metadataObjectTypes = cameraOutputCapability.supportedMetadataObjectTypes;
let metadataOutput;
try {
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### createCaptureSession

createCaptureSession(): CaptureSession

Creates a **CaptureSession** instance. This API returns the result synchronously.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CaptureSession](#capturesession)   | **CaptureSession** instance created. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**Example**

```js
let captureSession;
try {
    captureSession = cameraManager.createCaptureSession();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

Listens for camera status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type           | Mandatory| Description      |
| -------- | -----------------| ---- | --------- |
| type     | string           | Yes  | Event type. The value is fixed at **'cameraStatus'**. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the corresponding information is returned only when the device is enabled or disabled.|
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.|                 |

**Example**

```js
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.log(`status: ${cameraStatusInfo.status}`);
})
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback<boolean\>): void

Listens for camera mute status changes. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status. The event can be listened for when a **CameraManager** instance is obtained. This event is triggered and the status is returned when the camera is enabled or disabled.|
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the mute status. The value **true** means that the camera is enabled, and **false** means that the camera is disabled.              |

**Example**

```js
cameraManager.on('cameraMute', (curMuetd) => {
    let isMuted = curMuetd;
})
```

## CameraStatusInfo

Describes the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           |     Mandatory    | Description      |
| ------ | ----------------------------- | -------------- | ---------- |
| camera | [CameraDevice](#cameradevice) |        Yes      | Camera object.|
| status | [CameraStatus](#camerastatus) |        Yes       | Camera status.|

## CameraPosition

Enumerates the camera positions.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Value  | Description           |
| --------------------------- | ---- | -------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | Unspecified position. |
| CAMERA_POSITION_BACK        | 1    | Rear camera.      |
| CAMERA_POSITION_FRONT       | 2    | Front camera.      |

## CameraType

Enumerates the camera types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value  | Description           |
| ----------------------- | ---- | -------------- |
| CAMERA_TYPE_DEFAULT     | 0    | Unspecified camera type. |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | Wide camera.      |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | Ultra wide camera.    |
| CAMERA_TYPE_TELEPHOTO   | 3    | Telephoto camera.      |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | Camera with depth of field information.|

## ConnectionType

Enumerates the camera connection types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                         | Value  | Description          |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | Built-in camera.     |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | Camera connected using USB.|
| CAMERA_CONNECTION_REMOTE     | 2    | Remote camera.|

## CameraDevice

Defines the camera device information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                               | Mandatory| Description       |
| -------------- | --------------------------------- | ---- | ---------- |
| cameraId       | string                            | Yes  | **CameraDevice** object.|
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | Camera position.   |
| cameraType     | [CameraType](#cameratype)         | Yes  | Camera type.   |
| connectionType | [ConnectionType](#connectiontype) | Yes  | Camera connection type.|

## Size

Enumerates the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type  | Readable| Writable| Description        |
| ------ | ------ | ---- | ---- | ------------ |
| height | number | Yes  | Yes  | Image height, in pixels.|
| width  | number | Yes  | Yes  | Image width, in pixels.|

## Point

Enumerates the point coordinates, which are used for focus and exposure configuration.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type  | Mandatory  | Description        |
| ------ | ------ | ---- | ------------ |
| x      | number | Yes   | X coordinate of a point.  |
| y      | number | Yes   | Y coordinate of a point.  |

## CameraFormat

Enumerates the camera output formats.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                    | Value       | Description        |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGB image.            |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV 420 SP image.     |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG image.           |

## CameraInput

Provides camera information used in **[CaptureSession](#capturesession)**.

### open

open\(callback: AsyncCallback<void\>\): void

Opens this camera. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                 | Mandatory| Description                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```js
cameraInput.open((err) => {
    if (err) {
        console.error(`Failed to open the camera. ${err.code}`);
        return;
    }
    console.log('Callback returned with camera opened.');
})
```

### open

open(): Promise<void\>

Opens this camera. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```js
cameraInput.open().then(() => {
    console.log('Promise returned with camera opened.');
}).catch((err) => {
    console.error(`Failed to open the camera. ${err.code}`);
});
```

### close

close\(callback: AsyncCallback<void\>\): void

Closes this camera. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```js
cameraInput.close((err) => {
    if (err) {
        console.error(`Failed to close the cameras. ${err.code}`);
        return;
    }
    console.log('Callback returned with camera closed.');
})
```

### close

close(): Promise<void\>

Closes this camera. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**Example**

```js
cameraInput.close().then(() => {
    console.log('Promise returned with camera closed.');
}).catch((err) => {
    console.error(`Failed to close the cameras. ${err.code}`);
});
```

### on('error')

on(type: 'error', cameraDevice:CameraDevice, callback: ErrorCallback<BusinessError\>): void

Listens for **CameraInput** errors. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **CameraInput** instance is created. This event is triggered and the result is returned when an error occurs on the camera. For example, if the device is unavailable or a conflict occurs, the error information is returned.|
| cameraDevice   | [CameraDevice](#cameradevice)    | Yes  | **CameraDevice** object.|
| callback | ErrorCallback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).  |

**Example**

```js
let cameraDevice = cameras[0];
cameraInput.on('error', cameraDevice, (error) => {
    console.log(`Camera input error code: ${error.code}`);
})
```

## FlashMode

Enumerates the flash modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Value  | Description       |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | The flash is off.|
| FLASH_MODE_OPEN        | 1    | The flash is on.|
| FLASH_MODE_AUTO        | 2    | The flash mode is auto, indicating that the flash fires automatically depending on the shooting conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3    | The flash is steady on.|

## ExposureMode

Enumerates the exposure modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description        |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | Exposure locked.|
| EXPOSURE_MODE_AUTO            | 1    | Auto exposure.|
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | Continuous auto exposure.|

 ## FocusMode

Enumerates the focus modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                       | Value  | Description         |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | Manual focus.    |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | Continuous auto focus.|
| FOCUS_MODE_AUTO            | 2    | Auto focus.    |
| FOCUS_MODE_LOCKED          | 3    | Focus locked.    |

## FocusState

Enumerates the focus states.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Value  | Description      |
| --------------------- | ---- | --------- |
| FOCUS_STATE_SCAN      | 0    | Focusing. |
| FOCUS_STATE_FOCUSED   | 1    | Focused. |
| FOCUS_STATE_UNFOCUSED | 2    | Unfocused.|

## VideoStabilizationMode

Enumerates the video stabilization modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Value  | Description        |
| --------- | ---- | ------------ |
| OFF       | 0    | Video stabilization is disabled.  |
| LOW       | 1    | The basic video stabilization algorithm is used.  |
| MIDDLE    | 2    | A video stabilization algorithm with a stabilization effect better than that of the **LOW** type is used.  |
| HIGH      | 3    | A video stabilization algorithm with a stabilization effect better than that of the **MIDDLE** type is used.  |
| AUTO      | 4    | Automatic video stabilization is used.  |

## CaptureSession

Implements a shooting session, which saves all **[CameraInput](#camerainput)** and **[CameraOutput](#cameraoutput)** instances required to run the camera and requests the camera to complete shooting or video recording.

### beginConfig

beginConfig(): void

Starts configuration for the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400105                |  Session config locked.               |

**Example**

```js
try {
    captureSession.beginConfig();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### commitConfig

commitConfig(callback: AsyncCallback<void\>): void

Commits the configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.commitConfig((err) => {
    if (err) {
        console.log('Failed to commitConfig '+ err.code);
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});
```

### commitConfig

commitConfig(): Promise<void\>

Commits the configuration for this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                     |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
}).catch((err) => {
    // If the operation fails, error.code is returned and processed.
    console.log('Failed to commitConfig '+ err.code);
});
```

### addInput

addInput(cameraInput: CameraInput): void

Adds a [CameraInput](#camerainput) instance to the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```js
try {
    captureSession.addInput(cameraInput);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### removeInput

removeInput(cameraInput: CameraInput): void

Removes a [CameraInput](#camerainput) instance from the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```js
try {
    captureSession.removeInput(cameraInput);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### addOutput

addOutput(previewOutput: CameraOutput): void

Adds a [CameraOutput](#cameraoutput) instance to the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | Yes  | **PreviewOutput** instance to add.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```js
try {
    captureSession.addOutput(previewOutput);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### removeOutput

removeOutput(previewOutput: CameraOutput): void

Removes a [CameraOutput](#cameraoutput) instance from the session.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | Yes  | **PreviewOutput** instance to remove.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**Example**

```js
try {
    captureSession.removeOutput(previewOutput);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### start

start\(callback: AsyncCallback<void\>\): void

Starts this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.start((err) => {
    if (err) {
        console.error(`Failed to start the session ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the session start success.');
});
```

### start

start\(\): Promise<void\>

Starts this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
}).catch((err) => {
    console.error(`Failed to start the session ${err.code}`);
});
```

### stop

stop\(callback: AsyncCallback<void\>\): void

Stops this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.stop((err) => {
    if (err) {
        console.error(`Failed to stop the session ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});
```

### stop

stop(): Promise<void\>

Stops this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
}).catch((err) => {
    console.error(`Failed to stop the session ${err.code}`);
});
```

### release

release\(callback: AsyncCallback<void\>\): void

Releases this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.release((err) => {
    if (err) {
        console.error(`Failed to release the CaptureSession instance ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
}).catch((err) => {
    console.error(`Failed to release the CaptureSession instance ${err.code}`);
});
```

### hasFlash

hasFlash(): boolean

Checks whether the device has flash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the device has flash; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let status = captureSession.hasFlash();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode): boolean

Checks whether a flash mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                              |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.                    |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the flash mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setFlashMode

setFlashMode(flashMode: FlashMode): void

Sets a flash mode for the device.

Before the setting, do the following checks:

1. Use **[hasFlash](#hasflash)** to check whether the device has flash.
2. Use **[isFlashModeSupported](#isflashmodesupported)** to check whether the device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.      |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getFlashMode

getFlashMode(): FlashMode

Obtains the flash mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | Flash mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let flashMode = captureSession.getFlashMode();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): boolean;

Checks whether an exposure mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.                     |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the exposure mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getExposureMode

getExposureMode(): ExposureMode

Obtains the exposure mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | Exposure mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let exposureMode = captureSession.getExposureMode();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setExposureMode

setExposureMode(aeMode: ExposureMode): void

Sets an exposure mode for the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.               |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getMeteringPoint

getMeteringPoint(): Point

Obtains the metering point of the device.  

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Metering point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let exposurePoint = captureSession.getMeteringPoint();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setMeteringPoint

setMeteringPoint(point: Point): void

Sets the metering point, which is the center point of the metering rectangle.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | Yes  | Exposure point.             |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
const exposurePoint = {x: 1, y: 1};
try {
    captureSession.setMeteringPoint(exposurePoint);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getExposureBiasRange

getExposureBiasRange(): Array<number\>

Obtains the exposure compensation values of the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array<number\>   | An array of compensation values. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let biasRangeArray = captureSession.getExposureBiasRange();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setExposureBias

setExposureBias(exposureBias: number): void

Sets an exposure compensation value (EV).

Before the setting, you are advised to use **[getExposureBiasRange](#getexposurebiasrange)** to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | Yes  | Exposure bias to set, which must be within the range obtained by running **getExposureBiasRange** interface. If the API call fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
let exposureBias = biasRangeArray[0];
try {
    captureSession.setExposureBias(exposureBias);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getExposureValue

getExposureValue(): number

Obtains the exposure value in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Exposure value obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let exposureValue = captureSession.getExposureValue();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode): boolean

Checks whether a focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the focus mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setFocusMode

setFocusMode(afMode: FocusMode): void

Sets a focus mode for the device.

Before the setting, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.      |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getFocusMode

getFocusMode(): FocusMode

Obtains the focus mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | Focus mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let afMode = captureSession.getFocusMode();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setFocusPoint

setFocusPoint(point: Point): void

Sets the focal point.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| Point1    | [Point](#point)         | Yes  | Focal point.               |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
const Point1 = {x: 1, y: 1};
try {
    captureSession.setFocusPoint(Point1);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getFocusPoint

getFocusPoint(): Point

Obtains the focal point of the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [Point](#point)    | Focal point obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let point = captureSession.getFocusPoint();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getFocalLength

getFocalLength(): number

Obtains the focal length of the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Focal length obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let focalLength = captureSession.getFocalLength();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getZoomRatioRange

getZoomRatioRange(): Array<number\>

Obtains the supported zoom ratio range.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| Array<number\>   | Callback used to return an array containing the minimum and maximum zoom ratios. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let zoomRatioRange = captureSession.getZoomRatioRange();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setZoomRatio

setZoomRatio(zoomRatio: number): void

Sets a zoom ratio.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory| Description                |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | Yes  | Zoom ratio. You can use **getZoomRatioRange** to obtain the supported values.|

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
let zoomRatio = zoomRatioRange[0];
try {
    captureSession.setZoomRatio(zoomRatio);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getZoomRatio

getZoomRatio(): number

Obtains the zoom ratio in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| number    | Zoom ratio obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let zoomRatio = captureSession.getZoomRatio();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

Checks whether the specified video stabilization mode is supported. 

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.                   |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the video stabilization mode is supported; returns **false** otherwise. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(): VideoStabilizationMode

Obtains the video stabilization mode in use.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| VideoStabilizationMode    | Video stabilization mode obtained. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    let vsMode = captureSession.getActiveVideoStabilizationMode();
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode): void

Sets a video stabilization mode for the device.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
} catch (error) {
    // If the operation fails, error.code is returned and processed.
    console.log(error.code);
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

Listens for focus state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**. The event can be listened for when a session is created. This event is triggered only when the camera focus state changes in auto focus mode.|
| callback | AsyncCallback<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```js
captureSession.on('focusStateChange', (focusState) => {
    console.log(`Focus state  : ${focusState}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

Listens for **CaptureSession** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a session is created. This event is triggered and the error message is returned when an error occurs during the calling of a session-related API such as **beginConfig()**, **commitConfig()**, and **addInput**.|
| callback | ErrorCallback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).       |

**Example**

```js
captureSession.on('error', (error) => {
    console.log(`Capture session error code: ${error.code}`);
})
```

## CameraOutput

Implements output information used in a **[CaptureSession](#capturesession)**. It is the base class of **output**.

## PreviewOutput

Implements preview output. It inherits **[CameraOutput](#cameraoutput)**.

### start

start(callback: AsyncCallback<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
previewOutput.start((err) => {
    if (err) {
        console.error(`Failed to start the previewOutput. ${err.code}`);
        return;
    }
    console.log('Callback returned with previewOutput started.');
})
```

### start

start(): Promise<void\>

Starts to output preview streams. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**Example**

```js
previewOutput.start().then(() => {
    console.log('Promise returned with previewOutput started.');
}).catch((err) => {
    console.log('Failed to previewOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

Stops outputting preview streams. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
previewOutput.stop((err) => {
    if (err) {
        console.error(`Failed to stop the previewOutput. ${err.code}`);
        return;
    }
    console.log('Callback returned with previewOutput stopped.');
})
```

### stop

stop(): Promise<void\>

Stops outputting preview streams. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
previewOutput.stop().then(() => {
    console.log('Callback returned with previewOutput stopped.');
}).catch((err) => {
    console.log('Failed to previewOutput stop '+ err.code);
});
```

### release

release(callback: AsyncCallback<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
previewOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to previewOutput release '+ err.code);
});
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for preview frame start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. The preview starts as long as this event is returned.                    |

**Example**

```js
previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

Listens for preview frame end events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                 |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and returned when the last frame of preview ends.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. The preview ends as long as this event is returned.                |

**Example**

```js
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

Listens for **PreviewOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                      |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **previewOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the use of a preview-related API such as **start()** or **release()**.|
| callback | ErrorCallback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode). |

**Example**

```js
previewOutput.on('error', (previewOutputError) => {
    console.log(`Preview output error code: ${previewOutputError.code}`);
})
```

## ImageRotation

Enumerates the image rotation angles.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Value  | Description          |
| ------------ | ---- | ------------- |
| ROTATION_0   | 0    | The image rotates 0 degrees.  |
| ROTATION_90  | 90   | The image rotates 90 degrees. |
| ROTATION_180 | 180  | The image rotates 180 degrees.|
| ROTATION_270 | 270  | The image rotates 270 degrees.|

## Location

Defines geolocation information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Type  | Mandatory|Description        |
| ------------ | ------ | --- |------------ |
| latitude     | number | Yes |Latitude, in degrees.   |
| longitude    | number | Yes |Longitude, in degrees.   |
| altitude     | number | Yes |Altitude, in meters.   |

## QualityLevel

Enumerates the image quality levels.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                 | Value  | Description        |
| -------------------- | ---- | ------------ |
| QUALITY_LEVEL_HIGH   | 0    | High image quality.  |
| QUALITY_LEVEL_MEDIUM | 1    | Medium image quality.|
| QUALITY_LEVEL_LOW    | 2    | Low image quality.  |


## PhotoCaptureSetting

Defines the settings for photo capture.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                           | Mandatory | Description             |
| -------- | ------------------------------- | ---- | -----------------|
| quality  | [QualityLevel](#qualitylevel)   | No  | Photo quality.        |
| rotation | [ImageRotation](#imagerotation) | No  | Rotation angle of the photo.     |
| location | [Location](#location)           | No  | Geolocation information of the photo.  |
| mirror   | boolean                         | No  |Whether mirroring is enabled. By default, mirroring is disabled.|

## PhotoOutput

Implements output information used in a shooting session. This class inherits from [CameraOutput](#cameraoutput).

### capture

capture(callback: AsyncCallback<void\>): void

Captures a photo with the default shooting parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
photoOutput.capture((err) => {
    if (err) {
        console.error(`Failed to capture the photo ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

### capture

capture(): Promise<void\>

Captures a photo with the default shooting parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
}).catch((err) => {
    console.log('Failed to photoOutput capture '+ err.code);
});
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback<void\>): void

Captures a photo with the specified shooting parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                        | Mandatory| Description                 |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | Yes  | Shooting settings.            |
| callback | AsyncCallback<void\>                        | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned. |

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
let captureLocation = {
  latitude: 0,
  longitude: 0,
  altitude: 0,
}
let settings = {
  quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
  rotation: camera.ImageRotation.ROTATION_0,
  location: captureLocation,
  mirror: false
}
photoOutput.capture(settings, (err) => {
    if (err) {
        console.error(`Failed to capture the photo ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

### capture

capture(setting?: PhotoCaptureSetting): Promise<void\>

Captures a photo with the specified shooting parameters. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description     |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | No  | Shooting settings.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
photoOutput.capture(settings).then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
}).catch((err) => {
    console.log('Failed to photoOutput capture '+ err.code);
});
```

### isMirrorSupported

isMirrorSupported(): boolean

Checks whether mirroring is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| boolean | Returns **true** if mirroring is supported; returns **false** otherwise.|

**Example**

```js
let isSupported = photoOutput.isMirrorSupported();
```

### release

release(callback: AsyncCallback<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
photoOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to photoOutput release '+ err.code);
});
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

Listens for shooting start events. This API uses an asynchronous callback to return the capture ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and returned when the bottom layer starts exposure each time a photo is taken.|
| callback | AsyncCallback<number\> | Yes  | Callback used to return the capture ID.           |

**Example**

```js
photoOutput.on('captureStart', (captureId) => {
    console.log(`photo capture stated, captureId : ${captureId}`);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

Listens for frame shutter events. This API uses an asynchronous callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type     | Mandatory| Description                                 |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | Yes  | Event type. The value is fixed at **'frameShutter'**. The event can be listened for when a **photoOutput** instance is created.|
| callback | AsyncCallback<[FrameShutterInfo](#frameshutterinfo)\> | Yes  | Callback used to return the result. A new photographing request can be delivered as long as this event is returned.            |

**Example**

```js
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

Listens for shooting end events. This API uses an asynchronous callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type          | Mandatory| Description                                      |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | Yes  | Event type. The value is fixed at **'captureEnd'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding information is returned when the photographing is complete.|
| callback | AsyncCallback<[CaptureEndInfo](#captureendinfo)\> | Yes  | Callback used to return the result.                 |

**Example**

```js
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.log(`frameCount : ${captureEndInfo.frameCount}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

Listens for **PhotoOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **photoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a photographing-related API.|
| callback | ErrorCallback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).            |

**Example**

```js
photoOutput.on('error', (error) => {
    console.log(`Photo output error code: ${error.code}`);
})
```

## FrameShutterInfo

Defines the frame shutter information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ---------- |
| captureId | number | Yes  | ID of this capture action. |
| timestamp | number | Yes  | Timestamp when the frame shutter event is triggered.|

## CaptureEndInfo

Defines the capture end information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name      | Type  | Mandatory| Description      |
| ---------- | ------ | ---- | ---------|
| captureId  | number | Yes  | ID of this capture action.|
| frameCount | number | Yes  | Number of frames captured.   |

## VideoOutput

Implements output information used in a video recording session. This class inherits from [CameraOutput](#cameraoutput).

### start

start(callback: AsyncCallback<void\>): void

Starts video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
videoOutput.start((err) => {
    if (err) {
        console.error(`Failed to start the video output ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the video output start success.');
});
```

### start

start(): Promise<void\>

Starts video recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
}).catch((err) => {
    console.log('Failed to videoOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

Stops video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
videoOutput.stop((err) => {
    if (err) {
        console.error(`Failed to stop the video output ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
});
```

### stop

stop(): Promise<void\>

Stops video recording. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
videoOutput.stop().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
}).catch((err) => {
    console.log('Failed to videoOutput stop '+ err.code);
});
```

### release

release(callback: AsyncCallback<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
videoOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.code}`);
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases output resources. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to videoOutput release '+ err.code);
});
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for video recording start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**. The event can be listened for when a **videoOutput** instance is created. The event is triggered and the corresponding information is returned when the bottom layer starts exposure for the first time.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.  The recording starts as long as this event is returned.                    |

**Example**

```js
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

Listens for video recording stop events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and returned when the last frame of recording is complete.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result. The recording ends as long as this event is returned.                     |

**Example**

```js
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

Listens for errors that occur during video recording. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type      | Mandatory| Description                                   |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **videoOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a recording-related API such as **start()** and **release()**.|
| callback | Callback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).                |

**Example**

```js
videoOutput.on('error', (error) => {
    console.log(`Video output error code: ${error.code}`);
})
```

## MetadataOutput

Implements metadata streams. It inherits **[CameraOutput](#cameraoutput)**.

### start

start(callback: AsyncCallback<void\>): void

Starts to output metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>       | Yes  | Callback used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
metadataOutput.start((err) => {
    if (err) {
        console.error(`Failed to start metadataOutput. ${err.code}`);
        return;
    }
    console.log('Callback returned with metadataOutput started.');
})
```

### start

start(): Promise<void\>

Starts to output metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                    | Description                    |
| ----------------------  | ------------------------ |
| Promise<void\>         | Promise used to return the result. If the operation fails, an error code defined in [CameraErrorCode](#cameraerrorcode) is returned.|

**Error codes**

For details about the error codes, see [CameraErrorCode](#cameraerrorcode).

| ID        | Error Message       |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**Example**

```js
metadataOutput.start().then(() => {
    console.log('Callback returned with metadataOutput started.');
}).catch((err) => {
    console.log('Failed to metadataOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

Stops outputting metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                        | Mandatory| Description                 |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>       | Yes  | Callback used to return the result.|

**Example**

```js
metadataOutput.stop((err) => {
    if (err) {
        console.error(`Failed to stop the metadataOutput. ${err.code}`);
        return;
    }
    console.log('Callback returned with metadataOutput stopped.');
})
```

### stop

stop(): Promise<void\>

Stops outputting metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                   | Description                       |
| ----------------------  | --------------------------- |
| Promise<void\>        | Promise used to return the result.|

**Example**

```js
metadataOutput.stop().then(() => {
    console.log('Callback returned with metadataOutput stopped.');
}).catch((err) => {
    console.log('Failed to metadataOutput stop '+ err.code);
});
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback<Array<MetadataObject\>\>): void

Listens for metadata objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type        | Mandatory| Description                                 |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | Yes  | Event type. The value is fixed at **'metadataObjectsAvailable'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding metadata is returned when valid metadata is detected.|
| callback | Callback<Array<[MetadataObject](#metadataobject)\>\> | Yes  | Callback used to return the metadata.|

**Example**

```js
metadataOutput.on('metadataObjectsAvailable', (metadataObjectArr) => {
    console.log(`metadata output metadataObjectsAvailable`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

Listens for metadata errors. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type        | Mandatory| Description                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | Yes  | Event type. The value is fixed at **'error'**. The event can be listened for when a **metadataOutput** instance is created. This event is triggered and the corresponding error message is returned when an error occurs during the calling of a metadata-related API such as **start()** and **release()**.|
| callback | Callback<BusinessError\> | Yes  | Callback used to return an error code defined in [CameraErrorCode](#cameraerrorcode).           |

**Example**

```js
metadataOutput.on('error', (metadataOutputError) => {
    console.log(`Metadata output error code: ${metadataOutputError.code}`);
})
```

## MetadataObjectType

Enumerates the metadata object types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description             |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | Face detection.|

## Rect

Defines a rectangle.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  |      Mandatory    |           Description                |
| -------- | ------ | --------------- | -------------------- |
| topLeftX | number |        Yes         | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number |         Yes         | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number |         Yes        | Width of the rectangle.             |
| height   | number |         Yes          |Height of the rectangle.             |

## MetadataObject

Implements camera metadata, which is the data source of [CameraInput](#camerainput). The metadata is obtained through metadataOutput.on('metadataObjectsAvailable').

| Name     | Type                           | Mandatory | Description             |
| -------- | ------------------------------- | ---- | -----------------|
| type  | [MetadataObjectType](#metadataobjecttype)   | No  | Metadata data type. Only face recognition is supported.|
| timestamp | number | No  | Current timestamp, in milliseconds.|
| boundingBox | [Rect](#rect)           | No  | Metadata rectangle.|
