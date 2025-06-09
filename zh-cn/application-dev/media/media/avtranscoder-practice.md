# 创建异步线程执行AVTranscoder视频转码(ArkTS)

在开发过程中，应用经常会创建异步线程执行视频转码任务以满足不同诉求，主要包括：

- 节省存储空间。

  高清视频文件通常存储空间占用大，几分钟的视频就可能占用数GB的存储空间。视频压缩可以显著减小文件大小，节省存储空间。

- 提高设备兼容性。

  不同设备所支持播放的视频格式各不相同。视频转码可以将源视频格式转换成设备支持的常用格式，以满足不同设备的播放需求，从而提高视频文件的设备兼容性。

<!--RP1--><!--RP1End-->

## 使用异步线程的方式进行转码

本示例使用的是worker线程的方式来实现异步线程进行转码，worker线程的详细使用方式，可以参见文档:

- [Worker线程使用说明](../../reference/apis-arkts/js-apis-worker.md)
- [Worker简介](../../arkts-utils/worker-introduction.md)

### 开发步骤

1. 引入头文件，创建worker线程，并注册回调。

   ```ts
   import { ErrorEvent, MessageEvents, worker } from '@kit.ArkTS'
   import { SendableObject } from '../util/SendableObject';
   import { common, sendableContextManager } from '@kit.AbilityKit';
   ```

   ```ts
   // 创建Worker对象
   this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

   // 注册onmessage回调，当宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用，
   // 在宿主线程执行
   this.workerInstance.onmessage = (e: MessageEvents) => {
       let data: string = e.data;
       console.info("workerInstance onmessage is: ", data);
       if (data == 'complete') {
           console.info("complete: ", data);
           this.workerInstance?.terminate();
       }
   }

   // 注册onErrors回调，可以捕获Worker线程的onmessage回调、timer回调以及文件执行等流程产生的全局异常，在宿主线程执行
   this.workerInstance.onerror = (err: ErrorEvent) => {
       console.info("workerInstance onerror message is: " + err.message);
   }

   // 注册onmessageerror回调，当Worker对象接收到一条无法被序列化的消息时被调用，在宿主线程执行
   this.workerInstance.onmessageerror = () => {
       console.info('workerInstance onmessageerror');
   }

   // 注册onexit回调，当Worker销毁时被调用，在宿主线程执行
   this.workerInstance.onexit = (e: number) => {
       // 当Worker正常退出时code为0，异常退出时code为1
       console.info("workerInstance onexit code is: ", e);
   }
   ```

2. 创建参数对象，向worker线程发送参数对象。

   如下是参数对象模型：

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

    如下是发送参数的逻辑：

    ```ts
    // 向Worker线程发送消息
    this.context = this.getUIContext().getHostContext();
    const sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
    const sendableObject: SendableObject = new SendableObject(sendableContext, "some information");
    this.workerInstance.postMessageWithSharedSendable(sendableObject);
    ```

3. worker线程接收参数，并且执行转码的逻辑。

   worker线程接收参数：

    ```ts
    //worker线程接收参数
    const sendableObject: SendableObject = event.data;
    const sendableContext: sendableContextManager.SendableContext =
    sendableObject.getSendableContext() as sendableContextManager.SendableContext;
    const context: common.Context =
    sendableContextManager.convertToContext(sendableContext) as common.Context;
    //执行转码逻辑
    await doSome(context);
    // 向主线程发送消息
    workerPort.postMessage('start end');
    ```

    执行转码逻辑：

    ```ts
    async function doSome(context: common.Context) {
        console.info(`doSome in`);
        try {
            let transcoder = await media.createAVTranscoder();
            // 转码完成回调函数
            transcoder.on('complete', async () => {
                console.info(`transcode complete`);
                await transcoder?.release()
                workerPort.postMessage('complete');
            })
            // 转码错误回调函数
            transcoder.on('error', async (err: BusinessError) => {
                await transcoder?.release();
            })
            // 转码进度更新
            transcoder.on('progressUpdate', (progress: number) => {
            })

            try {
                // 获取输入文件fd，3.mkv为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
                let fileDescriptor = await context.resourceManager.getRawFd('3.mkv');
                transcoder.fdSrc = fileDescriptor;
            } catch (error) {
                console.error('Failed to get the file descriptor, please check the resource and path.');
            }
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
            console.error(`transcode error: code = ` + e.code.toString() + `, message = ${JSON.stringify(e.message)}`);
        }
    }
    ```

4. 监听转码的Complete回调，在转码结束的时候向主线程发送消息。

    ```ts
    transcoder.on('complete', async () => {
        console.info(`transcode complete`);
        await transcoder?.release()
        //向主线程发送转码结束的消息
        workerPort.postMessage('complete');
    })
    ```

5. 主线程接收到worker线程转码结束的信息，销毁worker线程。

   ```ts
   // 注册onmessage回调，当宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用，在宿主线程执行
       this.workerInstance.onmessage = (e: MessageEvents) => {
           let data: string = e.data;
           console.info("workerInstance onmessage is: ", data);
           if (data == 'complete') {
               console.info("complete: ", data);
               this.workerInstance?.terminate();
           }
       }
   ```

### 整体核心代码

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
        Button('启动转码')
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
        // 创建Worker对象
        this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

        // 注册onmessage回调，当宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用，
        // 在宿主线程执行
        this.workerInstance.onmessage = (e: MessageEvents) => {
            let data: string = e.data;
            console.info("workerInstance onmessage is: ", data);
            if (data == 'complete') {
                console.info("complete: ", data);
                this.workerInstance?.terminate();
            }
        }

        // 注册onErrors回调，可以捕获Worker线程的onmessage回调、timer回调以及文件执行等流程产生的全局异常，
        // 在宿主线程执行
        this.workerInstance.onerror = (err: ErrorEvent) => {
            console.info("workerInstance onerror message is: " + err.message);
        }

        // 注册onmessageerror回调，当Worker对象接收到一条无法被序列化的消息时被调用，在宿主线程执行
        this.workerInstance.onmessageerror = () => {
            console.info('workerInstance onmessageerror');
        }

        // 注册onexit回调，当Worker销毁时被调用，在宿主线程执行
        this.workerInstance.onexit = (e: number) => {
            // 当Worker正常退出时code为0，异常退出时code为1
            console.info("workerInstance onexit code is: ", e);
        }

        // 向Worker线程发送消息
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

//发送的参数必须加上@Sendable标注
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
    //worker线程接收参数
    const sendableObject: SendableObject = event.data;
    const sendableContext: sendableContextManager.SendableContext =
        sendableObject.getSendableContext() as sendableContextManager.SendableContext;
    const context: common.Context =
        sendableContextManager.convertToContext(sendableContext) as common.Context;
    //执行转码逻辑
    await doSome(context);
    // 向主线程发送消息
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
        // 转码完成回调函数
        transcoder.on('complete', async () => {
            console.info(`transcode complete`);
            await transcoder?.release()
            //向主线程发送转码结束的消息
            workerPort.postMessage('complete');
        })
        // 转码错误回调函数
        transcoder.on('error', async (err: BusinessError) => {
            await transcoder?.release();
        })
        // 转码进度更新
        transcoder.on('progressUpdate', (progress: number) => {
        })
        try {
            // 获取输入文件fd，3.mkv为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
            let fileDescriptor = await context.resourceManager.getRawFd('3.mkv');
            transcoder.fdSrc = fileDescriptor;
        } catch (error) {
            console.error('Failed to get the file descriptor, please check the resource and path.');
        }
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
        console.error(`transcode error: code = ` + e.code.toString() + `, message = ${JSON.stringify(e.message)}`);
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
