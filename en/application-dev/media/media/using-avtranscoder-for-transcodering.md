# Using AVTranscoder to Transcode Videos (ArkTS)

You can use the [AVTranscoder](media-kit-intro.md#avtranscoder) to implement video transcoding<!--RP1--><!--RP1End-->. You can check whether the current device supports the AVTranscoder by calling [canIUse](../../reference/common/js-apis-syscap.md). If the return value of canIUse("SystemCapability.Multimedia.Media.AVTranscoder") is **true**, the transcoding capability can be used.

This topic describes how to use the AVTranscoder to implement video transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.

## How to Develop

Read [AVTranscoder](../../reference/apis-media-kit/js-apis-media.md#avtranscoder12) for the API reference.
> **NOTE**
>
> To forward, upload, or save the transcoded file, the application must call the system API **await avTranscoder.release()** after receiving the complete event. This ensures the integrity of the video file.

1. Create an **avTranscoder** instance.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avTranscoder: media.AVTranscoder | undefined = undefined;
   media.createAVTranscoder().then((transcoder: media.AVTranscoder) => {
     avTranscoder = transcoder;
     // Perform other operations after avTranscoder is assigned a value.
   }, (error: BusinessError) => {
     console.error(`createAVTranscoder failed`);
   });
   ```

2. Set the events to listen for.

   | Event Type| Description| 
   | -------- | -------- |
   | complete | Mandatory; used to listen for the completion of transcoding.| 
   | error | Mandatory; used to listen for AVTranscoder errors.|

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   
   // Callback function for the completion of transcoding.
   avTranscoder.on('complete', async () => {
     console.log(`transcoder is completed`);
     // Listen for the transcoding completion event and call release.
     // Wait until avTranscoder.release() is complete before forwarding, uploading, or saving the transcoded file.
     await avTranscoder.release();
     avTranscoder = undefined;
   });
   
   // Callback function for errors.
   avTranscoder.on('error', (err: BusinessError) => {
     console.error(`avTranscoder failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

3. Set the FD of the source video file.
   > **NOTE**
   >
   > The **fdSrc** value in the code snippet below is for reference only. You need to check the media asset validity and set **fdSrc** based on service requirements.
   > 
   > - If local files are used for transcoding, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   > 
   > - To obtain the application file path, you should use the Context property. You are advised to use **getUIContext** to obtain a UIContext instance and use **getHostContext** to call **getContext** of the bound instance. For details, see [Obtaining Context](../../reference/apis-arkui/js-apis-arkui-UIContext.md#gethostcontext12).
   >
   > - You can also use **ResourceManager.getRawFd()** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).

   ```ts
   import {AVTranscoderDemo} from '../transcoder/AVTranscoderManager'

   @Entry
   @Component
   struct Index {
     private context:Context | undefined = this.getUIContext().getHostContext();
     private avTranscoder: AVTranscoderDemo = new AVTranscoderDemo(this.context);
     build() {
       Column() {
        Button('Transcode').onClick(() => {
          this.avTranscoder.avTranscoderDemo();
        })
      }
     }
   }
   ```

   ```ts
   import resourceManager from '@ohos.resourceManager';
   import { common } from '@kit.AbilityKit';

   private context: Context | undefined;
    constructor(context: Context | undefined) {
      if (context != undefined) {
        this.context = context; // this.getUIContext().getHostContext();
      }
   }
   // Obtain the file descriptor of the input file. H264_AAC.mp4 is a preset resource in the rawfile directory. Replace it with the actual one.
   let fileDescriptor = await this.context.resourceManager.getRawFd('H264_AAC.mp4');
   // Set fdSrc used for transcoding.
   this.avTranscoder.fdSrc = fileDescriptor;
   ```

4. Set the FD of the target video file.
   > **NOTE**
   >
   > **fdDst** specifies the FD of the output file after transcoding. The value is a number. You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Accessing Application Files](../../file-management/app-file-access.md).
   
   ```ts
   // Set the sandbox path of the output target file.
   let outputFilePath = this.context.filesDir + "/output.mp4";
   // Create and open a file if the file does not exist. Open it if the file exists.
   let file = fs.openSync(outputFilePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   // Set fdDst of the output file.
   this.avTranscoder.fdDst = file.fd; // Obtain the file descriptor of the created video file by referring to the sample code in Accessing Application Files.
   ```

5. Set video transcoding parameters and call **prepare()**.

   > **NOTE**
   >
   > Only transcoding-related parameters are set in the input parameter **avConfig** of the **prepare()** API.
   >
   > Only the supported [transcoding formats](media-kit-intro.md#avtranscoder) can be used due to the limited demultiplexing, multiplexing, encoding, and decoding capabilities.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avConfig: media.AVTranscoderConfig = {
     audioBitrate: 100000, // Audio bit rate.
     audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Container format.
     videoBitrate: 2000000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
   };
   avTranscoder.prepare(avConfig).then(() => {
     console.log('Invoke prepare succeeded.');
   }, (err: BusinessError) => {
     console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
   });
   ```
   <!--RP2--><!--RP2End-->

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

## Development Example

  Refer to the sample code below to implement transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.
  
```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';
import fs from '@ohos.file.fs';

export class AVTranscoderDemo {
  private avTranscoder: media.AVTranscoder | undefined = undefined;
  private context: Context | undefined;
  constructor(context: Context | undefined) {
    if (context != undefined) {
      this.context = context;
    }
  }
  private avConfig: media.AVTranscoderConfig = {
    audioBitrate: 100000, // Audio bit rate.
    audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
    fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Container format.
    videoBitrate: 200000, // Video bit rate.
    videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
  };

  // Set AVTranscoder callback functions.
  setAVTranscoderCallback() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) {
        // Callback function for the completion of transcoding.
        this.avTranscoder.on('complete', async () => {
          console.log(`AVTranscoder is completed`);
          await this.releaseTranscoderingProcess();
        });
        // Callback function for errors.
        this.avTranscoder.on('error', (err: BusinessError) => {
          console.error(`AVTranscoder failed, code is ${err.code}, message is ${err.message}`);
        });
      }
    }
  }

  // Process of starting transcoding.
  async startTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) {
        await this.avTranscoder.release();
        this.avTranscoder = undefined;
      }
      // 1. Create an avTranscoder instance.
      this.avTranscoder = await media.createAVTranscoder();
      this.setAVTranscoderCallback();
      // 2. Obtain the source file FD and output file FD and assign them to avTranscoder. For details, see the FilePicker document.
      if (this.context != undefined) {
        try {
          // Obtain the file descriptor of the input file. H264_AAC.mp4 is a preset resource in the rawfile directory. Replace it with the actual one.
          let fileDescriptor = await this.context.resourceManager.getRawFd('H264_AAC.mp4');
          this.avTranscoder.fdSrc = fileDescriptor;
        } catch (error) {
          console.error('Failed to get the file descriptor, please check the resource and path.');
        }
        let outputFilePath = this.context.filesDir + "/output.mp4";
        let file = fs.openSync(outputFilePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
        this.avTranscoder.fdDst = file.fd;
      }
      // 3. Set transcoding parameters to complete the preparations.
      await this.avTranscoder.prepare(this.avConfig);
      // 4. Start transcoding.
      await this.avTranscoder.start();
    }
  }

  // Process of pausing transcoding.
  async pauseTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) { // It is reasonable to call pause only after start is called and returns a value.
        await this.avTranscoder.pause();
      }
    }
  }

  // Resume the transcoding process.
  async resumeTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) { // It is reasonable to call resume only after pause is called and returns a value.
        await this.avTranscoder.resume();
      }
    }
  }

  // Release the transcoding process.
  async releaseTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) {
        // 1. Release the avTranscoder instance.
        await this.avTranscoder.release();
        this.avTranscoder = undefined;
        // 2. Close the FD of the output file.
      }
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
