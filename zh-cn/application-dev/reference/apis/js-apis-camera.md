# @ohos.multimedia.camera (相机管理)

本模块为开发者提供一套简单且易于理解的相机服务接口，开发者通过调用接口可以开发相机应用。应用通过访问和操作相机硬件，实现基础操作，如预览、拍照和录像；还可以通过接口组合完成更多操作，如控制闪光灯和曝光时间、对焦或调焦等。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import camera from '@ohos.multimedia.camera';
```

## camera.getCameraManager

getCameraManager(context: Context): CameraManager

获取相机管理器实例，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ---------------------------- |
| context  | [Context](js-apis-inner-application-baseContext.md)      | 是   | 应用上下文。                   |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CameraManager](#cameramanager)           | 相机管理器。                   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect               |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {
  let cameraManager: camera.CameraManager | undefined = undefined;
  try {
    cameraManager = camera.getCameraManager(context);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getCameraManager call failed. error code: ${err.code}`);
  }
  return cameraManager;
}
```

## CameraDevice

相机设备信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称           | 类型                                | 必填 | 只读 | 说明        |
| -------------- | --------------------------------- | ---- | ---- |---------- |
| cameraId       | string                            | 是   | 是   | CameraDevice对象。|
| cameraPosition | [CameraPosition](#cameraposition) | 是   | 是   | 相机位置。    |
| cameraType     | [CameraType](#cameratype)         | 是   | 是   | 相机类型。    |
| connectionType | [ConnectionType](#connectiontype) | 是   | 是   | 相机连接类型。 |
| hostDeviceName | string                            | 是   | 是   | 远端设备名称。**系统接口：** 此接口为系统接口。 |
| hostDeviceType | [HostDeviceType](#hostdevicetype) | 是   | 是   | 远端相机设备类型。**系统接口：** 此接口为系统接口。 |

## CameraPosition

枚举，相机位置。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                         | 值   | 说明            |
| --------------------------- | ---- | -------------- |
| CAMERA_POSITION_UNSPECIFIED | 0    | 相机位置未指定。  |
| CAMERA_POSITION_BACK        | 1    | 后置相机。       |
| CAMERA_POSITION_FRONT       | 2    | 前置相机。       |
| CAMERA_POSITION_FOLD_INNER<sup>11+</sup>  | 3    | 折叠态相机。     |

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

## HostDeviceType

枚举，远端相机设备类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值       | 说明           |
| ---------------------------- | ----     | ------------- |
| UNKNOWN_TYPE                 | 0        | 未知设备类型。      |
| PHONE                        | 0x0E     | 手机相机。 |
| TABLET                       | 0x11     | 平板相机。 |

## CameraStatus

枚举，相机状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明            |
| ------------------------- | ---- | ------------    |
| CAMERA_STATUS_APPEAR      | 0    | 新的相机出现。   |
| CAMERA_STATUS_DISAPPEAR   | 1    | 相机被移除。     |
| CAMERA_STATUS_AVAILABLE   | 2    | 相机可用。       |
| CAMERA_STATUS_UNAVAILABLE | 3    | 相机不可用。     |

## CameraStatusInfo

相机管理器回调返回的接口实例，表示相机状态信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| camera | [CameraDevice](#cameradevice) |        是       | 相机信息。 |
| status | [CameraStatus](#camerastatus) |        是        | 相机状态。 |

## Profile

相机配置信息项。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                           | 必填 | 只读 | 说明         |
| -------- | ----------------------------- |---- | ---- | ------------- |
| format   | [CameraFormat](#cameraformat) | 是  |  是  | 输出格式。      |
| size     | [Size](#size)                 | 是  |  是  | 分辨率。       |

## FrameRateRange

帧率范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                           | 必填 | 只读 | 说明         |
| -------- | ----------------------------- |---- | ---- | ------------- |
| min      | number                        | 是  |  是  | 最小帧率。      |
| max      | number                        | 是  |  是  | 最大帧率。      |

## VideoProfile

视频配置信息项，继承[Profile](#profile)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 类型                                      | 必填 | 只读 | 说明        |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| frameRateRange            | [FrameRateRange](#frameraterange)         | 是  |  是  | 帧率范围，fps(frames per second)。 |

## CameraOutputCapability

相机输出能力项。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 类型                                               | 必填 | 只读 | 说明                |
| ----------------------------- | -------------------------------------------------- | --- | ---- | ------------------- |
| previewProfiles               | Array\<[Profile](#profile)\>                        | 是  |  是  | 支持的预览配置信息。    |
| photoProfiles                 | Array\<[Profile](#profile)\>                        | 是  |  是  | 支持的拍照配置信息。    |
| videoProfiles                 | Array\<[VideoProfile](#videoprofile)\>              | 是  |  是  | 支持的录像配置信息。    |
| supportedMetadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | 是  |  是  | 支持的metadata流类型信息。|

## SceneMode<sup>11+</sup>

枚举，相机支持模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| NORMAL_PHOTO  | 1         | 普通拍照模式。             |
| NORMAL_VIDEO | 2      | 普通录像模式。      |
| PORTRAIT_PHOTO       | 3      | 人像拍照模式。**系统接口：** 此接口为系统接口。            |
| NIGHT_PHOTO        | 4      | 夜景拍照模式。**系统接口：** 此接口为系统接口。             |

## CameraErrorCode

相机错误码。

接口使用不正确以及on接口监听error状态返回。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值          | 说明            |
| -------------------------  | ----       | ------------    |
| INVALID_ARGUMENT           | 7400101    | 参数缺失或者参数类型不对。   |
| OPERATION_NOT_ALLOWED      | 7400102    | 操作流程不对，不允许。     |
| SESSION_NOT_CONFIG         | 7400103    | session 未配置返回。       |
| SESSION_NOT_RUNNING        | 7400104    | session 未运行返回。    |
| SESSION_CONFIG_LOCKED      | 7400105    | session 配置已锁定返回。     |
| DEVICE_SETTING_LOCKED      | 7400106    | 设备设置已锁定返回。     |
| CONFLICT_CAMERA            | 7400107    | 设备重复打开返回。     |
| DEVICE_DISABLED            | 7400108    | 安全原因摄像头被禁用。     |
| DEVICE_PREEMPTED           | 7400109    | 相机被抢占导致无法使用。     |
| SERVICE_FATAL_ERROR        | 7400201    | 相机服务错误返回。     |

## CameraManager

相机管理器类，使用前需要通过getCameraManager获取相机管理实例。

### getSupportedCameras

getSupportedCameras(): Array\<CameraDevice\>

获取支持指定的相机设备对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[CameraDevice](#cameradevice)>            | 相机设备列表。                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getSupportedCameras(cameraManager: camera.CameraManager): Array<camera.CameraDevice> {
  let cameras: Array<camera.CameraDevice> = [];
  try {
    cameras = cameraManager.getSupportedCameras();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedCameras call failed. error code: ${err.code}`);
  }
  return cameras;
}
```
### getSupportedSceneModes<sup>11+</sup>

getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode\>

获取指定的相机设备对象支持的模式，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | 是 | 相机设备，通过 [getSupportedCameras](#getsupportedcameras) 接口获取。       |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
|  Array\<[SceneMode](#scenemode11)>            | 相机支持的模式列表。                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getSupportedSceneModes(cameraManager: camera.CameraManager): Array<camera.SceneMode> {
  let modes: Array<camera.SceneMode> = [];
  try {
    modes = cameraManager.getSupportedSceneModes(camera);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The getSupportedSceneModes call failed. error code: ${err.code}`);
  }
  return modes;
}
```

### getSupportedOutputCapability<sup>(deprecated)</sup>

getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability

查询相机设备支持的输出能力，同步返回结果。

> **说明：**
> 从 API version 10开始支持，从API version 11开始废弃。建议使用[getSupportedOutputCapability<sup>11+</sup>](#getsupportedoutputcapability11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | 是 | 相机设备，通过 [getSupportedCameras](#getsupportedcameras) 接口获取。       |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | 相机输出能力。                   |

**示例：**

```ts
function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice);
  return cameraOutputCapability;
}
```

### getSupportedOutputCapability<sup>11+</sup>

getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability

查询相机设备在模式下支持的输出能力，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| cameraDevice | [CameraDevice](#cameradevice)                              | 是 | 相机设备，通过 [getSupportedCameras](#getsupportedcameras) 接口获取。       |
| mode | [SceneMode](#scenemode11)                              | 是 | 相机模式，通过 [getSupportedSceneModes](#getsupportedscenemodes11) 接口获取。       |

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [CameraOutputCapability](#cameraoutputcapability)            | 相机输出能力。                   |

**示例：**

```ts
function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): camera.CameraOutputCapability {
  let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice, sceneMode);
  return cameraOutputCapability;
}
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

```ts
function isCameraMuted(cameraManager: camera.CameraManager): boolean {
  let isMuted: boolean = cameraManager.isCameraMuted();
  return isMuted;
}
```

### isCameraMuteSupported

isCameraMuteSupported(): boolean

查询当前设备是否支持禁用相机。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示相机可以被禁用，返回false表示相机不能被禁用。 |

**示例：**

```ts
function isCameraMuteSupported(cameraManager: camera.CameraManager): boolean {
  let isMuteSupported: boolean = cameraManager.isCameraMuteSupported();
  return isMuteSupported;
}
```

### muteCamera

muteCamera(mute: boolean): void

禁用相机。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                              | 必填  | 说明        |
| -------- | --------------------------------- | ---- | ---------- |
| mute     | boolean                           |  是  |  禁用相机。true为禁用；false为解除禁用。  |

**示例：**

```ts
function muteCamera(cameraManager: camera.CameraManager): void {
  let mute: boolean = true;
  cameraManager.muteCamera(mute);
}
```

### createCameraInput

createCameraInput(camera: CameraDevice): CameraInput

