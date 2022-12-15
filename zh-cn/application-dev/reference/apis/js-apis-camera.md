# @ohos.multimedia.camera (相机管理)

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

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](js-apis-inner-app-context.md)      | 是   | 应用上下文。                   |
| callback | AsyncCallback<[CameraManager](#cameramanager)\> | 是   | 回调函数，用于获取相机管理器实例。 |

**示例：**

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

获取相机管理器实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型    | 必填 | 说明         |
| ------- | ------- | ---- | ------------ |
| context | [Context](js-apis-inner-app-context.md) | 是   | 应用上下文。 |

**返回值：**

| 类型                                      | 说明                                  |
| ----------------------------------------- | ----------------------------------- |
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
| CAMERA_STATUS_APPEAR      | 0    | 新的相机出现。   |
| CAMERA_STATUS_DISAPPEAR   | 1    | 相机被移除。 |
| CAMERA_STATUS_AVAILABLE   | 2    | 相机可用。   |
| CAMERA_STATUS_UNAVAILABLE | 3    | 相机不可用。 |

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

## CameraManager

相机管理器类，使用前需要通过getCameraManager获取相机管理实例。

### getSupportedCameras

getSupportedCameras(callback: AsyncCallback<Array<CameraDevice\>\>): void

获取支持指定的相机设备对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                   | 必填 | 说明                             |
| -------- | ----------------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback<Array<[CameraDevice](#cameradevice)\>\> | 是   | 使用callback方式获取支持的相机列表。 |

**示例：**

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

获取支持指定的相机设备对象，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                       |
| ----------------------------------------------- | ------------------------- |
| Promise<Array<[CameraDevice](#cameradevice)\>\> | 使用promise获取支持相机列表。 |


**示例：**

```js
cameraManager.getSupportedCameras().then((cameras) => {
    console.log(`Promise returned with an array of supported cameras: ${cameras.length}`);
})
```

### getSupportedOutputCapability

getSupportedOutputCapability(camera:CameraDevice, callback: AsyncCallback<CameraOutputCapability\>): void

查询相机设备在模式下支持的输出能力，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | 是 | 相机设备，通过 getSupportedCameras 接口获取       |
| callback     | AsyncCallback<[CameraOutputCapability](#cameraoutputcapability)\> | 是 | 使用callback方式获取相机输出能力。 |

**示例：**

```js
cameraManager.getSupportedCameras().then((cameras) => {
    let cameraDevice = cameras[0];
    cameraManager.getSupportedOutputCapability(cameraDevice, (err, CameraOutputCapability) => {
        if (err) {
            console.error(`Failed to get the outputCapability. ${err.message}`);
            return;
        }
        console.log('Callback returned with an array of supported outputCapability');
    })
})
```

### getSupportedOutputCapability

getSupportedOutputCapability(camera:CameraDevice): Promise<CameraOutputCapability\>

查询相机设备在模式下支持的输出能力，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                              | 必填  | 说明        |
| -------- | --------------------------------- | ---- | ---------- |
| cameradevice   | [CameraDevice](#cameradevice)     |  是  | 相机设备，通过 getSupportedCameras 接口获取   |

**返回值：**

| 类型                                                            | 说明                          |
| -------------------------------------------------------------- | ----------------------------- |
| Promise<[CameraOutputCapability](#cameraoutputcapability)\>    | 使用Promise的方式获取结果，返回相机输出能力。 |

**示例：**

```js
cameraManager.getSupportedCameras().then((cameras) => {
    let cameraDevice = cameras[0];
    cameraManager.getSupportedOutputCapability(cameraDevice).then((cameraoutputcapability) => {
        console.log('Promise returned with an array of supported outputCapability');
    })
})
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

createCameraInput(camera: CameraDevice, callback: AsyncCallback<CameraInput\>): void

使用CameraDevice对象异步创建CameraInput实例，通过注册回调函数获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| cameraDevice   | [CameraDevice](#cameradevice)               | 是   | CameraDevice对象，通过 getSupportedCameras 接口获取   |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | 是   | 回调函数，用于获取CameraInput实例。    |

**示例：**

```js
let cameraDevice = cameras[0];
cameraManager.createCameraInput(cameraDevice, (err, cameraInput) => {
    if (err) {
        console.error(`Failed to create the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback returned with the CameraInput instance.');
})
```

### createCameraInput

createCameraInput(cameraDevice: CameraDevice): Promise<CameraInput\>

使用CameraDevice对象异步创建CameraInput实例，通过Promise获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                           | 必填 | 说明         |
| -------- | ----------------------------- | ---- | ---------- |
| cameraDevice   | [CameraDevice](#cameradevice) | 是   | CameraDevice对象，通过 getSupportedCameras 接口获取 |

**返回值：**

| 类型                                  | 说明                                   |
| ------------------------------------- | ------------------------------------ |
| Promise<[CameraInput](#camerainput)\> | 使用Promise的方式获取CameraInput的实例。 |

**示例：**

```js
let cameraDevice = cameras[0];
cameraManager.createCameraInput(cameraDevice).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type: CameraType, callback: AsyncCallback<CameraInput\>): void

根据相机位置和类型创建CameraInput实例，通过注册回调函数获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| position | [CameraPosition](#cameraposition)           | 是   | 相机位置，通过 getSupportedCameras 接口获取设备，然后获取设备位置信息  |
| type     | [CameraType](#cameratype)                   | 是   | 相机类型，通过 getSupportedCameras 接口获取设备，然后获取设备类型信息  |
| callback | AsyncCallback<[CameraInput](#camerainput)\> | 是   | 回调函数，用于获取CameraInput实例。    |

**示例：**

```js
let cameraDevice = cameras[0];
let position = cameraDevice.cameraPosition;
let type = cameraDevice.cameraType;
cameraManager.createCameraInput(position, type, (err, cameraInput) => {
    if (err) {
        console.error(`Failed to create the CameraInput instance. ${err.message}`);
        return;
    }
    console.log('Callback returned with the CameraInput instance');
})
```

### createCameraInput

createCameraInput(position: CameraPosition, type:CameraType ): Promise<CameraInput\>

根据相机位置和类型创建CameraInput实例，通过Promise获取结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                               | 必填 | 说明           |
| -------- | --------------------------------- | ---- | ------------ |
| position | [CameraPosition](#cameraposition) | 是   | 相机位置，通过 getSupportedCameras 接口获取设备，然后获取设备位置信息     |
| type     | [CameraType](#cameratype)         | 是   | 相机类型，通过 getSupportedCameras 接口获取设备，然后获取设备类型信息     |

**返回值：**

| 类型                                  | 说明                                   |
| ------------------------------------- | ------------------------------------ |
| Promise<[CameraInput](#camerainput)\> | 使用Promise的方式获取CameraInput的实例。 |

**示例：**

```js
let cameraDevice = cameras[0];
let position = cameraDevice.cameraPosition;
let type = cameraDevice.cameraType;
cameraManager.createCameraInput(position, type).then((cameraInput) => {
    console.log('Promise returned with the CameraInput instance');
})
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PreviewOutput\>): void

创建预览输出对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                              |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | 是   | 支持的预览配置信息,通过getSupportedOutputCapability接口获取。|
| surfaceId| string | 是   | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)或者[ImageReceiver](js-apis-image.md#imagereceiver9)组件获取的surfaceId。|
| callback | AsyncCallback<[PreviewOutput](#previewoutput)\>  | 是   | 回调函数，用于获取PreviewOutput实例。|

**示例：**

```js
let profile = cameraoutputcapability.previewProfiles[0];
cameraManager.createPreviewOutput(profile, surfaceId, (err, previewOutput) => {
    if (err) {
        console.error(`Failed to gcreate previewOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with previewOutput created.');
})
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): Promise<PreviewOutput\>

创建预览输出对象，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                |
| -------- | ---------------------------------| ---- | ----------------- |
| profile  | [Profile](#profile)              | 是   | 支持的预览配置信息，通过getSupportedOutputCapability接口获取。|
| surfaceId| string | 是   | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)或者[ImageReceiver](js-apis-image.md#imagereceiver9)组件获取的surfaceId。 |

**返回值：**

| 类型                                      | 说明                                     |
| ---------------------------------------- | ---------------------------------------- |
| Promise<[PreviewOutput](#previewoutput)\> | 使用Promise的方式获取PreviewOutput的实例。  |

**示例：**

```js
let profile = cameraoutputcapability.previewProfiles[0];
cameraManager.createPreviewOutput(profile, surfaceId).then((previewOutput) => {
    console.log('Promise returned with previewOutput created.');
})
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string, callback: AsyncCallback<PhotoOutput\>): void

创建拍照输出对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | 是   | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。|
| surfaceId| string            | 是   | 从[ImageReceiver](js-apis-image.md#imagereceiver9)获取的surfaceId。|
| callback | AsyncCallback<[PhotoOutput](#photooutput)\>  | 是   | 回调函数，用于获取PhotoOutput实例。    |

**示例：**

```js
let profile = cameraoutputcapability.photoProfiles[0];
cameraManager.createPhotoOutput(profile, surfaceId, (err, photoOutput) => {
    if (err) {
        console.error(`Failed to create photoOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with photoOutput created.');
})
```

### createPhotoOutput

createPhotoOutput(profile: Profile, surfaceId: string): Promise<PhotoOutput\>

创建拍照输出对象，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                               | 必填 | 说明         |
| -------- | ---------------------------------| ---- | ----------- |
| profile  | [Profile](#profile)              | 是   | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。 |
| surfaceId| string       | 是   | 从[ImageReceiver](js-apis-image.md#imagereceiver9)获取的surfaceId。|

**返回值：**

| 类型                                  | 说明                                     |
| ------------------------------------- | -------------------------------------- |
| Promise<[PhotoOutput](#photooutput)\>  | 使用Promise的方式获取PhotoOutput的实例。  |

**示例：**

```js
let profile = cameraoutputcapability.photoProfiles[0];
cameraManager.createPhotoOutput(profile, surfaceId).then((photoOutput) => {
    console.log('Promise returned with photoOutput created.');
})
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string, callback: AsyncCallback<VideoOutput\>): void

创建录像输出对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                        | 必填 | 说明                              |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| profile  | [VideoProfile](#videoprofile)               | 是   | 支持的录像配置信息，通过getSupportedOutputCapability接口获取。 |
| surfaceId| string          | 是   | 从[VideoRecorder](js-apis-media.md#videorecorder9)获取的surfaceId。|
| callback | AsyncCallback<[VideoOutput](#videooutput)\>  | 是   | 回调函数，用于获取VideoOutput实例。 |

**示例：**

```js
let profile = cameraoutputcapability.videoProfiles[0];
cameraManager.createVideoOutput(profile, surfaceId, (err, videoOutput) => {
    if (err) {
        console.error(`Failed to create videoOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with an array of supported outputCapability' );
})
```

### createVideoOutput

createVideoOutput(profile: VideoProfile, surfaceId: string): Promise<VideoOutput\>

创建录像输出对象，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明         |
| -------- | ---------------------------------| ---- | ---------- |
| profile  | [VideoProfile](#videoprofile)    | 是   | 支持的录像配置信息，通过getSupportedOutputCapability接口获取。 |
| surfaceId| string        | 是   | 从[VideoRecorder](js-apis-media.md#videorecorder9)获取的surfaceId。|

**返回值：**

| 类型                                  | 说明                                     |
| ------------------------------------- | -------------------------------------- |
| Promise<[VideoOutput](#videooutput)\>  | 使用Promise的方式获取videoOutput的实例。  |

**示例：**

```js
let profile = cameraoutputcapability.videoProfiles[0];
cameraManager.createVideoOutput(profile, surfaceId).then((videoOutput) => {
    console.log('Promise returned with videoOutput created.');
})
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>, callback: AsyncCallback<MetadataOutput\>): void

创建metadata流输出对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |
| callback             | AsyncCallback<[MetadataOutput](#metadataoutput)\>  | 是   | 回调函数，用于获取MetadataOutput实例。    |

**示例：**

```js
let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
cameraManager.createMetadataOutput(metadataObjectTypes, (err, metadataOutput) => {
    if (err) {
        console.error(`Failed to create metadataOutput. ${err.message}`);
        return;
    }
    console.log('Callback returned with metadataOutput created.');
})
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes:Array<MetadataObjectType\>): Promise<MetadataOutput\>

创建metadata流输出对象，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                 |
| -------------------- | -------------------------------------------------- | --- | -------------------- |
| metadataObjectTypes  | Array<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。  |

**返回值：**

| 类型                                        | 说明                                       |
| ------------------------------------------ | ----------------------------------------- |
| Promise<[MetadataOutput](#metadataoutput)\> |  使用Promise的方式获取MetadataOutput的实例。 |

**示例：**

```js
let metadataObjectTypes = cameraoutputcapability.supportedMetadataObjectTypes;
cameraManager.createMetadataOutput(metadataObjectTypes).then((metadataOutput) => {
    console.log('Promise returned with metadataOutput created.');
})
```

### createCaptureSession

createCaptureSession(callback: AsyncCallback<CaptureSession\>): void

创建CaptureSession实例，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                      | 必填         | 说明                          |
| -------------------- | ----------------------------------------- | ----------- | ---------------------------- |
| callback             | AsyncCallback<[CaptureSession](#capturesession)\>  | 是   | 回调函数，用于获取拍照会话实例。 |

**示例：**

```js
cameraManager.createCaptureSession((err, captureSession) => {
    if (err) {
        console.error(`Failed to create captureSession. ${err.message}`);
        return;
    }
    console.log('Callback returned with captureSession created.');
})
```

### createCaptureSession

createCaptureSession(): Promise<CaptureSession\>

创建CaptureSession实例，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                         | 说明                                      |
| ------------------------------------------- | ---------------------------------------- |
| Promise<[CaptureSession](#capturesession)\>  | 使用Promise的方式获取CaptureSession的实例。 |

**示例：**

```js
cameraManager.createCaptureSession().then((captureSession) => {
    console.log('Promise returned with captureSession created.');
})
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback<CameraStatusInfo\>): void

镜头状态回调，通过注册回调函数获取相机的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明       |
| -------- | ----------------------------------------------------- | ---- | --------- |
| type     | string                                                | 是   | 监听事件，固定为'cameraStatus'，即镜头状态变化事件。 |
| callback | AsyncCallback<[CameraStatusInfo](#camerastatusinfo)\> | 是   | 回调函数，用于获取镜头状态变化信息。                 |

**示例：**

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

禁用回调，通过注册回调函数获取相机禁用状态变化。

此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'cameraMute'，即禁用状态变化事件。 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，用于获取禁用状态变化信息。               |

**示例：**

```js
cameraManager.on('cameraMute', (err, curMuetd) => {
    if (err) {
        console.error(`Failed to get cameraMute callback. ${err.message}`);
        return;
    }
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
| CAMERA_TYPE_UNSPECIFIED | 0    | 相机类型未指定。  |
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
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

打开相机，通过Promise获取相机的状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.open().then(() => {
    console.log('Promise returned with camera opened.');
})
```

### close

close\(callback: AsyncCallback<void\>\): void

关闭相机，通过注册回调函数获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

关闭相机，通过Promise获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.close().then(() => {
    console.log('Promise returned with camera closed.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

释放资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

释放资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
cameraInput.release().then(() => {
    console.log('Promise returned to indicate that the CameraInput instance is released successfully.');
})
```

### on('error')

on(type: 'error', cameraDevice:CameraDevice, callback: ErrorCallback<CameraInputError\>): void

监听CameraInput的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'error'，即CameraInput错误事件。 |
| cameraDevice   | [CameraDevice](#cameradevice)    | 是   | CameraDevice对象。 |
| callback | ErrorCallback<[CameraInputError](#camerainputerror)\> | 是   | 回调函数，用于获取结果。   |

**示例：**

```js
let cameraDevice = cameras[0];
cameraInput.on('error', cameraDevice, (cameraInputError) => {
    console.log(`Camera input error code: ${cameraInputError.code}`);
})
```

## CameraInputErrorCode

枚举，[CameraInput](#camerainput)错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明       |
| ------------------------- | ---- | ---------- |
| ERROR_UNKNOWN             | -1   | 未知错误。 |
| ERROR_NO_PERMISSION       | 0    | 没有权限。 |
| ERROR_DEVICE_PREEMPTED    | 1    | 相机被抢占。 |
| ERROR_DEVICE_DISCONNECTED | 2    | 相机断开连接。 |
| ERROR_DEVICE_IN_USE       | 3    | 相机正在使用。 |
| ERROR_DRIVER_ERROR        | 4    | 驱动错误。    |

## CameraInputError

[CameraInput](#camerainput)错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                           |     必填     | 说明                   |
| ---- | --------------------------------------------- | ------------ |--------------------- |
| code | [CameraInputErrorCode](#camerainputerrorcode) |       是     |CameraInput中的错误码。 |


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

beginConfig\(callback: AsyncCallback<void\>\): void

开始配置会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

开始配置会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.beginConfig().then(() => {
    console.log('Promise returned to indicate the begin config success.');
})
```

### commitConfig

commitConfig\(callback: AsyncCallback<void\>\): void

提交配置信息，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

提交配置信息，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                      |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.commitConfig().then(() => {
    console.log('Promise returned to indicate the commit config success.');
})
```

### addInput

addInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

把[CameraInput](#camerainput)加入到会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

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

把[CameraInput](#camerainput)加入到会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addInput(cameraInput).then(() => {
    console.log('Promise used to indicate that the CameraInput instance is added.');
})
```

### removeInput

removeInput\(cameraInput: CameraInput, callback: AsyncCallback<void\>\): void

移除[CameraInput](#camerainput)，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                      |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |
| callback    | AsyncCallback<void\>        | 是   | 回调函数，用于获取结果。    |

**示例：**

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

移除[CameraInput](#camerainput)，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                      |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |

**返回值：**

| 类型            | 说明                      |
| -------------- | ------------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.removeInput(cameraInput).then(() => {
    console.log('Promise returned to indicate that the cameraInput instance is removed.');
})
```

### addOutput

addOutput\(previewOutput: CameraOutput, callback: AsyncCallback<void\>\): void

把[CameraOutput](#cameraoutput)加入到会话，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要添加的previewoutput实例。 |
| callback      | AsyncCallback<void\>            | 是   | 回调函数，用于获取结果。      |

**示例：**

```js
captureSession.addOutput(previewOutput, (err) => {
    if (err) {
        console.error(`Failed to add output. ${err.message}`);
        return;
    }
    console.log('Callback returned with output added.');
})
```

### addOutput

addOutput\(previewOutput: CameraOutput\): Promise<void\>

把[CameraOutput](#cameraoutput)加入到会话，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                       |
| ------------- | ------------------------------- | ---- | ------------------------- |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要添加的previewOutput实例。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.addOutput(previewOutput).then(() => {
    console.log('Promise returned with cameraOutput added.');
})
```

### removeOutput

removeOutput\(previewOutput: CameraOutput, callback: AsyncCallback<void\>\): void

从会话中移除[CameraOutput](#cameraoutput)，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要移除的previewoutput实例。 |
| callback      | AsyncCallback<void\>            | 是   | 回调函数，用于获取结果。      |

**示例：**

```js
captureSession.removeOutput(previewOutput, (err) => {
    if (err) {
        console.error(`Failed to remove the CameraOutput instance. ${err.message}`);
        return;
    }
    console.log('Callback invoked to indicate that the CameraOutput instance is removed.');
});
```

### removeOutput

removeOutput(previewOutput: CameraOutput): Promise<void\>

从会话中移除[CameraOutput](#cameraoutput)，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------- |
| previewOutput  | [PreviewOutput](#previewoutput)   | 是   | 需要移除的previewoutput实例。 |


**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
captureSession.removeOutput(previewOutput).then(() => {
    console.log('Promise returned to indicate that the CameraOutput instance is removed.');
})
```

### start

start\(callback: AsyncCallback<void\>\): void

开始会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

开始会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.start().then(() => {
    console.log('Promise returned to indicate the session start success.');
})
```

### stop

stop\(callback: AsyncCallback<void\>\): void

停止会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

停止会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.stop().then(() => {
    console.log('Promise returned to indicate the session stop success.');
})
```

### release

release\(callback: AsyncCallback<void\>\): void

释放会话资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

释放会话资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.release().then(() => {
    console.log('Promise returned to indicate that the CaptureSession instance is released successfully.');
})
```

### hasFlash

hasFlash(callback: AsyncCallback<boolean\>): void

检测是否有闪光灯，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                             |
| -------- | ----------------------- | ---- | -------------------------------- |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示设备支持闪光灯。 |

**示例：**

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

检测是否有闪光灯，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型               | 说明                                             |
| ----------------- | ----------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持闪光灯。 |

**示例：**

```js
captureSession.hasFlash().then((status) => {
    console.log(`Promise returned with the flash light support status: ${status}`);
})
```

### isFlashModeSupported

isFlashModeSupported(flashMode: FlashMode, callback: AsyncCallback<boolean\>): void

检测闪光灯模式是否支持，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                               |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。                     |
| callback  | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示支持该闪光灯模式。 |

**示例：**

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

检测闪光灯模式是否支持，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                    | 必填 | 说明            |
| --------- | ----------------------- | ---- | ------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。 |

**返回值：**

| 类型               | 说明                                                  |
| ----------------- | ---------------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持该闪光灯模式。 |

**示例：**

```js
captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO).then((status) => {
    console.log(`Promise returned with flash mode support status.${status}`);
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

| 参数名       | 类型                     | 必填 | 说明                  |
| --------- | ----------------------- | ---- | --------------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。         |
| callback  | AsyncCallback<void\>    | 是   | 回调函数，用于获取结果。 |

**示例：**

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

设置闪光灯模式，通过Promise获取结果。

进行设置之前，需要先检查：

1. 设备是否支持闪光灯，可使用方法[hasFlash](#hasflash)。
2. 设备是否支持指定的闪光灯模式，可使用方法[isFlashModeSupported](#isflashmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明           |
| --------- | ----------------------- | ---- | ------------- |
| flashMode | [FlashMode](#flashmode) | 是   | 指定闪光灯模式。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFlashMode.');
})
```

### getFlashMode

getFlashMode(callback: AsyncCallback<FlashMode\>): void

获取当前设备的闪光灯模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                     | 必填 | 说明                              |
| -------- | --------------------------------------- | ---- | --------------------------------- |
| callback | AsyncCallback<[FlashMode](#flashmode)\> | 是   | 回调函数，用于获取当前设备的闪光灯模式。 |

**示例：**

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

获取当前设备的闪光灯模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                               | 说明                               |
| --------------------------------- | --------------------------------- |
| Promise<[FlashMode](#flashmode)\> | 使用Promise的方式获取当前的闪光灯模式。 |

**示例：**

```js
captureSession.getFlashMode().then((flashMode) => {
    console.log(`Promise returned with current flash mode : ${flashMode}`);
})
```

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode, callback: AsyncCallback<boolean\>): void;

检测曝光模式是否支持，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                      |
| callback | AsyncCallback<boolean\>        | 是   | 回调函数，用于获取是否支持曝光模式。 |

**示例：**

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

检测曝光模式是否支持，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                      |

**返回值：**

| 名称               | 说明                             |
| ----------------- |--------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取支持的曝光模式。 |

**示例：**

```js
captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED).then((isSupported) => {
    console.log(`Promise returned with exposure mode supported : ${isSupported}`);
})
```

### getExposureMode

getExposureMode(callback: AsyncCallback<ExposureMode\>): void

获取当前曝光模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                                     |
| -------- | -------------------------------| ---- | ---------------------------------------- |
| callback | AsyncCallback<[ExposureMode](#exposuremode)\>   | 是   | 回调函数，用于获取当前曝光模式。 |

**示例：**

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

获取当前曝光模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 名称                                     | 说明                           |
| --------------------------------------- |------------------------------- |
| Promise<[ExposureMode](#exposuremode)\> | 使用Promise的方式获取当前曝光模式。 |

**示例：**

```js
captureSession.getExposureMode().then((exposureMode) => {
    console.log(`Promise returned with current exposure mode : ${exposureMode}`);
})
```

### setExposureMode

setExposureMode(aeMode: ExposureMode, callback: AsyncCallback<void\>): void

设置曝光模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                |
| callback | AsyncCallback<void\>           | 是   | 回调函数，用于获取设置结果。 |

**示例：**

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

设置曝光模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 名称               | 说明                        |
| ----------------- |---------------------------- |
| Promise<void\>    | 使用Promise的方式获取设置结果。 |

**示例：**

```js
captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED).then(() => {
    console.log('Promise returned with the successful execution of setExposureMode.');
})
```

### getMeteringPoint

getMeteringPoint(callback: AsyncCallback<Point\>): void

查询曝光区域中心点，通过注册回调函数获取结果。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                       |
| -------- | -------------------------------| ---- | ------------------------ |
| callback | AsyncCallback<[Point](#point)\>| 是   | 回调函数，用于获取当前曝光点。 |

**示例：**

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

查询曝光区域中心点，通过Promise获取结果。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 名称                       | 说明                          |
| ------------------------- |----------------------------- |
| Promise<[Point](#point)\> | 使用Promise的方式获取当前曝光点。 |

**示例：**

```js
captureSession.getMeteringPoint().then((exposurePoint) => {
    console.log(`Promise returned with current exposure point : ${exposurePoint}`);
})
```

### setMeteringPoint

setMeteringPoint(point: Point, callback: AsyncCallback<void\>): void

设置曝光区域中心点，通过注册回调函数获取结果。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | 是   | 曝光点。              |
| callback      | AsyncCallback<void\>           | 是   | 回调函数，用于获取结果。 |

**示例：**

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

设置曝光区域中心点，通过Promise获取结果。（该接口目前为预留，将在3.2版本开放）

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | 是   | 曝光点。              |

**返回值：**

| 名称               | 说明                     |
| ----------------- |------------------------ |
| Promise<void\>    | 使用Promise的方式返回结果。 |

**示例：**

```js
const Point2 = {x: 2, y: 2};

captureSession.setMeteringPoint(Point2).then(() => {
    console.log('Promise returned with the successful execution of setMeteringPoint');
})
```

### getExposureBiasRange

getExposureBiasRange(callback: AsyncCallback<Array<number\>\>): void

查询曝光补偿范围，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| callback | AsyncCallback<Array<number\>\>  | 是   | 回调函数，用于获取补偿范围的数组。 |

**示例：**

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

查询曝光补偿范围，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 名称               | 说明                                   |
| ----------------- |-------------------------------------- |
| Promise<Array<number\>\> | 使用Promise的方式获取曝光补偿范围。 |

**示例：**

```js
captureSession.getExposureBiasRange().then((biasRangeArray) => {
    console.log('Promise returned with the array of compenstation range: ' + JSON.stringify(biasRangeArray));
})
```

### setExposureBias

setExposureBias(exposureBias: number, callback: AsyncCallback<void\>): void

设置曝光补偿，通过注册回调函数获取结果。

进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrange)查询支持的范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                 |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | 是   | 曝光补偿,getExposureBiasRange查询支持的范围 |
| callback | AsyncCallback<void\>           | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
let exposureBias = biasRangeArray[0];
captureSession.setExposureBias(exposureBias,(err) => {
    if (err) {
        console.log(`Failed to set the exposure bias ${err.message}`);
        return ;
    }
    console.log('Callback returned with the successful execution of setExposureBias');
})
```

### setExposureBias

setExposureBias(exposureBias: number): Promise<void\>

设置曝光补偿，通过Promise获取结果。

进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrange)查询支持的范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名            | 类型      | 必填 | 说明        |
| -------------- | --------- | ---- | --------- |
| exposureBias   | number    | 是   | 曝光补偿,getExposureBiasRange查询支持的范围  |

**返回值：**

| 名称               | 说明                     |
| ----------------- |------------------------- |
| Promise<void\>    | 使用Promise的方式获取结果。 |

**示例：**

```js
let exposureBias = biasRangeArray[0];
captureSession.setExposureBias(exposureBias).then(() => {
    console.log('Promise returned with the successful execution of setExposureBias.');
})
```

### getExposureValue

getExposureValue(callback: AsyncCallback<number\>): void

查询当前曝光值，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                      | 必填 | 说明                   |
| -------- | ------------------------| ---- | --------------------- |
| callback | AsyncCallback<number\>  | 是   | 回调函数，用于获取曝光值。 |

**示例：**

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

查询当前曝光值，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 名称               | 说明                       |
| ----------------- |-------------------------- |
| Promise<number\>  | 使用Promise的方式获取曝光值。 |

**示例：**

```js
captureSession.getExposureValue().then((exposureValue) => {
    console.log(`Promise returned with exposure value: ${exposureValude}`);
})
```

### isFocusModeSupported

isFocusModeSupported(afMode: FocusMode, callback: AsyncCallback<boolean\>): void

检测对焦模式是否支持，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                              |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。                    |
| callback | AsyncCallback<boolean\> | 是   | 回调函数，返回true表示支持该焦距模式。 |

**示例：**

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

检测对焦模式是否支持，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明           |
| ------ | ----------------------- | ---- | ------------- |
| afMode | [FocusMode](#focusmode) | 是   | 指定的焦距模式。 |

**返回值：**

| 类型               | 说明                                                |
| ----------------- | --------------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回true表示设备支持该焦距模式。 |

**示例：**

```js
captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO).then((status) => {
    console.log(`Promise returned with focus mode support status ${status}.`);
})
```

### setFocusMode

setFocusMode(afMode: FocusMode, callback: AsyncCallback<void\>): void

设置对焦模式，通过注册回调函数获取结果。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](#focusmode) | 是   | 指定的焦距模式。       |
| callback | AsyncCallback<void\>    | 是   | 回调函数，用于获取结果。 |

**示例：**

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

设置对焦模式，通过Promise获取结果。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明           |
| ------ | ----------------------- | ---- | ------------- |
| afMode | [FocusMode](#focusmode) | 是   | 指定的焦距模式。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO).then(() => {
    console.log('Promise returned with the successful execution of setFocusMode.');
})
```

### getFocusMode

getFocusMode(callback: AsyncCallback<FocusMode\>): void

获取当前的对焦模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                     | 必填 | 说明                             |
| -------- | --------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback<[FocusMode](#focusmode)\> | 是   | 回调函数，用于获取当前设备的焦距模式。 |

**示例：**

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

获取当前的对焦模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                 | 说明                             |
| ------------------- | -------------------------------- |
| Promise<FocusMode\> | 使用Promise的方式获取当前的焦距模式。 |

**示例：**

```js
captureSession.getFocusMode().then((afMode) => {
    console.log(`Promise returned with current focus mode : ${afMode}`);
})
```

### setFocusPoint

setFocusPoint(point: Point, callback: AsyncCallback<void\>): void

设置焦点，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | 是   | 焦点。                |
| callback | AsyncCallback<void\>    | 是   | 回调函数，用于获取结果。 |

**示例：**

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

设置焦点，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | 是   | 焦点。                |

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
const Point2 = {x: 2, y: 2};

captureSession.setFocusPoint(Point2).then(() => {
    console.log('Promise returned with the successful execution of setFocusPoint.');
})
```

### getFocusPoint

getFocusPoint(callback: AsyncCallback<Point\>): void

查询焦点，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                               | 必填 | 说明                     |
| -------- | ---------------------------------- | ---- | ----------------------- |
| callback | AsyncCallback<[Point](#point)\>    | 是   | 回调函数，用于获取当前焦点。 |

**示例：**

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

查询焦点，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型             | 说明                        |
| --------------- | --------------------------- |
| Promise<Point\> | 使用Promise的方式获取当前焦点。 |

**示例：**

```js
captureSession.getFocusPoint().then((point) => {
    console.log('Promise returned with the current focus point: ' + JSON.stringify(point));
})
```

### getFocalLength

getFocalLength(callback: AsyncCallback<number\>): void

查询焦距值，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                       | 必填 | 说明                     |
| -------- | ------------------------- | ---- | ----------------------- |
| callback | AsyncCallback<number\>    | 是   | 回调函数，用于获取当前焦距。 |

**示例：**

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

查询焦距值，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型              | 说明                     |
| ---------------- | ----------------------- |
| Promise<number\> | 使用Promise的方式获取焦距。 |

**示例：**

```js
captureSession.getFocalLength().then((focalLength) => {
    console.log(`Promise returned with the current focal length: ${focalLength}`);
})
```

### getZoomRatioRange

getZoomRatioRange\(callback: AsyncCallback<Array<number\>\>\): void

获取支持的变焦范围，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                 |
| -------- | ------------------------------ | ---- | ------------------- |
| callback | AsyncCallback<Array<number\>\> | 是   | 回调函数，用于获取可变焦距比范围，返回的数组包括其最小值和最大值。 |

**示例：**

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

获取支持的变焦范围，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                      | 说明                        |
| ------------------------ | --------------------------- |
| Promise<Array<number\>\> |  使用Promise的方式获取当前的可变焦距比范围，返回的数组包括其最小值和最大值。 |

**示例：**

```js
captureSession.getZoomRatioRange().then((zoomRatioRange) => {
    console.log(`Promise returned with zoom ratio range: ${zoomRatioRange.length}`);
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number, callback: AsyncCallback<void\>): void

设置变焦比，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                  | 必填 | 说明                 |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | 是   | 可变焦距比,通过getZoomRatioRange获取支持的变焦范围 |
| callback  | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
let zoomRatio = zoomRatioRange[0];
captureSession.setZoomRatio(zoomRatio, (err) => {
    if (err) {
        console.error(`Failed to set the zoom ratio value ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of setZoomRatio.');
})
```

### setZoomRatio

setZoomRatio(zoomRatio: number): Promise<void\>

设置变焦比，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型    | 必填 | 说明       |
| --------- | ------ | ---- | --------- |
| zoomRatio | number | 是   | 可变焦距比，通过getZoomRatioRange获取支持的变焦范围|

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
let zoomRatio = zoomRatioRange[0];
captureSession.setZoomRatio(zoomRatio).then(() => {
    console.log('Promise returned with the successful execution of setZoomRatio.');
})
```

### getZoomRatio

getZoomRatio(callback: AsyncCallback<number\>): void

获取当前的变焦比，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                   | 必填 | 说明                  |
| -------- | ---------------------- | ---- | ------------------- |
| callback | AsyncCallback<number\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

获取当前的变焦比，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型              | 说明                     |
| ---------------- | ----------------------- |
| Promise<number\> | 使用Promise的方式获取结果。 |

**示例：**

```js
captureSession.getZoomRatio().then((zoomRatio) => {
    console.log(`Promise returned with current zoom ratio : ${zoomRatio}`);
})
```

### isVideoStabilizationModeSupported

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode, callback: AsyncCallback<boolean\>): void

查询是否支持指定的视频防抖模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                             |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](#videostabilizationmode) | 是   | 视频防抖模式。                    |
| callback | AsyncCallback<boolean\>                           | 是   | 回调函数，返回视频防抖模式是否支持。  |

**示例：**

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

查询是否支持指定的视频防抖模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型               | 说明                                           |
| ----------------- | --------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回视频防抖模式是否支持。 |

**示例：**

```js
captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF).then((isSupported) => {
    console.log(`Promise returned with video stabilization mode supported: ${isSupported}`);
})
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(callback: AsyncCallback<VideoStabilizationMode\>): void

查询当前正在使用的视频防抖模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                       | 必填 | 说明                            |
| -------- | ----------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<VideoStabilizationMode\>    | 是   | 回调函数，返回视频防抖是否正在使用。  |

**示例：**

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

查询当前正在使用的视频防抖模式，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                              | 说明                                              |
| -------------------------------- | ------------------------------------------------- |
| Promise<VideoStabilizationMode\> | 使用Promise的方式获取结果，返回视频防抖当前是否正在使用。  |

**示例：**

```js
captureSession.getActiveVideoStabilizationMode().then((vsMode) => {
    console.log(`Promise returned with the current video stabilization mode: ${vsMode}`);
})
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode, callback: AsyncCallback<void\>): void

设置视频防抖模式，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | 是   | 需要设置的视频防抖模式。   |
| callback | AsyncCallback<void\>                              | 是   | 回调函数。     |

**示例：**

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

设置视频防抖，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | 是   | 需要设置的视频防抖模式。   |

**返回值：**

| 类型            | 说明                                               |
| -------------- | ------------------------------------------------- |
| Promise<void\> | 使用Promise的方式获取结果，返回设置的视频防抖模式的结果。  |

**示例：**

```js
captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF).then(() => {
    console.log('Promise returned with the successful execution of setVideoStabilizationMode.');
})
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback<FocusState\>): void

监听焦距的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，即焦距状态变化事件。 |
| callback | AsyncCallback<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取焦距状态。  |

**示例：**

```js
captureSession.on('focusStateChange', (focusState) => {
    console.log(`Focus state  : ${focusState}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<CaptureSessionError\>): void

监听拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，即拍照会话错误事件。 |
| callback | ErrorCallback<[CaptureSessionError](#capturesessionerror)\> | 是   | 回调函数，用于获取错误信息。        |

**示例：**

```js
captureSession.on('error', (captureSessionError) => {
    console.log(`Capture session error code: ${captureSessionError.code}`);
})
```

## CaptureSessionErrorCode

枚举，会话错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明      |
| ----------------------------- | ---- | -------- |
| ERROR_UNKNOWN                 | -1   | 未知错误。 |
| ERROR_INSUFFICIENT_RESOURCES  | 0    | 资源不足。 |
| ERROR_TIMEOUT                 | 1    | 超时。 |

## CaptureSessionError

会话错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                        |        必填           |        说明                       |
| ---- | ------------------------------------------- | -------------------------- |-------------------------- |
| code | [CaptureSessionError](#capturesessionerror) |         是             |CaptureSession中的错误码。 |

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
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

开始输出预览流，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
previewOutput.start().then(() => {
    console.log('Promise returned with previewOutput started.');
})
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
        console.error(`Failed to stop the previewOutput. ${err.message}`);
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
})
```

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
previewOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.message}`);
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

| 参数名      | 类型                  | 必填 | 说明                                     |
| -------- | -------------------- | ---- | --------------------------------------- |
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

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，即帧结束事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                  |

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

| 参数名     | 类型                                                               | 必填 | 说明                       |
| -------- | ----------------------------------------------------------------- | ---- | ------------------------ |
| type     | string                                               | 是   | 监听事件，固定为'error'，即预览输出错误事件。|
| callback | ErrorCallback<[PreviewOutputErrorCode](#previewoutputerrorcode)\> | 是   | 回调函数，用于获取错误信息。  |

**示例：**

```js
previewOutput.on('error', (previewOutputError) => {
    console.log(`Preview output error code: ${previewOutputError.code}`);
})
```

## PreviewOutputErrorCode

枚举，预览输出错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 值   | 说明       |
| ------------- | ---- | -------- |
| ERROR_UNKNOWN | -1   | 未知错误。 |

## PreviewOutputError

预览输出错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                              |        必填       |          说明              |
| ---- | ------------------------------------------------- | ---------------- |---------------------- |
| code | [PreviewOutputErrorCode](#previewoutputerrorcode) |        是          |PreviewOutput中的错误码。 |

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
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

以指定参数触发一次拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                  |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | 是   | 拍照设置。             |
| callback | AsyncCallback<void\>                        | 是   | 回调函数，用于获取结果。  |

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
        console.error(`Failed to capture the photo ${err.message}`);
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
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
photoOutput.capture().then(() => {
    console.log('Promise returned to indicate that photo capture request success.');
})
```

### isMirrorSupported

isMirrorSupported(callback: AsyncCallback<boolean\>): void

查询是否支持镜像拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                         |
| -------- | ------------------------------------------------- | ---- | -------------------------- |
| callback | AsyncCallback<boolean\>                           | 是   | 回调函数,返回是否支持镜像拍照。  |

**示例：**

```js
photoOutput.isMirrorSupported((err, isSupported) => {
    if (err) {
        console.error(`Failed to check mirror is supported ${err.message}`);
        return;
    }
    console.log('Callback returned with the successful execution of isMirrorSupported.');
})
```

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
photoOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.message}`);
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
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
photoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### isMirrorSupported

isMirrorSupported(): Promise<boolean\>

查询是否支持镜像拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型               | 说明                                        |
| ----------------- | ------------------------------------------- |
| Promise<boolean\> | 使用Promise的方式获取结果，返回是否支持自拍结果。  |

**示例：**

```js
photoOutput.isMirrorSupported().then((isSupported) => {
    console.log(`Promise returned with mirror supported: ${isSupported}`);
})
```

### on('captureStart')

on(type: 'captureStart', callback: AsyncCallback<number\>): void

监听拍照开始，通过注册回调函数获取Capture ID。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'captureStart'，即拍照启动事件。 |
| callback | AsyncCallback<number\> | 是   | 使用callback的方式获取Capture ID。            |

**示例：**

```js
photoOutput.on('captureStart', (err, captureId) => {
    console.log(`photo capture stated, captureId : ${captureId}`);
})
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback<FrameShutterInfo\>): void

监听拍照帧输出捕获，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                   | 必填 | 说明                                  |
| -------- | ----------------------------------------------------- | --- | ------------------------------------ |
| type     | string                                           | 是   | 监听事件，固定为'frameShutter'，即帧刷新事件。 |
| callback | AsyncCallback<[FrameShutterInfo](#frameshutterinfo)\> | 是   | 回调函数，用于获取相关信息。             |

**示例：**

```js
photoOutput.on('frameShutter', (err, frameShutterInfo) => {
    console.log(`photo capture end, captureId : ${frameShutterInfo.captureId}`);
    console.log(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
})
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback<CaptureEndInfo\>): void

监听拍照结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                              | 必填 | 说明                                       |
| -------- | ------------------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                            | 是   | 监听事件，固定为'captureEnd'，即拍照停止事件。 |
| callback | AsyncCallback<[CaptureEndInfo](#captureendinfo)\> | 是   | 回调函数，用于获取相关信息。                  |

**示例：**

```js
photoOutput.on('captureEnd', (err, captureEndInfo) => {
    console.log(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.log(`frameCount : ${captureEndInfo.frameCount}`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<PhotoOutputError\>): void

监听拍照输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ----------------------------------- |
| type     | string                                                | 是   | 监听事件，固定为'error'，即拍照错误事件。 |
| callback | ErrorCallback<[PhotoOutputError](#photooutputerror)\> | 是   | 回调函数，用于获取错误信息。             |

**示例：**

```js
photoOutput.on('error', (err, photoOutputError) => {
    console.log(`Photo output error code: ${photoOutputError.code}`);
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

## PhotoOutputErrorCode

枚举，拍照输出错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明             |
| ----------------------------- | ---- | --------------- |
| ERROR_UNKNOWN                 | -1   | 未知错误。        |
| ERROR_DRIVER_ERROR            | 0    | 驱动或者硬件错误。 |
| ERROR_INSUFFICIENT_RESOURCES  | 1    | 资源不足。        |
| ERROR_TIMEOUT                 | 2    | 超时。           |

## PhotoOutputError

拍照输出错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                  |    必填    |说明                    |
| ---- | ------------------------------------- | --------- | ----------------------- |
| code | [PhotoOutputErrorCode](#photooutputerrorcode) |        是        | PhotoOutput中的错误码。 |

## VideoOutput

录像会话中使用的输出信息，继承[CameraOutput](#cameraoutput)

### start

start(callback: AsyncCallback<void\>): void

启动录制，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

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

启动录制，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise<void\> | 使用Promise的方式获取结果。 |


**示例：**

```js
videoOutput.start().then(() => {
    console.log('Promise returned to indicate that start method execution success.');
})
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
        console.error(`Failed to stop the video output ${err.message}`);
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
})
``` 

### release

release(callback: AsyncCallback<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
videoOutput.release((err) => {
    if (err) {
        console.error(`Failed to release the PreviewOutput instance ${err.message}`);
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
| Promise<void\> | 使用Promise的方式获取结果。 |

**示例：**

```js
videoOutput.release().then(() => {
    console.log('Promise returned to indicate that the PreviewOutput instance is released successfully.');
})
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback<void\>): void

监听录像开始，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，即视频帧开启事件。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                       |

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
| type     | string               | 是   | 监听事件，固定为'frameEnd'，即视频帧结束事件  。 |
| callback | AsyncCallback<void\> | 是   | 回调函数，用于获取结果。                       |

**示例：**

```js
videoOutput.on('frameEnd', () => {
    console.log('Video frame ended');
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<VideoOutputError\>): void

监听录像输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                               | 必填 | 说明                                    |
| -------- | ------------------------------------------------ | ---- | -------------------------------------- |
| type     | string                                           | 是   | 监听事件，固定为'error'，即视频输出错误事件。 |
| callback | Callback<[VideoOutputError](#videooutputerror)\> | 是   | 回调函数，用于获取错误信息。                 |

**示例：**

```js
videoOutput.on('error', (VideoOutputError) => {
    console.log(`Video output error code: ${VideoOutputError.code}`);
})
```

## VideoOutputErrorCode

枚举，录像输出错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                   | 值   | 说明          |
| --------------------- | ---- | ------------ |
| ERROR_UNKNOWN         | -1   | 未知错误。     |
| ERROR_DRIVER_ERROR    | 0    | 驱动或者硬件错误。|

## VideoOutputError

录像输出错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                  |       必填       |           说明                    |
| ---- | ------------------------------------- | ----------------- | ----------------------- |
| code | [PhotoOutputErrorCode](#photooutputerrorcode) |            是           |  VideoOutput中的错误码。 |

## MetadataOutput

metadata流。继承[CameraOutput](#cameraoutput)

### start

start(callback: AsyncCallback<void\>): void

开始输出metadata，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | ----------------------------------------------------------- | ---- | ------------------- |
| callback | AsyncCallback<void\>                                       | 是   | 回调函数，用于获取结果。 |

**示例：**

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

开始输出metadata，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                     | 说明                     |
| ----------------------  | ------------------------ |
| Promise<void\>          | 使用Promise的方式获取结果。 |

**示例：**

```js
metadataOutput.start().then(() => {
    console.log('Callback returned with metadataOutput started.');
})
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
        console.error(`Failed to stop the metadataOutput. ${err.message}`);
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
})
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback<Array<MetadataObject\>\>): void

监听检测到的metadata对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                  | 必填 | 说明                                  |
| -------- | ------------------------------------------------ | ---- | ------------------------------------ |
| type     | string                            | 是   | 监听事件，固定为'metadataObjectsAvailable'，即metadata对象。 |
| callback | Callback<Array<[MetadataObject](#metadataobject)\>\> | 是   | 回调函数，用于获取错误信息。               |

**示例：**

```js
metadataOutput.on('metadataObjectsAvailable', (metadataObjectArr) => {
    console.log(`metadata output metadataObjectsAvailable`);
})
```

### on('error')

on(type: 'error', callback: ErrorCallback<MetadataOutputError\>): void

监听metadata流的错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                               | 必填 | 说明                                     |
| -------- | ------------------------------------------------ | ---- | --------------------------------------- |
| type     | string                                           | 是   | 监听事件，固定为'error'，即metadata流的错误。 |
| callback | Callback<[MetadataOutputError](#metadataoutputerror)\> | 是   | 回调函数，用于获取错误信息。            |

**示例：**

```js
metadataOutput.on('error', (metadataOutputError) => {
    console.log(`Metadata output error code: ${metadataOutputError.code}`);
})
```

## MetadataOutputErrorCode

枚举，metadata输出错误类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                             | 值   | 说明      |
| ------------------------------- | ---- | -------- |
| ERROR_UNKNOWN                   | -1   | 未知错误。 |
| ERROR_INSUFFICIENT_RESOURCES    | 0    | 资源不足。 |

## MetadataOutputError

metadata输出错误码。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型                                  |      必填      |               说明                    |
| ---- | ------------------------------------- | ----------------- | ----------------------- |
| code | [MetadataOutputErrorCode](#metadataoutputerrorcode) |        是          | MetadataOutput中的错误码。 |

## MetadataObjectType

枚举，metadata流。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | metadata对象类型。 |

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

### getType

getType(callback: AsyncCallback<MetadataObjectType\>): void

查询metadata对象类型，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                       | 必填 | 说明                  |
| -------- | --------------------------------------------------------- | --- | -------------------- |
| callback | AsyncCallback<[MetadataObjectType](#metadataobjecttype)\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
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

查询metadata对象类型，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                                 | 说明                        |
| --------------------------------------------------- | --------------------------- |
| Promise<[MetadataObjectType](#metadataobjecttype)\> | 使用Promise的方式获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
metadataObject.getType().then((metadataObjectType) => {
    console.log('Callback returned with an array of metadataObjectType.');
})
```

### getTimestamp

getTimestamp(callback: AsyncCallback<number\>): void

查询metadata时间戳，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                     |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<number\>                                      | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
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

查询metadata时间戳，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型               | 说明                        |
| ----------------  | --------------------------- |
| Promise<number)\> | 使用Promise的方式获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
metadataObject.getTimestamp().then((timestamp) => {
    console.log('Callback returned with timestamp getted timestamp : ${timestamp}');
})
```

### getBoundingBox

getBoundingBox(callback: AsyncCallback<Rect\>): void

查询metadata的边界框，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                     |
| -------- | ----------------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback<[Rect](#rect)\>                               | 是   | 回调函数，用于获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
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

查询metadata的边界框，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                    | 说明                        |
| ----------------------  | --------------------------- |
| Promise<[Rect](#rect)\> | 使用Promise的方式获取结果。 |

**示例：**

```js
let metadataObject = metadataObjectArr[0];
metadataObject.getBoundingBox().then((rect) => {
    console.log('Callback returned with boundingBox getted.');
})
```

## MetadataFaceObject

metadata的人脸对象。继承[MetadataObject](#metadataobject)