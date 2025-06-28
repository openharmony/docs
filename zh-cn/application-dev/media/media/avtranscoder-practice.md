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
   // 创建Worker对象。
   private workerInstance?: worker.ThreadWorker;
   this.workerInstance = new worker.ThreadWorker('entry/ets/workers/task.ets');

   // 注册onmessage回调，当宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用，在宿主线程执行。
   this.workerInstance.onmessage = (e: MessageEvents) => {
      let data: string | number = e.data;
      if (typeof data === 'string') { // complete事件。
        console.info('workerInstance onmessage is: ', data);
        if (data === 'complete') {
          console.info('complete: ', data);
          this.workerInstance?.terminate();
        }
      } else if (typeof data === 'number') {
        this.currentProgress = data; // 当前进度。
      }
    }

   // 注册onErrors回调，可以捕获Worker线程的onmessage回调、timer回调以及文件执行等流程产生的全局异常，在宿主线程执行。
   this.workerInstance.onerror = (err: ErrorEvent) => {
       console.info("workerInstance onerror message is: " + err.message);
   }

   // 注册onmessageerror回调，当Worker对象接收到一条无法被序列化的消息时被调用，在宿主线程执行。
   this.workerInstance.onmessageerror = () => {
       console.info('workerInstance onmessageerror');
   }

   // 注册onexit回调，当Worker销毁时被调用，在宿主线程执行。
   this.workerInstance.onexit = (e: number) => {
       // 当Worker正常退出时code为0，异常退出时code为1。
       console.info("workerInstance onexit code is: ", e);
   }
   ```

2. 创建参数对象，向worker线程发送参数对象。

   如下是参数对象模型：

   ```ts
   import { sendableContextManager } from '@kit.AbilityKit';

   //发送的参数必须加上@Sendable标注。
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
   private context: Context | undefined;
   // 向Worker线程发送消息。
   this.context = this.getUIContext().getHostContext(); // 获取当前组件所在Ability的Context。
   if (this.context != undefined) {
     const sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(
       this.context);
     const sendableObject: SendableObject = new SendableObject(sendableContext, 'some information');
     this.workerInstance.postMessageWithSharedSendable(sendableObject);
   }
   ```

3. worker线程接收参数，并且执行转码的逻辑。

   worker线程接收参数：

   ```ts
   //worker线程接收参数。
   const sendableObject: SendableObject = event.data;
   const sendableContext: sendableContextManager.SendableContext =
     sendableObject.getSendableContext() as sendableContextManager.SendableContext;
   const context: common.Context =
     sendableContextManager.convertToContext(sendableContext) as common.Context;
   //执行转码逻辑。
   await doSome(context);
   // 向主线程发送消息。
   workerPort.postMessage('start end');
   ```

   执行转码逻辑：

   ```ts
   async function doSome(context: common.Context) {
     console.info(`doSome in`);
     try {
       let transcoder = await media.createAVTranscoder();
       // 转码完成回调函数。
       transcoder.on('complete', async () => {
         console.info(`transcode complete`);
         fs.closeSync(transcoder.fdDst); // 关闭fdDst。
         await transcoder?.release()
         workerPort.postMessage('complete');
       })
       // 转码错误回调函数。
       transcoder.on('error', async (err: BusinessError) => {
         fs.closeSync(transcoder.fdDst);
         await transcoder?.release();
       })
       // 转码进度更新回调函数。
       transcoder.on('progressUpdate', (progress: number) => {
         console.info(`AVTranscoder progressUpdate = ${progress}`);
         workerPort.postMessage(progress);
       })

       try {
         // 获取输入文件fd，H264_AAC.mp4为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
         let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
         transcoder.fdSrc = fileDescriptor; // 设置fdSrc。
       } catch (error) {
         console.error('Failed to get the file descriptor, please check the resource and path.');
       }
       // 设置输出文件路径，context.filesDir为应用的沙箱路径。
       let fdPath = context.filesDir + "/" + "VID_" + Date.parse(new Date().toString()) + ".mp4";
       let file = fs.openSync(fdPath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
       let fd = file.fd;
       console.info(`file fd ${fd}`);
       transcoder.fdDst = file.fd;

       let config: media.AVTranscoderConfig = {
         fileFormat: media.ContainerFormatType.CFT_MPEG_4, // 封装格式。
         audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式。
         videoCodec: media.CodecMimeType.VIDEO_AVC, // 视频编码格式。
         videoBitrate: 200000, // 视频比特率。
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
   // 转码完成回调函数。
   transcoder.on('complete', async () => {
     console.info(`transcode complete`);
     fs.closeSync(transcoder.fdDst); // 关闭fdDst。
     await transcoder?.release()
     workerPort.postMessage('complete');
   })
   ```

5. 主线程接收到worker线程转码结束的信息，销毁worker线程。

   ```ts
   // 注册onmessage回调，当宿主线程接收到来自其创建的Worker通过workerPort.postMessage接口发送的消息时被调用，在宿主线程执行。
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

## 运行示例工程

参考以下示例，使用worker线程的方式来实现异步线程进行转码。

1. 新建工程，下载[完整示例工程](https://gitee.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVTranscoder/AsyncTranscoder)，并将示例工程的资源复制到对应目录。
    ```
    AsyncTranscoder
    entry/build-profile.json5 (配置字段信息将Worker线程文件打包到应用)
    entry/src/main/ets/
    ├── pages
    │    └── Index.ets (转码界面)
    ├── util
    │    └── SendableObject.ets (Sendable对象)
    │
    └── workers
        └── task.ets (转码任务)

    entry/src/main/resources/
    ├── base
    │   ├── element
    │   │   ├── color.json
    │   │   ├── float.json
    │   │   └── string.json
    │   └── media
    │
    └── rawfile
        └── H264_AAC.mp4 (视频资源)
    ```
2. 编译新建工程并运行。