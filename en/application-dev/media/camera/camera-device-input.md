# Device Input Management (ArkTS)

Before developing a camera application, request permissions by following the instructions provided in [Camera Development Preparations](camera-preparation.md).

A camera application invokes and controls a camera device to perform basic operations such as preview, photo capture, and video recording.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

   > **NOTE**
   >
   > Before any camera device input, you must complete camera management by following the instructions provided in [Camera Device Management](camera-device-management.md).

2. Call [createCameraInput](../../reference/apis-camera-kit/js-apis-camera.md#createcamerainput) in the [cameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameramanager) class to create a camera input stream.

   ```ts
   async function createInput(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): Promise<camera.CameraInput | undefined> {
     // Create a camera input stream.
     let cameraInput: camera.CameraInput | undefined = undefined;
     try {
       cameraInput = cameraManager.createCameraInput(cameraDevice);
     } catch (error) {
       let err = error as BusinessError;
       console.error('Failed to createCameraInput errorCode = ' + err.code);
     }
     if (cameraInput === undefined) {
       return undefined;
     }
     // Listen for camera input errors.
     cameraInput.on('error', cameraDevice, (error: BusinessError) => {
       console.error(`Camera input error code: ${error.code}`);
     });
     // Open the camera.
     await cameraInput.open();
     return cameraInput;
   }
   ```

3. Call [getSupportedSceneModes](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedscenemodes11) to obtain the list of scene modes supported by the current camera device. The list stores all the [SceneModes](../../reference/apis-camera-kit/js-apis-camera.md#scenemode11) supported by the camera device.

    ```ts
    function getSupportedSceneMode(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager): Array<camera.SceneMode> {
      // Obtain the list of scene modes supported by the camera device.
      let sceneModeArray: Array<camera.SceneMode> = cameraManager.getSupportedSceneModes(cameraDevice);
      if (sceneModeArray != undefined && sceneModeArray.length > 0) {
        for (let index = 0; index < sceneModeArray.length; index++) {
          console.info('Camera SceneMode : ' + sceneModeArray[index]);  
      }
        return sceneModeArray;
      } else {
          console.error("cameraManager.getSupportedSceneModes error");
          return [];
      }
    }
    ```

4. Call [getSupportedOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedoutputcapability11) to obtain all output streams supported by the current camera device, such as preview streams, photo streams, and video streams. The supported output streams are listed in the **profile** field in [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability). Different types of output streams must be added based on the value of [SceneMode](../../reference/apis-camera-kit/js-apis-camera.md#scenemode11) specified by the camera device.

   ```ts
   async function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): Promise<camera.CameraOutputCapability | undefined> {
      // Obtain the output streams supported by the camera device.
      let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice, sceneMode);
      if (!cameraOutputCapability) {
        console.error("cameraManager.getSupportedOutputCapability error");
        return undefined;
      }
      console.info("outputCapability: " + JSON.stringify(cameraOutputCapability));
      // The following uses the NORMAL_PHOTO mode as an example. You need to add the preview stream and photo stream.
      // previewProfiles is the preview output streams supported by the current camera device.
      let previewProfilesArray: Array<camera.Profile> = cameraOutputCapability.previewProfiles;
      if (!previewProfilesArray) {
        console.error("createOutput previewProfilesArray == null || undefined");
      }
      // photoProfiles is the photo output streams supported by the current camera device.
      let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
      if (!photoProfilesArray) {
        console.error("createOutput photoProfilesArray == null || undefined");
      }
      return cameraOutputCapability;
   } 
   ```
