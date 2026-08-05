# Interface (AutoExposure)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->

AutoExposure继承自[AutoExposureQuery](arkts-apis-camera-AutoExposureQuery.md)。

自动曝光类，对设备自动曝光（AE）操作。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 11开始支持。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## getExposureMode<sup>11+</sup>

getExposureMode(): ExposureMode

获取当前曝光模式。

> **说明：**
>
> 若未通过[setExposureMode](arkts-apis-camera-AutoExposure.md#setexposuremode11)接口进行设置，直接调用该接口查询当前曝光模式，会返回无效值。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMode](arkts-apis-camera-e.md#exposuremode)    | 获取当前曝光模式。接口调用失败会抛出相应错误码并返回undefined，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMode(photoSession: camera.PhotoSession): camera.ExposureMode | undefined {
  let exposureMode: camera.ExposureMode | undefined = undefined;
  try {
    exposureMode = photoSession.getExposureMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureMode call failed. error code: ${err.code}`);
  }
  return exposureMode;
}
```

## setExposureMode<sup>11+</sup>

setExposureMode(aeMode: ExposureMode): void

设置曝光模式。进行设置之前，需要先检查设备是否支持指定的曝光模式，可使用方法[isExposureModeSupported](arkts-apis-camera-AutoExposureQuery.md#isexposuremodesupported11)。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                            | 必填 | 说明                    |
| -------- | -------------------------------| ---- | ----------------------- |
| aeMode   | [ExposureMode](arkts-apis-camera-e.md#exposuremode)  | 是   | 曝光模式。传参为null或者undefined，作为0处理，曝光锁定。                |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                | Operation not allowed.<br>适用版本：19+                                 |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMode(photoSession: camera.PhotoSession): void {
  try {
    photoSession.setExposureMode(camera.ExposureMode.EXPOSURE_MODE_LOCKED);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setExposureMode call failed. error code: ${err.code}`);
  }
}
```

## getMeteringPoint<sup>11+</sup>

getMeteringPoint(): Point

查询曝光区域中心点。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [Point](arkts-apis-camera-i.md#point)    | 获取当前曝光点。接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息        |
|---------| --------------- |
| 7400103 |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getMeteringPoint(photoSession: camera.PhotoSession): camera.Point | undefined {
  let exposurePoint: camera.Point | undefined = undefined;
  try {
    exposurePoint = photoSession.getMeteringPoint();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getMeteringPoint call failed. error code: ${err.code}`);
  }
  return exposurePoint;
}
```

## setMeteringPoint<sup>11+</sup>

setMeteringPoint(point: Point): void

设置曝光区域中心点，曝光点应在0-1坐标系内，该坐标系左上角为{0,0}，右下角为{1,1}。

此坐标系是以设备充电口在右侧时的横向设备方向为基准的，例如应用的预览界面布局以设备充电口在下侧时的竖向方向为基准，布局宽高为{w,h}，且触摸点为{x,y}，则转换后的坐标点为{y/h,1-x/w}。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名           | 类型                            | 必填 | 说明                 |
| ------------- | -------------------------------| ---- | ------------------- |
| point | [Point](arkts-apis-camera-i.md#point)                | 是   | 曝光点，x、y设置范围应在[0,1]之内，超过范围，如果小于0设置0，大于1设置1。             |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setMeteringPoint(photoSession: camera.PhotoSession): void {
  const point: camera.Point = {x: 1, y: 1};
  try {
    photoSession.setMeteringPoint(point);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setMeteringPoint call failed. error code: ${err.code}`);
  }
}
```

## setExposureBias<sup>11+</sup>

setExposureBias(exposureBias: number): void

设置曝光补偿，曝光补偿值（EV）。

进行设置之前，建议先通过方法[getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11)查询支持的范围。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                            | 必填 | 说明                                                                                                                                                                                            |
| -------- | -------------------------------| ---- |-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| exposureBias   | number                   | 是   | 曝光补偿，[getExposureBiasRange](arkts-apis-camera-AutoExposureQuery.md#getexposurebiasrange11)查询支持的范围，如果设置超过支持范围的值，自动匹配到就近临界点。<br>曝光补偿存在步长，由于设备差异，步长也存在差异。例如步长为0.5，则设置1.2时，获取到实际生效曝光补偿为1.0。<br>接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allowed.<br>适用版本：12+                 |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureBias(photoSession: camera.PhotoSession, biasRangeArray: Array<number>): void {
  if (biasRangeArray && biasRangeArray.length > 0) {
    let exposureBias = biasRangeArray[0];
    try {
      photoSession.setExposureBias(exposureBias);
    } catch (error) {
      // 失败返回错误码error.code并处理。
      let err = error as BusinessError;
      console.error(`The setExposureBias call failed. error code: ${err.code}`);
    }
  }
}
```

## getExposureValue<sup>11+</sup>

getExposureValue(): number

查询当前曝光值。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| number    | 获取曝光值。曝光补偿存在步长，如步长为0.5。则设置1.2时，获取到实际生效曝光补偿为1.0。<br>接口调用失败会返回相应错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureValue(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let exposureValue: number = invalidValue;
  try {
    exposureValue = photoSession.getExposureValue();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureValue call failed. error code: ${err.code}`);
  }
  return exposureValue;
}
```

## getExposureMeteringMode<sup>24+</sup>

getExposureMeteringMode(): ExposureMeteringMode

获取当前曝光测光模式。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明                          |
| ---------- | ----------------------------- |
| [ExposureMeteringMode](arkts-apis-camera-e.md#exposuremeteringmode24)    | 当前曝光测光模式。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allowed, the inputDevice or the session is abnormal.                                   |
| 7400103                |  Session not config, only throw in session usage.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getExposureMeteringMode(photoSession: camera.PhotoSession): camera.ExposureMeteringMode {
  let meteringMode: camera.ExposureMeteringMode = camera.ExposureMeteringMode.MATRIX;
  try {
    meteringMode = photoSession.getExposureMeteringMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getExposureMeteringMode call failed. error code: ${err.code}`);
  }
  return meteringMode;
}
```

## setExposureMeteringMode<sup>24+</sup>

setExposureMeteringMode(aeMeteringMode: ExposureMeteringMode): void

设置曝光测光模式。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                           | 必填  | 说明                           |
| -------- | -------------------------------| ---- | ----------------------------- |
| aeMeteringMode   | [ExposureMeteringMode](arkts-apis-camera-e.md#exposuremeteringmode24)  | 是   | 曝光测光模式。                 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400102                |  Operation not allowed, the inputDevice or the session is abnormal.                                   |
| 7400103                |  Session not config, only throw in session usage.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setExposureMeteringMode(photoSession: camera.PhotoSession, aeMeteringMode: camera.ExposureMeteringMode): void {
  try {
    photoSession.setExposureMeteringMode(aeMeteringMode);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setExposureMeteringMode call failed. error code: ${err.code}`);
  }
}
```

## onExposureStateChange

onExposureStateChange(callback: Callback\<ExposureState\>): void

监听曝光状态事件变更。使用callback异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[ExposureState](arkts-apis-camera-e.md#exposurestate)\> | 是   | 回调函数，返回当前曝光状态。            |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(exposureState: camera.ExposureState): void {
  console.info(`exposureState: ${exposureState}`);
}

function registerPhotoOutputCaptureStart(captureSession: camera.PhotoSession): void {
  captureSession.onExposureStateChange(callback);
}
```

## offExposureStateChange

offExposureStateChange(callback?: Callback\<ExposureState\>): void

注销监听曝光状态事件变更。使用callback异步回调。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Multimedia.Camera.Core

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型                    | 必填 | 说明                                       |
| -------- | ---------------------- | ---- | ------------------------------------------ |
| callback | Callback\<[ExposureState](arkts-apis-camera-e.md#exposurestate)\> | 否   | 回调函数，如果指定参数则取消对应callback，callback对象如果为空或为匿名函数，则取消所有callback。     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(exposureState: camera.ExposureState): void {
  console.info(`exposureState: ${exposureState}`);
}

function unregisterPhotoOutputCaptureStart(captureSession: camera.PhotoSession): void {
  captureSession.offExposureStateChange(callback);
}

function unregisterPhotoOutputCaptureStartWithoutParam(captureSession: camera.PhotoSession): void {
  captureSession.offExposureStateChange();
}
```
