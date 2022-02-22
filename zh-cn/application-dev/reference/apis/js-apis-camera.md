# 相机管理<a name="EN-US_TOPIC_0000001149807881"></a>

## 导入模块

```
import camera from '@ohos.multimedia.camera';
```

## 权限

```
ohos.permission.CAMERA
```
## getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取**相机管理器**，使用callback方式获取一个异步的实例。

**参数：**

| 名称      | 类型                          | 必填       | 说明                                                 |
|----------|-------------------------------|-----------|-----------------------------------------------------|
| context  | Context                       | Yes       | 应用环境 |
| callback | AsyncCallback<CameraManager\> | Yes       | 使用callback方式获取**相机管理器**实例<br/> |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取**相机管理器**，使用promise的方式获取一个实例。

**参数：**

| 名称      | 类型                  | 必填      | 说明                        |
|----------|----------------------|-----------|----------------------------|
| context  | Context              | Yes       | 应用环境                     |

**返回值：**

| 类型                     | 说明                                                   |
|-------------------------|--------------------------------------------------------|
| Promise<CameraManager\> | 使用Promise的方式获取一个**相机管理器** 实例                |

**示例：**

```
camera.getCameraManager(context).then((cameraManger) => {
    console.log('Promise returned with the CameraManager instance.');
})
```

## CameraStatus<a name="section_camera_status"></a>

枚举相机状态类型。

| 名称                       | 默认值         | 说明               |
|---------------------------|---------------|--------------------|
| CAMERA_STATUS_APPEAR      | 0             | Camera appear<br/>系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_STATUS_DISAPPEAR   | 1             | Camera disappear<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_STATUS_AVAILABLE   | 2             | 相机就绪<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_STATUS_UNAVAILABLE | 3             | 相机未就绪<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## CameraPosition<a name="section_camera_position"></a>

枚举相机位置。

| 名称                         | 默认值         | 说明                  |
|-----------------------------|---------------|-----------------------|
| CAMERA_POSITION_UNSPECIFIED | 0             | 未指定方向相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_POSITION_BACK        | 1             | 后置相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_POSITION_FRONT       | 2             | 前置相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |

## CameraType<a name="section_camera_type"></a>

枚举相机类型。

| 名称                     | 默认值         | 说明                     |
|-------------------------|---------------|-------------------------|
| CAMERA_TYPE_UNSPECIFIED | 0             | 未指定相机类型<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_TYPE_WIDE_ANGLE  | 1             | 广角相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_TYPE_ULTRA_WIDE  | 2             | 超级广角相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_TYPE_TELEPHOTO   | 3             | 电话相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_TYPE_TRUE_DEPTH  | 4             | 深度相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## ConnectionType<a name="section_ConnectionType"></a>

枚举相机连接类型。

| 名称                          | 默认值         | 说明                        |
|------------------------------|---------------|----------------------------|
| CAMERA_CONNECTION_BUILT_IN   | 0             | 内置相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_CONNECTION_USB_PLUGIN | 1             | USB外连相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_CONNECTION_REMOTE     | 2             | 分布式相机<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## CameraFormat<a name="section_CameraFormat"></a>

枚举相机格式。

| 名称                        | 默认值         | 说明                 |
|----------------------------|---------------|---------------------|
| CAMERA_FORMAT_YCRCb_420_SP | 1003          | YCRCb格式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_FORMAT_JPEG         | 2000          | JPEG格式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_FORMAT_AVC          | 3000          | AVC 格式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| CAMERA_FORMAT_HEVC         | 3001          | HEVC 格式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## CameraManager<a name="section_CameraManager"></a>

相机管理器类, 包含获取相机并创建“相机输入”实例。

### getCameras(callback: AsyncCallback<Array<Camera\>\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取设备支持的所有相机，使用callback方式获取异步的支持相机列表。

**参数：**

| 名称      | 类型                            | 必填      | 说明                                                    |
|----------|--------------------------------|-----------|---------------------------------------------------------|
| callback | AsyncCallback<Array<Camera\>\> | Yes       | 使用callback方式获取支持的相机列表                          |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取设备支持的所有相机，使用promise方式获取支持相机列表。

**参数：**

none

**返回值：**

| 类型                    | 说明                                                   |
|------------------------|--------------------------------------------------------|
| Promise<Array<Camera\>\> | 使用promise方获取支持相机列表                          |


**示例：**

```
cameraManager.getCameras().then((cameraArray) => {
    console.log('Promise returned with an array of supported cameras: ' + cameraArray.length);
})
```

### createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用相机ID创建 **相机输入** 实例，使用callback方式获取一个异步的实例。

**参数：**

| 名称      | 默认值                        | 必填      | 说明                                              |
|----------|------------------------------|-----------|--------------------------------------------------|
| cameraId | string                       | Yes       | 使用 相机ID 来创建一个实例                           |
| callback | AsyncCallback<CameraInput\>  | Yes       | 使用Callback方式来获取一个 CameraInput 实例          |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用相机ID创建 **相机输入** 实例，使用promise方式获取一个实例。

**参数：**

| 名称      | 默认值                       | 必填       | 说明                                     |
|----------|-----------------------------|-----------|------------------------------------------|
| cameraId | string                      | Yes       | 使用 相机ID 来创建一个实例                   |

**返回值：**

