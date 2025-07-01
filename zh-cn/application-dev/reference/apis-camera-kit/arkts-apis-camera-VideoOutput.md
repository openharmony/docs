# Interface (VideoOutput)

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

录像会话中使用的输出信息，继承[CameraOutput](arkts-apis-camera-CameraOutput.md)。

## 导入模块

```ts
import { camera } from '@kit.CameraKit';
```

## start

start(callback: AsyncCallback\<void\>): void

启动录制，通过注册回调函数获取结果。使用callback异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

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

## start

start(): Promise\<void\>

启动录制，通过Promise获取结果。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

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

function startVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.start().then(() => {
    console.info('Promise returned to indicate that start method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to video output start, error code: ${error.code}.`);
  });
}
```

## stop

stop(callback: AsyncCallback\<void\>): void

结束录制，通过注册回调函数获取结果。使用callback异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

## stop

stop(): Promise\<void\>

结束录制，通过Promise获取结果。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                     |
| -------------- | ----------------------- |
| Promise\<void\> | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function stopVideoOutput(videoOutput: camera.VideoOutput): void {
  videoOutput.stop().then(() => {
    console.info('Promise returned to indicate that stop method execution success.');
  }).catch((error: BusinessError) => {
    console.error(`Failed to video output stop, error code: ${error.code}.`);
  });
}
```

## on('frameStart')

on(type: 'frameStart', callback: AsyncCallback\<void\>): void

监听录像开始，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。底层第一次曝光时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。  只要有该事件返回就证明录像开始。                     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Video frame started');
}

function registerVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameStart', callback);
}
```

## off('frameStart')

off(type: 'frameStart', callback?: AsyncCallback\<void\>): void

注销监听录像开始。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ----------------------------------------- |
| type     | string               | 是   | 监听事件，固定为'frameStart'，videoOutput创建成功后可监听。 |
| callback | AsyncCallback\<void\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameStart');
}

```

## on('frameEnd')

on(type: 'frameEnd', callback: AsyncCallback\<void\>): void

监听录像结束，通过注册回调函数获取结果。使用callback异步回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。录像完全结束最后一帧时触发该事件并返回。 |
| callback | AsyncCallback\<void\> | 是   | 回调函数，用于获取结果。 只要有该事件返回就证明录像结束。                      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info('Video frame ended');
}

function registerVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.on('frameEnd', callback);
}
```

## off('frameEnd')

off(type: 'frameEnd', callback?: AsyncCallback\<void\>): void

注销监听录像结束。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                  | 必填 | 说明                                       |
| -------- | -------------------- | ---- | ------------------------------------------ |
| type     | string               | 是   | 监听事件，固定为'frameEnd'，videoOutput创建成功后可监听。 |
| callback | AsyncCallback\<void\> | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
  videoOutput.off('frameEnd');
}
```

## on('error')

on(type: 'error', callback: ErrorCallback): void

监听录像输出发生错误，通过注册回调函数获取结果。使用callback异步回调。

> **说明：**
>
> 当前注册监听接口，不支持在on监听的回调方法里，调用off注销回调。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型       | 必填 | 说明                                    |
| -------- | ----------- | ---- | -------------------------------------- |
| type     | string      | 是   | 监听事件，固定为'error'，videoOutput创建成功后可监听。录像接口调用出现错误时触发该事件并返回对应错误码，比如调用[start](#start-1)，[CameraOutput.release](arkts-apis-camera-CameraOutput.md#release-1)接口时出现错误返回对应错误信息。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于获取错误信息。返回错误码，错误码类型[CameraErrorCode](arkts-apis-camera-e.md#cameraerrorcode)。                 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function callback(err: BusinessError): void {
  console.error(`Video output error code: ${err.code}`);
}

function registerVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.on('error', callback);
}
```

## off('error')

off(type: 'error', callback?: ErrorCallback): void

注销监听录像输出发生错误。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                                 |
| -------- | ------------- | ---- | ----------------------------------- |
| type     | string       | 是   | 监听事件，固定为'error'，photoOutput创建成功后可监听。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 回调函数，如果指定参数则取消对应callback（callback对象不可是匿名函数），否则取消所有callback。 |

**示例：**

```ts
function unregisterVideoOutputError(videoOutput: camera.VideoOutput): void {
  videoOutput.off('error');
}
```

## getSupportedFrameRates<sup>12+</sup>

getSupportedFrameRates(): Array\<FrameRateRange\>

查询支持的帧率范围。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

|      类型      |     说明     |
| -------------  | ------------ |
| Array<[FrameRateRange](arkts-apis-camera-i.md#frameraterange)> | 支持的帧率范围列表 |

**示例：**

```ts
function getSupportedFrameRates(videoOutput: camera.VideoOutput): Array<camera.FrameRateRange> {
  let supportedFrameRatesArray: Array<camera.FrameRateRange> = videoOutput.getSupportedFrameRates();
  return supportedFrameRatesArray;
}
```

## setFrameRate<sup>12+</sup>

setFrameRate(minFps: number, maxFps: number): void

设置录像流帧率范围，设置的范围必须在支持的帧率范围内。

进行设置前，可通过[getSupportedFrameRates](#getsupportedframerates12)查询支持的帧率范围。

> **说明：**
> 仅在[PhotoSession](arkts-apis-camera-PhotoSession.md)或[VideoSession](arkts-apis-camera-VideoSession.md)模式下支持。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| minFps   | number        | 是   | 最小帧率。 |
| maxFps   | number        | 是   | 最大帧率。当传入的最小值大于最大值时，传参异常，接口不生效。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID        | 错误信息        |
| --------------- | --------------- |
| 7400101                |  Parameter missing or parameter type incorrect.        |
| 7400110                |  Unresolved conflicts with current configurations.     |

**示例：**

```ts
function setFrameRateRange(videoOutput: camera.VideoOutput, frameRateRange: Array<number>): void {
  videoOutput.setFrameRate(frameRateRange[0], frameRateRange[1]);
}
```

## getActiveFrameRate<sup>12+</sup>

getActiveFrameRate(): FrameRateRange

获取已设置的帧率范围。

使用[setFrameRate](#setframerate12)对录像流设置过帧率后可查询。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

|      类型      |     说明     |
| -------------  | ------------ |
| [FrameRateRange](arkts-apis-camera-i.md#frameraterange) | 帧率范围 |

**示例：**

```ts
function getActiveFrameRate(videoOutput: camera.VideoOutput): camera.FrameRateRange {
  let activeFrameRate: camera.FrameRateRange = videoOutput.getActiveFrameRate();
  return activeFrameRate;
}
```

## getActiveProfile<sup>12+</sup>

getActiveProfile(): VideoProfile

获取当前生效的配置信息。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

|      类型      | 说明        |
| -------------  |-----------|
| [VideoProfile](arkts-apis-camera-i.md#videoprofile) | 当前生效的配置信息 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                         |
|---------|------------------------------|
| 7400201 | Camera service fatal error.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

function testGetActiveProfile(videoOutput: camera.VideoOutput): camera.Profile | undefined {
  let activeProfile: camera.VideoProfile | undefined = undefined;
  try {
    activeProfile = videoOutput.getActiveProfile();
  } catch (error) {
    // 失败返回错误码error.code并处理。
    let err = error as BusinessError;
    console.error(`The videoOutput.getActiveProfile call failed. error code: ${err.code}`);
  }
  return activeProfile;
}
```

## isMirrorSupported<sup>15+</sup>

isMirrorSupported(): boolean

查询是否支持镜像录像。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**返回值：**

| 类型            | 说明                              |
| -------------- |---------------------------------|
| boolean | 返回是否支持镜像录像，true表示支持，false表示不支持。 |

**示例：**

```ts
function testIsMirrorSupported(videoOutput: camera.VideoOutput): boolean {
  let isSupported: boolean = videoOutput.isMirrorSupported();
  return isSupported;
}
```

## enableMirror<sup>15+</sup>

enableMirror(enabled: boolean): void

启用/关闭镜像录像。

