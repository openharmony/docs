# @ohos.multimedia.camera (相机管理)(系统接口)

本模块为开发者提供一套简单且易于理解的相机服务接口，开发者通过调用接口可以开发相机应用。应用通过访问和操作相机硬件，实现基础操作，如预览、拍照和录像；还可以通过接口组合完成更多操作，如控制闪光灯和曝光时间、对焦或调焦等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.camera (相机管理)](js-apis-camera.md)。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## SceneMode<sup>11+</sup>

枚举，相机支持模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| PORTRAIT_PHOTO       | 3      | 人像拍照模式。**系统接口：** 此接口为系统接口。            |
| NIGHT_PHOTO        | 4      | 夜景拍照模式。**系统接口：** 此接口为系统接口。             |
| PROFESSIONAL_PHOTO<sup>12+</sup>        | 5      | 专业拍照模式。**系统接口：** 此接口为系统接口。             |
| PROFESSIONAL_VIDEO<sup>12+</sup>        | 6      | 专业录像模式。**系统接口：** 此接口为系统接口。             |
| SLOW_MOTION_VIDEO<sup>12+</sup>        | 7   | 慢动作模式。**系统接口：** 此接口为系统接口。  |
| HIGH_RESOLUTION_PHOTO<sup>12+</sup>        | 11     | 高像素拍照模式。 **系统接口：** 此接口为系统接口。          |
| PANORAMA_PHOTO<sup>12+</sup>        | 15     | 全景拍照模式。 **系统接口：** 此接口为系统接口。          |
| TIME_LAPSE_PHOTO<sup>12+</sup>        | 16     | 延时摄影模式。 **系统接口：** 此接口为系统接口。          |

## SlowMotionStatus<sup>12+</sup>

枚举，慢动作状态。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 值   | 说明            |
|----------------|-----|---------------|
| DISABLED       | 0   | 慢动作关闭状态。      |
| READY          | 1   | 慢动作就绪状态。      |
| VIDEO_START    | 2   | 慢动作视频开始状态。    |
| VIDEO_DONE     | 3   | 慢动作视频完成状态。    |
| FINISHED       | 4   | 慢动作结束状态。      |

## LcdFlashStatus<sup>12+</sup>

lcd闪光灯信息项。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选  | 说明         |
| -------- | ----------------------------- |---- |-----| ------------- |
| isLcdFlashNeeded   | boolean | 是  | 否   | 是否需要lcd闪光灯。      |
| lcdCompensation     | number                 | 是  | 否   | lcd闪光灯补偿值。       |

## Photo<sup>11+</sup>

全质量图对象。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称   | 类型                            | 只读  | 可选       | 说明 |
| ------ | ----------------------------- |-----| ---------- | ---------- |
| raw<sup>12+</sup> | [image.Image](../apis-image-kit/js-apis-image.md#image9)| NA  | 是   | raw图。 |

## ExposureMode

枚举，曝光模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明      |
| ----------------------------- |-----|---------|
| EXPOSURE_MODE_MANUAL<sup>12+</sup>          | 3   | 手动曝光模式。 |

## PolicyType<sup>12+</sup>

枚举，策略类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明      |
| ----------------------------- |-----|---------|
| PRIVACY<sup>12+</sup>          | 1   | 隐私类型。 |

## LightPaintingType<sup>12+</sup>

枚举，流光快门模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明      |
| ----------------------------- |-----|---------|
| TRAFFIC_TRAILS         | 0   | 车水马龙。 |
| STAR_TRAILS          | 1   | 绚丽星轨。 |
| SILKY_WATER          | 2   | 丝绢流水。 |
| LIGHT_GRAFFITI          | 3   | 光绘涂鸦。 |

## CameraManager

相机管理器类，使用前需要通过[getCameraManager](js-apis-camera.md#cameragetcameramanager)获取相机管理实例。

### createDepthDataOutput<sup>13+</sup>

createDepthDataOutput(profile: Profile): DepthDataOutput

创建深度输出对象，同步返回结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                              |
| -------- | ----------------------------------------------- | ---- | ------------------------------- |
| profile  | [Profile](js-apis-camera.md#profile)                             | 是   | 支持的预览配置信息，通过[getSupportedOutputCapability](js-apis-camera.md#getsupportedoutputcapability11)接口获取。|

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [DepthDataOutput](#depthdataoutput13)    | DepthDataOutput实例。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.               |
| 7400201                |  Camera service fatal error.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function createDepthDataOutput(cameraOutputCapability: camera.CameraOutputCapability, cameraManager: camera.CameraManager): camera.DepthDataOutput | undefined {
  let profile: camera.Profile = cameraOutputCapability.depthProfiles[0];
  let depthDataOutput: camera.DepthDataOutput | undefined = undefined;
  try {
    depthDataOutput = cameraManager.createDepthDataOutput(profile);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The createDepthDataOutput call failed. error code: ${err.code}`);
  }
  return depthDataOutput;
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

> **说明：**
>从 API version 10开始支持，从API version 12开始废弃。建议使用[muteCameraPersistent](#mutecamerapersistent12)替代。

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

### muteCameraPersistent<sup>12+</sup>

muteCameraPersistent(mute: boolean, type: PolicyType): void

以持久化的方式禁用相机。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                          | 必填  | 说明                                         |
| -------- |-----------------------------| ---- |--------------------------------------------|
| mute     | boolean                     |  是  | 禁用相机。true为禁用；false为解除禁用。                   |
| type     | [PolicyType](#policytype12) |  是  | 策略类型。请使用[PolicyType](#policytype12)里面支持的类型 |

**示例：**

```ts
function muteCameraPersistent(cameraManager: camera.CameraManager): void {
  let mute: boolean = true;
  cameraManager.muteCameraPersistent(mute, camera.PolicyType.PRIVACY);
}
```

### on('cameraMute')

on(type: 'cameraMute', callback: AsyncCallback\<boolean\>): void

禁用回调，通过注册回调函数获取相机禁用状态变化。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| type     | string          | 是   | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。系统设置打开或禁用相机会触发该事件并返回状态。 |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，用于获取禁用状态变化信息，返回true是开启状态，返回false是禁用状态。               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, curMuted: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  let isMuted: boolean = curMuted;
  console.info(`cameraMute status: ${isMuted}`);
}

function registerCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraMute', callback);
}
```

### off('cameraMute')

off(type: 'cameraMute', callback?: AsyncCallback\<boolean\>): void

禁用回调，通过注销注册回调函数获取相机禁用状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明                                                      |
| -------- | --------------- | ---- |---------------------------------------------------------|
| type     | string          | 是   | 监听事件，固定为'cameraMute'，系统相机摄像头开关，cameraManager对象获取成功后可监听。 |
| callback | AsyncCallback\<boolean> | 否   | 回调函数，可选参数，有就是匹配on('cameraMute') callback（callback对象不可是匿名函数）。                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, curMuted: boolean): void {
  let isMuted: boolean = curMuted;
}

function unregisterCameraMute(cameraManager: camera.CameraManager): void {
  cameraManager.off('cameraMute', callback);
}
```

### isPrelaunchSupported

isPrelaunchSupported(camera: CameraDevice): boolean

检查指定cameraDevice是否支持预热启动。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                               | 必填 | 说明       |
| -------- |--------------------------------------------------| ---- | --------- |
| camera | [CameraDevice](./js-apis-camera.md#cameradevice) | 是 | 相机信息。|

**返回值：**

| 类型 | 说明 |
| -------- | --------------- |
| boolean | 返回指定cameraDevice是否支持预热启动。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed. |
| 7400201 | Camera service fatal error. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
| profile | [Profile](js-apis-camera.md#profile) | 是 | 相机预览流的配置文件。 |

**返回值：**

| 类型 | 说明 |
| -------- | --------------- |
| [PreviewOutput](#previewoutput) | 返回预览输出对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |
| 7400101 	      |  Parameter missing or parameter type incorrect. |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

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
| cameraId | string | 是 | 相机id。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                                           |
| ------- |------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400201 | Camera service fatal error.                    |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## CameraOcclusionDetectionResult<sup>12+</sup>
摄像头模组被遮挡状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 类型                                                | 只读 | 可选 | 说明                |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| isCameraOccluded                 | boolean              |  是  | 否 |遮挡状态。        |

## CameraOutputCapability<sup>13+</sup>

相机输出能力项。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 类型                                                | 只读 | 可选 | 说明                |
| ----------------------------- | --------------------------------------------------- | ---- | ---- |-------------------|
| depthProfiles                 | Array\<[DepthProfile](#depthprofile13)\>              |  是  | 否 | 支持的深度流配置信息集合。        |

## CameraFormat

枚举，输出格式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_DEPTH_16<sup>13+</sup> |   3000   | DEPTH_16格式的深度图。      |
| CAMERA_FORMAT_DEPTH_32<sup>13+</sup> |   3001   | DEPTH_32格式的深度图。      |

## CameraInput

相机设备输入对象。

会话中[Session](js-apis-camera.md#session11)使用的相机信息。

### on('cameraOcclusionDetection')<sup>12+</sup>

on(type: 'cameraOcclusionDetection', callback: AsyncCallback\<CameraOcclusionDetectionResult\>): void

监听CameraInput的遮挡事件，通过注册回调函数获取结果。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                          |
| -------- | -------------------------------- | --- | ------------------------------------------- |
| type     | string                           | 是   | 监听事件，固定为'cameraOcclusionDetection'，CameraInput对象创建成功可监听。相机模组遮挡状态发生改变时触发该事件并返回结果。 |
| callback | AsyncCallback\<[CameraOcclusionDetectionResult](#cameraocclusiondetectionresult12)\> | 是   | 回调函数，用于获取结果。返回遮挡状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, CameraOcclusionDetectionResult: camera.CameraOcclusionDetectionResult): void {
  if (err !== undefined && err.code !== 0) {
    console.error('cameraOcclusionDetection with errorCode = ' + err.code);
    return;
  }
  console.info(`isCameraOccluded : ${CameraOcclusionDetectionResult.isCameraOccluded}`);
}

function registerCameraOcclusionDetection(cameraInput: camera.CameraInput): void {
  cameraInput.on('cameraOcclusionDetection', callback);
}
```

### off('cameraOcclusionDetection')<sup>12+</sup>

off(type: 'cameraOcclusionDetection', callback?: AsyncCallback\<CameraOcclusionDetectionResult\>): void

注销CameraInput遮挡监听事件。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型             | 必填 | 说明                                                      |
| -------- | --------------- | ---- |---------------------------------------------------------|
| type     | string          | 是   | 监听事件，固定为'cameraOcclusionDetection'，CameraInput对象创建成功可监听。 |
| callback | AsyncCallback\<[CameraOcclusionDetectionResult](#cameraocclusiondetectionresult12)\> | 否   | 回调函数，可选参数，有就是匹配on('cameraOcclusionDetection') callback（callback对象不可是匿名函数）。                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, CameraOcclusionDetectionResult: camera.CameraOcclusionDetectionResult): void {
  if (err !== undefined && err.code !== 0) {
    console.error('cameraOcclusionDetection with errorCode = ' + err.code);
    return;
  }
  console.info(`isCameraOccluded : ${CameraOcclusionDetectionResult.isCameraOccluded}`);
}

function unregisterCameraOcclusionDetection(cameraInput: camera.CameraInput): void {
  cameraInput.off('cameraOcclusionDetection', callback);
}
```

## DepthDataAccuracy<sup>13+</sup>

深度数据的精度。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选 | 说明            |
| -------- | ----------------------------- |----- |---| -------------- |
| DEPTH_DATA_ACCURACY_RELATIVE      | number                        |  是  | 否 | 相对精度，基于视差计算得到的深度图。      |
| DEPTH_DATA_ACCURACY_ABSOLUTE      | number                        |  是  | 否 | 绝对精度，基于测距计算得到的深度图。      |

## DepthProfile<sup>13+</sup>

深度数据配置信息项，继承[Profile](js-apis-camera.md#profile)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 类型                                      | 只读 | 可选 | 说明        |
| ------------------------- | ----------------------------------------- | --- | ---- |----------- |
| depthDataAccuracy            | [DepthDataAccuracy](#depthdataaccuracy13)         | 是  |  否  | 深度数据的精度，分为相对精度和绝对精度。 |

## DepthDataQualityLevel<sup>13+</sup>

深度数据的质量。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选 | 说明            |
| -------- | ----------------------------- |----- |---| -------------- |
| DEPTH_DATA_QUALITY_BAD     | number            |  是  | 否 | 深度图的质量很差，无法用于虚化等。      |
| DEPTH_DATA_QUALITY_FAIR      | number          |  是  | 否 | 深度图的质量一般，无法生成高质量的虚化等。      |
| DEPTH_DATA_QUALITY_GOOD      | number          |  是  | 否 | 深度图的质量较高，可以生成高质量的虚化等。      |

## DepthData<sup>13+</sup>

深度数据对象。

### 属性

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型                          | 只读 | 可选 | 说明            |
| -------- | ----------------------------- |----- |---| -------------- |
| format | [CameraFormat](#cameraformat)   | 是 |  否  | 深度图的格式。 |
| depthMap | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)    | 是 |  否  | 深度图。 |
| qualityLevel | [DepthDataQualityLevel](#depthdataqualitylevel13)   | 是 |  否  | 深度图的质量。 |
| accuracy | [DepthDataAccuracy](#depthdataaccuracy13) | 是 |  否  | 深度图的精度。 |

### release<sup>13+</sup>

release(): void

释放输出资源。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**示例：**

```ts
function releaseDepthData(depthData: camera.DepthData): void {
  await depthData.release();
}
```

## DepthDataOutput<sup>13+</sup>

深度信息输出类。继承[CameraOutput](js-apis-camera.md#cameraoutput)。

### start<sup>13+</sup>

start(): Promise\<void\>

启动深度信息输出流，通过Promise获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startDepthDataOutput(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to depth data output start, error code: ${error.code}.`);
  });
}
```

### stop<sup>13+</sup>

stop(): Promise\<void\>

结束深度信息输出，通过Promise获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopDepthDataOutput(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to depth data output stop, error code: ${error.code}.`);
  });
}
```

### on('depthDataAvailable')<sup>13+</sup>

on(type: 'depthDataAvailable', callback: AsyncCallback\<DepthData\>): void

注册监听深度数据上报。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'depthDataAvailable'，depthDataOutput创建成功后可监听。 |
| callback | AsyncCallback\<[DepthData](#depthdata13)\> | 是   | 回调函数，用于监听深度信息上报。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, depthData: camera.DepthData): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
}

function registerDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.on('depthDataAvailable', callback);
}
```