| 类型                     | 说明                                             |
|-------------------------|-------------------------------------------------|
| Promise<CameraInput\>   | 使用Promise的方式获取一个 CameraInput 的实例        |

**示例：**

```
cameraManager.createCameraInput(cameraId).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用相机位置和相机类型创建 **相机输入** 实例， 使用callback方式获取一个异步的实例。

**参数：**

| 名称            | 类型                        | 必填      | 说明                                               |
|----------------|----------------------------|-----------|---------------------------------------------------|
| cameraPosition | CameraPosition             | Yes       | 相机位置                                            |
| cameraType     | CameraType                 | Yes       | 相机类型                                            |
| callback       | AsyncCallback<CameraInput\> | Yes      | 使用callback方式获取一个异步的实例                     |

**返回值：**

none

**实例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用相机位置和相机类型创建 **相机输入** 实例， 使用promise的方式获取一个实例。

**参数：**

| 名称            | 类型                        | 必填      | 说明                                    |
|----------------|----------------------------|-----------|----------------------------------------|
| cameraPosition | CameraPosition             | Yes       | 相机位置                                 |
| cameraType     | CameraType                 | Yes       | 相机类型                                 |

**返回值：**

| 类型                     | 说明                                             |
|-------------------------|-------------------------------------------------|
| Promise<CameraInput\>   | 使用promise的方式获取一个**相机输入**实例            |

**示例：**

```
cameraManager.createCameraInput(cameraPosition, cameraType).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance.');
})
```

### on(type: 'cameraStatus', callback: Callback<CameraStatusInfo\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听相机的状态变化，使用callback的方式获取相机的状态变化

**参数：**

| 名称      | 类型                    | 必填       | 说明                                                 |
| :------- | :--------------------- | :-------- | :--------------------------------------------------- |
| type     | string                 | Yes       | 监听项的名称                                           |
| callback | Callback<CameraStatusInfo\> | Yes  | 使用callback的方式获取相机状态变化                        |

**返回值：**

None

**示例：**

```
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})
```

## Camera<a name="section_Camera"></a>

**相机**类。

**字段：**

| 名称            | 类型           | 访问权限   | 说明                    |
|----------------|----------------|----------|------------------------|
| cameraId       | string         | readonly | 相机ID<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| cameraPosition | cameraPosition | readonly | 相机位置<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| cameraType     | cameraType     | readonly | 相机类型<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| connectionType | connectionType | readonly | 相机连接类型<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |

```
var cameraManager = await camera.getCameraManager();
var cameras = await cameraManager.getCameras();
var cameraObj = cameras[0];
var cameraId = cameraObj.cameraId;
var cameraPosition = cameraObj.cameraPosition;
var cameraType = cameraObj.cameraType;
var cameraId = cameraObj.connectionType;

