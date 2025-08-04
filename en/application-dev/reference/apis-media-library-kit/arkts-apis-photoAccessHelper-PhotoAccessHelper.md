# Interface (PhotoAccessHelper)

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## getAssets

getAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;PhotoAsset&gt;&gt;): void

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)        | Yes  | Retrieval options.             |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | Yes  | Callback used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName : ' + photoAsset.displayName);
      }
    } else {
      console.error(`fetchResult fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

## getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains image and video assets. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

When you call this API in Picker mode, you do not need to request the ohos.permission.READ_IMAGEVIDEO permission. For details, see [Obtaining an Image or Video by URI](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#obtaining-an-image-or-video-by-uri).

**Parameters**

| Name | Type               | Mandatory| Description            |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)   | Yes  | Retrieval options.    |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error(`getAssets failed, error: ${err.code}, ${err.message}`);
  }
}
```

## getBurstAssets<sup>12+</sup>

getBurstAssets(burstKey: string, options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains burst assets. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 20.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type               | Mandatory| Description            |
| ------- | ------------------- | ---- | ---------------- |
| burstKey | string   | Yes  | UUID of a set of burst photos ( **BURST_KEY** of [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)). The value is a string of 36 characters.|
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)   | Yes  | Retrieval options.    |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.         |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getBurstAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  // burstKey is a 36-bit UUID, which can be obtained from photoAccessHelper.PhotoKeys.
  let burstKey: string = "e719d696-09fa-44f8-8e9e-ec3f215aa62a";
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await 
      phAccessHelper.getBurstAssets(burstKey, fetchOptions);
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error(`getBurstAssets failed, error: ${err.code}, ${err.message}`);
  }
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, options: CreateOptions, callback: AsyncCallback&lt;string&gt;): void

Creates an image or video asset with the specified file type, file name extension, and options. This API uses an asynchronous callback to return the result.

