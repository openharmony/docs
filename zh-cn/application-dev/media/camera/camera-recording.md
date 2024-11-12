# 录像(ArkTS)

录像也是相机应用的最重要功能之一，录像是循环帧的捕获。对于录像的流畅度，开发者可以参考[拍照](camera-shooting.md)中的步骤4，设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

1. 导入media模块。创建录像输出流的SurfaceId以及录像输出的数据，都需要用到系统提供的[media接口](../../reference/apis-media-kit/js-apis-media.md)能力，导入media接口的方法如下。
     
   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   import { camera } from '@kit.CameraKit';
   import { media } from '@kit.MediaKit';
   ```

2. 创建Surface。
   
   系统提供的media接口可以创建一个录像AVRecorder实例，通过该实例的[getInputSurface](../../reference/apis-media-kit/js-apis-media.md#getinputsurface9)方法获取SurfaceId，与录像输出流做关联，处理录像输出流输出的数据。

   ```ts
   async function getVideoSurfaceId(aVRecorderConfig: media.AVRecorderConfig): Promise<string | undefined> {  // aVRecorderConfig可参考下一章节
     let avRecorder: media.AVRecorder | undefined = undefined;
     try {
       avRecorder = await media.createAVRecorder();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`createAVRecorder call failed. error code: ${err.code}`);
     }
     if (avRecorder === undefined) {
       return undefined;
     }
     avRecorder.prepare(aVRecorderConfig, (err: BusinessError) => {
       if (err == null) {
         console.info('prepare success');
       } else {
         console.error('prepare failed and error is ' + err.message);
       }
     });
     let videoSurfaceId = await avRecorder.getInputSurface();
     return videoSurfaceId;
   }
   ```

3. 创建录像输出流。

   通过[CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability)类中的videoProfiles属性，可获取当前设备支持的录像输出流。然后，定义创建录像的参数，通过[createVideoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createvideooutput)方法创建录像输出流。

   > **说明：**
   > 预览流与录像输出流的分辨率的宽高比要保持一致，如示例代码中宽高比为640:480 = 4:3，则需要预览流中的分辨率的宽高比也为4:3，如分辨率选择640:480，或960:720，或1440:1080，以此类推

   > 获取录像旋转角度的方法：通过[VideoOutput](../../reference/apis-camera-kit/js-apis-camera.md#videooutput)类中的[getVideoRotation](../../reference/apis-camera-kit/js-apis-camera.md#getvideorotation12)方法获取rotation实际的值

   ```ts
   async function getVideoOutput(cameraManager: camera.CameraManager, videoSurfaceId: string, cameraOutputCapability: camera.CameraOutputCapability): Promise<camera.VideoOutput | undefined> {
     let videoProfilesArray: Array<camera.VideoProfile> = cameraOutputCapability.videoProfiles;
     if (!videoProfilesArray) {
       console.error("createOutput videoProfilesArray == null || undefined");
       return undefined;
     }
     // AVRecorderProfile
     let aVRecorderProfile: media.AVRecorderProfile = {
       fileFormat : media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4
       videoBitrate : 100000, // 视频比特率
       videoCodec : media.CodecMimeType.VIDEO_AVC, // 视频文件编码格式，支持avc格式
       videoFrameWidth : 640,  // 视频分辨率的宽
       videoFrameHeight : 480, // 视频分辨率的高
       videoFrameRate : 30 // 视频帧率
     };
     // 创建视频录制的参数，预览流与录像输出流的分辨率的宽(videoFrameWidth)高(videoFrameHeight)比要保持一致
     let aVRecorderConfig: media.AVRecorderConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: aVRecorderProfile,
       url: 'fd://35',
       rotation: 90 // rotation的值90，是通过getPhotoRotation接口获取到的值，具体请参考说明中获取录像旋转角度的方法
     };
     // 创建avRecorder
     let avRecorder: media.AVRecorder | undefined = undefined;
     try {
       avRecorder = await media.createAVRecorder();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`createAVRecorder call failed. error code: ${err.code}`);
     }
     if (avRecorder === undefined) {
       return undefined;
     }
     // 设置视频录制的参数
     avRecorder.prepare(aVRecorderConfig);
     // 创建VideoOutput对象
     let videoOutput: camera.VideoOutput | undefined = undefined;
     // createVideoOutput传入的videoProfile对象的宽高需要和aVRecorderProfile保持一致。
     let videoProfile: undefined | camera.VideoProfile = videoProfilesArray.find((profile: camera.VideoProfile) => {
       return profile.size.width === aVRecorderProfile.videoFrameWidth && profile.size.height === aVRecorderProfile.videoFrameHeight;
     });
     if (!videoProfile) {
       console.error('videoProfile is not found');
       return;
     }
     try {
       videoOutput = cameraManager.createVideoOutput(videoProfile, videoSurfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error('Failed to create the videoOutput instance. errorCode = ' + err.code);
     }
     return videoOutput;
   }
   ```

4. 开始录像。
   
   先通过videoOutput的[start](../../reference/apis-camera-kit/js-apis-camera.md#start-1)方法启动录像输出流，再通过avRecorder的[start](../../reference/apis-media-kit/js-apis-media.md#start9)方法开始录像。

   ```ts
   async function startVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
     videoOutput.start(async (err: BusinessError) => {
       if (err) {
         console.error(`Failed to start the video output ${err.message}`);
         return;
       }
       console.info('Callback invoked to indicate the video output start success.');
     });
     try {
       await avRecorder.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`avRecorder start error: ${JSON.stringify(err)}`);
     }
   }
   ```

5. 停止录像。

   先通过avRecorder的[stop](../../reference/apis-media-kit/js-apis-media.md#stop9-3)方法停止录像，再通过videoOutput的[stop](../../reference/apis-camera-kit/js-apis-camera.md#stop-1)方法停止录像输出流。
     
   ```ts
   async function stopVideo(videoOutput: camera.VideoOutput, avRecorder: media.AVRecorder): Promise<void> {
     try {
       await avRecorder.stop();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
     }
     videoOutput.stop((err: BusinessError) => {
       if (err) {
         console.error(`Failed to stop the video output ${err.message}`);
         return;
       }
       console.info('Callback invoked to indicate the video output stop success.');
     });
   }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听录像输出流状态，包括录像开始、录像结束、录像流输出的错误。

- 通过注册固定的frameStart回调函数获取监听录像开始结果，videoOutput创建成功时即可监听，录像第一次曝光时触发，有该事件返回结果则认为录像开始。
    
  ```ts
  function onVideoOutputFrameStart(videoOutput: camera.VideoOutput): void {
    videoOutput.on('frameStart', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Video frame started');
    });
  }
  ```

- 通过注册固定的frameEnd回调函数获取监听录像结束结果，videoOutput创建成功时即可监听，录像完成最后一帧时触发，有该事件返回结果则认为录像流已结束。
    
  ```ts
  function onVideoOutputFrameEnd(videoOutput: camera.VideoOutput): void {
    videoOutput.on('frameEnd', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Video frame ended');
    });
  }
  ```

- 通过注册固定的error回调函数获取监听录像输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[CameraErrorCode](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode)。
    
  ```ts
  function onVideoOutputError(videoOutput: camera.VideoOutput): void {
    videoOutput.on('error', (error: BusinessError) => {
      console.error(`Video output error code: ${error.code}`);
    });
  }
  ```

<!--RP1-->
<!--RP1End-->