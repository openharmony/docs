# Interface (VideoSession)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 11开始支持。

VideoSession 继承自 [Session](arkts-apis-camera-Session.md)、[Flash](arkts-apis-camera-Flash.md)、[AutoExposure](arkts-apis-camera-AutoExposure.md)、 [WhiteBalance](arkts-apis-camera-WhiteBalance.md)、[Focus](arkts-apis-camera-Focus.md)、[Zoom](arkts-apis-camera-Zoom.md)、[Stabilization](arkts-apis-camera-Stabilization.md)、[ColorManagement](arkts-apis-camera-ColorManagement.md)、[AutoDeviceSwitch](arkts-apis-camera-AutoDeviceSwitch.md)、[Macro](arkts-apis-camera-Macro.md)、[ControlCenter](arkts-apis-camera-ControlCenter.md)。

普通录像模式会话类，提供了对闪光灯、曝光、白平衡、对焦、变焦、视频防抖、色彩空间、微距及控制器的操作。

> **说明：**
>
> 默认的视频录制模式，适用于一般场景。支持720P、1080p等多种分辨率的录制，可选择不同帧率（如30fps、60fps）。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## canPreconfig<sup>12+</sup>

canPreconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): boolean

查询当前Session是否支持指定的与配置类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名            | 类型                                  | 必填  | 说明              |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](arkts-apis-camera-e.md#preconfigtype12)   | 是   | 指定配置预期分辨率。      |
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | 否   | 可选画幅比例，默认为16:9。 |

**返回值：**

| 类型      | 说明                                      |
|---------|-----------------------------------------|
| boolean | true: 支持指定预配值类型。<br/>false: 不支持指定预配值类型。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                        |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**示例：**

```ts
function testCanPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = videoSession.canPreconfig(preconfigType, preconfigRatio);
    console.info(`canPreconfig ${preconfigType} ${preconfigRatio} result is : ${result}`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The canPreconfig call failed. error code: ${err.code}`);
  }
}
```

## preconfig<sup>12+</sup>

preconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): void

对当前Session进行预配置。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名            | 类型                                  | 必填  | 说明              |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](arkts-apis-camera-e.md#preconfigtype12)   | 是   | 指定配置预期分辨率。      |
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | 否   | 可选画幅比例，默认为16:9。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                        |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**示例：**

```ts
function testPreconfig(videoSession: camera.VideoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    videoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig ${preconfigType} ${preconfigRatio} success`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

## on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听普通录像会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型              | 必填 | 说明                           |
| -------- | ------------------ | ---- | ------------------------------ |
| type     | string             | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](arkts-apis-camera-Session.md#beginconfig11)，[commitConfig](arkts-apis-camera-Session.md#commitconfig11)，[addInput](arkts-apis-camera-Session.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)      | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video session error code: ${err.code}`);
}

function registerSessionError(videoSession: camera.VideoSession): void {
  videoSession.on('error', callback);
}
```

## off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听普通录像会话的错误事件，通过注册回调函数获取结果。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                          | 必填 | 说明                           |
| -------- | --------------------------- | ---- | ------------------------------ |
| type     | string                    | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterSessionError(videoSession: camera.VideoSession): void {
  videoSession.off('error');
}
```

## on('focusStateChange')<sup>11+</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                       |
| -------- | ---------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。仅当自动对焦模式时，且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

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

function registerFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.on('focusStateChange', callback);
}
```

## off('focusStateChange')<sup>11+</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | 否  | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterFocusStateChange(videoSession: camera.VideoSession): void {
  videoSession.off('focusStateChange');
}
```

## on('smoothZoomInfoAvailable')<sup>11+</sup>

on(type: 'smoothZoomInfoAvailable', callback: AsyncCallback\<SmoothZoomInfo\>): void

监听相机平滑变焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                       |
| -------- | ----------------------- | ---- | ------------------------ |
| type     | string                  | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](arkts-apis-camera-i.md#smoothzoominfo11)\> | 是   | 回调函数，用于获取当前平滑变焦状态。  |

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

function registerSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.on('smoothZoomInfoAvailable', callback);
}
```

## off('smoothZoomInfoAvailable')<sup>11+</sup>

off(type: 'smoothZoomInfoAvailable', callback?: AsyncCallback\<SmoothZoomInfo\>): void

注销监听相机平滑变焦的状态变化。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string              | 是   | 监听事件，固定为'smoothZoomInfoAvailable'，session创建成功可监听。|
| callback | AsyncCallback\<[SmoothZoomInfo](arkts-apis-camera-i.md#smoothzoominfo11)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('smoothZoomInfoAvailable');
}
```

## on('autoDeviceSwitchStatusChange')<sup>13+</sup>

on(type: 'autoDeviceSwitchStatusChange', callback: AsyncCallback\<AutoDeviceSwitchStatus\>): void

监听相机自动切换镜头状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                                   | 必填 | 说明                       |
| -------- |----------------------------------------------------------------------| ---- | ------------------------ |
| type     | string                                                               | 是   | 监听事件，固定为'autoDeviceSwitchStatusChange'，session创建成功可监听。|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | 是   | 回调函数，用于获取当前自动切换镜头的状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
}

function registerAutoDeviceSwitchStatus(videoSession: camera.VideoSession): void {
  videoSession.on('autoDeviceSwitchStatusChange', callback);
}
```

## off('autoDeviceSwitchStatusChange')<sup>13+</sup>

off(type: 'autoDeviceSwitchStatusChange', callback?: AsyncCallback\<AutoDeviceSwitchStatus\>): void

注销监听相机自动切换镜头状态变化。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                           | 必填 | 说明                       |
| -------- |----------------------------------------------| ---- | ------------------------ |
| type     | string                                       | 是   | 监听事件，固定为'autoDeviceSwitchStatusChange'，session创建成功可监听。|
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterSmoothZoomInfo(videoSession: camera.VideoSession): void {
  videoSession.off('autoDeviceSwitchStatusChange');
}
```

