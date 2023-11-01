# Camera Recording Sample

## Development Process

After obtaining the output stream capabilities supported by the camera, create a video stream. The development process is as follows:

![Recording Development Process](figures/recording-development-process.png)


## Sample Code
For details about how to obtain the BaseContext, see [BaseContext](../reference/apis/js-apis-inner-application-baseContext.md).
```ts
import camera from '@ohos.multimedia.camera';
import { BusinessError } from '@ohos.base';
import media from '@ohos.multimedia.media';
import common from '@ohos.app.ability.common';

async function videoRecording(baseContext: common.BaseContext, surfaceId: string): Promise<void> {
  // Create a CameraManager instance.
  let cameraManager: camera.CameraManager = camera.getCameraManager(baseContext);
  if (!cameraManager) {
    console.error("camera.getCameraManager error");
    return;
  }

  // Listen for camera status changes.
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
    console.log(`status: ${cameraStatusInfo.status}`);
  });

  // Obtain the camera list.
  let cameraArray: Array<camera.CameraDevice> = [];
  try {
    cameraArray = cameraManager.getSupportedCameras();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`getSupportedCameras call failed. error code: ${err.code}`);
  }

  if (cameraArray.length <= 0) {
    console.error("cameraManager.getSupportedCameras error");
    return;
  }

  // Obtain the output stream capabilities supported by the camera.
  let cameraOutputCap: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraArray[0]);
  if (!cameraOutputCap) {
    console.error("cameraManager.getSupportedOutputCapability error")
    return;
  }
  console.log("outputCapability: " + JSON.stringify(cameraOutputCap));

  let previewProfilesArray: Array<camera.Profile> = cameraOutputCap.previewProfiles;
  if (!previewProfilesArray) {
    console.error("createOutput previewProfilesArray == null || undefined");
  }

  let photoProfilesArray: Array<camera.Profile> = cameraOutputCap.photoProfiles;
  if (!photoProfilesArray) {
    console.error("createOutput photoProfilesArray == null || undefined");
  }

  let videoProfilesArray: Array<camera.VideoProfile> = cameraOutputCap.videoProfiles;
  if (!videoProfilesArray) {
    console.error("createOutput videoProfilesArray == null || undefined");
  }

  let metadataObjectTypesArray: Array<camera.MetadataObjectType> = cameraOutputCap.supportedMetadataObjectTypes;
  if (!metadataObjectTypesArray) {
    console.error("createOutput metadataObjectTypesArray == null || undefined");
  }

  // Configure the parameters based on those supported by the hardware device.
  let aVRecorderProfile: media.AVRecorderProfile = {
    audioBitrate: 48000,
    audioChannels: 2,
    audioCodec: media.CodecMimeType.AUDIO_AAC,
    audioSampleRate: 48000,
    fileFormat: media.ContainerFormatType.CFT_MPEG_4,
    videoBitrate: 2000000,
    videoCodec: media.CodecMimeType.VIDEO_MPEG4,
    videoFrameWidth: 640,
    videoFrameHeight: 480,
    videoFrameRate: 30
  };
  let aVRecorderConfig: media.AVRecorderConfig = {
    audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
    videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
    profile: aVRecorderProfile,
    url: 'fd://', // Before passing in a file descriptor to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: fd://45--file:///data/media/01.mp4.
    rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
    location: { latitude: 30, longitude: 130 }
  };

  let avRecorder: media.AVRecorder | undefined = undefined;
  try {
    avRecorder = await media.createAVRecorder();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`createAVRecorder call failed. error code: ${err.code}`);
  }

  if (avRecorder === undefined) {
    return;
  }

  try {
    await avRecorder.prepare(aVRecorderConfig);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prepare call failed. error code: ${err.code}`);
  }

  let videoSurfaceId: string | undefined = undefined; // The surfaceID is passed in to the camera API to create a VideoOutput instance.
  try {
    videoSurfaceId = await avRecorder.getInputSurface();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`getInputSurface call failed. error code: ${err.code}`);
  }
  if (videoSurfaceId === undefined) {
    return;
  }
  // Create a VideoOutput instance.
  let videoOutput: camera.VideoOutput | undefined = undefined;
  try {
    videoOutput = cameraManager.createVideoOutput(videoProfilesArray[0], videoSurfaceId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create the videoOutput instance. error: ${JSON.stringify(err)}`);
  }
  if (videoOutput === undefined) {
    return;
  }
  // Listen for video output errors.
  videoOutput.on('error', (error: BusinessError) => {
    console.log(`Preview output error code: ${error.code}`);
  });

  // Create a session.
  let captureSession: camera.CaptureSession | undefined = undefined;
  try {
    captureSession = cameraManager.createCaptureSession();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create the CaptureSession instance. error: ${JSON.stringify(err)}`);
  }
  if (captureSession === undefined) {
    return;
  }
  // Listen for session errors.
  captureSession.on('error', (error: BusinessError) => {
    console.log(`Capture session error code: ${error.code}`);
  });

  // Start configuration for the session.
  try {
    captureSession.beginConfig();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to beginConfig. error: ${JSON.stringify(err)}`);
  }

  // Create a camera input stream.
  let cameraInput: camera.CameraInput | undefined = undefined;
  try {
    cameraInput = cameraManager.createCameraInput(cameraArray[0]);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to createCameraInput. error: ${JSON.stringify(err)}`);
  }
  if (cameraInput === undefined) {
    return;
  }
  // Listen for camera input errors.
  let cameraDevice: camera.CameraDevice = cameraArray[0];
  cameraInput.on('error', cameraDevice, (error: BusinessError) => {
    console.log(`Camera input error code: ${error.code}`);
  });

  // Open the camera.
  try {
    await cameraInput.open();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open cameraInput. error: ${JSON.stringify(err)}`);
  }

  // Add the camera input stream to the session.
  try {
    captureSession.addInput(cameraInput);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to add cameraInput. error: ${JSON.stringify(err)}`);
  }

  // Create a preview output stream. For details about the surfaceId parameter, see the XComponent. The preview stream is the surface provided by the XComponent.
  let previewOutput: camera.PreviewOutput | undefined = undefined;
  try {
    previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create the PreviewOutput instance. error: ${JSON.stringify(err)}`);
  }

  if (previewOutput === undefined) {
    return;
  }
  // Add the preview input stream to the session.
  try {
    captureSession.addOutput(previewOutput);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to add previewOutput. error: ${JSON.stringify(err)}`);
  }

  // Add a video output stream to the session.
  try {
    captureSession.addOutput(videoOutput);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to add videoOutput. error: ${JSON.stringify(err)}`);
  }

  // Commit the session configuration.
  try {
    await captureSession.commitConfig();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`captureSession commitConfig error: ${JSON.stringify(err)}`);
  }

  // Start the session.
  try {
    await captureSession.start();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`captureSession start error: ${JSON.stringify(err)}`);
  }

  // Start the video output stream.
  videoOutput.start((err: BusinessError) => {
    if (err) {
      console.error(`Failed to start the video output. error: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Callback invoked to indicate the video output start success.');
  });

  // Start video recording.
  try {
    await avRecorder.start();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`avRecorder start error: ${JSON.stringify(err)}`);
  }

  // Stop the video output stream.
  videoOutput.stop((err: BusinessError) => {
    if (err) {
      console.error(`Failed to stop the video output. error: ${JSON.stringify(err)}`);
      return;
    }
    console.log('Callback invoked to indicate the video output stop success.');
  });

  // Stop video recording.
  try {
    await avRecorder.stop();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`avRecorder stop error: ${JSON.stringify(err)}`);
  }

  // Stop the session.
  captureSession.stop();

  // Release the camera input stream.
  cameraInput.close();

  // Release the preview output stream.
  previewOutput.release();

  // Release the video output stream.
  videoOutput.release();

  // Release the session.
  captureSession.release();

  // Set the session to null.
  captureSession = undefined;
}
```
