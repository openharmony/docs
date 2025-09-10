# Creating an Asynchronous Thread for AVTranscoder Video Transcoding (ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @wang-haizhou6-->
<!--Designer: @HmQQQ-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

During development, applications often create asynchronous threads to perform video transcoding tasks to meet various requirements, including:

- Saving storage space

  High-definition video files typically consume a significant amount of storage space, with just a few minutes of video potentially occupying several GB. Video compression can significantly reduce file size, thereby saving storage space.

- Improving device compatibility

  Different devices support various video formats for playback. Video transcoding can convert the source video format into commonly supported formats, meeting the playback needs of different devices and therefore enhancing the compatibility of video files across devices.

<!--RP1--><!--RP1End-->

## Using Asynchronous Threads for Transcoding

This example uses a Worker thread to perform asynchronous transcoding. For details about how to use Worker threads, refer to the following documents:

- [@ohos.worker (Starting the Worker)](../../reference/apis-arkts/js-apis-worker.md)
- [Worker](../../arkts-utils/worker-introduction.md)

### How to Develop

1. Import header files, create a Worker thread, and register callback functions.

   ```ts
   import { ErrorEvent, MessageEvents, worker } from '@kit.ArkTS'
   import { SendableObject } from '../util/SendableObject';
   import { common, sendableContextManager } from '@kit.AbilityKit';
   ```

   ```ts
   // Create a Worker object.
   private workerInstance?: worker.ThreadWorker;
   this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

   // Register the onmessage callback. When the host thread receives a message from the Worker thread through the workerPort.postMessage interface, this callback is invoked and executed in the host thread.
   this.workerInstance.onmessage = (e: MessageEvents) => {
      let data: string | number = e.data;
      if (typeof data === 'string') { // Complete event.
        console.info('workerInstance onmessage is: ', data);
        if (data === 'complete') {
          console.info('complete: ', data);
          this.workerInstance?.terminate();
        }
      } else if (typeof data === 'number') {
        this.currentProgress = data; // Current progress.
      }
    }

   // Register the onErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread. This callback is executed in the host thread.
   this.workerInstance.onerror = (err: ErrorEvent) => {
       console.info("workerInstance onerror message is: " + err.message);
   }

   // Register the onmessageerror callback. When the Worker object receives a message that cannot be serialized, this callback is invoked and executed in the host thread.
   this.workerInstance.onmessageerror = () => {
       console.info('workerInstance onmessageerror');
   }

   // Register the onexit callback. When the Worker object is destroyed, this callback is invoked and executed in the host thread.
   this.workerInstance.onexit = (e: number) => {
       // When the Worker object exits normally, the code is 0. When the Worker object exits abnormally, the code is 1.
       console.info("workerInstance onexit code is: ", e);
   }
   ```

2. Create a parameter object and send it to the Worker thread.

   The parameter object model is as follows:

   ```ts
   import { sendableContextManager } from '@kit.AbilityKit';

   // Decorate the parameters with @Sendable.
   @Sendable
   export class SendableObject {
     constructor(sendableContext: sendableContextManager.SendableContext, data: string = '') {
       this.sendableContext = sendableContext;
       this.data = data;
     }

     private sendableContext: sendableContextManager.SendableContext;
     private data: string;


     public getSendableContext() {
       return this.sendableContext;
     }

     public getData() {
       return this.data;
     }
   }
   ```

   The logic for sending parameters is as follows:

   ```ts
   private context: Context | undefined;
   // Send a message to the Worker thread.
   this.context = this.getUIContext().getHostContext(); // Obtain the context of the ability to which the current component belongs.
   if (this.context != undefined) {
     const sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(
       this.context);
     const sendableObject: SendableObject = new SendableObject(sendableContext, 'some information');
     this.workerInstance.postMessageWithSharedSendable(sendableObject);
   }
   ```

