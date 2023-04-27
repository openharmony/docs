# Camera Metadata

Metadata is the description and context of image information returned by the camera application. It provides detailed data for the image information, for example, coordinates of a viewfinder frame for identifying a portrait in a photo or a video.

Metadata uses a tag (key) to find the corresponding data during the transfer of parameters and configurations, reducing memory copy operations.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Obtain the metadata types supported by the current device from **supportedMetadataObjectTypes** in **CameraOutputCapability**, and then use **createMetadataOutput()** to create a metadata output stream.
     
   ```ts
   let metadataObjectTypes = cameraOutputCapability.supportedMetadataObjectTypes;
   let metadataOutput;
   try {
       metadataOutput = cameraManager.createMetadataOutput(metadataObjectTypes);
   } catch (error) {
       // If the operation fails, error.code is returned and processed.
       console.info(error.code);
   }
   ```

2. Call **start()** to start outputting metadata. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   metadataOutput.start().then(() => {
       console.info('Callback returned with metadataOutput started.');
   }).catch((err) => {
       console.info('Failed to metadataOutput start '+ err.code);
   });
   ```

3. Call **stop()** to stop outputting metadata. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   metadataOutput.stop().then(() => {
       console.info('Callback returned with metadataOutput stopped.');
   }).catch((err) => {
       console.info('Failed to metadataOutput stop '+ err.code);
   });
   ```

## Status Listening

During camera application development, you can listen for the status of metadata objects and output stream.

- Register the 'metadataObjectsAvailable' event to listen for metadata objects that are available. When a valid metadata object is detected, the callback function returns the metadata. This event can be registered when a **MetadataOutput** object is created.
    
  ```ts
  metadataOutput.on('metadataObjectsAvailable', (metadataObjectArr) => {
      console.info(`metadata output metadataObjectsAvailable`);
  })
  ```

  > **NOTE**
  >
  > Currently, only **FACE_DETECTION** is available for the metadata type. The metadata object is the rectangle of the recognized face, including the x-axis coordinate and y-axis coordinate of the upper left corner of the rectangle as well as the width and height of the rectangle.

- Register the 'error' event to listen for metadata stream errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  metadataOutput.on('error', (metadataOutputError) => {
      console.info(`Metadata output error code: ${metadataOutputError.code}`);
  })
  ```
