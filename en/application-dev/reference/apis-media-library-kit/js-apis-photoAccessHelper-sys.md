# @ohos.file.photoAccessHelper (Album Management) (System API)

The photoAccessHelper module provides APIs for album management, including creating an album and accessing and modifying media data in an album.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.photoAccessHelper (Album Management)](js-apis-photoAccessHelper.md).

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## PhotoAccessHelper

### createAsset

createAsset(displayName: string, callback: AsyncCallback&lt;PhotoAsset&gt;): void

Creates an image or video asset with the specified file name. This API uses an asynchronous callback to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br>API version 18 and later: \ / : * ? " < > | <br>API versions 10 to 17: . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| callback |  AsyncCallback&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Callback used to return the image or video created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
  phAccessHelper.createAsset(testFileName, (err, photoAsset) => {
    if (photoAsset !== undefined) {
      console.info('createAsset file displayName' + photoAsset.displayName);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

### createAsset

createAsset(displayName: string): Promise&lt;PhotoAsset&gt;

Creates an image or video asset with the specified file name. This API uses a promise to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br>API version 18 and later: \ / : * ? " < > | <br>API versions 10 to 17: . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise used to return the created image and video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions, callback: AsyncCallback&lt;PhotoAsset&gt;): void

Creates an image or video asset with the specified file name and options. This API uses an asynchronous callback to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br>API version 18 and later: \ / : * ? " < > | <br>API versions 10 to 17: . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| options  | [PhotoCreateOptions](#photocreateoptions)        | Yes  | Options for creating an image or video asset.             |
| callback |  AsyncCallback&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Callback used to return the image or video created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
  let createOption: photoAccessHelper.PhotoCreateOptions = {
    subtype: photoAccessHelper.PhotoSubtype.DEFAULT
  }
  phAccessHelper.createAsset(testFileName, createOption, (err, photoAsset) => {
    if (photoAsset !== undefined) {
      console.info('createAsset file displayName' + photoAsset.displayName);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions): Promise&lt;PhotoAsset&gt;

Creates an image or video asset with the specified file name and options. This API uses a promise to return the result.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br>API version 18 and later: \ / : * ? " < > | <br>API versions 10 to 17: . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| options  |  [PhotoCreateOptions](#photocreateoptions)       | Yes  | Options for creating an image or video asset.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise used to return the created image and video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  try {
    let testFileName:string = 'testFile' + Date.now() + '.jpg';
    let createOption: photoAccessHelper.PhotoCreateOptions = {
      subtype: photoAccessHelper.PhotoSubtype.DEFAULT
    }
    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName, createOption);
    console.info('createAsset file displayName' + photoAsset.displayName);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

### createAlbum<sup>(deprecated)</sup>

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void

Creates an album. This API uses an asynchronous callback to return the result.

The album name must meet the following requirements:
- The album name cannot exceed 255 characters.
- The album name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.createAlbumRequest](#createalbumrequest11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |
| callback |  AsyncCallback&lt;[Album](#album)&gt; | Yes  | Callback used to return the created album instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900015       |  File exists.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAlbumDemo');
  let albumName: string = 'newAlbumName' + new Date().getTime();
  phAccessHelper.createAlbum(albumName, (err, album) => {
    if (err) {
      console.error(`createAlbumCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    console.info('createAlbumCallback successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  });
}
```

### createAlbum<sup>(deprecated)</sup>

createAlbum(name: string): Promise&lt;Album&gt;

Creates an album. This API uses a promise to return the result.

The album name must meet the following requirements:
- The album name cannot exceed 255 characters.
- The album name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.createAlbumRequest](#createalbumrequest11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[Album](#album)&gt; | Promise used to return the created album instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900015       |  File exists.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('createAlbumDemo');
  let albumName: string = 'newAlbumName' + new Date().getTime();
  phAccessHelper.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err: BusinessError) => {
    console.error(`createAlbumPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### deleteAlbums<sup>(deprecated)</sup>

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes albums. This API uses an asynchronous callback to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAlbums](#deletealbums11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  | Array&lt;[Album](#album)&gt;         | Yes  | Albums to delete.             |
| callback |  AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
  phAccessHelper.deleteAlbums([album], (err) => {
    if (err) {
      console.error(`deletePhotoAlbumsCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    console.info('deletePhotoAlbumsCallback successfully');
  });
  fetchResult.close();
}
```

### deleteAlbums<sup>(deprecated)</sup>

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;

Deletes albums. This API uses a promise to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAlbums](#deletealbums11) instead.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  |  Array&lt;[Album](#album)&gt;          | Yes  | Albums to delete.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
  phAccessHelper.deleteAlbums([album]).then(() => {
    console.info('deletePhotoAlbumsPromise successfully');
    }).catch((err: BusinessError) => {
      console.error(`deletePhotoAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
  fetchResult.close();
}
```

### getHiddenAlbums<sup>11+</sup>

getHiddenAlbums(mode: HiddenPhotosDisplayMode, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains hidden albums based on the specified display mode and retrieval options. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden albums. |
| options  | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)         | Yes  |  Options for retrieving the hidden albums. |
| callback |  AsyncCallback&lt;[FetchResult](js-apis-photoAccessHelper.md#fetchresult)&lt;[Album](#album)&gt;&gt; | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

// Obtain the album newAlbumName that contains hidden files.
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE, fetchOptions,
    async (err, fetchResult) => {
      if (fetchResult === undefined) {
        console.error('getHiddenAlbumsViewCallback fetchResult is undefined');
        return;
      }
      let album = await fetchResult.getFirstObject();
      console.info('getHiddenAlbumsViewCallback successfully, album name: ' + album.albumName);
      fetchResult.close();
  });
}
```

### getHiddenAlbums<sup>11+</sup>

getHiddenAlbums(mode: HiddenPhotosDisplayMode, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains hidden albums based on the specified display mode. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden albums. |
| callback |  AsyncCallback&lt;[FetchResult](js-apis-photoAccessHelper.md#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

// Obtain the preset hidden album.
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE, async (err, fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getSysHiddenAlbumCallback fetchResult is undefined');
      return;
    }
    let hiddenAlbum: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getSysHiddenAlbumCallback successfully, albumUri: ' + hiddenAlbum.albumUri);
    fetchResult.close();
  });
}

// Obtain the hidden albums displayed by album, that is, the albums with hidden files. Such albums do not include the preset hidden album and the albums in the trash.
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE, async (err, fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getHiddenAlbumsViewCallback fetchResult is undefined');
      return;
    }
    let albums: Array<photoAccessHelper.Album> = await fetchResult.getAllObjects();
    console.info('getHiddenAlbumsViewCallback successfully, albums size: ' + albums.length);

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    for (let i = 0; i < albums.length; i++) {
      // Obtain hidden files in the album.
      albums[i].getAssets(fetchOption, (err, assetFetchResult) => {
        console.info('album get hidden assets successfully, getCount: ' + assetFetchResult.getCount());
      });
    }
    fetchResult.close();
  });
}
```

### getHiddenAlbums<sup>11+</sup>

getHiddenAlbums(mode: HiddenPhotosDisplayMode, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains hidden albums based on the specified display mode and retrieval options. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden albums. |
| options  | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)         | No  |  Options for retrieving the files. If this parameter is not specified, the files are retrieved based on the display mode of hidden files.     |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](js-apis-photoAccessHelper.md#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the preset hidden album.
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE)
    .then( async (fetchResult) => {
      if (fetchResult === undefined) {
        console.error('getSysHiddenAlbumPromise fetchResult is undefined');
        return;
      }
      let hiddenAlbum: photoAccessHelper.Album = await fetchResult.getFirstObject();
      console.info('getAlbumsPromise successfully, albumUri: ' + hiddenAlbum.albumUri);
      fetchResult.close();
    }).catch((err: BusinessError) => {
      console.error(`getSysHiddenAlbumPromise failed with err: ${err.code}, ${err.message}`);
    });
}

// Obtain the hidden albums displayed by album, that is, the albums with hidden files. Such albums do not include the preset hidden album and the albums in the trash.
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getHiddenAlbumsViewPromise fetchResult is undefined');
      return;
    }
    let albums: Array<photoAccessHelper.Album> = await fetchResult.getAllObjects();
    console.info('getHiddenAlbumsViewPromise successfully, albums size: ' + albums.length);

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    for (let i = 0; i < albums.length; i++) {
      // Obtain hidden files in the album.
      albums[i].getAssets(fetchOption).then((assetFetchResult) => {
        console.info('album get hidden assets successfully, getCount: ' + assetFetchResult.getCount());
      }).catch((err: BusinessError) => {
        console.error(`album get hidden assets failed with error: ${err.code}, ${err.message}`);
      });
    }
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getHiddenAlbumsViewPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### deleteAssets<sup>(deprecated)</sup>

deleteAssets(uriList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes media assets. This API uses an asynchronous callback to return the result. The deleted assets are moved to the trash.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.deleteAssets](js-apis-photoAccessHelper.md#deleteassets11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002       | Invalid uri.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('deleteAssetDemo');
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
    phAccessHelper.deleteAssets([asset.uri], (err) => {
      if (err === undefined) {
        console.info('deleteAssets successfully');
      } else {
        console.error(`deleteAssets failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`fetch failed, error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAssets<sup>(deprecated)</sup>

deleteAssets(uriList: Array&lt;string&gt;): Promise&lt;void&gt;

Deletes media assets. This API uses a promise to return the result. The deleted assets are moved to the trash.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.deleteAssets](js-apis-photoAccessHelper.md#deleteassets11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002       | Invalid uri.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('deleteDemo');
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
    await phAccessHelper.deleteAssets([asset.uri]);
    console.info('deleteAssets successfully');
  } catch (err) {
    console.error(`deleteAssets failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getPhotoIndex

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions, callback: AsyncCallback&lt;number&gt;): void

Obtains the index of an image or video in an album. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | Yes  | URI of the media asset whose index is to be obtained.|
| albumUri | string | Yes  | Album URI, which can be an empty string. If it is an empty string, all the media assets in the Gallery are obtained by default.  |
| options  | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |
| callback | AsyncCallback&lt;number&gt;| Yes  | Callback used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album.
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE, fetchOp);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(photoAccessHelper.PhotoKeys.DATE_MODIFIED);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [photoAccessHelper.PhotoKeys.DATE_MODIFIED],
      predicates: predicates
    };
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file.
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);

    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {
      if (err === undefined) {
        console.info(`getPhotoIndex successfully and index is : ${index}`);
      } else {
        console.error(`getPhotoIndex failed; error: ${err.code}, ${err.message}`);
      }
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error.code}, ${error.message}`);
  }
}
```

### getPhotoIndex

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions): Promise&lt;number&gt;

