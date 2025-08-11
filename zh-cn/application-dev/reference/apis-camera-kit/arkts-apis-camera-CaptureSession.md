# 废弃的Interface (CaptureSession, deprecated)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

> **说明：**
>
> 从 API version 10开始支持，从API version 11开始废弃。建议使用[PhotoSession](arkts-apis-camera-PhotoSession.md)、[VideoSession](arkts-apis-camera-VideoSession.md)替代。

拍照会话类，保存一次相机运行所需要的所有资源[CameraInput](arkts-apis-camera-CameraInput.md)、[CameraOutput](arkts-apis-camera-CameraOutput.md)，并向相机设备申请完成相机功能(录像，拍照)。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## beginConfig<sup>(deprecated)</sup>

beginConfig(): void

开始配置会话。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.beginConfig](arkts-apis-camera-Session.md#beginconfig11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400105         |  Session config locked.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function beginConfig(captureSession: camera.CaptureSession): void {
  try {
    captureSession.beginConfig();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The beginConfig call failed. error code: ${err.code}`);
  }
}
```

## commitConfig<sup>(deprecated)</sup>

commitConfig(callback: AsyncCallback\<void\>): void

提交配置信息，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                   | 必填 | 说明                  |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode) |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## commitConfig<sup>(deprecated)</sup>

commitConfig(): Promise\<void\>

提交配置信息，通过Promise获取结果。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.commitConfig](arkts-apis-camera-Session.md#commitconfig11-1)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                |
| -------------- |-------------------|
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.                                  |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function commitConfig(captureSession: camera.CaptureSession): void {
  captureSession.commitConfig().then(() => {
    console.info('Promise returned to indicate the commit config success.');
  }).catch((error: BusinessError) => {
    // 失败返回错误码error.code并处理。
    console.error(`The commitConfig call failed. error code: ${error.code}`);
  });
}
```

## addInput<sup>(deprecated)</sup>

addInput(cameraInput: CameraInput): void

把[CameraInput](arkts-apis-camera-CameraInput.md)加入到会话。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.addInput](arkts-apis-camera-Session.md#addinput11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                     |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](arkts-apis-camera-CameraInput.md) | 是   | 需要添加的CameraInput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                                          |
|---------|-----------------------------------------------|
| 7400101 | Parameter missing or parameter type incorrect. |
| 7400102 | Operation not allowed.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The addInput call failed. error code: ${err.code}`);
  }
}
```

## removeInput<sup>(deprecated)</sup>

removeInput(cameraInput: CameraInput): void

移除[CameraInput](arkts-apis-camera-CameraInput.md)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.removeInput](arkts-apis-camera-Session.md#removeinput11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名        | 类型                          | 必填 | 说明                      |
| ----------- | --------------------------- | ---- | ------------------------ |
| cameraInput | [CameraInput](arkts-apis-camera-CameraInput.md) | 是   | 需要移除的CameraInput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeInput(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput): void {
  try {
    captureSession.removeInput(cameraInput);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The removeInput call failed. error code: ${err.code}`);
  }
}
```

## addOutput<sup>(deprecated)</sup>

addOutput(cameraOutput: CameraOutput): void

把[CameraOutput](arkts-apis-camera-CameraOutput.md)加入到会话。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.addOutput](arkts-apis-camera-Session.md#addoutput11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](arkts-apis-camera-CameraOutput.md)   | 是   | 需要添加的CameraOutput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function addOutput(captureSession: camera.CaptureSession, cameraOutput: camera.CameraOutput): void {
  try {
    captureSession.addOutput(cameraOutput);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The addOutput call failed. error code: ${err.code}`);
  }
}
```

## removeOutput<sup>(deprecated)</sup>

removeOutput(cameraOutput: CameraOutput): void

从会话中移除[CameraOutput](arkts-apis-camera-CameraOutput.md)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.removeOutput](arkts-apis-camera-Session.md#removeoutput11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                             | 必填 | 说明                      |
| ------------- | ------------------------------- | ---- | ------------------------ |
| cameraOutput  | [CameraOutput](arkts-apis-camera-CameraOutput.md)   | 是   | 需要移除的CameraOutput实例。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400102                |  Operation not allowed.                                  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function removeOutput(captureSession: camera.CaptureSession, previewOutput: camera.PreviewOutput): void {
  try {
    captureSession.removeOutput(previewOutput);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The removeOutput call failed. error code: ${err.code}`);
  }
}
```

## start<sup>(deprecated)</sup>

start(callback: AsyncCallback\<void\>): void

开始会话工作，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.start](arkts-apis-camera-Session.md#start11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## start<sup>(deprecated)</sup>

start(): Promise\<void\>

开始会话工作，通过Promise获取结果。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.start](arkts-apis-camera-Session.md#start11-1)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
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

function startCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.start().then(() => {
    console.info('Promise returned to indicate the session start success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to start the session, error code: ${err.code}.`);
  });
}
```

## stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void\>): void

停止会话工作，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.stop](arkts-apis-camera-Session.md#stop11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | ------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## stop<sup>(deprecated)</sup>

stop(): Promise\<void\>

停止会话工作，通过Promise获取结果。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.stop](arkts-apis-camera-Session.md#stop11-1)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.stop().then(() => {
    console.info('Promise returned to indicate the session stop success.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to stop the session, error code: ${err.code}.`);
  });
}
```

## release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void\>): void

释放会话资源，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.release](arkts-apis-camera-Session.md#release11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                 |
| -------- | -------------------- | ---- | -------------------- |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## release<sup>(deprecated)</sup>

release(): Promise\<void\>

释放会话资源，通过Promise获取结果。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Session.release](arkts-apis-camera-Session.md#release11-1)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ------------------------ |
| Promise\<void\> | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function releaseCaptureSession(captureSession: camera.CaptureSession): void {
  captureSession.release().then(() => {
    console.info('Promise returned to indicate that the CaptureSession instance is released successfully.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to release the CaptureSession instance, error code: ${err.code}.`);
  });
}
```

## hasFlash<sup>(deprecated)</sup>

hasFlash(): boolean

检测是否有闪光灯。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Flash.hasFlash](arkts-apis-camera-FlashQuery.md#hasflash11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 设备支持闪光灯。true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function hasFlash(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.hasFlash();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The hasFlash call failed. error code: ${err.code}`);
  }
  return status;
}
```

## isFlashModeSupported<sup>(deprecated)</sup>

isFlashModeSupported(flashMode: FlashMode): boolean

检测闪光灯模式是否支持。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Flash.isFlashModeSupported](arkts-apis-camera-FlashQuery.md#isflashmodesupported11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                     | 必填 | 说明                               |
| --------- | ----------------------- | ---- | --------------------------------- |
| flashMode | [FlashMode](arkts-apis-camera-e.md#flashmode) | 是   | 指定闪光灯模式。                     |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 检测闪光灯模式是否支持。true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFlashModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFlashModeSupported(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFlashModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## setFlashMode<sup>(deprecated)</sup>

setFlashMode(flashMode: FlashMode): void

设置闪光灯模式。

进行设置之前，需要先检查：

1. 设备是否支持闪光灯，可使用方法[hasFlash](#hasflashdeprecated)。
2. 设备是否支持指定的闪光灯模式，可使用方法[isFlashModeSupported](#isflashmodesupporteddeprecated)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Flash.setFlashMode](arkts-apis-camera-Flash.md#setflashmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                    | 必填 | 说明                 |
| --------- | ----------------------- | ---- | -------------------- |
| flashMode | [FlashMode](arkts-apis-camera-e.md#flashmode) | 是   | 指定闪光灯模式。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFlashMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFlashMode(camera.FlashMode.FLASH_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFlashMode call failed. error code: ${err.code}`);
  }
}
```

## getFlashMode<sup>(deprecated)</sup>

getFlashMode(): FlashMode

获取当前设备的闪光灯模式。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Flash.getFlashMode](arkts-apis-camera-Flash.md#getflashmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FlashMode](arkts-apis-camera-e.md#flashmode)    | 获取当前设备的闪光灯模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFlashMode(captureSession: camera.CaptureSession): camera.FlashMode | undefined {
  let flashMode: camera.FlashMode | undefined = undefined;
  try {
    flashMode = captureSession.getFlashMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFlashMode call failed.error code: ${err.code}`);
  }
  return flashMode;
}
```

## isExposureModeSupported<sup>(deprecated)</sup>

isExposureModeSupported(aeMode: ExposureMode): boolean

查询曝光模式是否支持。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.isExposureModeSupported](arkts-apis-camera-AutoExposureQuery.md#isexposuremodesupported11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | 是   | 曝光模式。                      |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 获取是否支持曝光模式。true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isExposureModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isExposureModeSupported(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isExposureModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## getExposureMode<sup>(deprecated)</sup>

getExposureMode(): ExposureMode

获取当前曝光模式。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.getExposureMode](arkts-apis-camera-AutoExposure.md#getexposuremode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMode](arkts-apis-camera-e.md#exposuremode)    | 获取当前曝光模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMode(captureSession: camera.CaptureSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = captureSession.getExposureMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

## setExposureMode<sup>(deprecated)</sup>

setExposureMode(aeMode: ExposureMode): void

设置曝光模式。进行设置之前，需要先检查设备是否支持指定的曝光模式，可使用方法[isExposureModeSupported](#isexposuremodesupporteddeprecated)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.setExposureMode](arkts-apis-camera-AutoExposure.md#setexposuremode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | 是   | 曝光模式。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

## getMeteringPoint<sup>(deprecated)</sup>

getMeteringPoint(): Point

查询曝光区域中心点。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.getMeteringPoint](arkts-apis-camera-AutoExposure.md#getmeteringpoint11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | 获取当前曝光点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = captureSession.getMeteringPoint();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

## setMeteringPoint<sup>(deprecated)</sup>

setMeteringPoint(point: Point): void

设置曝光区域中心点，曝光点应位于0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。
此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以
设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，
则转换后的坐标点为{y/h，1-x/w}。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.setMeteringPoint](arkts-apis-camera-AutoExposure.md#setmeteringpoint11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)                | 是   | 曝光点，x,y设置范围应在[0,1]之内，超过范围，如果小于0设置0，大于1设置1。             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(captureSession: camera.CaptureSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setMeteringPoint(point);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

## getExposureBiasRange<sup>(deprecated)</sup>

getExposureBiasRange(): Array\<number\>

查询曝光补偿范围。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 获取补偿范围的数组。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureBiasRange(captureSession: camera.CaptureSession): Array<number> {
  let biasRangeArray: Array<number> = [];
  try {
    biasRangeArray = captureSession.getExposureBiasRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureBiasRange call failed. error code: ${err.code}`);
  }
  return biasRangeArray;
}
```

## setExposureBias<sup>(deprecated)</sup>

setExposureBias(exposureBias: number): void

设置曝光补偿，曝光补偿值（EV）。

进行设置之前，建议先通过方法[getExposureBiasRange](#getexposurebiasrangedeprecated)查询支持的范围。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.setExposureBias](arkts-apis-camera-AutoExposure.md#setexposurebias11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填  | 说明       |
| -------- | -----------|-----|-----------------|
| exposureBias   | number                   | 是  | 曝光补偿，[getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11)查询支持的范围，如果设置超过支持范围的值，自动匹配到就近临界点。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。传参为null或者undefined，作为0处理，曝光补偿设置0。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(captureSession: camera.CaptureSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      captureSession.setExposureBias(exposureBias);
    } catch (error) {
      // 失败返回错误码error.code并处理。
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

## getExposureValue<sup>(deprecated)</sup>

getExposureValue(): number

查询当前的曝光值。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[AutoExposure.getExposureValue](arkts-apis-camera-AutoExposure.md#getexposurevalue11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取曝光值。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = captureSession.getExposureValue();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

## isFocusModeSupported<sup>(deprecated)</sup>

isFocusModeSupported(afMode: FocusMode): boolean

查询对焦模式是否支持。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.isFocusModeSupported](arkts-apis-camera-FocusQuery.md#isfocusmodesupported11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                              |
| -------- | ----------------------- | ---- | -------------------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | 是   | 指定的焦距模式。                    |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 检测对焦模式是否支持。true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isFocusModeSupported(captureSession: camera.CaptureSession): boolean {
  let status: boolean = false;
  try {
    status = captureSession.isFocusModeSupported(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isFocusModeSupported call failed. error code: ${err.code}`);
  }
  return status;
}
```

## setFocusMode<sup>(deprecated)</sup>

setFocusMode(afMode: FocusMode): void

设置对焦模式。

进行设置之前，需要先检查设备是否支持指定的焦距模式，可使用方法[isFocusModeSupported](#isfocusmodesupporteddeprecated)。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.setFocusMode](arkts-apis-camera-Focus.md#setfocusmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                     | 必填 | 说明                 |
| -------- | ----------------------- | ---- | ------------------- |
| afMode   | [FocusMode](arkts-apis-camera-e.md#focusmode) | 是   | 指定的焦距模式。       |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setFocusMode(camera.FocusMode.FOCUS_MODE_AUTO);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusMode call failed. error code: ${err.code}`);
  }
}
```

## getFocusMode<sup>(deprecated)</sup>

getFocusMode(): FocusMode

获取当前的对焦模式。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.getFocusMode](arkts-apis-camera-Focus.md#getfocusmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [FocusMode](arkts-apis-camera-e.md#focusmode)   | 获取当前设备的焦距模式。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusMode(captureSession: camera.CaptureSession): camera.FocusMode | undefined {
  let afMode: camera.FocusMode | undefined = undefined;
  try {
    afMode = captureSession.getFocusMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusMode call failed. error code: ${err.code}`);
  }
  return afMode;
}
```

## setFocusPoint<sup>(deprecated)</sup>

setFocusPoint(point: Point): void

设置焦点，焦点应在0-1坐标系内，该坐标系左上角为{0，0}，右下角为{1，1}。
此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以
设备充电口在下侧时的竖向方向为基准，布局宽高为{w，h}，且触碰点为{x，y}，
则转换后的坐标点为{y/h，1-x/w}。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.setFocusPoint](arkts-apis-camera-Focus.md#setfocuspoint11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名   | 类型                     | 必填  | 说明                 |
|-------| ----------------------- |-----| ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)         | 是  | 焦点。x,y设置范围应在[0,1]之内，超过范围，如果小于0设置0，大于1设置1。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setFocusPoint(captureSession: camera.CaptureSession): void {
  const focusPoint: camera.Point = {x: 1, y: 1};
  try {
    captureSession.setFocusPoint(focusPoint);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setFocusPoint call failed. error code: ${err.code}`);
  }
}
```

## getFocusPoint<sup>(deprecated)</sup>

getFocusPoint(): Point

查询焦点。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.getFocusPoint](arkts-apis-camera-Focus.md#getfocuspoint11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | 用于获取当前焦点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocusPoint(captureSession: camera.CaptureSession): camera.Point | undefined {
  let point: camera.Point | undefined = undefined;
  try {
    point = captureSession.getFocusPoint();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocusPoint call failed. error code: ${err.code}`);
  }
  return point;
}
```

## getFocalLength<sup>(deprecated)</sup>

getFocalLength(): number

查询焦距值。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Focus.getFocalLength](arkts-apis-camera-Focus.md#getfocallength11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 用于获取当前焦距。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getFocalLength(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let focalLength: number = invalidValue;
  try {
    focalLength = captureSession.getFocalLength();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getFocalLength call failed. error code: ${err.code}`);
  }
  return focalLength;
}
```

## getZoomRatioRange<sup>(deprecated)</sup>

getZoomRatioRange(): Array\<number\>

获取支持的变焦范围。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Zoom.getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| Array\<number\>   | 用于获取可变焦距比范围，返回的数组包括其最小值和最大值。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatioRange(captureSession: camera.CaptureSession): Array<number> {
  let zoomRatioRange: Array<number> = [];
  try {
    zoomRatioRange = captureSession.getZoomRatioRange();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getZoomRatioRange call failed. error code: ${err.code}`);
  }
  return zoomRatioRange;
}
```

## setZoomRatio<sup>(deprecated)</sup>

setZoomRatio(zoomRatio: number): void

设置变焦比，变焦精度最高为小数点后两位，如果设置超过支持的精度范围，则只保留精度范围内数值。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Zoom.setZoomRatio](arkts-apis-camera-Zoom.md#setzoomratio11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                  | 必填  | 说明                 |
| --------- | -------------------- |-----| ------------------- |
| zoomRatio | number               | 是  | 可变焦距比，通过[getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11)获取支持的变焦范围，如果设置超过支持范围的值，则只保留精度范围内数值。传参为null或者undefined，作为0处理，变焦设置最小值。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setZoomRatio(captureSession: camera.CaptureSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    captureSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

## getZoomRatio<sup>(deprecated)</sup>

getZoomRatio(): number

获取当前的变焦比。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Zoom.getZoomRatio](arkts-apis-camera-Zoom.md#getzoomratio11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取当前的变焦比结果。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatio(captureSession: camera.CaptureSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = captureSession.getZoomRatio();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

## isVideoStabilizationModeSupported<sup>(deprecated)</sup>

isVideoStabilizationModeSupported(vsMode: VideoStabilizationMode): boolean

查询是否支持指定的视频防抖模式。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Stabilization.isVideoStabilizationModeSupported](arkts-apis-camera-StabilizationQuery.md#isvideostabilizationmodesupported11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                             |
| -------- | ------------------------------------------------- | ---- | ------------------------------ |
| vsMode   | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | 是   | 视频防抖模式。传参为null或者undefined，作为0处理，超级防抖模式关闭。              |

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| boolean    | 返回视频防抖模式是否支持。true表示支持，false表示不支持。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function isVideoStabilizationModeSupported(captureSession: camera.CaptureSession): boolean {
  let isSupported: boolean = false;
  try {
    isSupported = captureSession.isVideoStabilizationModeSupported(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The isVideoStabilizationModeSupported call failed. error code: ${err.code}`);
  }
  return isSupported;
}
```

## getActiveVideoStabilizationMode<sup>(deprecated)</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

查询当前正在使用的视频防抖模式。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Stabilization.getActiveVideoStabilizationMode](arkts-apis-camera-Stabilization.md#getactivevideostabilizationmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode)    | 视频防抖是否正在使用。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(captureSession: camera.CaptureSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = captureSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

## setVideoStabilizationMode<sup>(deprecated)</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

设置视频防抖模式。需要先检查设备是否支持对应的防抖模式，可以通过[isVideoStabilizationModeSupported](#isvideostabilizationmodesupporteddeprecated)方法判断所设置的模式是否支持。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[Stabilization.setVideoStabilizationMode](arkts-apis-camera-Stabilization.md#setvideostabilizationmode11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | 是   | 需要设置的视频防抖模式。传参为null或者undefined，作为0处理，超级防抖模式关闭。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(captureSession: camera.CaptureSession): void {
  try {
    captureSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```

