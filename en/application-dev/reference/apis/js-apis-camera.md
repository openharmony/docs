# Camera<a name="EN-US_TOPIC_0000001149807881"></a>

## Modules to Import

```
import camera from '@ohos.multimedia.camera';
```

## Required Permissions

```
ohos.permission.CAMERA
```
## getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void;

Gets a **CameraManager** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                          | Mandatory | Description                                         |
|----------|-------------------------------|-----------|-----------------------------------------------------|
| context  | Context                       | Yes       | Application context                                 |
| callback | AsyncCallback<CameraManager\> | Yes       | Callback used to return the CameraManager instance  |


**Return values**

none

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

| Name                      | Default Value | Description        |
|---------------------------|---------------|--------------------|
| CAMERA_STATUS_APPEAR      | 0             | Camera appear      |
| CAMERA_STATUS_DISAPPEAR   | 1             | Camera disappear   |
| CAMERA_STATUS_AVAILABLE   | 2             | Camera available   |
| CAMERA_STATUS_UNAVAILABLE | 3             | Camera unavailable |


## CameraPosition<a name="section_camera_position"></a>

Enumerates the camera positions.

| Name                        | Default value | Description           |
|-----------------------------|---------------|-----------------------|
| CAMERA_POSITION_UNSPECIFIED | 0             | Unspecified position  |
| CAMERA_POSITION_BACK        | 1             | Rear camera           |
| CAMERA_POSITION_FRONT       | 2             | Front camera          |

## CameraType<a name="section_camera_type"></a>

Enumerates the camera types.

| Name                    | Default value | Description             |
|-------------------------|---------------|-------------------------|
| CAMERA_TYPE_UNSPECIFIED | 0             | Unspecified camera type |
| CAMERA_TYPE_WIDE_ANGLE  | 1             | Wide camera             |
| CAMERA_TYPE_ULTRA_WIDE  | 2             | Ultra wide camera       |
| CAMERA_TYPE_TELEPHOTO   | 3             | Telephoto camera        |
| CAMERA_TYPE_TRUE_DEPTH  | 4             | True depth camera       |


## ConnectionType<a name="section_ConnectionType"></a>

Enumerates camera connection types.

| Name                         | Default value | Description                |
|------------------------------|---------------|----------------------------|
| CAMERA_CONNECTION_BUILT_IN   | 0             | Built-in camera            |
| CAMERA_CONNECTION_USB_PLUGIN | 1             | Camera connected using USB |
| CAMERA_CONNECTION_REMOTE     | 2             | Remote camera              |


## CameraFormat<a name="section_CameraFormat"></a>

Enumerates the camera formats.

| Name                       | Default value | Description         |
|----------------------------|---------------|---------------------|
| CAMERA_FORMAT_YCRCb_420_SP | 1003          | Camera YCRCb        |
| CAMERA_FORMAT_JPEG         | 2000          | Camera format jpeg  |
| CAMERA_FORMAT_AVC          | 3000          | Camera format avc   |
| CAMERA_FORMAT_HEVC         | 3001          | Camera format hevc  |


## CameraManager<a name="section_CameraManager"></a>

Implements camera management, including getting supported cameras and creating **CameraInput** instances.

### getCameras(callback: AsyncCallback<Array<Camera\>\>): void;

Gets all cameras supported by the device. This method uses an asynchronous callback to return the array of supported cameras.

**Parameters**

| Name     | Type                           | Mandatory | Description                                             |
|----------|--------------------------------|-----------|---------------------------------------------------------|
| callback | AsyncCallback<Array<Camera\>\> | Yes       | Callback used to return the array of supported cameras. |

**Return values**

none

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

Gets all cameras supported by the device. This method uses a promise to return the array of supported cameras.

**Parameters**

none

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

Creates a **CameraInput** instance with the specified camera ID. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name     | Default value                | Mandatory | Description                                      |
|----------|------------------------------|-----------|--------------------------------------------------|
| cameraId | string                       | Yes       | Camera ID used to create the instance            |
| callback | AsyncCallback<CameraInput\>  | Yes       | Callback used to return the CameraInput instance |

**Return values**

none

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

