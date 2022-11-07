# 音频渲染开发指导

## 简介

AudioRenderer提供了渲染音频文件和控制播放的接口，开发者可以通过本指导，了解如何在输出设备中播放音频文件并管理播放任务。同时，AudioRenderer支持音频中断的功能。
开发者在调用AudioRenderer提供的各个接口时，需要理解以下名词：

- **音频中断**：当优先级较高的音频流需要播放时，AudioRenderer会中断优先级较低的流。例如，当用户在收听音乐时有来电，则优先级较低音乐播放将被暂停。
- **状态检查**：在进行应用开发的过程中，建议开发者通过on('stateChange')方法订阅AudioRenderer的状态变更。因为针对AudioRenderer的某些操作，仅在音频播放器在固定状态时才能执行。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。
- **异步操作**：为保证UI线程不被阻塞，大部分AudioRenderer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用Promise函数，更多方式可参考[音频管理API文档AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8)。

## 运作机制

该模块提供了音频渲染模块的状态变化示意

**图1** 音频渲染状态示意图

![audio-renderer-state](figures/audio-renderer-state.png)

**PREPARED状态：** 通过调用create()方法进入到该状态。<br>
**RUNNING状态：** 正在进行音频数据播放，可以在prepared状态通过调用start()方法进入此状态，也可以在pause状态和stopped状态通过调用start()方法进入此状态。<br>
**PAUSED状态：** 在running状态可以通过pause()方法暂停音频数据的播放，暂停播放之后可以通过调用start()方法继续音频数据播放。<br>
**STOPPED状态：** 在paused状态可以通过调用stop()方法停止音频数据的播放，在running状态可以通过stop()方法停止音频数据的播放。<br>
**RELEASED状态：** 在prepared、paused、stop等状态，用户均可通过release()方法释放掉所有占用的硬件和软件资源，并且不会再进入到其他的任何一种状态了。<br>

## 开发指导

详细API含义可参考：[音频管理API文档AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8)

1. 使用createAudioRenderer()创建一个AudioRenderer实例。
   在audioRendererOptions中设置相关参数。该实例可用于音频渲染、控制和获取渲染状态，以及注册通知回调。

   ```js
    import audio from '@ohos.multimedia.audio';

    let audioStreamInfo = {
        samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
        channels: audio.AudioChannel.CHANNEL_1,
        sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
        encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    }

    let audioRendererInfo = {
        content: audio.ContentType.CONTENT_TYPE_SPEECH,
        usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
        rendererFlags: 0 // 0是音频渲染器的扩展标志位，默认为0
    }

    let audioRendererOptions = {
        streamInfo: audioStreamInfo,
        rendererInfo: audioRendererInfo
    }

    let audioRenderer = await audio.createAudioRenderer(audioRendererOptions);
    console.log("Create audio renderer success.");
   ```

2. 调用start()方法来启动/恢复播放任务。
   
   ```js
   async function startRenderer() {
     let state = audioRenderer.state;
     // Renderer start时的状态应该是STATE_PREPARED、STATE_PAUSED和STATE_STOPPED之一.
     if (state != audio.AudioState.STATE_PREPARED || state != audio.AudioState.STATE_PAUSED ||
       state != audio.AudioState.STATE_STOPPED) {
       console.info('Renderer is not in a correct state to start');
       return;
     }

     await audioRenderer.start();

     state = audioRenderer.state;
     if (state == audio.AudioState.STATE_RUNNING) {
       console.info('Renderer started');
     } else {
       console.error('Renderer start failed');
     }
   }
   ```
   启动完成后，渲染器状态将变更为STATE_RUNNING，然后应用可以开始读取缓冲区。


