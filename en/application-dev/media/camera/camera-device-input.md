# Device Input Management (ArkTS)

Before developing a camera application, you must create an independent camera object. The application invokes and controls the camera object to perform basic operations such as preview, photographing, and video recording.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Call [getCameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameragetcameramanager) to obtain a **CameraManager** object.

   For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   function getCameraManager(context: common.BaseContext): camera.CameraManager {
     let cameraManager: camera.CameraManager = camera.getCameraManager(context);
     return cameraManager;
   }
   ```

   > **NOTE**
   >
   > If obtaining the object fails, the camera hardware may be occupied or unusable. If it is occupied, wait until it is released.

3. Call [getSupportedCameras](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras) in the **CameraManager** class to obtain the list of cameras supported by the current device. The list stores the IDs of all cameras supported. If the list is not empty, each ID in the list can be used to create an independent camera object. If the list is empty, no camera is available for the current device and subsequent operations cannot be performed.

   ```ts
   function getCameraDevices(cameraManager: camera.CameraManager): Array<camera.CameraDevice> {
     let cameraArray: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
     if (cameraArray != undefined && cameraArray.length > 0) {
       for (let index = 0; index < cameraArray.length; index++) {
         console.info('cameraId : ' + cameraArray[index].cameraId);  // Obtain the camera ID.
         console.info('cameraPosition : ' + cameraArray[index].cameraPosition);  // Obtain the camera position.
         console.info('cameraType : ' + cameraArray[index].cameraType);  // Obtain the camera type.
         console.info('connectionType : ' + cameraArray[index].connectionType);  // Obtain the camera connection type.
       }
       return cameraArray;
     } else {
       console.error("cameraManager.getSupportedCameras error");
       return [];
     }
   }
   ```

4. Call [getSupportedOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedoutputcapability11) to obtain all output streams supported by the current device, such as preview streams and photo streams. The output streams supported are the value of each **profile** field under [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability).

   ```ts
   async function getSupportedOutputCapability(cameraDevice: camera.CameraDevice, cameraManager: camera.CameraManager, sceneMode: camera.SceneMode): Promise<camera.CameraOutputCapability | undefined> {
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
     // Obtain the output streams supported by the camera.
     let cameraOutputCapability: camera.CameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraDevice, sceneMode);
     if (!cameraOutputCapability) {
       console.error("cameraManager.getSupportedOutputCapability error");
       return undefined;
     }
     console.info("outputCapability: " + JSON.stringify(cameraOutputCapability));
     return cameraOutputCapability;
   }
   ```


## Status Listening

During camera application development, you can listen for the camera status, including the appearance of a new camera, removal of a camera, and availability of a camera. The camera ID and camera status are included in the callback function. When a new camera appears, the new camera can be added to the supported camera list.

  Register the **'cameraStatus'** event and return the listening result through a callback, which carries the **CameraStatusInfo** parameter. For details about the parameter, see [CameraStatusInfo](../../reference/apis-camera-kit/js-apis-camera.md#camerastatusinfo).

```ts
function onCameraStatus(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    console.info(`camera: ${cameraStatusInfo.camera.cameraId}`);
    console.info(`status: ${cameraStatusInfo.status}`);
  });
}
```
