# Distributed Camera Development

## When to Use

You can call the APIs provided by the **Camera** module to develop a distributed camera that provides the basic camera functions such as shooting and video recording.

## How to Develop
Connect your calculator to a distributed device. Your calculator will call **getSupportedCameras()** to obtain the camera list and traverse the returned camera list to check **ConnectionType** of the **Camera** objects. If **ConnectionType** of a **Camera** object is **CAMERA_CONNECTION_REMOTE**, your calculator will use this object to create a **cameraInput** object. The subsequent call process is the same as that of the local camera development. For details about the local camera development, see [Camera Development](./camera.md).

For details about the APIs, see [Camera Management](../reference/apis/js-apis-camera.md).

### Connecting to a Distributed Camera

Connect the calculator and the distributed device to the same LAN.

Open the calculator and click the arrow icon in the upper right corner. A new window is displayed. Enter the verification code as prompted, and the calculator will be connected to the distributed device.

### Creating an Instance

```js
import camera from '@ohos.multimedia.camera'
import image from '@ohos.multimedia.image'
import media from '@ohos.multimedia.media'
import featureAbility from '@ohos.ability.featureAbility'

// Create a CameraManager object.
let cameraManager = camera.getCameraManager(globalThis.Context)
if (!cameraManager) {
    console.error("camera.getCameraManager error")
    return;
} 

// Register a callback to listen for camera status changes and obtain the updated camera status information.
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
    console.log('camera : ' + cameraStatusInfo.camera.cameraId);
    console.log('status: ' + cameraStatusInfo.status);
})

// Obtain the camera list.
let remoteCamera
let cameraArray = cameraManager.getSupportedCameras();
if (cameraArray.length <= 0) {
    console.error("cameraManager.getSupportedCameras error")
    return;
} 

for(let cameraIndex = 0; cameraIndex < cameraArray.length; cameraIndex++) {
    console.log('cameraId : ' + cameraArray[cameraIndex].cameraId)                          // Obtain the camera ID.
    console.log('cameraPosition : ' + cameraArray[cameraIndex].cameraPosition)              // Obtain the camera position.
    console.log('cameraType : ' + cameraArray[cameraIndex].cameraType)                      // Obtain the camera type.
    console.log('connectionType : ' + cameraArray[cameraIndex].connectionType)              // Obtain the camera connection type.
    if (cameraArray[cameraIndex].connectionType == CAMERA_CONNECTION_REMOTE) {
        remoteCamera = cameraArray[cameraIndex]
    }
}

// Create a camera input stream.
let cameraInput
try {
    cameraInput = cameraManager.createCameraInput(remoteCamera);
} catch () {
   console.error('Failed to createCameraInput errorCode = ' + error.code);
}
```
For details about the subsequent steps, see [Camera Development](./camera.md).
