# @ohos.multimedia.camera (相机管理)

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```js
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

获取相机管理器实例，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](js-apis-inner-app-context.md)      | 是   | 应用上下文。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](#cameramanager)           | 相机管理器。                   |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```js
let cameraManager = camera.getCameraManager(context);
```

## CameraStatus

枚举，相机状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | 新的相机出现。   |
| CAMERA_STATUS_DISAPPEAR   | 1    | 相机被移除。     |
| CAMERA_STATUS_AVAILABLE   | 2    | 相机可用。       |
| CAMERA_STATUS_UNAVAILABLE | 3    | 相机不可用。     |

## Profile

相机配置信息项。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| format   | [CameraFormat](#cameraformat) | 是  | 输出格式。      |
| size     | [Size](#size)                 | 是  | 分辨率。       |

## FrameRateRange

帧率范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- |---- | ------------- |
| min      | number                        | 是  | 最小帧率。      |
| max      | number                        | 是  | 最大帧率。      |

## VideoProfile

视频配置信息项。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 类型                                      | 必填 | 说明        |
| ------------------------- | ----------------------------------------- | --- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | 是  | 帧率范围。   |

## CameraOutputCapability

相机输出能力项。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 类型                                               | 必填 | 说明                |
| ----------------------------- | -------------------------------------------------- | --- |------------------- |
| previewProfiles               | Array<[Profile](#profile)\>                        | 是  | 支持的预览配置信息。    |
| photoProfiles                 | Array<[Profile](#profile)\>                        | 是  | 支持的拍照配置信息。    |
| videoProfiles                 | Array<[VideoProfile](#videoprofile)\>              | 是  | 支持的录像配置信息。    |
| supportedMetadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | 是  | 支持的metadata流类型信息。|

## CameraErrorCode

相机错误码。接口使用不正确以及on接口监听error状态返回。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| INVALID_ARGUMENT       | 7400101    | 参数缺失或者参数类型不对。   |
| OPERATION_NOT_ALLOWED    | 7400102    | 操作流程不对，不允许。     |
| SESSION_NOT_CONFIG    | 7400103    | session 未配置返回。       |
| SESSION_NOT_RUNNING  | 7400104    | session 未运行返回。    |
| SESSION_CONFIG_LOCKED  | 7400105    | session 配置已锁定返回。     |
| DEVICE_SETTING_LOCKED  | 7400106    | 设备设置已锁定返回。     |
| CONFILICT_CAMERA  | 7400107    | 设备重复打开返回。     |
| DEVICE_DISABLED  | 7400108    | 安全原因摄像头被禁用。     |
| SERVICE_FATAL_ERROR  | 7400201    | 相机服务错误返回。     |

## CameraManager

相机管理器类，使用前需要通过getCameraManager获取相机管理实例。

### getSupportedCameras

getSupportedCameras(): Array<CameraDevice\>

获取支持指定的相机设备对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array<[CameraDevice](#cameradevice)>            | 相机设备列表。                   |

**示例：**

```js
let cameras = cameraManager.getSupportedCameras();

```

### getSupportedOutputCapability

getSupportedOutputCapability(cameraDevice:CameraDevice): CameraOutputCapability

查询相机设备在模式下支持的输出能力，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | 是 | 相机设备，通过 getSupportedCameras 接口获取       |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | 相机输出能力。                   |

**示例：**

```js
let cameraDevice = cameras[0];
let cameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);

