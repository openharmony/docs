# Moving Photos (ArkTS)

<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=b54f1cb0e9f1bc9f3c62717aa0640837f9ff1365 translatedAt=2026-08-10T09:14:59.292Z pushedAt=2026-08-10T11:46:20.271Z -->

The camera framework provides the capability of taking moving photos. With this capability, users can take a moving photo in one-click mode, in a way similar to taking an ordinary photo.

To develop the moving photo feature, perform the following steps:

- Configure the mandatory capabilities required for camera application development by following the instructions provided in [Requesting Camera Development Permissions](camera-preparation.md), [Camera Device Management](camera-device-management.md), [Device Input Management](camera-device-input.md), and [Camera Session Management](camera-session-management.md).

- Check whether the device supports taking moving photos.

- Enable the capability of taking moving photos (if supported).

- Listen for the photo callback function and save the photo to the media library. For details, see [Accessing and Managing Moving Photos](../medialibrary/photoAccessHelper-movingphoto.md).

## How to Develop

For the detailed API reference, see [@ohos.multimedia.camera (Camera Management)](../../reference/apis-camera-kit/arkts-apis-camera.md).

> **NOTE**
>
> The `ohos.permission.MICROPHONE` permission is required for taking moving photos. For details about how to apply for and verify the permission, see [Requesting Camera Development Permissions](camera-preparation.md). Otherwise, the captured photos will have no sound.

1. Import dependencies. Specifically, import the camera, image, and mediaLibrary modules.

   ```ts
   import { camera } from '@kit.CameraKit';
   import { photoAccessHelper } from '@kit.MediaLibraryKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   ```