### off('depthDataAvailable')<sup>13+</sup>

off(type: 'depthDataAvailable', callback?: AsyncCallback\<DepthData\>): void

注销监听深度信息上报。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'depthDataAvailable'，depthDataOutput创建成功后可监听。 |
| callback | AsyncCallback\<[DepthData](#depthdata13)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, depthData: camera.DepthData): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
}

function unRegisterDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.off('depthDataAvailable', callback);
}
```

### on('error')<sup>13+</sup>

on(type: 'error', callback: ErrorCallback): void

监听深度信息输出的错误事件，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | 是   | 监听事件，固定为'error'，depthDataOutput创建成功可监听。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(depthDataOutputError: BusinessError): void {
  console.error(`Depth data output error code: ${depthDataOutputError.code}`);
}

function registerDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.on('error', callback)
}
```

### off('error')<sup>13+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听深度信息输出的错误事件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| type     | string        | 是   | 监听事件，固定为'error'，depthDataOutput创建成功可监听。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
  depthDataOutput.off('error');
}
```

## PrelaunchConfig

相机预启动配置参数。

当前sensor级别预热，待扩展流预热参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

|            名称                 | 类型                                               |     只读    |     必填     | 说明       |
| ------------------------------- |--------------------------------------------------| ----------- | ------------ | ---------- |
| cameraDevice                    | [CameraDevice](./js-apis-camera.md#cameradevice) |      否     |       是      | 相机信息。         |
| restoreParamType<sup>11+</sup>  | [RestoreParamType](#restoreparamtype11)          |      否     |       否      | 预保存参数类型。    |
| activeTime<sup>11+</sup>        | number                                           |      否     |       否      | 激活时间，单位min。 |
| settingParam<sup>11+</sup>      | [SettingParam](#settingparam11)                  |      否     |       否      | 设置参数内容。      |

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

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称             | 类型   |   只读    | 可选  | 说明                                                                                                |
| --------------- | ------ | --------- |-----|---------------------------------------------------------------------------------------------------|
| skinSmoothLevel | number |  否       | 否   | 美颜类型光滑信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的光滑范围，例如1表示1级光滑。        |
| faceSlender     | number |  否       | 否   | 美颜类型瘦脸信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的瘦脸范围，例如1表示1级瘦脸。        |
| skinTone        | number |  否       | 否   | 美颜类型肤色信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的肤色范围，例如0xBF986C表示一个颜色。 |

## PreviewOutput

预览输出类。继承[CameraOutput](js-apis-camera.md#cameraoutput)。

### addDeferredSurface

addDeferredSurface(surfaceId: string): void

配置延迟预览的Surface，可以在[Session.commitConfig](js-apis-camera.md#commitconfig11-1)配流和[Session.start](js-apis-camera.md#start11-1)启流之后运行。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| surfaceId | string | 是 | 从[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

async function preview(context: common.BaseContext, cameraDevice: camera.CameraDevice, previewProfile: camera.Profile, photoProfile: camera.Profile, mode: camera.SceneMode, previewSurfaceId: string): Promise<void> {
  const cameraManager: camera.CameraManager = camera.getCameraManager(context);
  const cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameraDevice);
  const previewOutput: camera.PreviewOutput = cameraManager.createDeferredPreviewOutput(previewProfile);
  const photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  const session: camera.Session  = cameraManager.createSession(mode);
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

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息                    |
| --------------- |-------------------------|
| 202             | Not System Application. |

**示例：**

```ts
function isSketchSupported(previewOutput: camera.PreviewOutput): boolean {
  try {
    let isSupported: boolean = previewOutput.isSketchSupported();
    return isSupported;
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isSketchSupported call failed. error code: ${err.code}`);
  }
  return false;
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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

| 参数名     | 类型      | 必填 | 说明                       |
|---------|---------| ---- | ------------------------ |
| enabled | boolean | 是 | true表明开启画中画流进行预览。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID     | 错误信息                        |
|-----------|-----------------------------|
| 202       | Not System Application.     |
| 7400102   | Operation not allowed.      |
| 7400103   | Session not config.         |
| 7400201   | Camera service fatal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableSketch(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
  } catch (error) {
    // 失败返回错误码error.code并处理。
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
| surfaceId | string | 是 | 从[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                                           |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400103 | Session not config.                            |
| 7400201 | Camera service fatal error.                    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function attachSketchSurface(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput, sketchSurfaceId: string): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
    previewOutput.attachSketchSurface(sketchSurfaceId);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The attachSketchSurface call failed. error code: ${err.code}`);
  }
}
```

### on('sketchStatusChanged')<sup>11+</sup>

on(type: 'sketchStatusChanged', callback: AsyncCallback\<SketchStatusData\>): void

监听画中画状态信息改变，通过注册回调函数获取SketchStatusData。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| type     | string                 | 是   | 监听事件，固定为'sketchStatusChanged'，画中画流创建成功后可监听。底层画中画的状态启停以及画中画Zoom值变更会回调该接口。 |
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | 是   | 使用callback的方式获取SketchStatusData。            |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                          |
|---------|-------------------------------|
| 202     | Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(error: BusinessError, data: camera.SketchStatusData): void {
  if (error !== undefined && error.code !== 0) {
    console.error(`Callback Error, errorCode: ${error.code}`);
    return;
  }
  console.info(`sketch errorCode is ${error.code}, data is ${JSON.stringify(data)}`);
}

function registerSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.on('sketchStatusChanged', callback);
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
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | 否   | 回调函数，可选，有就是匹配on('sketchStatusChanged') callback（callback对象不可是匿名函数）。           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                          |
|---------|-------------------------------|
| 202     | Not System Application.       |

**示例：**

```ts
function unregisterSketchStatusChanged(previewOutput: camera.PreviewOutput): void {
  previewOutput.off('sketchStatusChanged');
}
```

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

### getThumbnail<sup>11+</sup>

getThumbnail(): Promise<image.PixelMap>

通过缩略图代理类提供的方法，获取缩略图 PixelMap。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<image.PixelMap\> | 缩略图 PixelMap。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { image } from '@kit.ImageKit';

function getThumbnail(proxyObj: camera.DeferredPhotoProxy): void {
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}
```

### release<sup>11+</sup>

release(): Promise\<void\>

释放输出资源，通过Promise获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明               |
| -------------- |------------------|
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
async function releaseDeferredPhotoProxy(proxyObj: camera.DeferredPhotoProxy): Promise<void> {
  await proxyObj.release();
}
```

## PhotoOutput

拍照会话中使用的输出信息，继承[CameraOutput](js-apis-camera.md#cameraoutput)。

### burstCapture<sup>12+</sup>

burstCapture(setting: PhotoCaptureSetting): Promise\<void\>

开始连续拍照，一般用于拍照模式下，开始后底层持续上图，可以通过[confirmCapture](#confirmcapture11)取消连续拍照。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名  | 类型                                        | 必填 | 说明     |
| ------- | ------------------------------------------- | ---- | -------- |
| setting | [PhotoCaptureSetting](js-apis-camera.md#photocapturesetting) | 是   | 拍照设置，传入undefined类型数据按默认无参处理。 |

**返回值：**

| 类型            | 说明                      |
| -------------- | ------------------------   |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |
| 7400101         |  Parameter missing or parameter type incorrect.          |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function burstCapture(photoOutput: camera.PhotoOutput): void {
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
  photoOutput.burstCapture(settings).then(() => {
    console.info('Promise returned to indicate that photo burstCapture request success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to photo output burstCapture, error code: ${error.code}.`);
  });
}
```

### confirmCapture<sup>11+</sup>

confirmCapture()

确认拍照，一般用于夜景模式下，在曝光倒计时过程中如需终止倒计时提前拍照的时候调用。

已经调用[burstCapture](#burstcapture12)开始连续拍照后，调用该接口用于结束连续拍照。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |
| 7400104         |  Session not running.          |
| 7400201         |  Camera service fatal error.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息                                                |
| --------------- |-----------------------------------------------------|
| 7400101                | Parameter missing or parameter type incorrect.      |
| 7400104                | Session not running.                                |
| 7400201                | Camera service fatal error.                         |
| 202                    | Not System Application.                             |

**示例：**

```ts
function isDeferredImageDeliverySupported(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): boolean {
  let res: boolean = false;
  res = photoOutput.isDeferredImageDeliverySupported(type);
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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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
  res = photoOutput.isDeferredImageDeliveryEnabled(type);
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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |
| 202                    |  Not System Application.                               |

**示例：**

```ts
function deferImageDelivery(photoOutput: camera.PhotoOutput, type: camera.DeferredDeliveryImageType): void {
  photoOutput.deferImageDelivery(type);
}
```

### isAutoHighQualityPhotoSupported<sup>13+</sup>

isAutoHighQualityPhotoSupported(): boolean

判断当前是否支持自动高画质。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 是否支持自动高画质。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isAutoHighQualityPhotoSupported(photoOutput: camera.PhotoOutput): boolean {
  return photoOutput.isAutoHighQualityPhotoSupported();
}
```

### enableAutoHighQualityPhoto<sup>13+</sup>

enableAutoHighQualityPhoto(enabled: boolean): void

使能拍照自动高画质。设置拍照自动高画质之前，需要调用[isAutoHighQualityPhotoSupported](#isautohighqualityphotosupported13)判断当前是否支持。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型               | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
|   enabled   |  boolean  |   是   |   是否使能拍照自动高画质。    |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  Session not running.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableAutoHighQualityPhoto(photoOutput: camera.PhotoOutput): void {
  return photoOutput.enableAutoHighQualityPhoto(true);
}
```

### on('deferredPhotoProxyAvailable')<sup>11+</sup>

on(type: 'deferredPhotoProxyAvailable', callback: AsyncCallback\<DeferredPhotoProxy\>): void

注册监听缩略图上报。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型      | 必填 | 说明                                  |
| -------- | ---------- | --- | ------------------------------------ |
| type     | string     | 是   | 监听事件，固定为'deferredPhotoProxyAvailable'，photoOutput创建成功后可监听。 |
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | 是   | 回调函数，用于获取相关信息。用于监听缩略图上报。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}

function registerPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.on('deferredPhotoProxyAvailable', callback);
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
| callback | AsyncCallback\<[DeferredPhotoProxy](#deferredphotoproxy11)\> | 否   | 回调函数，可选，有就是匹配on('deferredPhotoProxyAvailable') callback（callback对象不可是匿名函数）。            |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
  proxyObj.getThumbnail().then((thumbnail: image.PixelMap) => {
    AppStorage.setOrCreate('proxyThumbnail', thumbnail);
  });
}

function unRegisterPhotoOutputDeferredPhotoProxyAvailable(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('deferredPhotoProxyAvailable', callback);
}
```

### isQuickThumbnailSupported

isQuickThumbnailSupported(): boolean

是否支持输出快速缩略图。

在[addOutput](js-apis-camera.md#addoutput11)、[addInput](js-apis-camera.md#addinput11)之后，[commitConfig](js-apis-camera.md#commitconfig11-1)之前生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型 | 说明 |
| --------- | ------ |
| boolean | 返回支持情况，如果返回true表示支持，否则不支持。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                	 |  Not System Application.        |
| 7400104                |  session is not running.        |

**示例：**

```ts
import { common } from '@kit.AbilityKit';

async function isQuickThumbnailSupported(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<boolean> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例。
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话。
  session.beginConfig();
  // 把CameraInput加入到会话。
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把photoOutput加入到会话。
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
  let isSupported: boolean = photoOutput.isQuickThumbnailSupported();
  return isSupported;
}
```

### enableQuickThumbnail

enableQuickThumbnail(enabled: boolean): void

启用/禁用快速缩略图。

在[addOutput](js-apis-camera.md#addoutput11)、[addInput](js-apis-camera.md#addinput11)之后，[commitConfig](js-apis-camera.md#commitconfig11-1)之前生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| enabled    | boolean       | 是   | true：使能快速缩略图；false：去使能快速缩略图。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                	 |  Not System Application.        |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400104                |  session is not running.        |
| 7400201                |  Camera service fatal error.        |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function enableQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例。
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话。
  session.beginConfig();
  // 把CameraInput加入到会话。
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把PhotoOutPut加入到会话。
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
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

监听快速缩略图输出事件。使用callback异步回调。

在enableQuickThumbnail(true)使能快速缩略图之后监听生效。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type    | string     | 是   | 监听事件，固定为'quickThumbnail'。 |
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | 是 | 回调返回PixelMap。 |

**示例：**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';

function callback(err: BusinessError, pixelMap: image.PixelMap): void {
  if (err || pixelMap === undefined) {
      console.error('photoOutput on thumbnail failed');
      return;
  }
  // 显示或保存pixelMap。
  // do something.
}

async function registerQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例。
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话。
  session.beginConfig();
  // 把CameraInput加入到会话。
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把PhotoOutPut加入到会话。
  let photoOutput: camera.PhotoOutput = cameraManager.createPhotoOutput(photoProfile);
  session.addOutput(photoOutput);
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

  photoOutput.on('quickThumbnail', callback);
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
| callback | AsyncCallback\<[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)> | 否 | 回调函数，可选，有就是匹配on('quickThumbnail') callback（callback对象不可是匿名函数）。 |

**示例：**

```ts
function unregisterQuickThumbnail(photoOutput: camera.PhotoOutput): void {
  photoOutput.off('quickThumbnail');
}
```

## MetadataOutput

metadata流。继承[CameraOutput](js-apis-camera.md#cameraoutput)。

### addMetadataObjectTypes<sup>13+</sup> 

addMetadataObjectTypes(types: Array\<MetadataObjectType\>): void

新增需要上报的检测对象类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not system application.        |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addMetadataObjectTypes(metadataOutput: camera.MetadataOutput, types: Array<camera.MetadataObjectType>): void {
  try {
    metadataOutput.addMetadataObjectTypes(types);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`addMetadataObjectTypes error. error code: ${err.code}`);
  }
}
```

### removeMetadataObjectTypes<sup>13+</sup> 

removeMetadataObjectTypes(types: Array\<MetadataObjectType\>): void

