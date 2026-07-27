# 使用AVRecorder录制音频（ArkTS）
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->

使用[AVRecorder](media-kit-intro.md#avrecorder)可以实现音频录制功能，本开发指导将以“开始录制-暂停录制-恢复录制-停止录制”的一次流程为例，向开发者讲解AVRecorder音频录制相关功能。

在进行应用开发的过程中，开发者可以通过AVRecorder的state属性，主动获取当前状态或使用[on('stateChange')](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#onstatechange9)方法监听状态变化。开发过程中必须严格遵循状态机要求，例如只能在started状态下调用[pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1)接口，只能在paused状态下调用[resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1)接口。

**图1** 录制状态变化示意图

![Recording status change](figures/audio-recording-status-change.png)

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
- 应用录制音频时需要使用合适的录制流类型，请参考[选择合适的录制流类型](../audio/using-right-sourcetype-for-recording.md)。
- 应用录制音频时需要切换输入设备路由，请参考[实现音频输入设备路由切换](../audio/audio-input-device-switcher.md)。

## 开发步骤及注意事项

详细的API说明请参考[AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md)。

1. 创建AVRecorder实例，实例创建完成进入idle状态。

   > **说明：**
   >
   > 需要在avRecorder完成赋值后，再进行剩余操作。

   <!-- @[create_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   this.avRecorder = await media.createAVRecorder();
   ```

2. 设置业务需要的监听事件，监听状态变化及错误上报。
   | 事件类型 | 说明 |
   | -------- | -------- |
   | stateChange | 必要事件，监听AVRecorder的state属性改变。 |
   | error | 必要事件，监听AVRecorder的错误信息。 |

   <!-- @[set_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
     // 用户可以在此补充状态发生切换后想要进行的动作。
     onStateChanged(state, reason);
   });
   this.avRecorder?.on('error', (error: BusinessError) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. 配置音频录制参数，调用[prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1)接口，此时进入prepared状态。

   > **说明：**
   > 配置参数需要注意：
   >
   > - 配置参数之前需要确保完成对应权限的申请，请参考[申请权限](#申请权限)。
   >
   > - prepare接口的入参config中仅设置音频相关的配置参数，如示例代码所示。
   >   如果只需要录制音频，请不要设置视频相关配置参数；如果需要录制视频，可以参考[视频录制开发指导](video-recording.md)进行开发。直接设置视频相关参数会导致后续步骤报错。
   > - 需要使用支持的[录制规格](media-kit-intro.md#支持的格式)，具体录制参数配置可参考[AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9)。
   > - 录制输出的URL地址（即示例里avRecorderConfig中的url），形式为fd://xx（fd number）。需要基础文件操作接口（[Core File Kit的ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/app-file-access.md)。
   > - 示例中配置的audioCodec音频编码格式、fileFormat封装格式请参考[AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9)。

   <!-- @[prepare_audio_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   public async prepareAudioRecorder(context: common.Context): Promise<void> {
     let path: string = context.filesDir + '/audio_example.m4a';
     let file: fileIo.File = await fileIo.open(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
     this.fileFd = file.fd;
   
     let avRecorderConfig: media.AVRecorderConfig = {
       audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // 音频源类型。
       profile: {
         audioBitrate: 112000, // 音频比特率。
         audioChannels: 2, // 音频声道数。
         audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式。
         audioSampleRate: this.audioSampleRate, // 音频采样率。
         fileFormat: media.ContainerFormatType.CFT_MPEG_4A // 封装格式。
       } as media.AVRecorderProfile,
       url: 'fd://' + file.fd.toString()
     };
   
     try {
       if (this.avRecorder?.state === 'idle' || this.avRecorder?.state === 'stopped') {
         await this.avRecorder?.prepare(avRecorderConfig);
       }
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
       await this.closeFd();
     }
   }
   ```

4. 开始录制，调用[start](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#start9-1)接口，此时进入started状态。

   <!-- @[start_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.start();
   ```

5. 暂停录制，调用[pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1)接口，此时进入paused状态。

   <!-- @[pause_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.pause();
   ```

6. 恢复录制，调用[resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1)接口，此时再次进入started状态。

   <!-- @[resume_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.resume();
   ```

7. 停止录制，调用[stop](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#stop9-1)接口，此时进入stopped状态。

   <!-- @[stop_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.stop();
   await this.closeFd();
   ```

8. 重置资源，调用[reset](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#reset9-1)接口，重新进入idle状态，允许重新配置录制参数。

   <!-- @[reset_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.reset();
   ```

9. 销毁实例，调用[release](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#release9-1)接口，进入released状态，退出录制。

   <!-- @[release_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->
   
   ``` TypeScript
   await this.avRecorder?.release();
   ```

## 完整示例

  参考以下示例，完成“开始录制-暂停录制-恢复录制-停止录制”的完整流程。

  使用当前示例代码时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

<!-- @[full_audio_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { Resolution } from './CommonTypes';

export default class AVRecorderService {
  private avRecorder: media.AVRecorder | undefined = undefined;
  private fileFd: number | undefined = undefined;

  private audioSampleRate: number = 48000;
  private videoSourceType: media.VideoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV;
  private videoResolution: Resolution = { frameWidth: 1920, frameHeight: 1080 } as Resolution;

  public async createRecorder(): Promise<void> {
    await this.releaseRecorder();
    try {
      this.avRecorder = await media.createAVRecorder();
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`Failed to create avRecorder, error code: ${error.code}, message: ${error.message}`);
    }
  }

  public setCallback(onStateChanged: media.OnAVRecorderStateChangeHandler): void {
    if (this.avRecorder) {
      console.info('setCallback');
    }
    this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
      console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
      // 用户可以在此补充状态发生切换后想要进行的动作。
      onStateChanged(state, reason);
    });
    this.avRecorder?.on('error', (error: BusinessError) => {
      console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
    });
  }

  // ...

  public async prepareAudioRecorder(context: common.Context): Promise<void> {
    let path: string = context.filesDir + '/audio_example.m4a';
    let file: fileIo.File = await fileIo.open(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    this.fileFd = file.fd;

    let avRecorderConfig: media.AVRecorderConfig = {
      audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC, // 音频源类型。
      profile: {
        audioBitrate: 112000, // 音频比特率。
        audioChannels: 2, // 音频声道数。
        audioCodec: media.CodecMimeType.AUDIO_AAC, // 音频编码格式。
        audioSampleRate: this.audioSampleRate, // 音频采样率。
        fileFormat: media.ContainerFormatType.CFT_MPEG_4A // 封装格式。
      } as media.AVRecorderProfile,
      url: 'fd://' + file.fd.toString()
    };

    try {
      if (this.avRecorder?.state === 'idle' || this.avRecorder?.state === 'stopped') {
        await this.avRecorder?.prepare(avRecorderConfig);
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
      await this.closeFd();
    }
  }

  // ...

  public async startRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'prepared') {
        await this.avRecorder?.start();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async pauseRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'started') {
        await this.avRecorder?.pause();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async resumeRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'paused') {
        await this.avRecorder?.resume();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to resume avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async stopRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'started' || this.avRecorder?.state === 'paused') {
        await this.avRecorder?.stop();
        await this.closeFd();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to stop avRecorder, error code: ${err.code}, message: ${err.message}`);
      await this.closeFd();
    }
  }

  public async resetRecorder(): Promise<void> {
    try {
      await this.avRecorder?.reset();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to reset avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async releaseRecorder(): Promise<void> {
    try {
      this.avRecorder?.off('stateChange');
      this.avRecorder?.off('error');
      await this.avRecorder?.release();
      this.avRecorder = undefined;
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to release avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async closeFd(): Promise<void> {
    try {
      if (this.fileFd) {
        await fileIo.close(this.fileFd!);
        this.fileFd = undefined;
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
    }
  }
}
```
