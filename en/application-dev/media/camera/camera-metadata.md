# Metadata (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=425e79ed59a841b19860caacc0b050f68405d43e translatedAt=2026-08-10T09:13:58.387Z pushedAt=2026-08-10T11:41:29.475Z -->

Before developing a camera application, you must [request required permissions](camera-preparation.md).

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, such as the coordinates of a viewfinder frame for identifying a portrait in a photo or video.

Metadata uses a tag (key) to find the corresponding data during parameter transfers and configurations, reducing memory copy operations.

## When to Use

Detect faces in images and return high-precision face bounding box coordinates. Applications can integrate post-processing algorithms based on face detection results, making them suitable for a variety of scenarios.

## How to Develop

For detailed API descriptions, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

1. Import the modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Obtain the metadata types supported by the current device from **supportedMetadataObjectTypes** in [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability), and then use [createMetadataOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createmetadataoutput) to create a metadata output stream.

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

3. Call the [Session.start](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#start11) method to start metadata data output, and then obtain data through the **metadataObjectsAvailable** event callback. If the API call fails, a corresponding error code is returned. For the error code type, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

   For details about how to obtain preview output, see [Camera Preview (ArkTS)](camera-preview.md).

   ```ts
   async function startMetadataOutput(previewOutput: camera.PreviewOutput, metadataOutput: camera.MetadataOutput, cameraManager: camera.CameraManager): Promise<void> {
     let cameraArray: Array<camera.CameraDevice> = [];
     try {
       cameraArray = cameraManager.getSupportedCameras();
       if (cameraArray.length == 0) {
         console.error('no camera.');
         return;
       }
       // In this sample code, the first camera is selected. You need to select a camera as required.
       const cameraDevice: camera.CameraDevice = cameraArray[0];
       // Obtain the supported modes.
       let sceneModes: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraDevice);
       let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
       if (!isSupportPhotoMode) {
         console.error('photo mode not support');
         return;
       }
       let cameraInput: camera.CameraInput | undefined = undefined;
       cameraInput = cameraManager.createCameraInput(cameraDevice);
       if (cameraInput === undefined) {
         console.error('cameraInput is undefined');
         return;
       }
       // Open the camera.
       await cameraInput.open();
       let session = cameraManager.createSession(camera.SceneMode.NORMAL_PHOTO);
       if (!session) {
         console.error('session is null');
         return;
       }
       let photoSession: camera.PhotoSession = session as camera.PhotoSession;
       photoSession.beginConfig();
       photoSession.addInput(cameraInput);
       photoSession.addOutput(previewOutput);
       photoSession.addOutput(metadataOutput);
       await photoSession.commitConfig();
       await photoSession.start();
     } catch (error) {
       console.error('startMetadataOutput call failed');
     }
   }
   ```

4. Call the [Session.stop](../../reference/apis-camera-kit/arkts-apis-camera-Session.md#stop11) method to stop metadata data output. If the API call fails, a corresponding error code is returned. For the error code type, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

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
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the top-left corner of the rectangle as well as the width and height of the rectangle.

- Register a callback to obtain error results from the metadata stream. The callback returns the error code when the metadata output API is used incorrectly. For the error code type, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).

  ```ts
  function onMetadataError(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('error', (metadataOutputError: BusinessError) => {
      console.error(`Metadata output error code: ${metadataOutputError.code}`);
    });
  }
  ```