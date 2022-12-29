# Audio Capture Development

## Introduction

You can use the APIs provided by **AudioCapturer** to record raw audio files, thereby implementing audio data collection.

**Status check**: During application development, you are advised to use **on('stateChange')** to subscribe to state changes of the **AudioCapturer** instance. This is because some operations can be performed only when the audio capturer is in a given state. If the application performs an operation when the audio capturer is not in the given state, the system may throw an exception or generate other undefined behavior.

## Working Principles

This following figure shows the audio capturer state transitions.

**Figure 1** Audio capturer state transitions

![audio-capturer-state](figures/audio-capturer-state.png)

- **PREPARED**: The audio capturer enters this state by calling **create()**.
- **RUNNING**: The audio capturer enters this state by calling **start()** when it is in the **PREPARED** state or by calling **start()** when it is in the **STOPPED** state.
- **STOPPED**: The audio capturer in the **RUNNING** state can call **stop()** to stop playing audio data.
- **RELEASED**: The audio capturer in the **PREPARED** or **STOPPED** state can use **release()** to release all occupied hardware and software resources. It will not transit to any other state after it enters the **RELEASED** state.

## Constraints

Before developing the audio data collection feature, configure the **ohos.permission.MICROPHONE** permission for your application. For details about permission configuration, see [Permission Application Guide](../security/accesstoken-guidelines.md).

## How to Develop

