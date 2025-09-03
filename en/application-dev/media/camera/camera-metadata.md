# Camera Metadata (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Before developing a camera application, request permissions by following the instructions provided in [Camera Development Preparations](camera-preparation.md).

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, such as the coordinates of a viewfinder frame for identifying a portrait in a photo or video.

Metadata uses a tag (key) to find the corresponding data during parameter transfers and configurations, reducing memory copy operations.

## How to Develop

Read [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

1. Import the modules.
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the metadata types supported by the current device from **supportedMetadataObjectTypes** in the [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) class, and then use [createMetadataOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createmetadataoutput) to create a metadata output stream.

   ```ts
   function getMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.MetadataOutput | undefined {
     let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
     let metadataOutput: camera.MetadataOutput | undefined = undefined;
     try {
       metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createMetadataOutput, error code: ${err.code}`);
     }
     return metadataOutput;
   }
   ```

3. Call [Session.start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11) to start outputting metadata, and obtain the data through subscription to the **'metadataObjectsAvailable'** event. If the call fails, an error code is returned. For details, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

   For details about how to obtain preview output, see [Camera Preview (ArkTS)](camera-preview.md).

   ```ts
   async function startMetadataOutput(previewOutput: camera.PreviewOutput, metadataOutput: camera.MetadataOutput, cameraManager: camera.CameraManager): Promise<void> {
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
     // Open the camera.
     await cameraInput.open();
     let session: camera.PhotoSession = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
     session.beginConfig();
     session.addInput(cameraInput);
     session.addOutput(previewOutput);
     session.addOutput(metadataOutput);
     await session.commitConfig();
     await session.start();
   }
   ```

4. Call [Session.stop](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#stop11) to stop outputting metadata. If the call fails, an error code is returned. For details, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
     
   ```ts
   function stopMetadataOutput(session: camera.Session): void {
     session.stop().then(() => {
       console.info('Callback returned with session stopped.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to session stop, error code: ${err.code}`);
     });
   }
   ```

## Status Listening

During camera application development, you can listen for the status of metadata objects and output stream.

- Register the **'metadataObjectsAvailable'** event to listen for metadata objects that are available. When a valid metadata object is detected, the callback function returns the metadata. This event can be registered when a MetadataOutput object is created.
    
  ```ts
  function onMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('metadata output metadataObjectsAvailable');
    });
  }
  ```

  > **NOTE**
  >
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the upper left corner of the rectangle as well as the width and height of the rectangle.

- Register the **'error'** event to listen for metadata stream errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
    
  ```ts
  function onMetadataError(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('error', (metadataOutputError: BusinessError) => {
      console.error(`Metadata output error code: ${metadataOutputError.code}`);
    });
  }
  ```
