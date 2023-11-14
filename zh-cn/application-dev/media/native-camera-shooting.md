# 拍照(Native)

拍照是相机的最重要功能之一，拍照模块基于相机复杂的逻辑，为了保证用户拍出的照片质量，在中间步骤可以设置分辨率、闪光灯、焦距、照片质量及旋转角度等信息。

## 开发步骤

详细的API说明请参考[Camera API参考](../reference/apis/js-apis-camera.md)。

1. 导入image接口。创建拍照输出流的SurfaceId以及拍照输出的数据，都需要用到系统提供的image接口能力，导入image接口的方法如下。
     
   ```ts
   // ts侧需要导入image接口，通过ImageReceiver获取拍照的surfaceId
   import image from '@ohos.multimedia.image';
   private mReceiver: image.ImageReceiver = undefined
   ```

2. 获取SurfaceId。
   
   通过image的createImageReceiver方法创建ImageReceiver实例，再通过实例的getReceivingSurfaceId方法获取SurfaceId，与拍照输出流相关联，获取拍照输出流的数据。
 
   ```ts
   // 获取拍照的surfaceId （参考ndk demo：在modeSwitchPage.ets中调用）
    async getPhotoSurfaceID() {
        if(this.mReceiver) {
        Logger.info(this.tag, 'imageReceiver has been created')
        } else {
        this.createImageReceiver()
        }
        this.photoSurfaceId = await this.mReceiver.getReceivingSurfaceId()
        if(this.photoSurfaceId) {
        Logger.info(this.tag, `createImageReceiver photoSurfaceId: ${this.photoSurfaceId} `)
        } else {
        Logger.info(this.tag, `Get photoSurfaceId failed `)
        }
    }
   ```

3. 在CMake脚本中链接Camera NDK动态库。
   ```txt
    target_link_libraries(PUBLIC libcamera_ndk.so)
   ```


4. 导入NDK接口。创建拍照输出数据、配置相机参数以及触发拍照流程，都需要用到系统提供的NDK接口能力，导入NDK接口的方法如下。

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

5. 创建拍照输出流。
   
   通过OH_CameraManager_GetSupportedCameraOutputCapability方法，可获取当前设备支持的拍照输出流，通过OH_CameraManager_CreatePhotoOutput方法传入支持的某一个输出流及步骤二获取的SurfaceId创建拍照输出流。

   ```c++
    Camera_Manager* cameraManager = nullptr;
    Camera_Device* cameras = nullptr;
    Camera_CaptureSession* captureSession = nullptr;
    Camera_OutputCapability* cameraOutputCapability = nullptr;
    const Camera_Profile* previewProfile = nullptr;
    const Camera_Profile* photoProfile = nullptr;
    Camera_PreviewOutput* previewOutput = nullptr;
    Camera_PhotoOutput* photoOutput = nullptr;
    Camera_Input* cameraInput = nullptr;
    uint32_t size = 0;
    uint32_t cameraDeviceIndex = 0;

    Camera_ErrorCode ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex], &cameraOutputCapability);
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
   ```

6. 参数配置。

   配置相机的参数可以调整拍照的一些功能，包括闪光灯、变焦、焦距等。

   ```c++
    // 判断设备是否支持闪光灯
    Camera_FlashMode flashMode = FLASH_MODE_AUTO;
    bool hasFlash = false;
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

7. 触发拍照。

   - 通过OH_PhotoOutput_Capture方法，执行拍照任务。该方法有一个参数，该参数为CreatePhotoOutput时的回调参Camera_PhotoOutput** photoOutput。

   ```c++
    Camera_ErrorCode ret = OH_PhotoOutput_Capture(photoOutput);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
    }
   ```

   - 通过OH_PhotoOutput_Capture_WithCaptureSetting方法，执行拍照任务。该方法有两个参数，第一个参数为拍照设置参数的setting，setting中可以设置照片的质量和旋转角度，第二参数为回调函数。
 
   ```c++
    Camera_PhotoCaptureSetting* photoSetting = nullptr;
    photoSetting->quality = QUALITY_LEVEL_HIGH; // 设置图片质量高
    photoSetting->rotation = IAMGE_ROTATION_0; // 设置图片旋转角度0

    // 使用当前拍照设置进行拍照
    ret = OH_PhotoOutput_Capture_WithCaptureSetting(photoOutput, photoSetting);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture_WithCaptureSetting success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture_WithCaptureSetting failed. %d ", ret);
    }
   ```

## 状态监听

在相机应用开发过程中，可以随时监听拍照输出流状态，包括拍照流开始、拍照帧的开始与结束、拍照输出流的错误。

- 通过注册固定的onFrameStart回调函数获取监听拍照开始结果，photoOutput创建成功时即可监听，拍照第一次曝光时触发。
    
  ```c++
    void PhotoOutputOnFrameStart(Camera_PhotoOutput* photoOutput)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutputOnFrameStart");
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
    Camera_ErrorCode ret = OH_PhotoOutput_RegisterCallback(photoOutput, GetPhotoOutputListener());
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_RegisterCallback failed.");
    }
  ```

- 通过注册固定的onFrameEnd回调函数获取监听拍照结束结果，photoOutput创建成功时即可监听，该事件返回结果为拍照完全结束后的相关信息[CaptureEndInfo](../reference/apis/js-apis-camera.md#captureendinfo)。
    
  ```c++
    void PhotoOutputOnFrameEnd(Camera_PhotoOutput* photoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput frameCount = %{public}d", frameCount);
    }
  ```

- 通过注册固定的onError回调函数获取监听拍照输出流的错误结果。callback返回拍照输出接口使用错误时的对应错误码，错误码类型参见[CameraErrorCode](../reference/apis/js-apis-camera.md#cameraerrorcode)。
    
  ```c++
    void PhotoOutputOnError(Camera_PhotoOutput* photoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PhotoOutput errorCode = %{public}d", errorCode);
    }
  ```

## 相关实例

针对拍照，有以下相关实例可供参考：
- [拍照(Native)](https://gitee.com/openharmony/multimedia_camera_framework/tree/master/frameworks/native/camera/test/ndktest/camera_ndk_demo)