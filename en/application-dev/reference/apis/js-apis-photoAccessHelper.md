# @ohos.file.photoAccessHelper (Album Management)

The **photoAccessHelper** module provides APIs for album management, including creating an album and accessing and modifying media data in an album.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
```

## photoAccessHelper.getPhotoAccessHelper

getPhotoAccessHelper(context: Context): PhotoAccessHelper

Obtains a **PhotoAccessHelper** instance for accessing and modifying media files in the album.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](js-apis-inner-app-context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [PhotoAccessHelper](#photoaccesshelper) | Returns the **PhotoAccessHelper** instance created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401   | if parameter is invalid.         |

**Example**

```ts
// The phAccessHelper instance obtained is a global object. It is used by default in subsequent operations. If the code snippet is not added, an error will be reported indicating that phAccessHelper is not defined.
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
```

## PhotoAccessHelper

### getAssets

getAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;PhotoAsset&gt;&gt;): void

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the image and video assets.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Yes  | Callback invoked to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset != undefined) {
        console.info('photoAsset.displayName : ' + photoAsset.displayName);
      }
    } else {
      console.error('fetchResult fail' + err);
    }
  });
}
```

### getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains image and video assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type               | Mandatory| Description            |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](#fetchoptions)   | Yes  | Options for fetching the image and video assets.    |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset != undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getAssets failed, message = ', err);
  }
}
```

### createAsset

createAsset(displayName: string, callback: AsyncCallback&lt;PhotoAsset&gt;): void

Creates an image or video asset with the specified file name. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| callback |  AsyncCallback&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
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
    if (photoAsset != undefined) {
      console.info('createAsset file displayName' + photoAsset.displayName);
      console.info('createAsset successfully');
    } else {
      console.error('createAsset failed, message = ', err);
    }
  });
}
```

### createAsset

createAsset(displayName: string): Promise&lt;PhotoAsset&gt;

Creates an image or video asset with the specified file name. This API uses a promise to return the result.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
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
    console.error('createAsset failed, message = ', err);
  }
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions, callback: AsyncCallback&lt;PhotoAsset&gt;): void

Creates an image or video asset with the specified file name and options. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| options  | [PhotoCreateOptions](#photocreateoptions)        | Yes  | Options for creating an image or video asset.             |
| callback |  AsyncCallback&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
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
    if (photoAsset != undefined) {
      console.info('createAsset file displayName' + photoAsset.displayName);
      console.info('createAsset successfully');
    } else {
      console.error('createAsset failed, message = ', err);
    }
  });
}
```

### createAsset

createAsset(displayName: string, options: PhotoCreateOptions): Promise&lt;PhotoAsset&gt;

Creates an image or video asset with the specified file name and options. This API uses a promise to return the result.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
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
    console.error('createAsset failed, message = ', err);
  }
}
```

### createAsset

createAsset(photoType: PhotoType, extension: string, options: CreateOptions, callback: AsyncCallback&lt;string&gt;): void

Creates an image or video asset with the specified file type, file name extension, and options. This API uses an asynchronous callback to return the result.

If the application does not have the **ohos.permission.WRITE_IMAGEVIDEO** permission, you can use a security component to create a media asset. For details, see [Creating a Media Asset Using a Security Component](../../file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **jpg**.             |
| options  | [CreateOptions](#createoptions)        | Yes  | Options for creating the image or video asset, for example, **{title: 'testPhoto'}**.             |
| callback |  AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the URI of the created image or video.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension:string = 'jpg';
  let options: photoAccessHelper.CreateOptions = {
    title: 'testPhoto'
  }
  phAccessHelper.createAsset(photoType, extension, options, (err, uri) => {
    if (uri != undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error('createAsset failed, message = ', err);
    }
  });
}
```

### createAsset

createAsset(photoType: PhotoType, extension: string, callback: AsyncCallback&lt;string&gt;): void

Creates an image or video asset with the specified file type and file name extension. This API uses an asynchronous callback to return the result.

If the application does not have the **ohos.permission.WRITE_IMAGEVIDEO** permission, you can use a security component to create a media asset. For details, see [Creating a Media Asset Using a Security Component](../../file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **jpg**.             |
| callback |  AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the URI of the created image or video.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension: string = 'jpg';
  phAccessHelper.createAsset(photoType, extension, (err, uri) => {
    if (uri != undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error('createAsset failed, message = ', err);
    }
  });
}
```

### createAsset

createAsset(photoType: PhotoType, extension: string, options?: CreateOptions): Promise&lt;string&gt;

Creates an image or video asset with the specified file type, file name extension, and options. This API uses a promise to return the result.

If the application does not have the **ohos.permission.WRITE_IMAGEVIDEO** permission, you can use a security component to create a media asset. For details, see [Creating a Media Asset Using a Security Component](../../file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](#phototype)        | Yes  | Type of the file to create, which can be **IMAGE** or **VIDEO**.             |
| extension  | string        | Yes  | File name extension, for example, **jpg**.             |
| options  | [CreateOptions](#createoptions)        | No  | Options for creating the image or video asset, for example, **{title: 'testPhoto'}**.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the created image or video asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
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
    console.error('createAsset failed, message = ', err);
  }
}
```

### createAlbum

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void

Creates an album. This API uses an asynchronous callback to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br>. .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |
| callback |  AsyncCallback&lt;[Album](#album)&gt; | Yes  | Callback invoked to return the created album instance.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
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
      console.error('createAlbumCallback failed with err: ' + err);
      return;
    }
    console.info('createAlbumCallback successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  });
}
```

### createAlbum

createAlbum(name: string): Promise&lt;Album&gt;

Creates an album. This API uses a promise to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br>. .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900015       |  File exists.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  console.info('createAlbumDemo');
  let albumName: string = 'newAlbumName' + new Date().getTime();
  phAccessHelper.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err: BusinessError) => {
    console.error('createAlbumPromise failed with err: ' + err);
  });
}
```

### deleteAlbums

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes albums. This API uses an asynchronous callback to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  | Array&lt;[Album](#album)&gt;         | Yes  | Albums to delete.             |
| callback |  AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
      console.error('deletePhotoAlbumsCallback failed with err: ' + err);
      return;
    }
    console.info('deletePhotoAlbumsCallback successfully');
  });
  fetchResult.close();
}
```

### deleteAlbums

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;

