# Using AVRecorder to Record Videos (ArkTS)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @gcw_dyOv3Sds-->
<!--Designer: @chris2981-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=c762d5590997ee857200dc2bee7887632750ad51 translatedAt=2026-08-11T01:57:53.890Z pushedAt=2026-08-12T03:30:17.064Z -->

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
> Only when an app needs to clone, back up, or sync image and video files in the user's public directory can it apply for the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions to read and write image and video files. For details about how to request permissions, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

> **NOTE**
>
> The AVRecorder only processes video data. To complete video recording, it must work with the video data collection module, which transfers the captured video data to the AVRecorder for data processing through the surface. Currently, the mainstream data collection module is the camera module. For details about the implementation, see [Video Recording](../camera/camera-recording.md).
> For details about how to create and save a file, see [Accessing Application Files](../../file-management/app-file-access.md). By default, files are saved in the sandbox path of the application. To save them to Gallery, use the [security components](../medialibrary/photoAccessHelper-savebutton.md).

For details about the APIs, see [AVRecorder](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md).

1. Create an AVRecorder instance. The AVRecorder is in the **idle** state.

   <!-- @[create_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   this.avRecorder = await media.createAVRecorder();
   ```

2. Set the events to listen for.

   | Event Type| Description|
   | -------- | -------- |
   | stateChange | Mandatory event, listens for changes to the recorder's state attribute. |
   | error | Mandatory event, listens for error information of the recorder. |

   <!-- @[set_callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
     console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
     // You can add the actions to perform after a state transition here.
     onStateChanged(state, reason);
   });
   this.avRecorder?.on('error', (error: BusinessError) => {
     console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
   });
   ```

3. Set video recording parameters and call [prepare](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#prepare9-1) to enter the **prepared** state.

> **NOTE**
>
> Pay attention to the following points when configuring parameters:
>
> - Before configuring parameters, ensure that the required permissions have been requested. For details, see [Requesting Permissions](#requesting-permissions).
>
> - In the `avConfig` parameter of the `prepare` API, set only video-related configuration parameters, as shown in the sample code.
>   If audio parameters are added, the system treats it as "audio + video recording."
>
> - Use the supported [recording specifications](media-kit-intro.md#supported-formats). The video bit rate, resolution, and frame rate are subject to the actual hardware device capabilities.
>
> - The output URL (that is, `url` in `avConfig` in the sample) must be in the format of `fd://xx` (fd number). You need to call basic file operation APIs ([ohos.file.fs in Core File Kit](../../reference/apis-core-file-kit/js-apis-file-fs.md)) to implement app file access. For details about how to obtain the URL, see [Accessing Application Files (ArkTS)](../../file-management/app-file-access.md).
> - For the file encapsulation format (`fileFormat`) and video encoding format (`videoCodec`) configured in the sample, see [AVRecorderProfile](../../reference/apis-media-kit/arkts-apis-media-i.md#avrecorderprofile9).

   <!-- @[prepare_video_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   public async prepareVideoRecorder(context: common.Context): Promise<void> {
     let path: string = context.filesDir + '/video_example.mp4';
     let file: fileIo.File = await fileIo.open(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
     this.fileFd = file.fd;

     let avRecorderConfig: media.AVRecorderConfig = {
       videoSourceType: this.videoSourceType, // Video source type.
       profile: {
         videoBitrate: 3000000, // Video bitrate.
         videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
         videoFrameWidth: this.videoResolution.frameWidth, // Video frame width.
         videoFrameHeight: this.videoResolution.frameHeight, // Video frame height.
         videoFrameRate: 30, // Video frame rate.
         fileFormat: media.ContainerFormatType.CFT_MPEG_4 // Container format.
       } as media.AVRecorderProfile,
       metadata: {
         videoOrientation: '90' // Video rotation angle. The default value is 0, which means no rotation. Supported values are 0, 90, 180, and 270.
       } as media.AVMetadata,
       url: 'fd://' + file.fd.toString()
     };

     try {
       if (this.avRecorder?.state === 'idle' || this.avRecorder?.state === 'stopped') {
         await this.avRecorder?.prepare(avRecorderConfig);
       }
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
       await this.closeFd();
     }
   }
   ```

4. Obtain the surface ID required for video recording.

   Call [getInputSurface](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#getinputsurface9-1). The surface ID in the return value is passed to the video data input source module. which is the camera module in the sample code.

     The video data collection module obtains the surface based on the surface ID and transmits video data to the AVRecorder through the surface. Then the AVRecorder processes the video data.

   <!-- @[get_input_surface](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   let surfaceId: string | undefined = undefined;
   try {
     surfaceId = await this.avRecorder?.getInputSurface();
   } catch (error) {
     let err = error as BusinessError;
     console.error(`Failed to get input surface, error code: ${err.code}, message: ${err.message}`);
   }
   ```

5. Initialize the video data input source. This step is performed in the video data collection module. For the camera module, you need to create a Camera instance, obtain the camera list, create a camera input stream, and create a video output stream. For details, see [Video Recording](../camera/camera-recording.md).

6. Start recording. Start the input source to input video data, for example, by calling **camera.VideoOutput.start** of the camera module. Call [start](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#start9-1). The AVRecorder enters the **started** state.

   <!-- @[start_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   await this.avRecorder?.start();
   ```

7. Call [pause](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#pause9-1) to pause the recording. The AVRecorder enters the **paused** state, and the input source stops inputting data, for example, by calling **camera.VideoOutput.stop** of the camera module.

   <!-- @[pause_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   await this.avRecorder?.pause();
   ```

8. Call [resume](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#resume9-1) to resume recording. The AVRecorder enters the **started** state again.

   <!-- @[resume_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   await this.avRecorder?.resume();
   ```

9. Call [stop](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#stop9-1) to stop recording. The AVRecorder enters the **stopped** state and the camera stops recording.

   <!-- @[stop_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

   ``` TypeScript
   await this.avRecorder?.stop();
   await this.closeFd();
   ```

10. Call [reset](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#reset9-1) to reset resources. The AVRecorder enters the **idle** state and recording parameters can be configured again.

    <!-- @[reset_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

    ``` TypeScript
    await this.avRecorder?.reset();
    ```

11. Call [release](../../reference/apis-media-kit/arkts-apis-media-AVRecorder.md#release9-1) to release the instance. The AVRecorder enters the **released** state, exits recording, and releases resources related to the video data input source, such as camera resources.

    <!-- @[release_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

    ``` TypeScript
    await this.avRecorder?.release();
    ```

## Complete Sample Code

Refer to the sample code below to complete the process of starting, pausing, resuming, and stopping recording.

<!-- @[full_video_recorder](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVRecorder/AVRecorder/entry/src/main/ets/services/AVRecorderService.ets) -->

``` TypeScript
import { BusinessError } from '@kit.BasicServicesKit';
import { media } from '@kit.MediaKit';
import { fileIo } from '@kit.CoreFileKit';
import { common } from '@kit.AbilityKit';
import { Resolution } from './CommonTypes';

export default class AVRecorderService {
  private avRecorder: media.AVRecorder | undefined = undefined;
  private fileFd: number | undefined = undefined;

  private audioSampleRate: number = 48000;
  private videoSourceType: media.VideoSourceType = media.VideoSourceType.VIDEO_SOURCE_TYPE_SURFACE_YUV;
  private videoResolution: Resolution = { frameWidth: 1920, frameHeight: 1080 } as Resolution;

  public async createRecorder(): Promise<void> {
    await this.releaseRecorder();
    try {
      this.avRecorder = await media.createAVRecorder();
    } catch (err) {
      let error: BusinessError = err as BusinessError;
      console.error(`Failed to create avRecorder, error code: ${error.code}, message: ${error.message}`);
    }
  }
  
  public setCallback(onStateChanged: media.OnAVRecorderStateChangeHandler): void {
    if (this.avRecorder) {
      console.info('setCallback');
    }
    this.avRecorder?.on('stateChange', (state: media.AVRecorderState, reason: media.StateChangeReason) => {
      console.info(`AVRecorder state is changed to ${state}, reason: ${reason}`);
      // You can add the actions to be performed after the state switch here.
      onStateChanged(state, reason);
    });
    this.avRecorder?.on('error', (error: BusinessError) => {
      console.error(`Error occurred in avRecorder, error code: ${error.code}, message: ${error.message}`);
    });
  }

  // ...

  public async prepareVideoRecorder(context: common.Context): Promise<void> {
    let path: string = context.filesDir + '/video_example.mp4';
    let file: fileIo.File = await fileIo.open(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
    this.fileFd = file.fd;

    let avRecorderConfig: media.AVRecorderConfig = {
      videoSourceType: this.videoSourceType, // Video source type.
      profile: {
        videoBitrate: 3000000, // Video bitrate.
        videoCodec: media.CodecMimeType.VIDEO_AVC, // Video encoding format.
        videoFrameWidth: this.videoResolution.frameWidth, // Video frame width.
        videoFrameHeight: this.videoResolution.frameHeight, // Video frame height.
        videoFrameRate: 30, // Video frame rate.
        fileFormat: media.ContainerFormatType.CFT_MPEG_4 // Container format.
      } as media.AVRecorderProfile,
      metadata: {
        videoOrientation: '90' // Video rotation angle. The default value is 0, which means no rotation. Supported values are 0, 90, 180, and 270.
      } as media.AVMetadata,
      url: 'fd://' + file.fd.toString()
    };

    try {
      if (this.avRecorder?.state === 'idle' || this.avRecorder?.state === 'stopped') {
        await this.avRecorder?.prepare(avRecorderConfig);
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to prepare avRecorder, error code: ${err.code}, message: ${err.message}`);
      await this.closeFd();
    }
  }

  async getInputSurface(): Promise<string | undefined> {
    let surfaceId: string | undefined = undefined;
    try {
      surfaceId = await this.avRecorder?.getInputSurface();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to get input surface, error code: ${err.code}, message: ${err.message}`);
    }
    return surfaceId;
  }

  public async startRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'prepared') {
        await this.avRecorder?.start();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to start avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async pauseRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'started') {
        await this.avRecorder?.pause();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to pause avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async resumeRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'paused') {
        await this.avRecorder?.resume();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to resume avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async stopRecorder(): Promise<void> {
    try {
      if (this.avRecorder?.state === 'started' || this.avRecorder?.state === 'paused') {
        await this.avRecorder?.stop();
        await this.closeFd();
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to stop avRecorder, error code: ${err.code}, message: ${err.message}`);
      await this.closeFd();
    }
  }
  
  public async resetRecorder(): Promise<void> {
    try {
      await this.avRecorder?.reset();
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to reset avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async releaseRecorder(): Promise<void> {
    try {
      this.avRecorder?.off('stateChange');
      this.avRecorder?.off('error');
      await this.avRecorder?.release();
      this.avRecorder = undefined;
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to release avRecorder, error code: ${err.code}, message: ${err.message}`);
    }
  }

  public async closeFd(): Promise<void> {
    try {
      if (this.fileFd) {
        await fileIo.close(this.fileFd!);
        this.fileFd = undefined;
      }
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
    }
  }
}
```