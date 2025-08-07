# 使用AVRecorder录制视频(ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @shiwei75-->
<!--SE: @HmQQQ-->
<!--TSE: @xdlinc-->

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

   let avRecorder: media.AVRecorder;
   media.createAVRecorder().then((recorder: media.AVRecorder) => {
     avRecorder = recorder;
   }, (error: BusinessError) => {
     console.error('createAVRecorder failed');
   })
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
   this.avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info('current state is: ' + state);
   })
   // 错误上报回调函数。
   this.avRecorder.on('error', (err: BusinessError) => {
     console.error('error happened, error message is ' + err);
   })
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
     fileFormat : media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4。
     videoBitrate : 200000, // 视频比特率。
     videoCodec : media.CodecMimeType.VIDEO_AVC, // 视频文件编码格式，支持avc格式。
     videoFrameWidth : 640,  // 视频分辨率的宽。
     videoFrameHeight : 480, // 视频分辨率的高。
     videoFrameRate : 30 // 视频帧率。
   };

   let videoMetaData: media.AVMetadata = {
     videoOrientation: '0' // 视频旋转角度，默认为0不旋转，支持的值为0、90、180、270。
   };

   const context: Context = this.getUIContext().getHostContext()!; // 参考应用文件访问与管理。
   let filePath: string = context.filesDir + '/example.mp4';
   let videoFile: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   let fileFd = videoFile.fd; // 获取文件fd。
  
   let avConfig: media.AVRecorderConfig = {
     videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // 视频源类型，支持YUV和ES两种格式。
     profile : avProfile,
     url: 'fd://' + fileFd.toString(), // 参考应用文件访问与管理开发示例新建并读写一个视频文件。
     metadata : videoMetaData
   };
   this.avRecorder.prepare(avConfig).then(() => {
     console.info('avRecorder prepare success');
   }, (error: BusinessError) => {
     console.error('avRecorder prepare failed');
   })
   ```

4. 获取视频录制需要的SurfaceID。
   调用getInputSurface()接口，接口的返回值SurfaceID用于传递给视频数据输入源模块。常用的输入源模块为相机，以下示例代码中，采用相机作为视频输入源为例。

     输入源模块通过SurfaceID可以获取到Surface，通过Surface可以将视频数据流传递给AVRecorder，由AVRecorder再进行视频数据的处理。

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   this.avRecorder.getInputSurface().then((surfaceId: string) => {
     console.info('avRecorder getInputSurface success');
   }, (error: BusinessError) => {
     console.error('avRecorder getInputSurface failed');
   })
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
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs, fileUri } from '@kit.CoreFileKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';


const TAG = 'VideoRecorderDemo:';
export class VideoRecorderDemo extends CustomComponent {
  private context: Context;
  constructor() {
    super();
    this.context = this.getUIContext().getHostContext()!;
  }
  private avRecorder: media.AVRecorder | undefined = undefined;
  private videoOutSurfaceId: string = "";
  private avProfile: media.AVRecorderProfile = {
    fileFormat : media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4。
    videoBitrate : 100000, // 视频比特率。
    videoCodec : media.CodecMimeType.VIDEO_AVC, // 视频文件编码格式，支持avc格式。
    videoFrameWidth : 640,  // 视频分辨率的宽。
    videoFrameHeight : 480, // 视频分辨率的高。
    videoFrameRate : 30 // 视频帧率。
  };
  private videoMetaData: media.AVMetadata = {
    videoOrientation: '0' // 视频旋转角度，默认为0不旋转，支持的值为0、90、180、270。
  };
  private avConfig: media.AVRecorderConfig = {
    videoSourceType : media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // 视频源类型，支持YUV和ES两种格式。
    profile : this.avProfile,
    url : 'fd://35', //  参考应用文件访问与管理开发示例新建并读写一个文件。
    metadata : this.videoMetaData
  };
  
  private uriPath: string = ''; // 文件uri，可用于安全控件保存媒体资源。
  private filePath: string = ''; // 文件路径。
  private fileFd: number = 0;
  
  // 创建文件以及设置avConfig.url。
  async createAndSetFd() {
    const path: string = this.context.filesDir + '/example.mp4'; // 文件沙箱路径，文件后缀名应与封装格式对应。
    const videoFile: fs.File = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    this.avConfig.url = 'fd://' + videoFile.fd; // 设置url。
    this.fileFd = videoFile.fd; // 文件fd。
    this.filePath = path;
  }

  // 注册avRecorder回调函数。
  setAvRecorderCallback() {
    if (this.avRecorder != undefined) {
      // 状态机变化回调函数。
      this.avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
        console.info(TAG + 'current state is: ' + state);
      })
      // 错误上报回调函数。
      this.avRecorder.on('error', (err: BusinessError) => {
        console.error(TAG + 'error ocConstantSourceNode, error message is ' + err);
      })
    }
  }

  // 相机相关准备工作。
  async prepareCamera() {
    // 具体实现查看相机资料。
  }

  // 启动相机出流。
  async startCameraOutput() {
    // 调用VideoOutput的start接口开始录像输出。
  }

  // 停止相机出流。
  async stopCameraOutput() {
    // 调用VideoOutput的stop接口停止录像输出。
  }

  // 释放相机实例。
  async releaseCamera() {
    // 释放相机准备阶段创建出的实例。
  }

  // 开始录制对应的流程。
  async startRecordingProcess() {
    if (this.avRecorder === undefined) {
      // 1.创建录制实例。
      this.avRecorder = await media.createAVRecorder();
      this.setAvRecorderCallback();
    }
    // 2.获取录制文件fd，将获取到的值传递给avConfig中的url属性。
    await this.createAndSetFd();
    // 3.配置录制参数完成准备工作。
    await this.avRecorder.prepare(this.avConfig);
    this.videoOutSurfaceId = await this.avRecorder.getInputSurface();
    // 4.完成相机相关准备工作。
    await this.prepareCamera();
    // 5.启动相机出流。
    await this.startCameraOutput();
    // 6.启动录制。
    await this.avRecorder.start();

  }

  // 暂停录制对应的流程。
  async pauseRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'started') { // 仅在started状态下调用pause为合理状态切换。
      await this.avRecorder.pause();
      await this.stopCameraOutput(); // 停止相机出流。
    }
  }

  // 恢复录制对应的流程。
  async resumeRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'paused') { // 仅在paused状态下调用resume为合理状态切换。
      await this.startCameraOutput();  // 启动相机出流。
      await this.avRecorder.resume();
    }
  }

  async stopRecordingProcess() {
    if (this.avRecorder != undefined) {
      // 1.停止录制。
      if (this.avRecorder.state === 'started'
        || this.avRecorder.state === 'paused' ) { // 仅在started或者paused状态下调用stop为合理状态切换。
        await this.avRecorder.stop();
        await this.stopCameraOutput();
      }
      // 2.重置。
      await this.avRecorder.reset();
      // 3.释放录制实例。
      await this.avRecorder.release();
      // 4.文件录制完成后，关闭fd。
      await fs.close(this.fileFd);
      // 5.释放相机相关实例。
      await this.releaseCamera();
    }
  }
  
  // 安全控件保存媒体资源至图库。
  async saveRecorderAsset() {
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(this.context);
    // 需要确保uriPath对应的资源存在。
    this.uriPath = fileUri.getUriFromPath(this.filePath); // 获取录制文件的uri，用于安全控件保存至图库。
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = 
      photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(this.context, this.uriPath);
    await phAccessHelper.applyChanges(assetChangeRequest);
  }

  // 一个完整的【开始录制-暂停录制-恢复录制-停止录制】示例。
  async videoRecorderDemo() {
    await this.startRecordingProcess();         // 开始录制。
    // 用户此处可以自行设置录制时长，例如通过设置休眠阻止代码执行。
    await this.pauseRecordingProcess();         //暂停录制。
    await this.resumeRecordingProcess();        // 恢复录制。
    await this.stopRecordingProcess();          // 停止录制。
    // 安全控件保存媒体资源至图库。
    await this.saveRecorderAsset();
  }
}
```
