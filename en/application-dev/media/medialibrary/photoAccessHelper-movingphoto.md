# Accessing and Managing Moving Photos

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=00d7cb908705b920a9ee7ee48de288635f9580c9 translatedAt=2026-08-11T01:56:37.404Z pushedAt=2026-08-12T03:39:04.412Z -->

A moving photo is a photo form that combines an image and a video, empowering a static image with dynamic video effect. It helps users capture dynamic moments and improves the fault tolerance rate of photographing.

The media library provides the capabilities of accessing and managing moving photo assets, including:

- [Saving Moving Photo Assets](#saving-moving-photo-assets)

- [Obtaining a Moving Photo Object](#obtaining-a-moving-photo-object)

- [Playing Moving Photos with MovingPhotoView](movingphotoview-guidelines.md)

- [Reading Moving Photo Assets](#reading-moving-photo-assets)

The capability of taking moving photos is provided by Camera Kit. For details, see [Moving Photos (ArkTS)](../camera/camera-moving-photo.md).

## Saving Moving Photo Assets

Use the **SaveButton** security component to save the assets (image and video) of a moving photo.

With the **SaveButton** security component, the application does not need the **ohos.permission.WRITE_IMAGEVIDEO** permission. When the user taps the button embedded with the **SaveButton** security component, the application obtains the temporary permission to save the assets to the specified media library directory.

For details, see [SaveButton](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md).

**How to Develop**

1. Set the properties of the **SaveButton** security component.

2. Create a button with **SaveButton**.

3. Call [MediaAssetChangeRequest.createAssetRequest](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#createassetrequest11) to create an asset change request with **PhotoSubtype** set to **MOVING_PHOTO**.

4. Call [MediaAssetChangeRequest.addResource](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#addresource11) to set the image and video of the moving photo. The video duration of the moving photo cannot exceed 10s.

   In the following example, the image and video of the moving photo are specified by **fileUri** of the [application file](../../file-management/app-file-access.md) in the application sandbox.

   You can also specify the assets in **ArrayBuffer**. For details, see [MediaAssetChangeRequest.addResource(type: ResourceType, data: ArrayBuffer)](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#addresource11-1).

5. Call [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) to apply changes for the moving photo.

<!-- @[Save_Button](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoSample/entry/src/main/ets/pages/Scene1.ets) -->  

``` TypeScript
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';
// ...
import { fileUri } from '@kit.CoreFileKit';

@Entry({ routeName : 'Scene1' })
@Component
export struct Scene1 {
  @State statusMessage: string = '';
  @State imageSource: string = '';

  saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  }// Set properties of SaveButton.

  // ...

  build() {
    NavDestination() {
      Column({ space: 20 }) {
        // ...

        SaveButton(this.saveButtonOptions) // Create a button with SaveButton.
          .onClick(async (event, result: SaveButtonOnClickResult) => {
            if (result == SaveButtonOnClickResult.SUCCESS) {
              try {
                let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                // Ensure that the assets specified by imageFileUri and videoFileUri exist.
                let photoPath = context.filesDir;
                let imageFileUri = fileUri.getUriFromPath(photoPath) + '/create_moving_photo.jpg';
                let videoFileUri = fileUri.getUriFromPath(photoPath) + '/create_moving_photo.mp4';

                let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
                  photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context,
                    photoAccessHelper.PhotoType.IMAGE, 'jpg', {
                      title: 'moving_photo',
                      subtype: photoAccessHelper.PhotoSubtype.MOVING_PHOTO
                    });

                assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, imageFileUri);
                assetChangeRequest.addResource(photoAccessHelper.ResourceType.VIDEO_RESOURCE, videoFileUri);

                await phAccessHelper.applyChanges(assetChangeRequest);

                this.statusMessage = 'create moving photo successfully, uri: ' + assetChangeRequest.getAsset().uri;
                console.info('create moving photo successfully, uri: ' + assetChangeRequest.getAsset().uri);
              } catch (err) {
                this.statusMessage = `create moving photo failed with error: ${err.code}, ${err.message}`;
                console.error(`create moving photo failed with error: ${err.code}, ${err.message}`);
              }
            } else {
              this.statusMessage = 'SaveButtonOnClickResult create moving photo failed';
              console.error('SaveButtonOnClickResult create moving photo failed');
            }
          })

        // ...

      }
      .width('100%')
      .height('100%')
    }
    .title('Save Moving Photo')
  }
}
```

## Obtaining a Moving Photo Object

- Use **Picker** to obtain a moving photo object from the media library.

- Create a local moving photo object of the application by passing **fileUri** of an [application file](../../file-management/app-file-access.md) in the application sandbox.

If you want to play an obtained moving photo, see [Playing Moving Photos with MovingPhotoView](movingphotoview-guidelines.md).

### Obtaining a Moving Photo Object from the Media Library

1. Select the [URI of a media file](../../file-management/user-file-uri-intro.md#media-file-uri) of the moving photo by using **Picker**.

2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) and [FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1) to obtain the photo asset corresponding to the URI.

3. Call [MediaAssetManager.requestMovingPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#requestmovingphoto12) to obtain the moving photo object.

<!-- @[Obtaining_Moving_Photo_Sample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoSample/entry/src/main/ets/pages/Scene2.ets) -->

``` TypeScript
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';


@Entry({ routeName : 'Scene2' })
@Component
export struct Scene2 {

  @State statusMessage: string = '';

  build() {
    NavDestination() {
      Column({ space: 20 }) {

        Button('example')
          .width('80%')
          .height(50)
          .fontSize(16)
          .onClick(async () => {
            let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
            this.statusMessage = await example(phAccessHelper, context);
          })

        // ...
      }
      .width('100%')
      .height('100%')
    }
    .title('Get from Media Library')
  }
}
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context): Promise<string> {
  try {
    // Use Picker to select the URI of the moving photo.
    let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.MOVING_PHOTO_IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 9;
    let photoViewPicker = new photoAccessHelper.PhotoViewPicker();
    let photoSelectResult = await photoViewPicker.select(photoSelectOptions);
    let uris = photoSelectResult.photoUris;

    let resultMessage = 'Selected ' + uris.length + ' moving photo(s)\n\n';

    for (let i = 0; i < uris.length; i++) {
      // Obtain the photo asset corresponding to the URI.
      let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
      predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uris[i]);
      let fetchOption: photoAccessHelper.FetchOptions = {
        fetchColumns: [],
        predicates: predicates
      };
      let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = 
        await phAccessHelper.getAssets(fetchOption);
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

      let movingPhotoUri = await new Promise<string>((resolve) => {
        // Obtain the moving photo object corresponding to the photo asset.
        photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, photoAsset, {
          deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE
        }, {
          async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
            if (movingPhoto !== undefined) {
              // Customize the logic for processing the moving photo.
              console.info('request moving photo successfully, uri: ' + movingPhoto.getUri());
              resolve(movingPhoto.getUri());
            }
          }
        })
      });

      resultMessage += (i + 1) + '. request moving photo successfully, uri: ' + movingPhotoUri + '\n';
    }

    return resultMessage;
  } catch (err) {
    console.error(`request moving photo failed with error: ${err.code}, ${err.message}`);
    return `request moving photo failed with error: ${err.code}, ${err.message}`;
  }
}
```

### Obtaining a Moving Photo object in an Application Sandbox Directory

Call [MediaAssetManager.loadMovingPhoto](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetManager.md#loadmovingphoto12) to load the moving photo object in the application sandbox directory.

<!-- @[Reading_Moving_Photo_Sample](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoSample/entry/src/main/ets/pages/Scene3.ets) -->

``` TypeScript
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';
// ...
@Entry({ routeName : 'Scene3' })
@Component
export struct Scene3 {
  @State statusMessage: string = '';
  @State imageSource: string = '';

  // ...
  build() {
    NavDestination() {
      Column({ space: 20 }) {
        // ...

        Button('example')
          .width('80%')
          .height(50)
          .fontSize(16)
          .onClick(async () => {
            let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
            this.statusMessage = await example(context);
          })

        // ...

      }
      .width('100%')
      .height('100%')
    }
    .title('Load from Sandbox')
  }
}

async function example(context: Context): Promise<string> {
  try {
    let imageFileUri = 'file://' + context.filesDir + '/local_moving_photo.jpg';
    let videoFileUri = 'file://' + context.filesDir + '/local_moving_photo.mp4';
    let movingPhoto = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
    console.info('load moving photo successfully');
    return 'load moving photo successfully';
  } catch (err) {
    console.error(`load moving photo failed with error: ${err.code}, ${err.message}`);
    return `load moving photo failed with error: ${err.code}, ${err.message}`;
  }
}
```

## Reading Moving Photo Assets

Call [MovingPhoto.requestContent](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MovingPhoto.md#requestcontent12) to export the image and video of a moving photo to the application sandbox directory or read the image and video data from **ArrayBuffer**.

<!-- @[Reading_Moving_Photo_Assets](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/MediaLibraryKit/MovingPhotoSample/entry/src/main/ets/pages/Scene4.ets) -->

``` TypeScript
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';
// ...
@Entry({ routeName : 'Scene4' })
@Component
export struct Scene4 {
  @State movingPhotoObj: photoAccessHelper.MovingPhoto | null = null;
  @State statusMessage: string = '';
  // ...

  build() {
    NavDestination() {
      Column({ space: 20 }) {
        // ...
        Button('example')
          .width('80%')
          .height(50)
          .fontSize(16)
          .onClick(async () => {
            if (this.movingPhotoObj) {
              let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
              this.statusMessage = await example(this.movingPhotoObj, context);
            } else {
              this.statusMessage = 'Please prepare and load moving photo first!';
            }
          })
        // ...
      }
      .width('100%')
      .height('100%')
    }
    // ...
  }
}

async function example(movingPhoto: photoAccessHelper.MovingPhoto, context: Context): Promise<string> {
  try {
    let imageFileUri = context.filesDir + '/request_moving_photo.jpg';
    let videoFileUri = context.filesDir + '/request_moving_photo.mp4';
    await movingPhoto.requestContent(imageFileUri, videoFileUri);
    let imageData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.IMAGE_RESOURCE);
    let videoData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.VIDEO_RESOURCE);

    return 'Exported to:\n' + imageFileUri + '\n' + videoFileUri + '\n\nImage data size: ' + imageData.byteLength + ' bytes\nVideo data size: ' + videoData.byteLength + ' bytes';
  } catch (err) {
    console.error(`request content of moving photo failed with error: ${err.code}, ${err.message}`);
    return `request content of moving photo failed with error: ${err.code}, ${err.message}`;
  }
}
```