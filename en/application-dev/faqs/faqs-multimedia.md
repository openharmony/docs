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

[CameraStatus](../reference/apis-camera-kit/js-apis-camera.md#oncamerastatus)

## Does SoundPool support audio in WMV format? Which formats are supported? (API version 10)

**Solution**

Currently, WMV is not supported. The supported formats are AAC, MPEG (MP3), FLAC, and Vorbis.

**References**

The formats supported by **SoundPool** are the same as those supported by the bottom layer. For details about the supported formats, see [Audio Decoding](../media/avcodec/audio-decoding.md).

## How do I read the preview image of the camera? (API version 10)

**Solution**

You can call **ImageReceiver.readLatestImage** to obtain the preview image of the camera.

**References**

[readLatestImage](../reference/apis-image-kit/js-apis-image.md#readlatestimage9)

## How do I listen for recordings? (API version 10)

**Solution**

Audio-related listening of the system is implemented in **AudioStreamManager**. You can call **on(type: 'audioCapturerChange', callback: Callback\<AudioCapturerChangeInfoArray>): void** to listen for audio capturer changes.

**References**

[onaudiocapturerchange](../reference/apis-audio-kit/js-apis-audio.md#onaudiocapturerchange9)

## In which audio processing scenarios are 3A algorithms (AEC, ANC, and AGC) embedded? If they are embedded, is there any API related to audio 3A processing? How do I call them? Are independent switches provided for the 3A algorithms? Does the system support 3A in recording scenarios? If not, what is the solution? For example, how do I ensure the sound quality of audio recording when playing music? (API version 10)

**Solution**

The embedded 3A processing is automatically enabled for the audio stream with the **STREAM_USAGE_VOICE_COMMUNICATION** configuration. Currently, an independent switch is not provided. 3A is supported in recording scenarios. You need to configure **AudioScene** and **SourceType** to enable 3A processing in recording scenarios.

**References**

[AudioCapturer](../reference/apis-audio-kit/js-apis-audio.md#audiocapturer8)

## How do I implement low latency audio recording?(API 11)

**Solution**

To implement low latency audio recording, use the C APIs provided by the **AudioCapturer** class of the **OHAudio** module. For details, see [Using OHAudio for Audio Recording (C/C++)](../media/audio/using-ohaudio-for-recording.md).

**References**

[ohaudio](../reference/apis-audio-kit/_o_h_audio.md)

## How do I implement real-time video stream transmission? How do I implement live broadcast? (API version 10)

**Solution**

Currently, the AVPlayer supports HTTP, HTTPS, and HLS for real-time video stream transmission. In the live broadcast scenario, the AVPlayer can play the data sent by the peer once it receives the live broadcast address. Stream pushing is not supported yet, which means that the Avplayer cannot use the current device for live broadcast.

**References**

- [Media Kit](../media/media/media-kit-intro.md)
- [AVPlayer](../media/media/using-avplayer-for-playback.md)

## How do I enable the AVPlayer to play in the background? (API version 10)

**Solution**

To continue background playback, the application must request a continuous task and register the AVSession with the system for unified management.

**References**

[Accessing AVSession](../media/avsession/avsession-access-scene.md)

## Why can't a third-party application create albums? (API version 10)

**Symptom**

The read and write permissions of album resources are set to the system_basic level, and the APIs for creating albums are designed as system APIs. What is the reason of this design? (API version 10)

**Solution**

To protect the privacy of users' images and videos, any operation on these files must be notified by the users. Therefore, the read and write permissions are not granted to third-party applications. The system generates source albums based on the image and video storage sources. User-defined albums can only be created in Gallery and can be dragged to the user-defined album area.

## How do I compress an image to a specified size? What are the factors affecting the size after compression? (API version 10)

**Symptom**

What is the relationship between the **quality** parameter in the image compression APIs and the original size and compressed size of an image? How do I set the target image size? For example, if I want to compress an image to 500 KB, how do I set the parameters?

**Solution**

The **quality** parameter affects the target image size for a lossy compression image format (such as JPEG), but not for a lossless compression image format (such as PNG).
For lossy compression images, the target image size depends on the original image size, compression quality, and image content. Therefore, the current system does not support the setting of the target image size. If an application wants to specify the size, you can adjust the **quality** parameter based on the compression result, or scale the pixel map to a smaller size and then compress the pixel map.

**References**

- [scale](../reference/apis-image-kit/js-apis-image.md#scale9)
- [packing](../reference/apis-image-kit/js-apis-image.md#packing)
