# 使用AVRecorder录制视频(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--Designer: @HmQQQ-->
<!--Tester: @xdlinc-->
<!--Adviser: @zengyawen-->

当前仅支持[AVRecorder](media-kit-intro.md#avrecorder)开发视频录制，集成了音频捕获，音频编码，视频编码，音视频封装功能，适用于实现简单视频录制并直接得到视频本地文件的场景。

本开发指导将以“开始录制-暂停录制-恢复录制-停止录制”的一次流程为示例，向开发者讲解如何使用AVRecorder进行视频录制。

在进行应用开发的过程中，开发者可以通过AVRecorder的state属性主动获取当前状态，或使用on('stateChange')方法监听状态变化。开发过程中应该严格遵循状态机要求，例如只能在started状态下调用pause()接口，只能在paused状态下调用resume()接口。

**图1** 录制状态变化示意图

![Recording status change](figures/video-recording-status-change.png)

状态的详细说明请参考[AVRecorderState](../../reference/apis-media-kit/arkts-apis-media-t.md#avrecorderstate9)。


## 申请权限

在开发此功能前，开发者应根据实际需求申请相关权限：
- 当需要使用麦克风时，需要申请**ohos.permission.MICROPHONE**麦克风权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要使用相机拍摄时，需要申请**ohos.permission.CAMERA**相机权限。申请方式请参考：[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。
- 当需要从图库读取图片或视频文件时，请优先使用媒体库[Picker选择媒体资源](../medialibrary/photoAccessHelper-photoviewpicker.md)。
- 当需要保存图片或视频文件至图库时，请优先使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)。

> **说明：**
>
> 仅应用需要克隆、备份或同步用户公共目录的图片、视频类文件时，可申请ohos.permission.READ_IMAGEVIDEO、ohos.permission.WRITE_IMAGEVIDEO权限来读写音频文件，申请方式请参考<!--RP1-->[申请受控权限](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->。


## 开发步骤及注意事项

> **说明：**
>
> AVRecorder只负责视频数据的处理，需要与视频数据采集模块配合才能完成视频录制。视频数据采集模块需要通过Surface将视频数据传递给AVRecorder进行数据处理。当前主流的数据采集模块为相机模块，详细实现请参考[相机-录像](../camera/camera-recording.md)。
> 关于文件的创建与存储操作，请参考[应用文件访问与管理](../../file-management/app-file-access.md)，默认存储在应用的沙箱路径之下，如需存储至图库，请使用[安全控件保存媒体资源](../medialibrary/photoAccessHelper-savebutton.md)对沙箱内文件进行存储。


AVRecorder详细的API说明请参考[AVRecorder API参考](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md)。

1. 创建AVRecorder实例，实例创建完成进入idle状态。

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
   | stateChange | 必要事件，监听播放器的state属性改变。 |
   | error | 必要事件，监听播放器的错误信息。 |

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   // 状态上报回调函数。
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
   });
   // 错误上报回调函数。
   this.avRecorder?.on('error', (error: BusinessError) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. 配置视频录制参数，调用prepare()接口，此时进入prepared状态。

   > **说明：**
   >
   > 配置参数需要注意：
   >
   > - 配置参数之前需要确保完成对应权限的申请，请参考[申请权限](#申请权限)。
   >
   > - prepare接口的入参avConfig中仅设置视频相关的配置参数，如示例代码所示。
   >   如果添加了音频参数，系统将认为是“音频+视频录制”。
   >
   > - 需要使用支持的[录制规格](media-kit-intro.md#支持的格式)，视频比特率、分辨率、帧率以实际硬件设备支持的范围为准。
   >
   > - 录制输出的url地址（即示例里avConfig中的url），形式为fd://xx (fd number)。需要调用基础文件操作接口（[Core File Kit的ohos.file.fs](../../reference/apis-core-file-kit/js-apis-file-fs.md)）实现应用文件访问能力，获取方式参考[应用文件访问与管理](../../file-management/app-file-access.md)。

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   let avProfile: media.AVRecorderProfile = {
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4。
     videoBitrate: 200000, // 视频比特率。
     videoCodec: media.CodecMimeType.VIDEO_AVC, // 视频文件编码格式，支持avc格式。
     videoFrameWidth: 640,  // 视频分辨率的宽。
     videoFrameHeight: 480, // 视频分辨率的高。
     videoFrameRate: 30 // 视频帧率。
   };

   let videoMetaData: media.AVMetadata = {
     videoOrientation: '0' // 视频旋转角度，默认为0不旋转，支持的值为0、90、180、270。
   };

   const context: Context = this.getUIContext().getHostContext()!; // 参考应用文件访问与管理。
   let filePath: string = context.filesDir + '/example.mp4';
   let videoFile: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   let fileFd: number = videoFile.fd; // 获取文件fd。
  
   let avConfig: media.AVRecorderConfig = {
     videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // 视频源类型，支持YUV和ES两种格式。
     profile: avProfile,
     url: 'fd://' + fileFd.toString(), // 参考应用文件访问与管理开发示例新建并读写一个视频文件。
     metadata: videoMetaData
   };

   try {
     await this.avRecorder?.prepare(avConfig);
     console.info('Succeeded in preparing avRecorder');
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to prepare avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

4. 获取视频录制需要的SurfaceID。
   调用getInputSurface()接口，接口的返回值SurfaceID用于传递给视频数据输入源模块。常用的输入源模块为相机，以下示例代码中，采用相机作为视频输入源为例。

     输入源模块通过SurfaceID可以获取到Surface，通过Surface可以将视频数据流传递给AVRecorder，由AVRecorder再进行视频数据的处理。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   this.avRecorder?.getInputSurface().then((surfaceId: string) => {
     console.info('Succeeded in getting input surface');
   }, (error: BusinessError) => {
     console.error(`Failed to get input surface, error code: ${error.code}, message: ${error.message}`);
   });
   ```

5. 初始化视频数据输入源。该步骤需要在输入源模块完成，以相机为例，需要创建录像输出流，包括创建Camera对象、获取相机列表、创建相机输入流等，相机详细步骤请参考[相机-录像方案](../camera/camera-recording.md)。

6. 开始录制，启动输入源输入视频数据，例如相机模块调用camera.VideoOutput.start接口启动相机录制。然后调用AVRecorder.start()接口，此时AVRecorder进入started状态。

7. 暂停录制，调用pause()接口，此时AVRecorder进入paused状态，同时暂停输入源输入数据。例如相机模块调用camera.VideoOutput.stop停止相机视频数据输入。

8. 恢复录制，调用resume()接口，此时再次进入started状态。

9. 停止录制，调用stop()接口，此时进入stopped状态，同时停止相机录制。

10. 重置资源，调用reset()重新进入idle状态，允许重新配置录制参数。

11. 销毁实例，调用release()进入released状态，退出录制，释放视频数据输入源相关资源，例如相机资源。


## 完整示例

参考以下示例，完成“开始录制-暂停录制-恢复录制-停止录制”的完整流程。


```ts
import { common } from '@kit.AbilityKit';
import { camera } from '@kit.CameraKit';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs, fileUri } from '@kit.CoreFileKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function videoRecording(context: common.Context): Promise<void> {
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

  // 配置录制参数完成准备工作。
  let avProfile: media.AVRecorderProfile = {
    fileFormat: media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4。
    videoBitrate: 100000, // 视频比特率。
    videoCodec: media.CodecMimeType.VIDEO_AVC, // 视频文件编码格式，支持avc格式。
    videoFrameWidth: 640,  // 视频分辨率的宽。
    videoFrameHeight: 480, // 视频分辨率的高。
    videoFrameRate: 30 // 视频帧率。
  };
  let videoMetaData: media.AVMetadata = {
    videoOrientation: '0' // 视频旋转角度，默认为0不旋转，支持的值为0、90、180、270。
  };
  let avConfig: media.AVRecorderConfig = {
    videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // 视频源类型，支持YUV和ES两种格式。
    profile: avProfile,
    url: 'fd://35', //  参考应用文件访问与管理开发示例新建并读写一个文件。
    metadata: videoMetaData
  };

  // 创建文件以及设置avConfig.url。
  let filePath: string = ''; // 文件路径。
  let videoFile: fs.File | undefined = undefined;
  try {
    filePath = context.filesDir + '/example.mp4'; // 文件沙箱路径，文件后缀名应与封装格式对应。
    videoFile = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE); // 打开文件。
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open file, error code: ${err.code}, message: ${err.message}`);
  }
  if (videoFile !== undefined) {
    avConfig.url = 'fd://' + videoFile.fd; // 更新url。
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

  // 完成相机相关准备工作。
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let videoOutSurfaceId: string = await avRecorder.getInputSurface();
  await prepareCamera(cameraManager, videoOutSurfaceId);

  // 启动录制。
  try {
    if (avRecorder.state === 'prepared') { // 仅在prepared状态下调用start为合理状态切换。
      await startCameraOutput(); // 启动相机出流。
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
      await stopCameraOutput(); // 停止相机出流。
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // 恢复录制。
  try {
    if (avRecorder.state === 'paused') { // 仅在paused状态下调用resume为合理状态切换。
      await startCameraOutput(); // 启动相机出流。
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
      await stopCameraOutput(); // 停止相机出流。
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
    if (videoFile !== undefined) {
      await fs.close(videoFile.fd);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
  }

  // 释放相机相关实例。
  await releaseCamera();
  
  // 安全控件保存媒体资源至图库。
  let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  // 需要确保uriPath对应的资源存在。
  let uriPath: string = fileUri.getUriFromPath(filePath); // 获取录制文件的uri，用于安全控件保存至图库。
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = 
    photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(context, uriPath);
  await phAccessHelper.applyChanges(assetChangeRequest);
}

// 相机相关准备工作。
async function prepareCamera(cameraManager: camera.CameraManager, videoOutSurfaceId: string) {
  // 具体实现查看相机资料。
}

// 启动相机出流。
async function startCameraOutput() {
  // 调用VideoOutput的start接口开始录像输出。
}

// 停止相机出流。
async function stopCameraOutput() {
  // 调用VideoOutput的stop接口停止录像输出。
}

// 释放相机实例。
async function releaseCamera() {
  // 释放相机准备阶段创建出的实例。
}
```
