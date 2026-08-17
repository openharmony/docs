# Interface (AudioSessionManager)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @funny_sunix-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

AudioSessionManager是音频系统中的会话管理模块。本模块提供音频会话管理能力，包括音频会话的激活和停用、音频焦点控制、音频设备选择和切换、音频场景设置等。当开发者需要协调多个应用的音频播放行为、解决音频焦点冲突问题时，使用本模块接口完成相关操作。适用于媒体播放、VoIP通话、游戏等需要精细化音频管理的场景。

在使用AudioSessionManager的接口之前，需先通过[getSessionManager](arkts-apis-audio-AudioManager.md#getsessionmanager12)获取AudioSessionManager实例。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 12开始支持。

## 导入模块

```ts
import { audio } from '@kit.AudioKit';
```

## activateAudioSession<sup>12+</sup>

activateAudioSession(strategy: AudioSessionStrategy): Promise\<void>

激活音频会话。使用Promise异步回调。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名 | 类型                                              | 必填 | 说明         |
| ------ |-------------------------------------------------| ---- | ------------ |
| strategy | [AudioSessionStrategy](arkts-apis-audio-i.md#audiosessionstrategy12) | 是   | 音频会话策略。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters unspecified. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed.|
| 6800301 | System error. Possible causes: 1.Focus preemption failure. 2.Audio server process died. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置音频会话并发模式为混音模式。
let strategy: audio.AudioSessionStrategy = {
  concurrencyMode: audio.AudioConcurrencyMode.CONCURRENCY_MIX_WITH_OTHERS
};

audioSessionManager.activateAudioSession(strategy).then(() => {
  console.info('Succeeded in activating the audio session.');
}).catch((err: BusinessError) => {
  console.error(`Failed to activate the audio session. Code: ${err.code}, message: ${err.message}`);
});
```

## deactivateAudioSession<sup>12+</sup>

deactivateAudioSession(): Promise\<void>

停用音频会话。使用Promise异步回调。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 6800301 | System error. Possible causes: 1.The audio session is not existed or has been released. 2.Audio server process died. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.deactivateAudioSession().then(() => {
  console.info('Succeeded in deactivating the audio session.');
}).catch((err: BusinessError) => {
  console.error(`Failed to deactivate the audio session. Code: ${err.code}, message: ${err.message}`);
});
```

## isAudioSessionActivated<sup>12+</sup>

isAudioSessionActivated(): boolean

检查音频会话是否已激活。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                              | 说明                                    |
| ------------------------------------------------- |---------------------------------------|
| boolean | 音频会话是否处于激活状态。true表示已激活，false表示已停用。 |

**示例：**

```ts
let isActivated = audioSessionManager.isAudioSessionActivated();
```

## on('audioSessionDeactivated')<sup>12+</sup>

on(type: 'audioSessionDeactivated', callback: Callback\<AudioSessionDeactivatedEvent>): void

监听音频会话停用事件（当音频会话停用时触发）。使用callback异步回调。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                                                                        | 必填 | 说明                                                         |
| -------- |---------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'audioSessionDeactivated'，当音频会话停用时，触发该事件。 |
| callback | Callback<[AudioSessionDeactivatedEvent](arkts-apis-audio-i.md#audiosessiondeactivatedevent12)> | 是   | 回调函数，返回音频会话停用原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters unspecified. 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioSessionManager.on('audioSessionDeactivated',
  (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
  console.info(`Audio session deactivated, audioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}.`);
});
```

## off('audioSessionDeactivated')<sup>12+</sup>

off(type: 'audioSessionDeactivated', callback?: Callback\<AudioSessionDeactivatedEvent>): void

取消监听音频会话停用事件。

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'audioSessionDeactivated'。 |
| callback |Callback<[AudioSessionDeactivatedEvent](arkts-apis-audio-i.md#audiosessiondeactivatedevent12)> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('audioSessionDeactivated')](#onaudiosessiondeactivated12)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSessionManager.off('audioSessionDeactivated');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let audioSessionDeactivatedCallback = (audioSessionDeactivatedEvent: audio.AudioSessionDeactivatedEvent) => {
  console.info(`Audio session deactivated, audioSessionDeactivatedEvent: ${JSON.stringify(audioSessionDeactivatedEvent)}.`);
};

audioSessionManager.on('audioSessionDeactivated', audioSessionDeactivatedCallback);

audioSessionManager.off('audioSessionDeactivated', audioSessionDeactivatedCallback);
```

## setAudioSessionScene<sup>20+</sup>

setAudioSessionScene(scene: AudioSessionScene): void

设置音频会话场景参数。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| scene     | [AudioSessionScene](arkts-apis-audio-e.md#audiosessionscene20) | 是   | 音频会话场景。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state.|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
audioSessionManager.setAudioSessionScene(audio.AudioSessionScene.AUDIO_SESSION_SCENE_MEDIA);
```

## on('audioSessionStateChanged')<sup>20+</sup>

on(type: 'audioSessionStateChanged', callback: Callback\<AudioSessionStateChangedEvent>): void

监听音频会话状态变更事件（当音频会话焦点变更时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                                                                        | 必填 | 说明                                                         |
| -------- |---------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'audioSessionStateChanged'，当音频会话状态变更时，触发该事件。 |
| callback | Callback<[AudioSessionStateChangedEvent](arkts-apis-audio-i.md#audiosessionstatechangedevent20)> | 是   | 回调函数，返回音频会话变更提示信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800102 | Allocate memory failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
audioSessionManager.on('audioSessionStateChanged', (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
  console.info(`Audio session state changed, audioSessionStateChangedEvent: ${JSON.stringify(audioSessionStateChangedEvent)}.`);
});
```

## off('audioSessionStateChanged')<sup>20+</sup>

off(type: 'audioSessionStateChanged', callback?: Callback\<AudioSessionStateChangedEvent>): void

取消监听音频会话状态变更事件。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型                                                                        | 必填 | 说明                                                         |
| -------- |---------------------------------------------------------------------------| ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'audioSessionStateChanged'。 |
| callback | Callback<[AudioSessionStateChangedEvent](arkts-apis-audio-i.md#audiosessionstatechangedevent20)> | 否 | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('audioSessionStateChanged')](#onaudiosessionstatechanged20)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSessionManager.off('audioSessionStateChanged');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let audioSessionStateChangedCallback = (audioSessionStateChangedEvent: audio.AudioSessionStateChangedEvent) => {
  console.info(`Audio session state changed, audioSessionStateChangedEvent: ${JSON.stringify(audioSessionStateChangedEvent)}.`);
};

audioSessionManager.on('audioSessionStateChanged', audioSessionStateChangedCallback);

audioSessionManager.off('audioSessionStateChanged', audioSessionStateChangedCallback);
```

## setDefaultOutputDevice<sup>20+</sup>

setDefaultOutputDevice(deviceType: DeviceType): Promise&lt;void&gt;

设置默认发声设备。使用Promise方式进行异步回调。

> **说明：**
>
> - 本接口适用于以下情况：当设置的[AudioSessionScene](arkts-apis-audio-e.md#audiosessionscene20)为VoIP场景时，激活AudioSession后立即生效。若[AudioSessionScene](arkts-apis-audio-e.md#audiosessionscene20)为非VoIP场景，激活AudioSession时不会生效，仅在启动播放的[StreamUsage](arkts-apis-audio-e.md#streamusage)为语音消息、VoIP语音通话或VoIP视频通话时才生效。支持听筒、扬声器和系统默认设备。
> - 本接口允许在AudioSessionManager创建后随时调用，系统会记录应用设置的默认本机内置发声设备。但只有激活AudioSession后才能生效。应用启动播放时，若外接设备如蓝牙耳机或有线耳机已接入，系统优先从外接设备发声。否则，系统遵循应用设置的默认本机内置发声设备。
> - 由于AudioSessionManager是应用级设置，调用本接口设置默认音频输出设备时，会对当前应用所有适用范围内的音频流生效，且会覆盖AudioRenderer的[setDefaultOutputDevice](../../reference/apis-audio-kit/arkts-apis-audio-AudioRenderer.md#setdefaultoutputdevice12)接口设置的默认音频输出设备信息。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**设备行为差异：** 当该接口在无听筒的设备上设置默认发声设备为听筒时，将继续从扬声器发声。

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |----------------| ------ |---------------------------------------------------------|
| deviceType | [DeviceType](arkts-apis-audio-e.md#devicetype) | 是     | 设备类型。<br>仅支持以下设备：EARPIECE（听筒）、SPEAKER（扬声器）和DEFAULT（系统默认设备）。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. Return by promise. |
| 6800102 | Allocate memory failed. Return by promise. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('Succeeded in setting the default output device.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the default output device. Code: ${err.code}, message: ${err.message}`);
});
```

## getDefaultOutputDevice<sup>20+</sup>

getDefaultOutputDevice(): DeviceType

获取通过[setDefaultOutputDevice](#setdefaultoutputdevice20)设置的默认发声设备。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                                              | 说明                                    |
| ------------------------------------------------- |---------------------------------------|
| DeviceType |设备类型。<br>仅支持以下设备：EARPIECE（听筒）、SPEAKER（扬声器）和DEFAULT（系统默认设备）。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID   | 错误信息 |
|---------| --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state. Return by promise. |

**示例：**

```ts
let deviceType = audioSessionManager.getDefaultOutputDevice();
```

## setMediaOutputDevice

setMediaOutputDevice(deviceType: DeviceType): Promise&lt;void&gt;

当连接其他音频外设（如蓝牙耳机或有线耳机）时，将媒体输出设备切换为内置扬声器。使用Promise异步回调。

> **说明：**
>
> - 本接口仅适用于媒体播放场景，并且会作用于应用内发起的所有媒体流。
> - 若存在更高优先级的并发播放流或用户手动选择输出设备，则应用实际使用的输出设备将与本接口设置的设备不同。应用可通过监听[CurrentOutputDeviceChangedEvent](arkts-apis-audio-i.md#currentoutputdevicechangedevent20)事件获取当前活跃的输出设备。
> - 当应用需要清除之前通过接口设置的扬声器输出配置时，可通过调用接口将媒体输出设备设置为DEFAULT（系统默认设备）来实现。该设置仅在应用运行期间有效，当应用退出时，此接口的设置将自动清除。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**设备行为差异：** 当该接口在无扬声器的设备上设置输出设备为扬声器时，该设置不会生效。

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |----------------| ------ |---------------------------------------------------------|
| deviceType | [DeviceType](arkts-apis-audio-e.md#devicetype) | 是     | 设备类型。<br>仅支持以下设备：SPEAKER（扬声器）和DEFAULT（系统默认设备）。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed, for example, the selected device type is not supported. |
| 6800301 | System error. Possible causes: 1.Internal variable memory allocation failed. 2.Audio server process died. 3.Speaker device is not available. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.setMediaOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('Succeeded in setting the media output device.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the media output device. Code: ${err.code}, message: ${err.message}`);
});
```

## on('currentOutputDeviceChanged')<sup>20+</sup>

on(type: 'currentOutputDeviceChanged', callback: Callback\<CurrentOutputDeviceChangedEvent>): void

监听当前输出设备变化事件（当前输出设备发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'currentOutputDeviceChanged'，当前输出设备变更时触发。|
| callback | Callback<[CurrentOutputDeviceChangedEvent](arkts-apis-audio-i.md#currentoutputdevicechangedevent20)> | 是   | 回调函数，返回当前输出设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800102 | Allocate memory failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
let currentOutputDeviceChangedCallback = (currentOutputDeviceChangedEvent: audio.CurrentOutputDeviceChangedEvent) => {
  console.info(`Current output device changed, currentOutputDeviceChangedEvent: ${JSON.stringify(currentOutputDeviceChangedEvent)}.`);
};

audioSessionManager.on('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);
```

