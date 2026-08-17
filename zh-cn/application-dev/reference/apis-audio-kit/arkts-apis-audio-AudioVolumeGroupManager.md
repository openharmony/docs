# Interface (AudioVolumeGroupManager)
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @hao-liangfei-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

AudioVolumeGroupManager是音频系统中的音频组音量管理模块。本模块提供音频组音量管理能力，包括获取和设置不同音量类型的音量等级、静音状态管理、铃声模式监听和获取、麦克风状态管理和监听、固定音量模式控制、音量增益分贝值查询、输入/输出设备电平值获取等。当需要精细化控制音量时，使用本模块接口完成相关操作，适用于多媒体播放、音视频通话、游戏、音频录制等场景。

在使用AudioVolumeGroupManager的接口之前，需先通过[getVolumeGroupManager](arkts-apis-audio-AudioVolumeManager.md#getvolumegroupmanager9)获取AudioVolumeGroupManager实例。

> **说明：**
>
> - 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本Interface首批接口从API version 9开始支持。


## 导入模块

```ts
import { audio } from '@kit.AudioKit';
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的音量等级。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调函数。当获取指定流的音量成功，err为undefined，data为获取到的指定流的音量等级；否则为错误对象。指定流的音量等级范围可通过[getMinVolume](#getminvolumedeprecated)和[getMaxVolume](#getmaxvolumedeprecated)获取。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, volume: number) => {
  if (err) {
    console.error(`Failed to obtain the volume. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the volume, volume: ${volume}.`);
});
```

## getVolume<sup>(deprecated)</sup>

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的音量等级。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回指定流的音量等级。音量等级范围可通过[getMinVolume](#getminvolumedeprecated)和[getMaxVolume](#getmaxvolumedeprecated)获取。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getVolume(audio.AudioVolumeType.MEDIA).then((volume: number) => {
  console.info(`Succeeded in obtaining the volume, volume: ${volume}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the volume. Code: ${err.code}, message: ${err.message}`);
});
```

## getVolumeSync<sup>(deprecated)</sup>

getVolumeSync(volumeType: AudioVolumeType): number

获取指定流的音量等级。同步返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| number | 返回指定流的音量等级。指定流的音量等级范围可通过[getMinVolume](#getminvolumedeprecated)和[getMaxVolume](#getmaxvolumedeprecated)获取。 |

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
  let volume: number = audioVolumeGroupManager.getVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Succeeded in obtaining the volume, volume: ${volume}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the volume. Code: ${error.code}, message: ${error.message}`);
}
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最小音量等级。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明               |
| ---------- | ----------------------------------- | ---- | ------------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。       |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调函数。当获取指定流的最小音量成功，err为undefined，data为指定流的最小音量等级；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, minVolume: number) => {
  if (err) {
    console.error(`Failed to obtain the minimum volume. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the minimum volume, minVolume: ${minVolume}.`);
});
```

## getMinVolume<sup>(deprecated)</sup>

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最小音量等级。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise对象，返回最小音量等级。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((minVolume: number) => {
  console.info(`Succeeded in obtaining the minimum volume, minVolume: ${minVolume}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the minimum volume. Code: ${err.code}, message: ${err.message}`);
});
```

## getMinVolumeSync<sup>(deprecated)</sup>

getMinVolumeSync(volumeType: AudioVolumeType): number

获取指定流的最小音量等级。同步返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getMinVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getminvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                      |
| --------------------- | ------------------------- |
| number | 返回最小音量等级。 |

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
  let minVolume: number = audioVolumeGroupManager.getMinVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Succeeded in obtaining the minimum volume, minVolume: ${minVolume}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the minimum volume. Code: ${error.code}, message: ${error.message}`);
}
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最大音量等级。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                   |
| ---------- | ----------------------------------- | ---- | ---------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。           |
| callback   | AsyncCallback&lt;number&gt;         | 是   | 回调函数。当获取指定流的最大音量成功，err为undefined，data为指定流的最大音量等级；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err: BusinessError, maxVolume: number) => {
  if (err) {
    console.error(`Failed to obtain the maximum volume. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the maximum volume, maxVolume: ${maxVolume}.`);
});
```