```

### isCameraMuted

isCameraMuted(): boolean

查询相机当前的禁用状态（禁用/未禁用）。

在此之前，需要通过[isCameraMuteSupported](#iscameramutesupported)确认当前设备支持禁用相机。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                                         |
| ---------- | -------------------------------------------- |
| boolean    | 返回true表示相机被禁用，返回false表示相机未被禁用。 |

**示例：**

```js
let ismuted = cameraManager.isCameraMuted();
```

### isCameraMuteSupported

isCameraMuteSupported(): boolean

查询当前设备是否支持禁用相机，通过返回值返回结果。

此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示相机可以被禁用，返回false表示相机不能被禁用。 |

**示例：**

```js
let ismutesuppotred = cameraManager.isCameraMuteSupported();
```

### muteCamera

muteCamera(mute: boolean): void

禁用相机。

此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                              | 必填  | 说明        |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  是  |  禁用相机。  |

**示例：**

```js
let mute = true;
cameraManager.muteCamera(mute);
```

### createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

使用CameraDevice对象创建CameraInput实例，同步返回结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| cameraDevice   | [CameraDevice](#cameradevice)         | 是   | CameraDevice对象，通过 getSupportedCameras 接口获取   |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let cameraDevice = cameras[0];
let cameraInput;
try {
	cameraInput = cameraManager.createCameraInput(cameraDevice);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType): CameraInput

根据相机位置和类型创建CameraInput实例，同步返回结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](#cameraposition)           | 是   | 相机位置，通过 getSupportedCameras 接口获取设备，然后获取设备位置信息  |
| type     | [CameraType](#cameratype)                   | 是   | 相机类型，通过 getSupportedCameras 接口获取设备，然后获取设备类型信息  |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let cameraDevice = cameras[0];
let position = cameraDevice.cameraPosition;
let type = cameraDevice.cameraType;
let cameraInput;
try {
    cameraInput = cameraManager.createCameraInput(position, type);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput

创建预览输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                              |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | 是   | 支持的预览配置信息,通过getSupportedOutputCapability接口获取。|
| surfaceId| string | 是   | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)或者[ImageReceiver](js-apis-image.md#imagereceiver9)组件获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | PreviewOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let profile = cameraOutputCapability.previewProfiles[0];
let previewOutput;
try {
    previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

创建拍照输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | 是   | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。|
| surfaceId| string            | 是   | 从[ImageReceiver](js-apis-image.md#imagereceiver9)获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | PhotoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let profile = cameraOutputCapability.photoProfiles[0];
let photoOutput;
try {
    photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): VideoOutput

创建录像输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                              |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](#videoprofile)               | 是   | 支持的录像配置信息，通过getSupportedOutputCapability接口获取。 |
| surfaceId| string          | 是   | 从[VideoRecorder](js-apis-media.md#videorecorder9)获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | VideoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let profile = cameraOutputCapability.videoProfiles[0];
let videoOutput;
try {
    videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>): MetadataOutput

创建metadata流输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [MetadataOutput](#metadataoutput)   | MetadataOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |

**示例：**

```js
let metadataObjectTypes = cameraOutputCapability.supportedMetadataObjectTypes;
let metadataOutput;
try {
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### createCaptureSession

createCaptureSession(): CaptureSession

创建CaptureSession实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CaptureSession](#capturesession)   | CaptureSession实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**示例：**

```js
let captureSession;
try {
    captureSession = cameraManager.createCaptureSession();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

相机设备状态回调，通过注册回调函数获取相机的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型            | 必填 | 说明       |
| -------- | -----------------| ---- | --------- |
| type     | string           | 是   | 监听事件，固定为'cameraStatus'。cameraManager对象获取成功后可监听。目前只支持对设备打开或者关闭会触发该事件并返回对应信息 |
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | 是   | 回调函数，用于获取镜头状态变化信息。 |                 |

**示例：**

```js
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.log(`status: ${cameraStatusInfo.status}`);
})
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback<boolean\>): void

禁用回调，通过注册回调函数获取相机禁用状态变化。

此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。系统设置打开或禁用相机会触发该事件并返回状态 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，用于获取禁用状态变化信息，返回true是开启状态，返回false是禁用状态。               |

**示例：**

```js
cameraManager.on('cameraMute', (curMuetd) => {
    let isMuted = curMuetd;
})
```

## CameraStatusInfo

