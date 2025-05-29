# systemTonePlayer (系统提示音播放器)(系统接口)

系统提示音播放器提供了短信提示音、通知提示音的播放、配置、获取信息等功能。

systemTonePlayer需要和[@ohos.multimedia.systemSoundManager](js-apis-systemSoundManager-sys.md)配合使用，才能完成管理系统提示音的功能。

> **说明：**
>
> - 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import { systemSoundManager } from '@kit.AudioKit';
```

## SystemToneOptions

提示音参数选项。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

| 名称        | 类型    | 必填 | 说明                                          |
| ----------- | ------- | ---- | --------------------------------------------- |
| muteAudio   | boolean | 否   | 是否静音，true表示静音，false表示正常发声。   |
| muteHaptics | boolean | 否   | 是否震动，true表示无振动，false表示正常振动。 |

## SystemTonePlayer

系统提示音播放器提供了短信提示音、通知提示音的播放、配置、获取信息等功能。在调用SystemTonePlayer的接口前，需要先通过[getSystemTonePlayer](js-apis-systemSoundManager-sys.md#getsystemtoneplayer11)创建实例。

### getTitle

getTitle(): Promise&lt;string&gt;

获取提示音标题。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明                                  |
| ------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回获取的系统提示音标题。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400103  | I/O error.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.getTitle().then((value: string) => {
  console.info(`Promise returned to indicate that the value of the system tone player title is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to get the system tone player title ${err}`);
});
```

### prepare

prepare(): Promise&lt;void&gt;

准备播放提示音。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 5400102  | Operation not allowed.              |
| 5400103  | I/O error.                          |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.prepare().then(() => {
  console.info(`Promise returned to indicate a successful prepareing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to prepareing system tone player. ${err}`);
});
```

### start

start(toneOptions?: SystemToneOptions): Promise&lt;number&gt;

开始播放提示音。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**需要权限：** ohos.permission.VIBRATE

**参数：**

| 参数名      | 类型                                    | 必填 | 说明             |
| ----------- | --------------------------------------- | ---- | ---------------- |
| toneOptions | [SystemToneOptions](#systemtoneoptions) | 否   | 系统提示音选项。 |

**返回值：**

| 类型    | 说明                      |
| ------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回streamID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                                                                                                    |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 201      | Permission denied.                                                                                          |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

class SystemToneOptions {
  muteAudio: boolean = false;
  muteHaptics: boolean = false;
}
let systemToneOptions: SystemToneOptions = {muteAudio: true, muteHaptics: false};

systemTonePlayer.start(systemToneOptions).then((value: number) => {
  console.info(`Promise returned to indicate that the value of the system tone player streamID is obtained ${value}.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### stop

stop(id: number): Promise&lt;void&gt;

停止播放提示音。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | ------------------------- |
| id     | number | 是   | Promise对象，返回streamID。 |

**返回值：**

