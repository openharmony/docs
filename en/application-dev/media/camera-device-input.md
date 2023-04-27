# Device Input Management

Before developing a camera application, you must create an independent camera object. The application invokes and controls the camera object to perform basic operations such as preview, photographing, and video recording.

## How to Develop

Read [Camera](../reference/apis/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.
   
   ```ts
   import camera from '@ohos.multimedia.camera';
   ```

2. Call **getCameraManager()** to obtain a **CameraManager** object.
   
   ```ts
   let cameraManager;
   let context: any = getContext(this);
   cameraManager = camera.getCameraManager(context)
   ```

   > **NOTE**
   >
   > If obtaining the object fails, the camera hardware may be occupied or unusable. If it is occupied, wait until it is released.

3. Call **getSupportedCameras()** in the **CameraManager** class to obtain the list of cameras supported by the current device. The list stores the IDs of all cameras supported. If the list is not empty, each ID in the list can be used to create an independent camera object. Otherwise, no camera is available for the current device and subsequent operations cannot be performed.
   
   ```ts
   let cameraArray = cameraManager.getSupportedCameras();
   if (cameraArray.length <= 0) {
       console.error("cameraManager.getSupportedCameras error");
       return;
   } 
   
   for (let index = 0; index < cameraArray.length; index++) {
       console.info('cameraId : ' + cameraArray[index].cameraId);                          // Obtain the camera ID.
       console.info('cameraPosition : ' + cameraArray[index].cameraPosition);              // Obtain the camera position.
       console.info('cameraType : ' + cameraArray[index].cameraType);                      // Obtain the camera type.
       console.info('connectionType : ' + cameraArray[index].connectionType);              // Obtain the camera connection type.
   }
   ```

4. Call **getSupportedOutputCapability()** to obtain all output streams supported by the current device, such as preview streams and photo streams. The output stream is in each **profile** field under **CameraOutputCapability**.
   
   ```ts
   // Create a camera input stream.
   let cameraInput;
   try {    
       cameraInput = cameraManager.createCameraInput(cameraArray[0]);
   } catch (error) {
      console.error('Failed to createCameraInput errorCode = ' + error.code);
   } 
   // Listen for CameraInput errors.
   let cameraDevice = cameraArray[0];
   cameraInput.on('error', cameraDevice, (error) => {
       console.info(`Camera input error code: ${error.code}`);
   }) 
   // Open the camera.
   await cameraInput.open(); 
   // Obtain the output stream capabilities supported by the camera.
   let cameraOutputCapability = cameraManager.getSupportedOutputCapability(cameraArray[0]);
   if (!cameraOutputCapability) {
       console.error("cameraManager.getSupportedOutputCapability error");
       return;
   }
   console.info("outputCapability: " + JSON.stringify(cameraOutputCapability));
   ```


## Status Listening

During camera application development, you can listen for the camera status, including the appearance of a new camera, removal of a camera, and availability of a camera. The camera ID and camera status are used in the callback function. When a new camera appears, the new camera can be added to the supported camera list.

Register the 'cameraStatus' event and return the listening result through a callback, which carries the **CameraStatusInfo** parameter. For details about the parameter, see [CameraStatusInfo](../reference/apis/js-apis-camera.md#camerastatusinfo).

```ts
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
  console.info(`camera: ${cameraStatusInfo.camera.cameraId}`);
  console.info(`status: ${cameraStatusInfo.status}`);
})
```
