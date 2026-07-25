# Interface (AVRecorder)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->


AVRecorder是音视频录制管理类，用于音视频录制的全流程管理，支持音频录制、视频录制及音视频混合录制，可灵活配置编码参数、添加水印、监听录制状态。适用于录制音视频并保存到文件的场景。在调用AVRecorder的方法前，需要先调用[createAVRecorder](arkts-apis-media-f.md#mediacreateavrecorder9)接口构建一个AVRecorder实例。典型录制流程：[createAVRecorder](arkts-apis-media-f.md#mediacreateavrecorder9) → [prepare](#prepare9) → [getInputSurface](#getinputsurface9)（纯视频/音视频录制时） → [start](#start9) → [pause](#pause9)/[resume](#resume9) → [stop](#stop9) → [release](#release9)。

音视频录制示例可参考：[音频录制开发指导](../../media/media/using-avrecorder-for-recording.md)、[视频录制开发指导](../../media/media/video-recording.md)。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。
> - 相机视频录制功能需配合相机模块使用，相机模块接口的使用详情请参考[相机管理](../apis-camera-kit/arkts-apis-camera.md)。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

| 名称    | 类型                                 | 只读 | 可选 | 说明               |
| ------- | ------------------------------------ | ---- | ---- | ------------------ |
| state9+ | [AVRecorderState](arkts-apis-media-t.md#avrecorderstate9) | 是   | 否   | 音视频录制的状态。<br>**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。 |

## prepare<sup>9+</sup>

prepare(config: AVRecorderConfig, callback: AsyncCallback\<void>): void

准备录制。设置音视频录制的参数，并初始化录制上下文。使用callback异步回调。

需在idle状态下调用，调用成功后进入prepared状态，此时，纯音频录制可直接调用[start](#start9)接口开始录制；纯视频或音视频录制需先调用[getInputSurface](#getinputsurface9)接口获取surface，再调用[start](#start9)接口开始录制。

**需要权限：** ohos.permission.MICROPHONE

该权限为用户授权权限，需要通过调用requestPermissionsFromUser()向用户申请。不涉及音频录制时，无需获取ohos.permission.MICROPHONE权限。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                  |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| config   | [AVRecorderConfig](arkts-apis-media-i.md#avrecorderconfig9) | 是   | 配置音视频录制的相关参数。            |
| callback | AsyncCallback\<void>                   | 是   | 回调函数。当prepare接口成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置参数以实际硬件设备支持的范围为准。
let avRecorderProfile: media.AVRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
};
let videoMetaData: media.AVMetadata = {
  videoOrientation: '0' // 合理值0、90、180、270，非合理值prepare接口报错。
};
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://', // 文件需先通过fs.open接口（@kit.FileKit）打开获取文件描述符fd，赋予读写权限，将fd传给此参数，详见文件管理开发指导。
  metadata: videoMetaData,
  location : { latitude : 30, longitude : 130 }
};

avRecorder.prepare(avRecorderConfig, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to prepare and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in preparing');
  }
});
```

## prepare<sup>9+</sup>

prepare(config: AVRecorderConfig): Promise\<void>

准备录制。设置音视频录制的参数，并初始化录制上下文。使用Promise异步回调。

需在idle状态下调用，调用成功后进入prepared状态，此时，纯音频录制可直接调用[start](#start9)接口开始录制；纯视频或音视频录制需先调用[getInputSurface](#getinputsurface9)接口获取surface，再调用[start](#start9)接口开始录制。

**需要权限：** ohos.permission.MICROPHONE

该权限为用户授权权限，需要通过调用requestPermissionsFromUser()向用户申请。不涉及音频录制时，无需获取ohos.permission.MICROPHONE权限。


**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| config | [AVRecorderConfig](arkts-apis-media-i.md#avrecorderconfig9) | 是   | 配置音视频录制的相关参数。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 配置参数以实际硬件设备支持的范围为准。
let avRecorderProfile: media.AVRecorderProfile = {
  audioBitrate : 48000,
  audioChannels : 2,
  audioCodec : media.CodecMimeType.AUDIO_AAC,
  audioSampleRate : 48000,
  fileFormat : media.ContainerFormatType.CFT_MPEG_4,
  videoBitrate : 2000000,
  videoCodec : media.CodecMimeType.VIDEO_AVC,
  videoFrameWidth : 640,
  videoFrameHeight : 480,
  videoFrameRate : 30
};
let videoMetaData: media.AVMetadata = {
  videoOrientation: '0' // 合理值0、90、180、270，非合理值prepare接口报错。
};
let avRecorderConfig: media.AVRecorderConfig = {
  audioSourceType : media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile : avRecorderProfile,
  url : 'fd://',  // 文件需先通过fileIo.open接口（@kit.CoreFileKit）打开获取文件描述符fd，赋予读写权限，将fd传给此参数。
  metadata : videoMetaData,
  location : { latitude : 30, longitude : 130 }
};

avRecorder.prepare(avRecorderConfig).then(() => {
  console.info('Succeeded in preparing');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to prepare and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## addWatermark

addWatermark(watermark: image.PixelMap, config: WatermarkConfiguration): Promise\<number>

添加自定义水印图像到录制视频中。适用于需要在录制视频中嵌入品牌标识、版权信息或时间戳等水印的场景。使用Promise异步回调。

需在idle状态下调用。

> **说明：**
>
> - 应用最多可添加5个水印。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| watermark | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | 是   | 水印图像。该图像将作为水印叠加到录制的视频中。 |
| config | [WatermarkConfiguration](arkts-apis-media-i.md#watermarkconfiguration) | 是   | 配置视频录制水印的相关参数。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<number> | Promise对象，返回所添加水印的编号，取值范围[1, 5]。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise.  |
| 5400103  | IO error. Return by promise.    |
| 5400105  | Service died. Return by promise. |
| 5400108  | The parameter check failed, parameter value out of range.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';

let watermark: image.PixelMap | undefined = undefined; // 通过image.createImageSource创建ImageSource对象后调用createPixelMap接口（@kit.ImageKit）获取PixelMap。水印图像不能为空。
let watermarkConfig: media.WatermarkConfiguration = { top: 100, left: 100, width: 100, height: 100 };

if (watermark) {
    avRecorder.addWatermark(watermark, watermarkConfig).then((num: number) => {
      console.info(`Succeeded in adding watermark, watermarkNum is ${num}`);
    })
    .catch((error: BusinessError) => {
      console.error(`Failed to add watermark and catch error is: Code: ${error.code}, message: ${error.message}`);
    });
}
```

## getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void

获得录制需要的surface。使用callback异步回调。

需在prepared状态下调用。

开发者从此surface中获取surfaceBuffer，填入待录制的视频数据。

应当注意，填入的视频数据需要携带时间戳（单位ns）和buffer size。时间戳的起始时间请以系统启动时间为基准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | 是   | 回调函数。当获取surface成功，err为undefined，data为获取到的surfaceId，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let inputSurfaceId: string; // 该inputSurfaceId用于传递给相机接口创建videoOutput。

avRecorder.getInputSurface((err: BusinessError, surfaceId: string) => {
  if (err) {
    console.error(`Failed to do getInputSurface and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in doing getInputSurface');
    inputSurfaceId = surfaceId;
  }
});

```

## getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>

获得录制需要的surface。使用Promise异步回调。

需在prepared状态下调用。

开发者从此surface中获取surfaceBuffer，填入待录制的视频数据。填入的视频数据需要携带时间戳（单位ns）和buffer size，时间戳的起始时间以系统启动时间为基准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<string> | Promise对象，返回surface中获取的surfaceBuffer。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let inputSurfaceId: string; // 该inputSurfaceId用于传递给相机接口创建videoOutput。

avRecorder.getInputSurface().then((surfaceId: string) => {
  console.info('Succeeded in getting InputSurface');
  inputSurfaceId = surfaceId;
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to get InputSurface and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## updateRotation<sup>12+</sup>

updateRotation(rotation: number): Promise\<void>

更新视频旋转角度。适用于设备方向发生变化（如横竖屏切换）时需要动态调整录制视频旋转角度的场景。使用Promise异步回调。

需在prepared状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                        |
| -------- | -------------------- | ---- | --------------------------- |
| rotation | number | 是   | 旋转角度，单位为度（°）。取值仅支持0°、90°、180°和270°。传入不支持的角度值时，返回错误码401。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
|   401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.   |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rotation = 90;

avRecorder.updateRotation(rotation).then(() => {
  console.info('Succeeded in doing updateRotation');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to do updateRotation and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## setMetadata

setMetadata(metadata: Record&lt;string, string&gt;): void

设置录制的元数据信息。适用于需要在录制文件中嵌入自定义元数据（如作者、标题、标签等）的场景。如果metadata参数与config.metadata.customInfo（参考[prepare()](#prepare9-1)和[AVRecorderConfig](arkts-apis-media-i.md#avrecorderconfig9)）中存在相同的键，前者的对应值将覆盖后者。

需在prepared/started/paused状态下调用。

**起始版本：** 26.0.0

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |---------------- | ------ |---------------------------------------------------------|
| metadata | Record&lt;string, string&gt; | 是  | 录制的元数据信息。<br>格式为字符串键值对，其中，键需要以`com.openharmony.`开头，否则设置不生效；值的长度范围为0-256个字节，否则返回错误码5400108。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400101  | No memory. |
| 5400102  | Operation not allowed. |
| 5400108  | Parameter check failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let metadata: Record<string, string> = {
  'com.openharmony.userdefine': '10',
  'com.openharmony.userdefine2': '20'
};

try {
  avRecorder.setMetadata(metadata);
  console.info('set metadata successfully');
} catch (err) {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to set metadata. Code: ${error.code}, message: ${error.message}`);
}
```

## setWillMuteWhenInterrupted<sup>20+</sup>

setWillMuteWhenInterrupted(muteWhenInterrupted: boolean): Promise&lt;void&gt;

设置当前录制音频流是否启用静音打断模式。启用后，录制音频流被更高优先级音频打断时将录制静音而非停止录制，适用于需要在打断期间保持录制连续性的场景（如会议录音、语音备忘）。不启用则保持默认打断模式（音频流被打断时停止录制）。使用Promise异步回调。

需在idle状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |---------------- | ------ |---------------------------------------------------------|
| muteWhenInterrupted | boolean | 是  | 设置当前录制音频流是否启用静音打断模式, true表示启用，false表示不启用，保持为默认打断模式。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt;| Promise对象，无返回结果。|

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.setWillMuteWhenInterrupted(true).then(() => {
  console.info('Succeeded in doing setWillMuteWhenInterrupted');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to do setWillMuteWhenInterrupted and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## start<sup>9+</sup>

start(callback: AsyncCallback\<void>): void

开始录制。使用callback异步回调。

需在prepared状态下调用，调用成功后进入started状态。录制视频时，还需在[getInputSurface](#getinputsurface9)接口调用成功后，才能调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   |回调函数。如果开始录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start((err: BusinessError) => {
  if (err) {
    console.error(`Failed to start AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in starting AVRecorder');
  }
});
```

## start<sup>9+</sup>

start(): Promise\<void>

开始录制。使用Promise异步回调。

需在prepared状态下调用，调用成功后进入started状态。录制视频时，还需在[getInputSurface](#getinputsurface9-1)接口调用成功后，才能调用此接口。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.start().then(() => {
  console.info('Succeeded in starting AVRecorder');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to start AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

暂停录制。使用callback异步回调。

需在started状态下调用，调用成功后进入paused状态，之后可以通过调用[resume](#resume9)接口来恢复录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                        |
| -------- | -------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。如果暂停录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause((err: BusinessError) => {
  if (err) {
    console.error(`Failed to pause AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in pausing');
  }
});
```

## pause<sup>9+</sup>

pause(): Promise\<void>

暂停录制。使用Promise异步回调。

需在started状态下调用，调用成功后进入paused状态，之后可以通过调用[resume](#resume9-1)接口来恢复录制。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.pause().then(() => {
  console.info('Succeeded in pausing');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to pause AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## resume<sup>9+</sup>

resume(callback: AsyncCallback\<void>): void

恢复录制。使用callback异步回调。

需在paused状态下调用，调用成功后进入started状态，之后可以再次调用[pause](#pause9)接口暂停录制，或调用[stop](#stop9)接口停止录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。如果恢复录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume((err: BusinessError) => {
  if (err) {
    console.error(`Failed to resume AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in resuming AVRecorder');
  }
});
```

## resume<sup>9+</sup>

resume(): Promise\<void>

恢复录制。使用Promise异步回调。

需在paused状态下调用，调用成功后进入started状态，之后可以再次调用[pause](#pause9-1)接口暂停录制，或调用[stop](#stop9-1)接口停止录制。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.resume().then(() => {
  console.info('Succeeded in resuming AVRecorder');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to resume AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

停止录制。使用callback异步回调。

需在started/paused状态下调用，调用成功后进入stopped状态。

纯音频录制时，需要重新调用[prepare](#prepare9)接口才能重新录制；纯视频录制、音视频录制时，需要重新调用[prepare](#prepare9)和[getInputSurface](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。如果停止录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop((err: BusinessError) => {
  if (err) {
    console.error(`Failed to stop AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in stopping AVRecorder');
  }
});
```

## stop<sup>9+</sup>

stop(): Promise\<void>

停止录制。使用Promise异步回调。

需在started/paused状态下调用，调用成功后进入stopped状态。

纯音频录制时，需要重新调用[prepare](#prepare9-1)接口才能重新录制；纯视频录制、音视频录制时，需要重新调用[prepare](#prepare9-1)和[getInputSurface](#getinputsurface9-1)接口才能重新录制。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.stop().then(() => {
  console.info('Succeeded in stopping AVRecorder');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to stop AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

重置音视频录制，将录制器恢复至初始状态以便重新配置参数。使用callback异步回调。

需在idle/prepared/started/paused/stopped/error状态下调用，调用成功后进入idle状态。

纯音频录制时，需要重新调用[prepare](#prepare9)接口才能重新录制；纯视频录制、音视频录制时，需要重新调用[prepare](#prepare9)和[getInputSurface](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                           |
| -------- | -------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当重置音视频录制成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset((err: BusinessError) => {
  if (err) {
    console.error(`Failed to reset AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in resetting AVRecorder');
  }
});
```

## reset<sup>9+</sup>

reset(): Promise\<void>

重置音视频录制，将录制器恢复至初始状态以便重新配置参数。使用Promise异步回调。

需在idle/prepared/started/paused/stopped/error状态下调用，调用成功后进入idle状态。

纯音频录制时，需要重新调用[prepare](#prepare9-1)接口才能重新录制；纯视频录制、音视频录制时，需要重新调用[prepare](#prepare9-1)和[getInputSurface](#getinputsurface9-1)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.reset().then(() => {
  console.info('Succeeded in resetting AVRecorder');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to reset AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

释放音视频录制资源。使用callback异步回调。

需在idle/prepared/started/paused/stopped/error状态下调用，调用成功后进入released状态。

与[createAVRecorder](arkts-apis-media-f.md#mediacreateavrecorder9)配对使用，录制流程结束后应调用此接口释放资源。释放音视频录制资源之后，该AVRecorder实例不能再进行任何操作。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                 | 必填 | 说明                               |
| -------- | -------------------- | ---- | ---------------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当释放音视频录制资源成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release((err: BusinessError) => {
  if (err) {
    console.error(`Failed to release AVRecorder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in releasing AVRecorder');
  }
});
```

## release<sup>9+</sup>

release(): Promise\<void>

释放音视频录制资源。使用Promise异步回调。

需在idle/prepared/started/paused/stopped/error状态下调用，调用成功后进入released状态。

与[createAVRecorder](arkts-apis-media-f.md#mediacreateavrecorder9)配对使用，录制流程结束后应调用此接口释放资源。释放音视频录制资源之后，该AVRecorder实例不能再进行任何操作。

**原子化服务API：** 从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.release().then(() => {
  console.info('Succeeded in releasing AVRecorder');
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to release AVRecorder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(callback: AsyncCallback\<audio.AudioCapturerChangeInfo>): void

获取当前音频采集参数。适用于需要确认当前音频采集设备类型或验证音频配置的场景。使用callback异步回调。

需在prepared/started/paused状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                 |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------ |
| callback | AsyncCallback\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiocapturerchangeinfo9)> | 是   | 回调函数。当获取音频采集参数成功时，err为undefined，data为获取到的audio.AudioCapturerChangeInfo，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.             |
| 5400105  | Service died. Return by callback.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit';

let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo((err: BusinessError, capturerInfo: audio.AudioCapturerChangeInfo) => {
  if (err) {
    console.error(`Failed to get CurrentAudioCapturerInfo and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in getting CurrentAudioCapturerInfo');
    currentCapturerInfo = capturerInfo;
  }
});
```

## getCurrentAudioCapturerInfo<sup>11+</sup>

getCurrentAudioCapturerInfo(): Promise\<audio.AudioCapturerChangeInfo>

获取当前音频采集参数。适用于需要确认当前音频采集设备类型或验证音频配置的场景。使用Promise异步回调。

需在prepared/started/paused状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型                                                         | 说明                                              |
| ------------------------------------------------------------ | ------------------------------------------------- |
| Promise\<[audio.AudioCapturerChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiocapturerchangeinfo9)> | Promise对象，返回获取的当前音频采集参数。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400103  | I/O error.                       |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { audio } from '@kit.AudioKit';

let currentCapturerInfo: audio.AudioCapturerChangeInfo;

avRecorder.getCurrentAudioCapturerInfo().then((capturerInfo: audio.AudioCapturerChangeInfo) => {
  console.info('Succeeded in getting CurrentAudioCapturerInfo');
  currentCapturerInfo = capturerInfo;
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to get CurrentAudioCapturerInfo and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(callback: AsyncCallback\<number>): void

获取当前音频最大振幅。适用于需要实时监控音频振幅的场景，如录音音量可视化显示、音频质量检测等。使用callback异步回调。

需在prepared/started/paused状态下调用。

调用接口时，获取到的返回值是上一次获取最大振幅的时刻到当前这段区间内的音频最大振幅。例如，在1s时获取了一次最大振幅，到2s时再获取到的最大振幅是1-2s这个区间内的最大值。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                 |
| -------- | ---------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<number> | 是   |  回调函数。获取当前音频最大振幅成功时，err为undefined，data为获取到的最大振幅，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400105  | Service died. Return by callback.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude((err: BusinessError, amplitude: number) => {
  if (err) {
    console.error(`Failed to get AudioCapturerMaxAmplitude and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in getting AudioCapturerMaxAmplitude');
    maxAmplitude = amplitude;
  }
});
```

## getAudioCapturerMaxAmplitude<sup>11+</sup>

getAudioCapturerMaxAmplitude(): Promise\<number>

获取当前音频最大振幅。适用于需要实时监控音频振幅的场景，如录音音量可视化显示、音频质量检测等。使用Promise异步回调。

需在prepared/started/paused状态下调用。

调用接口时，获取到的返回值是上一次获取最大振幅的时刻到当前这段区间内的音频最大振幅。例如，在1s时获取了一次最大振幅，到2s时再获取到的最大振幅是1-2s这个区间里面的最大值。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型             | 说明                                              |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | Promise对象，返回获取的当前音频最大振幅。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let maxAmplitude: number;

avRecorder.getAudioCapturerMaxAmplitude().then((amplitude: number) => {
  console.info('Succeeded in getting AudioCapturerMaxAmplitude');
  maxAmplitude = amplitude;
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to get AudioCapturerMaxAmplitude and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(callback: AsyncCallback\<Array\<EncoderInfo>>): void

获取可用的编码器参数。使用callback异步回调。

需在idle/prepared/started/paused/stopped状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                                                  | 必填 | 说明                                 |
| -------- | ----------------------------------------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<Array\<[EncoderInfo](arkts-apis-media-i.md#encoderinfo11)>> | 是   | 回调函数。获取可用的编码器参数成功时，err为undefined，data为获取到的编码器参数，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. |
| 5400105  | Service died. Return by callback.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder((err: BusinessError, info: media.EncoderInfo[]) => {
  if (err) {
    console.error(`Failed to get AvailableEncoder and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in getting AvailableEncoder');
    if (info.length > 0) {
      encoderInfo = info[0];
    } else {
      console.error('No available encoder');
    }
  }
});
```

## getAvailableEncoder<sup>11+</sup>

getAvailableEncoder(): Promise\<Array\<EncoderInfo>>

获取可用的编码器参数。使用Promise异步回调。

需在idle/prepared/started/paused/stopped状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型                                            | 说明                                            |
| ----------------------------------------------- | ----------------------------------------------- |
| Promise\<Array\<[EncoderInfo](arkts-apis-media-i.md#encoderinfo11)>> | Promise对象，返回获取的可用的编码器参数。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed.           |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let encoderInfo: media.EncoderInfo;

avRecorder.getAvailableEncoder().then((info: media.EncoderInfo[]) => {
  console.info('Succeeded in getting AvailableEncoder');
    if (info.length > 0) {
      encoderInfo = info[0];
    } else {
      console.error('No available encoder');
    }
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to get AvailableEncoder and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(callback: AsyncCallback\<AVRecorderConfig>): void

获取实时的配置参数。适用于需要确认录制配置是否正确应用的场景，如调试录制参数、验证配置生效情况等。使用callback异步回调。

需在prepared/started/paused/stopped状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<[AVRecorderConfig](arkts-apis-media-i.md#avrecorderconfig9)> | 是   | 回调函数。获取实时配置的参数成功时，err为undefined，data为获取到的配置参数，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avRecorderConfig: media.AVRecorderConfig;

avRecorder.getAVRecorderConfig((err: BusinessError, config: media.AVRecorderConfig) => {
  if (err) {
    console.error(`Failed to get avRecorderConfig and error is: Code: ${err.code}, message: ${err.message}`);
  } else {
    console.info('Succeeded in getting AVRecorderConfig');
    avRecorderConfig = config;
  }
});
```

## getAVRecorderConfig<sup>11+</sup>

getAVRecorderConfig(): Promise\<AVRecorderConfig>;

获取实时的配置参数。适用于需要确认录制配置是否正确应用的场景，如调试录制参数、验证配置生效情况等。使用Promise异步回调。

需在prepared/started/paused/stopped状态下调用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<[AVRecorderConfig](arkts-apis-media-i.md#avrecorderconfig9)> | Promise对象。返回实时配置参数。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.             |
| 5400105  | Service died. Return by promise.          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let avRecorderConfig: media.AVRecorderConfig;

avRecorder.getAVRecorderConfig().then((config: media.AVRecorderConfig) => {
  console.info('Succeeded in getting AVRecorderConfig');
  avRecorderConfig = config;
}).catch((err: Error) => {
  let error: BusinessError = err as BusinessError;
  console.error(`Failed to get AVRecorderConfig and error is: Code: ${error.code}, message: ${error.message}`);
});
```

## on('stateChange')<sup>9+</sup>

on(type: 'stateChange', callback: OnAVRecorderStateChangeHandler): void

订阅录制状态机AVRecorderState切换的事件，当AVRecorderState状态机发生变化时，会通过订阅的回调方法通知用户。用户只能订阅一个录制状态机切换事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 录制状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback | [OnAVRecorderStateChangeHandler](arkts-apis-media-t.md#onavrecorderstatechangehandler12) | 是   | 回调函数，用于接收录制状态机切换事件。回调参数包括：state（录制状态，类型为AVRecorderState）和reason（状态切换原因，类型为StateChangeReason）。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
  console.info('case state has changed, new state is: ' + state + ', and reason is: ' + reason);
});
```

## off('stateChange')<sup>9+</sup>

off(type: 'stateChange', callback?: OnAVRecorderStateChangeHandler): void

取消订阅录制状态机[AVRecorderState](arkts-apis-media-t.md#avrecorderstate9)切换的事件。使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录制状态机切换事件回调类型，支持的事件：'stateChange'，用户操作和系统都会触发此事件。 |
| callback<sup>12+</sup> | [OnAVRecorderStateChangeHandler](arkts-apis-media-t.md#onavrecorderstatechangehandler12) | 否   | 回调函数，用于接收录制状态机切换事件。如果指定参数则取消对应callback（callback对象不能是匿名函数），否则取消所有callback。<br>从API version 12开始支持此参数。 |

**示例：**

```ts
avRecorder.off('stateChange');
```

## on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅AVRecorder的错误事件，该事件仅用于错误提示，不需要用户停止录制操作。如果此时[AVRecorderState](arkts-apis-media-t.md#avrecorderstate9)也切换至error状态，用户需要通过[reset](#reset9)或者[release](#release9)接口退出录制操作。使用callback异步回调。

用户只能订阅一个错误事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 回调函数，用于接收录制错误事件。回调参数为err（错误对象，类型为BusinessError，包含错误码code和错误信息message）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 201      | Permission denied.     |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 801      | Capability not supported. |
| 5400101  | No memory.             |
| 5400102  | Operation not allowed. |
| 5400103  | I/O error.             |
| 5400104  | Time out.              |
| 5400105  | Service died.          |
| 5400106  | Unsupported format.    |
| 5400107  | Audio interrupted. <br>适用版本：11+     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avRecorder.on('error', (err: BusinessError) => {
  console.error(`Failed to record. Code: ${err.code}, message: ${err.message}`);
});
```

## off('error')<sup>9+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅录制错误事件，取消后不再接收到AVRecorder的错误事件。使用callback异步回调。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录制错误事件回调类型'error'。 <br>- 'error'：录制过程中发生错误，触发该事件。 |
| callback<sup>12+</sup> | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 回调函数，用于接收录制错误事件。如果指定参数则取消对应callback（callback对象不能是匿名函数），否则取消所有callback。<br>从API version 12开始支持此参数。                   |

**示例：**

```ts
avRecorder.off('error');
```

## on('audioCapturerChange')<sup>11+</sup>

on(type: 'audioCapturerChange', callback: Callback<audio.AudioCapturerChangeInfo>): void

订阅录音配置变化的回调，任意录音配置的变化会触发变化后的录音配置全量信息回调。使用callback异步回调。

用户只能订阅一个录音配置变化事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 录音配置变化的回调类型，支持的事件：'audioCapturerChange'。 |
| callback | Callback<[audio.AudioCapturerChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiocapturerchangeinfo9)> | 是 | 回调函数，用于接收变化后的录音配置全量信息。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed.      |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let capturerChangeInfo: audio.AudioCapturerChangeInfo;

avRecorder.on('audioCapturerChange',  (audioCapturerChangeInfo: audio.AudioCapturerChangeInfo) => {
  console.info('audioCapturerChange called');
  capturerChangeInfo = audioCapturerChangeInfo;
});
```

## off('audioCapturerChange')<sup>11+</sup>

off(type: 'audioCapturerChange', callback?: Callback<audio.AudioCapturerChangeInfo>): void

取消订阅录音配置变化的回调事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 录音配置变化的回调类型，支持的事件：'audioCapturerChange'。 |
| callback<sup>12+</sup> | Callback<[audio.AudioCapturerChangeInfo](../apis-audio-kit/arkts-apis-audio-i.md#audiocapturerchangeinfo9)> | 否 | 回调函数，用于接收变化后的录音配置全量信息。如果指定参数则取消对应callback（callback对象不能是匿名函数），否则取消所有callback。<br>从API version 12开始支持此参数。|

**示例：**

```ts
avRecorder.off('audioCapturerChange');
```

## on('photoAssetAvailable')<sup>12+</sup>

on(type: 'photoAssetAvailable', callback: Callback\<photoAccessHelper.PhotoAsset>): void

订阅媒体资源回调事件，当[FileGenerationMode](arkts-apis-media-e.md#filegenerationmode12)枚举设置为系统创建媒体文件时，会在[stop](#stop9)操作结束后把[PhotoAsset](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md)对象回调给应用。使用callback异步回调。

用户只能订阅一个媒体资源回调事件的回调方法，当用户重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   |媒体资源的回调类型，支持的事件：'photoAssetAvailable'。 |
| callback | Callback<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md)> | 是 | 回调函数，用于接收系统创建的资源文件对应的PhotoAsset对象。需在prepare配置中将FileGenerationMode设置为系统创建媒体文件模式，stop结束后才会触发此回调。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400103  | IO error. Return by callback.             |
| 5400105  | Service died. Return by callback.          |

**示例：**

<!--code_no_check-->
```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
let photoAsset: photoAccessHelper.PhotoAsset;

// 例：处理photoAsset回调，保存video。
async function saveVideo(context: Context, asset: photoAccessHelper.PhotoAsset) {
  console.info('saveVideo called');
  try {
    let photoHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.saveCameraPhoto();
    await photoHelper.applyChanges(assetChangeRequest);
    console.info('apply saveVideo successfully');
  } catch (err) {
    let error: BusinessError = err as BusinessError;
    console.error(`Failed to apply saveVideo. Code: ${error.code}, message: ${error.message}`);
  }
}
// 注册photoAsset监听。
avRecorder.on('photoAssetAvailable', (asset: photoAccessHelper.PhotoAsset) => {
  console.info('photoAssetAvailable called');
  if (asset != undefined) {
    photoAsset = asset;
    // 处理photoAsset回调。
    // 例：this.saveVideo(context, asset);
  } else {
    console.error('photoAsset is undefined');
  }
});
```

## off('photoAssetAvailable')<sup>12+</sup>

off(type: 'photoAssetAvailable', callback?: Callback<photoAccessHelper.PhotoAsset>): void

取消订阅媒体资源的回调类型。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVRecorder

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 媒体资源创建完成的回调类型，支持的事件：'photoAssetAvailable'。 |
| callback | Callback<[photoAccessHelper.PhotoAsset](../apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md)> | 否 | 回调函数，用于接收系统创建的资源文件对应的PhotoAsset对象。如果指定参数则取消对应callback（callback对象不能是匿名函数），否则取消所有callback。|

**示例：**

```ts
avRecorder.off('photoAssetAvailable');
```