Creates a **CameraInput** instance with the specified camera position and camera type. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name           | Type                       | Mandatory | Description                                       |
|----------------|----------------------------|-----------|---------------------------------------------------|
| cameraPosition | CameraPosition             | Yes       | Camera position                                   |
| cameraType     | CameraType                 | Yes       | Camera type                                       |
| callback       | AsyncCallback<CameraInput\> | Yes       | Callback used to return the CameraInput instance |

**Return values**

none

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

Creates a **CameraInput** instance with the specified camera position and camera type. This method uses a promise to return the instance.

**Parameters**

| Name           | Type                       | Mandatory | Description                            |
|----------------|----------------------------|-----------|----------------------------------------|
| cameraPosition | CameraPosition             | Yes       | Camera position                        |
| cameraType     | CameraType                 | Yes       | Camera type                            |

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

## Camera<a name="section_Camera"></a>

Camera class.

**Fields**

| Name           | Type           | Access   | Description            |
|----------------|----------------|----------|------------------------|
| cameraId       | string         | readonly | Camera ID              |
| cameraPosition | cameraPosition | readonly | Camera position        |
| cameraType     | cameraType     | readonly | Camera type            |
| connectionType | connectionType | readonly | Camera connection type |

```
var cameraManager = await camera.getCameraManager();
var cameras = await cameraManager.getCameras();
var cameraObj = cameras[0];
var cameraId = cameraObj.cameraId;
var cameraPosition = cameraObj.cameraPosition;
var cameraType = cameraObj.cameraType;
var cameraId = cameraObj.connectionType;

```

## CameraInput<a name="section_CameraInput"></a>

Implements a **CameraInput** instance.

### getCameraId(callback: AsyncCallback<string\>\): void;

Gets the camera ID based on which this **CameraInput** instance is created. This method uses an asynchronous callback to return the camera ID.

**Parameters**

| Name     | Type                   | Mandatory | Description                           |
|----------|------------------------|-----------|---------------------------------------|
| callback | AsyncCallback<string\> | Yes       | Callback used to return the camera ID |

**Return values**

none

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

Gets the camera ID based on which this **CameraInput** instance is created. This method uses a promise to return the camera ID.

**Parameters**

none

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

### getSupportedSizes\(format: CameraFormat, callback: AsyncCallback<Array<Size\>\>\): void;

Gets supported sizes for a given format. This method uses an asynchronous callback to return the supported sizes.

**Parameters**

| Name     | Type                         | Mandatory | Description                                 |
|----------|------------------------------|-----------|---------------------------------------------|
| format   | CameraFormat                 | Yes       | Camera format used to get supported sizes   |
| callback | AsyncCallback<Array<Size\>\> | Yes       | Callback used to return the supported sizes |


**Return values**

none

**Example**

```
cameraInput.getSupportedSizes(format, (err, sizes) => {
    if (err) {
        console.error('Failed to get the supported sizes. ${err.message}');
		return;
    }
    console.log('Callback returned with the supported sizes:' + sizes);
})
```

### getSupportedSizes\(format: CameraFormat\): Promise<Array<Size\>\>;

Gets supported sizes for a given format. This method uses a promise to return the supported sizes.

**Parameters**

| Name     | Type                       | Mandatory | Description                                   |
|----------|----------------------------|-----------|-----------------------------------------------|
| format   | CameraFormat               | Yes       | Camera format used to get the supported sizes |

**Return values**

| Type                   | Description                                 |
|------------------------|---------------------------------------------|
| Promise<Array<Size\>\> | Promise used to return the supported sizes. |

**Example**

```
cameraInput.getSupportedSizes(format).then((sizes) => {
    console.log('Promise returned with supported sizes: ' + sizes);
})
```

### getSupportedPreviewFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;

Gets supported formats for preview. This method uses an asynchronous callback to return the supported formats.

**Parameters**

| Name     | Type                                 | Mandatory | Description                                       |
|----------|--------------------------------------|-----------|---------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | Callback used to return the supported preview formats. |


**Return values**

none

**Example**

```
cameraInput.getSupportedPreviewFormats((err, previewFormats) => {
    if (err) {
        console.error('Failed to get the supported preview formats. ${err.message}');
        return;
    }
    console.log('Callback returned with supported preview formats: ' + previewFormats.length);
})
```


