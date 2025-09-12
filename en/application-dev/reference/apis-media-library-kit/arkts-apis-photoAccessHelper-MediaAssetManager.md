# Class (MediaAssetManager)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this class are supported since API version 11.

The MediaAssetManager class is used for manipulating the read and write operations of media assets.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## requestImage<sup>11+</sup>

static requestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;image.ImageSource&gt;): Promise&lt;string&gt;

Requests an image.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

- When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).
- For the media assets saved to the media library by this application, the application can access them without the ohos.permission.READ_IMAGEVIDEO permission.

**Parameters**

| Name           | Type                                                                                                       | Mandatory| Description                     |
|----------------|-----------------------------------------------------------------------------------------------------------| ---- | ------------------------- |
| context        | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                                                           | Yes  | Context of the ability instance.|
| asset         | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                                                                | Yes  | Image to request.|
| requestOptions | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                                                        | Yes  | Options for requesting the image.|
| dataHandler    | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;[image.ImageSource](../apis-image-kit/arkts-apis-image-ImageSource.md)&gt; | Yes  | Media asset handler, which invokes a callback to return the image when the requested image is ready.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise used to return the request ID, which can be used in [cancelRequest](#cancelrequest12) to cancel a request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.MediaAssetDataHandler<image.ImageSource> {
  onDataPrepared(data: image.ImageSource) {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info('on image data prepared');
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestImage');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaHandler();

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestImage(context, photoAsset, requestOptions, handler);
      console.info('requestImage successfully');
  });
}
```

## requestImageData<sup>11+</sup>

static requestImageData(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;ArrayBuffer&gt;): Promise&lt;string&gt;

Requests image data.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

- When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).
- For the media assets saved to the media library by this application, the application can access them without the ohos.permission.READ_IMAGEVIDEO permission.

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | Yes  | Context of the ability instance.|
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | Yes  | Image to request.|
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | Yes  | Options for requesting the image.|      
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;ArrayBuffer&gt; | Yes  | Media asset handler, which invokes a callback to return the image when the requested image is ready.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise used to return the request ID, which can be used in [cancelRequest](#cancelrequest12) to cancel a request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<ArrayBuffer> {
  onDataPrepared(data: ArrayBuffer) {
    if (data === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info('on image data prepared');
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestImageData');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaDataHandler();

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestImageData(context, photoAsset, requestOptions, handler);
      console.info('requestImageData successfully');
  });
}
```

## requestMovingPhoto<sup>12+</sup>

static requestMovingPhoto(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: MediaAssetDataHandler&lt;MovingPhoto&gt;): Promise&lt;string&gt;

Requests a moving photo object, which can be used to request the asset data of the moving photo.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

- When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).
- For the moving photos saved to the media library by this application, the application can access them without the ohos.permission.READ_IMAGEVIDEO permission.

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | Yes  | Context of the ability instance.|
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | Yes  | Image to request.|
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | Yes  | Options for requesting the image.|       
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;[MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md)&gt; | Yes  | Media asset handler, which invokes a callback to return the image when the requested image is ready.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise used to return the request ID, which can be used in [cancelRequest](#cancelrequest12) to cancel a request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 801   | Capability not supported.       |
| 14000011       | System inner fail         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MovingPhotoHandler implements photoAccessHelper.MediaAssetDataHandler<photoAccessHelper.MovingPhoto> {
  async onDataPrepared(movingPhoto: photoAccessHelper.MovingPhoto) {
    if (movingPhoto === undefined) {
      console.error('Error occurred when preparing data');
      return;
    }
    console.info("moving photo acquired successfully, uri: " + movingPhoto.getUri());
  }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.PHOTO_SUBTYPE, photoAccessHelper.PhotoSubtype.MOVING_PHOTO);
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  // Ensure that there are moving photos in Gallery.
  let assetResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let asset: photoAccessHelper.PhotoAsset = await assetResult.getFirstObject();
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.FAST_MODE,
  }
  const handler = new MovingPhotoHandler();
  try {
    let requestId: string = await photoAccessHelper.MediaAssetManager.requestMovingPhoto(context, asset, requestOptions, handler);
    console.info("moving photo requested successfully, requestId: " + requestId);
  } catch (err) {
    console.error(`failed to request moving photo, error code is ${err.code}, message is ${err.message}`);
  }
}

