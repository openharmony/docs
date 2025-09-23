# Video Recording Practices (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Before developing a camera application, you must [request required permissions](camera-preparation.md).

This topic provides sample code that covers the complete recording process to help you understand the complete API calling sequence.

Before referring to the sample code, you are advised to read [Device Input Management](camera-device-input.md), [Camera Session Management](camera-session-management.md), [Video Recording](camera-recording.md), and other related topics in [Camera Development (ArkTS)](camera-device-management.md).

To save videos to the media library, follow the instructions provided in [Saving Media Assets](../medialibrary/photoAccessHelper-savebutton.md).
## Development Process

After obtaining the output stream capabilities supported by the camera, create a video stream. The development process is as follows:

![Recording Development Process](figures/recording-development-process.png)


## Complete Sample Code
For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
import { common } from '@kit.AbilityKit';
import { fileIo as fs } from '@kit.CoreFileKit';
import { JSON } from '@kit.ArkTS';

interface RecordingResources {
  avRecorder?: media.AVRecorder;
  videoOutput?: camera.VideoOutput;
  cameraInput?: camera.CameraInput;
  previewOutput?: camera.PreviewOutput;
  videoSession?: camera.VideoSession;
  file?: fs.File;
}

// Track global resources.
const resources: RecordingResources = {};

async function releaseResources(): Promise<void> {
  const releaseSteps = [
  // Stop video recording.
    async () => await resources.avRecorder?.stop().catch((e: BusinessError) => console.error('Failed to stop video recording:', e)),
    // Stop video output.
    async () => await resources.videoOutput?.stop().catch((e: BusinessError) => console.error('Failed to stop video output:', e)),
    // Stop the session.
    async () => await resources.videoSession?.stop().catch((e: BusinessError) => console.error('Failed to stop the session:', e)),
    // Release the AVRecorder.
    async () => await resources.avRecorder?.release().catch((e: BusinessError) => console.error('Failed to release the AVRecorder:', e)),
    // Close the camera input.
    async () => await resources.cameraInput?.close().catch((e: BusinessError) => console.error('Failed to close the camera input:', e)),
    // Release the video output.
    async () => await resources.videoOutput?.release().catch((e: BusinessError) => console.error('Failed to release the video output:', e)),
    // Release the preview output.
    async () => await resources.previewOutput?.release().catch((e: BusinessError) => console.error('Failed to release the preview output:', e)),
    // Release the session.
    async () => await resources.videoSession?.release().catch((e: BusinessError) => console.error('Failed to release the session:', e)),
    // Close the file.
    async () => {
      if (resources.file) {
        try {
          await fs.close(resources.file);
        } catch (e) {
          console.error('Failure to close file');
        }
      }
    },
  ];

  // Perform the release steps in sequence.
  for (const step of releaseSteps) {
    await step();
  }
  // Clear the resource reference.
  resources.avRecorder = undefined;
  resources.videoOutput = undefined;
  resources.cameraInput = undefined;
  resources.previewOutput = undefined;
  resources.videoSession = undefined;
  resources.file = undefined;
}

