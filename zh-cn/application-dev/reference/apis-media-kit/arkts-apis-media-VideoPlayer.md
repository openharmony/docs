# 废弃的Interface (VideoPlayer, deprecated)

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer](arkts-apis-media-AVPlayer.md)替代。

视频播放管理类，用于管理和播放视频媒体。在调用VideoPlayer的方法前，需要先通过[createVideoPlayer()](arkts-apis-media-f.md#mediacreatevideoplayerdeprecated)构建一个VideoPlayer实例。

## 导入模块

```ts
import { media } from '@kit.MediaKit';
```

## 属性

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                            | 类型                                                   | 只读 | 可选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>                | string                                                 | 否   | 否   | 视频媒体URL，支持当前主流的视频格式(mp4、mpeg-ts、mkv)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http\://xx<br/>3. https网络播放: https\://xx<br/>4. hls网络播放路径：http\://xx或者https\://xx<br>5. file类型: file\://xx<br/>**说明：**<br>从API version 11开始不支持webm。 |
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](arkts-apis-media-i.md#avfiledescriptor9)                 | 否   | 否   | 视频媒体文件描述，使用场景：应用中的视频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>视频1(地址偏移:0，字节长度:100)<br/>视频2(地址偏移:101，字节长度:50)<br/>视频3(地址偏移:151，字节长度:150)<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的视频文件: 请使用src=fd://xx <br/> |
| loop<sup>8+</sup>               | boolean                                                | 否   | 否   | 视频循环播放属性，设置为'true'表示循环播放。                 |
| videoScaleType<sup>9+</sup>     | [VideoScaleType](arkts-apis-media-e.md#videoscaletype9)                     | 否   | 是   | 视频缩放模式。默认值为VIDEO_SCALE_TYPE_FIT。                                               |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](../apis-audio-kit/arkts-apis-audio-e.md#interruptmode9) | 否   | 是   | 音频焦点模型。                                               |
| currentTime<sup>8+</sup>        | number                                                 | 是   | 否   | 视频的当前播放位置，单位为毫秒（ms）。                       |
| duration<sup>8+</sup>           | number                                                 | 是   | 否   | 视频时长，单位为毫秒（ms），返回-1表示直播模式。             |
| state<sup>8+</sup>              | [VideoPlayState](arkts-apis-media-t.md#videoplaystatedeprecated)                    | 是   | 否   | 视频播放的状态。                                             |
| width<sup>8+</sup>              | number                                                 | 是   | 否   | 视频宽，单位为像素（px）。                                   |
| height<sup>8+</sup>             | number                                                 | 是   | 否   | 视频高，单位为像素（px）。                                   |

## setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

设置SurfaceId。通过回调函数获取返回值。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.surfaceId](arkts-apis-media-AVPlayer.md#属性)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型                 | 必填 | 说明                      |
| --------- | -------------------- | ---- | ------------------------- |
| surfaceId | string               | 是   | SurfaceId.                 |
| callback  | AsyncCallback\<void> | 是   | 回调函数。当设置SurfaceId成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set DisplaySurface!');
  } else {
    console.info('Succeeded in setting DisplaySurface!');
  }
});
```

## setDisplaySurface<sup>(deprecated)</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

设置SurfaceId。通过Promise获取返回值。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.surfaceId](arkts-apis-media-AVPlayer.md#属性)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型   | 必填 | 说明      |
| --------- | ------ | ---- | --------- |
| surfaceId | string | 是   | SurfaceId. |

**返回值：**

| 类型           | 说明                           |
| -------------- | ------------------------------ |
| Promise\<void> | 设置SurfaceId的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let surfaceId: string = '';
videoPlayer.setDisplaySurface(surfaceId).then(() => {
  console.info('Succeeded in setting DisplaySurface');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## prepare<sup>(deprecated)</sup>

prepare(callback: AsyncCallback\<void>): void

准备播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.prepare](arkts-apis-media-AVPlayer.md#prepare9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当准备播放视频成功，err为undefined，否则为错误对象。|

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare((err: BusinessError) => {
  if (err) {
    console.error('Failed to prepare!');
  } else {
    console.info('Succeeded in preparing!');
  }
});
```

## prepare<sup>(deprecated)</sup>

prepare(): Promise\<void>

