# SoundPool (音频池)

音频池加载播放实例，音频池提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能。

SoundPool需要和@ohos.multimedia.media配合使用，需要先通过[media.createSoundPool](js-apis-media.md#mediacreatesoundpool10)完成音频池实例的创建。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import media from '@ohos.multimedia.media';
import audio from '@ohos.multimedia.audio';
```

## PlayParameters

表示音频池播放参数设置。

通过设置播放相关参数，来控制播放的音量，循环次数，播放优先级等参数。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

| 名称            | 类型                                     | 必填 | 说明                                                         |
| --------------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| loop | number   | 否  | 设置循环参数，0为循环一次，-1表示一直循环。                   |
| rate | number    | 否  | 设置音频播放的倍速，具体倍速范围参照[AudioRendererRate](js-apis-audio.md#AudioRendererRate)。 |
| leftVolume  | number | 否  | 设置左声道音量，设置范围（0~1）。                                    |
| rightVolume | number  | 否  | 设置右声道音量。（当前不支持左右分别设置，将以左声道音量为准）。 |
| priority  | number  | 否  | 音频流播放的优先级，0为最低优先级，数值越大优先级越高，通过相互比较大小确定播放优先级。      |
| parallelPlayFlag | boolean | 否   | 是否和其它正在播放的音频并行播放的标识，true:不抢占音频焦点和其它正在播放的音频并行播放，false:抢占焦点打断其它正在播放的音频。<br/>此接口为系统接口。|

## SoundPool

音频池提供了系统声音的加载、播放、音量设置、循环设置、停止播放、资源卸载等功能, 在调用SoundPool的接口前，需要先通过[createSoundPool](js-apis-media.md#mediacreatesoundpool10)创建实例

### load

load(uri: string, callback: AsyncCallback\<number>): void

加载音频资源。使用callback方式异步获取资源ID，入参uri通过获取文件fd生成以"fd://"开头的文件描述字符串。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                  |
| -------- | -------------------------------------- | ---- | ------------------------------------- |
| uri   | string | 是   | 音频文件的加载路径描述，一般以"fd://"开头的文件描述。 |
| callback | AsyncCallback\<number>                   | 是   | 异步音频资源加载返回的资源id，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback.|
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback. |

**示例：**

```ts
import fs from '@ohos.file.fs';
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let uri:string = "";
let file: fs.File;
//获取fd的uri路径
fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file_: fs.File) => {
  file = file_;
  console.info("file fd: " + file.fd);
  uri = 'fd://' + (file.fd).toString()
}); // '/test_01.mp3' 作为样例，使用时需要传入文件对应路径。

soundPool.load(uri, (error: BusinessError, soundId_: number) => {
  if (error) {
    console.info(`load soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info(`load soundPool Success` + JSON.stringify(soundId_))
  }
})
```

### load

load(uri: string): Promise\<number>

加载音频资源。使用Promise方式异步获取资源ID，入参uri通过获取文件fd生成以"fd://"开头的文件描述字符串。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                       |
| ------ | -------------------------------------- | ---- | -------------------------- |
| uri | string | 是   | 音频文件的加载路径描述，一般以"fd://"开头的文件描述。 |

**返回值：**

| 类型           | 说明                                       |
| -------------- | ------------------------------------------ |
| Promise\<number> | 异步音频池资源的加载，返回资源的id，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise.|
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import fs from '@ohos.file.fs';
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let uri:string = "";
let soundID: number;
let file: fs.File;
//获取fd的uri路径
fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file_: fs.File) => {
  file = file_;
  console.info("file fd: " + file.fd);
  uri = 'fd://' + (file.fd).toString()
}); // '/test_01.mp3' 作为样例，使用时需要传入文件对应路径。

soundPool.load(uri).then((soundId: number) => {
  console.info('soundPool load uri success');
  soundID = soundId;
}, (err: BusinessError) => {
  console.error('soundPool load failed and catch error is ' + err.message);
});

```

### load

load(fd: number, offset: number, length: number, callback: AsyncCallback\<number>): void

加载音频资源。使用callback方式异步获取资源ID，入参可手动传入资源信息或通过读取应用内置资源自动获取。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| fd     | number | 是   | 资源句柄，通过resourceManager.getRawFileDescriptor获取。     |
| offset | number | 是   | 资源偏移量，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |
| length | number | 是   | 资源长度，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |
| callback | AsyncCallback\<number> | 是   | 获取回调的soundID，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```ts
import fs from '@ohos.file.fs';
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});
let file: fs.File;
let soundID: number;
let fileSize: number; //通过fs.stat()获取size值
let uri: string = "";
//获取fd的描述信息
fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file_: fs.File) => {
  file = file_;
  console.info("file fd: " + file.fd);
  uri = 'fd://' + (file.fd).toString()
}); // '/test_01.mp3' 作为样例，使用时需要传入文件对应路径。