### getSupportedPreviewFormats\(\): Promise<Array<CameraFormat\>\>;

Gets supported formats for preview. This method uses a promise to return the supported formats.

**Parameters**

none

**Return values**

| Type                           | Description                                           |
|--------------------------------|-------------------------------------------------------|
| Promise<Array<CameraFormat\>\> | Promise used to return the supported preview formats  |

**Example**

```
cameraInput.getSupportedPreviewFormats().then((previewFormats) => {
    console.log('Promise returned with supported preview formats.' + previewFormats.length);
})
```

### getSupportedPhotoFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;<a name="section189141826104616"></a>

Gets supported formats for photographing. This method uses an asynchronous callback to return the supported formats.

**Parameters**

| Name     | Type                                 | Mandatory | Description                                     |
|----------|--------------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | Callback used to return the supported photo formats. |

**Return values**

none

**Example**

```
cameraInput.getSupportedPhotoFormats((err, photoFormats) => {
    if (err) {
        console.error('Failed to get the supported photo formats. ${err.message}');
        return;
    }
    console.log('Callback returned with supported photo formats');
})
```

### getSupportedPhotoFormats\(\): Promise<Array<CameraFormat\>\>;<a name="section189141826104616"></a>

Gets supported formats for photographing. This method uses a promise to return the supported formats.

**Parameters**

none

**Return values**

| Type                           | Description                                       |
|--------------------------------|---------------------------------------------------|
| Promise<Array<CameraFormat\>\> | Promise used to return supported photo formats.   |

**Example**

```
cameraInput.getSupportedPhotoFormats().then((photoFormats) => {
    console.log('Promise returned with supported photo formats.' + photoFormats.length);
})
```

### getSupportedVideoFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;

Gets supported formats for video recording. This method uses an asynchronous callback to return the supported video formats.

**Parameters**

| Name     | Type                                 | Mandatory | Description                                     |
|----------|--------------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | Callback used to return the supported video formats. |

**Return values**

none

**Example**

```
cameraInput.getSupportedVideoFormats((err, videoFormats) => {
    if (err) {
        console.error('Failed to get the supported video formats. ${err.message}');
        return;
    }
    console.log('Callback returned with supported video formats : ' + videoFormats.length);
})
```

### getSupportedVideoFormats\(\): Promise<Array<CameraFormat\>\>;

Gets supported formats for video recording. This method uses a promise to return the supported video format.

**Parameters**

none

**Return values**

| Type                           | Description                                       |
|--------------------------------|---------------------------------------------------|
| Promise<Array<CameraFormat\>\> | Promise used to return supported video formats.   |

**Example**

```
cameraInput.getSupportedVideoFormats().then((videoFormats) => {
    console.log('Promise returned with supported video formats.' + videoFormats.length);
})
```

### hasFlash(callback: AsyncCallback<boolean\>): void; <a name="sec_hasFlash"></a>

Checks whether the device has flash light. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                    | Mandatory | Description                                        |
|----------|-------------------------|-----------|----------------------------------------------------|
| callback | AsyncCallback<boolean\> | Yes       | Callback used to return the flash light support status |

**Return values**

none

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

Checks whether the device has flash light. This method uses a promise to return the result.

**Parameters**

none

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

Checks whether a specified flash mode is supported. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode                                         |
| callback  | AsyncCallback<boolean\> | Yes       | Callback used to return the device flash support status |

**Return values**

none

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

Sets flash mode. This method uses an asynchronous callback to return the result.

Note: Before setting the flash mode, check the support for the flash light (<a href="#sec_hasFlash">hasFlash</a> method) and flash mode support (<a href="#sec_isFlashModeSupported">isFlashModeSupported</a> method);

**Parameters**

| Name      | Type                   | Mandatory | Description                                        |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | Flash mode             |
| callback  | AsyncCallback<void\> | Yes       | Callback used to return the result         |

**Return values**

none

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
cameraInput.setFlashMode(flashMode).then() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode(callback: AsyncCallback<FlashMode\>): void;

Gets current flash mode. This method uses an asynchronous callback to return the result.

