# 录像实践(C/C++)

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

当前示例提供完整的录像流程及其接口调用顺序的介绍。对于单个流程（如设备输入、会话管理、录像）的介绍请参考[相机开发指导(Native)](camera-preparation.md)的具体章节。

## 开发流程

在获取到相机支持的输出流能力后，开始创建录像流，开发流程如下。

![Recording Development Process](figures/recording-ndk-development-process.png)

## 完整示例

1. 在CMake脚本中链接相关动态库。
    ```txt
    target_link_libraries(entry PUBLIC
        libace_napi.z.so
        libohcamera.so
        libhilog_ndk.z.so
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
       NDKCamera(char* previewId, char* videoId);
   };
   ```

3. cpp侧导入NDK接口，并根据传入的SurfaceId进行录像。
    ```c++
    #include "hilog/log.h"
    #include "ndk_camera.h"
    #include <cmath>

    bool IsAspectRatioEqual(float videoAspectRatio, float previewAspectRatio)
    {
        float epsilon = 1e-6f;
        return fabsf(videoAspectRatio - previewAspectRatio) <= epsilon;
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

    void VideoOutputOnFrameStart(Camera_VideoOutput* videoOutput)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutputOnFrameStart");
    }

    void VideoOutputOnFrameEnd(Camera_VideoOutput* videoOutput, int32_t frameCount)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput frameCount = %{public}d", frameCount);
    }

    void VideoOutputOnError(Camera_VideoOutput* videoOutput, Camera_ErrorCode errorCode)
    {
        OH_LOG_INFO(LOG_APP, "VideoOutput errorCode = %{public}d", errorCode);
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

    NDKCamera::NDKCamera(char* previewId, char* videoId)
    {
        Camera_Manager* cameraManager = nullptr;
        Camera_Device* cameras = nullptr;
        Camera_CaptureSession* captureSession = nullptr;
        Camera_OutputCapability* cameraOutputCapability = nullptr;
        Camera_VideoOutput* videoOutput = nullptr;
        const Camera_Profile* previewProfile = nullptr;
        const Camera_Profile* photoProfile = nullptr;
        const Camera_VideoProfile* videoProfile = nullptr;
        Camera_PreviewOutput* previewOutput = nullptr;
        Camera_PhotoOutput* photoOutput = nullptr;
        Camera_Input* cameraInput = nullptr;
        uint32_t size = 0;
        uint32_t cameraDeviceIndex = 0;
        char* videoSurfaceId = videoId;
        char* previewSurfaceId = previewId;
        // 创建CameraManager对象。
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraManager failed.");
            return;
        }
        // 监听相机状态变化。
        ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
            return;
        }

        // 获取相机列表。
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
            return;
        }

        for (int index = 0; index < size; index++) {
            OH_LOG_ERROR(LOG_APP, "cameraId  =  %{public}s ", cameras[index].cameraId);              // 获取相机ID。
            OH_LOG_ERROR(LOG_APP, "cameraPosition  =  %{public}d ", cameras[index].cameraPosition);  // 获取相机位置。
            OH_LOG_ERROR(LOG_APP, "cameraType  =  %{public}d ", cameras[index].cameraType);          // 获取相机类型。
            OH_LOG_ERROR(LOG_APP, "connectionType  =  %{public}d ", cameras[index].connectionType);  // 获取相机连接类型。
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
        previewProfile = cameraOutputCapability->previewProfiles[0];
        OH_LOG_INFO(LOG_APP, "previewProfile width: %{public}, height: %{public}.", previewProfile->size.width,
            previewProfile->size.height);
        if (cameraOutputCapability->photoProfiles == nullptr) {
            OH_LOG_ERROR(LOG_APP, "photoProfiles == null");
            return;
        }
        photoProfile = cameraOutputCapability->photoProfiles[0];

        if (cameraOutputCapability->videoProfiles == nullptr) {
            OH_LOG_ERROR(LOG_APP, "videorofiles == null");
            return;
        }
        // 预览流宽高比要与录像流的宽高比一致，如果录制的是hdr视频，请筛选支持hdr的Camera_VideoProfile。
        Camera_VideoProfile** videoProfiles = cameraOutputCapability->videoProfiles;
        for (int index = 0; index < cameraOutputCapability->videoProfilesSize; index++) {
            bool isEqual = IsAspectRatioEqual((float)videoProfiles[index]->size.width / videoProfiles[index]->size.height,
                (float)previewProfile->size.width / previewProfile->size.height);
            // 默认筛选CAMERA_FORMAT_YUV_420_SP的profile。
            if (isEqual && videoProfiles[index]->format == Camera_Format::CAMERA_FORMAT_YUV_420_SP) {
                videoProfile = videoProfiles[index];
                OH_LOG_INFO(LOG_APP, "videoProfile width: %{public}, height: %{public}.", videoProfile->size.width,
                    videoProfile->size.height);
                break;
            }
        }

        // 创建VideoOutput对象。
        ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
        if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
            return;
        }

        // 监听视频输出错误信息。
        ret = OH_VideoOutput_RegisterCallback(videoOutput, GetVideoOutputListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
        }

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
        }

        // 打开相机。
        ret = OH_CameraInput_Open(cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Open failed.");
            return;
        }

        // 向会话中添加相机输入流。
        ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
            return;
        }

        // 创建预览输出流,其中参数 surfaceId 参考下面 XComponent 组件，预览流为XComponent组件提供的surface。
        ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
        if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
            return;
        }

        // 向会话中添加预览输出流。
        ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
            return;
        }

        // 向会话中添加录像输出流。
        ret = OH_CaptureSession_AddVideoOutput(captureSession, videoOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddVideoOutput failed.");
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

        // 启动录像输出流。
        ret = OH_VideoOutput_Start(videoOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
            return;
        }

        // 开始录像 ts侧调用avRecorder.start()。

        // 停止录像输出流。
        ret = OH_VideoOutput_Stop(videoOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
        }

        // 停止录像 ts侧调用avRecorder.stop()。

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

        // 释放录像输出流。
        ret = OH_VideoOutput_Release(videoOutput);
        if (ret == CAMERA_OK) {
            OH_LOG_INFO(LOG_APP, "OH_VideoOutput_Release success ");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Release failed. %d ", ret);
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
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_DeleteSupportedCameraOutputCapability success");
        }
        ret = OH_Camera_DeleteCameraManager(cameraManager);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "Delete Cameras failed.");
        } else {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_DeleteCameraManager success");
        }
    }
    ```