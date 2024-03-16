# 会话管理(C/C++)

相机使用预览、拍照、录像、元数据功能前，均需要创建相机会话。

在会话中，可以完成以下功能：

- 配置相机的输入流和输出流。相机在拍摄前，必须完成输入输出流的配置。
  配置输入流即添加设备输入，对用户而言，相当于选择设备的某一摄像头拍摄；配置输出流，即选择数据将以什么形式输出。当应用需要实现拍照时，输出流应配置为预览流和拍照流，预览流的数据将显示在XComponent组件上，拍照流的数据将通过ImageReceiver接口的能力保存到相册中。

- 添加闪光灯、调整焦距等配置。具体支持的配置及接口说明请参考[Camera API参考](../../reference/apis-camera-kit/_o_h___camera.md)。

- 会话切换控制。应用可以通过移除和添加输出流的方式，切换相机模式。如当前会话的输出流为拍照流，应用可以将拍照流移除，然后添加视频流作为输出流，即完成了拍照到录像的切换。

完成会话配置后，应用提交和开启会话，可以开始调用相机相关功能。

## 开发步骤

1. 导入NDK相关接口，导入方法如下。
     
   ```c++
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

3. 调用cameraManager类中的OH_CameraManager_CreateCaptureSession()方法创建一个会话。
     
   ```c++
    Camera_Manager *cameraManager = nullptr;
    Camera_Input* cameraInput = nullptr;
    Camera_PreviewOutput* previewOutput = nullptr;
    Camera_PhotoOutput* photoOutput = nullptr;
    Camera_VideoOutput* videoOutput = nullptr;
    Camera_CaptureSession* captureSession = nullptr;
    Camera_ErrorCode ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
    if (captureSession == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
    }
   ```

4. 调用captureSession类中的OH_CaptureSession_BeginConfig()方法配置会话。
     
   ```c++
    ret = OH_CaptureSession_BeginConfig(captureSession);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
    }
   ```

5. 使能。向会话中添加相机的输入流和输出流，调用OH_CaptureSession_AddInput()添加相机的输入流；调用OH_CaptureSession_AddPreviewOutput()和OH_CaptureSession_AddPhotoOutput()添加相机的输出流。以下示例代码以添加预览流previewOutput和拍照流photoOutput为例，即当前模式支持拍照和预览。

     调用captureSession类中的commitConfig()和start()方法提交相关配置，并启动会话。
     
   ```c++
    // 向会话中添加相机输入流
    ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
    }

    // 向会话中添加预览输出流
    ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
    }

    // 向会话中添加拍照输出流
    ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
    }

    // 提交会话配置
    ret = OH_CaptureSession_CommitConfig(captureSession);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
    }

    // 启动会话
    ret = OH_CaptureSession_Start(captureSession);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
    }
   ```

6. 会话控制。调用captureSession类中的stop()方法可以停止当前会话。调用removeOutput()和addOutput()方法可以完成会话切换控制。以下示例代码以移除拍照流photoOutput，添加视频流videoOutput为例，完成了拍照到录像的切换。
     
   ```c++
    ret = OH_CaptureSession_Stop(captureSession);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Stop success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed. %d ", ret);
    }
    ret = OH_CaptureSession_BeginConfig(captureSession);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
    }
    // 从会话中移除拍照输出流
    ret = OH_CaptureSession_RemovePhotoOutput(captureSession, photoOutput);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_RemovePhotoOutput success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RemovePhotoOutput failed. %d ", ret);
    }
     // 向会话中添加视频输出流
    ret = OH_CaptureSession_AddVideoOutput(captureSession, videoOutput);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_RemovePhotoOutput success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RemovePhotoOutput failed. %d ", ret);
    }
   ```