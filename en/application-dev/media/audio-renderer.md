# Audio Rendering Development

## When to Use

**AudioRenderer** provides APIs for rendering audio files and controlling playback. It also supports audio interruption. You can use the APIs provided by **AudioRenderer** to play audio files in output devices and manage playback tasks.

### Audio Interruption

When an audio stream with a higher priority needs to be played, the audio renderer interrupts the stream with a lower priority. For example, if a call comes in when the user is listening to music, the music playback, which is the lower priority stream, is paused. For details, see [How to Develop](#how-to-develop).

### State Check

During application development, you are advised to use **on('stateChange')** to subscribe to state changes of the **AudioRenderer** instance. This is because some operations can be performed only when the audio renderer is in a given state. If the application performs an operation when the audio renderer is not in the given state, the system may throw an exception or generate other undefined behavior.

**Figure 1** Audio renderer state

![](figures/audio-renderer-state.png)

### Asynchronous Operations

To ensure that the UI thread is not blocked, most **AudioRenderer** calls are asynchronous. Each API provides the callback and promise functions. The following examples use the promise functions. For more information, see [AudioRenderer in Audio Management](../reference/apis/js-apis-audio.md#audiorenderer8).



## How to Develop

1. Use **createAudioRenderer()** to create an **AudioRenderer** instance.
   Set parameters of the audio renderer in **audioCapturerOptions**. This instance is used to render audio, control and obtain the rendering status, and register a callback for notification.

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

2. Use **on('interrupt')** to subscribe to audio interruption events.

   Stream-A is interrupted when Stream-B with a higher or equal priority requests to become active and use the output device.

   In some cases, the audio renderer performs forcible operations such as pausing and ducking, and notifies the application through **InterruptEvent**. In other cases, the application can choose to act on the **InterruptEvent** or ignore it.

   In the case of audio interruption, the application may encounter write failures. To avoid such failures, interruption unaware applications can use **audioRenderer.state** to check the renderer state before writing audio data. The applications can obtain more details by subscribing to the audio interruption events. For details, see [InterruptEvent](../reference/apis/js-apis-audio.md#interruptevent9).
   
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

3. Use **start()** to start audio rendering.
   
   The renderer state will be **STATE_RUNNING** once the audio renderer is started. The application can then begin reading buffers.

   ```js
    async function startRenderer() {
        var state = audioRenderer.state;
        // The state should be prepared, paused, or stopped.
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

4. Call **write()** to write data to the buffer.

   Read the audio data to be played to the buffer. Call **write()** repeatedly to write the data to the buffer.

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

5. (Optional) Call **pause()** or **stop()** to pause or stop rendering.

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

6. After the task is complete, call **release()** to release related resources.

   **AudioRenderer** uses a large number of system resources. Therefore, ensure that the resources are released after the task is complete.

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

   