删除需要上报的检测对象类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名                  | 类型                                               | 必填 | 说明                          |
| -------------------- | -------------------------------------------------- | --- | ---------------------------- |
| metadataObjectTypes  | Array\<[MetadataObjectType](#metadataobjecttype)\>  | 是  | metadata流类型信息，通过getSupportedOutputCapability接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not system application.        |
| 7400101                |  Parameter missing or parameter type incorrect.                                   |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeMetadataObjectTypes(metadataOutput: camera.MetadataOutput, types: Array<camera.MetadataObjectType>): void {
  try {
    metadataOutput.removeMetadataObjectTypes(types);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`removeMetadataObjectTypes error. error code: ${err.code}`);
  }
}
```

## MetadataObjectType

枚举，metadata元数据检测类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| -------------------------- | ---- | ----------------- |
| HUMAN_BODY<sup>13+</sup>                 | 1    | 用于检测人体的metadata类型。 |
| CAT_FACE<sup>13+</sup>                   | 2    | 用于检测猫脸的metadata类型。 |
| CAT_BODY<sup>13+</sup>                   | 3    | 用于检测猫的身体的metadata类型。 |
| DOG_FACE<sup>13+</sup>                   | 4    | 用于检测狗脸的metadata类型。 |
| DOG_BODY<sup>13+</sup>                   | 5    | 用于检测狗的身体的metadata类型。 |
| SALIENT_DETECTION<sup>13+</sup>          | 6    | 用于显著性检测。 |

## Emotion<sup>13+</sup>
枚举，人脸检测信息中的情绪类型。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                       | 值   | 说明              |
| -------------------------- | ---- | ----------------- |
| NEUTRAL                 | 0    | 平静。 |
| SADNESS                   | 1    | 悲伤。 |
| SMILE                   | 2    | 微笑。 |
| SURPRISE                   | 3    | 惊讶。 |

## MetadataObject

相机检测元数据信息的基础类型，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称         | 类型                                        | 只读 | 可选 |说明                |
| -----------  | ------------------------------------------- | ---- | ---- | ----------------- |
| objectId<sup>13+</sup>     | number                                      |  是  |  否  | metadataObject Id序号。|
| confidence<sup>13+</sup>   | number                                      |  是  |  否  | 检测置信度，取值范围[0,1]。|

## MetadataFaceObject<sup>13+</sup>

相机检测到的人脸元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                    | 类型                              | 只读 | 可选 |说明                |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](js-apis-camera.md#rect)                             |  是  |  否  | 左眼区域框|
| rightEyeBoundingBox    | [Rect](js-apis-camera.md#rect)                            |  是  |  否  | 右眼区域框。|
| emotion                | [Emotion](#emotion13)             |  是  |  否  | 检测到的情绪类型。|
| emotionConfidence      | number                            |  是  |  否  | 情绪检测置信度，取值范围[0,1]。|
| pitchAngle             | number                            |  是  |  否  | 俯仰角度，取值范围[-90, 90]，以向下为正。|
| yawAngle               | number                            |  是  |  否  | 左右旋转角度，取值范围[-90, 90]，以向右为正。|
| rollAngle              | number                            |  是  |  否  | 平面内旋转角度，取值范围[-180, 180]，以顺时针方向为正。|

## MetadataHumanBodyObject<sup>13+</sup>

相机检测到的人体元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## MetadataCatFaceObject<sup>13+</sup>

相机检测到的猫脸元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                    | 类型                              | 只读 | 可选 |说明                |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](js-apis-camera.md#rect)                              |  是  |  否  | 左眼区域框。|
| rightEyeBoundingBox    | [Rect](js-apis-camera.md#rect)                              |  是  |  否  | 右眼区域框。|

## MetadataCatBodyObject<sup>13+</sup>

相机检测到的猫的身体元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## MetadataDogFaceObject<sup>13+</sup>

相机检测到的狗脸元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                    | 类型                              | 只读 | 可选 |说明                |
| ---------------------- | --------------------------------- | ---- | ---- | --------------------- |
| leftEyeBoundingBox     | [Rect](js-apis-camera.md#rect)                              |  是  |  否  | 左眼区域框。|
| rightEyeBoundingBox    | [Rect](js-apis-camera.md#rect)                              |  是  |  否  | 右眼区域框。|

## MetadataDogBodyObject<sup>13+</sup>

相机检测到的狗的身体元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## MetadataSalientDetectionObject<sup>13+</sup>

相机检测到的显著性元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## MetadataBarcodeObject<sup>14+</sup>

相机检测到的二维码元数据信息，继承自[MetadataObject](#metadataobject)，[CameraInput](#camerainput)相机信息中的数据来源，通过metadataOutput.[on('metadataObjectsAvailable')](js-apis-camera.md#onmetadataobjectsavailable)接口获取。

**系统能力：** SystemCapability.Multimedia.Camera.Core

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

## BeautyQuery<sup>12+</sup>

提供了获取和设置美颜效果的方法。

### getSupportedBeautyTypes<sup>11+</sup>

getSupportedBeautyTypes(): Array\<BeautyType\>

获取当前支持的美颜效果列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| 返回当前支持的美颜效果列表。                             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |  Not System Application.                                   |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyTypes(portraitPhotoSession: camera.PortraitPhotoSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```

### getSupportedBeautyRange<sup>11+</sup>

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |  Not System Application.                                   |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyRange(portraitPhotoSession: camera.PortraitPhotoSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

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

## ManualExposureQuery<sup>12+</sup>

此接口提供了查询设备对手动曝光范围支持的功能。

### getSupportedExposureRange<sup>11+</sup>

getSupportedExposureRange(): Array\<number\>

获取当前支持的手动曝光时长，单位ms。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<number\>| 返回当前支持的手动曝光时长，单位ms。                             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |  Not System Application.  |
| 7400101            |  Parameter missing or parameter type incorrect.  |
| 7400103            |  Session not config, only throw in session usage.  |

 **示例：**

```ts
function getSupportedExposureRange(nightPhotoSession: camera.NightPhotoSession): Array<number> {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  return exposureRange;
}
```

## ManualExposure<sup>11+</sup>

ManualExposure extends [ManualExposureQuery](#manualexposurequery12)

提供了获取和设置曝光值的功能。

### getExposure<sup>11+</sup>

getExposure(): number

查询当前已设置的手动曝光时长，单位为ms。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**
| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| value     | number | 是   | 手动曝光时长，单位为ms。  |

**错误码：**
 
以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                               |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getExposure(nightPhotoSession: camera.NightPhotoSession): number | undefined {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return undefined;
  }
  let exposure: number = nightPhotoSession.getExposure();
  return exposure;
}
```

### setExposure<sup>11+</sup>

setExposure(exposure: number): void

设置手动曝光时长。[getSupportedExposureRange](#getsupportedexposurerange11)获取得到支持的手动曝光时长列表选取用户所需的时长下发，单位ms。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                                                      |
| -------- | --------------------------| ---- |-------------------------------------------------------------------------|
| value    | number                    | 是   | 手动曝光时长，通过[getSupportedExposureRange](#getsupportedexposurerange11)接口获取。 |

 **错误码：**

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                	 |  Not System Application.  |
| 7400102                |  Operation not allowed.   |
| 7400103                |  Session not config.      |

```ts
function setExposure(nightPhotoSession: camera.NightPhotoSession): void {
  let exposureRange: Array<number> = nightPhotoSession.getSupportedExposureRange();
  if (exposureRange === undefined || exposureRange.length <= 0) {
    return;
  }
  nightPhotoSession.setExposure(exposureRange[0]);
}
```

## MacroQuery<sup>12+</sup>

提供用于查询设备是否支持相机微距拍摄的方法。

### isMacroSupported<sup>11+</sup>

isMacroSupported(): boolean

检测当前状态下是否支持微距能力，需要在CaptureSession调用[commitConfig](js-apis-camera.md#commitconfig11-1)之后进行调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
|   boolean  | 返回是否支持微距能力。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                     |
|---------|--------------------------|
| 202     | Not System Application.  |

**示例：**

```ts
function isMacroSupported(photoSession: camera.PhotoSessionForSys): boolean {
  let isSupported: boolean = photoSession.isMacroSupported();
  return isSupported;
}
```

## Macro<sup>11+</sup>

Macro extends [MacroQuery](#macroquery12)

提供了使能微距能力的接口。

### enableMacro<sup>11+</sup>

enableMacro(enabled: boolean): void

使能当前的微距能力，需要在支持微距能力的情况下进行调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| enabled | boolean | 是   | true：开启微距能力，false：关闭微距能力。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID    | 错误信息                     |
|----------|--------------------------|
| 202      | Not System Application.  |
| 7400102  | Operation not allowed.   |
| 7400103  | Session not config.      |

**示例：**

```ts
function enableMacro(photoSession: camera.PhotoSessionForSys): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```

## TripodStatus<sup>13+</sup>

枚举，脚架状态枚举。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 值   | 说明                                  |
|----------|-----|-------------------------------------|
| INVALID  | 0   | 错误状态/默认未检测到脚架状态。**系统接口：** 此接口为系统接口。 |
| ACTIVE   | 1   | 脚架活动状态。**系统接口：** 此接口为系统接口。          |
| ENTERING | 2   | 进入脚架稳定状态。**系统接口：** 此接口为系统接口。        |
| EXITING  | 3   | 退出脚架稳定状态。**系统接口：** 此接口为系统接口。          |


## SceneFeatureType<sup>12+</sup>

枚举，场景特性枚举。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                            | 值   | 说明                        |
|-------------------------------|-----|---------------------------|
| MOON_CAPTURE_BOOST            | 0   | 月亮场景。**系统接口：** 此接口为系统接口。  |
| TRIPOD_DETECTION<sup>13+</sup> | 1   | 使用脚架拍摄的场景。**系统接口：** 此接口为系统接口。  |
| LOW_LIGHT_BOOST<sup>13+</sup> | 1   | 长曝光场景。**系统接口：** 此接口为系统接口。 |

## SceneFeatureDetectionResult<sup>12+</sup>

场景检测结果信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型        |   只读   |   必填   | 说明       |
| -------- | ---------- | -------- | -------- | ---------- |
| featureType |   [SceneFeatureType](#scenefeaturetype12)   |   是     |    是    | 特性类型。 |
| detected |   boolean   |   是     |    是    | 检测结果。true为检测到指定特性场景。 |

## TripodDetectionResult<sup>13+</sup>

TripodDetectionResult extends [SceneFeatureDetectionResult](#scenefeaturedetectionresult12)

脚架检测信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型                              |   只读   |   必填   | 说明      |
| -------- |---------------------------------| -------- | -------- |---------|
| tripodStatus | [TripodStatus](#tripodstatus13) |   是     |    是    | 脚架状态信息。 |

## SceneDetection<sup>12+</sup>

场景检测能力。

### isSceneFeatureSupported<sup>12+</sup>

isSceneFeatureSupported(type: SceneFeatureType): boolean

查询是否支持指定特性。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名   | 类型                                        | 必填  | 说明          |
|-------|-------------------------------------------|-----|-------------|
| type  | [SceneFeatureType](#scenefeaturetype12)   | 是   | 指定对应的场景特性。  |

**返回值：**

| 类型        | 说明           |
|-----------|--------------|
| boolean   | 返回是否支持指定特性。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                                           |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
function isSceneFeatureSupported(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): boolean {
  let isSupported: boolean = photoSession.isSceneFeatureSupported(featureType);
  return isSupported;
}
```

### enableSceneFeature<sup>12+</sup>

enableSceneFeature(type: SceneFeatureType, enabled: boolean): void

使能指定特性，该接口应当在收到对应场景检测回调结果[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)之后调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                        | 必填  | 说明                          |
|---------|-------------------------------------------|-----|-----------------------------|
| type    | [SceneFeatureType](#scenefeaturetype12)   | 是   | 指定需要开启或关闭的特性。               |
| enabled | boolean                                   | 是   | true表明开启指定特性，false表明关闭指定特性。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                                           |
|---------|------------------------------------------------|
| 202     | Not System Application.                        |
| 7400101 | Parameter missing or parameter type incorrect. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableSceneFeature(photoSession: camera.PhotoSessionForSys, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput): void {
  photoSession.beginConfig();
  photoSession.addInput(cameraInput);
  photoSession.addOutput(previewOutput);
  photoSession.commitConfig();

  photoSession.on('featureDetection', camera.SceneFeatureType.MOON_CAPTURE_BOOST,
    (err: BusinessError, statusObject: camera.SceneFeatureDetectionResult) => {
      if (err !== undefined && err.code !== 0) {
        console.error(`Callback Error, errorCode: ${err.code}`);
        return;
      }
      console.info(
        `on featureDetectionStatus featureType:${statusObject.featureType} detected:${statusObject.detected}`);
      if (statusObject.featureType === camera.SceneFeatureType.MOON_CAPTURE_BOOST) {
        try {
          photoSession.enableSceneFeature(statusObject.featureType, statusObject.detected);
        } catch (error) {
          let err = error as BusinessError;
          console.error(`The enableSceneFeature call failed. error code: ${err.code}`);
        }
      }
    });
}
```

## ZoomPointInfo<sup>12+</sup>

等效焦距信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型        |   只读   | 可选  | 说明       |
| -------- | ---------- | -------- |-----| ---------- |
| zoomRatio |   number   |   是     | 否   | 可变焦距比。 |
| equivalentFocalLength |   number   |   是     | 否   | 当前焦距比对应的等效焦距值。 |

## ZoomQuery<sup>12+</sup>

提供获取当前模式的等效焦距信息列表的方法。

### getZoomPointInfos<sup>12+</sup>

getZoomPointInfos(): Array\<ZoomPointInfo\>

获取当前模式的等效焦距信息列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<[ZoomPointInfo](#zoompointinfo12)\>| 获取当前模式的等效焦距信息列表。                   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomPointInfos(): Array<ZoomPointInfo> {
  try {
    let zoomPointInfos: Array<ZoomPointInfo> = sessionExtendsZoom.getZoomPointInfos();
	return zoomPointInfos;
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getZoomPointInfos call failed. error code: ${err.code}`);
  }
}
```

## Zoom<sup>11+</sup>

Zoom extend [ZoomQuery](#zoomquery12)

提供了处理设备变焦效果的相关方法，包括获取当前的变焦比，设置变焦比率，以及通过平滑方法设置目标变焦比，以及一些开启和结束变焦的函数。

### prepareZoom<sup>11+</sup>

prepareZoom(): void

通知底层准备变焦，如sensor上电。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function prepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.prepareZoom();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The prepareZoom call failed. error code: ${err.code}`);
  }
}
```

### unprepareZoom<sup>11+</sup>

unprepareZoom(): void

通知底层离开变焦准备状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                      |
| 7400103                |  Session not config.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function unprepareZoom(sessionExtendsZoom: camera.Zoom): void {
  try {
    sessionExtendsZoom.unprepareZoom();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The unprepareZoom call failed. error code: ${err.code}`);
  }
}
```

## ZoomRange<sup>11+</sup>

获取支持的变焦范围。变焦范围为[min, max)，即包括最小值，不包括最大值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型           | 只读 | 必填 | 说明         |
| -------- | ------------- |---- | ---- | -------------|
| min      | number        | 是  |  N/A  | 获取的可变焦距范围的最小值  |
| max      | number        | 是  |  N/A  | 获取的可变焦距范围的最大值。 |

## Beauty<sup>11+</sup>

Beauty extends [BeautyQuery](#beautyquery12)

提供了获取和设置美颜效果的方法。

### setBeauty<sup>11+</sup>

setBeauty(type: BeautyType, value: number): void

设置美颜类型以及对应的美颜强度。将通过[getSupportedBeautyTypes](#getsupportedbeautytypes11)获取得到的[BeautyType](#beautytype)都关闭，表明当前美颜关闭；若有一种美颜类型未关闭，表明当前美颜打开。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                                                |
| -------- | --------------------------| ---- |-------------------------------------------------------------------|
| type     | [BeautyType](#beautytype) | 是   | 美颜类型。                                                             |
| value    | number                    | 是   | 美颜强度，通过[getSupportedBeautyRange](#getsupportedbeautyrange11)接口获取。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |  Not System Application.                                   |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function setBeauty(portraitPhotoSession: camera.PortraitPhotoSession): void {
  let beautyTypes: Array<camera.BeautyType> = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  portraitPhotoSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty<sup>11+</sup>

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |  Not System Application.                                   |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getBeauty(portraitPhotoSession: camera.PortraitPhotoSession): number {
  const invalidValue: number = -1;
  let beautyTypes = portraitPhotoSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = portraitPhotoSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  portraitPhotoSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = portraitPhotoSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## ColorEffectQuery<sup>12+</sup>

提供了一个查询设备支持的颜色效果类型的方法。

### getSupportedColorEffects<sup>11+</sup>

getSupportedColorEffects(): Array\<ColorEffectType\>

获取支持的色彩效果类型列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[ColorEffectType](#coloreffecttype11)>       | 支持的色彩效果类型列表。           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                      |
| 202             |  Not System Application.                  |

**示例：**

```ts
function getSupportedColorEffects(session: camera.PhotoSessionForSys): Array<camera.ColorEffectType> {
  let colorEffects: Array<camera.ColorEffectType> = session.getSupportedColorEffects();
  return colorEffects;
}
```

## ColorEffect<sup>11+</sup>

ColorEffect extends [ColorEffectQuery](#coloreffectquery12)

提供了获取和设置镜头色彩效果的相关功能。

### setColorEffect<sup>11+</sup>

setColorEffect(type: ColorEffectType): void

设置色彩效果类型。可以先通过[getSupportedColorEffects](#getsupportedcoloreffects11)获取当前设备所支持的ColorEffects。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                                                            | 必填 | 说明                      |
| ------------ |--------------------------------------------------------------- | -- | -------------------------- |
| type | [ColorEffectType](#coloreffecttype11)                              | 是 | 色彩效果类型，通过[getSupportedColorEffects](#getsupportedcoloreffects11)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function setColorEffect(session: camera.PhotoSessionForSys, colorEffect: camera.ColorEffectType): void {
  session.setColorEffect(colorEffect);
}
```

