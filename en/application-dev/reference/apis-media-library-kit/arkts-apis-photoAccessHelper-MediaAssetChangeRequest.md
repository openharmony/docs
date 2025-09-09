# Class (MediaAssetChangeRequest)
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

MediaAssetChangeRequest implements [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11)

MediaAssetChangeRequest represents a media asset change request.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## constructor<sup>11+</sup>

constructor(asset: PhotoAsset)

Constructor used to initialize an asset change request.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| asset | [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md) | Yes  | Assets to change.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.          |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('MediaAssetChangeRequest constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
}
```

## createImageAssetRequest<sup>11+</sup>

static createImageAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest

Creates an image asset change request.

Use **fileUri** to specify the data source of the asset to be created. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| fileUri | string | Yes  | Data source of the image asset, which is specified by a URI in the application sandbox directory. Example: **'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg'**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAssetChangeRequest](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md) | **MediaAssetChangeRequest** created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900002   | The file corresponding to the URI is not in the app sandbox.         |
| 14000011   | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('createImageAssetRequestDemo');
  try {
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createImageAssetRequest(context, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply createImageAssetRequest successfully');
  } catch (err) {
    console.error(`createImageAssetRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## createVideoAssetRequest<sup>11+</sup>

static createVideoAssetRequest(context: Context, fileUri: string): MediaAssetChangeRequest

Creates a video asset change request.

