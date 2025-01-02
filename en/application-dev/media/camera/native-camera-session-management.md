# Camera Session Management (C/C++)

Before using the camera application for preview, photo capture, video recording, and metadata management, you must create a camera session.

You can implement the following functions in the session:

- Configure the camera input and output streams. This is mandatory for photo capture.

  Configuring an input stream is to add a device input, which means that the user selects a camera for photo capture. Configuring an output stream is to select a data output mode. For example, to implement photo capture, you must configure both the preview stream and photo stream as the output stream. The data of the preview stream is displayed on the **XComponent**, and that of the photo stream is saved to the Gallery application through the ImageReceiver API.

- Perform more operations on the camera hardware. For example, add the flash and adjust the focal length. For details about the supported configurations and APIs, see [Camera API Reference](../../reference/apis-camera-kit/_o_h___camera.md).

- Control session switching. The application can switch the camera mode by removing and adding output streams. For example, to switch from photo capture to video recording, the application must remove the photo output stream and add the video output stream.

After the session configuration is complete, the application must commit the configuration and start the session before using the camera functionalities.

## How to Develop

1. Import the NDK.
     
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

2. Link the dynamic library in the CMake script.

   ```txt
    target_link_libraries(entry PUBLIC libohcamera.so libhilog_ndk.z.so)
   ```

3. Call [OH_CameraManager_CreateCaptureSession()](../../reference/apis-camera-kit/_o_h___camera.md#oh_cameramanager_createcapturesession) in the CameraManager class to create a session.
     
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

4. Call [OH_CaptureSession_SetSessionMode()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_setsessionmode) in the CaptureSession class to set the session mode.

   ```c++
    ret = OH_CaptureSession_SetSessionMode(captureSession, NORMAL_PHOTO);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_SetSessionMode failed.");
    }
   ```

5. Call [OH_CaptureSession_BeginConfig()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_beginconfig) in the CaptureSession class to start configuration for the session.

   ```c++
    ret = OH_CaptureSession_BeginConfig(captureSession);
    if (ret != CAMERA_OK) {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_BeginConfig failed.");
    }
   ```

6. Configure the session. You can call [OH_CaptureSession_AddInput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_addinput) to add an input stream to the session, and call [OH_CaptureSession_AddPreviewOutput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_addpreviewoutput) and [OH_CaptureSession_AddPhotoOutput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_addphotooutput) to add output streams to the session. The code snippet below uses adding the preview stream **previewOutput** and photo stream **photoOutput** as an example to implement the photo capture and preview mode.

     After the configuration, call [OH_CaptureSession_CommitConfig()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_commitconfig) and [OH_CaptureSession_Start()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_start) in the CaptureSession class in sequence to commit the configuration and start the session.
     
   ```c++
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
   ```

7. Control the session. You can call [OH_CaptureSession_Stop()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_stop) in the CaptureSession class to stop the session, and call [OH_CaptureSession_RemovePhotoOutput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_removephotooutput) and [OH_CaptureSession_AddVideoOutput()](../../reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_addvideooutput) in this class to switch to another session. The code snippet below uses removing the photo stream **photoOutput** and adding the video stream **videoOutput** as an example to complete the switching from photo capture to video recording.
     
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
    // Remove the photo output stream from the session.
    ret = OH_CaptureSession_RemovePhotoOutput(captureSession, photoOutput);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_RemovePhotoOutput success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RemovePhotoOutput failed. %d ", ret);
    }
     // Add the video output stream to the session.
    ret = OH_CaptureSession_AddVideoOutput(captureSession, videoOutput);
    if (ret == CAMERA_OK) {
        OH_LOG_INFO(LOG_APP, "OH_CaptureSession_RemovePhotoOutput success ");
    } else {
        OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_RemovePhotoOutput failed. %d ", ret);
    }
   ```
