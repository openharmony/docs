# 音频采集开发指导

## 场景介绍

AudioCapturer提供了用于获取原始音频文件的方法。开发者可以通过本指导了解应用如何通过AudioCapturer采集音频。

### 状态检查

在进行应用开发的过程中，建议开发者通过on('stateChange')方法订阅AudioCapturer的状态变更。因为针对AudioCapturer的某些操作，仅在音频采集器在固定状态时才能执行。如果应用在音频采集器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

详细API含义可参考：[音频管理API文档AudioCapturer](../reference/apis/js-apis-audio.md)

**图1** 音频采集状态机

![](figures/audio-capturer-state.png)

## 开发步骤

1. 使用createAudioCapturer()创建一个AudioCapturer实例。

   在audioCapturerOptions中设置音频采集器的相关参数。该实例可用于音频采集、控制和获取采集状态，以及注册通知回调。 

   ```js
      var audioStreamInfo = {
           samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
           channels: audio.AudioChannel.CHANNEL_1,
           sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
           encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
       }
      
       var audioCapturerInfo = {
           source: audio.SourceType.SOURCE_TYPE_MIC,
           capturerFlags: 1
       }
      
       var audioCapturerOptions = {
           streamInfo: audioStreamInfo,
           capturerInfo: audioCapturerInfo
       }
      
       let audioCapturer = await audio.createAudioCapturer(audioCapturerOptions);
       var state = audioRenderer.state;
   ```

2. （可选）使用on（'stateChange'）API订阅音频采集器状态更改事件。(根据订阅事件的状态去更新采集器的状态)。应用程序还可以订阅更多的事件，例如'markReach'和'periodReach'。有关详细信息，请参阅[音频](../reference/apis/js-apis-audio.md)。

   ```js
    audioCapturer.on('stateChange',(state) => {
    console.info('AudioCapturerLog: Changed State to : ' + state)
    switch (state) {
     case audio.AudioState.STATE_PREPARED:
         console.info('--------CHANGE IN AUDIO STATE----------PREPARED--------------');
         console.info('Audio State is : Prepared');
         break;
     case audio.AudioState.STATE_RUNNING:
         console.info('--------CHANGE IN AUDIO STATE----------RUNNING--------------');
         console.info('Audio State is : Running');
         break;
     case audio.AudioState.STATE_STOPPED:
         console.info('--------CHANGE IN AUDIO STATE----------STOPPED--------------');
         console.info('Audio State is : stopped');
         break;
     case audio.AudioState.STATE_RELEASED:
         console.info('--------CHANGE IN AUDIO STATE----------RELEASED--------------');
         console.info('Audio State is : released');
         break;
     default:
         console.info('--------CHANGE IN AUDIO STATE----------INVALID--------------');
         console.info('Audio State is : invalid');
         break;
     }
    });
   ```

3. 调用start()方法来启动/恢复采集任务。

   启动完成后，采集器状态将变更为STATE_RUNNING，然后应用可以开始读取缓冲区。

   ```js
   await audioCapturer.start();
   if (audioCapturer.state == audio.AudioState.STATE_RUNNING) {
       console.info('AudioRecLog: Capturer started');
   } else {
       console.info('AudioRecLog: Capturer start failed');
   }
   ```

3. 使用getBufferSize()方法获取要读取的最小缓冲区大小。

   ```js
   var bufferSize = await audioCapturer.getBufferSize();
   console.info('AudioRecLog: buffer size: ' + bufferSize);
   ```

4. 读取采集器的音频数据并将其转换为字节流。重复调用read()方法读取数据，直到应用准备停止采集。   

   参考以下示例，将采集到的数据写入文件。 

   ```js
   import fileio from '@ohos.fileio';
      
   const path = '/data/data/.pulse_dir/capture_js.wav';
   let fd = fileio.openSync(path, 0o102, 0o777);
   if (fd !== null) {
       console.info('AudioRecLog: file fd created');
   }
   else{
       console.info('AudioRecLog: file fd create : FAILED');
       return;
   }
      
   fd = fileio.openSync(path, 0o2002, 0o666);
   if (fd !== null) {
       console.info('AudioRecLog: file fd opened in append mode');
   }
      
   var numBuffersToCapture = 150;
   while (numBuffersToCapture) {
       var buffer = await audioCapturer.read(bufferSize, true);
       if (typeof(buffer) == undefined) {
           console.info('read buffer failed');
       } else {
           var number = fileio.writeSync(fd, buffer);
           console.info('AudioRecLog: data written: ' + number);
       }
      
       numBuffersToCapture--;
   }
   ```

5. 采集完成后，调用stop方法，停止录制。

   ```
   await audioCapturer.stop();
   if (audioCapturer.state == audio.AudioState.STATE_STOPPED) {
       console.info('AudioRecLog: Capturer stopped');
   } else {
       console.info('AudioRecLog: Capturer stop failed');
   }
   ```

6. 任务结束，调用release()方法释放相关资源。

   ```js
   await audioCapturer.release();
   if (audioCapturer.state == audio.AudioState.STATE_RELEASED) {
       console.info('AudioRecLog: Capturer released');
   } else {
       console.info('AudioRecLog: Capturer release failed');
   }
   ```