## getMaxVolume<sup>(deprecated)</sup>

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最大音量等级。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise对象，返回最大音量等级。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((maxVolume: number) => {
  console.info(`Succeeded in obtaining the maximum volume, maxVolume: ${maxVolume}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the maximum volume. Code: ${err.code}, message: ${err.message}`);
});
```

## getMaxVolumeSync<sup>(deprecated)</sup>

getMaxVolumeSync(volumeType: AudioVolumeType): number

获取指定流的最大音量等级。同步返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getMaxVolumeByStream](arkts-apis-audio-AudioVolumeManager.md#getmaxvolumebystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                  | 说明                          |
| --------------------- | ----------------------------- |
| number | 返回最大音量等级。 |

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
  let maxVolume: number = audioVolumeGroupManager.getMaxVolumeSync(audio.AudioVolumeType.MEDIA);
  console.info(`Succeeded in obtaining the maximum volume, maxVolume: ${maxVolume}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the maximum volume. Code: ${error.code}, message: ${error.message}`);
}
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量类型静音状态。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                            |
| ---------- | ----------------------------------- | ---- | ----------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。                                    |
| callback   | AsyncCallback&lt;boolean&gt;        | 是   | 回调函数。当获取音量静音状态成功，err为undefined，data为true表示静音，false表示非静音；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA, (err: BusinessError, isMute: boolean) => {
  if (err) {
    console.error(`Failed to check whether the stream is muted. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in checking whether the stream is muted, isMuted: ${isMute}.`);
});
```

## isMute<sup>(deprecated)</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量类型静音状态。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 20开始废弃，建议使用[isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示静音；返回false表示非静音。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMute(audio.AudioVolumeType.MEDIA).then((isMute: boolean) => {
  console.info(`Succeeded in checking whether the stream is muted, isMuted: ${isMute}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the stream is muted. Code: ${err.code}, message: ${err.message}`);
});
```

## isMuteSync<sup>(deprecated)</sup>

isMuteSync(volumeType: AudioVolumeType): boolean

获取指定音量类型静音状态。同步返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[isSystemMutedForStream](arkts-apis-audio-AudioVolumeManager.md#issystemmutedforstream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明         |
| ---------- | ----------------------------------- | ---- | ------------ |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。 |

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| boolean | 音量是否为静音状态。返回true表示静音，返回false表示非静音。 |

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
  let isMute: boolean = audioVolumeGroupManager.isMuteSync(audio.AudioVolumeType.MEDIA);
  console.info(`Succeeded in checking whether the stream is muted, isMuted: ${isMute}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check whether the stream is muted. Code: ${error.code}, message: ${error.message}`);
}
```

## getRingerMode<sup>9+</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

