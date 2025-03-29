# 使用AVTranscoder实现视频转码(ArkTS)

使用[AVTranscoder](media-kit-intro.md#avtranscoder)可以实现视频转码功能<!--RP1--><!--RP1End-->。可以通过调用[canIUse](../../reference/common/js-apis-syscap.md)接口来判断当前设备是否支持AVTranscoder，canIUse("SystemCapability.Multimedia.Media.AVTranscoder")返回值为true，表示可以使用转码能力。

本开发指导将以“开始转码-暂停转码-恢复转码-转码完成”的一次流程为示例，向开发者讲解AVTranscoder视频转码相关功能。

## 开发步骤及注意事项

详细的API说明请参考[AVTranscoder API参考](../../reference/apis-media-kit/js-apis-media.md#avtranscoder12)。
> **说明：**
>
> 如需对转码后的文件进行转发、上传、转存等处理，应用须收到complete事件后调用系统接口await avTranscoder.release()，以保证视频文件完整性。

1. 创建AVTranscoder实例。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let avTranscoder: media.AVTranscoder;
   media.createAVTranscoder().then((transcoder: media.AVTranscoder) => {
     avTranscoder = transcoder;
     // 需要在avTranscoder完成赋值后，再进行其他操作。
   }, (error: BusinessError) => {
     console.error(`createAVTranscoder failed`);
   });
   ```

2. 设置业务需要的监听事件，监听状态变化及错误上报。

   | 事件类型 | 说明 | 
   | -------- | -------- |
   | complete | 必要事件，监听AVTranscoder的转码完成。 | 
   | error | 必要事件，监听AVTranscoder的错误信息。 |

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   
   // 转码完成回调函数。
   avTranscoder.on('complete', async () => {
     console.log(`transcoder is completed`);
     // 用户须在此监听转码完成事件，并调用release
     // 须等待avTranscoder.release()完成之后，再对转码后的文件进行转发、上传、转存等处理
     await avTranscoder.release();
     avTranscoder = undefined;
   });
   
   // 错误上报回调函数。
   avTranscoder.on('error', (err: BusinessError) => {
     console.error(`avTranscoder failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

3. 设置源视频文件fd：设置属性fdSrc。
   > **说明：**
   >
   > 下面代码示例中的fdSrc仅作示意使用，开发者需根据实际情况，确认资源有效性并设置：
   > 
   > - 如果使用本地资源转码，必须确认资源文件可用，并使用应用沙箱路径访问对应资源，参考[获取应用文件路径](../../application-models/application-context-stage.md#获取应用文件路径)。应用沙箱的介绍及如何向应用沙箱推送文件，请参考[文件管理](../../file-management/app-sandbox-directory.md)。
   > 
   > - 如果使用ResourceManager.getRawFd()打开HAP资源文件描述符，使用方法可参考[ResourceManager API参考](../../reference/apis-localization-kit/js-apis-resource-manager.md#getrawfd9)。

   ```ts
   import resourceManager from '@ohos.resourceManager';
   import { common } from '@kit.AbilityKit';

   let context = getContext(this) as common.UIAbilityContext;
   let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
   // 设置转码的源文件属性fdSrc。
   this.avTranscoder.fdSrc = fileDescriptor;
   ```

4. 设置目标视频文件fd：设置属性fdDst。
   > **说明：**
   >
   > 转码输出文件fd（即示例里fdDst），形式为number。需要调用基础文件操作接口（[Core File Kit的ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/app-file-access.md)。
   
   ```ts
   // 设置转码的目标文件属性fdDst。
   this.avTranscoder.fdDst = 55; // 参考应用文件访问与管理中的开发示例获取创建的视频文件fd填入此处。
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
     videoFrameWidth: 640, // 视频分辨率的宽为640。
     videoFrameHeight: 480, // 视频分辨率的高为480。
   };
   avTranscoder.prepare(avConfig).then(() => {
     console.log('Invoke prepare succeeded.');
   }, (err: BusinessError) => {
     console.error(`Invoke prepare failed, code is ${err.code}, message is ${err.message}`);
   });
   ```

6. 开始转码，调用start()接口。

   ```ts
   // 开始转码。
   avTranscoder.start();
   ```

7. 暂停转码，调用pause()接口。

   ```ts
   // 暂停转码。
   avTranscoder.pause();
   ```

8. 恢复转码，调用resume()接口。

   ```ts
   // 恢复转码。
   avTranscoder.resume();
   ```

8. 取消转码，调用cancel()接口。

   ```ts
   // 取消转码。
   avTranscoder.cancel();
   ```

9. 销毁实例，调用release()接口，退出转码。

   ```ts
   // 销毁实例。
   avTranscoder.release();
   ```

## 完整示例

  参考以下示例，完成“开始转码-暂停转码-恢复转码-转码完成”的完整流程。
  
```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

export class AVTranscoderDemo {
  private avTranscoder: media.AVTranscoder | undefined = undefined;
  private avConfig: media.AVTranscoderConfig = {
    audioBitrate: 100000, // 音频比特率。
    audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式。
    fileFormat: media.ContainerFormatType.CFT_MPEG_4, // 封装格式。
    videoBitrate: 200000, // 视频比特率。
    videoCodec: media.CodecMimeType.VIDEO_AVC, // 视频编码格式。
    videoFrameWidth: 640, // 视频分辨率的宽。
    videoFrameHeight: 480, // 视频分辨率的高。
  };

  // 注册avTranscoder回调函数。
  setAVTranscoderCallback() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
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
      }
    }
  }

  // 开始转码对应的流程。
  async startTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) {
        await this.avTranscoder.release();
        this.avTranscoder = undefined;
      }
      // 1.创建转码实例。
      this.avTranscoder = await media.createAVTranscoder();
      this.setAVTranscoderCallback();
      // 2.获取转码源文件fd和目标文件fd赋予avTranscoder；参考FilePicker文档。
      let context = getContext(this) as common.UIAbilityContext;
      let fileDescriptor = await context.resourceManager.getRawFd('H264_AAC.mp4');
      this.avTranscoder.fdSrc = fileDescriptor;
      this.avTranscoder.fdDst = 55;
      // 3.配置转码参数完成准备工作。
      await this.avTranscoder.prepare(this.avConfig);
      // 4.开始转码。
      await this.avTranscoder.start();
    }
  }

  // 暂停转码对应的流程。
  async pauseTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) { // 仅在调用start返回后调用pause为合理调用。
        await this.avTranscoder.pause();
      }
    }
  }

  // 恢复对应的转码流程。
  async resumeTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) { // 仅在调用pause返回后调用resume为合理调用。
        await this.avTranscoder.resume();
      }
    }
  }

  // 释放转码流程。
  async releaseTranscoderingProcess() {
    if (canIUse("SystemCapability.Multimedia.Media.AVTranscoder")) {
      if (this.avTranscoder != undefined) {
        // 1.释放转码实例。
        await this.avTranscoder.release();
        this.avTranscoder = undefined;
        // 2.关闭转码目标文件fd。
      }
    }
  }

  // 一个完整的【开始转码-暂停转码-恢复转码-转码完成】示例。
  async avTranscoderDemo() {
    await this.startTranscoderingProcess(); // 开始转码。
    await this.pauseTranscoderingProcess(); //暂停转码。
    await this.resumeTranscoderingProcess(); // 恢复转码。
    await this.releaseTranscoderingProcess(); // 释放转码。
  }
}
```