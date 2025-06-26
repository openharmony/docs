# Interface (AudioRenderer)

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

提供音频渲染的相关接口。

在使用AudioRenderer的接口之前，需先通过[createAudioRenderer](arkts-apis-audio-f.md#audiocreateaudiorenderer8)获取AudioRenderer实例。

## 属性

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

| 名称  | 类型                     | 只读 | 可选 | 说明               |
| ----- | -------------------------- | ---- | ---- | ------------------ |
| state<sup>8+</sup> | [AudioState](arkts-apis-audio-e.md#audiostate8) | 是   | 否   | 音频渲染器的状态。 |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let state: audio.AudioState = audioRenderer.state;
```

## getRendererInfo<sup>8+</sup>

getRendererInfo(callback: AsyncCallback<AudioRendererInfo\>): void

获取当前创建的音频渲染器信息。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                     | 必填 | 说明                   |
| :------- | :------------------------------------------------------- | :--- | :--------------------- |
| callback | AsyncCallback<[AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)\> | 是   | 回调函数。当获取音频渲染器的信息成功，err为undefined，data为获取到的音频渲染器的信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo((err: BusinessError, rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`);
});
```

## getRendererInfo<sup>8+</sup>

getRendererInfo(): Promise<AudioRendererInfo\>

获取当前创建的音频渲染器信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                               | 说明                            |
| -------------------------------------------------- | ------------------------------- |
| Promise<[AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8)\> | Promise对象，返回音频渲染器信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRendererInfo().then((rendererInfo: audio.AudioRendererInfo) => {
  console.info('Renderer GetRendererInfo:');
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${err}`);
});
```

## getRendererInfoSync<sup>10+</sup>

getRendererInfoSync(): AudioRendererInfo

获取当前创建的音频渲染器信息。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                               | 说明                            |
| -------------------------------------------------- | ------------------------------- |
| [AudioRendererInfo](arkts-apis-audio-i.md#audiorendererinfo8) | 返回音频渲染器信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let rendererInfo: audio.AudioRendererInfo = audioRenderer.getRendererInfoSync();
  console.info(`Renderer content: ${rendererInfo.content}`);
  console.info(`Renderer usage: ${rendererInfo.usage}`);
  console.info(`Renderer flags: ${rendererInfo.rendererFlags}`)
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: RendererInfo :ERROR: ${error}`);
}
```

## getStreamInfo<sup>8+</sup>

getStreamInfo(callback: AsyncCallback<AudioStreamInfo\>): void

获取音频流信息。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<[AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)\> | 是   | 回调函数。当获取音频流信息成功，err为undefined，data为获取到的音频流信息；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo((err: BusinessError, streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
});
```

## getStreamInfo<sup>8+</sup>

getStreamInfo(): Promise<AudioStreamInfo\>