获取铃声模式。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                                 | 必填 | 说明                     |
| -------- | ---------------------------------------------------- | ---- | ------------------------ |
| callback | AsyncCallback&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | 是   | 回调函数。当获取铃声模式成功，err为undefined，data为获取到的铃声模式；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getRingerMode((err: BusinessError, ringerMode: audio.AudioRingMode) => {
  if (err) {
    console.error(`Failed to obtain the ringer mode. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the ringer mode, ringerMode: ${ringerMode}.`);
});
```

## getRingerMode<sup>9+</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

获取铃声模式。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                                           | 说明                            |
| ---------------------------------------------- | ------------------------------- |
| Promise&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | Promise对象，返回系统的铃声模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getRingerMode().then((ringerMode: audio.AudioRingMode) => {
  console.info(`Succeeded in obtaining the ringer mode, ringerMode: ${ringerMode}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the ringer mode. Code: ${err.code}, message: ${err.message}`);
});
```

## getRingerModeSync<sup>10+</sup>

getRingerModeSync(): AudioRingMode

获取铃声模式。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                                           | 说明                            |
| ---------------------------------------------- | ------------------------------- |
| [AudioRingMode](arkts-apis-audio-e.md#audioringmode) | 返回系统的铃声模式。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let ringerMode: audio.AudioRingMode = audioVolumeGroupManager.getRingerModeSync();
  console.info(`Succeeded in obtaining the ringer mode, ringerMode: ${ringerMode}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the ringer mode. Code: ${error.code}, message: ${error.message}`);
}
```

## on('ringerModeChange')<sup>9+</sup>

on(type: 'ringerModeChange', callback: Callback\<AudioRingMode>): void

监听铃声模式变化事件（当[AudioRingMode](arkts-apis-audio-e.md#audioringmode)发生变化时触发）。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                      | 必填 | 说明                                                         |
| -------- | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                    | 是   | 事件回调类型，支持的事件为'ringerModeChange'，当铃声模式发生变化时，触发该事件。 |
| callback | Callback<[AudioRingMode](arkts-apis-audio-e.md#audioringmode)> | 是   | 回调函数，返回变化后的铃音模式。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeGroupManager.on('ringerModeChange', (ringerMode: audio.AudioRingMode) => {
  console.info(`Ringer mode changed, ringerMode: ${ringerMode}.`);
});
```

## off('ringerModeChange')<sup>18+</sup>

off(type: 'ringerModeChange', callback?: Callback&lt;AudioRingMode&gt;): void

取消监听铃声模式变化事件。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- |----| ------------------------------------------------------------ |
| type     | string                                 | 是  | 事件回调类型，支持的事件为'ringerModeChange'。 |
| callback |Callback&lt;[AudioRingMode](arkts-apis-audio-e.md#audioringmode)&gt; | 否  | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('ringerModeChange')](#onringermodechange9)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeGroupManager.off('ringerModeChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let ringerModeChangeCallback = (ringerMode: audio.AudioRingMode) => {
  console.info(`Ringer mode changed, ringerMode: ${ringerMode}.`);
};

audioVolumeGroupManager.on('ringerModeChange', ringerModeChangeCallback);

audioVolumeGroupManager.off('ringerModeChange', ringerModeChangeCallback);
```

## isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

获取麦克风静音状态。使用callback异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数。当获取麦克风静音状态成功，err为undefined，data为true表示静音，false表示非静音；否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMicrophoneMute((err: BusinessError, isMute: boolean) => {
  if (err) {
    console.error(`Failed to check whether the microphone is muted. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in checking whether the microphone is muted, isMuted: ${isMute}.`);
});
```

## isMicrophoneMute<sup>9+</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

获取麦克风静音状态。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise对象。返回true表示麦克风被静音；返回false表示麦克风未被静音。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.isMicrophoneMute().then((isMute: boolean) => {
  console.info(`Succeeded in checking whether the microphone is muted, isMuted: ${isMute}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to check whether the microphone is muted. Code: ${err.code}, message: ${err.message}`);
});
```

## isMicrophoneMuteSync<sup>10+</sup>

isMicrophoneMuteSync(): boolean

获取麦克风静音状态。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| boolean | 系统麦克风静音状态。返回true表示静音，返回false表示非静音。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  let isMute: boolean = audioVolumeGroupManager.isMicrophoneMuteSync();
  console.info(`Succeeded in checking whether the microphone is muted, isMuted: ${isMute}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to check whether the microphone is muted. Code: ${error.code}, message: ${error.message}`);
}
```

## on('micStateChange')<sup>9+</sup>

on(type: 'micStateChange', callback: Callback&lt;MicStateChangeEvent&gt;): void

监听系统麦克风状态更改事件（当检测到系统麦克风状态发生改变时触发）。使用callback异步回调。

目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅）。因此，推荐使用单一AudioManager实例进行开发。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| type     | string                                 | 是   | 事件回调类型，支持的事件为'micStateChange'，当检测到系统麦克风状态发生改变时，触发该事件。 |
| callback | Callback<[MicStateChangeEvent](arkts-apis-audio-i.md#micstatechangeevent9)> | 是   | 回调函数，返回变更后的麦克风状态。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
  console.info(`Mic state changed, micStateChangeEvent: ${JSON.stringify(micStateChange)}.`);
});
```

## off('micStateChange')<sup>12+</sup>

off(type: 'micStateChange', callback?: Callback&lt;MicStateChangeEvent&gt;): void

取消监听系统麦克风状态更改事件。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                         |
| -------- | -------------------------------------- |----| ------------------------------------------------------------ |
| type     | string                                 | 是  | 事件回调类型，支持的事件为'micStateChange'。 |
| callback | Callback<[MicStateChangeEvent](arkts-apis-audio-i.md#micstatechangeevent9)> | 否  | 回调函数。传入回调函数时，仅取消该回调对应的监听事件，需与[on('micStateChange')](#onmicstatechange9)绑定同一回调函数；不传参数时，取消此事件类型下所有已订阅的监听事件。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters missing; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. |

**示例：**

```ts
// 取消该事件的所有监听。
audioVolumeGroupManager.off('micStateChange');

