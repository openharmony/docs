# Depth Data (for System Applications Only) (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

Depth data reflects the spatial arrangement of image pixels in relation to the camera lens. It facilitates enhanced focus precision, background blurring effects, and the like. Depth data can be reported in the preview, photo capture, and video scenarios of camera applications.

## How to Develop

Read [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.
     
   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Use **depthProfiles** in the [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) class to obtain the depth data capabilities, in the format of an **depthProfilesArray** array, supported by the current device. Call [createDepthDataOutput](../../reference/apis-camera-kit/js-apis-camera-sys.md#createdepthdataoutput13) to create a depth data stream.

   ```ts
   function getDepthDataOutput(cameraManager: camera.CameraManager, cameraOutputCapability: camera.CameraOutputCapability): camera.DepthDataOutput | undefined {
     let depthProfilesArray: Array<camera.DepthProfile> = cameraOutputCapability.depthProfiles;
     if (!depthProfilesArray) {
       console.error("createOutput depthProfilesArray is null");
     }
     let depthDataOutput: camera.DepthDataOutput | undefined = undefined;
     try {
       depthDataOutput = cameraManager.createDepthDataOutput(depthProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to create the DepthDataOutput instance. error: ${err}`);
     }
     return depthDataOutput;
   }
   ```

3. Call [start](../../reference/apis-camera-kit/js-apis-camera-sys.md#start13) in the **depthDataOutput** class to start outputting the depth data stream. If the call fails, an error code is returned. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
     
   ```ts
   async function startDepthDataOutput(depthDataOutput: camera.DepthDataOutput): Promise<void> {
     if (!depthDataOutput) {
       console.error('depthDataOutput Undefined');
       return;
     }
     try {
       await depthDataOutput.start();
     } catch (err) {
       const error = err as BusinessError;
       console.error(`Failed to start depth data output. error: ${err}`);
     }
   }
   ```

## Status Listening

During camera application development, you can listen for depth data and depth data output errors.

- Register the fixed callback function **depthDataAvailable** to obtain the depth data.
    
  ```ts
  function onDepthDataAvailable(depthDataOutput: camera.DepthDataOutput): void {
    depthDataOutput.on('depthDataAvailable', (err: BusinessError) => {
      if (err !== undefined && err.code !== 0) {
        return;
      }
      console.info('Depth data available');
    });
  }
  ```

- Register the **'error'** event to listen for depth data output errors. The callback function returns an error code when an API is incorrectly used. For details about the error code types, see [CameraErrorCode](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraerrorcode).
    
  ```ts
  function onDepthDataOutputError(depthDataOutput: camera.DepthDataOutput): void {
    depthDataOutput.on('error', (depthDataOutputError: BusinessError) => {
      console.error(`Depth data output error code: ${depthDataOutputError.code}`);
    });
  }
  ```
