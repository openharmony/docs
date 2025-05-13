# Creating an Asynchronous Thread for AVTranscoder Video Transcoding (ArkTS)

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
   this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

   // Register the onmessage callback. When the host thread receives a message from the Worker thread through the workerPort.postMessage interface,
   // this callback is invoked and executed in the host thread.
   this.workerInstance.onmessage = (e: MessageEvents) => {
       let data: string = e.data;
       console.info("workerInstance onmessage is: ", data);
       if (data == 'complete') {
           console.info("complete: ", data);
           this.workerInstance?.terminate();
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
    // Send a message to the Worker thread.
    this.context = this.getUIContext().getHostContext();
    const sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
    const sendableObject: SendableObject = new SendableObject(sendableContext, "some information");
    this.workerInstance.postMessageWithSharedSendable(sendableObject);
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
                await transcoder?.release()
                workerPort.postMessage('complete');
            })
            // Callback function for transcoding errors.
            transcoder.on('error', async (err: BusinessError) => {
                await transcoder?.release();
            })
            // Callback function for transcoding progress updates.
            transcoder.on('progressUpdate', (progress: number) => {
            })

            let fileDescriptor = await context.resourceManager.getRawFd('3.mkv');
            transcoder.fdSrc = fileDescriptor;
            let fdPath = context.filesDir + "/" + "VID_" + Date.parse(new Date().toString()) + ".mp4";
            let file = fs.openSync(fdPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
            let fd = file.fd;
            console.info(`file fd ${fd}`);
            transcoder.fdDst = file.fd;

            let config: media.AVTranscoderConfig = {
                // audioBitrate: 200000,
                // audioCodec: media.CodecMimeType.AUDIO_AAC,
                fileFormat: media.ContainerFormatType.CFT_MPEG_4,
                videoBitrate: 200000,
                videoCodec: media.CodecMimeType.VIDEO_AVC,
            }
            await transcoder?.prepare(config);
            await transcoder?.start();
        } catch (e) {
            console.info(`error :  ${e}`);
        }
    }
    ```

4. Listen for transcoding completion events and send a message to the main thread when transcoding is complete.

    ```ts
    transcoder.on('complete', async () => {
        console.info(`transcode complete`);
        await transcoder?.release()
        // Send a message to the main thread, indicating that the transcoding is complete.
        workerPort.postMessage('complete');
    })
    ```

5. The main thread receives the message from the Worker thread indicating transcoding completion and destroys the Worker thread.

   ```ts
   // Register the onmessage callback. When the host thread receives a message from the Worker thread through the workerPort.postMessage interface, this callback is invoked and executed in the host thread.
       this.workerInstance.onmessage = (e: MessageEvents) => {
           let data: string = e.data;
           console.info("workerInstance onmessage is: ", data);
           if (data == 'complete') {
               console.info("complete: ", data);
               this.workerInstance?.terminate();
           }
       }
   ```

### Core Code

**Index.ets(src/main/ets/pages/Index.ets)**

```ts
import { ErrorEvent, MessageEvents, worker } from '@kit.ArkTS'
import { SendableObject } from '../util/SendableObject';
import { common, sendableContextManager } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
    private workerInstance?: worker.ThreadWorker;
    private context: Context | undefined;

    build() {
        RelativeContainer() {
        Button('Start transcoding')
            .onClick(async () => {
                console.info(`Button put`);
                await this.startWorker();
            })
            .alignRules({
                center: { anchor: '__container__', align: VerticalAlign.Center },
                middle: { anchor: '__container__', align: HorizontalAlign.Center }
            })
        }
        .height('100%')
        .width('100%')
    }

    async startWorker() {
        // Create a Worker object.
        this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

        // Register the onmessage callback. When the host thread receives a message from the Worker thread through the workerPort.postMessage interface,
        // this callback is invoked and executed in the host thread.
        this.workerInstance.onmessage = (e: MessageEvents) => {
            let data: string = e.data;
            console.info("workerInstance onmessage is: ", data);
            if (data == 'complete') {
                console.info("complete: ", data);
                this.workerInstance?.terminate();
            }
        }

        // Register the onErrors callback to capture global exceptions generated during the onmessage callback, timer callback, and file execution of the Worker thread.
        // this callback is invoked and executed in the host thread.
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

        // Send a message to the Worker thread.
        this.context = this.getUIContext().getHostContext();
        if (this.context != undefined) {
            const sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
            const sendableObject: SendableObject = new SendableObject(sendableContext, "some information");
            this.workerInstance.postMessageWithSharedSendable(sendableObject);
        }
    }
}
```

**SendableObject.ets(src/main/ets/util/SendableObject.ets)**

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

**task.ets(src/main/ets/workers/task.ets)**

```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import fs from '@ohos.file.fs';
import { SendableObject } from '../util/SendableObject';
import { common, sendableContextManager } from '@kit.AbilityKit';

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = async (event: MessageEvents) => {
    console.info(`onmessage in`);
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
};

workerPort.onmessageerror = (event: MessageEvents) => {
    console.info('workerPort onmessageerror');
};

workerPort.onerror = (event: ErrorEvent) => {
    console.info('workerPort onerror err is: ', event.message);
};

async function doSome(context: common.Context) {
    console.info(`doSome in`);
    try {
        let transcoder = await media.createAVTranscoder();
        // Callback function for the completion of transcoding.
        transcoder.on('complete', async () => {
            console.info(`transcode complete`);
            await transcoder?.release()
            // Send a message to the main thread, indicating that the transcoding is complete.
            workerPort.postMessage('complete');
        })
        // Callback function for transcoding errors.
        transcoder.on('error', async (err: BusinessError) => {
            await transcoder?.release();
        })
        // Callback function for transcoding progress updates.
        transcoder.on('progressUpdate', (progress: number) => {
        })
        // Read raw files in the rawfile directory.
        let fileDescriptor = await context.resourceManager.getRawFd('3.mkv');
        transcoder.fdSrc = fileDescriptor;
        let fdPath = context.filesDir + "/" + "VID_" + Date.parse(new Date().toString()) + ".mp4";
        let file = fs.openSync(fdPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
        let fd = file.fd;
        console.info(`file fd ${fd}`);
        transcoder.fdDst = file.fd;

        let config: media.AVTranscoderConfig = {
            fileFormat: media.ContainerFormatType.CFT_MPEG_4,
            audioCodec: media.CodecMimeType.AUDIO_AAC,
            videoCodec: media.CodecMimeType.VIDEO_AVC,
            videoBitrate: 200000,
        }
        await transcoder?.prepare(config);
        await transcoder?.start();
    } catch (e) {
        console.info(`error :  ${e}`);
    }
}
```

**build-profile.json5(build-profile.json5)**

```json
{
    "apiType": "stageMode",
    "buildOption": {
        "sourceOption": {
            "workers": [
                "./src/main/ets/workers/task.ets",
            ]
        }
    },
    "buildOptionSet": [
        {
            "name": "release",
            "arkOptions": {
                "obfuscation": {
                    "ruleOptions": {
                        "enable": false,
                        "files": [
                        "./obfuscation-rules.txt"
                        ]
                    }
                }
            }
        },
    ],
    "targets": [
        {
            "name": "default"
        },
        {
            "name": "ohosTest",
        }
    ]
}
```