## off('currentOutputDeviceChanged')<sup>20+</sup>

off(type: 'currentOutputDeviceChanged', callback?: Callback\<CurrentOutputDeviceChangedEvent>): void

取消监听当前输出设备的变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'currentOutputDeviceChanged'。|
| callback | Callback<[CurrentOutputDeviceChangedEvent](arkts-apis-audio-i.md#currentoutputdevicechangedevent20)> | 否 | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('currentOutputDeviceChanged')](#oncurrentoutputdevicechanged20)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSessionManager.off('currentOutputDeviceChanged');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let currentOutputDeviceChangedCallback = (currentOutputDeviceChangedEvent: audio.CurrentOutputDeviceChangedEvent) => {
  console.info(`Current output device changed, currentOutputDeviceChangedEvent: ${JSON.stringify(currentOutputDeviceChangedEvent)}.`);
};

audioSessionManager.on('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);

audioSessionManager.off('currentOutputDeviceChanged', currentOutputDeviceChangedCallback);
```

## getAvailableDevices<sup>21+</sup>

getAvailableDevices(deviceUsage: DeviceUsage): AudioDeviceDescriptors

获取音频可选设备列表。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| deviceUsage| [DeviceUsage](arkts-apis-audio-e.md#deviceusage12) | 是   | 音频设备类型（根据用途分类）。 |

**返回值：**

| 类型                                                         | 说明                      |
| ------------------------------------------------------------ | ------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 返回设备列表。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let data: audio.AudioDeviceDescriptors = audioSessionManager.getAvailableDevices(audio.DeviceUsage.MEDIA_OUTPUT_DEVICES);
  console.info(`Succeeded in obtaining available devices, audioDeviceDescriptors: ${JSON.stringify(data)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain available devices. Code: ${error.code}, message: ${error.message}`);
}
```

## on('availableDeviceChange')<sup>21+</sup>

on(type: 'availableDeviceChange', deviceUsage: DeviceUsage, callback: Callback\<DeviceChangeAction>): void

监听音频可选设备连接状态变化事件（当音频可选设备连接状态发生变化时触发）。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| type     | string                                               | 是   | 事件回调类型，支持的事件为'availableDeviceChange'，当音频可选设备连接状态发生变化时，触发该事件。 |
| deviceUsage | [DeviceUsage](arkts-apis-audio-e.md#deviceusage12)                       | 是   | 音频设备类型（根据用途分类）。     |
| callback | Callback<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)\> | 是   | 回调函数，返回设备更新详情。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
audioSessionManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_INPUT_DEVICES, (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`Available device changed, deviceChangeAction: ${JSON.stringify(deviceChanged)}.`);
});
```

## off('availableDeviceChange')<sup>21+</sup>

off(type: 'availableDeviceChange', callback?: Callback<DeviceChangeAction\>): void

取消监听音频可选设备连接状态变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                | 必填 | 说明                                       |
| -------- | --------------------------------------------------- | ---- | ------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'availableDeviceChange'。 |
| callback | Callback\<[DeviceChangeAction](arkts-apis-audio-i.md#devicechangeaction)\> | 否   | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('availableDeviceChange')](#onavailabledevicechange21)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSessionManager.off('availableDeviceChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let availableDeviceChangeCallback = (deviceChanged: audio.DeviceChangeAction) => {
  console.info(`Available device changed, deviceChangeAction: ${JSON.stringify(deviceChanged)}.`);
};

audioSessionManager.on('availableDeviceChange', audio.DeviceUsage.MEDIA_INPUT_DEVICES, availableDeviceChangeCallback);

audioSessionManager.off('availableDeviceChange', availableDeviceChangeCallback);
```

