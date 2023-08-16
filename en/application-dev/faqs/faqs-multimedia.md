# Multimedia Development

## How do I obtain the frame data of a camera when using the XComponent to display the preview output stream of the camera?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

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


## How do I obtain the preview image of the front camera?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Solution**

1. Use the **@ohos.multimedia.camera** module to obtain the physical camera information.

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


## How do I set the camera focal length?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Solution**

1. Check whether the camera is a front camera. A front camera does not support focal length setting.
2. Use **captureSession.getZoomRatioRange\(\)** to obtain the focal length range supported by the device.
3. Check whether the target focal length is within the range obtained. If yes, call **captureSession.setZoomRatio\(\)** to set the focal length.

## How do I play music in the background?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Symptom**

Music cannot be played in the background.

**Solution**

**AVSession** controls media playback. When a third-party application switches to the background or encounters a screen lock event, media playback is forcibly paused and the application is unaware of the pause. To enable the application to continue the playback in the background, request a continuous task and access the AVSession capability, which allows Control Panel to control the playback behavior of third-party applications.

**Reference**

[Continuous Task](../task-management/continuous-task.md)

[AVSession Development](../media/using-avsession-developer.md)


## What should I do when multiple video components cannot be used for playback?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

**Symptom**

A large number of video components are created. They cannot play media normally or even crash.

**Solution**

A maximum of 13 media player instances can be created.


## How do I invoke the image library directly?

Applicable to: OpenHarmony 3.2 (API version 9, stage model)

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