```

## CameraStatusInfo<a name="section_Camera"></a>

**相机状态信息**类。

**字段：**

| 名称            | 类型            | 说明             |
|----------------|----------------|------------------|
| camera         | Camera         | 相机类<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| status         | CameraStatus   | 相机状态<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## CameraInput<a name="section_CameraInput"></a>

**相机输入** 类。

### getCameraId(callback: AsyncCallback<string\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取该**相机输入** 实例的相机ID， 使用callback的方式获取一个异步的实例。

**参数：**

| 名称      | 类型                    | 必填      | 说明                                   |
|----------|------------------------|-----------|---------------------------------------|
| callback | AsyncCallback<string\> | Yes       | 使用callback的方式获取 相机ID             |

**返回值：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取该**相机输入** 实例的相机ID， 使用promise的方式获取相机ID。

**参数：**

none

**返回值：**

| 类型                    | 说明                                  |
|------------------------|--------------------------------------|
| Promise<string\>       | 使用promise的方式获取相机ID             |

**示例：**

```
cameraInput.getCameraId().then((cameraId) => {
    console.log('Promise returned with the camera ID:' + cameraId);
})
```

### getSupportedSizes\(format: CameraFormat, callback: AsyncCallback<Array<Size\>\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

根据格式查询相机支持的分辨率，使用callback的方式获取一个异步的支持分辨率。

**参数：**

| 名称      | 类型                          | 必填      | 说明                                         |
|----------|------------------------------|-----------|---------------------------------------------|
| format   | CameraFormat                 | Yes       | 使用CameraFormat来获取支持分辨率                |
| callback | AsyncCallback<Array<Size\>\> | Yes       | 使用callback的方式来获取支持分辨率               |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取CameraFormat的支持分辨率，使用promise的方式获取支持分辨率。

**参数：**

| 名称     | 类型                         | 必填      | 说明                                           |
|----------|----------------------------|-----------|-----------------------------------------------|
| format   | CameraFormat               | Yes       | 使用Camera format 获取支持分辨率                  |

**返回值：**

| 类型                    | 说明                                         |
|------------------------|---------------------------------------------|
| Promise<Array<Size\>\> | 使用promise的方式获取支持分辨率.                |

**示例：**

```
cameraInput.getSupportedSizes(format).then((sizes) => {
    console.log('Promise returned with supported sizes: ' + sizes);
})
```

### getSupportedPreviewFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取预览的支持格式，使用callback的方式获取一个异步的支持格式.

**参数：**

| 名称     | 类型                                   | 必填      | 说明                                               |
|----------|--------------------------------------|-----------|---------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | 使用callback的方式获取支持的预览格式.                  |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取预览的 supported formats，使用promise的方式获取supported formats.

**参数：**

none

**返回值：**

| 类型                            | 说明                                                   |
|--------------------------------|-------------------------------------------------------|
| Promise<Array<CameraFormat\>\> | 使用promise的方式获取supported preview formats           |

**示例：**

```
cameraInput.getSupportedPreviewFormats().then((previewFormats) => {
    console.log('Promise returned with supported preview formats.' + previewFormats.length);
})
```

### getSupportedPhotoFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;<a name="section189141826104616"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取 photographing的supported formats，使用callback的方式获取一个异步的supported formats.

**参数：**

| 名称      | 类型                                  | 必填      | 说明                                             |
|----------|--------------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | 使用callback的方式获取支持的照片格式                 |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取 photographing的supported formats，使用promise的方式获取supported formats.

**参数：**

none

**返回值：**

| 类型                            | 说明                                               |
|--------------------------------|---------------------------------------------------|
| Promise<Array<CameraFormat\>\> | 使用promise的方式获取支持的照片格式                    |

**示例：**

```
cameraInput.getSupportedPhotoFormats().then((photoFormats) => {
    console.log('Promise returned with supported photo formats.' + photoFormats.length);
})
```

### getSupportedVideoFormats\(callback: AsyncCallback<Array<CameraFormat\>\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取录制视频的supported formats，使用callback的方式获取一个异步的支持的录像格式。

**参数：**

| 名称      | 类型                                 | 必填       | 说明                                             |
|----------|--------------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<CameraFormat\>\> | Yes       | 使用callback的方式获取支持的录像格式                 |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取录制视频的supported formats，使用promise的方式获取支持的录像格式。

**参数：**

none

**返回值：**

| 类型                            | 说明                                               |
|--------------------------------|---------------------------------------------------|
| Promise<Array<CameraFormat\>\> | 使用promise的方式获取支持的录像格式                    |

**示例：**

```
cameraInput.getSupportedVideoFormats().then((videoFormats) => {
    console.log('Promise returned with supported video formats.' + videoFormats.length);
})
```

### hasFlash(callback: AsyncCallback<boolean\>): void; <a name="sec_hasFlash"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查设备是否支持闪光灯，使用callback的方式获取一个异步的结果。

**参数：**

| 名称     | 类型                     | 必填       | 说明                                                |
|----------|-------------------------|-----------|----------------------------------------------------|
| callback | AsyncCallback<boolean\> | Yes       | 使用callback的方式获取支持闪光灯的状态                  |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查设备是否支持闪光灯，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型                   | 说明                                                    |
|-----------------------|--------------------------------------------------------|
| Promise<boolean\>     | 使用promise的方式获取支持闪光灯的状态。                      |

**示例：**

```
cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
})
```

### isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void; <a name="sec_isFlashModeSupported"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查设备是否支持闪光灯模式，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                    | 必填        | 说明                                               |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | 闪光灯模式               |
| callback  | AsyncCallback<boolean\> | Yes       | 使用callback的方式获取设备支持闪光灯模式                |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查设备是否支持闪光灯模式，使用promise的方式获取结果。

**参数：**

| 名称       | 类型                   | 必填       | 说明                                                |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | 闪光灯模式               |

**返回值：**

| 类型                   | 说明                                               |
|-----------------------|---------------------------------------------------|
| Promise<boolean\>     | 使用promise的方式获取支持的闪光灯模式                   |

**示例：**

```
cameraInput.isFlashModeSupported(flashMode).then((status) => {
    console.log('Promise returned with flash mode support status.' + status);
})
```

### setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置闪光灯模式，使用callback的方式获取一个异步的结果。

说明: 设置闪光灯模式之前, 检查支持的闪光灯 (<a href="#sec_hasFlash">hasFlash</a> method) 以及支持的闪光灯模式 (<a href="#sec_isFlashModeSupported">isFlashModeSupported</a> method);

**参数：**

| 名称       | 类型                   | 必填       | 说明                                                |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | 闪光灯模式               |
| callback  | AsyncCallback<void\>   | Yes       | 使用callback的方式获取结果                            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置闪光灯模式，使用promise的方式获取结果。

说明: 设置闪光灯模式之前, 检查支持的闪光灯 (<a href="#sec_hasFlash">hasFlash</a> method) 以及支持的闪光灯模式 (<a href="#sec_isFlashModeSupported">isFlashModeSupported</a> method);

**参数：**

| 名称       | 类型                    | 必填      | 说明                                                |
|-----------|------------------------|-----------|----------------------------------------------------|
| flashMode | <a href="#sec_FlashMode">FlashMode</a>             | Yes       | 闪光灯模式               |

**返回值：**

| 类型                   | 说明                                    |
|-----------------------|-----------------------------------------|
| Promise<void\>        | 使用promise的方式获取结果                  |

**示例：**

```
cameraInput.setFlashMode(flashMode).then() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode(callback: AsyncCallback<FlashMode\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取当前闪光灯模式，使用callback的方式获取一个异步的结果。

**参数：**

| 名称       | 类型                      | 必填       | 说明                                            |
|-----------|---------------------------|-----------|------------------------------------------------|
| callback  | AsyncCallback<FlashMode\> | Yes       | 使用callback的方式获取当前闪光灯模式                |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取当前闪光灯模式，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型                   | 说明                                              |
|-----------------------|---------------------------------------------------|
| Promise<FlashMode\>   | 使用promise的方式获取当前闪光灯模式                    |

**示例：**

```
cameraInput.getFlashMode().then(flashMode) => {
    console.log('Promise returned with current flash mode : ' + flashMode);
})
```

### isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void; <a name="sec_isFocusModeSupported"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查支持的焦距模式，使用callback的方式获取一个异步的结果。

**参数：**

| 名称       | 类型                    | 必填      | 说明                                                |
|-----------|------------------------|-----------|----------------------------------------------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a>  | Yes       | 焦距模式                            |
| callback  | AsyncCallback<boolean\> | Yes       | 使用callback的方式获取设备支持的焦距模式                |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

检查支持的焦距模式，使用promise的方式获取结果。

**参数：**

| 名称       | 类型                                    | 必填      | 说明         |
|-----------|----------------------------------------|-----------|-------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a> | Yes       | 焦距模式      |

**返回值：**

| 类型                   | 说明                                               |
|-----------------------|---------------------------------------------------|
| Promise<boolean\>     | 使用promise的方式获取结果                            |

**示例：**

```
cameraInput.isFocusModeSupported(afMode).then((status) => {
    console.log('Promise returned with focus mode support status.' + status);
})
```

### setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置焦距模式，使用callback的方式获取一个异步的结果。

说明：使用设置焦距模式之前，检查设备支持的焦距模式 (<a href="#sec_isFocusModeSupported">isFocusModeSupported</a> method);

**参数：**

| 名称       | 类型                    | 必填      | 说明                                |
|-----------|------------------------|-----------|------------------------------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a> | Yes       | 焦距模式             |
| callback  | AsyncCallback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置焦距模式，使用promise的方式获取结果。

说明：使用设置焦距模式之前，检查设备支持的焦距模式 (<a href="#sec_isFocusModeSupported">isFocusModeSupported</a> method);

**参数：**

| 名称       | 类型                                     | 必填      | 说明         |
|-----------|-----------------------------------------|-----------|-------------|
| afMode    | <a href="#sec_FocusMode">FocusMode</a>  | Yes       | 焦距模式      |

**返回值：**

| 类型                   | 说明                                     |
|-----------------------|-----------------------------------------|
| Promise<void\>        | 使用promise的方式获取结果                  |

**示例：**

```
cameraInput.setFocusMode(afMode).then() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode(callback: AsyncCallback<FocusMode\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取当前的焦距模式，使用callback的方式获取一个异步的结果。

**参数：**

| 名称       | 类型                       | 必填      | 说明                                            |
|-----------|---------------------------|-----------|------------------------------------------------|
| callback  | AsyncCallback<FocusMode\> | Yes       | 使用callback的方式获取结果                        |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取当前的焦距模式，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型                  | 说明                                                |
|-----------------------|---------------------------------------------------|
| Promise<FocusMode\>   | 使用promise的方式获取结果                            |

**示例：**

```
cameraInput.getFocusMode().then(afMode) => {
    console.log('Promise returned with current focus mode : ' + afMode);
})
```

### getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取变焦比率的范围，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                            | 必填      | 说明                                             |
|----------|--------------------------------|-----------|-------------------------------------------------|
| callback | AsyncCallback<Array<number\>\> | Yes       | 使用callback的方式获取变焦比率的范围                 |


**返回值：**

none

**示例：**

```
cameraInput.getZoomRatioRange(err, zoomRatioRange) => {
    if (err) {
        console.error('Failed to get the zoom ratio range. ${err.message}');
        return;
    }
    console.log('Callback returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### getZoomRatioRange\(\): Promise<Array<number\>\>;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取变焦比率的范围，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型                    | 说明                                         |
|------------------------|---------------------------------------------|
| Promise<Array<number\>\> | 使用promise的方式获取变焦比率的范围            |

**示例：**

```
cameraInput.getZoomRatioRange().then((zoomRatioRange) => {
    console.log('Promise returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置变焦比率，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                     | 必填      | 说明                                |
|-----------|------------------------|-----------|------------------------------------|
| zoomRatio | number                 | Yes       | 变焦比率                            |
| callback  | AsyncCallback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置变焦比率，使用promise的方式获取结果。

**参数：**

| 名称       | 类型     | 必填 | 说明 |
|-----------|----------|-----------|-------------|
| zoomRatio | number   | Yes       | 变焦比率     |

**返回值：**

| 类型                   | 说明                                    |
|-----------------------|-----------------------------------------|
| Promise<void\>        | Promise used to return the result       |

**示例：**

```
cameraInput.setZoomRatio(zoomRatio).then() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio(callback: AsyncCallback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

获取当前的变焦比率，使用callback的方式获取一个异步的结果。

**参数：**

| 名称       | 类型                       | 必填      | 说明                                                  |
|-----------|---------------------------|-----------|------------------------------------------------------|
| callback  | AsyncCallback<number\>    | Yes       | 使用callback的方式获取结果                              |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

Gets current zoom ratio value. This method uses a promise to return the result.

**参数：**

none

**返回值：**

| 类型                  | 说明                                       |
|-----------------------|---------------------------------------------------|
| Promise<number\>      | Promise used to return the zoom ratio vaule       |

**示例：**

```
cameraInput.getZoomRatio().then(zoomRatio) => {
    console.log('Promise returned with current zoom ratio : ' + zoomRatio);
})
```

### release\(callback: AsyncCallback<void\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放这个 **相机输入** 实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称     | 类型                 | 必填 | 说明                        |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用异步的方式获取结果                 |

**返回值：**

none

**示例：**

```
camera.release((err) => {
    if (err) {
        console.error('Failed to release the CameraInput instance ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the CameraInput instance is released successfully.');
});
```

### release(): Promise<void\>;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放这个 **相机输入** 实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型           | 说明                                 |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |

**示例：**

```
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on(type: 'focusStateChange', callback: Callback<FocusState\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听焦距的状态变化，使用callback的方式获取焦距的状态变化。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<FocusState\>  | Yes       | 使用callback的方式获取结果                         |

**返回值：**

None

**示例：**

```
cameraInput.on('focusStateChange', (focusState) => {
    console.log('Focus state  : ' + focusState);
})
```

### on(type: 'error', callback: Callback<CameraInputError\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听**相机输入**的报错，使用callback的方式获取错误信息。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<CameraInputError\> | Yes  | 使用callback的方式获取**相机输入**的错误信息         |

**返回值：**

None

**示例：**

```
cameraInput.on('error', (cameraInputError) => {
    console.log('Camera input error code: ' + cameraInputError.code);
})
```


## FlashMode <a name="sec_FlashMode"></a>

枚举闪光灯模式。

| 名称                    | 默认值         | 说明                   |
|------------------------|---------------|------------------------|
| FLASH_MODE_CLOSE       | 0             | 闪光灯关闭模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FLASH_MODE_OPEN        | 1             | 闪光灯开启模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FLASH_MODE_AUTO        | 2             | 闪光灯自动模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FLASH_MODE_ALWAYS_OPEN | 3             | 闪光灯常亮模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |

## FocusMode <a name="sec_FocusMode"></a>

枚举焦距模式。

| 名称                        | 默认值         | 说明                        |
|----------------------------|---------------|----------------------------|
| FOCUS_MODE_MANUAL          | 0             | 手动变焦模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FOCUS_MODE_CONTINUOUS_AUTO | 1             | 连续自动变焦模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FOCUS_MODE_AUTO            | 2             | 自动变焦模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| FOCUS_MODE_LOCKED          | 3             | 焦距锁定模式<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## createCaptureSession\(context: Context, callback: AsyncCallback<CaptureSession\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建 **拍照会话** 实例，使用callback的方式获取一个异步的实例。

**参数：**

| 名称      | 类型                            | 必填      | 说明                                                |
|----------|--------------------------------|-----------|-----------------------------------------------------|
| context  | Context                        | Yes       | 应用环境                                             |
| callback | AsyncCallback<CaptureSession\> | Yes       | 使用callback的方式获取 **拍照会话** 实例                |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建 **拍照会话** 实例，使用promise方式获取一个实例。

**参数：**

| 名称      | 类型                          | 必填       | 说明                                                |
|----------|-------------------------------|-----------|-----------------------------------------------------|
| context  | Context                       | Yes       | 应用环境                                             |

**返回值：**

| 类型                       | 说明                                              |
|---------------------------|---------------------------------------------------|
| Promise<CaptureSession\>  | 使用promise的方式获取**拍照会话**的实例               |

**示例：**

```
camera.createCaptureSession(context).then((captureSession) => {
    console.log('Promise returned with the CaptureSession instance');
})
```

## CaptureSession<a name="sec_CaptureSession"></a>

**拍照会话**类。

### beginConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置此**拍照会话**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                  | 必填      | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

设置此**拍照会话**实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型           | 说明                                        |
|---------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                     |


**示例：**

```
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

提交此**拍照会话**实例的设置，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填      | 说明                                          |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取一个异步的结果             |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

提交此**拍照会话**实例的设置，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型           | 说明                                         |
|---------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                     |

**示例：**

```
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**相机输入**，使用callback的方式获取一个异步的结果。

**参数：**

| 名称         | 类型                  | 必填      | 说明                                         |
|-------------|----------------------|-----------|---------------------------------------------|
| cameraInput | CameraInput          | Yes       | 需要添加的**相机输入**实例                      |
| callback    | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                     |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**相机输入**，使用promise的方式获取结果。

**参数：**

| 名称         | 类型                 | 必填      | 说明                           |
|-------------|---------------------|-----------|-------------------------------|
| cameraInput | CameraInput         | Yes       | 需要添加的**相机输入**实例        |

**返回值：**

| 类型            | 说明                                |
|----------------|------------------------------------|
| Promise<void\> | 使用promise的方式获取结果             |

**示例：**

```
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### addOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**预览输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                 | 必填       | 说明                                 |
|---------------|----------------------|-----------|-------------------------------------|
| previewOutput | PreviewOutput        | Yes       | 需要添加的**预览输出**实例              |
| callback      | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果             |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**预览输出**实例，使用promise的方式获取结果。

**参数：**

| 名称           | 类型                 | 必填      | 说明                            |
|---------------|---------------------|-----------|--------------------------------|
| previewOutput | PreviewOutput       | Yes       | 需要添加的**预览输出**实例         |

**返回值：**

| 类型            | 说明                               |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.addOutput(previewOutput).then(() => {
    console.log('Promise used to indicate that the PreviewOutput instance is added.');
})
```

### addOutput\(photoOutput: PhotoOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**照片输出**实例， 使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                | 必填       | 说明                                 |
|---------------|---------------------|-----------|-------------------------------------|
| photoOutput   | PhotoOutput         | Yes       | 需要添加的**照片输出**实例              |
| callback      | AsyncCallback<void\> | Yes      | 使用callback的方式获取结果             |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**照片输出**实例，使用promise的方式获取结果。

**参数：**

| 名称           | 类型                 | 必填      | 说明                            |
|---------------|---------------------|-----------|--------------------------------|
| photoOutput   | PhotoOutput         | Yes       | 需要添加的**照片输出**实例         |

**返回值：**

| 类型           | 说明                              |
|---------------|-----------------------------------|
| Promise<void> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.addOutput(photoOutput).then(() => {
    console.log('Promise used to indicate that the PhotoOutput instance is added.');
})
```

### addOutput\(videoOutput: VideoOutput, callback: AsyncCallback<void\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**视频输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                 | 必填      | 说明                                 |
|---------------|---------------------|-----------|-------------------------------------|
| videoOutput   | VideoOutput         | Yes       | 需要添加的**视频输出**实例              |
| callback      | AsyncCallback<void\> | Yes      | 使用callback的方式获取结果             |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例添加一个**视频输出**实例， 使用promise的方式获取结果。

**参数：**

| 名称           | 类型                | 必填       | 说明                            |
|---------------|---------------------|-----------|--------------------------------|
| videoOutput   | VideoOutput         | Yes       | 需要添加的**视频输出**实例         |

**返回值：**

| 类型            | 说明                               |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.addOutput(videoOutput).then(() => {
    console.log('Promise used to indicate that the VideoOutput instance is added.');
})
```

### removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**相机输入**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称         | 类型                  | 必填      | 说明                                |
|-------------|----------------------|-----------|------------------------------------|
| cameraInput | CameraInput          | Yes       | 需要移除的**相机输入**实例             |
| callback    | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果             |


**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**相机输入**实例，使用promise的方式获取结果。

**参数：**

| 名称         | 类型                | 必填       | 说明                             |
|-------------|---------------------|-----------|---------------------------------|
| cameraInput | CameraInput         | Yes       | 需要移除的**相机输入**实例          |

**返回值：**

| 类型            | 说明                              |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### removeOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**预览输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                 | 必填       | 说明                                |
|---------------|----------------------|-----------|------------------------------------|
| previewOutput | PreviewOutput        | Yes       | 需要移除的**预览输出**实例             |
| callback      | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**预览输出**实例，使用promise的方式获取结果。

**参数：**

| 名称           | 类型                | 必填       | 说明                               |
|---------------|---------------------|-----------|-----------------------------------|
| previewOutput | PreviewOutput       | Yes       | 需要移除的**预览输出**实例            |


**返回值：**

| 类型         | 说明                                 |
|---------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果 |


**示例：**

```
captureSession.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is removed.');
})
```

### removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**照片输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                 | 必填       | 说明                                |
|---------------|----------------------|-----------|------------------------------------|
| photoOutput   | PhotoOutput          | Yes       | 需要移除的**照片输出**实例             |
| callback      | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**照片输出**实例，使用promise的方式获取结果。

**参数：**

| 名称           | 类型                 | 必填      | 说明                             |
|---------------|---------------------|-----------|---------------------------------|
| photoOutput   | PhotoOutput         | Yes       | 需要移除的**照片输出**实例          |


**返回值：**

| 类型         | 说明                                  |
|---------------|------------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |


**示例：**

```
captureSession.removeOutput(photoOutput).then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is removed.');
})
```

### removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**视频输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称           | 类型                  | 必填      | 说明                                |
|---------------|----------------------|-----------|------------------------------------|
| videoOutput   | VideoOutput          | Yes       | 需要移除的**视频输出**实例             |
| callback      | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

为此**拍照会话**实例移除一个**视频输出**实例，使用promise的方式获取结果。

**参数：**

| 名称           | 类型                | 必填       | 说明                             |
|---------------|---------------------|-----------|---------------------------------|
| videoOutput   | VideoOutput         | Yes       | 需要移除的**照片输出**实例          |


**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |


**示例：**

```
captureSession.removeOutput(videoOutput).then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is removed.');
})
```

### start\(callback: AsyncCallback<void\>\): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

开启**拍照会话** 实例， 使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

开启**拍照会话** 实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型            | 说明                              |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

关闭**拍照会话** 实例，使用callback的方式获取一个异步的结果。

**参数：**


| 名称      | 类型                 | 必填       | 说明                                |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

关闭**拍照会话** 实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型            | 说明                              |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |

**示例：**

```
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release\(callback: AsyncCallback<void\>\): void;<a name="section84581011418"></a>

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**拍照会话**实例，使用callback的方式获取一个异步的结果。

