# Camera<a name="EN-US_TOPIC_0000001149807881"></a>

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import camera from '@ohos.multimedia.camera';
```

## Required Permissions

```
ohos.permission.CAMERA
```
## getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets a **CameraManager** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                          | Mandatory | Description                                         |
|----------|-------------------------------|-----------|-----------------------------------------------------|
| context  | Context                       | Yes       | Application context                                 |
| callback | AsyncCallback<CameraManager\> | Yes       | Callback used to return the CameraManager instance  |

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

## getCameraManager(context: Context): Promise<CameraManager\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets a **CameraManager** instance. This method uses a promise to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                |
|----------|----------------------|-----------|----------------------------|
| context  | Context              | Yes       | Application context        |

**Return values**

| Type                    | Description                                            |
|-------------------------|--------------------------------------------------------|
| Promise<CameraManager\> | Promise used to return the **CameraManager** instance  |

**Example**

```
camera.getCameraManager(context).then((cameraManger) => {
    console.log('Promise returned with the CameraManager instance.');
})
```

## CameraStatus<a name="section_camera_status"></a>

Enumerates camera status types.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                      | Default Value | Description        |
|---------------------------|---------------|--------------------|
| CAMERA_STATUS_APPEAR      | 0             | Camera appear      |
| CAMERA_STATUS_DISAPPEAR   | 1             | Camera disappear   |
| CAMERA_STATUS_AVAILABLE   | 2             | Camera available   |
| CAMERA_STATUS_UNAVAILABLE | 3             | Camera unavailable |


## CameraPosition<a name="section_camera_position"></a>

Enumerates the camera positions.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                        | Default value | Description           |
|-----------------------------|---------------|-----------------------|
| CAMERA_POSITION_UNSPECIFIED | 0             | Unspecified position  |
| CAMERA_POSITION_BACK        | 1             | Rear camera           |
| CAMERA_POSITION_FRONT       | 2             | Front camera          |

## CameraType<a name="section_camera_type"></a>

Enumerates the camera types.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                    | Default value | Description             |
|-------------------------|---------------|-------------------------|
| CAMERA_TYPE_UNSPECIFIED | 0             | Unspecified camera type |
| CAMERA_TYPE_WIDE_ANGLE  | 1             | Wide camera             |
| CAMERA_TYPE_ULTRA_WIDE  | 2             | Ultra wide camera       |
| CAMERA_TYPE_TELEPHOTO   | 3             | Telephoto camera        |
| CAMERA_TYPE_TRUE_DEPTH  | 4             | True depth camera       |


## ConnectionType<a name="section_ConnectionType"></a>

Enumerates camera connection types.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                         | Default value | Description                |
|------------------------------|---------------|----------------------------|
| CAMERA_CONNECTION_BUILT_IN   | 0             | Built-in camera            |
| CAMERA_CONNECTION_USB_PLUGIN | 1             | Camera connected using USB  |
| CAMERA_CONNECTION_REMOTE     | 2             | Remote camera               |

## CameraManager<a name="section_CameraManager"></a>

Implements camera management, including getting supported cameras and creating **CameraInput** instances.

### getCameras(callback: AsyncCallback<Array<Camera\>\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets all cameras supported by the device. This method uses an asynchronous callback to return the array of supported cameras.

**Parameters**

| Name     | Type                           | Mandatory | Description                                             |
|----------|--------------------------------|-----------|---------------------------------------------------------|
| callback | AsyncCallback<Array<Camera\>\> | Yes       | Callback used to return the array of supported cameras. |

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

### getCameras(): Promise<Array<Camera\>\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets all cameras supported by the device. This method uses a promise to return the array of supported cameras.

**Return values**

| Type                   | Description                                            |
|------------------------|--------------------------------------------------------|
| Promise<Array<Camera\>\> | Promise used to return an array of supported cameras |


**Example**

```
cameraManager.getCameras().then((cameraArray) => {
    console.log('Promise returned with an array of supported cameras: ' + cameraArray.length);
})
```

### createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CameraInput** instance with the specified camera ID. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name     | Default value                | Mandatory | Description                                      |
|----------|------------------------------|-----------|--------------------------------------------------|
| cameraId | string                       | Yes       | Camera ID used to create the instance            |
| callback | AsyncCallback<CameraInput\>  | Yes       | Callback used to return the CameraInput instance |

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

### createCameraInput(cameraId: string): Promise<CameraInput\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CameraInput** instance with the specified camera ID. This method uses a promise to return the instance.

**Parameters**

| Name     | Default value               | Mandatory | Description                              |
|----------|-----------------------------|-----------|------------------------------------------|
| cameraId | string                      | Yes       | Camera ID used to create the instance    |

**Return values**

| Type                    | Description                                     |
|-------------------------|-------------------------------------------------|
| Promise<CameraInput\>   | Promise used to return the CameraInput instance |

**Example**

```
cameraManager.createCameraInput(cameraId).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CameraInput** instance with the specified camera position and camera type. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name     | Type                        | Mandatory | Description                                       |
|----------|-----------------------------|-----------|---------------------------------------------------|
| position | CameraPosition              | Yes       | Camera position                                   |
| type     | CameraType                  | Yes       | Camera type                                       |
| callback | AsyncCallback<CameraInput\> | Yes       | Callback used to return the CameraInput instance |

