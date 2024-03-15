# 拍照(C/C++)

拍照是相机的最重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

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

4. 创建拍照输出流。
   
   根据传入的SurfaceId，通过OH_CameraManager_GetSupportedCameraOutputCapability()方法，可获取当前设备支持的拍照输出流，通过OH_CameraManager_CreatePhotoOutput()方法传入支持的某一个输出流及步骤3获取的SurfaceId创建拍照输出流。

   ```c++
    NDKCamera::NDKCamera(char *str)
    {
        Camera_Manager* cameraManager = nullptr;
        Camera_Device* cameras = nullptr;
        Camera_OutputCapability* cameraOutputCapability = nullptr;
        Camera_PhotoOutput* photoOutput = nullptr;
        Camera_CaptureSession* captureSession = nullptr;
        const Camera_Profile* photoProfile = nullptr;
        uint32_t size = 0;
        uint32_t cameraDeviceIndex = 0;
        char* photoSurfaceId = str;
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
        }
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
        }
        ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex], &cameraOutputCapability);
        if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "GetSupportedCameraOutputCapability failed.");
        }
        photoProfile = cameraOutputCapability->photoProfiles[0];
        if (photoProfile == nullptr) {
            OH_LOG_ERROR(LOG_APP, "Get photoProfiles failed.");
        }
        ret = OH_CameraManager_CreatePhotoOutput(cameraManager, photoProfile, photoSurfaceId, &photoOutput);
        if (photoOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePhotoOutput failed.");
        }
    }
   ```

5. 参数配置。

   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。

   ```c++
    // 判断设备是否支持闪光灯
    Camera_FlashMode flashMode = FLASH_MODE_AUTO;
    bool hasFlash = false;
    ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
    if (captureSession == nullptr || ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
    }
    ret = OH_CaptureSession_HasFlash(captureSession, &hasFlash);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_HasFlash failed.");
    }
    if (hasFlash) {
        OH_LOG_INFO(LOG_APP, "hasFlash success");
    } else {
        OH_LOG_ERROR(LOG_APP, "hasFlash fail");
    }
    // 检测闪光灯模式是否支持
    bool isSupported = false;
    ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
    }
    if (isSupported) {
        OH_LOG_INFO(LOG_APP, "isFlashModeSupported success");
        // 设置闪光灯模式
        ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
        }
        // 获取当前设备的闪光灯模式
        ret = OH_CaptureSession_GetFlashMode(captureSession, &flashMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode：%{public}d ", flashMode);
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
        }
    } else {
        OH_LOG_ERROR(LOG_APP, "isFlashModeSupported fail");
    }

    // 判断是否支持连续自动变焦模式
    Camera_FocusMode focusMode = FOCUS_MODE_CONTINUOUS_AUTO;
    bool isFocusModeSupported = false;
    ret = OH_CaptureSession_IsFocusModeSupported(captureSession, focusMode, &isFocusModeSupported);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFocusModeSupported failed.");
    }
    if (isFocusModeSupported) {
        OH_LOG_INFO(LOG_APP, "isFocusModeSupported success");
        ret = OH_CaptureSession_SetFocusMode(captureSession, focusMode);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFocusMode failed. %{public}d ", ret);
        }
        ret = OH_CaptureSession_GetFocusMode(captureSession, &focusMode);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFocusMode success. focusMode%{public}d ", focusMode);
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFocusMode failed. %d ", ret);
        }
    } else {
        OH_LOG_ERROR(LOG_APP, "isFocusModeSupported fail");
    }

    // 获取相机支持的可变焦距比范围
    float minZoom;
    float maxZoom;
    ret = OH_CaptureSession_GetZoomRatioRange(captureSession, &minZoom, &maxZoom);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
    } else {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
            minZoom, maxZoom);
    }
    // 设置变焦
    ret = OH_CaptureSession_SetZoomRatio(captureSession, maxZoom);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
    }
    // 获取当前设备的变焦值
    ret = OH_CaptureSession_GetZoomRatio(captureSession, &maxZoom);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom：%{public}f ", maxZoom);
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
    }
   ```

6. 触发拍照。

    通过OH_PhotoOutput_Capture()方法，执行拍照任务。

     ```c++
      ret = OH_PhotoOutput_Capture(photoOutput);
      if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
      } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
      }
     ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的onFrameStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发。
    
  ```c++
    ret = OH_PhotoOutput_RegisterCallback(photoOutput, GetPhotoOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
    }
  ```
  ```c++
    void PhotoOutputOnFrameStart(Camera_PhotoOutput* photoOutput)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
    }
    void PhotoOutputOnFrameShutter(Camera_PhotoOutput* photoOutput, Camera_FrameShutterInfo* info)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameShutter");
    }
    PhotoOutput_Callbacks* GetPhotoOutputListener()
    {
        static PhotoOutput_Callbacks photoOutputListener = {
            .onFrameStart = PhotoOutputOnFrameStart,
            .onFrameShutter = PhotoOutputOnFrameShutter,
            .onFrameEnd = PhotoOutputOnFrameEnd,
            .onError = PhotoOutputOnError
        };
        return &photoOutputListener;
    }
  ```

- 通过注册固定的onFrameEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听。
    
  ```c++
    void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的onError回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[Camera_ErrorCode](../../reference/apis-camera-kit/_o_h___camera.md#camera_errorcode-1)。
    
  ```c++
    void PhotoOutputOnError(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
    }
  ```