# Using AVScreenCaptureRecorder to Record Screens and Save Them to Files (ArkTS)

Screen capture is mainly used to record the main screen.

You can call the ArkTS APIs of the [AVScreenCaptureRecorder](media-kit-intro.md#avscreencapture) module to record the screen and collect audio and video source data output by the device and microphone. You can call the APIs to obtain audio and video files and transfer the files to other modules for playback or processing. In this way, screen content can be shared in the form of files.

The AVScreenCaptureRecorder, Window, and Graphics modules together implement the entire video capture process.

The full screen capture process involves creating an AVScreenCaptureRecorder instance, configuring audio and video capture parameters, starting and stopping screen capture, and releasing resources.

If you are in a call when screen capture starts or a call is coming during screen capture, screen capture automatically stops, and the **SCREENCAPTURE_STATE_STOPPED_BY_CALL** status is reported.

This topic describes how to use the AVScreenCaptureRecorder APIs to carry out one-time screen capture. For details about the API reference, see [AVScreenCaptureRecorder](../../reference/apis-media-kit/arkts-apis-media-AVScreenCaptureRecorder.md).

If microphone data collection is configured, configure the permission ohos.permission.MICROPHONE and request a continuous task. For details, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md) and [Continuous Task](../../task-management/continuous-task.md).

## Applying for Permission

Before your development, configure the following permissions for your application.

- To use the microphone, request the ohos.permission.MICROPHONE permission. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).
- To read images or videos, preferentially use the media library [Picker for access](../medialibrary/photoAccessHelper-photoviewpicker.md).
- To save images or videos, preferentially use the [security component for storage](../medialibrary/photoAccessHelper-savebutton.md).

> **NOTE**
>
> To clone, back up, or synchronize images and videos in users' public directory, request the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions for reading and writing audio files. For details, see <!--RP1-->[Requesting Restricted Permissions](../../security/AccessToken/declare-permissions-in-acl.md)<!--RP1End-->.

## How to Develop

After an AVScreenCaptureRecorder instance is created, different APIs can be called to switch the AVScreenCaptureRecorder to different states and trigger the required behavior. If an API is called when the AVScreenCaptureRecorder is not in the given state, the system may throw an exception or generate other undefined behavior. Therefore, you are advised to check the AVScreenCaptureRecorder state before triggering state transition.

1. Add the header files.

    ```javascript
    import media from '@ohos.multimedia.media';
    import fs from '@ohos.file.fs';
    ```

2. Create the member variable **screenCapture** of the **AVScreenCaptureRecorder** type.

    ```javascript
    // Declare a member variable of the AVScreenCaptureRecorder type.
    private screenCapture?: media.AVScreenCaptureRecorder;
    // Create an AVScreenCaptureRecorder instance and assign a value to the member variable screenCapture.
    this.screenCapture = await media.createAVScreenCaptureRecorder();
    ```

3. Set callback functions for the member variable **screenCapture** to listen for state changes and errors.

    ```javascript
    this.screenCapture.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
    	switch (infoType) {
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
              	console.info("Callback invoked when screen capture starts");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
                this.screenCapture?.release();
                this.screenCapture = undefined;
              	console.info("Screen capture is not allowed.");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
                this.screenCapture?.release();
                this.screenCapture = undefined;
              	console.info("Touch the button in the screen capture capsule to stop screen capture. Underlying capture will stop.");
              	break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
                console.info("Screen capture stops due to other interruptions. Underlying capture will stop.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
                console.info("Screen capture stops due to incoming calls. Underlying capture will stop.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
                console.info("The screen capture microphone is unavailable.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
                console.info("The screen capture microphone is muted by the user.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
                console.info("The screen capture microphone is unmuted by the user.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
                // Currently, you can directly register a listener from the system to enter the privacy scenario.
                console.info("Screen capture enters the privacy scenario.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
                console.info("Screen capture exits the privacy scenario.");
                break;
            case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
                console.info("Underlying capture will stop after the user account is changed.");
                break;
            default:
              	break;
        }
    })
    this.screenCapture.on('error', (err) => {
        console.error("Handle exceptions.");
    })
    ```

4. Set screen capture parameters.

    ​After creating the screenCapture instance, you can set the parameters required for screen capture.

    ​Parameters **videoBitrate**, **audioSampleRate**, **audioChannelCount**, **audioBitrate**, **preset**, and **displayId** are optional, with default values provided in the code snippet below. The audio streams of the microphone and system sound share a set of audio parameters: **audioSampleRate**, **audioChannelCount**, and **audioBitrate**.

    You can create, read, and write a file descriptor by referring to the sample code in [Accessing Application Files](../../file-management/app-file-access.md) to obtain the value of the **fd** parameter. The **getFileFd()** API provided in the example below is for reference only.

    If **displayId** is set to the extended display ID of a 2-in-1 device, a dialog box for screen capture selection can be opened. Users can select the screen to capture in the dialog box, and the recorded content will match the user's choices.

    ```javascript
    public getFileFd(): number {
      let filesDir = '/data/storage/el2/base/haps';
      let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
      return file.fd;
    }

    captureConfig: media.AVScreenCaptureRecordConfig = {
        // Set the width and height as required.
        frameWidth: 768,
        frameHeight: 1280,
        // Create, read, and write a file descriptor by referring to the sample code in Accessing Application Files.
        fd: this.getFileFd(),
        // Optional parameters and their default values
        videoBitrate: 10000000,
        audioSampleRate: 48000,
        audioChannelCount: 2,
        audioBitrate: 96000,
        displayId: 0,
        preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
    };
    ```

