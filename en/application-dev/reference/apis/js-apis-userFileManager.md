# @ohos.filemanagement.userFileManager (User Data Management)

The **userFileManager** module provides user data management capabilities, including accessing and modifying user media data (audio and video clips, images, and files).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.

## Modules to Import

```ts
import userFileManager from '@ohos.filemanagement.userFileManager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

Obtains a **UserFileManager** instance. This instance can be used to access and modify user media data (such as audio and video clips, images, and files).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](js-apis-inner-app-context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | **UserFileManager** instance obtained.|

**Example**

```ts
// The userFileManager instance obtained is a global object. It is used by default in subsequent operations. If the code snippet is not added, an error will be reported indicating that mgr is not defined.
const context = getContext(this);
let mgr = userFileManager.getUserFileMgr(context);
```

## UserFileManager

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the image and video assets.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback invoked to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName : ' + fileAsset.displayName);
      }
    } else {
      console.error('fetchResult fail' + err);
    }
  });
}
```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

Obtains image and video assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name | Type               | Mandatory| Description            |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](#fetchoptions)   | Yes  | Options for fetching the image and video assets.    |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getPhotoAssets failed, message = ', err);
  }
}
```
### createPhotoAsset

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

Creates an image or video asset with the specified file name and URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| albumUri  | string        | Yes  | URI of the album where the image or video is located.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('createPhotoAssetDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    predicates: predicates
  };
  let albums = await mgr.getPhotoAlbums(fetchOptions);
  let album = await albums.getFirstObject();
  let testFileName = 'testFile' + Date.now() + '.jpg';
  mgr.createPhotoAsset(testFileName, album.albumUri, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

Creates an image or video asset with the specified file name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.jpg';
  mgr.createPhotoAsset(testFileName, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, albumUri?: string): Promise&lt;FileAsset&gt;;

Creates an image or video asset with the specified file name and URI. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| albumUri  | string        | No  | URI of the album where the image or video is located.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the created image and video asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback&lt;FileAsset&gt;): void;

Creates an image or video asset with the specified file name and options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| createOption  | [PhotoCreateOptions](#photocreateoptions10)        | Yes  | Options for creating an image or video asset.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.jpg';
  let createOption = {
    subType: userFileManager.PhotoSubType.DEFAULT
  }
  mgr.createPhotoAsset(testFileName, createOption, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise&lt;FileAsset&gt;;

Creates an image or video asset with the specified file name and options. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| createOption  |  [PhotoCreateOptions](#photocreateoptions10)       | Yes  | Options for creating an image or video asset.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the created image and video asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let createOption = {
      subType: userFileManager.PhotoSubType.DEFAULT
    }
    let fileAsset = await mgr.createPhotoAsset(testFileName, createOption);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

Creates an audio asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the audio asset to create.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the created audio asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

```ts
async function example() {
  console.info('createAudioAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.mp3';
  mgr.createAudioAsset(testFileName, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createAudioAsset file displayName' + fileAsset.displayName);
      console.info('createAudioAsset successfully');
    } else {
      console.error('createAudioAsset failed, message = ', err);
    }
  });
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string): Promise&lt;FileAsset&gt;;

Creates an audio asset. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the audio asset to create.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the created audio asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**Example**

