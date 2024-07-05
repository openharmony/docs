# Moving Photos (ArkTS)

The camera framework provides the capability of taking moving photos. With this capability, users can take a moving photo in one-click mode, in a way similar to taking an ordinary photo.

To develop the moving photo feature, perform the following steps:

- Check whether the device supports taking moving photos.
- Enable the capability of taking moving photos (if supported).
- Listen for the photo callback function and save the photo to the media library.

> **NOTE**
> 
> Before enabling the capability of taking moving photos, you must enable deferred delivery of photo capture.

## How to Develop

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

1. Import dependencies. Specifically, import the camera, image, and mediaLibrary modules.

   ```ts
   import camera from '@ohos.multimedia.camera';
   import image from '@ohos.multimedia.image';
   import photoAccessHelper from '@ohos.file.photoAccessHelper';
   import { BusinessError } from '@ohos.base';
   ```

2. Determine the photo output stream.

   You can use the **photoProfiles** attribute of the [CameraOutputCapability](../../reference/apis-camera-kit/js-apis-camera.md#cameraoutputcapability) class to obtain the photo output streams supported by the device and use [createPhotoOutput](../../reference/apis-camera-kit/js-apis-camera.md#createphotooutput11) to create a photo output stream.

   ```ts
   function getPhotoOutput(cameraManager: camera.CameraManager, 
                           cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: Array<camera.Profile> = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray) {
       console.error("createOutput photoProfilesArray == null || undefined");
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       photoOutput = cameraManager.createPhotoOutput(photoProfilesArray[0]);
     } catch (error) {
       let err = error as BusinessError;
       console.error(`Failed to createPhotoOutput. error: ${JSON.stringify(err)}`);
     }
     return photoOutput;
   }
   ```

3. Check whether the device supports taking moving photos.

   ```ts
   function isMovingPhotoSupported(photoOutput: camera.PhotoOutput): boolean {
     let isSupported: boolean = false;
     try {
       isSupported = photoOutput.isMovingPhotoSupported();
     } catch (error) {
       // If the operation fails, error.code is returned and processed.
       let err = error as BusinessError;
       console.error(`The isMovingPhotoSupported call failed. error code: ${err.code}`);
     }
     return isSupported;
   }
   ```

4. Enable the capability of taking moving photos.

   ```ts
   function enableMovingPhoto(photoOutput: camera.PhotoOutput): void {
     try {
       photoOutput.enableMovingPhoto(true);
     } catch (error) {
       // If the operation fails, error.code is returned and processed.
       let err = error as BusinessError;
       console.error(`The enableMovingPhoto call failed. error code: ${err.code}`);
     }
   }
   ```

5. Trigger photographing. This procedure is the same as that in the common photographing mode. For details, see [Camera Photographing](camera-shooting.md).

## Status Listening

Register a callback function to listen for **'photoAssetAvailable'** events.

   ```ts
   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput): void {
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void => {
       if (err) {
         console.info(`photoAssetAvailable error: ${JSON.stringify(err)}.`);
         return;
       }
       console.info('photoOutPutCallBack photoAssetAvailable');
       // Save or use the photo. You need to implement this API.
       photoAsset.saveCameraPhoto();
     });
   }
   ```