**参数：**
示例里
| 名称      | 类型                 | 必填       | 说明                                |
|----------|----------------------|-----------|------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**拍照会话**实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |

**示例：**

```
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### on(type: 'error', callback: Callback<CaptureSessionError\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听**拍照会话** 的报错，使用callback的方式获取错误信息。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<CaptureSessionError\> | Yes  | 使用callback的方式获取**拍照会话**的错误信息      |

**返回值：**

None

**示例：**

```
captureSession.on('error', (captureSessionError) => {
    console.log('Capture session error code: ' + captureSessionError.code);
})
```

## createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**预览输出**实例，使用callback的方式获取一个异步的实例。

**参数：**

| 名称        | 类型                          | 必填       | 说明                                                |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | 从XComponent组件获取的Surface ID                     |
| callback   | AsyncCallback<PreviewOutput\> | Yes       | 使用callback的方式获取的实例                           |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**预览输出**实例， 使用promise方式获取一个实例。.

**参数：**

| 名称        | 类型             | 必填      | 说明                                                |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | 从XComponent组件获取的Surface ID                     |

**返回值：**

| 类型                     | 说明                                               |
|-------------------------|---------------------------------------------------|
| Promise<PreviewOutput\> | 使用promise的方式获取结果                            |

**示例：**

```
camera.createPreviewOutput(surfaceId).then((previewOutput) => {
    console.log('Promise returned with the PreviewOutput instance');
})
```

## PreviewOutput

**预览输出**类。

### release(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**预览输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**预览输出**实例，使用promise的方式获取结果。

**参数：**
none

**返回值：**

| 类型            | 说明                               |
|----------------|-----------------------------------|
| Promise<void\> | 使用promise的方式获取结果            |


**示例：**

```
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### on(type: 'frameStart', callback: Callback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听一项预览帧的开启，使用callback的方式获取预览帧开启项。

