# 使用AVRecorder录制音频(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--Designer: @HmQQQ-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

使用[AVRecorder](media-kit-intro.md#avrecorder)可以实现音频录制功能，本开发指导将以“开始录制-暂停录制-恢复录制-停止录制”的一次流程为示例，向开发者讲解AVRecorder音频录制相关功能。

在进行应用开发的过程中，开发者可以通过AVRecorder的state属性，主动获取当前状态或使用on('stateChange')方法监听状态变化。开发过程中应该严格遵循状态机要求，例如只能在started状态下调用pause()接口，只能在paused状态下调用resume()接口。

**图1** 录制状态变化示意图

![Recording status change](figures/recording-status-change.png)

状态的详细说明请参考[AVRecorderState](../../reference/apis-media-kit/arkts-apis-media-t.md#avrecorderstate9)。

## 申请权限

在开发此功能前，开发者应根据实际需求申请相关权限：

- 当需要使用麦克风时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要读取和保存音频文件时，请优先使用[AudioViewPicker音频选择器对象](../../reference/apis-core-file-kit/js-apis-file-picker.md#audioviewpicker)。

> **说明：**
>
> 仅应用需要克隆、备份或同步用户公共目录的音频类文件时，可申请ohos.permission.READ_AUDIO、ohos.permission.WRITE_AUDIO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。

## 开发音频录制应用须知

- 如果需要持续录制或后台录制，请申请长时任务避免进入挂起（Suspend）状态。具体参考[长时任务开发指导](../../task-management/continuous-task.md)。
- 录制需要在前台启动，启动后可以退后台。在后台启动录制将会失败。
- 应用录制音频时需要使用合适的录制流类型，请参考[使用合适的音频流类型](../audio/using-right-streamusage-and-sourcetype.md)。

## 开发步骤及注意事项

详细的API说明请参考[AVRecorder API参考](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md)。

1. 创建AVRecorder实例，实例创建完成进入idle状态。

   > **说明：**
   >
   > 需要在avRecorder完成赋值后，再进行剩余操作。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private avRecorder: media.AVRecorder | undefined = undefined;

   try {
     this.avRecorder = await media.createAVRecorder();
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to create avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

2. 设置业务需要的监听事件，监听状态变化及错误上报。
   | 事件类型 | 说明 |
   | -------- | -------- |
   | stateChange | 必要事件，监听AVRecorder的state属性改变。 |
   | error | 必要事件，监听AVRecorder的错误信息。 |

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   // 状态上报回调函数。
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
     // 用户可以在此补充状态发生切换后想要进行的动作。
   });

   // 错误上报回调函数。
   this.avRecorder?.on('error', (error) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. 配置音频录制参数，调用prepare()接口，此时进入prepared状态。

   > **说明：**
   > 配置参数需要注意：
   >
   > - 配置参数之前需要确保完成对应权限的申请，请参考[申请权限](#申请权限)。
   >
   > - prepare接口的入参avConfig中仅设置音频相关的配置参数，如示例代码所示。
   >   如果只需要录制音频，请不要设置视频相关配置参数；如果需要录制视频，可以参考[视频录制开发指导](video-recording.md)进行开发。直接设置视频相关参数会导致后续步骤报错。
   > - 需要使用支持的[录制规格](media-kit-intro.md#支持的格式)，具体录制参数需严格契合既定的[录制参数配置](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9)。
   > - 录制输出的url地址（即示例里avConfig中的url），形式为fd://xx (fd number)。需要基础文件操作接口（[Core File Kit的ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/app-file-access.md)。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   let avProfile: media.AVRecorderProfile = {
     audioBitrate: 112000, // 音频比特率。
     audioChannels: 2, // 音频声道数。
     audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式，当前支持AAC，MP3，G711MU。
     audioSampleRate: 48000, // 音频采样率。
     fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // 封装格式，当前支持MP4，M4A，MP3，WAV，AMR，AAC。
   };
   
   const context: Context = this.getUIContext().getHostContext()!; // 参考应用文件访问与管理。
   let filePath: string = context.filesDir + '/example.mp3';
   let audioFile: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   let fileFd: number = audioFile.fd; // 获取文件fd。
    
   let avConfig: media.AVRecorderConfig = {
     audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // 音频输入源，这里设置为麦克风。
     profile: avProfile,
     url: 'fd://' + fileFd.toString(), // 参考应用文件访问与管理中的开发示例获取创建的音频文件fd填入此处。
   };
  
   try {
     await this.avRecorder?.prepare(avConfig);
     console.info('Succeeded in preparing avRecorder');
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to prepare avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

4. 开始录制，调用start()接口，此时进入started状态。

   ```ts
   // 开始录制。
   await this.avRecorder?.start();
   ```

5. 暂停录制，调用pause()接口，此时进入paused状态。

   ```ts
   // 暂停录制。
   await this.avRecorder?.pause();
   ```

6. 恢复录制，调用resume()接口，此时再次进入started状态。

   ```ts
   // 恢复录制。
   await this.avRecorder?.resume();
   ```

7. 停止录制，调用stop()接口，此时进入stopped状态。

   ```ts
   // 停止录制。
   await this.avRecorder?.stop();
   ```

8. 重置资源，调用reset()重新进入idle状态，允许重新配置录制参数。

   ```ts
   // 重置资源。
   await this.avRecorder?.reset();
   ```

9. 销毁实例，调用release()进入released状态，退出录制。

   ```ts
   // 销毁实例。
   await this.avRecorder?.release();
   ```

## 完整示例

  参考以下示例，完成“开始录制-暂停录制-恢复录制-停止录制”的完整流程。

```ts
import { common } from '@kit.AbilityKit';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs } from '@kit.CoreFileKit';

async function audioRecording(context: common.Context): Promise<void> {
  // 创建avRecorder对象。
  let avRecorder: media.AVRecorder | undefined = undefined;
  try {
    avRecorder = await media.createAVRecorder();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create avRecorder, error code: ${err.code}, message: ${err.message}`);
    return;
  }
  
  // 注册avRecorder回调函数。
  try {
    // 状态机变化回调函数。
    avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
      console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
    });
    // 错误上报回调函数。
    avRecorder.on('error', (error: BusinessError) => {
      console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to set avRecorder callback, error code: ${err.code}, message: ${err.message}`);
  }

  let avProfile: media.AVRecorderProfile = {
    audioBitrate: 112000, // 音频比特率。
    audioChannels: 2, // 音频声道数。
    audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式，当前支持AAC，MP3，G711MU。
    audioSampleRate: 48000, // 音频采样率。
    fileFormat: media.ContainerFormatType.CFT_MPEG_4A, // 封装格式，当前支持MP4，M4A，MP3，WAV，AMR，AAC。
  };
  let avConfig: media.AVRecorderConfig = {
    audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // 音频输入源，这里设置为麦克风。
    profile: avProfile,
    url: 'fd://35', // 参考应用文件访问与管理开发示例新建并读写一个文件。
  };

  // 创建文件以及设置avConfig.url。
  let audioFile: fs.File | undefined = undefined;
  try {
    let path: string = context.filesDir + '/example.mp3'; // 文件沙箱路径，文件后缀名应与封装格式对应。
    audioFile = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE); // 打开文件。
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open file, error code: ${err.code}, message: ${err.message}`);
  }
  if (audioFile !== undefined) {
    avConfig.url = 'fd://' + audioFile.fd; // 更新url。
  }
  
  // 配置录制参数完成准备工作。
  try {
    if (avRecorder.state === 'idle' || avRecorder.state === 'stopped') { // 仅在idle或者stopped状态下调用prepare为合理状态切换。
      await avRecorder.prepare(avConfig);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 开始录制。
  try {
    if (avRecorder.state === 'prepared') { // 仅在prepared状态下调用start为合理状态切换。
      await avRecorder.start();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to start avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 暂停录制。
  try {
    if (avRecorder.state === 'started') { // 仅在started状态下调用pause为合理状态切换。
      await avRecorder.pause();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 恢复录制。
  try {
    if (avRecorder.state === 'paused') { // 仅在paused状态下调用resume为合理状态切换。
      await avRecorder.resume();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to resume avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 停止录制。
  try {
    if (avRecorder.state === 'started' || avRecorder.state === 'paused') { // 仅在started或者paused状态下调用stop为合理状态切换。
      await avRecorder.stop();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to stop avRecorder, error code: ${err.code}, message: ${err.message}`);
  }
  
  // 重置。
  try {
    await avRecorder.reset();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to reset avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 释放录制实例。
  try {
    await avRecorder.release();
    avRecorder = undefined;
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to release avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 关闭录制文件fd。
  try {
    if (audioFile !== undefined) {
      await fs.close(audioFile.fd);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
  }
}
```
