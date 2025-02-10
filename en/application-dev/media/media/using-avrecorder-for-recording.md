# Using AVRecorder to Record Audio (ArkTS)

In this topic, you will learn how to use the [AVRecorder](media-kit-intro.md#avrecorder) to develop audio recording functionalities including starting, pausing, resuming, and stopping recording.

During application development, you can use the **state** attribute of the AVRecorder to obtain the AVRecorder state or call **on('stateChange')** to listen for state changes. Your code must meet the state machine requirements. For example, **pause()** is called only when the AVRecorder is in the **started** state, and **resume()** is called only when it is in the **paused** state.

**Figure 1** Recording state transition

![Recording state change](figures/recording-status-change.png)

For details about the state, see [AVRecorderState](../../reference/apis-media-kit/js-apis-media.md#avrecorderstate9).

## Requesting Permissions

Before your development, configure the following permissions for your application.
- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
- To read and save audio files, preferentially use [AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker).

> **NOTE**
>
> When the application needs to clone, back up, or synchronize audio files in users' public directory, request the ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.


## How to Develop

Read [AVRecorder](../../reference/apis-media-kit/js-apis-media.md#avrecorder9) for the API reference.

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   > **NOTE**
   >
   > Perform the subsequent operations after the AVRecorder completes value assignment, that is, after **avRecorder = recorder;** is executed.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let avRecorder: media.AVRecorder;
   media.createAVRecorder().then((recorder: media.AVRecorder) => {
     avRecorder = recorder;
   }, (error: BusinessError) => {
     console.error(`createAVRecorder failed`);
   })
   ```

2. Set the events to listen for.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** attribute of the AVRecorder.|
   | error | Mandatory; used to listen for AVRecorder errors.|

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   // Callback function for state changes.
   avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.log(`current state is ${state}`);
     // You can add the action to be performed after the state is switched.
   })

   // Callback function for errors.
   avRecorder.on('error', (err: BusinessError) => {
     console.error(`avRecorder failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

3. Set audio recording parameters and call **prepare()**. The AVRecorder enters the **prepared** state.

   > **NOTE**
   > Pay attention to the following when configuring parameters:
   >
   > - Before parameter configuration, ensure that you have gained the required permissions. For details, see [Requesting Permissions](#requesting-permissions).
   >
   > - In pure audio recording scenarios, set only audio-related parameters in **avConfig** of **prepare()**. If video-related parameters are configured, an error will be reported in subsequent steps. If video recording is required, follow the instructions provided in [Video Recording Development](video-recording.md).
   > - The [recording formats](media-kit-intro.md#supported-formats) in use must be those supported by the system.
   > - The recording output URL (URL in **avConfig** in the sample code) must be in the format of fd://xx (where xx indicates a file descriptor). You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Application File Access and Management](../../file-management/app-file-access.md).

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let avProfile: media.AVRecorderProfile = {
     audioBitrate: 100000, // Audio bit rate.
     audioChannels: 2, // Number of audio channels.
     audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format. Currently, ACC, MP3, and G711MU are supported.
     audioSampleRate: 48000, // Audio sampling rate.
     fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // Container format. Currently, MP4, M4A, MP3, and WAV are supported.
   };
   
   const context: Context = getContext(this); // Refer to Application File Access and Management.
   let filePath: string = context.filesDir + '/example.mp3';
   let audioFile: fs.File = fs.openSync(filePath, OpenMode.READ_WRITE | OpenMode.CREATE);
   let fileFd = this.audioFile.fd; // Obtain the file FD.
    
   let avConfig: media.AVRecorderConfig = {
     audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // Audio input source. In this example, the microphone is used.
     profile: avProfile,
     url: 'fd://' + fileFd.toString(), // Obtain the file descriptor of the created audio file by referring to the sample code in Application File Access and Management.
   };
    
   avRecorder.prepare(avConfig).then(() => {
     console.log('Invoke prepare succeeded.');
   }, (err: BusinessError) => {
     console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

4. Call **start()** to start recording. The AVRecorder enters the **started** state.

   ```ts
   // Start recording.
   avRecorder.start();
   ```

5. Call **pause()** to pause recording. The AVRecorder enters the **paused** state.

   ```ts
   // Pause recording.
   avRecorder.pause();
   ```

6. Call **resume()** to resume recording. The AVRecorder enters the **started** state again.

   ```ts
   // Resume recording.
   avRecorder.resume();
   ```

7. Call **stop()** to stop recording. The AVRecorder enters the **stopped** state.

   ```ts
   // Stop recording.
   avRecorder.stop();
   ```

8. Call **reset()** to reset the resources. The AVRecorder enters the **idle** state. In this case, you can reconfigure the recording parameters.

   ```ts
   // Reset resources.
   avRecorder.reset();
   ```

9. Call **release()** to switch the AVRecorder to the **released** state. Now your application exits the recording.

   ```ts
   // Destroy the instance.
   avRecorder.release();
   ```

## Sample Code

Refer to the sample code below to complete the process of starting, pausing, resuming, and stopping recording.

```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';

export class AudioRecorderDemo {
  private avRecorder: media.AVRecorder | undefined = undefined;
  private avProfile: media.AVRecorderProfile = {
    audioBitrate: 100000, // Audio bit rate.
    audioChannels: 2, // Number of audio channels.
    audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format. Currently, ACC, MP3, and G711MU are supported.
    audioSampleRate: 48000, // Audio sampling rate.
    fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // Container format. Currently, MP4, M4A, MP3, and WAV are supported.
  };
  private avConfig: media.AVRecorderConfig = {
    audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // Audio input source. In this example, the microphone is used.
    profile: this.avProfile,
    url: 'fd://35', // Create, read, and write a file by referring to the sample code in Application File Access and Management.
  };
  private uriPath: string = '';
  private filePath: string = '';
  
  // Create a file and set avConfig.url.
  async createAndSetFd(): Promise<void> {
      const context: Context = getContext(this);
      const path: string = context.filesDir + '/example.mp3'; // File sandbox path. The file name extension must match the container format.
      const audioFile: fs.File = fs.openSync(path, OpenMode.READ_WRITE | OpenMode.CREATE);
      this.avConfig.url = 'fd://' + audioFile.fd; // Update the URL.
      this.filePath = path;
  }

  // Set AVRecorder callback functions.
  setAudioRecorderCallback() {
    if (this.avRecorder != undefined) {
      // Callback function for state changes.
      this.avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
        console.log(`AudioRecorder current state is ${state}`);
      })
      // Callback function for errors.
      this.avRecorder.on('error', (err: BusinessError) => {
        console.error(`AudioRecorder failed, code is ${err.code}, message is ${err.message}`);
      })
    }
  }

  // Process of starting recording.
  async startRecordingProcess() {
    if (this.avRecorder != undefined) {
      await this.avRecorder.release();
      this.avRecorder = undefined;
    }
    // 1. Create an AVRecorder instance.
    this.avRecorder = await media.createAVRecorder();
    this.setAudioRecorderCallback();
    // 2. Obtain the file descriptor of the recording file and assign it to the URL in avConfig. For details, see FilePicker.

    // 3. Set recording parameters to complete the preparations.
    await this.avRecorder.prepare(this.avConfig);
    // 4. Start recording.
    await this.avRecorder.start();
  }

  // Process of pausing recording.
  async pauseRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'started') { // pause() can be called only when the AVRecorder is in the started state .
      await this.avRecorder.pause();
    }
  }

  // Process of resuming recording.
  async resumeRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'paused') { // resume() can be called only when the AVRecorder is in the paused state .
      await this.avRecorder.resume();
    }
  }

  // Process of stopping recording.
  async stopRecordingProcess() {
    if (this.avRecorder != undefined) {
      // 1. Stop recording.
      if (this.avRecorder.state === 'started'
        || this.avRecorder.state ==='paused') { // stop() can be called only when the AVRecorder is in the started or paused state.
        await this.avRecorder.stop();
      }
      // 2. Reset the AVRecorder.
      await this.avRecorder.reset();
      // 3. Release the AVRecorder instance.
      await this.avRecorder.release();
      this.avRecorder = undefined;
      // 4. Close the file descriptor of the recording file.
    }
  }

  // Complete sample code for starting, pausing, resuming, and stopping recording.
  async audioRecorderDemo() {
    await this.startRecordingProcess(); // Start recording.
    // You can set the recording duration. For example, you can set the sleep mode to prevent code execution.
    await this.pauseRecordingProcess(); // Pause recording.
    await this.resumeRecordingProcess(); // Resume recording.
    await this.stopRecordingProcess(); // Stop recording.
  }
}
```