使用CameraDevice对象创建CameraInput实例，同步返回结果。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                |
| -------- | ------------------------------------------- | ---- | --------------------------------- |
| cameraDevice   | [CameraDevice](#cameradevice)         | 是   | CameraDevice对象，通过 getSupportedCameras 接口获取。   |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(cameraDevice);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createCameraInput call failed. error code: ${err.code}`);
  }
  return cameraInput;
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
| position | [CameraPosition](#cameraposition)           | 是   | 相机位置，通过 [getSupportedCameras](#getsupportedcameras) 接口获取设备，然后获取设备位置信息。  |
| type     | [CameraType](#cameratype)                   | 是   | 相机类型，通过 [getSupportedCameras](#getsupportedcameras) 接口获取设备，然后获取设备类型信息。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CameraInput](#camerainput)    | CameraInput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createCameraInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): camera.CameraInput | undefined {
  let position: camera.CameraPosition = cameraDevice.cameraPosition;
  let type: camera.CameraType = cameraDevice.cameraType;
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(position, type);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createCameraInput call failed. error code: ${err.code}`);
  }
  return cameraInput;
}
```

### createPreviewOutput

createPreviewOutput(profile: Profile, surfaceId: string): PreviewOutput

创建预览输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                              |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](#profile)                             | 是   | 支持的预览配置信息，通过[getSupportedOutputCapability](#getsupportedoutputcapability11)接口获取。|
| surfaceId| string | 是   | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)或者[ImageReceiver](js-apis-image.md#imagereceiver9)组件获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [PreviewOutput](#previewoutput)    | PreviewOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createPreviewOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PreviewOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.previewProfiles[0];
  let previewOutput: camera.PreviewOutput | undefined = undefined;
  try {
    previewOutput = cameraManager.createPreviewOutput(profile, surfaceId);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createPreviewOutput call failed. error code: ${err.code}`);
  }
  return previewOutput;
}
```

### createPhotoOutput<sup>(deprecated)</sup>

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

创建拍照输出对象，同步返回结果。

> **说明：**
> 从 API version 10开始支持，从API version 11开始废弃。建议使用[createPhotoOutput<sup>11+</sup>](#createphotooutput11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | 是   | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。|
| surfaceId| string            | 是   | 从[ImageReceiver](js-apis-image.md#imagereceiver9)获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | PhotoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

```ts
import { BusinessError } from '@ohos.base';

function createPhotoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.PhotoOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.photoProfiles[0];
  let photoOutput: camera.PhotoOutput | undefined = undefined;
  try {
    photoOutput = cameraManager.createPhotoOutput(profile, surfaceId);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createPhotoOutput call failed. error code: ${err.code}`);
  }
  return photoOutput;
}
```

### createPhotoOutput<sup>11+</sup>

createPhotoOutput(profile: Profile): PhotoOutput

创建拍照输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明                                  |
| -------- | ------------------------------------------- | ---- | ----------------------------------- |
| profile  | [Profile](#profile)                         | 是   | 支持的拍照配置信息，通过getSupportedOutputCapability接口获取。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [PhotoOutput](#photooutput)   | PhotoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createPhotoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager): camera.PhotoOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.photoProfiles[0];
  let photoOutput: camera.PhotoOutput | undefined = undefined;
  try {
    photoOutput = cameraManager.createPhotoOutput(profile);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createPhotoOutput call failed. error code: ${err.code}`);
  }
  return photoOutput;
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
| surfaceId| string          | 是   | 从[AVRecorder](js-apis-media.md#avrecorder9)获取的surfaceId。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [VideoOutput](#videooutput)   | VideoOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createVideoOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager, surfaceId: string): camera.VideoOutput | undefined {
  let profile: camera.VideoProfile = cameraOutputCapability.videoProfiles[0];
  let videoOutput: camera.VideoOutput | undefined = undefined;
  try {
    videoOutput = cameraManager.createVideoOutput(profile, surfaceId);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The createVideoOutput call failed. error code: ${err.code}`);
  }
  return videoOutput;
}
```

### createMetadataOutput

createMetadataOutput(metadataObjectTypes: Array\<MetadataObjectType\>): MetadataOutput

创建metadata流输出对象，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [MetadataOutput](#metadataoutput)   | MetadataOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): void {
  let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
  let metadataOutput: camera.MetadataOutput | undefined = undefined;
  try {
    metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`createMetadataOutput error. error code: ${err.code}`);
  }
}
```

### createCaptureSession<sup>(deprecated)</sup>

createCaptureSession(): CaptureSession

创建CaptureSession实例，同步返回结果。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[createSession](#createsession11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [CaptureSession](#capturesession)   | CaptureSession实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createCaptureSession(cameraManager: camera.CameraManager): camera.CaptureSession | undefined {
  let captureSession: camera.CaptureSession | undefined = undefined;
  try {
    captureSession = cameraManager.createCaptureSession();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`createCaptureSession error. error code: ${err.code}`);
  }
  return captureSession;
}
```

### createSession<sup>11+</sup>

createSession\<T extends Session\>(mode: SceneMode): T

创建指定SceneMode的Session实例，同步返回结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名   | 类型              | 必填 | 说明       |
| -------- | -----------------| ---- | --------- |
| mode     | SceneMode        | 是   | 相机支持的模式。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [T extends Session](#session)   | Session实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function createSession(cameraManager: camera.CameraManager, mode: camera.SceneMode): camera.Session | undefined {
  let photoSession: camera.PhotoSession | undefined = undefined;
  try {
    photoSession = cameraManager.createSession(mode.NORMAL_PHOTO);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`createCaptureSession error. error code: ${err.code}`);
  }
  return photoSession;
}
```

### on('cameraStatus')

on(type: 'cameraStatus', callback: AsyncCallback\<CameraStatusInfo\>): void

相机设备状态回调，通过注册回调函数获取相机的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型            | 必填 | 说明       |
| -------- | -----------------| ---- | --------- |
| type     | string           | 是   | 监听事件，固定为'cameraStatus'。cameraManager对象获取成功后可监听。目前只支持对设备打开或者关闭会触发该事件并返回对应信息。 |
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | 是   | 回调函数，用于获取镜头状态变化信息。 |                 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    console.info(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.info(`status: ${cameraStatusInfo.status}`);
  });
}
```

### off('cameraStatus')

off(type: 'cameraStatus', callback?: AsyncCallback\<CameraStatusInfo\>): void

相机设备状态注销回调，通过注销回调函数取消获取相机的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型            | 必填 | 说明       |
| -------- | -----------------| ---- | --------- |
| type     | string           | 是   | 监听事件，固定为'cameraStatus'。cameraManager对象获取成功后可监听。 |
| callback | AsyncCallback\<[CameraStatusInfo](#camerastatusinfo)\> | 否   | 可选参数，有表明匹配on接口callback。 |

**示例：**

```ts
function unregisterCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.off('cameraStatus');
}
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback\<boolean\>): void

禁用回调，通过注册回调函数获取相机禁用状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。系统设置打开或禁用相机会触发该事件并返回状态。 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，用于获取禁用状态变化信息，返回true是开启状态，返回false是禁用状态。               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', (err: BusinessError, curMuted: boolean) => {
    let isMuted: boolean = curMuted;
    console.info(`cameraMute status: ${isMuted}`);
  })
}
```

### off('cameraMute')

off(type: 'cameraMute', callback?: AsyncCallback\<boolean\>): void

禁用回调，通过注销注册回调函数获取相机禁用状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。 |
| callback | AsyncCallback\<boolean> | 否   | 回调函数，可选参数，有表明匹配on接口callback。               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, curMuetd: boolean): void {
  let isMuted: boolean = curMuetd;
}

function unregisterCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', callback);
  cameraManager.off('cameraMute', callback);
}
```

### isPrelaunchSupported

isPrelaunchSupported(camera: CameraDevice): boolean

检查指定cameraDevice是否支持预热启动。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| camera | [CameraDevice](#cameradevice) | 是 | 相机信息。|

**返回值：**

| 类型 | 说明 |
| -------- | --------------- |
| boolean | 返回指定cameraDevice是否支持预热启动。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import common from '@ohos.app.ability.common';

function isPreLaunchSupported(context: common.BaseContext): boolean {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  let isSupported: boolean = false;
  if (cameras && cameras.length >= 1) {
    isSupported = cameraManager.isPrelaunchSupported(cameras[0]);
    console.info(`PreLaunch supported states: ${isSupported}`);
    return isSupported;
  }
  return isSupported;
}
```

### setPrelaunchConfig

setPrelaunchConfig(prelaunchConfig: PrelaunchConfig): void

设置预热启动的配置参数。

在调用setPrelaunchConfig接口前，需要先检查设备是否支持预热启动，使用[isPrelaunchSupported](#isprelaunchsupported)判断指定cameraDevice是否支持预热启动。

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.CAMERA

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| prelaunchConfig | [PrelaunchConfig](#prelaunchconfig) | 是 | 预启动配置参数。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allow. |

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function setPrelaunchConfig(context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  if (cameras && cameras.length >= 1) {
    let cameraDevice: camera.CameraDevice = cameras[0];
    if(cameraManager.isPrelaunchSupported(cameraDevice)) {
      try {
        cameraManager.setPrelaunchConfig({cameraDevice: cameraDevice});
      } catch (error) {
        let err = error as BusinessError;
        console.error(`setPrelaunchConfig error. Code: ${err.code}, message: ${err.message}`);
      }
    }
  }
}
```

### prelaunch

prelaunch(): void

用户点击系统相机图标，拉起相机应用同时调用，下发预热请求，使能相机预热启动。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function preLaunch(context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  try {
    cameraManager.prelaunch();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prelaunch error. Code: ${err.code}, message: ${err.message}`);
  }
}
```

### createDeferredPreviewOutput

createDeferredPreviewOutput(profile: Profile): PreviewOutput

创建延迟预览输出对象，在配流时替代普通的预览输出对象加入数据流。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| profile | [Profile](#profile) | 是 | 相机预览流的配置文件。 |

**返回值：**

| 类型 | 说明 |
| -------- | --------------- |
| [PreviewOutput](#previewoutput) | 返回预览输出对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import common from '@ohos.app.ability.common';

function getDeferredPreviewOutput(context: common.BaseContext, previewProfile: camera.Profile): camera.PreviewOutput {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const output: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  return output;
}
```

### preSwitchCamera<sup>11+</sup>

preSwitchCamera(cameraId: string): void

预切换摄像头，提升摄像头启动速度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| cameraId | string | 是 | CameraDevice对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

