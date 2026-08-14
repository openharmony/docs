# Using AVTranscoder to Transcode Videos (ArkTS)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=96ff78e2aadddba9fa0a3d5b83b43dfd7221d4f5 translatedAt=2026-08-11T01:54:04.877Z pushedAt=2026-08-12T01:45:10.928Z -->

You can use the [AVTranscoder](media-kit-intro.md#avtranscoder) to implement video transcoding. <!--RP1--><!--RP1End--> You can check whether the current device supports the AVTranscoder by calling [canIUse](../../reference/common/js-apis-syscap.md#caniuse). If the return value of **canIUse("SystemCapability.Multimedia.Media.AVTranscoder")** is **true**, the transcoding capability can be used.

This topic describes how to use the AVTranscoder to implement video transcoding, covering the process of starting, pausing, resuming, and exiting transcoding.

## How to Develop

For details about the APIs, see [AVTranscoder](../../reference/apis-media-kit/arkts-apis-media-AVTranscoder.md).

> **NOTE**
>
> To forward, upload, or save the transcoded file, the application must call the system API **await avTranscoder.release()** after receiving the complete event. This ensures the integrity of the video file.

1. Create an [AVTranscoder](../../reference/apis-media-kit/arkts-apis-media-f.md#mediacreateavtranscoder12) instance.

   ```ts
   import { media } from '@kit.MediaKit';
   
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   // Create an AVTranscoder instance.
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
   import { fileIo } from '@kit.CoreFileKit';
   import { media } from '@kit.MediaKit';
   private currentProgress: number = 0;
   private avTranscoder: media.AVTranscoder | undefined = undefined;

   async test() {
     // Create an AVTranscoder instance.
     this.avTranscoder = await media.createAVTranscoder();
     if (this.avTranscoder != undefined) {
       // Callback function for the completion of transcoding.
       this.avTranscoder.on('complete', async () => {
         console.info(`AVTranscoder is completed`);
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
   }

   // Obtain the current progress.
   getCurrentProgress(): number {
     console.info(`getCurrentProgress = ${this.currentProgress}`);
     return this.currentProgress;
   }
   // Release the transcoding process.
   async releaseTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) {
         // 1. Release the AVTranscoder instance.
         await this.avTranscoder.release();
         let lastFdDst = this.avTranscoder.fdDst;
         let lastFdSrc = this.avTranscoder.fdSrc;
         this.avTranscoder = undefined;
         // 2. Close the FD of the output file.
         if (lastFdDst != undefined) {
           fs.closeSync(lastFdDst);
         }
         // 3. Close the transcoding source file fd.
         if (lastFdSrc != undefined) {
           fs.closeSync(lastFdSrc.fd);
         }
       }
     }
   }


   ```

3. Set the FD of the source video file (**fdSrc**).

   > **NOTE**
   >
   > The **fdSrc** in the following code example is for reference only. You need to verify resource availability and set it based on the actual situation:
   >
   > - If you use a local resource for transcoding, ensure that the resource file is available and use the app sandbox path to access the corresponding resource. For details, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths). For an introduction to the app sandbox and how to push files to it, see [Application Sandbox](../../file-management/app-sandbox-directory.md).
   >
   > - Obtain the app file path through the **Context** property. You are advised to use **getUIContext** to obtain a **UIContext** instance and use **getHostContext** to call **getContext** of the bound instance. For details, see [getHostContext](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12).
   >
   > - To use **ResourceManager.getRawFd()** to open a HAP resource file descriptor, see [getRawFd](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9) in ResourceManager.

   ```ts
   // Import the ets/transcoder/AVTranscoderManager.ets file.
   import {AVTranscoderDemo} from '../transcoder/AVTranscoderManager'

   @Entry
   @Component
   struct Index {
     // Obtain the context of the ability to which the current component belongs and obtain the application file path through the context.
     private context:Context | undefined = this.getUIContext()?.getHostContext();
     // Obtain the AVTranscoder instance.
     @State avTranscoder: AVTranscoderDemo | undefined = this.context ? new AVTranscoderDemo(this.context) : undefined;

     build() {
       RelativeContainer() {
         Column() {
           Button($r('app.string.StartTranscoder')) // Value of name:StartTranscoder in the resources/base/element/string.json file.
             .onClick(async () => {
               console.info(`Button put`);
               await this.avTranscoder?.avTranscoderDemo();
             })
             .id('AVTranscoderButton')
             // Obtain the transcoding progress.
             Progress({ value: 0, total: 100, type: ProgressType.Linear }).value(this.avTranscoder?.getCurrentProgress())
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
   import { media } from '@kit.MediaKit';
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   private context: Context | undefined;
   constructor(context: Context | undefined) {
     if (context != undefined) {
       this.context = context; // this.getUIContext().getHostContext();
     }
   }

   async test() {
     // Create an AVTranscoder instance.
     this.avTranscoder = await media.createAVTranscoder();
     // Obtain the file descriptor of the input file. H264_AAC.mp4 is a preset resource in the rawfile directory. Replace it with the actual one.
     if (this.context != undefined) {
       let fileDescriptor = await this.context.resourceManager.getRawFd('H264_AAC.mp4');
       // Set fdSrc used for transcoding.
       this.avTranscoder.fdSrc = fileDescriptor;
     }
   }
   ```

4. Set the FD of the target video file (**fdSrc**)..

   > **NOTE**
   >
   > **fdDst** specifies the FD of the output file after transcoding. The value is a number. You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Accessing Application Files](../../file-management/app-file-access.md).

   ```ts
   import { fileIo } from '@kit.CoreFileKit';
   import { media } from '@kit.MediaKit';
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   private context: Context | undefined;
   constructor(context: Context | undefined) {
     if (context != undefined) {
       this.context = context; // this.getUIContext().getHostContext();
     }
   }

   async test() {
     // Create an AVTranscoder instance.
     this.avTranscoder = await media.createAVTranscoder();
     if (this.context != undefined) {
       // Set the sandbox path of the output target file.
       let outputFilePath = this.context.filesDir + "/output.mp4";
       // Create and open a file if the file does not exist. Open it if the file exists.
       let file = fileIo.openSync(outputFilePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
       // Set fdDst of the output file.
       this.avTranscoder.fdDst = file.fd; // Obtain the file descriptor of the created video file by referring to the sample code in Accessing Application Files.
     }
   }
   ```

5. Set video transcoding parameters and call **prepare()**.

   > **NOTE**
   >
   > Only transcoding-related parameters are set in the input parameter **avConfig** of the **prepare()** API.<br>
   > Only the supported [transcoding formats](media-kit-intro.md#avtranscoder) can be used due to the limited demultiplexing, multiplexing, encoding, and decoding capabilities.

   ```ts
   import { media } from '@kit.MediaKit';
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   private avConfig: media.AVTranscoderConfig = {
     audioBitrate: 100000, // Audio bit rate.
     audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Container format.
     videoBitrate: 2000000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
   };

   async test() {
     // Create an AVTranscoder instance.
     this.avTranscoder = await media.createAVTranscoder();
     // Set transcoding parameters to complete the preparations.
     await this.avTranscoder.prepare(this.avConfig);
   }
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
      // For details about the creation procedure, see steps 1 to 5 above.

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
         // 2. Close the FD of the output file.
         fileIo.closeSync(this.avTranscoder!.fdDst);
       }
     }
   }
   ```

10. A complete example of starting, pausing, resuming, and completing transcoding.

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

    ```txt
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