### getColorEffect<sup>11+</sup>

getColorEffect(): ColorEffectType

获取当前设置的色彩效果类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [ColorEffectType](#coloreffecttype11)             | 当前设置的色彩效果类型。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
function getColorEffect(session: camera.PhotoSessionForSys): camera.ColorEffectType {
  let colorEffect: camera.ColorEffectType = session.getColorEffect();
  return colorEffect;
}
```

## ColorEffectType<sup>11+</sup>

枚举，色彩效果类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                  | 值   | 说明       |
| --------------------- | ---- | --------- |
| NORMAL                | 0    | 常规的色彩效果。  |
| BRIGHT                | 1    | 明艳的色彩效果。  |
| SOFT                  | 2    | 柔和的色彩效果。  |
| BLACK_WHITE<sup>12+</sup>    | 3    | 黑白色彩效果。  |

## Portrait<sup>11+</sup>

人像类，用于设置人像参数。

### getSupportedPortraitEffects<sup>10+</sup>

getSupportedPortraitEffects(): Array\<PortraitEffect\>

获取支持的人像虚化效果列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[PortraitEffect](#portraiteffect)> | 支持的人像虚化效果列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**示例：**

```ts
function getSupportedPortraitEffects(portraitPhotoSession: camera.PortraitPhotoSession): Array<camera.PortraitEffect> {
  let portraitEffects: Array<camera.PortraitEffect> = portraitPhotoSession.getSupportedPortraitEffects();
  return portraitEffects;
}
```

### setPortraitEffect<sup>10+</sup>

setPortraitEffect(effect: PortraitEffect): void

设置人像虚化效果。需要先检查设备是否支持人像虚化模式，可以通过[getSupportedPortraitEffects](#getsupportedportraiteffects10)获取当前设备所支持的PortraitEffects。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                        | 必填 | 说明                      |
| ------------ |----------------------------- | -- | -------------------------- |
| effect | [PortraitEffect](#portraiteffect)  | 是 | 人像虚化效果，通过[getSupportedPortraitEffects](#getsupportedportraiteffects10)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                                   |
| 202             |  Not System Application.                         |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setPortraitEffect(portraitPhotoSession: camera.PortraitPhotoSession, portraitEffects: Array<camera.PortraitEffect>): void {
  if (portraitEffects === undefined || portraitEffects.length <= 0) {
    return;
  }
  try {
    portraitPhotoSession.setPortraitEffect(portraitEffects[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The setPortraitEffect call failed. error code: ${err.code}`);
  }
}
```

### getPortraitEffect<sup>10+</sup>

getPortraitEffect(): PortraitEffect

获取当前设置的人像虚化效果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| [PortraitEffect](#portraiteffect)               | 当前设置的人像虚化效果。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                |
| 202             |  Not System Application.            |

**示例：**

```ts
function getPortraitEffect(portraitPhotoSession: camera.PortraitPhotoSession): camera.PortraitEffect {
  let portraitEffect: camera.PortraitEffect = portraitPhotoSession.getPortraitEffect();
  return portraitEffect;
}
```

## PhysicalAperture<sup>11+</sup>

物理光圈信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称       | 类型                       |  只读 | 可选  | 说明               |
| ---------- | ------------------------- | ----- |-----| ----------------- |
| zoomRange  | [ZoomRange](#zoomrange11) | 否    | 否   | 特定物理光圈的变焦范围。  |
| apertures  | Array\<number\>           | 否    | 否   | 支持的物理光圈列表。      |

## Aperture<sup>11+</sup>

光圈类，用于设置光圈参数。

### getSupportedVirtualApertures<sup>11+</sup>

getSupportedVirtualApertures(): Array\<number\>

获取支持的虚拟光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array\<number\> | 支持的虚拟光圈列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

### getVirtualAperture<sup>11+</sup>

getVirtualAperture(): number

获取当前设置的虚拟光圈值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| number               | 当前设置的虚拟光圈值。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

### setVirtualAperture<sup>11+</sup>

setVirtualAperture(aperture: number): void

设置虚拟光圈。可以线通过[getSupportedVirtualApertures](#getsupportedvirtualapertures11)获取当前设备所支持的虚拟光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                    | 必填 | 说明                      |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | 是 | 虚拟光圈值，通过[getSupportedVirtualApertures](#getsupportedvirtualapertures11)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103         |  Session not config.                          |
| 202             |  Not System Application.                      |

**示例：**

```ts
function setVirtualAperture(session: camera.PortraitPhotoSession, virtualAperture: number): void {
  session.setVirtualAperture(virtualAperture);
}
```

### getSupportedPhysicalApertures<sup>11+</sup>

getSupportedPhysicalApertures(): Array\<PhysicalAperture\>

获取支持的物理光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                                             | 说明                           |
| ----------------------------------------------- | ---------------------------- |
| Array<[PhysicalAperture](#physicalaperture11)>    | 支持的物理光圈列表。               |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

### getPhysicalAperture<sup>11+</sup>

getPhysicalAperture(): number

获取当前设置的物理光圈值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                 | 说明                           |
| -------------------- | ---------------------------- |
| number               | 当前设置的物理光圈值。           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

### setPhysicalAperture<sup>11+</sup>

setPhysicalAperture(aperture: number): void

设置物理光圈。可以线通过[getSupportedPhysicalApertures](#getsupportedphysicalapertures11)获取当前设备所支持的物理光圈列表。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名         | 类型                    | 必填 | 说明                      |
| ------------ |------------------------- | -- | -------------------------- |
| aperture       | number                 | 是 | 物理光圈值，通过[getSupportedPhysicalApertures](#getsupportedphysicalapertures11)接口获取。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

拍照会话类，保存一次相机运行所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)，并向相机设备申请完成相机功能(录像，拍照)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[PhotoSession](#photosession11)、[VideoSession](#videosession11)替代。

### getSupportedBeautyTypes<sup>(deprecated)</sup>

getSupportedBeautyTypes(): Array\<BeautyType>

获取当前支持的美颜效果列表。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Beauty.getSupportedBeautyTypes](#getsupportedbeautytypes11)替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型                | 说明                                                  |
| ----------          | -----------------------------                         |
|  Array\<[BeautyType](#beautytype)\>| 返回当前支持的美颜效果列表。                             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyTypes(captureSession: camera.CaptureSession): Array<camera.BeautyType> {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  return beautyTypes;
}
```

### getSupportedBeautyRange<sup>(deprecated)</sup>

getSupportedBeautyRange(type: BeautyType): Array\<number\>

获取指定美颜效果的范围值。在不同设备返回的美颜强度有所不同，下表仅做示例。

| 传入参数           | 示例返回值    | 返回值说明     |
| ----------------| ----  | ---------|
| AUTO           | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     |美颜类型为自动时支持的美颜强度，0表明关闭美颜，其余正值表明自动的美颜强度。    |
| SKIN_SMOOTH    | [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]     | 美颜类型为光滑时支持的美颜强度，0表明关闭光滑，其余正值表明光滑的美颜强度。    |
| FACE_SLENDER   | [0, 1, 2, 3, 4, 5]      | 美颜类型为瘦脸时支持的美颜强度，0表明关闭瘦脸，其余正值表明瘦脸的美颜强度。   |
| SKIN_TONE      | [-1, 16242611]      | 美颜类型为美肤时支持的美颜强度，-1表明关闭美肤，其余非负值为使用RGB表示的美肤美颜强度，<br> 16242611转化为16进制为0xF7D7B3，F7为R通道值，D7为G通道值，B3位B通道值。    |

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)替代。

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedBeautyRange(captureSession: camera.CaptureSession): Array<number> {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return [];
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  return beautyLevels;
}
```

### setBeauty<sup>(deprecated)</sup>

setBeauty(type: BeautyType, value: number): void

设置美颜类型以及对应的美颜强度。将通过[getSupportedBeautyTypes](#getsupportedbeautytypesdeprecated)获取得到的[BeautyType](#beautytype)都关闭，表明当前美颜关闭；若有一种美颜类型未关闭，表明当前美颜打开。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Beauty.setBeauty](#setbeauty11)替代。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                   |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | 是   | 美颜类型 。              |
| value    | number                    | 是   | 美颜强度，通过[getSupportedBeautyRange](#getsupportedbeautyrangedeprecated)接口获取。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function setBeauty(captureSession: camera.CaptureSession): void {
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return;
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return;
  }
  captureSession.setBeauty(beautyTypes[0], beautyLevels[0]);
}
```

### getBeauty<sup>(deprecated)</sup>

getBeauty(type: BeautyType): number

查询当前已设置的美颜效果对应的美颜强度。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Beauty.getBeauty](#getbeauty11)替代。

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getBeauty(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let beautyTypes: Array<camera.BeautyType> = captureSession.getSupportedBeautyTypes();
  if (beautyTypes === undefined || beautyTypes.length <= 0) {
    return invalidValue;
  }
  let beautyLevels: Array<number> = captureSession.getSupportedBeautyRange(beautyTypes[0]);
  if (beautyLevels === undefined || beautyLevels.length <= 0) {
    return invalidValue;
  }
  captureSession.setBeauty(beautyTypes[0], beautyLevels[0]);
  let beautyLevel: number = captureSession.getBeauty(beautyTypes[0]);
  return beautyLevel;
}
```

## PhotoSessionForSys<sup>11+</sup>

PhotoSessionForSys extends PhotoSession, Beauty, ColorEffect, ColorManagement, Macro, SceneDetection

提供给系统应用的PhotoSession，普通拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## PhotoSession<sup>11+</sup>

PhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorManagement

普通拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('macroStatusChanged')<sup>11+</sup>

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, macroStatus: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Macro state: ${macroStatus}`);
}

function registerMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.on('macroStatusChanged', callback);
}
```

### off('macroStatusChanged')<sup>11+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销监听相机微距状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。|
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，有就是匹配on('macroStatusChanged') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

### on('featureDetection')<sup>12+</sup>

on(type: 'featureDetection', featureType: SceneFeatureType, callback: AsyncCallback\<SceneFeatureDetectionResult\>): void

监听相机特性检测状态变化。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'featureDetection'，photoSession创建成功可监听。 |
| featureType     | [SceneFeatureType](#scenefeaturetype12)      | 是   | 监听指定特性。 |
| callback | AsyncCallback\<[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)\>     | 是   | 回调函数，用于获取当前监听的特性的状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, result: camera.SceneFeatureDetectionResult): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`feature type: ${result.featureType}`);
  console.info(`feature status: ${result.detected}`);
}

function registerFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.on('featureDetection', featureType, callback);
}
```

### off('featureDetection')<sup>12+</sup>

off(type: 'featureDetection', featureType: SceneFeatureType, callback?: AsyncCallback\<SceneFeatureDetectionResult\>): void