async function videoRecording(context: common.Context, surfaceId: string): Promise<void> {
  // Create a CameraManager object.
  let cameraManager: camera.CameraManager | undefined = undefined;
  try {
    cameraManager = camera.getCameraManager(context);
  } catch (error) {
    console.error(`getCameraManager call failed, error: ${JSON.stringify(error)}`);
  }

  if (!cameraManager) {
    console.error("cameraManager is null");
    return;
  }

  // Obtain the camera list.
  let cameraArray: Array<camera.CameraDevice> = [];
  try {
    cameraArray = cameraManager.getSupportedCameras();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`getSupportedCameras call failed. error code: ${JSON.stringify(err)}`);
  }

  if (!cameraArray || cameraArray.length <= 0) {
    console.error("cameraManager.getSupportedCameras error");
    return;
  }

  // Obtain the supported modes.
  let sceneModes: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraArray[0]);
  let isSupportVideoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_VIDEO) >= 0;
  if (!isSupportVideoMode) {
    console.error('video mode not support');
    return;
  }

  // In this sample code, the first camera is selected. You need to select a camera as required.
  const cameraDevice: camera.CameraDevice = cameraArray[0];

  // Obtain the output stream capability supported by the camera.
  let cameraOutputCap: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice,
    camera.SceneMode.NORMAL_VIDEO);
  if (!cameraOutputCap) {
    console.error("cameraOutputCap is null");
    return;
  }
  console.info("outputCapability: " + JSON.stringify(cameraOutputCap));

  let videoProfilesArray: Array<camera.VideoProfile> = cameraOutputCap.videoProfiles;
  if (!videoProfilesArray || videoProfilesArray.length === 0) {
    console.error("videoProfilesArray is null or []");
    return;
  }

  // The width and height of videoProfile must be the same as those of AVRecorderProfile.
  // In this sample code, the first video profile is selected. You need to select a video profile as required.
  const videoProfile: camera.VideoProfile = cameraOutputCap.videoProfiles[0];
  let videoUri: string = context.filesDir + '/' + 'VIDEO_' + Date.parse(new Date().toString()) + '.mp4'; // Local sandbox path.
  try {
    resources.file = fs.openSync(videoUri, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
  } catch (error) {
    console.error(`openSync call failed, error: ${JSON.stringify(error)}`);
    return;
  }

  // Create and configure an AVRecorder.
  const isHdr: boolean = [
    camera.CameraFormat.CAMERA_FORMAT_YCBCR_P010,
    camera.CameraFormat.CAMERA_FORMAT_YCRCB_P010
  ].includes(videoProfile.format);
  // Configure the parameters based on those supported by the device.
  let aVRecorderProfile: media.AVRecorderProfile = {
    audioBitrate: 48000,
    audioChannels: 2,
    audioCodec: media.CodecMimeType.AUDIO_AAC,
    audioSampleRate: 48000,
    fileFormat: media.ContainerFormatType.CFT_MPEG_4,
    videoBitrate: 2000000,
    videoCodec: isHdr ? media.CodecMimeType.VIDEO_HEVC : media.CodecMimeType.VIDEO_AVC,
    videoFrameWidth: videoProfile.size.width,
    videoFrameHeight: videoProfile.size.height,
    videoFrameRate: 30,
    isHdr: isHdr
  };

  let avMetadata: media.AVMetadata = {
    videoOrientation: '0' // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
    location: { latitude: 30, longitude: 130 }
  }
  let aVRecorderConfig: media.AVRecorderConfig = {
    audioSourceType: media.AudioSourceType.AUDIO_SOURCE_TYPE_MIC,
    videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV,
    profile: aVRecorderProfile,
    url: `fd://${resources.file.fd.toString()}`, // Before passing in a file descriptor to this parameter, the file must be created by the caller and granted with the read and write permissions. Example value: fd://45--file:///data/media/01.mp4.
    rotation: 0, // The value can be 0, 90, 180, or 270. If any other value is used, prepare() reports an error.
    metadata: avMetadata
  };

  try {
    resources.avRecorder = await media.createAVRecorder();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`createAVRecorder call failed. error code: ${JSON.stringify(err)}`);
    return;
  }

  if (!resources.avRecorder) {
    console.error(`avRecorder is null`);
    return;
  }

  try {
    await resources.avRecorder.prepare(aVRecorderConfig);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`prepare call failed. error code: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }

  // Obtain the video input surface.
  let videoSurfaceId: string | undefined = undefined; // The surfaceID is passed in to the camera API to create a VideoOutput instance.
  try {
    videoSurfaceId = await resources.avRecorder.getInputSurface();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`getInputSurface call failed. error code: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }

  if (!videoSurfaceId) {
    await releaseResources();
    return;
  }

  // Create a VideoOutput instance.
  try {
    resources.videoOutput = cameraManager.createVideoOutput(videoProfile, videoSurfaceId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create the videoOutput instance. error: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }
  if (!resources.videoOutput) {
    console.error('videoOutput is null');
    await releaseResources();
    return;
  }

  let previewProfilesArray: Array<camera.Profile> = cameraOutputCap.previewProfiles;
  if (!previewProfilesArray || previewProfilesArray.length === 0) {
    console.error("previewProfilesArray is null or []");
    return;
  }

  // Create a preview output stream. The surfaceId parameter is provided by the XComponent.
  const previewProfile = previewProfilesArray.find((previewProfile: camera.Profile) => {
    return Math.abs((previewProfile.size.width / previewProfile.size.height) - (videoProfile.size.width / videoProfile.size.height)) < Number.EPSILON;
  }); // Select the preview resolution with the same aspect ratio as the recording resolution.
  if (!previewProfile) {
    console.error('No preview resolution found that matches the aspect ratio of the video resolution');
    await releaseResources();
    return;
  }

  try {
    resources.previewOutput = cameraManager.createPreviewOutput(previewProfile, surfaceId);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`createPreviewOutput call failed. error: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }
  if (!resources.previewOutput) {
    console.error('previewOutput is null');
    await releaseResources();
    return;
  }

  // Create a camera input stream.
  try {
    resources.cameraInput = cameraManager.createCameraInput(cameraDevice);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to createCameraInput. error: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }
  if (!resources.cameraInput) {
    console.error('cameraInput is null');
    await releaseResources();
    return;
  }

  // Listen for camera input errors.
  resources.cameraInput!.on('error', cameraDevice, (error: BusinessError) => {
    console.error(`Camera input error code: ${error.code}`);
  });

  // Open the camera.
  try {
    await resources.cameraInput!.open();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open cameraInput. error: ${err}`);
  }

  // Create a session.
  try {
    resources.videoSession = cameraManager.createSession(camera.SceneMode.NORMAL_VIDEO) as camera.VideoSession;
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create the session instance. error: ${JSON.stringify(err)}`);
    await releaseResources();
    return;
  }
  if (!resources.videoSession) {
    console.error('videoSession is null');
    await releaseResources();
    return;
  }
  // Listen for session errors.
  resources.videoSession!.on('error', (error: BusinessError) => {
    console.error(`Video session error code: ${error.code}`);
  });

  // Start configuration for the session.
  try {
    resources.videoSession!.beginConfig();
    resources.videoSession!.addInput(resources.cameraInput!);
    resources.videoSession!.addOutput(resources.videoOutput!);
    resources.videoSession!.addOutput(resources.previewOutput!);
    await resources.videoSession!.commitConfig();
    await resources.videoSession!.start();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Session Configuration Failure. error: ${err}`);
    await releaseResources();
    return;
  }

  // Start recording.
  try {
    await resources.videoOutput!.start();
    await resources.avRecorder!.start();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`avRecorder stop error: ${err}`);
  }

  // Stop the session.
  await resources.videoSession.stop();

  // Close the file.
  try {
    fs.closeSync(resources.file);
  } catch (error) {
    let err = error as BusinessError;
    console.error(`closeSync failed, error: ${err}`);
  }


  // Release the camera input stream.
  await resources.cameraInput.close();

  // Release the preview output stream.
  try {
    await resources.previewOutput.release();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`release previewOutput failed, error: ${err.code}`);
  }


  // Release the video output stream.
  try {
    await resources.videoOutput.release();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`release videoOutput failed, error: ${err.code}`);
  }

  // Release the session.
  try {
    await resources.videoSession.release();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`release videoSession failed, error: ${err.code}`);
  }

  // Set the session to null.
  resources.videoSession = undefined;
}
```
