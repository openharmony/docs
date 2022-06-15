# Camera Management

> **NOTE**<br/>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import camera from '@ohos.multimedia.camera';
```

## Required Permissions

ohos.permission.CAMERA

## camera.getCameraManager

getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void

Obtains a **CameraManager** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                           | Mandatory| Description                              |
| -------- | ----------------------------------------------- | ---- | ---------------------------------- |
| context  | Context                                         | Yes  | Application context.                      |
| callback | AsyncCallback<[CameraManager](#cameramanager)\> | Yes  | Callback used to return the **CameraManager** instance.|

**Example**

```
camera.getCameraManager(context, (err, cameraManager) => {
    if (err) {
        console.error('Failed to get the CameraManager instance ${err.message}');
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
| context | Context | Yes  | Application context.|

**Return value**

| Type                                     | Description                                     |
| ----------------------------------------- | ----------------------------------------- |
| Promise<[CameraManager](#cameramanager)\> | Promise used to return the **CameraManager** instance.|

**Example**

```
camera.getCameraManager(context).then((cameraManager) => {
    console.log('Promise returned with the CameraManager instance.');
})
```

## CameraStatus

Enumerates the camera statuses.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                     | Default Value| Description        |
| ------------------------- | ------ | ------------ |
| CAMERA_STATUS_APPEAR      | 0      | The camera exists.  |
| CAMERA_STATUS_DISAPPEAR   | 1      | The camera does not exist.|
| CAMERA_STATUS_AVAILABLE   | 2      | The camera is ready.  |
| CAMERA_STATUS_UNAVAILABLE | 3      | The camera is not ready.|


## CameraPosition

Enumerates the camera positions.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                       | Default Value| Description            |
| --------------------------- | ------ | ---------------- |
| CAMERA_POSITION_UNSPECIFIED | 0      | Unspecified position.|
| CAMERA_POSITION_BACK        | 1      | Rear camera.      |
| CAMERA_POSITION_FRONT       | 2      | Front camera.      |

## CameraType

Enumerates the camera types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                   | Default Value| Description            |
| ----------------------- | ------ | ---------------- |
| CAMERA_TYPE_UNSPECIFIED | 0      | Unspecified camera type.|
| CAMERA_TYPE_WIDE_ANGLE  | 1      | Wide camera.      |
| CAMERA_TYPE_ULTRA_WIDE  | 2      | Ultra wide camera.  |
| CAMERA_TYPE_TELEPHOTO   | 3      | Telephoto camera.      |
| CAMERA_TYPE_TRUE_DEPTH  | 4      | True depth camera.      |


## ConnectionType

Enumerates the camera connection types.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                        | Default Value| Description         |
| ---------------------------- | ------ | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0      | Built-in camera.   |
| CAMERA_CONNECTION_USB_PLUGIN | 1      | Camera connected using USB.|
| CAMERA_CONNECTION_REMOTE     | 2      | Remote camera. |


## CameraManager

Implements camera management. Before calling any API in **CameraManager**, you must use **getCameraManager** to obtain a **CameraManager** instance.

### getCameras

getCameras(callback: AsyncCallback<Array<Camera\>\>): void

Obtains all cameras supported by the device. This API uses an asynchronous callback to return the array of supported cameras.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                                |
| -------- | ----------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback<Array<[Camera](#camera)\>\> | Yes  | Callback used to return the array of supported cameras.|

**Example**

```
cameraManager.getCameras((err, cameras) => {
    if (err) {
        console.error('Failed to get the cameras. ${err.message}');
        return;
    }
    console.log('Callback returned with an array of supported cameras: ' + cameras.length);
})
```

### getCameras

getCameras(): Promise<Array<Camera\>\>

Obtains all cameras supported by the device. This API uses a promise to return the array of supported cameras.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<Array<[Camera](#camera)\>\> | Promise used to return the array of supported cameras.|


**Example**

```
cameraManager.getCameras().then((cameraArray) => {
    console.log('Promise returned with an array of supported cameras: ' + cameraArray.length);
})
```

### Size

Size parameters. This interface used to get supported size for Preview + Photo + Video.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Default Value                                     | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| height | number                                      | Yes  | Desired height of the Preview + Photo + Video.                       |
| width | number                                       | Yes  | Desired width of the Preview + Photo + Video.|

### createCameraInput

createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput\>): void

Creates a **CameraInput** instance with the specified camera ID. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Default Value                                     | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| cameraId | string                                      | Yes  | Camera ID used to create the instance.                       |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | Yes  | Callback used to return the **CameraInput** instance.|

**Example**

```
cameraManager.createCameraInput(cameraId, (err, cameraInput) => {
    if (err) {
        console.error('Failed to create the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CameraInput instance.');
})
```

### createCameraInput

createCameraInput(cameraId: string): Promise<CameraInput\>

Creates a **CameraInput** instance with the specified camera ID. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Default Value| Mandatory| Description        |
| -------- | ------ | ---- | ------------ |
| cameraId | string | Yes  | Camera ID used to create the instance.|

**Return value**

| Type                                 | Description                                    |
| ------------------------------------- | ---------------------------------------- |
| Promise<[CameraInput](#camerainput)\> | Promise used to return the **CameraInput** instance.|

**Example**

```
cameraManager.createCameraInput(cameraId).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void

Creates a **CameraInput** instance with the specified camera position and camera type. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| position | [CameraPosition](#cameraposition)           | Yes  | Camera position.                         |
| type     | [CameraType](#cameratype)                   | Yes  | Camera type.                         |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | Yes  | Callback used to return the **CameraInput** instance.|

**Example**

```
cameraManager.createCameraInput(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_UNSPECIFIED, (err, cameraInput) => {
    if (err) {
        console.error('Failed to create the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput\>

Creates a **CameraInput** instance with the specified camera position and camera type. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                             | Mandatory| Description      |
| -------- | --------------------------------- | ---- | ---------- |
| position | [CameraPosition](#cameraposition) | Yes  | Camera position.|
| type     | [CameraType](#cameratype)         | Yes  | Camera type.|

**Return value**

| Type                                 | Description                                    |
| ------------------------------------- | ---------------------------------------- |
| Promise<[CameraInput](#camerainput)\> | Promise used to return the **CameraInput** instance.|

**Example**

```
cameraManager.createCameraInput(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_UNSPECIFIED).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance.');
})
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

Listens for camera status changes. This API uses a callback to return the camera status changes.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                                 | Mandatory| Description                                                |
| :------- | :---------------------------------------------------- | :--- | :--------------------------------------------------- |
| type     | string                                                | Yes  | Type of event to listen for. The value is fixed at **cameraStatus**, indicating the camera status change event.|
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | Yes  | Callback used to return the camera status change.                |

**Example**

```
cameraManager.on('cameraStatus', (err, cameraStatusInfo) => {
    if (err) {
        console.error('Failed to get cameraStatus callback. ${err.message}');
        return;
    }
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})
```

## Camera

After **[camera.getCameraManager](#cameragetcameramanager)** is called, a camera instance is returned, including camera-related metadata such as **cameraId**, **cameraPosition**, **cameraType**, and **connectionType**.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name          | Type                             | Read only| Description          |
| -------------- | --------------------------------- | ---- | -------------- |
| cameraId       | string                            | Yes  | Camera ID.      |
| cameraPosition | [CameraPosition](#cameraposition) | Yes  | Camera position.    |
| cameraType     | [CameraType](#cameratype)         | Yes  | Camera type.    |
| connectionType | [ConnectionType](#connectiontype) | Yes  | Camera connection type.|

**Example**

```
async function getCameraInfo("cameraId") {
    var cameraManager = await camera.getCameraManager();
    var cameras = await cameraManager.getCameras();
    var cameraObj = cameras[0];
    var cameraId = cameraObj.cameraId;
    var cameraPosition = cameraObj.cameraPosition;
    var cameraType = cameraObj.cameraType;
    var connectionType = cameraObj.connectionType;
}

```

## CameraStatusInfo

Describes the camera status information.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name  | Type                         | Description      |
| ------ | ----------------------------- | ---------- |
| camera | [Camera](#camera)             | Camera object.|
| status | [CameraStatus](#camerastatus) | Camera status.|


## CameraInput

Implements a **CameraInput** instance. Before calling any API in **CameraInput**, you must create a **CameraInput** instance.

### getCameraId

getCameraId(callback: AsyncCallback<string\>\): void

Obtains the camera ID based on which this **CameraInput** instance is created. This API uses an asynchronous callback to return the camera ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                      |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback<string\> | Yes  | Callback used to return the camera ID.|

**Example**

```
cameraInput.getCameraId((err, cameraId) => {
    if (err) {
        console.error('Failed to get the camera ID. ${err.message}');
        return;
    }
    console.log('Callback returned with the camera ID: ' + cameraId);
})
```

### getCameraId

getCameraId(): Promise<string\>

Obtains the camera ID based on which this **CameraInput** instance is created. This API uses a promise to return the camera ID.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type            | Description                         |
| ---------------- | ----------------------------- |
| Promise<string\> | Promise used to return the camera ID.|

**Example**

```
cameraInput.getCameraId().then((cameraId) => {
    console.log('Promise returned with the camera ID:' + cameraId);
})
```


### hasFlash

hasFlash(callback: AsyncCallback<boolean\>): void

Checks whether the device has flash light. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the flash light support status. The value **true** means that the device has flash light.|

**Example**

```
cameraInput.hasFlash((err, status) => {
    if (err) {
        console.error('Failed to check whether the device has flash light. ${err.message}');
        return;
    }
    console.log('Callback returned with flash light support status: ' + status);
})
```

### hasFlash

hasFlash(): Promise<boolean\>

Checks whether the device has flash light. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type             | Description                                                   |
| ----------------- | ------------------------------------------------------- |
| Promise<boolean\> | Promise used to return the flash light support status. The value **true** means that the device has flash light.|

**Example**

```
cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void

Checks whether a specified flash mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                                    |
| --------- | ----------------------- | ---- | ---------------------------------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.                        |
| callback  | AsyncCallback<boolean\> | Yes  | Callback used to return the flash mode support status. The value **true** means that the specified flash mode is supported.|

**Example**

```
cameraInput.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO, (err, status) => {
    if (err) {
        console.error('Failed to check whether the flash mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the flash mode support status: ' + status);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode): Promise<boolean\>

Checks whether a specified flash mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description            |
| --------- | ----------------------- | ---- | ---------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | Promise used to return the flash mode support status. The value **true** means that the specified flash mode is supported.|

**Example**

```
cameraInput.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO).then((status) => {
    console.log('Promise returned with flash mode support status.' + status);
})
```

### setFlashMode

setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void\>): void

Sets the flash mode. This API uses an asynchronous callback to return the result.

Before setting the parameters, do the following checks:

1. Use [hasFlash](#hasflash) to check whether the device has flash light.
2. Use [isFlashModeSupported](#isflashmodesupported) to check whether the device supports a specified flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description                    |
| --------- | ----------------------- | ---- | ------------------------ |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.        |
| callback  | AsyncCallback<void\>    | Yes  | Callback used to return the result.|

**Example**

```
cameraInput.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO, (err) => {
    if (err) {
        console.error('Failed to set the flash mode  ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setFlashMode.');
})
```

### setFlashMode

setFlashMode(flashMode: FlashMode): Promise<void\>

Sets the flash mode. This API uses a promise to return the result.

Before setting the parameters, do the following checks:

1. Use [hasFlash](#hasflash) to check whether the device has flash light.
2. Use [isFlashModeSupported](#isflashmodesupported) to check whether the device supports a specified flash mode.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                   | Mandatory| Description            |
| --------- | ----------------------- | ---- | ---------------- |
| flashMode | [FlashMode](#flashmode) | Yes  | Flash mode.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
cameraInput.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode

getFlashMode(callback: AsyncCallback<FlashMode\>): void

Obtains the current flash mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                   | Mandatory| Description                                    |
| -------- | --------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[FlashMode](#flashmode)\> | Yes  | Callback used to return the current flash mode.|

**Example**

```
cameraInput.getFlashMode((err, flashMode) => {
    if (err) {
        console.error('Failed to get the flash mode  ${err.message}');
        return;
    }
    console.log('Callback returned with current flash mode: ' + flashMode);
})
```

### getFlashMode

getFlashMode(): Promise<FlashMode\>

Obtains the current flash mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                             | Description                                   |
| --------------------------------- | --------------------------------------- |
| Promise<[FlashMode](#flashmode)\> | Promise used to return the current flash mode.|

**Example**

```
cameraInput.getFlashMode().then((flashMode) => {
    console.log('Promise returned with current flash mode : ' + flashMode);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void

Checks whether a specified focus mode is supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.                      |
| callback | AsyncCallback<boolean\> | Yes  | Callback used to return the focus mode support status. The value **true** means that the specified focus mode is supported.|

**Example**

```
cameraInput.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO, (err, status) => {
    if (err) {
        console.error('Failed to check whether the focus mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the focus mode support status: ' + status);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode): Promise<boolean\>

Checks whether a specified focus mode is supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| afMode | [FocusMode](#focusmode) | Yes  | Focus mode.|

**Return value**

| Type             | Description                                                       |
| ----------------- | ----------------------------------------------------------- |
| Promise<boolean\> | Promise used to return the flash mode support status. The value **true** means that the specified focus mode is supported.|

**Example**

```
cameraInput.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO).then((status) => {
    console.log('Promise returned with focus mode support status.' + status);
})
```

### setFocusMode

setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void

Sets the focus mode. This API uses an asynchronous callback to return the result.

Before setting the focus mode, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                   | Mandatory| Description                    |
| -------- | ----------------------- | ---- | ------------------------ |
| afMode   | [FocusMode](#focusmode) | Yes  | Focus mode.        |
| callback | AsyncCallback<void\>    | Yes  | Callback used to return the result.|

**Example**

```
cameraInput.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO, (err) => {
    if (err) {
        console.error('Failed to set the focus mode  ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setFocusMode.');
})
```

### setFocusMode

setFocusMode(afMode: FocusMode): Promise<void\>

Sets the focus mode. This API uses a promise to return the result.

Before setting the focus mode, use **[isFocusModeSupported](#isfocusmodesupported)** to check whether the focus mode is supported.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name  | Type                   | Mandatory| Description            |
| ------ | ----------------------- | ---- | ---------------- |
| afMode | [FocusMode](#focusmode) | Yes  | Focus mode.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
cameraInput.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode

getFocusMode(callback: AsyncCallback<FocusMode\>): void

Obtains the current focus mode. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                   | Mandatory| Description                                  |
| -------- | --------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback<[FocusMode](#focusmode)\> | Yes  | Callback used to return the current focus mode.|

**Example**

```
cameraInput.getFocusMode((err, afMode) => {
    if (err) {
        console.error('Failed to get the focus mode  ${err.message}');
        return;
    }
    console.log('Callback returned with current focus mode: ' + afMode);
})
```

### getFocusMode

getFocusMode(): Promise<FocusMode\>

Obtains the current focus mode. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------- |
| Promise<FocusMode\> | Promise used to return the current focus mode.|

**Example**

```
cameraInput.getFocusMode().then((afMode) => {
    console.log('Promise returned with current focus mode : ' + afMode);
})
```

### getZoomRatioRange

getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void

Obtains the zoom ratio range. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                          | Mandatory| Description                    |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback<Array<number\>\> | Yes  | Callback used to return the zoom ratio range.|

**Example**

```
cameraInput.getZoomRatioRange((err, zoomRatioRange) => {
    if (err) {
        console.error('Failed to get the zoom ratio range. ${err.message}');
        return;
    }
    console.log('Callback returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### getZoomRatioRange

getZoomRatioRange\(\): Promise<Array<number\>\>

Obtains the zoom ratio range. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type                    | Description                                       |
| ------------------------ | ------------------------------------------- |
| Promise<Array<number\>\> | Promise used to return the zoom ratio range.|

**Example**

```
cameraInput.getZoomRatioRange().then((zoomRatioRange) => {
    console.log('Promise returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void

Sets a zoom ratio. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                | Mandatory| Description                    |
| --------- | -------------------- | ---- | ------------------------ |
| zoomRatio | number               | Yes  | Zoom ratio to set.            |
| callback  | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
cameraInput.setZoomRatio(1, (err) => {
    if (err) {
        console.error('Failed to set the zoom ratio value ${err.message}');
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

| Name     | Type  | Mandatory| Description        |
| --------- | ------ | ---- | ------------ |
| zoomRatio | number | Yes  | Zoom ratio to set.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
cameraInput.setZoomRatio(1).then(() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio

getZoomRatio(callback: AsyncCallback<number\>): void

Obtains the current zoom ratio. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                    |
| -------- | ---------------------- | ---- | ------------------------ |
| callback | AsyncCallback<number\> | Yes  | Callback used to return the current zoom ratio.|

**Example**

```
cameraInput.getZoomRatio((err, zoomRatio) => {
    if (err) {
        console.error('Failed to get the zoom ratio ${err.message}');
        return;
    }
    console.log('Callback returned with current zoom ratio: ' + zoomRatio);
})
```

### getZoomRatio

getZoomRatio(): Promise<number\>

Obtains the current zoom ratio. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type            | Description                       |
| ---------------- | --------------------------- |
| Promise<number\> | Promise used to return the current zoom ratio.|

**Example**

```
cameraInput.getZoomRatio().then((zoomRatio) => {
    console.log('Promise returned with current zoom ratio : ' + zoomRatio);
})
```

### release

release\(callback: AsyncCallback<void\>\): void

Releases this **CameraInput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
cameraInput.release((err) => {
    if (err) {
        console.error('Failed to release the CameraInput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **CameraInput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

Listens for focus state changes. This API uses a callback to return the focus state changes.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                     | Mandatory| Description                                                    |
| :------- | :---------------------------------------- | :--- | :------------------------------------------------------- |
| type     | string                                    | Yes  | Type of event to listen for. The value is fixed at **focusStateChange**, indicating the focus state change event.|
| callback | AsyncCallback<[FocusState](#focusstate)\> | Yes  | Callback used to return the focus state change.                            |

**Example**

```
cameraInput.on('focusStateChange', (focusState) => {
    console.log('Focus state  : ' + focusState);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CameraInputError\>): void

Listens for **CameraInput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                            | Mandatory| Description                                           |
| :------- | :------------------------------- | :--- | :---------------------------------------------- |
| type     | string                           | Yes  | Type of event to listen for. The value is fixed at **error**, indicating the camera input error event.|
| callback | ErrorCallback<CameraInputError\> | Yes  | Callback used to return the capture input errors.                       |

**Example**

```
cameraInput.on('error', (cameraInputError) => {
    console.log('Camera input error code: ' + cameraInputError.code);
})
```

## CameraInputErrorCode

Enumerates the CameraInput error code.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| ERROR_UNKNOWN       | -1      | Unknown error.|

## CameraInputError

Camera input error object which extends **Error** interface.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| code                | [CameraInputErrorCode](#camerainputerrorcode)     | Used to get error code in CameraInput on('error') callback|

## FlashMode

Enumerates the flash modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| FLASH_MODE_CLOSE       | 0      | The flash is off.|
| FLASH_MODE_OPEN        | 1      | The flash is on.|
| FLASH_MODE_AUTO        | 2      | The flash mode is auto, indicating that the flash fires automatically depending on the shooting conditions.|
| FLASH_MODE_ALWAYS_OPEN | 3      | The flash is steady on.|

## FocusMode

Enumerates the focus modes.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                      | Default Value| Description              |
| -------------------------- | ------ | ------------------ |
| FOCUS_MODE_MANUAL          | 0      | Manual focus.    |
| FOCUS_MODE_CONTINUOUS_AUTO | 1      | Continuous auto focus.|
| FOCUS_MODE_AUTO            | 2      | Auto focus.    |
| FOCUS_MODE_LOCKED          | 3      | Locked focus.        |

## FocusState

Enumerates the focus states.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                 | Default Value| Description        |
| --------------------- | ------ | ------------ |
| FOCUS_STATE_SCAN      | 0      | Scanning.  |
| FOCUS_STATE_FOCUSED   | 1      | Focused.|
| FOCUS_STATE_UNFOCUSED | 2      | Unfocused.|

## camera.createCaptureSession

createCaptureSession\(context: Context, callback: AsyncCallback<CaptureSession\>\): void

Creates a **CaptureSession** instance. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                             | Mandatory| Description                                  |
| -------- | ------------------------------------------------- | ---- | -------------------------------------- |
| context  | Context                                           | Yes  | Application context.                          |
| callback | AsyncCallback<[CaptureSession](#capturesession)\> | Yes  | Callback used to return the **CaptureSession** instance.|

**Example**

```
camera.createCaptureSession((context), (err, captureSession) => {
    if (err) {
        console.error('Failed to create the CaptureSession instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CaptureSession instance.' + captureSession);
});
```

## camera.createCaptureSession

createCaptureSession(context: Context\): Promise<CaptureSession\>;

Creates a **CaptureSession** instance. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type   | Mandatory| Description        |
| ------- | ------- | ---- | ------------ |
| context | Context | Yes  | Application context.|

**Return value**

| Type                                       | Description                                     |
| ------------------------------------------- | ----------------------------------------- |
| Promise<[CaptureSession](#capturesession)\> | Promise used to return the **CaptureSession** instance.|

**Example**

```
camera.createCaptureSession(context).then((captureSession) => {
    console.log('Promise returned with the CaptureSession instance');
})
```

## CaptureSession

Implements session capture.

### beginConfig

beginConfig\(callback: AsyncCallback<void\>\): void

Starts configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
captureSession.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
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

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig

commitConfig\(callback: AsyncCallback<void\>\): void

Commits the configuration for this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
captureSession.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
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

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput

addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

Adds a **CameraInput** instance to this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.addInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to add the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is added.');
});
```

### addInput

addInput\(cameraInput: CameraInput\): Promise<void\>

Adds a **CameraInput** instance to this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to add.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### addOutput

addOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void

Adds a **PreviewOutput** instance to this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name         | Type                           | Mandatory| Description                         |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | Yes  | **PreviewOutput** instance to add.|
| callback      | AsyncCallback<void\>            | Yes  | Callback used to return the result.     |

**Example**

```
captureSession.addOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to add the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is added.');
});
```

### addOutput

addOutput\(previewOutput: PreviewOutput\): Promise<void\>

Adds a **PreviewOutput** instance to this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name         | Type                           | Mandatory| Description                         |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | Yes  | **PreviewOutput** instance to add.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.addOutput(previewOutput).then(() => {
    console.log('Promise used to indicate that the PreviewOutput instance is added.');
})
```

### addOutput

addOutput\(photoOutput: PhotoOutput, callback: AsyncCallback<void\>\): void

Adds a **PhotoOutput** instance to this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | Yes  | **PhotoOutput** instance to add.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.addOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to add the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is added.');
});
```

### addOutput

addOutput\(photoOutput: PhotoOutput\): Promise<void\>

Adds a **PhotoOutput** instance to this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | Yes  | **PhotoOutput** instance to add.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
captureSession.addOutput(photoOutput).then(() => {
    console.log('Promise used to indicate that the PhotoOutput instance is added.');
})
```

### addOutput

addOutput\(videoOutput: VideoOutput, callback: AsyncCallback<void\>\): void

Adds a **VideoOutput** instance to this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | Yes  | **VideoOutput** instance to add.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.addOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to add the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is added.');
});
```

### addOutput

addOutput\(videoOutput: VideoOutput\): Promise<void\>

Adds a **VideoOutput** instance to this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | Yes  | **VideoOutput** instance to add.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
captureSession.addOutput(videoOutput).then(() => {
    console.log('Promise used to indicate that the VideoOutput instance is added.');
})
```

### removeInput

removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

Removes a **CameraInput** instance from this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.removeInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to remove the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the cameraInput instance is removed.');
});
```

### removeInput

removeInput\(cameraInput: CameraInput\): Promise<void\>

Removes a **CameraInput** instance from this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | Yes  | **CameraInput** instance to remove.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### removeOutput

removeOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void

Removes a **PreviewOutput** instance from this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name         | Type                           | Mandatory| Description                         |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | Yes  | **PreviewOutput** instance to remove.|
| callback      | AsyncCallback<void\>            | Yes  | Callback used to return the result.     |

**Example**

```
captureSession.removeOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is removed.');
});
```

### removeOutput

removeOutput(previewOutput: PreviewOutput): Promise<void\>

Removes a **PreviewOutput** instance from this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name         | Type                           | Mandatory| Description                         |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | Yes  | **PreviewOutput** instance to remove.|


**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
captureSession.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is removed.');
})
```

### removeOutput

removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void\>): void

Removes a **PhotoOutput** instance from this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | Yes  | **PhotoOutput** instance to remove.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.removeOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is removed.');
});
```

### removeOutput

removeOutput(photoOutput: PhotoOutput): Promise<void\>

Removes a **PhotoOutput** instance from this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | Yes  | **PhotoOutput** instance to remove.|


**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
captureSession.removeOutput(photoOutput).then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is removed.');
})
```

### removeOutput

removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void\>): void

Removes a **VideoOutput** instance from this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | Yes  | **VideoOutput** instance to remove.|
| callback    | AsyncCallback<void\>        | Yes  | Callback used to return the result.   |

**Example**

```
captureSession.removeOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is removed.');
});
```

### removeOutput

removeOutput(videoOutput: VideoOutput): Promise<void\>

Removes a **VideoOutput** instance from this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name       | Type                       | Mandatory| Description                       |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | Yes  | **VideoOutput** instance to remove.|


**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
captureSession.removeOutput(videoOutput).then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is removed.');
})
```

### start

start\(callback: AsyncCallback<void\>\): void

Starts this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
captureSession.start((err) => {
    if (err) {
        console.error('Failed to start the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session start success.');
});
```

### start

start\(\): Promise<void\>

Starts this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop

stop\(callback: AsyncCallback<void\>\): void

Stops this **CaptureSession** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**


| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
captureSession.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});
```

### stop

stop(): Promise<void\>

Stops this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

Releases this **CaptureSession** instance. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
captureSession.release((err) => {
    if (err) {
        console.error('Failed to release the CaptureSession instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **CaptureSession** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CaptureSessionError\>): void

Listens for **CaptureSession** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                               | Mandatory| Description                                         |
| :------- | :---------------------------------- | :--- | :-------------------------------------------- |
| type     | string                              | Yes  | Type of event to listen for. The value is fixed at **error**, indicating the capture session error event.|
| callback | ErrorCallback<CaptureSessionError\> | Yes  | Callback used to return the capture session errors.                 |

**Example**

```
captureSession.on('error', (captureSessionError) => {
    console.log('Capture session error code: ' + captureSessionError.code);
})
```

## CaptureSessionErrorCode

Enumerates the CaptureSession error code.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| ERROR_UNKNOWN       | -1      | Unknown error.|

## CaptureSessionError

Capture session error object which extends **Error** interface.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| code                | [CaptureSessionErrorCode](#capturesessionerrorcode)     | Used to get error code in CaptureSession on('error') callback.|

## camera.createPreviewOutput

createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void

Creates a **PreviewOutput** instance. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                           | Mandatory| Description                                 |
| --------- | ----------------------------------------------- | ---- | ------------------------------------- |
| surfaceId | string                                          | Yes  | Surface ID received from **XComponent**.   |
| callback  | AsyncCallback<[PreviewOutput](#previewoutput)\> | Yes  | Callback used to return the **PreviewOutput** instance.|

**Example**

```
camera.createPreviewOutput(("surfaceId"), (err, previewOutput) => {
    if (err) {
        console.error('Failed to create the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with previewOutput instance');
});
```

## camera.createPreviewOutput

createPreviewOutput(surfaceId: string): Promise\<PreviewOutput>

Creates a **PreviewOutput** instance. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type  | Mandatory| Description                              |
| --------- | ------ | ---- | ---------------------------------- |
| surfaceId | string | Yes  | Surface ID received from **XComponent**.|

**Return value**

| Type                                     | Description                       |
| ----------------------------------------- | --------------------------- |
| Promise<[PreviewOutput](#previewoutput)\> | Promise used to return the **PreviewOutput** instance.|

**Example**

```
camera.createPreviewOutput("surfaceId").then((previewOutput) => {
    console.log('Promise returned with the PreviewOutput instance');
})
```

## PreviewOutput

Implements preview output.

### release

release(callback: AsyncCallback<void\>): void

Releases this **PreviewOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
previewOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **PreviewOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for preview frame start events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                        |
| :------- | :------------------- | :--- | :------------------------------------------- |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **frameStart**, indicating the preview frame start event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                    |

**Example**

```
previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

Listens for preview frame end events. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                      |
| :------- | :------------------- | :--- | :----------------------------------------- |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **frameEnd**, indicating the preview frame end event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                  |

**Example**

```
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PreviewOutputError\>): void

Listens for **PreviewOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                              | Mandatory| Description                                         |
| :------- | :--------------------------------- | :--- | :-------------------------------------------- |
| type     | string                             | Yes  | Type of event to listen for. The value is fixed at **error**, indicating the preview output error event.|
| callback | ErrorCallback<PreviewOutputError\> | Yes  | Callback used to return the preview output errors.                 |

**Example**

```
previewOutput.on('error', (previewOutputError) => {
    console.log('Preview output error code: ' + previewOutputError.code);
})
```

## PreviewOutputErrorCode

Enumerates the PreviewOutput error code.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| ERROR_UNKNOWN       | -1      | Unknown error.|

## PreviewOutputError

Preview output error object which extends **Error** interface.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| code                | [PreviewOutputErrorCode](#previewoutputerrorcode)     | Used to get error code in PreviewOutput on('error') callback.|

## camera.createPhotoOutput

createPhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void

Creates a **PhotoOutput** instance. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                       | Mandatory| Description                               |
| --------- | ------------------------------------------- | ---- | ----------------------------------- |
| surfaceId | string                                      | Yes  | Surface ID received from **ImageReceiver**.  |
| callback  | AsyncCallback<[PhotoOutput](#photooutput)\> | Yes  | Callback used to return the **PhotoOutput** instance.|

**Example**

```
camera.createPhotoOutput(("surfaceId"), (err, photoOutput) => {
    if (err) {
        console.error('Failed to create the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the PhotoOutput instance.');
});
```

## camera.createPhotoOutput

createPhotoOutput(surfaceId: string): Promise<PhotoOutput\>

Creates a **PhotoOutput** instance. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type  | Mandatory| Description                             |
| --------- | ------ | ---- | --------------------------------- |
| surfaceId | string | Yes  | Surface ID received from **ImageReceiver**.|

**Return value**

| Type                                 | Description                                  |
| ------------------------------------- | -------------------------------------- |
| Promise<[PhotoOutput](#photooutput)\> | Promise used to return the **PhotoOutput** instance.|

**Example**

```
camera.createPhotoOutput("surfaceId").then((photoOutput) => {
    console.log('Promise returned with PhotoOutput instance');
})
```
## ImageRotation

Enumerates the image rotation angles.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name        | Default Value| Description           |
| ------------ | ------ | --------------- |
| ROTATION_0   | 0      | The image rotates 0 degrees.  |
| ROTATION_90  | 90     | The image rotates 90 degrees. |
| ROTATION_180 | 180    | The image rotates 180 degrees.|
| ROTATION_270 | 270    | The image rotates 270 degrees.|



## QualityLevel

Enumerates the image quality levels.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                | Default Value| Description          |
| -------------------- | ------ | -------------- |
| QUALITY_LEVEL_HIGH   | 0      | High image quality.  |
| QUALITY_LEVEL_MEDIUM | 1      | Medium image quality.|
| QUALITY_LEVEL_LOW    | 2      | Low image quality.  |


## PhotoCaptureSetting

Defines the settings for image capture.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name    | Type                           | Mandatory| Description          |
| -------- | ------------------------------- | ---- | -------------- |
| quality  | [QualityLevel](#qualitylevel)   | No  | Photo image quality.    |
| rotation | [ImageRotation](#imagerotation) | No  | Photo rotation.|


## PhotoOutput

Implements photo output.

### capture

capture(callback: AsyncCallback<void\>): void

Captures a photo. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
photoOutput.capture((err) => {
    if (err) {
        console.error('Failed to capture the photo ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback<void\>): void

Captures a photo with the specified capture settings. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                    |
| -------- | ------------------------------------------- | ---- | ------------------------ |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | Yes  | Photo capture settings.              |
| callback | AsyncCallback<void\>                        | Yes  | Callback used to return the result.|

**Example**

```
photoOutput.capture(settings, (err) => {
    if (err) {
        console.error('Failed to capture the photo ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the photo capture request success.');
});
```

### capture

capture(setting?: PhotoCaptureSetting): Promise<void\>

Captures a photo with the specified capture settings. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name   | Type                                       | Mandatory| Description      |
| ------- | ------------------------------------------- | ---- | ---------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | No  | Photo capture settings.|

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### release

release(callback: AsyncCallback<void\>): void

Releases this **PhotoOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
photoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **PhotoOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is released successfully.');
})
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

Listens for photo capture start events. This API uses a callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                  | Mandatory| Description                                            |
| :------- | :--------------------- | :--- | :----------------------------------------------- |
| type     | string                 | Yes  | Type of event to listen for. The value is fixed at **captureStart**, indicating the photo capture start event.|
| callback | AsyncCallback<number\> | Yes  | Callback used to return the capture ID.              |

**Example**

```
photoOutput.on('captureStart', (err, captureId) => {
    console.log('photo capture stated, captureId : ' + captureId);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

Listens for frame shutter events. This API uses a callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                            | Mandatory| Description                                          |
| :------- | :------------------------------- | :--- | :--------------------------------------------- |
| type     | string                           | Yes  | Type of event to listen for. The value is fixed at **frameShutter**, indicating the frame shutter event.|
| callback | AsyncCallback<FrameShutterInfo\> | Yes  | Callback used to return the frame shutter information.                  |

**Example**

```
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log('photo capture end, captureId : ' + frameShutterInfo.captureId);
    console.log('Timestamp for frame : ' + frameShutterInfo.timestamp);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

Listens for photo capture end events. This API uses a callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                          | Mandatory| Description                                          |
| :------- | :----------------------------- | :--- | :--------------------------------------------- |
| type     | string                         | Yes  | Type of event to listen for. The value is fixed at **captureEnd**, indicating the photo capture end event.|
| callback | AsyncCallback<CaptureEndInfo\> | Yes  | Callback used to return the photo capture end information.                  |

**Example**

```
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log('photo capture end, captureId : ' + captureEndInfo.captureId);
    console.log('frameCount : ' + captureEndInfo.frameCount);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PhotoOutputError\>): void

Listens for **PhotoOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                            | Mandatory| Description                                     |
| :------- | :------------------------------- | :--- | :---------------------------------------- |
| type     | string                           | Yes  | Type of event to listen for. The value is fixed at **error**, indicating the photo output error event.|
| callback | ErrorCallback<PhotoOutputError\> | Yes  | Callback used to return the photo output errors.             |

**Example**

```
photoOutput.on('error', (photoOutputError) => {
    console.log('Photo output error code: ' + photoOutputError.code);
})
```

### FrameShutterInfo

Frame shutter callback info which provides **captureId** & **timestamp** parameteres & indicates the frame shutter event.

**Parameteres**

| Name    | Type                            | Mandatory| Description                                     |
| :------- | :------------------------------- | :--- | :---------------------------------------- |
| captureId     | number                           | Yes  | Capture id.|
| timestamp | number | Yes  | Timestamp for frame.    

### CaptureEndInfo

Capture end info which provides **captureId** & **frameCount** parameteres & indicates the photo capture end event.

**Parameteres**

| Name    | Type                            | Mandatory| Description                                     |
| :------- | :------------------------------- | :--- | :---------------------------------------- |
| captureId     | number                           | Yes  | Capture id.|
| frameCount | number | Yes  | Frame count.    

## PhotoOutputErrorCode

Enumerates the PhotoOutput error code.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| ERROR_UNKNOWN       | -1      | Unknown error.|

## PhotoOutputError

Photo output error object which extends **Error** interface.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| code                | [PhotoOutputErrorCode](#photooutputerrorcode)     | Used to get error code in PhotoOutput on('error') callback.|

## camera.createVideoOutput

createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput\>): void

Creates a **VideoOutput** instance. This API uses an asynchronous callback to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type                                       | Mandatory| Description                               |
| --------- | ------------------------------------------- | ---- | ----------------------------------- |
| surfaceId | string                                      | Yes  | Surface ID received from **VideoRecorder**.  |
| callback  | AsyncCallback<[VideoOutput](#videooutput)\> | Yes  | Callback used to return the **VideoOutput** instance.|

**Example**

```
camera.createVideoOutput(("surfaceId"), (err, videoOutput) => {
    if (err) {
        console.error('Failed to create the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the VideoOutput instance');
});
```

## camera.createVideoOutput

createVideoOutput(surfaceId: string): Promise<VideoOutput\>

Creates a **VideoOutput** instance. This API uses a promise to return the instance.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name     | Type  | Mandatory| Description                             |
| --------- | ------ | ---- | --------------------------------- |
| surfaceId | string | Yes  | Surface ID received from **VideoRecorder**.|

**Return value**

| Type                                 | Description                                  |
| ------------------------------------- | -------------------------------------- |
| Promise<[VideoOutput](#videooutput)\> | Promise used to return the **VideoOutput** instance.|

**Example**

```
camera.createVideoOutput("surfaceId"
).then((videoOutput) => {
    console.log('Promise returned with the VideoOutput instance');
})
```

## VideoOutput

Implements video output.

### start

start(callback: AsyncCallback<void\>): void

Starts the video output. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
videoOutput.start((err) => {
    if (err) {
        console.error('Failed to start the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output start success.');
});
```

### start

start(): Promise<void\>

Starts the video output. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
```

### stop

stop(callback: AsyncCallback<void\>): void

Stops the video output. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
videoOutput.stop((err) => {
    if (err) {
        console.error('Failed to stop the video output ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
});
```

### stop

stop(): Promise<void\>

Stops the video output. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|

**Example**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
})
```

### release

release(callback: AsyncCallback<void\>): void

Releases this **VideoOutput** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.|

**Example**

```
videoOutput.release((err) => {
    if (err) {
        console.error('Failed to release the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is released successfully.');
});
```

### release

release(): Promise<void\>

Releases this **VideoOutput** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Return value**

| Type          | Description                       |
| -------------- | --------------------------- |
| Promise<void\> | Promise used to return the result.|


**Example**

```
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is released successfully.');
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

Listens for video frame start events. This API uses a callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                            |
| :------- | :------------------- | :--- | :----------------------------------------------- |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **frameStart**, indicating the video frame start event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                        |

**Example**

```
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

Listens for video frame end events. This API uses a callback to return the event information.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                | Mandatory| Description                                          |
| :------- | :------------------- | :--- | :--------------------------------------------- |
| type     | string               | Yes  | Type of event to listen for. The value is fixed at **frameEnd**, indicating the video frame end event.|
| callback | AsyncCallback<void\> | Yes  | Callback used to return the result.                      |

**Example**

```
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<VideoOutputError\>): void

Listens for **VideoOutput** errors. This API uses a callback to return the errors.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name    | Type                       | Mandatory| Description                                         |
| :------- | :-------------------------- | :--- | :-------------------------------------------- |
| type     | string                      | Yes  | Type of event to listen for. The value is fixed at **error**, indicating the video output error event.|
| callback | Callback<VideoOutputError\> | Yes  | Callback used to return the video output errors.                 |

**Example**

```
videoOutput.on('error', (VideoOutputError) => {
    console.log('Video output error code: ' + VideoOutputError.code);
})
```

## VideoOutputErrorCode

Enumerates the VideoOutput error code.

**System capability**: SystemCapability.Multimedia.Camera.Core

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| ERROR_UNKNOWN       | -1      | Unknown error.|

## VideoOutputError

Photo output error object which extends **Error** interface.

**System capability**: SystemCapability.Multimedia.Camera.Core

**Parameters**

| Name                  | Default Value| Description        |
| ---------------------- | ------ | ------------ |
| code                | [VideoOutputErrorCode](#videooutputerrorcode)     | Used to get error code in VideoOutput on('error') callback.|