**Parameters**

| Name      | Type                      | Mandatory | Description                                    |
|-----------|---------------------------|-----------|------------------------------------------------|
| callback  | AsyncCallback<FlashMode\> | Yes       | Callback used to return the current flash mode |

**Return values**

none

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

Gets current flash mode. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type                  | Description                                       |
|-----------------------|---------------------------------------------------|
| Promise<FlashMode\>   | Promise used to return the flash mode             |

**Example**

```
cameraInput.getFlashMode().then(flashMode) => {
    console.log('Promise returned with current flash mode : ' + flashMode);
})
```

## FlashMode <a name="sec_FlashMode"></a>

Enumerates the flash modes.

| Name                   | Default value | Description            |
|------------------------|---------------|------------------------|
| FLASH_MODE_CLOSE       | 0             | Flash mode close       |
| FLASH_MODE_OPEN        | 1             | Flash mode open        |
| FLASH_MODE_AUTO        | 2             | Flash mode auto        |
| FLASH_MODE_ALWAYS_OPEN | 3             | Flash mode always open |


## createCaptureSession\(context: Context, callback: AsyncCallback<CaptureSession\>\): void;

Creates a **CaptureSession** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name     | Type                           | Mandatory | Description                                         |
|----------|--------------------------------|-----------|-----------------------------------------------------|
| context  | Context                        | Yes       | Application context                                 |
| callback | AsyncCallback<CaptureSession\> | Yes       | Callback used to return the CaptureSession instance |

**Return values**

none

**Example**

```
camera.createCaptureSession(context), (err, captureSession) => {
    if (err) {
        console.error('Failed to create the CaptureSession instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the CaptureSession instance.' + captureSession);
});
```

## createCaptureSession(context: Context\): Promise<CaptureSession\>;

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
camera.createCaptureSession(context).then((captureSession) => {
    console.log('Promise returned with the CaptureSession instance');
})
```

## CaptureSession<a name="sec_CaptureSession"></a>

Implements session capture.

### beginConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Starts configuration for this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |


**Return values**

none

**Example**

```
camera.beginConfig((err) => {
    if (err) {
        console.error('Failed to start the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the begin config success.');
});
```

### beginConfig\(\): Promise<void\>;

Starts configuration for this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type          | Description                                 |
|---------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |


**Example**

```
camera.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Commits the configuration for this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                | Mandatory | Description                                  |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.commitConfig((err) => {
    if (err) {
        console.error('Failed to commit the configuration. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the commit config success.');
});
```


### commitConfig\(\): Promise<void\>;<a name="section189141826104616"></a>

Commits the configuration for this CaptureSession instance. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type          | Description                                 |
|---------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
camera.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;

Add a CameraInput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name        | Type                 | Mandatory | Description                                 |
|-------------|----------------------|-----------|---------------------------------------------|
| cameraInput | CameraInput          | Yes       | CameraInput instance to add                 |
| callback    | AsyncCallback<void\> | Yes       | Callback used to return the result          |


**Return values**

none

**Example**

```
camera.addInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to add the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is added.');
});
```

### addInput\(cameraInput: CameraInput\): Promise<void\>;<a name="section189141826104616"></a>

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
camera.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### addOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Add a PreviewOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                         |
|---------------|----------------------|-----------|-------------------------------------|
| previewOutput | PreviewOutput        | Yes       | PreviewOutput instance to add       |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result  |


**Return values**

none

**Example**

```
camera.addOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to add the PreviewOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is added.');
});
```

### addOutput\(previewOutput: PreviewOutput\): Promise<void\>;<a name="section189141826104616"></a>

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
camera.addOutput(previewOutput).then(() => {
    console.log('Promise used to indicate that the PreviewOutput instance is added.');
})
```

### addOutput\(photoOutput: PhotoOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Add a PhotoOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                         |
|---------------|---------------------|-----------|-------------------------------------|
| photoOutput   | PhotoOutput         | Yes       | PhotoOutput instance to add         |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.addOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to add the PhotoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is added.');
});
```

### addOutput\(photoOutput: PhotoOutput\): Promise<void\>;<a name="section189141826104616"></a>

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
camera.addOutput(photoOutput).then(() => {
    console.log('Promise used to indicate that the PhotoOutput instance is added.');
})
```