## selectMediaInputDevice<sup>21+</sup>

selectMediaInputDevice(inputAudioDevice: AudioDeviceDescriptor): Promise<void\>

设置媒体输入设备。使用Promise异步回调。

> **说明：**
>
> - 本接口不适用于VoIP通话录音，即[SourceType](arkts-apis-audio-e.md#sourcetype8)为SOURCE_TYPE_VOICE_COMMUNICATION的场景不适用。
> - 本接口调用前需要先调用[getAvailableDevices](#getavailabledevices21)接口查询到当前可用输入设备列表，从列表中选择输入设备。
> - 当系统中存在其他更高优先级的应用录音流时，实际使用的输入设备会跟随其他高优先级应用所选的输入设备。
> - 应用可以监听[currentInputDeviceChanged](#oncurrentinputdevicechanged21)事件来获得实际的输入设备。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| inputAudioDevice| [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 媒体输入设备。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed, for example, the selected device does not exist. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 获取可用音频输入设备列表，用于后续选择输入设备
  let data: audio.AudioDeviceDescriptors = audioSessionManager.getAvailableDevices(audio.DeviceUsage.MEDIA_INPUT_DEVICES);
  console.info(`Succeeded in obtaining available devices, audioDeviceDescriptors: ${JSON.stringify(data)}.`);

  if (data[0]) {
    // 选择第一个可用设备作为音频输入设备。
    audioSessionManager.selectMediaInputDevice(data[0]).then(() => {
      console.info('Succeeded in selecting the media input device.');
    }).catch((selectErr: BusinessError) => {
      console.error(`Failed to select the media input device. Code: ${selectErr.code}, message: ${selectErr.message}`);
    });
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain available devices. Code: ${error.code}, message: ${error.message}`);
}
```

## getSelectedMediaInputDevice<sup>21+</sup>

getSelectedMediaInputDevice(): AudioDeviceDescriptor

获得通过[selectMediaInputDevice](#selectmediainputdevice21)设置的媒体输入设备。如果没有设置，返回一个deviceType属性为INVALID的设备。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| [AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 媒体输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let device: audio.AudioDeviceDescriptor = audioSessionManager.getSelectedMediaInputDevice();
  console.info(`Succeeded in obtaining the selected media input device, audioDeviceDescriptor: ${JSON.stringify(device)}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the selected media input device. Code: ${error.code}, message: ${error.message}`);
}
```

## clearSelectedMediaInputDevice<sup>21+</sup>

clearSelectedMediaInputDevice(): Promise<void\>

清空通过[selectMediaInputDevice](#selectmediainputdevice21)设置的媒体输入设备。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.clearSelectedMediaInputDevice().then(() => {
  console.info('Succeeded in clearing the selected media input device.');
}).catch((err: BusinessError) => {
  console.error(`Failed to clear the selected media input device. Code: ${err.code}, message: ${err.message}`);
});
```

## setBluetoothAndNearlinkPreferredRecordCategory<sup>21+</sup>

setBluetoothAndNearlinkPreferredRecordCategory(category: BluetoothAndNearlinkPreferredRecordCategory): Promise<void\>

设置在使用蓝牙或星闪进行录音时，应用的设备偏好分类。使用Promise异步回调。

> **说明：**
>
> - 应用可以在蓝牙或星闪连接之前设置此分类，系统将在设备连接时优先使用蓝牙或星闪进行录音。
> - 当系统中存在其他更高优先级的应用录音流时，实际使用的输入设备会跟随其他高优先级应用所选的输入设备。
> - 应用可以监听[currentInputDeviceChanged](#oncurrentinputdevicechanged21)事件来获得实际的输入设备。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| category| [BluetoothAndNearlinkPreferredRecordCategory](arkts-apis-audio-e.md#bluetoothandnearlinkpreferredrecordcategory21) | 是   | 在使用蓝牙或星闪进行录音时，应用的设备偏好分类。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 设置蓝牙和星闪录音偏好为低延迟模式，优先使用低延迟设备。
let category = audio.BluetoothAndNearlinkPreferredRecordCategory.PREFERRED_LOW_LATENCY;

audioSessionManager.setBluetoothAndNearlinkPreferredRecordCategory(category).then(() => {
  console.info('Succeeded in setting the bluetooth and nearlink preferred record category.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the bluetooth and nearlink preferred record category. Code: ${err.code}, message: ${err.message}`);
});
```

## getBluetoothAndNearlinkPreferredRecordCategory<sup>21+</sup>

getBluetoothAndNearlinkPreferredRecordCategory(): BluetoothAndNearlinkPreferredRecordCategory

获取通过[setBluetoothAndNearlinkPreferredRecordCategory](#setbluetoothandnearlinkpreferredrecordcategory21)设置的在使用蓝牙或星闪进行录音时的设备偏好分类。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| [BluetoothAndNearlinkPreferredRecordCategory](arkts-apis-audio-e.md#bluetoothandnearlinkpreferredrecordcategory21) | 返回当前已设置的蓝牙或星闪录音设备偏好分类。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let category: audio.BluetoothAndNearlinkPreferredRecordCategory = audioSessionManager.getBluetoothAndNearlinkPreferredRecordCategory();
  console.info(`Succeeded in obtaining the bluetooth and nearlink preferred record category, category: ${category}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the bluetooth and nearlink preferred record category. Code: ${error.code}, message: ${error.message}`);
}
```

## on('currentInputDeviceChanged')<sup>21+</sup>

on(type: 'currentInputDeviceChanged', callback: Callback<CurrentInputDeviceChangedEvent\>): void

监听当前输入设备变化事件（当前输入设备发生变化时触发）。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                       |
| :------- | :--------------------------------------------------- | :--- | :----------------------------------------- |
| type     | string | 是   | 事件回调类型，支持的事件为'currentInputDeviceChanged'，当前输入设备发生变化时，触发该事件。 |
| callback | Callback\<[CurrentInputDeviceChangedEvent](arkts-apis-audio-i.md#currentinputdevicechangedevent21)\> | 是   | 回调函数，返回当前输入设备信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
let currentInputDeviceChangedCallback = (currentInputDeviceChangedEvent: audio.CurrentInputDeviceChangedEvent) => {
  console.info(`Current input device changed, currentInputDeviceChangedEvent: ${JSON.stringify(currentInputDeviceChangedEvent)}.`);
};

audioSessionManager.on('currentInputDeviceChanged', currentInputDeviceChangedCallback);
```

## off('currentInputDeviceChanged')<sup>21+</sup>

off(type: 'currentInputDeviceChanged', callback?: Callback<CurrentInputDeviceChangedEvent\>): void

取消监听当前输入设备的变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                                                      |
| :------- | :--------------------------------------------------- | :--- |:--------------------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'currentInputDeviceChanged'。|
| callback | Callback<[CurrentInputDeviceChangedEvent](arkts-apis-audio-i.md#currentinputdevicechangedevent21)> | 否 | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('currentInputDeviceChanged')](#oncurrentinputdevicechanged21)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800301 | Audio client call audio service error, System error. |

**示例：**

```ts
// 取消该事件的所有监听。
audioSessionManager.off('currentInputDeviceChanged');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let currentInputDeviceChangedCallback = (currentInputDeviceChangedEvent: audio.CurrentInputDeviceChangedEvent) => {
  console.info(`Current input device changed, currentInputDeviceChangedEvent: ${JSON.stringify(currentInputDeviceChangedEvent)}.`);
};

audioSessionManager.on('currentInputDeviceChanged', currentInputDeviceChangedCallback);

audioSessionManager.off('currentInputDeviceChanged', currentInputDeviceChangedCallback);
```

## enableMuteSuggestionWhenMixWithOthers<sup>23+</sup>

enableMuteSuggestionWhenMixWithOthers(enable: boolean): void

启用混音播放下接收静音播放建议通知功能。

通常，当使用混音模式时，如果其他应用同时播放音频，会和其他应用进行混音播放。但在某些场景下（如游戏或广播），应用自身会通过静音自身的音频以给用户提供更好的体验。

如果启用此功能，当订阅音频会话状态更改事件后静音建议和取消静音建议提示将通过[AudioSessionStateChangedEvent](arkts-apis-audio-i.md#audiosessionstatechangedevent20)回调发送。收到静音建议表示其他应用开始播放音频，且播放的音频和本应用的音频不能混音。

此功能仅支持已设置[AudioSessionScene](./arkts-apis-audio-e.md#audiosessionscene20)并激活模式为CONCURRENCY_MIX_WITH_OTHERS的音频会话使用。并且仅在激活音频会话期间生效一次，每次激活音频会话前都必须重新启用。

详细说明请参考[启用混音播放下静音建议通知](../../media/audio/audio-session-management.md#启用混音播放下静音建议通知)。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明      |
| -------- | ----------------- | ---- | --------- |
| enable   | boolean           | 是   | 是否启用混音播放下静音播放建议通知功能。true表示启用，false表示不启用。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 6800103 | Function is called without setting [AudioSessionScene](./arkts-apis-audio-e.md#audiosessionscene20) or called after audio session activation.|
| 6800301 | Audio client call audio service error, system internal error. |

**示例：**

```ts
audioSessionManager.enableMuteSuggestionWhenMixWithOthers(true);
```


## setCapturerMuteHint<sup>24+</sup>

setCapturerMuteHint(mute: boolean): Promise&lt;void&gt;

应用将当前音频会话内录音流的自身静音状态传递给系统音频模块。<!--RP1-->该接口不会触发录音流静音，当前仅在部分PC/2in1设备上用于优化设备功耗。<!--RP1End-->使用Promise异步回调。

> **说明：**
>
> - 该接口用于向系统音频模块上报当前音频会话内录音流的静音状态，不会改变录音流的实际静音状态。
> - 该接口仅在当前音频会话存在运行中的录音流时允许调用，否则返回错误码6800103。
> - 若某条录音流同时调用了流级接口[AudioCapturer.setMuteHint](arkts-apis-audio-AudioCapturer.md#setmutehint24)和本接口，流级接口设置优先级更高，以流级接口设置值为准。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Capturer

**参数：**

| 参数名   | 类型               | 必填 | 说明      |
| -------- | ----------------- | ---- | --------- |
| mute   | boolean           | 是   | 应用自身给系统音频模块上报的静音状态。true表示应用将当前流静音，false表示取消静音。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 6800103 | Operation not permit at current state, there is no audio capturer running. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioSessionManager.setCapturerMuteHint(true).then(() => {
  console.info('Succeeded in setting the capturer mute hint.');
}).catch((err: BusinessError) => {
  console.error(`Failed to set the capturer mute hint. Code: ${err.code}, message: ${err.message}`);
});
```

## isOtherMediaPlaying<sup>23+</sup>

isOtherMediaPlaying(): boolean

检查是否有其他应用正在播放MUSIC、MOVIE、AUDIOBOOK、GAME四种媒体类型的音频，已激活媒体类型的音频会话也将会被检查。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**返回值：**

| 类型                                              | 说明                                    |
| ------------------------------------------------- |---------------------------------------|
| boolean | 是否有其他应用正在播放媒体类型的音频。true表示有，false表示没有。 |

**示例：**

```ts
let isExistence = audioSessionManager.isOtherMediaPlaying();
```

## setAudioSessionBehavior<sup>24+</sup>

setAudioSessionBehavior(behavior: number): void

设置音频会话行为参数，支持多种标志位的组合使用。

> **说明：**
>
> 当音频会话在激活状态时调用此接口后，必须重新调用接口[activateAudioSession](#activateaudiosession12)使其生效。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Multimedia.Audio.Core

**参数：**

| 参数名   | 类型               | 必填 | 说明      |
| -------- | ----------------- | ---- | --------- |
| behavior   | number           | 是   | 用于设置音频会话行为。<br>该参数可以是单个标志，也可以是多个标志的按位OR组合。<br>当前支持的音频会话行为详见[AudioSessionBehaviorFlags](./arkts-apis-audio-e.md#audiosessionbehaviorflags24)中定义的标志。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permitted in the current state. |

**示例：**

```ts
// 设置音频会话行为为被打断时静音，当音频被其他应用打断时自动静音。
let behavior: number = audio.AudioSessionBehaviorFlags.MUTE_WHEN_INTERRUPTED;
audioSessionManager.setAudioSessionBehavior(behavior);
```