**参数：**

| 名称      | 类型               | 必填      |  说明                               |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | 监听项的名称                         |
| callback | Callback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

None

**示例：**

```
previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
})
```

### on(type: 'frameEnd', callback: Callback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听一项预览帧的关闭，使用callback的方式获取预览帧关闭项。

**参数：**

| 名称      | 类型               | 必填      | 说明                                |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | 监听项的名称                         |
| callback | Callback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

None

**示例：**

```
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on(type: 'error', callback: Callback<PreviewOutputError\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听**预览输出**的报错，使用callback的方式获取错误信息。

**参数：**

| 名称      | 类型                    | 必填      | 说明                                             |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of event to listen for.                    |
| callback | Callback<PreviewOutputError\> | Yes  | 使用callback的方式获取**预览输出**的错误信息        |

**返回值：**

None

**示例：**

```
previewOutput.on('error', (previewOutputError) => {
    console.log('Preview output error code: ' + previewOutputError.code);
})
```

## createPhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**照片输出**实例，使用callback的方式获取一个异步的实例。

**参数：**

| 名称        | 类型                          | 必填       | 说明                                                |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | 从ImageReceiver获取的Surfack ID                      |
| callback   | AsyncCallback<PhotoOutput\>   | Yes       | 使用callback的方式获取结果                            |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**照片输出**实例，使用promise的方式获取实例。

**参数：**

| 名称        | 类型             | 必填      | 说明                                                |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | 从ImageReceiver获取的Surfack ID                      |

**返回值：**

| 类型                     | 说明                                             |
|-------------------------|--------------------------------------------------|
| Promise<PhotoOutput\>   | 使用promise的方式获取结果                           |

**示例：**

```
camera.createPhotoOutput(surfaceId).then((photoOutput) => {
    console.log('Promise returned with PhotoOutput instance');
})
```
## 图片旋转

枚举图片旋转角度。

| 名称          | 默认值         | 说明                                    |
|--------------|---------------|----------------------------------------|
| ROTATION_0   | 0             | 图片旋转0度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| ROTATION_90  | 90            | 图片旋转90度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| ROTATION_180 | 180           | 图片旋转180度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| ROTATION_270 | 270           | 图片旋转270度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## 拍摄地点

拍摄的照片的地点。

| 名称       | 类型   | 权限          | 说明         |
|-----------|--------|--------------|-------------|
| latitude  | number | read / write | 纬度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| longitude | number | read / write | 经度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |

## 图片质量

枚举图片质量。

| 名称                  | 默认值         | 说明                  |
|----------------------|---------------|----------------------|
| QUALITY_LEVEL_HIGH   | 0             | 高图片质量<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| QUALITY_LEVEL_MEDIUM | 1             | 中图片质量<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| QUALITY_LEVEL_LOW    | 2             | 低图片质量<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## 拍照设置

拍摄的照片的设置。

| 名称      | 类型          | 必填       | 说明                 |
|----------|---------------|-----------|---------------------|
| quality  | QualityLevel  | Optional  | 图片质量<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |
| rotation | ImageRotation | Optional  | 图片旋转角度<br/> 系统能力 : SystemCapability.Multimedia.Camera.Core |


## 照片输出

**照片输出**类。

### capture(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

拍照，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填      | 说明                                          |
|----------|---------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                     |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用拍照设置拍照， 使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| setting  | PhotoCaptureSetting  | Yes       | 拍照设置                                       |
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

使用拍照设置拍照， 使用promise的方式获取结果。

**参数：**

| 名称      | 类型                 | 必填      | 说明                                          |
|----------|---------------------|-----------|----------------------------------------------|
| setting  | PhotoCaptureSetting | No        | 拍照设置                                       |

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |


**示例：**

```
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### release(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**拍照输出**实例，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**拍照输出**实例，使用promise的方式获取结果。