| 类型    | 说明                                |
| ------- | ----------------------------------- |
| Promise&lt;void&gt; | Promise回调返回停止播放成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                                                                                                    |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let streamID: number = 0; //streamID为start方法返回的streamID,此处只做初始化。
systemTonePlayer.stop(streamID).then(() => {
  console.info(`Promise returned to indicate a successful stopping of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop system tone player. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

释放提示音播放器。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型    | 说明                            |
| ------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.release().then(() => {
  console.info(`Promise returned to indicate a successful releasing of system tone player.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release system tone player. ${err}`);
});
```

### setAudioVolumeScale<sup>13+</sup>

setAudioVolumeScale(scale: number): void

设置音频音量大小，无返回结果。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                 |
| ------ | ------ | ---- | ------------------------------------ |
| scale  | number | 是   | 音频音量大小，必须在[0, 1]之间取值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)、[媒体服务错误码](../apis-media-kit/errorcode-media.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息                                                                                                    |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700002 | Parameter check error, For example, value is out side [0, 1].                                                |

**示例：**

```ts
let scale: number = 0.5;
try {
  systemTonePlayer.setAudioVolumeScale(scale);
} catch (err) {
  console.error(`Failed to set audio volume scale. ${err}`);
}
```

### getAudioVolumeScale<sup>13+</sup>

getAudioVolumeScale(): number

获取当前音频音量大小，同步返回当前音量。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**


| 类型   | 说明         |
| ------ | ------------ |
| number | 当前音频音量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |

**示例：**

```ts
try {
  let scale: number = systemTonePlayer.getAudioVolumeScale();
  console.info(` get audio volume scale. ${scale}`);
} catch (err) {
  console.error(`Failed to get audio volume scale. ${err}`);
}
```

### getSupportedHapticsFeatures<sup>13+</sup>

getSupportedHapticsFeatures(): Promise&lt;Array&lt;systemSoundManager.ToneHapticsFeature&gt;&gt;

获取当前支持的振动风格。使用Promise异步回调。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                                                                                                                          | 说明                                                                                                                  |
|-----------------------------------------------------------------------------------------------------------------------------| --------------------------------------------------------------------------------------------------------------------- |
| Promise&lt;Array&lt;[systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13)&gt;&gt; | Promise对象，返回当前支持的振动风格。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**示例：**

```ts
try {
  let features: Array<systemSoundManager.ToneHapticsFeature> = await systemTonePlayer.getSupportedHapticsFeatures();
  console.info(` get supported haptics features. ${features}`);
} catch (err) {
  console.error(`Failed to get supported haptics features. ${err}`);
}
```

### setHapticsFeature<sup>13+</sup>

setHapticsFeature(hapticsFeature: systemSoundManager.ToneHapticsFeature): void

设置播放铃音时的振动风格。

调用本接口前，应该先调用[getSupportedHapticsFeatures](#getsupportedhapticsfeatures13)查询支持的振动风格，如果设置不支持的振动风格，则设置失败。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名         | 类型                                                                                              | 必填 | 说明             |
| -------------- |-------------------------------------------------------------------------------------------------| ---- | ---------------- |
| hapticsFeature | [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13) | 是   | 振动风格。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)、[媒体服务错误码](../apis-media-kit/errorcode-media.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息                                                                                                    |
| -------- | ----------------------------------------------------------------------------------------------------------- |
| 202      | Caller is not a system application.                                                                         |
| 401      | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102  | Operation not allowed.                                                                                      |
| 20700003 | Unsupported operation.                                                                                      |

**示例：**

```ts
try {
  let features: Array<systemSoundManager.ToneHapticsFeature> = await systemTonePlayer.getSupportedHapticsFeatures();
  if (features.lenght == 0) {
    return;
  }
  let feature: systemSoundManager.ToneHapticsFeature = features[0];
  systemTonePlayer.setHapticsFeature(feature);
  console.info(` set haptics feature success`);
} catch (err) {
  console.error(`Failed to set haptics feature. ${err}`);
}
```

### getHapticsFeature<sup>13+</sup>

getHapticsFeature(): systemSoundManager.ToneHapticsFeature

获取播放铃音时的振动风格，同步返回振动风格枚举值。

**系统接口：** 该接口为系统接口

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**返回值：**

| 类型                                                                                              | 说明     |
|-------------------------------------------------------------------------------------------------| -------- |
| [systemSoundManager.ToneHapticsFeature](js-apis-systemSoundManager-sys.md#tonehapticsfeature13) | 振动风格。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。


| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 202      | Caller is not a system application. |
| 20700003 | Unsupported operation.              |

**示例：**

```ts
try {
  let feature: systemSoundManager.ToneHapticsFeature = systemTonePlayer.getHapticsFeature();
  console.info(` get haptics feature success. ${features}`);
} catch (err) {
  console.error(`Failed to get haptics feature. ${err}`);
}
```

### on('playFinished')<sup>18+</sup>

on(type: 'playFinished', streamId: number, callback: Callback\<number>): void

监听铃音播放完成事件（当铃音播放完成时触发）。使用callback异步回调。

监听对象为传入的streamId对应音频流。当streamId传入0时，监听本播放器对应的所有音频流。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                         |
| -------- | ----------------------- | ---- | --------------------------------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持的事件为'playFinished'，当铃音播放完成时，触发该事件。 |
| streamId | number                  | 是   | 监听对象为指定streamId对应的音频流，streamId通过[start](#start)获取。当streamId传入0时，可监听当前播放器对应的所有音频流。 |
| callback | Callback\<number>  | 是   | 'playFinished'的回调方法。返回播放完成的音频流的streamId。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 监听所有音频流的结束事件。
systemTonePlayer.on('playFinished', 0, (streamId: number) => {
  console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
});

// 监听指定音频流的结束事件。
systemTonePlayer.start().then((value: number) => {
  systemTonePlayer.on('playFinished', value, (streamId: number) => {
    console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to start system tone player. ${err}`);
});
```

### off('playFinished')<sup>18+</sup>

off(type: 'playFinished', callback?: Callback\<number>): void

取消监听铃音播放完成事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ----- | ----- | ---- | ------------------------------------------------ |
| type   | string | 是   | 事件回调类型，支持的事件为'playFinished'，当取消监听铃音播放完成事件时，触发该事件。 |
| callback | Callback\<number>    | 否   | 回调函数，返回结束事件的音频流的streamId。不填入此参数时，会取消该事件的所有监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**示例：**

```ts
// 取消该事件的所有监听。
systemTonePlayer.off('playFinished');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let playFinishedCallback = (streamId: number) => {
  console.info(`Receive the callback of playFinished, streamId: ${streamId}.`);
};

systemTonePlayer.on('playFinished', 0, playFinishedCallback);

systemTonePlayer.off('playFinished', playFinishedCallback);
```

### on('error')<sup>18+</sup>

on(type: 'error', callback: ErrorCallback): void

监听铃音播放过程中的错误事件（当铃音播放过程中发生错误时触发）。使用callback异步回调。

**系统能力**：SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 事件回调类型，支持的事件为'error'，当铃音播放过程中发生错误时，触发该事件。 |
| callback | ErrorCallback | 是   | 回调函数，返回错误码和错误信息。错误码请参考AVPlayer的[on('error')](../apis-media-kit/js-apis-media.md#onerror9)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

systemTonePlayer.on('error', (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
});
```

### off('error')<sup>18+</sup>

off(type: 'error', callback?: ErrorCallback): void

取消监听铃音播放过程中的错误事件。使用callback异步回调。

**系统能力**：SystemCapability.Multimedia.SystemSound.Core

**参数：**

| 参数名   | 类型          | 必填 | 说明                                 |
| -------- | ------------- | ---- | ------------------------------------ |
| type     | string        | 是   | 事件回调类型，支持的事件为'error'，当取消监听铃音播放过程中的错误事件时，触发该事件。 |
| callback | ErrorCallback | 否   | 回调函数，返回错误码和错误信息。不填入此参数时，会取消该事件的所有监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[铃声错误码说明文档](./errorcode-ringtone.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 202      | Not system App.  |
| 20700002 | Parameter check error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 取消该事件的所有监听。
systemTonePlayer.off('error');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let callback = (err: BusinessError) => {
  console.log("on error, err:" + JSON.stringify(err));
};

systemTonePlayer.on('error', callback);

systemTonePlayer.off('error', callback);
```
