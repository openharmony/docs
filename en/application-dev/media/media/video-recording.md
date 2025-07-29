# Using AVRecorder to Record Videos (ArkTS)

You can use the [AVRecorder](media-kit-intro.md#avrecorder) to develop the video recording service. The AVRecorder supports audio capture, audio encoding, video encoding, audio encapsulation, and video encapsulation. It is applicable to simple video recording scenarios and can be used to generate local video files directly.

In this topic, you will learn how to use the AVRecorder to complete the process of starting, pausing, resuming, and stopping video recording.

During application development, you can use the **state** property of the AVRecorder to obtain the AVRecorder state or call **on('stateChange')** to listen for state changes. Your code must meet the state machine requirements. For example, **pause()** is called only when the AVRecorder is in the **started** state, and **resume()** is called only when it is in the **paused** state.

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
>
> For details about how to create and save a file, see [Accessing Application Files](../../file-management/app-file-access.md). By default, files are saved in the sandbox path of the application. To save them to Gallery, use the [security components](../medialibrary/photoAccessHelper-savebutton.md).


Read [AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md) for the API reference.

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   let avRecorder: media.AVRecorder;
   media.createAVRecorder().then((recorder: media.AVRecorder) => {
     avRecorder = recorder;
   }, (error: BusinessError) => {
     console.error('createAVRecorder failed');
   })
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
   this.avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info('current state is: ' + state);
   })
   // Callback function for errors.
   this.avRecorder.on('error', (err: BusinessError) => {
     console.error('error happened, error message is ' + err);
   })
   ```

3. Set video recording parameters and call **prepare()**. The AVRecorder enters the **prepared** state.

   > **NOTE**
   >
   > Pay attention to the following when configuring parameters:
   >
   > - Before parameter configuration, ensure that you have gained the required permissions. For details, see [Requesting Permissions](#requesting-permissions).
   >
   > - In pure video recording scenarios, set only video-related parameters in **avConfig** of **prepare()**. If audio-related parameters are configured, the system regards it as audio and video recording.
   >
   > - The [recording specifications](media-kit-intro.md#supported-formats) in use must be those supported. The video bit rate, resolution, and frame rate are subject to the ranges supported by the hardware device.
   >
   > - The recording output URL (URL in **avConfig** in the sample code) must be in the format of fd://xx (where xx indicates a file descriptor). You must call [ohos.file.fs of Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md) to implement access to the application file. For details, see [Accessing Application Files](../../file-management/app-file-access.md).

   ```ts
   import { media } from '@kit.MediaKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { fileIo as fs } from '@kit.CoreFileKit';

   let avProfile: media.AVRecorderProfile = {
     fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file container format. Only MP4 is supported.
     videoBitrate: 200000, // Video bit rate.
     videoCodec: media.CodecMimeType.VIDEO_AVC, // Video file encoding format. AVC is supported.
     videoFrameWidth: 640, // Video frame width.
     videoFrameHeight: 480, // Video frame height.
     videoFrameRate: 30 // Video frame rate.
   };

   let videoMetaData: media.AVMetadata = {
     videoOrientation: '0' // Video rotation angle. The default value is 0, indicating that the video is not rotated. The value can be 0, 90, 180, or 270.
   };

   const context: Context = this.getUIContext().getHostContext()!; // Refer to Accessing Application Files.
   let filePath: string = context.filesDir + '/example.mp4';
   let videoFile: fs.File = fs.openSync(filePath, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
   let fileFd = videoFile.fd; // Obtain the file FD.
  
   let avConfig: media.AVRecorderConfig = {
     videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // Video source type. YUV and ES are supported.
     profile : avProfile,
     url: 'fd://' + fileFd.toString(), // Create, read, and write a video file by referring to the sample code in Accessing Application Files.
     metadata : videoMetaData
   };
   this.avRecorder.prepare(avConfig).then(() => {
     console.info('avRecorder prepare success');
   }, (error: BusinessError) => {
     console.error('avRecorder prepare failed');
   })
   ```

4. Obtain the surface ID required for video recording.

   Call **getInputSurface()**. The returned surface ID is transferred to the video data collection module, which is the camera module in the sample code.

   The video data collection module obtains the surface based on the surface ID and transmits video data to the AVRecorder through the surface. Then the AVRecorder processes the video data.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';

   this.avRecorder.getInputSurface().then((surfaceId: string) => {
     console.info('avRecorder getInputSurface success');
   }, (error: BusinessError) => {
     console.error('avRecorder getInputSurface failed');
   })
   ```

5. Initialize the video data input source.

   This step is performed in the video data collection module. For the camera module, you need to create a Camera instance, obtain the camera list, create a camera input stream, and create a video output stream. For details, see [Video Recording](../camera/camera-recording.md).

6. Start recording.

   Start the input source to input video data, for example, by calling **camera.VideoOutput.start** of the camera module. Then call **AVRecorder.start()** to switch the AVRecorder to the **started** state.

7. Call **pause()** to pause recording. The AVRecorder enters the **paused** state. In addition, pause data input, for example, by calling **camera.VideoOutput.stop** of the camera module.

8. Call **resume()** to resume recording. The AVRecorder enters the **started** state again.

9. Call **stop()** to stop recording. The AVRecorder enters the **stopped** state again. In addition, stop camera recording.

10. Call **reset()** to reset the resources. The AVRecorder enters the **idle** state. In this case, you can reconfigure the recording parameters.

11. Call **release()** to release the resources. The AVRecorder enters the **released** state. In addition, release the video data input source resources (camera resources in this example).


## Sample Code

Refer to the sample code below to complete the process of starting, pausing, resuming, and stopping recording.


```ts
import { media } from '@kit.MediaKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { fileIo as fs, fileUri } from '@kit.CoreFileKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';


const TAG = 'VideoRecorderDemo:';
export class VideoRecorderDemo extends CustomComponent {
  private context: Context;
  constructor() {
    super();
    this.context = this.getUIContext().getHostContext()!;
  }
  private avRecorder: media.AVRecorder | undefined = undefined;
  private videoOutSurfaceId: string = "";
  private avProfile: media.AVRecorderProfile = {
    fileFormat: media.ContainerFormatType.CFT_MPEG_4, // Video file container format. Only MP4 is supported.
    videoBitrate: 100000, // Video bit rate.
    videoCodec: media.CodecMimeType.VIDEO_AVC, // Video file encoding format. AVC is supported.
    videoFrameWidth: 640, // Video frame width.
    videoFrameHeight: 480, // Video frame height.
    videoFrameRate: 30 // Video frame rate.
  };
  private videoMetaData: media.AVMetadata = {
    videoOrientation: '0' // Video rotation angle. The default value is 0, indicating that the video is not rotated. The value can be 0, 90, 180, or 270.
  };
  private avConfig: media.AVRecorderConfig = {
    videoSourceType: media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV, // Video source type. YUV and ES are supported.
    profile : this.avProfile,
    url: 'fd://35', // Create, read, and write a file by referring to the sample code in Accessing Application Files.
    metadata : this.videoMetaData
  };
  
  private uriPath: string = ''; // File URI, which can be used by the security component to save the media asset.
  private filePath: string = ''; // File path.
  private fileFd: number = 0;
  
  // Create a file and set avConfig.url.
  async createAndSetFd() {
    const path: string = this.context.filesDir + '/example.mp4'; // File sandbox path. The file name extension must match the container format.
    const videoFile: fs.File = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    this.avConfig.url = 'fd://' + videoFile.fd; // Set the URL.
    this.fileFd = videoFile.fd; // File FD.
    this.filePath = path;
  }

  // Set AVRecorder callback functions.
  setAvRecorderCallback() {
    if (this.avRecorder != undefined) {
      // Callback for state changes.
      this.avRecorder.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
        console.info(TAG + 'current state is: ' + state);
      })
      // Callback function for errors.
      this.avRecorder.on('error', (err: BusinessError) => {
        console.error(TAG + 'error ocConstantSourceNode, error message is ' + err);
      })
    }
  }

  // Complete camera-related preparations.
  async prepareCamera() {
    // For details on the implementation, see the camera document.
  }

  // Start the camera stream output.
  async startCameraOutput() {
    // Call start of the VideoOutput class to start video output.
  }

  // Stop the camera stream output.
  async stopCameraOutput() {
    // Call stop of the VideoOutput class to stop video output.
  }

  // Release the camera instance.
  async releaseCamera() {
    // Release the instances created during camera preparation.
  }

  // Process of starting recording.
  async startRecordingProcess() {
    if (this.avRecorder === undefined) {
      // 1. Create an AVRecorder instance.
      this.avRecorder = await media.createAVRecorder();
      this.setAvRecorderCallback();
    }
    // 2. Obtain the file descriptor of the recorded file. The obtained file descriptor is passed in to the URL in avConfig. The implementation is omitted here.
    // 3. Set recording parameters to complete the preparations.
    await this.avRecorder.prepare(this.avConfig);
    this.videoOutSurfaceId = await this.avRecorder.getInputSurface();
    // 4. Complete camera-related preparations.
    await this.prepareCamera();
    // 5. Start the camera stream output.
    await this.startCameraOutput();
    // 6. Start recording.
    await this.avRecorder.start();

  }

  // Process of pausing recording.
  async pauseRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'started') { // pause() can be called only when the AVRecorder is in the started state .
      await this.avRecorder.pause();
      await this.stopCameraOutput(); // Stop the camera stream output.
    }
  }

  // Process of resuming recording.
  async resumeRecordingProcess() {
    if (this.avRecorder != undefined && this.avRecorder.state === 'paused') { // resume() can be called only when the AVRecorder is in the paused state .
      await this.startCameraOutput(); // Start camera stream output.
      await this.avRecorder.resume();
    }
  }

  async stopRecordingProcess() {
    if (this.avRecorder != undefined) {
      // 1. Stop recording.
      if (this.avRecorder.state === 'started'
        || this.avRecorder.state ==='paused') { // stop() can be called only when the AVRecorder is in the started or paused state.
        await this.avRecorder.stop();
        await this.stopCameraOutput();
      }
      // 2. Reset the AVRecorder.
      await this.avRecorder.reset();
      // 3. Release the AVRecorder instance.
      await this.avRecorder.release();
      // 4. After the file is recorded, close the file descriptor. The implementation is omitted here.
      await fs.close(this.fileFd);
      // 5. Release the camera instance.
      await this.releaseCamera();
    }
  }
  
  // The security component saves the media asset to Gallery.
  async saveRecorderAsset() {
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(this.context);
    // Ensure that the asset specified by uriPath exists.
    this.uriPath = fileUri.getUriFromPath(this.filePath); // Obtain the file URI, which is used by the security component when saving the file to Gallery.
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = 
      photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(this.context, this.uriPath);
    await phAccessHelper.applyChanges(assetChangeRequest);
  }

  // Complete sample code for starting, pausing, resuming, and stopping recording.
  async videoRecorderDemo() {
    await this.startRecordingProcess();         // Start recording.
    // You can set the recording duration. For example, you can set the sleep mode to prevent code execution.
    await this.pauseRecordingProcess();         // Pause recording.
    await this.resumeRecordingProcess();        // Resume recording.
    await this.stopRecordingProcess();          // Stop recording.
    // The security component saves the media asset to Gallery.
    await this.saveRecorderAsset();
  }
}
```