5. Call **init()** to initialize the screenCapture instance based on the preset screen capture parameters.

    ```javascript
    await this.screenCapture.init(this.captureConfig);
    ```

6. Set the windows that will be skipped during screen capture, by entering the subwindow IDs and main window IDs. For details, see [Window API Reference](../../reference/apis-arkui/arkts-apis-window-i.md#windowproperties).

    ```javascript
    let windowIDs = [57, 86];
    await screenCapture.skipPrivacyMode(windowIDs);
    ```

7. Call **startRecording()** to start screen capture and listen for state changes using the callback function.

    ```javascript
    await this.screenCapture.startRecording();
    ```

8. Stop screen capture.

    - When the user touches the stop button in the screen capture capsule to stop screen capture, the screenCapture instance triggers the **SCREENCAPTURE_STATE_STOPPED_BY_USER** callback to notify the application that the screen recording has stopped. The application does not need to call the **stopRecording()** API.

    - The application proactively calls **stopRecording()** to stop screen capture.

      ```javascript
      await this.screenCapture.stopRecording();
      ```

9. Call **release()** to release the instance.

    ```javascript
    await this.screenCapture.release();
    ```

## Development Example

Refer to the sample code below to implement captured file storage using **AVScreenCaptureRecorder**.

```javascript
import media from '@ohos.multimedia.media';
import fs from '@ohos.file.fs';

export class AVScreenCaptureDemo {
  private screenCapture?: media.AVScreenCaptureRecorder;
  captureConfig: media.AVScreenCaptureRecordConfig = {
    // Set the width and height as required.
    frameWidth: 768,
    frameHeight: 1280,
    // Create, read, and write a file descriptor by referring to the sample code in Accessing Application Files.
    fd: this.getFileFd(),
    // Optional parameters and their default values
    videoBitrate: 10000000,
    audioSampleRate: 48000,
    audioChannelCount: 2,
    audioBitrate: 96000,
    displayId: 0,
    preset: media.AVScreenCaptureRecordPreset.SCREEN_RECORD_PRESET_H264_AAC_MP4
  };

  public getFileFd(): number {
    let filesDir = '/data/storage/el2/base/haps';
    let file = fs.openSync(filesDir + '/screenCapture.mp4', fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    return file.fd;
  }

  // Call startRecording to start screen capture. To stop screen capture, click the stop button in the screen capture capsule.
  public async startRecording() {
    this.screenCapture = await media.createAVScreenCaptureRecorder();
    if (this.screenCapture != undefined) {
      // success.
    } else {
      // failed.
        return;
    }
    this.screenCapture?.on('stateChange', async (infoType: media.AVScreenCaptureStateCode) => {
      switch (infoType) {
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STARTED:
          console.info("Callback invoked when screen capture starts");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_CANCELED:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info("Screen capture is not allowed.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER:
          this.screenCapture?.release();
          this.screenCapture = undefined;
          console.info("Touch the button in the screen capture capsule to stop screen capture. Underlying capture will stop.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_INTERRUPTED_BY_OTHER:
          console.info("Screen capture stops due to other interruptions. Underlying capture will stop.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_CALL:
          console.info("Screen capture stops due to incoming calls. Underlying capture will stop.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNAVAILABLE:
          console.info("The screen capture microphone is unavailable.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_MUTED_BY_USER:
          console.info("The screen capture microphone is muted by the user.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_MIC_UNMUTED_BY_USER:
          console.info("The screen capture microphone is unmuted by the user.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_ENTER_PRIVATE_SCENE:
          // Currently, you can directly register a listener from the system to enter the privacy scenario.
          console.info("Screen capture enters the privacy scenario.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_EXIT_PRIVATE_SCENE:
          console.info("Screen capture exits the privacy scenario.");
          break;
        case media.AVScreenCaptureStateCode.SCREENCAPTURE_STATE_STOPPED_BY_USER_SWITCHES:
          console.info("Underlying capture will stop after the user account is changed.");
          break;
        default:
          break;
      }
    })
    this.screenCapture?.on('error', (err) => {
      console.error("Handle exceptions.");
    })
    await this.screenCapture?.init(this.captureConfig);

    // Exempt privacy windows.
    let windowIDs = [57, 86];
    await this.screenCapture?.skipPrivacyMode(windowIDs);

    await this.screenCapture?.startRecording();
  }

  // Proactively call stopRecording to stop screen capture.
  public async stopRecording() {
    if (this.screenCapture == undefined) {
      // Error.
      return;
    }
    await this.screenCapture?.stopRecording();

    // Call release() to release the instance.
    await this.screenCapture?.release();

    // Call fs.close (fd); to close the FD of the created screen capture file.
  }
}
```
