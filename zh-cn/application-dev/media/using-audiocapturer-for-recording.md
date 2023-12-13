# 使用AudioCapturer开发音频录制功能(ArkTS)

AudioCapturer是音频采集器，用于录制PCM（Pulse Code Modulation）音频数据，适合有音频开发经验的开发者实现更灵活的录制功能。

## 开发指导

使用AudioCapturer录制音频涉及到AudioCapturer实例的创建、音频采集参数的配置、采集的开始与停止、资源的释放等。本开发指导将以一次录制音频数据的过程为例，向开发者讲解如何使用AudioCapturer进行音频录制，建议搭配[AudioCapturer的API说明](../reference/apis/js-apis-audio.md#audiocapturer8)阅读。

下图展示了AudioCapturer的状态变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。需要注意的是在确定的状态执行不合适的方法可能导致AudioCapturer发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

**图1** AudioCapturer状态变化示意图  
![AudioCapturer status change](figures/audiocapturer-status-change.png)

使用on('stateChange')方法可以监听AudioCapturer的状态变化，每个状态对应值与说明见[AudioState](../reference/apis/js-apis-audio.md#audiostate8)。

### 开发步骤及注意事项

1. 配置音频采集参数并创建AudioCapturer实例，音频采集参数的详细信息可以查看[AudioCapturerOptions](../reference/apis/js-apis-audio.md#audiocaptureroptions8)。
     
   ```ts
    import audio from '@ohos.multimedia.audio';
    
    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
      channels: audio.AudioChannel.CHANNEL_2,
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    };
    
    let audioCapturerInfo: audio.AudioCapturerInfo = {
      source: audio.SourceType.SOURCE_TYPE_MIC,
      capturerFlags: 0
    };
    
    let audioCapturerOptions: audio.AudioCapturerOptions = {
      streamInfo: audioStreamInfo,
      capturerInfo: audioCapturerInfo
    };
    
    audio.createAudioCapturer(audioCapturerOptions, (err, data) => {
      if (err) {
        console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Invoke createAudioCapturer succeeded.');
        let audioCapturer = data;
      }
    });
   ```

2. 调用start()方法进入running状态，开始录制音频。
     
   ```ts
    audioCapturer.start((err: BusinessError) => {
      if (err) {
        console.error(`Capturer start failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Capturer start success.');
      }
    });
   ```

3. 指定录制文件地址，调用read()方法读取缓冲区的数据。
     
   ```ts
    import fs from '@ohos.file.fs';
    
    let context = getContext(this);
    async function read() {
      let path = context.filesDir;
      const filePath = path + '/voice_call_data.wav';
      let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      let bufferSize: number = await audioCapturer.getBufferSize();
      let buffer: ArrayBuffer = await audioCapturer.read(bufferSize, true);
      fs.writeSync(file.fd, buffer);
    }
   ```

4. 调用stop()方法停止录制。
     
   ```ts
    audioCapturer.stop((err: BusinessError) => {
      if (err) {
        console.error(`Capturer stop failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Capturer stopped.');
      }
    });
   ```

5. 调用release()方法销毁实例，释放资源。
     
   ```ts
    audioCapturer.release((err: BusinessError) => {
      if (err) {
        console.error(`capturer release failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('capturer released.');
      }
    });
   ```


### 完整示例

下面展示了使用AudioCapturer录制音频的完整示例代码。
  
```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';

const TAG = 'AudioCapturerDemo';
let context = getContext(this);

let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
  channels: audio.AudioChannel.CHANNEL_1,
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
}
let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型
  capturerFlags: 0 // 音频采集器标志
}
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

// 初始化，创建实例，设置监听事件
async function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // 创建AudioCapturer实例
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      (audioCapturer as audio.AudioCapturer).on('markReach', 1000, (position: number) => { // 订阅markReach事件，当采集的帧数达到1000时触发回调
        if (position === 1000) {
          console.info('ON Triggered successfully');
        }
      });
      (audioCapturer as audio.AudioCapturer).on('periodReach', 2000, (position: number) => { // 订阅periodReach事件，当采集的帧数达到2000时触发回调
        if (position === 2000) {
          console.info('ON Triggered successfully');
        }
      });
    }
  });
}

// 开始一次音频采集
async function start() {
  if (audioCapturer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf((audioCapturer as audio.AudioCapturer).state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集
      console.error(`${TAG}: start failed`);
      return;
    }
    await (audioCapturer as audio.AudioCapturer).start(); // 启动采集
    const path = context.filesDir + '/test.wav'; // 采集到的音频文件存储路径
    let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE); // 如果文件不存在则创建文件
    let fd = file.fd;
    let numBuffersToCapture = 150; // 循环写入150次
    let count = 0;
    class Options {
      offset: number = 0;
      length: number = 0
    }
    while (numBuffersToCapture) {
      let bufferSize = await (audioCapturer as audio.AudioCapturer).getBufferSize();
      let buffer = await (audioCapturer as audio.AudioCapturer).read(bufferSize, true);
      let options: Options = {
        offset: count * bufferSize,
        length: bufferSize
      };
      if (buffer === undefined) {
        console.error(`${TAG}: read buffer failed`);
      } else {
        let number = fs.writeSync(fd, buffer, options);
        console.info(`${TAG}: write date: ${number}`);
      }
      numBuffersToCapture--;
      count++;
    }
  }
}

// 停止采集
async function stop() {
  if (audioCapturer !== undefined) {
    // 只有采集器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_RUNNING && (audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }
    await (audioCapturer as audio.AudioCapturer).stop(); // 停止采集
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_STOPPED) {
       console.info('Capturer stopped');
    } else {
       console.error('Capturer stop failed');
    }
  }
}

// 销毁实例，释放资源
async function release() {
  if (audioCapturer !== undefined) {
    // 采集器状态不是STATE_RELEASED或STATE_NEW状态，才能release
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_RELEASED || (audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }
    await (audioCapturer as audio.AudioCapturer).release(); // 释放资源
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Capturer released');
    } else {
      console.error('Capturer release failed');
    }
  }
}
```
