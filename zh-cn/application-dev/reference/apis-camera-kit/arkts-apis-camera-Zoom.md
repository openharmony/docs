# Interface (Zoom)

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

Zoom extends [ZoomQuery](arkts-apis-camera-ZoomQuery.md)

变焦类，对设备变焦操作。

## setZoomRatio<sup>11+</sup>

setZoomRatio(zoomRatio: number): void

设置变焦比，变焦精度最高为小数点后两位，如果设置超过支持的精度范围，则只保留精度范围内数值。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型                  | 必填 | 说明                                                                                                                              |
| --------- | -------------------- | ---- |---------------------------------------------------------------------------------------------------------------------------------|
| zoomRatio | number               | 是   | 可变焦距比，通过[getZoomRatioRange](arkts-apis-camera-ZoomQuery.md#getzoomratiorange11)获取支持的变焦范围，如果设置超过支持范围的值，则只保留精度范围内数值。<br>设置可变焦距比到底层生效需要一定时间，获取正确设置的可变焦距比需要等待1~2帧的时间。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setZoomRatio(photoSession: camera.PhotoSession, zoomRatioRange: Array<number>): void {
  if (zoomRatioRange === undefined || zoomRatioRange.length <= 0) {
    return;
  }
  let zoomRatio = zoomRatioRange[0];
  try {
    photoSession.setZoomRatio(zoomRatio);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setZoomRatio call failed. error code: ${err.code}`);
  }
}
```

## getZoomRatio<sup>11+</sup>

getZoomRatio(): number

获取当前的变焦比。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

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
| 7400201                |  Camera service fatal error.                           |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getZoomRatio(photoSession: camera.PhotoSession): number {
  const invalidValue: number = -1;
  let zoomRatio: number = invalidValue;
  try {
    zoomRatio = photoSession.getZoomRatio();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getZoomRatio call failed. error code: ${err.code}`);
  }
  return zoomRatio;
}
```

## setSmoothZoom<sup>11+</sup>

setSmoothZoom(targetRatio: number, mode?: SmoothZoomMode): void

触发平滑变焦。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名       | 类型            | 必填 | 说明               |
| ------------ | -------------- | ---- | ----------------- |
| targetRatio  | number         | 是   | 目标值。      |
| mode         | [SmoothZoomMode](arkts-apis-camera-e.md#smoothzoommode11) | 否   | 模式。      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setSmoothZoom(sessionExtendsZoom: camera.Zoom, targetZoomRatio: number, mode: camera.SmoothZoomMode): void {
  sessionExtendsZoom.setSmoothZoom(targetZoomRatio, mode);
}
```