// 同一监听事件中，on方法和off方法传入callback参数一致，off方法取消对应on方法订阅的监听。
let micStateChangeCallback = (micStateChange: audio.MicStateChangeEvent) => {
  console.info(`Mic state changed, micStateChangeEvent: ${JSON.stringify(micStateChange)}.`);
};

audioVolumeGroupManager.on('micStateChange', micStateChangeCallback);

audioVolumeGroupManager.off('micStateChange', micStateChangeCallback);
```

## isVolumeUnadjustable<sup>10+</sup>

isVolumeUnadjustable(): boolean

获取固定音量模式开关状态，打开时进入固定音量模式，此时音量固定无法被调节。同步返回结果。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**返回值：**

| 类型                   | 说明                                                   |
| ---------------------- | ------------------------------------------------------ |
| boolean            | 固定音量模式开关状态。返回true表示固定音量模式，返回false表示非固定音量模式。 |

**示例：**

```ts
let isVolumeUnadjustable: boolean = audioVolumeGroupManager.isVolumeUnadjustable();
console.info(`Succeeded in checking whether the volume is unadjustable, isVolumeUnadjustable: ${isVolumeUnadjustable}.`);
```

## getSystemVolumeInDb<sup>(deprecated)</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType, callback: AsyncCallback&lt;number&gt;): void

获取音量增益dB值。使用callback异步回调。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。                                             |
| volumeLevel | number                         | 是   | 音量等级。                                               |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | 是   | 设备类型。                                               |
| callback   | AsyncCallback&lt;number&gt;           | 是   | 回调函数。当获取音量增益dB值成功，err为undefined，data为获取到的音量增益dB值；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by callback.                     |
| 6800301 | System error. Return by callback.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER, (err: BusinessError, volumeDb: number) => {
  if (err) {
    console.error(`Failed to obtain the system volume in dB. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in obtaining the system volume in dB, volumeDb: ${volumeDb}.`);
});
```

## getSystemVolumeInDb<sup>(deprecated)</sup>

getSystemVolumeInDb(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): Promise&lt;number&gt;

