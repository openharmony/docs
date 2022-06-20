# 音频渲染开发指导

## 场景介绍

AudioRenderer提供了渲染音频文件和控制播放的接口，开发者可以通过本指导，了解如何在输出设备中播放音频文件并管理播放任务。

同时，AudioRenderer支持音频中断的功能。

### 音频中断

当优先级较高的音频流需要播放时，AudioRenderer会中断优先级较低的流。例如，当用户在收听音乐时有来电，则优先级较低音乐播放将被暂停，具体可参考[开发步骤](#开发步骤)。

### 状态检查

在进行应用开发的过程中，建议开发者通过on('stateChange')方法订阅AudioRenderer的状态变更。因为针对AudioRenderer的某些操作，仅在音频播放器在固定状态时才能执行。如果应用在音频播放器处于错误状态时执行操作，系统可能会抛出异常或生成其他未定义的行为。

**图1** 音频渲染状态机

![](figures/audio-renderer-state.png)

### 异步操作

为保证UI线程不被阻塞，大部分AudioRenderer调用都是异步的。对于每个API均提供了callback函数和Promise函数，以下示例均采用Promise函数，更多方式可参考[音频管理API文档AudioRenderer](../reference/apis/js-apis-audio.md#audiorenderer8)。

## 开发步骤

1. 使用createAudioRenderer()创建一个AudioRenderer实例。
   在audioCapturerOptions中设置相关参数。该实例可用于音频渲染、控制和获取采集状态，以及注册通知回调。

   ```js
    var audioStreamInfo = {
        samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
        channels: audio.AudioChannel.CHANNEL_1,
        sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
        encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
    }
   
    var audioRendererInfo = {
        content: audio.ContentType.CONTENT_TYPE_SPEECH,
        usage: audio.StreamUsage.STREAM_USAGE_VOICE_COMMUNICATION,
        rendererFlags: 1
    }
   
    var audioRendererOptions = {
        streamInfo: audioStreamInfo,
        rendererInfo: audioRendererInfo
    }
   
    let audioRenderer = await audio.createAudioRenderer(audioRendererOptions);
   ```

2. 使用on('interrupt')方法订阅音频中断事件。

   当优先级更高或相等的Stream-B请求激活并使用输出设备时，Stream-A被中断。

   在某些情况下，框架会采取暂停播放、降低音量等强制操作，并通过InterruptEvent通知应用。在其他情况下，应用可以自行对InterruptEvent做出响应。

   在音频中断的情况下，应用可能会碰到音频数据写入失败的问题。所以建议不感知、不处理中断的应用在写入音频数据前，使用audioRenderer.state检查播放器状态。而订阅音频中断事件，可以获取到更多详细信息，具体可参考[InterruptEvent](../reference/apis/js-apis-audio.md#interruptevent9)。
   
   ```js
    audioRenderer.on('interrupt', (interruptEvent) => {
        console.info('InterruptEvent Received');
        console.info('InterruptType: ' + interruptEvent.eventType);
        console.info('InterruptForceType: ' + interruptEvent.forceType);
        console.info('AInterruptHint: ' + interruptEvent.hintType);
   
        if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_FORCE) {
            switch (interruptEvent.hintType) {
                // Force Pause: Action was taken by framework.
                // Halt the write calls to avoid data loss.
                case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
                    isPlay = false;
                    break;
                // Force Stop: Action was taken by framework.
                // Halt the write calls to avoid data loss.
                case audio.InterruptHint.INTERRUPT_HINT_STOP:
                    isPlay = false;
                    break;
                // Force Duck: Action was taken by framework,
                // just notifying the app that volume has been reduced.
                case audio.InterruptHint.INTERRUPT_HINT_DUCK:
                    break;
                // Force Unduck: Action was taken by framework,
                // just notifying the app that volume has been restored.
                case audio.InterruptHint.INTERRUPT_HINT_UNDUCK:
                    break;
            }
        } else if (interruptEvent.forceType == audio.InterruptForceType.INTERRUPT_SHARE) {
            switch (interruptEvent.hintType) {
                // Share Resume: Action is to be taken by App.
                // Resume the force paused stream if required.
                case audio.InterruptHint.INTERRUPT_HINT_RESUME:
                    startRenderer();
                    break;
                // Share Pause: Stream has been interrupted,
                // It can choose to pause or play concurrently.
                case audio.InterruptHint.INTERRUPT_HINT_PAUSE:
                    isPlay = false;
                    pauseRenderer();
                    break;
            }
        }
    });
   ```

3. 调用start()方法来启动/恢复播放任务。
   
   启动完成后，渲染器状态将变更为STATE_RUNNING，然后应用可以开始读取缓冲区。

   ```js
    async function startRenderer() {
        var state = audioRenderer.state;
        // state should be prepared, paused or stopped.
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

4. 调用write()方法向缓冲区写入数据。

   将需要播放的音频数据读入缓冲区，重复调用write()方法写入。

   ```js
    async function writeBuffer(buf) {
        var state = audioRenderer.state;
        if (state != audio.AudioState.STATE_RUNNING) {
            console.error('Renderer is not running, do not write');
            isPlay = false;
            return;
        }
        let writtenbytes = await audioRenderer.write(buf);
   
        console.info('Actual written bytes: ' + writtenbytes);
        if (writtenbytes < 0) {
            console.error('Write buffer failed. check the state of renderer');
        }
    }
   
    // Reasonable minimum buffer size for renderer. However, the renderer can accept other read sizes as well.
    const bufferSize = await audioRenderer.getBufferSize();
    const path = '/data/file_example_WAV_2MG.wav';
    let ss = fileio.createStreamSync(path, 'r');
    const totalSize = 2146166; // file_example_WAV_2MG.wav
    let rlen = 0;
    let discardHeader = new ArrayBuffer(44);
    ss.readSync(discardHeader);
    rlen += 44;
   
    var id = setInterval(() =>  {
        if (isPlay || isRelease) {
            if (rlen >= totalSize || isRelease) {
                ss.closeSync();
                stopRenderer();
                clearInterval(id);
            }
            let buf = new ArrayBuffer(bufferSize);
            rlen += ss.readSync(buf);
            console.info('Total bytes read from file: ' + rlen);
            writeBuffer(buf);
        } else {
            console.info('check after next interval');
        }
    } , 30); // interval to be set based on audio file format
   ```

5. （可选）调用pause()方法或stop()方法暂停/停止渲染音频数据。

   ```js
    async function pauseRenderer() {
        var state = audioRenderer.state;
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
        var state = audioRenderer.state;
        if (state != audio.AudioState.STATE_RUNNING || state != audio.AudioState.STATE_PAUSED) {
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

6. 任务完成，调用release()方法释放相关资源。

   AudioRenderer会使用大量的系统资源，所以请确保完成相关任务后，进行资源释放。

   ```js
    async function releaseRenderer() {
        if (state_ == RELEASED || state_ == NEW) {
            console.info('Resourced already released');
            return;
        }

        await audioRenderer.release();

        state = audioRenderer.state;
        if (state == STATE_RELEASED) {
            console.info('Renderer released');
        } else {
            console.info('Renderer release failed');
        }

    }
   ```