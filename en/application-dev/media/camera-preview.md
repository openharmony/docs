# Camera Preview

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Create a surface.
     
     The XComponent, the capabilities of which are provided by the UI, offers the surface for preview streams. For details, see [XComponent](../reference/arkui-ts/ts-basic-components-xcomponent.md).
     
   ```ts
   // Create an XComponentController object.
   mXComponentController: XComponentController = new XComponentController;                   
   build() {
       Flex() {
           // Create an XComponent.
           XComponent({                                                                     
               id: '',
               type: 'surface',
               libraryname: '',
               controller: this.mXComponentController
           })
           .onLoad(() => {                                                                  
               // Set the surface width and height (1920 x 1080). For details about how to set the preview size, see the preview resolutions supported by the current device, which are obtained from previewProfilesArray.
               this.mXComponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080});
               // Obtain the surface ID.
               globalThis.surfaceId = this.mXComponentController.getXComponentSurfaceId();
           })
           .width('1920px')                                                                 
           .height('1080px')                                                                
       }
   }
   ```

2. Call **previewProfiles()** in the **CameraOutputCapability** class to obtain the preview capabilities, in the format of an **previewProfilesArray** array, supported by the current device. Then call **createPreviewOutput()** to create a preview output stream, with the first parameter set to the first item in the **previewProfilesArray** array and the second parameter set to the surface ID obtained in step 1.
     
   ```ts
   let previewProfilesArray = cameraOutputCapability.previewProfiles;
   let previewOutput;
   try {
       previewOutput = cameraManager.createPreviewOutput(previewProfilesArray[0], surfaceId);
   } 
   catch (error) {
       console.error("Failed to create the PreviewOutput instance." + error);
   }
   ```

3. Call **start()** to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   previewOutput.start().then(() => {
       console.info('Callback returned with previewOutput started.');
   }).catch((err) => {
       console.info('Failed to previewOutput start '+ err.code);
   });
   ```


## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the 'frameStart' event to listen for preview start events This event can be registered when a **PreviewOutput** object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream is started as long as a result is returned.
    
  ```ts
  previewOutput.on('frameStart', () => {
      console.info('Preview frame started');
  })
  ```

- Register the 'frameEnd' event to listen for preview end events. This event can be registered when a **PreviewOutput** object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```ts
  previewOutput.on('frameEnd', () => {
      console.info('Preview frame ended');
  })
  ```

- Register the 'error' event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  previewOutput.on('error', (previewOutputError) => {
      console.info(`Preview output error code: ${previewOutputError.code}`);
  })
  ```