3. The Worker thread receives the parameters and executes the transcoding logic.

   Receiving parameters:

   ```ts
   // Receive the parameters.
   const sendableObject: SendableObject = event.data;
   const sendableContext: sendableContextManager.SendableContext =
     sendableObject.getSendableContext() as sendableContextManager.SendableContext;
   const context: common.Context =
     sendableContextManager.convertToContext(sendableContext) as common.Context;
   // Execute the transcoding logic.
   await doSome(context);
   // Send a message to the main thread.
   workerPort.postMessage('start end');
   ```

   Executing transcoding logic:

   ```ts
   async function doSome(context: common.Context) {
     console.info(`doSome in`);
     try {
       let transcoder = await media.createAVTranscoder();
       // Callback function for the completion of transcoding.
       transcoder.on('complete', async () => {
         console.info(`transcode complete`);
         fs.closeSync(transcoder.fdDst); // Close fdDst.
         await transcoder?.release()
         workerPort.postMessage('complete');
       })
       // Callback function for transcoding errors.
       transcoder.on('error', async (err: BusinessError) => {
         fs.closeSync(transcoder.fdDst);
         await transcoder?.release();
       })
       // Callback function for updating the transcoding progress.
       transcoder.on('progressUpdate', (progress: number) => {
         console.info(`AVTranscoder progressUpdate = ${progress}`);
         workerPort.postMessage(progress);
       })

       try {
         // Obtain the file descriptor of the input file. H264_AAC.mp4 is a preset resource in the rawfile directory. Replace it with the actual one.
         let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
         transcoder.fdSrc = fileDescriptor; // Set fdSrc.
       } catch (error) {
         console.error('Failed to get the file descriptor, please check the resource and path.');
       }
       // Set the output file path. context.filesDir is the sandbox path of the application.
       let fdPath = context.filesDir + "/" + "VID_" + Date.parse(new Date().toString()) + ".mp4";
       let file = fs.openSync(fdPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
       let fd = file.fd;
       console.info(`file fd ${fd}`);
       transcoder.fdDst = file.fd;

       let config: media.AVTranscoderConfig = {
         fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Container format.
         audioCodec: media.CodecMimeType.AUDIO_AAC, // Audio encoding format.
         videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
         videoBitrate: 200000, // Video bit rate.
       }
       await transcoder?.prepare(config); 
       await transcoder?.start();
     } catch (e) {
       console.error(`transcode error: code = ` + e.code.toString() + `, message = ${JSON.stringify(e.message)}`);
     }
   }
   ```

4. Listen for transcoding completion events and send a message to the main thread when transcoding is complete.

   ```ts
   // Callback function for the completion of transcoding.
   transcoder.on('complete', async () => {
     console.info(`transcode complete`);
     fs.closeSync(transcoder.fdDst); // Close fdDst.
     await transcoder?.release()
     workerPort.postMessage('complete');
   })
   ```

5. The main thread receives the message from the Worker thread indicating transcoding completion and destroys the Worker thread.

   ```ts
   // Register the onmessage callback. When the host thread receives a message from the Worker thread through the workerPort.postMessage interface, this callback is invoked and executed in the host thread.
   this.workerInstance.onmessage = (e: MessageEvents) => {
     let data: string | number = e.data;
     if (typeof data === 'string') {
       console.info('workerInstance onmessage is: ', data);
       if (data === 'complete') {
         console.info('complete: ', data);
         this.workerInstance?.terminate();
       }
     } else if (typeof data === 'number') {
       this.currentProgress = data;
     }
   }
   ```

## Running the Sample Project

Refer to the sample project to use a Worker thread to implement asynchronous transcoding.

1. Create a project, download the [sample project](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVTranscoder/AsyncTranscoder), and copy its resources to the corresponding directories.
    ```
    AsyncTranscoder
    entry/build-profile.json5 (Configure fields to package Worker thread files into the application.)
    entry/src/main/ets/
    ├── pages
    │    └── Index.ets (Transcoding UI)
    ├── util
    │    └── SendableObject.ets (Sendable object)
    │
    └── workers
        └── task.ets (Transcoding task)

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