获取音量增益dB值。使用Promise异步回调。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。                                             |
| volumeLevel | number                              | 是   | 音量等级。                                             |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | 是   | 设备类型。                                               |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回对应的音量增益dB值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise.                     |
| 6800301 | System error. Return by promise.                                |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.getSystemVolumeInDb(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER).then((volumeDb: number) => {
  console.info(`Succeeded in obtaining the system volume in dB, volumeDb: ${volumeDb}.`);
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the system volume in dB. Code: ${err.code}, message: ${err.message}`);
});
```

## getSystemVolumeInDbSync<sup>(deprecated)</sup>

getSystemVolumeInDbSync(volumeType: AudioVolumeType, volumeLevel: number, device: DeviceType): number

获取音量增益dB值。同步返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 20开始废弃，建议使用[getVolumeInUnitOfDbByStream](arkts-apis-audio-AudioVolumeManager.md#getvolumeinunitofdbbystream20)替代。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ---------- | ----------------------------------- | ---- | -------------------------------------------------------- |
| volumeType | [AudioVolumeType](arkts-apis-audio-e.md#audiovolumetype) | 是   | 音频音量类型。                                             |
| volumeLevel | number                              | 是   | 音量等级。                                             |
| device     | [DeviceType](arkts-apis-audio-e.md#devicetype)           | 是   | 设备类型。                                               |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| number | 返回对应的音量增益dB值。 |

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
  let volumeDb: number = audioVolumeGroupManager.getSystemVolumeInDbSync(audio.AudioVolumeType.MEDIA, 3, audio.DeviceType.SPEAKER);
  console.info(`Succeeded in obtaining the system volume in dB, volumeDb: ${volumeDb}.`);
} catch (err) {
  let error = err as BusinessError;
  console.error(`Failed to obtain the system volume in dB. Code: ${error.code}, message: ${error.message}`);
}
```

## getMaxAmplitudeForInputDevice<sup>12+</sup>

getMaxAmplitudeForInputDevice(inputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

获取输入设备音频流的最大电平值，取值范围为[0, 1]。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ----------- | ------------------------------------- | ---- | --------------------------------------------------- |
| inputDevice |[AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 获取最大电平值的设备信息。                                 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回对应设备的电平值，大小在[0, 1]之间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let capturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型：Mic音频源。根据业务场景配置，参考SourceType。
  capturerFlags: 0 // 音频采集器标志。
};

audio.getAudioManager().getRoutingManager().getPreferredInputDeviceForCapturerInfo(capturerInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForInputDevice(data[0]).then((maxAmplitude) => {
    console.info(`Succeeded in obtaining the maximum amplitude for input device, maxAmplitude: ${maxAmplitude}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain the maximum amplitude for input device. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the preferred input device for capturer info. Code: ${err.code}, message: ${err.message}`);
});
```

## getMaxAmplitudeForOutputDevice<sup>12+</sup>

getMaxAmplitudeForOutputDevice(outputDevice: AudioDeviceDescriptor): Promise&lt;number&gt;

获取输出设备音频流的最大电平值，取值范围为[0, 1]。使用Promise异步回调。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名     | 类型                                | 必填 | 说明                                                     |
| ------------ | --------------------------------------- | ---- | -------------------------------------------------------- |
| outputDevice |[AudioDeviceDescriptor](arkts-apis-audio-i.md#audiodevicedescriptor) | 是   | 获取最大电平值的设备信息。                                             |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise&lt;number&gt; | Promise对象，返回对应设备的电平值，大小在[0, 1]之间。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)和[Audio错误码](errorcode-audio.md)。

| 错误码ID | 错误信息 |
| ------- | --------------------------------------------|
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 6800101 | Parameter verification failed. Return by promise. |
| 6800301 | System error. Return by promise. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let rendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型：音乐。根据业务场景配置，参考StreamUsage。
  rendererFlags: 0 // 音频渲染器标志。
};

audio.getAudioManager().getRoutingManager().getPreferOutputDeviceForRendererInfo(rendererInfo).then((data) => {
  audioVolumeGroupManager.getMaxAmplitudeForOutputDevice(data[0]).then((maxAmplitude) => {
    console.info(`Succeeded in obtaining the maximum amplitude for output device, maxAmplitude: ${maxAmplitude}.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to obtain the maximum amplitude for output device. Code: ${err.code}, message: ${err.message}`);
  });
}).catch((err: BusinessError) => {
  console.error(`Failed to obtain the preferred output device for renderer info. Code: ${err.code}, message: ${err.message}`);
});
```
## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置麦克风静音状态。使用callback异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                          |
| -------- | ------------------------- | ---- | --------------------------------------------- |
| mute     | boolean                   | 是   | 是否设置麦克风为静音状态。true表示静音，false表示非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当设置麦克风静音状态成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setMicrophoneMute(true, (err: BusinessError) => {
  if (err) {
    console.error(`Failed to mute the microphone. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in muting the microphone.');
});
```

## setMicrophoneMute<sup>(deprecated)</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态。使用Promise异步回调。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。

**需要权限：** ohos.permission.MANAGE_AUDIO_CONFIG，该权限仅系统应用可申请。

**系统能力：** SystemCapability.Multimedia.Audio.Volume

**参数：**

| 参数名 | 类型    | 必填 | 说明                                          |
| ------ | ------- | ---- | --------------------------------------------- |
| mute   | boolean | 是   | 是否设置麦克风为静音状态。true表示静音，false表示非静音。 |

**返回值：**

| 类型                | 说明                            |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise对象，无返回结果。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

audioVolumeGroupManager.setMicrophoneMute(true).then(() => {
  console.info('Succeeded in muting the microphone.');
}).catch((err: BusinessError) => {
  console.error(`Failed to mute the microphone. Code: ${err.code}, message: ${err.message}`);
});
```