获取音频流信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| Promise<[AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8)\> | Promise对象，返回音频流信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getStreamInfo().then((streamInfo: audio.AudioStreamInfo) => {
  console.info('Renderer GetStreamInfo:');
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getStreamInfoSync<sup>10+</sup>

getStreamInfoSync(): AudioStreamInfo

获取音频流信息。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| [AudioStreamInfo](arkts-apis-audio-i.md#audiostreaminfo8) | 返回音频流信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamInfo: audio.AudioStreamInfo = audioRenderer.getStreamInfoSync();
  console.info(`Renderer sampling rate: ${streamInfo.samplingRate}`);
  console.info(`Renderer channel: ${streamInfo.channels}`);
  console.info(`Renderer format: ${streamInfo.sampleFormat}`);
  console.info(`Renderer encoding type: ${streamInfo.encodingType}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getAudioStreamId<sup>9+</sup>

getAudioStreamId(callback: AsyncCallback<number\>): void

获取音频流id。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                 |
| :------- | :--------------------------------------------------- | :--- | :------------------- |
| callback | AsyncCallback<number\> | 是   | 回调函数。当获取音频流id成功，err为undefined，data为获取到的音频流id；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId((err: BusinessError, streamId: number) => {
  console.info(`Renderer GetStreamId: ${streamId}`);
});
```

## getAudioStreamId<sup>9+</sup>

getAudioStreamId(): Promise<number\>

获取音频流id。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| Promise<number\> | Promise对象，返回音频流id。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioStreamId().then((streamId: number) => {
  console.info(`Renderer getAudioStreamId: ${streamId}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioStreamIdSync<sup>10+</sup>

getAudioStreamIdSync(): number

获取音频流id。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                           | 说明                   |
| :--------------------------------------------- | :--------------------- |
| number | 返回音频流id。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let streamId: number = audioRenderer.getAudioStreamIdSync();
  console.info(`Renderer getAudioStreamIdSync: ${streamId}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode, callback: AsyncCallback\<void>): void

设置当前音效模式。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| mode     | [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)    | 是   | 音效模式。               |
| callback | AsyncCallback\<void>                     | 是   | 回调函数。当设置当前音效模式成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ----------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.  |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful audio effect mode setting.');
  }
});
```

## setAudioEffectMode<sup>10+</sup>

setAudioEffectMode(mode: AudioEffectMode): Promise\<void>

设置当前音效模式。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明         |
| ------ | ---------------------------------------- | ---- | ------------ |
| mode   | [AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)   | 是   | 音效模式。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | ---------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setAudioEffectMode(audio.AudioEffectMode.EFFECT_DEFAULT).then(() => {
  console.info('setAudioEffectMode SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(callback: AsyncCallback\<AudioEffectMode>): void

获取当前音效模式。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明               |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)> | 是   | 回调函数。当获取当前音效模式成功，err为undefined，data为获取到的当前音效模式；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode((err: BusinessError, effectMode: audio.AudioEffectMode) => {
  if (err) {
    console.error('Failed to get params');
  } else {
    console.info(`getAudioEffectMode: ${effectMode}`);
  }
});
```

## getAudioEffectMode<sup>10+</sup>

getAudioEffectMode(): Promise\<AudioEffectMode>

获取当前音效模式。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明                      |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioEffectMode](arkts-apis-audio-e.md#audioeffectmode10)> | Promise对象，返回当前音效模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioEffectMode().then((effectMode: audio.AudioEffectMode) => {
  console.info(`getAudioEffectMode: ${effectMode}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## start<sup>8+</sup>

start(callback: AsyncCallback<void\>): void

启动音频渲染器。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当启动音频渲染器成功，err为undefined，否则为错误对象。异常将返回error对象：<br>错误码6800301：表示包含状态检查异常、焦点抢占失败、系统处理异常（具体错误查看系统日志）。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start((err: BusinessError) => {
  if (err) {
    console.error('Renderer start failed.');
  } else {
    console.info('Renderer start success.');
  }
});
```

## start<sup>8+</sup>

start(): Promise<void\>

启动音频渲染器。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象，成功表示启动音频渲染器成功。异常将返回error对象：<br>错误码6800301：表示包含状态检查异常、焦点抢占失败、系统处理异常（具体错误查看系统日志）。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

暂停音频渲染。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当暂停渲染成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause((err: BusinessError) => {
  if (err) {
    console.error('Renderer pause failed');
  } else {
    console.info('Renderer paused.');
  }
});
```

## pause<sup>8+</sup>

pause(): Promise\<void>

暂停音频渲染。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.pause().then(() => {
  console.info('Renderer paused');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## drain<sup>8+</sup>

drain(callback: AsyncCallback\<void>): void

检查缓冲区是否已被耗尽。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当检查缓冲区是否已被耗尽成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain((err: BusinessError) => {
  if (err) {
    console.error('Renderer drain failed');
  } else {
    console.info('Renderer drained.');
  }
});
```

## drain<sup>8+</sup>

drain(): Promise\<void>

检查缓冲区是否已被耗尽。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.drain().then(() => {
  console.info('Renderer drained successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## flush<sup>11+</sup>

flush(): Promise\<void>

清空缓冲区（[AudioState](arkts-apis-audio-e.md#audiostate8)为STATE_RUNNING、STATE_PAUSED、STATE_STOPPED状态下可用）。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.flush().then(() => {
  console.info('Renderer flushed successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

停止音频渲染。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当停止渲染成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop((err: BusinessError) => {
  if (err) {
    console.error('Renderer stop failed');
  } else {
    console.info('Renderer stopped.');
  }
});
```

## stop<sup>8+</sup>

stop(): Promise\<void>

停止音频渲染。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.stop().then(() => {
  console.info('Renderer stopped successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

释放音频渲染器。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。当释放音频渲染器成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release((err: BusinessError) => {
  if (err) {
    console.error('Renderer release failed');
  } else {
    console.info('Renderer released.');
  }
});
```

## release<sup>8+</sup>

release(): Promise\<void>

释放音频渲染器。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.release().then(() => {
  console.info('Renderer released successfully');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTime<sup>8+</sup>

getAudioTime(callback: AsyncCallback\<number>): void

获取当前播放位置的时间戳（从1970年1月1日开始），单位为纳秒。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明             |
| -------- | ---------------------- | ---- | ---------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当获取时间戳成功，err为undefined，data为获取到的时间戳；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime((err: BusinessError, timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
});
```

## getAudioTime<sup>8+</sup>

getAudioTime(): Promise\<number>

获取当前播放位置的时间戳（从1970年1月1日开始），单位为纳秒。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 描述                    |
| ---------------- | ----------------------- |
| Promise\<number> | Promise对象，返回时间戳。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTime().then((timestamp: number) => {
  console.info(`Current timestamp: ${timestamp}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTimeSync<sup>10+</sup>

getAudioTimeSync(): number

获取当前播放位置的时间戳（从1970年1月1日开始），单位为纳秒。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 描述                    |
| ---------------- | ----------------------- |
| number | 返回时间戳。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let timestamp: number = audioRenderer.getAudioTimeSync();
  console.info(`Current timestamp: ${timestamp}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getAudioTimestampInfo<sup>19+</sup>

getAudioTimestampInfo(): Promise\<AudioTimestampInfo>

获取音频流时间戳和当前数据帧位置信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                                    | 描述                    |
|-------------------------------------------------------| ----------------------- |
| Promise\<[AudioTimestampInfo](arkts-apis-audio-i.md#audiotimestampinfo19)> | Promise对象，返回音频流时间戳和当前数据帧位置信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getAudioTimestampInfo().then((audioTimestampInfo: audio.AudioTimestampInfo) => {
  console.info(`Current timestamp: ${audioTimestampInfo.timestamp}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getAudioTimestampInfoSync<sup>19+</sup>

getAudioTimestampInfoSync(): AudioTimestampInfo

获取音频流时间戳和当前数据帧位置信息。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 描述                    |
| ---------------- | ----------------------- |
| [AudioTimestampInfo](arkts-apis-audio-i.md#audiotimestampinfo19) | 返回音频流时间戳和当前数据帧位置信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800103 | Operation not permit at current state. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let audioTimestampInfo: audio.AudioTimestampInfo = audioRenderer.getAudioTimestampInfoSync();
  console.info(`Current timestamp: ${audioTimestampInfo.timestamp}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```

## getBufferSize<sup>8+</sup>

getBufferSize(callback: AsyncCallback\<number>): void

获取音频渲染器的最小缓冲区大小。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当获取音频渲染器的最小缓冲区大小成功，err为undefined，data为获取到的最小缓冲区大小；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;

audioRenderer.getBufferSize((err: BusinessError, data: number) => {
  if (err) {
    console.error('getBufferSize error');
  } else {
    console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
    bufferSize = data;
  }
});
```

## getBufferSize<sup>8+</sup>

getBufferSize(): Promise\<number>

获取音频渲染器的最小缓冲区大小。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| Promise\<number> | Promise对象，返回缓冲区大小。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number;

audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## getBufferSizeSync<sup>10+</sup>

getBufferSizeSync(): number

获取音频渲染器的最小缓冲区大小。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| number | 返回缓冲区大小。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let bufferSize: number = 0;

try {
  bufferSize = audioRenderer.getBufferSizeSync();
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${bufferSize}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${error}`);
}
```

## setSpeed<sup>11+</sup>

setSpeed(speed: number): void

设置播放倍速。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                   |
| ------ | ---------------------------------------- | ---- |----------------------|
| speed | number | 是   | 设置播放的倍速值（倍速范围：0.125-4.0）。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioRenderer.setSpeed(1.5);
```

## getSpeed<sup>11+</sup>

getSpeed(): number

获取播放倍速。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明        |
| ------------------------------------------------- |-----------|
| number | 返回播放的倍速值。 |

**示例：**

```ts
let speed = audioRenderer.getSpeed();
```

## setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode): Promise&lt;void&gt;

设置应用的焦点模型。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名     | 类型                                | 必填   | 说明        |
| ---------- | ---------------------------------- | ------ | ---------- |
| mode       | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)    | 是     | 焦点模型。  |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 0;

audioRenderer.setInterruptMode(mode).then(() => {
  console.info('setInterruptMode Success!');
}).catch((err: BusinessError) => {
  console.error(`setInterruptMode Fail: ${err}`);
});
```
## setInterruptMode<sup>9+</sup>

setInterruptMode(mode: InterruptMode, callback: AsyncCallback\<void>): void

设置应用的焦点模型。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名   | 类型                                | 必填   | 说明            |
| ------- | ----------------------------------- | ------ | -------------- |
|mode     | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)     | 是     | 焦点模型。|
|callback | AsyncCallback\<void>                 | 是     |回调函数。当设置应用的焦点模型成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let mode = 1;

audioRenderer.setInterruptMode(mode, (err: BusinessError) => {
  if(err){
    console.error(`setInterruptMode Fail: ${err}`);
  }
  console.info('setInterruptMode Success!');
});
```

## setInterruptModeSync<sup>10+</sup>

setInterruptModeSync(mode: InterruptMode): void

设置应用的焦点模型。同步设置。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名     | 类型                                | 必填   | 说明        |
| ---------- | ---------------------------------- | ------ | ---------- |
| mode       | [InterruptMode](arkts-apis-audio-e.md#interruptmode9)    | 是     | 焦点模型。  |

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
  audioRenderer.setInterruptModeSync(0);
  console.info('setInterruptMode Success!');
} catch (err) {
  let error = err as BusinessError;
  console.error(`setInterruptMode Fail: ${error}`);
}
```

## setVolume<sup>9+</sup>

setVolume(volume: number): Promise&lt;void&gt;

设置音频流的音量。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型    | 必填   | 说明                 |
| ---------- | ------- | ------ | ------------------- |
| volume     | number  | 是     | 音量值范围为[0.0, 1.0]。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5).then(() => {
  console.info('setVolume Success!');
}).catch((err: BusinessError) => {
  console.error(`setVolume Fail: ${err}`);
});
```
## setVolume<sup>9+</sup>

setVolume(volume: number, callback: AsyncCallback\<void>): void

设置音频流的音量。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|volume   | number     | 是     | 音量值范围为[0.0, 1.0]。 |
|callback | AsyncCallback\<void> | 是     |回调函数。当设置应用的音量成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setVolume(0.5, (err: BusinessError) => {
  if(err){
    console.error(`setVolume Fail: ${err}`);
    return;
  }
  console.info('setVolume Success!');
});
```
## getVolume<sup>12+</sup>

getVolume(): number

获取音频流的音量。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型             | 说明                        |
| ---------------- | --------------------------- |
| number | 返回音量大小，音量值范围为[0.0, 1.0]。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getVolume();
  console.info(`Indicate that the volume is obtained ${value}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume, error ${error}.`);
}
```

## getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(callback: AsyncCallback&lt;number&gt;): void

获取音频流的最小音量。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|callback |AsyncCallback&lt;number&gt; | 是     |回调函数。当获取音频流的最小音量成功，err为undefined，data为获取到的应用基于音频流的最小音量（音量范围[0, 1]）；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume((err: BusinessError, minVolume: number) => {
  if (err) {
    console.error(`getMinStreamVolume error: ${err}`);
  } else {
    console.info(`getMinStreamVolume Success! ${minVolume}`);
  }
});
```
## getMinStreamVolume<sup>10+</sup>

getMinStreamVolume(): Promise&lt;number&gt;

获取音频流的最小音量。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise对象，返回音频流最小音量（音量范围[0, 1]）。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMinStreamVolume().then((value: number) => {
  console.info(`Get min stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get min stream volume Fail: ${err}`);
});
```

## getMinStreamVolumeSync<sup>10+</sup>

getMinStreamVolumeSync(): number

获取音频流的最小音量。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| number| 返回音频流最小音量（音量范围[0, 1]）。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMinStreamVolumeSync();
  console.info(`Get min stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get min stream volume Fail: ${error}`);
}
```

## getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(callback: AsyncCallback&lt;number&gt;): void

获取音频流的最大音量。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback&lt;number&gt; | 是     |回调函数。当获取音频流的最大音量成功，err为undefined，data为获取到的应用基于音频流的最大音量（音量范围[0, 1]）；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume((err: BusinessError, maxVolume: number) => {
  if (err) {
    console.error(`getMaxStreamVolume Fail: ${err}`);
  } else {
    console.info(`getMaxStreamVolume Success! ${maxVolume}`);
  }
});
```
## getMaxStreamVolume<sup>10+</sup>

getMaxStreamVolume(): Promise&lt;number&gt;

获取音频流的最大音量。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise对象，返回音频流最大音量（音量范围[0, 1]）。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getMaxStreamVolume().then((value: number) => {
  console.info(`Get max stream volume Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get max stream volume Fail: ${err}`);
});
```

## getMaxStreamVolumeSync<sup>10+</sup>

getMaxStreamVolumeSync(): number

获取音频流的最大音量。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| number| 返回音频流最大音量（音量范围[0, 1]）。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getMaxStreamVolumeSync();
  console.info(`Get max stream volume Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get max stream volume Fail: ${error}`);
}
```

## getUnderflowCount<sup>10+</sup>

getUnderflowCount(callback: AsyncCallback&lt;number&gt;): void

获取当前播放音频流的欠载音频帧数量。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback&lt;number&gt; | 是     |回调函数。当获取当前播放音频流的欠载音频帧数量成功，err为undefined，data为获取到的当前播放音频流的欠载音频帧数量；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount((err: BusinessError, underflowCount: number) => {
  if (err) {
    console.error(`getUnderflowCount Fail: ${err}`);
  } else {
    console.info(`getUnderflowCount Success! ${underflowCount}`);
  }
});
```
## getUnderflowCount<sup>10+</sup>

getUnderflowCount(): Promise&lt;number&gt;

获取当前播放音频流的欠载音频帧数量。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;number&gt;| Promise对象，返回音频流的欠载音频帧数量。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getUnderflowCount().then((value: number) => {
  console.info(`Get underflow count Success! ${value}`);
}).catch((err: BusinessError) => {
  console.error(`Get underflow count Fail: ${err}`);
});
```

## getUnderflowCountSync<sup>10+</sup>

getUnderflowCountSync(): number

获取当前播放音频流的欠载音频帧数量，同步返回数据。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| number| 返回音频流的欠载音频帧数量。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let value: number = audioRenderer.getUnderflowCountSync();
  console.info(`Get underflow count Success! ${value}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get underflow count Fail: ${error}`);
}
```

## getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频流输出设备信息。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名  | 类型       | 必填   | 说明                 |
| ------- | -----------| ------ | ------------------- |
|callback | AsyncCallback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)>| 是     |回调函数。当获取音频流输出设备信息成功，err为undefined，data为获取到的音频流输出设备信息；否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices((err: BusinessError, deviceInfo: audio.AudioDeviceDescriptors) => {
  if (err) {
    console.error(`getCurrentOutputDevices Fail: ${err}`);
  } else {
    for (let i = 0; i < deviceInfo.length; i++) {
      console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
      console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
      console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
      console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
      console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
      console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
      console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
      console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
    }
  }
});
```
## getCurrentOutputDevices<sup>10+</sup>

getCurrentOutputDevices(): Promise&lt;AudioDeviceDescriptors&gt;

获取音频流输出设备信息。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)&gt;| Promise对象，返回音频流的输出设备信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getCurrentOutputDevices().then((deviceInfo: audio.AudioDeviceDescriptors) => {
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
}).catch((err: BusinessError) => {
  console.error(`Get current output devices Fail: ${err}`);
});
```

## getCurrentOutputDevicesSync<sup>10+</sup>

getCurrentOutputDevicesSync(): AudioDeviceDescriptors

获取音频流输出设备信息。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| [AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors) | 返回音频流的输出设备信息。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let deviceInfo: audio.AudioDeviceDescriptors = audioRenderer.getCurrentOutputDevicesSync();
  for (let i = 0; i < deviceInfo.length; i++) {
    console.info(`DeviceInfo id: ${deviceInfo[i].id}`);
    console.info(`DeviceInfo type: ${deviceInfo[i].deviceType}`);
    console.info(`DeviceInfo role: ${deviceInfo[i].deviceRole}`);
    console.info(`DeviceInfo name: ${deviceInfo[i].name}`);
    console.info(`DeviceInfo address: ${deviceInfo[i].address}`);
    console.info(`DeviceInfo samplerate: ${deviceInfo[i].sampleRates[0]}`);
    console.info(`DeviceInfo channelcount: ${deviceInfo[i].channelCounts[0]}`);
    console.info(`DeviceInfo channelmask: ${deviceInfo[i].channelMasks[0]}`);
  }
} catch (err) {
  let error = err as BusinessError;
  console.error(`Get current output devices Fail: ${error}`);
}
```
## setChannelBlendMode<sup>11+</sup>

setChannelBlendMode(mode: ChannelBlendMode): void

设置单双声道混合模式。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| mode | [ChannelBlendMode](arkts-apis-audio-e.md#channelblendmode11) | 是   | 声道混合模式类型。                                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state.    |

**示例：**

```ts
let mode = audio.ChannelBlendMode.MODE_DEFAULT;

audioRenderer.setChannelBlendMode(mode);
console.info(`BlendMode: ${mode}`);
```
## setVolumeWithRamp<sup>11+</sup>

setVolumeWithRamp(volume: number, duration: number): void

设置音量渐变模式。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volume     | number | 是   | 渐变目标音量值，音量范围为[0.0, 1.0]。                                             |
| duration     | number | 是   | 渐变持续时间，单位为ms。                                             |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
let volume = 0.5;
let duration = 1000;

audioRenderer.setVolumeWithRamp(volume, duration);
console.info(`setVolumeWithRamp: ${volume}`);
```

## setSilentModeAndMixWithOthers<sup>12+</sup>

setSilentModeAndMixWithOthers(on: boolean): void

设置静音并发播放模式。

当设置为true，打开静音并发播放模式，系统将让此音频流静音播放，并且不会打断其他音频流。设置为false，将关闭静音并发播放，音频流可根据系统焦点策略抢占焦点。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                   |
| ------ | ---------------------------------------- | ---- |----------------------|
| on | boolean | 是   | 打开/关闭静音并发播放模式。true表示打开，false表示关闭。 |

**示例：**

```ts
audioRenderer.setSilentModeAndMixWithOthers(true);
```

## getSilentModeAndMixWithOthers<sup>12+</sup>

getSilentModeAndMixWithOthers(): boolean

获取静音并发播放模式。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明        |
| ------------------------------------------------- |-----------|
| boolean | 静音并发播放模式状态。返回true表示打开，返回false表示关闭。 |

**示例：**

```ts
let on = audioRenderer.getSilentModeAndMixWithOthers();
```

## setDefaultOutputDevice<sup>12+</sup>

setDefaultOutputDevice(deviceType: DeviceType): Promise&lt;void&gt;

设置默认发声设备。使用Promise异步回调。

> **说明：**
>
> - 本接口仅适用于[StreamUsage](arkts-apis-audio-e.md#streamusage)为语音消息、VoIP语音通话或者VoIP视频通话的场景，支持听筒、扬声器和系统默认设备。
>
> - 本接口允许在AudioRenderer创建后随时调用，系统记录应用设置的默认本机内置发声设备。应用启动播放时，若外接设备如蓝牙耳机或有线耳机已接入，系统优先从外接设备发声；否则，系统遵循应用设置的默认本机内置发声设备。
>
> - 本接口优先级低于[AVCastPicker](../apis-avsession-kit/ohos-multimedia-avcastpicker.md#avcastpicker)。如果使用AVCastPicker切换过发声设备，再次调用本接口切换设备将不生效。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名     | 类型             | 必填   | 说明                                                      |
| ---------- |----------------| ------ |---------------------------------------------------------|
| deviceType | [DeviceType](arkts-apis-audio-e.md#devicetype) | 是     | 设备类型。<br>仅支持以下设备：EARPIECE（听筒）、SPEAKER（扬声器）和DEFAULT（系统默认设备）。 |

**返回值：**

| 类型                | 说明                          |
| ------------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |
| 6800103 | Operation not permit at current state.    |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// 本接口允许在AudioRenderer创建以后的任何时间被调用。
// 未播放时调用，系统会记录应用设置的默认本机内置发声设备，当应用启动播放时从设置的默认本机内置发声设备发声。
// 正在播放时调用，在没有外接设备如蓝牙耳机/有线耳机，系统会立即切换到设置的默认本机内置发声设备发声；否则系统会先记录应用设置的默认本机内置发声设备，等外接设备移除后再切换到设置的默认本机内置发声设备发声。
audioRenderer.setDefaultOutputDevice(audio.DeviceType.SPEAKER).then(() => {
  console.info('setDefaultOutputDevice Success!');
}).catch((err: BusinessError) => {
  console.error(`setDefaultOutputDevice Fail: ${err}`);
});
```

## on('audioInterrupt')<sup>9+</sup>

on(type: 'audioInterrupt', callback: Callback\<InterruptEvent>): void

监听音频中断事件（当音频焦点发生变化时触发）。使用callback异步回调。

AudioRenderer对象在start事件时获取焦点，在pause、stop等事件时释放焦点，无需开发者主动申请。

调用此方法后，如果AudioRenderer对象获取焦点失败或发生中断事件（如被其他音频打断等），会收到[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)。建议应用根据InterruptEvent的信息进行进一步处理。更多信息请参阅文档[音频焦点和音频会话介绍](../../media/audio/audio-playback-concurrency.md)。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                        |
| -------- | -------------------------------------------- | ---- | ----------------------------------------------------------- |
| type     | string                                       | 是   | 事件回调类型，支持的事件为'audioInterrupt'，当音频焦点状态发生变化时，触发该事件。 |
| callback | Callback\<[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)\> | 是   | 回调函数，返回中断事件信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

let isPlaying: boolean; // 标识符，表示是否正在渲染。
let isDucked: boolean; // 标识符，表示是否被降低音量。
onAudioInterrupt();

async function onAudioInterrupt(){
  audioRenderer.on('audioInterrupt', (interruptEvent: audio.InterruptEvent) => {
    // 在发生音频打断事件时，audioRenderer收到interruptEvent回调，此处根据其内容做相应处理。
    // 1. 可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
    // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
    // 2. 必选：读取interruptEvent.hintType的类型，做出相应的处理。
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
          console.info('Invalid interruptEvent');
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
          console.info('Invalid interruptEvent');
          break;
      }
    }
  });
}
```

## off('audioInterrupt')<sup>18+</sup>

off(type: 'audioInterrupt', callback?: Callback&lt;InterruptEvent&gt;): void

取消监听音频中断事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Interrupt

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                         |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string | 是   | 事件回调类型，支持的事件为'audioInterrupt'，当取消监听音频中断事件时，触发该事件。 |
| callback | Callback\<[InterruptEvent](arkts-apis-audio-i.md#interruptevent9)\> | 否 |  回调函数，返回中断事件信息。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('audioInterrupt');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let isPlaying: boolean; // 标识符，表示是否正在渲染。
let isDucked: boolean; // 标识符，表示是否被降低音量。

let audioInterruptCallback = (interruptEvent: audio.InterruptEvent) => {
  // 在发生音频打断事件时，audioRenderer收到interruptEvent回调，此处根据其内容做相应处理。
  // 1. 可选：读取interruptEvent.forceType的类型，判断系统是否已强制执行相应操作。
  // 注：默认焦点策略下，INTERRUPT_HINT_RESUME为INTERRUPT_SHARE类型，其余hintType均为INTERRUPT_FORCE类型。因此对forceType可不做判断。
  // 2. 必选：读取interruptEvent.hintType的类型，做出相应的处理。
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
        console.info('Invalid interruptEvent');
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
        console.info('Invalid interruptEvent');
        break;
    }
  }
};

audioRenderer.on('audioInterrupt', audioInterruptCallback);

audioRenderer.off('audioInterrupt', audioInterruptCallback);
```

## on('markReach')<sup>8+</sup>

on(type: 'markReach', frame: number, callback: Callback&lt;number&gt;): void

监听标记到达事件（当渲染的帧数到达frame参数的值时触发，仅调用一次）。使用callback异步回调。

如果将frame设置为100，当渲染帧数到达第100帧时，系统将上报信息。

**系统能力:** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                      |
| :------- | :----------------------- | :--- | :---------------------------------------- |
| type     | string                   | 是   | 事件回调类型，支持的事件为'markReach'，当渲染的帧数到达frame参数的值时，触发该事件。 |
| frame    | number                   | 是   | 触发事件的帧数。该值必须大于0。         |
| callback | Callback\<number>         | 是   | 回调函数，返回frame参数的值。 |

**示例：**

```ts
audioRenderer.on('markReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```


## off('markReach')<sup>8+</sup>

off(type: 'markReach', callback?: Callback&lt;number&gt;): void

取消监听标记到达事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| :----- | :----- | :--- | :------------------------------------------------ |
| type   | string | 是   | 事件回调类型，支持的事件为'markReach'，当取消监听标记到达事件时，触发该事件。 |
| callback<sup>18+</sup> | Callback\<number>         | 否  | 回调函数，返回frame参数的值。 |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('markReach');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let markReachCallback = (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
};

audioRenderer.on('markReach', 1000, markReachCallback);

audioRenderer.off('markReach', markReachCallback);
```

## on('periodReach')<sup>8+</sup>

on(type: 'periodReach', frame: number, callback: Callback&lt;number&gt;): void

监听标记到达事件（每当渲染的帧数达到frame参数的值时触发，即按周期上报信息）。使用callback异步回调。

如果将frame设置为10，每渲染10帧数据均会上报信息（例如：第10帧、第20帧、第30帧......）。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                     | 必填 | 说明                                        |
| :------- | :----------------------- | :--- | :------------------------------------------ |
| type     | string                   | 是   | 事件回调类型，支持的事件为'periodReach'，当渲染的帧数达到frame参数的值时，触发该事件。 |
| frame    | number                   | 是   | 触发事件的帧数。该值必须大于 0。           |
| callback | Callback\<number>         | 是   | 回调函数，返回frame参数的值。 |

**示例：**

```ts
audioRenderer.on('periodReach', 1000, (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
});
```

## off('periodReach')<sup>8+</sup>

off(type: 'periodReach', callback?: Callback&lt;number&gt;): void

取消监听标记到达事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | 是   | 事件回调类型，支持的事件为'periodReach'，当取消监听标记到达事件时，触发该事件。 |
| callback<sup>18+</sup> | Callback\<number>         | 否  | 回调函数，返回frame参数的值。 |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('periodReach');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let periodReachCallback = (position: number) => {
  if (position == 1000) {
    console.info('ON Triggered successfully');
  }
};

audioRenderer.on('periodReach', 1000, periodReachCallback);

audioRenderer.off('periodReach', periodReachCallback);
```

## on('stateChange')<sup>8+</sup>

on(type: 'stateChange', callback: Callback<AudioState\>): void

监听状态变化事件（当AudioRenderer的状态发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为'stateChange'，当AudioRenderer的状态发生变化时，触发该事件。 |
| callback | Callback\<[AudioState](arkts-apis-audio-e.md#audiostate8)> | 是   | 回调函数，返回当前音频的状态。 |

**示例：**

```ts
audioRenderer.on('stateChange', (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
});
```

## off('stateChange')<sup>18+</sup>

off(type: 'stateChange', callback?: Callback&lt;AudioState&gt;): void

取消监听到达标记事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                |
| :----- | :----- | :--- | :-------------------------------------------------- |
| type   | string | 是   | 事件回调类型，支持的事件为'stateChange'，当取消监听到达标记事件时，触发该事件。 |
| callback | Callback\<[AudioState](arkts-apis-audio-e.md#audiostate8)> | 否 | 回调函数，返回当前音频的状态。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('stateChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let stateChangeCallback = (state: audio.AudioState) => {
  if (state == 1) {
    console.info('audio renderer state is: STATE_PREPARED');
  }
  if (state == 2) {
    console.info('audio renderer state is: STATE_RUNNING');
  }
};

audioRenderer.on('stateChange', stateChangeCallback);

audioRenderer.off('stateChange', stateChangeCallback);
```

## on('outputDeviceChange')<sup>10+</sup>

on(type: 'outputDeviceChange', callback: Callback\<AudioDeviceDescriptors>): void

监听音频输出设备变化事件（当音频输出设备发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为'outputDeviceChange'，当音频输出设备发生变化时，触发该事件。 |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 是   | 回调函数，返回当前音频流的输出设备描述信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioRenderer.on('outputDeviceChange', (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
});
```

## off('outputDeviceChange')<sup>10+</sup>

off(type: 'outputDeviceChange', callback?: Callback\<AudioDeviceDescriptors>): void

取消监听音频输出设备变化事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                       | 必填 | 说明                                        |
| :------- | :------------------------- | :--- | :------------------------------------------ |
| type     | string                     | 是   | 事件回调类型，支持的事件为'outputDeviceChange'，当取消监听音频输出设备变化事件时，触发该事件。 |
| callback | Callback\<[AudioDeviceDescriptors](arkts-apis-audio-t.md#audiodevicedescriptors)> | 否   | 回调函数，返回当前音频流的输出设备描述信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('outputDeviceChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let outputDeviceChangeCallback = (deviceInfo: audio.AudioDeviceDescriptors) => {
  console.info(`DeviceInfo id: ${deviceInfo[0].id}`);
  console.info(`DeviceInfo name: ${deviceInfo[0].name}`);
  console.info(`DeviceInfo address: ${deviceInfo[0].address}`);
};

audioRenderer.on('outputDeviceChange', outputDeviceChangeCallback);

audioRenderer.off('outputDeviceChange', outputDeviceChangeCallback);
```

## on('outputDeviceChangeWithInfo')<sup>11+</sup>

on(type: 'outputDeviceChangeWithInfo', callback: Callback\<AudioStreamDeviceChangeInfo>): void

监听音频流输出设备变化及原因事件（当音频输出设备发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                                       | 必填 | 说明                                          |
| :------- |:-------------------------------------------------------------------------| :--- |:--------------------------------------------|
| type     | string                                                                   | 是   | 事件回调类型，支持的事件为'outputDeviceChangeWithInfo'，当音频输出设备发生变化时，触发该事件。 |
| callback | Callback\<[AudioStreamDeviceChangeInfo](arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 是   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioRenderer.on('outputDeviceChangeWithInfo', (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
});
```

## off('outputDeviceChangeWithInfo')<sup>11+</sup>

off(type: 'outputDeviceChangeWithInfo', callback?: Callback\<AudioStreamDeviceChangeInfo>): void

取消监听音频流输出设备变化及原因事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Device

**参数：**

| 参数名   | 类型                                                                       | 必填 | 说明                                          |
| :------- |:-------------------------------------------------------------------------| :--- |:--------------------------------------------|
| type     | string | 是   | 事件回调类型，支持的事件为'outputDeviceChangeWithInfo'，当取消监听音频流输出设备变化及原因事件时，触发该事件。 |
| callback | Callback\<[AudioStreamDeviceChangeInfo](arkts-apis-audio-i.md#audiostreamdevicechangeinfo11)> | 否   | 回调函数，返回当前音频流的输出设备描述信息及变化原因。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('outputDeviceChangeWithInfo');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let outputDeviceChangeWithInfoCallback = (deviceChangeInfo: audio.AudioStreamDeviceChangeInfo) => {
  console.info(`DeviceInfo id: ${deviceChangeInfo.devices[0].id}`);
  console.info(`DeviceInfo name: ${deviceChangeInfo.devices[0].name}`);
  console.info(`DeviceInfo address: ${deviceChangeInfo.devices[0].address}`);
  console.info(`Device change reason: ${deviceChangeInfo.changeReason}`);
};

audioRenderer.on('outputDeviceChangeWithInfo', outputDeviceChangeWithInfoCallback);

audioRenderer.off('outputDeviceChangeWithInfo', outputDeviceChangeWithInfoCallback);
```

## on('writeData')<sup>11+</sup>

on(type: 'writeData', callback: AudioRendererWriteDataCallback): void

监听音频数据写入回调事件（当需要写入音频数据时触发），使用 callback 方式返回结果。

回调函数仅用来写入音频数据，请勿在回调函数中调用AudioRenderer相关接口。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                  |
| :------- |:--------------------------------| :--- |:--------------------------------------|
| type     | string                           | 是   | 事件回调类型，支持的事件为'writeData'，当需要写入音频数据时，触发该事件。 |
| callback | [AudioRendererWriteDataCallback](arkts-apis-audio-t.md#audiorendererwritedatacallback12)   | 是   | 回调函数，入参代表应用接收待写入的数据缓冲区。<br>API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果[AudioDataCallbackResult](arkts-apis-audio-e.md#audiodatacallbackresult12)。        |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import {fileIo as fs} from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let path = context.cacheDir;
// 确保该沙箱路径下存在该资源。
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };

  try {
    fs.readSync(file.fd, buffer, options);
    bufferSize += buffer.byteLength;
    // API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果。
    return audio.AudioDataCallbackResult.VALID;
  } catch (error) {
    console.error('Error reading file:', error);
    // API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果。
    return audio.AudioDataCallbackResult.INVALID;
  }
};

audioRenderer.on('writeData', writeDataCallback);
audioRenderer.start().then(() => {
  console.info('Renderer started');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## off('writeData')<sup>11+</sup>

off(type: 'writeData', callback?: AudioRendererWriteDataCallback): void

取消监听音频数据写入回调事件。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                             | 必填 | 说明                                  |
| :------- |:--------------------------------| :--- |:--------------------------------------|
| type     | string                           | 是   | 事件回调类型，支持的事件为'writeData'，当取消监听音频数据写入回调事件时，触发该事件。 |
| callback | [AudioRendererWriteDataCallback](arkts-apis-audio-t.md#audiorendererwritedatacallback12)   | 否   | 回调函数，入参代表应用接收待写入的数据缓冲区。<br>API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果[AudioDataCallbackResult](arkts-apis-audio-e.md#audiodatacallbackresult12)。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401     | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioRenderer.off('writeData');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let writeDataCallback = (data: ArrayBuffer) => {
    console.info(`write data: ${data}`);
};

audioRenderer.on('writeData', writeDataCallback);

audioRenderer.off('writeData', writeDataCallback);
```
## write<sup>(deprecated)</sup>

write(buffer: ArrayBuffer, callback: AsyncCallback\<number>): void

写入缓冲区。使用callback异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[on('writeData')](#onwritedata11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | 是   | 要写入缓冲区的数据。                                |
| callback | AsyncCallback\<number> | 是   | 回调函数。当写入缓冲区成功，err为undefined，data为获取到的写入的字节数；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number)=> {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`Buffer size: ${bufferSize}`);
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.stat(filePath).then(async (stat: fs.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readSize: number = await fs.read(file.fd, buf, options);
      let writeSize: number = await new Promise((resolve,reject)=>{
        audioRenderer.write(buf,(err: BusinessError, writeSize: number)=>{
          if(err){
            reject(err)
          }else{
            resolve(writeSize)
          }
        })
      })
    }
  });
  }).catch((err: BusinessError) => {
    console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## write<sup>(deprecated)</sup>

write(buffer: ArrayBuffer): Promise\<number>

写入缓冲区。使用Promise异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[on('writeData')](#onwritedata11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| buffer   | ArrayBuffer            | 是   | 要写入缓冲区的数据。                                |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise对象，返回写入的字节数。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';

let bufferSize: number;
class Options {
  offset?: number;
  length?: number;
}
audioRenderer.getBufferSize().then((data: number) => {
  console.info(`AudioFrameworkRenderLog: getBufferSize: SUCCESS ${data}`);
  bufferSize = data;
  console.info(`BufferSize: ${bufferSize}`);
  // 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
  let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  let path = context.cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  fs.stat(filePath).then(async (stat: fs.Stat) => {
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize == 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0;i < len; i++) {
      let options: Options = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readSize: number = await fs.read(file.fd, buf, options);
      try{
        let writeSize: number = await audioRenderer.write(buf);
      } catch(err) {
        let error = err as BusinessError;
        console.error(`audioRenderer.write err: ${error}`);
      }
    }
  });
}).catch((err: BusinessError) => {
  console.error(`AudioFrameworkRenderLog: getBufferSize: ERROR: ${err}`);
});
```

## setRenderRate<sup>(deprecated)</sup>

setRenderRate(rate: AudioRendererRate, callback: AsyncCallback\<void>): void

设置音频渲染速率。使用callback异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[setSpeed](#setspeed11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                     | 必填 | 说明                     |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| rate     | [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | 是   | 渲染的速率。             |
| callback | AsyncCallback\<void>                     | 是   | 回调函数。当设置音频渲染速率成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set params');
  } else {
    console.info('Callback invoked to indicate a successful render rate setting.');
  }
});
```

## setRenderRate<sup>(deprecated)</sup>

setRenderRate(rate: AudioRendererRate): Promise\<void>

设置音频渲染速率。使用Promise异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[setSpeed](#setspeed11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名 | 类型                                     | 必填 | 说明         |
| ------ | ---------------------------------------- | ---- | ------------ |
| rate   | [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | 是   | 渲染的速率。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.setRenderRate(audio.AudioRendererRate.RENDER_RATE_NORMAL).then(() => {
  console.info('setRenderRate SUCCESS');
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getRenderRate<sup>(deprecated)</sup>

getRenderRate(callback: AsyncCallback\<AudioRendererRate>): void

获取音频渲染速率。使用callback异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[getSpeed](#getspeed11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明               |
| -------- | ------------------------------------------------------- | ---- | ------------------ |
| callback | AsyncCallback<[AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8)> | 是   | 回调函数。当获取当前渲染速率成功，err为undefined，data为获取到的当前渲染速率；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate((err: BusinessError, renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
});
```

## getRenderRate<sup>(deprecated)</sup>

getRenderRate(): Promise\<AudioRendererRate>

获取音频渲染速率。使用Promise异步回调。

> **说明：**
> 从API version 8开始支持，从API version 11开始废弃，建议使用[getSpeed](#getspeed11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明                      |
| ------------------------------------------------- | ------------------------- |
| Promise<[AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8)> | Promise对象，返回渲染速率。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioRenderer.getRenderRate().then((renderRate: audio.AudioRendererRate) => {
  console.info(`getRenderRate: ${renderRate}`);
}).catch((err: BusinessError) => {
  console.error(`ERROR: ${err}`);
});
```

## getRenderRateSync<sup>(deprecated)</sup>

getRenderRateSync(): AudioRendererRate

获取音频渲染速率。同步返回结果。

> **说明：**
> 从API version 10开始支持，从API version 11开始废弃，建议使用[getSpeed](#getspeed11)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Renderer

**返回值：**

| 类型                                              | 说明                      |
| ------------------------------------------------- | ------------------------- |
| [AudioRendererRate](arkts-apis-audio-e.md#audiorendererrate8) | 返回渲染速率。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let renderRate: audio.AudioRendererRate = audioRenderer.getRenderRateSync();
  console.info(`getRenderRate: ${renderRate}`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`ERROR: ${error}`);
}
```
