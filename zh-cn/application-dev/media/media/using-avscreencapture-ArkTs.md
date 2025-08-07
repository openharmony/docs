# 使用AVScreenCaptureRecorder录屏写文件(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @zzs_911-->
<!--SE: @stupig001-->
<!--TSE: @xdlinc-->

屏幕录制主要为主屏幕录屏功能。

开发者可以调用录屏（[AVScreenCaptureRecorder](media-kit-intro.md#avscreencapture)）模块的ArkTs接口，完成屏幕录制，采集设备内、麦克风等的音视频源数据。可以调用录屏模块获取音视频文件，然后通过文件的形式流转到其他模块进行播放或处理，达成文件形式分享屏幕内容的场景。

录屏模块和窗口（Window）、图形（Graphic）等模块协同完成整个视频采集的流程。

使用AVScreenCaptureRecorder录制屏幕涉及到AVScreenCaptureRecorder实例的创建、音视频采集参数的配置、采集的开始与停止、资源的释放等。

开始屏幕录制时正在通话中或者屏幕录制过程中来电，录屏将自动停止。因通话中断的录屏会上报SCREENCAPTURE_STATE_STOPPED_BY_CALL状态。

本开发指导将以完成一次屏幕数据录制的过程为例，向开发者讲解如何使用AVScreenCaptureRecorder进行屏幕录制，详细的API声明请参考[AVScreenCaptureRecorder API参考](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md)。

如果配置了采集麦克风音频数据，需对应配置麦克风权限ohos.permission.MICROPHONE和申请长时任务，配置方式请参见[向用户申请权限](../../security/AccessToken/request-user-authorization.md)、[申请长时任务](../../task-management/continuous-task.md)。

## 申请权限

在开发此功能前，开发者应根据实际需求申请相关权限：

- 当需要使用麦克风时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要读取图片或视频文件时，请优先使用媒体库[Picker选择媒体资源](../medialibrary/photoAccessHelper-photoviewpicker.md)。
- 当需要保存图片或视频文件时，请优先使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)。

> **说明：**
>
> 仅应用需要克隆、备份或同步用户公共目录的图片、视频类文件时，可申请ohos.permission.READ_IMAGEVIDEO、ohos.permission.WRITE_IMAGEVIDEO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。

## 开发步骤及注意事项

使用AVScreenCaptureRecorder时要明确其状态的变化，在创建实例后，调用对应的方法可以进入指定的状态实现对应的行为。在确定的状态下执行不合适的方法会导致AVScreenCaptureRecorder发生错误，开发者需要在调用状态转换的方法前进行状态检查，避免程序运行异常。

1. 添加头文件。

    ```javascript
    import media from '@ohos.multimedia.media';
    import fs from '@ohos.file.fs';
    ```

2. 创建AVScreenCaptureRecorder类型的成员变量screenCapture。

    ```javascript
    // 声明一个AVScreenCaptureRecorder类型的变量。
    private screenCapture?: media.AVScreenCaptureRecorder;
    // 创建一个AVScreenCaptureRecorder，并赋值给screenCapture成员变量。
    this.screenCapture = await media.createAVScreenCaptureRecorder();
    ```

3. 对成员变量screenCapture设置监听函数，分别监听不同状态和异常情况。

    ```javascript
    this.screenCapture.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
    	switch (infoType) {
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
              	console.info("录屏成功开始后会收到的回调");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
                this.screenCapture?.release();
                this.screenCapture = undefined;
              	console.info("不允许使用录屏功能");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
                this.screenCapture?.release();
                this.screenCapture = undefined;
              	console.info("通过录屏胶囊结束录屏，底层录制会停止");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
                console.info("录屏因其他中断而停止，底层录制会停止");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
                console.info("录屏过程因通话中断，底层录制会停止");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
                console.info("录屏麦克风不可用");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
                console.info("录屏麦克风被用户静音");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
                console.info("录屏麦克风被用户取消静音");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
                // 目前可以从系统直接注册监听到进入隐私场景。
                console.info("录屏进入隐私场景");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
                console.info("录屏退出隐私场景");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
                console.info("用户账号切换，底层录制会停止");
                break;
            default:
              	break;
        }
    })
    this.screenCapture.on('error', (err) => {
        console.error("处理异常情况");
    })
    ```

