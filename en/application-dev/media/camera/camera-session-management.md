# Camera Session Management (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Before using the camera application for preview, photo capture, video recording, and metadata management, you must create a camera session.

You can implement the following functions in the session:

- Configure the camera input and output streams. This is mandatory for photo capture.
  
  Configuring an input stream is to add a device input, which means that the user selects a camera for photo capture. Configuring an output stream is to select a data output mode. For example, to implement photo capture, you must configure both the preview stream and photo stream as the output stream. The data of the preview stream is displayed on the **XComponent**, and that of the photo stream is saved to the Gallery application through the **ImageReceiver** API.

- Perform more operations on the camera hardware. For example, add the flash and adjust the focal length. For details about the supported configurations and APIs, see [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md).

- Control session switching. The application can switch the camera mode by removing and adding output streams. For example, to switch from photo capture to video recording, the application must remove the photo output stream and add the video output stream.

After the session configuration is complete, the application must commit the configuration and start the session before using the camera functionalities.

## How to Develop
1. Import the modules.
     
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Call [createSession](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createsession11) in the **CameraManager** class to create a session.
     
   ```ts
   function getSession(cameraManager: camera.CameraManager): camera.Session | undefined {
     let session: camera.Session | undefined = undefined;
     try {
       session = cameraManager.createSession(camera.SceneMode.NORMAL_VIDEO) as camera.VideoSession;
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to create the session instance. error: ${err}`);
     }
     return session;
   }
   ```

3. Call [beginConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#beginconfig11) in the **VideoSession** class to configure the session.
     
   ```ts
   function beginConfig(videoSession: camera.VideoSession): void {
     try {
       videoSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${err}`);
     }
   }
   ```

4. Configure the session. You can call [addInput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addinput11) and [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) in the **VideoSession** class to add the input and output streams to the session, respectively. The code snippet below uses adding the preview stream **previewOutput** and photo stream **photoOutput** as an example to implement the photo capture and preview mode.

    After the configuration, call [commitConfig](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#commitconfig11) and [start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11) in the **VideoSession** class in sequence to commit the configuration and start the session.

     > **NOTE**
     >
     > Before calling [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) to add a camera output stream, you can call [canAddOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#canaddoutput11) to check whether the camera output stream can be added to the session.
     
   ```ts
   async function startSession(videoSession: camera.VideoSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       videoSession.addInput(cameraInput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to addInput. error: ${err}`);
     }
     try {
       videoSession.canAddOutput(previewOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to canAdd previewOutput. error: ${err}`);
     }
     try {
       videoSession.addOutput(previewOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add previewOutput. error: ${err}`);
     }
     try {
       videoSession.canAddOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to canAdd photoOutput error: ${err}`);
     }
     try {
       videoSession.addOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add photoOutput. error: ${err}`);
     }
     try {
       await videoSession.commitConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to commitConfig. error: ${err}`);
      return;
     }
   
     try {
       await videoSession.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to start. error: ${err}`);
     }
   }
   ```

5. Control the session. You can call [stop](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#stop11) in the **VideoSession** class to stop the current session, and call [removeOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#removeoutput11) and [addOutput](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#addoutput11) in this class to switch to another session. The code snippet below uses removing the photo stream **photoOutput** and adding the video stream **videoOutput** as an example to complete the switching from photo capture to recording.

   ```ts
   async function switchOutput(videoSession: camera.VideoSession, videoOutput: camera.VideoOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       await videoSession.stop();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to stop. error: ${err}`);
     }
   
     try {
       videoSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${err}`);
     }
     // Remove the photo output stream from the session.
     try {
       videoSession.removeOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to remove photoOutput. error: ${err}`);
     }
     try {
       videoSession.canAddOutput(videoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to canAdd videoOutput error: ${err}`);
     }
     // Add the video output stream to the session.
     try {
       videoSession.addOutput(videoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add videoOutput. error: ${err}`);
     }
     try {
       await videoSession.commitConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to commitConfig. error: ${err}`);
     }
   
     try {
       await videoSession.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to start. error: ${err}`);
     }
   }
   ```