```ts
async function example() {
  console.info('createAudioAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.mp3';
    let fileAsset = await mgr.createAudioAsset(testFileName);
    console.info('createAudioAsset file displayName' + fileAsset.displayName);
    console.info('createAudioAsset successfully');
  } catch (err) {
    console.error('createAudioAsset failed, message = ', err);
  }
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;


Obtains image and video albums. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | Yes  | Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the image and video albums obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };

  mgr.getPhotoAlbums(albumFetchOptions, (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('albums.count = ' + fetchResult.getCount());
      fetchResult.getFirstObject((err, album) => {
        if (album != undefined) {
          console.info('first album.albumName = ' + album.albumName);
        } else {
          console.error('album is undefined, err = ', err);
        }
      });
    } else {
      console.error('getPhotoAlbums fail, message = ', err);
    }
  });
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;;

Obtains image and video albums. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | Yes  | Options for fetching the albums.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the image and video albums obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAlbums(albumFetchOptions);
    console.info('album.count = ' + fetchResult.getCount());
    const album = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + album.albumName);
  } catch (err) {
    console.error('getPhotoAlbums fail, message = ' + err);
  }
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void;

Creates an album. This API uses an asynchronous callback to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br>.. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |
| callback |  AsyncCallback&lt;[Album](#album)&gt; | Yes  | Callback invoked to return the created album instance.|

**Example**

```ts
async function example() {
  console.info('createAlbumDemo');
  let albumName = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName, (err, album) => {
    if (err) {
      console.error('createAlbumCallback failed with err: ' + err);
      return;
    }
    console.info('createAlbumCallback successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  });
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string): Promise&lt;Album&gt;;

Creates an album. This API uses a promise to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br>.. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[Album](#album)&gt; | Promise used to return the created album instance.|

**Example**

```ts
async function example() {
  console.info('createAlbumDemo');
  let albumName = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err) => {
    console.error('createAlbumPromise failed with err: ' + err);
  });
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void;

Deletes albums. This API uses an asynchronous callback to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  | Array&lt;[Album](#album)&gt;         | Yes  | Albums to delete.             |
| callback |  AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album], (err) => {
    if (err) {
      console.error('deletePhotoAlbumsCallback failed with err: ' + err);
      return;
    }
    console.info('deletePhotoAlbumsCallback successfully');
  });
  fetchResult.close();
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;;

Deletes albums. This API uses a promise to return the result.

Ensure that the albums to be deleted exist. Only user albums can be deleted.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  |  Array&lt;[Album](#album)&gt;          | Yes  | Albums to delete.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album]).then(() => {
    console.info('deletePhotoAlbumsPromise successfully');
    }).catch((err) => {
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);
  });
  fetchResult.close();
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;

Obtain albums based on the specified options and album type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | Yes  | Type of the album to obtain.             |
| subType  | [AlbumSubType](#albumsubtype10)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](#fetchoptions)         | Yes  |  Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions, async (err, fetchResult) => {
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

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;

Obtains albums by type. This API uses an asynchronous callback to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | Yes  | Type of the album to obtain.             |
| subType  | [AlbumSubType](#albumsubtype10)         | Yes  | Subtype of the album.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

```ts
async function example() {
  // Obtain the system album VIDEO, which is preset by default.
  console.info('getAlbumsDemo');
  mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.VIDEO, async (err, fetchResult) => {
    if (err) {
      console.error('getAlbumsCallback failed with err: ' + err);
      return;
    }
    if (fetchResult == undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;;

Obtain albums based on the specified options and album type. This API uses a promise to return the result.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | Yes  | Type of the album to obtain.             |
| subType  | [AlbumSubType](#albumsubtype10)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](#fetchoptions)         | No  |  Options for fetching the albums. If this parameter is not specified, the albums are obtained based on the album type by default.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult == undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err) => {
    console.error('getAlbumsPromise failed with err: ' + err);
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void;

Obtains the system album. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | Yes  | Type of the system album to obtain.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Yes  | Callback invoked to return the album obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**Example**

```ts
async function example() {
  console.info('getPrivateAlbumDemo');
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      let trashAlbum = await fetchResult.getFirstObject();
      console.info('first album.albumName = ' + trashAlbum.albumName);
    } else {
      console.error('getPrivateAlbum failed. message = ', err);
    }
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType): Promise&lt;FetchResult&lt;PrivateAlbum&gt;&gt;;

Obtains the system album. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | Yes  | Type of the system album to obtain.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Promise used to return the system album obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**Example**

```ts
async function example() {
  console.info('getPrivateAlbumDemo');
  try {
    let fetchResult = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
    let trashAlbum = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + trashAlbum.albumName);
  } catch (err) {
    console.error('getPrivateAlbum failed. message = ', err);
  }
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

Obtains audio assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the audio assets.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback invoked to return the audio assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAudioAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getAudioAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    } else {
      console.error('fetchFileResult fail' + err);
    }
  });
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;


Obtains audio assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the audio assets.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise used to return the audio assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAudioAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    var fetchResult = await mgr.getAudioAssets(fetchOptions);
  } catch (err) {
    console.error('getAudioAssets failed, message = ', err);
  }

  if (fetchResult != undefined) {
    console.info('fetchFileResult success');
    let fileAsset = await fetchResult.getFirstObject();
    if (fileAsset != undefined) {
      console.info('fileAsset.displayName :' + fileAsset.displayName);
    }
  }
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void;

Deletes a media file. This API uses an asynchronous callback to return the result. The deleted file is moved to the recycle bin.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the media file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteAssetDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err);
  }

  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  mgr.delete(asset.uri, (err) => {
    if (err == undefined) {
      console.info('delete successfully');
    } else {
      console.error('delete failed with error: ' + err);
    }
  });
}
```

### delete

delete(uri: string): Promise&lt;void&gt;;

Deletes a media file. This API uses a promise to return the result. The deleted file is moved to the recycle bin.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the media file.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err);
  }

  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  try {
    await mgr.delete(asset.uri);
    console.info('delete successfully');
  } catch (err) {
    console.error('delete failed with error: ' + err);
  }
}
```

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