准备播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.prepare](arkts-apis-media-AVPlayer.md#prepare9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 准备播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.prepare().then(() => {
  console.info('Succeeded in preparing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## play<sup>(deprecated)</sup>

play(callback: AsyncCallback\<void>): void

开始播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.play](arkts-apis-media-AVPlayer.md#play9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当开始播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play((err: BusinessError) => {
  if (err) {
    console.error('Failed to play!');
  } else {
    console.info('Succeeded in playing!');
  }
});
```

## play<sup>(deprecated)</sup>

play(): Promise\<void>

开始播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.play](arkts-apis-media-AVPlayer.md#play9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 开始播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.play().then(() => {
  console.info('Succeeded in playing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## pause<sup>(deprecated)</sup>

pause(callback: AsyncCallback\<void>): void

通过回调方式暂停播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.pause](arkts-apis-media-AVPlayer.md#pause9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当暂停播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause((err: BusinessError) => {
  if (err) {
    console.error('Failed to pause!');
  } else {
    console.info('Succeeded in pausing!');
  }
});
```

## pause<sup>(deprecated)</sup>

pause(): Promise\<void>

暂停播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.pause](arkts-apis-media-AVPlayer.md#pause9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 暂停播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.pause().then(() => {
  console.info('Succeeded in pausing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## stop<sup>(deprecated)</sup>

stop(callback: AsyncCallback\<void>): void

通过回调方式停止播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.stop](arkts-apis-media-AVPlayer.md#stop9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当停止播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop((err: BusinessError) => {
  if (err) {
    console.error('Failed to stop!');
  } else {
    console.info('Succeeded in stopping!');
  }
});
```

## stop<sup>(deprecated)</sup>

stop(): Promise\<void>

停止播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.stop](arkts-apis-media-AVPlayer.md#stop9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 停止播放视频的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.stop().then(() => {
  console.info('Succeeded in stopping');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## reset<sup>(deprecated)</sup>

reset(callback: AsyncCallback\<void>): void

重置播放视频。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.reset](arkts-apis-media-AVPlayer.md#reset9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当重置播放视频成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset((err: BusinessError) => {
  if (err) {
    console.error('Failed to reset!');
  } else {
    console.info('Succeeded in resetting!');
  }
});
```

## reset<sup>(deprecated)</sup>

reset(): Promise\<void>

重置播放视频。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.reset](arkts-apis-media-AVPlayer.md#reset9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.reset().then(() => {
  console.info('Succeeded in resetting');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## seek<sup>(deprecated)</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

跳转到指定播放位置，默认跳转到指定时间点的上一个关键帧。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](arkts-apis-media-AVPlayer.md#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。跳转到指定播放位置成功时，err为undefined，data为获取到的跳转到的播放位置，否则为错误对象。                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});

let seekTime: number = 5000;
videoPlayer.seek(seekTime, (err: BusinessError, result: number) => {
  if (err) {
    console.error('Failed to do seek!');
  } else {
    console.info('Succeeded in doing seek!');
  }
});
```

## seek<sup>(deprecated)</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

跳转到指定播放位置。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](arkts-apis-media-AVPlayer.md#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode     | [SeekMode](arkts-apis-media-e.md#seekmode8) | 是   | 跳转模式。                                                   |
| callback | AsyncCallback\<number> | 是   | 回调函数。跳转到指定播放位置成功时，err为undefined，data为获取到的跳转到的播放位置，否则为错误对象。                               |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC, (err: BusinessError, result: number) => {
    if (err) {
      console.error('Failed to do seek!');
    } else {
      console.info('Succeeded in doing seek!');
    }
  });
}
```

## seek<sup>(deprecated)</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

跳转到指定播放位置，如果没有设置mode则跳转到指定时间点的上一个关键帧。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.seek](arkts-apis-media-AVPlayer.md#seek9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode   | [SeekMode](arkts-apis-media-e.md#seekmode8) | 否   | 基于视频I帧的跳转模式，默认为SEEK_PREV_SYNC模式。            |

**返回值：**

| 类型             | 说明                                        |
| ---------------- | ------------------------------------------- |
| Promise\<number> | 跳转到指定播放位置的Promise返回值，单位ms。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let seekTime: number = 5000;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).seek(seekTime).then((seekDoneTime: number) => { // seekDoneTime表示seek完成后的时间点。
    console.info('Succeeded in doing seek');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });

  (videoPlayer as media.VideoPlayer).seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime: number) => {
    console.info('Succeeded in doing seek');
  }).catch((error: BusinessError) => {
    console.error(`video catchCallback, error:${error}`);
  });
}
```

## setVolume<sup>(deprecated)</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

设置音量。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setVolume](arkts-apis-media-AVPlayer.md#setvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。当设置音量成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol, (err: BusinessError) => {
  if (err) {
    console.error('Failed to set Volume!');
  } else {
    console.info('Succeeded in setting Volume!');
  }
});
```

