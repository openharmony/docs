# 媒体服务

> **说明：**
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

媒体子系统为开发者提供一套简单且易于理解的接口，使得开发者能够方便接入系统并使用系统的媒体资源。

媒体子系统包含了音视频相关媒体业务，提供以下常用功能：

- 音频播放（[AudioPlayer](#audioplayer)）
- 视频播放（[VideoPlayer](#videoplayer8)）
- 音频录制（[AudioRecorder](#audiorecorder)）
- 视频录制（[VideoRecorder](#videorecorder9)）

后续将提供以下功能：DataSource音视频播放、音视频编解码、容器封装解封装、媒体能力查询等功能。

## 导入模块

```js
import media from '@ohos.multimedia.media';
```

##  media.createAudioPlayer

createAudioPlayer(): [AudioPlayer](#audioplayer)

同步方式创建音频播放实例。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**返回值：**

| 类型                        | 说明                                                         |
| --------------------------- | ------------------------------------------------------------ |
| [AudioPlayer](#audioplayer) | 返回AudioPlayer类实例，失败时返回null。可用于音频播放、暂停、停止等操作。 |

**示例：**

```js
let audioPlayer = media.createAudioPlayer();
```

## media.createVideoPlayer<sup>8+</sup>

createVideoPlayer(callback: AsyncCallback\<[VideoPlayer](#videoplayer8)>): void

异步方式创建视频播放实例，通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                           |
| -------- | ------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoPlayer](#videoplayer8)> | 是   | 回调函数。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |

**示例：**

```js
let videoPlayer

media.createVideoPlayer((error, video) => {
   if (video != null) {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info(`video createVideoPlayer fail, error:${error}`);
   }
});
```

## media.createVideoPlayer<sup>8+</sup>

createVideoPlayer(): Promise<[VideoPlayer](#videoplayer8)>

异步方式创建视频播放实例，通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型                                  | 说明                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoPlayer](#videoplayer8)> | Promise对象。异步返回VideoPlayer实例，失败时返回null。可用于管理和播放视频媒体。 |

**示例：**

```js
let videoPlayer

media.createVideoPlayer().then((video) => {
   if (video != null) {
       videoPlayer = video;
       console.info('video createVideoPlayer success');
   } else {
       console.info('video createVideoPlayer fail');
   }
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

## media.createAudioRecorder

createAudioRecorder(): AudioRecorder

创建音频录制的实例来控制音频的录制。
一台设备只允许创建一个录制实例。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**返回值:**

| 类型                            | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ |
| [AudioRecorder](#audiorecorder) | 返回AudioRecorder类实例，失败时返回null。可用于录制音频媒体。 |

**示例：**

```js
let audioRecorder = media.createAudioRecorder();
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(callback: AsyncCallback\<[VideoRecorder](#videorecorder9)>): void

异步方式创建视频录制实例。通过注册回调函数获取返回值。
一台设备只允许创建一个录制实例。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                           |
| -------- | ----------------------------------------------- | ---- | ------------------------------ |
| callback | AsyncCallback<[VideoRecorder](#videorecorder9)> | 是   | 回调函数。异步返回VideoRecorder实例，失败时返回null。可用于录制视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 5400101  | No memory. Return by callback. |

**示例：**

```js
let videoRecorder

media.createVideoRecorder((error, video) => {
   if (video != null) {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info(`video createVideoRecorder fail, error:${error}`);
   }
});
```

## media.createVideoRecorder<sup>9+</sup>

createVideoRecorder(): Promise<[VideoRecorder](#videorecorder9)>

异步方式创建视频录制实例。通过Promise获取返回值。
一台设备只允许创建一个录制实例。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型                                      | 说明                                                         |
| ----------------------------------------- | ------------------------------------------------------------ |
| Promise<[VideoRecorder](#videorecorder9)> | Promise对象。异步返回VideoRecorder实例，失败时返回null。可用于录制视频媒体。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                      |
| -------- | ----------------------------- |
| 5400101  | No memory. Return by promise. |

**示例：**

```js
let videoRecorder

media.createVideoRecorder().then((video) => {
    if (video != null) {
       videoRecorder = video;
       console.info('video createVideoRecorder success');
   } else {
       console.info('video createVideoRecorder fail');
   }
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```



## MediaErrorCode<sup>8+</sup>

媒体服务错误类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                       | 值   | 说明                                   |
| -------------------------- | ---- | -------------------------------------- |
| MSERR_OK                   | 0    | 表示操作成功。                         |
| MSERR_NO_MEMORY            | 1    | 表示申请内存失败，系统可能无可用内存。 |
| MSERR_OPERATION_NOT_PERMIT | 2    | 表示无权限执行此操作。                 |
| MSERR_INVALID_VAL          | 3    | 表示传入入参无效。                     |
| MSERR_IO                   | 4    | 表示发生IO错误。                       |
| MSERR_TIMEOUT              | 5    | 表示操作超时。                         |
| MSERR_UNKNOWN              | 6    | 表示未知错误。                         |
| MSERR_SERVICE_DIED         | 7    | 表示服务端失效。                       |
| MSERR_INVALID_STATE        | 8    | 表示在当前状态下，不允许执行此操作。   |
| MSERR_UNSUPPORTED          | 9    | 表示在当前版本下，不支持此操作。       |

## MediaType<sup>8+</sup>

媒体类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称           | 值   | 说明       |
| -------------- | ---- | ---------- |
| MEDIA_TYPE_AUD | 0    | 表示音频。 |
| MEDIA_TYPE_VID | 1    | 表示视频。 |

## CodecMimeType<sup>8+</sup>

Codec MIME类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称         | 值                    | 说明                     |
| ------------ | --------------------- | ------------------------ |
| VIDEO_H263   | 'video/h263'          | 表示视频/h263类型。      |
| VIDEO_AVC    | 'video/avc'           | 表示视频/avc类型。       |
| VIDEO_MPEG2  | 'video/mpeg2'         | 表示视频/mpeg2类型。     |
| VIDEO_MPEG4  | 'video/mp4v-es'       | 表示视频/mpeg4类型。     |
| VIDEO_VP8    | 'video/x-vnd.on2.vp8' | 表示视频/vp8类型。       |
| AUDIO_AAC    | 'audio/mp4a-latm'     | 表示音频/mp4a-latm类型。 |
| AUDIO_VORBIS | 'audio/vorbis'        | 表示音频/vorbis类型。    |
| AUDIO_FLAC   | 'audio/flac'          | 表示音频/flac类型。      |

## MediaDescriptionKey<sup>8+</sup>

媒体信息描述枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称                     | 值              | 说明                                                         |
| ------------------------ | --------------- | ------------------------------------------------------------ |
| MD_KEY_TRACK_INDEX       | 'track_index'   | 表示轨道序号，其对应键值类型为number。                       |
| MD_KEY_TRACK_TYPE        | 'track_type'    | 表示轨道类型，其对应键值类型为number，参考[MediaType](#mediatype8)。 |
| MD_KEY_CODEC_MIME        | 'codec_mime'    | 表示codec_mime类型，其对应键值类型为string。                 |
| MD_KEY_DURATION          | 'duration'      | 表示媒体时长，其对应键值类型为number，单位为毫秒（ms）。     |
| MD_KEY_BITRATE           | 'bitrate'       | 表示比特率，其对应键值类型为number，单位为比特率（bps）。    |
| MD_KEY_WIDTH             | 'width'         | 表示视频宽度，其对应键值类型为number，单位为像素（px）。     |
| MD_KEY_HEIGHT            | 'height'        | 表示视频高度，其对应键值类型为number，单位为像素（px）。     |
| MD_KEY_FRAME_RATE        | 'frame_rate'    | 表示视频帧率，其对应键值类型为number，单位为100帧每秒（100fps）。 |
| MD_KEY_AUD_CHANNEL_COUNT | 'channel_count' | 表示声道数，其对应键值类型为number。                         |
| MD_KEY_AUD_SAMPLE_RATE   | 'sample_rate'   | 表示采样率，其对应键值类型为number，单位为赫兹（Hz）。       |

## BufferingInfoType<sup>8+</sup>

缓存事件类型枚举。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称              | 值   | 说明                             |
| ----------------- | ---- | -------------------------------- |
| BUFFERING_START   | 1    | 表示开始缓存。                   |
| BUFFERING_END     | 2    | 表示结束缓存。                   |
| BUFFERING_PERCENT | 3    | 表示缓存百分比。                 |
| CACHED_DURATION   | 4    | 表示缓存时长，单位为毫秒（ms）。 |

## AudioPlayer

音频播放管理类，用于管理和播放音频媒体。在调用AudioPlayer的方法前，需要先通过[createAudioPlayer()](#mediacreateaudioplayer)构建一个[AudioPlayer](#audioplayer)实例。

音频播放demo可参考：[音频播放开发指导](../../media/audio-playback.md)

### 属性<a name=audioplayer_属性></a>

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

| 名称                            | 类型                                                   | 可读 | 可写 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| src                             | string                                                 | 是   | 是   | 音频媒体URI，支持当前主流的音频格式(m4a、aac、mp3、ogg、wav)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http://xx<br/>3. https网络播放: https://xx<br/>4. hls网络播放路径：http://xx或者https://xx<br/>**需要权限：** ohos.permission.READ_MEDIA 或 ohos.permission.INTERNET。 |
| fdSrc<sup>9+</sup>              | [AVFileDescriptor](#avfiledescriptor9)                 | 是   | 是   | 音频媒体文件描述，使用场景：应用中的音频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>音乐1(地址偏移:0，字节长度:100)<br/>音乐2(地址偏移:101，字节长度:50)<br/>音乐3(地址偏移:151，字节长度:150)<br/>1. 播放音乐1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放音乐2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放音乐3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的音乐文件: 请使用src=fd://xx <br/> |
| loop                            | boolean                                                | 是   | 是   | 音频循环播放属性，设置为'true'表示循环播放。                 |
| audioInterruptMode<sup>9+</sup> | [audio.InterruptMode](js-apis-audio.md#interruptmode9) | 是   | 是   | 音频焦点模型。                                               |
| currentTime                     | number                                                 | 是   | 否   | 音频的当前播放位置，单位为毫秒（ms）。                       |
| duration                        | number                                                 | 是   | 否   | 音频时长，单位为毫秒（ms）。                                 |
| state                           | [AudioState](#audiostate)                              | 是   | 否   | 可以查询音频播放的状态，该状态不可作为调用play/pause/stop等状态切换的触发条件。 |
### play<a name=audioplayer_play></a>

play(): void

开始播放音频资源，需在[dataLoad](#audioplayer_on)事件成功触发后，才能调用。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```js
audioPlayer.on('play', () => {    //设置'play'事件回调
    console.log('audio play success');
});
audioPlayer.play();
```

### pause<a name=audioplayer_pause></a>

pause(): void

暂停播放音频资源。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```js
audioPlayer.on('pause', () => {    //设置'pause'事件回调
    console.log('audio pause success');
});
audioPlayer.pause();
```

### stop<a name=audioplayer_stop></a>

stop(): void

停止播放音频资源。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```js
audioPlayer.on('stop', () => {    //设置'stop'事件回调
    console.log('audio stop success');
});
audioPlayer.stop();
```

### reset<sup>7+</sup><a name=audioplayer_reset></a>

reset(): void

重置播放音频资源。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```js
audioPlayer.on('reset', () => {    //设置'reset'事件回调
    console.log('audio reset success');
});
audioPlayer.reset();
```

### seek<a name=audioplayer_seek></a>

seek(timeMs: number): void

跳转到指定播放位置。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                        |
| ------ | ------ | ---- | ----------------------------------------------------------- |
| timeMs | number | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围[0, duration]。 |

**示例：**

```js
audioPlayer.on('timeUpdate', (seekDoneTime) => {    //设置'timeUpdate'事件回调
    if (seekDoneTime == null) {
        console.info('audio seek fail');
        return;
    }
    console.log('audio seek success. seekDoneTime: ' + seekDoneTime);
});
audioPlayer.seek(30000);    //seek到30000ms的位置
```

### setVolume<a name=audioplayer_setvolume></a>

setVolume(vol: number): void

设置音量。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| vol    | number | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**示例：**

```js
audioPlayer.on('volumeChange', () => {    //设置'volumeChange'事件回调
    console.log('audio volumeChange success');
});
audioPlayer.setVolume(1);    //设置音量到100%
```

### release<a name=audioplayer_release></a>

release(): void

释放音频资源。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**示例：**

```js
audioPlayer.release();
audioPlayer = undefined;
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription1></a>

getTrackDescription(callback: AsyncCallback<Array\<MediaDescription>>): void

通过回调方式获取音频轨道信息。需在[dataLoad](#audioplayer_on)事件成功触发后，才能调用。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | 是   | 音频轨道信息MediaDescription数组回调方法。 |

**示例：**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('audio key is ' + item);
        console.info('audio value is ' + property);
    }
}

audioPlayer.getTrackDescription((error, arrList) => {
    if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
            printfDescription(arrList[i]);
        }
    } else {
        console.log(`audio getTrackDescription fail, error:${error}`);
    }
});
```

### getTrackDescription<sup>8+</sup><a name=audioplayer_gettrackdescription2></a>

getTrackDescription(): Promise<Array\<MediaDescription>>

通过Promise方式获取音频轨道信息。需在[dataLoad](#audioplayer_on)事件成功触发后，才能调用

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**返回值：**

| 类型                                                   | 说明                                            |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | 音频轨道信息MediaDescription数组Promise返回值。 |

**示例：**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('audio key is ' + item);
        console.info('audio value is ' + property);
    }
}
let arrayDescription = null
audioPlayer.getTrackDescription().then((arrList) => {
    if (arrList != null) {
        arrayDescription = arrList;
    } else {
        console.log('audio getTrackDescription fail');
    }
}).catch((error) => {
   console.info(`audio catchCallback, error:${error}`);
});

for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: [BufferingInfoType](#bufferinginfotype8), value: number) => void): void

开始订阅音频缓存更新事件。仅网络播放支持该订阅事件。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 音频缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | function | 是   | 音频缓存事件回调方法。<br>[BufferingInfoType](#bufferinginfotype8)为BUFFERING_PERCENT或CACHED_DURATION时，value值有效，否则固定为0。 |

**示例：**

```js
audioPlayer.on('bufferingUpdate', (infoType, value) => {
    console.log('audio bufferingInfo type: ' + infoType);
    console.log('audio bufferingInfo value: ' + value);
});
```

 ### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')<a name = audioplayer_on></a>

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void): void

开始订阅音频播放事件。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型       | 必填 | 说明                                                         |
| -------- | ---------- | ---- | ------------------------------------------------------------ |
| type     | string     | 是   | 播放事件回调类型，支持的事件包括：'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange'。<br>- 'play'：完成[play()](#audioplayer_play)调用，音频开始播放，触发该事件。<br>- 'pause'：完成[pause()](#audioplayer_pause)调用，音频暂停播放，触发该事件。<br>- 'stop'：完成[stop()](#audioplayer_stop)调用，音频停止播放，触发该事件。<br>- 'reset'：完成[reset()](#audioplayer_reset)调用，播放器重置，触发该事件。<br>- 'dataLoad'：完成音频数据加载后触发该事件，即src属性设置完成后触发该事件。<br>- 'finish'：完成音频播放后触发该事件。<br>- 'volumeChange'：完成[setVolume()](#audioplayer_setvolume)调用，播放音量改变后触发该事件。 |
| callback | () => void | 是   | 播放事件回调方法。                                           |

**示例：**

```js
import fileio from '@ohos.fileio'

let audioPlayer = media.createAudioPlayer();  //创建一个音频播放实例
audioPlayer.on('dataLoad', () => {            //设置'dataLoad'事件回调，src属性设置成功后，触发此回调
    console.info('audio set source success');
    audioPlayer.play();                       //开始播放，并触发'play'事件回调
});
audioPlayer.on('play', () => {                //设置'play'事件回调
    console.info('audio play success');
    audioPlayer.seek(30000);                  //调用seek方法，并触发'timeUpdate'事件回调
});
audioPlayer.on('pause', () => {               //设置'pause'事件回调
    console.info('audio pause success');
    audioPlayer.stop();                       //停止播放，并触发'stop'事件回调
});
audioPlayer.on('reset', () => {               //设置'reset'事件回调
    console.info('audio reset success');
    audioPlayer.release();                    //释放播放实例资源
    audioPlayer = undefined;
});
audioPlayer.on('timeUpdate', (seekDoneTime) => {  //设置'timeUpdate'事件回调
    if (seekDoneTime == null) {
        console.info('audio seek fail');
        return;
    }
    console.info('audio seek success, and seek time is ' + seekDoneTime);
    audioPlayer.setVolume(0.5);                //设置音量为50%，并触发'volumeChange'事件回调
});
audioPlayer.on('volumeChange', () => {         //设置'volumeChange'事件回调
    console.info('audio volumeChange success');
    audioPlayer.pause();                       //暂停播放，并触发'pause'事件回调
});
audioPlayer.on('finish', () => {               //设置'finish'事件回调
    console.info('audio play finish');
    audioPlayer.stop();                        //停止播放，并触发'stop'事件回调
});
audioPlayer.on('error', (error) => {           //设置'error'事件回调
    console.info(`audio error called, error: ${error}`);
});

// 用户选择视频设置fd(本地播放)
let fdPath = 'fd://';
// path路径的码流可通过"hdc file send D:\xxx\01.mp3 /data/accounts/account_0/appdata" 命令，将其推送到设备上
let path = '/data/accounts/account_0/appdata/ohos.xxx.xxx.xxx/01.mp3';
fileio.open(path).then((fdValue) => {
   fdPath = fdPath + '' + fdValue;
   console.info('open fd success fd is' + fdPath);
}, (err) => {
   console.info('open fd failed err is' + err);
}).catch((err) => {
   console.info('open fd failed err is' + err);
});
audioPlayer.src = fdPath;  //设置src属性，并触发'dataLoad'事件回调
```

### on('timeUpdate')

on(type: 'timeUpdate', callback: Callback\<number>): void

开始订阅音频播放时间更新事件。处于播放状态时，每隔1s上报一次该事件。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型              | 必填 | 说明                                                         |
| -------- | ----------------- | ---- | ------------------------------------------------------------ |
| type     | string            | 是   | 播放事件回调类型，支持的事件包括：'timeUpdate'。<br>- 'timeUpdate'：音频播放时间戳更新，开始播放后自动触发该事件。 |
| callback | Callback\<number> | 是   | 播放事件回调方法。回调方法入参为更新后的时间戳。             |

**示例：**

```js
audioPlayer.on('timeUpdate', (newTime) => {    //设置'timeUpdate'事件回调
    if (newTime == null) {
        console.info('audio timeUpadate fail');
        return;
    }
    console.log('audio timeUpadate success. seekDoneTime: ' + newTime);
});
audioPlayer.play();    //开始播放后，自动触发时间戳更新事件
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

开始订阅音频播放错误事件，当上报error错误事件后，用户需处理error事件，退出播放操作。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 播放错误事件回调类型，支持的事件包括：'error'。<br>- 'error'：音频播放中发生错误，触发该事件。 |
| callback | ErrorCallback | 是   | 播放错误事件回调方法。                                       |

**示例：**

```js
audioPlayer.on('error', (error) => {      //设置'error'事件回调
    console.info(`audio error called, error: ${error}`); 
});
audioPlayer.setVolume(3);  //设置volume为无效值，触发'error'事件
```

## AudioState

音频播放的状态机。可通过state属性获取当前状态。

**系统能力：** SystemCapability.Multimedia.Media.AudioPlayer

| 名称    | 类型   | 说明                                           |
| ------- | ------ | ---------------------------------------------- |
| idle    | string | 音频播放空闲，dataload/reset成功后处于此状态。 |
| playing | string | 音频正在播放，play成功后处于此状态。           |
| paused  | string | 音频暂停播放，pause成功后处于此状态。          |
| stopped | string | 音频播放停止，stop/播放结束后处于此状态。      |
| error   | string | 错误状态。                                     |

## AVFileDescriptor<sup>9+</sup>

音视频文件资源描述，一种特殊资源的播放方式，使用场景：应用中的音频资源被连续存储在同一个文件中，需要根据偏移量和长度进行播放。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| fd     | number | 是   | 资源句柄，通过resourceManager.getRawFileDescriptor获取       |
| offset | number | 是   | 资源偏移量，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误 |
| length | number | 是   | 资源长度，需要基于预置资源的信息输入，非法值会造成音视频资源解析错误 |

## VideoPlayer<sup>8+</sup>

视频播放管理类，用于管理和播放视频媒体。在调用VideoPlayer的方法前，需要先通过[createVideoPlayer()](#mediacreatevideoplayer8)构建一个[VideoPlayer](#videoplayer8)实例。

视频播放demo可参考：[视频播放开发指导](../../media/video-playback.md)

### 属性<a name=videoplayer_属性></a>

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                     | 类型                               | 可读 | 可写 | 说明                                                         |
| ------------------------ | ---------------------------------- | ---- | ---- | ------------------------------------------------------------ |
| url<sup>8+</sup>         | string                             | 是   | 是   | 视频媒体URL，支持当前主流的视频格式(mp4、mpeg-ts、webm、mkv)。<br>**支持路径示例**：<br>1. fd类型播放：fd://xx<br>![](figures/zh-cn_image_url.png)<br>2. http网络播放: http://xx<br/>3. https网络播放: https://xx<br/>4. hls网络播放路径：http://xx或者https://xx<br/> |
| fdSrc<sup>9+</sup> | [AVFileDescriptor](#avfiledescriptor9) | 是 | 是 | 视频媒体文件描述，使用场景：应用中的视频资源被连续存储在同一个文件中。<br/>**使用示例**：<br/>假设一个连续存储的音乐文件: <br/>视频1(地址偏移:0，字节长度:100)<br/>视频2(地址偏移:101，字节长度:50)<br/>视频3(地址偏移:151，字节长度:150)<br/>1. 播放视频1：AVFileDescriptor { fd = 资源句柄; offset = 0; length = 100; }<br/>2. 播放视频2：AVFileDescriptor { fd = 资源句柄; offset = 101; length = 50; }<br/>3. 播放视频3：AVFileDescriptor { fd = 资源句柄; offset = 151; length = 150; }<br/>假设是一个独立的视频文件: 请使用src=fd://xx <br/> |
| loop<sup>8+</sup>        | boolean                            | 是   | 是   | 视频循环播放属性，设置为'true'表示循环播放。                 |
| videoScaleType<sup>9+</sup>        | [VideoScaleType](#videoscaletype9)                   | 是   | 是   | 视频缩放模式。       |
| audioInterruptMode<sup>9+</sup>        | [audio.InterruptMode](js-apis-audio.md#interruptmode9)  | 是   | 是   | 音频焦点模型。       |
| currentTime<sup>8+</sup> | number                             | 是   | 否   | 视频的当前播放位置，单位为毫秒（ms）。                       |
| duration<sup>8+</sup>    | number                             | 是   | 否   | 视频时长，单位为毫秒（ms），返回-1表示直播模式。             |
| state<sup>8+</sup>       | [VideoPlayState](#videoplaystate8) | 是   | 否   | 视频播放的状态。                                             |
| width<sup>8+</sup>       | number                             | 是   | 否   | 视频宽，单位为像素（px）。                                   |
| height<sup>8+</sup>      | number                             | 是   | 否   | 视频高，单位为像素（px）。                                   |

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string, callback: AsyncCallback\<void>): void

通过回调方式设置SurfaceId。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型                 | 必填 | 说明                      |
| --------- | -------------------- | ---- | ------------------------- |
| surfaceId | string               | 是   | SurfaceId                 |
| callback  | AsyncCallback\<void> | 是   | 设置SurfaceId的回调方法。 |

**示例：**

```js
let surfaceId = null;
videoPlayer.setDisplaySurface(surfaceId, (err) => {
    if (err == null) {
        console.info('setDisplaySurface success!');
    } else {
        console.info('setDisplaySurface fail!');
    }
});
```

### setDisplaySurface<sup>8+</sup>

setDisplaySurface(surfaceId: string): Promise\<void>

通过Promise方式设置SurfaceId。

*注意：SetDisplaySurface需要在设置url和Prepare之间，无音频的视频流必须设置Surface否则Prepare失败。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名    | 类型   | 必填 | 说明      |
| --------- | ------ | ---- | --------- |
| surfaceId | string | 是   | SurfaceId |

**返回值：**

| 类型           | 说明                           |
| -------------- | ------------------------------ |
| Promise\<void> | 设置SurfaceId的Promise返回值。 |

**示例：**

```js
let surfaceId = null;
videoPlayer.setDisplaySurface(surfaceId).then(() => {
    console.info('setDisplaySurface success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### prepare<sup>8+</sup>

prepare(callback: AsyncCallback\<void>): void

通过回调方式准备播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 准备播放视频的回调方法。 |

**示例：**

```js
videoPlayer.prepare((err) => {
    if (err == null) {
        console.info('prepare success!');
    } else {
        console.info('prepare fail!');
    }
});
```

### prepare<sup>8+</sup>

prepare(): Promise\<void>

通过Promise方式准备播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 准备播放视频的Promise返回值。 |

**示例：**

```js
videoPlayer.prepare().then(() => {
    console.info('prepare success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### play<sup>8+</sup>

play(callback: AsyncCallback\<void>): void;

通过回调方式开始播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 开始播放视频的回调方法。 |

**示例：**

```js
videoPlayer.play((err) => {
    if (err == null) {
        console.info('play success!');
    } else {
        console.info('play fail!');
    }
});
```

### play<sup>8+</sup>

play(): Promise\<void>;

通过Promise方式开始播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 开始播放视频的Promise返回值。 |

**示例：**

```js
videoPlayer.play().then(() => {
    console.info('play success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### pause<sup>8+</sup>

pause(callback: AsyncCallback\<void>): void

通过回调方式暂停播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 暂停播放视频的回调方法。 |

**示例：**

```js
videoPlayer.pause((err) => {
    if (err == null) {
        console.info('pause success!');
    } else {
        console.info('pause fail!');
    }
});
```

### pause<sup>8+</sup>

pause(): Promise\<void>

通过Promise方式暂停播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 暂停播放视频的Promise返回值。 |

**示例：**

```js
videoPlayer.pause().then(() => {
    console.info('pause success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### stop<sup>8+</sup>

stop(callback: AsyncCallback\<void>): void

通过回调方式停止播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 停止播放视频的回调方法。 |

**示例：**

```js
videoPlayer.stop((err) => {
    if (err == null) {
        console.info('stop success!');
    } else {
        console.info('stop fail!');
    }
});
```

### stop<sup>8+</sup>

stop(): Promise\<void>

通过Promise方式停止播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 停止播放视频的Promise返回值。 |

**示例：**

```js
videoPlayer.stop().then(() => {
    console.info('stop success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### reset<sup>8+</sup>

reset(callback: AsyncCallback\<void>): void

通过回调方式重置播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 切换播放视频的回调方法。 |

**示例：**

```js
videoPlayer.reset((err) => {
    if (err == null) {
        console.info('reset success!');
    } else {
        console.info('reset fail!');
    }
});
```

### reset<sup>8+</sup>

reset(): Promise\<void>

通过Promise方式重置播放视频。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 切换播放视频的Promise返回值。 |

**示例：**

```js
videoPlayer.reset().then(() => {
    console.info('reset success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### seek<sup>8+</sup>

seek(timeMs: number, callback: AsyncCallback\<number>): void

通过回调方式跳转到指定播放位置，默认跳转到指定时间点的下一个关键帧。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| callback | AsyncCallback\<number> | 是   | 跳转到指定播放位置的回调方法。                               |

**示例：**

```js
let seekTime = 5000;
videoPlayer.seek(seekTime, (err, result) => {
    if (err == null) {
        console.info('seek success!');
    } else {
        console.info('seek fail!');
    }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode:SeekMode, callback: AsyncCallback\<number>): void

通过回调方式跳转到指定播放位置。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs   | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode     | [SeekMode](#seekmode8) | 是   | 跳转模式。                                                   |
| callback | AsyncCallback\<number> | 是   | 跳转到指定播放位置的回调方法。                               |

**示例：**

```js
import media from '@ohos.multimedia.media'
let seekTime = 5000;
videoPlayer.seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC, (err, result) => {
    if (err == null) {
        console.info('seek success!');
    } else {
        console.info('seek fail!');
    }
});
```

### seek<sup>8+</sup>

seek(timeMs: number, mode?:SeekMode): Promise\<number>

通过Promise方式跳转到指定播放位置，如果没有设置mode则跳转到指定时间点的下一个关键帧。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型                   | 必填 | 说明                                                         |
| ------ | ---------------------- | ---- | ------------------------------------------------------------ |
| timeMs | number                 | 是   | 指定的跳转时间节点，单位毫秒（ms），取值范围为[0, duration]。 |
| mode   | [SeekMode](#seekmode8) | 否   | 跳转模式。                                                   |

**返回值：**

| 类型           | 说明                                        |
| -------------- | ------------------------------------------- |
| Promise\<number> | 跳转到指定播放位置的Promise返回值，单位ms。 |

**示例：**

```js
import media from '@ohos.multimedia.media'
let seekTime = 5000;
videoPlayer.seek(seekTime).then((seekDoneTime) => { // seekDoneTime表示seek完成后的时间点
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});

videoPlayer.seek(seekTime, media.SeekMode.SEEK_NEXT_SYNC).then((seekDoneTime) => {
    console.info('seek success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number, callback: AsyncCallback\<void>): void

通过回调方式设置音量。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| vol      | number               | 是   | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |
| callback | AsyncCallback\<void> | 是   | 设置音量的回调方法。                                         |

**示例：**

```js
let vol = 0.5;
videoPlayer.setVolume(vol, (err, result) => {
    if (err == null) {
        console.info('setVolume success!');
    } else {
        console.info('setVolume fail!');
    }
});
```

### setVolume<sup>8+</sup>

setVolume(vol: number): Promise\<void>

通过Promise方式设置音量。

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

```js
let vol = 0.5;
videoPlayer.setVolume(vol).then(() => {
    console.info('setVolume success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### release<sup>8+</sup>

release(callback: AsyncCallback\<void>): void

通过回调方式释放视频资源。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                 | 必填 | 说明                     |
| -------- | -------------------- | ---- | ------------------------ |
| callback | AsyncCallback\<void> | 是   | 释放视频资源的回调方法。 |

**示例：**

```js
videoPlayer.release((err) => {
    if (err == null) {
        console.info('release success!');
    } else {
        console.info('release fail!');
    }
});
```

### release<sup>8+</sup>

release(): Promise\<void>

通过Promise方式释放视频资源。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型           | 说明                          |
| -------------- | ----------------------------- |
| Promise\<void> | 释放视频资源的Promise返回值。 |

**示例：**

```js
videoPlayer.release().then(() => {
    console.info('release success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(callback: AsyncCallback<Array\<MediaDescription>>): void

通过回调方式获取视频轨道信息。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                       |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------ |
| callback | AsyncCallback<Array<[MediaDescription](#mediadescription8)>> | 是   | 视频轨道信息MediaDescription数组回调方法。 |

**示例：**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('video key is ' + item);
        console.info('video value is ' + property);
    }
}

videoPlayer.getTrackDescription((error, arrList) => {
    if ((arrList) != null) {
        for (let i = 0; i < arrList.length; i++) {
            printfDescription(arrList[i]);
        }
    } else {
        console.log(`video getTrackDescription fail, error:${error}`);
    }
});
```

### getTrackDescription<sup>8+</sup>

getTrackDescription(): Promise<Array\<MediaDescription>>

通过Promise方式获取视频轨道信息。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**返回值：**

| 类型                                                   | 说明                                            |
| ------------------------------------------------------ | ----------------------------------------------- |
| Promise<Array<[MediaDescription](#mediadescription8)>> | 视频轨道信息MediaDescription数组Promise返回值。 |

**示例：**

```js
function printfDescription(obj) {
    for (let item in obj) {
        let property = obj[item];
        console.info('video key is ' + item);
        console.info('video value is ' + property);
    }
}

let arrayDescription;
videoPlayer.getTrackDescription().then((arrList) => {
    if (arrList != null) {
        arrayDescription = arrList;
    } else {
        console.log('video getTrackDescription fail');
    }
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
for (let i = 0; i < arrayDescription.length; i++) {
    printfDescription(arrayDescription[i]);
}
```

### setSpeed<sup>8+</sup>

setSpeed(speed:number, callback: AsyncCallback\<number>): void

通过回调方式设置播放速度。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                       |
| -------- | ---------------------- | ---- | ---------------------------------------------------------- |
| speed    | number                 | 是   | 指定播放视频速度，具体见[PlaybackSpeed](#playbackspeed8)。 |
| callback | AsyncCallback\<number> | 是   | 设置播放速度的回调方法。                                   |

**示例：**

```js
import media from '@ohos.multimedia.media'
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;

videoPlayer.setSpeed(speed, (err, result) => {
    if (err == null) {
        console.info('setSpeed success!');
    } else {
        console.info('setSpeed fail!');
    }
});
```

### setSpeed<sup>8+</sup>

setSpeed(speed:number): Promise\<number>

通过Promise方式设置播放速度。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                       |
| ------ | ------ | ---- | ---------------------------------------------------------- |
| speed  | number | 是   | 指定播放视频速度，具体见[PlaybackSpeed](#playbackspeed8)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | 播放速度Promise返回值，具体见[PlaybackSpeed](#playbackspeed8)。 |

**示例：**

```js
import media from '@ohos.multimedia.media'
let speed = media.PlaybackSpeed.SPEED_FORWARD_2_00_X;

videoPlayer.setSpeed(speed).then(() => {
    console.info('setSpeed success');
}).catch((error) => {
   console.info(`video catchCallback, error:${error}`);
});
```

### on('playbackCompleted')<sup>8+</sup>

on(type: 'playbackCompleted', callback: Callback\<void>): void

开始监听视频播放完成事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                        |
| -------- | -------- | ---- | ----------------------------------------------------------- |
| type     | string   | 是   | 视频播放完成事件回调类型，支持的事件：'playbackCompleted'。 |
| callback | function | 是   | 视频播放完成事件回调方法。                                  |

**示例：**

```js
videoPlayer.on('playbackCompleted', () => {
    console.info('playbackCompleted success!');
});
```

### on('bufferingUpdate')<sup>8+</sup>

on(type: 'bufferingUpdate', callback: (infoType: BufferingInfoType, value: number) => void): void

开始监听视频缓存更新事件。仅网络播放支持该订阅事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频缓存事件回调类型，支持的事件：'bufferingUpdate'。        |
| callback | function | 是   | 视频缓存事件回调方法。<br>[BufferingInfoType](#bufferinginfotype8)为BUFFERING_PERCENT或CACHED_DURATION时，value值有效，否则固定为0。 |

**示例：**

```js
videoPlayer.on('bufferingUpdate', (infoType, value) => {
    console.log('video bufferingInfo type: ' + infoType);
    console.log('video bufferingInfo value: ' + value);
});
```

### on('startRenderFrame')<sup>8+</sup>

on(type: 'startRenderFrame', callback: Callback\<void>): void

开始监听视频播放首帧送显上报事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型            | 必填 | 说明                                                         |
| -------- | --------------- | ---- | ------------------------------------------------------------ |
| type     | string          | 是   | 视频播放首帧送显上报事件回调类型，支持的事件：'startRenderFrame'。 |
| callback | Callback\<void> | 是   | 视频播放首帧送显上报事件回调方法。                           |

**示例：**

```js
videoPlayer.on('startRenderFrame', () => {
    console.info('startRenderFrame success!');
});
```

### on('videoSizeChanged')<sup>8+</sup>

on(type: 'videoSizeChanged', callback: (width: number, height: number) => void): void

开始监听视频播放宽高变化事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放宽高变化事件回调类型，支持的事件：'videoSizeChanged'。 |
| callback | function | 是   | 视频播放宽高变化事件回调方法，width表示宽，height表示高。    |

**示例：**

```js
videoPlayer.on('videoSizeChanged', (width, height) => {
    console.log('video width is: ' + width);
    console.log('video height is: ' + height);
});
```

### on('error')<sup>8+</sup>

on(type: 'error', callback: ErrorCallback): void

开始监听视频播放错误事件，当上报error错误事件后，用户需处理error事件，退出播放操作。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 播放错误事件回调类型，支持的事件包括：'error'。<br>- 'error'：视频播放中发生错误，触发该事件。 |
| callback | ErrorCallback | 是   | 播放错误事件回调方法。                                       |

**示例：**

```js
videoPlayer.on('error', (error) => {      // 设置'error'事件回调
    console.info(`video error called, error: ${error}`);
});
videoPlayer.url = 'fd://error';  //设置错误的播放地址，触发'error'事件
```

### on('availableBitratesCollect')<sup>9+</sup>

on(type: 'availableBitratesCollect', callback: (bitrates: Array\<number>) => void): void

开始监听视频播放码率上报事件。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 视频播放码率上报事件回调类型，支持的事件：'availableBitratesCollect'，只在开始播放时候上报一次 |
| callback | function | 是   | 视频播放码率事件回调方法，使用数组存放支持的码率。           |

**示例：**

```js
videoPlayer.on('availableBitratesCollect', (bitrates) => {
    for (let i = 0; i < bitrates.length; i++) {
        console.info('case availableBitratesCollect bitrates: '  + bitrates[i]);  //打印支持的码率
    }
});
```

## VideoPlayState<sup>8+</sup>

视频播放的状态机，可通过state属性获取当前状态。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称     | 类型   | 说明           |
| -------- | ------ | -------------- |
| idle     | string | 视频播放空闲。 |
| prepared | string | 视频播放准备。 |
| playing  | string | 视频正在播放。 |
| paused   | string | 视频暂停播放。 |
| stopped  | string | 视频播放停止。 |
| error    | string | 错误状态。     |

## SeekMode<sup>8+</sup>

视频播放的Seek模式枚举，可通过seek方法作为参数传递下去。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称           | 值   | 说明                                                         |
| -------------- | ---- | ------------------------------------------------------------ |
| SEEK_NEXT_SYNC | 0    | 表示跳转到指定时间点的下一个关键帧，建议向后快进的时候用这个枚举值。 |
| SEEK_PREV_SYNC | 1    | 表示跳转到指定时间点的上一个关键帧，建议向前快进的时候用这个枚举值。 |

## PlaybackSpeed<sup>8+</sup>

视频播放的倍速枚举，可通过setSpeed方法作为参数传递下去。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                 | 值   | 说明                           |
| -------------------- | ---- | ------------------------------ |
| SPEED_FORWARD_0_75_X | 0    | 表示视频播放正常播速的0.75倍。 |
| SPEED_FORWARD_1_00_X | 1    | 表示视频播放正常播速。         |
| SPEED_FORWARD_1_25_X | 2    | 表示视频播放正常播速的1.25倍。 |
| SPEED_FORWARD_1_75_X | 3    | 表示视频播放正常播速的1.75倍。 |
| SPEED_FORWARD_2_00_X | 4    | 表示视频播放正常播速的2.00倍。 |

## VideoScaleType<sup>9+</sup>

枚举，视频缩放模式。

**系统能力：** SystemCapability.Multimedia.Media.VideoPlayer

| 名称                         | 值 | 说明     |
| ---------------------------- | ------ | ---------- |
| VIDEO_SCALE_TYPE_FIT     | 0      | 视频拉伸至与窗口等大。 |
| VIDEO_SCALE_TYPE_FIT_CROP| 1      | 保持视频宽高比拉伸至填满窗口，内容可能会有裁剪。     |

## MediaDescription<sup>8+</sup>

通过key-value方式获取媒体信息。

**系统能力：** SystemCapability.Multimedia.Media.Core

**示例：**

```js
import media from '@ohos.multimedia.media'
function printfItemDescription(obj, key) {
    let property = obj[key];
    console.info('audio key is ' + key); // 通过key值获取对应的value。key值具体可见[MediaDescriptionKey]
    console.info('audio value is ' + property); //对应key值得value。其类型可为任意类型，具体key对应value的类型可参考[MediaDescriptionKey]
}
let audioPlayer = media.createAudioPlayer();
audioPlayer.getTrackDescription((error, arrList) => {
    if (arrList != null) {
        for (let i = 0; i < arrList.length; i++) {
            printfItemDescription(arrList[i], media.MediaDescriptionKey.MD_KEY_TRACK_TYPE);  //打印出每条轨道MD_KEY_TRACK_TYPE的值
        }
    } else {
        console.log(`audio getTrackDescription fail, error:${error}`);
    }
});
```

## AudioRecorder

音频录制管理类，用于录制音频媒体。在调用AudioRecorder的方法前，需要先通过[createAudioRecorder()](#mediacreateaudiorecorder) 构建一个[AudioRecorder](#audiorecorder)实例。

音频录制demo可参考：[音频录制开发指导](../../media/audio-recorder.md)

### prepare<a name=audiorecorder_prepare></a>

prepare(config: AudioRecorderConfig): void

录音准备。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名 | 类型                                        | 必填 | 说明                                                         |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfig) | 是   | 配置录音的相关参数，包括音频输出URI、编码格式、采样率、声道数、输出格式等。 |

**示例：**

```js
let audioRecorderConfig = {
    audioEncoder : media.AudioEncoder.AAC_LC,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : media.AudioOutputFormat.AAC_ADTS,
    uri : 'fd://1',       // 文件需先由调用者创建，并给予适当的权限
    location : { latitude : 30, longitude : 130},
}
audioRecorder.on('prepare', () => {    //设置'prepare'事件回调
    console.log('prepare success');
});
audioRecorder.prepare(audioRecorderConfig);
```


### start<a name=audiorecorder_start></a>

start(): void

开始录制，需在[prepare](#audiorecorder_on)事件成功触发后，才能调用start方法。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('start', () => {    //设置'start'事件回调
    console.log('audio recorder start success');
});
audioRecorder.start();
```

### pause<a name=audiorecorder_pause></a>

pause():void

暂停录制，需要在[start](#audiorecorder_on)事件成功触发后，才能调用pause方法。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('pause', () => {    //设置'pause'事件回调
    console.log('audio recorder pause success');
});
audioRecorder.pause();
```

### resume<a name=audiorecorder_resume></a>

resume():void

恢复录制，需要在[pause](#audiorecorder_on)事件成功触发后，才能调用resume方法。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('resume', () => {    //设置'resume'事件回调
    console.log('audio recorder resume success');
});
audioRecorder.resume();
```

### stop<a name=audiorecorder_stop></a>

stop(): void

停止录音。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('stop', () => {    //设置'stop'事件回调
    console.log('audio recorder stop success');
});
audioRecorder.stop();
```

### release<a name=audiorecorder_release></a>

release(): void

释放录音资源。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('release', () => {    //设置'release'事件回调
    console.log('audio recorder release success');
});
audioRecorder.release();
audioRecorder = undefined;
```

### reset<a name=audiorecorder_reset></a>

reset(): void

重置录音。

进行重置录音之前，需要先调用[stop()](#audiorecorder_stop)停止录音。重置录音之后，需要调用[prepare()](#audiorecorder_prepare)设置录音参数项，才能再次进行录音。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**示例：**

```js
audioRecorder.on('reset', () => {    //设置'reset'事件回调
    console.log('audio recorder reset success');
});
audioRecorder.reset();
```

### on('prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset')<a name=audiorecorder_on></a>

on(type: 'prepare' | 'start' | 'pause' | 'resume' | 'stop' | 'release' | 'reset', callback: () => void): void

开始订阅音频录制事件。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 录制事件回调类型，支持的事件包括：'prepare'&nbsp;\|&nbsp;'start'&nbsp;\|  'pause' \| ’resume‘ \|&nbsp;'stop'&nbsp;\|&nbsp;'release'&nbsp;\|&nbsp;'reset'。<br/>-&nbsp;'prepare'&nbsp;：完成[prepare](#audiorecorder_prepare)调用，音频录制参数设置完成，触发该事件。<br/>-&nbsp;'start'&nbsp;：完成[start](#audiorecorder_start)调用，音频录制开始，触发该事件。<br/>-&nbsp;'pause': 完成[pause](#audiorecorder_pause)调用，音频暂停录制，触发该事件。<br/>-&nbsp;'resume': 完成[resume](#audiorecorder_resume)调用，音频恢复录制，触发该事件。<br/>-&nbsp;'stop'&nbsp;：完成[stop](#audiorecorder_stop)调用，音频停止录制，触发该事件。<br/>-&nbsp;'release'&nbsp;：完成[release](#audiorecorder_release)调用，音频释放录制资源，触发该事件。<br/>-&nbsp;'reset'：完成[reset](#audiorecorder_reset)调用，音频重置为初始状态，触发该事件。 |
| callback | ()=>void | 是   | 录制事件回调方法。                                           |

**示例：**

```js
let audioRecorder = media.createAudioRecorder();                                  // 创建一个音频录制实例
let audioRecorderConfig = {
    audioEncoder : media.AudioEncoder.AAC_LC,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : media.AudioOutputFormat.AAC_ADTS,
    uri : 'fd://xx',                                                            // 文件需先由调用者创建，并给予适当的权限
    location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {                                             // 设置'error'事件回调
    console.info(`audio error called, error: ${error}`);
});
audioRecorder.on('prepare', () => {                                              // 设置'prepare'事件回调
    console.log('prepare success');
    audioRecorder.start();                                                       // 开始录制，并触发'start'事件回调
});
audioRecorder.on('start', () => {                                                 // 设置'start'事件回调
    console.log('audio recorder start success');
});
audioRecorder.on('pause', () => {                                                 // 设置'pause'事件回调
    console.log('audio recorder pause success');
});
audioRecorder.on('resume', () => {                                                 // 设置'resume'事件回调
    console.log('audio recorder resume success');
});
audioRecorder.on('stop', () => {                                                 // 设置'stop'事件回调
    console.log('audio recorder stop success');
});
audioRecorder.on('release', () => {                                                 // 设置'release'事件回调
    console.log('audio recorder release success');
});
audioRecorder.on('reset', () => {                                                 // 设置'reset'事件回调
    console.log('audio recorder reset success');
});
audioRecorder.prepare(audioRecorderConfig)                                       // 设置录制参数 ，并触发'prepare'事件回调
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

开始订阅音频录制错误事件，当上报error错误事件后，用户需处理error事件，退出录制操作。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。<br/>-&nbsp;'error'：音频录制过程中发生错误，触发该事件。 |
| callback | ErrorCallback | 是   | 录制错误事件回调方法。                                       |

**示例：**

```js
let audioRecorderConfig = {
    audioEncoder : media.AudioEncoder.AAC_LC,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : media.AudioOutputFormat.AAC_ADTS,
    uri : 'fd://xx',                                                     // 文件需先由调用者创建，并给予适当的权限
    location : { latitude : 30, longitude : 130},
}
audioRecorder.on('error', (error) => {                                  // 设置'error'事件回调
    console.info(`audio error called, error: ${error}`); 
});
audioRecorder.prepare(audioRecorderConfig);                            // prepare不设置参数，触发'error'事件
```

## AudioRecorderConfig

表示音频的录音配置。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称                  | 类型                                | 必填 | 说明                                                         |
| --------------------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder<sup>(deprecated)</sup>          | [AudioEncoder](#audioencoder)           | 否   | 音频编码格式，默认设置为AAC_LC。<br/>**说明：** 从API Version 8 开始废弃，建议使用audioEncoderMime替代。                             |
| audioEncodeBitRate    | number                                  | 否   | 音频编码比特率，默认值为48000。                              |
| audioSampleRate       | number                                  | 否   | 音频采集采样率，默认值为48000。                              |
| numberOfChannels      | number                                  | 否   | 音频采集声道数，默认值为2。                                  |
| format<sup>(deprecated)</sup>                | [AudioOutputFormat](#audiooutputformat) | 否   | 音频输出封装格式，默认设置为MPEG_4。<br/>**说明：** 从API Version 8 开始废弃，建议使用fileFormat替代。                         |
| location              | [Location](#location)                   | 否   | 音频采集的地理位置。                                         |
| uri                   | string                                  | 是   | 音频输出URI：fd://xx&nbsp;(fd&nbsp;number)<br/>![](figures/zh-cn_image_url.png) <br/>文件需要由调用者创建，并赋予适当的权限。 |
| audioEncoderMime<sup>8+</sup>      | [CodecMimeType](#codecmimetype8)        | 否   | 音频编码格式。           |
| fileFormat<sup>8+</sup>      | [ContainerFormatType](#containerformattype8)        | 否   | 音频编码格式。         |

## AudioEncoder<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[CodecMimeType](#codecmimetype8)替代。

表示音频编码格式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称    | 值   | 说明                                                         |
| ------- | ---- | ------------------------------------------------------------ |
| DEFAULT | 0    | 默认编码格式。<br/>仅做接口定义，暂不支持使用。              |
| AMR_NB  | 1    | AMR-NB(Adaptive Multi Rate-Narrow Band Speech Codec) 编码格式。<br/>仅做接口定义，暂不支持使用。 |
| AMR_WB  | 2    | AMR-WB(Adaptive Multi Rate-Wide Band Speech Codec) 编码格式。<br/>仅做接口定义，暂不支持使用。 |
| AAC_LC  | 3    | AAC-LC（Advanced&nbsp;Audio&nbsp;Coding&nbsp;Low&nbsp;Complexity）编码格式。 |
| HE_AAC  | 4    | HE_AAC（High-Efficiency Advanced&nbsp;Audio&nbsp;Coding）编码格式。<br/>仅做接口定义，暂不支持使用。 |


## AudioOutputFormat<sup>(deprecated)</sup>

> **说明：**
> 从 API Version 8 开始废弃，建议使用[ContainerFormatType](#containerformattype8)替代。

表示音频封装格式的枚举。

**系统能力：** SystemCapability.Multimedia.Media.AudioRecorder

| 名称     | 值   | 说明                                                         |
| -------- | ---- | ------------------------------------------------------------ |
| DEFAULT  | 0    | 默认封装格式。<br/>仅做接口定义，暂不支持使用。              |
| MPEG_4   | 2    | 封装为MPEG-4格式。                                           |
| AMR_NB   | 3    | 封装为AMR_NB格式。<br/>仅做接口定义，暂不支持使用。          |
| AMR_WB   | 4    | 封装为AMR_WB格式。<br/>仅做接口定义，暂不支持使用。          |
| AAC_ADTS | 6    | 封装为ADTS（Audio&nbsp;Data&nbsp;Transport&nbsp;Stream）格式，是AAC音频的传输流格式。 |

## VideoRecorder<sup>9+</sup>

视频录制管理类，用于录制视频媒体。在调用VideoRecorder的方法前，需要先通过[createVideoRecorder()](#mediacreatevideorecorder9)构建一个[VideoRecorder](#videorecorder9)实例。

视频录制demo可参考：[视频录制开发指导](../../media/video-recorder.md)

### 属性

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称               | 类型                                   | 可读 | 可写 | 说明             |
| ------------------ | -------------------------------------- | ---- | ---- | ---------------- |
| state<sup>9+</sup> | [VideoRecordState](#videorecordstate9) | 是   | 否   | 视频录制的状态。 |

### prepare<sup>9+</sup><a name=videorecorder_prepare1></a>

prepare(config: VideoRecorderConfig, callback: AsyncCallback\<void>): void;

异步方式进行视频录制的参数设置。通过注册回调函数获取返回值。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                |
| -------- | -------------------------------------------- | ---- | ----------------------------------- |
| config   | [VideoRecorderConfig](#videorecorderconfig9) | 是   | 配置视频录制的相关参数。            |
| callback | AsyncCallback\<void>                         | 是   | 异步视频录制prepare方法的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 201      | Permission denied. Return by callback.  |
| 401      | Parameter error. Return by callback.    |
| 5400102  | Operate not permit. Return by callback. |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
    videoFrameWidth : 640,
    videoFrameHeight : 480,
    videoFrameRate : 30
}

let videoConfig = {
    audioSourceType : 1,
    videoSourceType : 0,
    profile : videoProfile,
    url : 'fd://xx',   // 文件需先由调用者创建，并给予适当的权限
    orientationHint : 0,
    location : { latitude : 30, longitude : 130 },
}

// asyncallback
videoRecorder.prepare(videoConfig, (err) => {
    if (err == null) {
        console.info('prepare success');
    } else {
        console.info('prepare failed and error is ' + err.message);
    }
})
```

### prepare<sup>9+</sup><a name=videorecorder_prepare2></a>

prepare(config: VideoRecorderConfig): Promise\<void>;

异步方式进行视频录制的参数设置。通过Promise获取返回值。

**需要权限：** ohos.permission.MICROPHONE

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名 | 类型                                         | 必填 | 说明                     |
| ------ | -------------------------------------------- | ---- | ------------------------ |
| config | [VideoRecorderConfig](#videorecorderconfig9) | 是   | 配置视频录制的相关参数。 |

**返回值：**

| 类型           | 说明                                     |
| -------------- | ---------------------------------------- |
| Promise\<void> | 异步视频录制prepare方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 201      | Permission denied. Return by promise.  |
| 401      | Parameter error. Return by promise.    |
| 5400102  | Operate not permit. Return by promise. |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
let videoProfile = {
    audioBitrate : 48000,
    audioChannels : 2,
    audioCodec : 'audio/mp4a-latm',
    audioSampleRate : 48000,
    fileFormat : 'mp4',
    videoBitrate : 48000,
    videoCodec : 'video/mp4v-es',
    videoFrameWidth : 640,
    videoFrameHeight : 480,
    videoFrameRate : 30
}

let videoConfig = {
    audioSourceType : 1,
    videoSourceType : 0,
    profile : videoProfile,
    url : 'fd://xx',   // 文件需先由调用者创建，并给予适当的权限
    orientationHint : 0,
    location : { latitude : 30, longitude : 130 },
}

// promise
videoRecorder.prepare(videoConfig).then(() => {
    console.info('prepare success');
}).catch((err) => {
    console.info('prepare failed and catch error is ' + err.message);
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(callback: AsyncCallback\<string>): void;

异步方式获得录制需要的surface。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的数据。

应当注意，填入的视频数据需要携带时间戳（单位ns），buffersize。时间戳的起始时间请以系统启动时间为基准。

只能在[prepare()](#videorecorder_prepare1)接口调用后调用。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                   | 必填 | 说明                        |
| -------- | ---------------------- | ---- | --------------------------- |
| callback | AsyncCallback\<string> | 是   | 异步获得surface的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
// asyncallback
let surfaceID = null;                                               // 传递给外界的surfaceID
videoRecorder.getInputSurface((err, surfaceId) => {
    if (err == null) {
        console.info('getInputSurface success');
        surfaceID = surfaceId;
    } else {
        console.info('getInputSurface failed and error is ' + err.message);
    }
});
```

### getInputSurface<sup>9+</sup>

getInputSurface(): Promise\<string>;

 异步方式获得录制需要的surface。此surface提供给调用者，调用者从此surface中获取surfaceBuffer，填入相应的数据。

应当注意，填入的视频数据需要携带时间戳（单位ns），buffersize。时间戳的起始时间请以系统启动时间为基准。

只能在[prepare()](#videorecorder_prepare1)接口调用后调用。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型             | 说明                             |
| ---------------- | -------------------------------- |
| Promise\<string> | 异步获得surface的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
// promise
let surfaceID = null;                                               // 传递给外界的surfaceID
videoRecorder.getInputSurface().then((surfaceId) => {
    console.info('getInputSurface success');
    surfaceID = surfaceId;
}).catch((err) => {
    console.info('getInputSurface failed and catch error is ' + err.message);
});
```

### start<sup>9+</sup><a name=videorecorder_start1></a>

start(callback: AsyncCallback\<void>): void;

异步方式开始视频录制。通过注册回调函数获取返回值。

在[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)后调用，需要依赖数据源先给surface传递数据。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步开始视频录制的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
// asyncallback
videoRecorder.start((err) => {
    if (err == null) {
        console.info('start videorecorder success');
    } else {
        console.info('start videorecorder failed and error is ' + err.message);
    }
});
```

### start<sup>9+</sup><a name=videorecorder_start2></a>

start(): Promise\<void>;

异步方式开始视频录制。通过Promise获取返回值。

在[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)后调用，需要依赖数据源先给surface传递数据。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步开始视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
// promise
videoRecorder.start().then(() => {
    console.info('start videorecorder success');
}).catch((err) => {
    console.info('start videorecorder failed and catch error is ' + err.message);
});
```

### pause<sup>9+</sup><a name=videorecorder_pause1></a>

pause(callback: AsyncCallback\<void>): void;

异步方式暂停视频录制。通过注册回调函数获取返回值。

在[start()](#videorecorder_start1)后调用。可以通过调用[resume()](#videorecorder_resume1)接口来恢复录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步暂停视频录制的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
// asyncallback
videoRecorder.pause((err) => {
    if (err == null) {
        console.info('pause videorecorder success');
    } else {
        console.info('pause videorecorder failed and error is ' + err.message);
    }
});
```

### pause<sup>9+</sup><a name=videorecorder_pause2></a>

pause(): Promise\<void>;

异步方式暂停视频录制。通过Promise获取返回值。

在[start()](#videorecorder_start1)后调用。可以通过调用[resume()](#videorecorder_resume1)接口来恢复录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步暂停视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
// promise
videoRecorder.pause().then(() => {
    console.info('pause videorecorder success');
}).catch((err) => {
    console.info('pause videorecorder failed and catch error is ' + err.message);
});
```

### resume<sup>9+</sup><a name=videorecorder_resume1></a>

resume(callback: AsyncCallback\<void>): void;

异步方式恢复视频录制。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步恢复视频录制的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
// asyncallback
videoRecorder.resume((err) => {
    if (err == null) {
        console.info('resume videorecorder success');
    } else {
        console.info('resume videorecorder failed and error is ' + err.message);
    }
});
```

### resume<sup>9+</sup><a name=videorecorder_resume2></a>

resume(): Promise\<void>;

异步方式恢复视频录制。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步恢复视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
// promise
videoRecorder.resume().then(() => {
    console.info('resume videorecorder success');
}).catch((err) => {
    console.info('resume videorecorder failed and catch error is ' + err.message);
});
```

### stop<sup>9+</sup><a name=videorecorder_stop1></a>

stop(callback: AsyncCallback\<void>): void;

异步方式停止视频录制。通过注册回调函数获取返回值。

需要重新调用[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步停止视频录制的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                                |
| -------- | --------------------------------------- |
| 5400102  | Operate not permit. Return by callback. |
| 5400103  | IO error. Return by callback.           |
| 5400105  | Service died. Return by callback.       |

**示例：**

```js
// asyncallback
videoRecorder.stop((err) => {
    if (err == null) {
        console.info('stop videorecorder success');
    } else {
        console.info('stop videorecorder failed and error is ' + err.message);
    }
});
```

### stop<sup>9+</sup><a name=videorecorder_stop2></a>

stop(): Promise\<void>;

异步方式停止视频录制。通过Promise获取返回值。

需要重新调用[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步停止视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                               |
| -------- | -------------------------------------- |
| 5400102  | Operate not permit. Return by promise. |
| 5400103  | IO error. Return by promise.           |
| 5400105  | Service died. Return by promise.       |

**示例：**

```js
// promise
videoRecorder.stop().then(() => {
    console.info('stop videorecorder success');
}).catch((err) => {
    console.info('stop videorecorder failed and catch error is ' + err.message);
});
```

### release<sup>9+</sup><a name=videorecorder_release1></a>

release(callback: AsyncCallback\<void>): void;

异步方式释放视频录制资源。通过注册回调函数获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                             |
| -------- | -------------------- | ---- | -------------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步释放视频录制资源的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```js
// asyncallback
videoRecorder.release((err) => {
    if (err == null) {
        console.info('release videorecorder success');
    } else {
        console.info('release videorecorder failed and error is ' + err.message);
    }
});
```

### release<sup>9+</sup><a name=videorecorder_release2></a>

release(): Promise\<void>;

异步方式释放视频录制资源。通过Promise获取返回值。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                      |
| -------------- | ----------------------------------------- |
| Promise\<void> | 异步释放视频录制资源方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400105  | Service died. Return by callback. |

**示例：**

```js
// promise
videoRecorder.release().then(() => {
    console.info('release videorecorder success');
}).catch((err) => {
    console.info('release videorecorder failed and catch error is ' + err.message);
});
```

### reset<sup>9+</sup><a name=videorecorder_reset1></a>

reset(callback: AsyncCallback\<void>): void;

异步方式重置视频录制。通过注册回调函数获取返回值。

需要重新调用[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<void> | 是   | 异步重置视频录制的回调方法。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```js
// asyncallback
videoRecorder.reset((err) => {
    if (err == null) {
        console.info('reset videorecorder success');
    } else {
        console.info('reset videorecorder failed and error is ' + err.message);
    }
});
```

### reset<sup>9+</sup><a name=videorecorder_reset2></a>

reset(): Promise\<void>;

异步方式重置视频录制。通过Promise获取返回值。

需要重新调用[prepare()](#videorecorder_prepare1)和[getInputSurface()](#getinputsurface9)接口才能重新录制。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

**返回值：**

| 类型           | 说明                                  |
| -------------- | ------------------------------------- |
| Promise\<void> | 异步重置视频录制方法的Promise返回值。 |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 5400103  | IO error. Return by promise.     |
| 5400105  | Service died. Return by promise. |

**示例：**

```js
// promise
videoRecorder.reset().then(() => {
    console.info('reset videorecorder success');
}).catch((err) => {
    console.info('reset videorecorder failed and catch error is ' + err.message);
});
```

### on('error')<sup>9+</sup>

on(type: 'error', callback: ErrorCallback): void

开始订阅视频录制错误事件，当上报error错误事件后，用户需处理error事件，退出录制操作。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。<br/>-&nbsp;'error'：视频录制过程中发生错误，触发该事件。 |
| callback | ErrorCallback | 是   | 录制错误事件回调方法。                                       |

**错误码：**

以下错误码的详细介绍请参见[媒体错误码](../errorcodes/errorcode-media.md)

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 5400103  | IO error. Return by callback.     |
| 5400105  | Service died. Return by callback. |

**示例：**

```js
// 当获取videoRecordState接口出错时通过此订阅事件上报
videoRecorder.on('error', (error) => {                                  // 设置'error'事件回调
    console.info(`audio error called, error: ${error}`); 
})
```

## VideoRecordState<sup>9+</sup>

视频录制的状态机。可通过state属性获取当前状态。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称     | 类型   | 说明                   |
| -------- | ------ | ---------------------- |
| idle     | string | 视频录制空闲。         |
| prepared | string | 视频录制参数设置完成。 |
| playing  | string | 视频正在录制。         |
| paused   | string | 视频暂停录制。         |
| stopped  | string | 视频录制停止。         |
| error    | string | 错误状态。             |

## VideoRecorderConfig<sup>9+</sup>

表示视频录制的参数设置。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称            | 类型                                           | 必填 | 说明                                                         |
| --------------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| audioSourceType | [AudioSourceType](#audiosourcetype9)           | 是   | 视频录制的音频源类型。                                       |
| videoSourceType | [VideoSourceType](#videosourcetype9)           | 是   | 视频录制的视频源类型。                                       |
| profile         | [VideoRecorderProfile](#videorecorderprofile9) | 是   | 视频录制的profile。                                          |
| rotation        | number                                         | 否   | 录制视频的旋转角度。                                         |
| location        | [Location](#location)                          | 否   | 录制视频的地理位置。                                         |
| url             | string                                         | 是   | 视频输出URL：fd://xx&nbsp;(fd&nbsp;number)<br/>![](figures/zh-cn_image_url.png) |

## AudioSourceType<sup>9+</sup>

表示视频录制中音频源类型的枚举。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称                      | 值   | 说明                   |
| ------------------------- | ---- | ---------------------- |
| AUDIO_SOURCE_TYPE_DEFAULT | 0    | 默认的音频输入源类型。 |
| AUDIO_SOURCE_TYPE_MIC     | 1    | 表示MIC的音频输入源。  |

## VideoSourceType<sup>9+</sup>

表示视频录制中视频源类型的枚举。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称                          | 值   | 说明                            |
| ----------------------------- | ---- | ------------------------------- |
| VIDEO_SOURCE_TYPE_SURFACE_YUV | 0    | 输入surface中携带的是raw data。 |
| VIDEO_SOURCE_TYPE_SURFACE_ES  | 1    | 输入surface中携带的是ES data。  |

## VideoRecorderProfile<sup>9+</sup>

视频录制的配置文件。

**系统能力：** SystemCapability.Multimedia.Media.VideoRecorder

**系统接口：** 该接口为系统接口

| 名称             | 类型                                         | 必填 | 说明             |
| ---------------- | -------------------------------------------- | ---- | ---------------- |
| audioBitrate     | number                                       | 是   | 音频编码比特率。 |
| audioChannels    | number                                       | 是   | 音频采集声道数。 |
| audioCodec       | [CodecMimeType](#codecmimetype8)             | 是   | 音频编码格式。   |
| audioSampleRate  | number                                       | 是   | 音频采样率。     |
| fileFormat       | [ContainerFormatType](#containerformattype8) | 是   | 文件的容器格式。 |
| videoBitrate     | number                                       | 是   | 视频编码比特率。 |
| videoCodec       | [CodecMimeType](#codecmimetype8)             | 是   | 视频编码格式。   |
| videoFrameWidth  | number                                       | 是   | 录制视频帧的宽。 |
| videoFrameHeight | number                                       | 是   | 录制视频帧的高。 |
| videoFrameRate   | number                                       | 是   | 录制视频帧率。   |

## ContainerFormatType<sup>8+</sup>

表示容器格式类型的枚举，缩写为CFT。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称        | 值    | 说明                  |
| ----------- | ----- | --------------------- |
| CFT_MPEG_4  | 'mp4' | 视频的容器格式，MP4。 |
| CFT_MPEG_4A | 'm4a' | 音频的容器格式，M4A。 |

## Location

视频录制的地理位置。

**系统能力：** SystemCapability.Multimedia.Media.Core

| 名称      | 类型   | 必填 | 说明             |
| --------- | ------ | ---- | ---------------- |
| latitude  | number | 是   | 地理位置的纬度。 |
| longitude | number | 是   | 地理位置的经度。 |