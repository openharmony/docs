# 录像(C/C++)

录像也是相机应用的最重要功能之一，录像是循环帧的捕获。对于录像的流畅度，开发者可以参考[拍照参考](native-camera-shooting.md)中的步骤5，设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```c++
    // 导入NDK接口头文件
    #include "hilog/log.h"
    #include "ohcamera/camera.h"
    #include "ohcamera/camera_input.h"
    #include "ohcamera/capture_session.h"
    #include "ohcamera/photo_output.h"
    #include "ohcamera/preview_output.h"
    #include "ohcamera/video_output.h"
    #include "ohcamera/camera_manager.h"
   ```

2. 在CMake脚本中链接相关动态库。

   ```txt
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. 获取SurfaceId。
   
   系统提供的media接口可以创建一个录像AVRecorder实例，通过该实例的getInputSurface()方法获取SurfaceId。

4. 创建录像输出流。

   根据传入的SurfaceId，通过CameraOutputCapability类中的videoProfiles，可获取当前设备支持的录像输出流。然后，定义创建录像的参数，通过createVideoOutput()方法创建录像输出流。

   ```c++
    NDKCamera::NDKCamera(char *str)
    {
      Camera_Manager *cameraManager = nullptr;
      Camera_Device* cameras = nullptr;
      Camera_OutputCapability* cameraOutputCapability = nullptr;
      Camera_VideoOutput* videoOutput = nullptr;
      const Camera_VideoProfile* videoProfile;
      uint32_t size = 0;
      uint32_t cameraDeviceIndex = 0;
      char* videoSurfaceId = str;
      Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
      if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
      }
      ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
      if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
      }
      ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                  &cameraOutputCapability);
      if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
      }
      if (cameraOutputCapability->videoProfilesSize < 0) {
        OH_LOG_ERROR(LOG_APP, "videorofilesSize == null");
      }
      videoProfile = cameraOutputCapability->videoProfiles[0];
      // 创建VideoOutput对象
      ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
      if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
      }
    }
   ```

5. 开始录像。
   
   通过videoOutput的OH_VideoOutput_Start()方法启动录像输出流。

   ```c++
      // 启动录像输出流
      ret = OH_VideoOutput_Start(videoOutput);
      if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
      }
   ```

6. 停止录像。
     
   通过videoOutput的OH_VideoOutput_Stop()方法停止录像输出流。

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
    ret = OH_VideoOutput_RegisterCallback(videoOutput, GetVideoOutputListener());
    if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
    }
  ```
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
  ```

- 通过注册固定的frameEnd回调函数获取监听录像结束结果，videoOutput创建成功时即可监听，录像完成最后一帧时触发，有该事件返回结果则认为录像流已结束。
    
  ```c++
    void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的error回调函数获取监听录像输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
    
  ```c++
    void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
    }
  ```