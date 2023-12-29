# Camera Session Management (ArkTS)

Before using the camera application for preview, photographing, video recording, and metadata management, you must create a camera session.

You can implement the following functions in the session:

- Configure the camera input and output streams. This is mandatory for photographing.
  Configuring an input stream is to add a device input, which means that the user selects a camera for photographing. Configuring an output stream is to select a data output mode. For example, to implement photographing, you must configure both the preview stream and photo stream as the output stream. The data of the preview stream is displayed on the **\<XComponent>**, and that of the photo stream is saved to the Gallery application through the **ImageReceiver** API.

- Perform more operations on the camera hardware. For example, add the flash and adjust the focal length. For details about the supported configurations and APIs, see [Camera API Reference](../reference/apis/js-apis-camera.md).

- Control session switching. The application can switch the camera mode by removing and adding output streams. For example, to switch from photographing to video recording, the application must remove the photo output stream and add the video output stream.

After the session configuration is complete, the application must commit the configuration and start the session before using the camera functionalities.

## How to Develop
1. Import the modules.
     
   ```ts
   import camera from '@ohos.multimedia.camera';
   import { BusinessError } from '@ohos.base';
   ```

2. Call **createCaptureSession()** in the **CameraManager** class to create a session.
     
   ```ts
   function getCaptureSession(cameraManager: camera.CameraManager): camera.CaptureSession | undefined {
     let captureSession: camera.CaptureSession | undefined = undefined;
     try {
       captureSession = cameraManager.createCaptureSession();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to create the CaptureSession instance. error: ${JSON.stringify(err)}`);
     }
     return captureSession;
   }
   ```

3. Call **beginConfig()** in the **CaptureSession** class to start configuration for the session.
     
   ```ts
   function beginConfig(captureSession: camera.CaptureSession): void {
     try {
       captureSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${JSON.stringify(err)}`);
     }
   }
   ```

4. Configure the session. You can call **addInput()** and **addOutput()** in the **CaptureSession** class  to add the input and output streams to the session, respectively. The code snippet below uses adding the preview stream **previewOutput** and photo stream **photoOutput** as an example to implement the photographing and preview mode.

     After the configuration, call **commitConfig()** and **start()** in the **CaptureSession** class in sequence to commit the configuration and start the session.
     
   ```ts
   async function startSession(captureSession: camera.CaptureSession, cameraInput: camera.CameraInput, previewOutput: camera.PreviewOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       captureSession.addInput(cameraInput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to addInput. error: ${JSON.stringify(err)}`);
     }
     try {
       captureSession.addOutput(previewOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add previewOutput. error: ${JSON.stringify(err)}`);
     }
     try {
       captureSession.addOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add photoOutput. error: ${JSON.stringify(err)}`);
     }
     try {
       await captureSession.commitConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to commitConfig. error: ${JSON.stringify(err)}`);
     }
   
     try {
       await captureSession.start();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to start. error: ${JSON.stringify(err)}`);
     }
   }
   ```

5. Control the session. You can call **stop()** in the **CaptureSession** class to stop the session, and call **removeOutput()** and **addOutput()** in this class to switch to another session. The code snippet below uses removing the photo stream **photoOutput** and adding the video stream **videoOutput** as an example to complete the switching from photographing to recording.
     
   ```ts
   async function switchOutput(captureSession: camera.CaptureSession, videoOutput: camera.VideoOutput, photoOutput: camera.PhotoOutput): Promise<void> {
     try {
       await captureSession.stop();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to stop. error: ${JSON.stringify(err)}`);
     }
   
     try {
       captureSession.beginConfig();
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to beginConfig. error: ${JSON.stringify(err)}`);
     }
     // Remove the photo output stream from the session.
     try {
       captureSession.removeOutput(photoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to remove photoOutput. error: ${JSON.stringify(err)}`);
     }
     // Add the video output stream to the session.
     try {
       captureSession.addOutput(videoOutput);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to add videoOutput. error: ${JSON.stringify(err)}`);
     }
   }
   ```
