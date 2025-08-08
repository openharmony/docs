# 拍照实践(C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

当前示例提供完整的拍照流程及其接口调用顺序的介绍。对于单个流程（如设备输入、会话管理、拍照）的介绍请参考[相机开发指导(Native)](camera-preparation.md)的具体章节。

## 开发流程

在获取到相机支持的输出流能力后，开始创建拍照流，开发流程如下。

![Photographing Development Process](figures/photographing-ndk-development-process.png)

## 完整示例

1. 在CMake脚本中链接相关动态库。
    ```txt
    target_link_libraries(entry PUBLIC
        libace_napi.z.so
        libhilog_ndk.z.so
        libnative_buffer.so
        libohcamera.so
        libohimage.so
        libohfileuri.so
    )
    ```
2. 创建头文件ndk_camera.h。
   ```c++
   #include "ohcamera/camera.h"
   #include "ohcamera/camera_input.h"
   #include "ohcamera/capture_session.h"
   #include "ohcamera/photo_output.h"
   #include "ohcamera/preview_output.h"
   #include "ohcamera/video_output.h"
   #include "ohcamera/camera_manager.h"
   
   class NDKCamera {
   public:
       ~NDKCamera();
       NDKCamera(char* previewId);
       Camera_ErrorCode RegisterBufferCb(void* cb);
   };
   ```

