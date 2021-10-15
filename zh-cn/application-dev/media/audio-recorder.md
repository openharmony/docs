# 音频录制开发指导

- [场景介绍](#场景介绍)
- [接口说明](#接口说明)

## 场景介绍

音频录制的主要工作是将音频信号记录并保存下来，同时提供包括采样率、声道数、码率、编码格式、封装格式、文件路径等设置功能。


## 接口说明

**表1** media

| 接口名 | 描述 |
| -------- | -------- |
| media.createAudioRecorder() | 创建AudioRecorder实例。 |
| AudioRecorder | 提供音频录制相关功能。 |
| AudioRecorderConfig | 提供音频录制相关参数设置。 |

**表2** 音频录制相关的interface **AudioRecorder**

| 接口名 | 描述 | 
| -------- | -------- |
| prepare(config:&nbsp;AudioRecorderConfig):&nbsp;void | 准备音频录制并设置参数。 | 
| start():&nbsp;void | 开始音频录制。 | 
| pause():&nbsp;void | 暂停音频录制。(暂不支持) | 
| resume():&nbsp;void | 恢复音频录制。(暂不支持) | 
| stop():&nbsp;void | 停止音频录制。 | 
| release():&nbsp;void | 释放音频录制资源。 | 
| reset():&nbsp;void | 重置音频录制。 | 
| on('prepare',&nbsp;function&nbsp;callback) | 订阅音频录制准备事件。 | 
| on('start',&nbsp;function&nbsp;callback) | 订阅音频录制开始事件。 | 
| on('pause',&nbsp;function&nbsp;callback) | 订阅音频录制暂停事件。 | 
| on('resume',&nbsp;function&nbsp;callback) | 订阅音频录制恢复事件。 | 
| on('stop',function&nbsp;callback) | 订阅音频录制结束事件。 | 
| on('release',&nbsp;function&nbsp;callback) | 订阅音频录制释放资源事件。 | 
| on('reset',&nbsp;function&nbsp;callback) | 订阅音频录制重置事件。 | 
| on('error',&nbsp;function&nbsp;callback) | 订阅音频录制错误事件。 | 

**表3** 音频录制的相关参数的interface **AudioRecorderConfig**

| 接口名 | 描述 |
| -------- | -------- |
| audioEncoder?: AudioEncoder | 音频编码格式,默认值是AAC_LC。 |
| audioEncodeBitRate?:&nbsp;number | 音频编码的比特率，默认值为48000。 |
| audioSampleRate?:&nbsp;number | 音频编码的采样率，默认值为48000。 |
| numberOfChannels?：number | 音频的声道数，默认值为2。 |
| format?:&nbsp;AudioOutputFormat | 音频的输出格式，默认值是MPEG_4。 |
| uri:&nbsp;string | 音频的输出路径。（file://path&nbsp;或者&nbsp;file://fd） |

**表4** AudioEncoder的相关参数的interface **AudioEncoder**

| 接口名 | 描述 | 
| -------- | -------- |
| AAC_LC&nbsp;=&nbsp;3 | 表示AAC_LC编码格式。 | 

**表5** 音频输出格式的相关参数的interface **AudioOutputFormat**

| 接口名 | 描述 | 
| -------- | -------- |
| MPEG_4&nbsp;=&nbsp;2 | 表示MPEG_4编码格式。 | 
| AAC_ADTS=&nbsp;6 | 表示AAC_ADTS编码格式。 | 

1. 创建音频录制器。
   ```
   import media from '@ohos.multimedia.media';
   var recorder = media.createAudioRecorder();
   ```

2. 准备音频录制参数。
   ```
   let audioRecorderConfig = {
       audioEncoder : AAC_LC ,
       audioEncodeBitRate : 22050,
       audioSampleRate : 22050,
       numberOfChannels : 2,
       format : AAC_ADTS,
       uri : 'file:///data/accounts/account_0/appdata/appdata/recorder/test.m4a',
   }
   recorder.prepare(audioRecorderConfig);
   ```

3. 设置消息订阅事件。
   ```
   recorder.on('prepare', () => {
       console.info('setCallback prepare() case callback is called');
       recorder.start();
   });
   recorder.on('start', () => {
       console.info('setCallback start() case callback is called');
       setTimeout(function(){
          recorder.pause();
       }, 10000); // 开始录音10秒后，暂停录音。
   });
   recorder.on('pause', () => {
       console.info('setCallback pause() case callback is called');
       setTimeout(function(){
          recorder.resume(); 
       }, 10000); // 暂停录音10秒后，恢复录音。
   });
   recorder.on('resume', () => {
       console.info('setCallback resume() case callback is called');
       setTimeout(function(){
          recorder.stop();
       }, 10000); // 恢复录音10秒后，停止录音。
   });
   recorder.on('stop', () => {
       console.info('setCallback stop() case callback is called');
       recorder.release();
   });
   recorder.on('release', () => {
        console.info('setCallback release() case callback is called');
   });
   recorder.on('error', (err) => {
        console.info(`case error called,errCode is ${err.code}`);
        console.info(`case error called,errMessage is ${err.message}`);
        recorder.reset();
   });
   ```