## setVolume<sup>(deprecated)</sup>

setVolume(vol: number): Promise\<void>

设置音量。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setVolume](arkts-apis-media-AVPlayer.md#setvolume9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**返回值：**

| 类型           | 说明                      |
| -------------- | ------------------------- |
| Promise\<void> | 设置音量的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let vol: number = 0.5;
videoPlayer.setVolume(vol).then(() => {
  console.info('Succeeded in setting Volume');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## release<sup>(deprecated)</sup>

release(callback: AsyncCallback\<void>): void

释放视频资源。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.release](arkts-apis-media-AVPlayer.md#release9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 回调函数。当释放视频资源成功，err为undefined，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release((err: BusinessError) => {
  if (err) {
    console.error('Failed to release!');
  } else {
    console.info('Succeeded in releasing!');
  }
});
```

## release<sup>(deprecated)</sup>

release(): Promise\<void>

释放视频资源。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.release](arkts-apis-media-AVPlayer.md#release9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 释放视频资源的Promise返回值。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.release().then(() => {
  console.info('Succeeded in releasing');
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(callback: AsyncCallback\<Array\<MediaDescription>>): void

获取视频轨道信息。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](arkts-apis-media-AVPlayer.md#gettrackdescription9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback\<Array\<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | 是   | 回调函数。获取视频轨道信息成功时，err为undefined，data为获取到的视频轨道信息MediaDescription数组，否则为错误对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription((error: BusinessError, arrList: Array<media.MediaDescription>) => {
  if ((arrList) != null) {
    console.info('Succeeded in getting TrackDescription');
  } else {
    console.error(`Failed to get TrackDescription, error:${error}`);
  }
});
```

## getTrackDescription<sup>(deprecated)</sup>

getTrackDescription(): Promise\<Array\<MediaDescription>>

获取视频轨道信息。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.getTrackDescription](arkts-apis-media-AVPlayer.md#gettrackdescription9-1)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型                                                   | 说明                                            |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](arkts-apis-media-i.md#mediadescription8)>> | Promise对象，返回获取的视频轨道信息MediaDescription数组。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.getTrackDescription().then((arrList: Array<media.MediaDescription>) => {
  if (arrList != null) {
    console.info('Succeeded in getting TrackDescription');
  } else {
    console.error('Failed to get TrackDescription');
  }
}).catch((error: BusinessError) => {
  console.error(`video catchCallback, error:${error}`);
});
```

## setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number, callback: AsyncCallback\<number>): void

设置播放速度。通过回调函数获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setSpeed](arkts-apis-media-AVPlayer.md#setspeed9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                       |
| -------- | ---------------------- | ---- | ---------------------------------------------------------- |
| speed    | number                 | 是   | 指定播放视频速度，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。设置播放速度成功时，err为undefined，data为设置的播放速度，否则为错误对象。                                   |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed, (err: BusinessError, result: number) => {
    if (err) {
      console.error('Failed to set Speed!');
    } else {
      console.info('Succeeded in setting Speed!');
    }
  });
}
```

## setSpeed<sup>(deprecated)</sup>

setSpeed(speed: number): Promise\<number>