## on('focusStateChange')<sup>(deprecated)</sup>

on(type: 'focusStateChange', callback: AsyncCallback\<FocusState\>): void

监听相机聚焦的状态变化，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
> 从 API version 10开始支持，从API version 11开始废弃。建议使用[VideoSession.on('focusStateChange')](arkts-apis-camera-VideoSession.md#onfocusstatechange11)替代。
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session 创建成功可监听。仅当自动对焦模式时,且相机对焦状态发生改变时可触发该事件。 |
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | 是   | 回调函数，用于获取当前对焦状态。  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.on('focusStateChange', (err: BusinessError, focusState: camera.FocusState) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    console.info(`Focus state: ${focusState}`);
  });
}
```

## off('focusStateChange')<sup>(deprecated)</sup>

off(type: 'focusStateChange', callback?: AsyncCallback\<FocusState\>): void

注销监听相机聚焦的状态变化。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[VideoSession.off('focusStateChange')](arkts-apis-camera-VideoSession.md#offfocusstatechange11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                       |
| -------- | ----------------------------------------- | ---- | ------------------------ |
| type     | string                                    | 是   | 监听事件，固定为'focusStateChange'，session 创建成功可监听。|
| callback | AsyncCallback\<[FocusState](arkts-apis-camera-e.md#focusstate)\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterFocusStateChange(captureSession: camera.CaptureSession): void {
  captureSession.off('focusStateChange');
}
```

