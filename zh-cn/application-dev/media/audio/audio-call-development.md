# 开发音频通话功能
<!--Kit: Audio Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zyy0412-->
<!--Designer: @magekkkk-->
<!--Tester: @Filger-->
<!--Adviser: @w_Machine_cc-->

在音频通话场景下，应用需要同时进行音频输出（播放对端声音）和音频输入（录制本端声音）。应用可以使用AudioRenderer实现音频输出，使用AudioCapturer实现音频输入，并结合系统API version 8之后提供的3A算法（声学回声消除、噪声抑制、自动增益控制）提升通话质量。

## 3A算法介绍

系统面向通话场景，根据音频流类型自动启用3A算法，用于提升人声清晰度和通话听感。

3A通常包括以下音频处理能力：

- 声学回声消除（Acoustic Echo Cancellation，AEC）：抑制扬声器播放声音被麦克风再次采集形成的回声。
- 噪声抑制（Automatic Noise Suppression，ANS）：降低环境噪声对通话人声的影响。
- 自动增益控制（Automatic Gain Control，AGC）：动态调整采集音量，使人声保持在合适响度范围内。

### 生效方式

- 播放对端声音时，`AudioRendererInfo`中的`usage`需设置为[STREAM_USAGE_VOICE_COMMUNICATION](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)或者[STREAM_USAGE_VIDEO_COMMUNICATION](../../reference/apis-audio-kit/arkts-apis-audio-e.md#streamusage)，用于标识VoIP语音通话播放流。该类型的播放流起播时，会触发开启3A算法。
- 录制本端声音时，`AudioCapturerInfo`中的`source`需设置为[SOURCE_TYPE_VOICE_COMMUNICATION](../../reference/apis-audio-kit/arkts-apis-audio-e.md#sourcetype8)，用于标识语音通话采集流。
- 播放和录制具体开发流程见下文[音频通话功能](audio-call-development.md#音频通话功能)。

### 注意事项

- 3A处理由系统根据设备能力和当前音频通路自动决策，不保证所有设备、所有路由下的处理效果完全一致。
- 通话场景下不建议叠加应用自定义降噪、回声消除或增益处理，避免与系统3A策略重复处理，造成声音失真、音量波动或人声异常。
- 如果通话中切换了输入或输出设备，系统可能重新选择音频通路，应用应关注设备变更并重新确认通话体验。
- 开发通话业务时，应同时按通话场景配置播放流和录音流。如果使用非STREAM_USAGE_VOICE_COMMUNICATION、STREAM_USAGE_VIDEO_COMMUNICATION播放类型或非SOURCE_TYPE_VOICE_COMMUNICATION录音类型，系统将无法识别为通话场景，导致回声消除、噪声抑制、自动增益控制等处理策略不生效或效果不符合预期。

## 音频通话功能

在音频通话开始和结束时，应用可以自行检查当前的[音频场景模式](audio-call-overview.md#音频场景模式)和[铃声模式](audio-call-overview.md#铃声模式)，以便采取合适的音频管理及提示策略。

以下代码示范了同时使用AudioRenderer和AudioCapturer实现音频通话功能的基本过程，其中未包含音频通话数据的传输过程，实际开发中，需要将网络传输来的对端通话数据解码播放，此处仅以读取音频文件的数据代替；同时需要将本端录制的通话数据编码打包，通过网络发送给对端，此处仅以将数据写入音频文件代替。

示例为片段代码，可通过点击示例代码右下方的链接获取[完整示例](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/Audio/VoipCallSampleJS)。

### 使用AudioRenderer播放对端的通话声音

该过程与[使用AudioRenderer开发音频播放功能(ArkTS)](using-audiorenderer-for-playback.md)过程相似，关键区别在于audioRendererInfo参数和音频数据来源。audioRendererInfo参数中，音频流使用类型usage需设置为VoIP通话：STREAM_USAGE_VOICE_COMMUNICATION。

<!-- @[all_VoIPDemoForAudioRenderer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/VoipCallSampleJS/entry/src/main/ets/pages/VoIpDemoForAudioRenderer.ets) -->   

``` TypeScript
import { audio } from '@kit.AudioKit'; // 导入audio模块。
import { BusinessError } from '@kit.BasicServicesKit'; // 导入BusinessError。
import { fileIo as fs } from '@kit.CoreFileKit'; // 导入文件操作模块。
import { common } from '@kit.AbilityKit'; // 导入UIAbilityContext。

// 与使用AudioRenderer开发音频播放功能过程相似，关键区别在于audioRendererInfo参数和音频数据来源。
const TAG = 'VoIPDemoForAudioRenderer';

class Options {
  public offset?: number;
  public length?: number;
}

let bufferSize: number = 0;
let audioRenderer: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率。
  channels: audio.AudioChannel.CHANNEL_2, // 通道。
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式。
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式。
};
let audioRendererInfo: audio.AudioRendererInfo = {
  // 需使用通话场景相应的参数。
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // 音频流使用类型：VoIP通话。
  rendererFlags: 0 // 音频渲染器标志：默认为0即可。
};
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};
let file: fs.File;
let writeDataCallback: audio.AudioRendererWriteDataCallback;
// ...
async function initArguments(context: common.UIAbilityContext) {
  let path = context.cacheDir;
  // 此处仅作示例，实际使用时需要将文件替换为应用要播放的PCM文件。
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
  writeDataCallback = (buffer: ArrayBuffer) => {
    let options: Options = {
      offset: bufferSize,
      length: buffer.byteLength
    };

    try {
      let bufferLength = fs.readSync(file.fd, buffer, options);
      bufferSize += buffer.byteLength;
      // 如果当前回调传入的数据不足一帧，空白区域需要使用静音数据填充,否则会导致播放出现杂音。
      if (bufferLength < buffer.byteLength) {
        let view = new DataView(buffer);
        for (let i = bufferLength; i < buffer.byteLength; i++) {
          // 空白区域填充静音数据。当使用音频采样格式为SAMPLE_FORMAT_U8时0x7F为静音数据，使用其他采样格式时0为静音数据。
          view.setUint8(i, 0);
        }
      }
      // API version 11不支持返回回调结果，从API version 12开始支持返回回调结果。
      // 如果开发者不希望播放某段buffer，返回audio.AudioDataCallbackResult.INVALID即可。
      if (typeof audio.AudioDataCallbackResult != 'undefined') {
        return audio.AudioDataCallbackResult.VALID;
      } else {
        return;
      }
    } catch (error) {
      console.error('Error reading file:', error);

      // ...
      // API version 11不支持返回回调结果，从API version 12开始支持返回回调结果。
      if (typeof audio.AudioDataCallbackResult != 'undefined') {
        return audio.AudioDataCallbackResult.VALID;
      } else {
        return;
      }
    }
  };
}

// 初始化，创建实例，设置监听事件。
async function init() {
  audio.createAudioRenderer(audioRendererOptions, (err, renderer) => { // 创建AudioRenderer实例。
    if (!err) {
      console.info(`${TAG}: creating AudioRenderer success`);
      // ...
      audioRenderer = renderer;
      if (audioRenderer !== undefined) {
        audioRenderer.on('writeData', writeDataCallback);
      }
    } else {
      console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
      // ...
    }
  });
}

// 开始一次音频渲染。
async function start() {
  if (audioRenderer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioRenderer.state.valueOf()) === -1) { // 当且仅当状态为prepared、paused和stopped之一时才能启动渲染。
      console.error(TAG + 'start failed');
      // ...
      return;
    }
    // 启动渲染。
    audioRenderer.start((err: BusinessError) => {
      if (err) {
        console.error('Renderer start failed.');
        // ...
      } else {
        console.info('Renderer start success.');
        // ...
      }
    });
  }
}

// 暂停渲染。
async function pause() {
  if (audioRenderer !== undefined) {
    // 只有渲染器状态为running的时候才能暂停。
    if (audioRenderer.state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      // ...
      return;
    }
    // 暂停渲染。
    audioRenderer.pause((err: BusinessError) => {
      if (err) {
        console.error('Renderer pause failed.');
        // ...
      } else {
        console.info('Renderer pause success.');
        // ...
      }
    });
  }
}

// 停止渲染。
async function stop() {
  if (audioRenderer !== undefined) {
    // 只有渲染器状态为running或paused的时候才可以停止。
    if (audioRenderer.state.valueOf() !== audio.AudioState.STATE_RUNNING &&
      audioRenderer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      // ...
      return;
    }
    // 停止渲染。
    audioRenderer.stop((err: BusinessError) => {
      if (err) {
        console.error('Renderer stop failed.');
        // ...
      } else {
        console.info('Renderer stop success.');
        // ...
      }
    });
  }
}

// 销毁实例，释放资源。
async function release() {
  if (audioRenderer !== undefined) {
    // 渲染器状态不是released状态,才能release。
    if (audioRenderer.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      // ...
      return;
    }
    // 释放资源。
    audioRenderer.release((err: BusinessError) => {
      if (err) {
        console.error('Renderer release failed.');
        // ...
      } else {
        console.info('Renderer release success.');
        // ...
      }
    });
    fs.close(file.fd);
  }
}
```

### 使用AudioCapturer录制本端的通话声音

该过程与[使用AudioCapturer开发音频录制功能(ArkTS)](using-audiocapturer-for-recording.md)过程相似，关键区别在于audioCapturerInfo参数和音频数据流向。audioCapturerInfo参数中音源类型source需设置为语音通话：SOURCE_TYPE_VOICE_COMMUNICATION。

所有录制均需要申请麦克风权限：ohos.permission.MICROPHONE，申请方式请参考[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

<!-- @[all_VoIPDemoForAudioCapturer](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Audio/VoipCallSampleJS/entry/src/main/ets/pages/VoIpDemoForAudioCapturer.ets) -->   

``` TypeScript
import { audio } from '@kit.AudioKit'; // 导入audio模块。
import { BusinessError } from '@kit.BasicServicesKit'; // 导入BusinessError。
import { fileIo as fs } from '@kit.CoreFileKit'; // 导入文件操作模块。
import { common, abilityAccessCtrl } from '@kit.AbilityKit'; // 导入UIAbilityContext。
// ...
// 与使用AudioCapturer开发音频录制功能过程相似，关键区别在于audioCapturerInfo参数和音频数据流向。
const TAG = 'VoIPDemoForAudioCapturer';

class Options {
  public offset?: number;
  public length?: number;
}

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
let file: fs.File;
let readDataCallback: Callback<ArrayBuffer>;

// ...

async function initArguments(context: common.UIAbilityContext) {
  let path = context.cacheDir;
  let filePath = path + '/StarWars10s-2C-48000-4SW.pcm';
  file = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  console.info(`File opened: ${filePath}`);

  readDataCallback = (buffer: ArrayBuffer) => {
    let options: Options = {
      offset: bufferSize,
      length: buffer.byteLength
    }
    fs.writeSync(file.fd, buffer, options);
    bufferSize += buffer.byteLength;
  }
}

// 初始化，创建实例，设置监听事件。
async function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err, capturer) => { // 创建AudioCapturer实例。
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      // ...
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    // ...
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      audioCapturer.on('readData', readDataCallback);
    }
  });
}

// 开始一次音频采集。
async function start() {
  if (audioCapturer !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioCapturer.state.valueOf()) === -1) {
      // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集。
      console.error(`${TAG}: start failed`);
      // ...
      return;
    }

    // 启动采集。
    audioCapturer.start((err: BusinessError) => {
      if (err) {
        console.error('Capturer start failed.');
        // ...
      } else {
        console.info('Capturer start success.');
        // ...
      }
    });
  }
}

// 停止采集。
async function stop() {
  if (audioCapturer !== undefined) {
    // 只有采集器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止。
    if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING &&
      audioCapturer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      // ...
      return;
    }

    // 停止采集。
    audioCapturer.stop((err: BusinessError) => {
      if (err) {
        console.error('Capturer stop failed.');
        // ...
      } else {
        fs.close(file);
        console.info('Capturer stop success.');
        // ...
      }
    });
  }
}

// 销毁实例，释放资源。
async function release() {
  if (audioCapturer !== undefined) {
    // 采集器状态不是STATE_RELEASED或STATE_NEW状态,才能release。
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED ||
      audioCapturer.state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      // ...
      return;
    }

    // 释放资源。
    audioCapturer.release((err: BusinessError) => {
      if (err) {
        console.error('Capturer release failed.');
        // ...
      } else {
        console.info('Capturer release success.');
        // ...
      }
    });
  }
}
```
