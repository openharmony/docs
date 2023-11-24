# Camera Recording Sample (Native)

## Development Process

After obtaining the output stream capabilities supported by the camera, create a video stream. The development process is as follows:

![Recording Development Process](figures/recording-ndk-development-process.png)


## Sample Code

```ts
// Import the media module on the TS side.
import media from '@ohos.multimedia.media';
// Configure the parameters based on those supported by the hardware device.
let videoConfig: media.AVRecorderConfig = {
  audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
  videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
  profile: {
    audioBitrate: 48000,
    audioChannels: 2,
    audioCodec: media.CodecMimeType.AUDIO_AAC,
    audioSampleRate: 48000,
    fileFormat: media.ContainerFormatType.CFT_MPEG_4,
    videoBitrate: 512000,
    videoCodec: media.CodecMimeType.VIDEO_AVC,
    videoFrameWidth: 640,
    videoFrameHeight: 480,
    videoFrameRate: 30
  },
  url: '',
  rotation: 0
};
private photoRotationMap = {
  rotation0: 0,
  rotation90: 90,
  rotation180: 180,
  rotation270: 270,
};
// Obtain the surface ID for the video stream.
async getVideoSurfaceID(){
  this.videoRecorder = await media.createAVRecorder()
  this.fileAsset = await this.mediaUtil.createAndGetUri(mediaLibrary.MediaType.VIDEO)
  this.fd = await this.mediaUtil.getFdPath(this.fileAsset)
  this.videoConfig.url = `fd://${this.fd}`

  if (deviceInfo.deviceType == 'default') {
    Logger.info(this.tag, `deviceType = default`)
    this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_ES
  }
  if (deviceInfo.deviceType == 'phone') {
    Logger.info(this.tag, `deviceType = phone`)
    this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
    this.videoConfig.profile.videoCodec = media.CodecMimeType.VIDEO_MPEG4;
    if (this.cameraDeviceIndex == 1) {
      this.videoConfig.rotation = this.photoRotationMap.rotation270;
    } else {
      this.videoConfig.rotation = this.photoRotationMap.rotation90;
    }
  }
  if (deviceInfo.deviceType == 'tablet') {
    Logger.info(this.tag, `deviceType = tablet`)
    this.videoConfig.videoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV
  }

  this.videoConfig.profile.videoFrameWidth = 640;
  this.videoConfig.profile.videoFrameHeight = 480;
  this.videoConfig.profile.videoFrameRate = 30;

  await this.videoRecorder.prepare(this.videoConfig)
  this.videoSurfaceId = await this.videoRecorder.getInputSurface()
}

// Start video recording.
try {
  await avRecorder.start();
} catch (error) {
  console.error(`avRecorder start error: ${JSON.stringify(err)}`);
}
// Stop video recording.
try {
  await avRecorder.stop();
} catch (error) {
  console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
}
```

```c++
// Import the NDK on the C++ side.
#include "multimedia/camera_framework/camera.h"
#include "multimedia/camera_framework/camera_input.h"
#include "multimedia/camera_framework/capture_session.h"
#include "multimedia/camera_framework/photo_output.h"
#include "multimedia/camera_framework/preview_output.h"
#include "multimedia/camera_framework/video_output.h"
#include "multimedia/camera_framework/camera_manager.h"


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

int main()
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
  // Create a CameraManager object.
  Camera_ErrorCode ret = OH_Camera_GetCameraMananger(&cameraManager);
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

  for (int index = 0; index < size; index++) {
    OH_LOG_ERROR(LOG_APP, "cameraId  =  %{public}s ", cameras[index].cameraId);              // Obtain the camera ID.
    OH_LOG_ERROR(LOG_APP, "cameraPosition  =  %{public}d ", cameras[index].cameraPosition);  // Obtain the camera position.
    OH_LOG_ERROR(LOG_APP, "cameraType  =  %{public}d ", cameras[index].cameraType);          // Obtain the camera type.
    OH_LOG_ERROR(LOG_APP, "connectionType  =  %{public}d ", cameras[index].connectionType);  // Obtain the camera connection type.
  }

  // Obtain the output streams supported by the camera.
  ret = OH_CameraManager_GetSupportedCameraOutputCapability(cameraManager, &cameras[cameraDeviceIndex],
                                                               &cameraOutputCapability);
  if (cameraOutputCapability == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_GetSupportedCameraOutputCapability failed.");
  }
  
  if (cameraOutputCapability->previewProfilesSize < 0) {
    console.error("previewProfilesSize == null");
  }
  previewProfile = cameraOutputCapability->previewProfiles[0];

  if (cameraOutputCapability->photoProfilesSize < 0) {
    console.error("photoProfilesSize == null");
  }
  photoProfile = cameraOutputCapability->photoProfiles[0];

  if (cameraOutputCapability->videorofilesSize < 0) {
    console.error("videorofilesSize == null");
  }
  videoProfile = cameraOutputCapability->videoProfiles[0];

  // Call getVideoSurfaceID() on the TS side.

  // Create a VideoOutput instance.
  ret = OH_CameraManager_CreateVideoOutput(cameraManager, videoProfile, videoSurfaceId, &videoOutput);
  if (videoProfile == nullptr || videoOutput == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreateVideoOutput failed.");
  }

  // Listen for video output errors.
  ret = OH_VideoOutput_RegisterCallback(videoOutput_, GetVideoOutputListener());
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_RegisterCallback failed.");
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

  // Add the camera input stream to the session.
  ret = OH_CaptureSession_AddInput(captureSession, cameraInput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddInput failed.");
  }

  // Create a preview output stream. For details about the surfaceId parameter, see the <XComponent>. The preview stream is the surface provided by the <XComponent>.
  ret = OH_CameraManager_CreatePreviewOutput(cameraManager, previewProfile, previewSurfaceId, &previewOutput);
  if (previewProfile == nullptr || previewOutput == nullptr || ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CameraManager_CreatePreviewOutput failed.");
  }

  // Add the preview input stream to the session.
  ret = OH_CaptureSession_AddPreviewOutput(captureSession, previewOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddPreviewOutput failed.");
  }

  // Add the video output stream to the session.
  ret = OH_CaptureSession_AddVideoOutput(captureSession, videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_AddVideoOutput failed.");
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

  // Start the video output stream.
  ret = OH_VideoOutput_Start(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Start failed.");
  }

  // Call avRecorder.start() on the TS side to start video recording.

  // Stop the video output stream.
  ret = OH_VideoOutput_Stop(videoOutput);
  if (ret != CAMERA_OK) {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Stop failed.");
  }

  // Call avRecorder.stop() on the TS side to stop video recording.

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


  // Release the video output stream.
  ret = OH_VideoOutput_Release(videoOutput);
  if (ret == CAMERA_OK) {
      OH_LOG_INFO(LOG_APP, "OH_VideoOutput_Release success ");
  } else {
      OH_LOG_ERROR(LOG_APP, "OH_VideoOutput_Release failed. %d ", ret);
  }


  // Release the session.
  ret = OH_CaptureSession_Release(captureSession);
  if (ret == CAMERA_OK) {
      OH_LOG_INFO(LOG_APP, "OH_CaptureSession_Release success ");
  } else {
      OH_LOG_ERROR(LOG_APP, "OH_CaptureSession_Release failed. %d ", ret);
  }

}
```

