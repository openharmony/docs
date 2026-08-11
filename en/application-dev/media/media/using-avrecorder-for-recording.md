# Using AVRecorder to Record Audio (ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

In this topic, you will learn how to use [AVRecorder](media-kit-intro.md#avrecorder) to develop audio recording functionalities including starting, pausing, resuming, and stopping recording.

During application development, you can use the **state** property of AVRecorder to obtain its current state or use [on('stateChange')](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#onstatechange9) to listen for state change events. During development, you must strictly comply with the state machine requirements. For example, you can call the [pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1) API only in the **started** state and call the [resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1) API only in the **paused** state.

**Figure 1** Recording state transition

![Recording status change](figures/audio-recording-status-change.png)

For details about the states, see [AVRecorderState](../../reference/apis-media-kit/arkts-apis-media-t.md#avrecorderstate9).

## Requesting Permissions

Before your development, configure the following permissions for your application.

- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
- To read and save audio files, preferentially use [AudioViewPicker](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker).

> **NOTE**
>
> To clone, back up, or synchronize audio files in users' public directory, request the ohos.permission.READ_AUDIO and ohos.permission.WRITE_AUDIO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## Precautions for Developing Audio Recording Applications

- If continuous recording or background recording is required, the application must request a continuous task to prevent it from being suspended. For details, see [Continuous Task](../../task-management/continuous-task.md).
- The application must start recording when it runs in the foreground. It can switch to the background after the recording is started. Recording cannot be started in the background.
- To record audio, the application must use an appropriate recording stream type. For details, see [Selecting the Appropriate Audio Stream Types](../audio/using-right-streamusage-and-sourcetype.md).
- To switch the input device route when recording audio, see [Switching Audio Input Devices](../audio/audio-input-device-switcher.md).

## How to Develop

For details about the APIs, see [AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md).

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   > **NOTE**
   >
   > Perform the subsequent operations after the AVRecorder completes value assignment.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private avRecorder: media.AVRecorder | undefined = undefined;

   try {
     this.avRecorder = await media.createAVRecorder();
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to create avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

2. Set the events to listen for.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** property of the AVRecorder.|
   | error | Mandatory; used to listen for AVRecorder errors.|

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   // Callback function for state changes.
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
     // You can add the action to be performed after the state is switched.
   });

   // Callback function for errors.
   this.avRecorder?.on('error', (error) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. Set audio recording parameters and call [prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1) to enter the **prepared** state.

   > **NOTE**
   > Pay attention to the following when configuring parameters:
   >
   > - Before parameter configuration, ensure that you have gained the required permissions. For details, see [Requesting Permissions](#requesting-permissions).
   >
   > - In pure audio recording scenarios, set only audio-related parameters in **avConfig** of **prepare()**.
   >   If video recording is required, follow the instructions provided in [Video Recording Development](video-recording.md). If video-related parameters are configured, an error will be reported in subsequent steps.
   > - The [recording specifications](media-kit-intro.md#supported-formats) in use must be those supported. The specific recording parameters must strictly comply with the specified [recording parameter configuration](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9).
   > - The recording output URL (URL in **avConfig** in the sample code) must be in the format of fd://xx (where xx indicates a file descriptor). You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Accessing Application Files](../../file-management/app-file-access.md).
   > - For details about the audio encoding format (**audioCodec**), extended audio encoding format (**aacProfile**), and encapsulation format (**fileFormat**) configured in the example, see [AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9).

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo } from '@kit.CoreFileKit';

   let avProfile: media.AVRecorderProfile = {
     audioBitrate: 112000, // Audio bit rate.
     audioChannels: 2, // Number of audio channels.
     audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
     aacProfile: media.AacProfile.AAC_HE, // Extended audio encoding format.
     audioSampleRate: 48000, // Audio sampling rate.
     fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // Encapsulation format.
   };
   
   const context: Context = this.getUIContext().getHostContext()!; // Refer to Accessing Application Files.
   let filePath: string = context.filesDir + '/example.mp3';
   let audioFile: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
   let fileFd: number = audioFile.fd; // Obtain the file FD.
    
   let avConfig: media.AVRecorderConfig = {
     audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // Audio input source. In this example, the microphone is used.
     profile: avProfile,
     url: 'fd://' + fileFd.toString(), // Obtain the file descriptor of the created audio file by referring to the sample code in Application File Access and Management.
   };
  
   try {
     await this.avRecorder?.prepare(avConfig);
     console.info('Succeeded in preparing avRecorder');
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to prepare avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

4. Call [start](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#start9-1) to start recording and enter the **started** state.

   ```ts
   // Start recording.
   await this.avRecorder?.start();
   ```

5. Call [pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1) to pause recording and enter the **paused** state.

   ```ts
   // Pause recording.
   await this.avRecorder?.pause();
   ```

6. Call [resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1) to resume recording and enter the **started** state again.

   ```ts
   // Resume recording.
   await this.avRecorder?.resume();
   ```

7. Call [stop](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#stop9-1) to stop recording and enter the **stopped** state.

   ```ts
   // Stop recording.
   await this.avRecorder?.stop();
   ```

8. Call [reset](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#reset9-1) to reset resources. The AVRecorder enters the **idle** state and recording parameters can be configured again.

   ```ts
   // Reset resources.
   await this.avRecorder?.reset();
   ```

9. Call [release](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#release9-1) to release the instance, enter the **released** state, and exit recording.

   ```ts
   // Destroy the instance.
   await this.avRecorder?.release();
   ```

## Complete Sample Code

  Refer to the sample code below to complete the process of starting, pausing, resuming, and stopping recording.

  Before using the sample code, you need to apply for the ohos.permission.MICROPHONE microphone permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

```ts
import { common } from '@kit.AbilityKit';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo } from '@kit.CoreFileKit';

async function audioRecording(context: common.Context): Promise<void> {
  // Create an AVRecorder instance named avRecorder.
  let avRecorder: media.AVRecorder | undefined = undefined;
  try {
    avRecorder = await media.createAVRecorder();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create avRecorder, error code: ${err.code}, message: ${err.message}`);
    return;
  }
  
  // Set AVRecorder callback functions.
  try {
    // Callback for state changes.
    avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
      console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
    });
    // Callback function for errors.
    avRecorder.on('error', (error: BusinessError) => {
      console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to set avRecorder callback, error code: ${err.code}, message: ${err.message}`);
  }

  let avProfile: media.AVRecorderProfile = {
    audioBitrate: 112000, // Audio bit rate.
    audioChannels: 2, // Number of audio channels.
    audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
    aacProfile: media.AacProfile.AAC_HE, // Extended audio encoding format.
    audioSampleRate: 48000, // Audio sampling rate.
    fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // Encapsulation format.
  };
  let avConfig: media.AVRecorderConfig = {
    audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // Audio input source. In this example, the microphone is used.
    profile: avProfile,
    url: 'fd://35', // Create, read, and write a file by referring to the sample code in Application File Access and Management.
  };

  // Create a file and set avConfig.url.
  let audioFile: fileIo.File | undefined = undefined;
  try {
    let path: string = context.filesDir + '/example.mp3'; // File sandbox path. The file name extension must match the container format.
    audioFile = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE); // Open the file.
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open file, error code: ${err.code}, message: ${err.message}`);
  }
  if (audioFile) {
    avConfig.url = 'fd://' + audioFile.fd; // Update the URL.
  }
  
  // Set recording parameters to complete the preparations.
  try {
    if (avRecorder.state === 'idle' || avRecorder.state === 'stopped') { // prepare() can be called only when the AVRecorder is in the idle or stopped state.
      await avRecorder.prepare(avConfig);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Start recording.
  try {
    if (avRecorder.state === 'prepared') { // start() can be called only when the AVRecorder is in the prepared state.
      await avRecorder.start();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to start avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Pause recording.
  try {
    if (avRecorder.state === 'started') { // pause() can be called only when the AVRecorder is in the started state.
      await avRecorder.pause();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Resume recording.
  try {
    if (avRecorder.state === 'paused') { // resume() can be called only when the AVRecorder is in the paused state.
      await avRecorder.resume();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to resume avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Stop recording.
  try {
    if (avRecorder.state === 'started' || avRecorder.state === 'paused') { // stop() can be called only when the AVRecorder is in the started or paused state.
      await avRecorder.stop();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to stop avRecorder, error code: ${err.code}, message: ${err.message}`);
  }
  
  // Reset recording.
  try {
    await avRecorder.reset();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to reset avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Release the AVRecorder instance.
  try {
    await avRecorder.release();
    avRecorder = undefined;
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to release avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Close the file descriptor of the recording file.
  try {
    if (audioFile) {
      await fileIo.close(audioFile.fd);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
  }
}
```