注销监听相机特性检测状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | 是   | 监听事件，固定为'featureDetection'，session创建成功可取消监听。|
| featureType     | [SceneFeatureType](#scenefeaturetype12)      | 是   | 指定特性。 |
| callback | AsyncCallback\<[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)\> | 否   | 回调函数，可选，有就是匹配on('featureDetection') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.off('featureDetection', featureType);
}
```

### on('lcdFlashStatus')<sup>13+</sup>

on(type: 'lcdFlashStatus', callback: AsyncCallback\<LcdFlashStatus\>): void

监听LCD闪光灯状态变化。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                                       |
| -------- | ----------------------------------------- | ---- |------------------------------------------|
| type     | string      | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可监听。 |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>     | 是   | 回调函数，用于获取当前lcd flash状态。                  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, lcdFlashStatus: camera.LcdFlashStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isLcdFlashNeeded: ${lcdFlashStatus.isLcdFlashNeeded}`);
  console.info(`lcdCompensation: ${lcdFlashStatus.lcdCompensation}`);
}

function registerLcdFlashStatus(photoSession: camera.PhotoSession): void {
  photoSession.on('lcdFlashStatus', callback);
}
```

### off('lcdFlashStatus')<sup>13+</sup>

off(type: 'lcdFlashStatus', callback?: AsyncCallback\<LcdFlashStatus\>): void

注销监听LCD闪光灯状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                                                               |
| -------- | ------------------------ | ---- |------------------------------------------------------------------|
| type     | string                   | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可取消监听。                       |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | 否   | 回调函数，可选，有就是匹配on('lcdFlashStatus') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterLcdFlashStatus(photoSession: camera.PhotoSession): void {
  photoSession.off('lcdFlashStatus');
}
```

## FocusTrackingMode<sup>15+</sup>

枚举，对焦追踪模式。

**系统能力**： SystemCapability.Multimedia.Camera.Core

| 名称 | 值   | 说明   |
| ---- | ---- | ------ |
| AUTO | 0    | 自动。 |

## FocusTrackingInfo<sup>15+</sup>

相机对焦追踪信息，通过VideoSessionForSys.[on('focusTrackingInfoAvailable')](#onfocustrackinginfoavailable15)接口获取。

**系统能力**： SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                                      | 只读 | 可选 | 说明       |
| -------------- | ----------------------------------------- | ---- | ---- | ---------- |
| trackingMode   | [FocusTrackingMode](#focustrackingmode15) | 否   | 否   | 跟踪模式。 |
| trackingRegion | [Rect](js-apis-camera.md#rect)            | 否   | 否   | 跟踪区域。 |

## VideoSessionForSys<sup>11+</sup>

VideoSessionForSys extends VideoSession, Beauty, ColorEffect, ColorManagement, Macro, Aperture, ColorReservation

提供给系统应用的VideoSession，普通录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Stabilization, ColorManagement

普通录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('macroStatusChanged')<sup>11+</sup>

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, macroStatus: boolean): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Macro state: ${macroStatus}`);
}

function registerMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.on('macroStatusChanged', callback);
}
```

### off('macroStatusChanged')<sup>11+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销监听相机微距状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                       |
| -------- | ------------------------ | ---- | ------------------------ |
| type     | string                   | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。|
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，有就是匹配on('macroStatusChanged') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```

### on('lcdFlashStatus')<sup>13+</sup>

on(type: 'lcdFlashStatus', callback: AsyncCallback\<LcdFlashStatus\>): void

监听LCD闪光灯状态变化。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                                       |
| -------- | ----------------------------------------- | ---- |------------------------------------------|
| type     | string      | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可监听。 |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>     | 是   | 回调函数，用于获取当前lcd flash状态。                  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, lcdFlashStatus: camera.LcdFlashStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isLcdFlashNeeded: ${lcdFlashStatus.isLcdFlashNeeded}`);
  console.info(`lcdCompensation: ${lcdFlashStatus.lcdCompensation}`);
}

function registerLcdFlashStatus(videoSession: camera.VideoSession): void {
  videoSession.on('lcdFlashStatus', callback);
}
```

### off('lcdFlashStatus')<sup>13+</sup>

off(type: 'lcdFlashStatus', callback?: AsyncCallback\<LcdFlashStatus\>): void

注销监听LCD闪光灯状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                                                               |
| -------- | ------------------------ | ---- |------------------------------------------------------------------|
| type     | string                   | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可取消监听。                       |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | 否   | 回调函数，可选，有就是匹配on('lcdFlashStatus') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterLcdFlashStatus(videoSession: camera.VideoSession): void {
  videoSession.off('lcdFlashStatus');
}
```

### on('focusTrackingInfoAvailable')<sup>15+</sup>

on(type: 'focusTrackingInfoAvailable', callback: Callback\<FocusTrackingInfo\>): void

监听相机对焦跟踪信息，通过注册回调函数获取结果。使用callback方式返回结果。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'focusTrackingInfoAvailable'，VideoSessionForSys创建成功可监听。 |
| callback | Callback\<[FocusTrackingInfo](#focustrackinginfo15)\>      | 是   | 回调函数，用于获取当前对焦跟踪信息。                         |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |

**示例**：

```ts
function callback(focusTrackingInfo: camera.FocusTrackingInfo): void {
  console.info(`Focus tracking mode: ${focusTrackingInfo.trackingMode}`);
  console.info(`Focus tracking Region: topLeftX ${focusTrackingInfo.trackingRegion.topLeftX}
                                       topLeftY ${focusTrackingInfo.trackingRegion.topLeftY}
                                       width ${focusTrackingInfo.trackingRegion.width}
                                       height ${focusTrackingInfo.trackingRegion.height}`);
}

function registerFocusTrakingInfoChanged(session: camera.VideoSessionForSys): void {
  session.on('focusTrackingInfoAvailable', callback);
}
```

### off('focusTrackingInfoAvailable')<sup>15+</sup>

off(type: 'focusTrackingInfoAvailable', callback?: Callback\<FocusTrackingInfo\>): void

注销监听相机对焦跟踪信息。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名   | 类型                                                       | 必填 | 说明                                                         |
| -------- | ---------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                                     | 是   | 监听事件，固定为'focusTrackingInfoAvailable'，videoSessionForSys创建成功可监听。 |
| callback | Callback\<[FocusTrackingInfo](#focustrackinginfo15)\>      | 否   | 回调函数，可选，有就是匹配on('focusTrackingInfoAvailable') callback（callback对象不可是匿名函数）。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |

**示例**：

```ts
function unregisterFocusTrakingInfoChanged(session: camera.VideoSessionForSys): void {
  session.off('focusTrackingInfoAvailable');
}
```

## PortraitPhotoSession<sup>11+</sup>

PortraitPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Portrait, Aperture

人像拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置人像拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听人像拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听人像拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匹配on('error') callback（callback对象不可是匿名函数）。    |

**示例：**

```ts
function unregisterSessionError(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('smoothZoomInfoAvailable', callback);
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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，可选，有就是匹配on('smoothZoomInfoAvailable') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('smoothZoomInfoAvailable');
}
```

### on('lcdFlashStatus')<sup>13+</sup>

on(type: 'lcdFlashStatus', callback: AsyncCallback\<LcdFlashStatus\>): void

监听LCD闪光灯状态变化。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                                       |
| -------- | ----------------------------------------- | ---- |------------------------------------------|
| type     | string      | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可监听。 |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>     | 是   | 回调函数，用于获取当前lcd flash状态。                  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, lcdFlashStatus: camera.LcdFlashStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isLcdFlashNeeded: ${lcdFlashStatus.isLcdFlashNeeded}`);
  console.info(`lcdCompensation: ${lcdFlashStatus.lcdCompensation}`);
}

function registerLcdFlashStatus(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('lcdFlashStatus', callback);
}
```

### off('lcdFlashStatus')<sup>13+</sup>

off(type: 'lcdFlashStatus', callback?: AsyncCallback\<LcdFlashStatus\>): void

注销监听LCD闪光灯状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                                                               |
| -------- | ------------------------ | ---- |------------------------------------------------------------------|
| type     | string                   | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可取消监听。                       |
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | 否   | 回调函数，可选，有就是匹配on('lcdFlashStatus') callback（callback对象不可是匿名函数）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterLcdFlashStatus(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.off('lcdFlashStatus');
}
```

## NightPhotoSession<sup>11+</sup>

NightPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ColorManagement, ManualExposure

夜景拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置夜景拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听夜景拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Night photo session error code: ${err.code}`);
}

function registerSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('error', callback);
}
```

### off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听夜景拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匹配on('error') callback（callback对象不可是匿名函数）。       |

**示例：**

```ts
function unregisterSessionError(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('smoothZoomInfoAvailable', callback);
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
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，可选，有就是匹配on('smoothZoomInfoAvailable') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterSmoothZoomInfo(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('smoothZoomInfoAvailable');
}
```

### on('lcdFlashStatus')<sup>12+</sup>

on(type: 'lcdFlashStatus', callback: AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>): void

监听lcd flash状态，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可监听。|
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | 是   | 回调函数，用于获取当前lcd flash状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, lcdFlashStatus: camera.LcdFlashStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`lcdFlashStatus: ${lcdFlashStatus}`);
}

function registerLcdFlashStatus(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('lcdFlashStatus', callback);
}
```

### off('lcdFlashStatus')<sup>12+</sup>

off(type: 'lcdFlashStatus', callback?: AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\>): void

注销lcd flash状态，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'lcdFlashStatus'，session创建成功可监听。|
| callback | AsyncCallback\<[LcdFlashStatus](#lcdflashstatus12)\> | 否   | 回调函数，可选，有就是匹配on('lcdFlashStatus') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                      |
|-------|---------------------------|
| 202   | Not System Application.   |

**示例：**

```ts
function unregisterLcdFlashStatus(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.off('lcdFlashStatus');
}
```

## HighResolutionPhotoSession<sup>12+</sup>

HighResolutionPhotoSession extends Session, AutoExposure, Focus

高像素拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置高像素拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听高像素拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。        |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`High resolution photo session error code: ${err.code}`);
}

function registerSessionError(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.on('error', callback);
}
```
### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听高像素拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匹配on('error') callback（callback对象不可是匿名函数）。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**示例：**

```ts
function unregisterSessionError(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                |   Not System Application.               |

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterFocusStateChange(highResolutionPhotoSession: camera.HighResolutionPhotoSession): void {
  highResolutionPhotoSession.off('focusStateChange');
}
```

## SketchStatusData<sup>11+</sup>

画中画状态返回数据。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称          | 类型      | 只读 | 必填 | 说明        |
| ------------- | -------- | ---- | ---- | ---------- |
| status        | number   | 否   | 是   | 画中画当前的状态。0：已停止，1：已启动，2：停止中，3：启动中。|
| sketchRatio   | number   | 否   | 是   | 画中画画面的Zoom倍率。|

## SlowMotionVideoSession<sup>12+</sup>

SlowMotionVideoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect

慢动作录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置慢动作录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

> **说明：**
> 慢动作模式下只能添加预览流和录像流。
### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听慢动作录像模式会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。        |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销慢动作录像模式会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | -------------------------- | ---- | ------------------------------ |
| type     | string                     | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匹配on('error') callback（callback对象不可是匿名函数）。    |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSessionError(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterFocusStateChange(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，可选，有就是匹配on('smoothZoomInfoAvailable') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSmoothZoomInfo(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('smoothZoomInfoAvailable');
}
```

### on('slowMotionStatus')<sup>12+</sup>

on(type: 'slowMotionStatus', callback: AsyncCallback\<SlowMotionStatus\>): void

监听慢动作状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                                        | 必填 | 说明                                         |
| -------- |---------------------------------------------------------------------------| ---- |--------------------------------------------|
| type     | string                                                                    | 是   | 监听事件，固定为'slowMotionStatus'，session创建成功可监听。 |
| callback | AsyncCallback\<[SlowMotionStatus](#slowmotionstatus12)\> | 是   | 回调函数，用于获取当前慢动作状态。当慢动作状态发生变动时，此回调函数也会被执行。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, slowMotionStatus: camera.SlowMotionStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The slow motion status: ${slowMotionStatus}`);
}

function registerSlowMotionStatus(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('slowMotionStatus', callback);
}
```

### off('slowMotionStatus')<sup>12+</sup>

off(type: 'slowMotionStatus', callback?: AsyncCallback\<SlowMotionStatus\>): void

注销慢动作状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'slowMotionStatus'，session创建成功可监听。|
| callback | AsyncCallback\<[SlowMotionStatus](#slowmotionstatus12)\> | 否   | 回调函数，可选，有就是匹配on('slowMotionStatus') callback（callback对象不可是匿名函数）。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application.                               |

**示例：**

```ts
function unregisterSlowMotionStatus(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.off('slowMotionStatus');
}
```
### isSlowMotionDetectionSupported<sup>12+</sup>

isSlowMotionDetectionSupported(): boolean

查询当前设备是否支持慢动作检测功能。

> **说明：**
> 该接口需要在[commitConfig](js-apis-camera.md#commitconfig11-1)之后调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                                                                                     |
| ---------- |----------------------------------------------------------------------------------------|
| boolean    | 返回true表示支持慢动作检测功能，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application.                               |
| 7400103 |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isSlowMotionDetectionSupported(slowMotionVideoSession: camera.SlowMotionVideoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = slowMotionVideoSession.isSlowMotionDetectionSupported();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### setSlowMotionDetectionArea<sup>12+</sup>

setSlowMotionDetectionArea(area: Rect): void

设置一个进行慢动作检测的区域。

> **说明：**
> 在调用该方法之前，先调用[isSlowMotionDetectionSupported](#isslowmotiondetectionsupported12)确认设备是否支持慢动作检测功能, 才能保证其他相关方法的正常运行。 
该接口需要在[commitConfig](js-apis-camera.md#commitconfig11-1)之后调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                            | 必填 | 说明                          |
| -------- | ---------------------------------------------- | ---- | --------------------------- |
| area  | [Rect](js-apis-camera.md#rect)      | 是   | 矩形定义。                   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application.                            |
| 7400101 |  Parameter missing or parameter type incorrect.     |
| 7400103 |  Session not config.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setSlowMotionDetectionArea(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  try {
    slowMotionVideoSession.setSlowMotionDetectionArea({topLeftX: 0.1, topLeftY: 0.1, width: 0.8, height: 0.8});
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setSlowMotionDetectionArea call failed. error code: ${err.code}`);
  }
}
```

## PanoramaPhotoSession<sup>12+</sup>

PanoramaPhotoSession extends Session, Focus, AutoExposure, WhiteBalance, ColorEffect

全景拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置全景拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听全景拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Panorama photo session error code: ${err.code}`);
}