Subscribes to changes of the file management library. This API uses a callback to return the result.

This API will be deprecated. Use [on<sup>10+</sup>](#on10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | Yes  | Type of event to subscribe to.<br>**deviceChange** indicates the device change.<br>**albumChange** indicates the album change.<br>**imageChange** indicates the image change.<br>**audioChange** indicates the audio file change.<br>**videoChange** indicates the video file change.<br>**remoteFileChange** indicates the file change on the registered device.|
| callback | Callback&lt;void&gt; | Yes  | Callback that returns no value.                                                  |

**Example**

```ts
async function example() {
  console.info('onDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // Image file changed. Do something.
  });
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  // Sleep 1s.
  if (count > 0) {
    console.info('onDemo success');
  } else {
    console.error('onDemo fail');
  }
  mgr.off('imageChange', () => {
    // Unsubscription succeeds.
  });
}
```

### off

off(type: ChangeEvent, callback?: Callback&lt;void&gt;): void

Unsubscribes from changes of the file management library. This API uses a callback to return the result.

This API will be deprecated. Use [off<sup>10+</sup>](#off10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | Yes  | Type of event to subscribe to.<br>**deviceChange** indicates the device change.<br>**albumChange** indicates the album change.<br>**imageChange** indicates the image change.<br>**audioChange** indicates the audio file change.<br>**videoChange** indicates the video file change.<br>**remoteFileChange** indicates the change of the file on a registered device.|
| callback | Callback&lt;void&gt; | No  | Callback that returns no value.                                                  |

**Example**

```ts
async function example() {
  console.info('offDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // Image file changed. Do something.
  });

  mgr.off('imageChange', () => {
    // Unsubscription succeeds.
  });

  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  // Sleep 1s.
  if (count == 0) {
    console.info('offDemo success');
  } else {
    console.error('offDemo fail');
  }
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback invoked to return a list of online peer devices.|

**Example**

```ts
async function example() {
  console.info('getActivePeersDemo');
  mgr.getActivePeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.log('getActivePeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('getActivePeers failed. message = ', err);
    }
  });
}
```

### getActivePeers

getActivePeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

Obtains information about online peer devices. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return a list of online peer devices.|

**Example**

```ts
async function example() {
  console.info('getActivePeersDemo');
  try {
    var devicesInfo = await mgr.getActivePeers();
  } catch (err) {
    console.error('getActivePeers failed. message = ', err);
  }
  if (devicesInfo != undefined) {
    console.log('getActivePeers succeed.');
    for (let i = 0; i < devicesInfo.length; i++) {
      console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
    }
  } else {
    console.error('get distributed fail');
  }
}
```

### getAllPeers

getAllPeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

Obtains information about all peer devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback invoked to return the information obtained.|

**Example**

```ts
async function example() {
  console.info('getAllPeersDemo');
  mgr.getAllPeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.log('getAllPeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('getAllPeers failed. message = ', err);
    }
  });
}
```

### getAllPeers

getAllPeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

Obtains information about all peer devices. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return the information obtained.|

**Example**

```ts
async function example() {
  console.info('getAllPeersDemo');
  try {
    var devicesInfo = await mgr.getAllPeers();
  } catch (err) {
    console.error('getAllPeers failed. message = ', err);
  }
  if (devicesInfo != undefined) {
    console.log('getAllPeers succeed.');
    for (let i = 0; i < devicesInfo.length; i++) {
      console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
    }
  } else {
    console.error('get distributed fail');
  }
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

Releases this **UserFileManager** instance. This API uses an asynchronous callback to return the result.
Call this API when the APIs in the **UserFileManager** instance are no longer used.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Example**

```ts
async function example() {
  console.info('releaseDemo');
  mgr.release((err) => {
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

Releases this **UserFileManager** instance. This API uses a promise to return the result.
Call this API when the APIs in the **UserFileManager** instance are no longer used.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
async function example() {
  console.info('releaseDemo');
  try {
    await mgr.release();
    console.info('release ok.');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### on<sup>10+</sup>

on(uri: string, forSubUri: boolean, callback: Callback&lt;ChangeData&gt;) : void

Enables listening for the specified URI. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type                                       | Mandatory| Description                                                        |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | Yes  | URI of the file asset or album, or [DefaultChangeUri](#defaultchangeuri10).|
| forSubUri | boolean                                     | Yes  | Whether to perform fuzzy listening.<br>If **uri** is the URI of an album, the value **true** means to listen for the changes of the files in the album; the value **false** means to listen for the changes of the album. <br>If **uri** is the URI of a file asset, there is no difference between **true** and **false** for **forSubUri**.<br>If **uri** is **DefaultChangeUri**, **forSubUri** must be set to **true**. If **forSubUri** is **false**, the URI cannot be found and no message can be received.|
| callback  | Callback&lt;[ChangeData](#changedata10)&gt; | Yes  | Callback invoked to return [ChangeData](#changedata10). <br>**NOTE**: Different callbacks can be registered for a URI. You can use [off<sup>10+</sup>](#off10) to disable the specified callback or all callbacks for the URI.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('onDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  let onCallback2 = (changeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    // File changed. Do something.
  }
  // Register onCallback1.
  mgr.on(fileAsset.uri, false, onCallback1); 
  // Register onCallback2.
  mgr.on(fileAsset.uri, false, onCallback2);

  fileAsset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

### off<sup>10+</sup>

 off(uri: string, callback?: Callback&lt;ChangeData&gt;): void

Disables listening for the specified URI. Multiple callbacks can be registered for a URI for listening. You can use **off()** to disable the listening of the specified callbacks or all callbacks.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | Yes  | URI of the file asset or album, or [DefaultChangeUri](#defaultchangeuri10).|
| callback | Callback&lt;[ChangeData](#changedata10)&gt; | No  | Callback registered by [on<sup>10+</sup>](#on10). If this parameter is not specified, all callbacks registered for the URI will be unregistered. <br>**NOTE**: The specified callback will not be invoked.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('offDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData) => {
    console.info('onCallback2 on');
  }
  // Register onCallback1.
  mgr.on(fileAsset.uri, false, onCallback1);
  // Register onCallback2.
  mgr.on(fileAsset.uri, false, onCallback2);
  // Disable the listening of onCallback1.
  mgr.off(fileAsset.uri, onCallback1);
  fileAsset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

## FileAsset

Provides APIs for encapsulating file asset attributes.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | Yes  | No  | File asset URI, for example, **file://media/image/2**.        |
| fileType   | [FileType](#filetype) | Yes  | No  | Type of the file.                                              |
| displayName               | string                   | Yes  | Yes  | File name, including the file name extension, to display.                                |

### get

get(member: string): MemberType;

Obtains the value of a **FileAsset** parameter.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Name of the parameter, for example, **ImageVideoKey.URI**.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetGetDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let title = userFileManager.ImageVideoKey.TITLE;
    let fileAssetTitle = fileAsset.get(title.toString());
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void;

Sets a **FileAsset** parameter.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Name of the parameter, for example, **ImageVideoKey.URI**.|
| value | string | Yes   | Value to set. Only the value of **ImageVideoKey.DISPLAY_NAME** can be changed.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetSetDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
    fileAsset.set(displayName, 'newDisplayName1');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the file metadata to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  fileAsset.set(displayName, 'newDisplayName2');
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let newFileAssetDisplayName = fileAsset.get(displayName);
      console.info('fileAsset get newFileAssetDisplayName = ', newFileAssetDisplayName);
    } else {
      console.error('commitModify failed, message =', err);
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the file metadata to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example** 

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  fileAsset.set(displayName, 'newDisplayName3');
  try {
    await fileAsset.commitModify();
    let newFileAssetDisplayName = fileAsset.get(displayName);
    console.info('fileAsset get newFileAssetDisplayName = ', newFileAssetDisplayName);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

**NOTE**<br>The write operations are mutually exclusive. After a write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, ohos.permission.WRITE_IMAGEVIDEO, or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the file descriptor of the file opened.                           |

**Example**

```ts
async function example() {
  console.info('openDemo');
   let testFileName = 'testFile' + Date.now() + '.jpg';
  const fileAsset = await mgr.createPhotoAsset(testFileName);
  fileAsset.open('rw', (err, fd) => {
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd);
    } else {
      console.error('File err' + err);
    }
  });
}
```

### open

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

**NOTE**<br>The write operations are mutually exclusive. After a write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, ohos.permission.WRITE_IMAGEVIDEO, or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the file descriptor of the file opened.|

**Example**

```ts
async function example() {
  console.info('openDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    const fileAsset = await mgr.createPhotoAsset(testFileName);
    let fd = await fileAsset.open('rw');
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd);
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

Closes a file asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | File descriptor of the file to close.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    const fileAsset = await fetchResult.getFirstObject();
    let fd = await fileAsset.open('rw');
    console.info('file fd', fd);
    fileAsset.close(fd, (err) => {
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

Closes a file asset. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| fd   | number | Yes   | File descriptor of the file to close.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    const asset = await fetchResult.getFirstObject();
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

Obtains the thumbnail of this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
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

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [image.Size](js-apis-image.md#size) | Yes   | Size of the thumbnail.           |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
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

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| size | [image.Size](js-apis-image.md#size) | No   | Size of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the PixelMap of the thumbnail.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err) => {
    console.error('getThumbnail fail' + err);
  });
}
```

### favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

### favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| isFavorite | boolean | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.favorite(true).then(function () {
    console.info('favorite successfully');
  }).catch(function (err) {
    console.error('favorite failed with error:' + err);
  });
}
```

### setHidden<sup>10+</sup>

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets this file asset to hidden state. This API uses an asynchronous callback to return the result.

The private files set to hidden state are located in the private album (in hidden state) and are not open to third-party applications. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| hiddenState | boolean                   | Yes   | Whether to set a file to hidden state. The value **true** means to hide the file; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md) and [Universal Error Codes](../errorcodes/errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('setHiddenDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
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

### setHidden<sup>10+</sup>

setHidden(hiddenState: boolean): Promise&lt;void&gt;

Sets this file asset to hidden state. This API uses a promise to return the result.

The private files set to hidden state are located in the private album (in hidden state) and are not open to third-party applications. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | Yes   | Whether to set a file to hidden state. The value **true** means to hide the file; the value **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md) and [Universal Error Codes](../errorcodes/errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // Restore a file from a hidden album. Before the operation, ensure that the file exists in the hidden album.
  console.info('setHiddenDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.HIDDEN);
  const album = await albumList.getFirstObject();
  let fetchResult = await album.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err) => {
    console.error('setHidden failed with error:' + err);
  });
}
```

## FetchResult

Provides APIs to manage the file retrieval result.

### getCount

getCount(): number

Obtains the total number of files in the result set.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Returns the total number of files obtained.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getCountDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('fetchCount = ', fetchCount);
}
```

### isAfterLast

isAfterLast(): boolean

Checks whether the cursor is in the last row of the result set.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type     | Description                                |
| ------- | ---------------------------------- |
| boolean | Returns **true** if the cursor is in the last row of the result set; returns **false** otherwise.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let fileAsset = await fetchResult.getLastObject();
  if (fetchResult.isAfterLast()) {
    console.info('fileAsset isAfterLast displayName = ', fileAsset.displayName);
  } else {
    console.info('fileAsset  not isAfterLast ');
  }
}
```

### close

close(): void

Releases and invalidates this **FetchFileResult** instance. After this instance is released, the APIs in this instance cannot be invoked.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fetchResultCloseDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    await fetchResult.close();
    console.info('close succeed.');
  } catch (err) {
    console.error('close fail. message = ' + err);
  }
}
```

