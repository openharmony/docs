# 预览(C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

预览是启动相机后看见的画面，通常在拍照和录像前执行。

## 开发步骤

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/capi-oh-camera.md)。

1. 导入NDK接口，接口中提供了相机相关的属性和方法，导入方法如下。
     
   ```c++
   // 导入NDK接口头文件。
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
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libohcamera.so
       libhilog_ndk.z.so
   )
   ```

3. 获取SurfaceId。
     
    XComponent组件为预览流提供的SurfaceId，而XComponent的能力由UI提供，相关介绍可参考[XComponent组件参考](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)。

4. 根据传入的SurfaceId，通过[OH_CameraManager_GetSupportedCameraOutputCapability()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_getsupportedcameraoutputcapability)方法获取当前设备支持的预览能力。通过[OH_CameraManager_CreatePreviewOutput()](../../reference/apis-camera-kit/capi-camera-manager-h.md#oh_cameramanager_createpreviewoutput)方法创建预览输出流，其中，OH_CameraManager_CreatePreviewOutput()方法中的参数分别是cameraManager指针，previewProfiles数组中的第一项，步骤三中获取的surfaceId，以及返回的previewOutput指针。
     
    ```c++
    Camera_PreviewOutput* CreatePreviewOutput(char* previewSurfaceIdstr, Camera_Manager* cameraManager,
        const Camera_Profile* previewProfile)
    {
        Camera_PreviewOutput* previewOutput = nullptr;
        Camera_ErrorCode ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile,
            previewSurfaceIdstr, &previewOutput);
        if (previewOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
        }
        return previewOutput;
    }
    ```

5. 使能。当session完成CommitConfig后通过调用[OH_CaptureSession_Start()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_start)方法输出预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。

   ```c++
   Camera_ErrorCode SessionStart(Camera_CaptureSession* captureSession)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Start(captureSession);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
       }
       return ret;
   }
   ```

6. 通过[OH_CaptureSession_Stop()](../../reference/apis-camera-kit/capi-capture-session-h.md#oh_capturesession_stop)方法停止预览流，接口调用失败会返回相应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。

   ```c++
   Camera_ErrorCode SessionStop(Camera_CaptureSession* captureSession)
   {
       Camera_ErrorCode ret = OH_CaptureSession_Stop(captureSession);
       if (ret != CAMERA_OK) {
           OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed.");
       }
       return ret;
   }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听预览输出流状态，包括预览流启动、预览流结束、预览流输出错误。

- 通过注册固定的frameStart回调函数获取监听预览启动结果，previewOutput创建成功时即可监听，预览第一次曝光时触发，有该事件返回结果则认为预览流已启动。

  ```c++
  void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
  }
  ```

- 通过注册固定的frameEnd回调函数获取监听预览结束结果，previewOutput创建成功时即可监听，预览完成最后一帧时触发，有该事件返回结果则认为预览流已结束。
    
  ```c++
  void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
  {
      OH_LOG_INFO(LOG_APP, "PreviewOutput frameCount = %{public}d", frameCount);
  }
  ```

- 通过注册固定的error回调函数获取监听预览输出错误结果，callback返回预览输出接口使用错误时对应的错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/capi-camera-h.md#camera_errorcode)。
    
  ```c++
  void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
  {
      OH_LOG_ERROR(LOG_APP, "PreviewOutput errorCode = %{public}d", errorCode);
  }
  ```
  ```c++
  PreviewOutput_Callbacks* GetPreviewOutputListener(void)
  {
      static PreviewOutput_Callbacks previewOutputListener = {
          .onFrameStart = PreviewOutputOnFrameStart,
          .onFrameEnd = PreviewOutputOnFrameEnd,
          .onError = PreviewOutputOnError
      };
      return &previewOutputListener;
  }
  Camera_ErrorCode RegisterPreviewOutputCallback(Camera_PreviewOutput* previewOutput)
  {
      Camera_ErrorCode ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
      if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
      }
      return ret;
  }
  ```