- 调用该接口前，需要通过[isMirrorSupported](#ismirrorsupported15)查询是否支录像镜像功能。

- 启用/关闭录像镜像后，需要通过[getVideoRotation](#getvideorotation12)以及[updateRotation](../apis-media-kit/arkts-apis-media-AVRecorder.md#updaterotation12)更新旋转角度。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名      | 类型                    | 必填 | 说明                        |
|----------| ---------------------- | ---- |---------------------------|
| enabled | boolean                | 是   | 启用/关闭镜像录像。true为开启镜像录像，false为关闭镜像录像。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID    | 错误信息                                           |
| -------- |------------------------------------------------|
| 7400101  | Parameter missing or parameter type incorrect. |
| 7400103  | Session not config.                    |


**示例：**

```ts
import { camera } from '@kit.CameraKit';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';

function enableMirror(videoOutput: camera.VideoOutput, mirrorMode: boolean, aVRecorder: media.AVRecorder, deviceDegree : number): void {
    try {
        videoOutput.enableMirror(mirrorMode);
        aVRecorder.updateRotation(videoOutput.getVideoRotation(deviceDegree));
    } catch (error) {
        let err = error as BusinessError;
    }
}
```

## getVideoRotation<sup>12+</sup>

getVideoRotation(deviceDegree: number): ImageRotation

获取录像旋转角度。

- 设备自然方向：设备默认使用方向，手机为竖屏（充电口向下）。
- 相机镜头角度：值等于相机图像顺时针旋转到设备自然方向的角度，手机后置相机传感器是横屏安装的，所以需要顺时针旋转90度到设备自然方向。
- 屏幕显示方向：需要屏幕显示的图片左上角为第一个像素点为坐标原点。锁屏时与自然方向一致。

**原子化服务API：** 从API version 19开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Camera.Core

**参数：**

| 参数名     | 类型         | 必填 | 说明                       |
| -------- | --------------| ---- | ------------------------ |
| deviceDegree | number | 是   | 设备旋转角度（单位：度）。 |

**返回值：**

|      类型      | 说明        |
| -------------  |-----------|
| [ImageRotation](arkts-apis-camera-e.md#imagerotation) | 获取录像旋转角度。 |

**错误码：**

以下错误码的详细介绍请参见[Camera错误码](errorcode-camera.md)。

| 错误码ID   | 错误信息                         |
|---------|------------------------------|
| 7400101 | Parameter missing or parameter type incorrect.  |
| 7400201 | Camera service fatal error.  |

**示例：**

```ts
import { camera } from '@kit.CameraKit';
import { Decimal } from '@kit.ArkTS';
import { sensor } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

function getVideoRotation(videoOutput: camera.VideoOutput): camera.ImageRotation {
    let videoRotation: camera.ImageRotation = camera.ImageRotation.ROTATION_0;
    try {
        videoRotation = videoOutput.getVideoRotation(getDeviceDegree());
    } catch (error) {
        let err = error as BusinessError;
    }
    return videoRotation;
}

//获取deviceDegree。
function getDeviceDegree(): number {
    let deviceDegree: number = -1;
    try {
        sensor.once(sensor.SensorId.GRAVITY, (data: sensor.GravityResponse) => {
            console.info('Succeeded in invoking once. X-coordinate component: ' + data.x);
            console.info('Succeeded in invoking once. Y-coordinate component: ' + data.y);
            console.info('Succeeded in invoking once. Z-coordinate component: ' + data.z);
            let x = data.x;
            let y = data.y;
            let z = data.z;
            if ((x * x + y * y) * 3 < z * z) {
                deviceDegree = -1;
            } else {
                let sd: Decimal = Decimal.atan2(y, -x);
                let sc: Decimal = Decimal.round(Number(sd) / 3.141592653589 * 180)
                deviceDegree = 90 - Number(sc);
                deviceDegree = deviceDegree >= 0 ? deviceDegree% 360 : deviceDegree% 360 + 360;
            }
        });
    } catch (error) {
        let err: BusinessError = error as BusinessError;
    }
    return deviceDegree;
}
```