## setQualityPrioritization<sup>14+</sup>

setQualityPrioritization(quality : QualityPrioritization) : void;

设置录像质量优先级。

> **说明：**
> 默认为高质量，设置为功耗平衡将降低录像质量以减少功耗。实际功耗收益因平台而异。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名  | 类型                                              | 必填 | 说明                                       |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------ |
| quality | [QualityPrioritization](arkts-apis-camera-e.md#qualityprioritization14) | 是   | 需要设置的视频质量优先级（默认为高质量）。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID | 错误信息                                                                                                                                        |
| -------- | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 7400103  | Session not config. The session has not been committed or configured.                                                                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setQualityPrioritization(videoSession: camera.VideoSession): void {
  try {
    videoSession.setQualityPrioritization(camera.QualityPrioritization.POWER_BALANCE);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setQualityPrioritization call failed. error code: ${err.code}`);
  }
}
```

## on('systemPressureLevelChange')<sup>20+</sup>

on(type: 'systemPressureLevelChange', callback: AsyncCallback\<SystemPressureLevel\>): void

监听系统压力状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名  | 类型                                                      | 必填 | 说明                                                              |
|---------|----------------------------------------------------------|------|-------------------------------------------------------------------|
|type     | string                                                   | 是   | 监听事件，固定为'systemPressureLevelChange'，session创建成功可监听。 |
|callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | 是 | 回调函数，用于获取当前系统压力状态。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, systemPressureLevel: camera.SystemPressureLevel): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`systemPressureLevel: ${systemPressureLevel}`);
}

function registerSystemPressureLevelChangeCallback(videoSession: camera.VideoSession): void {
    videoSession.on('systemPressureLevelChange', callback);
}
```

## off('systemPressureLevelChange')<sup>20+</sup>

off(type: 'systemPressureLevelChange', callback?: AsyncCallback\<SystemPressureLevel\>): void

注销监听系统压力状态变化。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                           | 必填    | 说明                                                             |
|----------|--------------------------------|---------|------------------------------------------------------------------|
| type     | string                         | 是      | 注销监听事件，固定为'systemPressureLevelChange'，session创建成功可触发此事件。|
| callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | 否 | 回调函数，如果指定参数则取消对应callback (callback对象不可是匿名函数)，否则参数默认为空，取消所有callback。 |

**示例：**

```ts
function unregisterSystemPressureLevelChangeCallback(videoSession: camera.VideoSession): void {
  videoSession.off('systemPressureLevelChange');
}
```

## on('controlCenterEffectStatusChange')<sup>20+</sup>

on(type: 'controlCenterEffectStatusChange', callback: AsyncCallback\<ControlCenterStatusInfo\>): void

监听相机控制器效果激活状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型 | 必填 | 说明 |
|----------|-------|----|------------------------------------------------------------------------|
| type     | string | 是 | 监听事件，固定为'controlCenterEffectStatusChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[ControlCenterStatusInfo](arkts-apis-camera-i.md#controlcenterstatusinfo20)\> | 是 | 回调函数，用于获取当前控制器激活状态。 |

**示例：**
```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError, status: camera.ControlCenterStatusInfo): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`controlCenterEffectStatusChange: ${status}`);
}

function registerControlCenterEffectStatusChangeCallback(videoSession: camera.VideoSession): void {
  videoSession.on('controlCenterEffectStatusChange', callback);
}
```

## off('controlCenterEffectStatusChange')<sup>20+</sup>

off(type: 'controlCenterEffectStatusChange', callback?: AsyncCallback\<ControlCenterStatusInfo\>): void

注销监听相机控制器激活状态变化。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型 | 必填 | 说明 |
|----------|-------|----|------------------------------------------------------------------------|
| type     | string | 是 | 注销监听事件，固定为'controlCenterEffectStatusChange'，session创建成功可触发此事件。 |
| callback | AsyncCallback\<[ControlCenterStatusInfo](arkts-apis-camera-i.md#controlcenterstatusinfo20)\> | 否 | 回调函数，如果指定参数则取消对应callback (callback对象不可是匿名函数)，否则参数默认为空，取消所有callback。|

**示例：**

```ts
function unregisterControlCenterEffectStatusChange(videoSession: camera.VideoSession): void {
  videoSession.off('controlCenterEffectStatusChange');
}
```

## on('macroStatusChanged')<sup>20+</sup>

on(type: 'macroStatusChanged', callback: AsyncCallback\<boolean\>): void

监听相机微距状态变化，通过注册回调函数获取结果。使用callback异步回调。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string      | 是   | 监听事件，固定为'macroStatusChanged'，session创建成功可监听。 |
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态，返回true是开启状态，返回false是禁用状态。  |

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

## off('macroStatusChanged')<sup>20+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销相机微距状态变化的监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名    | 类型                     | 必填 | 说明                                                                     |
| -------- | ------------------------ | ---- |------------------------------------------------------------------------|
| type     | string                   | 是   | 注销监听事件，固定为'macroStatusChanged'，session创建成功可触发此事件。                      |
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，如果指定参数则取消对应callback (callback对象不可是匿名函数)，否则参数默认为空，取消所有callback。 |

**示例：**

```ts
function unregisterMacroStatusChanged(videoSession: camera.VideoSession): void {
  videoSession.off('macroStatusChanged');
}
```
