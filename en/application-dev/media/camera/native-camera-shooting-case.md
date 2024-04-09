# Camera Photographing Sample (C/C++)

This topic provides sample code that covers the complete photographing process and the API calling sequence. For details about a single process (such as device input, session management, and photographing), see the corresponding C/C++ development guide links provided in [Camera Development Preparations](camera-preparation.md).

## Development Process

After obtaining the output stream capabilities supported by the camera, create a photo stream. The development process is as follows:

![Photographing Development Process](figures/photographing-ndk-development-process.png)

## Sample Code

1. Link the dynamic library in the CMake script.
    ```txt
        target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
    ```

2. Import the NDK APIs on the C++ side, and perform photographing based on the surface ID passed in.
    ```c++
    #include "hilog/log.h"
    #include "ohcamera/camera.h"
    #include "ohcamera/camera_input.h"
    #include "ohcamera/capture_session.h"
    #include "ohcamera/photo_output.h"
    #include "ohcamera/preview_output.h"
    #include "ohcamera/video_output.h"
    #include "ohcamera/camera_manager.h"

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

    NDKCamera::NDKCamera(char *previewId, char *photoId)
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
        char* photoSurfaceId = photoId;
        // Create a CameraManager object.
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraMananger failed.");
        }
        // Listen for camera status changes.
        ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
        }
        
        // Obtain the camera list.
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size < 0 || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
        }
        
        // Create a camera input stream.
        ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
        if (cameraInput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
        }
        
        // Listen for camera input errors.
        ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
        }
        
        // Open the camera.
        ret = OH_CameraInput_Open(cameraInput);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Open failed.");
        }
        
        // Obtain the output streams supported by the camera.
        ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                                  &cameraOutputCapability);
        if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
        }
        
        if (cameraOutputCapability->previewProfilesSize < 0) {
          OH_LOG_ERROR(LOG_APP, "previewProfilesSize == null");
        }
        previewProfile = cameraOutputCapability->previewProfiles[0];
        
        if (cameraOutputCapability->photoProfilesSize < 0) {
          OH_LOG_ERROR(LOG_APP, "photoProfilesSize == null");
        }
        photoProfile = cameraOutputCapability->photoProfiles[0];
        
        
        // Create a preview output stream, with the previewSurfaceId parameter set to the ID of the surface provided by the <XComponent>.
        ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
        if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
        }
        
        // Listen for preview output errors.
        ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
        }
        
        // Create a photo output stream, with the photoSurfaceId parameter set to the ID of the surface obtained through ImageReceiver.
        ret = OH_CameraManager_CreatePhotoOutput(cameraManager, photoProfile, photoSurfaceId, &photoOutput);
        if (photoProfile == nullptr || photoOutput == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePhotoOutput failed.");
        }
        
        // Create a session.
        ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
        if (captureSession == nullptr || ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
        }
        
        // Listen for session errors.
        ret = OH_CaptureSession_RegisterCallback(captureSession, GetCaptureSessionRegister());
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RegisterCallback failed.");
        }
        
        // Start configuration for the session.
        ret = OH_CaptureSession_BeginConfig(captureSession);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
        }
        
        // Add the camera input stream to the session.
        ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
        }
        
        // Add the preview output stream to the session.
        ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
        }
        
        // Add the photo output stream to the session.
        ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
        }
        
        // Commit the session configuration.
        ret = OH_CaptureSession_CommitConfig(captureSession);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
        }
        
        // Start the session.
        ret = OH_CaptureSession_Start(captureSession);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
        }
        
        // Check whether the camera has flash.
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
        // Check whether a flash mode is supported.
        bool isSupported = false;
        ret = OH_CaptureSession_IsFlashModeSupported(captureSession, flashMode, &isSupported);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_IsFlashModeSupported failed.");
        }
        if (isSupported) {
          OH_LOG_INFO(LOG_APP, "isFlashModeSupported success");
          // Set the flash mode.
          ret = OH_CaptureSession_SetFlashMode(captureSession, flashMode);
          if (ret == CAMERA_OK) {
              OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetFlashMode success.");
          } else {
              OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetFlashMode failed. %{public}d ", ret);
          }
          // Obtain the flash mode in use.
          ret = OH_CaptureSession_GetFlashMode(captureSession, &flashMode);
          if (ret == CAMERA_OK) {
              OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetFlashMode success. flashMode: %{public}d ", flashMode);
          } else {
              OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetFlashMode failed. %d ", ret);
          }
        } else {
          OH_LOG_ERROR(LOG_APP, "isFlashModeSupported fail");
        }
        
        // Check whether the continuous auto focus is supported.
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
        
        // Obtain the zoom ratio range supported by the camera.
        float minZoom;
        float maxZoom;
        ret = OH_CaptureSession_GetZoomRatioRange(captureSession, &minZoom, &maxZoom);
        if (ret != CAMERA_OK) {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatioRange failed.");
        } else {
          OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatioRange success. minZoom: %{public}f, maxZoom:%{public}f",
              minZoom, maxZoom);
        }
        // Set a zoom ratio.
        ret = OH_CaptureSession_SetZoomRatio(captureSession, maxZoom);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_CaptureSession_SetZoomRatio success.");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetZoomRatio failed. %{public}d ", ret);
        }
        // Obtain the zoom ratio of the camera.
        ret = OH_CaptureSession_GetZoomRatio(captureSession, &maxZoom);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_CaptureSession_GetZoomRatio success. zoom: %{public}f ", maxZoom);
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_GetZoomRatio failed. %{public}d ", ret);
        }
        
        // Take photos without photographing settings.
        ret = OH_PhotoOutput_Capture(photoOutput);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Capture success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Capture failed. %d ", ret);
        }
        
        // Stop the session.
        ret = OH_CaptureSession_Stop(captureSession);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Stop success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Stop failed. %d ", ret);
        }
        
        // Release the camera input stream.
        ret = OH_CameraInput_Close(cameraInput);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_CameraInput_Close success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Close failed. %d ", ret);
        }
        
        // Release the preview output stream.
        ret = OH_PreviewOutput_Release(previewOutput);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PreviewOutput_Release success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_Release failed. %d ", ret);
        }
        
        // Release the photo output stream.
        ret = OH_PhotoOutput_Release(photoOutput);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_PhotoOutput_Release success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_PhotoOutput_Release failed. %d ", ret);
        }
        
        // Release the session.
        ret = OH_CaptureSession_Release(captureSession);
        if (ret == CAMERA_OK) {
          OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Release success ");
        } else {
          OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Release failed. %d ", ret);
        }
        
        // Release the resources.
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
