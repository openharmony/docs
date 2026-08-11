# Camera Session Management (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=03da8d98875c99278437bdd28f12d4fdb3efd8f7 translatedAt=2026-08-10T09:15:56.876Z pushedAt=2026-08-10T12:20:56.305Z -->

Before using the camera application for preview, photo capture, video recording, and metadata management, you must create a camera session.

You can implement the following functions in the session:

- Configure the camera input and output streams. This is mandatory for photo capture.

Configuring an input stream is to add a device input, which means that the user selects a camera for photo capture. Configuring an output stream is to select a data output mode. For example, to implement photo capture, the output streams must be configured as a preview stream and a photo stream. The preview stream data is displayed on the [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) component, and the photo stream data is saved to the album through the [ImageReceiver](../../reference/apis-image-kit/arkts-apis-image-ImageReceiver.md) API.

- Add configurations such as flash and focal length adjustment. For details about the supported configurations and APIs, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

- Control session switching. The application can switch the camera mode by removing and adding output streams. For example, to switch from photo capture to video recording, the application must remove the photo output stream and add the video output stream.

After the session configuration is complete, the application must commit the configuration and start the session before using the camera functionalities.

## How to Develop

1. Import the modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Call the [createSession](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createsession11) method in [cameraManager](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md) to create a session.

   ```ts
   // videoSession is used as an example.
   function getSession(cameraManager: camera.CameraManager): camera.VideoSession | undefined {
     let videoSession: camera.VideoSession | undefined = undefined;
     try {
       videoSession = cameraManager.createSession(camera.SceneMode.NORMAL_VIDEO) as camera.VideoSession;
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to create the session instance. error: ${err.code}`);
     }
     return videoSession;
   }
   ```

3. Call the [beginConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#beginconfig11) method in [VideoSession](../../reference/apis-camera-kit/arkts-apis-camera-VideoSession.md) to configure the session.

   ```ts
   function beginConfig(videoSession: camera.VideoSession): void {
     try {
       videoSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${err.code}`);
     }
   }
   ```

4. Configure the session. You can call [addInput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addinput11) and [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) in **VideoSession** to add the input and output streams to the session, respectively. The code snippet below uses adding the preview stream **previewOutput** and photo stream **photoOutput** as an example to implement the photo capture and preview mode.

Call the [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) and [start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11) methods in **VideoSession** to commit the configuration and start the session.

> **NOTE**
>
> Before calling [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) to add a camera output stream, you can call [canAddOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#canaddoutput11) to check whether the current camera output stream can be added to the session.
> For details about creating a camera input stream (cameraInput), see [Device Input Management](camera-device-input.md). For details about creating a camera preview output stream (previewOutput) and a photo output stream (photoOutput), see [Preview](camera-preview.md) and [Photo Capture](camera-shooting.md) respectively.

   ```ts
   async function startSession(videoSession: camera.VideoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       videoSession.addInput(cameraInput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to addInput. error: ${err.code}`);
     }
     let canAddPreviewOutput : boolean = false;
     try {
       canAddPreviewOutput = videoSession.canAddOutput(previewOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add previewOutput. error: ${err.code}`);
     } 
     if (!canAddPreviewOutput) {
       console.error(`Failed to add preview output.`);
       return;
     }
     try {
       videoSession.addOutput(previewOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add previewOutput. error: ${err.code}`);
     }
     let canAddPhotoOutput : boolean = false
     try {
       canAddPhotoOutput = videoSession.canAddOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add photoOutput error: ${err.code}`);
     }
     if (!canAddPhotoOutput) {
       console.error(`Failed to add photo output.`);
       return;
     }
     try {
       videoSession.addOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add photoOutput. error: ${err.code}`);
     }
     try {
       await videoSession.commitConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to commitConfig. error: ${err.code}`);
      return;
     }
   
     try {
       await videoSession.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to start. error: ${err.code}`);
     }
   }
   ```

5. Control the session. You can call [stop](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#stop11) in **VideoSession** to stop the current session, and call [removeOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#removeoutput11) and [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) to switch to another session. The code snippet below uses removing the photo stream **photoOutput** and adding the video stream **videoOutput** as an example to complete the switching from photo capture to recording.

   ```ts
   async function switchOutput(videoSession: camera.VideoSession, videoOutput: camera.VideoOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       await videoSession.stop();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to stop. error: ${err.code}`);
     }
   
     try {
       videoSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${err.code}`);
     }
     // Remove the photo output stream from the session.
     try {
       videoSession.removeOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to remove photoOutput. error: ${err.code}`);
     }
     try {
       videoSession.canAddOutput(videoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add videoOutput error: ${err.code}`);
     }
     // Add the video output stream to the session.
     try {
       videoSession.addOutput(videoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add videoOutput. error: ${err.code}`);
     }
     try {
       await videoSession.commitConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to commitConfig. error: ${err.code}`);
     }
   
     try {
       await videoSession.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to start. error: ${err.code}`);
     }
   }
   ```