**Example**

```
cameraManager.createCameraInput(cameraPosition, cameraType, (err, cameraInput) => {
    if (err) {
        console.error('Failed to create the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CameraInput instance');
})
```

### createCameraInput(position: CameraPosition, type: CameraType): Promise<CameraInput\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CameraInput** instance with the specified camera position and camera type. This method uses a promise to return the instance.

**Parameters**

| Name     | Type                       | Mandatory | Description                            |
|----------|----------------------------|-----------|----------------------------------------|
| position | CameraPosition             | Yes       | Camera position                        |
| type     | CameraType                 | Yes       | Camera type                            |

**Return values**

| Type                    | Description                                     |
|-------------------------|-------------------------------------------------|
| Promise<CameraInput\>   | Promise used to return the CameraInput instance |

**Example**

```
cameraManager.createCameraInput(cameraPosition, cameraType).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance.');
})
```

### on(type: 'cameraStatus', callback: Callback<CameraStatusInfo\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for camera status changes. This method uses a callback to get camera status changes.

**Parameters**

| Name     | Type                   | Mandatory | Description                                          |
| :------- | :--------------------- | :-------- | :--------------------------------------------------- |
| type     | string                 | Yes       | Camera status event.                                 |
| callback | Callback<CameraStatusInfo\> | Yes  | Callback used to get the camera status change.       |

**Example**

```
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})
```

## Camera<a name="section_Camera"></a>

when we call *cameraManager.getCameras()* API, then it will return the **Camera** class which will have all camera-related metadata such as *cameraId, cameraPosition, cameraType & connectionType*.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Fields**

| Name           | Type           | Access   | Description            |
|----------------|----------------|----------|------------------------|
| cameraId       | string         | readonly | Camera ID              |
| cameraPosition | cameraPosition | readonly | Camera position        |
| cameraType     | cameraType     | readonly | Camera type            |
| connectionType | connectionType | readonly | Camera connection type |

```
async function getCameraInfo() {
    var cameraManager = await camera.getCameraManager();
    var cameras = await cameraManager.getCameras();
    var cameraObj = cameras[0];
    var cameraId = cameraObj.cameraId;
    var cameraPosition = cameraObj.cameraPosition;
    var cameraType = cameraObj.cameraType;
    var cameraId = cameraObj.connectionType;
}

```

## CameraStatusInfo<a name="section_Camera"></a>

This interface is a CameraManager callback API return. **CameraStatusInfo** will have *Camera* class & *CameraStatus* predefine constants.From *Camera* class, we can have all camera-related metadata & from *CameraStatus* constants, we will have information such as *APPEAR, DISAPPEAR, AVAILABLE & UNAVAILABLE*.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Fields**

| Name           | Type           | Description      |
|----------------|----------------|------------------|
| camera         | Camera         | Camera object    |
| status         | CameraStatus   | Camera status    |


## CameraInput<a name="section_CameraInput"></a>

Implements a **CameraInput** instance.

### getCameraId(callback: AsyncCallback<string\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the camera ID based on which this **CameraInput** instance is created. This method uses an asynchronous callback to return the camera ID.

**Parameters**

| Name     | Type                   | Mandatory | Description                           |
|----------|------------------------|-----------|---------------------------------------|
| callback | AsyncCallback<string\> | Yes       | Callback used to return the camera ID |

```
cameraInput.getCameraId((err, cameraId) => {
    if (err) {
        console.error('Failed to get the camera ID. ${err.message}');
        return;
    }
    console.log('Callback returned with the camera ID: ' + cameraId);
})
```