3. cpp侧导入NDK接口，并根据传入的SurfaceId进行拍照。
    ```c++
    #include "hilog/log.h"
    #include "ndk_camera.h"

    void CaptureSessionOnFocusStateChange(Camera_CaptureSession* session, Camera_FocusState focusState)
    {
        OH_LOG_INFO(LOG_APP, "CaptureSessionOnFocusStateChange");
    }

    void CaptureSessionOnError(Camera_CaptureSession* session, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "CaptureSessionOnError = %{public}d", errorCode);
    }

    CaptureSession_Callbacks* GetCaptureSessionRegister(void)
    {
        static CaptureSession_Callbacks captureSessionCallbacks = {
            .onFocusStateChange = CaptureSessionOnFocusStateChange,
            .onError = CaptureSessionOnError
        };
        return &captureSessionCallbacks;
    }

    void PreviewOutputOnFrameStart(Camera_PreviewOutput* previewOutput)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameStart");
    }

    void PreviewOutputOnFrameEnd(Camera_PreviewOutput* previewOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnFrameEnd = %{public}d", frameCount);
    }

    void PreviewOutputOnError(Camera_PreviewOutput* previewOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "PreviewOutputOnError = %{public}d", errorCode);
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

    void OnCameraInputError(const Camera_Input* cameraInput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "OnCameraInput errorCode = %{public}d", errorCode);
    }

    CameraInput_Callbacks* GetCameraInputListener(void)
    {
        static CameraInput_Callbacks cameraInputCallbacks = {
            .onError = OnCameraInputError
        };
        return &cameraInputCallbacks;
    }

    void CameraManagerStatusCallback(Camera_Manager* cameraManager, Camera_StatusInfo* status)
    {
        OH_LOG_INFO(LOG_APP, "CameraManagerStatusCallback is called");
    }

    CameraManager_Callbacks* GetCameraManagerListener()
    {
        static CameraManager_Callbacks cameraManagerListener = {
            .onCameraStatus = CameraManagerStatusCallback
        };
        return &cameraManagerListener;
    }

    static void* bufferCb = nullptr;
    Camera_ErrorCode NDKCamera::RegisterBufferCb(void* cb) {
        OH_LOG_INFO(LOG_APP, " RegisterBufferCb start");
        if (cb == nullptr) {
            OH_LOG_INFO(LOG_APP, " RegisterBufferCb invalid error");
            return CAMERA_INVALID_ARGUMENT;
        }
        bufferCb = cb;
    
        return CAMERA_OK;
    }
    void OnPhotoAvailable(Camera_PhotoOutput* photoOutput, OH_PhotoNative* photo) {
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable start!");
        OH_ImageNative* imageNative;
        Camera_ErrorCode errCode = OH_PhotoNative_GetMainImage(photo, &imageNative);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable errCode:%{public}d imageNative:%{public}p", errCode, imageNative);
        // 读取 OH_ImageNative 的 size 属性。
        Image_Size size;
        Image_ErrorCode imageErr = OH_ImageNative_GetImageSize(imageNative, &size);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d width:%{public}d height:%{public}d", imageErr,
            size.width, size.height);
        // 读取 OH_ImageNative 的组件列表的元素个数。
        size_t componentTypeSize = 0;
        imageErr = OH_ImageNative_GetComponentTypes(imageNative, nullptr, &componentTypeSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d componentTypeSize:%{public}zu", imageErr,
            componentTypeSize);
        // 读取 OH_ImageNative 的组件列表。
        uint32_t* components = new uint32_t[componentTypeSize];
        imageErr = OH_ImageNative_GetComponentTypes(imageNative, &components, &componentTypeSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetComponentTypes imageErr:%{public}d", imageErr);
        // 读取 OH_ImageNative 的第一个组件所对应的缓冲区对象。
        OH_NativeBuffer* nativeBuffer = nullptr;
        imageErr = OH_ImageNative_GetByteBuffer(imageNative, components[0], &nativeBuffer);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetByteBuffer imageErr:%{public}d", imageErr);
        // 读取 OH_ImageNative 的第一个组件所对应的缓冲区大小。
        size_t nativeBufferSize = 0;
        imageErr = OH_ImageNative_GetBufferSize(imageNative, components[0], &nativeBufferSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d nativeBufferSize:%{public}zu", imageErr,
             nativeBufferSize);
        // 读取 OH_ImageNative 的第一个组件所对应的像素行宽。
        int32_t rowStride = 0;
        imageErr = OH_ImageNative_GetRowStride(imageNative, components[0], &rowStride);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d rowStride:%{public}d", imageErr, rowStride);
        // 读取 OH_ImageNative 的第一个组件所对应的像素大小。
        int32_t pixelStride = 0;
        imageErr = OH_ImageNative_GetPixelStride(imageNative, components[0], &pixelStride);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d pixelStride:%{public}d", imageErr, pixelStride);
        // 将ION内存映射到进程空间。
        void* virAddr = nullptr; // 指向映射内存的虚拟地址，解除映射后这个指针将不再有效。
        int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr); // 映射后通过第二个参数virAddr返回内存的首地址。
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Map err:%{public}d", ret);
        // 通过回调函数，将处理完的buffer传给ArkTS侧做显示或通过安全控件写文件保存，参考拍照(C/C++)开发指导。
        auto cb = (void (*)(void *, size_t))(bufferCb);
        cb(virAddr, nativeBufferSize);
        // 在处理完之后，解除映射并释放缓冲区。
        ret = OH_NativeBuffer_Unmap(nativeBuffer);
        if (ret != 0) {
            OH_LOG_ERROR(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Unmap error:%{public}d", ret);
        }
    }

    NDKCamera::NDKCamera(char* previewId)
    {
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
        char* previewSurfaceId = previewId;
        // 创建CameraManager对象。
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraMananger failed.");
            return;
        }
        // 监听相机状态变化。
        ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
        }

        // 获取相机列表。
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size <= 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
            return;
        }

        if (size < cameraDeviceIndex + 1) {
            OH_LOG_ERROR(LOG_APP, "cameraDeviceIndex is invalid.");
            return;
        }

        // 创建相机输入流。
        ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
        if (cameraInput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
            return;
        }

        // 监听cameraInput错误信息。
        ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
            return;
        }

        // 打开相机。
        ret = OH_CameraInput_Open(cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Open failed.");
            return;
        }

        // 获取相机设备支持的输出流能力。
        ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                  &cameraOutputCapability);
        if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
            return;
        }

        if (cameraOutputCapability->previewProfiles == nullptr) {
            OH_LOG_ERROR(LOG_APP, "previewProfiles == null");
            return;
        }
        // 根据所需从cameraOutputCapability->previewProfiles中选择合适的预览分辨率
        previewProfile = cameraOutputCapability->previewProfiles[0];

        if (cameraOutputCapability->photoProfiles == nullptr) {
            OH_LOG_ERROR(LOG_APP, "photoProfiles == null");
            return;
        }
        // 根据所需从cameraOutputCapability->photoProfiles中选择合适的拍照分辨率
        photoProfile = cameraOutputCapability->photoProfiles[0];

        // 创建预览输出流,其中参数 previewSurfaceId 参考上文 XComponent 组件，预览流为XComponent组件提供的surface。
        ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
        if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
            return;
        }

        // 监听预览输出错误信息。
        ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
        }

        // 创建拍照输出流。
        ret = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager, photoProfile, &photoOutput);

        // 监听单端式拍照回调。
        ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);

        //创建会话。
        ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
        if (captureSession == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
            return;
        }

        // 监听session错误信息。
        ret = OH_CaptureSession_RegisterCallback(captureSession, GetCaptureSessionRegister());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RegisterCallback failed.");
        }

        // 开始配置会话。
        ret = OH_CaptureSession_BeginConfig(captureSession);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
            return;
        }

        // 向会话中添加相机输入流。
        ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
            return;
        }

        // 向会话中添加预览输出流。
        ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
            return;
        }

        // 向会话中添加拍照输出流。
        ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
            return;
        }

        // 提交会话配置。
        ret = OH_CaptureSession_CommitConfig(captureSession);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
            return;
        }

        // 启动会话。
        ret = OH_CaptureSession_Start(captureSession);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
            return;
        }

        // 判断设备是否支持闪光灯。
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
        
        // 检测闪光灯模式是否支持。
        bool isSupported = false;
        ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
        }
        if (isSupported) {
            OH_LOG_INFO(LOG_APP, "isFlashModeSupported success");

            // 设置闪光灯模式。
            ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
            if (ret == CAMERA_OK) {
                OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
            } else {
                OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
            }

            // 获取当前设备的闪光灯模式。
            ret = OH_CaptureSession_GetFlashMode(captureSession, &flashMode);
            if (ret == CAMERA_OK) {
                OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode：%{public}d ", flashMode);
            } else {
                OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
            }
        } else {
            OH_LOG_ERROR(LOG_APP, "isFlashModeSupported fail");
        }

        // 判断是否支持连续自动变焦模式。
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

        // 获取相机支持的可变焦距比范围。
        float minZoom;
        float maxZoom;
        ret = OH_CaptureSession_GetZoomRatioRange(captureSession, &minZoom, &maxZoom);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
        } else {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
                minZoom, maxZoom);
        }

        // 设置变焦。
        ret = OH_CaptureSession_SetZoomRatio(captureSession, maxZoom);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
        }

        // 获取当前设备的变焦值。
        ret = OH_CaptureSession_GetZoomRatio(captureSession, &maxZoom);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom：%{public}f ", maxZoom);
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
        }

        // 无拍照设置进行拍照。
        ret = OH_PhotoOutput_Capture(photoOutput);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
        }

        // 停止当前会话。
        ret = OH_CaptureSession_Stop(captureSession);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Stop success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed. %d ", ret);
        }

        // 释放相机输入流。
        ret = OH_CameraInput_Close(cameraInput);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CameraInput_Close success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Close failed. %d ", ret);
        }

        // 释放预览输出流。
        ret = OH_PreviewOutput_Release(previewOutput);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_PreviewOutput_Release success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Release failed. %d ", ret);
        }

        // 释放拍照输出流。
        ret = OH_PhotoOutput_Release(photoOutput);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Release success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Release failed. %d ", ret);
        }

        // 释放会话。
        ret = OH_CaptureSession_Release(captureSession);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Release success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Release failed. %d ", ret);
        }

        // 资源释放。
        ret = OH_CameraManager_DeleteSupportedCameras(cameraManager, cameras, size);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "Delete Cameras failed.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_DeleteSupportedCameras. ok");
        }
        ret = OH_CameraManager_DeleteSupportedCameraOutputCapability(cameraManager, cameraOutputCapability);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "Delete Cameras failed.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_DeleteSupportedCameraOutputCapability. ok");
        }
        ret = OH_Camera_DeleteCameraManager(cameraManager);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "Delete Cameras failed.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_DeleteCameraManager. ok");
        }
    }
    ```