Deletes albums. This API uses a promise to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

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
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);
  });
  fetchResult.close();
}
```

### getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums based on the specified options and album type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype)         | Yes  | Type of the album to obtain.             |
| subtype  | [AlbumSubtype](#albumsubtype)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](#fetchoptions)         | Yes  |  Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
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
      console.error('getAlbumsCallback failed with err: ' + err);
      return;
    }
    if (fetchResult == undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

### getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums by type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype)         | Yes  | Type of the album to obtain.             |
| subtype  | [AlbumSubtype](#albumsubtype)         | Yes  | Subtype of the album.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  // Obtain the system album VIDEO, which is preset by default.
  console.info('getAlbumsDemo');
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO, async (err, fetchResult) => {
    if (err) {
      console.error('getAlbumsCallback failed with err: ' + err);
      return;
    }
    if (fetchResult == undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

### getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains albums based on the specified options and album type. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype)         | Yes  | Type of the album to obtain.             |
| subtype  | [AlbumSubtype](#albumsubtype)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](#fetchoptions)         | No  |  Options for fetching the albums. If this parameter is not specified, the albums are obtained based on the album type by default.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult == undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error('getAlbumsPromise failed with err: ' + err);
  });
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
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden files. |
| options  | [FetchOptions](#fetchoptions)         | Yes  |  Options for retrieving the hidden files. |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
      if (fetchResult == undefined) {
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
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden files. |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201      |  Permission denied.         |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

// Obtain the preset hidden album.
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE, async (err, fetchResult) => {
    if (fetchResult == undefined) {
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
    if (fetchResult == undefined) {
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
| mode  | [HiddenPhotosDisplayMode](#hiddenphotosdisplaymode11)         | Yes  | Display mode of hidden files. |
| options  | [FetchOptions](#fetchoptions)         | No  |  Options for retrieving the files. If this parameter is not specified, the files are retrieved based on the display mode of hidden files.     |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

// Obtain the preset hidden album.
async function getSysHiddenAlbum() {
  console.info('getSysHiddenAlbumDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ASSETS_MODE)
    .then( async (fetchResult) => {
      if (fetchResult == undefined) {
        console.error('getSysHiddenAlbumPromise fetchResult is undefined');
        return;
      }
      let hiddenAlbum: photoAccessHelper.Album = await fetchResult.getFirstObject();
      console.info('getAlbumsPromise successfully, albumUri: ' + hiddenAlbum.albumUri);
      fetchResult.close();
    }).catch((err: BusinessError) => {
      console.error('getSysHiddenAlbumPromise failed with err: ' + err);
    });
}

// Obtain the hidden albums displayed by album, that is, the albums with hidden files. Such albums do not include the preset hidden album and the albums in the trash.
async function getHiddenAlbumsView() {
  console.info('getHiddenAlbumsViewDemo');
  phAccessHelper.getHiddenAlbums(photoAccessHelper.HiddenPhotosDisplayMode.ALBUMS_MODE).then( async (fetchResult) => {
    if (fetchResult == undefined) {
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
        console.error('album get hidden assets failed with error: ' + err);
      });
    }
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error('getHiddenAlbumsViewPromise failed with err: ' + err);
  });
}
```

### deleteAssets