### getCameraId(): Promise<string\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the camera ID based on which this **CameraInput** instance is created. This method uses a promise to return the camera ID.

**Return values**

| Type                   | Description                          |
|------------------------|--------------------------------------|
| Promise<string\>       | Promise used to return the camera ID |

**Example**

```
cameraInput.getCameraId().then((cameraId) => {
    console.log('Promise returned with the camera ID:' + cameraId);
})
```

### hasFlash(callback: AsyncCallback<boolean\>): void; <a name="sec_hasFlash"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether the device has flash light. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                    | Mandatory | Description                                        |
|----------|-------------------------|-----------|----------------------------------------------------|
| callback | AsyncCallback<boolean\> | Yes       | Callback used to return the flash light support status |

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

### hasFlash(): Promise<boolean\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether the device has flash light. This method uses a promise to return the result.

**Return values**

| Type                  | Description                                            |
|-----------------------|--------------------------------------------------------|
| Promise<boolean\>     | Promise used to return the flash light support status  |

**Example**

```
cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
})
```

### isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void; <a name="sec_isFlashModeSupported"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether a specified flash mode is supported. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode                                         |
| callback  | AsyncCallback<boolean\> | Yes       | Callback used to return the device flash support status |

**Example**

```
cameraInput.isFlashModeSupported(flashMode, (err, status) => {
    if (err) {
        console.error('Failed to check whether the flash mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the flash mode support status: ' + status);
})
```

### isFlashModeSupported(flashMode: FlashMode): Promise<boolean\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether a specified flash mode is supported. This method uses a promise to return the result.

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode                    |

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<boolean\>     | Promise used to return flash mode support status. |

**Example**

```
cameraInput.isFlashModeSupported(flashMode).then((status) => {
    console.log('Promise returned with flash mode support status.' + status);
})
```

### setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets flash mode. This method uses an asynchronous callback to return the result.

Note: Before setting the flash mode, check the support for the flash light (<a href="#sec_hasFlash">hasFlash</a> method) and flash mode support (<a href="#sec_isFlashModeSupported">isFlashModeSupported</a> method);

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode             |
| callback  | AsyncCallback<void\> | Yes       | Callback used to return the result         |

**Example**

```
cameraInput.setFlashMode(flashMode, (err) => {
    if (err) {
        console.error('Failed to set the flash mode  ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setFlashMode.');
})
```

### setFlashMode(flashMode: FlashMode): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets flash mode. This method uses a promise to return the result.

Note: Before setting the flash mode, check the support for the flash light (<a href="#sec_hasFlash">hasFlash</a> method) and flash mode support (<a href="#sec_isFlashModeSupported">isFlashModeSupported</a> method);

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode                    |

**Return values**

| Type                  | Description                             |
|-----------------------|-----------------------------------------|
| Promise<void\>        | Promise used to return the result       |

**Example**

