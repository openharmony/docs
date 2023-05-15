# Camera Session Management

Before using the camera application for preview, photographing, video recording, and metadata, you must create a camera session.

You can implement the following functions in the session:

- Configure the camera input and output streams. This is mandatory for photographing.
  Configuring an input stream is to add a device input, which means that the user selects a camera for photographing. Configuring an output stream is to select a data output mode. For example, to implement photographing, you must configure both the preview stream and photo stream as the output stream. The data of the preview stream is displayed on the XComponent, and that of the photo stream is saved to the Gallery application through the **ImageReceiver** API.

- Perform more operations on the camera hardware. For example, add the flash and adjust the focal length. For details about the supported configurations and APIs, see [Camera API Reference](../reference/apis/js-apis-camera.md).

- Control session switching. The application can switch the camera mode by removing and adding output streams. For example, to switch from photographing to video recording, the application must remove the photo output stream and add the video output stream.

After the session configuration is complete, the application must commit the configuration and start the session before using the camera functionalities.

## How to Develop

1. Call **createCaptureSession()** in the **CameraManager** class to create a session.
   
   ```ts
   let captureSession;
   try {
       captureSession = cameraManager.createCaptureSession();
   } catch (error) {
       console.error('Failed to create the CaptureSession instance. errorCode = ' + error.code);
   }
   ```

2. Call **beginConfig()** in the **CaptureSession** class to start configuration for the session.
   
   ```ts
   try {
       captureSession.beginConfig();
   } catch (error) {
       console.error('Failed to beginConfig. errorCode = ' + error.code);
   }
   ```

3. Configure the session. You can call **addInput()** and **addOutput()** in the **CaptureSession** class  to add the input and output streams to the session, respectively. The code snippet below uses adding the preview stream **previewOutput** and photo stream **photoOutput** as an example to implement the photographing and preview mode.

     After the configuration, call **commitConfig()** and **start()** in the **CaptureSession** class in sequence to commit the configuration and start the session.
     
   ```ts
   try {
       captureSession.addInput(cameraInput);
   } catch (error) {
       console.error('Failed to addInput. errorCode = ' + error.code);
   }
   try {
       captureSession.addOutput(previewOutput);
   } catch (error) {
       console.error('Failed to addOutput(previewOutput). errorCode = ' + error.code);
   }
   try {
       captureSession.addOutput(photoOutput);
   } catch (error) {
       console.error('Failed to addOutput(photoOutput). errorCode = ' + error.code);
   }
   await captureSession.commitConfig() ;
   await captureSession.start().then(() => {
       console.info('Promise returned to indicate the session start success.');
   })
   ```

4. Control the session. You can call **stop()** in the **CaptureSession** class to stop the session, and call **removeOutput()** and **addOutput()** in this class to switch to another session. The code snippet below uses removing the photo stream **photoOutput** and adding the video stream **videoOutput** as an example to complete the switching from photographing to recording.
   
   ```ts
   await captureSession.stop();
   try {
       captureSession.beginConfig();
   } catch (error) {
       console.error('Failed to beginConfig. errorCode = ' + error.code);
   } 
   // Remove the photo output stream from the session.
   try {
       captureSession.removeOutput(photoOutput);
   } catch (error) {
       console.error('Failed to removeOutput(photoOutput). errorCode = ' + error.code);
   } 
   // Add the video output stream to the session.
   try {
       captureSession.addOutput(videoOutput);
   } catch (error) {
       console.error('Failed to addOutput(videoOutput). errorCode = ' + error.code);
   }
   ```