deleteAssets(uriList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes media assets. This API uses an asynchronous callback to return the result. The deleted assets are moved to the trash.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002       | Invalid uri.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    phAccessHelper.deleteAssets([asset.uri], (err) => {
      if (err == undefined) {
        console.info('deleteAssets successfully');
      } else {
        console.error('deleteAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.info('fetch failed, message =', err);
  }
}
```

### deleteAssets

deleteAssets(uriList: Array&lt;string&gt;): Promise&lt;void&gt;

Deletes media assets. This API uses a promise to return the result. The deleted assets are moved to the trash.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000002       | Invalid uri.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    await phAccessHelper.deleteAssets([asset.uri]);
    console.info('deleteAssets successfully');
  } catch (err) {
    console.error('deleteAssets failed with error: ' + err);
  }
}
```

### registerChange

registerChange(uri: string, forChildUris: boolean, callback: Callback&lt;ChangeData&gt;) : void

Registers listening for the specified URI. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type                                       | Mandatory| Description                                                        |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | Yes  | URI of the photo asset, URI of the album, or [DefaultChangeUri](#defaultchangeuri).|
| forChildUris | boolean                                     | Yes  | Whether to perform fuzzy listening.<br>If **uri** is the URI of an album, the value **true** means to listen for the changes of the files in the album; the value **false** means to listen for the changes of the album only. <br>If **uri** is the URI of a **photoAsset**, there is no difference between **true** and **false** for **forChildUris**.<br>If **uri** is **DefaultChangeUri**, **forChildUris** must be set to **true**. If **forChildUris** is **false**, the URI cannot be found and no message can be received.|
| callback  | Callback&lt;[ChangeData](#changedata)&gt; | Yes  | Callback invoked to return the [ChangeData](#changedata). <br>**NOTE**<br>Multiple callback listeners can be registered for a URI. You can use [unRegisterChange](#unregisterchange) to unregister all listeners for the URI or a specified callback listener.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('registerChangeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset != undefined) {
    console.info('photoAsset.displayName : ' + photoAsset.displayName);
  }
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  // Register onCallback1.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
  // Register onCallback2.
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);

  photoAsset.setFavorite(true, (err) => {
    if (err == undefined) {
      console.info('setFavorite successfully');
    } else {
      console.error('setFavorite failed with error:' + err);
    }
  });
}
```

### unRegisterChange

unRegisterChange(uri: string, callback?: Callback&lt;ChangeData&gt;): void

Unregisters listening for the specified URI. Multiple callbacks can be registered for a URI for listening. You can use this API to unregister the listening of the specified callbacks or all callbacks.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | Yes  | URI of the photo asset, URI of the album, or [DefaultChangeUri](#defaultchangeuri).|
| callback | Callback&lt;[ChangeData](#changedata)&gt; | No  | Callback to unregister. If this parameter is not specified, all the callbacks for listening for the URI will be canceled. <br>**NOTE**: The specified callback unregistered will not be invoked when the data changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('offDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset != undefined) {
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
  photoAsset.setFavorite(true, (err) => {
    if (err == undefined) {
      console.info('setFavorite successfully');
    } else {
      console.error('setFavorite failed with error:' + err);
    }
  });
}
```

### createDeleteRequest

createDeleteRequest(uriList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Creates a dialog box for deleting media files. This API uses an asynchronous callback to return the result. The deleted media files are moved to the trash.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | Yes  | URIs of the media files to delete. A maximum of 300 media files can be deleted.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    phAccessHelper.createDeleteRequest([asset.uri], (err) => {
      if (err == undefined) {
        console.info('createDeleteRequest successfully');
      } else {
        console.error('createDeleteRequest failed with error: ' + err);
      }
    });
  } catch (err) {
    console.info('fetch failed, message =', err);
  }
}
```

### createDeleteRequest

createDeleteRequest(uriList: Array&lt;string&gt;): Promise&lt;void&gt;

Creates a dialog box for deleting media files. This API uses a promise to return the result. The deleted media files are moved to the trash.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    await phAccessHelper.createDeleteRequest([asset.uri]);
    console.info('createDeleteRequest successfully');
  } catch (err) {
    console.error('createDeleteRequest failed with error: ' + err);
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
| options  | [FetchOptions](#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search conditions or sorting modes are set, the API cannot be called successfully.     |
| callback | AsyncCallback&lt;number&gt;| Yes  | Callback invoked to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
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
    // Obtain the uri of the second file
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);

    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {
      if (err == undefined) {
        console.info(`getPhotoIndex successfully and index is : ${index}`);
      } else {
        console.info(`getPhotoIndex failed;`);
      }
    });
  } catch (error) {
    console.info(`getPhotoIndex failed; error: ${error}`);
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
| options  | [FetchOptions](#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search conditions or sorting modes are set, the API cannot be called successfully.     |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt;| Promise used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
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
    // Obtain the uri of the second file
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getObjectByPosition(expectIndex);
    phAccessHelper.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {
      console.info(`getPhotoIndex successfully and index is : ${index}`);
    }).catch((err: BusinessError) => {
      console.info(`getPhotoIndex failed; error: ${err}`);
    });
  } catch (error) {
    console.info(`getPhotoIndex failed; error: ${error}`);
  }
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

Releases this **PhotoAccessHelper** instance. This API uses an asynchronous callback to return the result.
Call this API when the APIs of the **PhotoAccessHelper** instance are no longer used.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('releaseDemo');
  phAccessHelper.release((err) => {
    if (err != undefined) {
      console.error('release failed. message = ', err);
    } else {
      console.info('release ok.');
    }
  });
}
```

### release

release(): Promise&lt;void&gt;

Releases this **PhotoAccessHelper** instance. This API uses a promise to return the result.
Call this API when the APIs of the **PhotoAccessHelper** instance are no longer used.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('releaseDemo');
  try {
    await phAccessHelper.release();
    console.info('release ok.');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

## PhotoAsset

Provides APIs for encapsulating file asset attributes.

### Attributes

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | Yes  | No  | Media asset URI, for example, **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**. For details, see [Media File URI](../../file-management/user-file-uri-intro.md#media-file-uri).        |
| photoType   | [PhotoType](#phototype) | Yes  | No  | Type of the file.                                              |
| displayName               | string                   | Yes  | No  | File name, including the file name extension, to display.                                |

### get

get(member: string): MemberType;

Obtains a **PhotoAsset** member parameter.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Name of the member parameter to obtain. Except **uri**, **photoType**, and **displayName**, you need to pass in [PhotoKeys](#photokeys) in **fetchColumns** in **get()**. For example, to obtain the title attribute, set **fetchColumns: ['title']**.|

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| [MemberType](#membertype) | **PhotoAsset** member parameter obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000014     | Member is not a valid PhotoKey.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('photoAssetGetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: photoAccessHelper.PhotoKeys = photoAccessHelper.PhotoKeys.TITLE;
    let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title.toString());
    console.info('photoAsset Get photoAssetTitle = ', photoAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void

Sets a **PhotoAsset** member parameter.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Name of the member parameter to set. For example, **[PhotoKeys](#photokeys).TITLE**.|
| value | string | Yes   | Member parameter to set. Only the value of **[PhotoKeys](#photokeys).TITLE** can be modified.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000014     | Member is not a valid PhotoKey.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('photoAssetSetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
    photoAsset.set(title, 'newTitle');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the file metadata to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | if values to commit is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);
  photoAsset.set(title, 'newTitle2');
  photoAsset.commitModify((err) => {
    if (err == undefined) {
      let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
      console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);
    } else {
      console.error('commitModify failed, message =', err);
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the file metadata to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401    | if values to commit is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000001      | Invalid display name.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: ['title'],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  let title: string = photoAccessHelper.PhotoKeys.TITLE.toString();
  let photoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
  console.info('photoAsset get photoAssetTitle = ', photoAssetTitle);
  photoAsset.set(title, 'newTitle3');
  try {
    await photoAsset.commitModify();
    let newPhotoAssetTitle: photoAccessHelper.MemberType = photoAsset.get(title);
    console.info('photoAsset get newPhotoAssetTitle = ', newPhotoAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**<br>The write operations are mutually exclusive. After a write operation is complete, you must call **close** to close the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the file descriptor (FD) of the file opened.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('openDemo');
   let testFileName: string = 'testFile' + Date.now() + '.jpg';
  const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
  photoAsset.open('rw', (err, fd) => {
    if (fd != undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error('File err' + err);
    }
  });
}
```

### open

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

> **NOTE**<br>The write operations are mutually exclusive. After a write operation is complete, you must call **close** to close the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the FD of the file opened.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202     |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('openDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    let fd: number = await photoAsset.open('rw');
    if (fd != undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error(' open File fail');
    }
  } catch (err) {
    console.error('open Demo err' + err);
  }
}
```

### getReadOnlyFd

getReadOnlyFd(callback: AsyncCallback&lt;number&gt;): void

Opens this file in read-only mode. This API uses an asynchronous callback to return the result.

> **NOTE**<br>After the read operation is complete, call **close** to close the file.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the FD of the file opened.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('getReadOnlyFdDemo');
   let testFileName: string = 'testFile' + Date.now() + '.jpg';
  const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
  photoAsset.getReadOnlyFd((err, fd) => {
    if (fd != undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error('File err' + err);
    }
  });
}
```

### getReadOnlyFd

getReadOnlyFd(): Promise&lt;number&gt;

Opens this file in read-only mode. This API uses a promise to return the result.

> **NOTE**<br>After the read operation is complete, call **close** to close the file.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the FD of the file opened.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
async function example() {
  console.info('getReadOnlyFdDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    const photoAsset: photoAccessHelper.PhotoAsset = await phAccessHelper.createAsset(testFileName);
    let fd: number = await photoAsset.getReadOnlyFd();
    if (fd != undefined) {
      console.info('File fd' + fd);
      photoAsset.close(fd);
    } else {
      console.error(' open File fail');
    }
  } catch (err) {
    console.error('open Demo err' + err);
  }
}
```

### close

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | FD of the file to close.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    const photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd: number = await photoAsset.open('rw');
    console.info('file fd', fd);
    photoAsset.close(fd, (err) => {
      if (err == undefined) {
        console.info('asset close succeed.');
      } else {
        console.error('close failed, message = ' + err);
      }
    });
  } catch (err) {
    console.error('close failed, message = ' + err);
  }
}
```

### close

close(fd: number): Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| fd   | number | Yes   | FD of the file to close.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    const asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let fd = await asset.open('rw');
    console.info('file fd', fd);
    await asset.close(fd);
    console.info('asset close succeed.');
  } catch (err) {
    console.error('close failed, message = ' + err);
  }
}
```

### getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the thumbnail of this file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail((err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size: image.Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the file thumbnail of the given size. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [image.Size](js-apis-image.md#size) | Yes   | Size of the thumbnail.           |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import image from '@ohos.multimedia.image'

async function example() {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size, (err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size?: image.Size): Promise&lt;image.PixelMap&gt;

Obtains the file thumbnail of the given size. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| size | [image.Size](js-apis-image.md#size) | No   | Size of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the PixelMap of the thumbnail.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import image from '@ohos.multimedia.image'
import { BusinessError } from '@ohos.base';

async function example() {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err: BusinessError) => {
    console.error('getThumbnail fail' + err);
  });
}
```

### setFavorite

setFavorite(favoriteState: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| favoriteState | boolean                   | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setFavorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

### setFavorite

setFavorite(favoriteState: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  console.info('setFavoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setFavorite(true).then(() => {
    console.info('setFavorite successfully');
  }).catch((err: BusinessError) => {
    console.error('setFavorite failed with error:' + err);
  });
}
```

### setHidden

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets this file to hidden state. This API uses an asynchronous callback to return the result.

Private files are stored in the private album. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| hiddenState | boolean                   | Yes   | Whether to set a file to hidden state. The value **true** means to hide the file; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setHidden(true, (err) => {
    if (err == undefined) {
      console.info('setHidden successfully');
    } else {
      console.error('setHidden failed with error:' + err);
    }
  });
}
```

### setHidden

setHidden(hiddenState: boolean): Promise&lt;void&gt;

Sets this file asset to hidden state. This API uses a promise to return the result.

Private files are stored in the private album. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  // Restore a file from a hidden album. Before the operation, ensure that the file exists in the hidden album.
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.HIDDEN);
  const album = await albumList.getFirstObject();
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error('setHidden failed with error:' + err);
  });
}
```

### getExif

getExif(): Promise&lt;string&gt;

Obtains a JSON string consisting of the EXIF tags of this JPG image. This API uses a promise to return the result.

> **NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Callback invoked to return the JSON string obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Supported EXIF tags**

For details about the EXIF tags, see [image.PropertyKey](js-apis-image.md#propertykey7).

| Key Value                                   | Description             |
| --------------------------------------- | ----------------- |
| BitsPerSample | Number of bits per pixel.|
| Orientation | Image orientation.|
| ImageLength | Image length.|
| ImageWidth | Image width.|
| GPSLatitude | GPS latitude of the image.|
| GPSLongitude | GPS longitude of the image.|
| GPSLatitudeRef | Longitude reference, for example, W or E.|
| GPSLongitudeRef | Latitude reference, for example, N or S.|
| DateTimeOriginal | Shooting time.|
| ExposureTime | Exposure time.|
| SceneType | Shooting scene type.|
| ISOSpeedRatings | ISO sensitivity or speed.|
| FNumber | f-number.|
| DateTime | Date and time when the image was last modified.|
| GPSTimeStamp | GPS timestamp.|
| GPSDateStamp | GPS date stamp.|
| ImageDescription | Image description.|
| Make | Camera vendor.|
| MakeNote | Camera vendor.|
| Model | Model.|
| PhotoMode | Photo mode.|
| SensitivityType | Sensitivity type.|
| StandardOutputSensitivity | Standard output sensitivity.|
| RecommendedExposureIndex | Recommended exposure index.|
| ApertureValue | Aperture value.|
| MeteringMode | Metering mode.|
| LightSource | Light source.|
| Flash | Flash status.|
| FocalLength | Focal length.|
| UserComment | User comment.|
| PixelXDimension | Pixel X dimension.|
| PixelYDimension | Pixel Y dimension.|
| WhiteBalance | White balance.|
| FocalLengthIn35mmFilm | Focal length in 35 mm film.|
| ExposureBiasValue | Exposure compensation.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    fetchResult.close();
  } catch (err) {
    console.error('getExifDemoCallback failed with error: ' + err);
  }
}
```

### getExif

getExif(callback: AsyncCallback&lt;string&gt;): void

Obtains a JSON string consisting of the EXIF tags of this JPG image. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [PhotoKeys.USER_COMMENT](#photokeys). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the JSON string obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Supported EXIF tags**

For details about the EXIF tags, see [image.PropertyKey](js-apis-image.md#propertykey7).

| Key Value                                   | Description             |
| --------------------------------------- | ----------------- |
| BitsPerSample | Number of bits per pixel.|
| Orientation | Image orientation.|
| ImageLength | Image length.|
| ImageWidth | Image width.|
| GPSLatitude | GPS latitude of the image.|
| GPSLongitude | GPS longitude of the image.|
| GPSLatitudeRef | Longitude reference, for example, W or E.|
| GPSLongitudeRef | Latitude reference, for example, N or S.|
| DateTimeOriginal | Shooting time.|
| ExposureTime | Exposure time.|
| SceneType | Shooting scene type.|
| ISOSpeedRatings | ISO sensitivity or speed.|
| FNumber | f-number.|
| DateTime | Date and time when the image was last modified.|
| GPSTimeStamp | GPS timestamp.|
| GPSDateStamp | GPS date stamp.|
| ImageDescription | Image description.|
| Make | Camera vendor.|
| MakeNote | Camera vendor.|
| Model | Model.|
| PhotoMode | Photo mode.|
| SensitivityType | Sensitivity type.|
| StandardOutputSensitivity | Standard output sensitivity.|
| RecommendedExposureIndex | Recommended exposure index.|
| ApertureValue | Aperture value.|
| MeteringMode | Metering mode.|
| LightSource | Light source.|
| Flash | Flash status.|
| FocalLength | Focal length.|
| UserComment | User comment.|
| PixelXDimension | Pixel X dimension.|
| PixelYDimension | Pixel Y dimension.|
| WhiteBalance | White balance.|
| FocalLengthIn35mmFilm | Focal length in 35 mm film.|
| ExposureBiasValue | Exposure compensation.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
      if (exifMessage != undefined) {
        let userComment = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
        console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
      } else {
        console.error('getExif failed, message = ', err);
      }
    });
    fetchResult.close();
  } catch (err) {
    console.error('getExifDemoCallback failed with error: ' + err);
  }
}
```

### setUserComment

setUserComment(userComment: string): Promise&lt;void&gt;

Sets user comment information of an image or video. This API uses a promise to return the result.

> **NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 140 characters.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    console.error('setUserCommentDemoCallback failed with error: ' + err);
  }
}
```

### setUserComment

setUserComment(userComment: string, callback: AsyncCallback&lt;void&gt;): void

Sets user comment information of an image or video. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 140 characters.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202        |  Called by non-system application.         |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('setUserComment failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('setUserCommentDemoCallback failed with error: ' + err);
  }
}
```

### setPending<sup>11+</sup>

setPending(pendingState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets the pending state for this image or video asset. This API uses an asynchronous callback to return the result.

The pending state can be removed only through **setPending(false)**. You can use **photoAsset.get(photoAccessHelper.PhotoKeys.PENDING)** to check whether the asset state is pending. If the asset is in pending state, **true** is returned. Otherwise, **false** is returned.

> **NOTE**<br>**setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| pendingState | boolean | Yes   | Whether to set the file to pending state. The value **true** means to set the file to pending state, and the value **false** means to remove the pending state.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
async function example() {
  try {
    console.info('setPendingCallbackDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    photoAsset.setPending(true, async (err) => {
      if (err !== undefined) {
        console.error('setPending(true) failed with error: ' + err);
        return;
      }
      // write photo buffer in fd
      photoAsset.setPending(false, async (err) => {
        if (err !== undefined) {
          console.error('setPending(false) failed with error: ' + err);
          return;
        }
        await photoAsset.close(fd);
      });
    });
  } catch (err) {
    console.error('setPendingCallbackDemo failed with error: ' + err);
  }
}
```

### setPending<sup>11+</sup>

setPending(pendingState: boolean): Promise&lt;void&gt;

Sets the pending state for this image or video asset. This API uses a promise to return the result.

The pending state can be removed only through **setPending(false)**. You can use **photoAsset.get(photoAccessHelper.PhotoKeys.PENDING)** to check whether the asset state is pending. If the asset is in pending state, **true** is returned. Otherwise, **false** is returned.

> **NOTE**<br>**setPending** can be used only during the file creation process. Once the FD is closed, **setPending(true)** cannot be used to set the pending state for the file.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
async function example() {
  try {
    console.info('setPendingPromiseDemo');
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let photoAsset = await phAccessHelper.createAsset(testFileName);
    let fd = await photoAsset.open('fd');
    await photoAsset.setPending(true);
    // write photo buffer in fd
    photoAsset.setPending(false);
    await photoAsset.close(fd);
  } catch (err) {
    console.error('setPendingPromiseDemo failed with error: ' + err);
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
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('isEdited failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('isEditedDemoCallback failed with error: ' + err);
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
|Promise&lt;boolean&gt; | Promise used to return the result.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    console.error('isEditedDemoCallback failed with error: ' + err);
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
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the edit data obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('requestEditData failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('requestEditDataCallbackDemo failed with error: ' + err);
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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    let editdata = await photoAsset.requestEditData();
    console.info('Editdata is ' + editdata);
  } catch (err) {
    console.error('requestEditDataPromiseDemo failed with error: ' + err);
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
| callback | AsyncCallback&lt;string&gt; | Yes   | Callback invoked to return the FD.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('requestSource failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('requsetSourceCallbackDemo failed with error: ' + err);
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
|Promise&lt;string&gt; | Promise used to return the FD.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    console.error('requsetSourcePromiseDemo failed with error: ' + err);
  }
}
```

### commitEditedAsset<sup>11+</sup>

commitEditedAsset(editData: string, uri: string, callback: AsyncCallback&lt;void&gt;)

Commits the edited image or video asset. This API uses an asynchronous callback to return the result.

The edited file is saved to the media library based on the URI. The URI is **FileUri** of the edited file in the application sandbox. For details, see [FileUri](./js-apis-file-fileuri.md).

> **NOTE**<br>The commit operation overwrites the previous edited data.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('requestSource failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('commitEditedAssetCallbackDemo failed with error: ' + err);
  }
}
```

### commitEditedAsset<sup>11+</sup>

commitEditedAsset(editData: string, uri: string): Promise&lt;void&gt

Commits the edited image or video asset. This API uses a promise to return the result.

The edited file is saved to the media library based on the URI. The URI is **FileUri** of the edited file in the application sandbox. For details, see [FileUri](./js-apis-file-fileuri.md).

> **NOTE**<br>The commit operation overwrites the previous edited data.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
    photoAsset.commitEditedAsset(editData, uri);
    console.info('commitEditedAsset is successful');
  } catch (err) {
    console.error('commitEditedAssetPromiseDemo failed with error: ' + err);
  }
}
```

### revertToOriginal<sup>11+</sup>

revertToOriginal(callback: AsyncCallback&lt;void&gt;)

Reverts to the state of the file before being edited. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('revertToOriginal failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('RevertToOriginalCallbackDemo failed with error: ' + err);
  }
}
```

### revertToOriginal<sup>11+</sup>

revertToOriginal(): Promise&lt;void&gt;

Reverts to the state of the file before being edited. This API uses a promise to return the result.

> **NOTE**<br>This API deletes the edited data and edited image or video asset, and the deleted data cannot be restored. Exercise caution when using this API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;string&gt; | Promise that returns no value.|


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 201   | Permission denied.        |
| 202   | Called by non-system application.         |
| 401   | if parameter is invalid.         |
| 14000011   | System inner fail.        |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('RevertToOriginalPromiseDemo')
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
    console.error('RevertToOriginalPromiseDemo failed with error: ' + err);
  }
}
```

## PhotoViewPicker

Provides APIs for selecting images and videos. Before using the APIs of **PhotoViewPicker**, you need to create a **PhotoViewPicker** instance.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Example**

```ts
let photoPicker = new photoAccessHelper.PhotoViewPicker();
```

### select

select(option?: PhotoSelectOptions) : Promise&lt;PhotoSelectResult&gt;

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses a promise to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | No  | Options for selecting files. If this parameter is not specified, images and videos are selected by default. A maximum of 50 files can be selected.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| Promise&lt;[PhotoSelectResult](#photoselectresult)&gt; | Promise return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example01() {
  try {
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    }).catch((err: BusinessError) => {
      console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(option: PhotoSelectOptions, callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result. You can pass in **PhotoSelectOptions** to specify the media file type and the maximum number of files to select.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| option | [PhotoSelectOptions](#photoselectoptions) | Yes  | Options for selecting images or videos.|
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example02() {
  try {
    let PhotoSelectOptions = new photoAccessHelper.PhotoSelectOptions();
    PhotoSelectOptions.MIMEType = photoAccessHelper.PhotoViewMIMETypes.IMAGE_TYPE;
    PhotoSelectOptions.maxSelectNumber = 5;
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select(PhotoSelectOptions, (err: BusinessError, PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

### select

select(callback: AsyncCallback&lt;PhotoSelectResult&gt;) : void

Starts a **photoPicker** page for the user to select one or more images or videos. This API uses an asynchronous callback to return the result.

> **NOTE**<br>The **photoUris** in the **PhotoSelectResult** object returned by this API can be used only by calling [photoAccessHelper.getAssets()](#getassets) with temporary authorization. For details, see [Using a Media File URI](../../file-management/user-file-uri-intro.md#using-a-media-file-uri).

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| callback | AsyncCallback&lt;[PhotoSelectResult](#photoselectresult)&gt;      | Yes  | Callback invoked to return information about the images or videos selected.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401      |  if parameter is invalid.         |
| 13900042      | Unknown error.         |

**Example**

```ts
import { BusinessError } from '@ohos.base';
async function example03() {
  try {
    let photoPicker = new photoAccessHelper.PhotoViewPicker();
    photoPicker.select((err: BusinessError, PhotoSelectResult: photoAccessHelper.PhotoSelectResult) => {
      if (err) {
        console.error('PhotoViewPicker.select failed with err: ' + JSON.stringify(err));
        return;
      }
      console.info('PhotoViewPicker.select successfully, PhotoSelectResult uri: ' + JSON.stringify(PhotoSelectResult));
    });
  } catch (error) {
    let err: BusinessError = error as BusinessError;
    console.error('PhotoViewPicker failed with err: ' + JSON.stringify(err));
  }
}
```

## FetchResult

Provides APIs to manage the file retrieval result.

### getCount

getCount(): number

Obtains the total number of files in the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Returns the total number of files obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getCountDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('fetchCount = ', fetchCount);
}
```

### isAfterLast

isAfterLast(): boolean

Checks whether the cursor is in the last row of the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type     | Description                                |
| ------- | ---------------------------------- |
| boolean | Returns **true** if the cursor is in the last row of the result set; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
  if (fetchResult.isAfterLast()) {
    console.info('photoAsset isAfterLast displayName = ', photoAsset.displayName);
  } else {
    console.info('photoAsset  not isAfterLast ');
  }
}
```

### close

close(): void

Closes this **FetchFileResult** instance to invalidate it. After this instance is closed, the APIs in this instance cannot be invoked.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fetchResultCloseDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    fetchResult.close();
    console.info('close succeed.');
  } catch (err) {
    console.error('close fail. message = ' + err);
  }
}
```

### getFirstObject

getFirstObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the first file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the first file asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  fetchResult.getFirstObject((err, photoAsset) => {
    if (photoAsset != undefined) {
      console.info('photoAsset displayName: ', photoAsset.displayName);
    } else {
      console.error('photoAsset failed with err:' + err);
    }
  });
}
```

### getFirstObject

getFirstObject(): Promise&lt;T&gt;

Obtains the first file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;T&gt; | Promise used to return the first object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getNextObject

getNextObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.
Before using this API, you must use [isAfterLast()](#isafterlast) to check whether the current position is the end of the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the next file asset.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
    fetchResult.getNextObject((err, photoAsset) => {
      if (photoAsset != undefined) {
        console.info('photoAsset displayName: ', photoAsset.displayName);
      } else {
        console.error('photoAsset failed with err: ' + err);
      }
    });
  }
}
```

### getNextObject

getNextObject(): Promise&lt;T&gt;

Obtains the next file asset in the result set. This API uses a promise to return the result.
Before using this API, you must use [isAfterLast()](#isafterlast) to check whether the current position is the end of the result set.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the next object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getNextObject();
    console.info('photoAsset displayName: ', photoAsset.displayName);
  }
}
```

### getLastObject

getLastObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the last file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                       |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the last file asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  fetchResult.getLastObject((err, photoAsset) => {
    if (photoAsset != undefined) {
      console.info('photoAsset displayName: ', photoAsset.displayName);
    } else {
      console.error('photoAsset failed with err: ' + err);
    }
  });
}
```

### getLastObject

getLastObject(): Promise&lt;T&gt;

Obtains the last file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the last object in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getLastObject();
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getObjectByPosition

getObjectByPosition(index: number, callback: AsyncCallback&lt;T&gt;): void

Obtains a file asset with the specified index in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | Yes   | Index of the file asset to obtain. The value starts from **0**.    |
| callback | AsyncCallback&lt;T&gt; | Yes   | Callback invoked to return the file asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getObjectByPositionDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  fetchResult.getObjectByPosition(0, (err, photoAsset) => {
    if (photoAsset != undefined) {
      console.info('photoAsset displayName: ', photoAsset.displayName);
    } else {
      console.error('photoAsset failed with err: ' + err);
    }
  });
}
```

### getObjectByPosition

getObjectByPosition(index: number): Promise&lt;T&gt;

Obtains a file asset with the specified index in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name   | Type    | Mandatory  | Description            |
| ----- | ------ | ---- | -------------- |
| index | number | Yes   | Index of the file asset to obtain. The value starts from **0**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the file asset obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getObjectByPositionDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getObjectByPosition(0);
  console.info('photoAsset displayName: ', photoAsset.displayName);
}
```

### getAllObjects

getAllObjects(callback: AsyncCallback&lt;Array&lt;T&gt;&gt;): void

Obtains all the file assets in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | Yes  | Callback invoked to return an array of all file assets in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  fetchResult.getAllObjects((err, photoAssetList) => {
    if (photoAssetList != undefined) {
      console.info('photoAssetList length: ', photoAssetList.length);
    } else {
      console.error('photoAssetList failed with err:' + err);
    }
  });
}
```

### getAllObjects

getAllObjects(): Promise&lt;Array&lt;T&gt;&gt;

Obtains all the file assets in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return an array of all file assets in the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
  let photoAssetList: Array<photoAccessHelper.PhotoAsset> = await fetchResult.getAllObjects();
  console.info('photoAssetList length: ', photoAssetList.length);
}
```

## Album

Provides APIs to manage albums.

### Attributes

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name          | Type   | Readable  | Writable | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| albumType | [AlbumType]( #albumtype) | Yes   | No   | Type of the album.   |
| albumSubtype | [AlbumSubtype]( #albumsubtype) | Yes   | No  | Subtype of the album.   |
| albumName | string | Yes   | Yes for a user album; no for a system album.  | Name of the album.   |
| albumUri | string | Yes   | No   | URI of the album.  |
| count | number | Yes   | No   |  Number of files in the album.|
| coverUri | string | Yes   | No   | URI of the cover file of the album.|

### getAssets

getAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;PhotoAsset&gt;&gt;): void

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the albums.|
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Yes  | Callback invoked to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetAssetsDemoCallback');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  const album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.getAssets(fetchOption, (err, albumFetchResult) => {
    if (albumFetchResult != undefined) {
      console.info('album getAssets successfully, getCount: ' + albumFetchResult.getCount());
    } else {
      console.error('album getAssets failed with error: ' + err);
    }
  });
}
```

### getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

Obtains image and video assets. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the album files.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PhotoAsset](#photoasset)&gt;&gt; | Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  console.info('albumGetAssetsDemoPromise');

  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  const album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.getAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getPhotoAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error('album getPhotoAssets failed with error: ' + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the album attributes to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  const album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify((err) => {
    if (err != undefined) {
      console.error('commitModify failed with error: ' + err);
    } else {
      console.info('commitModify successfully');
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the album attributes to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  const album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info('commitModify successfully');
  }).catch((err: BusinessError) => {
    console.error('commitModify failed with error: ' + err);
  });
}
```

### addAssets

addAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Adds image and video assets to an album. Before the operation, ensure that the image and video assets to add and the album exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image and video assets to add.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('addAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.addAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album addAssets successfully');
      } else {
        console.error('album addAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('addAssetsDemoCallback failed with error: ' + err);
  }
}
```

### addAssets

addAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Adds image and video assets to an album. Before the operation, ensure that the image and video assets to add and the album exist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image and video assets to add.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  try {
    console.info('addAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.addAssets([asset]).then(() => {
      console.info('album addAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album addAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('addAssetsDemoPromise failed with error: ' + err);
  }
}
```

### removeAssets

removeAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Removes image and video assets from an album. The album and file resources must exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image and video assets to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('removeAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.removeAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album removeAssets successfully');
      } else {
        console.error('album removeAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('removeAssetsDemoCallback failed with error: ' + err);
  }
}
```

### removeAssets

removeAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Removes image and video assets from an album. The album and file resources must exist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image and video assets to remove.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401       |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

async function example() {
  try {
    console.info('removeAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: photoAccessHelper.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOption);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    album.removeAssets([asset]).then(() => {
      console.info('album removeAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album removeAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('removeAssetsDemoPromise failed with error: ' + err);
  }
}
```

### recoverAssets

recoverAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Recovers image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to recover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('album recoverAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('recoverAssetsDemoCallback failed with error: ' + err);
  }
}
```

### recoverAssets

recoverAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Recovers image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses a promise to return the result.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

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
      console.error('album recoverAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('recoverAssetsDemoPromise failed with error: ' + err);
  }
}
```

### deleteAssets

deleteAssets(assets: Array&lt;PhotoAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses an asynchronous callback to return the result.

**CAUTION**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[PhotoAsset](#photoasset)&gt; | Yes  | Array of the image or video assets to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('album deleteAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('deleteAssetsDemoCallback failed with error: ' + err);
  }
}
```

### deleteAssets

deleteAssets(assets: Array&lt;PhotoAsset&gt;): Promise&lt;void&gt;

Deletes image or video assets from the trash. Before the operation, ensure that the image or video assets exist in the trash. This API uses a promise to return the result.

**CAUTION**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from '@ohos.base';

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
      console.error('album deleteAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('deleteAssetsDemoPromise failed with error: ' + err);
  }
}
```

### setCoverUri

setCoverUri(uri: string, callback: AsyncCallback&lt;void&gt;): void

Sets the album cover. This API uses an asynchronous callback to return the result.

> **NOTE**<br>This API can be used to set the user album cover, but not the system album cover.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to be set as the album cover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('album setCoverUri failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('setCoverUriDemoCallback failed with error: ' + err);
  }
}
```

### setCoverUri

setCoverUri(uri: string): Promise&lt;void&gt;

Sets the album cover. This API uses a promise to return the result.

> **NOTE**<br>This API can be used to set the user album cover, but not the system album cover.

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

For details about the error codes, see [Universal Error Codes](../errorcodes/errorcode-universal.md) and [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202      |  Called by non-system application.         |
| 401      |  if parameter is invalid.         |
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |
**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

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
        console.error('album setCoverUri failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('setCoverUriDemoCallback failed with error: ' + err);
  }
}
```

## MemberType

Enumerates the member types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Type|  Readable |  Writable |  Description |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | Yes| Yes| The member is a number.|
| string |  string | Yes| Yes| The member is a string.|
| boolean |  boolean | Yes| Yes| The member is a Boolean value.|

## PhotoType

Enumerates media file types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| IMAGE |  1 |  Image.|
| VIDEO |  2 |  Video.|

## PhotoSubtype

Enumerates the [PhotoAsset](#photoasset) types.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Default (photo) type.|
| SCREENSHOT |  1 |  Screenshot and screen recording file.|

## PositionType

Enumerates the file locations.

**System API**: This is a system API.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| LOCAL |  1 << 0 |  Stored only on a local device.|
| CLOUD |  1 << 1 |  Stored only on the cloud.|

## AlbumType

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| USER |  0 |  User album.|
| SYSTEM |  1024 |  System album.|

## AlbumSubtype

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| USER_GENERIC |  1 |  User album.|
| FAVORITE |  1025 |  Favorites.|
| VIDEO |  1026 |  Video album.|
| HIDDEN |  1027 |  Hidden album.<br>**System API**: This is a system API.|
| TRASH |  1028 |  Trash.<br>**System API**: This is a system API.|
| SCREENSHOT |  1029 |  Album for screenshots and screen recording files.<br>**System API**: This is a system API.|
| CAMERA |  1030 |  Album for photos and videos taken by the camera.<br>**System API**: This is a system API.|
| IMAGE<sup>11+</sup> |  1031 | Album for images.<br>**System API**: This is a system API.|
| ANY |  2147483647 |  Any album.|

## PhotoKeys

Defines the key information about an image or video file.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | URI of the file.                                                  |
| PHOTO_TYPE    | 'media_type'           | Type of the file.                                             |
| DISPLAY_NAME  | 'display_name'        | File name displayed.                                                  |
| SIZE          | 'size'                | File size.                                                  |
| DATE_ADDED    | 'date_added'          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).            |
| DATE_MODIFIED | 'date_modified'       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| DURATION      | 'duration'            | Duration, in ms.                                   |
| WIDTH         | 'width'               | Image width, in pixels.                                   |
| HEIGHT        | 'height'              | Image height, in pixels.                                     |
| DATE_TAKEN    | 'date_taken'          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.               |
| ORIENTATION   | 'orientation'         | Orientation of the image file.                                            |
| FAVORITE      | 'is_favorite'            | Whether the file is added to favorites.                                                   |
| TITLE         | 'title'               | Title in the file.                                                  |
| POSITION  | 'position'            | File location type.<br>**System API**: This is a system API.                              |
| DATE_TRASHED  | 'date_trashed'  | Date when the file was deleted. The value is the number of seconds elapsed since the Epoch time. **System API**: This is a system API.                |
| HIDDEN  | 'hidden'            | Whether the file is hidden.<br>**System API**: This is a system API.                              |
| CAMERA_SHOT_KEY  | 'camera_shot_key'  | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.)<br>**System API**: This is a system API.           |
| USER_COMMENT<sup>10+</sup>  | 'user_comment'            | User comment information.<br>**System API**: This is a system API.          |
| DATE_YEAR<sup>11+</sup>  | 'date_year'            | Year when the file was created.<br>**System API**: This is a system API.          |
| DATE_MONTH<sup>11+</sup>  | 'date_month'            | Month when the file was created.<br>**System API**: This is a system API.          |
| DATE_DAY<sup>11+</sup>  | 'date_day'            | Date when the file was created.<br>**System API**: This is a system API.          |
| PENDING<sup>11+</sup>  | 'pending'            | Pending state.<br>**System API**: This is a system API.          |

## AlbumKeys

Enumerates the key album attributes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | 'uri'                 | URI of the album.                                                  |
| ALBUM_NAME    | 'album_name'          | Name of the album.                                                  |

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

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| subtype           | [PhotoSubtype](#photosubtype) | No | Subtype of the image or video. |
| cameraShotKey           | string | No | Key for the Ultra Snapshot feature, which allows the camera to take photos or record videos with the screen off. (This parameter is available only for the system camera, and the key value is defined by the system camera.)  |

## CreateOptions

Defines the options for creating an image or video asset.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| title           | string | No | Title of the image or video. |

## FetchOptions

Defines the options for fetching media files.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                  | Type               | Readable| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | Yes  | Yes  | Options for fetching files based on the attributes in columns.<br>If this parameter is left empty, files are fetched by URI, name, and type (the specific field names vary with the file asset or album object) by default. In addition, an error will be reported if [get](#get) is called to obtain other attributes of this object.<br>Example: fetchColumns: ['uri', 'title']|
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## ChangeData

Defines the return value of the listener callback.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name   | Type                       | Readable| Writable| Description                                                        |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](#notifytype) | Yes  | No  | Notification type.                                      |
| uris    | Array&lt;string&gt;         | Yes  | No  | All URIs with the same [NotifyType](#notifytype), which can be **PhotoAsset** or **Album**.|
| extraUris | Array&lt;string&gt;         | Yes  | No  | URIs of the changed files in the album.                                   |

## NotifyType

Enumerates the notification event types.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_ADD                | 0    | A file asset or album is added.    |
| NOTIFY_UPDATE             | 1    | A file asset or album is updated.    |
| NOTIFY_REMOVE             | 2    | A file asset or album is removed.    |
| NOTIFY_ALBUM_ADD_ASSET    | 3    | A file asset is added to the album.|
| NOTIFY_ALBUM_REMOVE_ASSET | 4    | A file asset is removed from the album.|

## DefaultChangeUri

Enumerates the **DefaultChangeUri** subtypes.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name             | Value                     | Description                                                        |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_PHOTO_URI | 'file://media/Photo'      | Default **PhotoAsset** URI, which must be used with **forChildUris{true}** to subscribe to change notifications of all photo assets.|
| DEFAULT_ALBUM_URI | 'file://media/PhotoAlbum' | Default album URI, which must be used with **forChildUris{true}** to subscribe to change notifications of all albums.|
| DEFAULT_HIDDEN_ALBUM_URI<sup>11+</sup>  | 'file://media/HiddenAlbum' | URI of an album in the hidden albums that are displayed by album, that is, the URI of an album with hidden files. Such albums do not include the preset hidden album and the albums in the trash. This URI is used to subscribe to the change notifications of the hidden albums displayed by album. **System API**: This is a system API.|

## PhotoViewMIMETypes

Enumerates the media file types that can be selected.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| IMAGE_TYPE  |  'image/*' | Image.|
| VIDEO_TYPE |  'video/*' | Video.|
| IMAGE_VIDEO_TYPE |  '\*/*' | Image and video.|

## PhotoSelectOptions

Defines the options for selecting images or videos.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Mandatory| Description                         |
| ----------------------- | ------------------- | ---- | -------------------------------- |
| MIMEType              | [PhotoViewMIMETypes](#photoviewmimetypes)   | No  | Available media file types. **IMAGE_VIDEO_TYPE** is used by default.|
| maxSelectNumber       | number | No  | Maximum number of media files that can be selected. The default value is **50**, and the maximum value is **500**.     |
| isPhotoTakingSupported<sup>11+</sup> | boolean  | No  | Whether photo taking is supported.|
| isEditSupported<sup>11+</sup>       | boolean | No  | Whether the photo is editable.     |

## PhotoSelectResult

Defines information about the images or videos selected.

**System capability**: SystemCapability.FileManagement.PhotoAccessHelper.Core

| Name                   | Type               | Readable| Writable| Description                          |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------ |
| photoUris        | Array&lt;string&gt;    | Yes  | Yes  | URIs of the images or videos selected. The URI array can be used only by calling [photoAccessHelper.getAssets](#getassets) with temporary authorization. For details about how to use the media file URI, see [Using a Media File URI] (../../file-management/user-file-uri-intro.md#using-a-media-file-uri).|
| isOriginalPhoto        | boolean    | Yes  | Yes  | Whether the selected media asset is the original image.|
