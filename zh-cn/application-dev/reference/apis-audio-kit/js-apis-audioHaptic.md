# @ohos.multimedia.audioHaptic (音振协同)

音振协同，表示在播放声音时，可同步发起振动。可用于来电通知、消息提醒等场景。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import { audioHaptic } from '@kit.AudioKit';
```

## audioHaptic.getAudioHapticManager

getAudioHapticManager(): AudioHapticManager

获取音振管理器。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                          | 说明         |
| ----------------------------- | ------------ |
| [AudioHapticManager](#audiohapticmanager) | 音振管理器。 |

**示例：**
```ts
let audioHapticManagerInstance: audioHaptic.AudioHapticManager = audioHaptic.getAudioHapticManager();
```

## AudioLatencyMode

枚举，音频时延模式。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

| 名称                            |  值     | 说明                                         |
| ------------------------------- | ------ | -------------------------------------------- |
| AUDIO_LATENCY_MODE_NORMAL       | 0      | 普通时延模式。                                |
| AUDIO_LATENCY_MODE_FAST         | 1      | 低时延模式。该模式适用于比较短的音频文件，音频文件过长时可能被截断，该特性与[SoundPool](../apis-media-kit/js-apis-inner-multimedia-soundPool.md#soundpool)一致。 |

## AudioHapticPlayerOptions

音振播放器选项。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

| 名称      | 类型            |必填   | 说明                              |
| --------- | -------------- | ---- | --------------------------------- |
| muteAudio   | boolean      | 否   | 是否将音频静音，true表示将音频静音，false表示正常播放声音。若不填该参数，则默认为false。 |
| muteHaptics | boolean      | 否   | 是否禁止振动，true表示将禁止振动，false表示正常振动。若不填该参数，则默认为false。 |

## AudioHapticManager

管理音振协同功能。在调用AudioHapticManager的接口前，需要先通过[getAudioHapticManager](#audiohapticgetaudiohapticmanager)创建实例。

### registerSource

registerSource(audioUri: string, hapticUri: string): Promise&lt;number&gt;

注册音频和振动资源的Uri，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| audioUri  | string                                  | 是   | 音频资源的Uri。对普通时延模式，音频资源格式和路径格式的支持可参考[media.AVPlayer](../apis-media-kit/js-apis-media.md#avplayer9)；对低时延模式，音频资源格式支持可参考[SoundPool](../apis-media-kit/js-apis-inner-multimedia-soundPool.md#soundpool)，路径格式需满足[文件管理模块open函数](../apis-core-file-kit/js-apis-file-fs.md#fsopen)的要求。对两种时延模式，均建议传入文件的绝对路径。           |
| hapticUri | string                                  | 是   | 振动资源的Uri。振动资源格式支持可参考[vibrator](../apis-sensor-service-kit/js-apis-vibrator.md#hapticfiledescriptor10)，路径格式需满足[文件管理模块open函数](../apis-core-file-kit/js-apis-file-fs.md#fsopen)的要求。建议传入文件的绝对路径。         |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise回调返回注册资源的source id。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri。
let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri。
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});
```

### unregisterSource

unregisterSource(id: number): Promise&lt;void&gt;

取消注册音频和振动资源，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | 是   | 已注册资源的source id。    |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri。
let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri。
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

