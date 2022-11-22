# Camera Management

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void

Obtains a **CameraManager** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                          |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](../../ability/context-userguide.md)      | Yes  | Application context.                  |
| callback | AsyncCallback<[CameraManager](#cameramanager)\> | Yes  | Callback used to return the **CameraManager** instance.|

**Example**

```js
camera.getCameraManager(context, (err, cameraManager) => {
    if (err) {
        console.error(`Failed to get the CameraManager instance ${err.message}`);
        return;
    }
    console.log('Callback returned with the CameraManager instance');
});
```

## camera.getCameraManager

getCameraManager(context: Context): Promise<CameraManager\>

Obtains a **CameraManager** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type   | Mandatory| Description        |
| ------- | ------- | ---- | ------------ |
| context | [Context](../../ability/context-userguide.md) | Yes  | Application context.|

**Return value**

| Type                                     | Description                                 |
| ----------------------------------------- | ----------------------------------- |
| Promise<[CameraManager](#cameramanager)\> | Promise used to return the **CameraManager** instance.|

**Example**

```js
camera.getCameraManager(context).then((cameraManager) => {
    console.log('Promise returned with the CameraManager instance.');
})
```

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                     | Value  | Description        |
| ------------------------- | ---- | ------------ |
| CAMERA_STATUS_APPEAR      | 0    | A camera appears.  |
| CAMERA_STATUS_DISAPPEAR   | 1    | The camera disappears.|
| CAMERA_STATUS_AVAILABLE   | 2    | The camera is available.  |
| CAMERA_STATUS_UNAVAILABLE | 3    | The camera is unavailable.|

## Profile

Defines the camera profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Read Only| Description        |
| -------- | ----------------------------- |---- | ------------- |
| format   | [CameraFormat](#cameraformat) | Yes | Output format.     |
| size     | [Size](#size)                 | Yes | Resolution.      |

## FrameRateRange

Defines the frame rate range.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type                          | Read Only| Description        |
| -------- | ----------------------------- |---- | ------------- |
| min      | number                        | Yes | Minimum frame rate.     |
| max      | number                        | Yes | Maximum frame rate.     |

## VideoProfile

Defines the video profile.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Type                                     | Read Only| Description       |
| ------------------------- | ----------------------------------------- | --- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | Yes | Frame rate range.  |

## CameraOutputCapability

Defines the camera output capability.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Type                                              | Read Only| Description               |
| ----------------------------- | -------------------------------------------------- | --- |------------------- |
| previewProfiles               | Array<[Profile](#profile)\>                        | Yes | Supported preview profiles.   |
| photoProfiles                 | Array<[Profile](#profile)\>                        | Yes | Supported shooting profiles.   |
| videoProfiles                 | Array<[VideoProfile](#videoprofile)\>              | Yes | Supported video recording profiles.   |
| supportedMetadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Supported metadata object types.|

## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use **getCameraManager** to obtain a **CameraManager** instance.

### getSupportedCameras

getSupportedCameras(callback: AsyncCallback<Array<CameraDevice\>\>): void

Obtains supported cameras. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                  | Mandatory| Description                            |
| -------- | ----------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback<Array<[CameraDevice](#cameradevice)\>\> | Yes  | Callback used to return the array of supported cameras.|

**Example**

```js
cameraManager.getSupportedCameras((err, cameras) => {
    if (err) {
        console.error(`Failed to get the cameras. ${err.message}`);
        return;
    }
    console.log(`Callback returned with an array of supported cameras: ${cameras.length}`);
})
```

### getSupportedCameras

getSupportedCameras(): Promise<Array<CameraDevice\>\>

Obtains supported cameras. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                            | Description                      |
| ----------------------------------------------- | ------------------------- |
| Promise<Array<[CameraDevice](#cameradevice)\>\> | Promise used to return the array of supported cameras.|


**Example**

```js
cameraManager.getSupportedCameras().then((cameraArray) => {
    console.log(`Promise returned with an array of supported cameras: ${cameraArray.length}`);
})
```

### getSupportedOutputCapability

getSupportedOutputCapability(camera:CameraDevice, callback: AsyncCallback<CameraOutputCapability\>): void

Obtains the output capability supported by a camera. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name        | Type                                                           | Mandatory| Description                     |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| CameraDevice | [CameraDevice](#cameradevice)                              | Yes| Camera device.                      |
| callback     | AsyncCallback<[CameraOutputCapability](#cameraoutputcapability)\> | Yes| Callback used to return the output capability.|

**Example**

```js
cameraManager.getSupportedOutputCapability(cameradevice, (err, cameras) => {
    if (err) {
        console.error(`Failed to get the cameras. ${err.message}`);
        return;
    }
    console.log('Callback returned with an array of supported outputCapability');
})
```

### getSupportedOutputCapability

getSupportedOutputCapability(camera:CameraDevice): Promise<CameraOutputCapability\>

Obtains the output capability supported by a camera. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                             | Mandatory | Description       |
| -------- | --------------------------------- | ---- | ---------- |
| camera   | [CameraDevice](#cameradevice)     |  Yes | Camera device.  |

**Return value**

| Type                                                           | Description                         |
| -------------------------------------------------------------- | ----------------------------- |
| Promise<[CameraOutputCapability](#cameraoutputcapability)\>    | Promise used to return the output capability.|

**Example**

```js
cameraManager.getSupportedOutputCapability(cameradevice).then((cameraoutputcapability) => {
    console.log('Promise returned with an array of supported outputCapability');
})
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
let ismuted = await cameraManager.isCameraMuted();
```

### isCameraMuteSupported

isCameraMuteSupported(): boolean

Checks whether the camera can be muted.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type       | Description                         |
| ---------- | ----------------------------- |
| boolean    | Returns **true** if the camera can be muted; returns **false** otherwise.|

**Example**

```js
let ismutesuppotred = await cameraManager.isCameraMuteSupported();
```

### muteCamera

muteCamera(mute: boolean): void

Mutes or unmutes the camera.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                             | Mandatory | Description       |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  Yes |  Whether to mute the camera. The value **true** means to mute the camera, and **false** means the opposite. |

**Example**

```js
cameraManager.muteCamera(mute);
```

### createCameraInput

createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput\>): void

Creates a **CameraInput** instance with the specified **CameraDevice** object. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| camera   | [CameraDevice](#cameradevice)               | Yes  | **CameraDevice** object.                       |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | Yes  | Callback used to return the **CameraInput** instance.   |

**Example**

```js
cameraManager.createCameraInput(camera, (err, cameraInput) => {
    if (err) {
        console.error(`Failed to create the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback returned with the CameraInput instance.');
})
```

### createCameraInput

createCameraInput(camera: CameraDevice): Promise<CameraInput\>

Creates a **CameraInput** instance with the specified **CameraDevice** object. This API uses a promise to return the result.

This is a system API.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                          | Mandatory| Description        |
| -------- | ----------------------------- | ---- | ---------- |
| camera   | [CameraDevice](#cameradevice) | Yes  | **CameraDevice** object.|

**Return value**

| Type                                 | Description                                  |
| ------------------------------------- | ------------------------------------ |
| Promise<[CameraInput](#camerainput)\> | Promise used to return the **CameraInput** instance.|

**Example**

```js
cameraManager.createCameraInput(camera).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void

Creates a **CameraInput** instance with the specified camera position and type. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](#cameraposition)           | Yes  | Camera position.                         |
| type     | [CameraType](#cameratype)                   | Yes  | Camera type.                         |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | Yes  | Callback used to return the **CameraInput** instance.   |

**Example**

```js
cameraManager.createCameraInput(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_UNSPECIFIED, (err, cameraInput) => {
    if (err) {
        console.error(`Failed to create the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type:CameraType ): Promise<CameraInput\>

Creates a **CameraInput** instance with the specified camera position and type. This API uses a promise to return the result.

This is a system API.

**Required permissions**: ohos.permission.CAMERA

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                              | Mandatory| Description          |
| -------- | --------------------------------- | ---- | ------------ |
| position | [CameraPosition](#cameraposition) | Yes  | Camera position.    |
| type     | [CameraType](#cameratype)         | Yes  | Camera type.    |

**Return value**

| Type                                 | Description                                  |
| ------------------------------------- | ------------------------------------ |
| Promise<[CameraInput](#camerainput)\> | Promise used to return the **CameraInput** instance.|

**Example**

```js
cameraManager.createCameraInput(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_UNSPECIFIED).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void

Creates a **PreviewOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                            | Mandatory| Description                             |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | Yes  | Supported preview profile.               |
| surfaceId| string | Yes  | Surface ID, which is obtained from **[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)** or **[ImageReceiver](js-apis-image.md#imagereceiver9)**.|
| callback | AsyncCallback<[PreviewOutput](#previewoutput)\>  | Yes  | Callback used to return the **PreviewOutput** instance.|

**Example**

```js
cameraManager.createPreviewOutput(profile, surfaceId, (err, previewoutput) => {
    if (err) {
        console.error(`Failed to gcreate previewOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with previewOutput created.');
})
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput\>

Creates a **PreviewOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description               |
| -------- | ---------------------------------| ---- | ----------------- |
| profile  | [Profile](#profile)              | Yes  | Supported preview profile. |
| surfaceId| string | Yes  | Surface ID, which is obtained from **[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)** or **[ImageReceiver](js-apis-image.md#imagereceiver9)**.|

**Return value**

| Type                                     | Description                                    |
| ---------------------------------------- | ---------------------------------------- |
| Promise<[PreviewOutput](#previewoutput)\> | Promise used to return the **PreviewOutput** instance. |

**Example**

```js
cameraManager.createPreviewOutput(profile, surfaceId).then((previewoutput) => {
    console.log('Promise returned with previewOutput created.');
})
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void

Creates a **PhotoOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                 |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | Yes  | Supported shooting profile.                   |
| surfaceId| string            | Yes  | Surface ID, which is obtained from **[ImageReceiver](js-apis-image.md#imagereceiver9)**.|
| callback | AsyncCallback<[PhotoOutput](#photooutput)\>  | Yes  | Callback used to return the **PhotoOutput** instance.   |

**Example**

```js
cameraManager.createPhotoOutput(profile, surfaceId, (err, photooutput) => {
    if (err) {
        console.error(`Failed to create photoOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with photoOutput created.');
})
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput\>

Creates a **PhotoOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                              | Mandatory| Description        |
| -------- | ---------------------------------| ---- | ----------- |
| profile  | [Profile](#profile)              | Yes  | Supported shooting profile. |
| surfaceId| string       | Yes  | Surface ID, which is obtained from **[ImageReceiver](js-apis-image.md#imagereceiver9)**.|

**Return value**

| Type                                 | Description                                    |
| ------------------------------------- | -------------------------------------- |
| Promise<[PhotoOutput](#photooutput)\>  | Promise used to return the **PhotoOutput** instance. |

**Example**

```js
cameraManager.createPhotoOutput(profile, surfaceId).then((photooutput) => {
    console.log('Promise returned with photoOutput created.');
})
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput\>): void

Creates a **VideoOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                             |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](#videoprofile)               | Yes  | Supported video recording profile.              |
| surfaceId| string          | Yes  | Surface ID, which is obtained from **[VideoRecorder](js-apis-media.md#videorecorder9)**.|
| callback | AsyncCallback<[VideoOutput](#videooutput)\>  | Yes  | Callback used to return the **VideoOutput** instance.|

**Example**

```js
cameraManager.createVideoOutput(profile, surfaceId, (err, videooutput) => {
    if (err) {
        console.error(`Failed to create videoOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with an array of supported outputCapability' );
})
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput\>

Creates a **VideoOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description        |
| -------- | ---------------------------------| ---- | ---------- |
| profile  | [VideoProfile](#videoprofile)    | Yes  | Supported video recording profile.  |
| surfaceId| string        | Yes  | Surface ID, which is obtained from **[VideoRecorder](js-apis-media.md#videorecorder9)**.|

**Return value**

| Type                                 | Description                                    |
| ------------------------------------- | -------------------------------------- |
| Promise<[VideoOutput](#videooutput)\>  | Promise used to return the **VideoOutput** instance. |

**Example**

```js
cameraManager.createVideoOutput(profile, surfaceId).then((videooutput) => {
    console.log('Promise returned with videoOutput created.');
})
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>, callback: AsyncCallback<MetadataOutput\>): void

Creates a **MetadataOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                         |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Metadata object types.           |
| callback             | AsyncCallback<[MetadataOutput](#metadataoutput)\>  | Yes  | Callback used to return the **MetadataOutput** instance.   |

**Example**

```js
cameraManager.createMetadataOutput(metadataObjectTypes, (err, metadataoutput) => {
    if (err) {
        console.error(`Failed to create metadataOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with metadataOutput created.');
})
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>): Promise<MetadataOutput\>

Creates a **MetadataOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                              | Mandatory| Description                |
| -------------------- | -------------------------------------------------- | --- | -------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | Yes | Metadata object types.  |

**Return value**

| Type                                       | Description                                      |
| ------------------------------------------ | ----------------------------------------- |
| Promise<[MetadataOutput](#metadataoutput)\> |  Promise used to return the **MetadataOutput** instance.|

**Example**

```js
cameraManager.createMetadataOutput().then((metadataoutput) => {
    console.log('Promise returned with metadataOutput created.');
})
```

### createCaptureSession

createCaptureSession(callback: AsyncCallback<CaptureSession\>): void

Creates a **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                 | Type                                     | Mandatory        | Description                         |
| -------------------- | ----------------------------------------- | ----------- | ---------------------------- |
| callback             | AsyncCallback<[CaptureSession](#capturesession)\>  | Yes  | Callback used to return the **CaptureSession** instance.|

**Example**

```js
cameraManager.createCaptureSession((err, capturesession) => {
    if (err) {
        console.error(`Failed to create captureSession. ${err.message}`);
        return;
    }
    console.log('Callback returned with captureSession created.');
})
```

### createCaptureSession

createCaptureSession(): Promise<CaptureSession\>

Creates a **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                        | Description                                     |
| ------------------------------------------- | ---------------------------------------- |
| Promise<[CaptureSession](#capturesession)\>  | Promise used to return the **CaptureSession** instance.|

**Example**

```js
cameraManager.createCaptureSession().then((capturesession) => {
    console.log('Promise returned with captureSession created.');
})
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

Listens for camera status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                   | Mandatory| Description      |
| -------- | ----------------------------------------------------- | ---- | --------- |
| type     | string                                                | Yes  | Event type. The value is fixed at **'cameraStatus'**, indicating the camera status change event.|
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.                |

**Example**

```js
cameraManager.on('cameraStatus', (err, cameraStatusInfo) => {
    if (err) {
        console.error(`Failed to get cameraStatus callback. ${err.message}`);
        return;
    }
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.log(`status: ${cameraStatusInfo.status}`);
})
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback<boolean\>): void

Listens for camera mute status changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type            | Mandatory| Description      |
| -------- | --------------- | ---- | --------- |
| type     | string          | Yes  | Event type. The value is fixed at **'cameraMute'**, indicating the camera mute status change event.|
| callback | boolean         | Yes  | Callback used to return the camera mute status.              |

**Example**

```js
cameraManager.on('cameraMute', (err, cameraStatusInfo) => {
    if (err) {
        console.error(`Failed to get cameraMute callback. ${err.message}`);
        return;
    }
})
```

## CameraStatusInfo

Describes the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                           | Description      |
| ------ | ----------------------------- | ---------- |
| camera | [CameraDevice](#cameradevice) | Camera object.|
| status | [CameraStatus](#camerastatus) | Camera status.|

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
| CAMERA_TYPE_UNSPECIFIED | 0    | Unspecified camera type. |
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

| Name          | Type                               | Read Only| Description       |
| -------------- | --------------------------------- | ---- | ---------- |
| cameraId       | string                            | Yes  | **CameraDevice** object.|
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | Camera position.   |
| cameraType     | [CameraType](#cameratype)         | Yes  | Camera type.   |
| connectionType | [ConnectionType](#connectiontype) | Yes  | Camera connection type.|

**Example**

```js
async function getCameraInfo("cameraId") {
    let cameraManager = await camera.getCameraManager(context);
    let cameras = await cameraManager.getSupportedCameras();
    let cameraObj = cameras[0];
    let cameraId = cameraObj.cameraId;
    let cameraPosition = cameraObj.cameraPosition;
    let cameraType = cameraObj.cameraType;
    let connectionType = cameraObj.connectionType;
}
```

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

| Name                    | Default Value    | Description        |
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
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
cameraInput.open((err) => {
    if (err) {
        console.error(`Failed to open the camera. ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|

**Example**

```js
cameraInput.open().then(() => {
    console.log('Promise returned with camera opened.');
})
```

### close

close\(callback: AsyncCallback<void\>\): void

Closes this camera. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
cameraInput.close((err) => {
    if (err) {
        console.error(`Failed to close the cameras. ${err.message}`);
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

**Example**

```js
cameraInput.close().then(() => {
    console.log('Promise returned with camera closed.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

Releases this camera. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
cameraInput.release((err) => {
    if (err) {
        console.error(`Failed to release the CameraInput instance ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this camera. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on('error')

on(type: 'error', camera:CameraDevice, callback: ErrorCallback<CameraInputError\>): void

Listens for **CameraInput** errors. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description                                         |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | Yes  | Event type. The value is fixed at **'error'**, indicating the camera input error event.|
| camera   | [CameraDevice](#cameradevice)    | Yes  | **CameraDevice** object.|
| callback | ErrorCallback<[CameraInputError](#camerainputerror)\> | Yes  | Callback used to return the result.  |

**Example**

```js
cameraInput.on('error', camera, (cameraInputError) => {
    console.log(`Camera input error code: ${cameraInputError.code}`);
})
```

## CameraInputErrorCode

Enumerates the error codes used for camera input.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description      |
| ------------------------- | ---- | ---------- |
| ERROR_UNKNOWN             | -1   | Unknown error.|
| ERROR_NO_PERMISSION       | 0    | You do not have the required permission.|
| ERROR_DEVICE_PREEMPTED    | 1    | The camera is preempted.|
| ERROR_DEVICE_DISCONNECTED | 2    | The camera is disconnected.|
| ERROR_DEVICE_IN_USE       | 3    | The camera is in use.|
| ERROR_DRIVER_ERROR        | 4    | Driver error.   |

## CameraInputError

Defines an error object used for **[CameraInput](#camerainput)**.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                          | Description                  |
| ---- | --------------------------------------------- | --------------------- |
| code | [CameraInputErrorCode](#camerainputerrorcode) | **CameraInput** error code.|


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

beginConfig\(callback: AsyncCallback<void\>\): void

Starts configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.beginConfig((err) => {
    if (err) {
        console.error(`Failed to start the configuration. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});
```

### beginConfig

beginConfig\(\): Promise<void\>

Starts configuration for this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|


**Example**

```js
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig

commitConfig\(callback: AsyncCallback<void\>\): void

Commits the configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.commitConfig((err) => {
    if (err) {
        console.error(`Failed to commit the configuration. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});
```

### commitConfig

commitConfig\(\): Promise<void\>

Commits the configuration for this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type           | Description                     |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput

addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

Adds a **[CameraInput](#camerainput)** instance to this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```js
captureSession.addInput(cameraInput, (err) => {
    if (err) {
        console.error(`Failed to add the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is added.');
});
```

### addInput

addInput\(cameraInput: CameraInput\): Promise<void\>

Adds a **[CameraInput](#camerainput)** instance to this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                    |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Return value**

| Type          | Description                     |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### removeInput

removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

Removes a **[CameraInput](#camerainput)** instance from this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```js
captureSession.removeInput(cameraInput, (err) => {
    if (err) {
        console.error(`Failed to remove the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate that the cameraInput instance is removed.');
});
```

### removeInput

removeInput\(cameraInput: CameraInput\): Promise<void\>

Removes a **[CameraInput](#camerainput)** instance from this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                         | Mandatory| Description                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Return value**

| Type           | Description                     |
| -------------- | ------------------------- |
| Promise\<void\> | Promise used to return the result.|

**Example**

```js
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### addOutput

addOutput\(cameraOutput: CameraOutput, callback: AsyncCallback<void\>\): void

Adds a **[CameraOutput](#cameraoutput)** instance to this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|
| callback      | AsyncCallback<void\>            | Yes  | Callback used to return the result.     |

**Example**

```js
captureSession.addOutput(cameraOutput, (err) => {
    if (err) {
        console.error(`Failed to add output. ${err.message}`);
        return;
    }
    console.log('Callback returned with output added.');
})
```

### addOutput

addOutput\(cameraOutput: CameraOutput\): Promise<void\>

Adds a **[CameraOutput](#cameraoutput)** instance to this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                      |
| ------------- | ------------------------------- | ---- | ------------------------- |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to add.|

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.addOutput(cameraOutput).then(() => {
    console.log('Promise returned with cameraOutput added.');
})
```

### removeOutput

removeOutput\(cameraOutput: CameraOutput, callback: AsyncCallback<void\>\): void

Removes a **[CameraOutput](#cameraoutput)** instance from this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|
| callback      | AsyncCallback<void\>            | Yes  | Callback used to return the result.     |

**Example**

```js
captureSession.removeOutput(cameraOutput, (err) => {
    if (err) {
        console.error(`Failed to remove the CameraOutput instance. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate that the CameraOutput instance is removed.');
});
```

### removeOutput

removeOutput(cameraOutput: CameraOutput): Promise<void\>

Removes a **[CameraOutput](#cameraoutput)** instance from this **CaptureSession**. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                            | Mandatory| Description                     |
| ------------- | ------------------------------- | ---- | ------------------------- |
| cameraOutput  | [CameraOutput](#cameraoutput)   | Yes  | **CameraOutput** instance to remove.|


**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|


**Example**

```js
captureSession.removeOutput(cameraOutput).then(() => {
    console.log('Promise returned to indicate that the CameraOutput instance is removed.');
})
```

### start

start\(callback: AsyncCallback<void\>\): void

Starts this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.start((err) => {
    if (err) {
        console.error(`Failed to start the session ${err.message}`);
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

**Example**

```js
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop

stop\(callback: AsyncCallback<void\>\): void

Stops this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.stop((err) => {
    if (err) {
        console.error(`Failed to stop the session ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

Releases this **CaptureSession**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.release((err) => {
    if (err) {
        console.error(`Failed to release the CaptureSession instance ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### hasFlash

hasFlash(callback: AsyncCallback<boolean\>): void

Checks whether the device has flash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                            |
| -------- | ----------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the flash support status. The value **true** means that the device has flash.|

**Example**

```js
captureSession.hasFlash((err, status) => {
    if (err) {
        console.error(`Failed to check whether the device has flash light. ${err.message}`);
        return;
    }
    console.log(`Callback returned with flash light support status: ${status}`);
})
```

### hasFlash

hasFlash(): Promise<boolean\>

Checks whether the device has flash. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type              | Description                                            |
| ----------------- | ----------------------------------------------- |
| Promise<boolean\> | Promise used to return the flash support status. The value **true** means that the device has flash.|

**Example**

```js
captureSession.hasFlash().then((status) => {
    console.log(`Promise returned with the flash light support status: ${status}`);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void

Checks whether a specified flash mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                              |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.                    |
| callback  | AsyncCallback<boolean\> | Yes  | Callback used to return the flash mode support status. The value **true** means that the flash mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO, (err, status) => {
    if (err) {
        console.error(`Failed to check whether the flash mode is supported. ${err.message}`);
        return;
    }
    console.log(`Callback returned with the flash mode support status: ${status}`);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode): Promise<boolean\>

Checks whether a specified flash mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                   | Mandatory| Description           |
| --------- | ----------------------- | ---- | ------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.|

**Return value**

| Type              | Description                                                 |
| ----------------- | ---------------------------------------------------- |
| Promise<boolean\> | Promise used to return the flash mode support status. The value **true** means that the flash mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO).then((status) => {
    console.log(`Promise returned with flash mode support status.${status}`);
})
```

### setFlashMode

setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void\>): void

Sets the flash mode. This API uses an asynchronous callback to return the result.

Before the setting, do the following checks:

1. Use **[hasFlash](#hasflash)** to check whether the device has flash.
2. Use **[isFlashModeSupported](#isflashmodesupported)** to check whether the device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                 |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.        |
| callback  | AsyncCallback<void\>    | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO, (err) => {
    if (err) {
        console.error(`Failed to set the flash mode  ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setFlashMode.');
})
```

### setFlashMode

setFlashMode(flashMode: FlashMode): Promise<void\>

Sets a flash mode. This API uses a promise to return the result.

Before the setting, do the following checks:

1. Use **[hasFlash](#hasflash)** to check whether the device has flash.
2. Use **[isFlashModeSupported](#isflashmodesupported)** to check whether the device supports the flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                    | Mandatory| Description          |
| --------- | ----------------------- | ---- | ------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode

getFlashMode(callback: AsyncCallback<FlashMode\>): void

Obtains the flash mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                    | Mandatory| Description                             |
| -------- | --------------------------------------- | ---- | --------------------------------- |
| callback | AsyncCallback<[FlashMode](#flashmode)\> | Yes  | Callback used to return the flash mode.|

**Example**

```js
captureSession.getFlashMode((err, flashMode) => {
    if (err) {
        console.error(`Failed to get the flash mode  ${err.message}`);
        return;
    }
    console.log(`Callback returned with current flash mode: ${flashMode}`);
})
```

### getFlashMode

getFlashMode(): Promise<FlashMode\>

Obtains the flash mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                              | Description                              |
| --------------------------------- | --------------------------------- |
| Promise<[FlashMode](#flashmode)\> | Promise used to return the flash mode.|

**Example**

```js
captureSession.getFlashMode().then((flashMode) => {
    console.log(`Promise returned with current flash mode : ${flashMode}`);
})
```

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean\>): void;

Checks whether a specified exposure mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.                     |
| callback | AsyncCallback<boolean\>        | Yes  | Callback used to return the exposure mode support status. The value **true** means that the exposure mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED,(err) => {
    if (err) {
        console.log(`Failed to check exposure mode supported ${err.message}`);
        return ;
    }
    console.log('Callback returned with the successful execution of isExposureModeSupported');
})
```

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): Promise<boolean\>

Checks whether a specified exposure mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                          | Mandatory | Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.                     |

**Return value**

| Name              | Description                            |
| ----------------- |--------------------------------- |
| Promise<boolean\> | Promise used to return the exposure mode support status. The value **true** means that the exposure mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED).then((isSupported) => {
    console.log(`Promise returned with exposure mode supported : ${isSupported}`);
})
```

### getExposureMode

getExposureMode(callback: AsyncCallback<ExposureMode\>): void

Obtains the exposure mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                                    |
| -------- | -------------------------------| ---- | ---------------------------------------- |
| callback | AsyncCallback<[ExposureMode](#exposuremode)\>   | Yes  | Callback used to return the exposure mode.|

**Example**

```js
captureSession.getExposureMode((err, exposureMode) => {
    if (err) {
        console.log(`Failed to get the exposure mode ${err.message}`);
        return ;
    }
    console.log(`Callback returned with current exposure mode: ${exposureMode}`);
})
```

### getExposureMode

getExposureMode(): Promise<ExposureMode\>

Obtains the exposure mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Name                                    | Description                          |
| --------------------------------------- |------------------------------- |
| Promise<[ExposureMode](#exposuremode)\> | Promise used to return the exposure mode.|

**Example**

```js
captureSession.getExposureMode().then((exposureMode) => {
    console.log(`Promise returned with current exposure mode : ${exposureMode}`);
})
```

### setExposureMode

setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void\>): void

Sets an exposure mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                   |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | Yes  | Exposure mode.               |
| callback | AsyncCallback<void\>           | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED,(err) => {
    if (err) {
        console.log(`Failed to set the exposure mode ${err.message}`);
        return ;
    }
    console.log('Callback returned with the successful execution of setExposureMode');
})
```

### setExposureMode

setExposureMode(aeMode: ExposureMode): Promise<void\>

Sets an exposure mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Name              | Description                       |
| ----------------- |---------------------------- |
| Promise<void\>   | Promise used to return the result.|

**Example**

```js
captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED).then(() => {
    console.log('Promise returned with the successful execution of setExposureMode.');
})
```

### getMeteringPoint

getMeteringPoint(callback: AsyncCallback<Point\>): void

Obtains the center of the metering area. This API uses an asynchronous callback to return the result.  

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                      |
| -------- | -------------------------------| ---- | ------------------------ |
| callback | AsyncCallback<[Point](#point)\>| Yes  | Callback used to return the center of the metering area.|

**Example**

```js
captureSession.getMeteringPoint((err, exposurePoint) => {
    if (err) {
        console.log(`Failed to get the current exposure point ${err.message}`);
        return ;
    }
    console.log(`Callback returned with current exposure point: ${exposurePoint}`);
})
```

### getMeteringPoint

getMeteringPoint(): Promise<Point\>

Obtains the center of the metering area. This API uses a promise to return the result.  

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Name                      | Description                         |
| ------------------------- |----------------------------- |
| Promise<[Point](#point)\> | Promise used to return the center of the metering area.|

**Example**

```js
captureSession.getMeteringPoint().then((exposurePoint) => {
    console.log(`Promise returned with current exposure point : ${exposurePoint}`);
})
```

### setMeteringPoint

setMeteringPoint(point: Point, callback: AsyncCallback<void\>): void

Sets the center of the metering area. This API uses an asynchronous callback to return the result.  

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | Yes  | Exposure point.             |
| callback      | AsyncCallback<void\>           | Yes  | Callback used to return the result.|

**Example**

```js
const Point1 = {x: 1, y: 1};

captureSession.setMeteringPoint(Point1,(err) => {
    if (err) {
        console.log(`Failed to set the exposure point ${err.message}`);
        return ;
    }
    console.log('Callback returned with the successful execution of setMeteringPoint');
})
```

### setMeteringPoint

setMeteringPoint(point: Point): Promise<void\>

Sets the center of the metering area. This API uses a promise to return the result.  

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name          | Type                           | Mandatory| Description                |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | Yes  | Exposure point.             |

**Return value**

| Name              | Description                    |
| ----------------- |------------------------ |
| Promise<void\>   | Promise used to return the center of the metering area.|

**Example**

```js
const Point2 = {x: 2, y: 2};

captureSession.setMeteringPoint(Point2).then(() => {
    console.log('Promise returned with the successful execution of setMeteringPoint');
})
```

### getExposureBiasRange

getExposureBiasRange(callback: AsyncCallback<Array<number\>\>): void

Obtains the exposure compensation values. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                          |
| -------- | -------------------------------| ---- | ----------------------------- |
| callback | AsyncCallback<Array<number\>\>  | Yes  | Callback used to return the array of compensation values.|

**Example**

```js
captureSession.getExposureBiasRange((err, biasRangeArray) => {
    if (err) {
        console.log(`Failed to get the array of compenstation range ${err.message}`);
        return ;
    }
    console.log('Callback returned with the array of compenstation range: ' + JSON.stringify(biasRangeArray));
})
```

### getExposureBiasRange

getExposureBiasRange(): Promise<Array<number\>\>

Obtains the exposure compensation values. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Name              | Description                                  |
| ----------------- |-------------------------------------- |
| Promise<Array<number\>\> | Promise used to return the array of compensation values.|

**Example**

```js
captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED).then((isSupported) => {
    console.log(`Promise returned with exposure mode supported : ${isSupported}`);
})
```

### setExposureBias

setExposureBias(exposureBias: number, callback: AsyncCallback<void\>): void

Sets an exposure compensation value. This API uses an asynchronous callback to return the result.

Before the setting, you are advised to use **[getExposureBiasRange](#getexposurebiasrange)** to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | Yes  | Compensation value.           |
| callback | AsyncCallback<void\>           | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.setExposureBias(-4,(err) => {
    if (err) {
        console.log(`Failed to set the exposure bias ${err.message}`);
        return ;
    }
    console.log('Callback returned with the successful execution of setExposureBias');
})
```

### setExposureBias

setExposureBias(exposureBias: number): Promise<void\>

Sets an exposure compensation value. This API uses a promise to return the result.

Before the setting, you are advised to use **[getExposureBiasRange](#getexposurebiasrange)** to obtain the supported values.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name           | Type     | Mandatory| Description       |
| -------------- | --------- | ---- | --------- |
| exposureBias   | number    | Yes  | Compensation value. |

**Return value**

| Name              | Description                    |
| ----------------- |------------------------- |
| Promise<void\>   | Promise used to return the result.|

**Example**

```js
captureSession.setExposureBias(-4).then(() => {
    console.log('Promise returned with the successful execution of setExposureBias.');
})
```

### getExposureValue

getExposureValue(callback: AsyncCallback<number\>): void

Obtains the exposure value in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                     | Mandatory| Description                  |
| -------- | ------------------------| ---- | --------------------- |
| callback | AsyncCallback<number\>  | Yes  | Callback used to the exposure value.|

**Example**

```js
captureSession.getExposureValue((err, exposureValue) => {
    if (err) {
        console.log(`Failed to get the exposure value ${err.message}`);
        return ;
    }
    console.log(`Callback returned with the exposure value: ${exposureValue}`);
})
```

### getExposureValue

getExposureValue(): Promise<number\>

Obtains the exposure value in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Name              | Description                      |
| ----------------- |-------------------------- |
| Promise<number\>  | Promise used to the exposure value.|

**Example**

```js
captureSession.getExposureValue().then((exposureValue) => {
    console.log(`Promise returned with exposure value: ${exposureValude}`);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void

Checks whether a specified focus mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.                   |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the focus mode support status. The value **true** means that the focus mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO, (err, status) => {
    if (err) {
        console.error(`Failed to check whether the focus mode is supported. ${err.message}`);
        return;
    }
    console.log(`Callback returned with the focus mode support status: ${status}`);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode): Promise<boolean\>

Checks whether a specified focus mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description          |
| ------ | ----------------------- | ---- | ------------- |
| afMode | [FocusMode](#focusmode) | Yes  | Focus mode.|

**Return value**

| Type              | Description                                               |
| ----------------- | --------------------------------------------------- |
| Promise<boolean\> | Promise used to return the focus mode support status. The value **true** means that the focus mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO).then((status) => {
    console.log(`Promise returned with focus mode support status ${status}.`);
})
```

### setFocusMode

setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void

Sets a focus mode. This API uses an asynchronous callback to return the result.

Before the setting, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.      |
| callback | AsyncCallback<void\>    | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO, (err) => {
    if (err) {
        console.error(`Failed to set the focus mode  ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setFocusMode.');
})
```

### setFocusMode

setFocusMode(afMode: FocusMode): Promise<void\>

Sets a focus mode. This API uses a promise to return the result.

Before the setting, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                    | Mandatory| Description          |
| ------ | ----------------------- | ---- | ------------- |
| afMode | [FocusMode](#focusmode) | Yes  | Focus mode.|

**Return value**

| Type           | Description                    |
| -------------- | ------------------------ |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode

getFocusMode(callback: AsyncCallback<FocusMode\>): void

Obtains the focus mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                    | Mandatory| Description                            |
| -------- | --------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback<[FocusMode](#focusmode)\> | Yes  | Callback used to return the focus mode.|

**Example**

```js
captureSession.getFocusMode((err, afMode) => {
    if (err) {
        console.error(`Failed to get the focus mode  ${err.message}`);
        return;
    }
    console.log(`Callback returned with current focus mode: ${afMode}`);
})
```

### getFocusMode

getFocusMode(): Promise<FocusMode\>

Obtains the focus mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                | Description                            |
| ------------------- | -------------------------------- |
| Promise<FocusMode\> | Promise used to return the focus mode.|

**Example**

```js
captureSession.getFocusMode().then((afMode) => {
    console.log(`Promise returned with current focus mode : ${afMode}`);
})
```

### setFocusPoint

setFocusPoint(point: Point, callback: AsyncCallback<void\>): void

Sets a focus point. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | Yes  | Focal point.               |
| callback | AsyncCallback<void\>    | Yes  | Callback used to return the result.|

**Example**

```js
const Point1 = {x: 1, y: 1};

captureSession.setFocusPoint(Point1, (err) => {
    if (err) {
        console.error(`Failed to set the focus point  ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setFocusPoint.');
})
```

### setFocusPoint

setFocusPoint(point: Point): Promise<void\>

Sets a focal point. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | Yes  | Focal point.               |

**Return value**

| Type          | Description                     |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
const Point2 = {x: 2, y: 2};

captureSession.setFocusPoint(Point2).then(() => {
    console.log('Promise returned with the successful execution of setFocusPoint.');
})
```

### getFocusPoint

getFocusPoint(callback: AsyncCallback<Point\>): void

Obtains the focal point. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                              | Mandatory| Description                    |
| -------- | ---------------------------------- | ---- | ----------------------- |
| callback | AsyncCallback<[Point](#point)\>    | Yes  | Callback used to return the focal point.|

**Example**

```js
captureSession.getFocusPoint((err, point) => {
    if (err) {
        console.error(`Failed to get the current focus point ${err.message}`);
        return;
    }
    console.log('Callback returned with the current focus point: ' + JSON.stringify(point));
})
```

### getFocusPoint

getFocusPoint(): Promise<Point\>

Obtains the focal point. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type            | Description                       |
| --------------- | --------------------------- |
| Promise<Point\> | Promise used to return the focal point.|

**Example**

```js
captureSession.getFocusPoint().then((point) => {
    console.log('Promise returned with the current focus point: ' + JSON.stringify(point));
})
```

### getFocalLength

getFocalLength(callback: AsyncCallback<number\>): void

Obtains the focal length. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                      | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ----------------------- |
| callback | AsyncCallback<number\>    | Yes  | Callback used to return the focal length.|

**Example**

```js
captureSession.getFocalLength((err, focalLength) => {
    if (err) {
        console.error(`Failed to get the current focal length  ${err.message}`);
        return;
    }
    console.log(`Callback returned with the current focal length: ${focalLength}`);
})
```

### getFocalLength

getFocalLength(): Promise<number\>

Obtains the focal length. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type             | Description                    |
| ---------------- | ----------------------- |
| Promise<number\> | Promise used to return the focal length.|

**Example**

```js
captureSession.getFocalLength().then((focalLength) => {
    console.log(`Promise returned with the current focal length: ${focalLength}`);
})
```

### getZoomRatioRange

getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void

Obtains the zoom ratio range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                           | Mandatory| Description                |
| -------- | ------------------------------ | ---- | ------------------- |
| callback | AsyncCallback<Array<number\>\> | Yes  | Callback used to return an array containing the minimum and maximum zoom ratios.|

**Example**

```js
captureSession.getZoomRatioRange((err, zoomRatioRange) => {
    if (err) {
        console.error(`Failed to get the zoom ratio range. ${err.message}`);
        return;
    }
    console.log(`Callback returned with zoom ratio range: ${zoomRatioRange.length}`);
})
```

### getZoomRatioRange

getZoomRatioRange\(\): Promise<Array<number\>\>

Obtains the zoom ratio range. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                     | Description                       |
| ------------------------ | --------------------------- |
| Promise<Array<number\>\> |  Promise used to return an array containing the minimum and maximum zoom ratios.|

**Example**

```js
captureSession.getZoomRatioRange().then((zoomRatioRange) => {
    console.log(`Promise returned with zoom ratio range: ${zoomRatioRange.length}`);
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void

Sets a zoom ratio. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type                 | Mandatory| Description                |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | Yes  | Zoom ratio.          |
| callback  | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.setZoomRatio(1, (err) => {
    if (err) {
        console.error(`Failed to set the zoom ratio value ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setZoomRatio.');
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number): Promise<void\>

Sets a zoom ratio. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name      | Type   | Mandatory| Description      |
| --------- | ------ | ---- | --------- |
| zoomRatio | number | Yes  | Zoom ratio.|

**Return value**

| Type           | Description                    |
| -------------- | ----------------------- |
| Promise<void\>| Promise used to return the result.|

**Example**

```js
captureSession.setZoomRatio(1).then(() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio

getZoomRatio(callback: AsyncCallback<number\>): void

Obtains the zoom ratio in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                  | Mandatory| Description                 |
| -------- | ---------------------- | ---- | ------------------- |
| callback | AsyncCallback<number\> | Yes  | Callback used to return the result.|

**Example**

```js
captureSession.getZoomRatio((err, zoomRatio) => {
    if (err) {
        console.error(`Failed to get the zoom ratio ${err.message}`);
        return;
    }
    console.log(`Callback returned with current zoom ratio: ${zoomRatio}`);
})
```

### getZoomRatio

getZoomRatio(): Promise<number\>

Obtains the zoom ratio in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type             | Description                    |
| ---------------- | ----------------------- |
| Promise<number\> | Promise used to return the zoom ratio.|

**Example**

```js
captureSession.getZoomRatio().then((zoomRatio) => {
    console.log(`Promise returned with current zoom ratio : ${zoomRatio}`);
})
```

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean\>): void

Checks whether the specified video stabilization mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                            |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.                   |
| callback | AsyncCallback<boolean\>                           | Yes  | Callback used to return whether the video stabilization mode is supported. The value **true** means that the video stabilization mode is supported, and **false** means the opposite. |

**Example**

```js
captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF, (err, isSupported) => {
    if (err) {
        console.error(`Failed to check whether video stabilization mode supported. ${err.message}`);
        return;
    }
    console.log(`Callback returned with the successful execution of isVideoStabilizationModeSupported`);
})
```

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): Promise<boolean\>

Checks whether the specified video stabilization mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type              | Description                                          |
| ----------------- | --------------------------------------------- |
| Promise<boolean\> | Promise used to return whether the video stabilization mode is supported. The value **true** means that the video stabilization mode is supported, and **false** means the opposite.|

**Example**

```js
captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF).then((isSupported) => {
    console.log(`Promise returned with video stabilization mode supported: ${isSupported}`);
})
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode\>): void

Obtains the video stabilization mode in use. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                      | Mandatory| Description                           |
| -------- | ----------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<VideoStabilizationMode\>    | Yes  | Callback used to return the video stabilization mode. |

**Example**

```js
captureSession.getActiveVideoStabilizationMode((err, vsMode) => {
    if (err) {
        console.error(`Failed to get active video stabilization mode ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of getActiveVideoStabilizationMode.');
})
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(): Promise<VideoStabilizationMode\>

Obtains the video stabilization mode in use. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                             | Description                                             |
| -------------------------------- | ------------------------------------------------- |
| Promise<VideoStabilizationMode\> | Promise used to return the video stabilization mode. |

**Example**

```js
captureSession.getActiveVideoStabilizationMode().then((vsMode) => {
    console.log(`Promise returned with the current video stabilization mode: ${vsMode}`);
})
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void\>): void

Sets a video stabilization mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |
| callback | AsyncCallback<void\>                              | Yes  | Callback used to return the result.    |

**Example**

```js
captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF, (err) => {
    if (err) {
        console.error(`Failed to set the video stabilization mode ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setVideoStabilizationMode.');
})
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode): Promise<void\>

Sets a video stabilization mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                   |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | Yes  | Video stabilization mode.  |

**Return value**

| Type           | Description                                              |
| -------------- | ------------------------------------------------- |
| Promise<void\>| Promise used to return the result. |

**Example**

```js
captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF).then(() => {
    console.log('Promise returned with the successful execution of setVideoStabilizationMode.');
})
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

Listens for focus state changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                      |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | Yes  | Event type. The value is fixed at **'focusStateChange'**, indicating the focus state change event.|
| callback | AsyncCallback<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change. |

**Example**

```js
captureSession.on('focusStateChange', (focusState) => {
    console.log(`Focus state  : ${focusState}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CaptureSessionError\>): void

Listens for **CaptureSession** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                         | Mandatory| Description                          |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | Yes  | Event type. The value is fixed at **'error'**, indicating the capture session error event.|
| callback | ErrorCallback<[CaptureSessionError](#capturesessionerror)\> | Yes  | Callback used to return the error information.       |

**Example**

```js
captureSession.on('error', (captureSessionError) => {
    console.log(`Capture session error code: ${captureSessionError.code}`);
})
```

## CaptureSessionErrorCode

Enumerates the error codes used in a **CaptureSession**.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description     |
| ----------------------------- | ---- | -------- |
| ERROR_UNKNOWN                 | -1   | Unknown error.|
| ERROR_INSUFFICIENT_RESOURCES  | 0    | Insufficient resources.|
| ERROR_TIMEOUT                 | 1    | Timeout.|

## CaptureSessionError

Defines a **CaptureSession** error.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                       | Description                      |
| ---- | ------------------------------------------- | -------------------------- |
| code | [CaptureSessionError](#capturesessionerror) | **CaptureSession** error code.|

## CameraOutput

Implements output information used in a **[CaptureSession](#capturesession)**. It is the base class of **output**.

### release

release(callback: AsyncCallback<void\>): void

Releases output resources. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
cameraOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|

**Example**

```js
cameraOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

## PreviewOutput

Implements preview output. It inherits **[CameraOutput](#cameraoutput)**.

### start

start(callback: AsyncCallback<void\>): void

Starts to output preview streams. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
previewOutput.start((err) => {
    if (err) {
        console.error(`Failed to start the previewOutput. ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|

**Example**

```js
previewOutput.start().then(() => {
    console.log('Promise returned with previewOutput started.');
})
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
        console.error(`Failed to stop the previewOutput. ${err.message}`);
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
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for preview frame start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                    |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **'frameStart'**, indicating the preview frame start event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                    |

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
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**, indicating the preview frame end event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                 |

**Example**

```js
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PreviewOutputError\>): void

Listens for **PreviewOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                              | Mandatory| Description                      |
| -------- | ----------------------------------------------------------------- | ---- | ------------------------ |
| type     | string                                               | Yes  | Event type. The value is fixed at **'error'**, indicating the preview output error event.|
| callback | ErrorCallback<[PreviewOutputErrorCode](#previewoutputerrorcode)\> | Yes  | Callback used to return the error information. |

**Example**

```js
previewOutput.on('error', (previewOutputError) => {
    console.log(`Preview output error code: ${previewOutputError.code}`);
})
```

## PreviewOutputErrorCode

Enumerates the error codes used for preview output.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name         | Value  | Description      |
| ------------- | ---- | -------- |
| ERROR_UNKNOWN | -1   | Unknown error.|

## PreviewOutputError

Defines the preview output error.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                             | Description                  |
| ---- | ------------------------------------------------- | ---------------------- |
| code | [PreviewOutputErrorCode](#previewoutputerrorcode) | **PreviewOutput** error code.|

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

| Name     | Type                           | Mandatory | Default Value            | Description             |
| -------- | ------------------------------- | ---- | ----------------- | -----------------|
| quality  | [QualityLevel](#qualitylevel)   | No  | QUALITY_LEVEL_HIGH| Photo quality.        |
| rotation | [ImageRotation](#imagerotation) | No  | ROTATION_0        | Rotation angle of the photo.     |
| location | [Location](#location)           | No  | (0,0,0)           | Geolocation information of the photo.  |
| mirror   | boolean                         | No  | false             |Whether mirroring is enabled. By default, mirroring is disabled.|

## PhotoOutput

Implements output information used in a **CaptureSession**.

### capture

capture(callback: AsyncCallback<void\>): void

Captures a photo with the default shooting parameters. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
photoOutput.capture((err) => {
    if (err) {
        console.error(`Failed to capture the photo ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
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
| callback | AsyncCallback<void\>                        | Yes  | Callback used to return the result. |

**Example**

```js
let settings:PhotoCaptureSetting = {
    quality = 1,
    rotation = 0
}
photoOutput.capture(settings, (err) => {
    if (err) {
        console.error(`Failed to capture the photo ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|


**Example**

```js
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### isMirrorSupported

isMirrorSupported(callback: AsyncCallback<boolean\>): void

Checks whether mirroring is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                             | Mandatory| Description                        |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<boolean\>                           | Yes  | Callback used to return the mirroring support status. The value **true** means that mirroring is supported, and **false** means the opposite. |

**Example**

```js
photoOutput.isMirrorSupported((err, isSupported) => {
    if (err) {
        console.error(`Failed to check mirror is supported ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of isMirrorSupported.');
})
```

### isMirrorSupported

isMirrorSupported(): Promise<boolean\>

Checks whether mirroring is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type              | Description                                       |
| ----------------- | ------------------------------------------- |
| Promise<boolean\> | Promise used to return the mirroring support status. The value **true** means that mirroring is supported, and **false** means the opposite. |

**Example**

```js
photoOutput.isMirrorSupported().then((isSupported) => {
    console.log(`Promise returned with mirror supported: ${isSupported}`);
})
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

Listens for shooting start events. This API uses an asynchronous callback to return the capture ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                      |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | Yes  | Event type. The value is fixed at **'captureStart'**, indicating the shooting start event.|
| callback | AsyncCallback<number\> | Yes  | Callback used to return the capture ID.           |

**Example**

```js
photoOutput.on('captureStart', (err, captureId) => {
    console.log(`photo capture stated, captureId : ${captureId}`);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

Listens for frame shutter events. This API uses an asynchronous callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                  | Mandatory| Description                                 |
| -------- | ----------------------------------------------------- | --- | ------------------------------------ |
| type     | string                                           | Yes  | Event type. The value is fixed at **'frameShutter'**, indicating the frame shutter event.|
| callback | AsyncCallback<[FrameShutterInfo](#frameshutterinfo)\> | Yes  | Callback used to return the result.            |

**Example**

```js
photoOutput.on('frameShutter', (err, frameShutterInfo) => {
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

Listens for shooting end events. This API uses an asynchronous callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                             | Mandatory| Description                                      |
| -------- | ------------------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                            | Yes  | Event type. The value is fixed at **'captureEnd'**, indicating the shooting end event.|
| callback | AsyncCallback<[CaptureEndInfo](#captureendinfo)\> | Yes  | Callback used to return the result.                 |

**Example**

```js
photoOutput.on('captureEnd', (err, captureEndInfo) => {
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.log(`frameCount : ${captureEndInfo.frameCount}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PhotoOutputError\>): void

Listens for **PhotoOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                   | Mandatory| Description                                |
| -------- | ----------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                | Yes  | Event type. The value is fixed at **'error'**, indicating the photo output error event.|
| callback | ErrorCallback<[PhotoOutputError](#photooutputerror)\> | Yes  | Callback used to return the error information.            |

**Example**

```js
photoOutput.on('error', (err, photoOutputError) => {
    console.log(`Photo output error code: ${photoOutputError.code}`);
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

## PhotoOutputErrorCode

Enumerates the error codes used for photo output.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                          | Value  | Description            |
| ----------------------------- | ---- | --------------- |
| ERROR_UNKNOWN                 | -1   | Unknown error.       |
| ERROR_DRIVER_ERROR            | 0    | The driver or hardware is faulty.|
| ERROR_INSUFFICIENT_RESOURCES  | 1    | Insufficient resources.       |
| ERROR_TIMEOUT                 | 2    | Timeout.          |

## PhotoOutputError

Defines a photo output error.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                 | Description                   |
| ---- | ------------------------------------- | ----------------------- |
| code | [PhotoOutputErrorCode](#photooutputerrorcode) | **PhotoOutput** error code.|

## VideoOutput

Implements output information used in a video recording session.

### start

start(callback: AsyncCallback<void\>): void

Starts video recording. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```js
videoOutput.start((err) => {
    if (err) {
        console.error(`Failed to start the video output ${err.message}`);
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
| Promise<void\>| Promise used to return the result.|


**Example**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
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
        console.error(`Failed to stop the video output ${err.message}`);
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
})
``` 

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for video recording start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                 | Mandatory| Description                                      |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | Yes  | Event type. The value is fixed at **`frameStart`**, indicating the video recording start event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                      |

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
| type     | string               | Yes  | Event type. The value is fixed at **'frameEnd'**, indicating the video recording stop event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                      |

**Example**

```js
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<VideoOutputError\>): void

Listens for errors that occur during video recording. This API uses a callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                              | Mandatory| Description                                   |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| type     | string                                           | Yes  | Event type. The value is fixed at **'error'**, indicating the video output error event.|
| callback | Callback<[VideoOutputError](#videooutputerror)\> | Yes  | Callback used to return the error information.                |

**Example**

```js
videoOutput.on('error', (VideoOutputError) => {
    console.log(`Video output error code: ${VideoOutputError.code}`);
})
```

## VideoOutputErrorCode

Enumerates the error codes used for video recording.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Value  | Description         |
| --------------------- | ---- | ------------ |
| ERROR_UNKNOWN         | -1   | Unknown error.    |
| ERROR_DRIVER_ERROR    | 0    | The driver or hardware is faulty.|

## VideoOutputError

Defines a video output error.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                 | Description                   |
| ---- | ------------------------------------- | ----------------------- |
| code | [PhotoOutputErrorCode](#photooutputerrorcode) | **VideoOutput** error code.|

## MetadataObjectType

Enumerates metadata streams.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Value  | Description             |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | Metadata object type.|

## Rect

Defines a rectangle.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name     | Type  | Description                |
| -------- | ------ | -------------------- |
| topLeftX | number | X-axis coordinate of the upper left corner of the rectangle.  |
| topLeftY | number | Y-axis coordinate of the upper left corner of the rectangle.  |
| width    | number | Width of the rectangle.             |
| height   | number | Height of the rectangle.             |

## MetadataObject

Implements camera metadata, which is the data source of **[CameraInput](#camerainput)**.

### getType

getType(callback: AsyncCallback<MetadataObjectType\>): void

Obtains the metadata object type. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                      | Mandatory| Description                 |
| -------- | --------------------------------------------------------- | --- | -------------------- |
| callback | AsyncCallback<[MetadataObjectType](#metadataobjecttype)\> | Yes  | Callback used to return the result.|

**Example**

```js
metadataObject.getType((err, metadataObjectType) => {
    if (err) {
        console.error(`Failed to get type. ${err.message}`);
        return;
    }
    console.log('Callback returned with an array of metadataObjectType.');
})
```

### getType

getType(): Promise<MetadataObjectType\>

Obtains the metadata object type. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                                                | Description                       |
| --------------------------------------------------- | --------------------------- |
| Promise<[MetadataObjectType](#metadataobjecttype)\> | Promise used to return the result.|

**Example**

```js
metadataObject.getType().then((metadataObjectType) => {
    console.log('Callback returned with an array of metadataObjectType.');
})
```

### getTimestamp

getTimestamp(callback: AsyncCallback<number\>): void

Obtains the metadata timestamp. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                    |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<number\>                                      | Yes  | Callback used to return the result.|

**Example**

```js
metadataObject.getTimestamp((err,timestamp) => {
    if (err) {
        console.error(`Failed to get timestamp. ${err.message}`);
        return;
    }
    console.log('Callback returned with timestamp getted timestamp : ${timestamp}');
})
```

### getTimestamp

getTimestamp(): Promise<number\>

Obtains the metadata timestamp. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type              | Description                       |
| ----------------  | --------------------------- |
| Promise<number)\> | Promise used to return the result.|

**Example**

```js
metadataObject.getTimestamp().then((timestamp) => {
    console.log('Callback returned with timestamp getted timestamp : ${timestamp}');
})
```

### getBoundingBox

getBoundingBox(callback: AsyncCallback<Rect\>): void

Obtains the bounding box of metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                    |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Rect](#rect)\>                               | Yes  | Callback used to return the result.|

**Example**

```js
metadataObject.getBoundingBox((err, rect) => {
    if (err) {
        console.error(`Failed to get boundingBox. ${err.message}`);
        return;
    }
    console.log('Callback returned with boundingBox getted.');
})
```

### getBoundingBox

getBoundingBox(): Promise<Rect\>

Obtains the bounding box of metadata. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                   | Description                       |
| ----------------------  | --------------------------- |
| Promise<[Rect](#rect)\> | Promise used to return the result.|

**Example**

```js
metadataObject.getBoundingBox().then((rect) => {
    console.log('Callback returned with boundingBox getted.');
})
```

## MetadataFaceObject

Implements the face object of metadata. It inherits [MetadataObject](#metadataobject).

## MetadataOutput

Implements metadata streams. It inherits **[CameraOutput](#cameraoutput)**.

### start

start(callback: AsyncCallback<void\>): void

Starts to output metadata. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                |
| -------- | ----------------------------------------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>                                       | Yes  | Callback used to return the result.|

**Example**

```js
metadataOutput.start((err) => {
    if (err) {
        console.error(`Failed to start metadataOutput. ${err.message}`);
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
| Promise<void\>         | Promise used to return the result.|

**Example**

```js
metadataOutput.start().then(() => {
    console.log('Callback returned with metadataOutput started.');
})
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
        console.error(`Failed to stop the metadataOutput. ${err.message}`);
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
})
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback<Array<MetadataObject\>\>): void

Listens for metadata objects. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                                 | Mandatory| Description                                 |
| -------- | ------------------------------------------------ | ---- | ------------------------------------ |
| type     | string                            | Yes  | Event type. The value is fixed at **'metadataObjectsAvailable'**, that is, the metadata object.|
| callback | Callback<Array<[MetadataObject](#metadataobject)\>\> | Yes  | Callback used to return the error information.              |

**Example**

```js
metadataOutput.on('metadataObjectsAvailable', (metadataObject) => {
    console.log(`metadata output error code: ${metadataObject.code}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<MetadataOutputError\>): void

Listens for metadata errors. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                              | Mandatory| Description                                    |
| -------- | ------------------------------------------------ | ---- | --------------------------------------- |
| type     | string                                           | Yes  | Event type. The value is fixed at **'error'**, that is, the metadata error.|
| callback | Callback<[MetadataOutputError](#metadataoutputerror)\> | Yes  | Callback used to return the error information.           |

**Example**

```js
metadataOutput.on('error', (metadataOutputError) => {
    console.log(`Metadata output error code: ${metadataOutputError.code}`);
})
```

## MetadataOutputErrorCode

Enumerates the codes used for metadata output errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                            | Value  | Description     |
| ------------------------------- | ---- | -------- |
| ERROR_UNKNOWN                   | -1   | Unknown error.|
| ERROR_INSUFFICIENT_RESOURCES    | 0    | Insufficient resources.|

## MetadataOutputError

Defines a metadata output error.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name| Type                                 | Description                   |
| ---- | ------------------------------------- | ----------------------- |
| code | [MetadataOutputErrorCode](#metadataoutputerrorcode) | **MetadataOutput** error code.|