2. Determine the photo output stream.

   You can use the **photoProfiles** property of [CameraOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-i.md#cameraoutputcapability) to obtain the photo output streams supported by the device and use [createPhotoOutput](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#createphotooutput11) to create a photo output stream.

   <!-- @[camera_getPhotoOutput](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   getPhotoOutput(cameraManager: camera.CameraManager,
     cameraOutputCapability: camera.CameraOutputCapability): camera.PhotoOutput | undefined {
     let photoProfilesArray: camera.Profile[] = cameraOutputCapability.photoProfiles;
     if (!photoProfilesArray || photoProfilesArray.length === 0) {
       console.error('photoProfilesArray is null or []');
     }
     let photoOutput: camera.PhotoOutput | undefined = undefined;
     try {
       this.photoProfileObj = photoProfilesArray[0]
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
   > Before querying whether moving photo is supported, you must configure, commit, and start a camera session. For detailed development steps, see [Session Management](camera-session-management.md).

   <!-- @[camera_moving_photo_support](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   isMovingPhotoSupported(): boolean {
     let isSupported: boolean = false;
     try {
       if (this.photoOutput == undefined) {
         console.error(`photoOutput is nullptr.`);
         return false;
       }
       isSupported = this.photoOutput.isMovingPhotoSupported();
     } catch (error) {
       // Return error code error.code and handle it on failure.
       let err = error as BusinessError;
       console.error(`The isMovingPhotoSupported call failed. error code: ${err.code}`);
     }
     return isSupported;
   }
   ```

4. Enable the capability of taking moving photos.

   > **NOTE**
   >
   > Before enabling moving photo, you must enable the [deferred capture](camera-deferred-capture.md) capability.

   <!-- @[camera_moving_photo_enable](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

   ``` TypeScript
   enableMovingPhoto(enable: boolean): void {
     try {
       if (this.photoOutput != undefined) {
         console.info(TAG, `enableMovingPhoto: ${enable}`);
         this.photoOutput.enableMovingPhoto(enable);
       }
     } catch (error) {
       // Return error code error.code and handle it upon failure.
       let err = error as BusinessError;
       console.error(`The enableMovingPhoto call failed. error code: ${err.code}`);
     }
   }
   ```

5. Trigger photo capture. This procedure is the same as that in the common photo capture mode. For details, see [Photo Capture](camera-shooting.md).

## Status Listening

During camera application development, you can listen for the output stream status of moving photos by registering the **'photoAsset'** event. This event can be registered when a PhotoOutput instance is created.

<!-- @[photo_asset_available](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/Camera/PhotoSameSource/entry/src/main/ets/mode/CameraService.ets) -->

``` TypeScript
onPhotoOutputPhotoAssetAvailable(photoOutput: camera.PhotoOutput, context: Context): void {
  photoOutput.on('photoAssetAvailable', (err: BusinessError, photoAsset: photoAccessHelper.PhotoAsset) => {
    if (err) {
      console.error(`photoAssetAvailable error: ${err}.`);
      return;
    }
    console.info('photoOutputCallBack photoAssetAvailable');
    // You can call media library APIs through photoAsset to customize image processing.
    // Method 1: Call the media library save-to-disk API to save the first-stage image. After the second-stage image is ready, the media library automatically replaces the saved image for the app.
    let accessHelper: photoAccessHelper.PhotoAccessHelper =
      photoAccessHelper.getPhotoAccessHelper(this.context);
    this.mediaLibSavePhoto(photoAsset, accessHelper);
    // Method 2: Call the media library API to request the image and register the first-stage or second-stage image buffer callback for custom use.
    this.mediaLibRequestBuffer(photoAsset, context, this.callback);
  });
}

async mediaLibSavePhoto(photoAsset: photoAccessHelper.PhotoAsset,
  phAccessHelper: photoAccessHelper.PhotoAccessHelper): Promise<void> {
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
      new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    assetChangeRequest.saveCameraPhoto();
    await phAccessHelper.applyChanges(assetChangeRequest);
    phAccessHelper.release().catch(() => {
      console.error(`release failed.`);
    });
  } catch (error) {
    Logger.error(`apply saveCameraPhoto failed with error: ${error.code}, ${error.message}`);
  }
}

async mediaLibRequestBuffer(photoAsset: photoAccessHelper.PhotoAsset, context: Context,
  callback: (pixelMap: image.PixelMap, url: string) => void) {
  class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
    onDataPrepared(data: ArrayBuffer) {
      if (data === undefined) {
        Logger.error('Error occurred when preparing data');
        return;
      }
      let imageSource = image.createImageSource(data);
      imageSource.createPixelMap().then((pixelMap: image.PixelMap) => {
        callback(pixelMap, photoAsset.uri);
      }).catch((err: BusinessError) => {
        Logger.error(`createPixelMap err:${err.code}`);
      })
    }
  }

  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
  }
  const handler = new MediaDataHandler();
  try {
    await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, handler);
  } catch (error) {
    console.error(`requestImageData failed, err: ${error.code}`);
  }
}
```

## HDR Moving Photo

Starting from API version 23, the camera provides the HDR moving photo capture capability. This means that both the still image and the short video that make up a moving photo are high dynamic range (HDR) content, delivering better highlight and shadow details, richer color gradation, and superior overall texture compared to SDR output.

You can flexibly determine whether to output SDR or HDR moving photos by configuring the preview output format (`Profile.format`) and color space (`ColorSpace`). The specific mapping is shown in the following table. All capabilities must be queried before use. The supported preview output formats can be queried through the [getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23) interface, and the supported color spaces can be queried through the [getSupportedColorSpaces](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12) interface.

| Still Image Dynamic Range | Short Video Dynamic Range | Preview Output Format | Color Space |
|----------------|------------|------------|------------|
| SDR       | SDR       | CAMERA_FORMAT_YUV_420_SP       | SRGB |
| HDR       | SDR       | CAMERA_FORMAT_YUV_420_SP       | DISPLAY_P3 |
| HDR       | HDR       | CAMERA_FORMAT_YCRCB_P010, <br>CAMERA_FORMAT_YCBCR_P010 | BT2020_HLG |

**HDR Configuration Description**

- When configuring the preview output stream, you must first query the full capabilities supported by the current lens and mode through the [getSupportedFullOutputCapability](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedfulloutputcapability23) interface, and select P010 (`CAMERA_FORMAT_YCRCB_P010`/`CAMERA_FORMAT_YCBCR_P010`) as the preview output format.

- When configuring the color space, you must first obtain the color spaces supported by the current device through [getSupportedColorSpaces](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagementQuery.md#getsupportedcolorspaces12), and then set the color space to `BT2020_HLG` through [setColorSpace](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagement.md#setcolorspace12). For details, see the description of [setColorSpace](../../reference/apis-camera-kit/arkts-apis-camera-ColorManagement.md#setcolorspace12).