### getFirstObject

getFirstObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the first file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the first file asset.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getFirstObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err:' + err);
    }
  });
}
```

### getFirstObject

getFirstObject(): Promise&lt;T&gt;

Obtains the first file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;T&gt; | Promise used to return the first object in the result set.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getNextObject

 getNextObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the next file asset.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (fetchResult.isAfterLast()) {
    fetchResult.getNextObject((err, fileAsset) => {
      if (fileAsset != undefined) {
        console.info('fileAsset displayName: ', fileAsset.displayName);
      } else {
        console.error('fileAsset failed with err: ' + err);
      }
    });
  }
}
```

### getNextObject

 getNextObject(): Promise&lt;T&gt;

Obtains the next file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the next object in the result set.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (fetchResult.isAfterLast()) {
    let fileAsset = await fetchResult.getNextObject();
    console.info('fileAsset displayName: ', fileAsset.displayName);
  }
}
```

### getLastObject

getLastObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the last file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                       |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback invoked to return the last file asset obtained.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getLastObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err: ' + err);
    }
  });
}
```

### getLastObject

getLastObject(): Promise&lt;T&gt;

Obtains the last file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the last object in the result set.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getLastObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getPositionObject

getPositionObject(index: number, callback: AsyncCallback&lt;T&gt;): void

