# Managing Media Assets
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

Applications can call photoAccessHelper APIs to manage media assets (images and videos).

> **NOTE**
>
> - Before you get started, obtain a PhotoAccessHelper instance and apply for required permissions. For details, see [Before You Start](photoAccessHelper-preparation.md).
>
> - Unless otherwise specified, the PhotoAccessHelper instance obtained in [Before You Start](photoAccessHelper-preparation.md) is used to call photoAccessHelper APIs. If the code for obtaining the PhotoAccessHelper instance is missing, an error will be reported to indicate that photoAccessHelper is not defined.

To ensure application running efficiency, most PhotoAccessHelper APIs are asynchronously implemented in callback or promise mode. The following examples use promise-based APIs. For details about the APIs, see [Module Description](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md).

## Obtaining Media Assets

You can obtain media assets based on the specified conditions, such as the media type, date, or album name.

Use [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) with the [FetchOptions](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-i.md#fetchoptions) object to specify the search criteria. Unless otherwise specified, all the media assets to be obtained in this document exist in the database. If no media asset is obtained, check whether the media assets exist in the database.

> **NOTICE**
>
> When [PhotoAccessHelper.PhotoKeys.URI](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-e.md#photokeys) is used as the search criterion, only the [DataSharePredicates.equalTo](../../reference/apis-arkdata/js-apis-data-dataSharePredicates.md#equalto10) API is supported.

To obtain the object at the specified position (for example, the first one, the last one, or the one with the specified index) in the result set, use [FetchResult](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md).

**Prerequisites**

- A PhotoAccessHelper instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).
- The [dataSharePredicates](../../reference/apis-arkdata/js-apis-data-dataSharePredicates.md) module is imported.

### Obtaining an Image or Video by Name

Example: Obtain the image **test.jpg**.

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    fetchResult.close();
  } catch (err) {
    console.error('getAssets failed with err: ' + err);
  }
}
```

## Obtaining an Image or Video Thumbnail

To display images and videos in Gallery or to preview edits, applications must obtain image and video thumbnails.

The thumbnails offer a quick preview on images and videos. You can use [PhotoAsset.getThumbnail](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAsset.md#getthumbnail-2) with the thumbnail size specified to obtain the image or video thumbnail.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).
- The [dataSharePredicates](../../reference/apis-arkdata/js-apis-data-dataSharePredicates.md) module is imported.

For example, obtain the file descriptor (FD) of an image, and decode the image into a PixelMap for display or processing. For details, see [Image Decoding](../image/image-decoding.md).

Example: Obtain the thumbnail at the size of 720 x 720 of an image.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1) to obtain the first image from the result set.
4. Call **PhotoAsset.getThumbnail** to obtain the [PixelMap](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) of the thumbnail of the image.

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.displayName : ' + photoAsset.displayName);
    let size: image.Size = { width: 720, height: 720 };
    let pixelMap: image.PixelMap =  await photoAsset.getThumbnail(size);
    let imageInfo: image.ImageInfo = await pixelMap.getImageInfo()
    console.info('getThumbnail successful, pixelMap ImageInfo size: ' + JSON.stringify(imageInfo.size));
    fetchResult.close();
  } catch (err) {
    console.error('getThumbnail failed with err: ' + err);
  }
}
```

<!--Del-->
## Creating a Media Asset

Use [MediaAssetChangeRequest](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md) to create a media asset change request object for a media asset, and use [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) to apply the changes.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.
- The application has the ohos.permission.WRITE_IMAGEVIDEO permission. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

### Creating an Image or Video Asset (for System Applications Only)

Example: Create an image asset.

**How to Develop**

1. Set the file name and **createOption** for setting attributes for the image asset to create.
2. Call **MediaAssetChangeRequest.createAssetRequest** to create a media asset change request object.
3. Call **MediaAssetChangeRequest.getWriteCacheHandler** to obtain the handle of the file to write and write the content of the image asset.
4. Call **PhotoAccessHelper.applyChanges** to apply the changes to the image.

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { fileIo } from '@kit.CoreFileKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  try {
    let displayName: string = 'testPhoto' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    };
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, displayName, createOption);
    let fd: number = await assetChangeRequest.getWriteCacheHandler();
    // write date into fd.
    await fileIo.close(fd);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error(`create asset failed with error: ${err.code}, ${err.message}`);
  }
}
```

You can also use **MediaAssetChangeRequest.addResource** to specify the data source information of the media asset, including the [application sandbox](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#addresource11), [ArrayBuffer](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#addresource11-1), and [PhotoProxy](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#addresource11).
<!--DelEnd-->

## Renaming a Media Asset

To rename a media asset, change the **PhotoAsset.displayName** attribute, that is, the file name (including the file name extension) displayed.

Use [FetchResult](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md) to obtain the file to rename, use [MediaAssetChangeRequest.setTitle](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#settitle11) to set the new name, and then use [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) to apply the changes to the database.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Rename the first image in the obtained image assets.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1) to obtain the first image from the obtained file assets.
4. Call [MediaAssetChangeRequest.setTitle](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#settitle11) to rename the image.
5. Call [PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) to save the modification to the database.

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let newTitle: string = 'newTestPhoto';

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    assetChangeRequest.setTitle(newTitle);
    await phAccessHelper.applyChanges(assetChangeRequest);
    fetchResult.close();
  } catch (err) {
    console.error(`rename failed with error: ${err.code}, ${err.message}`);
  }
}
```

## Moving a Media Asset to the Trash

You can use [MediaAssetChangeRequest.deleteAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11) to move files to the trash.

The file moved to the trash will be retained for 30 days before being deleted permanently. Before a file is deleted permanently from the trash, the user can restore it using the system application **Files** or **Gallery**.

**Prerequisites**

- A PhotoAccessHelper instance is obtained.
- The application has the ohos.permission.READ_IMAGEVIDEO and ohos.permission.WRITE_IMAGEVIDEO permissions. For details, see [Requesting Permissions](photoAccessHelper-preparation.md#requesting-permissions).

Example: Move the first file in the result set to the trash.

**How to Develop**

1. Set the fetch options.
2. Call [PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getassets-1) to obtain image assets.
3. Call [FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1) to obtain the first image.
4. Call [MediaAssetChangeRequest.deleteAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11) to move the image to the trash.

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    fetchResult.close();
  } catch (err) {
    console.error(`deleteAssets failed with error: ${err.code}, ${err.message}`);
  }
}
```
