# @ohos.multimedia.camera (相机管理)(系统接口)

本模块为开发者提供一套简单且易于理解的相机服务接口，开发者通过调用接口可以开发相机应用。应用通过访问和操作相机硬件，实现基础操作，如预览、拍照和录像；还可以通过接口组合完成更多操作，如控制闪光灯和曝光时间、对焦或调焦等。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.multimedia.camera (相机管理)](js-apis-camera.md)。

## 导入模块

```ts
import camera from '@ohos.multimedia.camera';
```

## CameraDevice

相机设备信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称           | 类型                               | 只读 | 必填 | 说明        |
| -------------- | --------------------------------- | ---- | ---- |---------- |
| hostDeviceName | string                            | 是   | 是   | 远端设备名称。**系统接口：** 此接口为系统接口。 |
| hostDeviceType | [HostDeviceType](#hostdevicetype) | 是   | 是   | 远端相机设备类型。**系统接口：** 此接口为系统接口。 |

## HostDeviceType

枚举，远端相机设备类型。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                          | 值       | 说明           |
| ---------------------------- | ----     | ------------- |
| UNKNOWN_TYPE                 | 0        | 未知设备类型。      |
| PHONE                        | 0x0E     | 手机相机。 |
| TABLET                       | 0x11     | 平板相机。 |

## SceneMode<sup>11+</sup>

枚举，相机支持模式。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| PORTRAIT_PHOTO       | 3      | 人像拍照模式。**系统接口：** 此接口为系统接口。            |
| NIGHT_PHOTO        | 4      | 夜景拍照模式。**系统接口：** 此接口为系统接口。             |
| SLOW_MOTION_VIDEO<sup>12+</sup>        | 7   | 慢动作模式。**系统接口：** 此接口为系统接口。  |
| MACRO_PHOTO<sup>12+</sup>        | 8      | 超级微距拍照模式。**系统接口：** 此接口为系统接口。             |
| MACRO_VIDEO<sup>12+</sup>        | 9      | 超级微距录像模式。**系统接口：** 此接口为系统接口。             |

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


## CameraManager

相机管理器类，使用前需要通过[getCameraManager](js-apis-camera.md#cameragetcameramanager)获取相机管理实例。

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

function callback(err: BusinessError, curMuted: boolean): void {
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
import { BusinessError } from '@ohos.base';

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

| 参数名     | 类型             | 必填 | 说明       |
| -------- | --------------- | ---- | --------- |
| camera | [CameraDevice](#cameradevice) | 是 | 相机信息。|

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed. |
| 7400201 | Camera service fatal error. |

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
| cameraId | string | 是 | 相机id。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202 | Not System Application. |
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400201 | Camera service fatal error. |

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

## PrelaunchConfig

相机预启动配置参数。

当前sensor级别预热，待扩展流预热参数。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

|            名称                 |                     类型                  |     只读    |     必填     | 说明       |
| ------------------------------- | ---------------------------------------- | ----------- | ------------ | ---------- |
| cameraDevice                    | [CameraDevice](#cameradevice)            |      否     |       是      | 相机信息。         |
| restoreParamType<sup>11+</sup>  | [RestoreParamType](#restoreparamtype11)  |      否     |       否      | 预保存参数类型。    |
| activeTime<sup>11+</sup>        | number                                   |      否     |       否      | 激活时间，单位min。 |
| settingParam<sup>11+</sup>      |  [SettingParam](#settingparam11)         |      否     |       否      | 设置参数内容。      |

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

| 名称             | 类型   |   只读    |    必填    | 说明       |
| --------------- | ------ | --------- | ---------- | ---------- |
| skinSmoothLevel | number |  否       |  N/A       | 美颜类型光滑信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的光滑范围，例如1表示1级光滑。 |
| faceSlender     | number |  否       |  N/A       | 美颜类型瘦脸信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的瘦脸范围，例如1表示1级瘦脸。 |
| skinTone        | number |  否       |  N/A       | 美颜类型肤色信息，从[Beauty.getSupportedBeautyRange](#getsupportedbeautyrange11)获取支持的肤色范围，例如0xBF986C表示一个颜色。 |

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
import common from '@ohos.app.ability.common';

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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |

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

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| enabled | boolean | 是 | true表明开启画中画流进行预览。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400102         |  Operation not allowed.                   |
| 7400103         |  Session not config.                      |
| 7400201         |  Camera service fatal error.              |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function enableSketch(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
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
| surfaceId | string | 是 | 从[XComponent](../apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)组件获取的surfaceId。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400101         |  Parameter missing or parameter type incorrect.                      |
| 7400103         |  Session not config.                      |
| 7400201         |  Camera service fatal error.                      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function attachSketchSurface(previewOutput: camera.PreviewOutput, session: camera.Session, cameraInput: camera.CameraInput, sketchSurfaceId: string): void {
  try {
    session.beginConfig();
    session.addInput(cameraInput);
    session.addOutput(previewOutput);
    previewOutput.enableSketch(true);
    session.commitConfig();
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
| callback | AsyncCallback\<[SketchStatusData](#sketchstatusdata11)\> | 是   | 使用callback的方式获取SketchStatusData。            |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(error: BusinessError, data: camera.SketchStatusData): void {
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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

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
import image from '@ohos.multimedia.image';

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

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 使用Promise的方式获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

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

### confirmCapture<sup>11+</sup>

confirmCapture()

确认拍照，一般用于夜景模式下，在曝光倒计时过程中如需终止倒计时提前拍照的时候调用。

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

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

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

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

function callback(err: BusinessError, proxyObj: camera.DeferredPhotoProxy): void {
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
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

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
import common from '@ohos.app.ability.common';

async function isQuickThumbnailSupported(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<boolean> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话
  session.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把photoOutput加入到会话
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
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

async function enableQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话
  session.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把PhotoOutPut加入到会话
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

监听快速缩略图输出事件。

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
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';
import image from '@ohos.multimedia.image';

function callback(err: BusinessError, pixelMap: image.PixelMap): void {
  if (err || pixelMap === undefined) {
      console.error('photoOutput on thumbnail failed');
      return;
  }
  // 显示或保存pixelMap
  // do something
}

async function registerQuickThumbnail(context: common.BaseContext, mode: camera.SceneMode, photoProfile: camera.Profile): Promise<void> {
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let cameras: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  // 创建CaptureSession实例
  let session: camera.Session = cameraManager.createSession(mode);
  // 开始配置会话
  session.beginConfig();
  // 把CameraInput加入到会话
  let cameraInput: camera.CameraInput = cameraManager.createCameraInput(cameras[0]);
  await cameraInput.open();
  session.addInput(cameraInput);
  // 把PhotoOutPut加入到会话
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

## ManualExposure<sup>11+</sup>

手动曝光类，用于设置手动曝光参数。

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

| 参数名      | 类型                    | 必填 | 说明                   |
| -------- | --------------------------| ---- | --------------------- |
| value    | number                    | 是   | 手动曝光时长，通过[getSupportedExposureRange](#getsupportedexposurerange11)接口获取。|

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

## Macro<sup>11+</sup>

微距能力。

### isMacroSupported<sup>11+</sup>

isMacroSupported(): boolean

检测当前状态下是否支持微距能力，需要在CaptureSession调用commitConfig之后进行调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
|   boolean  | 返回是否支持微距能力。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |

**示例：**

```ts
function isMacroSupported(photoSession: camera.PhotoSessionForSys): boolean {
  let isSupported: boolean = photoSession.isMacroSupported();
  return isSupported;
}
```

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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400102         |  Operation not allowed.                   |
| 7400103         |  Session not config.                      |

**示例：**

```ts
function enableMacro(photoSession: camera.PhotoSessionForSys): void {
  let isSupported: boolean = photoSession.isMacroSupported();
  if (isSupported) {
    photoSession.enableMacro(true);
  }
}
```

## SceneFeatureType<sup>12+</sup>

枚举，场景特性枚举。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称                     | 值        | 说明         |
| ----------------------- | --------- | ------------ |
| MOON_CAPTURE_BOOST       | 0      | 月亮场景。**系统接口：** 此接口为系统接口。            |

## SceneFeatureDetectionResult<sup>12+</sup>

场景检测结果信息。

**系统能力：** SystemCapability.Multimedia.Camera.Core

| 名称     | 类型        |   只读   |   必填   | 说明       |
| -------- | ---------- | -------- | -------- | ---------- |
| featureType |   [SceneFeatureType](#scenefeaturetype12)   |   是     |    是    | 特性类型。 |
| detected |   boolean   |   是     |    是    | 检测结果。true为检测到指定特性场景。 |

## SceneDetection<sup>12+</sup>

场景检测能力。

### isSceneFeatureSupported<sup>12+</sup>

isSceneFeatureSupported(featureType: camera.SceneFeatureType): boolean

查询是否支持指定特性。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| featureType | [SceneFeatureType](#scenefeaturetype12) | 是 | 指定对应的场景特性。|

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| boolean | 返回是否支持指定特性。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400101         |  Parameter missing or parameter type incorrect.                      |

**示例：**

```ts
function isSceneFeatureSupported(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): boolean {
  let isSupported: boolean = photoSession.isSceneFeatureSupported(featureType);
  return isSupported;
}
```

### enableSceneFeature<sup>12+</sup>

enableSceneFeature(featureType: camera.SceneFeatureType, enabled: boolean): void

使能指定特性，该接口应当在收到对应场景检测回调结果[SceneFeatureDetectionResult](#scenefeaturedetectionresult12)之后调用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| featureType | [SceneFeatureType](#scenefeaturetype12) | 是 | 指定需要开启或关闭的特性。|
| enabled | boolean | 是 | true表明开启指定特性，false表明关闭指定特性。|

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202             |  Not System Application.                  |
| 7400101         |  Parameter missing or parameter type incorrect.                      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function enableSceneFeature(photoSession: camera.PhotoSession): void {
  try {
    photoSession.beginConfig();
    photoSession.addInput(cameraInput);
    photoSession.addOutput(previewOutput);
    photoSession.commitConfig();

    photoSession.on('featureDetection', camera.SceneFeatureType.MOON_CAPTURE_BOOST,
      (err, statusObject) => {
        console.info(
          `on featureDetection featureType:${statusObject.featureType} detected:${statusObject.detected}`);
        if (statusObject.featureType === camera.SceneFeatureType.MOON_CAPTURE_BOOST) {
          try {
            photoSession.enableSceneFeature(statusObject.featureType, statusObject.detected);
          } catch (error) {
            return false;
          }
        }
      });

  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The enableSceneFeature call failed. error code: ${err.code}`);
  }
}
```

## Zoom<sup>11+</sup>

变焦类，对设备变焦操作。

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

| 名称     | 类型           | 只读 | 必填 | 说明         |
| -------- | ------------- |---- | ---- | -------------|
| min      | number        | 是  |  N/A  | 获取的可变焦距范围的最小值  |
| max      | number        | 是  |  N/A  | 获取的可变焦距范围的最大值。 |

## Beauty<sup>11+</sup>

美肤类，用于设置美肤参数。

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

### setBeauty<sup>11+</sup>

setBeauty(type: BeautyType, value: number): void

设置美颜类型以及对应的美颜强度。将通过[getSupportedBeautyTypes](#getsupportedbeautytypes11)获取得到的[BeautyType](#beautytype)都关闭，表明当前美颜关闭；若有一种美颜类型未关闭，表明当前美颜打开。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                   |
| -------- | --------------------------| ---- | --------------------- |
| type     | [BeautyType](#beautytype) | 是   | 美颜类型。              |
| value    | number                    | 是   | 美颜强度，通过[getSupportedBeautyRange](#getsupportedbeautyrange11)接口获取。|

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

## ColorEffect<sup>11+</sup>

色彩效果类，用于设置色彩效果类型。

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
import { BusinessError } from '@ohos.base';

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

| 名称       | 类型                       |  只读 |  必填 | 说明               |
| ---------- | ------------------------- | ----- | ----- | ----------------- |
| zoomRange  | [ZoomRange](#zoomrange11) | 否    | N/A   | 特定物理光圈的变焦范围。  |
| apertures  | Array\<number\>           | 否    | N/A   | 支持的物理光圈列表。      |

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

监听相机微距状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, macroStatus: boolean): void {
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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```

### on('featureDetection')<sup>12+</sup>

on(type: 'featureDetection', featureType: camera.SceneFeatureType, callback: AsyncCallback\<camera.SceneFeatureDetectionResult\>): void

监听相机特性检测状态变化。

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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, result: camera.SceneFeatureDetectionResult): void {
  console.info(`feature type: ${result.featureType}`);
  console.info(`feature status: ${result.detected}`);
}

function registerFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.on('featureDetection', featureType, callback);
}
```

### off('featureDetection')<sup>12+</sup>

off(type: 'featureDetection', featureType: camera.SceneFeatureType, callback?: AsyncCallback\<camera.SceneFeatureDetectionResult\>): void

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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
function unregisterFeatureDetectionStatus(photoSession: camera.PhotoSession, featureType: camera.SceneFeatureType): void {
  photoSession.off('featureDetection', featureType);
}
```

## VideoSessionForSys<sup>11+</sup>

VideoSessionForSys extends VideoSession, Beauty, ColorEffect, ColorManagement, Macro

提供给系统应用的VideoSession，普通录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

## VideoSession<sup>11+</sup>

VideoSession extends Session, Flash, AutoExposure, Focus, Zoom, Stabilization, ColorManagement

普通录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置普通录像模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('macroStatusChanged')<sup>11+</sup>

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, macroStatus: boolean): void {
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

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 202         	  |  Not System Application.       |

**示例：**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```

## PortraitPhotoSession<sup>11+</sup>

PortraitPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, Beauty, ColorEffect, ColorManagement, Portrait, Aperture

人像拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置人像拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听人像拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型        | 必填 | 说明                           |
| -------- | --------------------------------- | ---- | ------------------------------ |
| type     | string                               | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(portraitPhotoSession: camera.PortraitPhotoSession): void {
  portraitPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

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

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
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

## NightPhotoSession<sup>11+</sup>

NightPhotoSession extends Session, Flash, AutoExposure, Focus, Zoom, ColorEffect, ColorManagement, ManualExposure

夜景拍照模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置夜景拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

### on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听夜景拍照会话的错误事件，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](js-apis-camera.md#beginconfig11)，[commitConfig](js-apis-camera.md#commitconfig11-1)，[addInput](js-apis-camera.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](js-apis-camera.md#cameraerrorcode)。 |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

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

监听相机聚焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](js-apis-camera.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(nightPhotoSession: camera.NightPhotoSession): void {
  nightPhotoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

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

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](js-apis-camera.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
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

慢动作录像模式会话类，继承自[Session](js-apis-camera.md#session11)，用于设置人像拍照模式的参数以及保存所需要的所有资源[CameraInput](js-apis-camera.md#camerainput)、[CameraOutput](js-apis-camera.md#cameraoutput)。

> **说明：**
> 慢动作模式下只能添加预览流和录像流。
### on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

监听人像拍照会话的错误事件，通过注册回调函数获取结果。

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
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError): void {
  console.error(`Portrait photo session error code: ${err.code}`);
}

function registerSessionError(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('error', callback);
}
```

### off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听人像拍照会话的错误事件，通过注册回调函数获取结果。

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

监听相机聚焦的状态变化，通过注册回调函数获取结果。

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
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, focusState: camera.FocusState): void {
  console.info(`Focus state: ${focusState}`);
}

function registerFocusStateChange(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  slowMotionVideoSession.on('focusStateChange', callback);
}
```

### off('focusStateChange')<sup>12+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

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

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。

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
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, smoothZoomInfo: camera.SmoothZoomInfo): void {
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

监听慢动作状态变化，通过注册回调函数获取结果。

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
import { BusinessError } from '@ohos.base';

function callback(err: BusinessError, slowMotionStatus: camera.SlowMotionStatus): void {
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

isSlowMotionDetectionSupported(): boolean;

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
import { BusinessError } from '@ohos.base';

function isSlowMotionDetectionSupported(slowMotionVideoSession: camera.SlowMotionVideoSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = slowMotionVideoSession.isSlowMotionDetectionSupported();
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

### setSlowMotionDetectionArea<sup>12+</sup>

setSlowMotionDetectionArea(area: Rect): void;

设置一个进行慢动作检测的区域。

> **说明：**
> 在调用该方法之前，先调用[isSlowMotionDetectionSupported](#isslowmotiondetectionsupported12)确认设备是否支持慢动作检测功能, 确认支持下并且调用[enableMotionDetection](#enablemotiondetection12)接口使能，才能保证其他相关方法的正常运行。 
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
import { BusinessError } from '@ohos.base';

function setSlowMotionDetectionArea(slowMotionVideoSession: camera.SlowMotionVideoSession): void {
  try {
    slowMotionVideoSession.setSlowMotionDetectionArea({topLeftX: 0.1, topLeftY: 0.1, width: 0.8, height: 0.8});
  } catch (error) {
    // 失败返回错误码error.code并处理
    let err = error as BusinessError;
    console.error(`The setSlowMotionDetectionArea call failed. error code: ${err.code}`);
  }
  return status;
}
```