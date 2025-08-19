# Interface (PhotoSession)
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

PhotoSession 继承自 [Session](arkts-apis-camera-Session.md)、[Flash](arkts-apis-camera-Flash.md)、[AutoExposure](arkts-apis-camera-AutoExposure.md)、[WhiteBalance](arkts-apis-camera-WhiteBalance.md)、[Focus](arkts-apis-camera-Focus.md)、[Zoom](arkts-apis-camera-Zoom.md)、[ColorManagement](arkts-apis-camera-ColorManagement.md)、[AutoDeviceSwitch](arkts-apis-camera-AutoDeviceSwitch.md)、[Macro](arkts-apis-camera-Macro.md)。

普通拍照模式会话类，提供了对闪光灯、曝光、白平衡、对焦、变焦、色彩空间及微距的操作。

> **说明：**
>
> 默认的拍照模式，用于拍摄标准照片。支持多种照片格式和分辨率，适合大多数日常拍摄场景。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## canPreconfig<sup>12+</sup>

canPreconfig(preconfigType: PreconfigType, preconfigRatio?: PreconfigRatio): boolean

查询当前Session是否支持指定的预配置类型。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名            | 类型                                  | 必填  | 说明              |
|----------------|-------------------------------------|-----|-----------------|
| preconfigType  | [PreconfigType](arkts-apis-camera-e.md#preconfigtype12)   | 是   | 指定配置预期分辨率。      |
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | 否   | 可选画幅比例，默认为4:3。  |

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
function testCanPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    let result = photoSession.canPreconfig(preconfigType, preconfigRatio);
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
| preconfigRatio | [PreconfigRatio](arkts-apis-camera-e.md#preconfigratio12) | 否   | 可选画幅比例，默认为4:3。  |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                        |
|---------|-----------------------------|
| 7400201 | Camera service fatal error. |

**示例：**

```ts
function testPreconfig(photoSession: camera.PhotoSession, preconfigType: camera.PreconfigType,
  preconfigRatio: camera.PreconfigRatio): void {
  try {
    photoSession.preconfig(preconfigType, preconfigRatio);
    console.info(`preconfig ${preconfigType} ${preconfigRatio} success`);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`The preconfig call failed. error code: ${err.code}`);
  }
}
```

## on('error')<sup>11+</sup>

on(type: 'error', callback: ErrorCallback): void

监听普通拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](arkts-apis-camera-Session.md#beginconfig11)，[commitConfig](arkts-apis-camera-Session.md#commitconfig11)，[addInput](arkts-apis-camera-Session.md#addinput11)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Photo session error code: ${err.code}`);
}

function registerSessionError(photoSession: camera.PhotoSession): void {
  photoSession.on('error', callback);
}
```

## off('error')<sup>11+</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听普通拍照会话的错误事件，通过注册回调函数获取结果。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                           |
| -------- | -------------------------------- | ---- | ------------------------------ |
| type     | string                           | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterSessionError(photoSession: camera.PhotoSession): void {
  photoSession.off('error');
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

function registerFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.on('focusStateChange', callback);
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
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterFocusStateChange(photoSession: camera.PhotoSession): void {
  photoSession.off('focusStateChange');
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

function registerSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.on('smoothZoomInfoAvailable', callback);
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
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('smoothZoomInfoAvailable');
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

| 参数名     | 类型                                                                   | 必填 | 说明                                                     |
| -------- |----------------------------------------------------------------------| ---- |--------------------------------------------------------|
| type     | string                                                               | 是   | 监听事件，固定为'autoDeviceSwitchStatusChange'，session创建成功可监听。 |
| callback | AsyncCallback\<[AutoDeviceSwitchStatus](arkts-apis-camera-i.md#autodeviceswitchstatus13)\> | 是   | 回调函数，用于获取当前自动切换镜头的状态。                                  |

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

function registerAutoDeviceSwitchStatus(photoSession: camera.PhotoSession): void {
  photoSession.on('autoDeviceSwitchStatusChange', callback);
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
function unregisterSmoothZoomInfo(photoSession: camera.PhotoSession): void {
  photoSession.off('autoDeviceSwitchStatusChange');
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
|callback | AsyncCallback\<[SystemPressureLevel](arkts-apis-camera-e.md#systempressurelevel20)\> | 是 | 回调函数，用于获取当前系统压力状态. |

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

function registerSystemPressureLevelChangeCallback(photoSession: camera.PhotoSession): void {
    photoSession.on('systemPressureLevelChange', callback);
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
function unregisterSystemPressureLevelChangeCallback(photoSession: camera.PhotoSession): void {
  photoSession.off('systemPressureLevelChange');
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
| callback | AsyncCallback\<boolean\>     | 是   | 回调函数，用于获取当前微距状态，返回true为开启状态，返回false为禁用状态。  |

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

## off('macroStatusChanged')<sup>20+</sup>

off(type: 'macroStatusChanged', callback?: AsyncCallback\<boolean\>): void

注销相机微距状态变化的监听。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                                                                     |
| -------- | ------------------------ | ---- |------------------------------------------------------------------------|
| type     | string                   | 是   | 注销监听事件，固定为'macroStatusChanged'，session创建成功可触发此事件。|
| callback | AsyncCallback\<boolean\> | 否   | 回调函数，可选，如果指定参数则取消对应callback (callback对象不可是匿名函数)，否则参数默认为空，取消所有callback。 |

**示例：**

```ts
function unregisterMacroStatusChanged(photoSession: camera.PhotoSession): void {
  photoSession.off('macroStatusChanged');
}
```
