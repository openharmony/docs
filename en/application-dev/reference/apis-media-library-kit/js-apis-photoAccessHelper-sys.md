# @ohos.file.photoAccessHelper (Album Management) (System API)

<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=064bb08ccf99717a1b68e90ff57938ff22079494 translatedAt=2026-08-17T10:28:44.070Z pushedAt=2026-08-19T05:51:59.876Z -->

The module provides APIs for album management, including creating an album and accessing and modifying media data in an album.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.file.photoAccessHelper (Album Management)](arkts-apis-photoAccessHelper.md).

## Modules to Import

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## photoAccessHelper.getPhotoAccessHelper<sup>19+</sup>

getPhotoAccessHelper(context: Context, userId: number): PhotoAccessHelper

Obtains a PhotoAccessHelper instance for the specified user, letting you access and modify media files in an album.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| userId | number | Yes  | ID of the user.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [PhotoAccessHelper](#photoaccesshelper) | PhotoAccessHelper instance obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 13900020 | Invalid argument.         |

**Example**

```ts
// The phAccessHelper instance obtained is a global object. It is used by default in subsequent operations. If the code snippet is not added, an error will be reported indicating that phAccessHelper is not defined.
// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button("example").onClick(async () => {
        let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        // 101 indicates the user ID of another user space.
        let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context, 101);
      }).width('100%')
    }
    .height('90%')
  }
}
```

​

## PhotoAccessHelper

### createAsset

createAsset(displayName: string, callback: AsyncCallback&lt;PhotoAsset&gt;): void

Creates an image or video asset with the specified file name. This API uses an asynchronous callback to return the result.

The file name must meet the following requirements:

- A valid file name must include a base name and a supported image or video extension.

- The total length of the file name must be between 1 and 255 characters.

- The base name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > | <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 14000001 is returned, refer to [PhotoKeys](#photokeys) to learn about the format and length requirements of the file name.

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

The file name must meet the following requirements:

- A valid file name must include a base name and a supported image or video extension.

- The total length of the file name must be between 1 and 255 characters.

- The base name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > | <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 14000001 is returned, refer to [PhotoKeys](#photokeys) to learn about the format and length requirements of the file name.

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

The file name must meet the following requirements:

- A valid file name must include a base name and a supported image or video extension.

- The total length of the file name must be between 1 and 255 characters.

- The base name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > | <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 14000001 is returned, refer to [PhotoKeys](#photokeys) to learn about the format and length requirements of the file name.

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

The file name must meet the following requirements:

- A valid file name must include a base name and a supported image or video extension.

- The total length of the file name must be between 1 and 255 characters.

- The base name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > | <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 14000001 is returned, refer to [PhotoKeys](#photokeys) to learn about the format and length requirements of the file name.

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

- The total length of the album name must be between 1 and 255 characters.

- It must not contain any invalid characters, which are:<br> . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900015       |  The file name already exists.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

- The total length of the album name must be between 1 and 255 characters.

- It must not contain any invalid characters, which are:<br> . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900015       |  The file name already exists.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Deletes user albums. This API uses an asynchronous callback to return the result.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Deletes user albums. This API uses a promise to return the result.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | Yes  |  Retrieval options. |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](#album)&gt;&gt; | Yes  |  Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

// Obtain the album newAlbumName that contains hidden files.
async function getHiddenAlbumsView(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getHiddenAlbumsViewDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE, fetchOptions,
    async (err, fetchResult) => {
      if (err !== undefined) {
        console.error(`getHiddenAlbumsViewCallback failed with error: ${err.code}, ${err.message}`);
        return;
      }
      if (fetchResult === undefined) {
        console.error('getHiddenAlbumsViewCallback fetchResult is undefined');
        return;
      }
      let album = await fetchResult.getFirstObject();
      if (album === undefined) {
        console.error('getHiddenAlbumsViewCallback album is undefined');
        fetchResult.close();
        return;
      }
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

| Name| Type| Mandatory| Description|
| -------- | ------------------------ | ---- | - |
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11) | Yes| Display mode of hidden albums.|
| callback | AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](#album)&gt;&gt; | Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

// Obtain the preset hidden album.
async function getSysHiddenAlbum(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE, async (err, fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getSysHiddenAlbumCallback fetchResult is undefined');
      return;
    }
    let hiddenAlbum: photoAccessHelper.Album = await fetchResult.getFirstObject();
    if (hiddenAlbum === undefined) {
      console.error('getSysHiddenAlbumCallback hiddenAlbum is undefined');
      fetchResult.close();
      return;
    }
    console.info('getSysHiddenAlbumCallback successfully, albumUri: ' + hiddenAlbum.albumUri);
    fetchResult.close();
  });
}

// Obtain the hidden albums displayed by album, that is, the albums with hidden files. Such albums do not include the preset hidden album and the albums in the trash.
async function getHiddenAlbumsView(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE, async (err, fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getHiddenAlbumsViewCallback fetchResult is undefined');
      return;
    }
    let albums: Array<photoAccessHelper.Album> = await fetchResult.getAllObjects();
    if (albums === undefined) {
      console.error('getHiddenAlbumsViewCallback albums is undefined');
      fetchResult.close();
      return;
    }
    console.info('getHiddenAlbumsViewCallback successfully, albums size: ' + albums.length);

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    for (let i = 0; i < albums.length; i++) {
      // Obtain hidden files in the album.
      albums[i].getAssets(fetchOption, (err, assetFetchResult) => {
        if (assetFetchResult === undefined) {
          console.error('getHiddenAlbumsViewCallback assetFetchResult is undefined');
          return;
        }
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
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | No  |  Options for retrieving the files. If this parameter is not specified, the files are retrieved based on the display mode of hidden files.     |

**Return value**

| Type| Description|
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission verification failed, usually the result returned by VerifyAccessToken.         |
| 202      |  Permission verification failed, application which is not a system application uses system API.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the preset hidden album.
async function getSysHiddenAlbum(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
async function getHiddenAlbumsView(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Deletes media assets. The deleted assets are moved to the trash. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002 |  The uri format is incorrect or does not exist.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Deletes media assets. The deleted assets are moved to the trash. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002 |  The uri format is incorrect or does not exist.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)       | Yes  |  Retrieval options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |
| callback | AsyncCallback&lt;number&gt;| Yes  | Callback used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)       | Yes  |  Retrieval options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt;| Promise used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Saves the Gallery widget information bound to a single image to the database. This API uses an asynchronous callback to return the result.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Saves the Gallery widget information bound to a single image to the database. This API uses a promise to return the result.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Removes the Gallery widget information bound to a single image from the database. This API uses an asynchronous callback to return the result.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Removes the Gallery widget information bound to a single image from the database. This API uses a promise to return the result.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### createAssetsForApp<sup>19+</sup>

createAssetsForApp(bundleName: string, appName: string, tokenId: number, photoCreationConfigs: Array&lt;PhotoCreationConfig&gt;): Promise&lt;Array&lt;string&gt;&gt;

Creates media assets for an application with the specified token ID. The returned URIs have been granted with the permission for writing the media assets (images or videos).

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| bundleName | string | Yes| Bundle name of the target application.|
| appName | string | Yes| Name of the target application.|
| tokenId | number | Yes| Token ID of the target application.|
| photoCreationConfigs | Array&lt;[PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)&gt; | Yes| Configuration for creating (saving) the media assets in the media library.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the media asset files in the media library. The target application (identified by **tokenId**) can write the media assets based on the URIs without requesting the write permission. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 13900020 | Invalid argument. Possible causes: 1. The photoCreationConfigs is empty; 2. Incorrect photoCreationConfigs format. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetsForAppDemo.');

  try {
    let bundleName: string = 'testBundleName';
    let appName: string = 'testAppName';
    let tokenId: number = 537197950;
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test',
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT,
      }
    ];
    let desFileUris: Array<string> = await phAccessHelper.createAssetsForApp(bundleName, appName, tokenId, photoCreationConfigs);
    console.info('createAssetsForApp success, data is ' + desFileUris);
  } catch (err) {
    console.error(`createAssetsForApp failed with error: ${err.code}, ${err.message}`);
  }
}
```

### grantPhotoUriPermission<sup>19+</sup>

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
| Promise&lt;number&gt; | Promise used to return the result. The value **0** means that the permission is granted to the application. The value **1** means that the application already has the permission. The value **-1** means that the permission fails to be granted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 13900020 | Invalid argument. Possible causes: 1. Incorrect uri format; 2. The value of photoPermissionType or hideSensitiveType is out of range. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('grantPhotoUriPermissionDemo');

  try {
    let tokenId = 502334412;
    let result = await phAccessHelper.grantPhotoUriPermission(tokenId,
        'file://media/Photo/1/IMG_datetime_0001/displayName.jpg',
        photoAccessHelper.PhotoPermissionType.TEMPORARY_READ_IMAGEVIDEO,
        photoAccessHelper.HideSensitiveType.HIDE_LOCATION_AND_SHOOTING_PARAM);

    console.info('grantPhotoUriPermission success, result=' + result);
  } catch (err) {
    console.error('grantPhotoUriPermission failed, error=' + err);
  }
}
```

### grantPhotoUrisPermission<sup>19+</sup>

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
| Promise&lt;number&gt; | Promise used to return the result. The value **0** means that the permission is granted to the application. The value **-1** means that the permission fails to be granted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 13900020 | Invalid argument. Possible causes: 1. Incorrect uri format; 2. The value of photoPermissionType or hideSensitiveType is out of range. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('grantPhotoUrisPermissionDemo');

  try {
    // URIs of the media assets.
    let uris: Array<string> = [
      'file://media/Photo/11/IMG_datetime_0001/displayName1.jpg',
      'file://media/Photo/22/IMG_datetime_0002/displayName2.jpg'];
    let tokenId = 502334412;
    let result = await phAccessHelper.grantPhotoUrisPermission(tokenId, uris,
        photoAccessHelper.PhotoPermissionType.TEMPORARY_READ_IMAGEVIDEO,
        photoAccessHelper.HideSensitiveType.HIDE_LOCATION_AND_SHOOTING_PARAM);

    console.info('grantPhotoUrisPermission success, result=' + result);
  } catch (err) {
    console.error('grantPhotoUrisPermission failed, error=' + err);
  }
}
```

### cancelPhotoUriPermission<sup>19+</sup>

cancelPhotoUriPermission(tokenId: number, uri: string, photoPermissionType: PhotoPermissionType): Promise&lt;number&gt;

Cancels the permission for accessing a URI from an application. This API uses a promise to return the result.

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
| 13900020 | Invalid argument. Possible causes: 1. Incorrect uri format; 2. The value of photoPermissionType or hideSensitiveType is out of range. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### startThumbnailCreationTask<sup>13+</sup>

startThumbnailCreationTask(predicate: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void\>): number

Generates a thumbnail based on the specified rule.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ---------  | --------------------------------------- | ---- | --------------- |
| predicates | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Rule for generating the thumbnail. |
| callback   | AsyncCallback&lt;void&gt;               | Yes  | Callback used to return the result. If the operation is successful, the notification task ends, and **err** is undefined. If the task fails, **err** is an error object.|

**Return value**

| Type                 | Description                 |
| --------------------- | -------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the thumbnail generation task.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

function testCallBack() {

}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();

  try {
    console.info('startThumbnailCreationTask test start');
    phAccessHelper.startThumbnailCreationTask(predicates, testCallBack);
  } catch (err) {
    console.error(`startThumbnailCreationTask failed, error: ${err.code}, ${err.message}`);
  }
}
```

### startThumbnailCreationTask<sup>23+</sup>

startThumbnailCreationTask(predicate: dataSharePredicates.DataSharePredicates, callback: AsyncCallback\<void\>, response: AsyncCallback\<number\>): number

Generates a thumbnail based on the specified rule. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ---------  | --------------------------------------- | ---- | --------------- |
| predicate | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Predicates for generating a thumbnail. |
| callback   | AsyncCallback&lt;void&gt;               | Yes  | Callback used to notify that the task is complete when the operation is successful.|
| response   | AsyncCallback&lt;number&gt;               | Yes  | Callback used to return whether there are ungenerated thumbnails. If **1** is returned, all thumbnails have been generated. If **0** is returned, some thumbnails have not been generated.|

**Return value**

| Type                 | Description                 |
| --------------------- | -------------------- |
| number | Promise used to return the ID of the thumbnail generation task.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: The predicates invalid. |
| 23800301     | Internal system error. You are advised to retry and check the logs. Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

function testCallBack() {
  console.info(`startThumbnailCreationTask: First callback`);
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();

  try {
    console.info('startThumbnailCreationTask test start');
    phAccessHelper.startThumbnailCreationTask(predicates, testCallBack, (err, state) =>{
        if(err) {
          console.error("error message: " + err?.message)
          console.error("error code: " + err?.code)
          return
        }
        console.info(`startThumbnailCreationTask: response state ${state}`);
      });
  } catch (err) {
    console.error(`startThumbnailCreationTask failed, error: ${err.code}, ${err.message}`);
  }
}
```

### stopThumbnailCreationTask<sup>13+</sup>

stopThumbnailCreationTask(taskId: number): void

Stops generating a thumbnail.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type  | Mandatory| Description                    |
| -----  | ------ | ---- | ------------------------ |
| taskId | number | Yes  | ID of the thumbnail generation task to stop.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('stopThumbnailCreationTask test start');
    let taskId: number = 75983;
    phAccessHelper.stopThumbnailCreationTask(taskId);
  } catch (err) {
    console.error(`stopThumbnailCreationTask failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getIndexConstructProgress<sup>12+</sup>

getIndexConstructProgress(): Promise&lt;string&gt;

Obtains the index construction progress. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise used to return a string in JSON format. The string indicates the number of images that have been analyzed, the total number of images, the number of videos that have been analyzed, and the total number of videos.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {

  class indexProgress {
    finishedImageCount: number = 0;
    totalImageCount: number = 0;
    finishedVideoCount: number = 0;
    totalVideoCount: number = 0;
  }

  try {
    console.info('getIndexConstructProgress test start');
    let result: string = await phAccessHelper.getIndexConstructProgress();
    console.info('getIndexProgress:' + result);

    let jsonObj: indexProgress = JSON.parse(result);
    //...Use the obtained index construction progress data.
  } catch (err) {
    console.error(`getIndexConstructProgress failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getDataAnalysisProgress<sup>12+</sup>

getDataAnalysisProgress(analysisType?: AnalysisType): Promise&lt;string&gt;

Obtains the asset analysis progress. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| analysisType | [AnalysisType](#analysistype11) | No   | Analysis type. The default value is null.<br>This parameter is mandatory in API versions 12 to 21 and optional from API version 22 onwards.|

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise used to return a string in JSON format. The string indicates the asset analysis progress.<br>If the parameter is empty, the overall progress is returned. If the parameter is provided, the progress corresponding to the specified analysis type is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 401 | Parameter error. Possible causes: 1. Incorrect parameter types; 2. Parameter verification failed. | 
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('getDataAnalysisProgress test start');

    let result: string = await phAccessHelper.getDataAnalysisProgress();
    console.info('getDataAnalysisProgress:' + result);

  } catch (err) {
    console.error(`getDataAnalysisProgress failed, error: ${err.code}, ${err.message}`);
  }
}
```

### getSharedPhotoAssets<sup>13+</sup>

getSharedPhotoAssets(options: FetchOptions): Array\<SharedPhotoAsset\>

Obtains the shared photo assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permission**: ohos.permission.ACCESS_MEDIALIB_THUMB_DB

**Parameters**

| Name     | Type        | Mandatory| Description    |
| ---------  | ------------ | ---- | ------- |
| options    | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes  | Options for obtaining the shared photo assets.|

**Return value**

| Type                   | Description               |
| ----------------------- | ------------------ |
| Array\<[SharedPhotoAsset](#sharedphotoasset13)\> | Shared photo assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    console.info('getSharedPhotoAssets test start');
    phAccessHelper.getSharedPhotoAssets(fetchOptions);
    console.info('getSharedPhotoAssets test end');
  } catch (err) {
    console.error(`getSharedPhotoAssets failed, error: ${err.code}, ${err.message}`);
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
| type      | [AnalysisType](#analysistype11) | Yes  | Smart analysis type. Only **ANALYSIS_SEARCH_INDEX** is supported.                                    |
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(context: Context) {
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

### startAssetAnalysisAsync<sup>24+</sup>

startAssetAnalysisAsync(config: AnalysisConfig, callback: Callback&lt;AnalysisResult&gt;): Promise&lt;number&gt;

Starts asynchronous asset analysis. This API uses an asynchronous callback to return the result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| config    | [AnalysisConfig](#analysisconfig24) | Yes  | Asset analysis configuration. The **uris** in the **config** parameter is obtained from the [PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md) object.|
| callback  | Callback&lt;[AnalysisResult](#analysisresult24)&gt; | Yes  | Callback used to return the asset analysis result.|

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;number&gt; | Promise used to return the service task ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Unsupported or invalid types of config.<br>2. The types or uris array size of config exceed max value. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
let callback = (result: photoAccessHelper.AnalysisResult) => {
  console.info('startAssetAnalysisAsync callback result: ' + JSON.stringify(result));
};

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('startAssetAnalysisAsyncDemo');
  let config: photoAccessHelper.AnalysisConfig = {
    types: [photoAccessHelper.AnalysisType.ANALYSIS_SEARCH_INDEX],
    uris: ['file://media/Photo/14/IMG_1729066473_013/IMG_20241016_122253.jpg'],
    extraInfos: '{"trigger":"manual"}'
  };

  try {
    let taskId = await phAccessHelper.startAssetAnalysisAsync(config, callback);
    console.info('startAssetAnalysisAsync success, taskId=' + taskId);
  } catch (err) {
    console.error(`startAssetAnalysisAsync failed with error: ${err.code}, ${err.message}`);
  }
}
```

### stopAssetAnalysis<sup>24+</sup>

stopAssetAnalysis(config: AnalysisConfig): void

Stops asset analysis.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| config    | [AnalysisConfig](#analysisconfig24) | Yes  | Asset analysis configuration.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Unsupported or invalid AnalysisType of config.<br>2. The types or uris array size of config exceed max value. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('stopAssetAnalysisDemo');
  let config: photoAccessHelper.AnalysisConfig = {
    types: [photoAccessHelper.AnalysisType.ANALYSIS_SEARCH_INDEX],
    uris: ['file://media/Photo/14/IMG_1729066473_013/IMG_20241016_122253.jpg']
  };

  try {
    phAccessHelper.stopAssetAnalysis(config);
    console.info('stopAssetAnalysis success');
  } catch (err) {
    console.error(`stopAssetAnalysis failed with error: ${err.code}, ${err.message}`);
  }
}
```

### createAssetsForAppWithMode<sup>12+</sup>

createAssetsForAppWithMode(bundleName: string, appName: string, appId: string, tokenId: number, authorizationMode: AuthorizationMode, photoCreationConfigs:Array\<PhotoCreationConfig>): Promise\<Array\<string>>

Creates assets with a temporary permission. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                                                                  | Mandatory| Description                     |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| bundleName| string | Yes| Bundle name of the target application.|
| appName| string | Yes| Name of the target application.|
| appId| string | Yes| ID of the target application.|
| tokenId| number| Yes| Unique identifier for the temporary authorization.|
| authorizationMode| [AuthorizationMode](#authorizationmode12)| Yes| Authorization mode. No confirmation dialog box is displayed when the application with the temporary permission saves media assets in the give period of time.|
| PhotoCreationConfig| Array\<[PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)> | Yes| Configuration for creating (saving) the media assets in the media library.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<Array\<string>> | Promise used to return the URIs of the media asset files in the media library. The target application (identified by **appid**) can write the media assets based on the URIs without requesting the write permission. If the URIs fail to be generated, a batch creation error code will be returned.<br>The error code **-3006** means that there are invalid characters; **-2004** means that the image type does not match the file name extension; **-203** means that the file operation is abnormal.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 |  Permission denied.         |
| 202 |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |
| 14000011       | Internal system error.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### saveGalleryFormInfo<sup>18+</sup>

saveGalleryFormInfo(info:GalleryFormInfo):Promise&lt;void&gt;

Saves the Gallery widget information bound to a group of images to the database. This API uses a promise to return the result.

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('saveGalleryFormInfoDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  if (fetchResult === undefined) {
    console.error('fetchResult is undefined');
    return;
  }  
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset === undefined) {
    console.error('photoAsset is undefined');
    return;
  }
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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Removes the Gallery widget information bound to a group of images from the database. This API uses a promise to return the result.

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| isAuthorized  |  boolean              | Yes  | Whether to authorize other applications. **true** to authorize, **false** otherwise.                                    |
| PhotoCreationConfigs| Array\<[PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)> | Yes| Configuration for creating (saving) the media assets in the media library.|

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### on('hiddenPhotoChange')<sup>20+</sup>

on(type: 'hiddenPhotoChange', callback: Callback&lt;PhotoAssetChangeInfos&gt;): void

Registers a listener for the **'hiddenPhotoChange'** event to monitor hidden media asset changes. This API uses a callback to return the result, and it accepts multiple callbacks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'hiddenPhotoChange'**. After the registration is complete, any change to the hidden media assets is returned through the callback.|
| callback  | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | Yes  | Callback used to return the hidden media asset information after change, which is [PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20).<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [off('hiddenPhotoChange')](#offhiddenphotochange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenPhotoChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('onHiddenPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('hiddenPhotoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('hiddenPhotoChange', onCallback2);
  } catch (error) {
    console.error('onHiddenPhotoChange failed, errCode is', error);
  }
}
```

### off('hiddenPhotoChange')<sup>20+</sup>

off(type: 'hiddenPhotoChange', callback?: Callback&lt;PhotoAssetChangeInfos&gt;): void

Unregisters a listener for the **'hiddenPhotoChange'** event to stop monitoring hidden media asset changes. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'hiddenPhotoChange'**. After the unregistration is complete, any change to the hidden media assets is no longer returned through the callback.|
| callback | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('hiddenPhotoChange')](#onhiddenphotochange20). If this parameter is left unspecified, all listeners for the **'hiddenPhotoChange'** event are unregistered.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when a hidden media asset changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenPhotoChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('offHiddenPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('hiddenPhotoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('hiddenPhotoChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('hiddenPhotoChange', onCallback1);
  } catch (error) {
    console.error('offHiddenPhotoChange failed, errCode is', error);
  }
}
```

### on('trashedPhotoChange')<sup>20+</sup>

on(type: 'trashedPhotoChange', callback: Callback&lt;PhotoAssetChangeInfos&gt;): void

Registers a listener for the **'trashedPhotoChange'** event to monitor media asset changes in the trash. This API uses a callback to return the result, and it accepts multiple callbacks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'trashedPhotoChange'**. After the registration is complete, any change to the trashed media assets is returned through the callback.|
| callback  | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | Yes  | Callback used to return the trashed media asset information after change, which is [PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20).<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [off('trashedPhotoChange')](#offtrashedphotochange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151  | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedPhotoChange'; 2. The same callback is registered repeatedly. |
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
  console.info('onTrashedPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('trashedPhotoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('trashedPhotoChange', onCallback2);
  } catch (error) {
    console.error('onTrashedPhotoChangeDemo failed, errCode is', error);
  }
}
```

### off('trashedPhotoChange')<sup>20+</sup>

off(type: 'trashedPhotoChange', callback?: Callback&lt;PhotoAssetChangeInfos&gt;): void

Unregisters a listener for the **'trashedPhotoChange'** event to stop monitoring media asset changes in the trash. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'trashedPhotoChange'**. After the unregistration is complete, any change to the trashed media assets is no longer returned through the callback.|
| callback | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('trashedPhotoChange')](#ontrashedphotochange20). If this parameter is left unspecified, all listeners for the **'trashedPhotoChange'** event are unregistered.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when a trashed media asset changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedPhotoChange'; 2. The same callback is unregistered repeatedly. |
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
  console.info('offTrashedPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('trashedPhotoChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('trashedPhotoChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('trashedPhotoChange', onCallback1);
  } catch (error) {
    console.error('offTrashedPhotoChangeDemo failed, errCode is', error);
  }
}
```

### onAnalysisPhotoChange<sup>23+</sup>

onAnalysisPhotoChange(callback: Callback&lt;PhotoAssetChangeInfos&gt;): void

Listens for the changes of media assets associated with the smart analysis album. The change carries the smart analysis album change information. The asset change notification is sent only when the asset change involves the smart analysis album information change. The asset change result is returned through the callback. Multiple callbacks can be registered. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                                                               |
|-----------|-------------------------|-----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| callback  | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | Yes  | Callback used to return the [PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20) of the corresponding smart analysis album.<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [offAnalysisPhotoChange](#offanalysisphotochange23) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151  | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedPhotoChange'; 2. The same callback is registered repeatedly. |
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
  console.info('onAnalysisPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.onAnalysisPhotoChange(onCallback1);
    // Register onCallback2.
    phAccessHelper.onAnalysisPhotoChange(onCallback2);
  } catch (error) {
    console.error('onAnalysisPhotoChangeDemo failed, errCode is', error);
  }
}
```

### offAnalysisPhotoChange<sup>23+</sup>

offAnalysisPhotoChange(callback?: Callback&lt;PhotoAssetChangeInfos&gt;): void

Cancels the listening for the media asset changes related to the smart analysis album. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                      |
|-----------|-------------------------|-----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| callback | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | No  | Callback used to return the media asset information of the corresponding smart analysis album. If this parameter is set, the callback listener specified during [onAnalysisPhotoChange](#onanalysisphotochange23) registration is canceled. If this parameter is not set, all listeners of [onAnalysisPhotoChange](#onanalysisphotochange23) are canceled.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when the assets in the smart analysis album change.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedPhotoChange'; 2. The same callback is unregistered repeatedly. |
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
  console.info('offAnalysisPhotoChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.offAnalysisPhotoChange(onCallback1);
    // Register onCallback2.
    phAccessHelper.offAnalysisPhotoChange(onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.offAnalysisPhotoChange(onCallback1);
  } catch (error) {
    console.error('offAnalysisPhotoChangeDemo failed, errCode is', error);
  }
}
```

### on('hiddenAlbumChange')<sup>20+</sup>

on(type: 'hiddenAlbumChange', callback: Callback&lt;AlbumChangeInfos&gt;): void

Registers a listener for the **'hiddenAlbumChange'** event to monitor hidden album changes. This API uses a callback to return the result, and it accepts multiple callbacks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'hiddenAlbumChange'**. After the registration is complete, any change to the hidden albums is returned through the callback.|
| callback  | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | Yes  | Callback used to return the hidden album information after change, which is [AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20).<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [off('hiddenAlbumChange')](#offhiddenalbumchange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenAlbumChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('onHiddenAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('hiddenAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('hiddenAlbumChange', onCallback2);
  } catch (error) {
    console.error('onHiddenAlbumChangeDemo failed, errCode is', error);
  }
}
```

### off('hiddenAlbumChange')<sup>20+</sup>

off(type: 'hiddenAlbumChange', callback?: Callback&lt;AlbumChangeInfos&gt;): void

Unregisters a listener for the **'hiddenAlbumChange'** event to stop monitoring hidden album changes. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'hiddenAlbumChange'**. After the unregistration is complete, any change to the hidden albums is no longer returned through the callback.|
| callback | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('hiddenAlbumChange')](#onhiddenalbumchange20). If this parameter is left unspecified, all listeners for the **'hiddenAlbumChange'** event are unregistered.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when a hidden album changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenAlbumChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('onHiddenAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('hiddenAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('hiddenAlbumChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('hiddenAlbumChange', onCallback1);
  } catch (error) {
    console.error('onHiddenAlbumChangeDemo failed, errCode is', error);
  }
}
```

### on('trashedAlbumChange')<sup>20+</sup>

on(type: 'trashedAlbumChange', callback: Callback&lt;AlbumChangeInfos&gt;): void

Registers a listener for the **'trashedAlbumChange'** event to monitor album changes in the trash. This API uses a callback to return the result, and it accepts multiple callbacks.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'trashedAlbumChange'**. After the registration is complete, any change to the trashed albums is returned through the callback.|
| callback  | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | Yes  | Callback used to return the trashed album information after change, which is [AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20).<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [off('trashedAlbumChange')](#offtrashedalbumchange20) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedAlbumChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onTrashedAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('trashedAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('trashedAlbumChange', onCallback2);
  } catch (error) {
    console.error('onTrashedAlbumChangeDemo failed, errCode is', error);
  }
}
```

### off('trashedAlbumChange')<sup>20+</sup>

off(type: 'trashedAlbumChange', callback?: Callback&lt;AlbumChangeInfos&gt;): void

Unregisters a listener for the **'trashedAlbumChange'** event to stop monitoring album changes in the trash. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| type | string | Yes  | Event type. The value is fixed at **'trashedAlbumChange'**. After the unregistration is complete, any change to the trashed albums is no longer returned through the callback.|
| callback | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | No  | Exact callback you previously registered with [on('trashedAlbumChange')](#ontrashedalbumchange20). If this parameter is left unspecified, all listeners for the **'trashedAlbumChange'** event are unregistered.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when an album in the trash changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'trashedAlbumChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onTrashedAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.on('trashedAlbumChange', onCallback1);
    // Register onCallback2.
    phAccessHelper.on('trashedAlbumChange', onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.off('trashedAlbumChange', onCallback1);
  } catch (error) {
    console.error('onTrashedAlbumChangeDemo failed, errCode is', error);
  }
}
```

### onAnalysisAlbumChange<sup>23+</sup>

onAnalysisAlbumChange(callback: Callback&lt;AlbumChangeInfos&gt;): void

Listens for the smart analysis album and returns the album change result using a callback. You can register multiple callbacks. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                                       |
|-----------|-------------------------|-----------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| callback  | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | Yes  | Callback used to return the [AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20) about the smart analysis album.<br>**NOTE**<br>You can register multiple listeners using this API, and you can call [offAnalysisAlbumChange](#offanalysisalbumchange23) to unregister all listeners or a specific one.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenAlbumChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('onAnalysisAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.onAnalysisAlbumChange(onCallback1);
    // Register onCallback2.
    phAccessHelper.onAnalysisAlbumChange(onCallback2);
  } catch (error) {
    console.error('onAnalysisAlbumChangeDemo failed, errCode is', error);
  }
}
```

### offAnalysisAlbumChange<sup>23+</sup>

offAnalysisAlbumChange(callback?: Callback&lt;AlbumChangeInfos&gt;): void

Cancels the listener for the smart analysis album. If multiple listeners are registered, you can unregister a specific listener by specifying **callback**. Alternatively, you can unregister all of them without specifying **callback**. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                                                                                   |
|-----------|-------------------------|-----------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| callback | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | No  | Callback used to return the changed smart analysis album information. If this parameter is set, the callback listener specified during [onAnalysisAlbumChange](#onanalysisalbumchange23) registration is canceled. If this parameter is not set, all listeners registered by [onAnalysisAlbumChange](#onanalysisalbumchange23) are canceled.<br>**NOTE**<br>Once a specific callback is unregistered, it will not be invoked when a smart album changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'hiddenAlbumChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changeData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper){
  console.info('offAnalysisAlbumChangeDemo.');

  try {
    // Register onCallback1.
    phAccessHelper.onAnalysisAlbumChange(onCallback1);
    // Register onCallback2.
    phAccessHelper.onAnalysisAlbumChange(onCallback2);

    // Unregister the listening of onCallback1.
    phAccessHelper.offAnalysisAlbumChange(onCallback1);
  } catch (error) {
    console.error('offAnalysisAlbumChangeDemo failed, errCode is', error);
  }
}
```

### isCompatibleDuplicateSupported<sup>21+</sup>

isCompatibleDuplicateSupported(bundleName: string): Promise&lt;boolean&gt;

Checks whether a temporary JPEG copy should be created for an application. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                  | Mandatory| Description     |
|-----------|-------------------------|-----------|-----------------|
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;boolean&gt; | Check result for whether a temporary JPEG copy should be created for the application. **true** if a temporary JPEG copy should be created, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. The IPC request timed out. 2.system running error.|

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('isCompatibleDuplicateSupportedPromiseDemo')
    let isSupport: boolean = await phAccessHelper.isCompatibleDuplicateSupported('com.example.helloworld');
    console.info(`isCompatibleDuplicateSupported: ${isSupport}`);
  } catch (err) {
    console.error(`isCompatibleDuplicateSupportedPromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getPhotoAlbums<sup>20+</sup>

getPhotoAlbums(options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains system, user, and source albums based on the specified options. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | No  |  Retrieval options. If this parameter is not specified, the albums are obtained based on the album type by default.             |

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getPhotoAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getPhotoAlbums(fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getPhotoAlbumsPromise fetchResult is undefined');
      return;
    }
    let albums: photoAccessHelper.Album[] = await fetchResult.getAllObjects();
    console.info(`getPhotoAlbumsPromise successfully, albums length: ${albums.length}`);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getPhotoAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### getPhotoAlbumOrder<sup>20+</sup>

getPhotoAlbumOrder(orderStyle: number, options?: FetchOptions): Promise&lt;FetchResult&lt;AlbumOrder&gt;&gt;

Obtains the sorting order for system, user, and source albums. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| orderStyle  | number         | Yes  |  Sorting style for albums.<br>The value **0** means the phone style, and **1** means the PC style.       |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | No  |  Retrieval options. If this parameter is not specified, the albums are obtained based on the album type by default.             |

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[AlbumOrder](#albumorder20)&gt;&gt; | Promise used to return the sorting order.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The input parameter is not within the valid range. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getPhotoAlbumOrderDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let orderStyle: number = 0;
  phAccessHelper.getPhotoAlbumOrder(orderStyle, fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getPhotoAlbumOrderPromise fetchResult is undefined');
      return;
    }
    let albumOrders: photoAccessHelper.AlbumOrder[] = await fetchResult.getAllObjects();
    console.info(`getPhotoAlbumOrderPromise successfully, albumOrders length: ${albumOrders.length}`);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getPhotoAlbumOrderPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### setPhotoAlbumOrder<sup>20+</sup>

setPhotoAlbumOrder(orderStyle: number, albumOrders: Array&lt;AlbumOrder&gt;): Promise&lt;void&gt;

Sets the sorting order for system, user, and source albums. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type               | Mandatory| Description                                                        |
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| orderStyle  | number         | Yes  |  Sorting style for albums.<br>The value **0** means the phone style, and **1** means the PC style.       |
| albumOrders | Array&lt;[AlbumOrder](#albumorder20)&gt; | Yes  | Array of album sorting orders.|

**Return value**

| Type                 | Description                       |
| --------------------- | --------------------------- |
| Promise&amp;lt;void&amp;gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The input parameter is not within the valid range. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setPhotoAlbumOrderDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let orderStyle: number = 0;
  phAccessHelper.getPhotoAlbumOrder(orderStyle, fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getPhotoAlbumOrderPromise fetchResult is undefined');
      return;
    }
    let albumOrder: photoAccessHelper.AlbumOrder = await fetchResult.getFirstObject();
    albumOrder.albumOrder = 10;
    albumOrder.orderSection = 0;
    albumOrder.orderType = 1;
    albumOrder.orderStatus = 1;
    await phAccessHelper.setPhotoAlbumOrder(orderStyle, [albumOrder]);
    console.info('setPhotoAlbumOrderPromise successfully.');
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`setPhotoAlbumOrderPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

### query<sup>22+</sup>

query(sql: string): Promise&lt;ResultSet&gt;

Queries data in the database using the specified SQL statement. This API does not support write operations or multi-level queries. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permission**: ohos.permission.ACCESS_MEDIALIB_THUMB_DB

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type | Mandatory| Description|
| ------- | ----- | ----- | ---- |
| sql | string | Yes| SQL statement to execute.|

**Return value**

| Type| Description|
| ----- | ---- |
| Promise&lt;[ResultSet](#resultset22)&gt; | Promise used to return a **ResultSet** object. If the operation fails, an exception is thrown.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: The SQL statement is abnormal. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out.|

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('query');
  try {
    let ret: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    while (ret.goToNextRow()) {
      let row = ret.getRow();
      Object.entries(row).forEach((entry) => {
        const key = entry[0];
        const value = entry[1];
      });
    }
    ret.close();
  } catch (err) {
    console.error(`query failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getClonedAssetUris<sup>22+</sup>

getClonedAssetUris(oldUris: Array&lt;string&gt;): Promise&lt;Map&lt;string, string&gt;&gt;

Obtains the current URIs of cloned assets. This API uses a promise to return the result.

To control the size of the database table space, the system automatically deletes the previously stored clone data during each clone operation. As a result, this API only keeps the mapping between the user's new and old device URIs from the latest clone operation.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| oldUris | Array&lt;string&gt; | Yes| Array of old URIs before cloning.|

**Return value**

| Type| Description|
| --------------------- | --------------------------- |
| Promise&lt;Map&lt;string, string&gt;&gt; | Promise used to return a map of URIs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| **ID**| **Error Message**|
| ----------------- | --------------------------------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: The size of input parameter exceeds 100 or is 0. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
    console.info('getClonedAssetUrisDemo');
    // The following is an array of URIs of media files.
    let uris: Array<string> = [
        'file://media/Photo/1/IMG_datetime_0001/displayName1.jpg',
        'file://media/Photo/2/IMG_datetime_0002/displayName2.jpg',
        'file://media/Photo/3/IMG_datetime_0003/displayName3.jpg'
    ];
    try {
        let assets: Map<string, string> = await phAccessHelper.getClonedAssetUris(uris);
        console.info(`Assets: ${assets}`);
    } catch (error) {
        console.error(`Error thrown: ${error}`);
    }
}
```

### getClonedAlbumUris<sup>22+</sup>

getClonedAlbumUris(oldUris: Array&lt;string&gt;): Promise&lt;Map&lt;string, string&gt;&gt;

Obtains the current URIs of cloned albums. This API uses a promise to return the result.

To control the size of the database table space, the system automatically deletes the previously stored clone data during each clone operation. As a result, this API only keeps the mapping between the user's new and old device URIs from the latest clone operation.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --------- | ------------------- | ---- | ------------------------------------------------------------ |
| oldUris | Array&lt;string&gt; | Yes| Array of old URIs before cloning.|

**Return value**

| Type| Description|
| --------------------- | --------------------------- |
| Promise&lt;Map&lt;string, string&gt;&gt; | Promise used to return a map of URIs.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| **ID**| **Error Message**|
| ----------------- | --------------------------------------------------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: The size of input parameter exceeds 100 or is 0. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
    console.info('getClonedAlbumUrisDemo');
    // The following is an array of URIs of media files.
    let uris: Array<string> = [
        'file://media/PhotoAlbum/1',
        'file://media/PhotoAlbum/2',
        'file://media/AnalysisAlbum/3'
    ];
    try {
        let albums: Map<string, string> = await phAccessHelper.getClonedAlbumUris(uris);
        console.info(`Albums: ${albums}`);
    } catch (error) {
        console.error(`Error thrown: ${error}`);
    }
}
```

### batchGetPhotoAssetParams<sup>21+</sup>

batchGetPhotoAssetParams(assets: PhotoAsset[], members: string[]): PhotoAssetParams

Obtains the values of specified properties for an array of [PhotoAsset](js-apis-photoAccessHelper-sys.md#photoasset) objects in batches.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| assets | [PhotoAsset](js-apis-photoAccessHelper-sys.md#photoasset)[] | Yes  | Array of files for which property values are to be retrieved.|
| members | string[] | Yes  | Array of properties for which values are to be retrieved.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [PhotoAssetParams](arkts-apis-photoAccessHelper-t.md#photoassetparams21)| Array of record types that map file property names to their values.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     | Called by non-system application.         |
| 23800151       | The scenario parameter verification fails. Possible causes: The attribute to be queried does not exist in assets.        |
| 23800104       | The provided member must be a property name of PhotoKey.        |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper} from '@kit.MediaLibraryKit';

async function example(context: Context) {
  console.info('batchGetPhotoAssetParams');
  type PhotoAsset = photoAccessHelper.PhotoAsset;
  let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
  const FETCH_COLUMNS: string[] = [
    photoAccessHelper.PhotoKeys.SIZE,
    photoAccessHelper.PhotoKeys.DATE_ADDED,
    photoAccessHelper.PhotoKeys.DATE_MODIFIED,
    photoAccessHelper.PhotoKeys.PHOTO_TYPE,
    photoAccessHelper.PhotoKeys.TITLE,
    photoAccessHelper.PhotoKeys.DATE_MODIFIED_MS,
    photoAccessHelper.PhotoKeys.DURATION,
    photoAccessHelper.PhotoKeys.WIDTH,
    photoAccessHelper.PhotoKeys.HEIGHT,
    photoAccessHelper.PhotoKeys.DATE_TRASHED_MS,
    photoAccessHelper.PhotoKeys.POSITION,
    photoAccessHelper.PhotoKeys.DATE_TAKEN,
    'owner_album_id',
    'thumbnail_ready',
    'data',
  ];
  const keyToGet: string[] = [
    photoAccessHelper.PhotoKeys.URI,
    photoAccessHelper.PhotoKeys.DISPLAY_NAME,
    photoAccessHelper.PhotoKeys.DATE_ADDED,
    photoAccessHelper.PhotoKeys.SIZE,
    photoAccessHelper.PhotoKeys.DURATION,
    photoAccessHelper.PhotoKeys.WIDTH,
    photoAccessHelper.PhotoKeys.HEIGHT,
    'data',
    photoAccessHelper.PhotoKeys.THUMBNAIL_READY,];
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: FETCH_COLUMNS,
    predicates: predicates
  };
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  }
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.
  getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
  let photoAssetsFetchResult: photoAccessHelper.FetchResult<PhotoAsset> = await album.getAssets(fetchOptions);
  let photoAssets: PhotoAsset[] = await photoAssetsFetchResult.getAllObjects();
  const batchParamOfPhotoAssets: photoAccessHelper.PhotoAssetParams =
   phAccessHelper.batchGetPhotoAssetParams(photoAssets, keyToGet);
  console.info(`batchGetPhotoAssetParams success, the length is ${batchParamOfPhotoAssets.length}`);
}
```

### addResourceForPicker<sup>22+</sup>

addResourceForPicker(type: ResourceType, fileUri: string): void

Adds a resource using [fileUri](../apis-core-file-kit/js-apis-file-fileuri.md).

> **NOTE**
>
> - For the same asset change request, this API cannot be repeatedly called after the resource is successfully added.
> - For a moving photo, you can call this API twice to add the image and video resources.

**System API**: This is a system API and is provided only for PhotoPicker.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permission**: ohos.permission.ACCESS_MEDIALIB_THUMB_DB

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| type | [ResourceType](arkts-apis-photoAccessHelper-e.md#resourcetype11) | Yes  | Type of the resource to be added. Only images and videos are supported.|
| fileUri | string | Yes  | Data source of the resource to be added, which is specified by a URI in the application sandbox directory.<br>For example, **fileUri: 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg'**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The file corresponding to the URI is not in the app sandbox. 2. ResourceType must be image or video. |
| 23800301 | Internal system error. You are advised to retry and check the logs. Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('addResourceForPickerByFileUriDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = photoAccessHelper.MediaAssetChangeRequest.createAssetRequest(context, photoType, extension);
    // Ensure that the asset specified by fileUri exists.
    let fileUri = 'file://com.example.temptest/data/storage/el2/base/haps/entry/files/test.jpg';
    assetChangeRequest.addResourceForPicker(photoAccessHelper.ResourceType.IMAGE_RESOURCE, fileUri);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('addResourceForPickerByFileUri successfully');
  } catch (err) {
    console.error(`addResourceForPickerByFileUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### isMediaDataReady<sup>24+</sup>

isMediaDataReady(mediaDataKey: string): Promise&lt;boolean&gt;

Checks whether the specified media data is ready.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| mediaDataKey | string | Yes  | Media data type to be checked.<br>Currently, the **date_added_year** value is supported, indicating whether the adding time (year, month, and day) of the asset is ready.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that the media data is ready, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails, unsupported media data type. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('isMediaDataReady demo');

  try {
    let ready: boolean = await phAccessHelper.isMediaDataReady('date_added_year');
    if (ready) {
      console.info('date_added_year media data is ready.');
    } else {
      console.info('date_added_year media data is not ready.');
    }
  } catch (err) {
    console.error(`isMediaDataReady failed: ${err.code}, ${err.message}`);
  }
}
```

### getPhotoAssets<sup>24+</sup>

getPhotoAssets(assetsData: ValuesBucket[]): Promise&lt;PhotoAsset[]&gt;

Converts the **ValuesBucket** record to a **PhotoAsset** object.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| assetsData | [ValuesBucket](#valuesbucket22)[] | Yes  | Array of asset records.<br>Each element in the array contains the column name and value of the asset.<br>The array can contain a maximum of 500 elements.<br>Each element in the array must contain the following asset column information: **file_id**, **data**, **display_name**, **media_type**, and **subtype**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)[]&gt; | Promise used to return the **PhotoAsset** object array (which may be empty).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. Invalid value type in ValuesBucket; 2. Missing required column in ValuesBucket; 3. Array size exceeds 500.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getPhotoAssets demo');
  let valuesArr: photoAccessHelper.ValuesBucket[] = [];
  let resultSet: photoAccessHelper.ResultSet | undefined = undefined;
  let photoAssetArr: photoAccessHelper.PhotoAsset[] = [];
  let QUERY_SQL = 'SELECT file_id,data,display_name,media_type,subtype from Photos limit 100';
  try {
    resultSet = await phAccessHelper.query(QUERY_SQL);
    let index: number = 0;
    while(resultSet && index < resultSet.rowCount){
      resultSet.goToRow(index);
      valuesArr.push(resultSet.getRow());
      index++;
    }
    photoAssetArr = await phAccessHelper.getPhotoAssets(valuesArr);
    console.info('getPhotoAssets successfully');
  } catch (err) {
    console.error(`valuesArr failed: ${err.code}, ${err.message}`);
  }
}
```

### getAssetCompatibleUris

getAssetCompatibleUris(bundleName: string, assets: Array&lt;PhotoAsset&gt;, compatibleFlag?: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the list of URIs to be transcoded based on the bundle name, photo asset list, and compatible flag. This API uses a promise to return the result.

> **NOTE**
>
> The **compatibleFlag** parameter is a compatibility configuration mask flag. The bit definitions are as follows:
> - Bit 0: indicates a high-resolution image.
> - Bit 1: indicates an image in HEIF format.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                               | Mandatory| Description                                                        |
| ------------- | ----------------------------------- | ---- | ------------------------------------------------------------ |
| bundleName    | string                              | Yes  | Bundle name of the application.                                          |
| assets        | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of assets to be checked.                                          |
| compatibleFlag | number                              | No  | Compatibility configuration mask flag.<br>Bit 0 indicates a high-resolution image, and bit 1 indicates an image in HEIF format.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URI list of media library files to be transcoded.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | Called by non-system application.        |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The bundleName is invalid; 2. The compatibleFlag is invalid. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let bundleName: string = 'com.example.helloWorld';
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [photoAccessHelper.PhotoKeys.URI, photoAccessHelper.PhotoKeys.WIDTH, photoAccessHelper.PhotoKeys.HEIGHT],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let assets: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
    // compatibleFlag: Bit 0 indicates the full image, and bit 1 indicates the HEIF image.
    let compatibleFlag: number = 0;
    let uris: Array<string> = await phAccessHelper.getAssetCompatibleUris(bundleName, assets, compatibleFlag);
    console.info(`getAssetCompatibleUris success, uri count: ${uris.length}`);
  } catch (err) {
    console.error(`getAssetCompatibleUris failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setAssetCompatibleCapability<sup>24+</sup>

setAssetCompatibleCapability(bundleName: string, capability: AssetCompatibleCapability): Promise\<void>

Sets the asset compatibility capability based on the bundle name. You can obtain the compatibility capability and determine whether to perform compatibility conversion based on the capability.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| capability | [AssetCompatibleCapability](arkts-apis-photoAccessHelper-i.md#assetcompatiblecapability24) | Yes  | Asset compatibility capability.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The bundleName or capability is invalid.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let bundleName = "com.test.example";
    let capability : photoAccessHelper.AssetCompatibleCapability = {
        supportedHighResolution : true,
    };
    await phAccessHelper.setAssetCompatibleCapability(bundleName, capability);
  } catch (error) {
    console.error('failed to setAssetCompatibleCapability err', error);
  }
}
```

### convertToAsset

convertToAsset(path: string): Promise&lt;PhotoAsset&gt;

Converts assets in the public directory of the file management to asset objects. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| path | string | Yes| File path in the file management.<br>The value starts with **/Docs**, for example, **/Docs/Download/test.jpg**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[PhotoAsset](#photoasset)&gt; | Promise that returns the asset object that is successfully converted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Converted an image after filtering into an asset object;<br>2. File to be converted is not exist;<br>3. Only images in the public directory of filemanager can be converted. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let path: string = '/Docs/Download/test.jpg';
    let photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.convertToAsset(path);
    console.info(`convertToAsset success, asset uri: ${photoAsset.uri}`);
  } catch (err) {
    console.error(`convertToAsset failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cloneToAlbum

cloneToAlbum(assets: PhotoAsset[], target: Album,option?: BatchOperationOptions): Promise\<PhotoAsset[]>

Clones assets to the target album. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| assets | [PhotoAsset](#photoasset)[] | Yes| Array of assets to be cloned.|
| target | [Album](#album) | Yes| Target album.|
| option | [BatchOperationOptions](#batchoperationoptions) | No| Options for cloning assets in batches. If this parameter is not specified, automatic renaming is supported by default, and no progress information is returned.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)[]&gt; | Promise used to return the list of assets that are successfully cloned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Asset to be cloned has been deleted or hidden;<br>2. Asset to be cloned is cloud pictures, which can not be cloned;<br>3. The target directory does not exist;<br>4. Insufficient system space;<br>5. Automatic renaming is not supported. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let assetFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let assets: Array<photoAccessHelper.PhotoAsset> = await assetFetchResult.getAllObjects();
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let target: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let options: photoAccessHelper.BatchOperationOptions = {
      mode: 0
    };
    let clonedAssets: Array<photoAccessHelper.PhotoAsset> = await phAccessHelper.cloneToAlbum(assets, target, options);
    console.info(`cloneToAlbum success, count: ${clonedAssets.length}`);
  } catch (err) {
    console.error(`cloneToAlbum failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cloneToDir

cloneToDir(assets: string[], target: string, option?: BatchOperationOptions): Promise\<string[]>

Clones assets to the file management directory. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| assets | string[] | Yes| Array of URIs of the assets to be cloned.|
| target | string | Yes| Target directory in file management.|
| option | [BatchOperationOptions](#batchoperationoptions) | No| Options for cloning assets in batches. If this parameter is not specified, automatic renaming is supported by default, and no progress information is returned.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<string[]> | Promise used to return the array of paths to the assets that are successfully cloned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Asset to be cloned has been deleted or hidden;<br>2. Asset to be cloned is cloud pictures, which can not be cloned;<br>3. The target album does not exist;<br>4. Insufficient system space;<br>5. Automatic renaming is not supported. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let assetFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let assets: Array<photoAccessHelper.PhotoAsset> = await assetFetchResult.getAllObjects();
    let assetUris: Array<string> = assets.map((item) => item.uri);
    let target: string = '/Docs/Download';
    let clonedPaths: Array<string> = await phAccessHelper.cloneToDir(assetUris, target);
    console.info(`cloneToDir success, count: ${clonedPaths.length}`);
  } catch (err) {
    console.error(`cloneToDir failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cloneAssetsByPath

cloneAssetsByPath(assets: string[], target: Album, option?: BatchOperationOptions): Promise\<string[]>

Clones assets in file management to the target album. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| assets | string[] | Yes| Array of paths to the assets to be cloned.|
| target | [Album](#album) | Yes| Target album.|
| option | [BatchOperationOptions](#batchoperationoptions) | No| Options for cloning assets in batches. If this parameter is not specified, automatic renaming is supported by default, and no progress information is returned.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<string[]> | Promise used to return the URI array of the assets that are successfully cloned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Asset to be cloned has been deleted or hidden;<br>2. Asset to be cloned is cloud pictures, which can not be cloned;<br>3. The target album does not exist;<br>4. Insufficient system space;<br>5. Automatic renaming is not supported. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let assets: Array<string> = ['/Docs/Download/test.jpg'];
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let target: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let clonedUris: Array<string> = await phAccessHelper.cloneAssetsByPath(assets, target);
    console.info(`cloneAssetsByPath success, count: ${clonedUris.length}`);
  } catch (err) {
    console.error(`cloneAssetsByPath failed with error: ${err.code}, ${err.message}`);
  }
}
```

### modifyAlbumDefaultCoverOrder

modifyAlbumDefaultCoverOrder(coverOrderInfos: DefaultCoverOrderInfo[], disableModification: boolean, isAsyncRefreshAlbum: boolean): Promise\<void>

Sets the default cover selection rule for an album based on the default cover selection rule information of the batch albums in **coverOrderInfos**. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ---- | -------------------------- |
| coverOrderInfos | [DefaultCoverOrderInfo](#defaultcoverorderinfo)[] | Yes| Default cover selection rule information of the batch albums.<br>The valid combinations of **orderKey** and **orderSubKey** are as follows:<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_TAKEN and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_ADDED and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_TAKEN.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).SIZE and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](#photokeys).HIDDEN_TIME and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.|
| disableModification | boolean | Yes| Whether to disable the default cover modification option. **true**: yes; **false**: no.|
| isAsyncRefreshAlbum | boolean | Yes| Whether to refresh the default cover image of the album asynchronously. The value **true** indicates asynchronous refreshing, and **false** indicates synchronous refreshing.|

**Return value**

| Type| Description|
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Only the system album can be set without lpath. Otherwise, the setting is not supported;<br>2. The orderKey and orderSubKey are not in the specified range;<br>3. The order type must be either descending or ascending. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```javascript
async function modifyAlbumDefaultCoverOrder(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let coverOrderInfos: Array<photoAccessHelper.DefaultCoverOrderInfo> = [];
    let coverOrderInfo: photoAccessHelper.DefaultCoverOrderInfo = {
      albumType: photoAccessHelper.AlbumType.USER,
      albumSubtype: photoAccessHelper.AlbumSubtype.USER_GENERIC,
      lpath: "/Pictures/Users/1",
      orderKey: photoAccessHelper.PhotoKeys.DATE_ADDED,
      orderSubKey: photoAccessHelper.PhotoKeys.DISPLAY_NAME,
      orderType: 1,
    }
    coverOrderInfos.push(coverOrderInfo);
    let disableModification: boolean = false;
    let isAsyncRefreshAlbum: boolean = false;
    await phAccessHelper.modifyAlbumDefaultCoverOrder(coverOrderInfos, disableModification, isAsyncRefreshAlbum);
    console.info(`Succeeded in modifying default cover order of user album 1`);
  } catch (err) {
    console.error(`modifyAlbumDefaultCoverOrder failed with error: ${err.code}, ${err.message}`);
  }
}
```

### modifyHiddenAlbumDefaultCoverOrder

modifyHiddenAlbumDefaultCoverOrder(coverOrderInfos: DefaultCoverOrderInfo[], disableModification: boolean, isAsyncRefreshAlbum: boolean): Promise\<void>

Sets the default cover selection rule for hidden albums based on the default cover selection rule information of the batch albums in **coverOrderInfos**. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO and ohos.permission.MANAGE_PRIVATE_PHOTOS

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ---- | -------------------------- |
| coverOrderInfos | [DefaultCoverOrderInfo](#defaultcoverorderinfo)[] | Yes| Default cover selection rule information of the batch albums.<br>The valid combinations of **orderKey** and **orderSubKey** are as follows:<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_TAKEN and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_ADDED and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DATE_TAKEN.<br>- [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).SIZE and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.<br>- [PhotoKeys](#photokeys).HIDDEN_TIME and [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys).DISPLAY_NAME.|
| disableModification | boolean | Yes| Whether to disable the default cover modification option. **true**: yes; **false**: no.|
| isAsyncRefreshAlbum | boolean | Yes| Whether to refresh the default cover image of the hidden album asynchronously. The value **true** indicates asynchronous refreshing, and **false** indicates synchronous refreshing.|

**Return value**

| Type| Description|
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Only the system album can be set without lpath. Otherwise, the setting is not supported;<br>2. The orderKey and orderSubKey are not in the specified range;<br>3. The order type must be either descending or ascending. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```javascript
async function modifyHiddenAlbumDefaultCoverOrder(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let coverOrderInfos: Array<photoAccessHelper.DefaultCoverOrderInfo> = [];
    let coverOrderInfo: photoAccessHelper.DefaultCoverOrderInfo = {
      albumType: photoAccessHelper.AlbumType.SYSTEM,
      albumSubtype: photoAccessHelper.AlbumSubtype.HIDDEN,
      orderKey: photoAccessHelper.PhotoKeys.DATE_ADDED,
      orderSubKey: photoAccessHelper.PhotoKeys.DISPLAY_NAME,
      orderType: 1,
    }
    coverOrderInfos.push(coverOrderInfo);
    let disableModification: boolean = false;
    let isAsyncRefreshAlbum: boolean = false;
    await phAccessHelper.modifyHiddenAlbumDefaultCoverOrder(coverOrderInfos, disableModification, isAsyncRefreshAlbum);
    console.info(`Succeeded in modifying default cover order of hidden album`);
  } catch (err) {
    console.error(`modifyHiddenAlbumDefaultCoverOrder failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getAssetCompatibleCapability<sup>24+</sup>

getAssetCompatibleCapability(bundleName: string): Promise\<AssetCompatibleCapability>

Obtains the asset compatibility capability based on the bundle name. When an application obtains a file, it can determine whether compatibility conversion is required.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[AssetCompatibleCapability](arkts-apis-photoAccessHelper-i.md#assetcompatiblecapability24)&gt; | Promise used to return the specified asset compatibility capability.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The bundleName is invalid, such as null, undefined and empty.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let bundleName = "com.test.example";
    let capability : photoAccessHelper.AssetCompatibleCapability = await phAccessHelper.getAssetCompatibleCapability(bundleName);
  } catch (error) {
    console.error('failed to getAssetCompatibleCapability err', error);
  }
}
```

### setPreferredCompatibleMode

setPreferredCompatibleMode(bundleName: string, compatibleMode: PreferredCompatibleMode): Promise\<void>

Sets the preferred compatibility mode for an application based on the bundle name. This API uses a promise to return the result.

**Since**: 26.0.0

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name of the application.|
| compatibleMode | [PreferredCompatibleMode](arkts-apis-photoAccessHelper-e.md#preferredcompatiblemode) | Yes  | Preferred compatibility mode of the application.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The bundleName is invalid, such as null, undefined and empty.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a **phAccessHelper** instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function setPreferredCompatibleMode(
  phAccessHelper: photoAccessHelper.PhotoAccessHelper,
  bundleName: string,
  preferredCompatibleMode: photoAccessHelper.PreferredCompatibleMode
): Promise<void> {
  console.info('setPreferredCompatibleModeDemo');
  phAccessHelper.setPreferredCompatibleMode(bundleName, preferredCompatibleMode)
    .then(() => {
      console.info('setPreferredCompatibleMode successfully');
    })
    .catch((err: BusinessError) => {
      console.error(`The setPreferredCompatibleMode call failed. error: ${err.code}, ${err.message}`);
    });
}
```

### getPreferredCompatibleMode

getPreferredCompatibleMode(bundleName: string): Promise\<PreferredCompatibleMode>

Obtains the preferred compatibility mode configured for an application based on the bundle name. This API uses a promise to return the result.

**Since**: 26.0.0

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| bundleName | string | Yes  | Bundle name of the application.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[PreferredCompatibleMode](arkts-apis-photoAccessHelper-e.md#preferredcompatiblemode)&gt; | Preferred compatibility mode of the application.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The bundleName is invalid, such as null, undefined and empty.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function getPreferredCompatibleMode(
  phAccessHelper: photoAccessHelper.PhotoAccessHelper,
  bundleName: string
): Promise<photoAccessHelper.PreferredCompatibleMode> {
  console.info('getPreferredCompatibleModeDemo');
  let mode: photoAccessHelper.PreferredCompatibleMode = photoAccessHelper.PreferredCompatibleMode.DEFAULT;
  await phAccessHelper.getPreferredCompatibleMode(bundleName)
    .then((result: photoAccessHelper.PreferredCompatibleMode) => {
      mode = result;
      console.info('getPreferredCompatibleMode successfully');
    })
    .catch((err: BusinessError) => {
      console.error(`The getPreferredCompatibleMode call failed. error: ${err.code}, ${err.message}`);
    });
  return mode;
}
```

### moveAssetsToDir

moveAssetsToDir(assets: string[], target: string, option?: BatchOperationOptions): Promise\<string[]>

Moves assets to the file management directory. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| assets | string[] | Yes| Array of URIs of the assets to be moved.|
| target | string | Yes| Target directory in file management. Example: **/Docs/Download/**|
| option | [BatchOperationOptions](#batchoperationoptions) | No| Option for moving assets in batches. If this parameter is not specified, automatic renaming is supported by default, and no progress information is returned.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<string[]> | Promise used to return the array of paths to the assets that are successfully moved.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Moving to the target directory is not supported;<br>2. Asset to be moved does not exist;<br>3. Automatic renaming is not supported. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let assetFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let assets: Array<photoAccessHelper.PhotoAsset> = await assetFetchResult.getAllObjects();
    let assetUris: Array<string> = assets.map((item) => item.uri);
    let target: string = "/Docs/Download/";
    let movePaths: Array<string> = await phAccessHelper.moveAssetsToDir(assetUris, target);
    console.info(`moveAssetsToDir success, count: ${movePaths.length}`);
  } catch (err) {
    console.error(`moveAssetsToDir failed with error: ${err.code}, ${err.message}`);
  }
}
```

### moveAssetsByPath

moveAssetsByPath(assets: string[], target: Album, option?: BatchOperationOptions): Promise\<string[]>

Moves assets in file management to the target album. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| assets | string[] | Yes| Array of paths to the assets to be moved. Example: ["/Docs/Download/test.jpg"]|
| target | [Album](#album) | Yes| Target album.|
| option | [BatchOperationOptions](#batchoperationoptions) | No| Options for moving assets in batches. If this parameter is not specified, automatic renaming is supported by default, and no progress information is returned.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<string[]> | Promise used to return the array of URIs to the assets that are successfully moved.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Moving to the target Album is not supported;<br>2. Asset to be moved does not exist;<br>3. Automatic renaming is not supported. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let assets: Array<string> = ["/Docs/Download/test.jpg"];
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let target: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let moveUris: Array<string> = await phAccessHelper.moveAssetsByPath(assets, target);
    console.info(`moveAssetsByPath success, count: ${moveUris.length}`);
  } catch (err) {
    console.error(`moveAssetsByPath failed with error: ${err.code}, ${err.message}`);
  }
}
```

### createAssetsWithAlbum

createAssetsWithAlbum(creationSettings: CreationSetting[], isRealTimeThumb: boolean, albumUri?: string): Promise\<string[]>

Creates assets in batches. You can also specify whether to specify an album and whether to generate thumbnails in real time. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| creationSettings | [CreationSetting](arkts-apis-photoAccessHelper-i.md#creationsetting23)[] | Yes| List of settings for creating an asset.|
| isRealTimeThumb | boolean | Yes| Whether to generate a thumbnail in real time when an asset is created. The value **true** means to generate a thumbnail in real time when an asset is created, and **false** means the opposite.|
| albumUri | string | No| URI of the target album specified when an asset is created. If this parameter is not specified, the default value is an empty string.|

**Return value**

| Type| Description|
| ---- | ---- |
| Promise\<string[]> | Promise used to return the array of URIs to the assets that are successfully created. If the creation fails, **null** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 |Scenario-specific parameters are incorrect. Possible causes are as follows:<br>1. The input parameter creationSettings is null or undefined.<br>2. The array length of creationSettings is bigger than 500. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes:<br>1. Database corrupted; <br>2. The file system is abnormal; <br>3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    // Construct creation parameters.
    let creationSettings: Array<photoAccessHelper.CreationSetting> = [
      {
        title: 'test',
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE
      }
    ];
    // Do not generate a thumbnail in real time when an asset is created.
    let isRealTimeThumb: boolean = false;
    // Specify the album URI.
    let albumUri: string = 'file://media/PhotoAlbum/10';
    // Call the API to create an asset.
    let result: Array<string> = await phAccessHelper.createAssetsWithAlbum(
      creationSettings,
      isRealTimeThumb,
      albumUri
    );
    console.info('Succeeded in creating assets with album, uri is ' + result);
  } catch (err) {
    console.error(`createAssetsWithAlbum failed with error: ${err.code}, ${err.message}`);
  }
}
```

### canPerformDeepOptimizeSpace

canPerformDeepOptimizeSpace(): Promise&lt;boolean&gt;

Checks whether the system can perform in-depth optimization on the storage space. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** indicates that [startDeepOptimizeSpace](#startdeepoptimizespace) can be called, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let canPerform: boolean = await phAccessHelper.canPerformDeepOptimizeSpace();
    console.info(`canPerformDeepOptimizeSpace result: ${canPerform}`);
  } catch (err) {
    console.error(`canPerformDeepOptimizeSpace failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getDeepOptimizeSpace

getDeepOptimizeSpace(): Promise&lt;number&gt;

Obtains the size of storage space available for deep optimization, in bytes. This API uses a promise to return the result.

> - This API is time-consuming. You are advised to call [canPerformDeepOptimizeSpace](#canperformdeepoptimizespace) first to check whether the current system status allows the operation.
> - This API can be called only when **true** is returned.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the size of storage space available for deep optimization.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let canPerform: boolean = await phAccessHelper.canPerformDeepOptimizeSpace();
    if (canPerform) {
      let size: number = await phAccessHelper.getDeepOptimizeSpace();
      console.info(`getDeepOptimizeSpace result: ${size}`);
    }
  } catch (err) {
    console.error(`getDeepOptimizeSpace failed with error: ${err.code}, ${err.message}`);
  }
}
```

### startDeepOptimizeSpace

startDeepOptimizeSpace(callback?: Callback&lt;DeepOptimizeSpaceProgress&gt;): Promise&lt;void&gt;

Starts in-depth storage optimization. This API uses a promise to return the result.

You are advised to call the [canPerformDeepOptimizeSpace](#canperformdeepoptimizespace) API to check whether the current system status allows the operation. This API can be called only when **true** is returned.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| callback | Callback&lt;[DeepOptimizeSpaceProgress](#deepoptimizespaceprogress)&gt; | No| Callback used to return the deep optimization progress. The default value is **null**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800201 | Unsupported operation type. Possible causes:<br>1. Repeatedly started;<br>2. System is busy, please try again later. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    await phAccessHelper.startDeepOptimizeSpace((progress: photoAccessHelper.DeepOptimizeSpaceProgress) => {
      console.info(`startDeepOptimizeSpace progress: state=${progress.state}, progress=${progress.progress}`);
    });
    console.info('startDeepOptimizeSpace successfully');
  } catch (err) {
    console.error(`startDeepOptimizeSpace failed with error: ${err.code}, ${err.message}`);
  }
}
```

### stopDeepOptimizeSpace

stopDeepOptimizeSpace(): Promise&lt;void&gt;

Stops deep optimization of storage space. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    await phAccessHelper.stopDeepOptimizeSpace();
    console.info('stopDeepOptimizeSpace successfully');
  } catch (err) {
    console.error(`stopDeepOptimizeSpace failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getAlbumIdByBundleName<sup>22+</sup>

getAlbumIdByBundleName(bundleName: string): Promise&lt;number&gt;

Obtains the album ID in the media library based on the bundle name. This API uses a promise to return the result.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| bundleName | string | Yes| Bundle name of the application. The value can contain a maximum of 255 characters.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt; | Promise used to return the album ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.   |
| 202     | Called by non-system application.   |
| 23800151     | The bundleName is invalid, such as null, undefined and empty. |
| 23800301     | Internal system error. You are advised to retry and check the logs. Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getAlbumIdByBundleName');

  try {
      let albumId: number = await phAccessHelper.getAlbumIdByBundleName('test.bundleName');
      console.info('requestFile:: albumId: ', albumId);

      console.info('getAlbumIdByBundleName completed.');
      console.info(`albumId : ${albumId}`);
    } catch (err) {
      console.error(`getAlbumIdByBundleName failed: ${err.code}, ${err.message}`);
    }
}
```

## PhotoAsset

Provides APIs for encapsulating file asset attributes.

### open<sup>(deprecated)</sup>

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

The returned FD must be closed when it is not required.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. For security purposes, the API for obtaining the media file handle is no longer provided.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

The returned FD must be closed when it is not required.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. For security purposes, the API for obtaining the media file handle is no longer provided.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Favorites or unfavorites this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.setFavorite](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#setfavorite) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| favoriteState | boolean                   | Yes    | Whether to set the file as a favorite. The value **true** means to set it as a favorite, and **false** means to cancel the favorite. |
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
> This API is supported since API version 10 and deprecated since API version 11. You are advised to use [MediaAssetChangeRequest.setFavorite](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#setfavorite) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| favoriteState | boolean | Yes | Whether to set the file as a favorite. The value **true** indicates to set the file as a favorite, and **false** indicates to cancel the favorite. |

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  if (asset === undefined) {
    console.error('asset is undefined');
    return;
  }
  asset.setFavorite(true).then(() => {
    console.info('setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error(`setFavorite failed with error: ${err.code}, ${err.message}`);
  });
}
```

### setHidden<sup>(deprecated)</sup>

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets this file asset to the hidden state. This API uses an asynchronous callback to return the result.

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
| hiddenState | boolean                   | Yes   | Whether to set a file to hidden state. **true** to hide, **false** otherwise.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Sets this file asset to the hidden state. This API uses a promise to return the result.

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
| hiddenState | boolean | Yes   | Whether to set a file to hidden state. **true** to hide, **false** otherwise.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Obtains the Exif data from a JPG image and returns a JSON string. This API uses a promise to return the result.

The Exif data obtained are provided by the [image](../apis-image-kit/arkts-apis-image.md) module. For details about the Exif data, see [image.PropertyKey](../apis-image-kit/arkts-apis-image-e.md#propertykey7).

> **NOTE**
>
> This API returns a JSON string consisting of Exif tags. The complete Exif data consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via [FetchOptions](./arkts-apis-photoAccessHelper-i.md#fetchoptions).fetchColumns.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Promise used to return the Exif data, in JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Obtains the Exif data from a JPG image and returns a JSON string. This API uses an asynchronous callback to return the result.

The Exif data obtained are provided by the [image](../apis-image-kit/arkts-apis-image.md) module. For details about the Exif data, see [image.PropertyKey](../apis-image-kit/arkts-apis-image-e.md#propertykey7).

> **NOTE**
>
> This API returns a JSON string consisting of Exif tags. The complete Exif data consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via [FetchOptions](./arkts-apis-photoAccessHelper-i.md#fetchoptions).fetchColumns.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the Exif data, in JSON strings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

If error code 201 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201     | Permission denied.         |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

> **NOTE**
>
> **setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| pendingState | boolean | Yes   | Whether to set the file to pending state. **true** to pend, **false** otherwise.|
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('setPendingCallbackDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    photoAsset.setPending(true, async (err) => {
      if (err !== undefined) {
        console.error(`setPending(true) failed with error: ${err.code}, ${err.message}`);
        return;
      }
      // add asset resource.
      photoAsset.setPending(false, async (err) => {
        if (err !== undefined) {
          console.error(`setPending(false) failed with error: ${err.code}, ${err.message}`);
          return;
        }
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

> **NOTE**
>
> **setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| pendingState | boolean | Yes   | Whether to set the file to pending state. **true** to pend, **false** otherwise.|

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('setPendingPromiseDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    await photoAsset.setPending(true);
    // add asset resource.
    photoAsset.setPending(false);
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
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback used to return the result indicating whether the image or video asset is edited. **true** if edited, **false** otherwise. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
|Promise&lt;boolean&gt; | Promise used to return the result indicating whether the image or video asset is edited. **true** if edited, **false** otherwise. The default value is **false**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011   | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### createTemporaryCompatibleDuplicate<sup>21+</sup>

createTemporaryCompatibleDuplicate(): Promise&lt;void&gt;

Creates a JPEG-compatible copy for a third-party application that does not support HEIF/HEIC image encoding. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 23800151    | Scene parameters validate failed, possible causes:<br>1. The original file does not exist locally in PhotoAsset;<br>2. The original file format is not within the supported range<br>3. The original file is a temporary file or is being edited.|
| 23800301   |Internal system error.It is recommended to retry and check the logs.Possible causes:<br> 1. Database corrupted.2. The file system is abnormal.3. The IPC request timed out.   |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('createTemporaryCompatibleDuplicatePromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    await photoAsset.createTemporaryCompatibleDuplicate();
  } catch (err) {
    console.error(`createTemporaryCompatibleDuplicatePromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestSource<sup>11+</sup>

requestSource(callback: AsyncCallback&lt;number&gt;): void

Opens the source file and returns the FD. This API uses an asynchronous callback to return the result.

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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('requestSourceCallbackDemo')
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
    console.error(`requestSourceCallbackDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### requestSource<sup>11+</sup>

requestSource(): Promise&lt;number&gt;

Opens the source file and returns the FD. This API uses a promise to return the result.

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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('requestSourcePromiseDemo')
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
    console.error(`requestSourcePromiseDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### commitEditedAsset<sup>11+</sup>

commitEditedAsset(editData: string, uri: string, callback: AsyncCallback&lt;void&gt;)

Commits the edited image or video asset. This API uses an asynchronous callback to return the result.

The edited file is transferred to the media library based on the URI, which is **FileUri** of the edited file in the application sandbox directory. For details, see [File URI](../apis-core-file-kit/js-apis-file-fileuri.md).

> **NOTE**
>
> The commit operation overwrites the previous edited data.

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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('commitEditedAssetCallbackDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (photoAsset === undefined) {
      console.error('photoAsset is undefined');
      return;
    }
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

> **NOTE**
>
> The commit operation overwrites the previous edited data.

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
| 14000011   | System inner fail. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.       |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

> **NOTE**
>
> This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

> **NOTE**
>
> This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('revertToOriginalPromiseDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (photoAsset === undefined) {
      console.error('getHiddenAlbumsViewCallback albums is undefined');
      return;
    }
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
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes   | Callback invoked twice to return the quick and quality thumbnails obtained.|

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes   | Callback used to return the thumbnails obtained. The callback may be invoked more than once, depending on **options**.|

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Since API version 22, the **ohos.permission.MEDIA\_LOCATION** permission is required when **analysisType** is set to [ANALYSIS\_DETAIL\_ADDRESS](#analysistype11). If the permission is not granted, the universal error code [201 Permission Denied](../errorcode-universal.md#201-permission-denied) is thrown.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| 201 | Permission denied.  | 
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. | 
| 14000011       | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### getKeyFrameThumbnail<sup>18+</sup>

getKeyFrameThumbnail(beginFrameTimeMs: number, type: ThumbnailType): Promise<image.PixelMap>

Obtains the thumbnail of the specified type for the key frame. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| beginFrameTimeMs | number | Yes   | Time of the start frame, in ms. The value **0** indicates the cover frame.|
| type | [ThumbnailType](#thumbnailtype13)| Yes   | Type of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the PixelMap of the thumbnail obtained. The cover frame is returned by default if no thumbnail is obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by non-system application.       |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | Internal system error. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { common }  from '@kit.AbilityKit';
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(context: Context) {
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

### convertImageFormat<sup>20+</sup>

convertImageFormat(title: string, imageFormat: SupportedImageFormat): Promise&lt;PhotoAsset&gt;

Duplicates an image within the same album (either user-created or application-specific) and converts it to the specified format. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| title | string | Yes   | Title of the new image.|
| imageFormat | [SupportedImageFormat](#supportedimageformat20) | Yes   | Format of the new image.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise\<[PhotoAsset](#photoasset)> | Promise used to return the PhotoAsset instance representing the new image file.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied.  | 
| 202      | Called by non-system application. |
| 23800151 | Scene parameters validate failed. Possible causes: 1. The original file does not exist locally in PhotoAsset. 2. The original file format is not within the supported range. 3. The original file is a temporary file or is being edited. 4. The title is the same with an image in the same album. 5. PhotoAsset is a photo in the trash or a hidden photo. 6. The title does not meet the parameter specifications. |
| 23800301    | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('convertImageFormatDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset = await fetchResult.getFirstObject();
  try {
    let newPhotoAsset = await photoAsset.convertImageFormat('test', photoAccessHelper.SupportedImageFormat.AVFILE_FORMAT_JPG);
    console.error(`convertImageFormat success.`);
  } catch (err) {
    console.error(`convertImageFormat failed. error: ${err.code}, ${err.message}`);
  }
}
```

## SharedPhotoAsset<sup>13+</sup>

Describes the information about a shared media asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### Properties

| Name| Type| Read-Only| Optional| Description|
| ---- | --- | ---- | ---- | --- |
| fileId | number | No| No| ID of the media asset.<br>**System API**: This is a system API.|
| uri | string | No| No| URI of the media asset.<br>**System API**: This is a system API.|
| data | string | No| No| Path data of the media asset.<br>**System API**: This is a system API.|
| mediaType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | No| No| Media type of the media asset.<br>**System API**: This is a system API.|
| displayName | string | No| No| Display name of the media asset.<br>**System API**: This is a system API.|
| size | number  | No| No| Size of the media asset file, in bytes.<br>**System API**: This is a system API.|
| dataAdded | number | No| No| Data of the added media asset, in seconds.<br>**System API**: This is a system API.|
| dataModified | number | No| No| Data of the modified media asset, in seconds.<br>**System API**: This is a system API.|
| duration | number | No| No| Duration of the video-type media asset, in milliseconds.<br>**System API**: This is a system API.|
| width | number | No| No| Width of the media asset, in pixels.<br>**System API**: This is a system API.|
| height | number | No| No| Height of the media asset, in pixels.<br>**System API**: This is a system API.|
| dataTaken | number | No| No| Time when the media asset is saved to the local host after being taken, in seconds.<br>**System API**: This is a system API.|
| orientation | number | No| No| Rotation angle of the media asset, in degrees.<br>**System API**: This is a system API.|
| isFavorite | boolean | No| No| Whether the media asset is marked as a favorite. **true** if marked, **false** otherwise.<br>**System API**: This is a system API.|
| title | string | No| No| Title of the media asset.<br>**System API**: This is a system API.|
| position | [PositionType](arkts-apis-photoAccessHelper-e.md#positiontype16) | No| No| Location of the media asset.<br>**System API**: This is a system API.|
| dataTrashed | number | No| No| Whether the media asset is moved to the trash.<br>**System API**: This is a system API.|
| hidden | boolean | No| No| Whether the media asset is hidden. **true** if hidden, **false** otherwise.<br>**System API**: This is a system API.|
| userComment | string | No| No| User comments on the media asset.<br>**System API**: This is a system API.|
| cameraShotKey | string | No| No| Camera shot information of the media asset.<br>**System API**: This is a system API.|
| dateYear | string | No| No| Year when the media asset was created.<br>**System API**: This is a system API.|
| dateMonth | string | No| No| Month when the media asset was created.<br>**System API**: This is a system API.|
| dateDay | string | No| No| Time when the media asset was created.<br>**System API**: This is a system API.|
| pending | boolean | No| No| Whether the media asset is in a pending state. **true** if pending, **false** otherwise.<br>**System API**: This is a system API.|
| dateAddedMs | number | No| No| Time elapsed after the media asset was added, in milliseconds.<br>**System API**: This is a system API.|
| dateTrashedMs | number | No| No| Time elapsed after the media asset was moved to the recycle bin, in milliseconds.<br>**System API**: This is a system API.|
| subtype | [PhotoSubtype](#photosubtype) | No| No| Subtype of the media asset.<br>**System API**: This is a system API.|
| movingPhotoEffectMode | [MovingPhotoEffectMode](#movingphotoeffectmode12) | No| No| Effect of the moving photo.<br>**System API**: This is a system API.|
| dynamicRangeType | [DynamicRangeType](arkts-apis-photoAccessHelper-e.md#dynamicrangetype12) | No| No| Dynamic range type of the media asset.<br>**System API**: This is a system API.|
| thumbnailReady | boolean | No| No| Whether the thumbnail of the media asset is ready. **true** if ready, **false** otherwise.<br>**System API**: This is a system API.|
| lcdSize | string | No| No| Width and height of the LCD thumbnail of the media asset.<br>**System API**: This is a system API.|
| thmSize | string | No| No| Width and height of the thumb thumbnail of the media asset.<br>**System API**: This is a system API.|
| thumbnailModifiedMs<sup>14+</sup> | number | No| Yes| Time elapsed since the thumbnail status of the media asset changed, in milliseconds.<br>**System API**: This is a system API.|
| thumbnailVisible<sup>14+</sup> | [ThumbnailVisibility](#thumbnailvisibility14) | No| No| Whether the thumbnail of the media asset is visible.<br>**System API**: This is a system API.|

## Album

Provides APIs to manage albums.

### Properties

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name          | Type   | Read-Only  | Optional | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| dateAdded<sup>18+</sup>    | number | Yes   | Yes  | Time when the album is added, in seconds.<br>**System API**: This is a system API.|
| dateModified<sup>18+</sup>    | number | Yes   | Yes  | Time when the album is modified, in seconds.<br>**System API**: This is a system API.|
| coverUriSource<sup>20+</sup>    | number | Yes   | Yes  | Source URI of the album cover.<br>**System API**: This is a system API.|
| uploadStatus<sup>22+</sup>    | boolean | Yes   | No  | Whether the album can be synced to cloud storage or family storage. **true** if it can be synced, **false** otherwise.<br>**System API**: This is a system API.|
| HIDDEN<sup>23+</sup>    | boolean | Yes   | Yes  | Whether the album is hidden. **true** if hidden, **false** otherwise.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAssets](#deleteassets11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Deletes image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. It is recommended that the number of images or videos to be deleted be less than or equal to 1000. This API uses a promise to return the result.

> **NOTE**
>
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.deleteAssets](#deleteassets11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Sets the cover of the user album. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.setCoverUri](#setcoveruri11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Sets the cover of the user album. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 10 and deprecated since API version 11. Use [MediaAlbumChangeRequest.setCoverUri](#setcoveruri11) instead.

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

If error code 13900012 is returned, follow the instructions provided in [Before You Start](../../media/medialibrary/photoAccessHelper-preparation.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
    if (fetchResult === undefined) {
      console.error('getFaceId fetchResult is undefined');
      return;
    }
    let album = await fetchResult?.getFirstObject();
    if (album === undefined) {
      console.error('album is undefined');
      return;
    }
    let faceId = await album?.getFaceId();
    if (faceId === undefined) {
      console.error('faceId is undefined');
      return;
    }
    console.info(`getFaceId successfully, faceId: ${faceId}`);
    fetchResult.close();
  } catch (err) {
    console.error(`getFaceId failed with err: ${err.code}, ${err.message}`);
  }
}
```

### getSelectedAssets<sup>22+</sup>

getSelectedAssets(optionCheck: FetchOptions, filter?: string): Promise\<FetchResult\<PhotoAsset>>

Obtains portrait album assets that meet filter criteria.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| optionCheck | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes| Fetch options, which limit the number of assets returned.|
| filter | string | No| Filter option, which must be a JSON string.<br>Currently, only **currentFileId** is supported, which indicates the file ID of the currently displayed featured portrait card. An example is '{"currentFileId":"123"}'.<br>If this parameter is not provided, assets are returned from the beginning.<br>If **currentFileId** is provided, assets with scores less than or equal to the calculated score based on the **currentFileId** are returned.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;FetchResult&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the image information.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message                                                    |
| :------- | :----------------------------------------------------------- |
| 201      | Permission denied.                                           |
| 202      | Called by non-system application.                            |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The input parameter is not within the valid range. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example1(phAccessHelper: photoAccessHelper.PhotoAccessHelper) : Promise<void> {
  try {
    console.info('getSelectedAssetsDemo');
    let predicatesHomePage: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicatesHomePage.equalTo('user_display_level', 1);
    let optionHome: photoAccessHelper.FetchOptions = {
      predicates: predicatesHomePage,
      fetchColumns: [],
    };
    let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART,
      photoAccessHelper.AlbumSubtype.PORTRAIT, optionHome);

    if (albumFetchResult === undefined) {
      console.error('getSelected fetchResult is undefined');
      return;
    }
    let album = await albumFetchResult?.getFirstObject();
    if (album === undefined) {
      console.error('album is undefined');
      return;
    }

    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await album.getSelectedAssets(fetchOption);
    let photoAsset = await fetchResult.getFirstObject();
    if (!fetchResult||fetchResult.getCount() <= 0) {
      console.error('get selected assets in album with empty dataList');
      return;
    }

    let uriParts = photoAsset.uri.split('/');
    let fileId = uriParts[uriParts.length - 3];
    let filter = `{"currentFileId":"${fileId}"}`;
    let fetchResult1 = await album.getSelectedAssets(fetchOption, filter);
    if (!fetchResult1||fetchResult1.getCount() <= 0) {
      console.error('get selected assets in album with empty dataList');
      return;
    }
    let photoAssetList = fetchResult.getAllObjects();
    console.info('get selected assets in album success');
  } catch (err) {
    console.error(`get selected assets in album fail, error: ${err?.code}, ${err?.message}`);
  }
}
```

### getAttribute

getAttribute(attrs: AlbumAttribute[]): Promise<Record<AlbumAttribute, AlbumAttributeInfo>>

Obtains album attributes. This API uses a promise to return the result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| attrs | [AlbumAttribute](#albumattribute)[] | Yes| List of album attributes to be obtained. The array can contain a maximum of 20 elements and cannot be empty.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;Record&lt;[AlbumAttribute](#albumattribute), [AlbumAttributeInfo](#albumattributeinfo)&gt;&gt; | Promise used to return the album attributes and their values.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. Unsupported attribute;<br>2. The attrs size exceeds 20;<br>3. Empty or duplicate attribute; |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes:<br>1. Database corrupted.<br>2. The file system is abnormal.<br>3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('getAttributeDemo');
    // Create query conditions.
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    // Configure query options.
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    // Obtain the smart album (portrait album).
    let albumFetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SMART, 
      photoAccessHelper.AlbumSubtype.PORTRAIT, fetchOptions);
    // Obtain the first album object.
    let album = await albumFetchResult.getFirstObject();
    if (album === undefined) {
      console.error('album is undefined');
      return;
    }
    // Define the list of attributes to be obtained.
    let attrs: [photoAccessHelper.AlbumAttribute] = [
      photoAccessHelper.AlbumAttribute.EXTRA_INFO_ATTR
    ];
    // Obtain the album attributes.
    let attrInfo = await album.getAttribute(attrs);
    console.info(`getAttribute successfully, attrInfo: ${JSON.stringify(attrInfo)}`);
  } catch (err) {
    console.error(`getAttribute failed with err: ${err.code}, ${err.message}`);
  }
}
```

## MediaAssetEditData<sup>11+</sup>

Represents the edited media asset data.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### Properties

| Name          | Type   | Read-Only| Optional| Description  |
| ------------ | ------ | ---- | ---- | ------- |
| compatibleFormat | string | No  | No   | Format of the edited data.<br>**System API**: This is a system API.   |
| formatVersion | string | No  | No  | Version of the data format.<br>**System API**: This is a system API.   |
| data | string | No  | No  | Content edited.<br>**System API**: This is a system API.   |

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

The file name must meet the following requirements:

- A valid file name must include a base name and a supported image or video extension.

- The total length of the file name must be between 1 and 255 characters.

- The base name must not contain any invalid characters.<br>Starting from API version 18, the following characters are considered invalid: \ / : * ? " < > | <br>For API versions 10 to 17, the following characters are considered invalid: . .. \ / : * ? " ' ` < > | { } [ ]

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

If error code 14000001 is returned, refer to [PhotoKeys](#photokeys) to learn about the format and length requirements of the file name.

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
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

### setHidden<sup>11+</sup>

setHidden(hiddenState: boolean): void

Hides this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean  | Yes   | Whether to hide the file. **true** to hide, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

> **NOTE**
>
> For the same asset change request, this API cannot be repeatedly called after resources are successfully added.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
class PhotoProxyImpl implements photoAccessHelper.PhotoProxy {
  // Implement PhotoProxy.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset, context: Context) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| cameraShotKey | string | Yes  | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.)|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset) {
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
| mode | [MovingPhotoEffectMode](#movingphotoeffectmode12) | Yes  | Effect of the moving photo.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016       | Operation Not Support.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset) {
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
| watermarkType | [WatermarkType](#watermarktype14) | Yes  | Watermark type to set.<br>**NOTE**<br>**WatermarkType.DEFAULT** cannot be passed.|

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Permanently deletes images or videos in batches. This API uses a promise to return the result.

> **NOTE**
>
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assets | Array\<[PhotoAsset](#photoasset)>| Yes   | Array of images or videos to be permanently deleted. The array can contain a maximum of 500 elements.|

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
| 14000011   | Internal system error. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('deleteAssetsPermanentlyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
    await photoAccessHelper.MediaAssetChangeRequest.deleteLocalAssetsPermanently(context, photoAssetList);
  } catch (err) {
    console.error(`deleteAssetsPermanentlyDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setHasAppLink<sup>21+</sup>

setHasAppLink(hasAppLink: int): void

Sets the status of the app link association.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| hasAppLink | int | Yes   | Whether to enable or disable the app link association.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.       |
| 23800301 | Internal system error.It is recommended to retry and check the logs. |
| 23800151 | The scenario parameter verification fails.Possible causes: The input parameter is not within the valid range. |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

enum linkType {
  NOT_DECODED = 0,
  LINK_NOT_EXIST = 1,
  LINK_EXIST = 2
}

async function example(asset: photoAccessHelper.PhotoAsset, hasAppLink: linkType, context: Context) {
    try {
      let phAccessHelper: photoAccessHelper.PhotoAccessHelper =
        photoAccessHelper.getPhotoAccessHelper(context);
      let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
        new photoAccessHelper.MediaAssetChangeRequest(asset);
      assetChangeRequest.setHasAppLink(hasAppLink);
      await phAccessHelper.applyChanges(assetChangeRequest);
    } catch (error) {
      console.error('set hasAppLink error: ' + error);
      return;
    }
}
```

### setAppLinkState<sup>24+</sup>

setAppLinkState(appLinkState: AppLinkState): void

Sets the status of the app link association.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| appLinkState | [AppLinkState](#applinkstate24) | Yes   | Whether to enable or disable the app link association.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Invoked by non-system applications.       |
| 23800301 | Internal system error.It is recommended to retry and check the logs. |
| 23800151 | The scenario parameter verification fails.Possible causes: The input parameter is not within the valid range. |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(asset: photoAccessHelper.PhotoAsset, context: Context) {
    try {
      let phAccessHelper: photoAccessHelper.PhotoAccessHelper =
        photoAccessHelper.getPhotoAccessHelper(context);
      let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
        new photoAccessHelper.MediaAssetChangeRequest(asset);
      assetChangeRequest.setAppLinkState(photoAccessHelper.AppLinkState.HAS_NO_LINK);
      await phAccessHelper.applyChanges(assetChangeRequest);
    } catch (error) {
      console.error('set appLink state error: ' + error);
      return;
    }
}
```

### setAppLinkInfo<sup>21+</sup>

setAppLinkInfo(appLink: string): void

Sets the information about the app link association.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| appLink | string | Yes   | Information about the app link association.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.       |
| 23800301 | Internal system error.It is recommended to retry and check the logs. |
| 23800151 | The scenario parameter verification fails.Possible causes: The input parameter's length is not within the valid range. |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';


async function example(asset: photoAccessHelper.PhotoAsset, appLinkInfo: string, context: Context) {
    try {
      let phAccessHelper: photoAccessHelper.PhotoAccessHelper =
        photoAccessHelper.getPhotoAccessHelper(context);
      let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest =
        new photoAccessHelper.MediaAssetChangeRequest(asset);
      assetChangeRequest.setAppLinkInfo(appLinkInfo);
      await phAccessHelper.applyChanges(assetChangeRequest);
    } catch (error) {
      console.error('set appLinkInfo error: ' + error);
      return;
    }
}
```

### setCompositeDisplayMode<sup>22+</sup>

setCompositeDisplayMode(compositeDisplayMode: CompositeDisplayMode): Promise\<void\>

Sets the display mode of the composite image. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| compositeDisplayMode | [CompositeDisplayMode](#compositedisplaymode22) | Yes   | Display mode.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.       |
| 23800151 | Scene parameters validate failed. Possible causes: 1. The CompositeDisplayMode is not within the supported range; 2.The original file does not exist locally in PhotoAsset; 3. The PhotoAsset is not composite Asset; 4. The original file format is not within the supported range; 5. The original file has been edited. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
    console.info('setCompositeDisplayModeDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    try {
      let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
      let asset = await fetchResult.getFirstObject();
      let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
      assetChangeRequest.setCompositeDisplayMode(photoAccessHelper.CompositeDisplayMode.DEFAULT);
      await phAccessHelper.applyChanges(assetChangeRequest);
      console.info('apply setCompositeDisplayModeDemo successfully');
    } catch (err) {
      console.error(`apply setCompositeDisplayModeDemo failed with error: ${err.code}, ${err.message}`);
    }
}
```

### setHiddenAttribute

setHiddenAttribute(hiddenState: boolean): void

Sets the hidden state of an asset.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | Yes   | Whether to set the hidden state of an asset. **true** means to set the hidden state of an asset, and **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The asset is not exist. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setHiddenAttributeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.setHiddenAttribute(true);
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('setHiddenAttribute successfully');
  } catch (err) {
    console.error(`setHiddenAttribute failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setTitleByFile

setTitleByFile(name: string): void

Sets an asset title based on the file management scenario.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Name of the asset to be set.<br>The file name specifications are as follows:<br>- It must not contain a file name extension.<br>- The file name length ranges from 1 to 255 characters.<br>- It must not contain the following invalid characters: \\/:*?" ' ` < > \| { } [ ]<br>- It cannot be only a period (.) or two consecutive periods (..).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The asset is not exist. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);
    assetChangeRequest.setTitleByFile('new_file_name');
    await phAccessHelper.applyChanges(assetChangeRequest);
    console.info('setTitleByFile successfully');
  } catch (err) {
    console.error(`setTitleByFile failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteLocalAssetsPermanentlyWithUri<sup>19+</sup>

static deleteLocalAssetsPermanentlyWithUri(context: Context, assetUris: Array&lt;String&gt;): Promise&lt;void&gt;

Permanently deletes images or video assets in batches by URI. This API uses a promise to return the result.

> **NOTE**
>
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assetUris | Array&lt;String&gt; | Yes   | Array of URIs of the images or videos to be permanently deleted. The array can contain a maximum of 500 elements.|

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
| 13900020 | Invalid argument. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.  |     

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
    console.info('deleteLocalAssetsPermanentlyWithUriDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
    };
    try {
        let  photoUris: Array<string> = [];
        let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
        let assets: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
        for (const asset of assets) {
            if (!asset?.uri) {
                continue; 
            }
            let uri:string = asset.uri.trim();
            photoUris.push(uri);
        }
        await photoAccessHelper.MediaAssetChangeRequest.deleteLocalAssetsPermanentlyWithUri(context, photoUris);
    } catch (err) {
    console.error(`deleteLocalAssetsPermanentlyWithUriDemo failed with error: ${err.code}, ${err.message}`);
}
}
```

### deleteLocalAssetsWithUri<sup>22+</sup>

static deleteLocalAssetsWithUri(context: Context, assetUris: string[]): Promise&lt;void&gt;

Deletes local media assets to the trash in batches. This API uses a promise to return the result.

>**NOTE**
>
>- If the assets are only on the local device, they are moved directly to the trash.
>- If the assets are only in the cloud, no changes are made.
>- If the assets are on both the local device and the cloud, after deletion, they only remain in the cloud, and the local copies are moved in the trash.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assetUris | string[] | Yes   | Array of URIs of the images or videos to be deleted. The array can contain a maximum of 500 elements.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by non-system application.       |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The context is empty; 2. Asset uri array size is empty or bigger than 500 . |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1.Database corrupted; 2.The file system is abnormal; 3.The IPC request timed out. | 

**Example**

```ts
async function example(context: Context, assetUri: string) {
    console.info('deleteLocalAssetsWithUriDemo');
    try {
      await photoAccessHelper.MediaAssetChangeRequest.deleteLocalAssetsWithUri(context, [assetUri]);
    } catch (err) {
      console.error(`deleteLocalAssetsWithUri failed with error: ${err.code}, ${err.message}`);
    }
}
```

### deleteCloudAssetsWithUri<sup>22+</sup>

static deleteCloudAssetsWithUri(context: Context, assetUris: string[]): Promise&lt;void&gt;

Deletes cloud media assets to the trash in batches. This API uses a promise to return the result.

>**NOTE**
>
>- If the assets are only on the local device, no changes are made.
>- If the assets are only in the cloud, they are moved directly to the trash.
>- If the assets are on both the local device and the cloud, after deletion, they only remain on the local device, and the cloud copies are moved in the trash.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assetUris | string[] | Yes   | Array of URIs of the images or videos to be deleted. The array can contain a maximum of 500 elements.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by non-system application.       |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The context is empty; 2. Asset uri array size is empty or bigger than 500 . |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1.Database corrupted; 2.The file system is abnormal; 3.The IPC request timed out. | 

**Example**

```ts
async function example(context: Context, assetUri: string) {
    console.info('deleteCloudAssetsWithUriDemo');
    try {
      await photoAccessHelper.MediaAssetChangeRequest.deleteCloudAssetsWithUri(context, [assetUri]);
    } catch (err) {
      console.error(`deleteCloudAssetsWithUri failed with error: ${err.code}, ${err.message}`);
    }
}
```

### deleteAssetsPermanentlyWithUri<sup>24+</sup>

static deleteAssetsPermanentlyWithUri(context: Context, assetUris: string[]): Promise\<void\>

Permanently deletes images or videos in batches by URI. The deleted images or videos are not stored in the recycle bin. This API uses a promise to return the result.

> **NOTE**
>
> - Assets that exist only on the local device, on the cloud, or on both the local device and the cloud can be permanently deleted. The deleted assets are not stored in the recycle bin.
> - This operation is irreversible. The deleted assets cannot be restored. Exercise caution when performing this operation.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes   | Context of the ability instance.|
| assetUris | string[] | Yes   | Array of URIs of the images or videos to be deleted. The array can contain a maximum of 500 elements.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.       |
| 202   | Called by nonsystem application.       |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The context is empty; 2. Asset uri array size is empty or bigger than 500 . |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes:1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. | 

**Example**

```ts
async function example(context: Context, assetUri: string) {
    console.info('deleteAssetsPermanentlyWithUri');
    try {
      await photoAccessHelper.MediaAssetChangeRequest.deleteAssetsPermanentlyWithUri(context, [assetUri]);
      console.info('deleteAssetsPermanentlyWithUri success.');
    } catch (err) {
      console.error(`deleteAssetsPermanentlyWithUri failed with error: ${err.code}, ${err.message}`);
    }
}
```

### setMovingPhotoVersion

setMovingPhotoVersion(version: number): void

Saves the version number of a moving photo.

**Since:** 26.0.0

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| version | number | Yes   | Version number of the moving photo.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 23800151 | Parameter error, Only supports 9. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setMovingPhotoVersionDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let asset = await fetchResult.getFirstObject();
  let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(asset);

  let movingPhotoVersion: number = 9;
  assetChangeRequest.setMovingPhotoVersion(movingPhotoVersion);
  phAccessHelper.applyChanges(assetChangeRequest).then(() => {
    console.info('apply setMovingPhotoVersion successfully');
  }).catch((err: BusinessError) => {
    console.error(`apply setMovingPhotoVersion failed with error: ${err.code}, ${err.message}`);
  });
}
```

## MediaAssetsChangeRequest<sup>11+</sup>

Represents a request for changing multiple assets.

### Properties

**System API**: This is a system API.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name          | Type   | Read-Only  | Optional | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| comment<sup>23+</sup>    | string | Yes   | No  | Used to verify the [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11) type.<br>If a class (such as **MediaAssetsChangeRequest**) object can be accessed, it is an implementation class of **MediaChangeRequest**.|

### setHidden<sup>11+</sup>

setHidden(hiddenState: boolean): void

Hides this file.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean  | Yes   | Whether to hide the file. **true** to hide, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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
| isRencentShow | boolean | Yes  | Whether this asset is displayed in the **Recent** list. **true** if displayed, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Creates a MediaAlbumChangeRequest instance.

The album name must meet the following requirements:

- The total length of the album name must be between 1 and 255 characters.

- It must not contain any invalid characters, which are:<br> . .. \ / : * ? " ' ` < > | { } [ ]

- The characters are case insensitive.

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
| [MediaAlbumChangeRequest](#mediaalbumchangerequest11) | MediaAlbumChangeRequest instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011   | System inner fail.        |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
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

Deletes user albums. This API uses a promise to return the result.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
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

### deleteAlbumsWithUri<sup>19+</sup>

static deleteAlbumsWithUri(context: Context, albumUris: Array&lt;string&gt;): Promise&lt;void&gt;

Deletes user albums by URI. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| albumUris  |  Array&lt;string&gt;          | Yes  | Array of URIs of the albums to be deleted.        |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 202      |  Called by non-system application.  |
| 13900020 |  Invalid argument. | 
| 14000011 |  Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2.The file System is abnormal; 3. The IPC request timed out;  |

**Example**

```ts
async function example(context: Context, albumUri: string) {
  console.info('deleteAlbumsWithUriDemo');
  try {
    await photoAccessHelper.MediaAlbumChangeRequest.deleteAlbumsWithUri(context, [albumUri]);
    console.info('deleteAlbums successfully');
  } catch (err) {
    console.error(`deleteAlbumsWithUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setUploadStatus<sup>22+</sup>

static setUploadStatus(context: Context, albums: Album[], allowUpload: boolean): Promise&lt;void&gt;

Sets whether the albums can be synced to cloud storage or family storage. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md) | Yes  | Context of the ability instance.|
| albums  |   [Album](#album)[]          | Yes  | Array of albums whose sync status is to be set. You can set the sync status for user albums and source albums. The array can contain a maximum of 500 elements.        |
| allowUpload  |   boolean       | Yes  | Whether the albums can be synced to cloud storage or family storage. **true** if they can be synced, **false** otherwise.        |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 202      |  Called by non-system application.  |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The context is empty; 2. Album array size is bigger than 500. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1.Database corrupted; 2.The file system is abnormal; 3.The IPC request timed out. |

**Example**

```ts
async function example(context: Context, album: photoAccessHelper.Album) {
  console.info('setUploadStatusDemo');
  try {
    let allowUpload = true;
    await photoAccessHelper.MediaAlbumChangeRequest.setUploadStatus(context, [album], allowUpload);
    console.info('setUploadStatus successfully');
  } catch (err) {
    console.error(`setUploadStatus failed with error: ${err.code}, ${err.message}`);
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setCoverUriDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (albums === undefined) {
      console.error('getHiddenAlbumsViewCallback albums is undefined');
      return;
    }
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset === undefined) {
      console.error('asset is undefined');
      return;
    }
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.setCoverUri(asset.uri);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setCoverUri successfully');
  } catch (err) {
    console.error(`setCoverUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### resetCoverUri<sup>20+</sup>

resetCoverUri(): void

Resets the cover.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 23800301       | Internal system error.It is recommended to retry and check the logs. Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](./arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('resetCoverUriDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.resetCoverUri();
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('resetCoverUri successfully');
  } catch (err) {
    console.error(`resetCoverUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setHiddenAttribute

setHiddenAttribute(hiddenState: boolean, isInherited: boolean):void

Sets the hidden state of an album.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | Yes   | Hidden state of the album. The value **true** indicates that the album is hidden, and **false** indicates the opposite.|
| isInherited | boolean | Yes   | Whether all subfiles or subdirectories in the album inherit the hidden state. The value **true** indicates that the hidden state is inherited, and **false** indicates the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The album is not exist. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('albumSetHiddenAttributeDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOption);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.setHiddenAttribute(true, true);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('album setHiddenAttribute successfully');
  } catch (err) {
    console.error(`album setHiddenAttribute failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setAlbumNameByFile

setAlbumNameByFile(name: string): void

Sets an album name based on the file management scenario.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| name | string | Yes| Album name to set.<br>The album name must meet the following requirements:<br>- The album name length ranges from 1 to 255 characters.<br>- It must not contain the following invalid characters: \\/:*?" ' ` < > \| { } [ ]<br>- It cannot be only a period (.) or two consecutive periods (..).<br>- The characters are case insensitive.<br>- The album name must be unique.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The album is not exist. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOption);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.setAlbumNameByFile('new_album_name');
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setAlbumNameByFile successfully');
  } catch (err) {
    console.error(`setAlbumNameByFile failed with error: ${err.code}, ${err.message}`);
  }
}
```

### operateAttribute

operateAttribute(operation: AlbumOperation): void

Sets the album attribute. The setting takes effect only after [applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) is called.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permission**: ohos.permission.ACCESS_MEDIALIB_THUMB_DB

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| operation | [AlbumOperation](#albumoperation) | Yes| Album attribute setting to be executed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. The attr of operation is invalid.<br>2. The type of operation is invalid.<br>3. The values or operation is incorrect. |
| 23800201 | Unsupported operation type. It is recommended to check the logs.<br>Possible causes:<br>1. Unsupported AlbumAttribute for the album.<br>2. Unsupported AlbumOperationType for the AlbumAttribute.<br>3. Other operation limit. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('operateAttributeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
      await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER,
        photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    if (album === undefined) {
      console.error('album is undefined');
      return;
    }

    let operation: photoAccessHelper.AlbumOperation = {
      attr: photoAccessHelper.AlbumAttribute.NICK_NAME_ATTR,
      type: photoAccessHelper.AlbumOperationType.UPDATE,
      values: ['newNickname']
    };
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest =
      new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.operateAttribute(operation);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('operateAttribute successfully');
  } catch (err) {
    console.error(`operateAttribute failed with error: ${err.code}, ${err.message}`);
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### moveAssetsWithUri<sup>19+</sup>

moveAssetsWithUri(assetUris: Array&lt;String&gt;, targetAlbum: Album): void

Moves assets in an album to another album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assetUris | Array&lt;String&gt; | Yes  | Array of URIs of the assets to move.|
| targetAlbum | [Album](#album) | Yes  | Album to which the assets are to be moved.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | Called by non-system application.         |
| 13900020 | Invalid argument.| 
| 14000011 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.         |
| 14000016 | Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('moveAssetsWithUriDemo');
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
    if (asset === undefined) {
      console.error('asset is undefined');
      return;
    }
    if (albumFetchResult.isAfterLast()) {
      console.error('lack of album to be moved into');
      return;
    }
    let nextAlbum: photoAccessHelper.Album = await albumFetchResult.getNextObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.moveAssetsWithUri([asset.uri], nextAlbum);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('moveAssetsWithUri successfully');
  } catch (err) {
    console.error(`moveAssetsWithUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### recoverAssets<sup>11+</sup>

recoverAssets(assets: Array&lt;PhotoAsset&gt;): void

Restores the assets corresponding to the specified PhotoAsset object array from the trash.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

### recoverAssetsWithUri<sup>19+</sup>

recoverAssetsWithUri(assetUris: Array&lt;String&gt;): void

Restores the assets corresponding to the specified URI string array from the trash.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assetUris | Array&lt;String&gt; | Yes  | Array of URIs of the assets to recover.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | Called by non-system application.         |
| 13900020 | Invalid argument.| 
| 14000011 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.         |
| 14000016 | Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('recoverAssetsWithUriDemo');
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
    albumChangeRequest.recoverAssetsWithUri([asset.uri]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('recoverAssetsWithUri successfully');
  } catch (err) {
    console.error(`recoverAssetsWithUriDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### deleteAssets<sup>11+</sup>

deleteAssets(assets: Array&lt;PhotoAsset&gt;): void

Permanently deletes assets from the trash.

> **NOTE**
>
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.

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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('deleteAssetsPermanentlyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.TRASH);
    if (albumFetchResult === undefined) {
      console.error('albumFetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    if (fetchResult === undefined) {
      console.error('fetchResult is undefined');
      return;
    }
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

### deleteAssetsWithUri<sup>19+</sup>

deleteAssetsWithUri(assetUris: Array&lt;String&gt;): void

Permanently deletes assets from the trash.

> **NOTE**
>
> This operation is irreversible. The assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| assetUris | Array&lt;String&gt; | Yes  | Array of URIs of the assets to be permanently deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      | Called by non-system application.         |
| 13900020 | Invalid argument.| 
| 14000011 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.         |
| 14000016 | Operation Not Support.     |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('deleteAssetsWithUriDemo');
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
    albumChangeRequest.deleteAssetsWithUri([asset.uri]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to deleteAssets permanently');
  } catch (err) {
    console.error(`deleteAssetsWithUriDemo failed with error: ${err.code}, ${err.message}`);
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
| displayLevel | number | Yes   | Display level to set. The options are as follows:<br>**0**: unfavorite the portrait album.<br>**1**: set the portrait album as the first to display.<br>**2**: do not display the portrait album as the first one.<br>**3**: favorite the portrait album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

``` ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
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

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| album | [Album](#album) | Yes  | **Highlights** album.|

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('HighlightAlbum constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(
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

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise used to return the album information.|

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('getHighlightAlbumInfoDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(
      photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOptions);
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

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;ArrayBuffer&gt; | Promise used to return the ArrayBuffer.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. Possible causes: 1. The database is corrupted; 2. The file system is abnormal; 3. The IPC request timed out; 4. Permission denied.           |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('getHighlightResourceDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(
      photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOptions);
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

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    console.info('setHighlightUserActionDataDemo')
    let fetchOptions: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    }
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(
      photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.HIGHLIGHT, fetchOptions);
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

- The total length of the subtitle must be between 0 and 255 characters.

- It must not contain any invalid characters, which are:<br> . \ / : * ? " ' ` < > | { } [ ]

- The characters are case insensitive.

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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
| Promise&lt;number&gt; | Promise used to return the operation result. The value **0** means that the operation is successful, and **1** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  | **Highlights** album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

### setRelationship<sup>21+</sup>

setRelationship(relationship: string): Promise&lt;void&gt;

Sets the relationships of a person in the portrait album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| relationship | string | Yes  | Name of the relationship to set.<br>You can set it to an empty string to remove the current relationship setting.|

The supported relationship names include:

| Unique ID       | Description     |
| ---------- | ------- |
| me | Me|
| son | Son|
| daughter | Daughter|
| wife | Wife|
| husband | Husband|
| father | Father|
| mother | Mother|
| colleague | Colleague|
| friend | Friend|
| classmate | Classmate|
| best_friend_female | Best female friend|
| boyfriend | Boyfriend|
| girlfriend | Girlfriend|
| family | Family|
| maternal_grandfather | Maternal grandfather|
| maternal_grandmother | Maternal grandmother|
| paternal_grandfather | Paternal grandfather|
| paternal_grandmother | Paternal grandmother|
| older_brother | Older brother|
| older_sister | Older sister|
| younger_brother | Younger brother|
| younger_sister | Younger sister|
| relative | Relative|
| other | Other|

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The input parameter is not within the valid range.  | 
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function SetRelationshipExample(context: Context, relationship: string) {
  try {
    console.info('setRelationship');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let portraitAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    let changeRequest: photoAccessHelper.MediaAnalysisAlbumChangeRequest =
      new photoAccessHelper.MediaAnalysisAlbumChangeRequest(portraitAlbum);
    changeRequest.setRelationship(relationship);
    await helper.applyChanges(changeRequest);
    console.info(`setRelationship ${relationship}`);
  } catch (err) {
    console.error(`setRelationship error: ${err}`);
  }
}
```

### createAnalysisAlbumRequest<sup>23+</sup>

static createAnalysisAlbumRequest(context: Context, name: string, subtype: AlbumSubtype): MediaAnalysisAlbumChangeRequest

Creates a change request for the **Analysis** album.

> **NOTE**
>
> The album name must meet the following requirements:
> - The album name string length ranges from 1 to 255.
> - The album name cannot contain any of the following characters:.. \ / : * ? " ' ` < > | { } [ ]

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes  | Context of the ability instance.|
| name | string | Yes  | Name of the album.|
| subtype |  [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype) | Yes  | Subtype of the album.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [MediaAnalysisAlbumChangeRequest](#mediaanalysisalbumchangerequest18) | MediaAnalysisAlbumChangeRequest instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The input parameter is not within the valid range. | 
| 23800301   | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2.The file system is abnormal; 3. The IPC request timed out. |

**Example**

For details about how to create a photoAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('createAlbumRequestDemo');
  try {
    let albumName: string = 'newAlbumName' + new Date().getTime();
    let albumChangeRequest: photoAccessHelper.MediaAnalysisAlbumChangeRequest = photoAccessHelper.MediaAnalysisAlbumChangeRequest.createAnalysisAlbumRequest(context, albumName, photoAccessHelper.AlbumSubtype.PORTRAIT);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('apply createAlbumRequest successfully');
  } catch (err) {
    console.error(`createAlbumRequestDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### setDefaultCoverUri<sup>24+</sup>

setDefaultCoverUri(coverUri: string): void

Sets the default cover image for the smart album.

​**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type  | Mandatory| Description                                          |
| -------- | ------ | ---- | ---------------------------------------------- |
| coverUri | string | Yes  | URI of the file to be set as the default cover image of the smart album.        |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID  | Error Message|
| ---------- | ------------------------------------------------------------ |
| 202        | Called by non-system application.                            |
| 23800151   | The scenario parameter verification fails. Possible causes: 1. The input parameter is not within the valid range. |
| 23800301   | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2.The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
  console.info('setDefaultCoverUri');
  try {
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> =
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let portraitAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    albumFetchResult.close();
    // Obtain resources from the album.
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> =
      await portraitAlbum.getAssets(fetchOption);
    if (fetchResult.getCount() === 0) {
      console.error('No asset in album');
      fetchResult.close();
      return;
    }
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let coverUri: string = asset.uri;
    fetchResult.close();
    // Set the default cover.
    let changeRequest: photoAccessHelper.MediaAnalysisAlbumChangeRequest =
      new photoAccessHelper.MediaAnalysisAlbumChangeRequest(portraitAlbum);
    changeRequest.setDefaultCoverUri(coverUri);
    await helper.applyChanges(changeRequest);
    console.info('setDefaultCoverUri success');
  } catch (err) {
    console.error(`setDefaultCoverUri error: ${err}`);
  }
}
```

## MediaHighlightAlbumChangeRequest<sup>21+</sup>

Provides APIs for managing the media album change request. It inherits from [MediaAnalysisAlbumChangeRequest](#mediaanalysisalbumchangerequest18).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>21+</sup>

constructor(album: Album)

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  | **Highlights** album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 23800151 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
  console.info('MediaHighlightAlbumChangeRequest constructorDemo');
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
  let changeRequest: photoAccessHelper.MediaHighlightAlbumChangeRequest =
    new photoAccessHelper.MediaHighlightAlbumChangeRequest(highlightAlbum);
}
```

### setHighlightAttribute<sup>21+</sup>

setHighlightAttribute(attribute: HighlightAlbumChangeAttribute, value: string): void

Sets the specified attribute value in the highlights album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| attribute | [HighlightAlbumChangeAttribute](#highlightalbumchangeattribute21) | Yes  | Attribute to set.|
| value       | string   | Yes   | Value to set for the attribute.<br>When **attribute** is **IS\_VIEWED** or **IS\_FAVORITE**, the value is **0** or **1**. When **attribute** is **NOTIFICATION\_TIME**, the value is a numeric string of a maximum of 8 bytes, for example, **12345678**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
  try {
    console.info('setHighlightAttribute');
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
    let highlightAlbumChangeAttribute: photoAccessHelper.HighlightAlbumChangeAttribute =
      photoAccessHelper.HighlightAlbumChangeAttribute.IS_VIEWED;
    let value: string = "1";
    let changeRequest: photoAccessHelper.MediaHighlightAlbumChangeRequest =
      new photoAccessHelper.MediaHighlightAlbumChangeRequest(highlightAlbum);
    changeRequest.setHighlightAttribute(highlightAlbumChangeAttribute, value);
    await helper.applyChanges(changeRequest);
    console.info(`setHighlightAttribute end`);
  } catch (err) {
    console.error(`setHighlightAttribute error: ${err}`);
  }
}
```

## AnalysisAlbum<sup>18+</sup>

Implements an **Analysis** album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

### constructor<sup>18+</sup>

constructor(album: Album)

Constructor.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| album | [Album](#album) | Yes  | **Highlights** album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.   |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

### getRelationship<sup>21+</sup>

getRelationship(): Promise&lt;string&gt;

Obtains the relationships of a person in the portrait album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ\_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                               |
| :------------------ | :---------------------------------- |
| Promise&lt;string&gt;| Relationships of the person in the portrait album.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function GetRelationshipExample(context: Context) {
  try {
    console.info('getRelationship');
    let helper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    let albumFetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: new dataSharePredicates.DataSharePredicates()
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = 
      await helper.getAlbums(photoAccessHelper.AlbumType.SMART, photoAccessHelper.AlbumSubtype.PORTRAIT, albumFetchOption);
    if (albumFetchResult.getCount() === 0) {
      console.error('No album');
      return;
    }
    let portraitAlbum: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let analysisAlbum = new photoAccessHelper.AnalysisAlbum(portraitAlbum);
    let relationship: string | undefined = await analysisAlbum?.getRelationship();
    console.info(`getRelationship ${relationship}`);
  } catch (err) {
    console.error(`getRelationship error: ${err}`);
  }
}
```

## CloudEnhancement<sup>13+</sup>

Provides APIs for cloud enhancement management, including managing the tasks of generating AI-powered cloud-enhanced photos and obtaining the association between the original photos and AI cloud-enhanced photos.

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

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| [CloudEnhancement](#cloudenhancement13) | A cloud enhancement instance.|

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

async function example(context: Context) {
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

Submits cloud enhancement tasks. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | [PhotoAsset](#photoasset) to enhance.|
| hasCloudWatermark | boolean | Yes  | Whether to add a cloud enhancement watermark to the enhanced images.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

Submits cloud enhancement tasks. You can select the trigger mode of the cloud enhancement task. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | [PhotoAsset](#photoasset) to enhance.|
| hasCloudWatermark | boolean | Yes  | Whether to add a cloud watermark to the enhanced image. **true** to add, **false** otherwise.|
| triggerMode | number | No  | Trigger mode of the cloud enhancement task.<br>**- 0**: manually triggered.<br>**- 1**: automatically triggered.<br>The default value is **0**.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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
| photoAssets | Array<[PhotoAsset](#photoasset)> | Yes  | Array of [PhotoAsset](#photoasset) objects whose cloud enhancement tasks are to be canceled.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

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

async function example(context: Context) {
  console.info('cancelAllCloudEnhancementTasksDemo');
  try {
    let cloudEnhancementInstance: photoAccessHelper.CloudEnhancement
      = photoAccessHelper.CloudEnhancement.getCloudEnhancementInstance(context);
    await cloudEnhancementInstance.cancelAllCloudEnhancementTasks();
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

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise<[CloudEnhancementTaskState](#cloudenhancementtaskstate13)> | Promise used to return the information about the cloud enhancement task.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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
      console.info("task has exception");
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_PREPARING) {
      console.info("task is preparing");
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_UPLOADING) {
      let transferredFileSize = cloudEnhancementTaskState.transferredFileSize;
      let totalFileSize = cloudEnhancementTaskState.totalFileSize;
      let message = `task is uploading, transferredFileSize: ${transferredFileSize}, totalFileSize: ${totalFileSize}`;
      console.info(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_EXECUTING) {
      let expectedDuration = cloudEnhancementTaskState.expectedDuration;
      let message = `task is executing, expectedDuration: ${expectedDuration}`;
      console.info(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING) {
      let transferredFileSize = cloudEnhancementTaskState.transferredFileSize;
      let totalFileSize = cloudEnhancementTaskState.totalFileSize;
      let message = `task is downloading, transferredFileSize: ${transferredFileSize}, totalFileSize: ${totalFileSize}`;
      console.info(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_FAILED) {
      let errCode = cloudEnhancementTaskState.statusCode;
      let message = `task is failed, errCode: ${errCode}`;
      console.info(message);
    } else if (taskStage == photoAccessHelper.CloudEnhancementTaskStage.TASK_STAGE_COMPLETED) {
      console.info("task is completed");
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

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

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

async function example(context: Context) {
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
| photoAsset | [PhotoAsset](#photoasset) | Yes  | [PhotoAsset](#photoasset) for which the cloud-enhanced photo is to be obtained.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise<[PhotoAsset](#photoasset)> | Promise used to return the photo after cloud enhancement.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(context: Context) {
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

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [File Management Error Codes](../apis-core-file-kit/errorcode-filemanagement.md).

| ID   | Error Message                             |
| :------- | :-------------------------------- |
| 202      | Called by non-system application. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011 | Internal system error.            |
| 14000016 | Operation Not Support.            |

**Example**

For details about how to create a phAccessHelper instance, see the example provided in [photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper).

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, asset: photoAccessHelper.PhotoAsset) {
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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.          |

**Example**

```ts
async function example(context: Context) {
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

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.           |

**Example**

```ts
async function example(context: Context) {
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

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
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

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
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

**Required permissions**: ohos.permission.CLOUDFILE_SYNC_MANAGER

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
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

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

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
| 14000011 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('getCloudMediaAssetStatusDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    const cloudMediaAssetStatus: photoAccessHelper.CloudMediaAssetStatus = await cloudMediaAssetManagerInstance.getCloudMediaAssetStatus();
    let taskStatus = cloudMediaAssetStatus.taskStatus;
    let taskInfo = cloudMediaAssetStatus.taskInfo;
    let errorCode = cloudMediaAssetStatus.errorCode;
    let message = `taskStatus: ${taskStatus}, taskInfo: ${taskInfo}, errorCode: ${errorCode}`;
    console.info(message);
  } catch (err) {
    console.error(`getCloudMediaAssetStatusDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

### startDownloadSpecificCloudMedia<sup>21+</sup>

startDownloadSpecificCloudMedia(assetUris: string[]): Promise\<Map\<string, CloudAssetDownloadCode\>\>

Starts a batch download for the specified cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.CLOUDFILE_SYNC_MANAGER

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assetUris | string[] | Yes  | Array of URIs pointing to the original-quality images and videos to be downloaded.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<Map\<string, [CloudAssetDownloadCode](#cloudassetdownloadcode21)\>\> | Promise used to return a map, where each key is a URI and its value indicates the status of that individual download item.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: 1. The assetUris array is empty; 2. The assetUris array size is bigger than 500.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('StartDownloadSpecificCloudMediaDemo');
  try {
    let assetURIs: Array<string> = [
       'file://media/Photo/12/IMG_1755046662_091/IMG_20250801_175331.jpg'];
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    let taskRespMap : Map<string, photoAccessHelper.CloudAssetDownloadCode> =
      await cloudMediaAssetManagerInstance.startDownloadSpecificCloudMedia(assetURIs);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### pauseDownloadSpecificCloudMedia<sup>21+</sup>

pauseDownloadSpecificCloudMedia(assetUris: string[] | null): Promise\<void\>

Pauses a batch download for the specified cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.CLOUDFILE_SYNC_MANAGER

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assetUris | string[]  \| null | Yes  | Array of URIs pointing to the original-quality images and videos to be paused.<br>If null, undefined, or an empty list is passed, it represents all existing individual download items.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes: The assetUris array size is bigger than 500.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('PauseDownloadSpecificCloudMediaDemo');
  try {
    let assetURIs: Array<string> = [
       'file://media/Photo/12/IMG_1755046662_091/IMG_20250801_175331.jpg'];
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.pauseDownloadSpecificCloudMedia(assetURIs);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### resumeDownloadSpecificCloudMedia<sup>21+</sup>

resumeDownloadSpecificCloudMedia(assetUris: string[] | null): Promise\<void\>

Resumes a batch download for the specified cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.CLOUDFILE_SYNC_MANAGER

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assetUris | string[]  \| null | Yes  | Array of URIs pointing to the original-quality images and videos to be resumed.<br>If null, undefined, or an empty list is passed, it represents all existing individual download items.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:  The assetUris array size is bigger than 500.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('ResumeDownloadSpecificCloudMediaDemo');
  try {
    let assetURIs: Array<string> = [
       'file://media/Photo/12/IMG_1755046662_091/IMG_20250801_175331.jpg'];
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.resumeDownloadSpecificCloudMedia(assetURIs);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### cancelDownloadSpecificCloudMedia<sup>21+</sup>

cancelDownloadSpecificCloudMedia(assetUris: string[] | null): Promise\<void\>

Cancels a batch download for the specified cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO and ohos.permission.CLOUDFILE_SYNC_MANAGER

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assetUris | string[]  \| null | Yes  | Array of URIs pointing to the original-quality images and videos to be canceled.<br>If null, undefined, or an empty list is passed, it represents all existing individual download items.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<void\> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:  The assetUris array size is bigger than 500.|
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('CancelDownloadSpecificCloudMediaDemo');
  try {
    let assetURIs: Array<string> = [
       'file://media/Photo/12/IMG_1755046662_091/IMG_20250801_175331.jpg'];
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    await cloudMediaAssetManagerInstance.cancelDownloadSpecificCloudMedia(assetURIs);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### queryDownloadSpecificCloudMediaDetails<sup>21+</sup>

queryDownloadSpecificCloudMediaDetails(predicates: dataSharePredicates.DataSharePredicates): Promise\<CloudAssetDownloadStatus\>

Obtains the details of a batch download for cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| predicates | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Predicates that specify the fetch criteria.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<[CloudAssetDownloadStatus](#cloudassetdownloadstatus21)\> | Promise used to return the details obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData'

async function example(context: Context) {
  console.info('QueryDownloadSpecificCloudMediaDetailsDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc("file_id");
    let taskListStatus : photoAccessHelper.CloudAssetDownloadStatus =
       await cloudMediaAssetManagerInstance.queryDownloadSpecificCloudMediaDetails(predicates);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### queryDownloadSpecificCloudMediaTaskCount<sup>21+</sup>

queryDownloadSpecificCloudMediaTaskCount(predicates: dataSharePredicates.DataSharePredicates): Promise\<number\>

Obtains the number of batch download tasks for cloud media assets. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| predicates | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Predicates that specify the fetch criteria.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise\<number\> | Promise used to return the number of batch download tasks.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData'

async function example(context: Context) {
  console.info('QueryDownloadSpecificCloudMediaTaskCountDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc("file_id");
    let count : number =
       await cloudMediaAssetManagerInstance.queryDownloadSpecificCloudMediaTaskCount(predicates);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### onDownloadProgressChange<sup>21+</sup>

onDownloadProgressChange(callback: Callback\<CloudAssetDownloadProgressInfo\>): void

Registers a callback to monitor changes in the progress of a batch download for cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | Callback\<[CloudAssetDownloadProgressInfo](#cloudassetdownloadprogressinfo21)\> | Yes  | Callback to register. The callback returns progress information of the batch download.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
let onCallback = (changeData: photoAccessHelper.CloudAssetDownloadProgressInfo) => {
  console.info('batchdownload downloadProgressChange onCallback success, changData: ' + JSON.stringify(changeData));
}
async function example(context: Context) {
  console.info('OnDownloadProgressChangeDemo');
  try {
      let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
        = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
      // Register onCallback.
      cloudMediaAssetManagerInstance.onDownloadProgressChange(onCallback);
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

### offDownloadProgressChange<sup>21+</sup>

offDownloadProgressChange(callback?: Callback\<CloudAssetDownloadProgressInfo\>): void

Unregisters a callback to monitor changes in the progress of a batch download for cloud media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | Callback\<[CloudAssetDownloadProgressInfo](#cloudassetdownloadprogressinfo21)\> | No  | Callback to unregister, which is registered by [onDownloadProgressChange](#ondownloadprogresschange21). If this parameter is left empty, all progress-related callbacks are unregistered.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied.                |
| 202      | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out.            |

**Example**

```ts
async function example(context: Context) {
  console.info('OffDownloadProgressChangeDemo');
  try {
    let cloudMediaAssetManagerInstance: photoAccessHelper.CloudMediaAssetManager
      = photoAccessHelper.CloudMediaAssetManager.getCloudMediaAssetManagerInstance(context);
    cloudMediaAssetManagerInstance.offDownloadProgressChange();
  } catch (err) {
    console.error(`failed with error: ${err.code}, ${err.message}`);
  }
}
```

## MovingPhoto<sup>12+</sup>

Provides APIs for managing a moving photo instance.

### isVideoReady<sup>20+</sup>

isVideoReady(): Promise&lt;boolean&gt;

Checks whether the video of the moving photo is ready. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. **true** if the video of the moving photo is ready, **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      | Permission denied |
| 202      | Called by non-system application |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

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
    try {
    let isVideoReady = await movingPhoto.isVideoReady()
      console.info("moving photo video ready:" + `${isVideoReady}`);
    } catch (err) {
      console.error(`failed to get isVideoReady, error code is ${err.code}, message is ${err.message}`)
    }
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

## PhotoAssetCustomRecordManager<sup>20+</sup>

Provides APIs for custom user behavior recording for Gallery.

**System API**: This is a system API.

### getCustomRecordManagerInstance<sup>20+</sup>

static getCustomRecordManagerInstance(context: Context): PhotoAssetCustomRecordManager

Obtains an instance of custom user behavior recording for Gallery.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-context.md#context) | Yes| Context of the ability instance.|

**Return value**

| Type| Description|
| --- | --- |
| [PhotoAssetCustomRecordManager](#photoassetcustomrecordmanager20) | Custom user behavior recording instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800107 | Context is invalid. |

**Example**

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('getCustomRecordManagerInstance');
  try {
    let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  } catch(err) {
    console.error(`getCustomRecordManagerInstance failed with error: ${err.code}, ${err.message}`);
  }
}
```

### createCustomRecords<sup>20+</sup>

createCustomRecords(customRecords: Array&lt;PhotoAssetCustomRecord&gt;): Promise&lt;void&gt;

Adds custom user behavior recordings. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| customRecords | Array&lt;[PhotoAssetCustomRecord](#photoassetcustomrecord20)&gt; | Yes| Custom user behavior recordings.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The value range of mandatory parameters in photoAssetCustomRecord does not meet the requirements. 2. The transferred record already exists. 3. The number of transferred records exceeds 200. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('createCustomRecords');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let crArray:Array<photoAccessHelper.PhotoAssetCustomRecord> = [
    {fileId:1,shareCount:1,lcdJumpCount:1}
  ];
  crManager.createCustomRecords(crArray).then(() => {
    console.info('createCustomRecords successful');
  }).catch((err: BusinessError) => {
    console.error(`createCustomRecords fail with error: ${err.code}, ${err.message}`);
  });
}
```

### getCustomRecords<sup>20+</sup>

getCustomRecords(optionCheck: FetchOptions): Promise&lt;FetchResult&lt;PhotoAssetCustomRecord&gt;&gt;

Obtains custom user behavior recordings based on retrieval options. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| optionCheck | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes| Retrieval options.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;FetchResult&lt;[PhotoAssetCustomRecord](#photoassetcustomrecord20)&gt;&gt; | Promise used to return the collection of custom user behavior recordings.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The filter criteria or fetchColumns that are not supported by options are transferred. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('getCustomRecords');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('file_id', 1);
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  crManager.getCustomRecords(fetchOption).then(async (fetchResult) => {
    let record = await fetchResult.getFirstObject();
    console.info('record file id is ' + record.fileId);
  }).catch((err: BusinessError) => {
    console.error('getCustomRecords fail with error: ${err.code}, ${err.message}');
  });
}
```

### setCustomRecords<sup>20+</sup>

setCustomRecords(customRecords: Array&lt;PhotoAssetCustomRecord&gt;): Promise&lt;Array&lt;number&gt;&gt;

Updates the existing database fields based on custom user behavior recordings. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| customRecords | Array&lt;[PhotoAssetCustomRecord](#photoassetcustomrecord20)&gt; | Yes| Custom user behavior recordings.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the file ID in the custom user behavior recordings that fail to be updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The value range of mandatory parameters in photoAssetCustomRecord does not meet the requirements. 2. The number of transferred records exceeds 200. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('setCustomRecords');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let UpdateArray: Array<photoAccessHelper.PhotoAssetCustomRecord> = [
    {fileId:1,shareCount:2,lcdJumpCount:3},
    {fileId:2,shareCount:2,lcdJumpCount:3}
  ];
  crManager.setCustomRecords(UpdateArray).then((failIds) => {
    console.info('setCustomRecords successful');
  }).catch((err: BusinessError) => {
    console.error('setCustomRecords file with err: ${err.code}, ${err.message}');
  });
}
```

### removeCustomRecords<sup>20+</sup>

removeCustomRecords(optionCheck: FetchOptions): Promise&lt;void&gt;

Removes custom user behavior recordings based on retrieval options. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| optionCheck | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | Yes| Retrieval options.|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The filter criteria or fetchColumns that are not supported by options are transferred |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('removeCustomRecords');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('file_id', 1);
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  crManager.removeCustomRecords(fetchOption).then(() => {
    console.info('removeCustomRecords successful');
  }).catch((err: BusinessError) => {
    console.error(`removeCustomRecords fail with error: ${err.code}, ${err.message}`);
  });
}
```

### addShareCount<sup>20+</sup>

addShareCount(ids: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Increases the value of **shareCount** by 1 for the data in the database based on **fileId** in [PhotoAssetCustomRecord](#photoassetcustomrecord20). This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| ids | Array&lt;number&gt; | Yes| Array of file IDs in [PhotoAssetCustomRecord](#photoassetcustomrecord20).|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the file ID in the custom user behavior recordings that fail to be updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The ids list is empty; 2. The number of ids lists exceeds 500. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('addShareCount');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let ids: Array<number> = [1, 2];
  crManager.addShareCount(ids).then((failIds) => {
    console.info('addShareCount successful');
  }).catch((err: BusinessError) => {
    console.error('addShareCount fail with error: ${err.code}, ${err.message}');
  });
}
```

### addLcdJumpCount<sup>20+</sup>

addLcdJumpCount(ids: Array&lt;number&gt;): Promise&lt;Array&lt;number&gt;&gt;

Increases the value of **LcdJumpCount** by 1 for the data in the database based on **fileId** in [PhotoAssetCustomRecord](#photoassetcustomrecord20). This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| --- | --- | --- | --- |
| ids | Array&lt;number&gt; | Yes| Array of file IDs in [PhotoAssetCustomRecord](#photoassetcustomrecord20).|

**Return value**

| Type| Description|
| --- | --- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the file ID in the custom user behavior recordings that fail to be updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| --- | --- |
| 202 | Called by non-system application. |
| 23800151 | Scenario parameters fail to pass the verification. Possible causes: 1. The ids list is empty; 2. The number of ids lists exceeds 500. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(context: Context) {
  console.info('addLcdJumpCount');
  let crManager = photoAccessHelper.PhotoAssetCustomRecordManager.getCustomRecordManagerInstance(context);
  let ids: Array<number> = [1, 2];
  crManager.addLcdJumpCount(ids).then((failIds) => {
    console.info('addLcdJumpCount successful');
  }).catch((err: BusinessError) => {
    console.error('addLcdJumpCount fail with error: ${err.code}, ${err.message}');
  });
}
```

## PhotoSelectOptions

Defines additional options for selecting media assets from Gallery. It inherits from **BaseSelectOptions**. It is used to start the picker of the corresponding user ID space.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| userId<sup>18+</sup> | number  | No  | ID of the user space to access. The default value is **-1**.<br>To use it as a parameter of [PhotoViewPicker.select](arkts-apis-photoAccessHelper-PhotoViewPicker.md#select), request the permission **ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS**.<br>**System API**: This is a system API.|

**Example**

```ts
  async function photoPicker() {
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
| SLOW_MOTION_VIDEO<sup>22+</sup> |  6 |  Slow-motion video file.<br>**System API**: This is a system API.|
| SPATIAL_3DGS<sup>22+</sup> |  7 |  Video file using the 3D Gaussian Splatting (3DGS) rendering format.<br>**System API**: This is a system API.|

## NotifyChangeType<sup>20+</sup>

Enumerates the types of changes that trigger the media asset or album change events.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_CHANGE_YUV_READY<sup>23+</sup>         | 3    | A high-quality image is ready in deferred photo delivery scenarios.<br>Image quality metrics such as sharpness and color accuracy can be checked in the [OnDataPrepared](arkts-apis-photoAccessHelper-QuickImageDataHandler.md#ondataprepared13) callback.<br>**System API**: This is a system API.|
| NOTIFY_CHANGE_ADD_ANALYSIS<sup>23+</sup>    | 4 | A media asset (image or video) is created in the smart analysis album.<br>**System API**: This is a system API.|
| NOTIFY_CHANGE_REMOVE_ANALYSIS<sup>23+</sup> | 5 | A media asset (image or video) is deleted from the smart analysis album.<br>**System API**: This is a system API.|

## AlbumType

Enumerates the album types,

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                 | Value   | Description                       |
| ------------------- | ---- | ------------------------- |
| SMART<sup>11+</sup> | 4096 | Smart analysis album.<br>**System API**: This is a system API.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                               | Value         | Description                             |
| --------------------------------- | ---------- | ------------------------------- |
| HIDDEN                            | 1027       | Hidden album. **System API**: This is a system API.        |
| TRASH                             | 1028       | Trash. **System API**: This is a system API.         |
| SCREENSHOT                        | 1029       | Album for screenshots and screen recording files. **System API**: This is a system API.     |
| CAMERA                            | 1030       | Album for images and videos taken by the camera. **System API**: This is a system API.|
| CLASSIFY<sup>11+</sup>            | 4097       | Classified album. **System API**: This is a system API.        |
| GEOGRAPHY\_LOCATION<sup>11+</sup> | 4099       | Geographic location album. **System API**: This is a system API.        |
| GEOGRAPHY\_CITY<sup>11+</sup>     | 4100       | City album. **System API**: This is a system API.        |
| SHOOTING\_MODE<sup>11+</sup>      | 4101       | Shooting mode album. **System API**: This is a system API.      |
| PORTRAIT<sup>11+</sup>            | 4102       | Portrait album. **System API**: This is a system API.        |
| GROUP_PHOTO<sup>13+</sup>         | 4103       | Group photo album. **System API**: This is a system API.        |
| HIGHLIGHT<sup>12+</sup>           | 4104       | Highlights album. **System API**: This is a system API.        |
| HIGHLIGHT_SUGGESTIONS<sup>12+</sup> | 4105     | Highlights suggestion album. **System API**: This is a system API.        |
| CLOUD_ENHANCEMENT<sup>13+</sup> | 1032     | AI-powered cloud enhanced album. **System API**: This is a system API.        |

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
| DATE_TRASHED  | 'date_trashed'  | Date when the file was deleted. The value is the number of seconds elapsed since the Epoch time. **System API**: This is a system API.                |
| HIDDEN  | 'hidden'            | Whether the file is hidden. **System API**: This is a system API.                              |
| CAMERA_SHOT_KEY  | 'camera_shot_key'  | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.) **System API**: This is a system API.           |
| USER_COMMENT  | 'user_comment'            | User comment information. **System API**: This is a system API.          |
| DATE_YEAR<sup>11+</sup>  | 'date_year'            | Year when the file was created. **System API**: This is a system API.          |
| DATE_MONTH<sup>11+</sup>  | 'date_month'            | Month when the file was created. **System API**: This is a system API.          |
| DATE_DAY<sup>11+</sup>  | 'date_day'            | Date when the file was created. **System API**: This is a system API.          |
| PENDING<sup>11+</sup>  | 'pending'            | Pending state. **System API**: This is a system API.          |
| DATE_TRASHED_MS<sup>12+</sup>  | 'date_trashed_ms'  | Date when the file was deleted. The value is the number of milliseconds elapsed since the Epoch time. **System API**: This is a system API.<br>**NOTE**: The photos queried cannot be sorted based on this field.|
| MOVING_PHOTO_EFFECT_MODE<sup>12+</sup>  | 'moving_photo_effect_mode' | Effect of the moving photo. **System API**: This is a system API.|
| CE_AVAILABLE<sup>13+</sup>  | 'ce_available' | Cloud enhancement identifier. **System API**: This is a system API.|
| THUMBNAIL_READY<sup>13+</sup>  | 'thumbnail_ready' | Whether a thumbnail is generated. **System API**: This is a system API.|
| THUMBNAIL_VISIBLE<sup>14+</sup>  | 'thumbnail_visible' | Whether a thumbnail is visible. **System API**: This is a system API.|
| SUPPORTED_WATERMARK_TYPE<sup>14+</sup>  | 'supported_watermark_type' | Watermark type to set. **System API**: This is a system API.|
| IS_CE_AUTO<sup>18+</sup>  | 'is_auto' | Whether automatic cloud enhancement is supported. **System API**: This is a system API.|
| IS_RECENT_SHOW<sup>18+</sup>  | 'is_recent_show' | Whether the asset is displayed in the **Recent** list. **System API**: This is a system API.|
| SUM_SIZE<sup>19+</sup>  | 'sum(size)' | Total size of files. When **SUM_SIZE** is filled in **fetchColumns**, only the first asset is obtained, and the property includes the total size of all assets. **System API**: This is a system API.|
| EXIF_ROTATE<sup>21+</sup>  | 'exif_rotate' | Rotational angle of the file. **System API**: This is a system API.|
| HAS_APPLINK<sup>21+</sup>  | 'has_applink' | Whether to enable or disable the app link association. **System API**: This is a system API.|
| APPLINK<sup>21+</sup>  | 'applink' | Information about the app link association. **System API**: This is a system API.|
| HDR_MODE<sup>22+</sup>  | 'hdr_mode' | HDR mode of the file. **System API**: This is a system API.|
| EXIST_COMPATIBLE_DUPLICATE<sup>22+</sup>  | 'exist_compatible_duplicate' | Whether a JPEG-compatible copy exists. **System API**: This is a system API.|
| CLOUD_ID<sup>22+</sup>  | 'cloud_id' | Unique ID of the file on the cloud. **System API**: This is a system API.|
| COMPOSITE_DISPLAY_STATUS<sup>22+</sup> | 'composite_display_status' | Display status of the composite image asset. **System API**: This is a system API.|
| VIDEO_MODE<sup>22+</sup>  | 'video_mode' | Log mode of a video file. **System API**: This is a system API.|
| EDIT_DATA_EXIST<sup>22+</sup>  | 'edit_data_exist' | Edit data for the asset already exists. **System API**: This is a system API.|
| DATE_ADDED_YEAR<sup>24+</sup>  | 'date_added_year' | Year when an asset is added.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| DATE_ADDED_MONTH<sup>24+</sup> | 'date_added_month'| Month when an asset is added.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| DATE_ADDED_DAY<sup>24+</sup>   | 'date_added_day'  | Date when an asset is added.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| PACKAGE_NAME<sup>23+</sup> | 'package_name' | Package name of a file.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| PHOTO_RISK_STATUS<sup>23+</sup> | 'photo_risk_status' | Image risk control<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| THUMB_STATUS | 'thumb_status' | Thumbnail status.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| LCD_FILE_SIZE | 'lcd_file_size' | Size of the LCD image.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| HIDDEN_TIME | 'hidden_time'  | Time when the file was hidden. The value is the number of milliseconds elapsed since the epoch time (00:00:00 UTC on January 1, 1970).<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| FILE_HIDDEN | 'file_hidden' | Whether the file is hidden.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| ATTACHMENT_SIZE | 'attachment_size' | Size of the attachment file. The unit is bytes.<br>The default value is **0**, indicating that the attachment file size is not identified or the attachment file size is 0.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## AlbumKeys

Enumerates the album keys.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                             | Value                   | Description                                                      |
| --------------------------------- | -------------------- | ----------------------------------------------------- |
| BUNDLE_NAME<sup>18+</sup>          | 'bundle_name'                 | Bundle name of the album.<br>**System API**: This is a system API.           |
| DATE_MODIFIED<sup>18+</sup>        | 'date_modified'         | Timestamp when the album was modified, in milliseconds.<br>**System API**: This is a system API.           |
| COVER_URI_SOURCE<sup>20+</sup>     | 'cover_uri_source'      | Source URI of the album cover.<br>**System API**: This is a system API.           |
| UPLOAD_STATUS<sup>22+</sup>     | 'upload_status'      | Synchronization status of the album.<br>**System API**: This is a system API.           |
| HIDDEN<sup>23+</sup>     | 'hidden'      | Hidden status.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.           |
| FILE_HIDDEN     | 'file_hidden'      | Hidden status of a folder in the file management.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.           |

## AlbumAttribute

Enumerates the attribute types of albums.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Value| Description|
| --- | --- | --- |
| NICK_NAME_ATTR | 'nickname' | Nickname of the album.<br>**System API**: This is a system API.|
| EXTRA_INFO_ATTR | 'extra_info' | Extended information operation attribute of the album.<br>**System API**: This is a system API.|
| IS_REMOVED_ATTR | 'is_removed' | Whether the album has been removed.<br>- Currently, portrait albums are supported.<br>- **1**: The album has been removed.<br>- **0**: The album has not been removed or has been restored.<br>**System API**: This is a system API.|

## AlbumOperationType

Enumerates the operation types for setting album attributes.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Value| Description|
| --- | --- | --- |
| ADD | 'add' | Adding an album attribute.<br>**System API**: This is a system API.|
| REMOVE | 'remove' | Removing an album attribute.<br>**System API**: This is a system API.|
| UPDATE | 'update' | Updating an album attribute.<br>**System API**: This is a system API.|

## AlbumOperation

Describes the album operation information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| --- | --- | --- | --- | --- |
| attr | [AlbumAttribute](#albumattribute) | No| No| Album attribute type.<br>**System API**: This is a system API.|
| type | [AlbumOperationType](#albumoperationtype) | No| No| Operation type for setting album attributes.<br>**System API**: This is a system API.|
| values | string[] | No| No| String parameter for setting album attributes. The maximum length of the array is 20. Each string in the array can contain up to 500 characters.<br>**System API**: This is a system API.|

## AlbumAttributeInfo

Defines the album attribute information.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| --- | --- | --- | --- | --- |
| attrValue | string | No| Yes| Album attribute value.<br>**System API**: This is a system API.|

## HiddenPhotosDisplayMode<sup>11+</sup>

Enumerates the display modes of hidden files in the system.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| ASSETS_MODE   | 0       | Display all hidden files in the system.   |
| ALBUMS_MODE    | 1    | Display hidden files by album (display all albums that contain hidden files in the system, excluding the preset hidden album and the albums in the trash). |

## PhotoCreateOptions

Defines the options for creating an image or video asset.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---------------------- | ---- | ------------------------------------------------ |
| subtype           | [PhotoSubtype](#photosubtype) | No| Yes| Subtype of the image or video. |
| cameraShotKey           | string | No| Yes| Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.)  |
| userId<sup>19+</sup>           | number | No| Yes| User ID. |

## RequestPhotoOptions<sup>11+</sup>

Defines the options for obtaining the thumbnail of an image or video.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---------------------- | ---- | ------------------------------------------------ |
| size           | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | No| Yes| Size of the thumbnail to obtain. |
| requestPhotoType    | [RequestPhotoType](#requestphototype11) | No| Yes| Operation to perform. |

## PhotoCreationSource<sup>18+</sup>

Defines the application information provided to create assets on behalf of the application.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---- | ---- | ------------------------------------------------ |
| bundleName           | string | No | Yes |Bundle name of the target application. |
| appName    | string | No | Yes |Name of the target application. |
| appId    | string | No | Yes |ID of the target application. |
| tokenId    | number | No | Yes |Token ID of the target application. |

## RequestOptions<sup>11+</sup>

Represents request options.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type                             | Read-Only| Optional| Description                                             |
| ---------------------- |---------------------------------| ---- |---- | ------------------------------------------------ |
| sourceMode           | [SourceMode](#sourcemode11)     | No | Yes  | Type of the asset file requested, which can be the original file or edited file.<br>**System API**: This is a system API.|

## Progress

Describes the progress of the clone operation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| processed | number | Yes| No| Number of items that have been processed in the clone operation.|
| remain | number | Yes| No| Number of items that still need to be processed in the clone operation.|

## ResultInfo

Describes the result of the clone operation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| code | number | Yes| No| Result code of the clone operation. If an exception occurs, the error code 23800151 or 23800301 is returned.|
| result | Array&lt;string \| null&gt; | Yes| No| Result of the clone operation.|

## ProgressListener

type ProgressListener = (progress: Progress) => void

Defines the type of the listener for the clone operation progress.

The progress callback can report copy progress by size and by file count.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| progress | [Progress](#progress) | Yes| Progress information of the clone operation.|

## ResultListener

type ResultListener = (result: ResultInfo) => void

Defines the type of the listener for the clone operation result.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ---- | ---- | ---- | ---- |
| result | [ResultInfo](#resultinfo) | Yes| Result of the clone operation.|

## TaskSignal

Defines the signal used to interrupt the clone operation.

**Since**: 26.0.0

### cancel

cancel(): void

Cancels the clone operation.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 202 | Called by non-system application. |
| 23800151 | The scenario parameter verification fails. Possible causes:<br>1. No task can be canceled. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

let taskSignal = new photoAccessHelper.TaskSignal();

try {
  taskSignal.cancel();
  console.info('cancel batch operation success');
} catch (err) {
  console.error(`cancel batch operation failed with error: ${err.code}, ${err.message}`);
}
```

## BatchOperationOptions

Defines the batch clone operation options.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| ---- | ---- | ---- | ---- | ---- |
| sizeProgressListener | [ProgressListener](#progresslistener) | No| Yes| Listener for the size progress of the clone operation.|
| countProgressListener | [ProgressListener](#progresslistener) | No| Yes| Listener for the quantity progress of the clone operation.|
| taskSignal | [TaskSignal](#tasksignal) | No| Yes| Interruption signal of the clone operation.|
| resultListener | [ResultListener](#resultlistener) | No| Yes| Listener for the result of the clone operation.|
| mode | number | No| Yes| Automatic renaming mode for the clone operation.|

## PhotoProxy<sup>11+</sup>

Photo proxy object, which is used by the camera application to write image data.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## MediaChangeRequest<sup>11+</sup>

Media change request, which is the parent class of the asset change request and album change request.

> **NOTE**
>
> The media change request takes effect only after [applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11) is called.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

## FormInfo<sup>11+</sup>

Defines the Gallery widget information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---------------------- | ---- | ------------------------------------------------ |
|formId       |string  | No|No| Widget ID, which is provided when a widget is created in Gallery.|
|uri          |string  | No|No| URI of the image bound to the widget. When a widget is created, **uri** can be empty or the URI of an image. When a widget is removed, **uri** is not verified and can be empty. |

## GalleryFormInfo<sup>18+</sup>

Defines the Gallery widget information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description                                             |
| ---------------------- | ------------------- | ---------------------- | ---- | ------------------------------------------------ |
|formId             |string               | No|No| Widget ID, which is provided when a widget is created in Gallery.|
|assetUris          |Array&lt;string&gt;  | No|Yes| URIs of the images or albums bound to the widget.<br>This parameter cannot be empty when creating or updating a widget.<br>If you attempt to create or update a widget with more than 500 URIs in **assetUris**, only the first 500 URIs are registered for listening. Any URIs beyond the first 500 are not registered. <br>When deleting a widget, this parameter can be omitted. |

## ResourceType<sup>11+</sup>

Enumerates the types of the resources to write.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| PHOTO_PROXY |  3 |  Photo proxy. **System API**: This is a system API.|
| PRIVATE_MOVING_PHOTO_RESOURCE<sup>13+</sup> |  4 |  Private moving photo. **System API**: This is a system API.|
| PRIVATE_MOVING_PHOTO_METADATA<sup>18+</sup> |  5 |  Metadata resource of the private moving photo. **System API**: This is a system API.|

## DefaultChangeUri

Enumerates the **DefaultChangeUri** subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name             | Value                     | Description                                                        |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_HIDDEN_ALBUM_URI<sup>11+</sup>  | 'file://media/HiddenAlbum' | URI of an album in the hidden albums that are displayed by album, that is, the URI of an album with hidden files. Such albums do not include the preset hidden album and the albums in the trash. This URI is used to subscribe to the change notifications of the hidden albums displayed by album. **System API**: This is a system API.|

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
| ANALYSIS\_AESTHETICS\_SCORE   | 0  | Aesthetics score. **System API**: This is a system API.   |
| ANALYSIS\_LABEL               | 1  | Label. **System API**: This is a system API.   |
| ANALYSIS\_OCR                 | 2  | Optical character recognition (OCR) analysis. **System API**: This is a system API.   |
| ANALYSIS\_FACE                | 3  | Facial detection analysis. **System API**: This is a system API.   |
| ANALYSIS\_OBJECT              | 4  | Object detection analysis. **System API**: This is a system API.   |
| ANALYSIS\_RECOMMENDATION      | 5  | Recommendation analysis. **System API**: This is a system API.   |
| ANALYSIS\_SEGMENTATION        | 6  | Segmentation analysis. **System API**: This is a system API.   |
| ANALYSIS\_COMPOSITION         | 7  | Aesthetic composition analysis. **System API**: This is a system API.  |
| ANALYSIS\_SALIENCY            | 8  | Salience analysis. **System API**: This is a system API.  |
| ANALYSIS\_DETAIL\_ADDRESS     | 9  | Detailed address analysis. **System API**: This is a system API.   |
| ANALYSIS\_HUMAN\_FACE\_TAG<sup>12+</sup>    | 10 | Face clustering analysis. **System API**: This is a system API.   |
| ANALYSIS\_HEAD\_POSITION<sup>12+</sup>      | 11 | Analysis of the position of a person's or pet's head. **System API**: This is a system API.   |
| ANALYSIS\_BONE\_POSE<sup>12+</sup>        | 12 | Analysis of the position of skeletal elements (bones) in a human body. **System API**: This is a system API.   |
| ANALYSIS\_VIDEO\_LABEL<sup>12+</sup>        | 13 | Video label analysis. **System API**: This is a system API.   |
| ANALYSIS\_HIGHLIGHT<sup>12+</sup>        | 14 | Highlight label. **System API**: This is a system API.   |
| ANALYSIS\_MULTI\_CROP<sup>12+</sup>        | 15 | Label for 2D panning detection boxes. **System API**: This is a system API.   |
| ANALYSIS\_SEARCH\_INDEX<sup>18+</sup>        | 16 | Foreground index analysis. **System API**: This is a system API.   |
| ANALYSIS\_SELECTED<sup>24+</sup>        | 17 | Preferred analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |
| ANALYSIS\_DUPLICATE\_SIMILARITY<sup>24+</sup>        | 18 | Repetition and similarity analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |
| ANALYSIS\_NEGATIVE\_EMOTION<sup>24+</sup>        | 19 | Negative emotion analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |
| ANALYSIS\_FACE\_AESTHETICS<sup>24+</sup>        | 20 | Facial aesthetics analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |
| ANALYSIS\_MAGIC\_EMOJI<sup>24+</sup>        | 21 | Magic emoji analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |
| ANALYSIS\_AI\_EDIT<sup>24+</sup>        | 22 | AI editing analysis.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.   |

## AnalysisConfig<sup>24+</sup>

Defines the asset analysis configuration.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| types | [AnalysisType](#analysistype11)[]  | No| No| Array of intelligent analysis types. The maximum size of the array is the number of members defined by the [AnalysisType](#analysistype11) enum.|
| uris | string[]  | No| No| Asset URI array.<br>Length range: [0, 100].|
| extraInfos | string  | No| Yes| Extended information in JSON string format.<br>Length range: (0, 500].|

## AnalysisResult<sup>24+</sup>

Defines the asset analysis result.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| result | number  | No| No| Result code of asset analysis.|

## HighlightAlbumInfoType<sup>12+</sup>

Enumerates the types of the highlights album information.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name           | Value | Description      |
| :------------ | :- | :------- |
| COVER\_INFO   | 0  | Cover information.   |
| PLAY\_INFO    | 1  | Music information.   |
| ALBUM\_INFO<sup>21+</sup>    | 2  | Album information.   |

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

## HighlightAlbumChangeAttribute<sup>21+</sup>

Enumerates the attributes of a highlights album.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name           | Value | Description      |
| :------------ | :- | :------- |
| IS\_VIEWED   | 0  | Whether the highlights album has been viewed.   |
| NOTIFICATION\_TIME    | 1  | Time when the application sends a highlight notification.   |
| IS\_FAVORITE    | 2  | Whether the highlights album is marked as a favorite.   |

## ThumbnailVisibility<sup>14+</sup>

Enumerates the visibility statuses of thumbnails.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                          | Value | Description      |
| :---------------------------- | :- | :------- |
| INVISIBLE        | 0  | The thumbnail is inaccessible.   |
| VISIBLE         | 1  | The thumbnail is accessible.   |

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

Enumerates the types of data masking applied to media resources when accessed by an application.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| HIDE_LOCATION_AND_SHOOTING_PARAM |  0 |  Masks geographic location and capture parameters.|
| HIDE_LOCATION_ONLY |  1 |  Masks geographic location information only.|
| HIDE_SHOOTING_PARAM_ONLY |  2 |  Masks capture parameters only.|
| NO_HIDE_SENSITIVE_TYPE |  3 |  No data masking is applied.|
| DEFAULT<sup>23+</sup> |  4 |  Applies data masking based on the [ohos.permission.MEDIA_LOCATION](../../security/AccessToken/permissions-for-all-user.md#ohospermissionmedia_location) permission. The specifications are as follows:<br>- If this permission is available, no masking is applied.<br>- If this permission is unavailable, geographic location is masked.|

## CloudEnhancementTaskStage<sup>13+</sup>

Enumerates the cloud enhancement task states, which are returned by [CloudEnhancementTaskState](#cloudenhancementtaskstate13).

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

| Name   | Type                       | Read-Only| Optional| Description                                                        |
| ---- | ------- | ---- |  ---- | ----- |
| taskStage  | [CloudEnhancementTaskStage](#cloudenhancementtaskstage13)  | Yes| No| Cloud enhancement task state. |
| transferredFileSize  | number  | Yes| Yes| Size of the transferred file, in bytes. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_UPLOADING** or **CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING**. |
| totalFileSize  | number  | Yes| Yes| Total file size, in bytes. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_UPLOADING** or **CloudEnhancementTaskStage.TASK_STAGE_DOWNLOADING**. |
| expectedDuration  | number  | Yes| Yes| Queuing duration, in milliseconds. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_EXECUTING**. |
| statusCode  | number  | Yes| Yes| Status code. This parameter is mandatory when **taskStage** is **CloudEnhancementTaskStage.TASK_STAGE_FAILED**. |

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

## SupportedImageFormat<sup>20+</sup>

Enumerates the supported image formats.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                          | Value | Description      |
| :---------------------------- | :- | :------- |
| AVFILE_FORMAT_JPG         | 'jpg'  | JPG.   |

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
| HDC_RETAIN_FORCE<sup>22+</sup> |  1 |  Deletes the local metadata and thumbnail of the original files from the home storage device.|

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

| Name   | Type                       | Read-Only| Optional| Description                                                        |
| ---- | ------- | ---- |  ---- | ----- |
| taskStatus | [CloudMediaAssetTaskStatus](#cloudmediaassettaskstatus14)  | Yes| No| Status of the download task. |
| taskInfo | string  | Yes| No| Total number of and size (measured in bytes) of the assets that have been downloaded, and the total number and size (also measured in bytes) of the assets remaining to be downloaded. |
| errorCode | [CloudMediaTaskPauseCause](#cloudmediataskpausecause14)  | Yes| No| Reason why the download task is suspended. |

## RecommendationType<sup>11+</sup>

Enumerates the types of recommended images.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| COLOR_STYLE_PHOTO<sup>18+</sup> |  12 | Recommended style.<br>**System API**: This is a system API.|
| CAT<sup>23+</sup> |  13 | Cat images will be recommended.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| DOG<sup>23+</sup> |  14 | Dog images will be recommended.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| ARCHITECTURE<sup>23+</sup> |  15 | Architecture images will be recommended.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| LANDSCAPE<sup>23+</sup> |  16 | Landscape images will be recommended.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| GAUSSIAN_SPLAT_3D<sup>24+</sup> |  17 | Images generated using the 3D Gaussian technology will be recommended.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## RecommendationOptions<sup>11+</sup>

Defines the image recommendation options. The image recommendation feature depends on the image data analysis capability, which varies with devices.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Read-Only| Optional| Description                         |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| recommendationTypeList<sup>23+</sup> | Array\<[RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)>   | No  | Yes| List of recommendation types. If images of multiple categories need to be recommended based on the enumerated value, set this parameter.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| defaultRecommendationType<sup>24+</sup> | [RecommendationType](arkts-apis-photoAccessHelper-e.md#recommendationtype11)   | No  | Yes| Recommended tag displayed when the picker is opened. This configuration takes effect only after **recommendationTypeList** is set.<br>If the tag exists, the tag page is displayed by default.<br>If the tag does not exist, the All tag page is displayed by default.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## ThumbnailChangeStatus<sup>20+</sup>

Enumerates the change statuses of thumbnails (including images and videos).

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| THUMBNAIL_NOT_EXISTS      | 0    | The thumbnail does not exist.    |
| THUMBNAIL_ADD             | 1    | The thumbnail has been re-created.    |
| THUMBNAIL_UPDATE          | 2    | The thumbnail has been updated.    |
| THUMBNAIL_NOT_CHANGE      | 3    | The thumbnail has not changed.    |

## StrongAssociationType<sup>20+</sup>

Enumerates the strong association types of photos.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NORMAL                    | 0    | Common photo.    |
| CLOUD_ENHANCEMENT         | 1    | Cloud-enhanced photo.    |

## CompositeDisplayMode<sup>22+</sup>

Enumerates the display modes available for a composite image.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| DEFAULT                   | 0    | Displays the original composite image.    |
| CLOUD_ENHANCEMENT         | 1    | Displays the cloud-enhanced composite image.    |

## PhotoAssetChangeInfo<sup>20+</sup>

Describes the information about a media asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| fileId | number  | No| No| ID of the media asset.<br>**System API**: This is a system API. |
| dateDay | string  | No| No| Date when the media asset was created.<br>**System API**: This is a system API. |
| isHidden | boolean  | No| No| Whether the media asset is hidden. **true** if hidden, **false** otherwise.<br>**System API**: This is a system API. |
| strongAssociation | [StrongAssociationType](#strongassociationtype20)  | No| No| Strong association type of the media asset.<br>**System API**: This is a system API. |
| thumbnailVisible | [ThumbnailVisibility](#thumbnailvisibility14)  | No| No| Accessibility status of the thumbnail.<br>**System API**: This is a system API. |
| dateTrashedMs |number  |No| No| Unix timestamp when the media asset was deleted, in milliseconds.<br>**System API**: This is a system API. |
| dateAddedMs | number  | No| No| Unix timestamp when the media asset was created, in milliseconds.<br>**System API**: This is a system API. |
| dateTakenMs | number  | No| No| Unix timestamp when the media asset was captured, in milliseconds.<br>**System API**: This is a system API. |
| dateModifiedMs| number  | No| Yes| Unix timestamp when the file is modified, in milliseconds.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API. |
| hiddenTime | number  | No| Yes| Hidden time of a media asset (image or video), in milliseconds.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API. |
| position | [PositionType](arkts-apis-photoAccessHelper-e.md#positiontype16)  | No| Yes| Position of the media asset.<br>**System API**: This is a system API. |
| displayName | string  | No| Yes| Display name of the media asset.<br>**System API**: This is a system API. |
| size | number  | No| Yes| File size of the media asset, in bytes. The size of a moving photo includes the total size of the image and video.<br>**System API**: This is a system API. |
| albumChangeInfos | [AlbumChangeInfo](#albumchangeinfo20)[]  | No| Yes| Smart album change information.<br>**System API**: This is a system API. |

## PhotoAssetChangeData<sup>20+</sup>

Describes the change data of a media asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description         |
| ---- | ------- | ---- |  ---- | ----- |
| thumbnailChangeStatus | [ThumbnailChangeStatus](#thumbnailchangestatus20)  | No| No| Change status of the thumbnail (image/video).<br>**System API**: This is a system API.|
| version       |  number  | No| No| Version number of the media asset notification, which is used to determine the order of notifications.<br>**System API**: This is a system API. |

## AlbumChangeInfo<sup>20+</sup>

Describes the information about an album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| hiddenCount | number  | No| No| Number of hidden assets in the album.<br>**System API**: This is a system API.|
| hiddenCoverUri | string  | No| No| URI of the hidden cover asset in the album.<br>**System API**: This is a system API.|
| isCoverChanged | boolean  | No| No| Whether the file content of the album cover has changed. **true** if changed, **false** otherwise.<br>**System API**: This is a system API.|
| isHiddenCoverChanged | boolean  | No| No| Whether the file content of the hidden album cover has changed. **true** if changed, **false** otherwise.<br>**System API**: This is a system API.|
| coverInfo | [PhotoAssetChangeInfo](#photoassetchangeinfo20)  | No| Yes| Information of the album cover asset.<br>**System API**: This is a system API.|
| hiddenCoverInfo | [PhotoAssetChangeInfo](#photoassetchangeinfo20)  | No| Yes| Information of the hidden album cover asset.<br>**System API**: This is a system API.|
| orderSection | number  | No| Yes| Section that defines the order of the album, specifying where the album is displayed in the Gallery.<br>**System API**: This is a system API.|
| albumOrder | number  | No| Yes| Sorting value of the album.<br>**System API**: This is a system API.|
| HIDDEN<sup>23+</sup>    | boolean  | No| Yes| Whether the album is hidden. **true** if hidden, **false** otherwise.<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|
| lpath | string  | No| Yes| Virtual path of the album.<br>**Since**: 26.0.0<br>**Model restriction**: This API can be used only in the stage model.<br>**System API**: This is a system API.|

## AlbumChangeData<sup>20+</sup>

Describes the change data of an album.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Read-Only| Optional| Description      |
| ---- | ------- | ---- |  ---- | ----- |
| version | number  | No| No| Version number of the album notification, which is used to determine the order of notifications.<br>**System API**: This is a system API.|

## PhotoAssetCustomRecord<sup>20+</sup>

Provides APIs for custom user behavior recording for Gallery.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| --- | --- | --- | --- | --- |
| fileId | number | Yes| No| File ID, which must be an integer greater than 0.|
| shareCount | number | Yes| No| Number of times that image or video was shared. The value must be an integer greater than 0.|
| lcdJumpCount | number | Yes| No| Number of times the image or video was jumped to in large view. The value must be an integer greater than 0.|

## CoverUriSource<sup>20+</sup>

Enumerates the sources of the album covers.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| DEFAULT_COVER        | 0    | Default cover.    |
| MANUAL_COVER         | 1    | Cover manually set.    |

## AlbumOrder<sup>20+</sup>

Describes the album sorting order.

### Properties

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name          | Type   | Read-Only  | Optional | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| albumId      | number | No  | No | Album ID.    |
| albumOrder   | number | No  | No | Sorting value of the album. |
| orderSection | number | No  | No | Sorting section of the album.|
| orderType    | number | No  | No | Sorting type of the album.|
| orderStatus  | number | No  | No | Sorting status of the album.|

## ValueType<sup>22+</sup>

type ValueType =  number | string | boolean | Uint8Array | null

Defines the type of value in a KV pair. The type varies with the parameter function.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Type| Description|
|------|------|
| number | Number.|
| string | String.|
| boolean | Boolean.|
| Uint8Array | Uint8 array.|
| null | Null.|

## ValuesBucket<sup>22+</sup>

type ValuesBucket = Record&lt;string, ValueType&gt;

Defines the type of key and value in a KV pair.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Type| Description|
| ---- | ---- |
| Record&lt;string, [ValueType](#valuetype22)&gt; | Types of key and value in a KV pair. The key type is string, and the value type is specified by **ValueType**.|

## ResultSet<sup>22+</sup>

Defines APIs to access the result set obtained by querying the RDB store.

Before calling any of the following APIs, you must use [query](#query22) to obtain a ResultSet instance.

### Properties

​**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name| Type| Read-Only| Optional| Description|
| ----- | ---- | ----- | ---- | ----- |
| columnCount | number | No| No| Number of columns in the result set.<br>**System API**: This is a system API.|
| rowCount | number | No| No| Number of rows in the result set.<br>**System API**: This is a system API.|
| rowIndex | number | No| No| Index of the current row in the result set.<br>**System API**: This is a system API.|
| isAtLastRow | boolean | No| No| Whether the cursor is in the last row of the result set. **true** if the cursor is in the last row; **false** otherwise.<br>**System API**: This is a system API.|

### goToRow<sup>22+</sup>

goToRow(position: number): boolean

Moves the cursor to the specified row in the result set.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ---- | ----- | ----- |
| position | number | Yes| Index of the specified row, starting from 0. The value ranges from 0 to the total number of rows in the result set minus 1.|

**Return value**

| Type| Description|
| ---- | ----- |
| boolean | Operation result. **true** if the cursor is moved to the specified row; **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800151 | Scene parameters validate failed, possible causes: position invalid. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('goToRow');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.goToRow(0);
    resultSet.close();
  } catch (err) {
    console.error(`goToRow failed with error: ${err.code}, ${err.message}`);
  }
}
```

### goToFirstRow<sup>22+</sup>

goToFirstRow(): boolean

Moves the cursor to the first row of the result set.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type| Description|
| ----- | ---- |
| boolean | Operation result. **true** if the cursor is moved to the first row; **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('goToFirstRow');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.goToFirstRow();
    resultSet.close();
  } catch (err) {
    console.error(`goToFirstRow failed with error: ${err.code}, ${err.message}`);
  }
}
```

### goToNextRow<sup>22+</sup>

goToNextRow(): boolean

Moves the cursor to the next row in the result set.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type| Description|
| ----- | ---- |
| boolean | Operation result. **true** if the cursor is moved to the next row; **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('goToNextRow');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.goToNextRow();
    resultSet.close();
  } catch (err) {
    console.error(`goToNextRow failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getValue<sup>22+</sup>

getValue(columnIndex: number): ValueType

Obtains the value of the specified column in the current row.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ---- | ----- | ----- |
| columnIndex | number | Yes| Index of the specified column, starting from 0. The value ranges from 0 to the total number of columns in the result set minus 1.|

**Return value**

| Type| Description|
| ---- | ----- |
| [ValueType](#valuetype22) | Allowed data field types.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800151 | Scene parameters validate failed, possible causes: columnIndex invalid. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getValue');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.goToFirstRow();
    const codes = resultSet.getValue(0);
    resultSet.close();
  } catch (err) {
    console.error(`getValue failed with error: ${err.code}, ${err.message}`);
  }
}
```

### getRow<sup>22+</sup>

getRow(): ValuesBucket

Obtains the values of all columns in the specified row.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type| Description|
| ---- | ----- |
| [ValuesBucket](#valuesbucket22) | Values of all columns in the specified row.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getRow');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.goToFirstRow();
    const row = resultSet.getRow();
    resultSet.close();
  } catch (err) {
    console.error(`getRow failed with error: ${err.code}, ${err.message}`);
  }
}
```

### close<sup>22+</sup>

close(): void

Closes this resultSet to release memory. If it is not closed, memory leaks may occur.

​**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Media Library Error Codes](errorcode-medialibrary.md).

| ID| Error Message |
| --------- | ---------- |
| 202 | Called by non-system application. |
| 23800301 | Internal system error. It is recommended to retry and check the logs.<br>Possible causes: 1. Database corrupted; 2. The file system is abnormal; 3. The IPC request timed out. |

**Example**

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('close');
  try {
    let resultSet: photoAccessHelper.ResultSet = await phAccessHelper.query('SELECT * from Photos');
    resultSet.close();
  } catch (err) {
    console.error(`close failed with error: ${err.code}, ${err.message}`);
  }
}
```

## CloudAssetDownloadNotifyType<sup>21+</sup>

Enumerates the types of events reported during a cloud asset download.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DOWNLOAD_PROGRESS |  0 |  Fired when download progress is updated.|
| DOWNLOAD_FINISHED |  1 |  Fired when a download completes successfully. |
| DOWNLOAD_FAILED |  2 |  Fired when a download fails. |
| DOWNLOAD_ASSET_DELETED |  3 |  Fired when a downloaded asset is deleted. |
| DOWNLOAD_AUTO_PAUSED |  4 |  Fired when the system automatically pauses a download. |
| DOWNLOAD_AUTO_RESUMED |  5 |  Fired when the system automatically resumes a download. |
| DOWNLOAD_REFRESHED |  6 |  Fired when the download status is refreshed. |

## CloudAssetDownloadCode<sup>21+</sup>

Enumerates the status codes returned when adding an item to a batch download.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| ADD_DOWNLOAD_TASK_SUCCESS |  0 |  The individual download item is successfully added.|
| DOWNLOAD_ASSET_NOT_EXIST |  1 |  The requested asset does not exist. |

## CloudAssetDownloadProgressInfo<sup>21+</sup>

Describes the progress information about a batch download.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| downloadEventType | [CloudAssetDownloadNotifyType](#cloudassetdownloadnotifytype21)  | Yes| No| Type of event that triggers this update.|
| fileId  | number  |Yes|No| ID of the file being downloaded. |
| percent  | number  |Yes|No| Download completion percentage. |
| autoPauseReason       | number  |Yes|No| Reason for automatic pause. |

## CloudAssetDownloadStatus<sup>21+</sup>

Describes the status information about a batch download.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| taskInfos | string[]  | Yes| No| Array of strings containing the information of each individual download item within this batch download.|

## HdrMode<sup>22+</sup>

Enumerates the HDR modes of media assets.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Default type.|
| HDR_ISO_SINGLE |  1 |  Single-layer HDR image that complies with ISO specifications. |
| HDR_ISO_DUAL |  2 |  Dual-layer HDR images that comply with ISO specifications. |
| HDR_CUVA |  3 |  HDR image taken by a legacy device or camera. |
| HDR_VIVID_SINGLE |  4 |  Single-layer image that complies with the HDR Vivid standard. |
| HDR_VIVID_DUAL |  5 |  Dual-layer image that complies with the HDR Vivid standard. |

## PhotoRiskStatus<sup>23+</sup>

Enumerates the risk types of images.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| UNIDENTIFIED |  0 |  Default type.|
| APPROVED |  1 |  Approved images. |
| SUSPICIOUS |  2 |  Suspicious images. |
| REJECTED |  3 |  Rejected images. |

## AppLinkState<sup>24+</sup>

Enumerates the states of a file memory link.

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Whether the file has a memory link cannot be determined.|
| HAS_NO_LINK |  1 |  The file does not have a memory link. |
| HAS_LINK |  2 |  The file has a memory link. |

## DefaultCoverOrderInfo

Defines the default cover selection rule information of the album.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Read-Only| Optional| Description                         |
| ----------------------- | ------------------- | ---- | ---- | -------------------------------- |
| albumType    | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)   | No| No  | Album type.|
| albumSubtype    | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)   | No| No  | Subtype of the album.|
| lpath    | string   | No| Yes  | Virtual path of the album.|
| orderKey    | [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)   | No| No  | Main field on which the default cover selection depends.|
| orderSubKey    | [PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)   | No| No  | Auxiliary field on which the default cover selection depends.|
| orderType    | number   | No| No  | Sorting type of the field on which the default cover selection depends.<br>The value is an integer. The value range is [0, 1]. The value **0** indicates that the default cover is selected in descending order based on the **orderKey** and **orderSubKey** fields, and the value **1** indicates that the default cover is selected in ascending order based on the **orderKey** and **orderSubKey** fields.|

## DeepOptimizeState

Enumerates the status types of the deep optimization of storage space.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| RUNNING |  0 |  The deep optimization is in progress.|
| COMPLETED |  1 |  The deep optimization is successfully completed. |
| FAILED |  2 |  The deep optimization fails. |
| STOPPED |  3 |  The deep optimization is stopped. |
| INTERRUPTED |  4 |  The deep optimization is interrupted. |

## DeepOptimizeSpaceProgress

Defines the progress of deep optimization of storage space.

**Since**: 26.0.0

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name | Type               | Read-Only| Optional| Description                                             |
| ---- | ------- | ---- |  ---- | ----- |
| state | [DeepOptimizeState](#deepoptimizestate)  | No| No| Current deep optimization status.|
| progress  | number  |No|No| Progress of deep optimization, in percentage. The value range is [0, 100]. |