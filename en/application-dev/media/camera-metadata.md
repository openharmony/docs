# Camera Metadata (ArkTS)

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, such as the coordinates of a viewfinder frame for identifying a portrait in a photo or video.

Metadata uses a tag (key) to find the corresponding data during parameter transfers and configurations, reducing memory copy operations.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the modules.
   ```ts
   import camera from '@ohos.multimedia.camera';
   import { BusinessError } from '@ohos.base';
   ```

2. Obtain the metadata types supported by the current device from **supportedMetadataObjectTypes** in **CameraOutputCapability**, and then use **createMetadataOutput()** to create a metadata output stream.
     
   ```ts
   function getMetadataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.MetadataOutput | undefined {
     let metadataObjectTypes: Array<camera.MetadataObjectType> = cameraOutputCapability.supportedMetadataObjectTypes;
     let metadataOutput: camera.MetadataOutput | undefined = undefined;
     try {
       metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
     } catch (error) {
       let err = error as BusinessError;
       console.info('Failed to createMetadataOutput, error code: '+ err.code);
     }
     return metadataOutput;
   }
   ```

3. Call **start()** to start outputting metadata. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   function startMetadataOutput(metadataOutput: camera.MetadataOutput): void {
     metadataOutput.start().then(() => {
       console.info('Callback returned with metadataOutput started.');
     }).catch((err: BusinessError) => {
       console.info('Failed to metadataOutput start, error code: '+ err.code);
     });
   }
   ```

4. Call **stop()** to stop outputting metadata. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   function stopMetadataOutput(metadataOutput: camera.MetadataOutput): void {
     metadataOutput.stop().then(() => {
       console.info('Callback returned with metadataOutput stopped.');
     }).catch((err: BusinessError) => {
       console.info('Failed to metadataOutput stop '+ err.code);
     });
   }
   ```

## Status Listening

During camera application development, you can listen for the status of metadata objects and output stream.

- Register the **'metadataObjectsAvailable'** event to listen for metadata objects that are available. When a valid metadata object is detected, the callback function returns the metadata. This event can be registered when a **MetadataOutput** object is created.
    
  ```ts
  function onMetadataObjectsAvailable(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('metadataObjectsAvailable', (err: BusinessError, metadataObjectArr: Array<camera.MetadataObject>) => {
      console.info(`metadata output metadataObjectsAvailable`);
    });
  }
  ```

  > **NOTE**
  >
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the upper left corner of the rectangle as well as the width and height of the rectangle.

- Register the **'error'** event to listen for metadata stream errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  function onMetadataError(metadataOutput: camera.MetadataOutput): void {
    metadataOutput.on('error', (metadataOutputError: BusinessError) => {
      console.info(`Metadata output error code: ${metadataOutputError.code}`);
    });
  }
  ```