function registerSessionError(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听全景拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匹配on('error') callback（callback对象不可是匿名函数）。       |

**示例：**

```ts
function unregisterSessionError(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**示例：**

```ts
function unregisterFocusStateChange(panoramaPhotoSession: camera.PanoramaPhotoSession): void {
  panoramaPhotoSession.off('focusStateChange');
}
```

## IsoInfo<sup>12+</sup>

ISO参数信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型    | 只读 | 可选 | 说明           |
| ---- | ------- | ---- |--| -------------- |
| iso  | number  | 是   | 是 | ISO值。        |

---

## ExposureInfo<sup>12+</sup>

曝光参数信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称              | 类型    | 只读 | 可选  | 说明               |
| ----------------- | ------- | ---- |-----| ------------------ |
| exposureTime | number  | 是   | 是   | 曝光时间值，单位为毫秒。 |

---

## ApertureInfo<sup>12+</sup>

光圈参数信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称      | 类型    | 只读 | 可选  | 说明       |
| --------- | ------- | ---- |-----| ---------- |
| aperture  | number  | 是   | 是   | 光圈值。   |

---

## LuminationInfo<sup>12+</sup>

光照参数信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称        | 类型    | 只读 | 可选  | 说明       |
| ----------- | ------- | ---- |-----| ---------- |
| lumination  | number  | 是   | 是   | 范围[0,1],光照值归一化数值|

## CameraFormat

枚举，输出格式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| CAMERA_FORMAT_DNG<sup>12+</sup>  | 4         | DNG格式的RAW图片。**系统接口：** 此接口为系统接口。         |

## ExposureMeteringMode<sup>12+</sup>

枚举，测光模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| MATRIX          | 0    | 对画面广泛区域进行测光。 |
| CENTER          | 1    | 对整个画面进行测光，但最大比重分配给中央区域。 |
| SPOT            | 2    | 对画面测光点周围约2.5%进行测光 |

## AutoExposureQuery<sup>12+</sup>

提供了查询设备是否支持特定曝光模式，曝光补偿的范围，以及是否支持特定的曝光测光模式的方法。

### isExposureMeteringModeSupported<sup>12+</sup>

isExposureMeteringModeSupported(aeMeteringMode: ExposureMeteringMode): boolean

检测传入的测光模式是否支持。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMeteringMode   | [ExposureMeteringMode](#exposuremeteringmode12)  | 是   | 测光模式。                      |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 获取是否支持传入的测光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.                                   |
| 7400103                |  Session not config.                                   |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureMeteringModeSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = professionalPhotoSession.isExposureModeSupported(camera.ExposureMeteringMode.CENTER);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isExposureMeteringModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## AutoExposure

AutoExposure extends [AutoExposureQuery](#autoexposurequery12)

提供了处理设备自动曝光的相关功能，包括获取和设置曝光模式、测量点，查询补偿范围，设定曝光补偿，和获取设置曝光的测光模式。

### getExposureMeteringMode<sup>12+</sup>

getExposureMeteringMode(): ExposureMeteringMode

获取当前测光模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMeteringMode](#exposuremeteringmode12)    | 获取当前测光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMeteringMode(professionalPhotoSession: camera.ProfessionalPhotoSession): camera.ExposureMeteringMode | undefined {
  let exposureMeteringMode: camera.ExposureMeteringMode | undefined = undefined;
  try {
    exposureMeteringMode = professionalPhotoSession.getExposureMeteringMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureMeteringMode call failed. error code: ${err.code}`);
  }
  return exposureMeteringMode;
}
```

### setExposureMeteringMode<sup>12+</sup>

setExposureMeteringMode(aeMeteringMode: ExposureMeteringMode): void

设置测光模式。进行设置之前，需要先检查设备是否支持指定的测光模式，可使用方法[isExposureMeteringModeSupported](#isexposuremeteringmodesupported12)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMeteringMode   | [ExposureMeteringMode](#exposuremeteringmode12)  | 是   | 测光模式。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMeteringMode(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setExposureMeteringMode(camera.ExposureMeteringMode.CENTER);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setExposureMeteringMode call failed. error code: ${err.code}`);
  }
}
```

## FocusRangeType<sup>15+</sup>

枚举，对焦范围类型。

**系统能力**： SystemCapability.Multimedia.Camera.Core

| 名称 | 值   | 说明       |
| ---- | ---- | ---------- |
| AUTO | 0    | 自动对焦。     |
| NEAR | 1    | 近物对焦。 |

## FocusDrivenType<sup>15+</sup>

枚举，对焦驱动类型。

**系统能力**： SystemCapability.Multimedia.Camera.Core

| 名称 | 值   | 说明       |
| ---- | ---- | ---------- |
| AUTO | 0    | 自动。     |
| FACE | 1    | 人脸驱动。 |

## FocusQuery<sup>12+</sup>

提供了查询是否支持对焦辅助的方法。

### isFocusAssistSupported<sup>12+</sup>

isFocusAssistSupported(): boolean

检测是否支持对焦辅助灯。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示支持对焦辅助灯，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusAssistSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
    status = professionalPhotoSession.isFocusAssistSupported();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFocusAssistSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### isFocusRangeTypeSupported<sup>15+</sup>

isFocusRangeTypeSupported(type: FocusRangeType): boolean

查询是否支持指定的对焦范围类型。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名 | 类型                                | 必填 | 说明                     |
| ------ | ----------------------------------- | ---- | ------------------------ |
| type   | [FocusRangeType](#focusrangetype15) | 是   | 指定对应的对焦范围类型。 |

**返回值**：

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示支持指定的对焦范围类型，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System Application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 7400103  | Session not config.                                          |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusRangeTypeSupported(session: camera.VideoSessionForSys, type: camera.FocusRangeType): boolean {
  let status: boolean = false;
  try {
    status = session.isFocusRangeTypeSupported(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFocusRangeTypeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### isFocusDrivenTypeSupported<sup>15+</sup>

isFocusDrivenTypeSupported(type: FocusDrivenType): boolean

查询是否支持指定的对焦驱动类型。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名 | 类型                                  | 必填 | 说明                     |
| ------ | ------------------------------------- | ---- | ------------------------ |
| type   | [FocusDrivenType](#focusdriventype15) | 是   | 指定对应的对焦驱动类型。 |

**返回值**：

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示支持指定的对焦驱动类型，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System Application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 7400103  | Session not config.                                          |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusDrivenTypeSupported(session: camera.VideoSessionForSys, type: camera.FocusDrivenType): boolean {
  let status: boolean = false;
  try {
    status = session.isFocusDrivenTypeSupported(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFocusDrivenTypeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## Focus

Focus extends [FocusQuery](#focusquery12)

提供了获取和设置相机对焦模式和对焦点位置的方法。

### setFocusAssist<sup>12+</sup>

setFocusAssist(enabled: boolean): void

设置对焦辅助灯。进行设置之前，需要先检查设备是否支持对焦辅助灯，可使用方法[isFocusAssistSupported](#isfocusassistsupported12)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| enabled | boolean | 是   | true：开启对焦辅助灯，false：关闭对焦辅助灯。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusAssist(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setFocusAssist(false);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusAssist call failed. error code: ${err.code}`);
  }
}
```

### getFocusAssist<sup>12+</sup>

getFocusAssist(): boolean

获取对焦辅助灯是否开启。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示相机已打开对焦辅助灯，返回false表示相机已关闭对焦辅助灯。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusAssist(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let isFocusAssistOpened: boolean;
  try {
    isFocusAssistOpened = professionalPhotoSession.getFocusAssist();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusAssist call failed. error code: ${err.code}`);
  }
  return isFocusAssistOpened;
}
```

### setFocusRange<sup>15+</sup>

setFocusRange(type: FocusRangeType): void

设置对焦范围类型。进行设置之前，需要先检查设备是否支持指定的对焦范围类型，可使用方法[isFocusRangeTypeSupported](#isfocusrangetypesupported15)。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| type   | [FocusRangeType](#focusrangetype15) | 是   | 对焦范围类型。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System Application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |
| 7400102  | Operation not allowed.                                       |
| 7400103  | Session not config.                                          |
| 7400201  | Camera service fatal error.                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusRange(session: camera.VideoSessionForSys, type: camera.FocusRangeType): void {
  try {
    session.setFocusRange(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusRange call failed. error code: ${err.code}`);
  }
}
```

### getFocusRange<sup>15+</sup>

getFocusRange(): FocusRangeType

获取当前设置的对焦范围类型。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**返回值**：

| 类型                                | 说明                     |
| ----------------------------------- | ------------------------ |
| [FocusRangeType](#focusrangetype15) | 当前设置的对焦范围类型。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |
| 7400103  | Session not config.     |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusRange(session: camera.VideoSessionForSys): camera.FocusRangeType | undefined {
  let focusRangeType: camera.FocusRangeType | undefined = undefined;
  try {
    focusRangeType = session.getFocusRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusRange call failed. error code: ${err.code}`);
  }
  return focusRangeType;
}
```

### setFocusDriven<sup>15+</sup>

setFocusDriven(type: FocusDrivenType): void

设置对焦驱动类型。进行设置之前，需要先检查设备是否支持指定的对焦驱动类型，可使用方法[isFocusDrivenTypeSupported](#isfocusdriventypesupported15)。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名 | 类型                                  | 必填 | 说明           |
| ------ | ------------------------------------- | ---- | -------------- |
| type   | [FocusDrivenType](#focusdriventype15) | 是   | 对焦驱动类型。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System Application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |
| 7400102  | Operation not allowed.                                       |
| 7400103  | Session not config.                                          |
| 7400201  | Camera service fatal error.                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusDriven(session: camera.VideoSessionForSys, type: camera.FocusDrivenType): void {
  try {
    session.setFocusDriven(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusDriven call failed. error code: ${err.code}`);
  }
}
```

### getFocusDriven<sup>15+</sup>

getFocusDriven(): FocusDrivenType

获取当前设置的对焦驱动类型。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**返回值**：

| 类型                                  | 说明                     |
| ------------------------------------- | ------------------------ |
| [FocusDrivenType](#focusdriventype15) | 当前设置的对焦驱动类型。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |
| 7400103  | Session not config.     |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusDriven(session: camera.VideoSessionForSys): camera.FocusDrivenType | undefined {
  let focusDrivenType: camera.FocusDrivenType | undefined = undefined;
  try {
    focusDrivenType = session.getFocusDriven();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusDriven call failed. error code: ${err.code}`);
  }
  return focusDrivenType;
}
```

## ManualFocus<sup>12+</sup>

手动对焦类，对设备手动设置对焦操作。

### setFocusDistance<sup>12+</sup>

setFocusDistance(distance: number): void

手动设置对焦距离，可设置范围为[0,1]之间的浮点数，0表现为近景，1表现为远景。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| distance | number | 是   | 范围0-1：该值为归一化值，0为近景，1为远景，<br>可在该范围内调节 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusDistance(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let distance: number = 0.5;
    professionalPhotoSession.setFocusDistance(distance);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusDistance call failed. error code: ${err.code}`);
  }
}
```

### getFocusDistance<sup>12+</sup>

getFocusDistance(): number

获取当前的对焦距离。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 返回当前对焦距离的归一化值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusDistance(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let distance: number = 0;
  try {
    distance = professionalPhotoSession.getFocusDistance();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusDistance call failed. error code: ${err.code}`);
  }
  return distance;
}
```

## ManualIsoQuery<sup>12+</sup>

提供了查询设备是否支持手动设置ISO和获取设备支持的ISO范围的方法。

### isManualIsoSupported<sup>12+</sup>

isManualIsoSupported(): boolean

检测是否支持手动ISO。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示支持手动调节ISO，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isManualIsoSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
    status = professionalPhotoSession.isManualIsoSupported();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isManualIsoSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### getIsoRange<sup>12+</sup>

getIsoRange(): Array\<number\>

获取支持的ISO范围。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 用于获取ISO范围，范围为[50,100,...,6400]，实际根据底层能力返回为准，接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getIsoRange(professionalPhotoSession: camera.ProfessionalPhotoSession): Array<number> {
  let isoRange: Array<number> = [];
  try {
    isoRange = professionalPhotoSession.getIsoRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getIsoRange call failed. error code: ${err.code}`);
  }
  return isoRange;
}
```

## ManualIso<sup>12+</sup>

ManualIso extends [ManualIsoQuery](#manualisoquery12)

提供了获取和设置设备手动ISO（感光度）的功能。

### setIso<sup>12+</sup>
setIso(iso: number): void

设置ISO值。**注意：当ISO值设置为0时，表示设置自动ISO**

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| iso | number | 是   | 设置ISO值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setIso(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let iso: number = 200;
    professionalPhotoSession.setIso(iso);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setIso call failed. error code: ${err.code}`);
  }
}
```

### getIso<sup>12+</sup>

getIso(): number

获取当前的ISO值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 返回当前ISO值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getIso(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let iso: number = 0;
  try {
    iso = professionalPhotoSession.getIso();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getIso call failed. error code: ${err.code}`);
  }
  return iso;
}
```

## WhiteBalanceMode<sup>12+</sup>

枚举，白平衡模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| AUTO          | 0    | 自动 |
| CLOUDY        | 1    | 阴天 |
| INCANDESCENT  | 2    | 白炽光 |
| FLUORESCENT   | 3    | 荧光 |
| DAYLIGHT     	| 4    | 日光 |
| MANUAL        | 5    | 手动 |

## WhiteBalanceQuery<sup>12+</sup>

提供了查询设备对指定的白平衡模式是否支持，以及获取设备支持的白平衡模式范围的方法。

### isWhiteBalanceModeSupported<sup>12+</sup>

isWhiteBalanceModeSupported(mode: WhiteBalanceMode): boolean

检测是否支持当前传入的白平衡模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core
**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| mode   | [WhiteBalanceMode](#whitebalancemode12)  | 是   | 白平衡模式。                      |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回true表示支持该白平衡模式，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isWhiteBalanceModeSupported(professionalPhotoSession: camera.ProfessionalPhotoSession): boolean {
  let status: boolean = false;
  try {
	let mode: WhiteBalanceMode = camera.WhiteBalanceMode.DAYLIGHT;
    status = professionalPhotoSession.isWhiteBalanceModeSupported(mode);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isWhiteBalanceModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

### getWhiteBalanceRange<sup>12+</sup>

getWhiteBalanceRange(): Array\<number\>

获取手动白平衡的调节范围。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 用于获取手动白平衡值可调范围，如[2800,...,10000]，单位为K(Kelvin，温度单位)，实际情况根据底层能力返回为准。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalanceRange(professionalPhotoSession: camera.ProfessionalPhotoSession): Array<number> {
  let range: Array<number> = [];
  try {
    range = professionalPhotoSession.getWhiteBalanceRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getWhiteBalanceRange call failed. error code: ${err.code}`);
  }
  return range;
}
```

## WhiteBalance<sup>12+</sup>

WhiteBalance extends [WhiteBalanceQuery](#whitebalancequery12)

提供了处理设备白平衡的相关功能，包括获取和设置白平衡模式和白平衡值。

### setWhiteBalanceMode<sup>12+</sup>

setWhiteBalanceMode(mode: WhiteBalanceMode): void

设置白平衡模式。进行设置之前，需要先检查设备是否支持指定的白平衡模式，可使用方法[isWhiteBalanceModeSupported](#iswhitebalancemodesupported12)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| mode   | [WhiteBalanceMode](#whitebalancemode12)  | 是   | 白平衡模式。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setWhiteBalanceMode(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    professionalPhotoSession.setWhiteBalanceMode(camera.WhiteBalanceMode.DAYLIGHT);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setWhiteBalanceMode call failed. error code: ${err.code}`);
  }
}
```

### getWhiteBalanceMode<sup>12+</sup>

getWhiteBalanceMode(): WhiteBalanceMode

获取当前白平衡模式。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [WhiteBalanceMode](#whitebalancemode12)    | 获取当前白平衡模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalanceMode(professionalPhotoSession: camera.ProfessionalPhotoSession): camera.WhiteBalanceMode | undefined {
  let whiteBalanceMode: camera.WhiteBalanceMode | undefined = undefined;
  try {
    whiteBalanceMode = professionalPhotoSession.getWhiteBalanceMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getWhiteBalanceMode call failed. error code: ${err.code}`);
  }
  return whiteBalanceMode;
}
```

### setWhiteBalance<sup>12+</sup>
setWhiteBalance(whiteBalance: number): void

设置手动白平衡值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| whiteBalance | number | 是   | 设置手动白平衡值 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setWhiteBalance(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  try {
    let whiteBalance: number = 1000;
    professionalPhotoSession.setWhiteBalance(whiteBalance);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setWhiteBalance call failed. error code: ${err.code}`);
  }
}
```

### getWhiteBalance<sup>12+</sup>

getWhiteBalance(): number

获取当前手动白平衡的值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 返回当前白平衡值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getWhiteBalance(professionalPhotoSession: camera.ProfessionalPhotoSession): number {
  let whiteBalance: number = 0;
  try {
    whiteBalance = professionalPhotoSession.getWhiteBalance();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getWhiteBalance call failed. error code: ${err.code}`);
  }
  return whiteBalance;
}
```

## ProfessionalPhotoSession<sup>12+</sup>

ProfessionalPhotoSession extends Session, AutoExposure, ManualExposure, Focus, ManualFocus, WhiteBalance, ManualIso, Flash, Zoom, ColorEffect, Aperture

专业拍照会话类，继承自[Session](js-apis-camera.md#session12)，用于设置专业拍照会话的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听专业拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Professional photo session error code: ${err.code}`);
}