function preSwitch(cameraDevice: camera.CameraDevice, context: common.BaseContext): void {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  try {
    cameraManager.preSwitchCamera(cameraDevice.cameraId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prelaunch error. Code: ${err.code}, message: ${err.message}`);
  }
}
```

### isTorchSupported<sup>11+</sup>

isTorchSupported(): boolean

检测设备是否支持手电筒。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示设备支持手电筒。 |

**示例：**

```ts
function isTorchSupported(cameraManager: camera.CameraManager): boolean {
  let isSupported = cameraManager.isTorchSupported();
  return isSupported;
}
```

### isTorchModeSupported<sup>11+</sup>

isTorchModeSupported(mode: TorchMode): boolean

检测是否支持设置的手电筒模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](#torchmode) | 是 | 手电筒模式。 |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示设备支持设置的手电筒模式。 |

**示例：**

```ts
function isTorchModeSupported(cameraManager: camera.CameraManager, torchMode: camera.TorchMode): boolean {
  let isSupported = cameraManager.isTorchModeSupported(torchMode);
  return isSupported;
}
```

### getTorchMode<sup>11+</sup>

getTorchMode(): TorchMode

获取当前设备手电筒模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [TorchMode](#torchmode)    | 返回设备当前手电筒模式。 |

**示例：**

```ts
function getTorchMode(cameraManager: camera.CameraManager): camera.TorchMode | undefined {
  let torchMode: camera.TorchMode | undefined = undefined;
  torchMode = cameraManager.getTorchMode();
  return torchMode;
}
```

### setTorchMode<sup>11+</sup>

setTorchMode(mode: TorchMode): void

设置设备手电筒模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| mode | [TorchMode](#torchmode) | 是 | 手电筒模式。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setTorchMode(cameraManager: camera.CameraManager, torchMode: camera.TorchMode): void {
  try {
    cameraManager.setTorchMode(torchMode);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setTorchMode call failed. error code: ${err.code}`);
  }
}
```

### on('torchStatusChange')<sup>11+</sup>

on(type: 'torchStatusChange', callback: AsyncCallback\<TorchStatusInfo\>): void

手电筒状态变化回调，通过注册回调函数获取手电筒状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'torchStatusChange'。cameraManager对象获取成功后可监听。目前只支持手电筒打开，手电筒关闭，手电筒不可用，手电筒恢复可用会触发该事件并返回对应信息。 |
| callback | AsyncCallback\<TorchStatusInfo> | 是   | 回调函数，用于获取手电筒状态变化信息。               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerTorchStatusChange(cameraManager: camera.CameraManager): void {
  let callback = (err: BusinessError, torchStatusInfo: camera.TorchStatusInfo): void => {
    console.info('onTorchStatusChange, isTorchAvailable: ${torchStatusInfo.isTorchAvailable}, isTorchActive: ${torchStatusInfo.isTorchActive}, level: ${torchStatusInfo.torchLevel}');
  };
  cameraManager.on('torchStatusChange', callback);
}
```

### off('torchStatusChange')<sup>11+</sup>

off(type: 'torchStatusChange', callback?: AsyncCallback\<TorchStatusInfo\>): void

手电筒状态变化注销回调，通过注销回调函数取消获取手电筒状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'torchStatusChange'。cameraManager对象获取成功后可监听。 |
| callback | AsyncCallback\<TorchStatusInfo> | 否   | 回调函数，可选参数，有表明匹配on接口callback。               |

**示例：**

```ts
function unregisterTorchStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.off('torchStatusChange');
}
```

## PrelaunchConfig

相机预启动配置参数。

当前sensor级别预热，待扩展流预热参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| cameraDevice | [CameraDevice](#cameradevice) |        是       | 相机信息。 |
| restoreParamType<sup>11+</sup> | [RestoreParamType](#restoreparamtype11) |        否       | 预保存参数类型。 |
| activeTime<sup>11+</sup> | number |        否       | 激活时间，单位min。 |
| settingParam<sup>11+</sup> | [SettingParam](#settingparam11) |        否       | 设置参数内容。 |

## RestoreParamType<sup>11+</sup>

预保存参数类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 值    | 说明     |
| ----------------| ----  | ---------|
| NO_NEED_RESTORE_PARAM           | 0      | 不需要预保存参数类型。     |
| PRESISTENT_DEFAULT_PARAM    | 1      | 持久化参数类型，指某一时间点后，使用该参数恢复流信息。     |
| TRANSIENT_ACTIVE_PARAM   | 2      | 临时参数类型，只在关闭相机后一段时间内，使用该参数恢复流信息，优先级高于持久化参数。     |

## SettingParam<sup>11+</sup>

用于预热出图的效果参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| skinSmoothLevel | number |        是       | 美颜类型光滑信息，从[getSupportedBeautyRange](#getsupportedbeautyrange)获取支持的光滑范围，例如1表示1级光滑。 |
| faceSlender | number |        是        | 美颜类型瘦脸信息，从[getSupportedBeautyRange](#getsupportedbeautyrange)获取支持的瘦脸范围，例如1表示1级瘦脸。 |
| skinTone | number |        是        | 美颜类型肤色信息，从[getSupportedBeautyRange](#getsupportedbeautyrange)获取支持的肤色范围，例如0xBF986C表示一个颜色。 |

## TorchMode<sup>11+</sup>

枚举，手电筒模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值   | 说明           |
| ---------------------------- | ---- | ------------- |
| OFF    | 0    | 常关模式。      |
| ON  | 1    | 常开模式。 |
| AUTO      | 2    | 自动模式。 |

## TorchStatusInfo<sup>11+</sup>

手电筒回调返回的接口实例，表示手电筒状态信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称           | 类型                                | 只读 | 说明        |
| -------------- | --------------------------------- | ---- | ---------- |
| isTorchAvailable       | boolean   | 是   | 手电筒是否可用。|
| isTorchActive | boolean | 是   | 手电筒是否被激活。    |
| torchLevel     | number  | 是   | 手电筒亮度等级。取值范围为[0,1]，越靠近1，亮度越大。    |

## Size

输出能力查询。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型   | 可读 | 可写 | 说明         |
| ------ | ------ | ---- | ---- | ------------ |
| height | number | 是   | 是   | 图像尺寸高(像素)。 |
| width  | number | 是   | 是   | 图像尺寸宽(像素)。 |

## Point

点坐标用于对焦、曝光配置。

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
| CAMERA_FORMAT_YCBCR_P010<sup>11+</sup> |   2001    | YCBCR_P010格式的图片。      |
| CAMERA_FORMAT_YCRCB_P010<sup>11+</sup> |   2002    | YCRCB_P010 格式的图片。            |

## CameraInput

相机设备输入对象。

会话中[CaptureSession](#capturesession)使用的相机信息。

### open

open(callback: AsyncCallback\<void\>): void

打开相机，通过注册回调函数获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                  | 必填 | 说明                  |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open((err: BusinessError) => {
    if (err) {
      console.error(`Failed to open the camera, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera opened.');
  });
}
```

### open

open(): Promise\<void\>

打开相机，通过Promise获取相机的状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400107                |  Can not use camera cause of conflict.               |
| 7400108                |  Camera disabled cause of security reason.                                  |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function openCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.open().then(() => {
    console.info('Promise returned with camera opened.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to open the camera, error code: ${err.code}.`);
  });
}
```

### close

close(callback: AsyncCallback\<void\>\): void

关闭相机，通过注册回调函数获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close((err: BusinessError) => {
    if (err) {
      console.error(`Failed to close the cameras, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with camera closed.');
  });
}
```

### close

close(): Promise\<void\>

关闭相机，通过Promise获取状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function closeCameraInput(cameraInput: camera.CameraInput): void {
  cameraInput.close().then(() => {
    console.info('Promise returned with camera closed.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to close the cameras, error code: ${err.code}.`);
  });
}
```

### on('error')

on(type: 'error', camera: CameraDevice, callback: ErrorCallback): void

监听CameraInput的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'error'，CameraInput对象创建成功可监听。相机设备出错情况下可触发该事件并返回结果，比如（设备不可用或者冲突等返回对应错误信息）。 |
| cameraDevice   | [CameraDevice](#cameradevice)    | 是   | CameraDevice对象。 |
| callback | ErrorCallback | 是   | 回调函数，用于获取结果。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.on('error', cameraDevice, (error: BusinessError) => {
    console.error(`Camera input error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', camera: CameraDevice, callback?: ErrorCallback): void

注销监听CameraInput的错误事件。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'error'，CameraInput对象创建成功可监听。相机设备出错情况下可触发该事件并返回结果，比如（设备不可用或者冲突等返回对应错误信息）。 |
| cameraDevice   | [CameraDevice](#cameradevice)    | 是   | CameraDevice对象。 |
| callback | ErrorCallback | 否   | 回调函数，可选，有就是匹配on('error') callback。   |

**示例：**

```ts
function unregisterCameraInputError(cameraInput: camera.CameraInput, cameraDevice: camera.CameraDevice): void {
  cameraInput.off('error', cameraDevice);
}
```

## CameraOutput

会话中[CaptureSession](#capturesession)使用的输出信息，output的基类。

### release

release(callback: AsyncCallback\<void\>): void

释放输出资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the PreviewOutput instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the previewOutput instance is released successfully.');
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the VideoOutput instance ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate that the videoOutput instance is released successfully.');
  });
}
```

### release

release(): Promise\<void\>

释放输出资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function releasePreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.release().then(() => {
    console.info('Promise returned to indicate that the PreviewOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error('Failed to previewOutput release '+ err.code);
  });
}

function releaseVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.release().then(() => {
    console.info('Promise returned to indicate that the VideoOutput instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error('Failed to videoOutput release '+ err.code);
  });
}
```

## PreviewOutput

预览输出类。继承[CameraOutput](#cameraoutput)。

### start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

开始输出预览流，通过注册回调函数获取结果。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.start](#start-4)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the previewOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with previewOutput started.');
  });
}
```

### start<sup>(deprecated)</sup>

start(): Promise\<void\>

开始输出预览流，通过Promise获取结果。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.start](#start-5)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.start().then(() => {
    console.info('Promise returned with previewOutput started.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to previewOutput start, error code: ${err.code}.`);
  });
}
```

### stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

停止输出预览流，通过注册回调函数获取结果。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.stop](#stop-4)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the previewOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Returned with previewOutput stopped.');
  })
}
```

### stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

停止输出预览流，通过Promise获取结果。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.stop](#stop-5)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopPreviewOutput(previewOutput: camera.PreviewOutput): void {
  previewOutput.stop().then(() => {
    console.info('Callback returned with previewOutput stopped.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to previewOutput stop, error code: ${err.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

监听预览帧启动，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                     |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，previewOutput创建成功可监听。底层第一次开始曝光时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明预览开始。                    |

**示例：**

```ts
function registerPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameStart', () => {
    console.info('Preview frame started');
  });
}
```

### off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

注销监听预览帧启动。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                     |
| -------- | -------------------- | ---- | --------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，previewOutput创建成功可监听。 |
| callback | AsyncCallback\<void\> | 否   | 回调函数，可选，有表明匹配on接口callback。                     |

**示例：**

```ts
function unregisterPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameStart');
}
```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

监听预览帧结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，previewOutput创建成功可监听。预览完全结束最后一帧时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。只要有该事件返回就证明预览结束。                |

**示例：**

```ts
function registerPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('frameEnd', () => {
    console.info('Preview frame ended');
  });
}
```

### off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

注销监听预览帧结束。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                  |
| -------- | -------------------- | ---- | ------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，previewOutput创建成功可监听。 |
| callback | AsyncCallback\<void\> | 否   |  回调函数，可选，有表明匹配on接口callback。                |

**示例：**

```ts
function unregisterPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听预览输出的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | 是   | 监听事件，固定为'error'，previewOutput创建成功可监听。预览接口使用错误时触发该事件，比如调用（[Session.start](#start-5)，[CameraOutput.release](#release-1)）等接口发生错误时返回对应错误信息。|
| callback | ErrorCallback | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('error', (previewOutputError: BusinessError) => {
    console.error(`Preview output error code: ${previewOutputError.code}`);
  })
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听预览输出的错误事件。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | 是   | 监听事件，固定为'error'，previewOutput创建成功可监听。|
| callback | ErrorCallback | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterPreviewOutputError(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('error');
}
```

### addDeferredSurface

addDeferredSurface(surfaceId: string): void

配置延迟预览的Surface，可以在session.commitConfig()配流和session.start()启流之后运行。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | 是 | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |

**示例：**

```ts
import common from '@ohos.app.ability.common';

async function preview(context: common.BaseContext, cameraInfo: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, photoSurfaceId: string, previewSurfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraInfo)
  const previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, photoSurfaceId);
  const session: camera.CaptureSession  = cameraManager.createCaptureSession();
  session.beginConfig();
  session.addInput(cameraInput);
  session.addOutput(previewOutput);
  session.addOutput(photoOutput);
  await session.commitConfig();
  await session.start();
  previewOutput.addDeferredSurface(previewSurfaceId);
}
```

### isSketchSupported<sup>11+</sup>

isSketchSupported(): boolean

查询是否支持画中画能力。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 返回是否支持画中画。 |

**示例：**

```ts
function isSketchSupported(previewOutput: camera.PreviewOutput): boolean {
  let isSupported: boolean = previewOutput.isSketchSupported();
  return isSupported;
}
```

### getSketchRatio<sup>11+</sup>

getSketchRatio(): number

获取当前状态下启动画中画的Zoom倍率。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| number | 当前状态下启动画中画的Zoom倍率。不支持画中画的情况下，该接口返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
function getSketchRatio(previewOutput: camera.PreviewOutput): number {
  let sketchRatio: number = previewOutput.getSketchRatio();
  return sketchRatio;
}
```

### enableSketch<sup>11+</sup>

enableSketch(enabled: boolean): void

使能画中画。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| enabled | boolean | 是 | true表明开启画中画流进行预览。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function enableSketch(previewOutput: camera.PreviewOutput, captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.beginConfig();
    captureSession.addInput(cameraInput);
    captureSession.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    captureSession.commitConfig();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The enableSketch call failed. error code: ${err.code}`);
  }
}
```

### attachSketchSurface<sup>11+</sup>

attachSketchSurface(surfaceId: string): void

添加画中画预览的Surface。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | 是 | 从[XComponent](../arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function attachSketchSurface(previewOutput: camera.PreviewOutput, captureSession: camera.CaptureSession, cameraInput: camera.CameraInput, sketchSurfaceId: string): void {
  try {
    captureSession.beginConfig();
    captureSession.addInput(cameraInput);
    captureSession.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    captureSession.commitConfig();
    previewOutput.attachSketchSurface(sketchSurfaceId);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The attachSketchSurface call failed. error code: ${err.code}`);
  }
}
```

### on('sketchStatusChanged')<sup>11+</sup>

on(type: 'sketchStatusChanged', callback: AsyncCallback\<SketchStatusData\>): void

监听画中画状态信息改变，通过注册回调函数获取SketchStatusData。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'sketchStatusChanged'，画中画流创建成功后可监听。底层画中画的状态启停以及画中画Zoom值变更会回调该接口。 |
| callback | AsyncCallback\<SketchStatusData\> | 是   | 使用callback的方式获取SketchStatusData。            |

**示例：**

```ts
function registerSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('sketchStatusChanged', (errorCode: number, data: camera.SketchStatusData) => {
    console.info(`sketch errorCode is ${errorCode}, data is ${JSON.stringify(data)}`);
  });
}
```

### off('sketchStatusChanged')<sup>11+</sup>

off(type: 'sketchStatusChanged', callback?: AsyncCallback\<SketchStatusData\>): void

注销监听画中画状态信息改变。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'sketchStatusChanged'，画中画流创建成功后可监听。 |
| callback | AsyncCallback\<SketchStatusData\> | 否   | 回调函数，可选。            |

**示例：**

```ts
function unregisterSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('sketchStatusChanged');
}
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

