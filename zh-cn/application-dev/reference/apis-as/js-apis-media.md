# @ohos.multimedia.media (媒体服务)

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。

媒体子系统包含了音频相关媒体业务，提供以下常用功能：

- 音频播放（[AVPlayer](#avplayer9)<sup>9+</sup>）

## 导入模块

```ts
import media from '@ohos.multimedia.media';
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(callback: AsyncCallback\<AVPlayer>): void

异步方式创建音频播放实例，通过注册回调函数获取返回值。

> **说明：**
>
> - 可创建的音频播放实例不能超过13个。
> - 可创建的音频播放实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568仅支持创建6个以内的音频播放实例。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[AVPlayer](#avplayer9)> | 是   | 回调函数。异步返回AVPlayer实例，失败时返回null。可用于音频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let avPlayer: media.AVPlayer;
media.createAVPlayer((error: BusinessError, audio: media.AVPlayer) => {
  if (audio != null) {
    avPlayer = audio;
    console.info('createAVPlayer success');
  } else {
    console.error(`createAVPlayer fail, error message:${error.message}`);
  }
});
```

## media.createAVPlayer<sup>9+</sup>

createAVPlayer(): Promise\<AVPlayer>

异步方式创建音频播放实例，通过Promise获取返回值。

> **说明：**
>
> - 可创建的音频播放实例不能超过13个。
> - 可创建的音频播放实例数量依赖于设备芯片的支持情况，如芯片支持创建的数量少于上述情况，请以芯片规格为准。如RK3568仅支持创建6个以内的音频播放实例。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| Promise\<[AVPlayer](#avplayer9)> | Promise对象。异步返回AVPlayer实例，失败时返回null。可用于音频播放。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```ts
let avPlayer: media.AVPlayer;
media.createAVPlayer().then((audio: media.AVPlayer) => {
  if (audio != null) {
    avPlayer = audio;
    console.info('createAVPlayer success');
  } else {
    console.error('createAVPlayer fail');
  }
}).catch((error: BusinessError) => {
  console.error(`AVPlayer catchCallback, error message:${error.message}`);
});
```

## MediaDescriptionKey<sup>8+</sup>

媒体信息描述枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                     | 值              | 说明                                                         |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | 表示轨道序号，其对应键值类型为number。                       |
| MD_KEY_TRACK_TYPE        | 'track_type'    | 表示轨道类型，其对应键值类型为number，参考MediaType。 |
| MD_KEY_CODEC_MIME        | 'codec_mime'    | 表示codec_mime类型，其对应键值类型为string。                 |
| MD_KEY_DURATION          | 'duration'      | 表示媒体时长，其对应键值类型为number，单位为毫秒（ms）。     |
| MD_KEY_BITRATE           | 'bitrate'       | 表示比特率，其对应键值类型为number，单位为比特率（bps）。    |
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | 表示声道数，其对应键值类型为number。                         |
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | 表示采样率，其对应键值类型为number，单位为赫兹（Hz）。       |

## AVPlayer<sup>9+</sup>

播放管理类，用于管理和播放媒体资源。在调用AVPlayer的方法前，需要先通过[createAVPlayer()](#mediacreateavplayer9)构建一个AVPlayer实例。

Audio播放demo可参考：[音频播放开发指导](../../media/using-avplayer-for-playback.md)。

### 属性

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称                                                | 类型                                                         | 可读 | 可写 | 说明                                                         |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>9+</sup>                                    | string                                                       | 是   | 是   | 媒体URL，只允许在**idle**状态下设置，静态属性。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**支持路径示例**：<br>1. fd类型播放：fd://xx。<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx。<br/>3. https网络播放: https\://xx。<br/>4. hls网络播放路径：http\://xx或者https\://xx。 |
| fdSrc<sup>9+</sup>                                  | [AVFileDescriptor](#avfiledescriptor9)                       | 是   | 是   | 媒体文件描述，只允许在**idle**状态下设置，静态属性。<br/>使用场景：应用中的媒体资源被连续存储在同一个文件中。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**使用示例**：<br/>假设一个连续存储的媒体文件: <br/>音频1(地址偏移:0，字节长度:100)；<br/>音频2(地址偏移:101，字节长度:50)；<br/>音频3(地址偏移:151，字节长度:150)；<br/>1. 播放音频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }。<br/>2. 播放音频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }。<br/>3. 播放音频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }。<br/>假设是一个独立的媒体文件: 请使用src=fd://xx。 |
| dataSrc<sup>10+</sup>                               | [AVDataSrcDescriptor](#avdatasrcdescriptor10)                | 是   | 是   | 流式媒体资源描述，只允许在**idle**状态下设置，静态属性。<br/>使用场景：应用播放从远端下载到本地的文件，在应用未下载完整音频资源时，提前播放已获取的资源文件。<br>支持的音频格式(m4a、aac、mp3、ogg、wav、flac)。<br/>**使用示例**：<br/>假设用户正在从远端服务器获取音频媒体文件，希望下载到本地的同时播放已经下载好的部分: <br/>1.用户需要获取媒体文件的总大小size（单位为字节），获取不到时设置为-1。<br/>2.用户需要实现回调函数func用于填写数据，如果size = -1，则func形式为：func(buffer: ArrayBuffer, length: number)，此时播放器只会按照顺序获取数据；否则func形式为：func(buffer: ArrayBuffer, length: number, pos: number)，播放器会按需跳转并获取数据。<br/>3.用户设置AVDataSrcDescriptor {fileSize = size, callback = func}。<br/>**注意事项**：<br/>如果播放的是mp4/m4a格式用户需要保证moov字段（媒体信息字段）在mdat字段（媒体数据字段）之前，或者moov之前的字段小于10M，否则会导致解析失败无法播放。 |       |

**说明：**

将资源句柄（fd）传递给媒体播放器之后，请不要通过该资源句柄做其他读写操作，包括但不限于将同一个资源句柄传递给多个媒体播放器。同一时间通过同一个资源句柄读写文件时存在竞争关系，将导致播放异常。

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

监听[AVPlayer](#avplayer9)的错误事件，该事件仅用于错误提示，不需要用户停止播控动作。如果此时[AVPlayerState](#avplayerstate9)也切至error状态，用户需要通过reset()或者release()退出播放操作。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |
| callback | function | 是   | 错误事件回调方法：使用播放器的过程中发生错误，会提供错误码ID和错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息              |
| -------- | --------------------- |
| 201      | Permission denied     |
| 401      | The parameter check failed. |
| 801      | Capability not supported. |
| 5400101  | No Memory.            |
| 5400102  | Operation not allowed.|
| 5400103  | I/O error             |
| 5400104  | Time out              |
| 5400105  | Service Died.         |
| 5400106  | Unsupport Format.     |

**示例：**

```ts
avPlayer.on('error', (error: BusinessError) => {
  console.info('error happened,and error message is :' + error.message)
  console.info('error happened,and error code is :' + error.code)
})
```

### off('error')<sup>9+</sup>

off(type: 'error'): void

取消监听播放的错误事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error' |

**示例：**

```ts
avPlayer.off('error')
```

### prepare<sup>9+</sup>

prepare(callback: AsyncCallback\<void>): void

通过回调方式准备播放音频，需在stateChange事件成功触发至initialized状态后，才能调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 准备播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |
| 5400106  | Unsupport format. Return by callback.      |

**示例：**

```ts
avPlayer.prepare((err: BusinessError) => {
  if (err == null) {
    console.info('prepare success');
  } else {
    console.error('prepare filed,error message is :' + err.message)
  }
})
```

### prepare<sup>9+</sup>

prepare(): Promise\<void>

通过Promise方式准备播放音频，需在stateChange事件成功触发至initialized状态后，才能调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 准备播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400106  | Unsupport format. Return by promise.      |

**示例：**

```ts
avPlayer.prepare().then(() => {
  console.info('prepare success');
}, (err: BusinessError) => {
  console.error('prepare filed,error message is :' + err.message)
})
```

### play<sup>9+</sup>

play(callback: AsyncCallback\<void>): void

通过回调方式开始播放音频资源，只能在prepared/paused/completed状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 开始播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.play((err: BusinessError) => {
  if (err == null) {
    console.info('play success');
  } else {
    console.error('play filed,error message is :' + err.message)
  }
})
```

### play<sup>9+</sup>

play(): Promise\<void>

通过Promise方式开始播放音频资源，只能在prepared/paused/completed状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 开始播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.play().then(() => {
  console.info('play success');
}, (err: BusinessError) => {
  console.error('play filed,error message is :' + err.message)
})
```

### pause<sup>9+</sup>

pause(callback: AsyncCallback\<void>): void

通过回调方式暂停播放音频资源，只能在playing状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 暂停播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.pause((err: BusinessError) => {
  if (err == null) {
    console.info('pause success');
  } else {
    console.error('pause filed,error message is :' + err.message)
  }
})
```

### pause<sup>9+</sup>

pause(): Promise\<void>

通过Promise方式暂停播放音频资源，只能在playing状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 暂停播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.pause().then(() => {
  console.info('pause success');
}, (err: BusinessError) => {
  console.error('pause filed,error message is :' + err.message)
})
```

### stop<sup>9+</sup>

stop(callback: AsyncCallback\<void>): void

通过回调方式停止播放音频资源，只能在prepared/playing/paused/completed状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 停止播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.stop((err: BusinessError) => {
  if (err == null) {
    console.info('stop success');
  } else {
    console.error('stop filed,error message is :' + err.message)
  }
})
```

### stop<sup>9+</sup>

stop(): Promise\<void>

通过Promise方式停止播放音频资源，只能在prepared/playing/paused/completed状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 停止播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.stop().then(() => {
  console.info('stop success');
}, (err: BusinessError) => {
  console.error('stop filed,error message is :' + err.message)
})
```

### reset<sup>9+</sup>

reset(callback: AsyncCallback\<void>): void

通过回调方式重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 重置播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.reset((err: BusinessError) => {
  if (err == null) {
    console.info('reset success');
  } else {
    console.error('reset filed,error message is :' + err.message)
  }
})
```

### reset<sup>9+</sup>

reset(): Promise\<void>

通过Promise方式重置播放，只能在initialized/prepared/playing/paused/completed/stopped/error状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 重置播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.reset().then(() => {
  console.info('reset success');
}, (err: BusinessError) => {
  console.error('reset filed,error message is :' + err.message)
})
```

### release<sup>9+</sup>

release(callback: AsyncCallback\<void>): void

通过回调方式销毁播放资源，除released状态，都可以调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                 |
| -------- | -------- | ---- | -------------------- |
| callback | function | 是   | 销毁播放的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.release((err: BusinessError) => {
  if (err == null) {
    console.info('release success');
  } else {
    console.error('release filed,error message is :' + err.message)
  }
})
```

### release<sup>9+</sup>

release(): Promise\<void>

通过Promise方式销毁播放，除released状态，都可以调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 销毁播放的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.release().then(() => {
  console.info('release success');
}, (err: BusinessError) => {
  console.error('release filed,error message is :' + err.message)
})
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

通过回调方式获取音频轨道信息，可以在prepared/playing/paused状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                         |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------- |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | 是   | 音频轨道信息MediaDescription数组回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                   |
| -------- | ------------------------------------------ |
| 5400102  | Operation not allowed. Return by callback. |

**示例：**

```ts
avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('getTrackDescription success');
  } else {
    console.error(`audio getTrackDescription fail, error:${error}`);
  }
});
```

### getTrackDescription<sup>9+</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

通过Promise方式获取音频轨道信息，可以在prepared/playing/paused状态调用。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**返回值：**

| 类型                                                   | 说明                                              |
| ------------------------------------------------------ | ------------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | 音频轨道信息MediaDescription数组Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |

**示例：**

```ts
avPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  console.info('getTrackDescription success');
}).catch((error: BusinessError) => {
  console.error(`audio catchCallback, error:${error}`);
});
```

### seek<sup>9+</sup>

seek(timeMs: number, mode?:SeekMode): void

跳转到指定播放位置，只能在prepared/playing/paused/completed状态调用，可以通过[seekDone事件](#onseekdone9)确认是否生效。
注：直播场景不支持seek。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |


**示例：**

```ts
let seekTime: number = 1000
avPlayer.seek(seekTime, media.SeekMode.SEEK_PREV_SYNC)
```

### on('seekDone')<sup>9+</sup>

on(type: 'seekDone', callback: Callback\<number>): void

监听seek生效的事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | seek生效的事件回调类型，支持的事件：'seekDone'，每次调用seek后都会回调此事件。 |
| callback | Callback\<number> | 是   | seek生效的事件回调方法，只会上报用户请求的time位置。|

**示例：**

```ts
avPlayer.on('seekDone', (seekDoneTime:number) => {
  console.info('seekDone success,and seek time is:' + seekDoneTime)
})
```

### off('getTrackDescription')<sup>9+</sup>

off(type: 'seekDone'): void

取消监听seek生效的事件。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                 |
| ------ | ------ | ---- | ---------------------------------------------------- |
| type   | string | 是   | seek生效的事件回调类型，取消注册的事件：'seekDone'。 |

**示例：**

```ts
avPlayer.off('seekDone')
```

### on('timeUpdate')<sup>9+</sup>

on(type: 'timeUpdate', callback: Callback\<number>): void

监听资源播放当前时间，单位为毫秒（ms），用于刷新进度条当前位置，默认间隔1s时间上报，因用户操作(seek)产生的时间变化会立刻上报。
注：直播场景不支持timeUpdate上报。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                           |
| -------- | -------- | ---- | ---------------------------------------------- |
| type     | string   | 是   | 时间更新的回调类型，支持的事件：'timeUpdate'。 |
| callback | function | 是   | 当前时间。                                     |

**示例：**

```ts
avPlayer.on('timeUpdate', (time:number) => {
  console.info('timeUpdate success,and new time is :' + time)
})
```

### off('timeUpdate')<sup>9+</sup>

off(type: 'timeUpdate'): void

取消监听资源播放当前时间。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- | -------------------------------------------------- |
| type   | string | 是   | 时间更新的回调类型，取消注册的事件：'timeUpdate'。 |

**示例：**

```ts
avPlayer.off('timeUpdate')
```

## AVPlayerState<sup>9+</sup>

[AVPlayer](#avplayer9)的状态机，可通过state属性主动获取当前状态，也可通过监听stateChange事件上报当前状态，状态机之间的切换规则，可参考[音频播放开发指导](../../media/using-avplayer-for-playback.md)。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

|              名称               |  类型  | 说明                                                         |
| :-----------------------------: | :----: | :----------------------------------------------------------- |
|              idle               | string | 闲置状态，AVPlayer刚被创建[createAVPlayer()](#mediacreateavplayer9)或者调用了reset()方法之后，进入Idle状态。<br/>首次创建createAVPlayer()，所有属性都为默认值。<br/>调用reset()方法，url<sup>9+</sup> 或 fdSrc<sup>9+</sup>或dataSrc<sup>10+</sup>属性及loop属性会被重置，其他用户设置的属性将被保留。 |
|           initialized           | string | 资源初始化，在Idle 状态设置 url<sup>9+</sup> 或 fdSrc<sup>9+</sup>属性，AVPlayer会进入initialized状态，此时可以配置窗口、音频等静态属性。 |
|            prepared             | string | 已准备状态，在initialized状态调用prepare()方法，AVPlayer会进入prepared状态，此时播放引擎的资源已准备就绪。 |
|             playing             | string | 正在播放状态，在prepared/paused/completed状态调用play()方法，AVPlayer会进入playing状态。 |
|             paused              | string | 暂停状态，在playing状态调用pause方法，AVPlayer会进入paused状态。 |
|            completed            | string | 播放至结尾状态，当媒体资源播放至结尾时，如果用户未设置循环播放（loop = 1），AVPlayer会进入completed状态，此时调用play()会进入playing状态和重播，调用stop()会进入stopped状态。 |
|             stopped             | string | 停止状态，在prepared/playing/paused/completed状态调用stop()方法，AVPlayer会进入stopped状态，此时播放引擎只会保留属性，但会释放内存资源，可以调用prepare()重新准备，也可以调用reset()重置，或者调用release()彻底销毁。 |
|            released             | string | 销毁状态，销毁与当前AVPlayer关联的播放引擎，无法再进行状态转换，调用release()方法后，会进入released状态，结束流程。 |
| error | string | 错误状态，当**播放引擎**发生**不可逆的错误**（详见[媒体错误码](../errorcodes/errorcode-media.md)），则会转换至当前状态，可以调用reset()重置，也可以调用release()销毁重建。<br/>**注意：** 区分error状态和 [on('error')](#onerror9) ：<br/>1、进入error状态时，会触发on('error')监听事件，可以通过on('error')事件获取详细错误信息；<br/>2、处于error状态时，播放服务进入不可播控的状态，要求客户端设计容错机制，使用reset()重置或者release()销毁重建；<br/>3、如果客户端收到on('error')，但未进入error状态：<br/>原因1：客户端未按状态机调用API或传入参数错误，被AVPlayer拦截提醒，需要客户端调整代码逻辑；<br/>原因2：播放过程发现码流问题，导致容器、解码短暂异常，不影响连续播放和播控操作的，不需要客户端设计容错机制。 |

## AVFileDescriptor<sup>9+</sup>

音频文件资源描述，一种特殊资源的播放方式，使用场景：应用中的音频资源被连续存储在同一个文件中，需要根据偏移量和长度进行播放。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | 是   | 资源句柄，通过[resourceManager.getRawFd](js-apis-resource-manager.md#getrawfd9)获取。     |
| offset | number | 否   | 资源偏移量，需要基于预置资源的信息输入，非法值会造成音频资源解析错误。 |
| length | number | 否   | 资源长度，需要基于预置资源的信息输入，非法值会造成音频资源解析错误。 |

## AVDataSrcDescriptor<sup>10+</sup>

音频文件资源描述，用于DataSource播放方式，使用场景：应用在未获取完整音频资源时，允许用户创建播放实例并开始播放，达到提前播放的目的。

**系统能力：** SystemCapability.Multimedia.Media.AVPlayer

| 名称   | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fileSize     | number | 是   | 待播放文件大小（字节），-1代表大小未知。如果fileSize设置为-1, 播放模式类似于直播，不能进行seek及setSpeed操作，不能设置loop属性，因此不能重新播放。 |
| callback | function | 是   | 用户设置的回调函数，用于填写数据。<br>- buffer，ArrayBuffer类型，表示被填写的内存，必选。<br>- length，number类型，表示被填写内存的最大长度，必选。<br>- pos，number类型，表示填写的数据在资源文件中的位置，可选，当fileSize设置为-1时，该参数禁止被使用。 |

## MediaDescription<sup>8+</sup>

通过key-value方式获取媒体信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| [key: string] | Object | 是   | 该键值对支持的key取值范围，请参考[MediaDescriptionKey](#mediadescriptionkey8);每个key值的Object类型和范围，请参考[MediaDescriptionKey](#mediadescriptionkey8)对应Key值的说明 |

**示例：**

```ts
function printfItemDescription(obj: media.MediaDescription, key: string) {
  let property: Object = obj[key];
  console.info('audio key is ' + key); // 通过key值获取对应的value。key值具体可见[MediaDescriptionKey]
  console.info('audio value is ' + property); //对应key值得value。其类型可为任意类型，具体key对应value的类型可参考[MediaDescriptionKey]
}

avPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    for (let i = 0; i < arrList.length; i++) {
      printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  //打印出每条轨道MD_KEY_TRACK_TYPE的值
    }
  } else {
    console.error(`audio getTrackDescription fail, error:${error}`);
  }
});
```