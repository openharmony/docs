# 录像(Native)

录像也是相机应用的最重要功能之一，录像是循环帧的捕获。对于录像的流畅度，开发者可以参考拍照中的步骤4，设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考]。

1. 导入media模块。创建拍照输出流的SurfaceId以及拍照输出的数据，都需要用到系统提供的media接口能力，导入media接口的方法如下。
     
   ```ts
   // ts侧需要导入media接口
   import media from '@ohos.multimedia.media';
   ```

2. 创建Surface。
   
   系统提供的media接口可以创建一个录像AVRecorder实例，通过该实例的getInputSurface方法获取SurfaceId，与录像输出流做关联，处理录像输出流输出的数据。

   ```ts
    // ts侧获取video的surfaceId （参考ndk demo：在modeSwitchPage.ets中调用）
    async getVideoSurfaceID(){
      // 创建avRecorder
      this.videoRecorder = await media.createAVRecorder()
      this.fileAsset = await this.mediaUtil.createAndGetUri(mediaLibrary.MediaType.VIDEO)
      this.fd = await this.mediaUtil.getFdPath(this.fileAsset)
      this.videoConfig.url = `fd://${this.fd}`

      if (deviceInfo.deviceType == 'default') {
        Logger.info(this.tag, `deviceType = default`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_ES
      }
      if (deviceInfo.deviceType == 'phone') {
        Logger.info(this.tag, `deviceType = phone`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
        this.videoConfig.profile.videoCodec = media.CodecMimeType.VIDEO_MPEG4;
        if (this.cameraDeviceIndex == 1) {
          this.videoConfig.rotation = this.photoRotationMap.rotation270;
        } else {
          this.videoConfig.rotation = this.photoRotationMap.rotation90;
        }
      }
      if (deviceInfo.deviceType == 'tablet') {
        Logger.info(this.tag, `deviceType = tablet`)
        this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
      }

      this.videoConfig.profile.videoFrameWidth = 640;
      this.videoConfig.profile.videoFrameHeight = 480;
      this.videoConfig.profile.videoFrameRate = 30;
      // 设置视频录制的参数
      await this.videoRecorder.prepare(this.videoConfig)
      this.videoSurfaceId = await this.videoRecorder.getInputSurface()
    }
   ```
3. 在CMake脚本中链接Camera NDK动态库。

   ```txt
    target_link_libraries(PUBLIC libohcamera.so)
   ```

4. 导入NDK接口。创建录像输出数据、配置相机参数以及触发录像流程，都需要用到系统提供的NDK接口能力，导入NDK接口的方法如下。

   ```c++
    //导入NDK接口头文件 （参考ndk demo：在camera_manager.cpp中调用）
    #include "multimedia/camera_framework/camera.h"
    #include "multimedia/camera_framework/camera_input.h"
    #include "multimedia/camera_framework/capture_session.h"
    #include "multimedia/camera_framework/photo_output.h"
    #include "multimedia/camera_framework/preview_output.h"
    #include "multimedia/camera_framework/video_output.h"
    #include "multimedia/camera_framework/camera_manager.h"
   ```

5. 创建录像输出流。

   通过CameraOutputCapability类中的videoProfiles，可获取当前设备支持的录像输出流。然后，定义创建录像的参数，通过createVideoOutput方法创建录像输出流。

   **注**：预览流与录像输出流的分辨率的宽高比要保持一致，如示例代码中宽高比为640:480 = 4:3，则需要预览流中的分辨率的宽高比也为4:3，如分辨率选择640:480，或960:720，或1440:1080，以此类推

   ```ts
     // ts侧配置AVRecorderProfile（参考ndk demo：在modeSwitchPage.ets中调用）
     let aVRecorderProfile: media.AVRecorderProfile = {
       fileFormat : media.ContainerFormatType.CFT_MPEG_4, // 视频文件封装格式，只支持MP4
       videoBitrate : 100000, // 视频比特率
       videoCodec : media.CodecMimeType.VIDEO_MPEG4, // 视频文件编码格式，支持mpeg4和avc两种格式
       videoFrameWidth : 640,  // 视频分辨率的宽
       videoFrameHeight : 480, // 视频分辨率的高
       videoFrameRate : 30 // 视频帧率
     };
     // 创建视频录制的参数，预览流与录像输出流的分辨率的宽(videoFrameWidth)高(videoFrameHeight)比要保持一致
     let aVRecorderConfig: media.AVRecorderConfig = {
       videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
       profile: aVRecorderProfile,
       url: 'fd://35',
       rotation: 90 // 90°为默认竖屏显示角度，如果由于设备原因或应用期望以其他方式显示等原因，请根据实际情况调整该参数
     };
   ```
   ```c++
    // 获取相机设备支持的输出流能力
    ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                &cameraOutputCapability);
    if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
    }
    if (cameraOutputCapability->videorofilesSize < 0) {
      console.error("videorofilesSize == null");
    }
    videoProfile = cameraOutputCapability->videoProfiles[0];
     // 创建VideoOutput对象
    ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
    if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
    }
   ```

6. 开始录像。
   
   先通过videoOutput的start方法启动录像输出流，再通过avRecorder的start方法开始录像。

   ```c++
      // 启动录像输出流
      ret = OH_VideoOutput_Start(videoOutput);
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
      }
   ```
   ```ts
     // 开始录像 
     try {
       await avRecorder.start();
     } catch (error) {
       console.error(`avRecorder start error: ${JSON.stringify(err)}`);
     }
   ```

7. 停止录像。
     
   先通过avRecorder的stop方法停止录像，再通过videoOutput的stop方法停止录像输出流。
   ```ts
     // 停止录像 
     try {
       await avRecorder.stop();
     } catch (error) {
       console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
     }
   ```
   ```c++
      // 停止录像输出流
      ret = OH_VideoOutput_Stop(videoOutput);
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
      }
   ```


## 状态监听

在相机应用开发过程中，可以随时监听录像输出流状态，包括录像开始、录像结束、录像流输出的错误。

- 通过注册固定的frameStart回调函数获取监听录像开始结果，videoOutput创建成功时即可监听，录像第一次曝光时触发，有该事件返回结果则认为录像开始。
    
  ```c++
  void VideoOutputOnFrameStart(Camera_VideoOutput* videoOutput)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
  }

  VideoOutput_Callbacks* GetVideoOutputListener(void)
  {
      static VideoOutput_Callbacks videoOutputListener = {
          .onFrameStart = VideoOutputOnFrameStart,
          .onFrameEnd = VideoOutputOnFrameEnd,
          .onError = VideoOutputOnError
      };
      return &videoOutputListener;
  }
  ret = OH_VideoOutput_RegisterCallback(videoOutput_, GetVideoOutputListener());
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
  }
  ```

- 通过注册固定的frameEnd回调函数获取监听录像结束结果，videoOutput创建成功时即可监听，录像完成最后一帧时触发，有该事件返回结果则认为录像流已结束。
    
  ```c++
  void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的error回调函数获取监听录像输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode]。
    
  ```c++
  void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
  }
  ```

## 相关实例

针对录像，有以下相关实例可供参考：
- [录像(Native)](https://gitee.com/openharmony/multimedia_camera_framework/tree/master/frameworks/native/camera/test/ndktest/camera_ndk_demo)