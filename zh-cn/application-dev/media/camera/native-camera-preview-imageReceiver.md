# 预览流二次处理(C/C++)

通过ImageReceiver创建预览输出，获取预览流实时数据，以供后续进行图像二次处理，比如应用可以对其添加滤镜算法等。

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
   
   通过image的createImageReceiver()方法创建ImageReceiver实例，再通过实例的getReceivingSurfaceId()方法获取SurfaceId。

4. 根据传入的SurfaceId，通过OH_CameraManager_GetSupportedCameraOutputCapability()方法获取当前设备支持的预览能力。通过OH_CameraManager_CreatePreviewOutput()方法创建预览输出流，其中，OH_CameraManager_CreatePreviewOutput()方法中的参数分别是cameraManager指针、previewProfiles数组中的第一项、步骤三中获取的surfaceId，以及返回的previewOutput指针。
     
   ```c++
    NDKCamera::NDKCamera(char *str)
    {
      Camera_Manager *cameraManager = nullptr;
      Camera_Device* cameras = nullptr;
      Camera_OutputCapability* cameraOutputCapability = nullptr;
      Camera_PreviewOutput* previewOutput = nullptr;
      const Camera_Profile* previewProfile = nullptr;
      uint32_t size = 0;
      uint32_t cameraDeviceIndex = 0;
      char* previewSurfaceId = str;
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
      if (cameraOutputCapability->previewProfilesSize < 0) {
        OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
      }
      previewProfile = cameraOutputCapability->previewProfiles[0];
      
      ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
      if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
      }
    }
   ```

5. 使能。当session完成CommitConfig后通过调用start()方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
     
   ```c++
    ret = OH_PreviewOutput_Start(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Start failed.");
    }
   ```

6. 通过stop()方法停止预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
     
   ```c++
    ret = OH_PreviewOutput_Stop(previewOutput);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Stop failed.");
    }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。
    
  ```c++
    ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
    }
  ```
  ```c++
    void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
    }
    PreviewOutput_Callbacks* GetPreviewOutputListener(void)
    {
        static PreviewOutput_Callbacks previewOutputListener = {
            .onFrameStart = PreviewOutputOnFrameStart,
            .onFrameEnd = PreviewOutputOnFrameEnd,
            .onError = PreviewOutputOnError
        };
        return &previewOutputListener;
    }
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```c++
    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
    
  ```c++
    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
    }
  ```