### addOutput\(videoOutput: VideoOutput, callback: AsyncCallback<void\>\): void;

Add a VideoOutput instance to this CaptureSession instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                | Mandatory | Description                         |
|---------------|---------------------|-----------|-------------------------------------|
| videoOutput   | VideoOutput         | Yes       | VideoOutput instance to add         |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.addOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to add the VideoOutput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is added.');
});
```

### addOutput\(videoOutput: VideoOutput\): Promise<void\>;

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
camera.addOutput(videoOutput).then(() => {
    console.log('Promise used to indicate that the VideoOutput instance is added.');
})
```

### removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Removes a **CameraInput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name        | Type                 | Mandatory | Description                        |
|-------------|----------------------|-----------|------------------------------------|
| cameraInput | CameraInput          | Yes       | CameraInput instance to remove     |
| callback    | AsyncCallback<void\> | Yes       | Callback used to return the result |


**Return values**

none

**Example**

```
camera.removeInput(cameraInput, (err) => {
    if (err) {
        console.error('Failed to remove the CameraInput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the cameraInput instance is removed.');
});
```

### removeInput\(cameraInput: CameraInput\): Promise<void\>;<a name="section189141826104616"></a>

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
camera.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### removeOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Removes a **PreviewOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| previewOutput | PreviewOutput        | Yes       | PreviewOutput instance to remove   |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.removeOutput(previewOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PreviewOutput instance is removed.');
});
```

### removeOutput(previewOutput: PreviewOutput): Promise<void\>;

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
camera.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is removed.');
})
```

### removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void\>): void;

Removes a **PhotoOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| photoOutput   | PhotoOutput          | Yes       | PhotoOutput instance to remove     |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.removeOutput(photoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the PhotoOutput instance is removed.');
});
```

### removeOutput(photoOutput: PhotoOutput): Promise<void\>;

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
camera.removeOutput(photoOutput).then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is removed.');
})
```

### removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void\>): void;