3. 调用write()方法向缓冲区写入数据。

   将需要播放的音频数据读入缓冲区，重复调用write()方法写入。

   ```js
   import fileio from '@ohos.fileio';

    async function writeBuffer(buf) {
      let state = audioRenderer.state;
      // 写入数据时，渲染器的状态必须为STATE_RUNNING
      if (state != audio.AudioState.STATE_RUNNING) {
        console.error('Renderer is not running, do not write');
        this.isPlay = false;
        return;
      }
  
      let writtenbytes = await audioRenderer.write(buf);
  
      console.info(`Actual written bytes: ${writtenbytes} `);
      if (writtenbytes < 0) {
        console.error('Write buffer failed. check the state of renderer');
      }
    }
  
    // 此处是渲染器的合理的最小缓冲区大小（也可以选择其它大小的缓冲区）
    const bufferSize = await audioRenderer.getBufferSize();
    const path = '/data/file_example_WAV_2MG.wav'; // 需要渲染的音乐文件
    let ss = fileio.createStreamSync(path, 'r');
    const totalSize = fileio.statSync(path).size; // 音乐文件大小
    let discardHeader = new ArrayBuffer(bufferSize);
    ss.readSync(discardHeader);
    let rlen = 0;
    rlen += bufferSize;
  
    let id = setInterval(() => {
      if (this.isRelease) { // 如果渲染器状态为release，停止渲染
        ss.closeSync();
        stopRenderer();
        clearInterval(id);
      }
      if (this.isPlay) {
        if (rlen >= totalSize) { // 如果音频文件已经被读取完，停止渲染
          ss.closeSync();
          stopRenderer();
          clearInterval(id);
        }
        let buf = new ArrayBuffer(bufferSize);
        rlen += ss.readSync(buf);
        console.info(`Total bytes read from file: ${rlen}`);
        writeBuffer(buf);
      } else {
        console.info('check after next interval');
      }
    }, 30); // 定时器区间根据音频格式设置，单位为毫秒
   ```

4. （可选）调用pause()方法或stop()方法暂停/停止渲染音频数据。

   ```js
    async function pauseRenderer() {
      let state = audioRenderer.state;
      // 只有渲染器状态为STATE_RUNNING的时候才能暂停
      if (state != audio.AudioState.STATE_RUNNING) {
        console.info('Renderer is not running');
        return;
      }

      await audioRenderer.pause();

      state = audioRenderer.state;
      if (state == audio.AudioState.STATE_PAUSED) {
        console.info('Renderer paused');
      } else {
        console.error('Renderer pause failed');
      }
    }

    async function stopRenderer() {
      let state = audioRenderer.state;
      // 只有渲染器状态为STATE_RUNNING或STATE_PAUSED的时候才可以停止
      if (state != audio.AudioState.STATE_RUNNING && state != audio.AudioState.STATE_PAUSED) {
        console.info('Renderer is not running or paused');
        return;
      }

      await audioRenderer.stop();

      state = audioRenderer.state;
      if (state == audio.AudioState.STATE_STOPPED) {
        console.info('Renderer stopped');
      } else {
        console.error('Renderer stop failed');
      }
    }
   ```

5. （可选）调用drain()方法清空缓冲区。

   ```js
    async function drainRenderer() {
      let state = audioRenderer.state;
      // 只有渲染器状态为STATE_RUNNING的时候才能使用drain()
      if (state != audio.AudioState.STATE_RUNNING) {
        console.info('Renderer is not running');
        return;
      }

      await audioRenderer.drain();

      state = audioRenderer.state;
    }
   ```

6. 任务完成，调用release()方法释放相关资源。

   AudioRenderer会使用大量的系统资源，所以请确保完成相关任务后，进行资源释放。

   ```js
    async function releaseRenderer() {
      let state = audioRenderer.state;
      // 渲染器状态不是STATE_RELEASED或STATE_NEW状态，才能release
      if (state == audio.AudioState.STATE_RELEASED || state == audio.AudioState.STATE_NEW) {
        console.info('Renderer already released');
        return;
      }

      await audioRenderer.release();

      state = audioRenderer.state;
      if (state == audio.AudioState.STATE_RELEASED) {
        console.info('Renderer released');
      } else {
        console.info('Renderer release failed');
      }
    }
   ```

7. （可选）获取渲染器相关信息
   
   通过以下代码，可以获取渲染器的相关信息。

   ```js
   // 获取当前渲染器状态
   let state = audioRenderer.state;
   
   // 获取渲染器信息
   let audioRendererInfo : audio.AudioRendererInfo = await audioRenderer.getRendererInfo();

   // 获取音频流信息
   let audioStreamInfo : audio.AudioStreamInfo = await audioRenderer.getStreamInfo();

   // 获取音频流ID
   let audioStreamId : number = await audioRenderer.getAudioStreamId();

   // 获取纳秒形式的Unix时间戳
   let audioTime : number = await audioRenderer.getAudioTime();

   // 获取合理的最小缓冲区大小
   let bufferSize : number = await audioRenderer.getBuffersize();

   // 获取渲染速率
   let renderRate : audio.AudioRendererRate = await audioRenderer.getRenderRate();
   ```

8. （可选）设置渲染器相关信息
   
   通过以下代码，可以设置渲染器的相关信息。

   ```js
   // 设置渲染速率为正常速度
   let renderRate : audio.AudioRendererRate = audio.AudioRendererRate.RENDER_RATE_NORMAL;
   await audioRenderer.setRenderRate(renderRate);

   // 设置渲染器音频中断模式为SHARE_MODE
   let interruptMode : audio.InterruptMode = audio.InterruptMode.SHARE_MODE;
   await audioRenderer.setInterruptMode(interruptMode);

   // 设置一个流的音量为10
   let volume : number = 10;
   await audioRenderer.setVolume(volume);
   ```

