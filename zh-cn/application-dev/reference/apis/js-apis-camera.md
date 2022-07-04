# 相机管理

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context, callback: AsyncCallback<CameraManager\>): void

获取相机管理器实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                            | 必填 | 说明                               |
| -------- | ----------------------------------------------- | ---- | ---------------------------------- |
| context  | Context                                         | 是   | 应用上下文。                       |
| callback | AsyncCallback<[CameraManager](#cameramanager)\> | 是   | 回调函数，用于获取相机管理器实例。 |

**示例：**

```js
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

获取相机管理器实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称    | 类型    | 必填 | 说明         |
| ------- | ------- | ---- | ------------ |
| context | Context | 是   | 应用上下文。 |

**返回值：**

| 类型                                      | 说明                                      |
| ----------------------------------------- | ----------------------------------------- |
| Promise<[CameraManager](#cameramanager)\> | 使用Promise的方式获取一个相机管理器实例。 |

**示例：**

```js
camera.getCameraManager(context).then((cameraManager) => {
    console.log('Promise returned with the CameraManager instance.');
})
```

## CameraStatus

枚举，相机状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                      | 值   | 说明         |
| ------------------------- | ---- | ------------ |
| CAMERA_STATUS_APPEAR      | 0    | 相机存在。   |
| CAMERA_STATUS_DISAPPEAR   | 1    | 相机不存在。 |
| CAMERA_STATUS_AVAILABLE   | 2    | 相机就绪。   |
| CAMERA_STATUS_UNAVAILABLE | 3    | 相机未就绪。 |


## CameraPosition

枚举，相机方向。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                        | 值   | 说明             |
| --------------------------- | ---- | ---------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | 未指定方向相机。 |
| CAMERA_POSITION_BACK        | 1    | 后置相机。       |
| CAMERA_POSITION_FRONT       | 2    | 前置相机。       |

## CameraType

枚举，相机类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                    | 值   | 说明             |
| ----------------------- | ---- | ---------------- |
| CAMERA_TYPE_UNSPECIFIED | 0    | 未指定相机类型。 |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | 广角相机。       |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | 超级广角相机。   |
| CAMERA_TYPE_TELEPHOTO   | 3    | 长焦相机。       |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | 深度相机。       |


## ConnectionType

枚举，相机连接类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值   | 说明          |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | 内置相机。    |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | 外置USB相机。 |
| CAMERA_CONNECTION_REMOTE     | 2    | 分布式相机。  |

## Size

用于表示相机预览、照片、视频支持的尺寸大小。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型   | 可读 | 可写 | 说明         |
| ------ | ------ | ---- | ---- | ------------ |
| height | string | 是   | 是   | 图像的高度。 |
| width  | number | 是   | 是   | 图像的宽度。 |

## CameraManager

相机管理器类，使用前需要通过getCameraManager获取相机管理实例。

### getCameras

getCameras(callback: AsyncCallback<Array<Camera\>\>): void

异步获取设备支持的相机列表，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                      | 必填 | 说明                                 |
| -------- | ----------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback<Array<[Camera](#camera)\>\> | 是   | 使用callback方式获取支持的相机列表。 |

**示例：**

```js
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

异步获取设备支持的相机列表，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                | 说明                          |
| ----------------------------------- | ----------------------------- |
| Promise<Array<[Camera](#camera)\>\> | 使用promise获取支持相机列表。 |


**示例：**

```js
cameraManager.getCameras().then((cameraArray) => {
    console.log('Promise returned with an array of supported cameras: ' + cameraArray.length);
})
```

### createCameraInput

createCameraInput(cameraId: string, callback: AsyncCallback<CameraInput\>): void

使用相机ID异步创建CameraInput实例，通过注册回调函数获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                        | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| cameraId | string                                      | 是   | 指定相机ID。                        |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | 是   | 回调函数，用于获取CameraInput实例。 |

**示例：**

```js
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

使用相机ID异步创建CameraInput实例，通过Promise获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------ |
| cameraId | string | 是   | 指定相机ID。 |

**返回值：**

| 类型                                  | 说明                                     |
| ------------------------------------- | ---------------------------------------- |
| Promise<[CameraInput](#camerainput)\> | 使用Promise的方式获取CameraInput的实例。 |

**示例：**

```js
cameraManager.createCameraInput(cameraId).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void

使用相机位置和相机类型异步创建CameraInput实例，通过注册回调函数获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                        | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| position | [CameraPosition](#cameraposition)           | 是   | 相机位置。                          |
| type     | [CameraType](#cameratype)                   | 是   | 相机类型。                          |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | 是   | 回调函数，用于获取CameraInput实例。 |

**示例：**

```js
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

使用相机位置和相机类型异步创建CameraInput实例，通过Promise获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                              | 必填 | 说明       |
| -------- | --------------------------------- | ---- | ---------- |
| position | [CameraPosition](#cameraposition) | 是   | 相机位置。 |
| type     | [CameraType](#cameratype)         | 是   | 相机类型。 |

**返回值：**

| 类型                                  | 说明                                     |
| ------------------------------------- | ---------------------------------------- |
| Promise<[CameraInput](#camerainput)\> | 使用Promise的方式获取CameraInput的实例。 |

**示例：**

```js
cameraManager.createCameraInput(camera.CameraPosition.CAMERA_POSITION_BACK, camera.CameraType.CAMERA_TYPE_UNSPECIFIED).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance.');
})
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

监听相机的状态变化，通过注册回调函数获取相机的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                                  | 必填 | 说明                                                 |
| :------- | :---------------------------------------------------- | :--- | :--------------------------------------------------- |
| type     | string                                                | 是   | 监听事件，固定为'cameraStatus'，即相机状态变化事件。 |
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | 是   | 回调函数，用于获取相机状态变化信息。                 |

**示例：**

```js
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

调用[camera.getCameraManager](#cameragetcameramanager)后，将返回Camera实例，包括相机ID、位置、类型、连接类型等相机相关的元数据。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称           | 类型                              | 只读 | 说明           |
| -------------- | --------------------------------- | ---- | -------------- |
| cameraId       | string                            | 是   | 相机ID。       |
| cameraPosition | [CameraPosition](#cameraposition) | 是   | 相机位置。     |
| cameraType     | [CameraType](#cameratype)         | 是   | 相机类型。     |
| connectionType | [ConnectionType](#connectiontype) | 是   | 相机连接类型。 |

**示例：**

```js
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

相机管理器回调返回的接口实例，表示相机状态信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称   | 类型                          | 说明       |
| ------ | ----------------------------- | ---------- |
| camera | [Camera](#camera)             | 相机信息。 |
| status | [CameraStatus](#camerastatus) | 相机状态。 |


## CameraInput

相机输入类。在使用该类的方法前，需要先构建一个CameraInput实例。

### getCameraId

getCameraId(callback: AsyncCallback<string\>\): void

异步获取该CameraInput实例的相机ID，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                   | 必填 | 说明                       |
| -------- | ---------------------- | ---- | -------------------------- |
| callback | AsyncCallback<string\> | 是   | 回调函数，用于获取相机ID。 |

**示例：**

```js
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

异步获取该CameraInput实例的相机ID，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型             | 说明                          |
| ---------------- | ----------------------------- |
| Promise<string\> | 使用Promise的方式获取相机ID。 |

**示例：**

```js
cameraInput.getCameraId().then((cameraId) => {
    console.log('Promise returned with the camera ID:' + cameraId);
})
```


### hasFlash

hasFlash(callback: AsyncCallback<boolean\>): void

判断设备是否支持闪光灯，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示设备支持闪光灯。 |

**示例：**

```js
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

判断设备是否支持闪光灯，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型              | 说明                                                    |
| ----------------- | ------------------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持闪光灯。 |

**示例：**

```js
cameraInput.hasFlash().then((status) => {
    console.log('Promise returned with the flash light support status:' + status);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void

判断设备是否支持指定闪光灯模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                    | 必填 | 说明                                     |
| --------- | ----------------------- | ---- | ---------------------------------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。                         |
| callback  | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示支持该闪光灯模式。 |

**示例：**

```js
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

判断设备是否支持指定闪光灯模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持该闪光灯模式。 |

**示例：**

```js
cameraInput.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO).then((status) => {
    console.log('Promise returned with flash mode support status.' + status);
})
```

### setFlashMode

setFlashMode(flashMode: FlashMode, callback: AsyncCallback<void\>): void

设置闪光灯模式，通过注册回调函数获取结果。

进行设置之前，需要先检查：

1. 设备是否支持闪光灯，可使用方法[hasFlash](#hasflash)。
2. 设备是否支持指定的闪光灯模式，可使用方法[isFlashModeSupported](#isflashmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                    | 必填 | 说明                     |
| --------- | ----------------------- | ---- | ------------------------ |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。         |
| callback  | AsyncCallback<void\>    | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

设置闪光灯模式，通过Promise获取结果。

进行设置之前，需要先检查：

1. 设备是否支持闪光灯，可使用方法[hasFlash](#hasflash)。
2. 设备是否支持指定的闪光灯模式，可使用方法[isFlashModeSupported](#isflashmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                    | 必填 | 说明             |
| --------- | ----------------------- | ---- | ---------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode

getFlashMode(callback: AsyncCallback<FlashMode\>): void

获取当前设备的闪光灯模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                    | 必填 | 说明                                     |
| -------- | --------------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback<[FlashMode](#flashmode)\> | 是   | 回调函数，用于获取当前设备的闪光灯模式。 |

**示例：**

```js
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

获取当前设备的闪光灯模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                              | 说明                                    |
| --------------------------------- | --------------------------------------- |
| Promise<[FlashMode](#flashmode)\> | 使用Promise的方式获取当前的闪光灯模式。 |

**示例：**

```js
cameraInput.getFlashMode().then((flashMode) => {
    console.log('Promise returned with current flash mode : ' + flashMode);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void

判断设备是否支持指定的焦距模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。                       |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示支持该焦距模式。 |

**示例：**

```js
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

判断设备是否支持指定的焦距模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称   | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| afMode | [FocusMode](#focusmode) | 是   | 指定的焦距模式。 |

**返回值：**

| 类型              | 说明                                                        |
| ----------------- | ----------------------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持该焦距模式。 |

**示例：**

```js
cameraInput.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO).then((status) => {
    console.log('Promise returned with focus mode support status.' + status);
})
```

### setFocusMode

setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void

设置焦距模式，通过注册回调函数获取结果。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                    | 必填 | 说明                     |
| -------- | ----------------------- | ---- | ------------------------ |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。         |
| callback | AsyncCallback<void\>    | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

设置焦距模式，通过Promise获取结果。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称   | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| afMode | [FocusMode](#focusmode) | 是   | 指定的焦距模式。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode

getFocusMode(callback: AsyncCallback<FocusMode\>): void

获取当前设备的焦距模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                    | 必填 | 说明                                   |
| -------- | --------------------------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback<[FocusMode](#focusmode)\> | 是   | 回调函数，用于获取当前设备的焦距模式。 |

**示例：**

```js
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

获取当前设备的焦距模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                  |
| ------------------- | ------------------------------------- |
| Promise<FocusMode\> | 使用Promise的方式获取当前的焦距模式。 |

**示例：**

```js
cameraInput.getFocusMode().then((afMode) => {
    console.log('Promise returned with current focus mode : ' + afMode);
})
```

### getZoomRatioRange

getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void

获取可变焦距比范围，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                           | 必填 | 说明                     |
| -------- | ------------------------------ | ---- | ------------------------ |
| callback | AsyncCallback<Array<number\>\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

获取可变焦距比范围，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                     | 说明                                        |
| ------------------------ | ------------------------------------------- |
| Promise<Array<number\>\> | 使用Promise的方式获取当前的可变焦距比范围。 |

**示例：**

```js
cameraInput.getZoomRatioRange().then((zoomRatioRange) => {
    console.log('Promise returned with zoom ratio range: ' + zoomRatioRange.length);
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void

设置可变焦距比，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                 | 必填 | 说明                     |
| --------- | -------------------- | ---- | ------------------------ |
| zoomRatio | number               | 是   | 可变焦距比。             |
| callback  | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

设置可变焦距比，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ------------ |
| zoomRatio | number | 是   | 可变焦距比。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.setZoomRatio(1).then(() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio

getZoomRatio(callback: AsyncCallback<number\>): void

获取当前的可变焦距比，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                   | 必填 | 说明                     |
| -------- | ---------------------- | ---- | ------------------------ |
| callback | AsyncCallback<number\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

获取当前的可变焦距比，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise<number\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.getZoomRatio().then((zoomRatio) => {
    console.log('Promise returned with current zoom ratio : ' + zoomRatio);
})
```

### release

release\(callback: AsyncCallback<void\>\): void

释放相机实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

释放相机实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

监听焦距的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                      | 必填 | 说明                                                     |
| :------- | :---------------------------------------- | :--- | :------------------------------------------------------- |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，即焦距状态变化事件。 |
| callback | AsyncCallback<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取焦距状态。                             |

**示例：**

```js
cameraInput.on('focusStateChange', (focusState) => {
    console.log('Focus state  : ' + focusState);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CameraInputError\>): void

监听CameraInput的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                             | 必填 | 说明                                             |
| :------- | :------------------------------- | :--- | :----------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'error'，即CameraInput错误事件。 |
| callback | ErrorCallback<[CameraInputError](#camerainputerror)\> | 是   | 回调函数，用于获取结果。                         |

**示例：**

```js
cameraInput.on('error', (cameraInputError) => {
    console.log('Camera input error code: ' + cameraInputError.code);
})
```

##  CameraInputErrorCode

枚举，CameraInput的错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | ---------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

##  CameraInputError

CameraInput错误对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                        | 说明                       |
| ---- | ------------------------------------------- | -------------------------- |
| code | [CameraInputErrorCode](#camerainputerrorcode) | CameraInput中的错误码。 |


## FlashMode

枚举，闪光灯模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                   | 值   | 说明         |
| ---------------------- | ---- | ------------ |
| FLASH_MODE_CLOSE       | 0    | 闪光灯关闭。 |
| FLASH_MODE_OPEN        | 1    | 闪光灯开启。 |
| FLASH_MODE_AUTO        | 2    | 自动闪光灯。 |
| FLASH_MODE_ALWAYS_OPEN | 3    | 闪光灯常亮。 |

## FocusMode

枚举，焦距模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                       | 值   | 说明               |
| -------------------------- | ---- | ------------------ |
| FOCUS_MODE_MANUAL          | 0    | 手动变焦模式。     |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | 连续自动变焦模式。 |
| FOCUS_MODE_AUTO            | 2    | 自动变焦模式。     |
| FOCUS_MODE_LOCKED          | 3    | 定焦模式。         |

## FocusState

枚举，焦距状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                  | 值   | 说明         |
| --------------------- | ---- | ------------ |
| FOCUS_STATE_SCAN      | 0    | 扫描状态。   |
| FOCUS_STATE_FOCUSED   | 1    | 相机已对焦。 |
| FOCUS_STATE_UNFOCUSED | 2    | 相机未对焦。 |

## camera.createCaptureSession

createCaptureSession\(context: Context, callback: AsyncCallback<CaptureSession\>\): void

获取CaptureSession实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                              | 必填 | 说明                                   |
| -------- | ------------------------------------------------- | ---- | -------------------------------------- |
| context  | Context                                           | 是   | 应用上下文。                           |
| callback | AsyncCallback<[CaptureSession](#capturesession)\> | 是   | 回调函数，用于获取CaptureSession实例。 |

**示例：**

```js
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

获取CaptureSession实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称    | 类型    | 必填 | 说明         |
| ------- | ------- | ---- | ------------ |
| context | Context | 是   | 应用上下文。 |

**返回值：**

| 类型                                        | 说明                                      |
| ------------------------------------------- | ----------------------------------------- |
| Promise<[CaptureSession](#capturesession)\> | 使用Promise的方式获取CaptureSession实例。 |

**示例：**

```js
camera.createCaptureSession(context).then((captureSession) => {
    console.log('Promise returned with the CaptureSession instance');
})
```

## CaptureSession

拍照会话类。

### beginConfig

beginConfig\(callback: AsyncCallback<void\>\): void

开始配置会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

开始配置会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig

commitConfig\(callback: AsyncCallback<void\>\): void

提交会话配置，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

提交会话配置，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput

addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

在当前会话中，添加一个CameraInput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，添加一个CameraInput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### addOutput

addOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void

在当前会话中，添加一个PreviewOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称          | 类型                            | 必填 | 说明                          |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | 是   | 需要添加的PreviewOutput实例。 |
| callback      | AsyncCallback<void\>            | 是   | 回调函数，用于获取结果。      |

**示例：**

```js
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

在当前会话中，添加一个PreviewOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称          | 类型                            | 必填 | 说明                          |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | 是   | 需要添加的PreviewOutput实例。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addOutput(previewOutput).then(() => {
    console.log('Promise used to indicate that the PreviewOutput instance is added.');
})
```

### addOutput

addOutput\(photoOutput: PhotoOutput, callback: AsyncCallback<void\>\): void

在当前会话中，添加一个PhotoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | 是   | 需要添加的PhotoOutput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，添加一个PhotoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | 是   | 需要添加的PhotoOutput实例。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addOutput(photoOutput).then(() => {
    console.log('Promise used to indicate that the PhotoOutput instance is added.');
})
```

### addOutput

addOutput\(videoOutput: VideoOutput, callback: AsyncCallback<void\>\): void

在当前会话中，添加一个VideoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | 是   | 需要添加的VideoOutput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，添加一个VideoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | 是   | 需要添加的VideoOutput实例。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addOutput(videoOutput).then(() => {
    console.log('Promise used to indicate that the VideoOutput instance is added.');
})
```

### removeInput

removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

在当前会话中，移除一个CameraInput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，移除一个CameraInput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise\<void> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### removeOutput

removeOutput\(previewOutput: PreviewOutput, callback: AsyncCallback<void\>\): void

在当前会话中，移除一个PreviewOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称          | 类型                            | 必填 | 说明                          |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | 是   | 需要移除的PreviewOutput实例。 |
| callback      | AsyncCallback<void\>            | 是   | 回调函数，用于获取结果。      |

**示例：**

```js
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

在当前会话中，移除一个PreviewOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称          | 类型                            | 必填 | 说明                          |
| ------------- | ------------------------------- | ---- | ----------------------------- |
| previewOutput | [PreviewOutput](#previewoutput) | 是   | 需要移除的PreviewOutput实例。 |


**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is removed.');
})
```

### removeOutput

removeOutput(photoOutput: PhotoOutput, callback: AsyncCallback<void\>): void

在当前会话中，移除一个PhotoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | 是   | 需要移除的PhotoOutput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，移除一个PhotoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| photoOutput | [PhotoOutput](#photooutput) | 是   | 需要移除的PhotoOutput实例。 |


**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.removeOutput(photoOutput).then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is removed.');
})
```

### removeOutput

removeOutput(videoOutput: VideoOutput, callback: AsyncCallback<void\>): void

在当前会话中，移除一个VideoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | 是   | 需要移除的VideoOutput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

```js
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

在当前会话中，移除一个VideoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称        | 类型                        | 必填 | 说明                        |
| ----------- | --------------------------- | ---- | --------------------------- |
| videoOutput | [VideoOutput](#videooutput) | 是   | 需要移除的VideoOutput实例。 |


**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.removeOutput(videoOutput).then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is removed.');
})
```

### start

start\(callback: AsyncCallback<void\>\): void

启动拍照会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

启动拍照会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop

stop\(callback: AsyncCallback<void\>\): void

停止拍照会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**


| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

停止拍照会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

释放CaptureSession实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

释放CaptureSession实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CaptureSessionError\>): void

监听拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                                        | 必填 | 说明                                          |
| :------- | :---------------------------------------------------------- | :--- | :-------------------------------------------- |
| type     | string                                                      | 是   | 监听事件，固定为'error'，即拍照会话错误事件。 |
| callback | ErrorCallback<[CaptureSessionError](#capturesessionerror)\> | 是   | 回调函数，用于获取错误信息。                  |

**示例：**

```js
captureSession.on('error', (captureSessionError) => {
    console.log('Capture session error code: ' + captureSessionError.code);
})
```

##  CaptureSessionErrorCode

枚举，拍照会话的错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | ---------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

##  CaptureSessionError

拍照会话错误对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                        | 说明                       |
| ---- | ------------------------------------------- | -------------------------- |
| code | [CaptureSessionError](#capturesessionerror) | CaptureSession中的错误码。 |

## camera.createPreviewOutput

createPreviewOutput(surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void

获取PreviewOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                                            | 必填 | 说明                                  |
| --------- | ----------------------------------------------- | ---- | ------------------------------------- |
| surfaceId | string                                          | 是   | 从XComponent组件获取的Surface ID。    |
| callback  | AsyncCallback<[PreviewOutput](#previewoutput)\> | 是   | 回调函数，用于获取PreviewOutput实例。 |

**示例：**

```js
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

获取PreviewOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型   | 必填 | 说明                               |
| --------- | ------ | ---- | ---------------------------------- |
| surfaceId | string | 是   | 从XComponent组件获取的Surface ID。 |

**返回值：**

| 类型                                      | 说明                        |
| ----------------------------------------- | --------------------------- |
| Promise<[PreviewOutput](#previewoutput)\> | 使用Promise的方式获取结果。 |

**示例：**

```js
camera.createPreviewOutput("surfaceId").then((previewOutput) => {
    console.log('Promise returned with the PreviewOutput instance');
})
```

## PreviewOutput

预览输出类。

### release

release(callback: AsyncCallback<void\>): void

释放PreviewOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

释放PreviewOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

监听预览帧启动，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                                         |
| :------- | :------------------- | :--- | :------------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，即帧启动事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                     |

**示例：**

```js
previewOutput.on('frameStart', () => {
    console.log('Preview frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

监听预览帧结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                                       |
| :------- | :------------------- | :--- | :----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，即帧结束事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                   |

**示例：**

```js
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PreviewOutputError\>): void

监听预览输出的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                                         | 必填 | 说明                                          |
| :------- | :----------------------------------------------------------- | :--- | :-------------------------------------------- |
| type     | string                                                       | 是   | 监听事件，固定为'error'，即预览输出错误事件。 |
| callback | ErrorCallback<[PreviewOutputErrorCode](#previewoutputerrorcode)\> | 是   | 回调函数，用于获取错误信息。                  |

**示例：**

```js
previewOutput.on('error', (previewOutputError) => {
    console.log('Preview output error code: ' + previewOutputError.code);
})
```

## PreviewOutputErrorCode

枚举，预览输出的错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | ---------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

##  PreviewOutputError

预览输出错误对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                              | 说明                   |
| ---- | ------------------------------------------------- | ---------------------- |
| code | [PreviewOutputErrorCode](#previewoutputerrorcode) | PreviewOutput中的错误码。 |

## camera.createPhotoOutput

createPhotoOutput(surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void

获取PhotoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                                        | 必填 | 说明                                |
| --------- | ------------------------------------------- | ---- | ----------------------------------- |
| surfaceId | string                                      | 是   | 从ImageReceiver获取的Surface ID。   |
| callback  | AsyncCallback<[PhotoOutput](#photooutput)\> | 是   | 回调函数，用于获取PhotoOutput实例。 |

**示例：**

```js
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

获取PhotoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型   | 必填 | 说明                              |
| --------- | ------ | ---- | --------------------------------- |
| surfaceId | string | 是   | 从ImageReceiver获取的Surface ID。 |

**返回值：**

| 类型                                  | 说明                                   |
| ------------------------------------- | -------------------------------------- |
| Promise<[PhotoOutput](#photooutput)\> | 使用Promise的方式获取PhotoOutput实例。 |

**示例：**

```js
camera.createPhotoOutput("surfaceId").then((photoOutput) => {
    console.log('Promise returned with PhotoOutput instance');
})
```
## ImageRotation

枚举，图片旋转角度。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 值   | 说明            |
| ------------ | ---- | --------------- |
| ROTATION_0   | 0    | 图片旋转0度。   |
| ROTATION_90  | 90   | 图片旋转90度。  |
| ROTATION_180 | 180  | 图片旋转180度。 |
| ROTATION_270 | 270  | 图片旋转270度。 |

## QualityLevel

枚举，图片质量。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                 | 值   | 说明           |
| -------------------- | ---- | -------------- |
| QUALITY_LEVEL_HIGH   | 0    | 图片质量高。   |
| QUALITY_LEVEL_MEDIUM | 1    | 图片质量中等。 |
| QUALITY_LEVEL_LOW    | 2    | 图片质量差。   |


## PhotoCaptureSetting

拍摄照片的设置。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型                            | 必填 | 说明           |
| -------- | ------------------------------- | ---- | -------------- |
| quality  | [QualityLevel](#qualitylevel)   | 否   | 图片质量。     |
| rotation | [ImageRotation](#imagerotation) | 否   | 图片旋转角度。 |


## PhotoOutput

照片输出类。

### capture

capture(callback: AsyncCallback<void\>): void

拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

根据拍照设置拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                        | 必填 | 说明                     |
| -------- | ------------------------------------------- | ---- | ------------------------ |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | 是   | 拍照设置。               |
| callback | AsyncCallback<void\>                        | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

根据拍照设置拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称    | 类型                                        | 必填 | 说明       |
| ------- | ------------------------------------------- | ---- | ---------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | 否   | 拍照设置。 |

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### release

release(callback: AsyncCallback<void\>): void

释放PhotoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

释放PhotoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PhotoOutput instance is released successfully.');
})
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

监听拍照启动，通过注册回调函数获取Capture ID。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                   | 必填 | 说明                                             |
| :------- | :--------------------- | :--- | :----------------------------------------------- |
| type     | string                 | 是   | 监听事件，固定为'captureStart'，即拍照启动事件。 |
| callback | AsyncCallback<number\> | 是   | 使用callback的方式获取Capture ID。               |

**示例：**

```js
photoOutput.on('captureStart', (err, captureId) => {
    console.log('photo capture stated, captureId : ' + captureId);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

监听快门，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                                  | 必填 | 说明                                           |
| :------- | :---------------------------------------------------- | :--- | :--------------------------------------------- |
| type     | string                                                | 是   | 监听事件，固定为'frameShutter'，即帧刷新事件。 |
| callback | AsyncCallback<[FrameShutterInfo](#frameshutterinfo)\> | 是   | 回调函数，用于获取相关信息。                   |

**示例：**

```js
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log('photo capture end, captureId : ' + frameShutterInfo.captureId);
    console.log('Timestamp for frame : ' + frameShutterInfo.timestamp);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

监听拍照停止，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                              | 必填 | 说明                                           |
| :------- | :------------------------------------------------ | :--- | :--------------------------------------------- |
| type     | string                                            | 是   | 监听事件，固定为'captureEnd'，即拍照停止事件。 |
| callback | AsyncCallback<[CaptureEndInfo](#captureendinfo)\> | 是   | 回调函数，用于获取相关信息。                   |

**示例：**

```js
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log('photo capture end, captureId : ' + captureEndInfo.captureId);
    console.log('frameCount : ' + captureEndInfo.frameCount);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PhotoOutputError\>): void

监听拍照的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                                  | 必填 | 说明                                      |
| :------- | :---------------------------------------------------- | :--- | :---------------------------------------- |
| type     | string                                                | 是   | 监听事件，固定为'error'，即拍照错误事件。 |
| callback | ErrorCallback<[PhotoOutputError](#photooutputerror)\> | 是   | 回调函数，用于获取错误信息。              |

**示例：**

```js
photoOutput.on('error', (photoOutputError) => {
    console.log('Photo output error code: ' + photoOutputError.code);
})
```

## FrameShutterInfo

快门事件信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   | 必填 | 说明                          |
| --------- | ------ | ---- | ----------------------------- |
| captureId | number | 是   | CaptureId，本次拍摄动作的ID。 |
| timestamp | number | 是   | 时间戳。                      |

## CaptureEndInfo

拍照停止信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型   | 必填 | 说明                          |
| ---------- | ------ | ---- | ----------------------------- |
| captureId  | number | 是   | CaptureId，本次拍摄动作的ID。 |
| frameCount | number | 是   | 帧计数。                      |

## PhotoOutputErrorCode

枚举，拍照输出的错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | ---------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

##  PhotoOutputError

拍照输出错误对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                  | 说明                    |
| ---- | ------------------------------------- | ----------------------- |
| code | [PhotoOutputError](#photooutputerror) | PhotoOutput中的错误码。 |

## camera.createVideoOutput

createVideoOutput(surfaceId: string, callback: AsyncCallback<VideoOutput\>): void

获取VideoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型                                        | 必填 | 说明                                |
| --------- | ------------------------------------------- | ---- | ----------------------------------- |
| surfaceId | string                                      | 是   | 从VideoRecorder获取的Surface ID。   |
| callback  | AsyncCallback<[VideoOutput](#videooutput)\> | 是   | 回调函数，用于获取VideoOutput实例。 |

**示例：**

```js
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

获取VideoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称      | 类型   | 必填 | 说明                              |
| --------- | ------ | ---- | --------------------------------- |
| surfaceId | string | 是   | 从VideoRecorder获取的Surface ID。 |

**返回值：**

| 类型                                  | 说明                                   |
| ------------------------------------- | -------------------------------------- |
| Promise<[VideoOutput](#videooutput)\> | 使用Promise的方式获取VideoOutput实例。 |

**示例：**

```js
camera.createVideoOutput("surfaceId"
).then((videoOutput) => {
    console.log('Promise returned with the VideoOutput instance');
})
```

## VideoOutput

视频输出类。

### start

start(callback: AsyncCallback<void\>): void

开始拍摄视频，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

开始拍摄视频，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
```

### stop

stop(callback: AsyncCallback<void\>): void

停止拍摄视频，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

停止拍摄视频，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
})
```

### release

release(callback: AsyncCallback<void\>): void

释放VideoOutput实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
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

释放VideoOutput实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                        |
| -------------- | --------------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the VideoOutput instance is released successfully.');
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

监听视频帧开启，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                                             |
| :------- | :------------------- | :--- | :----------------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，即视频帧开启事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                         |

**示例：**

```js
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

监听视频帧结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                 | 必填 | 说明                                           |
| :------- | :------------------- | :--- | :--------------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，即视频帧结束事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                       |

**示例：**

```js
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<VideoOutputError\>): void

监听视频输出的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 名称     | 类型                                             | 必填 | 说明                                          |
| :------- | :----------------------------------------------- | :--- | :-------------------------------------------- |
| type     | string                                           | 是   | 监听事件，固定为'error'，即视频输出错误事件。 |
| callback | Callback<[VideoOutputError](#videooutputerror)\> | 是   | 回调函数，用于获取错误信息。                  |

**示例：**

```js
videoOutput.on('error', (VideoOutputError) => {
    console.log('Video output error code: ' + VideoOutputError.code);
})
```

## VideoOutputErrorCode

枚举，视频输出的错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | ---------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

##  VideoOutputError

视频输出错误对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                  | 说明                    |
| ---- | ------------------------------------- | ----------------------- |
| code | [PhotoOutputError](#photooutputerror) | VideoOutput中的错误码。 |