4. 配置屏幕录制参数。

    ​创建AVScreenCaptureRecorder实例screenCapture后，可以设置屏幕录制所需要的参数。

    ​参数videoBitrate、audioSampleRate、audioChannelCount、audioBitrate、preset、displayId为可选参数，若不设置则可按默认值进行设置，如下示例中提供了可选参数的默认值。麦克风和系统音的音频流共用一套音频参数，分别是音频采样率、音频通道数和音频比特率，对应audioSampleRate、audioChannelCount和audioBitrate参数。

    参数fd可以参考应用文件访问与管理的开发实例[新建并读写一个文件fd](../../file-management/app-file-access.md)。本示例中提供的getFileFd()仅作为参考。

    2in1设备配置displayId为扩展屏Id，可拉起录屏窗口选择界面，用户在界面上选择录屏内容，最终录屏内容以用户在弹窗界面上的选择为准。

    ```javascript
    public getFileFd(): number {
      let filesDir = '/data/storage/el2/base/haps';
      let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      return file.fd;
    }

    captureConfig: media.AVScreenCaptureRecordConfig = {
        // 开发者可以根据自身的需要设置宽高。
        frameWidth: 768,
        frameHeight: 1280,
        // 参考应用文件访问与管理开发示例新建并读写一个文件fd。
        fd: this.getFileFd(),
        // 可选参数及其默认值。
        videoBitrate: 10000000,
        audioSampleRate: 48000,
        audioChannelCount: 2,
        audioBitrate: 96000,
        displayId: 0,
        preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
    };
    ```

5. 基于预先配置的屏幕录制参数，调用init()方法初始化screenCapture。

    ```javascript
    await this.screenCapture.init(this.captureConfig);
    ```

6. 创建豁免隐私窗口，这里填写的是子窗口id和主窗口id，具体开发步骤可参见[窗口API](../../reference/apis-arkui/arkts-apis-window-i.md#windowproperties)。

    ```javascript
    let windowIDs = [57, 86];
    await screenCapture.skipPrivacyMode(windowIDs);
    ```

7. 调用startRecording()方法开始进行屏幕录制，并通过监听函数监听状态。

    ```javascript
    await this.screenCapture.startRecording();
    ```

8. 停止录屏。

    - 点击录屏胶囊中的结束按钮停止录制：基于回调函数实现，录屏对象实例screenCapture会触发SCREENCAPTURE_STATE_STOPPED_BY_USER的回调，通知应用此次录屏已停止，不需要开发者主动调用stopRecording()方法。

    - 应用主动调用stopRecording()方法，停止录屏。

      ```javascript
      await this.screenCapture.stopRecording();
      ```

9. 调用release()方法销毁实例，释放资源。

    ```javascript
    await this.screenCapture.release();
    ```

## 完整示例

下面展示了使用AVScreenCaptureRecorder屏幕录屏存文件的完整示例代码。

```javascript
import media from '@ohos.multimedia.media';
import fs from '@ohos.file.fs';

export class AVScreenCaptureDemo {
  private screenCapture?: media.AVScreenCaptureRecorder;
  captureConfig: media.AVScreenCaptureRecordConfig = {
    // 开发者可以根据自身的需要设置宽高。
    frameWidth: 768,
    frameHeight: 1280,
    // 参考应用文件访问与管理开发示例新建并读写一个文件fd。
    fd: this.getFileFd(),
    // 可选参数及其默认值。
    videoBitrate: 10000000,
    audioSampleRate: 48000,
    audioChannelCount: 2,
    audioBitrate: 96000,
    displayId: 0,
    preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
  };

  public getFileFd(): number {
    let filesDir = '/data/storage/el2/base/haps';
    let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    return file.fd;
  }

  // 调用startRecording方法可以开始一次录屏存文件的流程，结束录屏可以通过点击录屏胶囊停止按钮进行操作。
  public async startRecording() {
    this.screenCapture = await media.createAVScreenCaptureRecorder();
    if (this.screenCapture != undefined) {
      // success.
    } else {
      // failed.
        return;
    }
    this.screenCapture?.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
      switch (infoType) {
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
          console.info("录屏成功开始后会收到的回调");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info("不允许使用录屏功能");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info("通过录屏胶囊结束录屏，底层录制会停止");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
          console.info("录屏因其他中断而停止，底层录制会停止");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
          console.info("录屏过程因通话中断，底层录制会停止");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
          console.info("录屏麦克风不可用");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
          console.info("录屏麦克风被用户静音");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
          console.info("录屏麦克风被用户取消静音");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
          // 目前可以从系统直接注册监听到进入隐私场景。
          console.info("录屏进入隐私场景");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
          console.info("录屏退出隐私场景");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
          console.info("用户账号切换，底层录制会停止");
          break;
        default:
          break;
      }
    })
    this.screenCapture?.on('error', (err) => {
      console.error("处理异常情况");
    })
    await this.screenCapture?.init(this.captureConfig);

    // 豁免隐私窗口。
    let windowIDs = [57, 86];
    await this.screenCapture?.skipPrivacyMode(windowIDs);

    await this.screenCapture?.startRecording();
  }

  // 可以主动调用stopRecording方法来停止录屏。
  public async stopRecording() {
    if (this.screenCapture == undefined) {
      // Error.
      return;
    }
    await this.screenCapture?.stopRecording();

    // 调用release()方法销毁实例，释放资源。
    await this.screenCapture?.release();

    // 最后需要关闭创建的录屏文件fd, fs.close(fd);
  }
}
```