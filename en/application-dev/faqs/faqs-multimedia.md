# Multimedia Development


## How do I obtain the frame data of a camera when using the XComponent to display the preview output stream of the camera? (API version 9)

**Symptom**

Currently, the API does not support real-time preview of the camera frame data. To obtain the frame data, you must bind an action, for example, photographing.

**Solution**

Create a dual-channel preview to obtain the frame data.

1. Use the XComponent to create a preview stream.

   ```
   // Obtain a PreviewOutput instance.
   const surfaceId = globalThis.mxXComponentController.getXComponentSurfaceld();
   this.mPreviewOutput = await Camera.createPreviewOutput(surfaceld) ;
   ```

2. Use imageReceiver to listen for image information.

   ```
   // Add dual-channel preview.
   const fullWidth = this.mFullScreenSize.width;
   const fullHeight = this.mFullScreenSize.height;
   const imageReceiver = await image.createImageReceiver(fullwidth, fullHeight, 
     formatImage, capacityImage) ;
   const photoSurfaceId = await imageReceiver.getReceivingSurfaceld();
   this.mPreviewOutputDouble = await Camera.createPreviewOutput ( photoSurfaceld)
   ```


## How do I obtain the preview image of the front camera? (API version 9)

**Solution**

1. Use the **\@ohos.multimedia.camera** module to obtain the physical camera information.

   ```
   let cameraManager = await camera.getCameraManager(context);
   let camerasInfo = await cameraManager.getSupportedCameras();
   let cameraDevice = this.camerasInfo[0];
   ```

2. Create and start the input stream channel of the physical camera.

   ```
   let cameraInput = await cameraManager.createCameraInput(cameraDevice);
   await this.cameraInput.open();
   ```

3. Obtain the output formats supported by the camera, and create a preview output channel based on the surface ID provided by the XComponent.

   ```
   let outputCapability = await this.cameraManager.getSupportedOutputCapability(cameraDevice);
   let previewProfile = this.outputCapability.previewProfiles[0];
   let previewOutput = await cameraManager.createPreviewOutput(previewProfile, previewId);
   ```

4. Create a camera session, add the camera input stream and preview output stream to the session, and start the session. The preview image is displayed on the XComponent.

   ```
   let captureSession = await cameraManager.createCaptureSession();
   await captureSession.beginConfig();
   await captureSession.addInput(cameraInput);
   await captureSession.addOutput(previewOutput);
   await this.captureSession.commitConfig()
   await this.captureSession.start();
   ```


## How do I set the camera focal length? (API version 9)

**Solution**

1. Check whether the camera is a front camera. A front camera does not support focal length setting.

2. Use **captureSession.getZoomRatioRange()** to obtain the focal length range supported by the device.

3. Check whether the target focal length is within the range obtained. If yes, call **captureSession.setZoomRatio()** to set the focal length.


## What should I do when multiple video components cannot be used for playback? (API version 9)

**Symptom**

A large number of video components are created. They cannot play media normally or even crash.

**Solution**

A maximum of 13 media player instances can be created.


## How do I invoke the image library directly? (API version 9)

**Solution**

```
let want = {
  bundleName: 'com.ohos.photos',
  abilityName: 'com.ohos.photos.MainAbility',
  parameters: {
 uri: 'detail'
  }
};
let context = getContext(this) as common.UIAbilityContext;
context.startAbility(want);
```


## How do I apply for the media read/write permission on a device? (API version 9)

Applicable to: stage model

**Solution**

1. Configure the permissions **ohos.permission.READ_MEDIA** and **ohos.permission.WRITE_MEDIA** in the **module.json5** file.

   Example:

   ```
   {
     "module" : {
       "requestPermissions":[
         {
           "name" : "ohos.permission.READ_MEDIA",
           "reason": "$string:reason"
         },
         {
           "name" : "ohos.permission.WRITE_MEDIA",
           "reason": "$string:reason"
         }
       ]
     }
   }
   ```

2. Call **requestPermissionsFromUser** to request the permissions from end users in the form of a dialog box. This operation is required because the grant mode of both permissions is **user_grant**.

   ```
   let context = getContext(this) as common.UIAbilityContext;
   let atManager = abilityAccessCtrl.createAtManager();
   let permissions: Array<string> = ['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
   atManager.requestPermissionsFromUser(context, permissions)
   .then((data) => {
       console.log("Succeed to request permission from user with data: " + JSON.stringify(data))
   }).catch((error) => {
       console.log("Failed to request permission from user with error: " + JSON.stringify(error))
   })
   ```


## How do I obtain the camera status? (API version 9)

Applicable to: stage model

**Solution**

The **cameraManager** class provides a listener to subscribe to the camera status.

```
cameraManager.on('cameraStatus', (cameraStatusInfo) => {
  console.log(`camera : ${cameraStatusInfo.camera.cameraId}`);
  console.log(`status: ${cameraStatusInfo.status}`);
})
```

CameraStatus

Enumerates the camera statuses.

**CAMERA_STATUS_APPEAR** (0): A camera appears.

**CAMERA_STATUS_DISAPPEAR** (1): The camera disappears.

**CAMERA_STATUS_AVAILABLE** (2): The camera is available.

**CAMERA_STATUS_UNAVAILABLE** (3): The camera is unavailable.

**References**

[CameraStatus](../reference/apis/js-apis-camera.md#oncamerastatus)