audioHapticManagerInstance.unregisterSource(id).then(() => {
  console.info(`Promise returned to indicate that unregister source successfully`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to unregistere source ${err}`);
});
```

### setAudioLatencyMode

setAudioLatencyMode(id:number, latencyMode: AudioLatencyMode): void

设置音频时延模式。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id          | number                                | 是   | 已注册资源的source id。    |
| latencyMode | [AudioLatencyMode](#audiolatencymode) | 是   | 音频时延模式。             |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102 | Operation not allowed.            |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri。
let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri。
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let latencyMode: audioHaptic.AudioLatencyMode = audioHaptic.AudioLatencyMode.AUDIO_LATENCY_MODE_FAST;

audioHapticManagerInstance.setAudioLatencyMode(id, latencyMode);
```

### setStreamUsage

setStreamUsage(id: number, usage: audio.StreamUsage): void

设置音频流使用类型。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | 是   | 已注册资源的source id。    |
| usage    | [audio.StreamUsage](js-apis-audio.md#streamusage) | 是   | 音频流使用类型。    |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types; 3.Parameter verification failed. |
| 5400102 | Operation not allowed.            |

**示例：**

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri。
let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri。
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let usage: audio.StreamUsage = audio.StreamUsage.STREAM_USAGE_NOTIFICATION;

audioHapticManagerInstance.setStreamUsage(id, usage);
```

### createPlayer

createPlayer(id: number, options?: AudioHapticPlayerOptions): Promise&lt;AudioHapticPlayer&gt;

创建音振播放器，使用Promise方式异步返回结果。

**需要权限：** ohos.permission.VIBRATE

如果应用创建的AudioHapticPlayer需要触发振动，则需要校验应用是否拥有该权限。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| id       | number                                   | 是   | 已注册资源的source id。    |
| options  | [AudioHapticPlayerOptions](#audiohapticplayeroptions) | 否   | 音振播放器选项。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;[AudioHapticPlayer](#audiohapticplayer)&gt; | Promise回调返回创建的音振播放器。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 5400102 | Operation not allowed. |
| 5400103 | I/O error. |
| 5400106 | Unsupport format. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let audioUri = 'data/audioTest.wav'; // 需更改为目标音频资源的Uri。
let hapticUri = 'data/hapticTest.json'; // 需更改为目标振动资源的Uri。
let id = 0;

audioHapticManagerInstance.registerSource(audioUri, hapticUri).then((value: number) => {
  console.info(`Promise returned to indicate that the source id of the registerd source ${value}.`);
  id = value;
}).catch ((err: BusinessError) => {
  console.error(`Failed to register source ${err}`);
});

let options: audioHaptic.AudioHapticPlayerOptions = {muteAudio: false, muteHaptics: false};
let audioHapticPlayerInstance: audioHaptic.AudioHapticPlayer | undefined = undefined;

audioHapticManagerInstance.createPlayer(id, options).then((value: audioHaptic.AudioHapticPlayer) => {
  audioHapticPlayerInstance = value;
  console.info(`Create the audio haptic player successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to create the audio haptic player. ${err}`);
});
```

## AudioHapticType

枚举，音振类型。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

| 名称                            |  值     | 说明                                         |
| ------------------------------- | ------ | -------------------------------------------- |
| AUDIO_HAPTIC_TYPE_AUDIO         | 0      | 音频。                                    |
| AUDIO_HAPTIC_TYPE_HAPTIC        | 1      | 振动。                                    |

## AudioHapticPlayer

音振播放器，提供音振协同播放功能。在调用AudioHapticPlayer的接口前，需要先通过[createPlayer](#createplayer)创建实例。

### isMuted

isMuted(type: AudioHapticType): boolean

查询该音振类型是否被静音。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| type     | [AudioHapticType](#audiohaptictype)      | 是   | 音振类型。                |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| boolean             | 查询的音振类型是否被静音。        |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID | 错误信息                              |
| ------- |-----------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Parameter verification failed. |

**示例：**

```ts
let audioHapticType: audioHaptic.AudioHapticType = audioHaptic.AudioHapticType.AUDIO_HAPTIC_TYPE_AUDIO;

let result: boolean = audioHapticPlayerInstance.isMuted(audioHapticType);
```

### start

start(): Promise&lt;void&gt;

开始播放，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise回调返回开始播放成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 5400102 | Operate not permit. |
| 5400103 | IO error. |
| 5400105 | Service died. |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.start().then(() => {
  console.info(`Promise returned to indicate that start playing successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to start playing. ${err}`);
});
```

### stop

stop(): Promise&lt;void&gt;

停止播放，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | -------------------------------- |
| Promise&lt;void&gt; | Promise回调返回停止播放成功或失败。 |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 5400102 | Operate not permit. |
| 5400105 | Service died. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.stop().then(() => {
  console.info(`Promise returned to indicate that stop playing successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to stop playing. ${err}`);
});
```

### release

release(): Promise&lt;void&gt;

释放音振播放器，使用Promise方式异步返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise回调返回释放成功或失败。   |

**错误码：**

以下错误码的详细介绍请参见[媒体服务错误码](../apis-media-kit/errorcode-media.md)。

| 错误码ID   | 错误信息                              |
|---------|-----------------------------------|
| 5400105 | Service died. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioHapticPlayerInstance.release().then(() => {
  console.info(`Promise returned to indicate that release the audio haptic player successfully.`);
}).catch ((err: BusinessError) => {
  console.error(`Failed to release the audio haptic player. ${err}`);
});
```

### on('endOfStream')

on(type: 'endOfStream', callback: Callback&lt;void&gt;): void

监听流结束事件（音频流播放结束时触发），使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                       |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持的事件为：'endOfStream'（流结束事件）。 |
| callback | Callback&lt;void&gt;    | 是   | 回调函数，无返回结果。 |

**示例：**

```ts
audioHapticPlayerInstance.on('endOfStream', () => {
  console.info(`Receive the callback of endOfStream.`);
});
```

### off('endOfStream')

off(type: 'endOfStream', callback?: Callback&lt;void&gt;): void

取消监听流结束事件，使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ----- | ----- | ---- | ------------------------------------------------ |
| type   | string | 是   | 要取消订阅事件的类型。支持的事件为：'endOfStream'。 |
| callback | Callback&lt;void&gt;    | 否   | 回调函数，无返回结果。 |

**示例：**

```ts
// 取消该事件的所有监听。
audioHapticPlayerInstance.off('endOfStream');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let endOfStreamCallback = () => {
  console.info(`Receive the callback of endOfStream.`);
};

audioHapticPlayerInstance.on('endOfStream', endOfStreamCallback);

audioHapticPlayerInstance.off('endOfStream', endOfStreamCallback);
```

### on('audioInterrupt')

on(type: 'audioInterrupt', callback: Callback&lt;audio.InterruptEvent&gt;): void

监听音频中断事件（当音频焦点发生变化时触发），使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                                                       |
| -------- | ----------------------- | ---- | -------------------------------------------------------------------------- |
| type     | string                  | 是   | 事件回调类型，支持的事件为：'audioInterrupt'（音频中断事件）。                     |
| callback | Callback&lt;[audio.InterruptEvent](js-apis-audio.md#interruptevent9)&gt; | 是   | 回调函数，返回播放中断时，应用接收的中断事件信息。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // 标识符，表示是否正在渲染。
let isDucked: boolean; // 标识符，表示是否被降低音量。

audioHapticPlayerInstance.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
  // 在发生音频打断事件时，audioHapticPlayerInstance收到interruptEvent回调，此处根据其内容做相应处理。
  // 1、可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
  // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
  // 2、必选：读取interruptEvent.hintType的类型，做出相应的处理。
  if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
    // 音频焦点事件已由系统强制执行，应用需更新自身状态及显示内容等。
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
        // 音频流已被暂停，临时失去焦点，待可重获焦点时会收到resume对应的interruptEvent。
        console.info('Force paused. Update playing status and stop writing');
        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_STOP:
        // 音频流已被停止，永久失去焦点，若想恢复渲染，需用户主动触发。
        console.info('Force stopped. Update playing status and stop writing');
        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_DUCK:
        // 音频流已被降低音量渲染。
        console.info('Force ducked. Update volume status');
        isDucked = true; // 简化处理，代表应用更新音量状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
        // 音频流已被恢复正常音量渲染。
        console.info('Force ducked. Update volume status');
        isDucked = false; // 简化处理，代表应用更新音量状态的若干操作。
        break;
      default:
        break;
    }
  } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
    // 音频焦点事件需由应用进行操作，应用可以自主选择如何处理该事件，建议应用遵从InterruptHint提示处理。
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_RESUME:
        // 建议应用继续渲染（说明音频流此前被强制暂停，临时失去焦点，现在可以恢复渲染）。
        // 由于INTERRUPT_HINT_RESUME操作需要应用主动执行，系统无法强制，故INTERRUPT_HINT_RESUME事件一定为INTERRUPT_SHARE类型。
        console.info('Resume force paused renderer or ignore');
        // 若选择继续渲染，需在此处主动执行开始渲染的若干操作。
        break;
      default:
        break;
    }
  }
});
```

### off('audioInterrupt')

off(type: 'audioInterrupt', callback?: Callback&lt;audio.InterruptEvent&gt;): void

取消监听音频中断事件，使用callback方式返回结果。

**系统能力：** SystemCapability.Multimedia.AudioHaptic.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ----- | ----- | ---- | ------------------------------------------------- |
| type   | string | 是   | 要取消订阅事件的类型。支持的事件为：'audioInterrupt'。 |
| callback | Callback&lt;[audio.InterruptEvent](js-apis-audio.md#interruptevent9)&gt; | 否   | 回调函数，取消监听时，返回应用中断事件信息。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

// 取消该事件的所有监听。
audioHapticPlayerInstance.off('audioInterrupt');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let isPlaying: boolean; // 标识符，表示是否正在渲染。
let isDucked: boolean; // 标识符，表示是否被降低音量。
let audioInterruptCallback = (interruptEvent: audio.InterruptEvent) => {
  // 在发生音频打断事件时，audioHapticPlayerInstance收到interruptEvent回调，此处根据其内容做相应处理。
  // 1、可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
  // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
  // 2、必选：读取interruptEvent.hintType的类型，做出相应的处理。
  if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
    // 音频焦点事件已由系统强制执行，应用需更新自身状态及显示内容等。
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
        // 音频流已被暂停，临时失去焦点，待可重获焦点时会收到resume对应的interruptEvent。
        console.info('Force paused. Update playing status and stop writing');
        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_STOP:
        // 音频流已被停止，永久失去焦点，若想恢复渲染，需用户主动触发。
        console.info('Force stopped. Update playing status and stop writing');
        isPlaying = false; // 简化处理，代表应用切换至暂停状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_DUCK:
        // 音频流已被降低音量渲染。
        console.info('Force ducked. Update volume status');
        isDucked = true; // 简化处理，代表应用更新音量状态的若干操作。
        break;
      case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
        // 音频流已被恢复正常音量渲染。
        console.info('Force ducked. Update volume status');
        isDucked = false; // 简化处理，代表应用更新音量状态的若干操作。
        break;
      default:
        break;
    }
  } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
    // 音频焦点事件需由应用进行操作，应用可以自主选择如何处理该事件，建议应用遵从InterruptHint提示处理。
    switch (interruptEvent.hintType) {
      case audio.InterruptHint.INTERRUPT_HINT_RESUME:
        // 建议应用继续渲染（说明音频流此前被强制暂停，临时失去焦点，现在可以恢复渲染）。
        // 由于INTERRUPT_HINT_RESUME操作需要应用主动执行，系统无法强制，故INTERRUPT_HINT_RESUME事件一定为INTERRUPT_SHARE类型。
        console.info('Resume force paused renderer or ignore');
        // 若选择继续渲染，需在此处主动执行开始渲染的若干操作。
        break;
      default:
        break;
    }
  }
};

audioHapticPlayerInstance.on('audioInterrupt', audioInterruptCallback);

audioHapticPlayerInstance.off('audioInterrupt', audioInterruptCallback);
```