```
cameraInput.setFlashMode(flashMode).then(() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode(callback: AsyncCallback<FlashMode\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets current flash mode. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                      | Mandatory | Description                                    |
|-----------|---------------------------|-----------|------------------------------------------------|
| callback  | AsyncCallback<FlashMode\> | Yes       | Callback used to return the current flash mode |

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

### getFlashMode(): Promise<FlashMode\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets current flash mode. This method uses a promise to return the result.

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<FlashMode\>   | Promise used to return the flash mode             |

**Example**

```
cameraInput.getFlashMode().then((flashMode) => {
    console.log('Promise returned with current flash mode : ' + flashMode);
})
```

### isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void; <a name="sec_isFocusModeSupported"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether a specified focus mode is supported. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a>  | Yes       | Focus mode                        |
| callback  | AsyncCallback<boolean\> | Yes       | Callback used to return the device focus support status |

**Example**

```
cameraInput.isFocusModeSupported(afMode, (err, status) => {
    if (err) {
        console.error('Failed to check whether the focus mode is supported. ${err.message}');
        return;
    }
    console.log('Callback returned with the focus mode support status: ' + status);
})
```

### isFocusModeSupported(afMode: FocusMode): Promise<boolean\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Checks whether a specified focus mode is supported. This method uses a promise to return the result.

**Parameters**

| Name      | Type                                   | Mandatory | Description |
|-----------|----------------------------------------|-----------|-------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a> | Yes       | Focus mode  |

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<boolean\>     | Promise used to return the focus mode support status. |

**Example**

```
cameraInput.isFocusModeSupported(afMode).then((status) => {
    console.log('Promise returned with focus mode support status.' + status);
})
```

### setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets focus mode. This method uses an asynchronous callback to return the result.

Note: Before setting the focus mode, check focus mode support (<a href="#sec_isFocusModeSupported">isFocusModeSupported</a> method);

**Parameters**

| Name      | Type                   | Mandatory | Description                        |
|-----------|------------------------|-----------|------------------------------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a> | Yes       | Focus mode         |
| callback  | AsyncCallback<void\>   | Yes       | Callback used to return the result |

**Example**

```
cameraInput.setFocusMode(afMode, (err) => {
    if (err) {
        console.error('Failed to set the focus mode  ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setFocusMode.');
})
```

### setFocusMode(afMode: FocusMode): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets focus mode. This method uses a promise to return the result.

Note: Before setting the focus mode, check focus mode support (<a href="#sec_isFocusModeSupported">isFocusModeSupported</a> method);

**Parameters**

| Name      | Type                                    | Mandatory | Description |
|-----------|-----------------------------------------|-----------|-------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a>  | Yes       | Focus mode  |

**Return values**

| Type                  | Description                             |
|-----------------------|-----------------------------------------|
| Promise<void\>        | Promise used to return the result       |

**Example**

```
cameraInput.setFocusMode(afMode).then(() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode(callback: AsyncCallback<FocusMode\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the current focus mode. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                      | Mandatory | Description                                    |
|-----------|---------------------------|-----------|------------------------------------------------|
| callback  | AsyncCallback<FocusMode\> | Yes       | Callback used to return the current focus mode |

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

### getFocusMode(): Promise<FocusMode\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the current focus mode. This method uses a promise to return the result.

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<FocusMode\>   | Promise used to return the focus mode             |

**Example**

```
cameraInput.getFocusMode().then((afMode) => {
    console.log('Promise returned with current focus mode : ' + afMode);
})
```

### getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the zoom ratios of all zoom values. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                           | Mandatory | Description                                     |
|----------|--------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<number\>\> | Yes       | Callback used to return the zoom ratio range |

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

### getZoomRatioRange\(\): Promise<Array<number\>\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets the zoom ratios of all zoom values. This method uses a promise to return the result.

**Return values**

| Type                   | Description                                 |
|------------------------|---------------------------------------------|
| Promise<Array<number\>\> | Promise used to return the zoom ratio range |

**Example**

```
cameraInput.getZoomRatioRange().then((zoomRatioRange) => {
    console.log('Promise returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets a zoom ratio. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                   | Mandatory | Description                        |
|-----------|------------------------|-----------|------------------------------------|
| zoomRatio | number                 | Yes       | Zoom ratio                         |
| callback  | AsyncCallback<void\>   | Yes       | Callback used to return the result |

**Example**

```
cameraInput.setZoomRatio(zoomRatio, (err) => {
    if (err) {
        console.error('Failed to set the zoom ratio value ${err.message}');
        return;
    }
    console.log('Callback returned with the successful execution of setZoomRatio.');
})
```

### setZoomRatio(zoomRatio: number): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Sets a zoom ratio. This method uses a promise to return the result.

**Parameters**

| Name      | Type     | Mandatory | Description |
|-----------|----------|-----------|-------------|
| zoomRatio | number   | Yes       | zoom ratio  |

**Return values**

| Type                  | Description                             |
|-----------------------|-----------------------------------------|
| Promise<void\>        | Promise used to return the result       |

**Example**

```
cameraInput.setZoomRatio(zoomRatio).then(() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio(callback: AsyncCallback<number\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets current zoom ratio value. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                      | Mandatory | Description                                          |
|-----------|---------------------------|-----------|------------------------------------------------------|
| callback  | AsyncCallback<number\>    | Yes       | Callback used to return the current zoom ratio value |

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

### getZoomRatio(): Promise<number\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Gets current zoom ratio value. This method uses a promise to return the result.

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<number\>      | Promise used to return the zoom ratio vaule       |

**Example**

```
cameraInput.getZoomRatio().then((zoomRatio) => {
    console.log('Promise returned with current zoom ratio : ' + zoomRatio);
})
```

### release\(callback: AsyncCallback<void\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **CameraInput** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### release(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **CameraInput** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on(type: 'focusStateChange', callback: Callback<FocusState\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for focus state changes. This method uses a callback to get focus state changes.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of the event to listen for.                    |
| callback | Callback<FocusState\>  | Yes       | Callback used to get the focus state change.    |

**Example**

```
cameraInput.on('focusStateChange', (focusState) => {
    console.log('Focus state  : ' + focusState);
})
```

### on(type: 'error', callback: Callback<CameraInputError\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for **CameraInput** errors. This method uses a callback to get errors.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Camera input error event.                       |
| callback | Callback<CameraInputError\> | Yes  | Callback used to get the camera input errors.   |

**Example**

```
cameraInput.on('error', (cameraInputError) => {
    console.log('Camera input error code: ' + cameraInputError.code);
})
```

## FlashMode <a name="sec_FlashMode"></a>

Enumerates the flash modes.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                   | Default value | Description            |
|------------------------|---------------|------------------------|
| FLASH_MODE_CLOSE       | 0             | Flash mode close       |
| FLASH_MODE_OPEN        | 1             | Flash mode open        |
| FLASH_MODE_AUTO        | 2             | Flash mode auto        |
| FLASH_MODE_ALWAYS_OPEN | 3             | Flash mode always open |

## FocusMode <a name="sec_FocusMode"></a>

Enumerates the focus modes.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                       | Default value | Description                |
|----------------------------|---------------|----------------------------|
| FOCUS_MODE_MANUAL          | 0             | Focus mode manual          |
| FOCUS_MODE_CONTINUOUS_AUTO | 1             | Focus mode continuous auto |
| FOCUS_MODE_AUTO            | 2             | Focus mode auto            |
| FOCUS_MODE_LOCKED          | 3             | Focus mode locked          |

## createCaptureSession\(context: Context, callback: AsyncCallback<CaptureSession\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CaptureSession** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name     | Type                           | Mandatory | Description                                         |
|----------|--------------------------------|-----------|-----------------------------------------------------|
| context  | Context                        | Yes       | Application context                                 |
| callback | AsyncCallback<CaptureSession\> | Yes       | Callback used to return the CaptureSession instance |

**Example**

```
captureSession.createCaptureSession((context), (err, captureSession) => {
    if (err) {
        console.error('Failed to create the CaptureSession instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CaptureSession instance.' + captureSession);
});
```

## createCaptureSession(context: Context\): Promise<CaptureSession\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **CaptureSession** instance. This method uses a promise to return the instance.

**Parameters**

| Name     | Type                          | Mandatory | Description                                         |
|----------|-------------------------------|-----------|-----------------------------------------------------|
| context  | Context                       | Yes       | Application context                                 |

**Return values**

| Type                      | Description                                       |
|---------------------------|---------------------------------------------------|
| Promise<CaptureSession\>  | Promise used to return the CaptureSession instance.   |

**Example**

```
captureSession.createCaptureSession(context).then((captureSession) => {
    console.log('Promise returned with the CaptureSession instance');
})
```

## CaptureSession<a name="sec_CaptureSession"></a>

Implements session capture.

### beginConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts configuration for this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### beginConfig\(\): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts configuration for this CaptureSession instance. This method uses a promise to return the result.

**Return values**

| Type          | Description                                 |
|---------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Commits the configuration for this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                | Mandatory | Description                                  |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### commitConfig\(\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Commits the configuration for this CaptureSession instance. This method uses a promise to return the result.

**Return values**

| Type          | Description                                 |
|---------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a CameraInput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name        | Type                 | Mandatory | Description                                 |
|-------------|----------------------|-----------|---------------------------------------------|
| cameraInput | CameraInput          | Yes       | CameraInput instance to add                 |
| callback    | AsyncCallback<void\> | Yes       | Callback used to return the result          |

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

### addInput\(cameraInput: CameraInput\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a CameraInput instance to this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

| Name        | Type                | Mandatory | Description                   |
|-------------|---------------------|-----------|-------------------------------|
| cameraInput | CameraInput         | Yes       | CameraInput instance to add   |

**Return values**

| Type           | Description                        |
|----------------|------------------------------------|
| Promise<void\> | Promise used to return the result  |

**Example**

```
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### addOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a PreviewOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                         |
|---------------|----------------------|-----------|-------------------------------------|
| previewOutput | PreviewOutput        | Yes       | PreviewOutput instance to add       |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result  |

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

### addOutput\(previewOutput: PreviewOutput\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a PreviewOutput instance to this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                    |
|---------------|---------------------|-----------|--------------------------------|
| previewOutput | PreviewOutput       | Yes       | PreviewOutput instance to add  |

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.addOutput(previewOutput).then(() => {
    console.log('Promise used to indicate that the PreviewOutput instance is added.');
})
```

### addOutput\(photoOutput: PhotoOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a PhotoOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                         |
|---------------|---------------------|-----------|-------------------------------------|
| photoOutput   | PhotoOutput         | Yes       | PhotoOutput instance to add         |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### addOutput\(photoOutput: PhotoOutput\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a PhotoOutput instance to this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                    |
|---------------|---------------------|-----------|--------------------------------|
| photoOutput   | PhotoOutput         | Yes       | PhotoOutput instance to add    |

**Return values**

| Type          | Description                       |
|---------------|-----------------------------------|
| Promise<void> | Promise used to return the result |

**Example**

```
captureSession.addOutput(photoOutput).then(() => {
    console.log('Promise used to indicate that the PhotoOutput instance is added.');
})
```

### addOutput\(videoOutput: VideoOutput, callback: AsyncCallback<void\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a VideoOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                         |
|---------------|---------------------|-----------|-------------------------------------|
| videoOutput   | VideoOutput         | Yes       | VideoOutput instance to add         |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### addOutput\(videoOutput: VideoOutput\): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Add a VideoOutput instance to this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                    |
|---------------|---------------------|-----------|--------------------------------|
| videoOutput   | VideoOutput         | Yes       | VideoOutput instance to add    |

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.addOutput(videoOutput).then(() => {
    console.log('Promise used to indicate that the VideoOutput instance is added.');
})
```

### removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **CameraInput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name        | Type                 | Mandatory | Description                        |
|-------------|----------------------|-----------|------------------------------------|
| cameraInput | CameraInput          | Yes       | CameraInput instance to remove     |
| callback    | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### removeInput\(cameraInput: CameraInput\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **CameraInput** instance from this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

| Name        | Type                | Mandatory | Description                     |
|-------------|---------------------|-----------|---------------------------------|
| cameraInput | CameraInput         | Yes       | CameraInput instance to remove  |

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### removeOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **PreviewOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| previewOutput | PreviewOutput        | Yes       | PreviewOutput instance to remove   |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### removeOutput(previewOutput: PreviewOutput): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **PreviewOutput** instance from this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                       |
|---------------|---------------------|-----------|-----------------------------------|
| previewOutput | PreviewOutput       | Yes       | PreviewOutput instance to remove  |


**Return values**

| Type          | Description                                 |
|---------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
captureSession.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is removed.');
})
```

### removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **PhotoOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| photoOutput   | PhotoOutput          | Yes       | PhotoOutput instance to remove     |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### removeOutput(photoOutput: PhotoOutput): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **PhotoOutput** instance from this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                     |
|---------------|---------------------|-----------|---------------------------------|
| photoOutput   | PhotoOutput         | Yes       | PhotoOutput instance to remove  |


**Return values**

| Type          | Description                        |
|---------------|------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
captureSession.removeOutput(photoOutput).then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is removed.');
})
```

### removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **VideoOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| videoOutput   | VideoOutput          | Yes       | VideoOutput instance to remove     |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### removeOutput(videoOutput: VideoOutput): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Removes a **VideoOutput** instance from this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                     |
|---------------|---------------------|-----------|---------------------------------|
| videoOutput   | VideoOutput         | Yes       | VideoOutput instance to remove  |


**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
captureSession.removeOutput(videoOutput).then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is removed.');
})
```

### start\(callback: AsyncCallback<void\>\): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### start\(\): Promise<void\>;<a name="section189141826104616"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts this **CaptureSession** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Stops this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**


| Name     | Type                 | Mandatory | Description                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### stop(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Stops this **CaptureSession** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### release(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **CaptureSession** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### on(type: 'error', callback: Callback<CaptureSessionError\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for **CaptureSession** errors. This method uses a callback to get errors.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of the event to listen for. It should be 'error', which is the CaptureSessionError event.                    |
| callback | Callback<CaptureSessionError\> | Yes  | Callback used to get the capture session errors. |

**Example**

```
captureSession.on('error', (captureSessionError) => {
    console.log('Capture session error code: ' + captureSessionError.code);
})
```

## createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **PreviewOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from XComponent view           |
| callback   | AsyncCallback<PreviewOutput\> | Yes       | Callback used to return the PreviewOutput instance |

**Example**

```
camera.createPreviewOutput((surfaceId), (err, previewOutput) => {
    if (err) {
        console.error('Failed to create the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with previewOutput instance');
});
``` 

## createPreviewOutput(surfaceId: string): Promise<PreviewOutput>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **PreviewOutput** instance. This method uses a promise to return the instance.

**Parameters**

| Name       | Type            | Mandatory | Description                                        |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | Surface ID received from XComponent view           |

**Return values**

| Type                    | Description                                       |
|-------------------------|---------------------------------------------------|
| Promise<PreviewOutput\> | Promise used to return the PreviewOutput instance |

**Example**

```
camera.createPreviewOutput(surfaceId).then((previewOutput) => {
    console.log('Promise returned with the PreviewOutput instance');
})
```

## PreviewOutput

Implements preview output.

### release(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **PreviewOutput** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### release(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **PreviewOutput** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### on(type: 'frameStart', callback: Callback<number\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for preview frame start events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type              | Mandatory | Description                        |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | Name of the event to listen for.   |
| callback | Callback<void\>   | Yes       | Callback used to return the result |

**Example**

```
previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
})
```

### on(type: 'frameEnd', callback: Callback<number\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for preview frame end event. This method uses a callback to get the event information.

**Parameters**

| Name     | Type              | Mandatory | Description                        |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | Name of the event to listen for.   |
| callback | Callback<void\>   | Yes       | Callback used to return the result |

**Example**

```
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on(type: 'error', callback: Callback<PreviewOutputError\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for **PreviewOutput** errors. This method uses a callback to get errors.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Preview output error event.                     |
| callback | Callback<PreviewOutputError\> | Yes  | Callback used to get the preview output errors. |

**Example**

```
previewOutput.on('error', (previewOutputError) => {
    console.log('Preview output error code: ' + previewOutputError.code);
})
```

## createPhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **PhotoOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from ImageReceiver             |
| callback   | AsyncCallback<PhotoOutput\>   | Yes       | Callback used to return the PhotoOutput instance   |

**Example**

```
camera.createPhotoOutput((surfaceId), (err, photoOutput) => {
    if (err) {
        console.error('Failed to create the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the PhotoOutput instance.');
});
``` 

## createPhotoOutput(surfaceId: string): Promise<PhotoOutput\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **PhotoOutput** instance. This method uses a promise to return the PhotoOutput instance.

**Parameters**

| Name       | Type            | Mandatory | Description                                        |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | Surface ID received from ImageReceiver             |

**Return values**

| Type                    | Description                                      |
|-------------------------|--------------------------------------------------|
| Promise<PhotoOutput\>   | Promise used to return the PhotoOutput instance  |

**Example**

```
camera.createPhotoOutput(surfaceId).then((photoOutput) => {
    console.log('Promise returned with PhotoOutput instance');
})
```
## ImageRotation

Enumerates the image rotation angles.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name         | Default Value | Description                            |
|--------------|---------------|----------------------------------------|
| ROTATION_0   | 0             | The capture image rotates 0 degrees    |
| ROTATION_90  | 90            | The capture image rotates 90 degrees   |
| ROTATION_180 | 180           | The capture image rotates 180 degrees  |
| ROTATION_270 | 270           | The capture image rotates 270 degrees  |


## Location

Defines the location of a captured image.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name      | Type   | Access       | Description |
|-----------|--------|--------------|-------------|
| latitude  | number | read / write | Latitude    |
| longitude | number | read / write | Longitude   |

## QualityLevel

Enumerates the image quality levels.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name                 | Default value | Description          |
|----------------------|---------------|----------------------|
| QUALITY_LEVEL_HIGH   | 0             | High image quality   |
| QUALITY_LEVEL_MEDIUM | 1             | Medium image quality |
| QUALITY_LEVEL_LOW    | 2             | Low image quality    |


## PhotoCaptureSetting

Defines the settings for image capture.

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

| Name     | Type          | Mandatory | Description         |
|----------|---------------|-----------|---------------------|
| quality  | QualityLevel  | Optional  | Photo image quality |
| rotation | ImageRotation | Optional  | Photo rotation      |


## PhotoOutput

Implements photo output.

### capture(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Captures a photo. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                | Mandatory | Description                                  |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### capture(setting: PhotoCaptureSetting, callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Captures a photo with the specified capture settings. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| setting  | PhotoCaptureSetting  | Yes       | Photo capture settings                       |
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### capture(setting?: PhotoCaptureSetting): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Captures a photo with the specified capture settings. This method uses a promise to return the result.

**Parameters**

| Name     | Type                | Mandatory | Description                                  |
|----------|---------------------|-----------|----------------------------------------------|
| setting  | PhotoCaptureSetting | No        | Photo capture settings                       |

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### release(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **PhotoOutput** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### release(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this **PhotoOutput** instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is released successfully.');
})
```

### on(type: 'captureStart', callback: Callback<number\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for photo capture start events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of the event to listen for.                |
| callback | Callback<number\>      | Yes       | Callback used to get the capture ID.            |

**Example**

```
photoOutput.on('captureStart', (captureId) => {
    console.log('photo capture stated, captureId : ' + captureId);
})
```

### on(type: 'frameShutter', callback: Callback<FrameShutterInfo\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for frame shutter events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of the event to listen for.                |
| callback | Callback<FrameShutterInfo\> | Yes   | Callback used to get the frame shutter information.|

**Example**

```
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log('photo capture end, captureId : ' + frameShutterInfo.captureId);
    console.log('Timestamp for frame : ' + frameShutterInfo.timestamp);
})
```

### on(type: 'captureEnd', callback: Callback<CaptureEndInfo\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for photo capture end events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type                   | Mandatory | Description                                      |
| :------- | :--------------------- | :-------- | :------------------------------------------------|
| type     | string                 | Yes       | Name of the event to listen for.                 |
| callback | Callback<CaptureEndInfo\> | Yes    | Callback used to get the capture end information |

**Example**

```
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log('photo capture end, captureId : ' + captureEndInfo.captureId);
    console.log('frameCount : ' + captureEndInfo.frameCount);
})
```

### on(type: 'error', callback: Callback<PhotoOutputError\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for **PhotoOutput** errors. This method uses a callback to get errors.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Photo output error event.                       |
| callback | Callback<PhotoOutputError\> | Yes  | Callback used to get the photo output errors.   |

**Example**

```
photoOutput.on('error', (photoOutputError) => {
    console.log('Photo output error code: ' + photoOutputError.code);
})
```

## createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **VideoOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from VideoRecorder             |
| callback   | AsyncCallback<VideoOutput\>   | Yes       | Callback used to return the VideoOutput instance   |

**Example**

```
camera.createVideoOutput((surfaceId), (err, videoOutput) => {
    if (err) {
        console.error('Failed to create the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the VideoOutput instance');
});
``` 

## createVideoOutput(surfaceId: string): Promise<VideoOutput\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Creates a **VideoOutput** instance. This method uses a promise to return the VideoOutput instance.

**Parameters**

| Name       | Type            | Mandatory | Description                                        |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | Surface ID received from VideoRecorder             |

**Return values**

| Type                                  | Description                                     |
|---------------------------------------|-------------------------------------------------|
| Promise<[VideoOutput](#videooutput)\> | Promise used to return the VideoOutput instance |

**Example**

```
camera.createVideoOutput(surfaceId).then((videoOutput) => {
    console.log('Promise returned with the VideoOutput instance');
})
```
## VideoOutput

Implements video output.

### start(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts the video output. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### start(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Starts the video output. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
```

### stop(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Stops the video output. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### stop(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Stops the video output. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
})
```

### release(callback: AsyncCallback<void\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this VideoOutput instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

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

### release(): Promise<void\>;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Releases this VideoOutput instance. This method uses a promise to return the result.

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result           |


**Example**

```
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is released successfully.');
})
```

### on(type: 'frameStart', callback: Callback<number\>): void;

**System Capabilities:**

SystemCapability.Multimedia.Camera.Core

**Description**

Listens for video frame start events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type              | Mandatory | Description                        |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | Name of the event to listen for.       |
| callback | Callback<void\>   | Yes       | Callback used to return the result |

**Example**

```
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on(type: 'frameEnd', callback: Callback<number\>): void;

Listens for video frame end events. This method uses a callback to get the event information.

**Parameters**

| Name     | Type              | Mandatory | Description                        |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | Name of the event to listen for.   |
| callback | Callback<void\>   | Yes       | Callback used to return the result |

**Example**

```
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on(type: 'error', callback: Callback<VideoOutputError\>): void;

Listens for **VideoOutput** errors. This method uses a callback to get errors.

**Parameters**

| Name     | Type                   | Mandatory | Description                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Video output error event.                       |
| callback | Callback<VideoOutputError\> | Yes  | Callback used to get the video output errors.   |

**Example**

```
videoOutput.on('error', (VideoOutputError) => {
    console.log('Video output error code: ' + VideoOutputError.code);
})
```