**参数：**
none

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |


**示例：**

```
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is released successfully.');
})
```

### on(type: 'captureStart', callback: Callback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听拍照项的启动，使用callback的方式获取一个拍照项的启动结果。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of event to listen for.                    |
| callback | Callback<number\>      | Yes       | 使用callback的方式获取captureID                    |

**返回值：**

None

**示例：**

```
photoOutput.on('captureStart', (captureId) => {
    console.log('photo capture stated, captureId : ' + captureId);
})
```

### on(type: 'frameShutter', callback: Callback<FrameShutterInfo\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听一项帧刷新，使用callback的方式获取帧的刷新项。

**参数：**

| 名称      | 类型                    | 必填      | 说明                                             |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<FrameShutterInfo\> | Yes   | 使用callback的方式获取结果                        |

**返回值：**

None

**示例：**

```
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log('photo capture end, captureId : ' + frameShutterInfo.captureId);
    console.log('Timestamp for frame : ' + frameShutterInfo.timestamp);
})
```

### on(type: 'captureEnd', callback: Callback<CaptureEndInfo\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听拍照项的关闭，使用callback的方式获取一个拍照项的关闭结果。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<CaptureEndInfo\> | Yes    | 使用callback的方式获取拍照结束的信息                 |

**返回值：**

None

