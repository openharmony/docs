# Using AVScreenCaptureRecorder to Record Screens and Write Them to Files (ArkTS)

<!--Kit: Media Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @chenkun613227-->
<!--Designer: @yxc2-->
<!--Tester: @xdlinc-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=967d5c9e466e5ee21347335d5ae1cf0c051f0215 translatedAt=2026-08-11T01:54:28.227Z pushedAt=2026-08-11T13:06:49.802Z -->

Screen capture is mainly used to record the main screen.

You can call the ArkTS APIs of the screen capture ([AVScreenCaptureRecorder](media-kit-intro.md#avscreencapture)) module to record the screen and capture audio and video source data from the device, microphone, and other sources. The screen capture module can be used to obtain audio and video files, which can then be transferred to other modules in file form for playback or processing, enabling screen content sharing through files.

The AVScreenCaptureRecorder, Window, and Graphics modules together implement the entire video capture process.

The full-screen capture process involves creating an AVScreenCaptureRecorder instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing resources.

If you are in a call when screen capture starts or a call is coming during screen capture, screen capture automatically stops, and the **SCREENCAPTURE_STATE_STOPPED_BY_CALL** status is reported.

This topic describes how to use the AVScreenCaptureRecorder APIs to carry out one-time screen capture. For details about the API reference, see [AVScreenCaptureRecorder](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md).

If microphone data collection is configured, configure the permission ohos.permission.MICROPHONE and request a continuous task. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md) and [Continuous Task](../../task-management/continuous-task.md).

## Applying for Permission

Before your development, configure the following permissions for your application.

- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

- To read images or videos, preferentially use the media library [Picker for access](../medialibrary/photoAccessHelper-photoviewpicker.md).

- To save images or videos, preferentially use the [security component for storage](../medialibrary/photoAccessHelper-savebutton.md).

- Starting from API version 22, when you perform screen capture for an application on a PC/2-in-1 device, you can request the ohos.permission.TIMEOUT_SCREENOFF_DISABLE_LOCK permission to maintain capture even when the screen is off but not locked. For details about the configuration, [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

- Starting from API version 22, when you perform screen capture for an application on a PC/2-in-1 device, you can request the ohos.permission.CUSTOM_SCREEN_RECORDING permission to prevent the privacy protection pop-up from being displayed during screen capture. For details about how to request the permission, see [Requesting Restricted Permissions](../../security/AccessToken/restricted-permissions.md).

> **NOTE**
>
> Only when an app needs to clone, back up, or synchronize image and video files in the user's public directory can it request the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions to read and write image and video files. For details about how to request permissions, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

After an AVScreenCaptureRecorder instance is created, different APIs can be called to switch the AVScreenCaptureRecorder to different states and trigger the required behavior. If an API is called when the AVScreenCaptureRecorder is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCaptureRecorder state before triggering state transition.

1. Import modules.

   <!-- @[screenCapture_arkts_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   import { common } from '@kit.AbilityKit';
   import { media } from '@kit.MediaKit';
   import { fileIo } from '@kit.CoreFileKit';
   import { display } from '@kit.ArkUI';
   ```

2. Create the member variable **screenCapture** of the **AVScreenCaptureRecorder** type.

   <!-- @[screenCapture_arkts_create](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   // Declare an AVScreenCaptureRecorder and assign it to the screenCapture member variable.
   private screenCapture?: media.AVScreenCaptureRecorder;
   
   async createAVScreenCapture(): Promise<void> {
     // Create an AVScreenCaptureRecorder and assign it to the screenCapture member variable.
     this.screenCapture = await media.createAVScreenCaptureRecorder();
   }
   ```

3. Set callback functions for the member variable **screenCapture** to listen for state changes and errors.

   <!-- @[screenCapture_arkts_Callback](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   this.screenCapture?.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
     switch (infoType) {
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
         console.info(`Callback received after screen recording starts successfully.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
         this.screenCapture?.release();
         this.screenCapture = undefined;
         console.info(`Screen recording is not allowed.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
         this.screenCapture?.release();
         this.screenCapture = undefined;
         console.info(`Screen recording ended via the screen recording capsule. The underlying recording will stop.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
         console.info(`Screen recording stopped due to another interruption. The underlying recording will stop.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
         console.info(`Screen recording interrupted by an incoming call. The underlying recording will stop.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
         console.info(`Screen recording microphone is unavailable.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
         console.info(`Screen recording microphone muted by the user.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
         console.info(`Screen recording microphone unmuted by the user.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
         // Currently, the system can directly register a listener for entering a privacy scene.
         console.info(`Screen recording enters a privacy scene.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
         console.info(`Screen recording exits a privacy scene.`);
         break;
       case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
         console.info(`User account switched. The underlying recording will stop.`);
         break;
       default:
         break;
     }
   })
   this.screenCapture?.on('error', (err) => {
     console.error(`Exception handled, code is ${err.code}, message is ${err.message}.`);
   })
   ```

4. Set screen capture parameters.

   After creating the AVScreenCaptureRecorder instance **screenCapture**, you can set the parameters required for screen recording.

   The parameters **videoBitrate**, **audioSampleRate**, **audioChannelCount**, **audioBitrate**, **preset**, and **displayId** are optional. If they are not set, default values are used. The following example provides the default values of these optional parameters. The microphone and system audio streams share the same set of audio parameters, namely the audio sampling rate, audio channel count, and audio bitrate, which correspond to the **audioSampleRate**, **audioChannelCount**, and **audioBitrate** parameters, respectively.

   For the **fd** parameter, refer to the development example in [Creating, Reading, and Writing a File](../../file-management/app-file-access.md). The **openFile()** method provided in this example is for reference only.

   On a PC/2-in-1 device, when **displayId** is set to the extended display ID, a screen capture window selection interface can be opened. The user can select the content to capture in this interface, and the final captured content is determined by the user's selection in the dialog box.

   <!-- @[screenCapture_arkts_config](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   openFile(context: Context): void {
     const path: string = context.filesDir + '/screenCapture.mp4';
     this.captureFile = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
   }

   setConfig(context: Context): void {
     this.openFile(context);
     if (!this.captureFile) {
       console.error(`Handle the exception.`)
       return;
     }
     let displayClass: display.Display | undefined = undefined;
     try {
       displayClass = display.getDefaultDisplaySync();
       console.info(`The display info is: ${JSON.stringify(displayClass)}`);
     } catch (exception) {
       console.error(`Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
     }
     if (!displayClass) {
       console.error(`Failed to get displayClass.`);
       return;
     }
     this.captureConfig = {
         // You can set the dimensions based on the screen width and height.
         // The screen width must be set to a multiple of 64.
         frameWidth: displayClass.width,
         // Set the height based on the screen height.
         frameHeight: displayClass.height,
         // Refer to the Application File Access and Management development example to create and read/write a file descriptor (fd).
         fd: this.captureFile.fd,
         // Optional parameters and their default values.
         videoBitrate: 10000000,
         audioSampleRate: 48000,
         audioChannelCount: 2,
         audioBitrate: 96000,
         displayId: 0,
         preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
       };
   }
   ```

5. Call [init](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md#init12) to initialize **screenCapture** based on the preconfigured screen recording parameters.

   <!-- @[screenCapture_arkts_init](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   await this.screenCapture?.init(this.captureConfig);
   ```

6. Set the windows that will be skipped during screen capture, by entering the subwindow IDs and main window IDs. For details, see [WindowProperties](../../reference/apis-arkui/arkts-apis-window-i.md#windowproperties).

   <!-- @[screenCapture_arkts_skipPrivacyMode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   let windowIDs: number[] = [57, 86];
   await this.screenCapture?.skipPrivacyMode(windowIDs);
   ```

7. Call [startRecording](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md#startrecording12) to start screen capture and use a listener to monitor state change events.

   <!-- @[screenCapture_arkts_startRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   await this.screenCapture?.startRecording();
   ```

8. Stop screen capture.

   - Tap the end button in the screen recording capsule to stop recording: This is implemented based on a callback function. The screen capture instance **screenCapture** triggers the SCREENCAPTURE_STATE_STOPPED_BY_USER callback to notify the app that the screen recording has stopped. You do not need to actively call the [stopRecording](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md#stoprecording12) method.

   - The app actively calls the [stopRecording](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md#stoprecording12) method to stop screen recording.

     <!-- @[screenCapture_arkts_stopRecording](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

     ``` TypeScript
     await this.screenCapture?.stopRecording();
     ```

9. Call [release](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md#release12) to release the instance.

   <!-- @[screenCapture_arkts_release](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) --> 

   ``` TypeScript
   await this.screenCapture?.release();
   ```

## Complete Sample Code

The following is the complete sample code for capturing a screen and saving the screen data captured to a file using **AVScreenCaptureRecorder**.

<!-- @[screenCapture_arkts_demo](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/ScreenCapture/ScreenCaptureSample/entry/src/main/ets/pages/AVScreenCaptureDemo.ets) -->  

``` TypeScript
import { common } from '@kit.AbilityKit';
import { media } from '@kit.MediaKit';
import { fileIo } from '@kit.CoreFileKit';
import { display } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

export class AVScreenCaptureDemo {
  private captureFile: fileIo.File | undefined = undefined;
  private captureConfig: media.AVScreenCaptureRecordConfig | undefined = undefined;
  // Declare an AVScreenCaptureRecorder and assign it to the screenCapture member variable.
  private screenCapture?: media.AVScreenCaptureRecorder;

  async createAVScreenCapture(): Promise<void> {
    // Create an AVScreenCaptureRecorder and assign it to the screenCapture member variable.
    this.screenCapture = await media.createAVScreenCaptureRecorder();
  }

  closeFile(): void {
    if (!this.captureFile) {
      return;
    }
    try {
      fileIo.closeSync(this.captureFile.fd);
    } catch (error) {
      let err = error as BusinessError;
      console.error(`Failed to close fd, error code: ${err.code}, message: ${err.message}`);
    }
  }
  openFile(context: Context): void {
    const path: string = context.filesDir + '/screenCapture.mp4';
    this.captureFile = fileIo.openSync(path, fileIo.OpenMode.READ_WRITE | fileIo.OpenMode.CREATE);
  }

  setConfig(context: Context): void {
    this.openFile(context);
    if (!this.captureFile) {
      console.error(`Handle the exception.`)
      return;
    }
    let displayClass: display.Display | undefined = undefined;
    try {
      displayClass = display.getDefaultDisplaySync();
      console.info(`The display info is: ${JSON.stringify(displayClass)}`);
    } catch (exception) {
      console.error(`Failed to get default display. Code: ${exception.code}, message: ${exception.message}`);
    }
    if (!displayClass) {
      console.error(`Failed to get displayClass.`);
      return;
    }
    this.captureConfig = {
        // Set the dimensions based on the screen width and height.
        // The screen width must be set to a multiple of 64.
        frameWidth: displayClass.width,
        // Set the height based on the screen height.
        frameHeight: displayClass.height,
        // Create, read, and write a file descriptor by referring to the sample code in Accessing Application Files.
        fd: this.captureFile.fd,
        // Optional parameters and their default values
        videoBitrate: 10000000,
        audioSampleRate: 48000,
        audioChannelCount: 2,
        audioBitrate: 96000,
        displayId: 0,
        preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
      };
  }

  registerScreenCaptureCallback(): void {
    this.screenCapture?.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
      switch (infoType) {
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
          console.info(`Callback received after screen recording starts successfully.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info(`Screen recording is not allowed.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info(`Screen recording ended via the screen recording capsule. The underlying recording will stop.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
          console.info(`Screen recording stopped due to another interruption. The underlying recording will stop.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
          console.info(`Screen recording interrupted by an incoming call. The underlying recording will stop.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
          console.info(`Screen recording microphone is unavailable.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
          console.info(`Screen recording microphone muted by the user.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
          console.info(`Screen recording microphone unmuted by the user.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
          // Currently, you can directly register a listener from the system to enter the privacy scenario.
          console.info(`Screen recording enters a privacy scenario.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
          console.info(`Screen recording exits the privacy scenario.`);
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
          console.info(`User account switched. The underlying recording will stop.`);
          break;
        default:
          break;
      }
    })
    this.screenCapture?.on('error', (err) => {
      console.error(`Handle exceptions, code is ${err.code}, message is ${err.message}.`);
    })
  }

  unRegisterScreenCaptureCallback(): void {
    this.screenCapture?.off('stateChange');
    this.screenCapture?.off('error');
  }

  async startRecording(context: Context): Promise<void> {
    this.createAVScreenCapture();
    if (!this.screenCapture) {
      return;
    }
    this.setConfig(context);
    await this.screenCapture?.init(this.captureConfig);
    this.registerScreenCaptureCallback();
    let windowIDs: number[] = [57, 86];
    await this.screenCapture?.skipPrivacyMode(windowIDs);
    await this.screenCapture?.startRecording();
  }

  async stopRecording(): Promise<void> {
    if (!this.screenCapture) {
      this.closeFile();
      return;
    }
    await this.screenCapture?.stopRecording();
    this.unRegisterScreenCaptureCallback();
    // Call release() to release the instance.
    await this.screenCapture?.release();

    // Finally, close the created recording file.
    this.closeFile();
  }
}
```