# 开发音频通话功能

在音频通话场景下，音频输出（播放对端声音）和音频输入（录制本端声音）会同时进行，应用可以通过使用AudioRenderer来实现音频输出，通过使用AudioCapturer来实现音频输入，同时使用AudioRenderer和AudioCapturer即可实现音频通话功能。

在音频通话开始和结束时，应用可以自行检查当前的[音频场景模式](audio-call-overview.md#音频场景模式)和[铃声模式](audio-call-overview.md#铃声模式)，以便采取合适的音频管理及提示策略。

以下代码示范了同时使用AudioRenderer和AudioCapturer实现音频通话功能的基本过程，其中未包含音频通话数据的传输过程，实际开发中，需要将网络传输来的对端通话数据解码播放，此处仅以读取音频文件的数据代替；同时需要将本端录制的通话数据编码打包，通过网络发送给对端，此处仅以将数据写入音频文件代替。

## 使用AudioRenderer播放对端的通话声音

  该过程与[使用AudioRenderer开发音频播放功能](using-audiorenderer-for-playback.md)过程相似，关键区别在于audioRendererInfo参数和音频数据来源。audioRendererInfo参数中，音频内容类型需设置为语音，CONTENT_TYPE_SPEECH，音频流使用类型需设置为语音通信，STREAM_USAGE_VOICE_COMMUNICATION。
  
```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';
const TAG = 'VoiceCallDemoForAudioRenderer';
// 与使用AudioRenderer开发音频播放功能过程相似，关键区别在于audioRendererInfo参数和音频数据来源
export default class VoiceCallDemoForAudioRenderer {
  private renderModel = undefined;
  private audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
    channels: audio.AudioChannel.CHANNEL_2, // 通道
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
  }
  private audioRendererInfo = {
    // 需使用通话场景相应的参数
    content: audio.ContentType.CONTENT_TYPE_SPEECH, // 音频内容类型：语音
    usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION, // 音频流使用类型：语音通信
    rendererFlags: 0 // 音频渲染器标志：默认为0即可
  }
  private audioRendererOptions = {
    streamInfo: this.audioStreamInfo,
    rendererInfo: this.audioRendererInfo
  }
  // 初始化，创建实例，设置监听事件
  init() {
    audio.createAudioRenderer(this.audioRendererOptions, (err, renderer) => { // 创建AudioRenderer实例
      if (!err) {
        console.info(`${TAG}: creating AudioRenderer success`);
        this.renderModel = renderer;
        this.renderModel.on('stateChange', (state) => { // 设置监听事件，当转换到指定的状态时触发回调
          if (state == 1) {
            console.info('audio renderer state is: STATE_PREPARED');
          }
          if (state == 2) {
            console.info('audio renderer state is: STATE_RUNNING');
          }
        });
        this.renderModel.on('markReach', 1000, (position) => { // 订阅markReach事件，当渲染的帧数达到1000帧时触发回调
          if (position == 1000) {
            console.info('ON Triggered successfully');
          }
        });
      } else {
        console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
      }
    });
  }
  // 开始一次音频渲染
  async start() {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(this.renderModel.state) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动渲染
      console.error(TAG + 'start failed');
      return;
    }
    await this.renderModel.start(); // 启动渲染
    const bufferSize = await this.renderModel.getBufferSize();
    // 此处仅以读取音频文件的数据举例，实际音频通话开发中，需要读取的是通话对端传输来的音频数据
    let context = getContext(this);
    let path = context.filesDir;
    
    const filePath = path + '/voice_call_data.wav'; // 沙箱路径，实际路径为/data/storage/el2/base/haps/entry/files/voice_call_data.wav
    let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
    let stat = await fs.stat(filePath);
    let buf = new ArrayBuffer(bufferSize);
    let len = stat.size % bufferSize === 0 ? Math.floor(stat.size / bufferSize) : Math.floor(stat.size / bufferSize + 1);
    for (let i = 0; i < len; i++) {
      let options = {
        offset: i * bufferSize,
        length: bufferSize
      };
      let readsize = await fs.read(file.fd, buf, options);
      // buf是要写入缓冲区的音频数据，在调用AudioRenderer.write()方法前可以进行音频数据的预处理，实现个性化的音频播放功能，AudioRenderer会读出写入缓冲区的音频数据进行渲染
      let writeSize = await new Promise((resolve, reject) => {
        this.renderModel.write(buf, (err, writeSize) => {
          if (err) {
            reject(err);
          } else {
            resolve(writeSize);
          }
        });
      });
      if (this.renderModel.state === audio.AudioState.STATE_RELEASED) { // 如果渲染器状态为STATE_RELEASED，停止渲染
        fs.close(file);
        await this.renderModel.stop();
      }
      if (this.renderModel.state === audio.AudioState.STATE_RUNNING) {
        if (i === len - 1) { // 如果音频文件已经被读取完，停止渲染
          fs.close(file);
          await this.renderModel.stop();
        }
      }
    }
  }
  // 暂停渲染
  async pause() {
    // 只有渲染器状态为STATE_RUNNING的时候才能暂停
    if (this.renderModel.state !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    await this.renderModel.pause(); // 暂停渲染
    if (this.renderModel.state === audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is paused.');
    } else {
      console.error('Pausing renderer failed.');
    }
  }
  // 停止渲染
  async stop() {
    // 只有渲染器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
    if (this.renderModel.state !== audio.AudioState.STATE_RUNNING && this.renderModel.state !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    await this.renderModel.stop(); // 停止渲染
    if (this.renderModel.state === audio.AudioState.STATE_STOPPED) {
      console.info('Renderer stopped.');
    } else {
      console.error('Stopping renderer failed.');
    }
  }
  // 销毁实例，释放资源
  async release() {
    // 渲染器状态不是STATE_RELEASED状态，才能release
    if (this.renderModel.state === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    await this.renderModel.release(); // 释放资源
    if (this.renderModel.state === audio.AudioState.STATE_RELEASED) {
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
const TAG = 'VoiceCallDemoForAudioCapturer';
// 与使用AudioCapturer开发音频录制功能过程相似，关键区别在于audioCapturerInfo参数和音频数据流向
export default class VoiceCallDemoForAudioCapturer {
  private audioCapturer = undefined;
  private audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100, // 采样率
    channels: audio.AudioChannel.CHANNEL_1, // 通道
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
  }
  private audioCapturerInfo = {
    // 需使用通话场景相应的参数
    source: audio.SourceType.SOURCE_TYPE_VOICE_COMMUNICATION, // 音源类型：语音通话
    capturerFlags: 0 // 音频采集器标志：默认为0即可
  }
  private audioCapturerOptions = {
    streamInfo: this.audioStreamInfo,
    capturerInfo: this.audioCapturerInfo
  }
  // 初始化，创建实例，设置监听事件
  init() {
    audio.createAudioCapturer(this.audioCapturerOptions, (err, capturer) => { // 创建AudioCapturer实例
      if (err) {
        console.error(`Invoke createAudioCapturer failed, code is ${err.code}, message is ${err.message}`);
        return;
      }
      console.info(`${TAG}: create AudioCapturer success`);
      this.audioCapturer = capturer;
      this.audioCapturer.on('markReach', 1000, (position) => { // 订阅markReach事件，当采集的帧数达到1000时触发回调
        if (position === 1000) {
          console.info('ON Triggered successfully');
        }
      });
      this.audioCapturer.on('periodReach', 2000, (position) => { // 订阅periodReach事件，当采集的帧数达到2000时触发回调
        if (position === 2000) {
          console.info('ON Triggered successfully');
        }
      });
    });
  }
  // 开始一次音频采集
  async start() {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf(this.audioCapturer.state) === -1) { // 当且仅当状态为STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一时才能启动采集
      console.error(`${TAG}: start failed`);
      return;
    }
    await this.audioCapturer.start(); // 启动采集
    // 此处仅以将音频数据写入文件举例，实际音频通话开发中，需要将本端采集的音频数据编码打包，通过网络发送给通话对端
    let context = getContext(this);
    const path = context.filesDir + '/voice_call_data.wav'; // 采集到的音频文件存储路径
    let file = fs.openSync(path, 0o2 | 0o100); // 如果文件不存在则创建文件
    let fd = file.fd;
    let numBuffersToCapture = 150; // 循环写入150次
    let count = 0;
    while (numBuffersToCapture) {
      let bufferSize = await this.audioCapturer.getBufferSize();
      let buffer = await this.audioCapturer.read(bufferSize, true);
      let options = {
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
  // 停止采集
  async stop() {
    // 只有采集器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
    if (this.audioCapturer.state !== audio.AudioState.STATE_RUNNING && this.audioCapturer.state !== audio.AudioState.STATE_PAUSED) {
      console.info('Capturer is not running or paused');
      return;
    }
    await this.audioCapturer.stop(); // 停止采集
    if (this.audioCapturer.state === audio.AudioState.STATE_STOPPED) {
      console.info('Capturer stopped');
    } else {
      console.error('Capturer stop failed');
    }
  }
  // 销毁实例，释放资源
  async release() {
    // 采集器状态不是STATE_RELEASED或STATE_NEW状态，才能release
    if (this.audioCapturer.state === audio.AudioState.STATE_RELEASED || this.audioCapturer.state === audio.AudioState.STATE_NEW) {
      console.info('Capturer already released');
      return;
    }
    await this.audioCapturer.release(); // 释放资源
    if (this.audioCapturer.state == audio.AudioState.STATE_RELEASED) {
      console.info('Capturer released');
    } else {
      console.error('Capturer release failed');
    }
  }
}
```
