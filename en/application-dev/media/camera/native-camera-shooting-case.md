# Photo Capture Practices (C/C++)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Before developing a camera application, request permissions by following the instructions provided in [Requesting Camera Development Permissions](camera-preparation.md).

This topic provides sample code that covers the complete photo capture process and the API calling sequence. For details about a single process (such as device input, session management, and photo capture), see the corresponding C/C++ development guide links provided in [Requesting Camera Development Permissions](camera-preparation.md).

## Development Process

After obtaining the output stream capabilities supported by the camera, create a photo stream. The development process is as follows:

![Photographing Development Process](figures/photographing-ndk-development-process.png)

## Sample Code

1. Link the dynamic library in the CMake script.
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
2. Create the header file **ndk_camera.h**.
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

3. Import the NDK APIs on the C++ side, and perform photo capture based on the surface ID passed in.
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
        // Read the size attribute of OH_ImageNative.
        Image_Size size;
        Image_ErrorCode imageErr = OH_ImageNative_GetImageSize(imageNative, &size);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d width:%{public}d height:%{public}d", imageErr,
            size.width, size.height);
        // Read the number of elements in the component list of OH_ImageNative.
        size_t componentTypeSize = 0;
        imageErr = OH_ImageNative_GetComponentTypes(imageNative, nullptr, &componentTypeSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d componentTypeSize:%{public}zu", imageErr,
            componentTypeSize);
        // Read the component list of OH_ImageNative.
        uint32_t* components = new uint32_t[componentTypeSize];
        imageErr = OH_ImageNative_GetComponentTypes(imageNative, &components, &componentTypeSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetComponentTypes imageErr:%{public}d", imageErr);
        // Read the buffer object corresponding to the first component of OH_ImageNative.
        OH_NativeBuffer* nativeBuffer = nullptr;
        imageErr = OH_ImageNative_GetByteBuffer(imageNative, components[0], &nativeBuffer);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_ImageNative_GetByteBuffer imageErr:%{public}d", imageErr);
        // Read the size of the buffer corresponding to the first component of OH_ImageNative.
        size_t nativeBufferSize = 0;
        imageErr = OH_ImageNative_GetBufferSize(imageNative, components[0], &nativeBufferSize);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d nativeBufferSize:%{public}zu", imageErr,
             nativeBufferSize);
        // Read the row stride corresponding to the first component of OH_ImageNative.
        int32_t rowStride = 0;
        imageErr = OH_ImageNative_GetRowStride(imageNative, components[0], &rowStride);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d rowStride:%{public}d", imageErr, rowStride);
        // Read the pixel stride corresponding to the first component of OH_ImageNative.
        int32_t pixelStride = 0;
        imageErr = OH_ImageNative_GetPixelStride(imageNative, components[0], &pixelStride);
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable imageErr:%{public}d pixelStride:%{public}d", imageErr, pixelStride);
        // Map the ION memory to the process address space.
        void* virAddr = nullptr; // Point to the virtual address of the mapped memory. After unmapping, the pointer is invalid.
        int32_t ret = OH_NativeBuffer_Map(nativeBuffer, &virAddr); // After mapping, the start address of the memory is returned through the parameter virAddr.
        OH_LOG_INFO(LOG_APP, "OnPhotoAvailable OH_NativeBuffer_Map err:%{public}d", ret);
        // Pass the processed buffer to the ArkTS side through the callback for image display or storage (using a security component). For details, see Photo Capture (C/C++).
        auto cb = (void (*)(void *, size_t))(bufferCb);
        cb(virAddr, nativeBufferSize);
        // After the processing is complete, unmap and release the buffer.
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
        // Create a CameraManager object.
        Camera_ErrorCode ret = OH_Camera_GetCameraManager(&cameraManager);
        if (cameraManager == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_Camera_GetCameraMananger failed.");
            return;
        }
        // Listen for camera status changes.
        ret = OH_CameraManager_RegisterCallback(cameraManager, GetCameraManagerListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_RegisterCallback failed.");
        }

        // Obtain the camera list.
        ret = OH_CameraManager_GetSupportedCameras(cameraManager, &cameras, &size);
        if (cameras == nullptr || size <= 0 || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameras failed.");
            return;
        }

        if (size < cameraDeviceIndex + 1) {
            OH_LOG_ERROR(LOG_APP, "cameraDeviceIndex is invalid.");
            return;
        }

        // Create a camera input stream.
        ret = OH_CameraManager_CreateCameraInput(cameraManager, &cameras[cameraDeviceIndex], &cameraInput);
        if (cameraInput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCameraInput failed.");
            return;
        }

        // Listen for camera input errors.
        ret = OH_CameraInput_RegisterCallback(cameraInput, GetCameraInputListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_RegisterCallback failed.");
            return;
        }

        // Open the camera.
        ret = OH_CameraInput_Open(cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraInput_Open failed.");
            return;
        }

        // Obtain the output stream capability supported by the camera.
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
        // Select an appropriate preview resolution from previewProfiles of cameraOutputCapability.
        previewProfile = cameraOutputCapability->previewProfiles[0];

        if (cameraOutputCapability->photoProfiles == nullptr) {
            OH_LOG_ERROR(LOG_APP, "photoProfiles == null");
            return;
        }
        // Select an appropriate photo resolution from photoProfiles of cameraOutputCapability.
        photoProfile = cameraOutputCapability->photoProfiles[0];

        // Create a preview output stream, with the previewSurfaceId parameter set to the ID of the surface provided by the XComponent.
        ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
        if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
            return;
        }

        // Listen for preview output errors.
        ret = OH_PreviewOutput_RegisterCallback(previewOutput, GetPreviewOutputListener());
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_PreviewOutput_RegisterCallback failed.");
        }

        // Create a photo output stream.
        ret = OH_CameraManager_CreatePhotoOutputWithoutSurface(cameraManager, photoProfile, &photoOutput);

        // Listen for the one-time photo capture callback.
        ret = OH_PhotoOutput_RegisterPhotoAvailableCallback(photoOutput, OnPhotoAvailable);

        // Create a session.
        ret = OH_CameraManager_CreateCaptureSession(cameraManager, &captureSession);
        if (captureSession == nullptr || ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateCaptureSession failed.");
            return;
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
            return;
        }

        // Add the camera input stream to the session.
        ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
            return;
        }

        // Add the preview output stream to the session.
        ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
            return;
        }

        // Add the photo output stream to the session.
        ret = OH_CaptureSession_AddPhotoOutput(captureSession, photoOutput);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPhotoOutput failed.");
            return;
        }

        // Commit the session configuration.
        ret = OH_CaptureSession_CommitConfig(captureSession);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_CommitConfig failed.");
            return;
        }

        // Start the session.
        ret = OH_CaptureSession_Start(captureSession);
        if (ret != CAMERA_OK) {
            OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Start failed.");
            return;
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

        // Take photos without photo capture settings.
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