**示例：**

```
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log('photo capture end, captureId : ' + captureEndInfo.captureId);
    console.log('frameCount : ' + captureEndInfo.frameCount);
})
```

### on(type: 'error', callback: Callback<PhotoOutputError\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听**照片输出**的报错，使用callback的方式获取错误信息。

**参数：**

| 名称     | 类型                   | 必填 | 说明                                     |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | Name of event to listen for.                    |
| callback | Callback<PhotoOutputError\> | Yes  | 使用callback的方式获取**照片输出**的错误信息          |

**返回值：**

None

**示例：**

```
photoOutput.on('error', (photoOutputError) => {
    console.log('Photo output error code: ' + photoOutputError.code);
})
```

## createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**视频输出**实例，使用callback的方式获取一个异步的实例。

**参数：**

| 名称        | 类型                           | 必填      | 说明                                                |
|------------|-------------------------------|-----------|----------------------------------------------------|
| surfaceId  | string                        | Yes       | 从VideoRecorder获取的Surfack ID                     |
| callback   | AsyncCallback<VideoOutput\>   | Yes       | 用callback的方式获取结果                              |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

创建**视频输出**实例，使用promise的方式获取结果。

**参数：**

| 名称        | 类型            | 必填       | 说明                                                |
|------------|-----------------|-----------|----------------------------------------------------|
| surfaceId  | string          | Yes       | 从VideoRecorder获取的Surfack ID                      |

