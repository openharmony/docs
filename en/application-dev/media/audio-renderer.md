# Audio Rendering Development

---
## ***Note***:
    1. This document applies to JavaScript.
---
## **Summary**
This guide will show you how to use AudioRenderer to create an audio player app.
You can use the APIs provided in this document to play audio files in output devices and manage playback tasks.

## **AudioRenderer Framework**
The AudioRenderer interface is one of the most important components of the audio framework.
### **Audio Rendering:**
The AudioRenderer framework provides APIs for playing audio files and controlling the playback.
### **Audio Interruption:**
When a higher priority stream wants to play, the AudioRenderer framework interrupts the lower priority stream.\
For example, if a call is arrived when you listen to music, the music playback, which is the lower priority stream, is paused.\
With the sample code below, we'll look at how AudioInterrupt works in detail.\
<br/>
Please see [AudioRenderer in the Audio API](../reference/apis/js-apis-audio.md#audiorenderer8) for a list of supported audio stream types and formats, such as AudioSampleFormat, AudioChannel, AudioSampleFormat, and AudioEncodingType.


## **Usage**
Here's an example of how to use AudioRenderer to play a raw audio file.
1. Use **createAudioRenderer** to create an AudioRenderer instance. Renderer parameters can be set in **audioRendererOptions**.\
   This object can be used to play, control, and obtain the status of the playback, as well as receive callback notifications.
   ```
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

2. Subscribe to audio interruption events using the **on** API.\
   Stream-A is interrupted when Stream-B with a higher or equal priority requests to become active and use the output device.\
   In some cases, the framework takes forced actions like pausing and ducking, and notifies the app using **InterruptEvent**. In other cases, the app can take action. In this situation, the app can choose to act on the **InterruptEvent** or ignore it. When the app is interrupted by forced action, it should handle the state, update the user interface, and so on.

   In case of audio interrupts, the app may encounter write failures. Interrupt unaware apps can check the renderer state using the **audioRenderer.state** API before writing audio data, whereas interrupt aware apps will have more details accessible via this listener.\
   <br/>
   The following information will be provided by the Interrupt Event Notification:

    1) **eventType:** Whether the interruption has begun or ended.

       | Value                | Description                                   |
       | :------------------- | :-------------------------------------------- |
       | INTERRUPT_TYPE_BEGIN | Indicates that the interruption has started.  |
       | INTERRUPT_TYPE_END   | Indicates that the interruption has finished. |

    2) **forceType:** Whether the framework has already taken action or if the app is being suggested to take action.

       | Value           | Description                                                         |
       | :-------------- | :------------------------------------------------------------------ |
       | INTERRUPT_FORCE | The audio state has been changed by the framework.                  |
       | INTERRUPT_SHARE | The app can decide whether or not to respond to the InterruptEvent. |

    3) **hintType:** The kind of action taken or to be taken.

       | Value                 | Description                  |
       | :-------------------- | :--------------------------- |
       | INTERRUPT_HINT_PAUSE  | Pausing the playback.        |
       | INTERRUPT_HINT_RESUME | Resuming the playback.       |
       | INTERRUPT_HINT_STOP   | Stopping the playback.       |
       | INTERRUPT_HINT_DUCK   | Ducking the stream volume.   |
       | INTERRUPT_HINT_UNDUCK | Unducking the stream volume. |

    4) **Some actions are exclusively forced or shared**, which means that they are performed by either the framework or the app.\
       For instance, when a call is received while a music stream is ongoing, the framework forces the music stream to pause. When the call is finished, the framework will not forcibly resume the music stream. Instead, it will alert the app to resume the playback.

       | Action                | Description                                                                       |
       | :-------------------- | :-------------------------------------------------------------------------------- |
       | INTERRUPT_HINT_RESUME | INTERRUPT_SHARE is always the forceType. It can only be done by the app.     |
       | INTERRUPT_HINT_DUCK   | INTERRUPT_FORCE is always the forceType. It will always be done by the framework. |
       | INTERRUPT_HINT_UNDUCK | INTERRUPT_FORCE is always the forceType. It will always be done by the framework. |

   ```
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

4. Call the **start()** function on the AudioRenderer instance to start/resume the playback task.\
   The renderer state will be STATE_RUNNING once the start is complete. You can then begin writing buffers.
   ```
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
5. Make **write** calls to start rendering the buffers.
   Read the audio data to be played into a buffer. Call the write function repeatedly to write data.
   ```
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

6. (Optional) Call the **pause()** or **stop()** function on the AudioRenderer instance.
```
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

7. After the playback task is complete, call the **release()** function on the AudioRenderer instance to release resources.\
   AudioRenderer can use a lot of system resources. As a result, whenever the resources are no longer required, they must be released. To ensure that any system resources allocated to it are appropriately released, you should always call **release()**.
```
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

## **Importance of State Check:**
You should also keep in mind that an AudioRenderer is state-based.
That is, the AudioRenderer has an internal state that you must always check when calling playback control APIs, because some operations are only acceptable while the renderer is in a given state.\
The system may throw an error/exception or generate other undefined behaviour if you perform an operation while in the improper state.\

## **Asynchronous Operations:**
Most of the AudioRenderer calls are asynchronous. As a result, the UI thread will not be blocked.\
For each API, the framework provides both callback and promises functions.\
In the example, promise functions are used for simplicity. [AudioRender in the Audio API](../reference/apis/js-apis-audio.md#audiorenderer8)
provides reference for both callback and promise.

## **Other APIs:**
See [Audio](../reference/apis/js-apis-audio.md) for more useful APIs like getAudioTime, drain, and getBufferSize.