| 名称      | 类型                            | 必填  | 说明                                                                   |
| -------- | ------------------------------- | ---- |----------------------------------------------------------------------|
| quality  | [QualityLevel](#qualitylevel)   | 否   | 图片质量(默认低)。                                                           |
| rotation | [ImageRotation](#imagerotation) | 否   | 图片旋转角度(默认0度，顺时针旋转)。                                                  |
| location | [Location](#location)           | 否   | 图片地理位置信息(默认以设备硬件信息为准)。                                               |
| mirror   | boolean                         | 否   | 镜像使能开关(默认关)。使用之前需要使用[isMirrorSupported](#ismirrorsupported)进行判断是否支持。 |

## DeferredDeliveryImageType<sup>11+</sup>

枚举，分段式能力类型。即将拍照/录像分为两个阶段，一阶段以较快速度输出图片/视频提供给用户，二阶段完成优化处理，重新输出高质量图片/视频。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称    | 值   | 说明         |
| ------- | ---- | ------------ |
| NONE    | 0    | 无分段式能力。|
| PHOTO   | 1    | 分段式拍照。|
| VIDEO   | 2    | 分段式录像。|

## DeferredPhotoProxy<sup>11+</sup>

类对象，缩略图代理类。

### getThumbnail

getThumbnail(): Promise<image.PixelMap>

通过缩略图代理类提供的方法，获取缩略图 PixelMap。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<image.PixelMap\> | 缩略图 PixelMap。 |

**示例：**

```ts
function getThumbnail(proxyObj: camera.DeferredPhotoProxy): void => {
	proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
		AppStorage.setOrCreate('proxyThumbnail', thumbnail);
	});
}
```

### release

release(): Promise\<void\>

释放输出资源，通过Promise获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**示例：**

```ts
async function releaseDeferredPhotoProxy(proxyObj: camera.DeferredPhotoProxy): void => {
	await proxyObj.release();
}
```

## Photo

全质量图对象。

### 属性

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                            |     必填     | 说明       |
| ------ | ----------------------------- | -------------- | ---------- |
| main | [image.Image](js-apis-image.md#image9) |        是       | 全质量图Image。 |

### release

release(): Promise\<void\>

释放输出资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**示例：**

```ts
async function releaseDeferredPhotoProxy(photo: camera.Photo): void => {
	await photo.release();
}
```

## PhotoOutput

拍照会话中使用的输出信息，继承[CameraOutput](#cameraoutput)。

### capture

capture(callback: AsyncCallback\<void\>): void

以默认设置触发一次拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  photoOutput.capture((err: BusinessError) => {
    if (err) {
      console.error(`Failed to capture the photo, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(): Promise\<void\>

以默认设置触发一次拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  photoOutput.capture().then(() => {
    console.info('Promise returned to indicate that photo capture request success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to photoOutput capture, error code: ${err.code}.`);
  });
}
```

### capture

capture(setting: PhotoCaptureSetting, callback: AsyncCallback\<void\>): void

以指定参数触发一次拍照，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                         | 必填 | 说明                  |
| -------- | ------------------------------------------- | ---- | -------------------- |
| setting  | [PhotoCaptureSetting](#photocapturesetting) | 是   | 拍照设置。             |
| callback | AsyncCallback\<void\>                        | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings, (err: BusinessError) => {
    if (err) {
      console.error(`Failed to capture the photo, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the photo capture request success.');
  });
}
```

### capture

capture(setting: PhotoCaptureSetting): Promise\<void\>

以指定参数触发一次拍照，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                         | 必填 | 说明      |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](#photocapturesetting) | 是   | 拍照设置，传入undefined类型数据按默认无参处理。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function capture(photoOutput: camera.PhotoOutput): void {
  let captureLocation: camera.Location = {
    latitude: 0,
    longitude: 0,
    altitude: 0
  }
  let settings: camera.PhotoCaptureSetting = {
    quality: camera.QualityLevel.QUALITY_LEVEL_LOW,
    rotation: camera.ImageRotation.ROTATION_0,
    location: captureLocation,
    mirror: false
  }
  photoOutput.capture(settings).then(() => {
    console.info('Promise returned to indicate that photo capture request success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to photoOutput capture, error code: ${err.code}.`);
  });
}
```

### confirmCapture<sup>11+</sup>

confirmCapture(): void

确认拍照，一般用于夜景模式下，在曝光倒计时过程中如需终止倒计时提前拍照的时候调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function confirmCapture(photoOutput: camera.PhotoOutput): void {
  try {
    photoOutput.confirmCapture();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The confirmCapture call failed. error code: ${err.code}`);
  }
}
```

### isDeferredImageDeliverySupported<sup>11+</sup>

isDeferredImageDeliverySupported(type: DeferredDeliveryImageType): boolean

查询当前模式是否支持相关分段式能力。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型               | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   是   |   分段式能力类型。    |

**返回值：**

| 类型            | 说明                    |
| -------------- | ----------------------- |
| boolean | true: 当前模式支持该类型分段式能力， false: 不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**示例：**

```ts
function isDeferredImageDeliverySupported(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): boolean {
	let res: boolean = false;
	res = photoOutPut.isDeferredImageDeliverySupported(type);
	return res;
}
```

### isDeferredImageDeliveryEnabled<sup>11+</sup>

isDeferredImageDeliveryEnabled(type: DeferredDeliveryImageType): boolean

查询当前模式是否已开启相关分段式能力。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型               | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   是   |   分段式能力类型。    |

**返回值：**

| 类型            | 说明                    |
| -------------- | ----------------------- |
| boolean | true: 当前模式已开启该类型分段式能力， false: 未开启。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**示例：**

```ts
function isDeferredImageDeliveryEnabled(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): boolean {
	let res: boolean = false;
	res = photoOutPut.isDeferredImageDeliveryEnabled(type);
	return res;
}
```

### deferImageDelivery<sup>11+</sup>

deferImageDelivery(type: DeferredDeliveryImageType): void

开启相关类型分段式能力。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型               | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
|   type   |  [DeferredDeliveryImageType](#deferreddeliveryimagetype11)  |   是   |   分段式能力类型。    |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**示例：**

```ts
function deferImageDelivery(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): void {
	photoOutPut.deferImageDelivery(type);
}
```

### on('photoAvailable')<sup>11+</sup>

on(type: 'photoAvailable', callback: AsyncCallback\<Photo\>): void

注册监听全质量图上报。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'photoAvailable'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[Photo](#photo)\> | 是   | 回调函数，用于监听全质量图上报。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputPhotoAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('photoAvailable', (err: BusinessError, photo: camera.Photo) => {
	let mainImage: image.Image = photo.main;
  });
}
```

### off('photoAvailable')<sup>11+</sup>

off(type: 'photoAvailable', callback?: AsyncCallback\<Photo\>): void

注销监听全质量图上报。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'photoAvailable'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[Photo](#photo)\> | 否   | 回调函数，可选，有表明匹配on接口callback。            |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function unRegisterPhotoOutputPhotoAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('photoAvailable', (err: BusinessError, photo: camera.Photo) => {
	let mainImage: image.Image = photo.main;
  });
}
```

### on('deferredPhotoProxyAvailable')<sup>11+</sup>

on(type: 'deferredPhotoProxyAvailable', callback: AsyncCallback\<DeferredPhotoProxy\>): void

注册监听缩略图上报。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'deferredPhotoProxyAvailable'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | 是   | 回调函数，用于获取相关信息。用于监听缩略图上报。|

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('deferredPhotoProxyAvailable', (err: BusinessError, proxyObj: camera.DeferredPhotoProxy) => {
	proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
		AppStorage.setOrCreate('proxyThumbnail', thumbnail);});
  });
}
```

### off('deferredPhotoProxyAvailable')<sup>11+</sup>

off(type: 'deferredPhotoProxyAvailable', callback?: AsyncCallback\<DeferredPhotoProxy\>): void

注销监听缩略图上报。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'deferredPhotoProxyAvailable'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。            |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function unRegisterPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('deferredPhotoProxyAvailable', (err: BusinessError, proxyObj: camera.DeferredPhotoProxy) => {
	proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
		AppStorage.setOrCreate('proxyThumbnail', thumbnail);});
  });
}
```

### on('captureStartWithInfo')<sup>11+</sup>

on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void

监听拍照开始，通过注册回调函数获取CaptureStartInfo。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'captureStartWithInfo'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo)\> | 是   | 使用callback的方式获取Capture ID。|

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureStartWithInfo', (err: BusinessError, captureStartInfo: camera.CaptureStartInfo) => {
    console.info(`photo capture started, captureStartInfo : ${captureStartInfo}`);
  });
}
```

### off('captureStartWithInfo')<sup>11+</sup>

off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo\>): void

注销监听拍照。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'captureStartWithInfo'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[CaptureStartInfo](#capturestartinfo11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。            |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function unRegisterCaptureStartWithInfo(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStartWithInfo');
}
```

### isMirrorSupported

isMirrorSupported(): boolean

查询是否支持镜像拍照。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 返回是否支持镜像拍照，true表示支持，false表示不支持。 |

**示例：**

```ts
function isMirrorSupported(photoOutput: camera.PhotoOutput): boolean {
  let isSupported: boolean = photoOutput.isMirrorSupported();
  return isSupported;
}
```

### on('captureStart')<sup>(deprecated)</sup>

on(type: 'captureStart', callback: AsyncCallback\<number\>): void

监听拍照开始，通过注册回调函数获取Capture ID。

> **说明：** 
>从 API version 10开始支持，从API version 11开始废弃。建议使用[on('captureStartWithInfo')](#oncapturestartwithinfo11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'captureStart'，photoOutput创建成功后可监听。每次拍照，底层开始曝光时触发该事件并返回。 |
| callback | AsyncCallback\<number\> | 是   | 使用callback的方式获取Capture ID。            |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureStart', (err: BusinessError, captureId: number) => {
    console.info(`photo capture started, captureId : ${captureId}`);
  });
}
```

### off('captureStart')<sup>(deprecated)</sup>

off(type: 'captureStart', callback?: AsyncCallback\<number\>): void

注销监听拍照开始。

