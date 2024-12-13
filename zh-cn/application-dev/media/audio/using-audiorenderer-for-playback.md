# 使用AudioRenderer开发音频播放功能

AudioRenderer是音频渲染器，用于播放PCM（Pulse Code Modulation）音频数据，相比[AVPlayer](../media/using-avplayer-for-playback.md)而言，可以在输入前添加数据预处理，更适合有音频开发经验的开发者，以实现更灵活的播放功能。

## 开发指导

使用AudioRenderer播放音频涉及到AudioRenderer实例的创建、音频渲染参数的配置、渲染的开始与停止、资源的释放等。本开发指导将以一次渲染音频数据的过程为例，向开发者讲解如何使用AudioRenderer进行音频渲染，建议搭配[AudioRenderer的API说明](../../reference/apis-audio-kit/js-apis-audio.md#audiorenderer8)阅读。

下图展示了AudioRenderer的状态变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。需要注意的是在确定的状态执行不合适的方法可能导致AudioRenderer发生错误，建议开发者在调用状态转换的方法前进行状态检查，避免程序运行产生预期以外的结果。

为保证UI线程不被阻塞，大部分AudioRenderer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用callback函数。

**图1** AudioRenderer状态变化示意图

![AudioRenderer status change](figures/audiorenderer-status-change.png)

在进行应用开发的过程中，建议开发者通过[on('stateChange')](../../reference/apis-audio-kit/js-apis-audio.md#onstatechange-8)方法订阅AudioRenderer的状态变更。因为针对AudioRenderer的某些操作，仅在音频播放器在固定状态时才能执行。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

- prepared状态： 通过调用[createAudioRenderer()](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiorenderer8)方法进入到该状态。

- running状态： 正在进行音频数据播放，可以在prepared状态通过调用[start()](../../reference/apis-audio-kit/js-apis-audio.md#start8)方法进入此状态，也可以在paused状态和stopped状态通过调用[start()](../../reference/apis-audio-kit/js-apis-audio.md#start8)方法进入此状态。

- paused状态： 在running状态可以通过调用[pause()](../../reference/apis-audio-kit/js-apis-audio.md#pause8)方法暂停音频数据的播放并进入paused状态，暂停播放之后可以通过调用[start()](../../reference/apis-audio-kit/js-apis-audio.md#start8)方法继续音频数据播放。

- stopped状态： 在paused/running状态可以通过[stop()](../../reference/apis-audio-kit/js-apis-audio.md#stop8)方法停止音频数据的播放。

- released状态： 在prepared、paused、stopped等状态，用户均可通过[release()](../../reference/apis-audio-kit/js-apis-audio.md#release8)方法释放掉所有占用的硬件和软件资源，并且不会再进入到其他的任何一种状态了。

### 开发步骤及注意事项

1. 配置音频渲染参数并创建AudioRenderer实例，音频渲染参数的详细信息可以查看[AudioRendererOptions](../../reference/apis-audio-kit/js-apis-audio.md#audiorendereroptions8)。

    ```ts
    import { audio } from '@kit.AudioKit';

    let audioStreamInfo: audio.AudioStreamInfo = {
      samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
      channels: audio.AudioChannel.CHANNEL_2, // 通道
      sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
      encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
    };

    let audioRendererInfo: audio.AudioRendererInfo = {
      usage: audio.StreamUsage.STREAM_USAGE_MUSIC,
      rendererFlags: 0
    };

    let audioRendererOptions: audio.AudioRendererOptions = {
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

2. 调用on('writeData')方法，订阅监听音频数据写入回调，推荐使用API version 12支持返回回调结果的方式。

   - API version 12开始该方法支持返回回调结果，系统可以根据开发者返回的值来决定此次回调中的数据是否播放。

     > **注意：**
     > 
     > - 能填满回调所需长度数据的情况下，返回audio.AudioDataCallbackResult.VALID，系统会取用完整长度的数据缓冲进行播放。请不要在未填满数据的情况下返回audio.AudioDataCallbackResult.VALID，否则会导致杂音、卡顿等现象。
     > 
     > - 在无法填满回调所需长度数据的情况下，建议开发者返回audio.AudioDataCallbackResult.INVALID，系统不会处理该段音频数据，然后会再次向应用请求数据，确认数据填满后返回audio.AudioDataCallbackResult.VALID。
     > 
     > - 回调函数结束后，音频服务会把缓冲中数据放入队列里等待播放，因此请勿在回调外再次更改缓冲中的数据。对于最后一帧，如果数据不够填满缓冲长度，开发者需要使用剩余数据拼接空数据的方式，将缓冲填满，避免缓冲内的历史脏数据对播放效果产生不良的影响。

     ```ts
     import { audio } from '@kit.AudioKit';
     import { BusinessError } from '@kit.BasicServicesKit';
     import { fileIo as fs } from '@kit.CoreFileKit';

     class Options {
       offset?: number;
       length?: number;
     }

     let bufferSize: number = 0;
     let path = getContext().cacheDir;
     // 确保该沙箱路径下存在该资源
     let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
     let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);

     let writeDataCallback = (buffer: ArrayBuffer) => {
       let options: Options = {
         offset: bufferSize,
         length: buffer.byteLength
       };

       try {
         fs.readSync(file.fd, buffer, options);
         bufferSize += buffer.byteLength;
         // 系统会判定buffer有效，正常播放。
         return audio.AudioDataCallbackResult.VALID;
       } catch (error) {
         console.error('Error reading file:', error);
         // 系统会判定buffer无效，不播放。
         return audio.AudioDataCallbackResult.INVALID;
       }
     };

     audioRenderer.on('writeData', writeDataCallback);
     ```

   - API version 11该方法不支持返回回调结果，系统默认回调中的数据均为有效数据。

     > **注意：**
     > 
     > - 请确保填满回调所需长度数据，否则会导致杂音、卡顿等现象。
     > 
     > - 在无法填满回调所需长度数据的情况下，建议开发者选择暂时停止写入数据（不暂停音频流），阻塞回调函数，等待数据充足时，再继续写入数据，确保数据填满。在阻塞回调函数后，如需调用AudioRenderer相关接口，需先解阻塞。
     > 
     > - 开发者如果不希望播放本次回调中的音频数据，可以主动将回调中的数据块置空（置空后，也会被系统统计到已写入的数据，播放静音帧）。
     > 
     > - 回调函数结束后，音频服务会把缓冲中数据放入队列里等待播放，因此请勿在回调外再次更改缓冲中的数据。对于最后一帧，如果数据不够填满缓冲长度，开发者需要使用剩余数据拼接空数据的方式，将缓冲填满，避免缓冲内的历史脏数据对播放效果产生不良的影响。

     ```ts
     import { BusinessError } from '@kit.BasicServicesKit';
     import { fileIo as fs } from '@kit.CoreFileKit';

     class Options {
       offset?: number;
       length?: number;
     }

     let bufferSize: number = 0;
     let path = getContext().cacheDir;
     // 确保该沙箱路径下存在该资源
     let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
     let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
     let writeDataCallback = (buffer: ArrayBuffer) => {
       // 如果开发者不希望播放某段buffer，可在此处添加判断并对buffer进行置空处理。
       let options: Options = {
         offset: bufferSize,
         length: buffer.byteLength
       };
       fs.readSync(file.fd, buffer, options);
       bufferSize += buffer.byteLength;
     };

     audioRenderer.on('writeData', writeDataCallback);
     ```

3. 调用start()方法进入running状态，开始渲染音频。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioRenderer.start((err: BusinessError) => {
      if (err) {
        console.error(`Renderer start failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer start success.');
      }
    });
    ```

4. 调用stop()方法停止渲染。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioRenderer.stop((err: BusinessError) => {
      if (err) {
        console.error(`Renderer stop failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer stopped.');
      }
    });
    ```

5. 调用release()方法销毁实例，释放资源。

    ```ts
    import { BusinessError } from '@kit.BasicServicesKit';

    audioRenderer.release((err: BusinessError) => {
      if (err) {
        console.error(`Renderer release failed, code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('Renderer released.');
      } 
    });
    ```

### 选择正确的StreamUsage

创建播放器时候，开发者需要根据应用场景指定播放器的`StreamUsage`，选择正确的`StreamUsage`可以避免用户遇到不符合预期的行为。

在音频API文档[StreamUsage](../../reference/apis-audio-kit/js-apis-audio.md#streamusage)介绍中，列举了每一种类型推荐的应用场景。例如音乐场景推荐使用`STREAM_USAGE_MUSIC`，电影或者视频场景推荐使用`STREAM_USAGE_MOVIE`，游戏场景推荐使用`STREAM_USAGE_GAME`，等等。

如果开发者配置了不正确的`StreamUsage`，可能带来一些不符合预期的行为。例如以下场景。

- 游戏场景错误使用`STREAM_USAGE_MUSIC`类型，游戏应用将无法和其他音乐应用并发播放，而游戏场景通常可以与其他音乐应用并发播放。
- 导航场景错误使用`STREAM_USAGE_MUSIC`类型，导航应用播报时候会导致正在播放的音乐停止播放，而导航场景我们通常期望正在播放的音乐仅仅降低音量播放。

### 完整示例

下面展示了使用AudioRenderer渲染音频文件的示例代码。

```ts
import { audio } from '@kit.AudioKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

const TAG = 'AudioRendererDemo';

class Options {
  offset?: number;
  length?: number;
}

let bufferSize: number = 0;
let renderModel: audio.AudioRenderer | undefined = undefined;
let audioStreamInfo: audio.AudioStreamInfo = {
  samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_48000, // 采样率
  channels: audio.AudioChannel.CHANNEL_2, // 通道
  sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE, // 采样格式
  encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW // 编码格式
};
let audioRendererInfo: audio.AudioRendererInfo = {
  usage: audio.StreamUsage.STREAM_USAGE_MUSIC, // 音频流使用类型
  rendererFlags: 0 // 音频渲染器标志
};
let audioRendererOptions: audio.AudioRendererOptions = {
  streamInfo: audioStreamInfo,
  rendererInfo: audioRendererInfo
};
let path = getContext().cacheDir;
// 确保该沙箱路径下存在该资源
let filePath = path + '/StarWars10s-2C-48000-4SW.wav';
let file: fs.File = fs.openSync(filePath, fs.OpenMode.READ_ONLY);
let writeDataCallback = (buffer: ArrayBuffer) => {
  let options: Options = {
    offset: bufferSize,
    length: buffer.byteLength
  };

  try {
    fs.readSync(file.fd, buffer, options);
    bufferSize += buffer.byteLength;
    // API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果
    return audio.AudioDataCallbackResult.VALID;
  } catch (error) {
    console.error('Error reading file:', error);
    // API version 11 不支持返回回调结果，从 API version 12 开始支持返回回调结果
    return audio.AudioDataCallbackResult.INVALID;
  }
};

// 初始化，创建实例，设置监听事件
function init() {
  audio.createAudioRenderer(audioRendererOptions, (err, renderer) => { // 创建AudioRenderer实例
    if (!err) {
      console.info(`${TAG}: creating AudioRenderer success`);
      renderModel = renderer;
      if (renderModel !== undefined) {
        (renderModel as audio.AudioRenderer).on('writeData', writeDataCallback);
      }
    } else {
      console.info(`${TAG}: creating AudioRenderer failed, error: ${err.message}`);
    }
  });
}

// 开始一次音频渲染
function start() {
  if (renderModel !== undefined) {
    let stateGroup = [audio.AudioState.STATE_PREPARED, audio.AudioState.STATE_PAUSED, audio.AudioState.STATE_STOPPED];
    if (stateGroup.indexOf((renderModel as audio.AudioRenderer).state.valueOf()) === -1) { // 当且仅当状态为prepared、paused和stopped之一时才能启动渲染
      console.error(TAG + 'start failed');
      return;
    }
    // 启动渲染
    (renderModel as audio.AudioRenderer).start((err: BusinessError) => {
      if (err) {
        console.error('Renderer start failed.');
      } else {
        console.info('Renderer start success.');
      }
    });
  }
}

// 暂停渲染
function pause() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为running的时候才能暂停
    if ((renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_RUNNING) {
      console.info('Renderer is not running');
      return;
    }
    // 暂停渲染
    (renderModel as audio.AudioRenderer).pause((err: BusinessError) => {
      if (err) {
        console.error('Renderer pause failed.');
      } else {
        console.info('Renderer pause success.');
      }
    });
  }
}

// 停止渲染
async function stop() {
  if (renderModel !== undefined) {
    // 只有渲染器状态为running或paused的时候才可以停止
    if ((renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_RUNNING && (renderModel as audio.AudioRenderer).state.valueOf() !== audio.AudioState.STATE_PAUSED) {
      console.info('Renderer is not running or paused.');
      return;
    }
    // 停止渲染
    (renderModel as audio.AudioRenderer).stop((err: BusinessError) => {
      if (err) {
        console.error('Renderer stop failed.');
      } else {
        fs.close(file);
        console.info('Renderer stop success.');
      }
    });
  }
}

// 销毁实例，释放资源
async function release() {
  if (renderModel !== undefined) {
    // 渲染器状态不是released状态，才能release
    if (renderModel.state.valueOf() === audio.AudioState.STATE_RELEASED) {
      console.info('Renderer already released');
      return;
    }
    // 释放资源
    (renderModel as audio.AudioRenderer).release((err: BusinessError) => {
      if (err) {
        console.error('Renderer release failed.');
      } else {
        console.info('Renderer release success.');
      }
    });
  }
}
```

当同优先级或高优先级音频流要使用输出设备时，当前音频流会被中断，应用可以自行响应中断事件并做出处理。具体的音频并发处理方式可参考[处理音频焦点事件](audio-playback-concurrency.md)。
