# Camera Preview (ArkTS)

Preview is the image you see after you start the camera application but before you take photos or record videos.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.
     
   ```ts
   import camera from '@ohos.multimedia.camera';
   import { BusinessError } from '@ohos.base';
   ```

2. Create a surface.
     
    The **\<XComponent>**, the capabilities of which are provided by the UI, offers the surface for preview streams. For details, see [XComponent](../reference/arkui-ts/ts-basic-components-xcomponent.md).

    **NOTE**: The preview stream and video output stream must have the same aspect ratio of the resolution. For example, the aspect ratio in the code snippet below is 1920:1080 (which is equal to 16:9), then the aspect ratio of the resolution of the preview stream must also be 16:9. This means that the resolution can be 640:360, 960:540, 1920:1080, or the like.

   ```ets
   // xxx.ets
   // Create an XComponentController object.
   @Component
   struct XComponentPage {
     // Create an XComponentController object.
     mXComponentController: XComponentController = new XComponentController;
     surfaceId: string = '';

     build() {
       Flex() {
         // Create an XComponent object.
         XComponent({
           id: '',
           type: 'surface',
           libraryname: '',
           controller: this.mXComponentController
         })
           .onLoad(() => {
             // Set the surface width and height (1920 x 1080). For details about how to set the preview size, see the preview resolutions supported by the current device, which are obtained from previewProfilesArray.
             // The preview stream and video output stream must have the same aspect ratio of the resolution.
             this.mXComponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080});
             // Obtain the surface ID.
             this.surfaceId = this.mXComponentController.getXComponentSurfaceId();
           })
           .width('1920px')
           .height('1080px')
       }
     }
   }
   ```

3. Call **previewProfiles()** in the **CameraOutputCapability** class to obtain the preview output capabilities, in the format of an **previewProfilesArray** array, supported by the current device. Then call **createPreviewOutput()** to create a **PreviewOutput** object, with the first parameter set to the first item in the **previewProfilesArray** array and the second parameter set to the surface ID obtained in step 2.
     
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

4. Call **start()** to start outputting the preview stream. If the call fails, an error code is returned. For details, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
     
   ```ts
   function startPreviewOutput(previewOutput: camera.PreviewOutput): void {
     previewOutput.start().then(() => {
       console.info('Callback returned with previewOutput started.');
     }).catch((err: BusinessError) => {
       console.info('Failed to previewOutput start '+ err.code);
     });
   }
   ```


## Status Listening

During camera application development, you can listen for the preview output stream status, including preview stream start, preview stream end, and preview stream output errors.

- Register the **'frameStart'** event to listen for preview start events. This event can be registered when a **PreviewOutput** object is created and is triggered when the bottom layer starts exposure for the first time. The preview stream starts as long as a result is returned.
    
  ```ts
  function onPreviewOutputFrameStart(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameStart', () => {
      console.info('Preview frame started');
    });
  }
  ```

- Register the **'frameEnd'** event to listen for preview end events. This event can be registered when a **PreviewOutput** object is created and is triggered when the last frame of preview ends. The preview stream ends as long as a result is returned.
    
  ```ts
  function onPreviewOutputFrameEnd(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('frameEnd', () => {
      console.info('Preview frame ended');
    });
  }
  ```

- Register the **'error'** event to listen for preview output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [Camera Error Codes](../reference/apis/js-apis-camera.md#cameraerrorcode).
    
  ```ts
  function onPreviewOutputError(previewOutput: camera.PreviewOutput): void {
    previewOutput.on('error', (previewOutputError: BusinessError) => {
      console.info(`Preview output error code: ${previewOutputError.code}`);
    });
  }
  ```