> **说明：**  
>从 API version 10开始支持，从API version 11开始废弃。建议使用[off('captureStartWithInfo')](#offcapturestartwithinfo11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'captureStart'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<number\> | 否   | 回调函数，可选，有表明匹配on接口callback。            |

**示例：**

```ts
function unregisterPhotoOutputCaptureStart(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureStart');
}
```

### on('frameShutter')

on(type: 'frameShutter', callback: AsyncCallback\<FrameShutterInfo\>): void

监听拍照帧输出捕获，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'frameShutter'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | 是   | 回调函数，用于获取相关信息。该回调返回意味着可以再次下发拍照请求。             |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('frameShutter', (err: BusinessError, frameShutterInfo: camera.FrameShutterInfo) => {
    console.info(`CaptureId for frame : ${frameShutterInfo.captureId}`);
    console.info(`Timestamp for frame : ${frameShutterInfo.timestamp}`);
  });
}
```

### off('frameShutter')

off(type: 'frameShutter', callback?: AsyncCallback\<FrameShutterInfo\>): void

注销监听拍照帧输出捕获。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'frameShutter'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[FrameShutterInfo](#frameshutterinfo)\> | 否   | 回调函数，可选，有表明匹配on接口callback。             |

**示例：**

```ts
function unregisterPhotoOutputFrameShutter(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('frameShutter');
}
```

### on('captureEnd')

on(type: 'captureEnd', callback: AsyncCallback\<CaptureEndInfo\>): void

监听拍照结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型           | 必填 | 说明                                       |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | 是   | 监听事件，固定为'captureEnd'，photoOutput创建成功后可监听。拍照完全结束可触发该事件发生并返回相应信息。 |
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | 是   | 回调函数，用于获取相关信息。                  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('captureEnd', (err: BusinessError, captureEndInfo: camera.CaptureEndInfo) => {
    console.info(`photo capture end, captureId : ${captureEndInfo.captureId}`);
    console.info(`frameCount : ${captureEndInfo.frameCount}`);
  });
}
```

### off('captureEnd')

off(type: 'captureEnd', callback?: AsyncCallback\<CaptureEndInfo\>): void

注销监听拍照结束。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型           | 必填 | 说明                                       |
| -------- | --------------- | ---- | ---------------------------------------- |
| type     | string          | 是   | 监听事件，固定为'captureEnd'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[CaptureEndInfo](#captureendinfo)\> | 否   | 回调函数，可选，有表明匹配on接口callback。                  |

**示例：**

```ts
function unregisterPhotoOutputCaptureEnd(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('captureEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听拍照输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | 是   | 监听事件，固定为'error'，photoOutput创建成功后可监听。拍照接口调用时出现错误触发该事件并返回错误信息。 |
| callback | ErrorCallback | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。             |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('error', (error: BusinessError) => {
    console.error(`Photo output error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听拍照输出发生错误。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | 是   | 监听事件，固定为'error'，photoOutput创建成功后可监听。 |
| callback | ErrorCallback | 否   | 回调函数，可选。          |

**示例：**

```ts
function unregisterPhotoOutputError(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('error');
}
```

### isQuickThumbnailSupported

isQuickThumbnailSupported(): boolean

是否支持输出快速缩略图。

在CaptureSession.addOutput、CaptureSession.addInput之后，CaptureSession.commitConfig之前生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型 | 说明 |
| --------- | ------ |
| boolean | 返回支持情况，如果返回true表示支持，否则不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**示例：**

```ts
import common from '@ohos.app.ability.common';

async function isQuickThumbnailSupported(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<boolean> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // 开始配置会话
  captureSession.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // 把photoOutput加入到会话
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  return isSupported;
}
```

### enableQuickThumbnail

enableQuickThumbnail(enabled: boolean): void

启用/禁用快速缩略图。

在CaptureSession.addOutput、CaptureSession.addInput之后，CaptureSession.commitConfig之前生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| enabled    | boolean       | 是   | true：使能快速缩略图；false：去使能快速缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400104                |  session is not running.        |

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

async function enableQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // 开始配置会话
  captureSession.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // 把PhotoOutPut加入到会话
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  if (!isSupported) {
    console.info('Quick Thumbnail is not supported to be turned on.');
    return;
  }
  try {
    photoOutput.enableQuickThumbnail(true);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);
  }
}
```

### on('quickThumbnail')

on(type: 'quickThumbnail', callback: AsyncCallback\<image.PixelMap>): void

监听快速缩略图输出事件。

在enableQuickThumbnail(true)使能快速缩略图之后监听生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type    | string     | 是   | 监听事件，固定为'quickThumbnail'。 |
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | 是 | 回调返回PixelMap。 |

**示例：**

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

async function registerQuickThumbnail(context: common.BaseContext, photoProfile: camera.Profile, surfaceId: string): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let captureSession: camera.CaptureSession = cameraManager.createCaptureSession();
  // 开始配置会话
  captureSession.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  captureSession.addInput(cameraInput);
  // 把PhotoOutPut加入到会话
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile, surfaceId);
  captureSession.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  if (!isSupported) {
    console.info('Quick Thumbnail is not supported to be turned on.');
    return;
  }
  try {
    photoOutput.enableQuickThumbnail(true);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The enableQuickThumbnail call failed. error code: ${err.code}`);
  }

  photoOutput.on('quickThumbnail', (err: BusinessError, pixelMap: image.PixelMap) => {
    if (err || pixelMap === undefined) {
      console.error('photoOutput on thumbnail failed');
      return;
    }
    // 显示或保存pixelMap
    // do something
  })
}
```

### off('quickThumbnail')

off(type: 'quickThumbnail', callback?: AsyncCallback\<image.PixelMap>): void

注销监听快速缩略图输出事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type    | string     | 是   | 监听事件，固定为'quickThumbnail'。 |
| callback | AsyncCallback\<[image.PixelMap](js-apis-image.md#pixelmap7)> | 否 | 回调函数，可选，有表明匹配on接口callback。 |

**示例：**

```ts
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('quickThumbnail');
}
```

## FrameShutterInfo

拍照帧输出信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   | 必填 | 说明         |
| --------- | ------ | ---- | ---------- |
| captureId | number | 是   | 拍照的ID。  |
| timestamp | number | 是   | 快门时间戳。 |

## CaptureStartInfo<sup>11+</sup>

拍照开始信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------|
| captureId  | number | 是   | 拍照的ID。 |
| time | number | 是   | 拍照时间戳。    |

## CaptureEndInfo

拍照停止信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型   | 必填 | 说明       |
| ---------- | ------ | ---- | ---------|
| captureId  | number | 是   | 拍照的ID。 |
| frameCount | number | 是   | 帧数。    |

## VideoOutput

录像会话中使用的输出信息，继承[CameraOutput](#cameraoutput)。

### start

start(callback: AsyncCallback\<void\>): void

启动录制，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the video output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the video output start success.');
  });
}
```

### start

start(): Promise\<void\>

启动录制，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to videoOutput start, error code: ${err.code}.`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

结束录制，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the video output, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the video output stop success.');
  });
}
```

### stop

stop(): Promise\<void\>

结束录制，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to videoOutput stop, error code: ${err.code}.`);
  });
}
```

### on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

监听录像开始，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始。                     |

**示例：**

```ts
function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameStart', () => {
    console.info('Video frame started');
  });
}
```

### off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

注销监听录像开始。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。 |
| callback | AsyncCallback\<void\> | 否   | 回调函数，可选，有表明匹配on接口callback。                     |

**示例：**

```ts
function unregisterVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameStart');
}

```

### on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

监听录像结束，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束。                      |

**示例：**

```ts
function registerVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameEnd', () => {
    console.info('Video frame ended');
  });
}
```

### off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

注销监听录像结束。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。 |
| callback | AsyncCallback\<void\> | 否   | 回调函数，可选，有表明匹配on接口callback。                      |

**示例：**

```ts
function unregisterVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameEnd');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听录像输出发生错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型       | 必填 | 说明                                    |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | 是   | 监听事件，固定为'error'，videoOutput创建成功后可监听。录像接口调用出现错误时触发该事件并返回对应错误码，比如调用（[start](#start-1)，[CameraOutput.release](#release-1)）接口时出现错误返回对应错误信息。 |
| callback | ErrorCallback | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。                 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.on('error', (error: BusinessError) => {
    console.error(`Video output error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听录像输出发生错误。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | 是   | 监听事件，固定为'error'，photoOutput创建成功后可监听。 |
| callback | ErrorCallback | 否   | 回调函数，可选，有表明匹配on接口callback。               |

**示例：**

```ts
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.off('error');
}
```

## MetadataOutput

metadata流。继承[CameraOutput](#cameraoutput)。

### start

start(callback: AsyncCallback\<void\>): void

开始输出metadata，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                 |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\>       | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start metadataOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadataOutput started.');
  });
}
```

### start

start(): Promise\<void\>

开始输出metadata，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                     | 说明                     |
| ----------------------  | ------------------------ |
| Promise\<void\>          | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.start().then(() => {
    console.info('Callback returned with metadataOutput started.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to metadataOutput stop, error code: ${err.code}`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

停止输出metadata，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                         | 必填 | 说明                  |
| -------- | -------------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\>       | 是   | 回调函数，用于获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the metadataOutput, error code: ${err.code}.`);
      return;
    }
    console.info('Callback returned with metadataOutput stopped.');
  })
}
```

### stop

stop(): Promise\<void\>

停止输出metadata，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                    | 说明                        |
| ----------------------  | --------------------------- |
| Promise\<void\>         | 使用Promise的方式获取结果。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.stop().then(() => {
    console.info('Callback returned with metadataOutput stopped.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to metadataOutput stop, error code: ${err.code}`);
  });
}
```

### on('metadataObjectsAvailable')

on(type: 'metadataObjectsAvailable', callback: AsyncCallback\<Array\<MetadataObject\>\>): void

监听检测到的metadata对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型         | 必填 | 说明                                  |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | 是   | 监听事件，固定为'metadataObjectsAvailable'，metadataOutput创建成功后可监听。检测到有效的metadata数据时触发该事件发生并返回相应的metadata数据。 |
| callback | Callback\<Array\<[MetadataObject](#metadataobject)\>\> | 是   | 回调函数，用于获取metadata数据。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
    console.info('metadata output metadataObjectsAvailable');
  });
}
```

### off('metadataObjectsAvailable')

off(type: 'metadataObjectsAvailable', callback?: AsyncCallback\<Array\<MetadataObject\>\>): void

