# Interface (AudioVolumeManager)

> **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

音量管理。

在使用AudioVolumeManager的接口之前，需先通过[getVolumeManager](arkts-apis-audio-AudioManager.md#getvolumemanager9)获取AudioVolumeManager实例。

## 导入模块

```ts
import { audio } from '@kit.AudioKit';
```

## getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager\>\): void

获取音频组管理器。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                        |
| ---------- | ------------------------------------------------------------ | ---- |-----------------------------------------------------------|
| groupId    | number                                    | 是   | 音量组id，默认使用DEFAULT_VOLUME_GROUP_ID。                         |
| callback   | AsyncCallback&lt;[AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md)&gt; | 是   | 回调函数。当获取音频组管理器成功，err为undefined，data为获取到的音频组管理器对象；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;

audioVolumeManager.getVolumeGroupManager(groupId, (err: BusinessError, value: audio.AudioVolumeGroupManager) => {
  if (err) {
    console.error(`Failed to obtain the volume group infos list. ${err}`);
    return;
  }
  console.info('Callback invoked to indicate that the volume group infos list is obtained.');
});

```

## getVolumeGroupManager<sup>9+</sup>

getVolumeGroupManager(groupId: number\): Promise<AudioVolumeGroupManager\>

获取音频组管理器。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                               |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | 是   | 音量组id，默认使用DEFAULT_VOLUME_GROUP_ID。|

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt; [AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md) &gt; | Promise对象，返回音量组实例。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let groupId: number = audio.DEFAULT_VOLUME_GROUP_ID;
let audioVolumeGroupManager: audio.AudioVolumeGroupManager | undefined = undefined;

async function getVolumeGroupManager(){
  audioVolumeGroupManager = await audioVolumeManager.getVolumeGroupManager(groupId);
  console.info('Promise returned to indicate that the volume group infos list is obtained.');
}
```

## getVolumeGroupManagerSync<sup>10+</sup>

getVolumeGroupManagerSync(groupId: number\): AudioVolumeGroupManager

获取音频组管理器。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明                               |
| ---------- | ---------------------------------------- | ---- |----------------------------------|
| groupId    | number                                   | 是   | 音量组id，默认使用DEFAULT_VOLUME_GROUP_ID。|

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [AudioVolumeGroupManager](arkts-apis-audio-AudioVolumeGroupManager.md) | 音量组实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioVolumeGroupManager: audio.AudioVolumeGroupManager = audioVolumeManager.getVolumeGroupManagerSync(audio.DEFAULT_VOLUME_GROUP_ID);
  console.info(`Get audioVolumeGroupManager success.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to get audioVolumeGroupManager, error: ${error}`);
}
```

## getAppVolumePercentage<sup>19+</sup>

getAppVolumePercentage(): Promise<number\>

获取应用的音量（范围为0到100）。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                | 说明                 |
| ------------------- |--------------------|
| Promise&lt;number&gt; | Promise对象，返回应用的音量。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.getAppVolumePercentage().then((value: number) => {
  console.info(`app volume is ${value}.`);
});
```

## setAppVolumePercentage<sup>19+</sup>

setAppVolumePercentage(volume: number\): Promise<void\>

设置应用的音量（范围为0到100）。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                      | 必填 | 说明       |
| ---------- | ---------------------------------------- | ---- |----------|
| volume    | number                                   | 是   | 要设置的音量值。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed.|
| 6800301 | Crash or blocking occurs in system process. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

audioVolumeManager.setAppVolumePercentage(20).then(() => {
  console.info(`set app volume success.`);
});
```

## on('volumeChange')<sup>9+</sup>

on(type: 'volumeChange', callback: Callback\<VolumeEvent>): void

监听系统音量变化事件（当系统音量发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'volumeChange'，当系统音量发生变化时，触发该事件。 |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeManager.on('volumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

## off('volumeChange')<sup>12+</sup>

off(type: 'volumeChange', callback?: Callback\<VolumeEvent>): void

取消监听系统音量变化事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'volumeChange'，当取消监听系统音量变化事件时，触发该事件。 |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 否   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.off('volumeChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let volumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.on('volumeChange', volumeChangeCallback);

audioVolumeManager.off('volumeChange', volumeChangeCallback);
```

## on('appVolumeChange')<sup>19+</sup>

on(type: 'appVolumeChange', callback: Callback\<VolumeEvent>): void

监听当前应用应用级音量变化事件（当应用级音量发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'appVolumeChange'，当应用级音量发生变化时，触发该事件。 |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 是   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeManager.on('appVolumeChange', (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
});
```

## off('appVolumeChange')<sup>19+</sup>

off(type: 'appVolumeChange', callback?: Callback\<VolumeEvent>): void

取消监听当前应用应用级音量变化事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'appVolumeChange'，当取消监听当前应用应用级音量变化事件时，触发该事件。 |
| callback | Callback<[VolumeEvent](arkts-apis-audio-i.md#volumeevent9)> | 否   | 回调函数，返回变化后的音量信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeManager.off('appVolumeChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let appVolumeChangeCallback = (volumeEvent: audio.VolumeEvent) => {
  console.info(`VolumeType of stream: ${volumeEvent.volumeType} `);
  console.info(`Volume level: ${volumeEvent.volume} `);
  console.info(`Whether to updateUI: ${volumeEvent.updateUi} `);
};

audioVolumeManager.on('appVolumeChange', appVolumeChangeCallback);

audioVolumeManager.off('appVolumeChange', appVolumeChangeCallback);
```
