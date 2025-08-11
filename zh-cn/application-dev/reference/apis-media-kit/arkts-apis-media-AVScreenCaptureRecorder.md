# Interface (AVScreenCaptureRecorder)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--SE: @stupig001-->
<!--TSE: @xdlinc-->

> **说明：**
>
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 12开始支持。

屏幕录制管理类，用于进行屏幕录制。在调用AVScreenCaptureRecorder的方法前，需要先通过[createAVScreenCaptureRecorder()](arkts-apis-media-f.md#mediacreateavscreencapturerecorder12)创建一个AVScreenCaptureRecorder实例。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## init<sup>12+</sup>

init(config: AVScreenCaptureRecordConfig): Promise\<void>

异步方式进行录屏初始化，设置录屏参数。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                     |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| config | [AVScreenCaptureRecordConfig](arkts-apis-media-i.md#avscreencapturerecordconfig12) | 是   | 配置屏幕录制的相关参数。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Promise\<void> | 异步录屏初始化方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                                       |
| -------- | ---------------------------------------------- |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. 3.Parameter verification failed. Return by promise. |
| 5400103  | IO error. Return by promise.                   |
| 5400105  | Service died. Return by promise.               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

public getFileFd(): number {
    let filesDir = '/data/storage/el2/base/haps';
    let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    return file.fd;
}

let avCaptureConfig: media.AVScreenCaptureRecordConfig = {
    fd: this.getFileFd(), // 文件需要先由调用者创建，通常是MP4文件，赋予写权限，将文件fd传给此参数。
    frameWidth: 640,
    frameHeight: 480
    // 补充其他参数。
};

avScreenCaptureRecorder.init(avCaptureConfig).then(() => {
    console.info('Succeeded in initing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to init avScreenCaptureRecorder, error: ' + err.message);
});
```

## startRecording<sup>12+</sup>

startRecording(): Promise\<void>

异步方式开始录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.startRecording().then(() => {
    console.info('Succeeded in starting avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to start avScreenCaptureRecorder, error: ' + err.message);
});
```

## stopRecording<sup>12+</sup>

stopRecording(): Promise\<void>

异步方式结束录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | 异步结束录屏方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.stopRecording().then(() => {
    console.info('Succeeded in stopping avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to stop avScreenCaptureRecorder, error: ' + err.message);
});
```

## skipPrivacyMode<sup>12+</sup>

skipPrivacyMode(windowIDs: Array\<number>): Promise\<void>

录屏时，应用可对本应用的隐私窗口做安全豁免。通过Promise获取返回值。
如录屏时，用户在本应用进行输入密码等操作，应用不会进行黑屏处理。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| windowIDs | Array\<number> | 是   | 需要豁免隐私的窗口列表，包括主窗口id和子窗口id，窗口属性获取方法可以参考[窗口API引用](../apis-arkui/arkts-apis-window-Window.md#getwindowproperties9)。 |

**返回值：**

| 类型           | 说明                             |
| -------------- | -------------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let windowIDs = [];
avScreenCaptureRecorder.skipPrivacyMode(windowIDs).then(() => {
    console.info('Succeeded in skipping privacy mode');
}).catch((err: BusinessError) => {
    console.info('Failed to skip privacy mode, error: ' + err.message);
});
```

## setMicEnabled<sup>12+</sup>

setMicEnabled(enable: boolean): Promise\<void>

异步方式设置麦克风开关。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名 | 类型    | 必填 | 说明                                                      |
| ------ | ------- | ---- | --------------------------------------------------------- |
| enable | boolean | 是   | 麦克风开关控制，true代表麦克风打开，false代表麦克风关闭。 |

**返回值：**

| 类型           | 说明                                    |
| -------------- | --------------------------------------- |
| Promise\<void> | 异步设置麦克风开关方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.setMicEnabled(true).then(() => {
    console.info('Succeeded in setMicEnabled avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Failed to setMicEnabled avScreenCaptureRecorder, error: ' + err.message);
});
```

## release<sup>12+</sup>

release(): Promise\<void>

异步方式释放录屏。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**返回值：**

| 类型           | 说明                              |
| -------------- | --------------------------------- |
| Promise\<void> | 异步释放录屏方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

avScreenCaptureRecorder.release().then(() => {
    console.info('Succeeded in releasing avScreenCaptureRecorder');
}).catch((err: BusinessError) => {
    console.info('Faile to release avScreenCaptureRecorder, error: ' + err.message);
});
```

## on('stateChange')<sup>12+</sup>

on(type: 'stateChange', callback: Callback\<AVScreenCaptureStateCode>): void

订阅录屏状态切换的事件，当状态发生的时候，会通过订阅的回调通知用户。用户只能订阅一个状态切换的回调方法，重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | function | 是   | 状态切换事件回调方法，[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)表示切换到的状态。 |

**示例：**

```ts
avScreenCaptureRecorder.on('stateChange', (state: media.AVScreenCaptureStateCode) => {
    console.info('avScreenCaptureRecorder stateChange to ' + state);
});
```

## on('error')<sup>12+</sup>

on(type: 'error', callback: ErrorCallback): void

订阅AVScreenCaptureRecorder的错误事件，用户可以根据应用自身逻辑对错误事件进行处理。用户只能订阅一个错误事件的回调方法，重复订阅时，以最后一次订阅的回调接口为准。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型          | 必填 | 说明                                    |
| -------- | ------------- | ---- | --------------------------------------- |
| type     | string        | 是   | 错误事件回调类型，支持的事件：'error'。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 录屏错误事件回调方法。                  |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体错误码](errorcode-media.md)。
| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 201      | permission denied.     |
| 5400103  | IO error. Return by ErrorCallback. |
| 5400105  | Service died. Return by ErrorCallback. |

**示例：**

```ts
avScreenCaptureRecorder.on('error', (err: BusinessError) => {
    console.error('avScreenCaptureRecorder error:' + err.message);
});
```

## off('stateChange')<sup>12+</sup>

 off(type: 'stateChange', callback?: Callback\<AVScreenCaptureStateCode>): void

取消订阅状态切换回调事件。用户可以指定填入状态切换的回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'stateChange'。            |
| callback | function | 否   | 状态切换事件回调方法，[AVScreenCaptureStateCode](arkts-apis-media-e.md#avscreencapturestatecode12)表示切换到的状态，不填此参数则会取消最后一次订阅事件。 |

**示例：**

```ts
avScreenCaptureRecorder.off('stateChange');
```

## off('error')<sup>12+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消订阅错误回调事件。用户可以指定填入错误回调方法来取消订阅。

**系统能力：** SystemCapability.Multimedia.Media.AVScreenCapture

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                       |
| -------- | -------- | ---- | ---------------------------------------------------------- |
| type     | string   | 是   | 状态切换事件回调类型，支持的事件：'error'。                |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 否   | 录屏错误事件回调方法，不填此参数则会取消最后一次订阅事件。 |

**示例：**

```ts
avScreenCaptureRecorder.off('error');
```