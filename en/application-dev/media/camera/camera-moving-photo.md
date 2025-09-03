# Moving Photos (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--SE: @leo_ysl-->
<!--TSE: @xchaosioda-->

The camera framework provides the capability of taking moving photos. With this capability, users can take a moving photo in one-click mode, in a way similar to taking an ordinary photo.

To develop the moving photo feature, perform the following steps:

- Check whether the device supports taking moving photos.
- Enable the capability of taking moving photos (if supported).
- Listen for the photo callback function and save the photo to the media library. For details, see [Accessing and Managing Moving Photos](../medialibrary/photoAccessHelper-movingphoto.md).

## How to Develop

Read [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

> **NOTE**
>
> - Before enabling the capability of taking moving photos, you must enable [deferred photo delivery](camera-deferred-capture.md).
> - The permission ohos.permission.MICROPHONE is required for taking moving photos. For details about how to apply for and verify the permission, see [Requesting Camera Development Permissions](camera-preparation.md). Otherwise, there is no sound when a photo is being taken.

1. Import dependencies. Specifically, import the camera, image, and mediaLibrary modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Determine the photo output stream.

   You can use the **photoProfiles** property of the [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) class to obtain the photo output streams supported by the device and use [createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11) to create a photo output stream.

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
       console.error(`Failed to createPhotoOutput. error: ${err}`);
     }
     return photoOutput;
   }
   ```

3. Check whether the device supports taking moving photos.

    > **NOTE**
    >
    > Before the check, you must configure, commit, and start a session. For details, see [Camera Session Management](camera-session-management.md).

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

5. Trigger photo capture. This procedure is the same as that in the common photo capture mode. For details, see [Photo Capture](camera-shooting.md).

## Status Listening

During camera application development, you can listen for the output stream status of moving photos by registering the **'photoAsset'** event. This event can be registered when a PhotoOutput instance is created.

   ```ts
   function getPhotoAccessHelper(context: Context): photoAccessHelper.PhotoAccessHelper {
     let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
     return phAccessHelper;
   }

   async function mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
     phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
     try {
       let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
       assetChangeRequest.saveCameraPhoto();
       await phAccessHelper.applyChanges(assetChangeRequest);
       console.info('apply saveCameraPhoto successfully');
     } catch (err) {
       console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
     }
   }

   function onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput, context: Context): void {
     photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset): void => {
       if (err) {
         console.error(`photoAssetAvailable error: ${err}.`);
         return;
       }
       console.info('photoOutPutCallBack photoAssetAvailable');
       // Call the mediaLibrary flush API to save the first-phase images and moving photos.
       mediaLibSavePhoto(photoAsset, getPhotoAccessHelper(context));
     });
   }
   ```
