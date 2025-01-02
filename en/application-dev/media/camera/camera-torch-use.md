# Using the Flashlight (ArkTS)

To use the flashlight mode, you manipulate your phone to turn on the flashlight, which then stays on persistently.

When you use the flashlight mode with a camera application, the following situations may occur:
- When the rear camera is used and [FlashMode](../../reference/apis-camera-kit/js-apis-camera.md#flashmode) is set to off, the flashlight cannot be turned on.
- When the front camera is used, the flashlight can be turned on and remains steady on.
- When you switch from the front camera to the rear camera, the flashlight will be automatically turned off if it was turned on previously.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import the camera module, which provides camera-related attributes and methods.

    ```ts
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. Call [isTorchSupported](../../reference/apis-camera-kit/js-apis-camera.md#istorchsupported11) in the [CameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameramanager) class to check whether the current device supports the flashlight.

    ```ts
    function isTorchSupported(cameraManager: camera.CameraManager) : boolean {
        let torchSupport: boolean = false;
        try {
            torchSupport = cameraManager.isTorchSupported();
        } catch (error) {
            let err = error as BusinessError;
            console.error('Failed to torch. errorCode = ' + err.code);
        }
        console.info('Returned with the torch support status:' + torchSupport);
        return torchSupport;
    }
    ```

3. Call [isTorchModeSupported](../../reference/apis-camera-kit/js-apis-camera.md#istorchmodesupported11) in the [CameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameramanager) class to check whether a specific [TorchMode](../../reference/apis-camera-kit/js-apis-camera.md#torchmode11) is supported.

    ```ts
    function isTorchModeSupported(cameraManager: camera.CameraManager, torchMode: camera.TorchMode) : boolean {
        let isTorchModeSupport: boolean = false;
        try {
            isTorchModeSupport = cameraManager.isTorchModeSupported(torchMode);
        } catch (error) {
            let err = error as BusinessError;
            console.error('Failed to set the torch mode. errorCode = ' + err.code);
        }
        return isTorchModeSupport;
    }
    ```

4. Call [setTorchMode](../../reference/apis-camera-kit/js-apis-camera.md#settorchmode11) in the [CameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameramanager) class to set the flashlight mode, and then [getTorchMode](../../reference/apis-camera-kit/js-apis-camera.md#gettorchmode11) in the [CameraManager](../../reference/apis-camera-kit/js-apis-camera.md#cameramanager) class to obtain the flashlight mode in use.

    ```ts
    function setTorchModeSupported(cameraManager: camera.CameraManager, torchMode: camera.TorchMode) : void {
        cameraManager.setTorchMode(torchMode);
        let isTorchMode = cameraManager.getTorchMode();
        console.info(`Returned with the torch mode supportd mode: ${isTorchMode}`);
    }
    ```

## Status Listening

During camera application development, you can listen for the flashlight status, including on, off, unavailable, and available.  

Register the **'torchStatusChange'** event and return the listening result through a callback, which carries the **TorchStatusInfo** parameter. For details about the parameter, see [TorchStatusInfo](../../reference/apis-camera-kit/js-apis-camera.md#torchstatusinfo11).


```ts
function onTorchStatusChange(cameraManager: camera.CameraManager): void {
    cameraManager.on('torchStatusChange', (err: BusinessError, torchStatusInfo: camera.TorchStatusInfo) => {
        if (err !== undefined && err.code !== 0) {
            console.error(`Callback Error, errorCode: ${err.code}`);
            return;
        }
        console.info(`onTorchStatusChange, isTorchAvailable: ${torchStatusInfo.isTorchAvailable}, isTorchActive: ${torchStatusInfo.
            isTorchActive}, level: ${torchStatusInfo.torchLevel}`);
    });
}
```