注销监听检测到的metadata对象。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型         | 必填 | 说明                                  |
| -------- | -------------- | ---- | ------------------------------------ |
| type     | string         | 是   | 监听事件，固定为'metadataObjectsAvailable'，metadataOutput创建成功后可监听。 |
| callback | Callback\<Array\<[MetadataObject](#metadataobject)\>\> | 否   | 回调函数，可选，有表明匹配on接口callback。 |

**示例：**

```ts
function unregisterMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.off('metadataObjectsAvailable');
}
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听metadata流的错误，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                     |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 监听事件，固定为'error'，metadataOutput创建成功后可监听。metadata接口使用错误时触发该事件并返回对应错误码，比如调用（[start](#start-3)，[CameraOutput.release](#release-1)）接口时发生错误返回对应错误信息。 |
| callback | ErrorCallback | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。            |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerMetadataOutputError(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.on('error', (metadataOutputError: BusinessError) => {
    console.error(`Metadata output error code: ${metadataOutputError.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听metadata流的错误。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                     |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 监听事件，固定为'error'，metadataOutput创建成功后可监听。 |
| callback | ErrorCallback | 否   | 回调函数，可选，有表明匹配on接口callback。           |

**示例：**

```ts
function unregisterMetadataOutputError(metadataOutput: camera.MetadataOutput): void {
  metadataOutput.off('error');
}
```

## MetadataObjectType

枚举，metadata流。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| ------------------------- | ---- | ----------------- |
| FACE_DETECTION            | 0    | metadata对象类型，用于人脸检测。<br> 检测点应在0-1坐标系内，该坐标系左上角为(0，0)，右下角为(1，1)。<br> 此坐标系以设备充电口在右侧时的横向设备方向为基准。<br>例如应用的预览界面布局以设备充电口在下侧时的竖向方向为基准，<br>布局宽高为(w，h)， 返回点为(x，y)，则转换后的坐标点为(1-y，x)。 |

## Rect

矩形定义。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型   |      必填     |           说明                 |
| -------- | ------ | --------------- | -------------------- |
| topLeftX | number |        是          | 矩形区域左上角x坐标。   |
| topLeftY | number |         是          | 矩形区域左上角y坐标。   |
| width    | number |         是         | 矩形宽，相对值，范围[0, 1]。  |
| height   | number |         是         | 矩形高，相对值，范围[0, 1]。  |

## MetadataObject

相机元能力信息，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.on('metadataObjectsAvailable')接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                            | 必填  | 只读 |说明              |
| -------- | ------------------------------- | ---- | ---- |-----------------|
| type  | [MetadataObjectType](#metadataobjecttype)   | 否   |  是  | metadata 类型。 |
| timestamp | number | 否   |  是  | 当前时间戳（毫秒）。 |
| boundingBox | [Rect](#rect)           | 否   |  是  | metadata 区域框。 |

## PortraitEffect

人像效果类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 值    | 说明     |
| ----------------| ----  | ---------|
| OFF             | 0      | 关闭。    |
| CIRCLES         | 1      | 圆形。    |
| HEART<sup>11+</sup>           | 2      | 心形。    |
| ROTATED<sup>11+</sup>         | 3      | 旋焦。    |
| STUDIO<sup>11+</sup>          | 4      | 影棚光。  |
| THEATER<sup>11+</sup>         | 5      | 剧场光。  |

## BeautyType

美颜类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 值    | 说明     |
| ----------------| ----  | ---------|
| AUTO           | 0      | 自动。     |
| SKIN_SMOOTH    | 1      | 光滑。     |
| FACE_SLENDER   | 2      | 瘦脸。     |
| SKIN_TONE      | 3      | 肤色。     |

## FlashMode

枚举，闪光灯模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                    | 值   | 说明        |
| ---------------------- | ---- | ---------- |
| FLASH_MODE_CLOSE       | 0    | 闪光灯关闭。 |
| FLASH_MODE_OPEN        | 1    | 闪光灯打开。 |
| FLASH_MODE_AUTO        | 2    | 自动闪光灯。 |
| FLASH_MODE_ALWAYS_OPEN | 3    | 闪光灯常亮。 |

## ManualExposure<sup>11+</sup>

手动曝光类，用于设置手动曝光参数。

### getSupportedExposureRange

getSupportedExposureRange(): Array\<number\>

获取当前支持的手动曝光时长，单位ms。

**系统接口：** 此接口为系统接口。
 
**系统能力：** SystemCapability.Multimedia.Camera.Core
 
**返回值：**
 
| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<number\>| 返回当前支持的手动曝光时长，单位ms。                             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.  |

 **示例：**
 
 ```ts
function getSupportedExposureRange(nightPhotoSession: camera.NightPhotoSession): Array<number> {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  return exposureRange;
}
```

### getExposure

getExposure(): number

查询当前已设置的手动曝光时长，单位为ms。

**系统接口：** 此接口为系统接口。
 
**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**
| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | 是   | 手动曝光时长，单位为ms。  |

**错误码：**
 
以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getExposure(portraitSession: camera.PortraitPhotoSession): number {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  let exposure: number = nightPhotoSession.getExposure();
  return exposure;
}
```

### setExposure

setExposure(exposure: number): void

设置手动曝光时长。[getSupportedExposureRange](#getsupportedexposurerange)获取得到支持的手动曝光时长列表选取用户所需的时长下发，单位ms。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                   |
| -------- | --------------------------| ---- | --------------------- |
| value    | number                    | 是   | 手动曝光时长，通过[getSupportedExposureRange](#getsupportedexposurerange)接口获取。|

 **错误码：**

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.  |

 ```ts
function setExposure(nightPhotoSession: camera.NightPhotoSession): void {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  nightPhotoSession.setExposure(exposureRange[0]);
}
```

## ExposureMode

枚举，曝光模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| EXPOSURE_MODE_LOCKED          | 0    | 锁定曝光模式。不支持曝光区域中心点设置。 |
| EXPOSURE_MODE_AUTO            | 1    | 自动曝光模式。支持曝光区域中心点设置，可以使用[setMeteringPoint](#setmeteringpoint)设置曝光区域中心点。 |
| EXPOSURE_MODE_CONTINUOUS_AUTO | 2    | 连续自动曝光。不支持曝光区域中心点设置。 |

## FocusMode

枚举，焦距模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                        | 值   | 说明          |
| -------------------------- | ---- | ------------ |
| FOCUS_MODE_MANUAL          | 0    | 手动对焦。通过手动修改相机焦距来改变对焦位置，不支持对焦点设置。     |
| FOCUS_MODE_CONTINUOUS_AUTO | 1    | 连续自动对焦。不支持对焦点设置。 |
| FOCUS_MODE_AUTO            | 2    | 自动对焦。支持对焦点设置，可以使用[setFocusPoint](#setfocuspoint)设置对焦点，根据对焦点执行一次自动对焦。    |
| FOCUS_MODE_LOCKED          | 3    | 对焦锁定。不支持对焦点设置。     |

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

## Macro

微距能力。

### isMacroSupported

isMacroSupported(): boolean

检测当前状态下是否支持微距能力，需要在CaptureSession调用commitConfig之后进行调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
|   boolean  | 返回是否支持微距能力。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
function isMacroSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = captureSession.isMacroSupported();
  return isSupported;
}
```

### enableMacro

enableMacro(enabled: boolean): void

使能当前的微距能力，需要在支持微距能力的情况下进行调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | 是   | true：开启微距能力，false：关闭微距能力。 |

**示例：**

```ts
function enableMacro(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = captureSession.isMacroSupported();
  if (isSupported) {
    captureSession.enableMacro(true);
  }
}
```

## Session<sup>11+</sup>

会话类，保存一次相机运行所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)，并向相机设备申请完成相机功能(录像，拍照)。

### beginConfig

beginConfig(): void

开始配置会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400105                |  Session config locked.               |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function beginConfig(captureSession: camera.CaptureSession): void {
  try {
    captureSession.beginConfig();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The beginConfig call failed. error code: ${err.code}`);
  }
}
```

### commitConfig

commitConfig(callback: AsyncCallback\<void\>): void

提交配置信息，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig((err: BusinessError) => {
    if (err) {
      console.error(`The commitConfig call failed. error code: ${err.code}`);
      return;
    }
    console.info('Callback invoked to indicate the commit config success.');
  });
}
```

### commitConfig

commitConfig(): Promise\<void\>

提交配置信息，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allow.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((err: BusinessError) => {
    // 失败返回错误码error.code并处理
    console.error(`The commitConfig call failed. error code: ${err.code}`);
  });
}
```

### canAddInput<sup>11+</sup>

canAddInput(cameraInput: CameraInput): boolean

判断当前cameraInput是否可以添加到session中。当前函数需要在Session.beginConfig()和Session.commitConfig()之间生效。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| boolean | 返回true表示支持添加当前cameraInput，返回false表示不支持添加。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function canAddInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
    let canAdd ：boolean = captureSession.canAddInput(cameraInput);
    console.error(`The input canAddInput : ${canAdd}`);
}
```

### addInput

addInput(cameraInput: CameraInput): void

把[CameraInput](#camerainput)加入到会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要添加的CameraInput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The addInput call failed. error code: ${err.code}`);
  }
}
```

### removeInput

removeInput(cameraInput: CameraInput): void

移除[CameraInput](#camerainput)。当前函数需要在Session.beginConfig()和Session.commitConfig()之间生效。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                      |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](#camerainput) | 是   | 需要移除的CameraInput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.removeInput(cameraInput);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

### canAddOutput<sup>11+</sup>

canAddOutput(cameraOutput: CameraOutput): boolean

判断当前cameraOutput是否可以添加到session中。当前函数需要在Session.addInput(cameraInput)和Session.commitConfig之间生效。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraOutput | [CameraOutput](#cameraoutput) | 是   | 需要添加的CameraOutput实例。 |

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| boolean | 是否可以添加当前cameraOutput到session中。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function canAddOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  let canAdd : boolean = captureSession.canAddOutput(cameraOutput);
  console.error(`This addOutput can add : ${canAdd}`);
}
```

### addOutput

addOutput(cameraOutput: CameraOutput): void

把[CameraOutput](#cameraoutput)加入到会话。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | 是   | 需要添加的CameraOutput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  try {
    captureSession.addOutput(cameraOutput);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

### removeOutput

removeOutput(cameraOutput: CameraOutput): void

从会话中移除[CameraOutput](#cameraoutput)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](#cameraoutput)   | 是   | 需要移除的CameraOutput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allow.                                  |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {
  try {
    captureSession.removeOutput(previewOutput);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

### start

start(callback: AsyncCallback\<void\>): void

开始会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session start success.');
  });
}
```

### start

start(): Promise\<void\>

开始会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start the session, error code: ${err.code}.`);
  });
}
```

### stop

stop(callback: AsyncCallback\<void\>): void

停止会话工作，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the session, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate the session stop success.');
  });
}
```

### stop

stop(): Promise\<void\>

停止会话工作，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop the session, error code: ${err.code}.`);
  });
}
```

### release

release(callback: AsyncCallback\<void\>): void

释放会话资源，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release((err: BusinessError) => {
    if (err) {
      console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
      return;
    }
    console.info('Callback invoked to indicate that the CaptureSession instance is released successfully.');
  });
}
```

### release

release(): Promise\<void\>

释放会话资源，通过Promise获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release().then(() => {
    console.info('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
  });
}
```

## Flash<sup>11+</sup>

闪光灯类，对设备闪光灯操作。

### hasFlash

hasFlash(): boolean

