# Interface (Stabilization)

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 11开始支持。

Stabilization extends [StabilizationQuery](arkts-apis-camera-StabilizationQuery.md)

提供设备在录像模式下设置视频防抖的操作。

 > **说明：**
 >
 > 需要会话中有录像流（[VideoOutput](arkts-apis-camera-VideoOutput.md)）的前提下，才可以对视频进行防抖设置，
 > 其中[VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode)中的枚举HIGH需要在[Profile](arkts-apis-camera-i.md#profile)的分辨率为1920*1080的场景下生效。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## getActiveVideoStabilizationMode<sup>11+</sup>

getActiveVideoStabilizationMode(): VideoStabilizationMode

查询当前正在使用的视频防抖模式。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型        | 说明          |
| ---------- |-------------|
| [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode)    | 视频防抖是否正在使用。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function getActiveVideoStabilizationMode(videoSession: camera.VideoSession): camera.VideoStabilizationMode | undefined {
  let vsMode: camera.VideoStabilizationMode | undefined = undefined;
  try {
    vsMode = videoSession.getActiveVideoStabilizationMode();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The getActiveVideoStabilizationMode call failed. error code: ${err.code}`);
  }
  return vsMode;
}
```

## setVideoStabilizationMode<sup>11+</sup>

setVideoStabilizationMode(mode: VideoStabilizationMode): void

设置视频防抖模式。需要先检查设备是否支持对应的防抖模式，可以通过[isVideoStabilizationModeSupported](arkts-apis-camera-StabilizationQuery.md#isvideostabilizationmodesupported11)方法判断所设置的模式是否支持。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明                    |
| -------- | ------------------------------------------------- | ---- | --------------------- |
| mode     | [VideoStabilizationMode](arkts-apis-camera-e.md#videostabilizationmode) | 是   | 需要设置的视频防抖模式。   |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID         | 错误信息        |
| --------------- | --------------- |
| 7400103                |  Session not config.                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function setVideoStabilizationMode(videoSession: camera.VideoSession): void {
  try {
    videoSession.setVideoStabilizationMode(camera.VideoStabilizationMode.OFF);
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The setVideoStabilizationMode call failed. error code: ${err.code}`);
  }
}
```
