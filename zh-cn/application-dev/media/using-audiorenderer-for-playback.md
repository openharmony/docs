# 使用AudioRenderer开发音频播放功能

AudioRenderer是音频渲染器，用于播放PCM（Pulse Code Modulation）音频数据，相比AVPlayer而言，可以在输入前添加数据预处理，更适合有音频开发经验的开发者，以实现更灵活的播放功能。

## 开发指导

使用AudioRenderer播放音频涉及到AudioRenderer实例的创建、音频渲染参数的配置、渲染的开始与停止、资源的释放等。本开发指导将以一次渲染音频数据的过程为例，向开发者讲解如何使用AudioRenderer进行音频渲染，建议搭配[AudioRenderer的API说明](../reference/apis/js-apis-audio.md#audiorenderer8)阅读。

下图展示了AudioRenderer的状态变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。需要注意的是在确定的状态执行不合适的方法可能导致AudioRenderer发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

为保证UI线程不被阻塞，大部分AudioRenderer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用callback函数。

**图1** AudioRenderer状态变化示意图  

![AudioRenderer status change](figures/audiorenderer-status-change.png)

在进行应用开发的过程中，建议开发者通过on('stateChange')方法订阅AudioRenderer的状态变更。因为针对AudioRenderer的某些操作，仅在音频播放器在固定状态时才能执行。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

- prepared状态： 通过调用createAudioRenderer()方法进入到该状态。

- running状态： 正在进行音频数据播放，可以在prepared状态通过调用start()方法进入此状态，也可以在paused状态和stopped状态通过调用start()方法进入此状态。

- paused状态： 在running状态可以通过调用pause()方法暂停音频数据的播放并进入paused状态，暂停播放之后可以通过调用start()方法继续音频数据播放。

- stopped状态： 在paused/running状态可以通过stop()方法停止音频数据的播放。

- released状态： 在prepared、paused、stopped等状态，用户均可通过release()方法释放掉所有占用的硬件和软件资源，并且不会再进入到其他的任何一种状态了。

### 开发步骤及注意事项

1. 配置音频渲染参数并创建AudioRenderer实例，音频渲染参数的详细信息可以查看[AudioRendererOptions](../reference/apis/js-apis-audio.md#audiorendereroptions8)。
     
   ```ts
   import audio from '@ohos.multimedia.audio';
   
   let audioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
     channels: audio.AudioChannel.CHANNEL_1,
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
   };
   
   let audioRendererInfo = {
     content: audio.ContentType.CONTENT_TYPE_SPEECH,
     usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
     rendererFlags: 0
   };
   
   let audioRendererOptions = {
     streamInfo: audioStreamInfo,
     rendererInfo: audioRendererInfo
   };
   
   audio.createAudioRenderer(audioRendererOptions, (err, data) => {
     if (err) {
       console.error(`Invoke createAudioRenderer failed, code is ${err.code}, message is ${err.message}`);
       return;
     } else {
       console.info('Invoke createAudioRenderer succeeded.');
       let audioRenderer = data;
     }
   });
   ```

2. 调用start()方法进入running状态，开始渲染音频。
     
   ```ts
   audioRenderer.start((err) => {
     if (err) {
       console.error(`Renderer start failed, code is ${err.code}, message is ${err.message}`);
     } else {
       console.info('Renderer start success.');
     }
   });
   ```

3. 指定待渲染文件地址，打开文件调用write()方法向缓冲区持续写入音频数据进行渲染播放。如果需要对音频数据进行处理以实现个性化的播放，在写入之前操作即可。
     
   ```ts
   const bufferSize = await audioRenderer.getBufferSize();
   let file = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
   let buf = new ArrayBuffer(bufferSize);
   let readsize = await fs.read(file.fd, buf);
   let writeSize = await new Promise((resolve, reject) => {
     audioRenderer.write(buf, (err, writeSize) => {
       if (err) {
         reject(err);
       } else {
         resolve(writeSize);
       }
     });
   });
   ```

4. 调用stop()方法停止渲染。
     
   ```ts
   audioRenderer.stop((err) => {
     if (err) {
       console.error(`Renderer stop failed, code is ${err.code}, message is ${err.message}`);
     } else {
       console.info('Renderer stopped.');
     }
   });
   ```

5. 调用release()方法销毁实例，释放资源。
     
   ```ts
   audioRenderer.release((err) => {
     if (err) {
       console.error(`Renderer release failed, code is ${err.code}, message is ${err.message}`);
     } else {
       console.info('Renderer released.');
     }
   });
   ```

### 完整示例

下面展示了使用AudioRenderer渲染音频文件的示例代码。
  
```ts
import audio from '@ohos.multimedia.audio';
import fs from '@ohos.file.fs';

const TAG = 'AudioRendererDemo';

export default class AudioRendererDemo {
  private renderModel = undefined;
  private audioStreamInfo = {
    samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
    channels: audio.AudioChannel.CHANNEL_2, // 通道
    sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
    encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
  }
  private audioRendererInfo = {
    content: audio.ContentType.CONTENT_TYPE_MUSIC, // 媒体类型
    usage: audio.StreamUsage.STREAM_USAGE_MEDIA, // 音频流使用类型
    rendererFlags: 0 // 音频渲染器标志
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
    if (stateGroup.indexOf(this.renderModel.state) === -1) { // 当且仅当状态为prepared、paused和stopped之一时才能启动渲染
      console.error(TAG + 'start failed');
      return;
    }
    await this.renderModel.start(); // 启动渲染

    const bufferSize = await this.renderModel.getBufferSize();
    let context = getContext(this);
    let path = context.filesDir;
    const filePath = path + '/test.wav'; // 使用沙箱路径获取文件，实际路径为/data/storage/el2/base/haps/entry/files/test.wav

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
      if (this.renderModel.state === audio.AudioState.STATE_RELEASED) { // 如果渲染器状态为released，停止渲染
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
    // 只有渲染器状态为running的时候才能暂停
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
    // 只有渲染器状态为running或paused的时候才可以停止
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
    // 渲染器状态不是released状态，才能release
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

当同优先级或高优先级音频流要使用输出设备时，当前音频流会被中断，应用可以自行响应中断事件并做出处理。具体的音频并发处理方式可参考[多音频播放的并发策略](audio-playback-concurrency.md)。