检测是否有闪光灯，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示设备支持闪光灯，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function hasFlash(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.hasFlash();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The hasFlash call failed. error code: ${err.code}`);
  }
  return status;
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
| boolean    | 返回true表示支持该闪光灯模式，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function isFlashModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);
  }
  return status;
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

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setFlashMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

### getFlashMode

getFlashMode(): FlashMode

获取当前设备的闪光灯模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FlashMode](#flashmode)    | 获取当前设备的闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = captureSession.getFlashMode();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```

## AutoExposure<sup>11+</sup>

自动曝光类，对设备自动曝光（AE）操作。

### isExposureModeSupported

isExposureModeSupported(aeMode: ExposureMode): boolean

检测曝光模式是否支持。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                      |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 获取是否支持曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function isExposureModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### getExposureMode

getExposureMode(): ExposureMode

获取当前曝光模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMode](#exposuremode)    | 获取当前曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = captureSession.getExposureMode();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

### setExposureMode

setExposureMode(aeMode: ExposureMode): void

设置曝光模式。进行设置之前，需要先检查设备是否支持指定的曝光模式，可使用方法[isExposureModeSupported](#isexposuremodesupported)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](#exposuremode)  | 是   | 曝光模式。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setExposureMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

### getMeteringPoint

getMeteringPoint(): Point

查询曝光区域中心点。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](#point)    | 获取当前曝光点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = captureSession.getMeteringPoint();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

### setMeteringPoint

setMeteringPoint(point: Point): void

设置曝光区域中心点，曝光点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。<br>此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以<br>设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，<br>则转换后的坐标点为{y/h，1-x/w}。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| exposurePoint | [Point](#point)                | 是   | 曝光点，x、y设置范围应在[0，1]之内，超过范围，如果小于0设置0，大于1设置1。             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setMeteringPoint(captureSession: camera.CaptureSession): void {
  const exposurePoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setMeteringPoint(exposurePoint);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

### getExposureBiasRange

getExposureBiasRange(): Array\<number\>

查询曝光补偿范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 获取补偿范围的数组。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getExposureBiasRange(captureSession: camera.CaptureSession): Array<number> {
  let biasRangeArray: Array<number> = [];
  try {
    biasRangeArray = captureSession.getExposureBiasRange();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);
  }
  return biasRangeArray;
}
```

### setExposureBias

setExposureBias(exposureBias: number): void

设置曝光补偿，曝光补偿值（EV）。

进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrange)查询支持的范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                 |
| -------- | -------------------------------| ---- | ------------------- |
| exposureBias   | number                   | 是   | 曝光补偿，getExposureBiasRange查询支持的范围，如果设置超过支持范围的值，自动匹配到就近临界点。<br>曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。<br>接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      captureSession.setExposureBias(exposureBias);
    } catch (error) {
      // 失败返回错误码error.code并处理
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

### getExposureValue

getExposureValue(): number

查询当前曝光值。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取曝光值。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。<br>接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getExposureValue(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = captureSession.getExposureValue();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

## Focus<sup>11+</sup>

对焦类，对设备对焦操作。

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
| boolean    | 返回true表示支持该焦距模式，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function isFocusModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
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

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setFocusMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

### getFocusMode

getFocusMode(): FocusMode

获取当前的对焦模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FocusMode](#focusmode)   | 获取当前设备的焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = captureSession.getFocusMode();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

### setFocusPoint

setFocusPoint(point: Point): void

设置焦点，焦点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。<br>此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以<br>设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，<br>则转换后的坐标点为{y/h，1-x/w}。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| point    | [Point](#point)         | 是   | 焦点。x、y设置范围应在[0，1]之内，超过范围，如果小于0设置0，大于1设置1。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setFocusPoint(captureSession: camera.CaptureSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setFocusPoint(focusPoint);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

### getFocusPoint

getFocusPoint(): Point

查询焦点。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](#point)    | 用于获取当前焦点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getFocusPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = captureSession.getFocusPoint();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

### getFocalLength

getFocalLength(): number

查询焦距值。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 用于获取当前焦距，单位mm。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getFocalLength(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = captureSession.getFocalLength();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

## SmoothZoomMode<sup>11+</sup>

平滑变焦模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 值   | 说明            |
| ------------ | ---- | -------------- |
| NORMAL       | 0    | 贝塞尔曲线模式。  |

## SmoothZoomInfo<sup>11+</sup>

平滑变焦参数信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称   -- | 类型       |   必填   | 说明       |
| -------- | ---------- | -------- | ---------- |
| duration |   number   |     是    | 平滑变焦总时长，单位ms。 |

## Zoom<sup>11+</sup>

变焦类，对设备变焦操作。

### getZoomRatioRange

getZoomRatioRange(): Array\<number\>

获取支持的变焦范围。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 用于获取可变焦距比范围，返回的数组包括其最小值和最大值。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getZoomRatioRange(captureSession: camera.CaptureSession): Array<number> {
  let zoomRatioRange: Array<number> = [];
  try {
    zoomRatioRange = captureSession.getZoomRatioRange();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);
  }
  return zoomRatioRange;
}
```

### setZoomRatio

setZoomRatio(zoomRatio: number): void

设置变焦比，变焦精度最高为小数点后两位，如果设置超过支持的精度范围，则只保留精度范围内数值。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                  | 必填 | 说明                 |
| --------- | -------------------- | ---- | ------------------- |
| zoomRatio | number               | 是   | 可变焦距比，通过[getZoomRatioRange](#getzoomratiorange)获取支持的变焦范围，如果设置超过支持范围的值，则只保留精度范围内数值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setZoomRatio(captureSession: camera.CaptureSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    captureSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

### getZoomRatio

getZoomRatio(): number

获取当前的变焦比。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取当前的变焦比结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getZoomRatio(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = captureSession.getZoomRatio();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

### setSmoothZoom

setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void

触发平滑变焦。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型            | 必填 | 说明               |
| ------------ | -------------- | ---- | ----------------- |
| targetRatio  | number         | 是   | 目标值。      |
| mode         | SmoothZoomMode | 否   | 模式。      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setSmoothZoom(sessionExtendsZoom: camera.Zoom, targetZoomRatio: number, mode: camera.SmoothZoomMode): void {
  try {
    sessionExtendsZoom.setSmoothZoom(targetZoomRatio, mode);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setSmoothZoom call failed. error code: ${err.code}`);
  }
}
```

### prepareZoom

prepareZoom(): void

通知底层准备变焦，如sensor上电。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function prepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.prepareZoom();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The prepareZoom call failed. error code: ${err.code}`);
  }
}
```

### unprepareZoom

unprepareZoom(): void

通知底层离开变焦准备状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function unprepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.unprepareZoom();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The unprepareZoom call failed. error code: ${err.code}`);
  }
}
```

## ZoomRange<sup>11+</sup>

获取支持的变焦范围。变焦范围为[min, max)，即包括最小值，不包括最大值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型           | 必填 | 只读 | 说明         |
| -------- | ------------- |---- | ---- | -------------|
| min      | number        | 是  |  是  | 获取的可变焦距范围的最小值。   |
| max      | number        | 是  |  是  | 获取的可变焦距范围的最大值。 |


## Stabilization<sup>11+</sup>

防抖类，对设备防抖操作。

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
| boolean    | 返回视频防抖模式是否支持，true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function isVideoStabilizationModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### getActiveVideoStabilizationMode

getActiveVideoStabilizationMode(): VideoStabilizationMode

查询当前正在使用的视频防抖模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [VideoStabilizationMode](#videostabilizationmode)    | 视频防抖是否正在使用。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = captureSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

### setVideoStabilizationMode

setVideoStabilizationMode(mode: VideoStabilizationMode): void

设置视频防抖模式。需要先检查设备是否支持对应的防抖模式，可以通过[isVideoStabilizationModeSupported](#isvideostabilizationmodesupported)方法判断所设置的模式是否支持。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](#videostabilizationmode) | 是   | 需要设置的视频防抖模式。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setVideoStabilizationMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```

## Beauty<sup>11+</sup>

美肤类，用于设置美肤参数。

### getSupportedBeautyTypes

getSupportedBeautyTypes(): Array\<BeautyType\>

获取当前支持的美颜效果列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| 返回当前支持的美颜效果列表。                             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyTypes(portraitSession: camera.PortraitSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```
### getSupportedBeautyRange

getSupportedBeautyRange(type: BeautyType): Array\<number\>

获取指定美颜效果的范围值。在不同设备返回的美颜强度有所不同，下表仅做示例。

| 传入参数           | 示例返回值    | 返回值说明     |
| ----------------| ----  | ---------|
| AUTO           | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     |美颜类型为自动时支持的美颜强度，0表明关闭美颜，其余正值表明自动的美颜强度。    |
| SKIN_SMOOTH    | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     | 美颜类型为光滑时支持的美颜强度，0表明关闭光滑，其余正值表明光滑的美颜强度。    |
| FACE_SLENDER   | [0, 1, 2, 3, 4, 5]      | 美颜类型为瘦脸时支持的美颜强度，0表明关闭瘦脸，其余正值表明瘦脸的美颜强度。   |
| SKIN_TONE      | [-1, 16242611]      | 美颜类型为美肤时支持的美颜强度，-1表明关闭美肤，其余非负值为使用RGB表示的美肤美颜强度，<br> 16242611转化为16进制为0xF7D7B3，F7为R通道值，D7为G通道值，B3位B通道值。    |

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明       |
| -------- | --------------------------| ---- | ----------|
| type     | [BeautyType](#beautytype) | 是   | 美颜类型。   |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
|  Array\<number\>     | 当前美颜类型所支持的美颜强度。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyRange(portraitSession: camera.PortraitSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

### setBeauty

setBeauty(type: BeautyType, value: number): void

设置美颜类型以及对应的美颜强度。将通过[getSupportedBeautyTypes](#getsupportedbeautytypes)获取得到的[BeautyType](#beautytype)都关闭，表明当前美颜关闭；若有一种美颜类型未关闭，表明当前美颜打开。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                   |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | 是   | 美颜类型。              |
| value    | number                    | 是   | 美颜强度，通过[getSupportedBeautyRange](#getsupportedbeautyrange)接口获取。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function setBeauty(portraitSession: camera.PortraitSession): void {
  let beautyTypes: Array<camera.BeautyType> = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty

getBeauty(type: BeautyType): number

查询当前已设置的美颜效果对应的美颜强度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| type     | [BeautyType](#beautytype) | 是   | 美颜类型。   |

**返回值：**
| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | 是   | 美颜强度。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getBeauty(portraitSession: camera.PortraitSession): number {
  const invalidValue: number = -1;
  let beautyTypes = portraitSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = portraitSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  portraitSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = portraitSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## ColorEffect<sup>11+</sup>

色彩效果类，用于设置色彩效果类型。

### getSupportedColorEffects

getSupportedColorEffects(): Array\<ColorEffectType\>

获取支持的色彩效果类型列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[ColorEffectType](#coloreffecttype11)>       | 支持的色彩效果类型列表。           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
function getSupportedColorEffects(session: camera.PhotoSession): Array<camera.ColorEffectType> {
  let colorEffects: Array<camera.ColorEffectType> = session.getSupportedColorEffects();
  return colorEffects;
}
```

### setColorEffect

setColorEffect(type: ColorEffectType): void

设置色彩效果类型。可以先通过[getSupportedColorEffects](#getsupportedcoloreffects)获取当前设备所支持的ColorEffects。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| type | [ColorEffectType](#coloreffecttype11)                              | 是 | 色彩效果类型，通过[getSupportedColorEffects](#getsupportedcoloreffects)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function setColorEffect(session: camera.PhotoSession, colorEffect: camera.ColorEffectType): void {
  session.setColorEffect(colorEffect);
}
```

### getColorEffect

getColorEffect(): ColorEffectType

获取当前设置的色彩效果类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [ColorEffectType](#coloreffecttype11)             | 当前设置的色彩效果类型。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getColorEffect(session: camera.PhotoSession): camera.ColorEffectType {
  let colorEffect: camera.ColorEffectType = session.getColorEffect();
  return colorEffect;
}
```

## ColorEffectType<sup>11+</sup>

枚举，色彩效果类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core。

| 名称                  | 值   | 说明       |
| --------------------- | ---- | --------- |
| NORMAL                | 0    | 常规的色彩效果。  |
| BRIGHT                | 1    | 明艳的色彩效果。  |
| SOFT                  | 2    | 柔和的色彩效果。  |

## ColorManagement<sup>11+</sup>

色彩管理类，用于设置色彩空间参数。

### getSupportedColorSpaces

getSupportedColorSpaces(): Array\<colorSpaceManager.ColorSpace\>

获取支持的色彩空间列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)>| 支持的色彩空间列表。     |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                       |
| 202             |  Not System Application.                   |

**示例：**

```ts
function getSupportedColorSpaces(session: camera.PhotoSession): Array<colorSpaceManager.ColorSpace> {
  let colorSpaces: Array<colorSpaceManager.ColorSpace> = session.getSupportedColorSpaces();
  return colorSpaces;
}
```
### setColorSpace

setColorSpace(colorSpace: colorSpaceManager.ColorSpace): void

设置色彩空间。可以先通过[getSupportedColorSpaces](#getsupportedcolorspaces)获取当前设备所支持的ColorSpaces。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                 | 必填 | 说明                      |
| ------------ |---------------------- | -- | -------------------------- |
| colorSpace | [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)  | 是 | 色彩空间，通过[getSupportedColorSpaces](#getsupportedcolorspaces)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.            |
| 7400102         |  The colorSpace does not match the format.               |
| 7400103         |  Session not config.                |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setColorSpace(session: camera.PhotoSession, colorSpaces: Array<colorSpaceManager.ColorSpace>): void {
  if (colorSpaces === undefined || colorSpaces.length <= 0) {
    return;
  }
  try {
    session.setColorSpace(colorSpaces[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setColorSpace call failed, error code: ${err.code}`);
  }
}
```
### getActiveColorSpace

getActiveColorSpace(): colorSpaceManager.ColorSpace

获取当前设置的色彩空间。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [colorSpaceManager.ColorSpace](js-apis-colorSpaceManager.md#colorspace)               | 当前设置的色彩空间。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getActiveColorSpace(session: camera.PhotoSession): colorSpaceManager.ColorSpace {
  let colorSpace: colorSpaceManager.ColorSpace = session.getActiveColorSpace();
  return colorSpace;
}
```

## Portrait<sup>11+</sup>

人像类，用于设置人像参数。

### getSupportedPortraitEffects

getSupportedPortraitEffects(): Array\<PortraitEffect\>

获取支持的人像虚化效果列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[PortraitEffect](#portraiteffect)> | 支持的人像虚化效果列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**示例：**

```ts
function getSupportedPortraitEffects(portraitSession: camera.PortraitSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```
### setPortraitEffect

setPortraitEffect(effect: PortraitEffect): void

设置人像虚化效果。需要先检查设备是否支持人像虚化模式，可以通过[getSupportedPortraitEffects](#getsupportedportraiteffects)获取当前设备所支持的PortraitEffects。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                        | 必填 | 说明                      |
| ------------ |----------------------------- | -- | -------------------------- |
| effect | [PortraitEffect](#portraiteffect)  | 是 | 人像虚化效果，通过[getSupportedPortraitEffects](#getsupportedportraiteffects)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function setPortraitEffect(portraitSession: camera.PortraitSession, portraitEffects: Array<camera.PortraitEffect>): void {
  if (portraitEffects === undefined || portraitEffects.length <= 0) {
    return;
  }
  try {
    portraitSession.setPortraitEffect(portraitEffects[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setPortraitEffect call failed. error code: ${err.code}`);
  }
}
```
### getPortraitEffect

getPortraitEffect(): PortraitEffect

获取当前设置的人像虚化效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [PortraitEffect](#portraiteffect)               | 当前设置的人像虚化效果。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getPortraitEffect(portraitSession: camera.PortraitSession): camera.PortraitEffect {
  let portraitEffect: camera.PortraitEffect = portraitSession.getPortraitEffect();
  return portraitEffect;
}
```

## PhysicalAperture<sup>11+</sup>

物理光圈信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型                       | 必填 | 说明              |
| ---------- | ------------------------- | ---- | -----------------|
| zoomRange  | [ZoomRange](#zoomrange11)   | 是   | 特定物理光圈的变焦范围。  |
| apertures  | Array\<number\>           | 是   | 支持的物理光圈列表。      |

## Aperture<sup>11+</sup>

光圈类，用于设置光圈参数。

### getSupportedVirtualApertures

getSupportedVirtualApertures(): Array\<number\>

获取支持的虚拟光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array\<number\> | 支持的虚拟光圈列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getSupportedVirtualApertures(session: camera.PortraitPhotoSession): Array<number> {
  let virtualApertures: Array<number> = session.getSupportedVirtualApertures();
  return virtualApertures;
}
```

### getVirtualAperture

getVirtualAperture(): number

获取当前设置的虚拟光圈值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| number               | 当前设置的虚拟光圈值。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getVirtualAperture(session: camera.PortraitPhotoSession): number {
  let virtualAperture: number = session.getVirtualAperture();
  return virtualAperture;
}
```

### setVirtualAperture

setVirtualAperture(aperture: number): void

设置虚拟光圈。可以线通过[getSupportedVirtualApertures](#getsupportedvirtualapertures)获取当前设备所支持的虚拟光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                    | 必填 | 说明                      |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | 是 | 虚拟光圈值，通过[getSupportedVirtualApertures](#getsupportedvirtualapertures)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**示例：**

```ts
setVirtualAperture:
function setVirtualAperture(session: camera.PortraitPhotoSession, virtualAperture: number): void {
  session.setVirtualAperture(virtualAperture);
}
```

### getSupportedPhysicalApertures

getSupportedPhysicalApertures(): Array\<PhysicalAperture\>

获取支持的物理光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[PhysicalAperture](#physicalaperture11)>    | 支持的物理光圈列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**示例：**

```ts
function getSupportedPhysicalApertures(session: camera.PortraitPhotoSession): Array<camera.PhysicalAperture> {
  let physicalApertures: Array<camera.PhysicalAperture> = session.getSupportedPhysicalApertures();
  return physicalApertures;
}
```

### getPhysicalAperture

getPhysicalAperture(): number

获取当前设置的物理光圈值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                 | 说明                           |
| -------------------- | ---------------------------- |
| number               | 当前设置的物理光圈值。           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                             |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getPhysicalAperture(session: camera.PortraitPhotoSession): number {
  let physicalAperture: number = session.getPhysicalAperture();
  return physicalAperture;
}
```

### setPhysicalAperture

setPhysicalAperture(aperture: number): void

设置物理光圈。可以线通过[getSupportedPhysicalApertures](#getsupportedphysicalapertures)获取当前设备所支持的物理光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                    | 必填 | 说明                      |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | 是 | 物理光圈值，通过[getSupportedPhysicalApertures](#getsupportedphysicalapertures)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](../errorcodes/errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**示例：**

```ts
function setPhysicalAperture(session: camera.PortraitPhotoSession, physicalAperture: number): void {
  session.setPhysicalAperture(physicalAperture);
}
```

## CaptureSession<sup>(deprecated)</sup>

CaptureSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty

会话类，保存一次相机运行所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)，并向相机设备申请完成相机功能（录像，拍照）。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[PhotoSession](#photosession11)、[VideoSession](#videosession11)替代。

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（[Session.beginConfig](#beginconfig)，[Session.commitConfig](#commitconfig)，[Session.addInput](#addinput)）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', (error: BusinessError) => {
    console.error(`Capture session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| type     | string              | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | ErrorCallback       | 否   | 回调函数，可选，有表明匹配on接口callback。      |

**示例：**

```ts
function unregisterSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

## PhotoSession<sup>11+</sup>

PhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Macro

普通拍照模式会话类，继承自[Session](#session11)，用于设置普通拍照模式的参数以及保存所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)。

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听普通拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（[Session.beginConfig](#beginconfig)，[Session.commitConfig](#commitconfig)，[Session.addInput](#addinput)）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSessionError(photoSession: camera.PhotoSession): void {
  photoSession.on('error', (error: BusinessError) => {
    console.error(`Photo session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听普通拍照会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                           |
| -------- | -------------------------------- | ---- | ------------------------------ |
| type     | string                           | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | ErrorCallback| 否   | 回调函数，可选，有表明匹配on接口callback。     |

**示例：**

```ts
function unregisterSessionError(photoSession: camera.PhotoSession): void {
  photoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.on('smoothZoomInfoAvailable', (err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo) => {
    console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
  });
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('smoothZoomInfoAvailable');
}
```

### on('macroStatusChanged')

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.on('macroStatusChanged', (err: BusinessError, macroStatus: boolean) => {
    console.info(`Macro state: ${macroStatus}`);
  });
}
```

### off('macroStatusChanged')

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销监听相机微距状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。|
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，有表明匹配on接口callback。 |

**示例：**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Macro, Stabilization

普通录像模式会话类，继承自[Session](#session11)，用于设置普通录像模式的参数以及保存所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)。

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听普通录像会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型              | 必填 | 说明                           |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（[Session.beginConfig](#beginconfig)，[Session.commitConfig](#commitconfig)，[Session.addInput](#addinput)）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback      | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。   |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSessionError(videoSession: camera.VideoSession): void {
  videoSession.on('error', (error: BusinessError) => {
    console.error(`Video session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听普通录像会话的错误事件，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                          | 必填 | 说明                           |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | ErrorCallback| 否   | 回调函数，可选，有表明匹配on接口callback。      |

**示例：**

```ts
function unregisterSessionError(videoSession: camera.VideoSession): void {
  videoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 否  | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.on('smoothZoomInfoAvailable', (err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo) => {
    console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
  });
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('smoothZoomInfoAvailable');
}
```

### on('macroStatusChanged')

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.on('macroStatusChanged', (err: BusinessError, macroStatus: boolean) => {
    console.info(`Macro state: ${macroStatus}`);
  });
}
```

### off('macroStatusChanged')

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销监听相机微距状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。|
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，有表明匹配on接口callback。 |

**示例：**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```

## PortraitPhotoSession<sup>11+</sup>

PortraitPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Portrait, Aperture

人像拍照模式会话类，继承自[Session](#session11)，用于设置人像拍照模式的参数以及保存所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)。

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听人像拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（[Session.beginConfig](#beginconfig)，[Session.commitConfig](#commitconfig)，[Session.addInput](#addinput)）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('error', (error: BusinessError) => {
    console.error(`Portrait photo session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听人像拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | ErrorCallback| 否   | 回调函数，可选，有表明匹配on接口callback。    |

**示例：**

```ts
function unregisterSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('smoothZoomInfoAvailable', (err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo) => {
    console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
  });
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('smoothZoomInfoAvailable');
}
```

## NightPhotoSession<sup>11+</sup>

NightPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ColorManagement, ManualExposure

夜景拍照模式会话类，继承自[Session](#session11)，用于设置夜景拍照模式的参数以及保存所需要的所有资源[CameraInput](#camerainput)、[CameraOutput](#cameraoutput)。

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听夜景拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用（[Session.beginConfig](#beginconfig)，[Session.commitConfig](#commitconfig)，[Session.addInput](#addinput)）等接口发生错误时返回错误信息。 |
| callback | ErrorCallback| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('error', (error: BusinessError) => {
    console.error(`Night photo session error code: ${error.code}`);
  });
}
```

### off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听夜景拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | ErrorCallback| 否   | 回调函数，可选，有表明匹配on接口callback。       |

**示例：**

```ts
function unregisterSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('error');
}
```

### on('focusStateChange')

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    console.info(`Focus state: ${focusState}`);
  });
}
```

### off('focusStateChange')

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](#focusstate)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function registerSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('smoothZoomInfoAvailable', (err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo) => {
    console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
  });
}
```

### off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](#smoothzoominfo11)\> | 否   | 回调函数，可选，有表明匹配on接口callback。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('smoothZoomInfoAvailable');
}
```

## SketchStatusData<sup>11+</sup>

画中画状态返回数据。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                | 必填 | 说明        |
| -------------- | ------------------ | ---- | ---------- |
| status         | number             | 是   | 画中画当前的状态。0：已停止，1：已启动，2：停止中，3：启动中。|
| sketchRatio    | number             | 是   | 画中画画面的Zoom倍率。|