Use **fileUri** to specify the data source of the asset to be created. For details, see [FileUri](../apis-core-file-kit/js-apis-file-fileuri.md).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| fileUri | string | Yes  | Data source of the video asset, which is specified by a URI in the application sandbox directory. Example: **'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4'**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAssetChangeRequest](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md) | **MediaAssetChangeRequest** created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900002   | The file corresponding to the URI is not in the app sandbox.         |
| 14000011   | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('createVideoAssetRequestDemo');
  try {
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.mp4';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createVideoAssetRequest(context, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply createVideoAssetRequest successfully');
  } catch (err) {
    console.error(`createVideoAssetRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## createAssetRequest<sup>11+</sup>

static createAssetRequest(context: Context, photoType: PhotoType, extension: string, options?: CreateOptions): MediaAssetChangeRequest

Create an asset change request based on the file type and filename extension.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **'jpg'**.             |
| options  | [CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions)        | No  | Options for creating the image or video asset, for example, **{title: 'testPhoto'}**.<br>The file name must not contain any invalid characters, which are:.. \ / : * ? " ' ` < > \| { } [ ]|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAssetChangeRequest](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md) | **MediaAssetChangeRequest** created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('createAssetRequestDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let options: photoAccessHelper.CreateOptions = {
      title: 'testPhoto'
    }
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension, options);
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply createAssetRequest successfully');
  } catch (err) {
    console.error(`createAssetRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## deleteAssets<sup>11+</sup>

static deleteAssets(context: Context, assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Deletes media assets. This API uses a promise to return the result. The deleted assets are moved to the trash.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| assets | Array&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt; | Yes  | Array of media assets to delete. The array can contain a maximum of 300 elements. <!--Del-->System applications are not subject to this limitation.<!--DelEnd--> |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 |  System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('deleteAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, photoAssetList);
    console.info('deleteAssets successfully');
  } catch (err) {
    console.error(`deleteAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## deleteAssets<sup>11+</sup>

static deleteAssets(context: Context, uriList: Array&lt;string&gt;): Promise&lt;void&gt;

Deletes media assets. This API uses a promise to return the result. The deleted assets are moved to the trash.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| uriList | Array&lt;string&gt; | Yes  | URIs of the media assets to delete. The array can contain a maximum of 300 elements. <!--Del-->System applications are not subject to this limitation.<!--DelEnd--> |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000002 |  The uri format is incorrect or does not exist.         |
| 14000011 |  System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('deleteAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [asset.uri]);
    console.info('deleteAssets successfully');
  } catch (err) {
    console.error(`deleteAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## getAsset<sup>11+</sup>

getAsset(): PhotoAsset

Obtains the asset in this asset change request.

**NOTE**: For the change request used to create an asset, this API returns **null** before [applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) is called to apply the changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md) | Asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011 |  System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('getAssetDemo');
  try {
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createImageAssetRequest(context, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    let asset: photoAccessHelper.PhotoAsset = assetChangeRequest.getAsset();
    console.info('create asset successfully with uri = ' + asset.uri);
  } catch (err) {
    console.error(`getAssetDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## setTitle<sup>11+</sup>

setTitle(title: string): void

Sets the media asset title.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| title | string | Yes  | Title to set.|

The title must meet the following requirements:
- It must not contain a file name extension.
- The total length of the file name must be between 1 and 255 characters.
- It must not contain any invalid characters, which are:<br> . \ / : * ? " ' ` < > | { } [ ]

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setTitleDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  let newTitle: string = 'newTitle';
  assetChangeRequest.setTitle(newTitle);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setTitle successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setTitle failed with error: ${err.code}, ${err.message}`);
  });
}
```

## getWriteCacheHandler<sup>11+</sup>

getWriteCacheHandler(): Promise&lt;number&gt;

Obtains the handler used for writing a file to cache.

**NOTE**: For the same asset change request, this API cannot be repeatedly called after a temporary file write handle is successfully obtained.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the write handle obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011 |  System inner fail.        |
| 14000016 |  Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { fileIo } from '@kit.CoreFileKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('getWriteCacheHandlerDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.VIDEO;
    let extension: string = 'mp4';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension);
    let fd: number = await assetChangeRequest.getWriteCacheHandler();
    console.info('getWriteCacheHandler successfully');
    // write date into fd..
    await fileIo.close(fd);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error(`getWriteCacheHandlerDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## addResource<sup>11+</sup>

addResource(type: ResourceType, fileUri: string): void

Adds a resource using [fileUri](../apis-core-file-kit/js-apis-file-fileuri.md).

**NOTE**: For the same asset change request, this API cannot be repeatedly called after the resource is successfully added. For a moving photo, you can call this API twice to add the image and video resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| type | [ResourceType](arkts-apis-photoAccessHelper-e.md#resourcetype11) | Yes  | Type of the resource to add.|
| fileUri | string | Yes  | Data source of the resource to be added, which is specified by a URI in the application sandbox directory. Example: **'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900002      |  The file corresponding to the URI is not in the app sandbox.   |
| 14000011 |  System inner fail.         |
| 14000016 |  Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('addResourceByFileUriDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension);
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('addResourceByFileUri successfully');
  } catch (err) {
    console.error(`addResourceByFileUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## addResource<sup>11+</sup>

addResource(type: ResourceType, data: ArrayBuffer): void

Adds a resource using **ArrayBuffer** data.

**NOTE**: For the same asset change request, this API cannot be repeatedly called after the resource is successfully added. For a moving photo, you can call this API twice to add the image and video resources.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| type | [ResourceType](arkts-apis-photoAccessHelper-e.md#resourcetype11) | Yes  | Type of the resource to add.|
| data | ArrayBuffer | Yes  | Data of the resource to add.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 |  System inner fail.         |
| 14000016 |  Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('addResourceByArrayBufferDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension);
    let buffer: ArrayBuffer = new ArrayBuffer(2048);
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, buffer);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('addResourceByArrayBuffer successfully');
  } catch (err) {
    console.error(`addResourceByArrayBufferDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## saveCameraPhoto<sup>12+</sup>

saveCameraPhoto(): void

Saves the photo taken by the camera.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 14000011 |  System inner fail.         |
| 14000016 |  Operation Not Support.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset) {
  console.info('saveCameraPhotoDemo');
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.saveCameraPhoto();
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply saveCameraPhoto successfully');
  } catch (err) {
    console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
  }
}
```

## saveCameraPhoto<sup>13+</sup>

saveCameraPhoto(imageFileType: ImageFileType): void

Saves the photo taken by the camera.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| imageFileType | [ImageFileType](arkts-apis-photoAccessHelper-e.md#imagefiletype13)  | Yes  | File type of the photo to save.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 14000011 |  System inner fail.         |
| 14000016 |  Operation Not Support.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(context: Context, asset: photoAccessHelper.PhotoAsset) {
  console.info('saveCameraPhotoDemo');
  try {
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.saveCameraPhoto(photoAccessHelper.ImageFileType.JPEG);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply saveCameraPhoto successfully');
  } catch (err) {
    console.error(`apply saveCameraPhoto failed with error: ${err.code}, ${err.message}`);
  }
}
```

## discardCameraPhoto<sup>12+</sup>

discardCameraPhoto(): void

Discards the photo taken by the camera.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 14000011 |  Internal system error.         |
| 14000016 |  Operation Not Support.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset) {
  console.info('discardCameraPhotoDemo');
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.discardCameraPhoto();
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply discardCameraPhoto successfully');
  } catch (err) {
    console.error(`apply discardCameraPhoto failed with error: ${err.code}, ${err.message}`);
  }
}
```

## setOrientation<sup>15+</sup>

setOrientation(orientation: number): void

Sets the orientation of this image.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| orientation | number | Yes  | Rotation angle of the image to set. The value can only be **0**, **90**, **180**, or **270**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 |  Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setOrientationDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  assetChangeRequest.setOrientation(90);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setOrientation successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setOrientation failed with error: ${err.code}, ${err.message}`);
  });
}
```