soundPool.load(file.fd, 0, fileSize, (error: BusinessError, soundId_: number) => {
  if (error) {
    console.info(`load soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    soundID = soundId_;
    console.info('load success soundid:' + soundId_);
  }
})

```

### load

load(fd: number, offset: number, length: number): Promise\<number>

加载音频资源。使用Promise方式异步获取资源ID，入参可手动传入资源信息或通过读取应用内置资源自动获取。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| fd     | number | 是   | 资源句柄，通过resourceManager.getRawFileDescriptor获取。     |
| offset | number | 是   | 资源偏移量，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |
| length | number | 是   | 资源长度，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<number> | 获取回调的soundID，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise.|
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise. |

**示例：**

```ts
import fs from '@ohos.file.fs';
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});
let file: fs.File;
let soundID: number;
let fileSize: number; //通过fs.stat()获取size值
let uri: string = "";
//获取fd的描述信息
fs.open('/test_01.mp3', fs.OpenMode.READ_ONLY).then((file_: fs.File) => {
  file = file_;
  console.info("file fd: " + file.fd);
  uri = 'fd://' + (file.fd).toString()
}); 

soundPool.load(file.fd, 0, fileSize).then((soundId: number) => {
  console.info('load success');
  soundID = soundId;
}, (err: BusinessError) => {
  console.error('soundpool load failed and catch error is ' + err.message);
});
```

### play

play(soundID: number, params: PlayParameters, callback: AsyncCallback\<number>): void

播放音频资源。使用callback方式异步获取音频流streamID。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | 是   | 资源ID，通过load方法获取。 |
| params | [PlayParameters](#playparameters) | 是  | play播放相关参数的设置。 |
| callback | AsyncCallback\<number> | 是   | 获取回调的音频流ID，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let soundID: number;
let streamID: number;
let playParameters: media.PlayParameters = {
    loop: 3, // 循环4次
    rate: audio.AudioRendererRate.RENDER_RATE_NORMAL, // 正常倍速
    leftVolume: 0.5, // range = 0.0-1.0
    rightVolume: 0.5, // range = 0.0-1.0
    priority: 0, // 最低优先级
    parallelPlayFlag: false // 不和其它正在播放的音频并行播放
  }
soundPool.play(soundID, playParameters, (error: BusinessError, streamId: number) => {
  if (error) {
    console.info(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    streamID = streamId;
    console.info('play success soundid:' + streamId);
  }
})
```

### play

play(soundID: number, callback: AsyncCallback\<number>): void

播放音频资源。使用callback方式异步获取音频流streamID。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | 是   | 资源ID，通过load方法获取。 |
| callback | AsyncCallback\<number> | 是   | 获取回调的音频流ID，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let soundID: number;
let streamID: number;
soundPool.play(soundID,  (error: BusinessError, streamId: number) => {
  if (error) {
    console.info(`play sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    streamID = streamId;
    console.info('play success soundid:' + streamId);
  }
})
```

### play

play(soundID: number, params?: PlayParameters): Promise\<number>

播放音频资源。使用Promise方式异步获取音频流streamID。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | 是   | 资源ID，通过load方法获取。 |
| params | [PlayParameters](#playparameters) | 否  | play播放相关参数的设置。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<number> | 获取回调的音频流ID，有效值大于0。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let soundID: number;
let streamID: number;
let playParameters: media.PlayParameters = {
    loop: 3, // 循环4次
    rate: audio.AudioRendererRate.RENDER_RATE_NORMAL, // 正常倍速
    leftVolume: 0.5, // range = 0.0-1.0
    rightVolume: 0.5, // range = 0.0-1.0
    priority: 0, // 最低优先级
    parallelPlayFlag: false // 不和其它正在播放的音频并行播放
  }

soundPool.play(soundID, playParameters).then((streamId: number) => {
  console.info('play success');
  streamID = streamId;
},(err: BusinessError) => {
  console.error('soundpool play failed and catch error is ' + err.message);
});
```

### stop

stop(streamID: number, callback: AsyncCallback\<void>): void

停止播放音频资源。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| callback | AsyncCallback\<void> | 是   | 异步音频池stop的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
//先调用play方法给拿到对应的streamID
soundPool.stop(streamID, (error: BusinessError) => {
  if (error) {
    console.info(`stop sound Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('stop success');
  }
})

```

### stop

stop(streamID: number): Promise\<void>

停止streamID对应的音频播放。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
//先调用play方法给拿到对应的streamID
soundPool.stop(streamID).then(() => {
  console.info('stop success');
}, (err: BusinessError) => {
  console.error('soundpool load stop and catch error is ' + err.message);
});
```

### setLoop

setLoop(streamID: number, loop: number, callback: AsyncCallback\<void>): void;

设置循环模式。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| loop | number | 是   | 设置循环的次数，0为默认1次，小于0为一直循环。 |
| callback | AsyncCallback\<void> | 是   | 异步setLoop的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
//先通过调用play方法获取到对应的streamID
//设置循环2次
soundPool.setLoop(streamID, 2, (error: BusinessError) => {
  if (error) {
    console.info(`setLoop soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('setLoop success streamID:' + streamID);
  }
})
```

### setLoop

setLoop(streamID: number, loop: number): Promise\<void>

设置循环模式。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| loop | number | 是   | 设置循环的次数，0为默认1次，小于0为一直循环。|

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池setLoop方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
//先通过调用play方法获取到对应的streamID
//设置循环1次
soundPool.setLoop(streamID, 1).then(() => {
  console.info('setLoop success streamID:' + streamID);
}).catch((err: BusinessError) => {
  console.error('soundpool setLoop failed and catch error is ' + err.message);
});
```

### setPriority

setPriority(streamID: number, priority: number, callback: AsyncCallback\<void>): void

设置音频流播放的优先级。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| priority | number | 是   | 优先级，0表示最低优先级。 |
| callback | AsyncCallback\<void> | 是   | 异步音频池setPriority方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
// 先调用play方法获取到对应资源的streamID
// 给对应的streamID资源设置优先级为1
soundPool.setPriority(streamID, 1, (error: BusinessError) => {
  if (error) {
    console.info(`setPriority soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('setPriority success streamID:' + streamID);
  }
})

```

### setPriority

setPriority(streamID: number, priority: number): Promise\<void>

设置音频流优先级。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| priority | number | 是   | 优先级，0表示最低优先级。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池setPriority的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
// 先调用play方法获取到对应资源的streamID
// 给对应的streamID资源设置优先级为1

soundPool.setPriority(streamID, 1).then(() => {
  console.info('setPriority success');
}, (err: BusinessError) => {
  console.error('soundpool setPriority failed and catch error is ' + err.message);
});
```

### setRate

setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback\<void>): void

设置音频流播放速率。使用callback方式异步获取返回值。

> **说明：**
> 该接口在4.0版本开放，功能实现受设备影响有所区别(当前RK3568开发板支持倍速，其他设备暂不支持)。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| rate | [audio.AudioRendererRate](js-apis-audio.md#audiorendererrate8) | 是   | 音频rate相关参数。 |
| callback | AsyncCallback\<void> | 是   | 异步音频池setRate方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
let selectedAudioRendererRate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL; // 默认正常速率
// 先调用play方法获取到对应资源的streamID

soundPool.setRate(streamID, selectedAudioRendererRate, (error: BusinessError) => {
  if (error) {
    console.info(`setRate soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('setRate success streamID:' + streamID);
  }
})

```

### setRate

setRate(streamID: number, rate: audio.AudioRendererRate): Promise\<void>

设置音频流的播放速率。使用Promise方式异步获取返回值。

> **说明：**
> 该接口在4.0版本开放，功能实现受设备影响有所区别(当前RK3568开发板支持倍速，其他设备暂不支持)。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| rate | [audio.AudioRendererRate](js-apis-audio.md#audiorendererrate8) | 是   | 音频rate相关参数。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池setRate方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
let selectedAudioRendererRate: audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL; // 默认正常速率
// 先调用play方法获取到对应资源的streamID

soundPool.setRate(streamID, selectedAudioRendererRate).then(() => {
  console.info('setRate success');
}, (err: BusinessError) => {
  console.error('soundpool setRate failed and catch error is ' + err.message);
});
```

### setVolume

setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback\<void>): void

设置音频流播放音量。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| leftVolume | number | 是   | 左声道音量，设置范围为0.0-1.0之间。 |
| rightVolume | number | 是   | 右声道音量，当前右声道设置无效，以左声道为准。 |
| callback | AsyncCallback\<void> | 是   | 异步音频池setVolume方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
// 先调用play方法获取到对应资源的streamID
//设置音量为0.5
soundPool.setVolume(streamID, 0.5, 0.5, (error: BusinessError) => {
  if (error) {
    console.info(`setVolume soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('setVolume success streamID:' + streamID);
  }
})

```

### setVolume

setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise\<void>

设置音频流的播放音量。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| streamID | number | 是   | 音频流ID，通过play方法获取。 |
| leftVolume | number | 是   | 左声道音量，设置范围为0.0-1.0之间。 |
| rightVolume | number | 是   | 右声道音量，当前右声道设置无效，以左声道为准。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池setVolume方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let streamID: number;
// 先调用play方法获取到对应资源的streamID

soundPool.setVolume(streamID, 0.5, 0.5).then(() => {
  console.info('setVolume success');
}, (err: BusinessError) => {
  console.error('soundpool setVolume failed and catch error is ' + err.message);
});
```

### unload

unload(soundID: number, callback: AsyncCallback\<void>): void

卸载音频资源。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | 是   | 资源ID，通过load方法获取。 |
| callback | AsyncCallback\<void> | 是   | 异步音频池unload方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by callback. |
| 5400103  | I/O error. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let soundID: number;
// 先调用load方法获取到对应资源的soundID
soundPool.unload(soundID, (error: BusinessError) => {
  if (error) {
    console.info(`unload soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('unload success:');
  }
})

```

### unload

unload(soundID: number): Promise\<void>

卸载音频资源。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| soundID | number | 是   | 资源ID，通过load方法获取。 |

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池unload方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operation not allowed. Return by promise. |
| 5400103  | I/O error. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

let soundID: number;
// 先调用load方法获取到对应资源的soundID

soundPool.unload(soundID).then(() => {
  console.info('unload success');
}, (err: BusinessError) => {
  console.error('soundpool unload failed and catch error is ' + err.message);
});
```

### release

release(callback: AsyncCallback\<void>): void

释放音频池实例。使用callback方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步音频池release方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.release((error: BusinessError) => {
  if (error) {
    console.info(`release soundPool Error: errCode is ${error.code}, errMessage is ${error.message}`)
  } else {
    console.info('release success');
  }
})

```

### release

release(): Promise\<void>

释放音频池实例。使用Promise方式异步获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<void> | 异步音频池release方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)。

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.release().then(() => {
  console.info('release success');
}, (err: BusinessError) => {
  console.error('soundpool release failed and catch error is ' + err.message);
});
```

### on('loadComplete')

on(type: 'loadComplete', callback: Callback\<number>): void

音频池资源加载完成监听。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 支持的事件：'loadComplete'，对应的ID加载完成会触发此回调。 |
| callback | Callback\<number> | 是   | 对应资源加载完成的资源ID。                               |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.on('loadComplete', (soundId: number) => {
  console.info('loadComplete success，soundId：' + soundId)
})
```

### off('loadComplete')

off(type: 'loadComplete'): void

取消监听资源的加载完成。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 取消注册的事件：'loadComplete'。 |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.off('loadComplete')
```

### on('playFinished')

on(type: 'playFinished', callback: Callback\<void>): void

音频池资源播放完成监听。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 支持的事件：'playFinished'，音频流播放完成会触发此回调。 |
| callback | Callback\<void> | 是   |  异步'playFinished'的回调方法。        |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.on('playFinished', () => {
  console.info('playFinished success')
})
```

### off('playFinished')

off(type: 'playFinished'): void

取消监听音频池资源播放完成。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| type   | string | 是   | 取消注册的事件：'playFinished'。 |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.off('playFinished')
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

监听[SoundPool](#soundpool)的错误事件，该事件仅用于错误提示。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 错误事件回调类型，支持的事件：'error'，用户操作和系统都会触发此事件。 |
| callback | ErrorCallback | 是   | 错误事件回调方法：使用播放器的过程中发生错误，会提供错误码ID和错误信息。 |

SoundPool回调的**错误分类**<a name = error_info></a>可以分为以下几种：

| 错误码ID | 错误信息              | 说明                                                         |
| -------- | --------------------- | ------------------------------------------------------------ |
| 401      | Invalid Parameter:    | 入参错误，表示调用无效。                                     |
| 801      | Unsupport Capability: | 不支持该API能力，表示调用无效。                              |
| 5400101  | No Memory:            | 内存不足。 |
| 5400102  | Operation Not Allowed:   | 当前状态机不支持此操作，表示调用无效。                       |
| 5400103  | IO Error:             | I/O异常。 |
| 5400105  | Service Died:         | 播放进程死亡，音频池依赖的service端发生异常。|

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});

soundPool.on('error', (error: BusinessError) => {
  console.error('error happened,and error message is :' + error.message)
  console.error('error happened,and error code is :' + error.code)
})
```

### off('error')

off(type: 'error'): void

取消监听音频池的错误事件。

**系统能力：** SystemCapability.Multimedia.Media.SoundPool

**参数：**

| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | ----------------------------------------- |
| type   | string | 是   | 错误事件回调类型，取消注册的事件：'error'。 |

**示例：**

```js
//创建soundPool实例
let soundPool: media.SoundPool;
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MEDIA,
  rendererFlags: 1
}
media.createSoundPool(5, audioRendererInfo, (error: BusinessError, soundPool_: media.SoundPool) => {
  if (error) {
    console.info(`createSoundPool failed`)
    return;
  } else {
    soundPool = soundPool_;
    console.info(`createSoundPool success`)
  }
});
soundPool.off('error')
```