Obtains the index of an image or video in an album. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | Yes  | URI of the media asset whose index is to be obtained.|
| albumUri | string | Yes  | Album URI, which can be an empty string. If it is an empty string, all the media assets in the Gallery are obtained by default.  |
| options  | [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt;| Promise used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album.
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE, fetchOp);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(photoAccessHelper.PhotoKeys.DATE_MODIFIED);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [photoAccessHelper.PhotoKeys.DATE_MODIFIED],
      predicates: predicates
    };
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file.
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);
    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {
      console.info(`getPhotoIndex successfully and index is : ${index}`);
    }).catch((err: BusinessError) => {
      console.error(`getPhotoIndex failed; error: ${err.code}, ${err.message}`);
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error.code}, ${error.message}`);
  }
}
```

### saveFormInfo<sup>11+</sup>

saveFormInfo(info:FormInfo, callback: AsyncCallback&lt;void&gt;):void

Saves a Gallery widget. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [FormInfo](#forminfo11)        | Yes  | Information about the Gallery widget to save, which includes the ID of the widget and the URI of the image bound to the widget.             |
| callback |  AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |


**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('saveFormInfoDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

  let info: photoAccessHelper.FormInfo = {
    // formId is a string consisting of only digits. uri indicates the URI of the image in Gallery. If there is no image in Gallery, uri must be an empty string.
    formId : "20230116123",
    uri: photoAsset.uri,
  }

  phAccessHelper.saveFormInfo(info, async (err: BusinessError) => {
    if (err == undefined) {
      console.info('saveFormInfo success');
    } else {
      console.error(`saveFormInfo fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

### saveFormInfo<sup>11+</sup>

saveFormInfo(info:FormInfo):Promise&lt;void&gt;

Saves a Gallery widget. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [FormInfo](#forminfo11)        | Yes  | Information about the Gallery widget to save, which includes the ID of the widget and the URI of the image bound to the widget.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('saveFormInfoDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

  let info: photoAccessHelper.FormInfo = {
    // formId is a string consisting of only digits. uri indicates the URI of the image in Gallery. If there is no image in Gallery, uri must be an empty string.
    formId: "20230116123",
    uri: photoAsset.uri,
  }

  phAccessHelper.saveFormInfo(info).then(() => {
    console.info('saveFormInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`saveFormInfo failed with error: ${err.code}, ${err.message}`);
  });
}
```

### removeFormInfo<sup>11+</sup>

removeFormInfo(info:FormInfo, callback: AsyncCallback&lt;void&gt;):void

Removes a Gallery widget. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [FormInfo](#forminfo11)        | Yes  |  Information about the Gallery widget to save, which includes the ID of the widget and the URI of the image bound to the widget.             |
| callback |  AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('removeFormInfoDemo');
  let info: photoAccessHelper.FormInfo = {
    // formId is a string consisting of only digits. When removing a widget, leave uri empty.
    formId: "20230116123",
    uri: "",
  }

  phAccessHelper.removeFormInfo(info, async (err: BusinessError) => {
    if (err == undefined) {
      console.info('removeFormInfo success');
    } else {
      console.error(`removeFormInfo fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

### removeFormInfo<sup>11+</sup>

removeFormInfo(info:FormInfo):Promise&lt;void&gt;

Removes a Gallery widget. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [FormInfo](#forminfo11)        | Yes  |  Information about the Gallery widget to save, which includes the ID of the widget and the URI of the image bound to the widget.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('removeFormInfoDemo');
  let info: photoAccessHelper.FormInfo = {
    // formId is a string consisting of only digits. When removing a widget, leave uri empty.
    formId: "20230116123",
    uri: "",
  }

  phAccessHelper.removeFormInfo(info).then(() => {
    console.info('removeFormInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`removeFormInfo failed with error: ${err.code}, ${err.message}`);
  });
}
```

### createAssetsForApp<sup>12+</sup>

createAssetsForApp(bundleName: string, appName: string, appId: string, photoCreationConfigs: Array&lt;PhotoCreationConfig&gt;): Promise&lt;Array&lt;string&gt;&gt;

Creates media assets for an application. The returned URIs has been granted with the permission for writing the media assets (images or videos).

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| bundleName | string | Yes| Bundle name of the target application.|
| appName | string | Yes| Name of the target application.|
| appId | string | Yes| ID of the target application.|
| photoCreationConfigs | Array&lt;[PhotoCreationConfig](./js-apis-photoAccessHelper.md#photocreationconfig12)&gt; | Yes| Configuration for creating (saving) the media assets in the media library.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the media asset files in the media library. The target application (identified by **appid**) can write the media assets based on the URIs without requesting the write permission. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('createAssetsForAppDemo.');

  try {
    let bundleName: string = 'testBundleName';
    let appName: string = 'testAppName';
    let appId: string = 'testAppId';
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test',
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT,
      }
    ];
    let desFileUris: Array<string> = await phAccessHelper.createAssetsForApp(bundleName, appName, appId, photoCreationConfigs);
    console.info('createAssetsForApp success, data is ' + desFileUris);
  } catch (err) {
    console.error(`createAssetsForApp failed with error: ${err.code}, ${err.message}`);
  }
}
```

### grantPhotoUriPermission<sup>15+</sup>

grantPhotoUriPermission(tokenId: number, uri: string, photoPermissionType: PhotoPermissionType, hideSensitiveType: HideSensitiveType): Promise&lt;number&gt;

Grants an application the permission to access a URI. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| tokenId | number | Yes| ID of the target application.|
| uri | string | Yes| URI of the media asset.|
| photoPermissionType | [PhotoPermissionType](#photopermissiontype12) | Yes| Type of the permission to be granted. For details, see the enum.|
| hideSensitiveType | [HideSensitiveType](#hidesensitivetype12) | Yes| Type of the information to hide. This parameter is reserved. Currently, any enumerated value of **HideSensitiveType** can be passed in.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the result. The value **0** means the permission is granted to the application. The value **1** means the application already has the permission. The value **-1** means the permission fails to be granted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('grantPhotoUriPermissionDemo');

  try {
    let tokenId = 502334412;
    let result = await phAccessHelper.grantPhotoUriPermission(tokenId,
        'file://media/Photo/1/IMG_datetime_0001/displayName.jpg',
        photoAccessHelper.PhotoPermissionType.TEMPORARY_READ_IMAGEVIDEO,
        photoAccessHelper.HideSensitiveType.HIDE_LOCATION_AND_SHOTING_PARM);

    console.info('grantPhotoUriPermission success, result=' + result);
  } catch (err) {
    console.error('grantPhotoUriPermission failed, error=' + err);
  }
}
```

### grantPhotoUrisPermission<sup>15+</sup>

grantPhotoUrisPermission(tokenId: number, uriList: Array&lt;string&gt;, photoPermissionType: PhotoPermissionType, hideSensitiveType: HideSensitiveType): Promise&lt;number&gt;

Grants an application the permission to access multiple URIs. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| tokenId | number | Yes| ID of the target application.|
| uriList | Array&lt;string&gt; | Yes| A list of URIs, which cannot exceed 1000.|
| photoPermissionType | [PhotoPermissionType](#photopermissiontype12) | Yes| Type of the permission to be granted. For details, see the enum.|
| hideSensitiveType | [HideSensitiveType](#hidesensitivetype12) | Yes| Type of the information to hide. This parameter is reserved. Currently, any enumerated value of **HideSensitiveType** can be passed in.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the result. The value **0** means the operation is successful; the value **-1** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('grantPhotoUrisPermissionDemo');

  try {
    // URIs of the media assets.
    let uris: Array<string> = [
      'file://media/Photo/11/IMG_datetime_0001/displayName1.jpg',
      'file://media/Photo/22/IMG_datetime_0002/displayName2.jpg'];
    let tokenId = 502334412;
    let result = await phAccessHelper.grantPhotoUrisPermission(tokenId, uris,
        photoAccessHelper.PhotoPermissionType.TEMPORARY_READ_IMAGEVIDEO,
        photoAccessHelper.HideSensitiveType.HIDE_LOCATION_AND_SHOTING_PARM);

    console.info('grantPhotoUrisPermission success, result=' + result);
  } catch (err) {
    console.error('grantPhotoUrisPermission failed, error=' + err);
  }
}
```

### cancelPhotoUriPermission<sup>15+</sup>

cancelPhotoUriPermission(tokenId: number, uri: string, photoPermissionType: PhotoPermissionType): Promise&lt;number&gt;

Cancels the permission for accessing an URI from an application. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| tokenId | number | Yes| ID of the target application.|
| uri | string | Yes| URI of the media asset.|
| photoPermissionType | [PhotoPermissionType](#photopermissiontype12) | Yes| Permission type.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the result. The value **0** means the operation is successful, and the value **-1** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('cancelPhotoUriPermissionDemo');

  try {
    let tokenId = 502334412;
    let result = await phAccessHelper.cancelPhotoUriPermission(tokenId,
        'file://media/Photo/11/IMG_datetime_0001/displayName.jpg',
        photoAccessHelper.PhotoPermissionType.TEMPORARY_READ_IMAGEVIDEO);

    console.info('cancelPhotoUriPermission success, result=' + result);
  } catch (err) {
    console.error('cancelPhotoUriPermission failed, error=' + err);
  }
}
```

### startAssetAnalysis<sup>18+</sup>

startAssetAnalysis(type: AnalysisType, assetUris?: Array&lt;string&gt;): Promise&lt;number&gt;

Starts asset analysis.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| type      | number              | Yes  | Smart analysis type.                                    |
| assetUris | Array&lt;string&gt; | No  | Array of asset URIs.<br>- If this parameter is specified, only the given assets are analyzed.<br>- If this parameter is left blank, full analysis is performed.|

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the task ID of the service.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**Example**

```ts
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('startAssetAnalysisDemo');
  try {
    let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let uris = ["file://media/Photo/14/IMG_1729066473_013/IMG_20241016_122253.jpg",
                "file://media/Photo/68/IMG_1729033213_018/IMG_20241016_100082.jpg"];
    let taskId = await phAccessHelper.startAssetAnalysis(photoAccessHelper.AnalysisType.ANALYSIS_SEARCH_INDEX,
        uris);
    console.info('startAssetAnalysis success, taskId=' + taskId);
  } catch (err) {
    console.error('startAssetAnalysis failed, error=' + err);
  }
}
```

### createAssetsForAppWithMode<sup>12+</sup>

createAssetsForAppWithMode(boundleName: string, appName: string, appId: string, tokenId: number, authorizationMode: AuthorizationMode, photoCreationConfigs:Array\<PhotoCreationConfig>): Promise\<Array\<string>>

Creates assets with a temporary permission. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| boundleName| string | Yes| Bundle name of the target application.|
| appName| string | Yes| Name of the target application.|
| appId| string | Yes| ID of the target application.|
| tokenId| number| Yes| Unique identifier for the temporary authorization.|
| authorizationMode| [AuthorizationMode](#authorizationmode12)| Yes| Authorization mode. No confirmation dialog box is displayed when the application with the temporary permission saves media assets in the give period of time.|
| PhotoCreationConfig| Array\<[PhotoCreationConfig](js-apis-photoAccessHelper.md#photocreationconfig12)> | Yes| Configuration for creating (saving) the media assets in the media library.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<Array\<string>> | Promise used to return the URIs of the media asset files in the media library. The target application (identified by **appid**) can write the assets based on the URIs without has been authorized to the application specified by appId to allow the application to write data. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('createAssetsForAppWithModeDemo.');

  try {
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: '123456',
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT,
      }
    ];
    let bundleName: string = 'testBundleName';
    let appName: string = 'testAppName';
    let appId: string = 'testAppId';
    let tokenId: number = 537197950;
    let authorizationMode: photoAccessHelper.AuthorizationMode = photoAccessHelper.AuthorizationMode.SHORT_TIME_AUTHORIZATION;
    let result: Array<string> = await phAccessHelper.createAssetsForAppWithMode(bundleName, appName, appId, tokenId, authorizationMode, photoCreationConfigs);
    console.info(`result: ${JSON.stringify(result)}`);
    console.info('Photo createAssetsForAppWithMode success.');
  } catch (err) {
    console.error(`createAssetsForAppWithMode failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getKeyFrameThumbnail<sup>18+</sup>

getKeyFrameThumbnail(beginFrameTimeMs: number, type: ThumbnailType): Promise<image.PixelMap>

Obtains the thumbnail of the specified type for the key frame. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| beginFrameTimeMs | number | Yes   | Time of the start frame, in ms. <br>The value **0** indicates the cover frame.|
| type | [ThumbnailType](#thumbnailtype13)| Yes   | Type of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Promise used to return the PixelMap of the thumbnail obtained. The cover frame is returned by default if no thumbnail is obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by non-system application.       |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | Internal system error.       

**Example**

```ts
import { common }  from '@kit.AbilityKit';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try{
    console.info('getKeyFrameThumbnail demo');
    let phAccessHelper:photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo(photoAccessHelper.PhotoKeys.PHOTO_TYPE, photoAccessHelper.PhotoType.VIDEO);
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
    let pixelMap: image.PixelMap = await asset.getKeyFrameThumbnail(0, photoAccessHelper.ThumbnailType.LCD);
    console.info('getKeyFrameThumbnail success');
  } catch (error) {
    console.error('getKeyFrameThumbnail failed, error: ' + JSON.stringify(error));
  }
}
```

### saveGalleryFormInfo<sup>18+</sup>

saveGalleryFormInfo(info:GalleryFormInfo):Promise&lt;void&gt;

Saves a Gallery widget. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [GalleryFormInfo](#galleryforminfo18)        | Yes  | Information about the Gallery widget, which includes the ID of the widget and the URIs of the image or album bound to the widget.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import {photoAccessHelper} from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('saveGalleryFormInfoDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let uriList: Array<string> = [
    photoAsset.uri,
  ];
  let info: photoAccessHelper.GalleryFormInfo = {
    // formId is a string consisting of only digits. assetUris indicates the URIs of the images or albums in Gallery.
    formId: "20230116123",
    assetUris: uriList,
  }

  phAccessHelper.saveGalleryFormInfo(info).then(() => {
    console.info('saveGalleryFormInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`saveGalleryFormInfo failed with error: ${err.code}, ${err.message}`);
  });
}
```

### updateGalleryFormInfo<sup>18+</sup>

updateGalleryFormInfo(info:GalleryFormInfo):Promise&lt;void&gt;

Updates the information about a Gallery widget and saves the information to the database. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [GalleryFormInfo](#galleryforminfo18)        | Yes  | Information about the Gallery widget, which includes the ID of the widget and the URIs of the image or album bound to the widget.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import {photoAccessHelper} from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('updateGalleryFormInfoDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let photoAssetLast: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
  let uriList: Array<string> = [
    photoAsset.uri,
    photoAssetLast.uri
  ];
  let info: photoAccessHelper.GalleryFormInfo = {
    // formId is a string consisting of only digits. assetUris indicates the URIs of the images or albums in Gallery.
    formId: "20230116123",
    assetUris: uriList,
  }

  phAccessHelper.updateGalleryFormInfo(info).then(() => {
    console.info('updateGalleryFormInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`updateGalleryFormInfo failed with error: ${err.code}, ${err.message}`);
  });
}
```

### removeGalleryFormInfo<sup>18+</sup>

removeGalleryFormInfo(info:GalleryFormInfo):Promise&lt;void&gt;

Removes a Gallery widget. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| info  | [GalleryFormInfo](#galleryforminfo18)        | Yes  | Information about the Gallery widget, which includes the ID of the widget and the URIs of the image or album bound to the widget.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import {photoAccessHelper} from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('removeGalleryFormInfoDemo');
  let info: photoAccessHelper.GalleryFormInfo = {
    // formId is a string consisting of only digits. When removing a widget, leave assertUris empty.
    formId: "20230116123"
  }

  phAccessHelper.removeGalleryFormInfo(info).then(() => {
    console.info('removeGalleryFormInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`removeGalleryFormInfo failed with error: ${err.code}, ${err.message}`);
  });
}
```


### getAlbumsByIds<sup>18+</sup>

getAlbumsByIds(albumIds: Array&lt;number&gt;): Promise&lt;Map&lt;number, Album&gt;&gt;

Obtains album information by album IDs. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| albumIds  | Array&lt;number&gt;              | Yes  | Array of album IDs.                                    |

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;Map&lt;number, Album&gt;&gt; | Promise used to return the map object that contains the album information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('startGetAlbumsByIdsDemo');

  try {
    // Obtain the sandbox URIs of the images or videos to be saved to the media library.
    let albumIds: Array<number> = [
      12 //Use the actual album ID.
    ];
    let map: Map<number, photoAccessHelper.Album> = await phAccessHelper.getAlbumsByIds(albumIds);
    console.info('getAlbumsByIds success, size is ' + map.size);
  } catch (err) {
    console.error('getAlbumsByIds failed, errCode is ' + err.code + ', errMsg is ' + err.message);
  }
}
```

### createAssetsForAppWithAlbum<sup>18+</sup>

createAssetsForAppWithAlbum(source: PhotoCreationSource, albumUri: string, isAuthorized: boolean, photoCreationConfigs: Array&lt;PhotoCreationConfig&gt;): Promise&lt;Array&lt;string&gt;&gt;

Creates assets for the current application or other applications in the specified source or user album. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| source  | [PhotoCreationSource](#photocreationsource18)         | Yes  | Application information provided to create assets on behalf of the application.                                    |
| albumUri  | string             | Yes  | URI of the album.                                    |
| isAuthorized  |  boolean              | Yes  | Whether to authorize other applications. The value **true** means that the permission is authorized, and **false** means the opposite.                                    |
| PhotoCreationConfigs| Array\<[PhotoCreationConfig](js-apis-photoAccessHelper.md#photocreationconfig12)> | Yes| Configuration for creating (saving) the media assets in the media library.|

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the media asset files in the media library.<br>The target application (identified by **appid**) can write the media assets based on the URIs without requesting the write permission. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

```ts
async function example() {
  console.info('createAssetsForAppWithAlbumDemo.');

  try {
    let source: photoAccessHelper.PhotoCreationSource = {
      bundleName: 'testBundleName',
      appName: 'testAppName',
      appId: 'testAppId',
      tokenId: 537197950,
    }
    let albumUri: string = 'file://media/PhotoAlbum/10';
    let isAuthorized: boolean = true;
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test',
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT,
      }
    ];
    let desFileUris: Array<string> = await phAccessHelper.createAssetsForAppWithAlbum(source, albumUri, isAuthorized, photoCreationConfigs);
    console.info('createAssetsForAppWithAlbum success, data is ' + desFileUris);
  } catch (err) {
    console.error(`createAssetsForAppWithAlbum failed with error: ${err.code}, ${err.message}`);
  }
}
```

## PhotoAsset

Provides APIs for encapsulating file asset attributes.

### open<sup>(deprecated)</sup>

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. For security purposes, the API for obtaining the media file handle is no longer provided.

> **NOTE**<br>A file can be opened in only one mode at a time. Use **close()** to close the FD returned when it is not required.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | Mode for opening the file, which can be **'r'** (read-only), **'w'** (write-only), or **'rw'** (read/write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the file descriptor (FD) of the file opened.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('Open demo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
  let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
  photoAsset.open('rw', (err, fd) => {
    if (fd !== undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error(`Open file err: ${err.code}, ${err.message}`);
    }
  });
}
```

### open<sup>(deprecated)</sup>

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. For security purposes, the API for obtaining the media file handle is no longer provided.

> **NOTE**<br>A file can be opened in only one mode at a time. Use **close()** to close the FD returned when it is not required.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | Mode for opening the file, which can be **'r'** (read-only), **'w'** (write-only), or **'rw'** (read/write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the FD of the file opened.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('Open demo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    let fd: number = await photoAsset.open('rw');
    if (fd !== undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error('Open file fail');
    }
  } catch (err) {
    console.error(`Open demo err: ${err.code}, ${err.message}`);
  }
}
```

### setFavorite<sup>(deprecated)</sup>

setFavorite(favoriteState: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setFavorite](#setfavorite11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| favoriteState | boolean                   | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  asset.setFavorite(true, (err) => {
    if (err === undefined) {
      console.info('favorite successfully');
    } else {
      console.error(`favorite failed with error: ${err.code}, ${err.message}`);
    }
  });
}
```

### setFavorite<sup>(deprecated)</sup>

setFavorite(favoriteState: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setFavorite](#setfavorite11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| favoriteState | boolean | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  asset.setFavorite(true).then(() => {
    console.info('setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error(`setFavorite failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setHidden<sup>(deprecated)</sup>

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets this file to hidden state. This API uses an asynchronous callback to return the result.

Private files are stored in the private album. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setHidden](#sethidden11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| hiddenState | boolean                   | Yes   | Whether to set a file to hidden state. The value **true** means to hide the file; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  asset.setHidden(true, (err) => {
    if (err === undefined) {
      console.info('setHidden successfully');
    } else {
      console.error(`setHidden failed with error: ${err.code}, ${err.message}`);
    }
  });
}
```

### setHidden<sup>(deprecated)</sup>

setHidden(hiddenState: boolean): Promise&lt;void&gt;

Sets this file asset to hidden state. This API uses a promise to return the result.

Private files are stored in the private album. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setHidden](#sethidden11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | Yes   | Whether to set a file to hidden state. The value **true** means to hide the file; the value **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  // Restore a file from a hidden album. Before the operation, ensure that the file exists in the hidden album.
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.HIDDEN);
  let album = await albumList.getFirstObject();
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error(`setHidden failed with error: ${err.code}, ${err.message}`);
  });
}
```

### getExif

getExif(): Promise&lt;string&gt;

Obtains the exchangeable image file format (EXIF) data from a JPG image. This API uses a promise to return the result.

The EXIF information obtained are provided by the [image](../apis-image-kit/js-apis-image.md) module. For details about the EXIF information, see [image.PropertyKey](../apis-image-kit/js-apis-image.md#propertykey7).

> **NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Promise used to return the EXIF data, in JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [ 'all_exif',  photoAccessHelper.PhotoKeys.USER_COMMENT],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let exifMessage = await photoAsset.getExif();
    let userCommentKey = 'UserComment';
    let userComment = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
    console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
    fetchResult.close();
  } catch (err) {
    console.error(`getExifDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getExif

getExif(callback: AsyncCallback&lt;string&gt;): void

Obtains the exchangeable image file format (EXIF) data from a JPG image. This API uses an asynchronous callback to return the result.

The EXIF data obtained are provided by the [image](../apis-image-kit/js-apis-image.md) module. For details about the EXIF information, see [image.PropertyKey](../apis-image-kit/js-apis-image.md#propertykey7).

> **NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the EXIF data, in JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.isNotNull('all_exif')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: ['all_exif', photoAccessHelper.PhotoKeys.USER_COMMENT],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getExifDemo photoAsset displayName: ' + JSON.stringify(photoAsset.displayName));
    let userCommentKey = 'UserComment';
    photoAsset.getExif((err, exifMessage) => {
      if (exifMessage !== undefined) {
        let userComment = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
        console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
      } else {
        console.error(`getExif failed, error: ${err.code}, ${err.message}`);
      }
    });
    fetchResult.close();
  } catch (err) {
    console.error(`getExifDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setUserComment<sup>(deprecated)</sup>

setUserComment(userComment: string): Promise&lt;void&gt;

Sets user comment information of an image or video. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setUserComment](#setusercomment11) instead.

**NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 420 characters.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let userComment = 'test_set_user_comment';
    await photoAsset.setUserComment(userComment);
  } catch (err) {
    console.error(`setUserCommentDemoPromise failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setUserComment<sup>(deprecated)</sup>

setUserComment(userComment: string, callback: AsyncCallback&lt;void&gt;): void

Sets user comment information of an image or video. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAssetChangeRequest.setUserComment](#setusercomment11) instead.

**NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 420 characters.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let userComment = 'test_set_user_comment';
    photoAsset.setUserComment(userComment, (err) => {
      if (err === undefined) {
        console.info('setUserComment successfully');
      } else {
        console.error(`setUserComment failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`setUserCommentDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setPending<sup>11+</sup>

setPending(pendingState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the pending state for this image or video asset. This API uses an asynchronous callback to return the result.

The pending state can be removed only through **setPending(false)**. You can use **photoAsset.get(photoAccessHelper.PhotoKeys.PENDING)** to check whether the asset state is pending. If the asset is in pending state, **true** is returned. Otherwise, **false** is returned.

**NOTE**<br>**setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| pendingState | boolean | Yes   | Whether to set the file to pending state. The value **true** means to set the file to pending state, and the value **false** means to remove the pending state.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
async function example() {
  try {
    console.info('setPendingCallbackDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    let fd = await photoAsset.open('rw');
    photoAsset.setPending(true, async (err) => {
      if (err !== undefined) {
        console.error(`setPending(true) failed with error: ${err.code}, ${err.message}`);
        return;
      }
      // write photo buffer in fd.
      photoAsset.setPending(false, async (err) => {
        if (err !== undefined) {
          console.error(`setPending(false) failed with error: ${err.code}, ${err.message}`);
          return;
        }
        await photoAsset.close(fd);
      });
    });
  } catch (err) {
    console.error(`setPendingCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setPending<sup>11+</sup>

setPending(pendingState: boolean): Promise&lt;void&gt;

Sets the pending state for this image or video asset. This API uses a promise to return the result.

The pending state can be removed only through **setPending(false)**. You can use **photoAsset.get(photoAccessHelper.PhotoKeys.PENDING)** to check whether the asset state is pending. If the asset is in pending state, **true** is returned. Otherwise, **false** is returned.

**NOTE**<br>**setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| pendingState | boolean | Yes   | Whether to set the file to pending state. The value **true** means to set the file to pending state, and the value **false** means to remove the pending state.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;boolean&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
async function example() {
  try {
    console.info('setPendingPromiseDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    let fd = await photoAsset.open('rw');
    await photoAsset.setPending(true);
    // write photo buffer in fd.
    photoAsset.setPending(false);
    await photoAsset.close(fd);
  } catch (err) {
    console.error(`setPendingPromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### isEdited<sup>11+</sup>

isEdited(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this image or video asset is edited. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result. The value **true** means that the image or video asset is edited, and **false** means the opposite. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('isEditedCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    photoAsset.isEdited((err, isEdited) => {
      if (err === undefined) {
        if (isEdited === true) {
          console.info('Photo is edited');
        } else {
          console.info('Photo is not edited');
        }
      } else {
        console.error(`isEdited failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`isEditedDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### isEdited<sup>11+</sup>

isEdited(): Promise&lt;boolean&gt;

Checks whether this image or video asset is edited. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means that the image or video asset is edited, and **false** means the opposite. The default value is **false**.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('isEditedPromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let isEdited = await photoAsset.isEdited();
    if (isEdited === true) {
      console.info('Photo is edited');
    } else {
      console.info('Photo is not edited');
    }
  } catch (err) {
    console.error(`isEditedDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestEditData<sup>11+</sup>

requestEditData(callback: AsyncCallback&lt;string&gt;): void

Obtains the edit data of this image or video asset. This API uses an asynchronous callback to return the result.

If the asset has never been edited, an empty string is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback used to return the edit data obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requestEditDataCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    photoAsset.requestEditData((err, editdata) => {
      if (err === undefined) {
        console.info('Editdata is ' + editdata);
      } else {
        console.error(`requestEditData failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`requestEditDataCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestEditData<sup>11+</sup>

requestEditData(): Promise&lt;string&gt;

Obtains the edit data of this image or video asset. This API uses a promise to return the result.

If the asset has never been edited, an empty string is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;string&gt; | Promise used to return the edit data obtained.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requestEditDataPromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let editdata: string = await photoAsset.requestEditData();
    console.info('Editdata is ' + editdata);
  } catch (err) {
    console.error(`requestEditDataPromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getEditData<sup>11+</sup>

getEditData(): Promise&lt;MediaAssetEditData&gt;

Obtains the edited data of this asset. This API uses a promise to return the result.

If the asset has never been edited, an empty string is returned.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;[MediaAssetEditData](#mediaasseteditdata11)&gt; | Promise used to return the edited asset data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getEditDataDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let assetEditData: photoAccessHelper.MediaAssetEditData = await photoAsset.getEditData();
    let data: string = assetEditData.data;
    console.info('edit data is ' + data);
  } catch (err) {
    console.error(`getEditDataDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestSource<sup>11+</sup>

requestSource(callback: AsyncCallback&lt;number&gt;): void

Opens the source file to obtain the FD. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the FD.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requsetSourceCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    photoAsset.requestSource((err, fd) => {
      if (err === undefined) {
        console.info('Source fd is ' + fd);
      } else {
        console.error(`requestSource failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`requsetSourceCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestSource<sup>11+</sup>

requestSource(): Promise&lt;number&gt;

Opens the source file to obtain the FD. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;number&gt; | Promise used to return the FD.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('requsetSourcePromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd = await photoAsset.requestSource();
    console.info('Source fd is ' + fd);
  } catch (err) {
    console.error(`requsetSourcePromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### commitEditedAsset<sup>11+</sup>

commitEditedAsset(editData: string, uri: string, callback: AsyncCallback&lt;void&gt;)

Commits the edited image or video asset. This API uses an asynchronous callback to return the result.

The edited file is transferred to the media library based on the URI, which is **FileUri** of the edited file in the application sandbox directory. For details, see [File URI](../apis-core-file-kit/js-apis-file-fileuri.md).

**NOTE**<br>The commit operation overwrites the previous edited data.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| editData | string | Yes   | New data to commit.|
| uri | string | Yes   | URI of the committed image or video in the application sandbox.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('commitEditedAssetCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let editData = '123456';
    let uri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    photoAsset.commitEditedAsset(editData, uri, (err) => {
      if (err === undefined) {
        console.info('commitEditedAsset is successful');
      } else {
        console.error(`commitEditedAsset failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`commitEditedAssetCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### commitEditedAsset<sup>11+</sup>

commitEditedAsset(editData: string, uri: string): Promise&lt;void&gt;

Commits the edited image or video asset. This API uses a promise to return the result.

The edited file is transferred to the media library based on the URI, which is **FileUri** of the edited file in the application sandbox directory. For details, see [File URI](../apis-core-file-kit/js-apis-file-fileuri.md).

**NOTE**<br>The commit operation overwrites the previous edited data.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| editData | string | Yes   | New data to commit.|
| uri | string | Yes   | URI of the committed image or video in the application sandbox.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('commitEditedAssetPromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let editData = '123456';
    let uri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    await photoAsset.commitEditedAsset(editData, uri);
    console.info('commitEditedAsset is successful');
  } catch (err) {
    console.error(`commitEditedAssetPromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### revertToOriginal<sup>11+</sup>

revertToOriginal(callback: AsyncCallback&lt;void&gt;)

Reverts to the state of the file before being edited. This API uses an asynchronous callback to return the result.

**NOTE**<br>This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('revertToOriginalCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    photoAsset.revertToOriginal((err) => {
      if (err === undefined) {
        console.info('revertToOriginal is successful');
      } else {
        console.error(`revertToOriginal failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`revertToOriginalCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### revertToOriginal<sup>11+</sup>

revertToOriginal(): Promise&lt;void&gt;

Reverts to the state of the file before being edited. This API uses a promise to return the result.

**NOTE**<br>This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;string&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('revertToOriginalPromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    photoAsset.revertToOriginal();
    console.info('revertToOriginal is successful');
  } catch (err) {
    console.error(`revertToOriginalPromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestPhoto<sup>11+</sup>

requestPhoto(callback: AsyncCallback&lt;image.PixelMap&gt;): string

Obtains the quick thumbnail and quality thumbnail of this asset. This API uses an asynchronous callback to return the result.

The size of a quick thumbnail is 128 x 128, and the size of a quality thumbnail is 256 x 256. After this API is called, the callback will be invoked twice to return a quick thumbnail and a quality thumbnail in sequence.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked twice to return the quick and quality thumbnails obtained.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| string | ID of the task for obtaining thumbnails.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.        |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example() {
  try {
    console.info('requestPhotoDemo')
    let options: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult = await phAccessHelper.getAssets(options);
    let photoAsset = await fetchResult.getFirstObject();
    let taskId: string = photoAsset.requestPhoto(async (err, pixel: image.PixelMap) => {
      if (err === undefined) {
        console.info("requestSource in, size: " + JSON.stringify((await pixel.getImageInfo()).size))
      } else {
        console.error(`requestSource failed with error: ${err.code}, ${err.message}`);
      }
    })
    console.info('requestSource taskId: ' + taskId)
  } catch (err) {
    console.error(`requestPhotoDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestPhoto<sup>11+</sup>

requestPhoto(options: RequestPhotoOptions, callback: AsyncCallback&lt;image.PixelMap&gt;): string

Obtains the thumbnails of an asset based on the specified options. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| options | [RequestPhotoOptions](#requestphotooptions11) | Yes   | Options for obtaining the asset thumbnail.|
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)&gt; | Yes   | Callback used to return the thumbnails obtained. The callback may be invoked more than once, depending on **options**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| string | ID of the task for obtaining thumbnails.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.        |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example() {
  try {
    console.info('requestPhotoDemo')
    let options: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult = await phAccessHelper.getAssets(options);
    let photoAsset = await fetchResult.getFirstObject();
    let taskId: string = photoAsset.requestPhoto({
      "size": {
        "width": 256,
        "height": 256
      },
      "requestPhotoType": photoAccessHelper.RequestPhotoType.REQUEST_ALL_THUMBNAILS
    }, async (err, pixel: image.PixelMap) => {
      if (err === undefined) {
        console.info("requestSource in, size: " + JSON.stringify((await pixel.getImageInfo()).size))
      } else {
        console.error(`requestSource failed with error: ${err.code}, ${err.message}`);
      }
    })
    console.info('requestSource taskId: ' + taskId)
  } catch (err) {
    console.error(`requestPhotoDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cancelPhotoRequest<sup>11+</sup>

cancelPhotoRequest(requestId: string): void

Cancels a task for obtaining media thumbnails.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| requestId | string | Yes   | ID of the task to cancel.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission verification failed, usually the result returned by VerifyAccessToken.        |
| 202   | Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example() {
  try {
    console.info('cancelPhotoRequestDemo')
    let options: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult = await phAccessHelper.getAssets(options);
    let photoAsset = await fetchResult.getFirstObject();
    let taskId: string = photoAsset.requestPhoto({
      "size": {
        "width": 256,
        "height": 256
      },
      "requestPhotoType": photoAccessHelper.RequestPhotoType.REQUEST_ALL_THUMBNAILS
    }, async (err, pixel: image.PixelMap) => {
      if (err === undefined) {
        console.info("requestSource in, size: " + JSON.stringify((await pixel.getImageInfo()).size))
      } else {
        console.error(`requestSource failed with error: ${err.code}, ${err.message}`);
      }
    })
    console.info('requestSource taskId: ' + taskId)
    photoAsset.cancelPhotoRequest(taskId);
  } catch (err) {
    console.error(`cancelPhotoRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getAnalysisData<sup>11+</sup>

getAnalysisData(analysisType: AnalysisType): Promise\<string>

Obtains analysis data. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name         | Type          | Mandatory| Description          |
| :----------- | :----------- | :- | :----------- |
| analysisType | [AnalysisType](#analysistype11) | Yes | Smart analysis type.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | System inner fail.                |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getAnalysisDataDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> =
      await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (photoAsset != undefined) {
      let analysisData: string = await photoAsset.getAnalysisData(
        photoAccessHelper.AnalysisType.ANALYSIS_OCR);
      console.info('get ocr result: ' + JSON.stringify(analysisData));
    }
    fetchResult.close();
  } catch (err) {
    console.error(`getAnalysisDataDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### getThumbnailData<sup>18+</sup>

getThumbnailData(type: ThumbnailType): Promise&lt;ArrayBuffer&gt;

Obtains the ArrayBuffer of a file thumbnail by specifying its type. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| type | [ThumbnailType](#thumbnailtype13) | Yes   | Type of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise\<ArrayBuffer> | Promise used to return the ArrayBuffer of the thumbnail.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 202      | Called by non-system application. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import {photoAccessHelper} from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('getThumbnailDataDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnailData(photoAccessHelper.ThumbnailType.LCD).then((buffer: ArrayBuffer) => {
    console.info('getThumbnailData successful, buffer byteLength = ${buffer.byteLength}');
  }).catch((err: BusinessError) => {
    console.error(`getThumbnailData fail with error: ${err.code}, ${err.message}`);
  });
}
```

## Album

Provides APIs to manage albums.

### Properties

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name          | Type   | Read-Only  | Optional | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| lpath<sup>18+</sup>    | string | Yes   | Yes  | Virtual path of the album.<br>**System API**: This is a system API.|
| dateAdded<sup>18+</sup>    | number | Yes   | Yes  | Time when the album was added.<br>**System API**: This is a system API.|
| dateModified<sup>18+</sup>    | number | Yes   | Yes  | Time when the album was modified.<br>**System API**: This is a system API.|

### recoverAssets<sup>(deprecated)</sup>

recoverAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Recovers image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.recoverAssets](#recoverassets11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to recover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('recoverAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.recoverAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album recoverAssets successfully');
      } else {
        console.error(`album recoverAssets failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`recoverAssetsDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### recoverAssets<sup>(deprecated)</sup>

recoverAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Recovers image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.recoverAssets](#recoverassets11) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to recover.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  try {
    console.info('recoverAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.recoverAssets([asset]).then(() => {
      console.info('album recoverAssets successfully');
    }).catch((err: BusinessError) => {
      console.error(`album recoverAssets failed with error: ${err.code}, ${err.message}`);
    });
  } catch (err) {
    console.error(`recoverAssetsDemoPromise failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAssets<sup>(deprecated)</sup>

deleteAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAssets](#deleteassets11) instead.

**NOTE**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('deleteAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.deleteAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album deleteAssets successfully');
      } else {
        console.error(`album deleteAssets failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`deleteAssetsDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAssets<sup>(deprecated)</sup>

deleteAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Deletes image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAssets](#deleteassets11) instead.

**NOTE**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to delete.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  try {
    console.info('deleteAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.deleteAssets([asset]).then(() => {
      console.info('album deleteAssets successfully');
    }).catch((err: BusinessError) => {
      console.error(`album deleteAssets failed with error: ${err.code}, ${err.message}`);
    });
  } catch (err) {
    console.error(`deleteAssetsDemoPromise failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setCoverUri<sup>(deprecated)</sup>

setCoverUri(uri: string, callback: AsyncCallback&lt;void&gt;): void

Sets the album cover. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.setCoverUri](#setcoveruri11) instead.

**NOTE**<br>This API can be used to set the user album cover, but not the system album cover.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to be set as the album cover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setCoverUriDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.setCoverUri(asset.uri, (err) => {
      if (err === undefined) {
        console.info('album setCoverUri successfully');
      } else {
        console.error(`album setCoverUri failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`setCoverUriDemoCallback failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setCoverUri<sup>(deprecated)</sup>

setCoverUri(uri: string): Promise&lt;void&gt;

Sets the album cover. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.setCoverUri](#setcoveruri11) instead.

**NOTE**<br>This API can be used to set the user album cover, but not the system album cover.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to be set as the album cover.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |
**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  try {
    console.info('setCoverUriDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.setCoverUri(asset.uri).then(() => {
      console.info('album setCoverUri successfully');
    }).catch((err: BusinessError) => { 
      console.error(`album setCoverUri failed with error: ${err.code}, ${err.message}`);
    });
  } catch (err) {
    console.error(`setCoverUriDemoPromise failed with error: ${err.code}, ${err.message}`);
  }
}
```

## MediaAssetEditData<sup>11+</sup>

Represents the edited media asset data.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### Properties

| Name          | Type   | Readable  | Writable | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| compatibleFormat | string | Yes   | Yes   | Format of the edited data.<br>**System API**: This is a system API.   |
| formatVersion | string | Yes   | Yes  | Version of the data format.<br>**System API**: This is a system API.   |
| data | string | Yes   | Yes  | Content edited.<br>**System API**: This is a system API.   |

### constructor<sup>11+</sup>

constructor(compatibleFormat: string, formatVersion: string)

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| compatibleFormat | string | Yes  | Format of the edited data.|
| formatVersion | string | Yes  | Version of the data format.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.          |

**Example**

```ts
let assetEditData: photoAccessHelper.MediaAssetEditData = new photoAccessHelper.MediaAssetEditData('system', '1.0');
```

## MediaAssetChangeRequest<sup>11+</sup>

Represents a media asset change request.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### createAssetRequest<sup>11+</sup>

static createAssetRequest(context: Context, displayName: string, options?: PhotoCreateOptions): MediaAssetChangeRequest

Creates an asset change request with the specified file name.

The file name must comply with the following specifications:
- The file name consists of a valid file name and an image or video file name extension.
- The file name cannot exceed 255 characters.
- The file name cannot contain any of the following characters:<br>API version 18 and later: \ / : * ? " < > | <br>API versions 10 to 17: . .. \ / : * ? " ' ` < > | { } [ ]

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| displayName  | string        | Yes  | File name of the image or video to create.             |
| options  | [PhotoCreateOptions](#photocreateoptions)        | No  | Options for creating an image or video asset.             |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAssetChangeRequest](#mediaassetchangerequest11) | **MediaAssetChangeRequest** created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetRequestDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, testFileName);
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

### setFavorite<sup>11+</sup>

setFavorite(favoriteState: boolean): void

Favorites or unfavorites this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| favoriteState | boolean | Yes   | Operation to perform. The value **true** means to favorite the file, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  assetChangeRequest.setFavorite(true);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setFavorite failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setHidden<sup>11+</sup>

setHidden(hiddenState: boolean): void

Hides this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean  | Yes   | Whether to hide the file. The value **true** means to hide the file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  assetChangeRequest.setHidden(true);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setHidden failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setUserComment<sup>11+</sup>

setUserComment(userComment: string): void

Sets the user comment information of this media asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| userComment | string | Yes  | Comment information to set, which cannot exceed 420 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setUserCommentDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  let userComment: string = 'test_set_user_comment';
  assetChangeRequest.setUserComment(userComment);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setUserComment successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setUserComment failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setEditData<sup>11+</sup>

setEditData(editData: MediaAssetEditData): void

Saves the edited data of an asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| editData | [MediaAssetEditData](#mediaasseteditdata11) | Yes  | Edited data to save.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setEditDataDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);

  let assetEditData: photoAccessHelper.MediaAssetEditData = new photoAccessHelper.MediaAssetEditData('system', '1.0');
  let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
  assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, fileUri);
  assetEditData.data = '123456';
  assetChangeRequest.setEditData(assetEditData);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setEditData successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setEditData failed with error: ${err.code}, ${err.message}`);
  });
}
```

### addResource<sup>11+</sup>

addResource(type: ResourceType, proxy: PhotoProxy): void

Adds resources using **PhotoProxy** data.

> **NOTE**<br>For the same asset change request, this API cannot be repeatedly called after resources are successfully added.

**System API**: This is a system API available only for camera applications.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type                             | Mandatory| Description                  |
| ------- |---------------------------------| ---- |----------------------|
| type | [ResourceType](#resourcetype11) | Yes  | Type of the resource to add.           |
| proxy | [PhotoProxy](#photoproxy11)     | Yes  | PhotoProxy data of the resource to add.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
|----------|-----------------------------------|
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | System inner fail.                | 
| 14000016 | Operation Not Support.            |

**Example**

```ts
class PhotoProxyImpl implements photoAccessHelper.PhotoProxy {
  // Implement PhotoProxy.
}

async function example() {
  console.info('addResourceByPhotoProxyDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension);
    let photoProxy: PhotoProxyImpl = new PhotoProxyImpl();
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, photoProxy);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('addResourceByPhotoProxy successfully');
  } catch (err) {
    console.error(`addResourceByPhotoProxyDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setLocation<sup>11+</sup>

setLocation(longitude: number, latitude: number): void

Sets location information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type         | Mandatory| Description   |
| ------- |-------------| ---- |-------|
| longitude | number      | Yes  | Longitude.|
| latitude | number | Yes  | Latitude.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 |  System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setLocationDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
  assetChangeRequest.setLocation(120.52, 30.40);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setLocation successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setLocation failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setCameraShotKey<sup>12+</sup>

setCameraShotKey(cameraShotKey: string): void

Sets the Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| cameraShotKey | string | Yes  | Key for the Ultra Snapshot feature.<br>This parameter is available only for the system camera, and the key value is defined by the system camera.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
async function example(asset: photoAccessHelper.PhotoAsset) {
  console.info('setCameraShotKeyDemo');
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    let cameraShotKey: string = 'test_MediaAssetChangeRequest_setCameraShotKey';
    assetChangeRequest.setCameraShotKey(cameraShotKey);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply setCameraShotKey successfully');
  } catch (err) {
    console.error(`apply setCameraShotKey failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setEffectMode<sup>12+</sup>

setEffectMode(mode: MovingPhotoEffectMode): void

Sets the effect of this moving photo.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| mode | [MovingPhotoEffectMode](#movingphotoeffectmode12) | Yes  | Effect to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016       | Operation Not Support.         |

**Example**

```ts
async function example(asset: photoAccessHelper.PhotoAsset) {
  console.info('setEffectModeDemo');
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.setEffectMode(photoAccessHelper.MovingPhotoEffectMode.LONG_EXPOSURE);
    // Ensure that the asset specified by fileUri exists.
    let imageFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/long_exposure.jpg';
    let videoFileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/long_exposure.mp4';
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.IMAGE_RESOURCE, imageFileUri);
    assetChangeRequest.addResource(photoAccessHelper.ResourceType.VIDEO_RESOURCE, videoFileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply setEffectMode successfully');
  } catch (err) {
    console.error(`apply setEffectMode failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setSupportedWatermarkType<sup>14+</sup>

setSupportedWatermarkType(watermarkType: WatermarkType): void

Sets the watermark type supported by photos.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| watermarkType | [WatermarkType](#watermarktype14) | Yes  | Watermark type to set. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | Internal system error.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('setSupportedWatermarkTypeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.setSupportedWatermarkType(photoAccessHelper.WatermarkType.BRAND_COMMON);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply setSupportedWatermarkType successfully');
  } catch (err) {
    console.error(`apply setSupportedWatermarkType failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteLocalAssetsPermanently<sup>18+</sup>

static deleteLocalAssetsPermanently(context: Context, assets: Array\<PhotoAsset>): Promise&lt;void&gt;

Permanently deletes photos or videos in batches. This API uses a promise to return the result.

> **NOTE**
>
> This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assets | Array\<[PhotoAsset](#photoasset)>| Yes   | Array of images or videos to be permanently deleted.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by non-system application.       |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | Internal system error.       

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

struct Index {
  // Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
  public context = this.getUIContext().getHostContext() as common.UIAbilityContext;
  public phAccessHelper = photoAccessHelper.getPhotoAccessHelper(this.context);

  async function example() {
    console.info('deleteAssetsPermanentlyDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    try {
      let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await this.phAccessHelper.getAssets(fetchOptions);
      let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
      await photoAccessHelper.MediaAssetChangeRequest.deleteLocalAssetsPermanently(this.context, photoAssetList);
    } catch (err) {
      console.error(`deleteAssetsPermanentlyDemo failed with error: ${err.code}, ${err.message}`);
    }
  }
}
```

### setDisplayName<sup>18+</sup>

setDisplayName(displayName: string): void

Sets the file name (including the file name extension) of a media asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| displayName | string | Yes  | File name of the media asset (including the file name extension).<br>The name must meet the following requirements:<br>- The file name extension must be included.<br>- The file name (excluding the file name extension) cannot exceed 255 characters.<br>- The file name cannot contain invalid characters, such as \ / : * ?" < > \| |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | Internal system error.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  console.info('setDisplayNameDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    let newDisplayName: string = 'newDisplayName.jpg';
    assetChangeRequest.setDisplayName(newDisplayName);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('apply setDisplayName successfully');
  } catch (err) {
    console.error(`apply setDisplayName failed with error: ${err.code}, ${err.message}`);
  }
}
```

## MediaAssetsChangeRequest<sup>11+</sup>

Represents a request for changing multiple assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>11+</sup>

constructor(assets: Array&lt;PhotoAsset&gt;)

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets to change.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.          |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('MediaAssetsChangeRequest constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
}
```

### setFavorite<sup>11+</sup>

setFavorite(favoriteState: boolean): void

Favorites or unfavorites this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| favoriteState | boolean | Yes   | Operation to perform. The value **true** means to favorite the file, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
  assetsChangeRequest.setFavorite(true);
  phAccessHelper.applyChanges(assetsChangeRequest).then(() => {
    console.info('apply setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setFavorite failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setHidden<sup>11+</sup>

setHidden(hiddenState: boolean): void

Hides this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean  | Yes   | Whether to hide the file. The value **true** means to hide the file; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
  assetsChangeRequest.setHidden(true);
  phAccessHelper.applyChanges(assetsChangeRequest).then(() => {
    console.info('apply setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setHidden failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setUserComment<sup>11+</sup>

setUserComment(userComment: string): void

Sets the user comment information of this media asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| userComment | string | Yes  | Comment information to set, which cannot exceed 420 characters.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setUserCommentDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
  assetsChangeRequest.setUserComment('test_set_user_comment');
  phAccessHelper.applyChanges(assetsChangeRequest).then(() => {
    console.info('apply setUserComment successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setUserComment failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setIsRecentShow<sup>18+</sup>

setIsRecentShow(isRencentShow: boolean): void

Sets whether this asset is displayed in the **Recent** list.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| isRencentShow | boolean | Yes  | Whether this asset is displayed in the **Recent** list. The value **true** means this asset is displayed in the **Recent** list, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example() {
  console.info('setIsRecentShowDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  let assetsChangeRequest: photoAccessHelper.MediaAssetsChangeRequest = new photoAccessHelper.MediaAssetsChangeRequest(photoAssetList);
  assetsChangeRequest.setIsRecentShow(true);
  phAccessHelper.applyChanges(assetsChangeRequest).then(() => {
    console.info('apply setIsRecentShow successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setIsRecentShow failed with error: ${err.code}, ${err.message}`);
  });
}
```

## MediaAlbumChangeRequest<sup>11+</sup>

Provides APIs for managing the media album change request.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### createAlbumRequest<sup>11+</sup>

static createAlbumRequest(context: Context, name: string): MediaAlbumChangeRequest

Creates a **MediaAlbumChangeRequest** instance.

The album name must comply with the following specifications:
- The album name cannot exceed 255 characters.
- The album name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| name | string | Yes  | Name of the album.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAlbumChangeRequest](#mediaalbumchangerequest11) | **MediaAlbumChangeRequest** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

```ts
async function example() {
  console.info('createAlbumRequestDemo');
  try {
    let albumName: string = 'newAlbumName' + new Date().getTime();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = photoAccessHelper.MediaAlbumChangeRequest.createAlbumRequest(context, albumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('apply createAlbumRequest successfully');
  } catch (err) {
    console.error(`createAlbumRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAlbums<sup>11+</sup>

static deleteAlbums(context: Context, albums: Array&lt;Album&gt;): Promise&lt;void&gt;

Deletes albums. This API uses a promise to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| albums  |  Array&lt;[Album](#album)&gt;          | Yes  | Albums to delete.        |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 202   |  Called by non-system application.  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 |  System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    await photoAccessHelper.MediaAlbumChangeRequest.deleteAlbums(context, [album]);
    console.info('deleteAlbums successfully');
  } catch (err) {
    console.error(`deleteAlbumsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setCoverUri<sup>11+</sup>

setCoverUri(coverUri: string): void

Sets the album cover.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| coverUri | string | Yes  | URI of the file to be set as the album cover.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('setCoverUriDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.setCoverUri(asset.uri);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setCoverUri successfully');
  } catch (err) {
    console.error(`setCoverUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### moveAssets<sup>11+</sup>

moveAssets(assets: Array&lt;PhotoAsset&gt;, targetAlbum: Album): void

Moves assets to another album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets to move.|
| targetAlbum | Album | Yes  | Album to which the assets are to be moved.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016 |  Operation Not Support.     |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('moveAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

    if (albumFetchResult.isAfterLast()) {
      console.error('lack of album to be moved into');
      return;
    }
    let nextAlbum: photoAccessHelper.Album = await albumFetchResult.getNextObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.moveAssets([asset], nextAlbum);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('moveAssets successfully');
  } catch (err) {
    console.error(`moveAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### recoverAssets<sup>11+</sup>

recoverAssets(assets: Array&lt;PhotoAsset&gt;): void

Recovers assets from the trash.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets to recover.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016 |  Operation Not Support.     |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('recoverAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.recoverAssets([asset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('recoverAssets successfully');
  } catch (err) {
    console.error(`recoverAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAssets<sup>11+</sup>

deleteAssets(assets: Array&lt;PhotoAsset&gt;): void

Permanently deletes assets from the trash.

**NOTE**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets to be permanently deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016 |  Operation Not Support.     |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('deleteAssetsPermanentlyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.deleteAssets([asset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to deleteAssets permanently');
  } catch (err) {
    console.error(`deleteAssetsPermanentlyDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setDisplayLevel<sup>11+</sup>

setDisplayLevel(displayLevel: number): void

Sets the display level of the portrait album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| displayLevel | number | Yes   | Display level to set.<br>The options are as follows:<br>**0**: unfavorite the portrait album.<br>**1**: set the portrait album as the first to display.<br>**2**: do not display the portrait album as the first one.<br>**3**: favorite the portrait album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setDisplayLevel Example')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo('user_display_level', 2);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    let changeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    changeRequest.setDisplayLevel(1);
    await phAccessHelper.applyChanges(changeRequest);
  } catch (err) {
    console.error(`setDisplayLevel failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setIsMe<sup>11+</sup>

setIsMe(): void

Sets the relationship between people in the portrait album to **Me**.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011       | System inner fail.         |

**Example**

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setIsMe Example')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo('user_display_level', 2);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    let changeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    changeRequest.setIsMe();
    await phAccessHelper.applyChanges(changeRequest);
  } catch (err) {
    console.error(`setIsMe failed with error: ${err.code}, ${err.message}`);
  }
}
```

### dismissAssets<sup>11+</sup>

dismissAssets(assets: Array&lt;PhotoAsset&gt;): void

Removes assets from this portrait album or group photo album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;PhotoAsset&gt; | Yes   | Assets to remove.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016       | Operation Not support.         |

**Example**

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('dismissAssets Example')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo('user_display_level', 2);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();

    let predicatesAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let assetFetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesAsset
    };
    let assetFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(assetFetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await assetFetchResult.getFirstObject();

    let changeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    changeRequest.dismissAssets([asset]);
    await phAccessHelper.applyChanges(changeRequest);
  } catch (err) {
    console.error(`dismissAssets failed with error: ${err.code}, ${err.message}`);
  }
}
```

### mergeAlbum<sup>11+</sup>

mergeAlbum(target: Album): void

Merges two portrait albums.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| target | [Album](#album) | Yes   | Album generated after the merge. The album must be renamed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016       | Operation Not support.         |

**Example**

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('mergeAlbum Example')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo('user_display_level', 2);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    if (fetchResult.isAfterLast()) {
      console.error('lack of album to merge');
      return;
    }
    let target: photoAccessHelper.Album = await fetchResult.getNextObject();

    let changeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    changeRequest.mergeAlbum(target);
    changeRequest.setAlbumName("testName");
    await phAccessHelper.applyChanges(changeRequest);
  } catch (err) {
    console.error(`mergeAlbum failed with error: ${err.code}, ${err.message}`);
  }
}
```

### placeBefore<sup>11+</sup>

placeBefore(album: Album): void;

Places this album before an album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  |  Target album. To place this album to the end, set **album** to null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('placeBeforeDemo');
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let firstAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (albumFetchResult.isAfterLast()) {
      console.error('lack of album to place before');
      return;
    }
    let secondAlbum: photoAccessHelper.Album = await albumFetchResult.getNextObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(secondAlbum);
    albumChangeRequest.placeBefore(firstAlbum);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('placeBefore successfully');
  } catch (err) {
    console.error(`placeBeforeDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### dismiss<sup>13+</sup>

dismiss(): void

Removes this group photo album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: Incorrect parameter types. |
| 14000011 | System inner fail.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('dismissDemo');
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.GROUP_PHOTO);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.dismiss();
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('dismiss successfully');
  } catch (err) {
    console.error(`dismissDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## HighlightAlbum<sup>12+</sup>

Provides APIs for managing the **Highlights** album, which is an automatically generated collection of memorable photos or videos.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>12+</sup>

constructor(album: Album)

A constructor used to create a **Highlights** album instance.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| album | [Album](#album) | Yes  | **Highlights** album to create.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('HighlightAlbum constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await photoAccessHelper.getAlbums(
    photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOption);
  let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
  let highlightAlbum: photoAccessHelper.HighlightAlbum = new photoAccessHelper.HighlightAlbum(album);
  albumFetchResult.close();
}
```

### getHighlightAlbumInfo<sup>12+</sup>

getHighlightAlbumInfo(type: HighlightAlbumInfoType): Promise&lt;string&gt;

Obtains specific information about the **Highlights** album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| type       | [HighlightAlbumInfoType](#highlightalbuminfotype12) | Yes   | Type of the album information to obtain.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getHighlightAlbumInfoDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await photoAccessHelper.getAlbums(
    photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOption);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (album != undefined) {
      let highlightAlbum: photoAccessHelper.HighlightAlbum = new photoAccessHelper.HighlightAlbum(album);
      let coverInfo: string = await highlightAlbum.getHighlightAlbumInfo(
        photoAccessHelper.HighlightAlbumInfoType.COVER_INFO);
      console.info('get cover info result: ' + JSON.stringify(coverInfo));
    }
    
    albumFetchResult.close();
  } catch (err) {
    console.error(`getHighlightAlbumInfoDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### getHighlightResource<sup>12+</sup>

getHighlightResource(resourceUri: string): Promise&lt;ArrayBuffer&gt;

Obtains the ArrayBuffer for caching the specified asset.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| resourceUri       | string | Yes   | URI of the asset to cache.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getHighlightResourceDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await photoAccessHelper.getAlbums(
    photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOption);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (album != undefined) {
      let highlightAlbum: photoAccessHelper.HighlightAlbum = new photoAccessHelper.HighlightAlbum(album);
      let uri: string = 'file://media/highlight/cover/10/1_1/background.png?oper=highlight'
      let arrayBuffer: ArrayBuffer = await highlightAlbum.getHighlightResource(uri);
    }
    albumFetchResult.close();
  } catch (err) {
    console.error(`getHighlightResourceDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### setHighlightUserActionData<sup>12+</sup>

setHighlightUserActionData(type: HighlightUserActionType, actionData: number): Promise&lt;void&gt;

Sets the user behavior data for the **Highlights** album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| type       | [HighlightUserActionType](#highlightuseractiontype12) | Yes   | Type of the user behavior data to set.|
| actionData | number | Yes   | Behavior data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('setHighlightUserActionDataDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await photoAccessHelper.getAlbums(
    photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOption);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (album != undefined) {
      let highlightAlbum: photoAccessHelper.HighlightAlbum = new photoAccessHelper.HighlightAlbum(album);
      highlightAlbum.setHighlightUserActionData(photoAccessHelper.HighlightUserActionType.INSERTED_PIC_COUNT, 1);
    }
    albumFetchResult.close();
  } catch (err) {
    console.error(`setHighlightUserActionDataDemofailed with error: ${err.code}, ${err.message}`);
  }
}
```

### setSubTitle<sup>18+</sup> 

setSubTitle(title: string): void

Sets the subtitle for this **Highlights** album instance.

The subtitle must meet the following requirements:

- The subtitle string contains 0 to 255 characters.
- The subtitle cannot contain any of the following characters:<br> . \ / : * ? " ' ` < > | { } [ ]
- The subtitle is case-insensitive.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| title       | string | Yes   | Subtitle to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try {
    console.info('setSubTitle');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    let changeHighlightAlbumRequest: photoAccessHelper.HighlightAlbum = new photoAccessHelper.HighlightAlbum(highlightAlbum);
    changeHighlightAlbumRequest.setSubTitle("testName");
    console.info('setSubTitle success');
  } catch (err) {
    console.error(`setSubTitle with error: ${err}`);
  }
}
```

### deleteHighlightAlbums<sup>18+</sup>

static deleteHighlightAlbums(context: Context, albums: Array&lt;Album&gt;): Promise&lt;number&gt;

Deletes highlight albums.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| albums       | Array&lt;[Album](#album)&gt;   | Yes   | Array of highlight albums to delete.|

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;number&gt; | Promise used to return the operation result. The value **0** means that the operation is successful, and **-1** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try {
    console.info('deleteHighlightAlbums');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    let result = await photoAccessHelper.HighlightAlbum.deleteHighlightAlbums(context, [highlightAlbum]);
    console.info('deleteHighlightAlbums success');
  } catch (err) {
    console.error(`deleteHighlightAlbums with error: ${err}`);
  }
}
```

## MediaAnalysisAlbumChangeRequest<sup>18+</sup> 

Provides APIs for managing the analysis album change request.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>18+</sup> 

constructor(album: Album)

A constructor used to create an **Analysis** album instance.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  | **Analysis** album to create.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';s

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('MediaAnalysisAlbumChangeRequest constructorDemo');
  let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  let albumFetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: new dataSharePredicates.DataSharePredicates()
  };
  let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
    await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
  if (albumFetchResult.getCount() === 0) {
    console.error('No album');
    return;
  }
  let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
  albumFetchResult.close();
  let changeRequest: photoAccessHelper.MediaAnalysisAlbumChangeRequest =
    new photoAccessHelper.MediaAnalysisAlbumChangeRequest(highlightAlbum);
}
```

### setOrderPosition<sup>18+</sup> 

setOrderPosition(assets: Array&lt;PhotoAsset&gt;, position: Array&lt;number&gt;): void

Sets the sequence of assets in the **Analysis** album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets in the album for which the sequence needs to be set.|
| position       | Array&lt;number&gt;   | Yes   | Sequence of assets in the album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try {
    console.info('setOrderPosition');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = 
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    const fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> =
      await highlightAlbum.getAssets(fetchOption);
    let assets: photoAccessHelper.PhotoAsset[] = await fetchResult.getAllObjects();
    let indexes: number[] = [];
    for (let i = 0; i < assets.length; i++) {
      indexes.push(i);
    }
    let changeRequest: photoAccessHelper.MediaAnalysisAlbumChangeRequest =
      new photoAccessHelper.MediaAnalysisAlbumChangeRequest(highlightAlbum);
    changeRequest.setOrderPosition(assets, indexes);
    await helper.applyChanges(changeRequest);
    console.info(`setOrderPosition ${indexes}`);
  } catch (err) {
    console.error(`setOrderPosition error: ${err}`);
  }
}
```

## AnalysisAlbum<sup>18+</sup> 

**Analysis** album to create.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>18+</sup> 

constructor(album: Album)

A constructor used to create an **Analysis** album instance.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  | **Analysis** album to create.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('AnalysisAlbum constructorDemo');
  let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  let albumFetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: new dataSharePredicates.DataSharePredicates()
  };
  let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = 
    await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
  if (albumFetchResult.getCount() === 0) {
    console.error('No album');
    return;
  }
  let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
  albumFetchResult.close();
  let analysisAlbum: photoAccessHelper.AnalysisAlbum = new photoAccessHelper.AnalysisAlbum(highlightAlbum);
}
```

### getOrderPosition<sup>18+</sup> 

getOrderPosition(assets: Array&lt;PhotoAsset&gt;): Promise&lt;Array&lt;number&gt;&gt;

Obtains the sequence of assets in the **Analysis** album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Assets in the album whose sequence needs to be obtained.|

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Sequence number of an asset in the album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  try {
    console.info('getOrderPosition');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = 
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let highlightAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let analysisAlbum: photoAccessHelper.AnalysisAlbum = new photoAccessHelper.AnalysisAlbum(highlightAlbum);
    const fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = 
      await highlightAlbum.getAssets(fetchOption);
    let assets: photoAccessHelper.PhotoAsset[] = await fetchResult.getAllObjects();
    let positions: number[] = await analysisAlbum.getOrderPosition(assets);
    console.info(`getOrderPosition ${positions}`);
  } catch (err) {
    console.error(`getOrderPosition error: ${err}`);
  }
}
```

## CloudEnhancement<sup>13+</sup>

Provides APIs for cloud enhancement management, including managing the tasks of generating AI-powered cloud enhancement photos and obtaining the association between the original photos and AI cloud enhancement photos.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### getCloudEnhancementInstance<sup>13+</sup>

static getCloudEnhancementInstance(context: Context): CloudEnhancement

Obtains a cloud enhancement instance.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('getCloudEnhancementInstanceDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    let hasCloudWatermark = true;
    await cloudEnhancementInstance.submitCloudEnhancementTasks([asset], hasCloudWatermark);
  } catch (err) {
    console.error(`getCloudEnhancementInstanceDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### submitCloudEnhancementTasks<sup>13+</sup>

submitCloudEnhancementTasks(photoAssets: Array&lt;PhotoAsset&gt;, hasCloudWatermark: boolean): Promise&lt;void&gt;

Submits cloud enhancement tasks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | [PhotoAsset](#photoasset) to enhance.|
| hasCloudWatermark | boolean | Yes  | Whether to add a cloud enhancement watermark to the enhanced images.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('submitCloudEnhancementTasksDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    let hasCloudWatermark = true;
    await cloudEnhancementInstance.submitCloudEnhancementTasks([asset], hasCloudWatermark);
  } catch (err) {
    console.error(`submitCloudEnhancementTasksDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### submitCloudEnhancementTasks<sup>18+</sup>

submitCloudEnhancementTasks(photoAssets: Array&lt;PhotoAsset&gt;, hasCloudWatermark: boolean, triggerMode?: number): Promise&lt;void&gt;

Submits cloud enhancement tasks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | [PhotoAsset](#photoasset) to enhance.|
| hasCloudWatermark | boolean | Yes  | Whether to add a cloud watermark to the enhanced image. The value **true** means to add the watermark, and **false** means the opposite.|
| triggerMode | number | No  | Trigger mode of the cloud enhancement task.<br>**- 0**: manually triggered.<br>**- 1**: automatically triggered.<br>The default value is **0**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('submitCloudEnhancementTasksDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    let hasCloudWatermark = true;
    let triggerAuto = 1;
    await cloudEnhancementInstance.submitCloudEnhancementTasks([asset], hasCloudWatermark, triggerAuto);
  } catch (err) {
    console.error(`submitCloudEnhancementTasksDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### prioritizeCloudEnhancementTask<sup>13+</sup>

prioritizeCloudEnhancementTask(photoAsset: PhotoAsset): Promise&lt;void&gt;

Prioritizes a cloud enhancement task.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAsset | [PhotoAsset](#photoasset) | Yes  | [PhotoAsset](#photoasset) whose cloud enhancement priority needs to be escalated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('prioritizeCloudEnhancementTaskDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  // Obtain the cloud enhancement tasks in progress.
  photoPredicates.equalTo(photoAccessHelper.PhotoKeys.CE_AVAILABLE, 2);
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    let hasCloudWatermark = true;
    await cloudEnhancementInstance.prioritizeCloudEnhancementTask(asset);
  } catch (err) {
    console.error(`prioritizeCloudEnhancementTaskDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cancelCloudEnhancementTasks<sup>13+</sup>

cancelCloudEnhancementTasks(photoAssets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Cancels cloud enhancement tasks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | Array of [PhotoAssets](#photoasset) whose cloud enhancement tasks are to be canceled.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('cancelCloudEnhancementTasksDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  // Obtain the cloud enhancement tasks in progress.
  photoPredicates.equalTo(photoAccessHelper.PhotoKeys.CE_AVAILABLE, 2);
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    await cloudEnhancementInstance.cancelCloudEnhancementTasks([asset]);
  } catch (err) {
    console.error(`cancelCloudEnhancementTasksDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cancelAllCloudEnhancementTasks<sup>13+</sup>

cancelAllCloudEnhancementTasks(): Promise&lt;void&gt;

Cancels all cloud enhancement tasks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('cancelAllCloudEnhancementTasksDemo');
  try {
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    await cloudEnhancementInstance.cancelCloudEnhancementTasks();
  } catch (err) {
    console.error(`cancelAllCloudEnhancementTasksDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### queryCloudEnhancementTaskState<sup>13+</sup>

queryCloudEnhancementTaskState(photoAsset: PhotoAsset): Promise&lt;CloudEnhancementTaskState&gt;

Queries information about a cloud enhancement task.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAsset | [PhotoAsset](#photoasset) | Yes  | [PhotoAsset](#photoasset) whose cloud enhancement task information is to be queried.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('queryCloudEnhancementTaskStateDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  // Obtain the cloud enhancement tasks in progress.
  photoPredicates.equalTo(photoAccessHelper.PhotoKeys.CE_AVAILABLE, 2);
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    const cloudEnhancementTaskState: photoAccessHelper.CloudEnhancementTaskState
      = await cloudEnhancementInstance.queryCloudEnhancementTaskState(asset);
    let taskStage = cloudEnhancementTaskState.taskStage;
    if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_EXCEPTION) {
      console.log("task has exception");
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_PREPARING) {
      console.log("task is preparing");
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_UPLOADING) {
      let transferredFileSize = cloudEnhancementTaskState.transferredFileSize;
      let totalFileSize = cloudEnhancementTaskState.totalFileSize;
      let message = `task is uploading, transferredFileSize: ${transferredFileSize}, totalFileSize: ${totalFileSize}`;
      console.log(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_EXECUTING) {
      let expectedDuration = cloudEnhancementTaskState.expectedDuration;
      let message = `task is executing, expectedDuration: ${expectedDuration}`;
      console.log(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING) {
      let transferredFileSize = cloudEnhancementTaskState.transferredFileSize;
      let totalFileSize = cloudEnhancementTaskState.totalFileSize;
      let message = `task is downloading, transferredFileSize: ${transferredFileSize}, totalFileSize: ${totalFileSize}`;
      console.log(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_FAILED) {
      let errCode = cloudEnhancementTaskState.statusCode;
      let message = `task is failed, errCode: ${errCode}`;
      console.log(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_COMPLETED) {
      console.log("task is completed");
    }
  } catch (err) {
    console.error(`queryCloudEnhancementTaskStateDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### syncCloudEnhancementTaskStatus<sup>13+</sup>

syncCloudEnhancementTaskStatus(): Promise&lt;void&gt;

Synchronizes the cloud enhancement task status.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('syncCloudEnhancementTaskStatusDemo');
  try {
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    await cloudEnhancementInstance.syncCloudEnhancementTaskStatus();
  } catch (err) {
    console.error(`syncCloudEnhancementTaskStatusDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getCloudEnhancementPair<sup>13+</sup>

getCloudEnhancementPair(asset: PhotoAsset): Promise&lt;PhotoAsset&gt;

Obtains the photo after cloud enhancement.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAsset | [PhotoAsset](#photoasset) | Yes  | [PhotoAsset](#photoasset) whose cloud enhancement photo is to be obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  console.info('getCloudEnhancementPairDemo');
  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  // Query the completed cloud enhancement tasks.
  photoPredicates.equalTo(photoAccessHelper.PhotoKeys.CE_AVAILABLE, 5);
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };
  let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  try {
    let fetchResult = await phAccessHelper.getAssets(photoFetchOptions);
    let asset = await fetchResult.getLastObject();
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    let photoAsset: photoAccessHelper.PhotoAsset
      = await cloudEnhancementInstance.getCloudEnhancementPair(asset);
  } catch (err) {
    console.error(`getCloudEnhancementPairDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setVideoEnhancementAttr<sup>13+</sup>

setVideoEnhancementAttr(videoEnhancementType: VideoEnhancementType, photoId: string): Promise&lt;void&gt;

Sets the attributes for deferred video enhancement.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| videoEnhancementType       | [VideoEnhancementType](#videoenhancementtype13) | Yes   | Type of video enhancement.|
| photoId | string | Yes   | Photo ID of the image.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |
| 14000016 | Operation Not Support.            |

**Example**

```ts
async function example(asset: photoAccessHelper.PhotoAsset) {
  try {
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    let photoId = "202410011800";
    assetChangeRequest.setVideoEnhancementAttr(photoAccessHelper.VideoEnhancementType.QUALITY_ENHANCEMENT_LOCAL, photoId);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error(`setVideoEnhancementAttr fail with error: ${err.code}, ${err.message}`);
  }
}
```

### getFaceId<sup>13+</sup>

getFaceId(): Promise\<string>

Obtains the face identifier on the cover of a portrait album or group photo album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;string&gt; | Promise used to return **tag_id** of the portrait album, **group_tag** of the group photo album, or an empty string if no face identifier is found.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message                                                    |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 14000011 | Internal system error                                        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example() {
  try {
    console.info('getFaceIdDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.equalTo("user_display_level", 1);
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult =
      await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT,
        fetchOptions);
    let album = await fetchResult?.getFirstObject();
    let faceId = await album?.getFaceId();
    console.info(`getFaceId successfully, faceId: ${faceId}`);
    fetchResult.close();
  } catch (err) {
    console.error(`getFaceId failed with err: ${err.code}, ${err.message}`);
  }
}
```

## CloudMediaAssetManager<sup>14+</sup>

A class used for cloud media asset management. It is used to manage download tasks for media assets stored in the cloud and delete local data and files pertaining to these cloud-based assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### getCloudMediaAssetManagerInstance<sup>14+</sup>

static getCloudMediaAssetManagerInstance(context: Context): CloudMediaAssetManager

Obtains a CloudMediaAssetManager instance.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [CloudMediaAssetManager](#cloudmediaassetmanager14) | CloudMediaAssetManager instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.          |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('getCloudMediaAssetManagerInstanceDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.pauseDownloadCloudMedia();
  } catch (err) {
    console.error(`getCloudMediaAssetManagerInstanceDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### startDownloadCloudMedia<sup>14+</sup>

startDownloadCloudMedia(downloadType: CloudMediaDownloadType): Promise&lt;void&gt;

Starts or resumes a task to download cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| downloadType | [CloudMediaDownloadType](#cloudmediadownloadtype14) | Yes  | Type of the download task.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.           |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('startDownloadCloudMediaDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.startDownloadCloudMedia(photoAccessHelper.CloudMediaDownloadType.DOWNLOAD_FORCE);
  } catch (err) {
    console.error(`startDownloadCloudMediaDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### pauseDownloadCloudMedia<sup>14+</sup>

pauseDownloadCloudMedia(): Promise&lt;void&gt;

Suspends a task that downloads cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('pauseDownloadCloudMediaDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.pauseDownloadCloudMedia();
  } catch (err) {
    console.error(`pauseDownloadCloudMediaDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cancelDownloadCloudMedia<sup>14+</sup>

cancelDownloadCloudMedia(): Promise&lt;void&gt;

Cancels a task that downloads cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('cancelDownloadCloudMediaDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.cancelDownloadCloudMedia();
  } catch (err) {
    console.error(`cancelDownloadCloudMediaDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### retainCloudMediaAsset<sup>14+</sup>

retainCloudMediaAsset(retainType: CloudMediaRetainType): Promise&lt;void&gt;

Deletes local metadata and files of cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| retainType | [CloudMediaRetainType](#cloudmediaretaintype14) | Yes  | Mode for deleting cloud media assets.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('retainCloudMediaAssetDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.retainCloudMediaAsset(photoAccessHelper.CloudMediaRetainType.RETAIN_FORCE);
  } catch (err) {
    console.error(`retainCloudMediaAssetDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getCloudMediaAssetStatus<sup>14+</sup>

getCloudMediaAssetStatus(): Promise&lt;CloudMediaAssetStatus&gt;

Obtains the status of a task that downloads cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;[CloudMediaAssetStatus](#cloudmediaassetstatus14)&gt; | Promise used to return the task status.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 14000011 | Internal system error. It is recommended to retry and check the logs. Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;

async function example() {
  console.info('getCloudMediaAssetStatusDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    const cloudMediaAssetStatus: photoAccessHelper.CloudMediaAssetStatus = await cloudMediaAssetManagerInstance.getCloudMediaAssetStatus();
    let taskStatus = cloudMediaAssetStatus.taskStatus;
    let taskInfo = cloudMediaAssetStatus.taskInfo;
    let errorCode = cloudMediaAssetStatus.errorCode;
    let message = `taskStatus: ${taskStatus}, taskInfo: ${taskInfo}, errorCode: ${errorCode}`;
    console.log(message);
  } catch (err) {
    console.error(`getCloudMediaAssetStatusDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## PhotoSelectOptions

Defines additional options for selecting media assets from Gallery. It inherits from **BaseSelectOptions**. It is used to start the picker of the corresponding user ID space.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| userId<sup>18+</sup> | number  | No  | ID of the user space to access. The default value is **-1**.<br>To use it as a parameter of [PhotoViewPicker.select](js-apis-photoAccessHelper.md#select), request the permission ohos.permission.INTERACTA_CROSS_LOCAL_ACCOUNTS.<br>**System API**: This is a system API.|

**Example**

```ts
  private photoPicker() {
    let picker = new photoAccessHelper.PhotoViewPicker();
    let option = new photoAccessHelper.PhotoSelectOptions();
    option.userId = 101;
    picker.select(option);
  }
```

## PhotoSubtype

Enumerates the [PhotoAsset](#photoasset) types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| SCREENSHOT |  1 |  Screenshot and screen recording file.<br>**System API**: This is a system API.|

## AlbumType

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                 | Value   | Description                       |
| ------------------- | ---- | ------------------------- |
| SOURCE<sup>18+</sup> | 2048 | Source album.<br>**System API**: This is a system API.|
| SMART<sup>11+</sup> | 4096 | Smart analysis album.<br>**System API**: This is a system API.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                               | Value         | Description                             |
| --------------------------------- | ---------- | ------------------------------- |
| HIDDEN                            | 1027       | Hidden album. <br>**System API**: This is a system API.        |
| TRASH                             | 1028       | Trash. <br>**System API**: This is a system API.         |
| SCREENSHOT                        | 1029       | Album for screenshots and screen recording files. <br>**System API**: This is a system API.     |
| CAMERA                            | 1030       | Album for photos and videos taken by the camera. <br>**System API**: This is a system API.|
| SOURCE\_GENERIC<sup>11+</sup>     | 2049       | Source album. <br>**System API**: This is a system API.        |
| CLASSIFY<sup>11+</sup>            | 4097       | Classified album. <br>**System API**: This is a system API.        |
| GEOGRAPHY\_LOCATION<sup>11+</sup> | 4099       | Geographic location album. <br>**System API**: This is a system API.        |
| GEOGRAPHY\_CITY<sup>11+</sup>     | 4100       | City album. <br>**System API**: This is a system API.        |
| SHOOTING\_MODE<sup>11+</sup>      | 4101       | Shooting mode album. <br>**System API**: This is a system API.      |
| PORTRAIT<sup>11+</sup>            | 4102       | Portrait album. <br>**System API**: This is a system API.        |
| GROUP_PHOTO<sup>13+</sup>         | 4103       | Group photo album. <br>**System API**: This is a system API.        |
| HIGHLIGHT<sup>12+</sup>           | 4104       | Highlights album. <br>**System API**: This is a system API.        |
| HIGHLIGHT_SUGGESTIONS<sup>12+</sup> | 4105     | Highlights suggestion album. <br>**System API**: This is a system API.        |
| CLOUD_ENHANCEMENT<sup>13+</sup> | 1032     | AI-powered cloud enhanced album. <br>**System API**: This is a system API.        |

## RequestPhotoType<sup>11+</sup>

Enumerates the types of the operation for obtaining image or video thumbnails.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| REQUEST_ALL_THUMBNAILS  |  0 |  Obtain both the quick thumbnail and the quality thumbnail.|
| REQUEST_FAST_THUMBNAIL |  1 |  Obtain only the quick thumbnail.|
| REQUEST_QUALITY_THUMBNAIL |  2 |  Obtain only the quality thumbnail.|

## PhotoKeys

Defines the key information about an image or video file.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| DATE_TRASHED  | 'date_trashed'  | Date when the file was deleted. The value is the number of seconds elapsed since the Epoch time. <br>**System API**: This is a system API.                |
| HIDDEN  | 'hidden'            | Whether the file is hidden. <br>**System API**: This is a system API.                              |
| CAMERA_SHOT_KEY  | 'camera_shot_key'  | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.) <br>**System API**: This is a system API.           |
| USER_COMMENT<sup>10+</sup>  | 'user_comment'            | User comment information. <br>**System API**: This is a system API.          |
| DATE_YEAR<sup>11+</sup>  | 'date_year'            | Year when the file was created. <br>**System API**: This is a system API.          |
| DATE_MONTH<sup>11+</sup>  | 'date_month'            | Month when the file was created. <br>**System API**: This is a system API.          |
| DATE_DAY<sup>11+</sup>  | 'date_day'            | Date when the file was created. <br>**System API**: This is a system API.          |
| PENDING<sup>11+</sup>  | 'pending'            | Pending state. <br>**System API**: This is a system API.          |
| DATE_TRASHED_MS<sup>12+</sup>  | 'date_trashed_ms'  | Date when the file was deleted. The value is the number of milliseconds elapsed since the Epoch time. **System API**: This is a system API.<br>**NOTE**: The photos queried cannot be sorted based on this field.|
| MOVING_PHOTO_EFFECT_MODE<sup>12+</sup>  | 'moving_photo_effect_mode' | Effect of the moving photo. <br>**System API**: This is a system API.|
| CE_AVAILABLE<sup>13+</sup>  | 'ce_available' | Cloud enhancement identifier. <br>**System API**: This is a system API.|
| SUPPORTED_WATERMARK_TYPE<sup>14+</sup>  | 'supported_watermark_type' | Editable watermark identifier. <br>**System API**: This is a system API.|
| IS_CE_AUTO<sup>18+</sup>  | 'is_auto' | Specifies whether automatic cloud enhancement is supported. <br>**System API**: This is a system API.|
| OWNER_ALBUM_ID<sup>18+</sup>  | 'owner_album_id' | ID of the album to which the photo belongs.<br>**System API**: This is a system API.|
| IS_RECENT_SHOW<sup>18+</sup>  | 'is_recent_show' | Whether the asset is displayed in the **Recent** list. <br>**System API**: This is a system API.|

## AlbumKeys

Enumerates the album keys.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                             | Value                   | Description                                                      |
| --------------------------------- | -------------------- | ----------------------------------------------------- |
| ALBUM_LPATH<sup>18+</sup>          | 'lpath'                 | Virtual path of the album.<br>**System API**: This is a system API.           |
| BUNDLE_NAME<sup>18+</sup>          | 'bundle_name'                 | Bundle name of the album.<br>**System API**: This is a system API.           |
| DATE_MODIFIED<sup>18+</sup>        | 'date_modified'         | Timestamp when the album was modified, in milliseconds.<br>**System API**: This is a system API.           |

## HiddenPhotosDisplayMode<sup>11+</sup>

Enumerates the display modes of hidden files in the system.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| ASSETS_MODE   | 0       | Display all hidden files in the system.   |
| ALBUMS_MODE    | 1    | Display hidden files by album (display all albums that contain hidden files in the system, excluding the preset hidden album and the albums in the trash). |

## PhotoCreateOptions

Options for creating an image or video asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| subtype           | [PhotoSubtype](#photosubtype) | No | Subtype of the image or video. |
| cameraShotKey           | string | No | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.)  |

## RequestPhotoOptions<sup>11+</sup>

Defines the options for obtaining the thumbnail of an image or video.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| size           | [image.Size](../apis-image-kit/js-apis-image.md#size) | No | Size of the thumbnail to obtain. |
| requestPhotoType    | [RequestPhotoType](#requestphototype11) | No | Operation to perform. |

## PhotoCreationSource<sup>18+</sup>

Defines the application information provided to create assets on behalf of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---- | ---- | ------------------------------------------------ |
| bundleName           | string | Yes | Yes |Bundle name of the target application. |
| appName    | string | Yes | Yes |Name of the target application. |
| appId    | string | Yes | Yes |ID of the target application. |
| tokenId    | number | Yes | Yes |Token ID of the target application. |

## RequestOptions<sup>11+</sup>

Represents request options.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type                             | Readable| Writable| Description                                             |
| ---------------------- |---------------------------------| ---- |---- | ------------------------------------------------ |
| sourceMode           | [SourceMode](#sourcemode11)     | Yes  | Yes  | Type of the asset file requested, which can be the original file or edited file. <br>**System API**: This is a system API.|

## PhotoProxy<sup>11+</sup>

Photo proxy object, which is used by the camera application to write image data.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## MediaChangeRequest<sup>11+</sup>

Media change request, which is the parent class of the asset change request and album change request.

> **NOTE**<br>The media change request takes effect only after [applyChanges](js-apis-photoAccessHelper.md#applychanges11) is called.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## FormInfo<sup>11+</sup>

Defines the Gallery widget information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
|formId       |string  |Yes| Widget ID, which is provided when a widget is created in Gallery.|
|uri          |string  |Yes| URI of the image bound to the widget. When a widget is created, **uri** can be empty or the URI of an image. When a widget is removed, **uri** is not verified and can be empty. |

## GalleryFormInfo<sup>18+</sup>

Defines the Gallery widget information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
|formId             |string               |Yes| Widget ID, which is provided when a widget is created in Gallery.|
|assetUris          |Array&lt;string&gt;  |Yes| URIs of the images or albums bound to the widget. This parameter is mandatory when a widget is created or updated and is optional when a widget is removed. |

## ResourceType<sup>11+</sup>

Enumerates the types of the resources to write.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| PHOTO_PROXY |  3 |  Photo proxy. <br>**System API**: This is a system API.|
| PRIVATE_MOVING_PHOTO_RESOURCE<sup>13+</sup> |  4 |  Private moving photo. <br>**System API**: This is a system API.|
| PRIVATE_MOVING_PHOTO_METADATA<sup>18+</sup> |  5 |  Metadata resource of the private moving photo. <br>**System API**: This is a system API.|

## DefaultChangeUri

Enumerates the **DefaultChangeUri** subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name             | Value                     | Description                                                        |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_HIDDEN_ALBUM_URI<sup>11+</sup>  | 'file://media/HiddenAlbum' | URI of an album in the hidden albums that are displayed by album, that is, the URI of an album with hidden files. Such albums do not include the preset hidden album and the albums in the trash. This URI is used to subscribe to the change notifications of the hidden albums displayed by album. <br>**System API**: This is a system API.|

## SourceMode<sup>11+</sup>

Enumerates the types of the file to read.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| ORIGINAL_MODE |  0 |  Original file.|
| EDITED_MODE |  1 |  Edited file.|
## AuthorizationMode<sup>12+</sup>

Enumerates the authorization modes.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| SHORT_TIME_AUTHORIZATION|  0 |  Temporary authorization.|

## AnalysisType<sup>11+</sup>

Enumerates the smart analysis types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                           | Value | Description      |
| :---------------------------- | :- | :------- |
| ANALYSIS\_AESTHETICS\_SCORE   | 0  | Aesthetics score. <br>**System API**: This is a system API.   |
| ANALYSIS\_LABEL               | 1  | Label. <br>**System API**: This is a system API.   |
| ANALYSIS\_OCR                 | 2  | Optical character recognition (OCR) analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_FACE                | 3  | Facial detection analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_OBJECT              | 4  | Object detection analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_RECOMMENDATION      | 5  | Recommendation analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_SEGMENTATION        | 6  | Segmentation analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_COMPOSITION         | 7  | Aesthetic composition analysis. <br>**System API**: This is a system API.  |
| ANALYSIS\_SALIENCY            | 8  | Salience analysis. <br>**System API**: This is a system API.  |
| ANALYSIS\_DETAIL\_ADDRESS     | 9  | Detailed address analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_HUMAN\_FACE\_TAG<sup>12+</sup>    | 10 | Face clustering analysis. <br>**System API**: This is a system API.   |
| ANALYSIS\_HEAD\_POSITION<sup>12+</sup>      | 11 | Analysis of the position of a person's or pet's head. <br>**System API**: This is a system API.   |
| ANALYSIS\_BONE\_POSE<sup>12+</sup>        | 12 | Analysis of the position of skeletal elements (bones) in a human body. <br>**System API**: This is a system API.   |
| ANALYSIS\_VIDEO\_LABEL<sup>12+</sup>        | 13 | Video label analysis. <br>**System API**: This is a system API.   |

## HighlightAlbumInfoType<sup>12+</sup>

Enumerates the types of the highlights album information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name           | Value | Description      |
| :------------ | :- | :------- |
| COVER\_INFO   | 0  | Cover information.   |
| PLAY\_INFO    | 1  | Music information.   |

## HighlightUserActionType<sup>12+</sup>

Enumerates the user behavior types of the highlights album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                          | Value | Description      |
| :---------------------------- | :- | :------- |
| INSERTED\_PIC\_COUNT          | 0  | Number of inserted pictures.   |
| REMOVED\_PIC\_COUNT           | 1  | Number of removed pictures.   |
| SHARED\_SCREENSHOT\_COUNT     | 2  | Number of times that a full-length image in a highlights album is shared.   |
| SHARED\_COVER\_COUNT          | 3  | Number of times that a highlights cover is shared.   |
| RENAMED\_COUNT                | 4  | Number of times that a highlights album is renamed.   |
| CHANGED\_COVER\_COUNT         | 5  | Number of times that a cover is changed.   |
| RENDER\_VIEWED\_TIMES         | 100  | Number of times that the pictures in a highlights album are played.   |
| RENDER\_VIEWED\_DURATION      | 101  | Time used to play the pictures in a highlights album.  |
| ART\_LAYOUT\_VIEWED\_TIMES    | 102  | Number of times that a highlights album is viewed.  |
| ART\_LAYOUT\_VIEWED\_DURATION | 103  | Time used to view a highlights album.   |

## MovingPhotoEffectMode<sup>12+</sup>

Enumerates the effects of a moving photo.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                          | Value | Description      |
| :---------------------------- | :- | :------- |
| DEFAULT          | 0  | Default effect.|
| BOUNCE\_PLAY     | 1  | Back-and-forth motion.|
| LOOP\_PLAY       | 2  | Continuously repeated animation.|
| LONG\_EXPOSURE   | 3  | Long exposure. |
| MULTI\_EXPOSURE  | 4  | Multiple exposures. |
| CINEMA\_GRAPH<sup>13+</sup>  | 5  | Cinemagraph. |
| IMAGE\_ONLY<sup>13+</sup>  | 10  | Image only. |

## PhotoPermissionType<sup>12+</sup>

Enumerates the types of permissions for accessing media assets.

The permissions include temporary read permission and persistent read permission. The temporary read permission will be removed when the application is dead, while the persistent read permission will not.

For the same media asset and application, the persistent read permission overwrites the temporary read permission. The temporary read permission does not overwrite the persistent read permission.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| TEMPORARY_READ_IMAGEVIDEO |  0 |  Temporary read permission.|
| PERSISTENT_READ_IMAGEVIDEO |  1 |  Persistent read permission.|

## HideSensitiveType<sup>12+</sup>

Enumerates the types of media resource information to be hidden from an application.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| HIDE_LOCATION_AND_SHOOTING_PARAM |  0 |  Geographical location and shooting parameters.|
| HIDE_LOCATION_ONLY |  1 |  Geographical location information.|
| HIDE_SHOOTING_PARAM_ONLY |  2 |  Shooting parameters.|
| NO_HIDE_SENSITIVE_TYPE |  3 |  Do not hide any information.|

## CloudEnhancementTaskStage<sup>13+</sup>

Enumerates the cloud enhancement task states, which are returned by [CloudEnhancementTaskState](#cloudenhancement13).

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| TASK_STAGE_EXCEPTION |  -1 |  The cloud enhancement task is abnormal.|
| TASK_STAGE_PREPARING |  0 |  The cloud enhancement task is being prepared.|
| TASK_STAGE_UPLOADING |  1 |  The cloud enhancement task is uploading data.|
| TASK_STAGE_EXECUTING |  2 |  The cloud enhancement task is being executed.|
| TASK_STAGE_DOWNLOADING |  3 |  The cloud enhancement task is downloading data.|
| TASK_STAGE_FAILED |  4 |  The cloud enhancement task failed.|
| TASK_STAGE_COMPLETED |  5 |  The cloud enhancement task is complete.|

## CloudEnhancementState<sup>13+</sup>

Enumerates the cloud enhancement states.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| UNAVAILABLE |  0 |  Cloud enhancement is unavailable.|
| AVAILABLE |  1 |  Cloud enhancement is available.|
| EXECUTING |  2 |  Cloud enhancement is being executed.|
| COMPLETED |  3 |  Cloud enhancement has been completed.|

## CloudEnhancementTaskState<sup>13+</sup>

Represents the cloud enhancement task information, which includes the cloud enhancement task state and other information related to certain states.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
|taskStage       |[CloudEnhancementTaskStage](#cloudenhancementtaskstage13)  |Yes| Cloud enhancement task state.|
|transferredFileSize          |number  |No| Size of the file transferred. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_UPLOADING** or **CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING**. |
|totalFileSize          |number  |No| Total file size. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_UPLOADING** or **CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING**. |
|expectedDuration          |number  |No| Queuing time. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_EXECUTING**. |
|statusCode          |number  |No| Status code. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_FAILED**. |

## VideoEnhancementType<sup>13+</sup>

Enumerates the types of segmented video enhancement.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| QUALITY_ENHANCEMENT_LOCAL |  0 |  Apply enhancement on the device.|
| QUALITY_ENHANCEMENT_CLOUD |  1 |  Apply enhancement on the cloud.|
| QUALITY_ENHANCEMENT_LOCAL_AND_CLOUD |  2 |  Apply enhancement on both the device and cloud.|

## ThumbnailType<sup>13+</sup>

Enumerates thumbnail types.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                          | Value | Description      |
| :---------------------------- | :- | :------- |
| LCD         | 1  | LCD thumbnail.   |
| THM          | 2 | THM thumbnail.   |

## WatermarkType<sup>14+</sup>

Enumerates the watermark editable flags.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Watermarks are not editable.|
| BRAND_COMMON |  1 |  Brand and common watermarks are editable.|
| COMMON |  2 |  Common watermarks are editable.|
| BRAND |  3 |  Brand watermarks are editable.|

## CloudMediaDownloadType<sup>14+</sup>

Enumerates the types of download tasks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DOWNLOAD_FORCE |  0 |  High-priority download, without the need for the device to switch to screen-off charging mode.|
| DOWNLOAD_GENTLE |  1 |  Low-priority download, demanding that device be in screen-off charging mode.|

## CloudMediaRetainType<sup>14+</sup>

Enumerates the modes used for deleting cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| RETAIN_FORCE |  0 |  Deletes the local metadata and thumbnail of the original files from the cloud.|

## CloudMediaAssetTaskStatus<sup>14+</sup>

Enumerates the statuses of tasks used for downloading cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DOWNLOADING |  0 |  The task is in progress.|
| PAUSED |  1 |  The task is paused.|
| IDLE |  2 |  There is no download task.|

## CloudMediaTaskPauseCause<sup>14+</sup>

Enumerates the reasons why a cloud media asset download task is paused.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| NO_PAUSE  |  0 |  Downloading is proceeding normally without any pauses.|
| TEMPERATURE_LIMIT |  1 |  The device temperature is excessively high.|
| ROM_LIMIT |  2 |  The local disk space is insufficient.|
| NETWORK_FLOW_LIMIT |  3 |  Network traffic is restricted, and Wi-Fi is not available.|
| WIFI_UNAVAILABLE |  4 |  The network is abnormal.|
| POWER_LIMIT |  5 |  Power usage is restricted.|
| BACKGROUND_TASK_UNAVAILABLE |  6 |  The device is not in charging screen-off mode.|
| FREQUENT_USER_REQUESTS |  7 |  The user is making requests too frequently.|
| CLOUD_ERROR |  8 |  There is an error with the cloud service.|
| USER_PAUSED |  9 |  The download has been paused by the user.|

## CloudMediaAssetStatus<sup>14+</sup>

Describes the details of a cloud media asset download task. It is the return value of the API used by applications to obtain the cloud asset download task status.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
|taskStatus       |[CloudMediaAssetTaskStatus](#cloudmediaassettaskstatus14)  |Yes| Status of the download task.|
|taskInfo          |string  |Yes| Total number of and size (measured in bytes) of the assets that have been downloaded, and the total number and size (also measured in bytes) of the assets remaining to be downloaded. |
|errorCode       |[CloudMediaTaskPauseCause](#cloudmediataskpausecause14)  |Yes| Reason why the download task is suspended.|
