# 使用AudioCapturer开发音频录制功能

AudioCapturer是音频采集器，用于录制PCM（Pulse Code Modulation）音频数据，适合有音频开发经验的开发者实现更灵活的录制功能。

## 开发指导

使用AudioCapturer录制音频涉及到AudioCapturer实例的创建、音频采集参数的配置、采集的开始与停止、资源的释放等。本开发指导将以一次录制音频数据的过程为例，向开发者讲解如何使用AudioCapturer进行音频录制，建议搭配[AudioCapturer的API说明](../../reference/apis-audio-kit/js-apis-audio.md#audiocapturer8)阅读。

下图展示了AudioCapturer的状态变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。需要注意的是在确定的状态执行不合适的方法可能导致AudioCapturer发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

**图1** AudioCapturer状态变化示意图

![AudioCapturer status change](figures/audiocapturer-status-change.png)

使用on('stateChange')方法可以监听AudioCapturer的状态变化，每个状态对应值与说明见[AudioState](../../reference/apis-audio-kit/js-apis-audio.md#audiostate8)。

### 开发步骤及注意事项

1. 配置音频采集参数并创建AudioCapturer实例，音频采集参数的详细信息可以查看[AudioCapturerOptions](../../reference/apis-audio-kit/js-apis-audio.md#audiocaptureroptions8)。

   > **说明：**
   > 当设置Mic音频源（即[SourceType](../../reference/apis-audio-kit/js-apis-audio.md#sourcetype8)为SOURCE_TYPE_MIC、SOURCE_TYPE_VOICE_RECOGNITION、SOURCE_TYPE_VOICE_COMMUNICATION、SOURCE_TYPE_VOICE_MESSAGE）时，需要申请麦克风权限ohos.permission.MICROPHONE，申请方式参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

   ```ts
    import { audio } from '@kit.AudioKit';
    
    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
      channels: audio.AudioChannel.CHANNEL_2, // 通道
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
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

2. 调用on('readData')方法，订阅监听音频数据读入回调。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';
    import { fileIo as fs } from '@kit.CoreFileKit';

    class Options {
      offset?: number;
      length?: number;
    }

    let bufferSize: number = 0;
    let path = getContext().cacheDir;
    let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
    let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    let readDataCallback = (buffer: ArrayBuffer) => {
      let options: Options = {
        offset: bufferSize,
        length: buffer.byteLength
      }
      fs.writeSync(file.fd, buffer, options);
      bufferSize += buffer.byteLength;
    };

    audioCapturer.on('readData', readDataCallback);
   ```

3. 调用start()方法进入running状态，开始录制音频。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioCapturer.start((err: BusinessError) => {
      if (err) {
        console.error(`Capturer start failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Capturer start success.');
      }
    });
   ```

4. 调用stop()方法停止录制。

   ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

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
    import { BusinessError } from '@kit.BasicServicesKit';

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
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const TAG = 'AudioCapturerDemo';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
  channels: audio.AudioChannel.CHANNEL_2, // 通道
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
};
let audioCapturerInfo: audio.AudioCapturerInfo = {
  source: audio.SourceType.SOURCE_TYPE_MIC, // 音源类型
  capturerFlags: 0 // 音频采集器标志
};
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};
let path = getContext().cacheDir;
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
let readDataCallback = (buffer: ArrayBuffer) => {
   let options: Options = {
      offset: bufferSize,
      length: buffer.byteLength
   }
   fs.writeSync(file.fd, buffer, options);
   bufferSize += buffer.byteLength;
};

// 初始化，创建实例，设置监听事件
function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // 创建AudioCapturer实例
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
       (audioCapturer as audio.AudioCapturer).on('readData', readDataCallback);
    }
  });
}

// 开始一次音频采集
function start() {
  if (audioCapturer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf((audioCapturer as audio.AudioCapturer).state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集
      console.error(`${TAG}: start failed`);
      return;
    }

    // 启动采集
    (audioCapturer as audio.AudioCapturer).start((err: BusinessError) => {
      if (err) {
        console.error('Capturer start failed.');
      } else {
        console.info('Capturer start success.');
      }
    });
  }
}

// 停止采集
function stop() {
  if (audioCapturer !== undefined) {
    // 只有采集器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_RUNNING && (audioCapturer as audio.AudioCapturer).state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }

    //停止采集
    (audioCapturer as audio.AudioCapturer).stop((err: BusinessError) => {
      if (err) {
        console.error('Capturer stop failed.');
      } else {
        fs.close(file);
        console.info('Capturer stop success.');
      }
    });
  }
}

// 销毁实例，释放资源
function release() {
  if (audioCapturer !== undefined) {
    // 采集器状态不是STATE_RELEASED或STATE_NEW状态，才能release
    if ((audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_RELEASED || (audioCapturer as audio.AudioCapturer).state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }

    //释放资源
    (audioCapturer as audio.AudioCapturer).release((err: BusinessError) => {
      if (err) {
        console.error('Capturer release failed.');
      } else {
        console.info('Capturer release success.');
      }
    });
  }
}
```