```

## requestVideoFile<sup>12+</sup>

static requestVideoFile(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, fileUri: string, dataHandler: MediaAssetDataHandler&lt;boolean&gt;): Promise&lt;string&gt;

Requests a video and saves it to the specified sandbox directory.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

- When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).
- For the videos saved to the media library by this application, the application can access them without the ohos.permission.READ_IMAGEVIDEO permission.

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | Yes  | Context of the ability instance.|
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                            | Yes  | Image to request.|
| requestOptions  | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                  | Yes  | Options for requesting the video asset.|
| fileUri| string                                                              | Yes| URI of the sandbox directory, to which the requested video asset is to be saved. Example: **'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4'**.|
| dataHandler  | [MediaAssetDataHandler](arkts-apis-photoAccessHelper-MediaAssetDataHandler.md)&lt;boolean&gt; | Yes  | Media asset handler. When the requested video is written to the specified directory, a callback is triggered.<br>If the video is successfully written, **true** is returned. Otherwise, **false** is returned.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise used to return the request ID, which can be used in [cancelRequest](#cancelrequest12) to cancel a request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 801<sup>15+</sup>   | Capability not supported.       |
| 14000011       | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

class MediaDataHandler implements photoAccessHelper.MediaAssetDataHandler<boolean> {
    onDataPrepared(data: boolean) {
        console.info('on video request status prepared');
    }
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestVideoFile');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaDataHandler();
  let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4';
  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.requestVideoFile(context, photoAsset, requestOptions, fileUri, handler);
      console.info('requestVideoFile successfully');
  });
}
```

## cancelRequest<sup>12+</sup>

static cancelRequest(context: Context, requestId: string): Promise\<void>

Cancels a request for the asset, the callback of which has not been triggered yet.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                      | Yes  | Context of the ability instance.|
| requestId | string     | Yes  | ID of the request to cancel. It is a valid request ID returned by **requestImage**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
  try {
    let requestId: string = 'xxx-xxx'; // A valid requestId returned by APIs such as requestImage() must be used.
    await photoAccessHelper.MediaAssetManager.cancelRequest(context, requestId);
    console.info("request cancelled successfully");
  } catch (err) {
    console.error(`cancelRequest failed with error: ${err.code}, ${err.message}`);
  }
}

```

## loadMovingPhoto<sup>12+</sup>

static loadMovingPhoto(context: Context, imageFileUri: string, videoFileUri: string): Promise\<MovingPhoto>

Loads a moving photo in the application sandbox.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md)   | Yes  | AbilityContext or UIExtensionContext instance.|
| imageFileUri | string     | Yes  | URI of the image file of the moving photo in the application sandbox.<br>Example: **'file://com.example.temptest/data/storage/el2/base/haps/ImageFile.jpg'**.|
| videoFileUri | string     | Yes  | URI of the video file of the moving photo in the application sandbox.<br>Example: **'file://com.example.temptest/data/storage/el2/base/haps/VideoFile.mp4'**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<MovingPhoto> | Promise used to return the [MovingPhoto](arkts-apis-photoAccessHelper-MovingPhoto.md) instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. |

**Example**

```ts
async function example(context: Context) {
  try {
    let imageFileUri: string = 'file://com.example.temptest/data/storage/el2/base/haps/ImageFile.jpg'; // URI of the image file of the moving photo in the application sandbox.
    let videoFileUri: string = 'file://com.example.temptest/data/storage/el2/base/haps/VideoFile.mp4'; // URI of the video file of the moving photo in the application sandbox.
    let movingPhoto: photoAccessHelper.MovingPhoto = await photoAccessHelper.MediaAssetManager.loadMovingPhoto(context, imageFileUri, videoFileUri);
  } catch (err) {
    console.error(`loadMovingPhoto failed with error: ${err.code}, ${err.message}`);
  }
}

```

## quickRequestImage<sup>13+</sup>

static quickRequestImage(context: Context, asset: PhotoAsset, requestOptions: RequestOptions, dataHandler: QuickImageDataHandler&lt;image.Picture&gt;): Promise&lt;string&gt;

Requests an image quickly.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

- When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).

**Parameters**

| Name           | Type                                                                                                       | Mandatory| Description                     |
|----------------|-----------------------------------------------------------------------------------------------------------| ---- | ------------------------- |
| context        | [Context](../apis-ability-kit/js-apis-inner-application-context.md)                                                           | Yes  | Context of the ability instance.|
| asset         | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)                                                                                | Yes  | Image to request.|
| requestOptions | [RequestOptions](arkts-apis-photoAccessHelper-i.md#requestoptions11)                                                                        | Yes  | Options for requesting the image.|
| dataHandler    | [QuickImageDataHandler](arkts-apis-photoAccessHelper-QuickImageDataHandler.md)&lt;[image.Picture](../apis-image-kit/arkts-apis-image-Picture.md)&gt; | Yes  | Media asset handler, which invokes a callback to return the image when the requested image is ready.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<string> | Promise used to return the request ID, which can be used in [cancelRequest](#cancelrequest12) to cancel a request.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

class MediaHandler implements photoAccessHelper.QuickImageDataHandler<image.Picture> {
  onDataPrepared(data: image.Picture, imageSource: image.ImageSource, map: Map<string, string>) {
    console.info('on image data prepared');
  }
}

async function example(context: Context) {
  console.info('quickRequestImage');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let requestOptions: photoAccessHelper.RequestOptions = {
    deliveryMode: photoAccessHelper.DeliveryMode.HIGH_QUALITY_MODE,
  }
  const handler = new MediaHandler();
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      await photoAccessHelper.MediaAssetManager.quickRequestImage(context, photoAsset, requestOptions, handler);
      console.info('quickRequestImage successfully');
  });
}
```
