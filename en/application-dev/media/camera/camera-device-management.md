# Camera Device Management (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=f0256a7e7998b4ec175cb1377224071f12b145e0 translatedAt=2026-08-10T09:13:17.290Z pushedAt=2026-08-10T11:28:22.813Z -->

Before developing a camera app, you need to create a camera management instance by calling camera APIs.

## How to Develop

For detailed API descriptions, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

1. Import the camera module, which provides camera-related properties and methods.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   ```

2. Call [getCameraManager](../../reference/apis-camera-kit/arkts-apis-camera-f.md#cameragetcameramanager) to obtain a CameraManager object.

   For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

   ```ts
   function getCameraManager(context: common.BaseContext): camera.CameraManager | undefined {
     let cameraManager: camera.CameraManager;
     try {
       cameraManager = camera.getCameraManager(context);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`getCameraManager error, errCode: ${err.code}`);
       return undefined;
     }
     return cameraManager;
   }
   ```

   > **NOTE**
   >
   > If obtaining the object fails, the camera device may be occupied or unusable. If it is occupied, wait until it is released.

3. Call the [getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras) method in [CameraManager](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md) to obtain the list of cameras supported by the current device. The list stores all camera IDs supported by the device. If the list is not empty, each ID in the list can be used to independently create a camera object. Otherwise, no camera is available on the current device, and subsequent operations cannot be performed.

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

## Status Listening

During camera application development, you can listen for the camera status, including the appearance of a new camera, removal of a camera, and availability of a camera. The camera ID and camera status are included in the callback function. When a new camera appears, the new camera can be added to the supported camera list.

Register the **cameraStatus** event to receive listening results through the callback. The callback returns a **CameraStatusInfo** parameter. For details about the parameter, see [CameraStatusInfo](../../reference/apis-camera-kit/arkts-apis-camera-i.md#camerastatusinfo).

```ts
function onCameraStatusChange(cameraManager: camera.CameraManager): void {
  cameraManager.on('cameraStatus', (err: BusinessError, cameraStatusInfo: camera.CameraStatusInfo) => {
    if (err !== undefined && err.code !== 0) {
      console.error(`Callback Error, errorCode: ${err.code}`);
      return;
    }
    // If a camera is connected through a USB cable, the callback function returns the CAMERA_STATUS_APPEAR status.
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_APPEAR) {
      console.info(`New Camera device appear.`);
    }
    // If the USB connection of the camera is interrupted, the callback function returns the CAMERA_STATUS_DISAPPEAR status.
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_DISAPPEAR) {
      console.info(`Camera device has been removed.`);
    }
    // If the camera is closed, the callback function returns the CAMERA_STATUS_AVAILABLE status.
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_AVAILABLE) {
      console.info(`Current Camera is available.`);
    }
    // If the camera is opened or occupied, the callback function returns the CAMERA_STATUS_UNAVAILABLE status.
    if (cameraStatusInfo.status == camera.CameraStatus.CAMERA_STATUS_UNAVAILABLE) {
      console.info(`Current Camera has been occupied.`);
    }
    console.info(`camera: ${cameraStatusInfo.camera.cameraId}`);
    console.info(`status: ${cameraStatusInfo.status}`);
  });
}
```