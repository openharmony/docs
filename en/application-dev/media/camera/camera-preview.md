# Preview (ArkTS)

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.
   
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Create a surface.

    The **XComponent**, the capabilities of which are provided by the UI, offers the surface for preview streams. For details about how to obtain the surface ID, see [getXcomponentSurfaceId](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#getxcomponentsurfaceid9). For details about the component, see [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md).

    > **NOTE**
    > The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio of the surface of the **XComponent** is 1920:1080 (which is equal to 16:9), then the aspect ratio of the resolution of the preview stream must also be 16:9. This means that the resolution can be 640:360, 960:540, 1920:1080, or the like.

3. Use **previewProfiles** in the [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability) class to obtain the preview output capabilities, in the format of an **previewProfilesArray** array, supported by the current device. Then call [createPreviewOutput](../../reference/apis-camera-kit/js-apis-camera.md#createpreviewoutput) to create a **PreviewOutput** object, with the first parameter set to the first item in the **previewProfilesArray** array and the second parameter set to the surface ID obtained in step 2.
   
   ```ts
   function getPreviewOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability, surfaceId: string): camera.PreviewOutput | undefined {
     let previewProfilesArray: Array<camera.Profile> = cameraOutputCapability.previewProfiles;
     let previewOutput: camera.PreviewOutput | undefined = undefined;
     try {
       previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
     } catch (error) {
       let err = error as BusinessError;
       console.error("Failed to create the PreviewOutput instance. error code: " + err.code);
     }
     return previewOutput;
   }
   ```

4. Call [Session.start](../../reference/apis-camera-kit/js-apis-camera.md#start11) to start outputting the preview stream. If the call fails, an error code is returned. For details, see [CameraErrorCode](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode).
   
   ```ts
   async function startPreviewOutput(cameraManager: camera.CameraManager, previewOutput: camera.PreviewOutput): Promise<void> {
     let cameraArray: Array<camera.CameraDevice> = [];
     cameraArray = cameraManager.getSupportedCameras();
     if (cameraArray.length == 0) {
       console.error('no camera.');
       return;
     }
     // Obtain the supported modes.
     let sceneModes: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraArray[0]);
     let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
     if (!isSupportPhotoMode) {
       console.error('photo mode not support');
       return;
     }
     let cameraInput: camera.CameraInput | undefined = undefined;
     cameraInput = cameraManager.createCameraInput(cameraArray[0]);
     if (cameraInput === undefined) {
       console.error('cameraInput is undefined');
       return;
     }
     // Open a camera.
     await cameraInput.open();
     let session: camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
     session.beginConfig();
     session.addInput(cameraInput);
     session.addOutput(previewOutput);
     await session.commitConfig();
     await session.start();
   }
   ```


## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a **PreviewOutput** object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.
  
  ```ts
  function onPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameStart', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame started');
    });
  }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a **PreviewOutput** object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
  
  ```ts
  function onPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameEnd', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Preview frame ended');
    });
  }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../../reference/apis-camera-kit/js-apis-camera.md#cameraerrorcode).
  
  ```ts
  function onPreviewOutputError(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('error', (previewOutputError: BusinessError) => {
      console.error(`Preview output error code: ${previewOutputError.code}`);
    });
  }
  ```

 <!--no_check--> 