function registerSessionError(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听专业拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匿名函数。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSessionError(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterFocusStateChange(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，可选，有就是匹配on('smoothZoomInfoAvailable') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSmoothZoomInfo(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('smoothZoomInfoAvailable');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<IsoInfo\>): void

监听自动ISO变化事件，通过注册回调函数获取实时ISO信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 是   | 回调函数，用于获取ISO信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<IsoInfo\>): void

注销监听ISO信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 否   | 回调函数，可选，用于匹配on('isoInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterIsoInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<ExposureInfo\>): void

监听曝光信息事件，通过注册回调函数获取曝光信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 是   | 回调函数，用于获取曝光信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<ExposureInfo\>): void

注销监听曝光信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 否   | 回调函数，可选，用于匹配on('exposureInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterExposureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('exposureInfoChange');
}
```

### on('apertureInfoChange')<sup>12+</sup>

on(type: 'apertureInfoChange', callback: AsyncCallback\<ApertureInfo\>): void

监听物理光圈变化事件，通过注册回调函数获取实时物理光圈信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'apertureInfoChange'。         |
| callback | AsyncCallback\<[ApertureInfo](#apertureinfo12)\>| 是   | 回调函数，用于获取物理光圈信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function apertureInfoCallback(err: BusinessError, info: camera.ApertureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Aperture value: ${info.aperture}`);
}

function registerApertureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('apertureInfoChange', apertureInfoCallback);
}
```

### off('apertureInfoChange')<sup>12+</sup>

off(type: 'apertureInfoChange', callback?: AsyncCallback\<ApertureInfo\>): void

注销监听物理光圈变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'apertureInfoChange'。         |
| callback | AsyncCallback\<[ApertureInfo](#apertureinfo12)\>| 否   | 回调函数，可选，用于匹配on('apertureInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterApertureInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('apertureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<LuminationInfo\>): void

监听光照变化事件，通过注册回调函数获取实时光照参数。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 是   | 回调函数，用于获取光照参数。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<LuminationInfo\>): void

注销监听光照变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 否   | 回调函数，可选，用于匹配on('luminationInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterLuminationInfoEvent(professionalPhotoSession: camera.ProfessionalPhotoSession): void {
  professionalPhotoSession.off('luminationInfoChange');
}
```

## ProfessionalVideoSession<sup>12+</sup>

ProfessionalVideoSession extends Session, AutoExposure, ManualExposure, Focus, ManualFocus, WhiteBalance, ManualIso, Flash, Zoom, ColorEffect, Aperture

专业录像模式会话类，继承自[Session](js-apis-camera.md#session12)，用于设置专业录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听专业录像会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Professional video session error code: ${err.code}`);
}

function registerSessionError(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听专业录像会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匿名函数。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSessionError(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterFocusStateChange(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，可选，有就是匹配on('smoothZoomInfoAvailable') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSmoothZoomInfo(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('smoothZoomInfoAvailable');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<IsoInfo\>): void

监听自动ISO变化事件，通过注册回调函数获取实时ISO信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 是   | 回调函数，用于获取ISO信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<IsoInfo\>): void

注销监听ISO信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 否   | 回调函数，可选，用于匹配on('isoInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterIsoInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<ExposureInfo\>): void

监听曝光信息事件，通过注册回调函数获取曝光信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 是   | 回调函数，用于获取曝光信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<ExposureInfo\>): void

注销监听曝光信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 否   | 回调函数，可选，用于匹配on('exposureInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterExposureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('exposureInfoChange');
}
```

### on('apertureInfoChange')<sup>12+</sup>

on(type: 'apertureInfoChange', callback: AsyncCallback\<ApertureInfo\>): void

监听物理光圈变化事件，通过注册回调函数获取物理光圈信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'apertureInfoChange'。         |
| callback | AsyncCallback\<[ApertureInfo](#apertureinfo12)\>| 是   | 回调函数，用于获取物理光圈信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function apertureInfoCallback(err: BusinessError, info: camera.ApertureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Aperture value: ${info.aperture}`);
}

function registerApertureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('apertureInfoChange', apertureInfoCallback);
}
```

### off('apertureInfoChange')<sup>12+</sup>

off(type: 'apertureInfoChange', callback?: AsyncCallback\<ApertureInfo\>): void

注销监听物理光圈变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'apertureInfoChange'。         |
| callback | AsyncCallback\<[ApertureInfo](#apertureinfo12)\>| 否   | 回调函数，可选，用于匹配on('apertureInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterApertureInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('apertureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<LuminationInfo\>): void

监听光照变化事件，通过注册回调函数获取光照参数。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 是   | 回调函数，用于获取光照参数。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<LuminationInfo\>): void

注销监听光照变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 否   | 回调函数，可选，用于匹配on('luminationInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterLuminationInfoEvent(professionalVideoSession: camera.ProfessionalVideoSession): void {
  professionalVideoSession.off('luminationInfoChange');
}
```

## MacroPhotoSession<sup>12+</sup>

MacroPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ManualFocus

微距拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置微距拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听微距拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填  | 说明                                                                                                                                                                      |
|----------|---------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                                    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。                                                                                                           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`MacroPhotoSession error code: ${err.code}`);
}