Obtains a file asset with the specified index in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | Yes   | Index of the file asset to obtain. The value starts from **0**.    |
| callback | AsyncCallback&lt;T&gt; | Yes   | Callback invoked to return the file asset obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getPositionObject(0, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err: ' + err);
    }
  });
}
```

### getPositionObject

getPositionObject(index: number): Promise&lt;T&gt;

Obtains a file asset with the specified index in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description            |
| ----- | ------ | ---- | -------------- |
| index | number | Yes   | Index of the file asset to obtain. The value starts from **0**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the file asset obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getPositionObject(0);
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getAllObject<sup>10+</sup>

getAllObject(callback: AsyncCallback&lt;Array&lt;T&gt;&gt;): void

Obtains all the file assets in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | Yes  | Callback invoked to return an array of all file assets in the result set.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getAllObject((err, fileAssetList) => {
    if (fileAssetList != undefined) {
      console.info('fileAssetList length: ', fileAssetList.length);
    } else {
      console.error('fileAssetList failed with err:' + err);
    }
  });
}
```

### getAllObject<sup>10+</sup>

getAllObject(): Promise&lt;Array&lt;T&gt;&gt;

Obtains all the file assets in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;Array&lt;T&gt;&gt; | Promise used to return an array of all file assets in the result set.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAssetList = await fetchResult.getAllObject();
  console.info('fileAssetList length: ', fileAssetList.length);
}
```

## Album

Provides APIs to manage albums.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Readable  | Writable | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| albumType<sup>10+</sup> | [AlbumType]( #albumtype10) | Yes   | No   | Type of the album.   |
| albumSubType<sup>10+</sup> | [AlbumSubType]( #albumsubtype10) | Yes   | No  | Subtype of the album.   |
| albumName | string | Yes   | Yes for a user album; no for a system album.  | Name of the album.   |
| albumUri | string | Yes   | No   | URI of the album.  |
| count | number | Yes   | No   |  Number of files in the album.|
| coverUri | string | Yes   | Yes for a user album; no for a system album.    | URI of the cover file of the album.|

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the image and video assets.|
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback invoked to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoCallback');

  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption, (err, albumFetchResult) => {
    if (albumFetchResult != undefined) {
      console.info('album getPhotoAssets successfully, getCount: ' + albumFetchResult.getCount());
    } else {
      console.error('album getPhotoAssets failed with error: ' + err);
    }
  });
}
```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

