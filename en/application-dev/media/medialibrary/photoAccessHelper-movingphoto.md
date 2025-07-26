# Accessing and Managing Moving Photos

A moving photo is a photo form that combines an image and a video, empowering a static image with dynamic video effect. It helps users capture dynamic moment and improves the fault tolerance rate of photographing.

The media library provides the capabilities of accessing and managing moving photo assets, including:

- [Saving Moving Photo Assets](#saving-moving-photo-assets)
- [Obtaining a Moving Photo Object](#obtaining-a-moving-photo-object)
- [Playing Moving Photos with MovingPhotoView](movingphotoview-guidelines.md)
- [Reading Moving Photo Assets](#reading-moving-photo-assets)

Camera Kit provides the capability of taking moving photos. For details, see [Moving Photos](../camera/camera-moving-photo.md).

## Saving Moving Photo Assets

Use the **SaveButton** security component to save the assets (image and video) of a moving photo.

With the **SaveButton** security component, the application does not need the ohos.permission.WRITE_IMAGEVIDEO permission. When the user taps the button embedded with the **SaveButton** security component, the application obtains the temporary permission to save the assets to the specified media library directory.

For details, see [SaveButton](../../reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md).

**How to Develop**

1. Set the properties of the **SaveButton** security component.
2. Create a button with **SaveButton**.
3. Call [MediaAssetChangeRequest.createAssetRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#createassetrequest11) to create an asset change request with **PhotoSubtype** set to **MOVING_PHOTO**.
4. Call [MediaAssetChangeRequest.addResource](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11) to set the image and video of the moving photo. The video duration of the moving photo cannot exceed 10s.
   
   In the following example, the image and video of the moving photo are specified by **fileUri** of the [application file](../../file-management/app-file-access.md) in the application sandbox.
   
   You can also specify the assets in **ArrayBuffer**. For details, see [MediaAssetChangeRequest.addResource(type: ResourceType, data: ArrayBuffer)](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addresource11-1).

5. Call [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11) to apply changes for the moving photo.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'Hello World'
  @State saveButtonOptions: SaveButtonOptions = {
    icon: SaveIconStyle.FULL_FILLED,
    text: SaveDescription.SAVE_IMAGE,
    buttonType: ButtonType.Capsule
  } // Set properties of SaveButton.

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
        SaveButton(this.saveButtonOptions) // Create a button with SaveButton.
          .onClick(async (event, result: SaveButtonOnClickResult) => {
             if (result == SaveButtonOnClickResult.SUCCESS) {
               try {
                 let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
                 let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
                 // Ensure that the assets specified by imageFileUri and videoFileUri exist. imageFileUri and videoFileUri specify the image and video of the moving photo to create.
                 let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/create_moving_photo.jpg';
                 let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/create_moving_photo.mp4';
                 let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoAccessHelper.PhotoType.IMAGE, "jpg", {
                  title: "moving_photo",
                  subtype: photoAccessHelper.PhotoSubtype.MOVING_PHOTO
                 });
                 assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, imageFileUri);
                 assetChangeRequest.addResource(photoAccessHelper.ResourceType.VIDEO_RESOURCE, videoFileUri);
                 await phAccessHelper.applyChanges(assetChangeRequest);
                 console.info('create moving photo successfully, uri: ' + assetChangeRequest.getAsset().uri);
               } catch (err) {
                 console.error(`create moving photo failed with error: ${err.code}, ${err.message}`);
               }
             } else {
               console.error('SaveButtonOnClickResult create moving photo failed');
             }
          })
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

## Obtaining a Moving Photo Object

- Use **Picker** to obtain a moving photo object from the media library.

- Create a local moving photo object of the application by passing **fileUri** of an [application file](../../file-management/app-file-access.md) in the application sandbox.

After obtaining a moving photo object, you can use [MovingPhotoView](movingphotoview-guidelines.md) to play it.

### Obtaining a Moving Photo Object from the Media Library

1. Select the [URI of a media file](../../file-management/user-file-uri-intro.md#media-file-uri) by using **Picker**.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-1) and [FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1) to obtain the photo asset corresponding to the URI.
3. Call [MediaAssetManager.requestMovingPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestmovingphoto12) to obtain the moving photo object.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    // Use Picker to select the URI of the moving photo.
    let photoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    photoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.MOVING_PHOTO_IMAGE_TYPE;
    photoSelectOptions.maxSelectNumber = 9;
    let photoViewPicker = new photoAccessHelper.PhotoViewPicker();
    let photoSelectResult = await photoViewPicker.select(photoSelectOptions);
    let uris = photoSelectResult.photoUris;
    for (let i = 0; i < uris.length; i++) {
      // Obtain the photo asset corresponding to the URI.
      let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
      predicates.equalTo(photoAccessHelper.PhotoKeys.URI, uris[i]);
      let fetchOption: photoAccessHelper.FetchOptions = {
        fetchColumns: [],
        predicates: predicates
      };
      let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      // Obtain the moving photo object corresponding to the photo asset.
      await photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, photoAsset, {
        deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE
      }, {
        async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
          if (movingPhoto !== undefined) {
            // Customize the logic for processing the moving photo.
            console.info('request moving photo successfully, uri: ' + movingPhoto.getUri());
          }
        }
      })
    }
  } catch (err) {
    console.error(`request moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### Obtaining a Moving Photo object in an Application Sandbox Directory

Call [MediaAssetManager.loadMovingPhoto](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#loadmovingphoto12) to load the moving photo object in the application sandbox directory.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try {
    let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/local_moving_photo.jpg';
    let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/local_moving_photo.mp4';
    let movingPhoto = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
    console.info('load moving photo successfully');
  } catch (err) {
    console.error(`load moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## Reading Moving Photo Assets

Call [MovingPhoto.requestContent](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#requestcontent12) to export the image and video of a moving photo to the application sandbox directory or read the image and video data from **ArrayBuffer**.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(movingPhoto: photoAccessHelper.MovingPhoto) {
  try {
    let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/request_moving_photo.jpg';
    let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/request_moving_photo.mp4';
    await movingPhoto.requestContent(imageFileUri, videoFileUri); // Export the image and video of the moving photo to the application sandbox directory.
    let imageData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.IMAGE_RESOURCE); // Read ArrayBuffer to obtain the image data.
    let videoData = await movingPhoto.requestContent(photoAccessHelper.ResourceType.VIDEO_RESOURCE); // Read ArrayBuffer to obtain the video data.
  } catch (err) {
    console.error(`request content of moving photo failed with error: ${err.code}, ${err.message}`);
  }
}
```