**返回值：**

| 类型                    | 说明                                              |
|-------------------------|-------------------------------------------------|
| Promise<PhotoOutput\>   | 使用promise的方式获取结果                          |

**示例：**

```
camera.createVideoOutput(surfaceId).then((videoOutput) => {
    console.log('Promise returned with the VideoOutput instance');
})
```

## VideoOutput

实现视频输出。

### start(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

开启**视频输出**实例， 使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                  | 必填      | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

开启**视频输出**实例， 使用promise的方式获取结果。

**参数：**
none

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |


**示例：**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
```

### stop(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

关闭视频输出，使用callback的方式获取一个异步的结果。

**参数：**

| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

关闭视频输出，使用promise的方式获取结果。

**参数：**
none

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |

**示例：**

```
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
})
```

### release(callback: AsyncCallback<void\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**视频输出**实例， 使用callback的方式获取一个异步的结果。

**参数：**
Camera appear
| 名称      | 类型                 | 必填       | 说明                                          |
|----------|----------------------|-----------|----------------------------------------------|
| callback | AsyncCallback<void\> | Yes       | 使用callback的方式获取结果                      |

**返回值：**

none

**示例：**

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

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

释放**视频输出**实例，使用promise的方式获取结果。

**参数：**

none

**返回值：**

| 类型            | 说明                                         |
|----------------|---------------------------------------------|
| Promise<void\> | 使用promise的方式获取结果                      |


**示例：**

```
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is released successfully.');
})
```

### on(type: 'frameStart', callback: Callback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听一项视频帧的开启，使用callback的方式获取视频帧的开启项。

**参数：**

| 名称      | 类型               | 必填      | 说明                                |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | 监听项的名称                         |
| callback | Callback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

None

**示例：**

```
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on(type: 'frameEnd', callback: Callback<number\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听一项视频帧的关闭，使用callback的方式获取视频帧的开启项。

**参数：**

| 名称      | 类型               | 必填      | 说明                                |
| :------- | :---------------- | :-------- | :----------------------------------|
| type     | string            | Yes       | 监听项的名称                         |
| callback | Callback<void\>   | Yes       | 使用callback的方式获取结果            |

**返回值：**

None

**示例：**

```
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on(type: 'error', callback: Callback<VideoOutputError\>): void;

**系统能力：**

SystemCapability.Multimedia.Camera.Core

**说明：**

监听 **视频输出** 的报错，使用callback的方式获取错误信息。

**参数：**

| 名称      | 类型                    | 必填      | 说明                                             |
| :------- | :--------------------- | :-------- | :-----------------------------------------------|
| type     | string                 | Yes       | 监听项的名称                                      |
| callback | Callback<VideoOutputError\> | Yes  | 使用callback的方式获取**视频输出**的错误信息          |

**返回值：**

None

**示例：**

```
videoOutput.on('error', (VideoOutputError) => {
    console.log('Video output error code: ' + VideoOutputError.code);
})
```