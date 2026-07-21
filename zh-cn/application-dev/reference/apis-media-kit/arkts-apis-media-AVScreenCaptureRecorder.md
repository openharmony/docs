# Interface (AVScreenCaptureRecorder)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

屏幕录制管理类，用于进行屏幕录制，支持录屏初始化、开始/暂停/恢复/停止录制、添加水印、隐私窗口豁免、麦克风开关控制、Picker模式选择和内容自动旋转等功能。适用于需要在应用内完成屏幕录制流程控制的场景，可帮助开发者灵活管理录屏生命周期、保护用户隐私并自定义录制输出。在调用AVScreenCaptureRecorder的方法前，需要先通过[createAVScreenCaptureRecorder()](arkts-apis-media-f.md#mediacreateavscreencapturerecorder12)创建一个AVScreenCaptureRecorder实例。

典型使用流程：createAVScreenCaptureRecorder → init → startRecording → pauseRecording/resumeRecording → stopRecording → release。

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 12开始支持。


## 导入模块

``` TypeScript
import { media } from '@kit.MediaKit';
```

## init<sup>12+</sup>

init(config: AVScreenCaptureRecordConfig): Promise\<void>

进行录屏初始化，设置录屏参数。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| config | [AVScreenCaptureRecordConfig](arkts-apis-media-i.md#avscreencapturerecordconfig12) | 是   | 配置屏幕录制的相关参数。关键配置项包括：fd（文件描述符）、frameWidth（视频宽度）、frameHeight（视频高度）等。详细配置说明请参考[AVScreenCaptureRecordConfig](arkts-apis-media-i.md#avscreencapturerecordconfig12)。文件需要先由调用者创建，通常是MP4文件，赋予写权限，将文件fd传给此参数。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示初始化成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. Return by promise. Suggestion: Please check that all required parameters are correctly passed and their types conform to the interface requirements. |
| 5400103  | IO error. Return by promise. Possible cause: File path does not exist, insufficient read/write permissions, or insufficient storage space. Suggestion: Please check the file path, permissions, and available storage space.                  |
| 5400105  | Service died. Return by promise. Possible cause: System service terminated unexpectedly. Suggested action: Please release resources and retry. If the issue persists, restart the application.              |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';
import { fileIo } from '@kit.CoreFileKit';

async function testInit() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 创建文件。
  let filesDir = '/data/storage/el2/base/haps';
  let file = fileIo.openSync(filesDir + '/screenCapture.mp4', fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);

  let avCaptureConfig: media.AVScreenCaptureRecordConfig = {
      fd: file.fd, // 文件需要先由调用者创建，通常是MP4文件，赋予写权限，将文件fd传给此参数。
      frameWidth: 640,
      frameHeight: 480
      // 补充其他参数。
  };

  // 调用init方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.init(avCaptureConfig).then(() => {
      console.info('Succeeded in initializing avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to init avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## startRecording<sup>12+</sup>

startRecording(): Promise\<void>

开始录屏，在使用前需要先调用[init](#init12)接口。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示开始录屏成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testStartRecording() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用startRecording方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.startRecording().then(() => {
      console.info('Succeeded in starting avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to start avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## stopRecording<sup>12+</sup>

stopRecording(): Promise\<void>

结束录屏。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示结束录屏成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testStopRecording() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用stopRecording方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.stopRecording().then(() => {
      console.info('Succeeded in stopping avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to stop avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## pauseRecording

pauseRecording(): Promise\<void>

暂停录屏。使用Promise异步回调。在录制过程中需要临时中断录制时调用此接口，例如用户临时离开或需要切换应用时。

在使用前需要先调用[startRecording](arkts-apis-media-AVScreenCaptureRecorder.md#startrecording12)接口且录屏需处于录制状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示暂停录屏成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                        |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed. Return by promise. Possible cause: This operation is not allowed in the current state (e.g., pausing before initialization). Suggestion: Please ensure the interfaces are called in the correct sequence. |
| 5400103  | IO error. Return by promise. Possible cause: File path does not exist, insufficient read/write permissions, or insufficient storage space. Suggestion: Please check the file path, permissions, and available storage space.    |
| 5400105  | Service died. Return by promise. Possible cause: System service terminated unexpectedly. Suggested action: Please release resources and retry. If the issue persists, restart the application. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testPauseRecording() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用pauseRecording方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.pauseRecording().then(() => {
      console.info('Succeeded in pausing avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to pause avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## resumeRecording

resumeRecording(): Promise\<void>

恢复录屏。使用Promise异步回调。

在使用前需要先调用[pauseRecording](arkts-apis-media-AVScreenCaptureRecorder.md#pauserecording)接口且录屏需处于暂停状态。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型          | 说明                             |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示恢复录屏成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                        |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed. Return by promise. Possible cause: This operation is not allowed in the current state (e.g., pausing before pauseRecording). Suggestion: Please ensure the interfaces are called in the correct sequence. |
| 5400103  | IO error. Return by promise. Possible cause: File path does not exist, insufficient read/write permissions, or insufficient storage space. Suggestion: Please check the file path, permissions, and available storage space.     |
| 5400105  | Service died. Return by promise. Possible cause: System service terminated unexpectedly. Suggested action: Please release resources and retry. If the issue persists, restart the application. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testResumeRecording() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用resumeRecording方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.resumeRecording().then(() => {
      console.info('Succeeded in resuming avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to resume avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## addWatermark

addWatermark(watermark: image.PixelMap, config: WatermarkConfiguration): Promise\<number>

在录制的视频中添加自定义水印图像。使用Promise异步回调。

> **说明：**
>
> - 应用最多可添加5个水印。
>
> - 需在[startRecording](#startrecording12)接口调用前调用addWatermark接口。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| watermark | [image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)  | 是   | 水印图像，取值原则：PixelMap对象不能为空。支持透明度设置。图像格式和尺寸要求请参考[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)。 |
| config | [WatermarkConfiguration](arkts-apis-media-i.md#watermarkconfiguration) | 是   | 配置视频录制水印的相关参数。各字段取值范围请参考WatermarkConfiguration定义。需在调用startRecording接口前设置。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<number> | Promise对象，返回所添加水印的编号ID表示添加水印成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. Possible cause: Called before startRecording or exceeded 5 watermarks. Suggestion: Please ensure proper timing of the call, and keep watermark count within 5. |
| 5400103  | IO error. Return by promise. Possible cause: Watermark image resource unavailable or insufficient storage space. Suggestion: Please check watermark image validity and storage space.    |
| 5400105  | Service died. Return by promise. Possible cause: System service terminated abnormally. Suggestion: Please release resources and retry. If the problem persists, restart the application. |
| 5400108  | The parameter check failed, parameter value out of range. Possible cause: Watermark configuration parameters out of valid range. Suggestion: Please check if top, left, width, height parameter values are valid.    |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { image } from '@kit.ImageKit';
import { media } from '@kit.MediaKit';

async function testAddWaterMark() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  let watermark: image.PixelMap | undefined = undefined; // 可以通过获取本地资源文件并转换为PixelMap，水印图像不能为空。
  let watermarkConfig: media.WatermarkConfiguration = { top: 100, left: 100, width: 100, height: 100 };

  if (watermark && avScreenCaptureRecorder) {
    avScreenCaptureRecorder.addWatermark(watermark, watermarkConfig).then((num: number) => {
      console.info(`Succeeded in adding watermark, watermarkNum is ${num}`);
    })
    .catch((error: BusinessError) => {
      console.error(`Failed to add watermark and catch error is: Code: ${error.code}, message: ${error.message}`);
    });
  }
}
```

## skipPrivacyMode<sup>12+</sup>

skipPrivacyMode(windowIDs: Array\<number>): Promise\<void>

录屏时，应用可对本应用的隐私窗口做安全豁免。使用Promise异步回调。

如录屏时，用户在本应用进行输入密码等操作，应用不会进行黑屏处理。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| windowIDs | Array\<number> | 是   | 需要豁免隐私的窗口列表，包括主窗口id和子窗口id，窗口属性获取方法可以参考[getWindowProperties](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)。 |

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示设置隐私豁免成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testSkipPrivacyMode() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用skipPrivacyMode方法。
  if (avScreenCaptureRecorder) {
    let windowIDs = [];
    avScreenCaptureRecorder.skipPrivacyMode(windowIDs).then(() => {
      console.info('Succeeded in skipping privacy mode');
    }).catch((err: BusinessError) => {
      console.error(`Failed to skip privacy mode. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## setMicEnabled<sup>12+</sup>

setMicEnabled(enable: boolean): Promise\<void>

设置麦克风开关。使用Promise异步回调。

> **说明：**
>
> - 在需要录制或静音麦克风音频时调用此接口，例如用户需要临时关闭麦克风或重新开启麦克风录制。
> - 需在[startRecording](arkts-apis-media-AVScreenCaptureRecorder.md#startrecording12)接口调用前调用此接口。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| enable | boolean | 是   | 麦克风开关控制，true代表麦克风打开，false代表麦克风关闭。 |

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示设置麦克风开关成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testSetMicEnable() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用setMicEnabled方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.setMicEnabled(true).then(() => {
      console.info('Succeeded in setting microphone enabled.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set microphone enabled. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## setPickerMode<sup>22+</sup>

setPickerMode(pickerMode: PickerMode): Promise\<void>

设置Picker显示模式，在下一次显示Picker时生效。使用Promise异步回调。

可根据录制需求选择不同模式，SCREEN_ONLY适用于只需要录制整个屏幕的场景；WINDOW_ONLY适用于只需要录制特定应用窗口的场景；SCREEN_AND_WINDOW适用于需要让用户自由选择录制屏幕或窗口的场景。


**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| pickerMode | [PickerMode](arkts-apis-media-e.md#pickermode22) | 是   | 选择Picker模式。 |

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示设置Picker显示模式成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testSetPickerMode() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用setPickerMode方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.setPickerMode(media.PickerMode.WINDOW_ONLY).then(() => {
      console.info('Succeeded in setting picker mode.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to set picker mode. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## excludePickerWindows<sup>22+</sup>

excludePickerWindows(excludedWindows: Array\<number>): Promise\<void>

设置在Picker中隐藏的窗口列表，在下一次显示Picker时生效。使用Promise异步回调。

在需要排除特定窗口不被用户选择时调用此接口，例如隐藏应用自身窗口、隐私窗口或不相关的后台窗口。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| excludedWindows | Array\<number> | 是   | 需要在Picker中隐藏的窗口列表，窗口属性获取方法可以参考[getWindowProperties](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)。 |

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示设置隐藏窗口列表成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testExcludePickerWindows() {
  let excludedWindows: number[] = [101, 102, 103];
  
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用excludePickerWindows方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.excludePickerWindows(excludedWindows).then(() => {
      console.info('Succeeded in excluding picker windows.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to exclude picker windows. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## presentPicker<sup>22+</sup>

presentPicker(): Promise\<void>

录屏开始后，调用该接口再次弹出Picker，可动态更新录制源（窗口、屏幕）。使用Promise异步回调。

使用前需要先调用[startRecording](#startrecording12)接口。

> **说明：**
>
> - 更新录制源过程中，原录制流程不中断。
> - 通过Picker动态更新录制源后，按照新的录制源进行录制。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示弹出Picker成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testPresentPicker() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用presentPicker方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.presentPicker().then(() => {
      console.info('Succeeded in presenting picker avScreenCaptureRecorder.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to present picker avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```
## setContentAutoRotation

setContentAutoRotation(enable: boolean): Promise\<void>

设置捕获的屏幕内容是否自动旋转以保持图像直立。使用Promise异步回调。

> **说明：**
>
> 需在[startRecording](#startrecording12)接口调用前调用此接口。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| enable | boolean | 是   | 表示是否启用自动旋转，默认值为false。true表示启用自动旋转，输出帧中的图像内容将自动保持直立。false表示不启用自动旋转，输出帧中的图像内容将不自动保持直立。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 801  | Capability not supported. Return by promise.  |
| 5400102  | Operation not allowed. Return by promise.    |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testSetContentAutoRotation() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用setContentAutoRotation方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.setContentAutoRotation(true).then(() => {
      console.info('Succeeded in enabling setContentAutoRotation.');
    }).catch((err: BusinessError) => {
      console.error(`Failed to enable setContentAutoRotation. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## release<sup>12+</sup>

release(): Promise\<void>

释放录屏。使用Promise异步回调。

在录屏功能不再使用时调用此接口释放资源，例如应用退出或录屏功能模块卸载时。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | Promise对象，无返回结果。无返回结果表示释放录屏成功，失败时返回错误码。 |

**错误码：**

以下错误码的详细介绍请参见[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testRelease() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用release方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.release().then(() => {
      console.info('Succeeded in releasing avScreenCaptureRecorder');
    }).catch((err: BusinessError) => {
      console.error(`Failed to release avScreenCaptureRecorder. Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## on('stateChange')<sup>12+</sup>

on(type: 'stateChange', callback: Callback\<AVScreenCaptureStateCode>): void

订阅录屏状态切换的事件，当状态发生变化时，会通过订阅的回调通知用户。用户只能订阅一个状态切换的回调方法，重复订阅时，以最后一次订阅的回调方法为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | Callback\<[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)> | 是   | 状态切换事件回调方法，[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)表示切换到的状态。 |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testOnStateChange() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用on方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.on('stateChange', (state: media.AVScreenCaptureStateCode) => {
        console.info('avScreenCaptureRecorder stateChange to ' + state);
    });
  }
}
```

## on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅AVScreenCaptureRecorder的错误事件，用户可以根据应用自身逻辑对错误事件进行处理。用户只能订阅一个错误事件的回调方法，重复订阅时，以最后一次订阅的回调方法为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型          | 必填 | 说明                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 错误事件回调类型，支持的事件：'error'。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 录屏错误事件回调方法。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Media错误码](errorcode-media.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 201      | permission denied. Possible cause: Missing required permissions. Suggestion: Please check and apply for the necessary permissions.     |
| 5400103  | IO error. Return by ErrorCallback. Possible cause: System I/O operation failed. Suggestion: Please retry the operation. If the issue persists, restart the application. |
| 5400105  | Service died. Return by ErrorCallback. Possible cause: System service terminated unexpectedly. Suggestion: Please release resources and retry. If the issue persists, restart the application. |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testOnError() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用on方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.on('error', (err: BusinessError) => {
      console.error(`avScreenCaptureRecorder error: Code: ${err.code}, message: ${err.message}`);
    });
  }
}
```

## off('stateChange')<sup>12+</sup>

 off(type: 'stateChange', callback?: Callback\<AVScreenCaptureStateCode>): void

取消订阅状态切换回调事件。用户可以指定填入状态切换的回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | Callback\<[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)> | 否   | 状态切换事件回调方法，[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)表示切换到的状态，不填此参数则会取消最后一次订阅事件。 |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testOffStateChange() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用off方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.off('stateChange');
  }
}
```

## off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅错误回调事件。用户可以指定填入错误回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                       |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'。                |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 录屏错误事件回调方法，不填此参数则会取消最后一次订阅事件。 |

**示例：**

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';

async function testOffError() {
  // 创建录屏实例。
  let avScreenCaptureRecorder = await media.createAVScreenCaptureRecorder();

  // 其余流程。

  // 调用off方法。
  if (avScreenCaptureRecorder) {
    avScreenCaptureRecorder.off('error');
  }
}
```