设置播放速度。通过Promise获取返回值。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.setSpeed](arkts-apis-media-AVPlayer.md#setspeed9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                       |
| ------ | ------ | ---- | ---------------------------------------------------------- |
| speed  | number | 是   | 指定播放视频速度，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise对象，返回设置的播放速度，具体见[PlaybackSpeed](arkts-apis-media-e.md#playbackspeed8)。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let videoPlayer: media.VideoPlayer | null = null;
media.createVideoPlayer((error: BusinessError, video: media.VideoPlayer) => {
  if (video != null) {
    videoPlayer = video;
    console.info('Succeeded in creating VideoPlayer');
  } else {
    console.error(`Failed to create VideoPlayer, error:${error}`);
  }
});
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;
if (videoPlayer) {
  (videoPlayer as media.VideoPlayer).setSpeed(speed).then((result: number) => {
    console.info('Succeeded in setting Speed');
  }).catch((error: BusinessError) => {
    console.error(`Failed to set Speed, error:${error}`);//todo:: error.
  });
}
```

## on('playbackCompleted')<sup>(deprecated)</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

开始监听视频播放完成事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('stateChange')](arkts-apis-media-AVPlayer.md#onstatechange9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | 是   | 视频播放完成事件回调类型，支持的事件：'playbackCompleted'。 |
| callback | Callback\<void> | 是   | 视频播放完成事件回调方法。                                  |

**示例：**

```ts
videoPlayer.on('playbackCompleted', () => {
  console.info('playbackCompleted called!');
});
```

## on('bufferingUpdate')<sup>(deprecated)</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

开始监听视频缓存更新事件。仅网络播放支持该订阅事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('bufferingUpdate')](arkts-apis-media-AVPlayer.md#onbufferingupdate9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | function | 是   | 视频缓存事件回调方法。<br>[BufferingInfoType](arkts-apis-media-e.md#bufferinginfotype8)value值固定为0。 |

**示例：**

```ts
videoPlayer.on('bufferingUpdate', (infoType: media.BufferingInfoType, value: number) => {
  console.info('video bufferingInfo type: ' + infoType);
  console.info('video bufferingInfo value: ' + value);
});
```

## on('startRenderFrame')<sup>(deprecated)</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

开始监听视频播放首帧送显上报事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('startRenderFrame')](arkts-apis-media-AVPlayer.md#onstartrenderframe9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 视频播放首帧送显上报事件回调类型，支持的事件：'startRenderFrame'。 |
| callback | Callback\<void> | 是   | 视频播放首帧送显上报事件回调方法。                           |

**示例：**

```ts
videoPlayer.on('startRenderFrame', () => {
  console.info('startRenderFrame called!');
});
```

## on('videoSizeChanged')<sup>(deprecated)</sup>

on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void

开始监听视频播放宽高变化事件。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('videoSizeChange')](arkts-apis-media-AVPlayer.md#onvideosizechange9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChanged'。 |
| callback | function | 是   | 视频播放宽高变化事件回调方法，width表示宽，height表示高。    |

**示例：**

```ts
videoPlayer.on('videoSizeChanged', (width: number, height: number) => {
  console.info('video width is: ' + width);
  console.info('video height is: ' + height);
});
```
## on('audioInterrupt')<sup>(deprecated)</sup>

on(type: 'audioInterrupt', callback: (info: audio.InterruptEvent) => void): void

监听音频焦点变化事件，参考[audio.InterruptEvent](../apis-audio-kit/arkts-apis-audio-i.md#interruptevent9)。

> **说明：**
> 从API version 9开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('audioInterrupt')](arkts-apis-media-AVPlayer.md#onaudiointerrupt9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                     |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------------- |
| type     | string                                                       | 是   | 音频焦点变化事件回调类型，支持的事件：'audioInterrupt'。 |
| callback | function | 是   | 音频焦点变化事件回调方法。                               |

**示例：**

```ts
import { audio } from '@kit.AudioKit';

videoPlayer.on('audioInterrupt', (info: audio.InterruptEvent) => {
  console.info('audioInterrupt called,and InterruptEvent info is:' + info);
});
```

## on('error')<sup>(deprecated)</sup>

on(type: 'error', callback: ErrorCallback): void

开始监听视频播放错误事件，当上报error错误事件后，用户需处理error事件，退出播放操作。

> **说明：**
> 从API version 8开始支持，从API version 9开始废弃，建议使用[AVPlayer.on('error')](arkts-apis-media-AVPlayer.md#onerror9)替代。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 播放错误事件回调类型，支持的事件包括：'error'。<br>- 'error'：视频播放中发生错误，触发该事件。 |
| callback | [ErrorCallback](../apis-basic-services-kit/js-apis-base.md#errorcallback) | 是   | 播放错误事件回调方法。                                       |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

videoPlayer.on('error', (error: BusinessError) => {  // 设置'error'事件回调。
  console.error(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  //设置错误的播放地址，触发'error'事件。
```