Obtains image and video assets. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the image and video assets.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoPromise');

  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getFileAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err) => {
    console.error('album getFileAssets failed with error: ' + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

Commits the modification on the album attributes to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
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

commitModify(): Promise&lt;void&gt;;

Commits the modification on the album attributes to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  try {
    var albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  } catch (err) {
    console.error('getPhotoAlbums failed. message = ', err);
  }
  const album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info('commitModify successfully');
  }).catch((err) => {
    console.error('commitModify failed with error: ' + err);
  });
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

Adds image and video assets to an album. Before the operation, ensure that the image and video assets to add and the album exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to add.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('addPhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album addPhotoAssets successfully');
      } else {
        console.error('album addPhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

Adds image and video assets to an album. Before the operation, ensure that the image and video assets to add and the album exist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to add.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('addPhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset]).then(() => {
      console.info('album addPhotoAssets successfully');
    }).catch((err) => {
      console.error('album addPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

Removes image and video assets from an album. The album and file resources must exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('removePhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album removePhotoAssets successfully');
      } else {
        console.error('album removePhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

Removes image and video assets from an album. The album and file resources must exist. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to remove.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('removePhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset]).then(() => {
      console.info('album removePhotoAssets successfully');
    }).catch((err) => {
      console.error('album removePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

Recovers image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to recover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('recoverPhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album recoverPhotoAssets successfully');
      } else {
        console.error('album recoverPhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

Recovers image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to recover.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('recoverPhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset]).then(() => {
      console.info('album recoverPhotoAssets successfully');
    }).catch((err) => {
      console.error('album recoverPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

Deletes image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses an asynchronous callback to return the result.

**CAUTION**: This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('deletePhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album deletePhotoAssets successfully');
      } else {
        console.error('album deletePhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

Deletes image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses a promise to return the result.

**CAUTION**: This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to delete.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('deletePhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset]).then(() => {
      console.info('album deletePhotoAssets successfully');
    }).catch((err) => {
      console.error('album deletePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

## PrivateAlbum

Provides APIs for managing the system albums.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Readable  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | Yes   | Yes   | Name of the album.   |
| albumUri | string | Yes   | No   | URI of the album.  |
| dateModified | number | Yes   | No   | Date when the album was last modified.   |
| count | number | Yes   | No   | Number of files in the album.|
| coverUri | string | Yes   | No   | URI of the cover file of the album.|

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

Obtains image and video assets from a system album. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the image and video assets.|
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback invoked to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  trashAlbum.getPhotoAssets(fetchOption, (err, fetchResult) => {
    if (fetchResult != undefined) {
      let count = fetchResult.getCount();
      console.info('fetchResult.count = ', count);
    } else {
      console.error('getFileAssets failed, message = ', err);
    }
  });
}

```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

Obtains image and video assets from a system album. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the image and video assets.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise:[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;| Promise used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](../errorcodes/errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  let count = fetchResult.getCount();
  console.info('fetchResult.count = ', count);
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void;

Deletes files from a system album.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the album.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumDeleteCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri, (err) => {
    if (err != undefined) {
      console.error('trashAlbum.delete failed, message = ', err);
    } else {
      console.info('trashAlbum.delete successfully');
    }
  });
}
```

### delete

delete(uri: string): Promise&lt;void&gt;;

Deletes files from a system album.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the album.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumDeleteDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri).then(() => {
    console.info('trashAlbum.delete successfully');
  }).catch((err) => {
    console.error('trashAlbum.delete failed, message = ', err);
  });
}   
```

### recover

recover(uri: string, callback: AsyncCallback&lt;void&gt;): void;

Recovers files in a system album.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the album.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumRecoverDemoCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let recoverFileUri = fileAsset.uri;
  trashAlbum.recover(recoverFileUri, (err) => {
    if (err != undefined) {
      console.error('trashAlbum.recover failed, message = ', err);
    } else {
      console.info('trashAlbum.recover successfully');
    }
  });
}
```

### recover

recover(uri: string): Promise&lt;void&gt;;

Recovers files in a system album.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the album.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumRecoverDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let recoverFileUri = fileAsset.uri;
  trashAlbum.recover(recoverFileUri).then(() => {
    console.info('trashAlbum.recover successfully');
  }).catch((err) => {
    console.error('trashAlbum.recover failed, message = ', err);
  });
}
```

## MemberType

Enumerates the member types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Type|  Readable |  Writable |  Description |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | Yes| Yes| The member is a number.|
| string |  string | Yes| Yes| The member is a string.|
| boolean |  boolean | Yes| Yes| The member is a Boolean value.|

## ChangeEvent

Enumerates the type of changes to observe.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Type|  Readable |  Writable |  Description|
| ----- |  ---- |  ---- |  ---- |  ---- |
| deviceChange |  string | Yes| Yes|  Device change.|
| albumChange |  string | Yes| Yes|  Album change.|
| imageChange |  string | Yes| Yes|  Image change.|
| audioChange |  string | Yes| Yes|  Audio change.|
| videoChange |  string | Yes| Yes|  Video change.|
| remoteFileChange |  string | Yes| Yes|  Remote file change.|

## PeerInfo

Defines information about a registered device.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

| Name      | Type                      | Readable| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online.        |

## FileType

Enumerates media file types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| IMAGE |  1 |  Image.|
| VIDEO |  2 |  Video.|
| AUDIO |  3 |  Audio.|

## PhotoSubType<sup>10+</sup>

Enumerates the [FileAsset](#fileasset) types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  Default (photo) type.|
| SCREENSHOT |  1 |  Screenshots and screen recording files.|
| CAMERA |  2 |  Photos and videos taken by a camera.|

## PositionType<sup>10+</sup>

Enumerates the file location.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| LOCAL |  1 |  Stored only on a local device.|
| CLOUD |  2 |  Stored only on the cloud.|
| BOTH |  3 |  Stored both on a local device and the cloud.|

## AlbumType<sup>10+</sup>

Enumerates the album types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| USER |  0 |  User album.|
| SYSTEM |  1024 |  System album.|

## AlbumSubType<sup>10+</sup>

Enumerate the album subtypes.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Value|  Description|
| ----- |  ---- |  ---- |
| USER_GENERIC |  1 |  User album.|
| FAVORITE |  1025 |  Favorites.|
| VIDEO |  1026 |  Video album.|
| HIDDEN |  1027 |  Hidden album.|
| TRASH |  1028 |  Recycle bin.|
| SCREENSHOT |  1029 |  Album for screenshots and screen recording files.|
| CAMERA |  1030 |  Album for photos and videos taken by the camera.|
| ANY |  2147483647 |  Any album.|

## PrivateAlbumType

Enumerates the system album types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name   |  Value|   Description  |
| -----   |  ----  |   ----  |
| TYPE_FAVORITE |  0 |  Favorites.|
| TYPE_TRASH |  1 |  Recycle bin.|

## AudioKey

Defines the key information about an audio file.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         |   Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | URI of the file.                                                  |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| TITLE         | title               | Title in the file.                                                  |
| ARTIST        | artist              | Author of the file.                                                  |
| AUDIOALBUM    | audio_album         | Audio album.                                                  |
| DURATION      | duration            | Duration, in ms.                                   |
| FAVORITE      | favorite            | Whether the file is added to favorites.                                                  |

## ImageVideoKey

Defines the key information about an image or video file.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | URI of the file.                                                  |
| FILE_TYPE     | file_type           | Type of the file.                                             |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| TITLE         | title               | Title of the file.                                                  |
| DURATION      | duration            | Duration, in ms.                                   |
| WIDTH         | width               | Image width, in pixels.                                   |
| HEIGHT        | height              | Image height, in pixels.                                     |
| DATE_TAKEN    | date_taken          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.               |
| ORIENTATION   | orientation         | Orientation of the image file.                                            |
| FAVORITE      | favorite            | Whether the file is added to favorites.                                                   |
| POSITION<sup>10+</sup>  | position            | File location type.                              |
| DATE_TRASHED<sup>10+</sup>  | date_trashed  | Date when the file was deleted. The value is the number of seconds between the time when the file is deleted and January 1, 1970.                |
| HIDDEN<sup>10+</sup>  | hidden            | Whether the file is hidden.                              |

## AlbumKey

Defines the key album information.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | URI of the album.                                                  |
| FILE_TYPE     | file_type           | Type of the file.                                             |
| ALBUM_NAME    | album_name          | Name of the album.                                                  |
| DATE_ADDED    | date_added          | Date when the album was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the album file content (not the album name) was last modified. The value is the number of seconds elapsed since the Epoch time.|

## PhotoCreateOptions<sup>10+</sup>

Options for creating an image or video asset.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| subType           | [PhotoSubType](#photosubtype10) | No | Subtype of the image or video. |

## FetchOptions

Defines the options for fetching media files.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Readable| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | Yes  | Yes  | Column names used for retrieval. If this parameter is left empty, the media files are fetched by URI, name, and file type by default. The specific field names are subject to the definition of the search object. Example:<br>fetchColumns: ['uri', 'title']|
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## AlbumFetchOptions

Defines the options for fetching an album.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Readable| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## ChangeData<sup>10+</sup>

Defines the return value of the listener callback.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name   | Type                       | Readable| Writable| Description                                                        |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](#notifytype10) | Yes  | No  | Notification type.                                      |
| uris    | Array&lt;string&gt;         | Yes  | No  | Array of all file asset or album URIs with the same [NotifyType](#notifytype10).|
| subUris | Array&lt;string&gt;         | Yes  | No  | URIs of the changed files in the album.                                   |

## NotifyType<sup>10+</sup>

Enumerates the notification event types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                     | Value  | Description                            |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_ADD                | 0    | A file asset or album is added.    |
| NOTIFY_UPDATE             | 1    | A file asset or album is updated.    |
| NOTIFY_REMOVE             | 2    | A file asset or album is removed.    |
| NOTIFY_ALBUM_ADD_ASSET    | 3    | A file asset is added to the album.|
| NOTIFY_ALBUM_REMOVE_ASSET | 4    | A file asset is removed from the album.|

## DefaultChangeUri<sup>10+</sup>

Enumerates the **DefaultChangeUri** subtypes.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name             | Value                     | Description                                                        |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_PHOTO_URI | file://media/Photo      | Default **PhotoAsset** URI. The **PhotoAsset** change notifications are received based on this parameter and **forSubUri{true}**.|
| DEFAULT_ALBUM_URI | file://media/PhotoAlbum | Default album URI. Album change notifications are received based on this parameter and **forSubUri{true}**. |
| DEFAULT_AUDIO_URI | file://media/Audio      | Default **AudioAsset** URI. The **AudioAsset** change notifications are received based on this parameter and **forSubUri{true}**.|
