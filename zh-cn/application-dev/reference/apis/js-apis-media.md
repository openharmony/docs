# 音频播放和录制

## 导入模块

```
import media from '@ohos.multimedia.media';
```


## 权限

无


## media.createAudioPlayer

createAudioPlayer(): AudioPlayer

创建音频播放的实例。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [AudioPlayer](#audioplayer) | 返回AudioPlayer类实例，失败时返回null。 |

**示例：**

```
var audioplayer = media.createAudioPlayer(); 
```
## media.createAudioRecorder
createAudioRecorder(): AudioRecorder

创建音频录制的实例来控制音频的录制。

**返回值:**

| 类型                            | 说明                                      |
| ------------------------------- | ----------------------------------------- |
| [AudioRecorder](#audiorecorder) | 返回AudioRecorder类实例，失败时返回null。 |

**示例：**
```
var audiorecorder = media.createAudioRecorder(); 
```

## AudioPlayer

音频播放管理类，用于管理和播放音频媒体。在调用AudioPlayer的方法前，需要先通过[createAudioPlayer()](#createaudioplayer-)构建一个AudioPlayer实例。


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| src | string | 是 | 是 | 音频媒体URI，支持当前主流的音频格式(mp4、aac、mp3、ogg)，支持本地绝对路径（file://) |
| loop | boolean | 是 | 是 | 音频循环播放属性，设置为'true'表示循环播放。 |
| currentTime | number | 是 | 否 | 音频的当前播放阶段。 |
| duration | number | 是 | 否 | 音频时长。 |
| state | [AudioState](#audiostate) | 是 | 否 | 音频播放的状态。 |

### play

play(): void

开始播放音频资源。

**示例：**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('play', () => {
  console.log('Playback starts.');
});
audioplayer.play();
```

### pause

pause(): void

暂停播放音频资源。

**示例：**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('pause', () => {
  console.log('Playback paused.');
});
audioplayer.pause();
```

### stop

stop(): void

停止播放音频资源。

**示例：**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('stop',() => {
  console.log('Playback stopped.');
});
audioplayer.stop();
```

### seek

seek(timeMs: number): void

跳转到指定播放位置。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| timeMs | number | 是 | 指定的跳转时间节点。 |

**示例：**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('timeupdate', (action) => {
  var newTime = audioplayer.currenTime;
  if(newTime >= 30000) {
    console.info('Seek succeeded. New time: ' + newTime);
  } else {
    console.info('Seek failed.');
  }
});
audioplayer.seek(30000);
```

### setVolume

setVolume(vol: number): void

设置音量。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| vol | number | 是 | 指定的相对音量大小，取值范围为[0.00-1.00]，1表示最大音量，即100%。 |

**示例：**

```
audioplayer.src = 'file:///data/media/sounds.mp4';
audioplayer.on('volumeChange', () => {
  console.log('Playback volume changed.');
});
audioplayer.setVolume(1);
```

### reset<sup>7+</sup>

reset(): void

切换播放音频资源。

**示例：**

```
audioplay.reset();
```

### release<sup>7+</sup>

release(): void

释放音频资源。

**示例：**

```
audioplay.release();
```

### on('play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange')

on(type: 'play' | 'pause' | 'stop' | 'reset' | 'dataLoad' | 'finish' | 'volumeChange', callback: () => void)

开始监听音频播放事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 播放事件回调类型，支持的事件包括：'play' \| 'pause' \| 'stop' \| 'reset' \| 'dataLoad' \| 'finish' \| 'volumeChange'。<br>- 'play' ：完成play方法调用，音频开始播放，触发该事件。<br>- 'pause'：完成pause方法调用，音频暂停播放，触发该事件。<br>-  'stop'：完成stop方法调用，音频停止播放，触发该事件。<br>-  'reset'：完成reset方法调用，播放器重置，触发该事件。<br>-  'dataLoad'：完成音频数据加载后触发该事件。<br>-  'finish'：完成音频播放后触发该事件。<br>-  'volumeChange'：播放音量改变后触发该事件。播放事件回调方法。 |
| callback | function | 是 | 播放事件回调方法。 |

**示例：**

```
audioplayer.src = 'file://xxx/sounds.mp4';
audioplayer.on('play', () => {
  console.log('Playback starts.');
});
audioplayer.play();
```

### on('timeUpdate')

on(type: 'timeUpdate', callback: Callback\<number>): void

开始监听音频播放时间戳更新事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 播放事件回调类型，支持的事件为：'timeUpdate'。<br>'timeUpdate'：音频播放时间戳更新，触发该事件。seek方法调用时也会触发该事件。 |
| callback | Callback&lt;number&gt; | 是 | 播放事件回调方法。 |

**示例：**

```
audioplayer.src = 'file://xxx/sounds.mp4';
audioplayer.on('timeupdate', (newTime ) => {
  if(newTime >= 30000) {
    console.info('Seek succeeded. New time: ' + newTime);
  } else {
    console.info('Seek failed.');
  }
});
audioplayer.seek(30000);
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

开始监听音频播放错误事件。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 播放错误事件回调类型'error'。<br>'error'：音频播放中发生错误，触发该事件。 |
| callback | ErrorCallback | 是 | 播放错误事件回调方法。 |

**示例：**

```
audioplayer.src = 'file:///data/sounds.mp4';
audioplayer.on('error', (err) => {
   console.info('error callback info: ' + err);
});
audioplayer.setVolume(30000);
```


## AudioState

音频播放的状态机。

| 名称 | 描述 |
| -------- | -------- |
| idle | 音频播放空闲。 |
| playing | 音频正在播放。 |
| paused | 音频暂停播放。 |
| stopped | 音频播放停止。 |

## AudioRecorder

音频录制管理类，用于录制音频媒体。在调用AudioRecorder的方法前，需要先通过[createAudioRecorder()](#createaudiorecorder-audiorecorder)构建一个AudioRecorder实例。

### prepare

prepare(config: AudioRecorderConfig): void

录音准备。

**参数：**

| 参数名 | 类型                                        | 必填 | 说明                                                         |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| config | [AudioRecorderConfig](#audiorecorderconfig) | 是   | 配置录音的相关参数，包括音频输出URI、编码格式、采样率、声道数等。 |

**示例：**

```
let audioRecorderConfig = {
    audioEncoder : AAC_LC ,
    audioEncodeBitRate : 22050,
    audioSampleRate : 22050,
    numberOfChannels : 2,
    format : AAC_ADTS,
    uri : 'file:///data/accounts/account_0/appdata/appdata/recorder/test.m4a',
}
audiorecorder.prepare(audioRecorderConfig)
```


### start

start(): void

开始录音。

**示例：**

```
audiorecorder.start();
```

### stop

stop(): void

停止录音。

**示例：**

```
audiorecorder.stop();
```

### release

release(): void

释放录音资源。

**示例：**

```
audiorecorder.release();
```

### reset

reset(): void

重置录音。

进行重置录音之前，需要先调用stop()停止录音。重置录音之后，需要调用prepare()设置录音配置项，才能再次进行录音。

**示例：**

```
audiorecorder.reset();
```

### on('prepare' | 'start' |  'stop' | 'release' | 'reset')

on(type: 'prepare' | 'start' | 'stop' | 'release' | 'reset', callback: () => void): void

开始订阅音频录制事件。

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                         |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | 是   | 录制事件回调类型，支持的事件包括：'prepare'&nbsp;\|&nbsp;'start'&nbsp;\|&nbsp;'stop'&nbsp;\|&nbsp;'release'&nbsp;\|&nbsp;'reset'。<br/>-&nbsp;'prepare'&nbsp;：音频录制准备完成后，触发该事件。<br/>-&nbsp;'start'&nbsp;：音频录制开始后，触发该事件。<br/>-&nbsp;'stop'&nbsp;：音频录制停止后，触发该事件。<br/>-&nbsp;'release'&nbsp;：音频录制相关资源释放后，触发该事件。<br/>-&nbsp;'reset'：音频录制重置后，触发该事件。 |
| callback | function | 是   | 录制事件回调方法。                                           |

**示例：**

```
audiorecorder.on('prepare', () => {
  console.log('Preparation succeeded.');
  audiorecorder.start();
});
```

### on('error')

on(type: 'error', callback: ErrorCallback): void

开始订阅音频录制错误事件。

**参数：**

| 参数名   | 类型          | 必填 | 说明                                                         |
| -------- | ------------- | ---- | ------------------------------------------------------------ |
| type     | string        | 是   | 录制错误事件回调类型'error'。<br/>-&nbsp;'error'：音频录制过程中发生错误，触发该事件。 |
| callback | ErrorCallback | 是   | 录制错误事件回调方法。                                       |


## AudioRecorderConfig

表示音频的录音配置。

| 名称               | 参数类型                                | 必填 | 说明                                                         |
| ------------------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| audioEncoder       | [AudioEncoder](#audioencoder)           | 否   | 音频编码格式，默认设置为AAC_LC。                             |
| audioEncodeBitRate | number                                  | 否   | 音频编码比特率，默认值为48000。                              |
| audioSampleRate    | number                                  | 否   | 音频采集采样率，默认值为48000。                              |
| numberOfChannels   | number                                  | 否   | 音频采集声道数，默认值为2。                                  |
| format             | [AudioOutputFormat](#audiooutputformat) | 否   | 音量输出封装格式，默认设置为MPEG_4。                         |
| uri                | string                                  | 是   | 音频输出URI。支持：<br/>1.&nbsp;文件的绝对路径：file:///data/data/ohos.xxx.xxx/cache/test.mp4![zh-cn_image_0000001164217678](figures/zh-cn_image_0000001164217678.png)<br/>2.&nbsp;文件的fd路径：file://1&nbsp;(fd&nbsp;number) |


## AudioEncoder

表示音频编码格式的枚举。

| 名称   | 默认值 | 说明                                                         |
| ------ | ------ | ------------------------------------------------------------ |
| AAC_LC | 3      | AAC-LC（Advanced&nbsp;Audio&nbsp;Coding&nbsp;Low&nbsp;Complexity）编码格式。 |


## AudioOutputFormat

表示音频封装格式的枚举。

| 名称     | 默认值 | 说明                                                         |
| -------- | ------ | ------------------------------------------------------------ |
| MPEG_4   | 2      | 封装为MPEG-4格式。                                           |
| AAC_ADTS | 6      | 封装为ADTS（Audio&nbsp;Data&nbsp;Transport&nbsp;Stream）格式，是AAC音频的传输流格式。 |