## on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

监听拍照会话的错误事件，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[VideoSession.on('error')](arkts-apis-camera-VideoSession.md#onerror11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                                       | 必填 | 说明                           |
| -------- |--------------------------------------------------------------------------| ---- | ------------------------------ |
| type     | string                                                                   | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。session调用相关接口出现错误时会触发该事件，比如调用[beginConfig](#beginconfigdeprecated)，[commitConfig](#commitconfigdeprecated-1)，[addInput](#addinputdeprecated)等接口发生错误时返回错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。        |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function registerCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.on('error', (error: BusinessError) => {
    console.error(`Capture session error code: ${error.code}`);
  });
}
```

## off('error')<sup>(deprecated)</sup>

off(type: 'error', callback?: ErrorCallback): void

注销监听拍照会话的错误事件，通过注册回调函数获取结果。

> **说明：**
>从 API version 10开始支持，从API version 11开始废弃。建议使用[VideoSession.off('error')](arkts-apis-camera-VideoSession.md#offerror11)替代。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                                                          | 必填 | 说明                           |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------ |
| type     | string                                                      | 是   | 监听事件，固定为'error'，session创建成功之后可监听该接口。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback)| 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterCaptureSessionError(captureSession: camera.CaptureSession): void {
  captureSession.off('error');
}
```
