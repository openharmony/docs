# 开发音频通话功能
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @songshenke-->
<!--Designer: @caixuejiang; @hao-liangfei; @zhanganxiang-->
<!--Tester: @Filger-->
<!--Adviser: @zengyawen-->

在音频通话场景下，音频输出（播放对端声音）和音频输入（录制本端声音）会同时进行，应用可以通过使用AudioRenderer来实现音频输出，通过使用AudioCapturer来实现音频输入，同时使用AudioRenderer和AudioCapturer即可实现音频通话功能。

在音频通话开始和结束时，应用可以自行检查当前的[音频场景模式](audio-call-overview.md#音频场景模式)和[铃声模式](audio-call-overview.md#铃声模式)，以便采取合适的音频管理及提示策略。

以下代码示范了同时使用AudioRenderer和AudioCapturer实现音频通话功能的基本过程，其中未包含音频通话数据的传输过程，实际开发中，需要将网络传输来的对端通话数据解码播放，此处仅以读取音频文件的数据代替；同时需要将本端录制的通话数据编码打包，通过网络发送给对端，此处仅以将数据写入音频文件代替。

## 使用AudioRenderer播放对端的通话声音

  该过程与[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)过程相似，关键区别在于audioRendererInfo参数和音频数据来源。audioRendererInfo参数中，音频内容类型需设置为语音：CONTENT_TYPE_SPEECH，音频流使用类型需设置为VOIP通话：STREAM_USAGE_VOICE_COMMUNICATION。
  
```ts
import { audio } from '@kit.AudioKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

const TAG = 'VoiceCallDemoForAudioRenderer';
// 与使用AudioRenderer开发音频播放功能过程相似，关键区别在于audioRendererInfo参数和音频数据来源。
class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let renderModel: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};
let audioRendererInfo: audio.AudioRendererInfo = {
  // 需使用通话场景相应的参数。
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // 音频流使用类型：VOIP通话。
  rendererFlags: 0 // 音频渲染器标志：默认为0即可。
};
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let path = context.cacheDir;
// 确保该沙箱路径下存在该资源。
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };
  fs.readSync(file.fd, buffer, options);
  bufferSize += buffer.byteLength;
};

// 初始化，创建实例，设置监听事件。
audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, renderer: audio.AudioRenderer) => { // 创建AudioRenderer实例。
  if (!err) {
    console.info(`${TAG}: creating AudioRenderer success`);
    renderModel = renderer;
    if (renderModel !== undefined) {
      renderModel.on('stateChange', (state: audio.AudioState) => { // 设置监听事件，当转换到指定的状态时触发回调。
        if (state == 1) {
          console.info('audio renderer state is: STATE_PREPARED');
        }
        if (state == 2) {
          console.info('audio renderer state is: STATE_RUNNING');
        }
      });
      renderModel.on('markReach', 1000, (position: number) => { // 订阅markReach事件，当渲染的帧数达到1000帧时触发回调。
        if (position == 1000) {
          console.info('ON Triggered successfully');
        }
      });
      renderModel.on('writeData', writeDataCallback);
    }
  } else {
    console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
  }
});

// 开始一次音频渲染。
async function start() {
  if (renderModel !== undefined) {
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(renderModel.state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动渲染。
      console.error(TAG + 'start failed');
      return;
    }
    renderModel.start((err: BusinessError) => {
      if (err) {
        console.error('Renderer start failed.');
      } else {
        console.info('Renderer start success.');
      }
    });
  }
}

// 暂停渲染。
async function pause() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为STATE_RUNNING的时候才能暂停。
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    await renderModel.pause(); // 暂停渲染。
    if (renderModel.state.valueOf() === audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is paused.');
    } else {
      console.error('Pausing renderer failed.');
    }
  }
}

// 停止渲染。
async function stop() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止。
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING && renderModel.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    await renderModel.stop(); // 停止渲染。
    if (renderModel.state.valueOf() === audio.AudioState.STATE_STOPPED) {
      console.info('Renderer stopped.');
    } else {
      console.error('Stopping renderer failed.');
    }
  }
}

// 销毁实例，释放资源。
async function release() {
  if (renderModel !== undefined) {
    // 渲染器状态不是STATE_RELEASED状态，才能release。
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    await renderModel.release(); // 释放资源。
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer released');
    } else {
      console.error('Renderer release failed.');
    }
  }
}
```

## 使用AudioCapturer录制本端的通话声音

  该过程与[使用AudioCapturer开发音频录制功能](using-audiocapturer-for-recording.md)过程相似，关键区别在于audioCapturerInfo参数和音频数据流向。audioCapturerInfo参数中音源类型需设置为语音通话：SOURCE_TYPE_VOICE_COMMUNICATION。

  所有录制均需要申请麦克风权限：ohos.permission.MICROPHONE，申请方式请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

```ts
import { audio } from '@kit.AudioKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

const TAG = 'VoiceCallDemoForAudioCapturer';
class Options {
  offset?: number;
  length?: number;
}

// 与使用AudioCapturer开发音频录制功能过程相似，关键区别在于audioCapturerInfo参数和音频数据流向。
let bufferSize: number = 0;
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};
let audioCapturerInfo: audio.AudioCapturerInfo = {
  // 需使用通话场景相应的参数。
  source: audio.SourceType.SOURCE_TYPE_VOICE_COMMUNICATION, // 音源类型：语音通话。
  capturerFlags: 0 // 音频采集器标志：默认为0即可。
};
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
};
// 请在组件内获取context，确保this.getUIContext().getHostContext()返回结果为UIAbilityContext。
let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let path = context.cacheDir;
let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
let readDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };
  fs.writeSync(file.fd, buffer, options);
  bufferSize += buffer.byteLength;
};

// 初始化，创建实例，设置监听事件。
async function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err: BusinessError, capturer: audio.AudioCapturer) => { // 创建AudioCapturer实例。
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      audioCapturer.on('markReach', 1000, (position: number) => { // 订阅markReach事件，当采集的帧数达到1000帧时触发回调。
        if (position === 1000) {
          console.info('ON Triggered successfully');
        }
      });
      audioCapturer.on('periodReach', 2000, (position: number) => { // 订阅periodReach事件，当采集的帧数每达到2000时触发回调。
        if (position === 2000) {
          console.info('ON Triggered successfully');
        }
      });
      audioCapturer.on('readData', readDataCallback);
    }
  });
}

// 开始一次音频采集。
async function start() {
  if (audioCapturer !== undefined) {
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioCapturer.state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集。
      console.error(`${TAG}: start failed`);
      return;
    }
    audioCapturer.start((err: BusinessError) => {
      if (err) {
        console.error('Capturer start failed.');
      } else {
        console.info('Capturer start success.');
      }
    });
  }
}

// 停止采集。
async function stop() {
  if (audioCapturer !== undefined) {
    // 只有采集器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止。
    if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING && audioCapturer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }
    await audioCapturer.stop(); // 停止采集。
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_STOPPED) {
      console.info('Capturer stopped');
    } else {
      console.error('Capturer stop failed');
    }
  }
}

// 销毁实例，释放资源。
async function release() {
  if (audioCapturer !== undefined) {
    // 采集器状态不是STATE_RELEASED或STATE_NEW状态，才能release。
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED || audioCapturer.state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }
    await audioCapturer.release(); // 释放资源。
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Capturer released');
    } else {
      console.error('Capturer release failed');
    }
  }
}
```