function registerSessionError(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听微距拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填 | 说明                                                          |
|----------|---------------------------------------------------------------------------|----|-------------------------------------------------------------|
| type     | string                                                                    | 是  | 监听事件，固定为'error'，session创建成功之后可监听该接口。                        |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSessionError(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                                      |
|-----------|---------------------------------------------|----|-------------------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 是  | 回调函数，用于获取当前对焦状态。                                                        |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                           |
|-----------|---------------------------------------------|----|--------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。                   |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterFocusStateChange(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSmoothZoomInfo(macroPhotoSession: camera.MacroPhotoSession): void {
  macroPhotoSession.off('smoothZoomInfoAvailable');
}
```

## MacroVideoSession<sup>12+</sup>

MacroVideoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ManualFocus

微距录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置微距录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听微距录像会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填  | 说明                                                                                                                                                                      |
|----------|---------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                                    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。                                                                                                           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`MacroPhotoSession error code: ${err.code}`);
}

function registerSessionError(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听微距录像会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填 | 说明                                                          |
|----------|---------------------------------------------------------------------------|----|-------------------------------------------------------------|
| type     | string                                                                    | 是  | 监听事件，固定为'error'，session创建成功之后可监听该接口。                        |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSessionError(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                                      |
|-----------|---------------------------------------------|----|-------------------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 是  | 回调函数，用于获取当前对焦状态。                                                        |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                           |
|-----------|---------------------------------------------|----|--------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。                   |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterFocusStateChange(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSmoothZoomInfo(macroVideoSession: camera.MacroVideoSession): void {
  macroVideoSession.off('smoothZoomInfoAvailable');
}
```

## FlashQuery<sup>12+</sup>

此接口提供了查阅设备闪光灯信息相应的方法，包括是否支持lcd闪光灯。

### isLcdFlashSupported<sup>12+</sup>

isLcdFlashSupported(): boolean

查询是否支持lcd闪光灯。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 查询是否支持lcd闪光灯。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400103                |  Session not config, only throw in session usage. |

**示例：**

```ts
function isLcdFlashSupported(nightPhotoSession: camera.NightPhotoSession): boolean {
  return nightPhotoSession.isLcdFlashSupported();
}
```

## Flash<sup>11+</sup>

Flash extends [FlashQuery](js-apis-camera.md#flashquery12)

闪光灯类，对设备闪光灯操作。

### enableLcdFlash<sup>13+</sup>

enableLcdFlash(enabled: boolean): void

使能或去使能LCD闪光灯。

进行设置之前，需要先检查：设备是否支持LCD闪光灯，可使用方法[isLcdFlashSupported](#islcdflashsupported12)。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                                               |
| --------- | ----------------------- | ---- |--------------------------------------------------|
| enabled | boolean | 是   | 使能或去使能LCD闪光灯。传参为null或者undefined，作为0处理，去使能LCD闪光灯。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function enableLcdFlash(session: camera.PhotoSessionForSys | camera.VideoSessionForSys | camera.NightPhotoSession): void {
  try {
    session.enableLcdFlash(true);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

## TimeLapseRecordState<sup>12+</sup>

枚举，延时摄影录制状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| IDLE          | 0    | 未录制 |
| RECORDING     | 1    | 录制中 |

## TimeLapsePreviewType<sup>12+</sup>

枚举，延时摄影预览类型，影响拍摄算法。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                           | 值   | 说明         |
| ----------------------------- | ---- | ----------- |
| DARK         | 1    | 暗光环境，指光照较差的场景，比如夜晚或暗处。 |
| LIGHT        | 2    | 亮光环境，指光照较好的场景，比如白天或灯光下。 |

## TryAEInfo<sup>12+</sup>

TryAE参数信息，TryAE是指延时摄影时硬件会根据环境光照变化上报状态的操作。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称 | 类型    | 只读 | 可选 | 说明           |
| ---- | ------- | ---- |--| -------------- |
| isTryAEDone        | boolean  | 是   | 否 | TryAE是否完成。        |
| isTryAEHintNeeded  | boolean  | 是   | 是 | 是否需要TryAE。        |
| previewType        | [TimeLapsePreviewType](#timelapsepreviewtype12) | 是   | 是 | 预览类型。        |
| captureInterval    | number   | 是   | 是 | 拍摄间隔，单位毫秒（ms）。        |

## TimeLapsePhotoSession<sup>12+</sup>

TimeLapsePhotoSession extends Session, Focus, ManualFocus, AutoExposure, ManualExposure, ManualIso, WhiteBalance, Zoom, ColorEffect

延时摄影会话类，继承自[Session](js-apis-camera.md#session12)，用于设置延时摄影会话的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听延时摄影会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Time lapse photo session error code: ${err.code}`);
}

function registerSessionError(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听延时摄影会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                        | 必填 | 说明                           |
| -------- | ------------------------ | ---- | ------------------------------ |
| type     | string    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，可选，有就是匿名函数。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterSessionError(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 否   | 回调函数，可选，有就是匹配on('focusStateChange') callback（callback对象不可是匿名函数）。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 202     |  Not System Application. |

**示例：**

```ts
function unregisterFocusStateChange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('focusStateChange');
}
```

### on('isoInfoChange')<sup>12+</sup>

on(type: 'isoInfoChange', callback: AsyncCallback\<IsoInfo\>): void

监听自动ISO变化事件，通过注册回调函数获取实时ISO信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 是   | 回调函数，用于获取ISO信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isoInfoCallback(err: BusinessError, info: camera.IsoInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`ISO value: ${info.iso}`);
}

function registerIsoInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('isoInfoChange', isoInfoCallback);
}
```

### off('isoInfoChange')<sup>12+</sup>

off(type: 'isoInfoChange', callback?: AsyncCallback\<IsoInfo\>): void

注销监听ISO信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'isoInfoChange'。         |
| callback | AsyncCallback\<[IsoInfo](#isoinfo12)\>| 否   | 回调函数，可选，用于匹配on('isoInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                    |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterIsoInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('isoInfoChange');
}
```

### on('exposureInfoChange')<sup>12+</sup>

on(type: 'exposureInfoChange', callback: AsyncCallback\<ExposureInfo\>): void

监听曝光信息事件，通过注册回调函数获取曝光信息。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 是   | 回调函数，用于获取曝光信息。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function exposureInfoCallback(err: BusinessError, info: camera.ExposureInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`exposureTimeValue: ${info.exposureTime}`);
}

function registerExposureInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('exposureInfoChange', exposureInfoCallback);
}
```

### off('exposureInfoChange')<sup>12+</sup>

off(type: 'exposureInfoChange', callback?: AsyncCallback\<ExposureInfo\>): void

注销监听曝光信息事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'exposureInfoChange'。         |
| callback | AsyncCallback\<[ExposureInfo](#exposureinfo12)\>| 否   | 回调函数，可选，用于匹配on('exposureInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterExposureInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('exposureInfoChange');
}
```

### on('luminationInfoChange')<sup>12+</sup>

on(type: 'luminationInfoChange', callback: AsyncCallback\<LuminationInfo\>): void

监听光照变化事件，通过注册回调函数获取实时光照参数。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 是   | 回调函数，用于获取光照参数。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function luminationInfoCallback(err: BusinessError, info: camera.LuminationInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`Lumination: ${info.lumination}`);
}

function registerLuminationInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('luminationInfoChange', luminationInfoCallback);
}
```

### off('luminationInfoChange')<sup>12+</sup>

off(type: 'luminationInfoChange', callback?: AsyncCallback\<LuminationInfo\>): void

注销监听光照变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'luminationInfoChange'。         |
| callback | AsyncCallback\<[LuminationInfo](#luminationinfo12)\>| 否   | 回调函数，可选，用于匹配on('luminationInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterLuminationInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('luminationInfoChange');
}
```

### on('tryAEInfoChange')<sup>12+</sup>

on(type: 'tryAEInfoChange', callback: AsyncCallback\<TryAEInfo\>): void

监听TryAE变化事件，通过注册回调函数获取实时TryAE参数。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'tryAEInfoChange'。         |
| callback | AsyncCallback\<[TryAEInfo](#tryaeinfo12)\>| 是   | 回调函数，用于获取TryAE参数。         |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function tryAEInfoCallback(err: BusinessError, info: camera.TryAEInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.log(`TryAEInfo: ${info.isTryAEDone}, ${info.isTryAEHintNeeded}, ${info.previewType}, ${info.captureInterval}`);
}

function registerTryAEInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.on('tryAEInfoChange', tryAEInfoCallback);
}
```

### off('tryAEInfoChange')<sup>12+</sup>

off(type: 'tryAEInfoChange', callback?: AsyncCallback\<TryAEInfo\>): void

注销监听TryAE变化事件，通过注册回调函数来注销。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                      | 必填 | 说明                               |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------- |
| type     | string                                                  | 是   | 监听事件，固定为'tryAEInfoChange'。         |
| callback | AsyncCallback\<[TryAEInfo](#tryaeinfo12)\>| 否   | 回调函数，可选，用于匹配on('tryAEInfoChange')的callback。 |

**错误码：**

| 错误码ID | 错误信息                     |
| ------- | ---------------------- |
| 202     | Not System Application. |

**示例：**

```ts
function unregisterTryAEInfoEvent(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  timeLapsePhotoSession.off('tryAEInfoChange');
}
```

### isTryAENeeded<sup>12+</sup>

isTryAENeeded(): boolean

判断是否需要执行TryAE。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean   | 是否需要执行TryAE，接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 |  Session not config.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isTryAENeeded(timeLapsePhotoSession: camera.TimeLapsePhotoSession): boolean {
  let needed = false;
  try {
    needed = timeLapsePhotoSession.isTryAENeeded();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isTryAENeeded call failed. error code: ${err.code}`);
  }
  return needed;
}
```

### startTryAE<sup>12+</sup>

startTryAE(): void

开始执行TryAE。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 | Session not config.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function startTryAE(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.startTryAE();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The startTryAE call failed. error code: ${err.code}`);
  }
}
```

### stopTryAE<sup>12+</sup>

stopTryAE(): void

停止执行TryAE。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103 | Session not config.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopTryAE(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.stopTryAE();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The stopTryAE call failed. error code: ${err.code}`);
  }
}
```

### getSupportedTimeLapseIntervalRange<sup>12+</sup>

getSupportedTimeLapseIntervalRange(): Array\<number\>

获取支持的拍摄间隔范围。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 用于获取拍摄间隔范围，单位毫秒（ms），根据底层能力返回为准，接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedTimeLapseIntervalRange(timeLapsePhotoSession: camera.TimeLapsePhotoSession): Array<number> {
  let intervalRange: Array<number> = [];
  try {
    intervalRange = timeLapsePhotoSession.getSupportedTimeLapseIntervalRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getSupportedTimeLapseIntervalRange call failed. error code: ${err.code}`);
  }
  return intervalRange;
}
```

### getTimeLapseInterval<sup>12+</sup>

getTimeLapseInterval(): number

获取当前的拍摄间隔值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 返回当前拍摄间隔值，单位毫秒（ms）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapseInterval(timeLapsePhotoSession: camera.TimeLapsePhotoSession): number {
  let interval: number = 0;
  try {
    interval = timeLapsePhotoSession.getTimeLapseInterval();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getTimeLapseInterval call failed. error code: ${err.code}`);
  }
  return interval;
}
```

### setTimeLapseInterval<sup>12+</sup>
setTimeLapseInterval(interval: number): void

设置拍摄间隔值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| interval | number | 是   | 设置拍摄间隔值，单位毫秒（ms）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapseInterval(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    let interval: number = 10000;
    timeLapsePhotoSession.setTimeLapseInterval(interval);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setTimeLapseInterval call failed. error code: ${err.code}`);
  }
}
```

### getTimeLapseRecordState<sup>12+</sup>

getTimeLapseRecordState(): TimeLapseRecordState

获取当前拍摄状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [TimeLapseRecordState](#timelapserecordstate12)    | 获取当前拍摄状态。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapseRecordState(timeLapsePhotoSession: camera.TimeLapsePhotoSession): camera.TimeLapseRecordState {
  let state = camera.TimeLapseRecordState.IDLE;
  try {
    state = timeLapsePhotoSession.getTimeLapseRecordState();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getTimeLapseRecordState call failed. error code: ${err.code}`);
  }
  return state;
}
```

### setTimeLapseRecordState<sup>12+</sup>

setTimeLapseRecordState(state: TimeLapseRecordState): void

设置当前拍摄状态。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| state   | [TimeLapseRecordState](#timelapserecordstate12)  | 是   | 拍摄状态。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapseRecordState(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.setTimeLapseRecordState(camera.TimeLapseRecordState.RECORDING);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setTimeLapseRecordState call failed. error code: ${err.code}`);
  }
}
```

### getTimeLapsePreviewType<sup>12+</sup>

getTimeLapsePreviewType(): TimeLapsePreviewType

获取当前预览类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [TimeLapsePreviewType](#timelapsepreviewtype12)    | 获取当前预览类型。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getTimeLapsePreviewType(timeLapsePhotoSession: camera.TimeLapsePhotoSession): camera.TimeLapsePreviewType {
  let type = camera.TimeLapsePreviewType.DARK;
  try {
    type = timeLapsePhotoSession.getTimeLapsePreviewType();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getTimeLapsePreviewType call failed. error code: ${err.code}`);
  }
  return type;
}
```

### setTimeLapsePreviewType<sup>12+</sup>

setTimeLapsePreviewType(type: TimeLapsePreviewType): void

设置当前预览类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| state   | [TimeLapsePreviewType](#timelapsepreviewtype12)  | 是   | 预览类型。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202     | Not System Application. |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setTimeLapsePreviewType(timeLapsePhotoSession: camera.TimeLapsePhotoSession): void {
  try {
    timeLapsePhotoSession.setTimeLapsePreviewType(camera.TimeLapsePreviewType.LIGHT);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setTimeLapsePreviewType call failed. error code: ${err.code}`);
  }
}
```

## LightPaintingPhotoSession<sup>12+</sup>

LightPaintingPhotoSession extends Session, Flash, Focus, Zoom, ColorEffect

流光快门拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置流光快门拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听流光快门拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填  | 说明                                                                                                                                                                      |
|----------|---------------------------------------------------------------------------|-----|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| type     | string                                                                    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。                                                                                                           |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`LightPaintingPhotoSession error code: ${err.code}`);
}

function registerSessionError(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听流光快门拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                                                        | 必填 | 说明                                                          |
|----------|---------------------------------------------------------------------------|----|-------------------------------------------------------------|
| type     | string                                                                    | 是  | 监听事件，固定为'error'，session创建成功之后可监听该接口。                        |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSessionError(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.off('error');
}
```

### on('focusStateChange')<sup>12+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机对焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                                      |
|-----------|---------------------------------------------|----|-------------------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 是  | 回调函数，用于获取当前对焦状态。                                                        |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机对焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                                          | 必填 | 说明                                                           |
|-----------|---------------------------------------------|----|--------------------------------------------------------------|
| type      | string                                      | 是  | 监听事件，固定为'focusStateChange'，session创建成功可监听。                   |
| callback  | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\>  | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterFocusStateChange(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.off('focusStateChange');
}
```

### on('smoothZoomInfoAvailable')<sup>12+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`The duration of smooth zoom: ${smoothZoomInfo.duration}`);
}

function registerSmoothZoomInfo(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.on('smoothZoomInfoAvailable', callback);
}
```

### off('smoothZoomInfoAvailable')<sup>12+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                       |
|-------|----------------------------|
| 202   | Not System Application.    |

**示例：**

```ts
function unregisterSmoothZoomInfo(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  lightPaintingPhotoSession.off('smoothZoomInfoAvailable');
}
```

### getLightPaintingType<sup>12+</sup>

getLightPaintingType(): LightPaintingType

获取当前生效的流光快门模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**
| 类型                                             | 说明                    |
|------------------------------------------------- | --------------------- |
| [LightPaintingType](#lightpaintingtype12) | 流光快门模式类型。  |

**错误码：**
 
以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                               |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getLightPaintingType(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): camera.LightPaintingType {
  let type: camera.LightPaintingType = lightPaintingPhotoSession.getLightPaintingType();
  return type;
}
```

### setLightPaintingType<sup>12+</sup>

setLightPaintingType(type: LightPaintingType): void

设置当前生效的流光快门模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**
| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| type | [LightPaintingType](#lightpaintingtype12) | 是   | 设置流光快门模式的类型。 |

**错误码：**
 
以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                               |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setLightPaintingType(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): void {
  try {
    let type: camera.LightPaintingType = camera.LightPaintingType.TRAFFIC_TRAILS;
    lightPaintingPhotoSession.setLightPaintingType(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setLightPaintingType call failed. error code: ${err.code}`);
  }
}
```

### getSupportedLightPaintingTypes<sup>12+</sup>

getSupportedLightPaintingTypes(): Array\<LightPaintingType\>

获取当前支持的流光快门模式类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**
| 类型                                             | 说明                    |
|------------------------------------------------- | --------------------- |
| Array\<[LightPaintingType](#lightpaintingtype12)\> | 支持的流光快门模式类型。  |

**错误码：**
 
以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202                    |  Not System Application.                               |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
function getSupportedLightPaintingTypes(lightPaintingPhotoSession: camera.LightPaintingPhotoSession): Array<camera.LightPaintingType> {
  let types: Array<camera.LightPaintingType> = lightPaintingPhotoSession.getSupportedLightPaintingTypes();
  return types
}
```

## ColorReservationType<sup>15+</sup>

枚举，色彩保留类型。

**系统能力**： SystemCapability.Multimedia.Camera.Core

| 名称     | 值   | 说明             |
| -------- | ---- | ---------------- |
| NONE     | 0    | 无色彩保留效果。 |
| PORTRAIT | 1    | 人像留色。       |

## ColorReservationQuery<sup>15+</sup>

提供了查询设备支持的色彩保留类型的功能。

### getSupportedColorReservationTypes<sup>15+</sup>

getSupportedColorReservationTypes(): Array\<ColorReservationType\>

获取支持的色彩保留类型列表。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**返回值**：

| 类型                                                   | 说明                     |
| ------------------------------------------------------ | ------------------------ |
| Array<[ColorReservationType](#colorreservationtype15)> | 支持的色彩保留类型列表。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |
| 7400103  | Session not config.     |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getSupportedColorReservationTypes(session: camera.VideoSessionForSys): Array<camera.ColorReservationType> {
  let colorReservationTypes: Array<camera.ColorReservationType> = [];
  try {
    colorReservationTypes = session.getSupportedColorReservationTypes();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getSupportedColorReservationTypes call failed. error code: ${err.code}`);
  }
  return colorReservationTypes;
}
```

## ColorReservation<sup>15+</sup>

ColorReservation extends [ColorReservationQuery](#colorreservationquery15)

提供了获取和设置相机色彩保留类型的方法。

### setColorReservation<sup>15+</sup>

setColorReservation(type: ColorReservationType): void

设置色彩保留类型。可以先通过[getSupportedColorReservationTypes](#getsupportedcolorreservationtypes15)获取当前设备所支持的ColorReservationType。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**参数**：

| 参数名 | 类型                                            | 必填 | 说明                                                         |
| ------ | ----------------------------------------------- | ---- | ------------------------------------------------------------ |
| type   | [ColorReservationType](#colorreservationtype15) | 是   | 色彩保留类型，通过[getSupportedColorReservationTypes](#getsupportedcolorreservationtypes15)接口获取。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Not System Application.                                      |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3.Parameter verification failed. |
| 7400102  | Operation not allowed.                                       |
| 7400103  | Session not config.                                          |
| 7400201  | Camera service fatal error.                                  |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setColorReservation(session: camera.VideoSessionForSys, type: camera.ColorReservationType): void {
  try {
    session.setColorReservation(type);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setColorReservation call failed. error code: ${err.code}`);
  }
}
```

### getColorReservation<sup>15+</sup>

getColorReservation(): ColorReservationType

获取当前设置的色彩保留类型。

**系统接口**： 此接口为系统接口。

**系统能力**： SystemCapability.Multimedia.Camera.Core

**返回值**：

| 类型                                            | 说明                     |
| ----------------------------------------------- | ------------------------ |
| [ColorReservationType](#colorreservationtype15) | 当前设置的色彩保留类型。 |

**错误码**：

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 202      | Not System Application. |
| 7400103  | Session not config.     |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getColorReservation(session: camera.VideoSessionForSys): camera.ColorReservationType | undefined {
  let colorReservation: camera.ColorReservationType | undefined = undefined;
  try {
    colorReservation = session.getColorReservation();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setColorReservation call failed. error code: ${err.code}`);
  }
  return colorReservation;
}
```