If you do not have the ohos.permission.WRITE_IMAGEVIDEO permission, you can create a media asset by using a security component. For details, see [Creating a Media Asset Using a Security Component](../../media/medialibrary/photoAccessHelper-savebutton.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **'jpg'**.             |
| options  | [CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions)        | Yes  | Options used for creation. Currently, only **title** is supported, for example, **{title: 'testPhoto'}**.<br>**NOTE**: If other options are passed, the configuration does not take effect.     |
| callback |  AsyncCallback&lt;string&gt; | Yes  | Callback used to return the URI of the created image or video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension:string = 'jpg';
  let options: photoAccessHelper.CreateOptions = {
    title: 'testPhoto'
  }
  phAccessHelper.createAsset(photoType, extension, options, (err, uri) => {
    if (uri !== undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, callback: AsyncCallback&lt;string&gt;): void

Creates an image or video asset with the specified file type and file name extension. This API uses an asynchronous callback to return the result.

If you do not have the ohos.permission.WRITE_IMAGEVIDEO permission, you can create a media asset by using a security component. For details, see [Creating a Media Asset Using a Security Component](../../media/medialibrary/photoAccessHelper-savebutton.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **'jpg'**.             |
| callback |  AsyncCallback&lt;string&gt; | Yes  | Callback used to return the URI of the created image or video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension: string = 'jpg';
  phAccessHelper.createAsset(photoType, extension, (err, uri) => {
    if (uri !== undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, options?: CreateOptions): Promise&lt;string&gt;

Creates an image or video asset with the specified file type, file name extension, and options. This API uses a promise to return the result.

If you do not have the ohos.permission.WRITE_IMAGEVIDEO permission, you can create a media asset by using a security component. For details, see [Creating a Media Asset Using a Security Component](../../media/medialibrary/photoAccessHelper-savebutton.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **'jpg'**.             |
| options  | [CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions)        | No  | Options used for creation. Currently, only **title** is supported, for example, **{title: 'testPhoto'}**.<br>**NOTE**: If other options are passed, the configuration does not take effect.     |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the created image or video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let options: photoAccessHelper.CreateOptions = {
      title: 'testPhoto'
    }
    let uri: string = await phAccessHelper.createAsset(photoType, extension, options);
    console.info('createAsset uri' + uri);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums based on the specified options and album type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | Yes  | Type of the album.             |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | Yes  |  Retrieval options.             |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions, async (err, fetchResult) => {
    if (err) {
      console.error(`getAlbumsCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    if (fetchResult === undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums by type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | Yes  | Type of the album.             |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | Yes  | Subtype of the album.             |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

In API version 13 and earlier versions, if the caller does not have the required permission, error code 13900012 is returned. Starting from API version 14, the same situation raises error code 201.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  // Obtain the system album VIDEO, which is preset by default.
  console.info('getAlbumsDemo');
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO, async (err, fetchResult) => {
    if (err) {
      console.error(`getAlbumsCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    if (fetchResult === undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains albums based on the specified options and album type. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | Yes  | Type of the album.             |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | No  |  Retrieval options. If this parameter is not specified, the albums are obtained based on the album type by default.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

## registerChange

registerChange(uri: string, forChildUris: boolean, callback: Callback&lt;ChangeData&gt;) : void

Registers listening for the specified URI. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type                                       | Mandatory| Description                                                        |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | Yes  | URI of the photo asset, URI of the album, or [DefaultChangeUri](arkts-apis-photoAccessHelper-e.md#defaultchangeuri).|
| forChildUris | boolean                                     | Yes  | Whether to perform fuzzy listening.<br>If **uri** is the URI of an album, the value **true** means to listen for the changes of the files in the album; the value **false** means to listen for the changes of the album only.<br>If **uri** is the URI of a photoAsset, there is no difference between **true** and false for **forChildUris**.<br>If **uri** is **DefaultChangeUri**, **forChildUris** must be set to **true**. If **forChildUris** is false, the URI cannot be found and no message can be received.|
| callback  | Callback&lt;[ChangeData](arkts-apis-photoAccessHelper-i.md#changedata)&gt; | Yes  | Callback used to return [ChangeData](arkts-apis-photoAccessHelper-i.md#changedata). <br>**NOTE**<br>Multiple callback listeners can be registered for a URI. You can use [unRegisterChange](#unregisterchange) to unregister all listeners for the URI or a specified callback listener.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('registerChangeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset !== undefined) {
    console.info('photoAsset.displayName : ' + photoAsset.displayName);
  }
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something.
  }
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something.
  }
  // Register onCallback1.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
  // Register onCallback2.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);

  await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
}
```

## unRegisterChange

unRegisterChange(uri: string, callback?: Callback&lt;ChangeData&gt;): void

Unregisters listening for the specified URI. Multiple callbacks can be registered for a URI for listening. You can use this API to unregister the listening of the specified callbacks or all callbacks.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | Yes  | URI of the photo asset, URI of the album, or [DefaultChangeUri](arkts-apis-photoAccessHelper-e.md#defaultchangeuri).|
| callback | Callback&lt;[ChangeData](arkts-apis-photoAccessHelper-i.md#changedata)&gt; | No  | Callback to unregister. If this parameter is not specified, all the callbacks for listening for the URI will be canceled. <br>**NOTE**: The specified callback unregistered will not be invoked when the data changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('offDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset !== undefined) {
    console.info('photoAsset.displayName : ' + photoAsset.displayName);
  }
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback2 on');
  }
  // Register onCallback1.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
  // Register onCallback2.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);
  // Unregister the listening of onCallback1.
  phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);
  await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
}
```

## applyChanges<sup>11+</sup>

applyChanges(mediaChangeRequest: MediaChangeRequest): Promise&lt;void&gt;

Applies media changes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

When you create a media asset by using a security component, you do not need to request the ohos.permission.WRITE_IMAGEVIDEO permission to call this API. For details, see [Creating a Media Asset Using a Security Component](../../media/medialibrary/photoAccessHelper-savebutton.md).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| mediaChangeRequest  | [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11)  | Yes |  Request for asset changes or album changes.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011  | System inner fail.     |

**Example**

This API depends on the [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11) object. For details about the sample code, see the examples of [MediaAssetChangeRequest](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md) and [MediaAlbumChangeRequest](arkts-apis-photoAccessHelper-MediaAlbumChangeRequest.md).

## release

release(callback: AsyncCallback&lt;void&gt;): void

Releases this PhotoAccessHelper instance. This API uses an asynchronous callback to return the result.

Call this API when the APIs of the PhotoAccessHelper instance are no longer used.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('releaseDemo');
  phAccessHelper.release((err) => {
    if (err !== undefined) {
      console.error(`release failed. error: ${err.code}, ${err.message}`);
    } else {
      console.info('release ok.');
    }
  });
}
```

## release

release(): Promise&lt;void&gt;

Releases this PhotoAccessHelper instance. This API uses a promise to return the result.

Call this API when the APIs of the PhotoAccessHelper instance are no longer used.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('releaseDemo');
  try {
    await phAccessHelper.release();
    console.info('release ok.');
  } catch (err) {
    console.error(`release failed. error: ${err.code}, ${err.message}`);
  }
}
```

## showAssetsCreationDialog<sup>12+</sup>

showAssetsCreationDialog(srcFileUris: Array&lt;string&gt;, photoCreationConfigs: Array&lt;PhotoCreationConfig&gt;): Promise&lt;Array&lt;string&gt;&gt;

Shows the dialog box for the user to confirm whether to save the photos or videos. If the user agrees to save the images or videos, a list of URIs granted with the save permission is returned. The list takes effect permanently, and the application can write the images or videos based on the URIs. If the user refuses to save the images or videos, an empty list is returned. To display the application name in the dialog box, the API relies on the configuration of **label** and **icon** under **abilities** in the **module.json5** file. If they are not configured, no application name is displayed in the dialog box.

> **NOTE**
>
> If the passed URI is a sandbox path, photos or videos can be saved but cannot be previewed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| srcFileUris | Array&lt;string&gt; | Yes| [URIs](../../file-management/user-file-uri-intro.md#media-file-uri) of the images or videos to be saved to the media library.<br>**NOTE**<br>- A maximum of 100 images can be saved at a time.<br>- Only image and video URIs are supported.<br>- URIs cannot be manually constructed. You must call APIs to obtain them. For details, see [Obtaining a Media File URI](../../file-management/user-file-uri-intro.md#obtaining-a-media-file-uri). |
| photoCreationConfigs | Array&lt;[PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)&gt; | Yes| Configuration for saving the images or videos, including the file names. The value must be consistent with that of **srcFileUris**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return a URI list. The URIs are granted with the permission for the application to write data. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('ShowAssetsCreationDialogDemo.');

  try {
    // Obtain the sandbox URIs of the images or videos to be saved to the media library.
    let srcFileUris: Array<string> = [
      'file://fileUriDemo1' // The URI here is an example only.
    ];
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test2', // Optional.
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT, // This parameter is optional.
      }
    ];
    let desFileUris: Array<string> = await phAccessHelper.showAssetsCreationDialog(srcFileUris, photoCreationConfigs);
    console.info('showAssetsCreationDialog success, data is ' + desFileUris);
  } catch (err) {
    console.error('showAssetsCreationDialog failed, errCode is ' + err.code + ', errMsg is ' + err.message);
  }
}
```

## createAssetWithShortTermPermission<sup>12+</sup>

createAssetWithShortTermPermission(photoCreationConfig: PhotoCreationConfig): Promise&lt;string&gt;

Creates an asset with a temporary permission of the given period. When this API is called by an application for the first time, a dialog box will be displayed for the user to confirm whether to save the asset. If the user agrees to save the asset, the asset instance will be created and the file URI granted with the save permission will be returned. The application can write the asset based on the URI
within 5 minutes after the user agrees to save the asset. If the same application calls this API again within the 5 minutes, the authorized URI can be automatically returned without the need to display the conformation dialog box.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| photoCreationConfig | [PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12); | Yes| Configuration for saving a media asset (image or video) to the media library, including the file name.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the asset saved. The URIs are granted with the permission for the application to write data. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { fileIo } from '@kit.CoreFileKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
    console.info('createAssetWithShortTermPermissionDemo.');
    
    try {
        let photoCreationConfig: photoAccessHelper.PhotoCreationConfig = {
            title: '123456', 
            fileNameExtension: 'jpg',
            photoType: photoAccessHelper.PhotoType.IMAGE,
            subtype: photoAccessHelper.PhotoSubtype.DEFAULT, 
        };

        let resultUri: string = await phAccessHelper.createAssetWithShortTermPermission(photoCreationConfig);
        let resultFile: fileIo.File = fileIo.openSync(resultUri, fileIo.OpenMode.READ_WRITE);
        // Use the actual URI and file size.
        let srcFile:  fileIo.File = fileIo.openSync("file://test.jpg", fileIo.OpenMode.READ_ONLY);
        let bufSize: number = 2000000;
        let readSize: number = 0;
        let buf = new ArrayBuffer(bufSize);
        let readLen = fileIo.readSync(srcFile.fd, buf, {
            offset: readSize,
            length: bufSize
        });
        if (readLen > 0) {
            readSize += readLen;
            fileIo.writeSync(resultFile.fd, buf, { length: readLen });
        }
        fileIo.closeSync(srcFile);
        fileIo.closeSync(resultFile);
    } catch (err) {
        console.error('createAssetWithShortTermPermission failed, errCode is ' + err.code + ', errMsg is ' + err.message);
    }
    
}
```

## requestPhotoUrisReadPermission<sup>14+</sup>

requestPhotoUrisReadPermission(srcFileUris: Array&lt;string&gt;): Promise&lt;Array&lt;string&gt;&gt;

<!--RP1--><!--RP1End-->Grants the save permission for URIs. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 14.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| srcFileUris | Array&lt;string&gt; | Yes| [URIs](../../file-management/user-file-uri-intro.md#media-file-uri) of the images or videos to be granted with the permission.<br>**NOTE**: Only image and video URIs are supported.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs granted with the save permission.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestPhotoUrisReadPermissionDemo.');

  try {
    let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    // Obtain the URIs of the images or videos to be granted with the permission.
    let srcFileUris: Array<string> = [
      'file://fileUriDemo1' // The URI here is an example only.
    ];
    let desFileUris: Array<string> = await phAccessHelper.requestPhotoUrisReadPermission(srcFileUris);
    console.info('requestPhotoUrisReadPermission success, data is ' + desFileUris);
  } catch (err) {
    console.error('requestPhotoUrisReadPermission failed, errCode is ' + err.code + ', errMsg is ' + err.message);
  }
}
```

## getSupportedPhotoFormats<sup>18+</sup> 

getSupportedPhotoFormats(photoType: PhotoType): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of image or video file name extensions supported by the media library.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| photoType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | Yes  | Type of the file.|

**Return value**

| Type                                    | Description             |
|------------------------------------------|-------------------------|
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return an array of the supported image or video file name extensions.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error. It is recommended to retry and check the logs. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, photoTypeNumber: number){
  console.info('getSupportedPhotoFormatsDemo.');

  try {
    let outputText: string;
    if (photoTypeNumber !== photoAccessHelper.PhotoType.IMAGE && photoTypeNumber !== photoAccessHelper.PhotoType.VIDEO) {
      outputText = 'Does not support querying formats other than images or videos';
      return;
    }
    outputText = 'The supported types are:\n';
    let imageFormat  = await phAccessHelper.getSupportedPhotoFormats(photoAccessHelper.PhotoType.IMAGE);
    let result = "";
    for (let i = 0; i < imageFormat.length; i++) {
      result += imageFormat[i];
      if (i !== imageFormat.length - 1) {
        result += ', ';
      }
    }
    outputText += result;
    console.info('getSupportedPhotoFormats success, data is ' + outputText);
  } catch (error) {
    console.error('getSupportedPhotoFormats failed, errCode is', error);
  }
}
```

## on('photoChange')<sup>20+</sup> 

on(type: 'photoChange', callback: Callback&lt;PhotoAssetChangeInfos&gt;): void

Registers a listener for the **'photoChange'** event to monitor media asset changes. This API uses a callback to return the result, and it accepts multiple callbacks.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'photoChange'**. After the registration is complete, any change to the media assets is returned through the callback.|
| callback  | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | Yes  | Callback used to return the media asset information after change, which is [PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20).<br>**NOTE**: You can register multiple listeners using this API, and you can call [off('photoChange')](#offphotochange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('photoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('photoChange', onCallback2);
  } catch (error) {
    console.error('onPhotoChangeDemo failed, errCode is', error);
  }
}
```

## off('photoChange')<sup>20+</sup> 

off(type: 'photoChange', callback?: Callback&lt;PhotoAssetChangeInfos&gt;): void

Unregisters the listener for the **'photoChange'** event to stop monitoring media asset changes. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'photoChange'**. After the unregistration is complete, any change to the media assets is no longer returned through the callback.|
| callback | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('photoChange')](#onphotochange20). If this parameter is left unspecified, all listeners for the **'photoChange'** event are unregistered.<br>**NOTE**: Once a specific callback is unregistered, it will not be invoked when a media asset changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('offPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('photoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('photoChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('photoChange', onCallback1);
  } catch (error) {
    console.error('offPhotoChangeDemo failed, errCode is', error);
  }
}
```

## on('photoAlbumChange')<sup>20+</sup> 

on(type: 'photoAlbumChange', callback: Callback&lt;AlbumChangeInfos&gt;): void

Registers a listener for the **'photoAlbumChange'** event to monitor album changes. This API uses a callback to return the result, and it accepts multiple callbacks.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'photoAlbumChange'**. After the registration is complete, any change to the albums is returned through the callback.|
| callback  | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | Yes  | Callback used to return the album information after change, which is [AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20).<br>**NOTE**: You can register multiple listeners using this API, and you can call [off('photoAlbumChange')](#offphotoalbumchange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoAlbumChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('photoAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('photoAlbumChange', onCallback2);
  } catch (error) {
    console.error('onPhotoAlbumChangeDemo failed, errCode is', error);
  }
}
```

## off('photoAlbumChange')<sup>20+</sup> 

off(type: 'photoAlbumChange', callback?: Callback&lt;AlbumChangeInfos&gt;): void

Unregisters a listener for the **'photoAlbumChange'** event to stop monitoring album changes. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'photoAlbumChange'**. After the unregistration is complete, any change to the albums is no longer returned through the callback.|
| callback | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('photoAlbumChange')](#onphotoalbumchange20). If this parameter is left unspecified, all listeners for the **'photoAlbumChange'** event are unregistered.<br>**NOTE**: Once a specific callback is unregistered, it will not be invoked when an album changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoAlbumChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('photoAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('photoAlbumChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('photoAlbumChange', onCallback1);
  } catch (error) {
    console.error('onPhotoAlbumChangeDemo failed, errCode is', error);
  }
}
```

## createDeleteRequest<sup>(deprecated)</sup>

createDeleteRequest(uriList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Creates a dialog box for deleting media files. This API uses an asynchronous callback to return the result. The deleted media files are moved to the trash.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11-1) instead.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete. A maximum of 300 media files can be deleted.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset === undefined) {
      console.error('asset not exist');
      return;
    }
    phAccessHelper.createDeleteRequest([asset.uri], (err) => {
      if (err === undefined) {
        console.info('createDeleteRequest successfully');
      } else {
        console.error(`createDeleteRequest failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`fetch failed, error: ${err.code}, ${err.message}`);
  }
}
```

## createDeleteRequest<sup>(deprecated)</sup>

createDeleteRequest(uriList: Array&lt;string&gt;): Promise&lt;void&gt;

Creates a dialog box for deleting media files. This API uses a promise to return the result. The deleted media files are moved to the trash.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11-1) instead.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete. A maximum of 300 media files can be deleted.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset === undefined) {
      console.error('asset not exist');
      return;
    }
    await phAccessHelper.createDeleteRequest([asset.uri]);
    console.info('createDeleteRequest successfully');
  } catch (err) {
    console.error(`createDeleteRequest failed with error: ${err.code}, ${err.message}`);
  }
}
```
