# Using AVTranscoder for Video Transcoding

This topic describes how to use AVTranscoder to implement video transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.

## How to Develop

Read [AVTranscoder](../../reference/apis-media-kit/js-apis-media.md#avtranscoder12) for the API reference.

1. Create an **avTranscoder** instance.

   > **NOTE**
   >
   > Perform the subsequent operations after the avTranscoder completes value assignment, that is, after **avTranscoder = transcoder;** is executed.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avTranscoder: media.AVTranscoder;
   media.createAVTranscoder().then((transcoder: media.AVTranscoder) => {
     avTranscoder = transcoder;
   }, (error: BusinessError) => {
     console.error(`createAVTranscoder failed`);
   })
   ```

2. Set the events to listen for.
   | Event Type| Description| 
   | -------- | -------- |
   | complete | Mandatory; used to listen for the completion of transcoding.| 
   | error | Mandatory; used to listen for AVTranscoder errors.|

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   
   // Callback function for the completion of transcoding.
   avTranscoder.on('complete', () => {
     console.log(`transcoder is completed`);
     // Listen for transcoding completion events.
   })
   
   // Callback function for errors.
   avTranscoder.on('error', (err: BusinessError) => {
     console.error(`avTranscoder failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

3. Set the **fdSrc** attribute.
   > **NOTE**
   >
   > The **fdSrc** value in the code snippet below is for reference only. You need to check the media asset validity and set **fdSrc** based on service requirements.
   > 
   > - If local files are used for transcoding, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   > 
   > - You can also use **ResourceManager.getRawFd** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).

   ```ts
   import resourceManager from '@ohos.resourceManager';

   let context = getContext(this) as common.UIAbilityContext;
   let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
   // Set fdSrc used for transcoding.
   this.avTranscoder.fdSrc = fileDescriptor;
   ```

4. Set the **fdDst** attribute.
   > **NOTE**
   >
   > - **fdDst** specifies the FD of the output file after transcoding. The value is a number. You must call [ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Application File Access and Management](../../file-management/app-file-access.md).
   
   ```ts
   // Set fdDst of the output file.
   this.avTranscoder.fdDst = 55 // Obtain the file descriptor of the created video file by referring to the sample code in Application File Access and Management.
   ```

5. Set video transcoding parameters and call **prepare()**.

   > **NOTE**
   > Pay attention to the following when configuring parameters:
   >
   > - Set only transcoding-related parameters in **avConfig** of **prepare()**.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avConfig: media.AVTranscoderConfig = {
     audioBitrate: 100000, // Audio bit rate.
     audioCodec: media.CodecMimeType.AUDIO_AAC,
     fileFormat: media.ContainerFormatType.CFT_MPEG_4A,
     videoBitrate: 2000000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC,
     videoFrameWidth: 640, // Video frame width.
     videoFrameHeight: 480, // Video frame height.
   }
   avTranscoder.prepare(avConfig).then(() => {
     console.log('Invoke prepare succeeded.');
   }, (err: BusinessError) => {
     console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
   })
   ```

6. Call **start()** to start transcoding.

   ```ts
   // Start transcoding.
   avTranscoder.start();
   ```

7. Call **pause()** to pause transcoding.

   ```ts
   // Pause transcoding.
   avTranscoder.pause();
   ```

8. Call **resume()** to resume transcoding.

   ```ts
   // Resume transcoding.
   avTranscoder.resume();
   ```

8. Call **cancel()** to cancel transcoding.

   ```ts
   // Cancel transcoding.
   avTranscoder.cancel();
   ```

9. Call **release()** to destroy the instance and exit transcoding.

   ```ts
   // Destroy the instance.
   avTranscoder.release();
   ```

## Sample Code

  Refer to the sample code below to implement transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.
  
```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

export class AVTranscoderDemo {
  private avTranscoder: media.AVTranscoder | undefined = undefined;
  private avConfig: media.AVTranscoderConfig = {
     audioBitrate: 100000, // Audio bit rate.
     audioCodec: media.CodecMimeType.AUDIO_AAC,
     fileFormat: media.ContainerFormatType.CFT_MPEG_4A,
     videoBitrate: 200000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC,
     videoFrameWidth: 640, // Video frame width.
     videoFrameHeight: 480, // Video frame height.
   }

  // Set AVTranscoder callback functions.
  setAVTranscoderCallback() {
    if (this.avTranscoder != undefined) {
      // Callback function for the completion of transcoding.
      this.avTranscoder.on('complete', async () => {
        console.log(`AVTranscoder is completed`);
        await this.releaseTranscoderingProcess();
      })
      // Callback function for errors.
      this.avTranscoder.on('error', (err: BusinessError) => {
        console.error(`AVTranscoder failed, code is ${err.code}, message is ${err.message}`);
      })
    }
  }

  // Process of starting transcoding.
  async startTranscoderingProcess() {
    if (this.avTranscoder != undefined) {
      await this.avTranscoder.release();
      this.avTranscoder = undefined;
    }
    // 1. Create an avTranscoder instance.
    this.avTranscoder = await media.createAVTranscoder();
    this.setAVTranscoderCallback();
    // 2. Obtain the source file FD and output file FD and assign them to avTranscoder. For details, see the FilePicker document.
    let context = getContext(this) as common.UIAbilityContext;
    let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
    this.avTranscoder.fdSrc = fileDescriptor;
    this.avTranscoder.fdDst = 55;
    // 3. Set transcoding parameters to complete the preparations.
    await this.avTranscoder.prepare(this.avConfig);
    // 4. Start transcoding.
    await this.avTranscoder.start();
  }

  // Process of pausing transcoding.
  async pauseTranscoderingProcess() {
    if (this.avTranscoder != undefined) { // It is reasonable to call pause only after start is called and returns a value.
      await this.avTranscoder.pause();
    }
  }

  // Resume the transcoding process.
  async resumeTranscoderingProcess() {
    if (this.avTranscoder != undefined) { // It is reasonable to call resume only after pause is called and returns a value.
      await this.avTranscoder.resume();
    }
  }

  // Release the transcoding process.
  async releaseTranscoderingProcess() {
    if (this.avTranscoder != undefined) {
      // 1. Release the avTranscoder instance.
      await this.avTranscoder.release();
      this.avTranscoder = undefined;
      // 2. Close the FD of the output file.
    }
  }

  // A complete example of starting, pausing, resuming, and exiting transcoding.
  async avTranscoderDemo() {
    await this.startTranscoderingProcess(); // Start transcoding.
    await this.pauseTranscoderingProcess(); // Pause transcoding.
    await this.resumeTranscoderingProcess(); // Resume transcoding.
    await this.releaseTranscoderingProcess(); // Exit transcoding.
  }
}
```