For details about the APIs, see [AudioCapturer in Audio Management](../reference/apis/js-apis-audio.md#audiocapturer8).

1. Use **createAudioCapturer()** to create an **AudioCapturer** instance.

   Set parameters of the **AudioCapturer** instance in **audioCapturerOptions**. This instance is used to capture audio, control and obtain the recording state, and register a callback for notification.

   ```js
   import audio from '@ohos.multimedia.audio';

   let audioStreamInfo = {
     samplingRate: audio.AudioSamplingRate.SAMPLE_RATE_44100,
     channels: audio.AudioChannel.CHANNEL_1,
     sampleFormat: audio.AudioSampleFormat.SAMPLE_FORMAT_S16LE,
     encodingType: audio.AudioEncodingType.ENCODING_TYPE_RAW
   }
   
   let audioCapturerInfo = {
     source: audio.SourceType.SOURCE_TYPE_MIC,
     capturerFlags: 0 // 0 is the extended flag bit of the audio capturer. The default value is 0.
   }
   
   let audioCapturerOptions = {
     streamInfo: audioStreamInfo,
     capturerInfo: audioCapturerInfo
   }
   
   let audioCapturer = await audio.createAudioCapturer(audioCapturerOptions);
   console.log('AudioRecLog: Create audio capturer success.');
   ```

2. Use **start()** to start audio recording.

   The capturer state will be **STATE_RUNNING** once the audio capturer is started. The application can then begin reading buffers.

   ```js
   import audio from '@ohos.multimedia.audio';

   async function startCapturer() {
     let state = audioCapturer.state;
     // The audio capturer should be in the STATE_PREPARED, STATE_PAUSED, or STATE_STOPPED state after being started.
     if (state != audio.AudioState.STATE_PREPARED || state != audio.AudioState.STATE_PAUSED ||
       state != audio.AudioState.STATE_STOPPED) {
       console.info('Capturer is not in a correct state to start');
       return;
     }
     await audioCapturer.start();

     let state = audioCapturer.state;
     if (state == audio.AudioState.STATE_RUNNING) {
       console.info('AudioRecLog: Capturer started');
     } else {
       console.error('AudioRecLog: Capturer start failed');
     }
   }
   ```

3. Read the captured audio data and convert it to a byte stream. Call **read()** repeatedly to read the data until the application stops the recording.  

   The following example shows how to write recorded data into a file.

   ```js
   import fileio from '@ohos.fileio';

    let state = audioCapturer.state;
    // The read operation can be performed only when the state is STATE_RUNNING.
    if (state != audio.AudioState.STATE_RUNNING) {
      console.info('Capturer is not in a correct state to read');
      return;
    }
      
   const path = '/data/data/.pulse_dir/capture_js.wav'; // Path for storing the collected audio file.
   let fd = fileio.openSync(path, 0o102, 0o777);
   if (fd !== null) {
     console.info('AudioRecLog: file fd created');
   }
   else{
     console.info('AudioRecLog: file fd create : FAILED');
     return;
   }
      
   fd = fileio.openSync(path, 0o2002, 0o666);
   if (fd !== null) {
     console.info('AudioRecLog: file fd opened in append mode');
   }
      
   let numBuffersToCapture = 150; // Write data for 150 times.
   while (numBuffersToCapture) {
     let buffer = await audioCapturer.read(bufferSize, true);
     if (typeof(buffer) == undefined) {
       console.info('AudioRecLog: read buffer failed');
     } else {
       let number = fileio.writeSync(fd, buffer);
       console.info(`AudioRecLog: data written: ${number}`);
     }
      
     numBuffersToCapture--;
   }
   ```

4. Once the recording is complete, call **stop()** to stop the recording.

   ```js
    async function StopCapturer() {
      let state = audioCapturer.state;
      // The audio capturer can be stopped only when it is in STATE_RUNNING or STATE_PAUSED state.
      if (state != audio.AudioState.STATE_RUNNING && state != audio.AudioState.STATE_PAUSED) {
        console.info('AudioRecLog: Capturer is not running or paused');
        return;
      }

      await audioCapturer.stop();

      state = audioCapturer.state;
      if (state == audio.AudioState.STATE_STOPPED) {
        console.info('AudioRecLog: Capturer stopped');
      } else {
        console.error('AudioRecLog: Capturer stop failed');
      }
    }
   ```

5. After the task is complete, call **release()** to release related resources.

   ```js
    async function releaseCapturer() {
      let state = audioCapturer.state;
      // The audio capturer can be released only when it is not in the STATE_RELEASED or STATE_NEW state.
      if (state == audio.AudioState.STATE_RELEASED || state == audio.AudioState.STATE_NEW) {
        console.info('AudioRecLog: Capturer already released');
        return;
      }

      await audioCapturer.release();

      state = audioCapturer.state;
      if (state == audio.AudioState.STATE_RELEASED) {
        console.info('AudioRecLog: Capturer released');
      } else {
        console.info('AudioRecLog: Capturer release failed');
      }
    }
   ```

6. (Optional) Obtain the audio capturer information.
   
   You can use the following code to obtain the audio capturer information:

   ```js
   // Obtain the audio capturer state.
   let state = audioCapturer.state;
   
   // Obtain the audio capturer information.
   let audioCapturerInfo : audio.AuduioCapturerInfo = await audioCapturer.getCapturerInfo();

   // Obtain the audio stream information.
   let audioStreamInfo : audio.AudioStreamInfo = await audioCapturer.getStreamInfo();

   // Obtain the audio stream ID.
   let audioStreamId : number = await audioCapturer.getAudioStreamId();

   // Obtain the Unix timestamp, in nanoseconds.
   let audioTime : number = await audioCapturer.getAudioTime();

   // Obtain a proper minimum buffer size.
   let bufferSize : number = await audioCapturer.getBuffersize();
   ```

7. (Optional) Use **on('markReach')** to subscribe to the mark reached event, and use **off('markReach')** to unsubscribe from the event.

    After the mark reached event is subscribed to, when the number of frames collected by the audio capturer reaches the specified value, a callback is triggered and the specified value is returned.
   
    ```js
    audioCapturer.on('markReach', (reachNumber) => {
      console.info('Mark reach event Received');
      console.info(`The Capturer reached frame: ${reachNumber}`);
    });

    audioCapturer.off('markReach'); // Unsubscribe from the mark reached event. This event will no longer be listened for.
    ```

8. (Optional) Use **on('periodReach')** to subscribe to the period reached event, and use **off('periodReach')** to unsubscribe from the event.

    After the period reached event is subscribed to, each time the number of frames collected by the audio capturer reaches the specified value, a callback is triggered and the specified value is returned.
   
    ```js
    audioCapturer.on('periodReach', (reachNumber) => {
      console.info('Period reach event Received');
      console.info(`In this period, the Capturer reached frame: ${reachNumber}`);
    });

    audioCapturer.off('periodReach'); // Unsubscribe from the period reached event. This event will no longer be listened for.
    ```

9. If your application needs to perform some operations when the audio capturer state is updated, it can subscribe to the state change event. When the audio capturer state is updated, the application receives a callback containing the event type.

    ```js
    audioCapturer.on('stateChange', (state) => {
      console.info(`AudioCapturerLog: Changed State to : ${state}`)
      switch (state) {
        case audio.AudioState.STATE_PREPARED:
          console.info('--------CHANGE IN AUDIO STATE----------PREPARED--------------');
          console.info('Audio State is : Prepared');
          break;
        case audio.AudioState.STATE_RUNNING:
          console.info('--------CHANGE IN AUDIO STATE----------RUNNING--------------');
          console.info('Audio State is : Running');
          break;
        case audio.AudioState.STATE_STOPPED:
          console.info('--------CHANGE IN AUDIO STATE----------STOPPED--------------');
          console.info('Audio State is : stopped');
          break;
        case audio.AudioState.STATE_RELEASED:
          console.info('--------CHANGE IN AUDIO STATE----------RELEASED--------------');
          console.info('Audio State is : released');
          break;
        default:
          console.info('--------CHANGE IN AUDIO STATE----------INVALID--------------');
          console.info('Audio State is : invalid');
          break;
      }
    });
    ```
