# 开发音频通话功能(ArkTS)

在音频通话场景下，音频输出（播放对端声音）和音频输入（录制本端声音）会同时进行，应用可以通过使用AudioRenderer来实现音频输出，通过使用AudioCapturer来实现音频输入，同时使用AudioRenderer和AudioCapturer即可实现音频通话功能。

在音频通话开始和结束时，应用可以自行检查当前的[音频场景模式](audio-call-overview.md#音频场景模式)和[铃声模式](audio-call-overview.md#铃声模式)，以便采取合适的音频管理及提示策略。

以下代码示范了同时使用AudioRenderer和AudioCapturer实现音频通话功能的基本过程，其中未包含音频通话数据的传输过程，实际开发中，需要将网络传输来的对端通话数据解码播放，此处仅以读取音频文件的数据代替；同时需要将本端录制的通话数据编码打包，通过网络发送给对端，此处仅以将数据写入音频文件代替。

## 使用AudioRenderer播放对端的通话声音

  该过程与[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)过程相似，关键区别在于audioRendererInfo参数和音频数据来源。audioRendererInfo参数中，音频内容类型需设置为语音，CONTENT_TYPE_SPEECH，音频流使用类型需设置为语音通信，STREAM_USAGE_VOICE_COMMUNICATION。
  
```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

const TAG = 'VoiceCallDemoForAudioRenderer';
// 与使用AudioRenderer开发音频播放功能过程相似，关键区别在于audioRendererInfo参数和音频数据来源
let context = getContext(this);
let renderModel: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
  channels: audio.AudioChannel.CHANNEL_2, // 通道
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
}
let audioRendererInfo: audio.AudioRendererInfo = {
  // 需使用通话场景相应的参数
  usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // 音频流使用类型：语音通信
  rendererFlags: 0 // 音频渲染器标志：默认为0即可
}
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
}

// 初始化，创建实例，设置监听事件
audio.createAudioRenderer(audioRendererOptions, (err: BusinessError, renderer: audio.AudioRenderer) => { // 创建AudioRenderer实例
  if (!err) {
    console.info(`${TAG}: creating AudioRenderer success`);
    renderModel = renderer;
    if (renderModel !== undefined) {
      renderModel.on('stateChange', (state: audio.AudioState) => { // 设置监听事件，当转换到指定的状态时触发回调
        if (state == 1) {
          console.info('audio renderer state is: STATE_PREPARED');
        }
        if (state == 2) {
          console.info('audio renderer state is: STATE_RUNNING');
        }
      });
      renderModel.on('markReach', 1000, (position: number) => { // 订阅markReach事件，当渲染的帧数达到1000帧时触发回调
        if (position == 1000) {
          console.info('ON Triggered successfully');
        }
      });
    }
  } else {
    console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
  }
});

// 开始一次音频渲染
async function start() {
  if (renderModel !== undefined) {
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(renderModel.state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动渲染
      console.error(TAG + 'start failed');
      return;
    }
    await renderModel.start(); // 启动渲染
    const bufferSize: number = await renderModel.getBufferSize();
    // 此处仅以读取音频文件的数据举例，实际音频通话开发中，需要读取的是通话对端传输来的音频数据

    let path = context.filesDir;

    const filePath = path + '/voice_call_data.wav'; // 沙箱路径，实际路径为/data/storage/el2/base/haps/entry/files/voice_call_data.wav
    let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
    let stat = await fs.stat(filePath);
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize === 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    class Option {
      offset: number = 0
      length: number = 0
    }
    for (let i = 0; i < len; i++) {
      let options: Option = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readsize = await fs.read(file.fd, buf, options);
      // buf是要写入缓冲区的音频数据，在调用AudioRenderer.write()方法前可以进行音频数据的预处理，实现个性化的音频播放功能，AudioRenderer会读出写入缓冲区的音频数据进行渲染
      let writeSize: number = await renderModel.write(buf);
      if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) { // 如果渲染器状态为STATE_RELEASED，停止渲染
        fs.close(file);
        await renderModel.stop();
      }
      if (renderModel.state.valueOf() === audio.AudioState.STATE_RUNNING) {
        if (i === len - 1) { // 如果音频文件已经被读取完，停止渲染
          fs.close(file);
          await renderModel.stop();
        }
      }
    }
  }
}

// 暂停渲染
async function pause() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为STATE_RUNNING的时候才能暂停
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    await renderModel.pause(); // 暂停渲染
    if (renderModel.state.valueOf() === audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is paused.');
    } else {
      console.error('Pausing renderer failed.');
    }
  }
}

// 停止渲染
async function stop() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
    if (renderModel.state.valueOf() !== audio.AudioState.STATE_RUNNING && renderModel.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    await renderModel.stop(); // 停止渲染
    if (renderModel.state.valueOf() === audio.AudioState.STATE_STOPPED) {
      console.info('Renderer stopped.');
    } else {
      console.error('Stopping renderer failed.');
    }
  }
}

// 销毁实例，释放资源
async function release() {
  if (renderModel !== undefined) {
    // 渲染器状态不是STATE_RELEASED状态，才能release
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    await renderModel.release(); // 释放资源
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer released');
    } else {
      console.error('Renderer release failed.');
    }
  }
}
```

## 使用AudioCapturer录制本端的通话声音

  该过程与[使用AudioCapturer开发音频录制功能](using-audiocapturer-for-recording.md)过程相似，关键区别在于audioCapturerInfo参数和音频数据流向。audioCapturerInfo参数中音源类型需设置为语音通话，SOURCE_TYPE_VOICE_COMMUNICATION。
  
```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';
import { BusinessError } from '@ohos.base';

let context = getContext(this);
const TAG = 'VoiceCallDemoForAudioCapturer';
// 与使用AudioCapturer开发音频录制功能过程相似，关键区别在于audioCapturerInfo参数和音频数据流向
let audioCapturer: audio.AudioCapturer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100, // 采样率
  channels: audio.AudioChannel.CHANNEL_1, // 通道
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
}
let audioCapturerInfo: audio.AudioCapturerInfo = {
  // 需使用通话场景相应的参数
  source: audio.SourceType.SOURCE_TYPE_VOICE_COMMUNICATION, // 音源类型：语音通话
  capturerFlags: 0 // 音频采集器标志：默认为0即可
}
let audioCapturerOptions: audio.AudioCapturerOptions = {
  streamInfo: audioStreamInfo,
  capturerInfo: audioCapturerInfo
}

// 初始化，创建实例，设置监听事件
async function init() {
  audio.createAudioCapturer(audioCapturerOptions, (err: BusinessError, capturer: audio.AudioCapturer) => { // 创建AudioCapturer实例
    if (err) {
      console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info(`${TAG}: create AudioCapturer success`);
    audioCapturer = capturer;
    if (audioCapturer !== undefined) {
      audioCapturer.on('markReach', 1000, (position: number) => { // 订阅markReach事件，当采集的帧数达到1000时触发回调
        if (position === 1000) {
          console.info('ON Triggered successfully');
        }
      });
      audioCapturer.on('periodReach', 2000, (position: number) => { // 订阅periodReach事件，当采集的帧数达到2000时触发回调
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
    let stateGroup: number[] = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(audioCapturer.state.valueOf()) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集
      console.error(`${TAG}: start failed`);
      return;
    }
    await audioCapturer.start(); // 启动采集
    // 此处仅以将音频数据写入文件举例，实际音频通话开发中，需要将本端采集的音频数据编码打包，通过网络发送给通话对端
    const path = context.filesDir + '/voice_call_data.wav'; // 采集到的音频文件存储路径
    let file = fs.openSync(path, 0o2 | 0o100); // 如果文件不存在则创建文件
    let fd = file.fd;
    let numBuffersToCapture = 150; // 循环写入150次
    let count = 0;
    class Options {
      offset: number = 0
      length: number = 0
    }
    while (numBuffersToCapture) {
      let bufferSize: number = await audioCapturer.getBufferSize();
      let buffer: ArrayBuffer = await audioCapturer.read(bufferSize, true);
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
    if (audioCapturer.state.valueOf() !== audio.AudioState.STATE_RUNNING && audioCapturer.state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }
    await audioCapturer.stop(); // 停止采集
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_STOPPED) {
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
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED || audioCapturer.state.valueOf() === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }
    await audioCapturer.release(); // 释放资源
    if (audioCapturer.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Capturer released');
    } else {
      console.error('Capturer release failed');
    }
  }
}
```

## 相关实例

针对音频通话开发，有以下相关实例可供参考：

- [音频通话示例（ArkTS）（Full SDK）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/Media/VoiceCallDemo)