Removes a **VideoOutput** instance from this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name          | Type                 | Mandatory | Description                        |
|---------------|----------------------|-----------|------------------------------------|
| videoOutput   | VideoOutput          | Yes       | VideoOutput instance to remove     |
| callback      | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.removeOutput(videoOutput, (err) => {
    if (err) {
        console.error('Failed to remove the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the VideoOutput instance is removed.');
});
```

### removeOutput(videoOutput: VideoOutput): Promise<void\>;

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
camera.removeOutput(videoOutput).then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is removed.');
})
```

### start\(callback: AsyncCallback<void\>\): void;

Starts this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.start((err) => {
    if (err) {
        console.error('Failed to start the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session start success.');
});
```

### start\(\): Promise<void\>;<a name="section189141826104616"></a>

Starts this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
camera.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Stops this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**


| Name     | Type                 | Mandatory | Description                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.stop((err) => {
    if (err) {
        console.error('Failed to stop the session ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate the session stop success.');
});
```


### stop(): Promise<void\>;

Stops this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type           | Description                       |
|----------------|-----------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
camera.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

Releases this **CaptureSession** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

**Example**

```
camera.release((err) => {
    if (err) {
        console.error('Failed to release the CaptureSession instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CaptureSession instance is released successfully.');
});
```

### release(): Promise<void\>;

Releases this **CaptureSession** instance. This method uses a promise to return the result.

**Parameters**

none

**Return values**

| Type           | Description                                 |
|----------------|---------------------------------------------|
| Promise<void\> | Promise used to return the result |

**Example**

```
camera.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

## createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void;

Creates a **PreviewOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from XComponent view           |
| callback   | AsyncCallback<PreviewOutput\> | Yes       | Callback used to return the PreviewOutput instance |

**Return values**

none

**Example**

```
camera.createPreviewOutput(surfaceId), (err, previewOutput) => {
    if (err) {
        console.error('Failed to create the PreviewOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with previewOutput instance');
});
``` 

## createPreviewOutput(surfaceId: string): Promise<PreviewOutput>;

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

Releases this **PreviewOutput** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Releases this **PreviewOutput** instance. This method uses a promise to return the result.

**Parameters**
none

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

## createPhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void;

Creates a **PhotoOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from ImageReceiver             |
| callback   | AsyncCallback<PhotoOutput\>   | Yes       | Callback used to return the PhotoOutput instance   |

**Return values**

none

**Example**

```
camera.createPhotoOutput(surfaceId), (err, photoOutput) => {
    if (err) {
        console.error('Failed to create the PhotoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the PhotoOutput instance.');
});
``` 

## createPhotoOutput(surfaceId: string): Promise<PhotoOutput\>;

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

| Name         | Default Value | Description                            |
|--------------|---------------|----------------------------------------|
| ROTATION_0   | 0             | The capture image rotates 0 degrees.   |
| ROTATION_90  | 90            | The capture image rotates 90 degrees.  |
| ROTATION_180 | 180           | The capture image rotates 180 degrees. |
| ROTATION_270 | 270           | The capture image rotates 270 degrees. |


## Location

Defines the location of a captured image.

| Name      | Type   | Access       | Description |
|-----------|--------|--------------|-------------|
| latitude  | number | read / write | Latitude    |
| longitude | number | read / write | Longitude   |

## QualityLevel

Enumerates the image quality levels.

| Name                 | Default value | Description          |
|----------------------|---------------|----------------------|
| QUALITY_LEVEL_HIGH   | 0             | High image quality   |
| QUALITY_LEVEL_MEDIUM | 1             | Medium image quality |
| QUALITY_LEVEL_LOW    | 2             | Low image quality    |


## PhotoCaptureSetting

Defines the settings for image capture.

| Name     | Type          | Mandatory | Description         |
|----------|---------------|-----------|---------------------|
| quality  | QualityLevel  | Optional  | Photo image quality |
| rotation | ImageRotation | Optional  | Photo rotation      |
| location | Location      | Optional  | Photo location      |
| mirror   | boolean       | Optional  | Mirror mode         |


## PhotoOutput

Implements photo output.

### capture(callback: AsyncCallback<void\>): void;

Captures a photo. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                | Mandatory | Description                                  |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Captures a photo with the specified capture settings. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| setting  | PhotoCaptureSetting  | Yes       | Photo capture settings                       |
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Releases this **PhotoOutput** instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Releases this **PhotoOutput** instance. This method uses a promise to return the result.

**Parameters**
none

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

## createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput\>): void;

Creates a **VideoOutput** instance. This method uses an asynchronous callback to return the instance.

**Parameters**

| Name       | Type                          | Mandatory | Description                                        |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | Surface ID received from VideoRecorder             |
| callback   | AsyncCallback<VideoOutput\>   | Yes       | Callback used to return the VideoOutput instance   |

**Return values**

none

**Example**

```
camera.createVideoOutput(surfaceId), (err, videoOutput) => {
    if (err) {
        console.error('Failed to create the VideoOutput instance. ${err.message}');
        return;
    }
    console.log('Callback returned with the VideoOutput instance');
});
``` 

## createVideoOutput(surfaceId: string): Promise<VideoOutput\>;

Creates a **VideoOutput** instance. This method uses a promise to return the VideoOutput instance.

**Parameters**

| Name       | Type            | Mandatory | Description                                        |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | Surface ID received from VideoRecorder             |

**Return values**

| Type                    | Description                                     |
|-------------------------|-------------------------------------------------|
| Promise<PhotoOutput\>   | Promise used to return the VideoOutput instance |

**Example**

```
camera.createVideoOutput(surfaceId).then((videoOutput) => {
    console.log('Promise returned with the VideoOutput instance');
})
```

### start(callback: AsyncCallback<void\>): void;

Starts the video output. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Starts the video output. This method uses a promise to return the result.

**Parameters**
none

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

Stops the video output. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Stops the video output. This method uses a promise to return the result.

**Parameters**
none

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

Releases this VideoOutput instance. This method uses an asynchronous callback to return the result.

**Parameters**

| Name     | Type                 | Mandatory | Description                                  |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | Callback used to return the result |

**Return values**

none

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

Releases this VideoOutput instance. This method uses a promise to return the result.

**Parameters**

none

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