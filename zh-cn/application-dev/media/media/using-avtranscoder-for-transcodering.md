# 使用AVTranscoder实现视频转码(ArkTS)

使用[AVTranscoder](media-kit-intro.md#avtranscoder)可以实现视频转码功能<!--RP1--><!--RP1End-->。可以通过调用[canIUse](../../reference/common/js-apis-syscap.md)接口来判断当前设备是否支持AVTranscoder，canIUse("SystemCapability.Multimedia.Media.AVTranscoder")返回值为true，表示可以使用转码能力。

本开发指导将以“开始转码-暂停转码-恢复转码-转码完成”的一次流程为示例，向开发者讲解AVTranscoder视频转码相关功能。

## 开发步骤及注意事项

详细的API说明请参考[AVTranscoder API参考](../../reference/apis-media-kit/arkts-apis-media-AVTranscoder.md)。

> **说明：**
>
> 如需对转码后的文件进行转发、上传、转存等处理，应用须收到complete事件后调用系统接口await avTranscoder.release()，以保证视频文件完整性。

1. 创建AVTranscoder实例。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   private avTranscoder: media.AVTranscoder | undefined = undefined;
   // 创建转码实例。
   this.avTranscoder = await media.createAVTranscoder();
   ```

2. 设置业务需要的监听事件，监听状态变化及错误上报。

   | 事件类型 | 说明 | 
   | -------- | -------- |
   | complete | 必要事件，监听AVTranscoder的转码完成。 | 
   | error | 必要事件，监听AVTranscoder的错误信息。 |
   | progressUpdate | 监听AVTranscoder的进度。 |

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   private currentProgress: number = 0;

   if (this.avTranscoder != undefined) {
     // 转码完成回调函数。
     this.avTranscoder.on('complete', async () => {
       console.log(`AVTranscoder is completed`);
       await this.releaseTranscoderingProcess();
     });
     // 错误上报回调函数。
     this.avTranscoder.on('error', (err: BusinessError) => {
       console.error(`AVTranscoder failed, code is ${err.code}, message is ${err.message}`);
     });
     // 进度上报回调函数
     this.avTranscoder.on('progressUpdate', (progress: number) => {
       console.info(`AVTranscoder progressUpdate = ${progress}`);
       this.currentProgress = progress;
     })
   }

   // 获取当前进度。
   getCurrentProgress(): number {
     console.info(`getCurrentProgress = ${this.currentProgress}`);
     return this.currentProgress;
   }
   ```

3. 设置源视频文件fd：设置属性fdSrc。
   > **说明：**
   >
   > 下面代码示例中的fdSrc仅作示意使用，开发者需根据实际情况，确认资源有效性并设置：
   > 
   > - 如果使用本地资源转码，必须确认资源文件可用，并使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   > 
   > - 应通过Context属性获取应用文件路径，建议使用getUIContext获取UIContext实例，并使用getHostContext调用绑定实例的getContext，请参考[获取Context](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#gethostcontext12)。
   >
   > - 如果使用ResourceManager.getRawFd()打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。

   ```ts
   import {AVTranscoderDemo} from '../transcoder/AVTranscoderManager'

   @Entry
   @Component
   struct Index {
     // 获取当前组件所在Ability的Context，以通过Context获取应用文件路径。
     private context:Context | undefined = this.getUIContext().getHostContext();
     // 获取转码功能管理类。
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
             // 获取转码进度。
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
       this.context = context; // this.getUIContext().getHostContext();。
     }
   }
   // 获取输入文件fd，H264_AAC.mp4为rawfile目录下的预置资源，需要开发者根据实际情况进行替换。
   let fileDescriptor = await this.context.resourceManager.getRawFd('H264_AAC.mp4');
   // 设置转码的源文件属性fdSrc。
   this.avTranscoder.fdSrc = fileDescriptor;
   ```

4. 设置目标视频文件fd：设置属性fdDst。
   > **说明：**
   >
   > 转码输出文件fd（即示例里fdDst），形式为number。需要调用基础文件操作接口（[Core File Kit的ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/app-file-access.md)。
   
   ```ts
   import fs from '@ohos.file.fs';
   // 设置输出目标文件的沙箱路径。
   let outputFilePath = this.context.filesDir + "/output.mp4";
   // 文件不存在时创建并打开文件，文件存在时打开文件。
   let file = fs.openSync(outputFilePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   // 设置转码的目标文件属性fdDst。
   this.avTranscoder.fdDst = file.fd; // 参考应用文件访问与管理中的开发示例获取创建的视频文件fd填入此处。
   ```

5. 配置视频转码参数，调用prepare()接口。

   > **说明：**
   >
   > 写入配置参数时需要注意，prepare()接口的入参avConfig中仅设置转码相关的配置参数。<br>
   > 受限于解析/封装/编解码能力，只能使用[支持的转码格式](media-kit-intro.md#avtranscoder)。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avConfig: media.AVTranscoderConfig = {
     audioBitrate: 100000, // 音频比特率。
     audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式。
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // 封装格式。
     videoBitrate: 2000000, // 视频比特率。
     videoCodec: media.CodecMimeType.VIDEO_AVC, // 视频编码格式。
   };
   // 配置转码参数完成准备工作。
   await this.avTranscoder.prepare(this.avConfig);
   ```
   <!--RP2--><!--RP2End-->

6. 开始转码，调用start()接口。

   ```ts
   async startTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) {
         await this.avTranscoder.release();
         this.avTranscoder = undefined;
       }
      // 开始转码前需要创建转码实例、设置回调、设置fd并完成prepare。
      // 开始转码。
      await this.avTranscoder.start();
    }
   }
   ```

7. 暂停转码，调用pause()接口。

   ```ts
   // 暂停转码对应的流程。
   async pauseTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) { // 仅在调用start返回后调用pause为合理调用。
         await this.avTranscoder.pause();
       }
     }
   }
   ```

8. 恢复转码，调用resume()接口。

   ```ts
   // 恢复转码。
   async resumeTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) { // 仅在调用pause返回后调用resume为合理调用。
         await this.avTranscoder.resume();
       }
     }
   }
   ```

9. 销毁实例，调用release()接口，退出转码。

   ```ts
   // 销毁实例。
   async releaseTranscoderingProcess() {
     if (canIUse('SystemCapability.Multimedia.Media.AVTranscoder')) {
       if (this.avTranscoder != undefined) {
         // 1.销毁实例。
         await this.avTranscoder.release();
         this.avTranscoder = undefined;
         // 关闭转码目标文件fd。
         fs.closeSync(this.avTranscoder!.fdDst);
       }
     }
   }
   ```
10. 完整的【开始转码-暂停转码-恢复转码-转码完成】流程

   ```ts
   async avTranscoderDemo() {
     await this.startTranscoderingProcess(); // 开始转码。
     await this.pauseTranscoderingProcess(); //暂停转码。
     await this.resumeTranscoderingProcess(); // 恢复转码。
   }
   ```

## 运行示例工程

参考以下示例，完成“开始转码-暂停转码-恢复转码-转码完成”的完整流程。
  
1. 新建工程，下载[完整示例工程](https://gitcode.com/openharmony/applications_app_samples/tree/master/code/DocsSample/Media/AVTranscoder/AVTranscoderArkTS)，并将示例工程的资源复制到对应目录。
    ```
    AVTranscoderArkTS
    entry/src/main/ets/
    └── pages
    │    └── Index.ets (转码界面)
    │
    └── transcoder
        └── AVTranscoderManager.ets (转码功能)

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