9. （可选）使用on('audioInterrupt')方法订阅渲染器音频中断事件，使用off('audioInterrupt')取消订阅事件。

   当优先级更高或相等的Stream-B请求激活并使用输出设备时，Stream-A被中断。

   在某些情况下，框架会采取暂停播放、降低音量等强制操作，并通过InterruptEvent通知应用。在其他情况下，应用可以自行对InterruptEvent做出响应。

   在音频中断的情况下，应用可能会碰到音频数据写入失败的问题。所以建议不感知、不处理中断的应用在写入音频数据前，使用audioRenderer.state检查播放器状态。而订阅音频中断事件，可以获取到更多详细信息，具体可参考[InterruptEvent](../reference/apis/js-apis-audio.md#interruptevent9)。
   
   ```js
   audioRenderer.on('audioInterrupt', (interruptEvent) => {
     console.info('InterruptEvent Received');
     console.info(`InterruptType: ${interruptEvent.eventType}`);
     console.info(`InterruptForceType: ${interruptEvent.forceType}`);
     console.info(`AInterruptHint: ${interruptEvent.hintType}`);

     if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
       switch (interruptEvent.hintType) {
         // 音频框架发起的强制暂停操作，为防止数据丢失，此时应该停止数据的写操作
         case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
           isPlay = false;
           break;
         // 音频框架发起的强制停止操作，为防止数据丢失，此时应该停止数据的写操作
         case audio.InterruptHint.INTERRUPT_HINT_STOP:
           isPlay = false;
           break;
         // 音频框架发起的强制降低音量操作
         case audio.InterruptHint.INTERRUPT_HINT_DUCK:
           break;
         // 音频框架发起的恢复音量操作
         case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
           break;
       }
     } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
       switch (interruptEvent.hintType) {
         // 提醒App开始渲染
         case audio.InterruptHint.INTERRUPT_HINT_RESUME:
           startRenderer();
           break;
         // 提醒App音频流被中断，由App自主决定是否继续（此处选择暂停）
         case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
           isPlay = false;
           pauseRenderer();
           break;
       }
     }
   });

   audioRenderer.off('audioInterrupt'); // 取消音频中断事件的订阅，后续将无法监听到音频中断事件
   ```

10. （可选）使用on('markReach')方法订阅渲染器标记到达事件，使用off('markReach')取消订阅事件。

    注册markReach监听后，当渲染器渲染的帧数到达设定值时，会触发回调并返回设定的值。
   
    ```js
    audioRenderer.on('markReach', (reachNumber) => {
      console.info('Mark reach event Received');
      console.info(`The renderer reached frame: ${reachNumber}`);
    });

    audioRenderer.off('markReach'); // 取消markReach事件的订阅，后续将无法监听到“标记到达”事件
    ```

11. （可选）使用on('periodReach')方法订阅渲染器区间标记到达事件，使用off('periodReach')取消订阅事件。

    注册periodReach监听后，**每当**渲染器渲染的帧数到达设定值时，会触发回调并返回设定的值。
   
    ```js
    audioRenderer.on('periodReach', (reachNumber) => {
      console.info('Period reach event Received');
      console.info(`In this period, the renderer reached frame: ${reachNumber} `);
    });

    audioRenderer.off('periodReach'); // 取消periodReach事件的订阅，后续将无法监听到“区间标记到达”事件
    ```

12. （可选）使用on('stateChange')方法订阅渲染器音频状态变化事件。

    注册stateChange监听后，当渲染器的状态发生改变时，会触发回调并返回当前渲染器的状态。
   
    ```js
    audioRenderer.on('stateChange', (audioState) => {
      console.info('State change event Received');
      console.info(`Current renderer state is: ${audioState}`);
    });
    ```

13. （可选）对on()方法的异常处理。

    在使用on()方法时，如果传入的字符串错误或传入的参数类型错误，程序会抛出异常，需要用try catch来捕获。
   
    ```js
    try {
      audioRenderer.on('invalidInput', () => { // 字符串不匹配
      })
    } catch (err) {
      console.info(`Call on function error,  ${err}`); // 程序抛出401异常
    }

    try {
      audioRenderer.on(1, () => { // 入参类型错误
      })
    } catch (err) {
      console.info(`Call on function error,  ${err}`); // 程序抛出6800101异常
    }
    ```