相机管理器回调返回的接口实例，表示相机状态信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| camera | [CameraDevice](#cameradevice) |        是       | 相机信息。 |
| status | [CameraStatus](#camerastatus) |        是        | 相机状态。 |

## CameraPosition

枚举，相机位置。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值   | 说明            |
| --------------------------- | ---- | -------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | 相机位置未指定。  |
| CAMERA_POSITION_BACK        | 1    | 后置相机。       |
| CAMERA_POSITION_FRONT       | 2    | 前置相机。       |

## CameraType

枚举，相机类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值   | 说明            |
| ----------------------- | ---- | -------------- |
| CAMERA_TYPE_DEFAULT     | 0    | 相机类型未指定。  |
| CAMERA_TYPE_WIDE_ANGLE  | 1    | 广角相机。       |
| CAMERA_TYPE_ULTRA_WIDE  | 2    | 超广角相机。     |
| CAMERA_TYPE_TELEPHOTO   | 3    | 长焦相机。       |
| CAMERA_TYPE_TRUE_DEPTH  | 4    | 带景深信息的相机。 |

## ConnectionType

枚举，相机连接类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值   | 说明           |
| ---------------------------- | ---- | ------------- |
| CAMERA_CONNECTION_BUILT_IN   | 0    | 内置相机。      |
| CAMERA_CONNECTION_USB_PLUGIN | 1    | USB连接的相机。 |
| CAMERA_CONNECTION_REMOTE     | 2    | 远程连接的相机。 |

## CameraDevice

相机设备信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称           | 类型                                | 必填 | 说明        |
| -------------- | --------------------------------- | ---- | ---------- |
| cameraId       | string                            | 是   | CameraDevice对象|
| cameraPosition | [CameraPosition](#cameraposition) | 是   | 相机位置。    |
| cameraType     | [CameraType](#cameratype)         | 是   | 相机类型。    |
| connectionType | [ConnectionType](#connectiontype) | 是   | 相机连接类型。 |

## Size

枚举，输出能力查询。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型   | 可读 | 可写 | 说明         |
| ------ | ------ | ---- | ---- | ------------ |
| height | number | 是   | 是   | 图像尺寸高(像素)。 |
| width  | number | 是   | 是   | 图像尺寸宽(像素)。 |

## Point

枚举，点坐标用于对焦、曝光配置。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型   | 必填   | 说明         |
| ------ | ------ | ---- | ------------ |
| x      | number | 是    | 点的x坐标。   |
| y      | number | 是    | 点的y坐标。   |

## CameraFormat

枚举，输出格式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_RGBA_8888 | 3         | RGB格式的图片。             |
| CAMERA_FORMAT_YUV_420_SP| 1003      | YUV 420 SP格式的图片。      |
| CAMERA_FORMAT_JPEG      | 2000      | JPEG格式的图片。            |

## CameraInput

会话中[CaptureSession](#capturesession)使用的相机信息。

### open

open\(callback: AsyncCallback<void\>\): void

打开相机，通过注册回调函数获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                  | 必填 | 说明                  |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

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

打开相机，通过Promise获取相机的状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```js
cameraInput.open().then(() => {
    console.log('Promise returned with camera opened.');
}).catch((err) => {
    console.error(`Failed to open the camera. ${err.code}`);
});
```

### close

close\(callback: AsyncCallback<void\>\): void

关闭相机，通过注册回调函数获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

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

关闭相机，通过Promise获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```js
cameraInput.close().then(() => {
    console.log('Promise returned with camera closed.');
}).catch((err) => {
    console.error(`Failed to close the cameras. ${err.code}`);
});
```

### on('error')

on(type: 'error', cameraDevice:CameraDevice, callback: ErrorCallback<BusinessError\>): void

监听CameraInput的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'error'，CameraInput对象创建成功可监听。相机设备出错情况下可触发该事件并返回结果，比如（设备不可用或者冲突等返回对应错误信息） |
| cameraDevice   | [CameraDevice](#cameradevice)    | 是   | CameraDevice对象。 |
| callback | ErrorCallback<BusinessError\> | 是   | 回调函数，用于获取结果。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)   |

**示例：**

```js
let cameraDevice = cameras[0];
cameraInput.on('error', cameraDevice, (error) => {
    console.log(`Camera input error code: ${error.code}`);
})
```

## FlashMode

枚举，闪光灯模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                    | 值   | 说明        |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | 闪光灯关闭。 |
| FLASH_MODE_OPEN        | 1    | 闪光灯打开。 |
| FLASH_MODE_AUTO        | 2    | 自动闪光灯。 |
| FLASH_MODE_ALWAYS_OPEN | 3    | 闪光灯常亮。 |

## ExposureMode

枚举，曝光模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | 锁定曝光模式。 |
| EXPOSURE_MODE_AUTO            | 1    | 自动曝光模式。 |
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | 连续自动曝光。 |

 ## FocusMode

枚举，焦距模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                        | 值   | 说明          |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | 手动对焦。     |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | 连续自动对焦。 |
| FOCUS_MODE_AUTO            | 2    | 自动对焦。     |
| FOCUS_MODE_LOCKED          | 3    | 对焦锁定。     |

## FocusState

枚举，焦距状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                   | 值   | 说明       |
| --------------------- | ---- | --------- |
| FOCUS_STATE_SCAN      | 0    | 触发对焦。  |
| FOCUS_STATE_FOCUSED   | 1    | 对焦成功。  |
| FOCUS_STATE_UNFOCUSED | 2    | 未完成对焦。 |

## VideoStabilizationMode

枚举，视频防抖模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称       | 值   | 说明         |
| --------- | ---- | ------------ |
| OFF       | 0    | 关闭视频防抖功能。   |
| LOW       | 1    | 使用基础防抖算法。   |
| MIDDLE    | 2    | 使用防抖效果一般的防抖算法，防抖效果优于LOW类型。   |
| HIGH      | 3    | 使用防抖效果最好的防抖算法，防抖效果优于MIDDLE类型。   |
| AUTO      | 4    | 自动进行选择。   |

## CaptureSession

拍照会话类，保存一次相机运行所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)，并向相机设备申请完成相机功能(录像，拍照)。

### beginConfig

beginConfig(): void

开始配置会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400105                |  Session config locked.               |

**示例：**

```js
try {
    captureSession.beginConfig();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### commitConfig

commitConfig(callback: AsyncCallback<void\>): void

提交配置信息，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

提交配置信息，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                      |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
}).catch((err) => {
    // 失败返回错误码error.code并处理
    console.log('Failed to commitConfig '+ err.code);
});
```

### addInput

addInput(cameraInput: CameraInput): void

把[CameraInput](#camerainput)加入到会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**示例：**

```js
try {
    captureSession.addInput(cameraInput);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### removeInput

removeInput(cameraInput: CameraInput): void

移除[CameraInput](#camerainput)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                      |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**示例：**

```js
try {
    captureSession.removeInput(cameraInput);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### addOutput

addOutput(previewOutput: CameraOutput): void

把[CameraOutput](#cameraoutput)加入到会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要添加的previewoutput实例。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**示例：**

```js
try {
    captureSession.addOutput(previewOutput);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### removeOutput

removeOutput(previewOutput: CameraOutput): void

从会话中移除[CameraOutput](#cameraoutput)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要移除的previewoutput实例。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400102                |  Operation not allow.                                  |

**示例：**

```js
try {
    captureSession.removeOutput(previewOutput);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### start

start\(callback: AsyncCallback<void\>\): void

开始会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

开始会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
}).catch((err) => {
    console.error(`Failed to start the session ${err.code}`);
});
```

### stop

stop\(callback: AsyncCallback<void\>\): void

停止会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

停止会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
}).catch((err) => {
    console.error(`Failed to stop the session ${err.code}`);
});
```

### release

release\(callback: AsyncCallback<void\>\): void

释放会话资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

释放会话资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
}).catch((err) => {
    console.error(`Failed to release the CaptureSession instance ${err.code}`);
});
```

### hasFlash

hasFlash(): boolean

检测是否有闪光灯，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示设备支持闪光灯。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let status = captureSession.hasFlash();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode): boolean

检测闪光灯模式是否支持。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                               |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。                     |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示支持该闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setFlashMode

setFlashMode(flashMode: FlashMode): void

设置闪光灯模式。

进行设置之前，需要先检查：

1. 设备是否支持闪光灯，可使用方法[hasFlash](#hasflash)。
2. 设备是否支持指定的闪光灯模式，可使用方法[isFlashModeSupported](#isflashmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                  |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。       |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getFlashMode

getFlashMode(): FlashMode

获取当前设备的闪光灯模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | 获取当前设备的闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let flashMode = captureSession.getFlashMode();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): boolean;

检测曝光模式是否支持。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                      |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 获取是否支持曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getExposureMode

getExposureMode(): ExposureMode

获取当前曝光模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | 获取当前曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let exposureMode = captureSession.getExposureMode();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setExposureMode

setExposureMode(aeMode: ExposureMode): void

设置曝光模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getMeteringPoint

getMeteringPoint(): Point

查询曝光区域中心点。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](#point)    | 获取当前曝光点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let exposurePoint = captureSession.getMeteringPoint();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setMeteringPoint

setMeteringPoint(point: Point): void

设置曝光区域中心点。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | 是   | 曝光点。              |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
const exposurePoint = {x: 1, y: 1};
try {
    captureSession.setMeteringPoint(exposurePoint);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getExposureBiasRange

getExposureBiasRange(): Array<number\>

查询曝光补偿范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array<number\>   | 获取补偿范围的数组。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let biasRangeArray = captureSession.getExposureBiasRange();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setExposureBias

setExposureBias(exposureBias: number): void

设置曝光补偿。

进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrange)查询支持的范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                 |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | 是   | 曝光补偿,getExposureBiasRange查询支持的范围,接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
let exposureBias = biasRangeArray[0];
try {
    captureSession.setExposureBias(exposureBias);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getExposureValue

getExposureValue(): number

查询当前曝光值。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取曝光值。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let exposureValue = captureSession.getExposureValue();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode): boolean

检测对焦模式是否支持。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                              |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。                    |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示支持该焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setFocusMode

setFocusMode(afMode: FocusMode): void

设置对焦模式。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。       |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getFocusMode

getFocusMode(): FocusMode

获取当前的对焦模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | 获取当前设备的焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let afMode = captureSession.getFocusMode();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setFocusPoint

setFocusPoint(point: Point): void

设置焦点。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| Point1    | [Point](#point)         | 是   | 焦点。                |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
const Point1 = {x: 1, y: 1};
try {
    captureSession.setFocusPoint(Point1);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getFocusPoint

getFocusPoint(): Point

查询焦点。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](#point)    | 用于获取当前焦点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let point = captureSession.getFocusPoint();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getFocalLength

getFocalLength(): number

查询焦距值。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 用于获取当前焦距。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let focalLength = captureSession.getFocalLength();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getZoomRatioRange

getZoomRatioRange(): Array<number\>

获取支持的变焦范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array<number\>   | 用于获取可变焦距比范围，返回的数组包括其最小值和最大值。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let zoomRatioRange = captureSession.getZoomRatioRange();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setZoomRatio

setZoomRatio(zoomRatio: number): void

设置变焦比。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                  | 必填 | 说明                 |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | 是   | 可变焦距比,通过getZoomRatioRange获取支持的变焦范围 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
let zoomRatio = zoomRatioRange[0];
try {
    captureSession.setZoomRatio(zoomRatio);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getZoomRatio

getZoomRatio(): number

获取当前的变焦比。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取当前的变焦比结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let zoomRatio = captureSession.getZoomRatio();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

查询是否支持指定的视频防抖模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                             |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | 是   | 视频防抖模式。                    |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回视频防抖模式是否支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(): VideoStabilizationMode

查询当前正在使用的视频防抖模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| VideoStabilizationMode    | 视频防抖是否正在使用。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    let vsMode = captureSession.getActiveVideoStabilizationMode();
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode): void

设置视频防抖模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | 是   | 需要设置的视频防抖模式。   |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraErrorCode](#cameraerrorcode)    | 接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
} catch (error) {
    // 失败返回错误码error.code并处理
    console.log(error.code);
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session 创建成功可监听。仅当自动对焦模式时,且相机对焦状态发生改变时可触发该事件 |
| callback | AsyncCallback<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```js
captureSession.on('focusStateChange', (focusState) => {
    console.log(`Focus state  : ${focusState}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

监听拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（beginConfig()，commitConfig()，addInput）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback<BusinessError\> | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)        |

**示例：**

```js
captureSession.on('error', (error) => {
    console.log(`Capture session error code: ${error.code}`);
})
```

## CameraOutput

会话中[CaptureSession](#capturesession)使用的输出信息，output的基类。

## PreviewOutput

预览输出类。继承[CameraOutput](#cameraoutput)

### start

start(callback: AsyncCallback<void\>): void

开始输出预览流，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

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

开始输出预览流，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)|

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```js
previewOutput.start().then(() => {
    console.log('Promise returned with previewOutput started.');
}).catch((err) => {
    console.log('Failed to previewOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

停止输出预览流，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

停止输出预览流，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
previewOutput.stop().then(() => {
    console.log('Callback returned with previewOutput stopped.');
}).catch((err) => {
    console.log('Failed to previewOutput stop '+ err.code);
});
```

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

释放输出资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
previewOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to previewOutput release '+ err.code);
});
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

监听预览帧启动，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                     |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，previewOutput创建成功可监听。底层第一次开始曝光时触发该事件并返回 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明预览开始                     |

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

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，previewOutput创建成功可监听。预览完全结束最后一帧时触发该事件并返回， |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明预览结束                 |

**示例：**

```js
previewOutput.on('frameEnd', () => {
    console.log('Preview frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

监听预览输出的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | 是   | 监听事件，固定为'error'，previewOutput创建成功可监听。预览接口使用错误时触发该事件，比如调用（start（），release（））等接口发生错误时返回对应错误信息。|
| callback | ErrorCallback<BusinessError\> | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)  |

**示例：**

```js
previewOutput.on('error', (previewOutputError) => {
    console.log(`Preview output error code: ${previewOutputError.code}`);
})
```

## ImageRotation

枚举，图片旋转角度。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明           |
| ------------ | ---- | ------------- |
| ROTATION_0   | 0    | 图片旋转0度。   |
| ROTATION_90  | 90   | 图片旋转90度。  |
| ROTATION_180 | 180  | 图片旋转180度。 |
| ROTATION_270 | 270  | 图片旋转270度。 |

## Location

图片地理位置信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 类型   | 必填 |说明         |
| ------------ | ------ | --- |------------ |
| latitude     | number | 是  |纬度(度)。    |
| longitude    | number | 是  |经度(度)。    |
| altitude     | number | 是  |海拔(米)。    |

## QualityLevel

枚举，图片质量。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                  | 值   | 说明         |
| -------------------- | ---- | ------------ |
| QUALITY_LEVEL_HIGH   | 0    | 图片质量高。   |
| QUALITY_LEVEL_MEDIUM | 1    | 图片质量中等。 |
| QUALITY_LEVEL_LOW    | 2    | 图片质量差。   |


## PhotoCaptureSetting

拍摄照片的设置。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                            | 必填  | 说明              |
| -------- | ------------------------------- | ---- | -----------------|
| quality  | [QualityLevel](#qualitylevel)   | 否   | 图片质量。         |
| rotation | [ImageRotation](#imagerotation) | 否   | 图片旋转角度。      |
| location | [Location](#location)           | 否   | 图片地理位置信息。   |
| mirror   | boolean                         | 否   |镜像使能开关(默认关)。 |

## PhotoOutput

拍照会话中使用的输出信息，继承[CameraOutput](#cameraoutput)

### capture

capture(callback: AsyncCallback<void\>): void

以默认设置触发一次拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

以默认设置触发一次拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
}).catch((err) => {
    console.log('Failed to photoOutput capture '+ err.code);
});
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback<void\>): void

以指定参数触发一次拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                  |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | 是   | 拍照设置。             |
| callback | AsyncCallback<void\>                        | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)  |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

以指定参数触发一次拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明      |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | 否   | 拍照设置。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
photoOutput.capture(settings).then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
}).catch((err) => {
    console.log('Failed to photoOutput capture '+ err.code);
});
```

### isMirrorSupported

isMirrorSupported(): boolean

查询是否支持镜像拍照。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 返回是否支持镜像拍照。 |

**示例：**

```js
let isSupported = photoOutput.isMirrorSupported();
```

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

释放输出资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to photoOutput release '+ err.code);
});
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

监听拍照开始，通过注册回调函数获取Capture ID。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'captureStart'，photoOutput创建成功后可监听。每次拍照，底层开始曝光时触发该事件并返回。 |
| callback | AsyncCallback<number\> | 是   | 使用callback的方式获取Capture ID。            |

**示例：**

```js
photoOutput.on('captureStart', (captureId) => {
    console.log(`photo capture stated, captureId : ${captureId}`);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

监听拍照帧输出捕获，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'frameShutter'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback<[FrameShutterInfo](#frameshutterinfo)\> | 是   | 回调函数，用于获取相关信息。该回调返回意味着可以再次下发拍照请求。             |

**示例：**

```js
photoOutput.on('frameShutter', (frameShutterInfo) => {
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

监听拍照结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型           | 必填 | 说明                                       |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | 是   | 监听事件，固定为'captureEnd'，photoOutput创建成功后可监听。拍照完全结束可触发该事件发生并返回相应信息。 |
| callback | AsyncCallback<[CaptureEndInfo](#captureendinfo)\> | 是   | 回调函数，用于获取相关信息。                  |

**示例：**

```js
photoOutput.on('captureEnd', (captureEndInfo) => {
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.log(`frameCount : ${captureEndInfo.frameCount}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

监听拍照输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | 是   | 监听事件，固定为'error'，photoOutput创建成功后可监听。拍照接口调用时出现错误触发该事件并返回错误信息。 |
| callback | ErrorCallback<BusinessError\> | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)             |

**示例：**

```js
photoOutput.on('error', (error) => {
    console.log(`Photo output error code: ${error.code}`);
})
```

## FrameShutterInfo

拍照帧输出信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ---------- |
| captureId | number | 是   | 拍照的ID。  |
| timestamp | number | 是   | 快门时间戳。 |

## CaptureEndInfo

拍照停止信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------|
| captureId  | number | 是   | 拍照的ID。 |
| frameCount | number | 是   | 帧数。    |

## VideoOutput

录像会话中使用的输出信息，继承[CameraOutput](#cameraoutput)

### start

start(callback: AsyncCallback<void\>): void

启动录制，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

启动录制，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
}).catch((err) => {
    console.log('Failed to videoOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

结束录制，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

结束录制，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
videoOutput.stop().then(() => {
    console.log('Promise returned to indicate that stop method execution success.');
}).catch((err) => {
    console.log('Failed to videoOutput stop '+ err.code);
});
```

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

释放输出资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
}).catch((err) => {
    console.log('Failed to videoOutput release '+ err.code);
});
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

监听录像开始，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始                     |

**示例：**

```js
videoOutput.on('frameStart', () => {
    console.log('Video frame started');
})
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback<void\>): void

监听录像结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回  。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束                      |

**示例：**

```js
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

监听录像输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型       | 必填 | 说明                                    |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | 是   | 监听事件，固定为'error'，videoOutput创建成功后可监听。录像接口调用出现错误时触发该事件并返回对应错误码,比如调用（start(),release()）接口时出现错误返回对应错误信息。 |
| callback | Callback<BusinessError\> | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)                 |

**示例：**

```js
videoOutput.on('error', (error) => {
    console.log(`Video output error code: ${error.code}`);
})
```

## MetadataOutput

metadata流。继承[CameraOutput](#cameraoutput)

### start

start(callback: AsyncCallback<void\>): void

开始输出metadata，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>       | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

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

开始输出metadata，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                     | 说明                     |
| ----------------------  | ------------------------ |
| Promise<void\>          | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见相机错误码

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```js
metadataOutput.start().then(() => {
    console.log('Callback returned with metadataOutput started.');
}).catch((err) => {
    console.log('Failed to metadataOutput start '+ err.code);
});
```

### stop

stop(callback: AsyncCallback<void\>): void

停止输出metadata，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                         | 必填 | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>       | 是   | 回调函数，用于获取结果。 |

**示例：**

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

停止输出metadata，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                    | 说明                        |
| ----------------------  | --------------------------- |
| Promise<void\>         | 使用Promise的方式获取结果。 |

**示例：**

```js
metadataOutput.stop().then(() => {
    console.log('Callback returned with metadataOutput stopped.');
}).catch((err) => {
    console.log('Failed to metadataOutput stop '+ err.code);
});
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback<Array<MetadataObject\>\>): void

监听检测到的metadata对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型         | 必填 | 说明                                  |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | 是   | 监听事件，固定为'metadataObjectsAvailable'，metadataOutput创建成功后可监听。检测到有效的metadata数据时触发该事件发生并返回相应的metadata数据 |
| callback | Callback<Array<[MetadataObject](#metadataobject)\>\> | 是   | 回调函数，用于获取metadata数据。 |

**示例：**

```js
metadataOutput.on('metadataObjectsAvailable', (metadataObjectArr) => {
    console.log(`metadata output metadataObjectsAvailable`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<BusinessError\>): void

监听metadata流的错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                     |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 监听事件，固定为'error'，metadataOutput创建成功后可监听。metadata接口使用错误时触发该事件并返回对应错误码，比如调用（start（），release（））接口时发生错误返回对应错误信息。 |
| callback | Callback<BusinessError\> | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)            |

**示例：**

```js
metadataOutput.on('error', (metadataOutputError) => {
    console.log(`Metadata output error code: ${metadataOutputError.code}`);
})
```

## MetadataObjectType

枚举，metadata流。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | metadata对象类型,人脸检测。 |

## Rect

矩形定义。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   |      必填     |           说明                 |
| -------- | ------ | --------------- | -------------------- |
| topLeftX | number |        是          | 矩形区域左上角x坐标。   |
| topLeftY | number |         是          | 矩形区域左上角y坐标。   |
| width    | number |         是         | 矩形宽。              |
| height   | number |         是           |矩形高。              |

## MetadataObject

相机元能力信息，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.on('metadataObjectsAvailable')接口获取

| 名称      | 类型                            | 必填  | 说明              |
| -------- | ------------------------------- | ---- | -----------------|
| type  | [MetadataObjectType](#metadataobjecttype)   | 否   | metadata 类型，目前只有人脸识别。 |
| timestamp | number | 否   | 当前时间戳（毫秒）。 |
| boundingBox | [Rect](#rect)           | 否   | metadata 区域框 |