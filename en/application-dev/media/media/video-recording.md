# Using AVRecorder to Record Videos (ArkTS)
<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @zzs911-->

You can use the [AVRecorder](media-kit-intro.md#avrecorder) to develop the video recording service. The AVRecorder supports audio capture, audio encoding, video encoding, audio encapsulation, and video encapsulation. It is applicable to simple video recording scenarios and can be used to generate local video files directly.

In this topic, you will learn how to use the AVRecorder to complete the process of starting, pausing, resuming, and stopping video recording.

During application development, you can use the **state** property of AVRecorder to obtain its current state or use [on('stateChange')](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#onstatechange9) to listen for state change events. During development, you must strictly comply with the state machine requirements. For example, you can call the [pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1) API only in the **started** state and call the [resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1) API only in the **paused** state.

**Figure 1** Recording state transition

![Recording state change](figures/video-recording-status-change.png)

For details about the states, see [AVRecorderState](../../reference/apis-media-kit/arkts-apis-media-t.md#avrecorderstate9).


## Requesting Permissions

Before your development, configure the following permissions for your application.
- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
- To use the camera for photo capture, request the ohos.permission.CAMERA permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
- To read images or videos from Gallery, preferentially use the media library [Picker for access](../medialibrary/photoAccessHelper-photoviewpicker.md).
- To save images or videos to Gallery, preferentially use the [security component for storage](../medialibrary/photoAccessHelper-savebutton.md).

> **NOTE**
>
> To clone, back up, or synchronize images and videos in users' public directory, request the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.


## How to Develop

> **NOTE**
>
> The AVRecorder only processes video data. To complete video recording, it must work with the video data collection module, which transfers the captured video data to the AVRecorder for data processing through the surface. Currently, the mainstream data collection module is the camera module. For details about the implementation, see [Video Recording](../camera/camera-recording.md).
> For details about how to create and save a file, see [Accessing Application Files](../../file-management/app-file-access.md). By default, files are saved in the sandbox path of the application. To save them to Gallery, use the [security components](../medialibrary/photoAccessHelper-savebutton.md).


For details about the APIs, see [AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md).

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   private avRecorder: media.AVRecorder | undefined = undefined;

   try {
     this.avRecorder = await media.createAVRecorder();
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to create avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

2. Set the events to listen for.
   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory; used to listen for changes of the **state** property of the AVRecorder.|
   | error | Mandatory; used to listen for AVRecorder errors.|

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   // Callback function for state changes.
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
   });
   // Callback function for errors.
   this.avRecorder?.on('error', (error: BusinessError) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. Set video recording parameters and call [prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1) to enter the **prepared** state.

   > **NOTE**
   >
   > Pay attention to the following when configuring parameters:
   >
   > - Before parameter configuration, ensure that you have gained the required permissions. For details, see [Requesting Permissions](#requesting-permissions).
   >
   > - In pure video recording scenarios, set only video-related parameters in **avConfig** of **prepare()**.
   >   If audio-related parameters are configured, the system regards it as audio and video recording.
   >
   > - The [recording specifications](media-kit-intro.md#supported-formats) in use must be those supported. The video bit rate, resolution, and frame rate are subject to the ranges supported by the hardware device.
   >
   > - The recording output URL (URL in **avConfig** in the sample code) must be in the format of fd://xx (where xx indicates a file descriptor). You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Accessing Application Files](../../file-management/app-file-access.md).
   > - For details about the video file encapsulation format (**fileFormat**) and video encoding format (**videoCodec**) configured in the sample code, see [AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9).

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo } from '@kit.CoreFileKit';

   let avProfile: media.AVRecorderProfile = {
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file encapsulation format.
     videoBitrate: 200000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC, // Video file encoding format.
     videoFrameWidth: 640, // Video frame width.
     videoFrameHeight: 480, // Video frame height.
     videoFrameRate: 30 // Video frame rate
   };

   let videoMetaData: media.AVMetadata = {
     videoOrientation: '0' // Video rotation angle. The default value is 0, indicating that the video is not rotated. The value can be 0, 90, 180, or 270.
   };

   const context: Context = this.getUIContext().getHostContext()!; // Refer to Accessing Application Files.
   let filePath: string = context.filesDir + '/example.mp4';
   let videoFile: fileIo.File = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
   let fileFd: number = videoFile.fd; // Obtain the file FD.
  
   let avConfig: media.AVRecorderConfig = {
     videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // Video source type. YUV and ES are supported.
     profile: avProfile,
     url: 'fd://' + fileFd.toString(), // Create, read, and write a video file by referring to the sample code in Application File Access and Management.
     metadata: videoMetaData
   };

   try {
     await this.avRecorder?.prepare(avConfig);
     console.info('Succeeded in preparing avRecorder');
   } catch (err) {
     let error: BusinessError = err as BusinessError;
     console.error(`Failed to prepare avRecorder, error code: ${error.code}, message: ${error.message}`);
   }
   ```

4. Obtain the surface ID required for video recording.

   Call [getInputSurface](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#getinputsurface9-1). The surface ID in the return value is passed to the video data input source module. which is the camera module in the sample code.

     The video data collection module obtains the surface based on the surface ID and transmits video data to the AVRecorder through the surface. Then the AVRecorder processes the video data.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   this.avRecorder?.getInputSurface().then((surfaceId: string) => {
     console.info('Succeeded in getting input surface');
   }, (error: BusinessError) => {
     console.error(`Failed to get input surface, error code: ${error.code}, message: ${error.message}`);
   });
   ```

5. Initialize the video data input source. This step is performed in the video data collection module. For the camera module, you need to create a Camera instance, obtain the camera list, create a camera input stream, and create a video output stream. For details, see [Video Recording](../camera/camera-recording.md).

6. Start recording. Start the input source to input video data, for example, by calling **camera.VideoOutput.start** of the camera module. Call [start](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#start9-1). The AVRecorder enters the **started** state.

7. Call [pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1) to pause the recording. The AVRecorder enters the **paused** state, and the input source stops inputting data. for example, by calling **camera.VideoOutput.stop** of the camera module.

8. Call [resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1) to resume recording. The AVRecorder enters the **started** state again.

9. Call [stop](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#stop9-1) to stop recording. The AVRecorder enters the **stopped** state and the camera stops recording.

10. Call [reset](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#reset9-1) to reset resources. The AVRecorder enters the **idle** state and recording parameters can be configured again.

11. Call [release](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#release9-1) to release the instance. The AVRecorder enters the **released** state, exits recording, and releases resources related to the video data input source, such as camera resources.


## Complete Sample Code

Refer to the sample code below to complete the process of starting, pausing, resuming, and stopping recording.


```ts
import { common } from '@kit.AbilityKit';
import { camera } from '@kit.CameraKit';
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileUri } from '@kit.CoreFileKit';
import { fileIo } from '@kit.CoreFileKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function videoRecording(context: common.Context): Promise<void> {
  // Create an AVRecorder instance named avRecorder.
  let avRecorder: media.AVRecorder | undefined = undefined;
  try {
    avRecorder = await media.createAVRecorder();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to create avRecorder, error code: ${err.code}, message: ${err.message}`);
    return;
  }
  
  // Set AVRecorder callback functions.
  try {
    // Callback for state changes.
    avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
      console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
    });
    // Callback function for errors.
    avRecorder.on('error', (error: BusinessError) => {
      console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
    });
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to set avRecorder callback, error code: ${err.code}, message: ${err.message}`);
  }

  // Set recording parameters to complete the preparations.
  let avProfile: media.AVRecorderProfile = {
    fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file encapsulation format.
    videoBitrate: 100000, // Video bit rate.
    videoCodec: media.CodecMimeType.VIDEO_AVC, // Video file encoding format.
    videoFrameWidth: 640, // Video frame width.
    videoFrameHeight: 480, // Video frame height.
    videoFrameRate: 30 // Video frame rate
  };
  let videoMetaData: media.AVMetadata = {
    videoOrientation: '0' // Video rotation angle. The default value is 0, indicating that the video is not rotated. The value can be 0, 90, 180, or 270.
  };
  let avConfig: media.AVRecorderConfig = {
    videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // Video source type. YUV and ES are supported.
    profile: avProfile,
    url: 'fd://35', // Create, read, and write a file by referring to the sample code in Application File Access and Management.
    metadata: videoMetaData
  };

  // Create a file and set avConfig.url.
  let filePath: string = ''; // File path.
  let videoFile: fileIo.File | undefined = undefined;
  try {
    filePath = context.filesDir + '/example.mp4'; // File sandbox path. The file name extension must match the encapsulation format.
    videoFile = fileIo.openSync(filePath, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE); // Open the file.
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to open file, error code: ${err.code}, message: ${err.message}`);
  }
  if (videoFile !== undefined) {
    avConfig.url = 'fd://' + videoFile.fd; // Update the URL.
  }

  // Set recording parameters to complete the preparations.
  try {
    if (avRecorder.state === 'idle' || avRecorder.state === 'stopped') { // prepare() can be called only when the AVRecorder is in the idle or stopped state.
      await avRecorder.prepare(avConfig);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Complete camera-related preparations.
  let cameraManager: camera.CameraManager = camera.getCameraManager(context);
  let videoOutSurfaceId: string = await avRecorder.getInputSurface();
  await prepareCamera(cameraManager, videoOutSurfaceId);

  // Start recording.
  try {
    if (avRecorder.state === 'prepared') { // start() can be called only when the AVRecorder is in the prepared state.
      await startCameraOutput(); // Start camera stream output.
      await avRecorder.start();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to start avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Pause recording.
  try {
    if (avRecorder.state === 'started') { // pause() can be called only when the AVRecorder is in the started state.
      await avRecorder.pause();
      await stopCameraOutput(); // Stop the camera stream output.
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Resume recording.
  try {
    if (avRecorder.state === 'paused') { // resume() can be called only when the AVRecorder is in the paused state.
      await startCameraOutput(); // Start camera stream output.
      await avRecorder.resume();
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to resume avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Stop recording.
  try {
    if (avRecorder.state === 'started' || avRecorder.state === 'paused') { // stop() can be called only when the AVRecorder is in the started or paused state.
      await avRecorder.stop();
      await stopCameraOutput(); // Stop the camera stream output.
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to stop avRecorder, error code: ${err.code}, message: ${err.message}`);
  }
  
  // Reset recording.
  try {
    await avRecorder.reset();
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to reset avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Release the AVRecorder instance.
  try {
    await avRecorder.release();
    avRecorder = undefined;
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to release avRecorder, error code: ${err.code}, message: ${err.message}`);
  }

  // Close the file descriptor of the recording file.
  try {
    if (videoFile !== undefined) {
      await fileIo.close(videoFile.fd);
    }
  } catch (error) {
    let err = error as BusinessError;
    console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
  }

  // Release the camera instance.
  await releaseCamera();
  
  // The security component saves the media asset to Gallery.
  let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

  // Ensure that the asset specified by uriPath exists.
  let uriPath: string = fileUri.getUriFromPath(filePath); // Obtain the file URI, which is used by the security component when saving the file to Gallery.
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = 
    photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(context, uriPath);
  await phAccessHelper.applyChanges(assetChangeRequest);
}

// Complete camera-related preparations.
async function prepareCamera(cameraManager: camera.CameraManager, videoOutSurfaceId: string) {
  // For details on the implementation, see the camera document.
}

// Start the camera stream output.
async function startCameraOutput() {
  // Call start of the VideoOutput class to start video output.
}

// Stop the camera stream output.
async function stopCameraOutput() {
  // Call stop of the VideoOutput class to stop video output.
}

// Release the camera instance.
async function releaseCamera() {
  // Release the instances created during camera preparation.
}
```
