# Using AVTranscoder to Transcode Videos (ArkTS)

You can use the [AVTranscoder](media-kit-intro.md#avtranscoder) to implement video transcoding. <!--RP1--><!--RP1End--> You can check whether the current device supports the AVTranscoder by calling [canIUse](../../reference/common/js-apis-syscap.md). If the return value of canIUse("SystemCapability.Multimedia.Media.AVTranscoder") is **true**, the transcoding capability can be used.

This topic describes how to use the AVTranscoder to implement video transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.

## How to Develop

Read [AVTranscoder](../../reference/apis-media-kit/arkts-apis-media-AVTranscoder.md) for the API reference.

> **NOTE**
>
> To forward, upload, or save the transcoded file, the application must call the system API **await avTranscoder.release()** after receiving the complete event. This ensures the integrity of the video file.

1. Create an AVTranscoder instance.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   // 1. Create an AVTranscoder instance.
   this.avTranscoder = await media.createAVTranscoder();
   ```

2. Set the events to listen for.

   | Event Type| Description| 
   | -------- | -------- |
   | complete | Mandatory; used to listen for the completion of transcoding.| 
   | error | Mandatory; used to listen for errors that occur during transcoding.|
   | progressUpdate | Used to listen for the transcoding progress.|

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   private currentProgress: number = 0;

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
     // Callback function for progress updates.
     this.avTranscoder.on('progressUpdate', (progress: number) => {
       console.info(`AVTranscoder progressUpdate = ${progress}`);
       this.currentProgress = progress;
     })
   }

   // Obtain the current progress.
   getCurrentProgress(): number {
     console.info(`getCurrentProgress = ${this.currentProgress}`);
     return this.currentProgress;
   }
   ```

3. Set the FD of the source video file.
   > **NOTE**
   >
   > The **fdSrc** value in the code snippet below is for reference only. You need to check the media asset validity and set **fdSrc** based on service requirements.
   > 
   > - If local files are used for transcoding, ensure that the files are available and the application sandbox path is used for access. For details about how to obtain the application sandbox path, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For details about the application sandbox and how to push files to the application sandbox directory, see [File Management](../../file-management/app-sandbox-directory.md).
   > 
   > - To obtain the application file path, you should use the Context property. You are advised to use **getUIContext** to obtain a UIContext instance and use **getHostContext** to call **getContext** of the bound instance. For details, see [Obtaining Context](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).
   >
   > - You can also use **ResourceManager.getRawFd()** to obtain the FD of a file packed in the HAP file. For details, see [ResourceManager API Reference](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9).

   ```ts
   import {AVTranscoderDemo} from '../transcoder/AVTranscoderManager'

   @Entry
   @Component
   struct Index {
     // Obtain the context of the ability to which the current component belongs and obtain the application file path through the context.
     private context:Context | undefined = this.getUIContext().getHostContext();
     // Obtain the AVTranscoder instance.
     @State avTranscoder: AVTranscoderDemo = new AVTranscoderDemo(this.context);

     build() {
       RelativeContainer() {
         Column() {
           Button($r('app.string.StartTranscoder'))
             .onClick(async () => {
               console.info(`Button put`);
               await this.avTranscoder.avTranscoderDemo();
             })
             .id('AVTranscoderButton')
             // Obtain the transcoding progress.
             Progress({ value: 0, total: 100, type: ProgressType.Linear }).value(this.avTranscoder.getCurrentProgress())
               .height(50)
               .width('80%')
         }
         .alignRules({
           center: { anchor: '__container__', align: VerticalAlign.Center },
           middle: { anchor: '__container__', align: HorizontalAlign.Center }
         })
       }
       .height('100%')
       .width('100%')
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
   import fs from '@ohos.file.fs';
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
   > Only transcoding-related parameters are set in the input parameter **avConfig** of the **prepare()** API.<br>
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
   // Set transcoding parameters to complete the preparations.
   await this.avTranscoder.prepare(this.avConfig);
   ```
   <!--RP2--><!--RP2End-->

6. Call **start()** to start transcoding.

   ```ts
   async startTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) {
         await this.avTranscoder.release();
         this.avTranscoder = undefined;
       }
      // Create an AVTranscoder instance, set the callback, set the file descriptor, and complete the preparation before starting transcoding.
      // Start transcoding.
      await this.avTranscoder.start();
    }
   }
   ```

7. Call **pause()** to pause transcoding.

   ```ts
   // Process of pausing transcoding.
   async pauseTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) { // It is reasonable to call pause only after start is called and returns a value.
         await this.avTranscoder.pause();
       }
     }
   }
   ```

8. Call **resume()** to resume transcoding.

   ```ts
   // Resume transcoding.
   async resumeTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) { // It is reasonable to call resume only after pause is called and returns a value.
         await this.avTranscoder.resume();
       }
     }
   }
   ```

9. Call **release()** to destroy the instance and exit transcoding.

   ```ts
   // Destroy the instance.
   async releaseTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) {
         // 1. Destroy the instance.
         await this.avTranscoder.release();
         this.avTranscoder = undefined;
         // Close the FD of the output file.
         fs.closeSync(this.avTranscoder!.fdDst);
       }
     }
   }
   ```
10. A complete example of starting, pausing, resuming, and exiting transcoding.

   ```ts
   async avTranscoderDemo() {
     await this.startTranscoderingProcess(); // Start transcoding.
     await this.pauseTranscoderingProcess(); // Pause transcoding.
     await this.resumeTranscoderingProcess(); // Resume transcoding.
   }
   ```

## Running the Sample Project

Refer to the sample code below to implement transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.
  
1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVTranscoder/AVTranscoderArkTS), and copy its resources to the corresponding directories.
    ```
    AVTranscoderArkTS
    entry/src/main/ets/
    └── pages
    │    └── Index.ets (Transcoding UI)
    │
    └── transcoder
        └── AVTranscoderManager.ets (Transcoding function)

    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── H264_AAC.mp4 (Video resource)
    ```
2. Compile and run the project.
