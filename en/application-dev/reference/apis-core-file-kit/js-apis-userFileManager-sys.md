# @ohos.filemanagement.userFileManager (User Data Management) (System API)

The **userFileManager** module provides user data management capabilities, including accessing and modifying user media data.

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

Obtains a **UserFileManager** instance. This instance can be used to access and modify user media data (such as audio and video assets, images, and documents).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-app-context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | **UserFileManager** instance obtained.|

**Example**

```ts
// The userFileManager instance obtained is a global object. It is used by default in subsequent operations. If the code snippet is not added, an error will be reported indicating that mgr is not defined.
// Obtain the context from the component and ensure that the return value of this.getUiContext().getHostContext() is UIAbilityContext.
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  build() {
    Row() {
      Button("example").onClick(async () => {
        let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let mgr = userFileManager.getUserFileMgr(context);
      }).width('100%')
    }
    .height('90%')
  }
}
```

## UserFileManager

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the image and video assets.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates an image or video asset with the specified file name and URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| albumUri  | string        | Yes  | URI of the album where the image or video is located.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback used to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let albums: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(fetchOptions);
  let album: userFileManager.Album = await albums.getFirstObject();
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
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

createPhotoAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates an image or video asset with the specified file name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback used to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
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

createPhotoAsset(displayName: string, albumUri?: string): Promise&lt;FileAsset&gt;

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
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the created image or video asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates an image or video asset with the specified file name and options. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| createOption  | [PhotoCreateOptions](#photocreateoptions10)        | Yes  | Options for creating an image or video asset.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback used to return the image or video created.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.jpg';
  let createOption: userFileManager.PhotoCreateOptions = {
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

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise&lt;FileAsset&gt;

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
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the created image or video asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let createOption: userFileManager.PhotoCreateOptions = {
      subType: userFileManager.PhotoSubType.DEFAULT
    }
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName, createOption);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates an audio asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the audio asset to create.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback used to return the created audio asset.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAudioAssetDemo');
  let testFileName: string = 'testFile' + Date.now() + '.mp3';
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

createAudioAsset(displayName: string): Promise&lt;FileAsset&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAudioAssetDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.mp3';
    let fileAsset: userFileManager.FileAsset = await mgr.createAudioAsset(testFileName);
    console.info('createAudioAsset file displayName' + fileAsset.displayName);
    console.info('createAudioAsset successfully');
  } catch (err) {
    console.error('createAudioAsset failed, message = ', err);
  }
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void

Creates an album. This API uses an asynchronous callback to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]
- The album name is case-insensitive.
- Duplicate album names are not allowed.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | Yes  | Name of the album to create.             |
| callback |  AsyncCallback&lt;[Album](#album)&gt; | Yes  | Callback used to return the created album instance.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAlbumDemo');
  let albumName: string = 'newAlbumName' + new Date().getTime();
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

createAlbum(name: string): Promise&lt;Album&gt;

Creates an album. This API uses a promise to return the result.

The album name must meet the following requirements:
- The album name is a string of 1 to 255 characters.
- The album name cannot contain any of the following characters:<br> . .. \ / : * ? " ' ` < > | { } [ ]
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('createAlbumDemo');
  let albumName: string  = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err: BusinessError) => {
    console.error('createAlbumPromise failed with err: ' + err);
  });
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void

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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album: userFileManager.Album = await fetchResult.getFirstObject();
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

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;

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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // Delete the album named newAlbumName.
  console.info('deleteAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album: userFileManager.Album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album]).then(() => {
    console.info('deletePhotoAlbumsPromise successfully');
    }).catch((err: BusinessError) => {
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);
  });
  fetchResult.close();
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums based on the specified options and album type. This API uses an asynchronous callback to return the result.

This API cannot be used to obtain hidden albums. Use [getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11) to obtain hidden albums.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | Yes  | Type of the album to obtain.             |
| subType  | [AlbumSubType](#albumsubtype10)         | Yes  | Subtype of the album.             |
| options  | [FetchOptions](#fetchoptions)         | Yes  |  Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
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
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains albums by type. This API uses an asynchronous callback to return the result.

This API cannot be used to obtain hidden albums. Use [getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11) to obtain hidden albums.

Before the operation, ensure that the albums to obtain exist.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | Yes  | Type of the album to obtain.             |
| subType  | [AlbumSubType](#albumsubtype10)         | Yes  | Subtype of the album.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains albums based on the specified options and album type. This API uses a promise to return the result.

This API cannot be used to obtain hidden albums. Use [getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11) to obtain hidden albums.

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // Obtain the album named newAlbumName.
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult == undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error('getAlbumsPromise failed with err: ' + err);
  });
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

Obtains image and video albums. This API uses an asynchronous callback to return the result.

This API cannot be used to obtain hidden albums. Use [getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11) to obtain hidden albums.

This API will be deprecated. Use [getAlbums<sup>10+</sup>](#getalbums10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | Yes  | Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback used to return the albums obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
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

getPhotoAlbums(options: AlbumFetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

Obtains image and video albums. This API uses a promise to return the result.

This API cannot be used to obtain hidden albums. Use [getHiddenAlbums](../apis-media-library-kit/js-apis-photoAccessHelper-sys.md#gethiddenalbums11) to obtain hidden albums.

This API will be deprecated. Use [getAlbums<sup>10+</sup>](#getalbums10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | Yes  | Options for fetching the albums.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the albums obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPhotoAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
    console.info('album.count = ' + fetchResult.getCount());
    const album: userFileManager.Album = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + album.albumName);
  } catch (err) {
    console.error('getPhotoAlbums fail, message = ' + err);
  }
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void

Obtains the system album. This API uses an asynchronous callback to return the result.

This API will be deprecated. Use [getAlbums<sup>10+</sup>](#getalbums10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | Yes  | Type of the system album to obtain.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Yes  | Callback used to return the albums obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPrivateAlbumDemo');
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();
      console.info('first album.albumName = ' + trashAlbum.albumName);
    } else {
      console.error('getPrivateAlbum failed. message = ', err);
    }
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType): Promise&lt;FetchResult&lt;PrivateAlbum&gt;&gt;

Obtains the system album. This API uses a promise to return the result.

This API will be deprecated. Use [getAlbums<sup>10+</sup>](#getalbums10) instead.

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPrivateAlbumDemo');
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
    let trashAlbum: userFileManager.PrivateAlbum = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + trashAlbum.albumName);
  } catch (err) {
    console.error('getPrivateAlbum failed. message = ', err);
  }
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

Obtains audio assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching the albums.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback used to return the audio assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAudioAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getAudioAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

getAudioAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;


Obtains audio assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_AUDIO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | Yes  | Options for fetching audio assets.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise used to return the audio assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAudioAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getAudioAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getAudioAssets failed, message = ', err);
  }
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a media file. This API uses an asynchronous callback to return the result. The deleted file is moved to the recycle bin.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the media file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('deleteAssetDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();


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
  } catch (err) {
    console.error('fetch failed, message =', err);
  }
}
```

### delete

delete(uri: string): Promise&lt;void&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('deleteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist');
      return;
    }
    await mgr.delete(asset.uri);
    console.info('delete successfully');
  } catch (err) {
    console.error('delete failed with error: ' + err);
  }
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback used to return a list of online peer devices.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

getActivePeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;

Obtains information about online peer devices. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return a list of online peer devices.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getActivePeersDemo');
  try {
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getActivePeers();
    if (devicesInfo != undefined) {
      console.log('getActivePeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('get distributed fail');
    }
  } catch (err) {
    console.error('getActivePeers failed. message = ', err);
  }
}
```

### getAllPeers

getAllPeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void

Obtains information about all peer devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback used to return a list of online peer devices.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

getAllPeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;

Obtains information about all peer devices. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return the information obtained.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllPeersDemo');
  try {
    let devicesInfo: Array<userFileManager.PeerInfo> = await mgr.getAllPeers();

    if (devicesInfo != undefined) {
      console.log('getAllPeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('get distributed fail');
    }
  } catch (err) {
    console.error('getAllPeers failed. message = ', err);
  }
}
```

### getPhotoIndex<sup>10+</sup>

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions, callback: AsyncCallback&lt;number&gt;): void

Obtains the index of an image or video in an album. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | Yes  | URI of the media asset whose index is to be obtained.|
| albumUri | string | Yes  | Album URI, which can be an empty string. If it is an empty string, all the media assets in the Gallery are obtained by default.  |
| options  | [FetchOptions](#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |
| callback | AsyncCallback&lt;number&gt;| Yes  | Callback used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],
      predicates: predicates
    };
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions, (err, index) => {
      if (err == undefined) {
        console.info(`getPhotoIndex successfully and index is : ${index}`);
      } else {
        console.error(`getPhotoIndex failed;`);
      }
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error}`);
  }
}
```

### getPhotoIndex<sup>10+</sup>

getPhotoIndex(photoUri: string, albumUri: string, options: FetchOptions): Promise&lt;number&gt;

Obtains the index of an image or video in an album. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| photoUri | string | Yes  | URI of the media asset whose index is to be obtained.|
| albumUri | string | Yes  | Album URI, which can be an empty string. If it is an empty string, all the media assets in the Gallery are obtained by default.  |
| options  | [FetchOptions](#fetchoptions)       | Yes  |  Fetch options. Only one search condition or sorting mode must be set in **predicates**. If no value is set or multiple search criteria or sorting modes are set, the API cannot be called successfully.     |

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;number&gt;| Promise used to return the index obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getPhotoIndexDemo');
    let predicatesForGetAsset: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOp: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicatesForGetAsset
    };
    // Obtain the uri of the album
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.FAVORITE, fetchOp);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.orderByAsc(userFileManager.ImageVideoKey.DATE_MODIFIED.toString());
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [userFileManager.ImageVideoKey.DATE_MODIFIED.toString()],
      predicates: predicates
    };
    let photoFetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOptions);
    let expectIndex = 1;
    // Obtain the uri of the second file
    let photoAsset: userFileManager.FileAsset = await photoFetchResult.getPositionObject(expectIndex);
    mgr.getPhotoIndex(photoAsset.uri, album.albumUri, fetchOptions).then((index) => {
      console.info(`getPhotoIndex successfully and index is : ${index}`);
    }).catch((err: BusinessError) => {
      console.error(`getPhotoIndex failed; error: ${err}`);
    });
  } catch (error) {
    console.error(`getPhotoIndex failed; error: ${error}`);
  }
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

Releases the **UserFileManager** instance. This API uses an asynchronous callback to return the result.
Call this API when the APIs in the **UserFileManager** instance are no longer used.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

Releases the **UserFileManager** instance. This API uses a promise to return the result.
Call this API when the APIs in the **UserFileManager** instance are no longer used.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type               | Description                             |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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

Registers a listener for the specified URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type                                       | Mandatory| Description                                                        |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | Yes  | URI of the file asset or album, or [DefaultChangeUri](#defaultchangeuri10).|
| forSubUri | boolean                                     | Yes  | Whether to perform fuzzy listening.<br> If **uri** is the URI of the album, the value **true** means to listen for the file change in the album; the value **false** means to listen for the album change only.<br> If **uri** is the URI of the file asset, there is no difference whether **forSubUri** is **true** or **false**.<br> If **uri** is **DefaultChangeUri**, the value must be **true**, otherwise, the URI cannot be found and no message can be received.|
| callback  | Callback&lt;[ChangeData](#changedata10)&gt; | Yes  | Callback used to return [ChangeData](#changedata10). <br>Note that different callbacks can be registered for a URI. You can use [off<sup>10+</sup>](#off10) to disable the specified callback or all callbacks for the URI.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('onDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData: userFileManager.ChangeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  let onCallback2 = (changeData: userFileManager.ChangeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
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

Unregisters the listener for the specified URI. Multiple callbacks can be registered for a URI for listening. You can use this API to unregister the specified callbacks or all callbacks.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | Yes  | URI of the file asset or album, or [DefaultChangeUri](#defaultchangeuri10).|
| callback | Callback&lt;[ChangeData](#changedata10)&gt; | No  | Callback registered by [on<sup>10+</sup>](#on10). If this parameter is not specified, all listener callbacks registered for the URI will be unregistered. <br>Note that the specified callback will not be invoked.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('offDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData: userFileManager.ChangeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData: userFileManager.ChangeData) => {
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

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

Subscribes to changes of the file management library. This API uses a callback to return the result.

This API will be deprecated. Use [on<sup>10+</sup>](#on10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | Yes  | Type of event to subscribe to.<br>**'deviceChange'**: device change.<br>**'albumChange'**: album change.<br>**'imageChange'**: image change.<br>**'audioChange'**: audio file change.<br>**'videoChange'**: video file change.<br>**'remoteFileChange'**: change of the file on a registered device.|
| callback | Callback&lt;void&gt; | Yes  | Callback that returns no value.                                                  |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('onDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // Image file changed. Do something.
  });
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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
| type     | [ChangeEvent](#changeevent)               | Yes  | Type of event to subscribe to.<br>**'deviceChange'**: device change.<br>**'albumChange'**: album change.<br>**'imageChange'**: image change.<br>**'audioChange'**: audio file change.<br>**'videoChange'**: video file change.<br>**'remoteFileChange'**: change of the file on a registered device.|
| callback | Callback&lt;void&gt; | No  | Callback that returns no value.                                                  |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
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
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    let fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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

## FileAsset

Provides APIs for encapsulating file asset attributes.

### Properties

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                     | Type                    | Read-Only| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | Yes  | No  | Media asset URI, for example, **file://media/Photo/1/IMG_datetime_0001/displayName.jpg**. For details, see [Media File URI](../../file-management/user-file-uri-intro.md#media-file-uri).        |
| fileType   | [FileType](#filetype) | Yes  | No  | Type of the file.                                              |
| displayName               | string                   | Yes  | Yes  | File name, including the file name extension, to display.                                |

### get

get(member: string): MemberType

Obtains the value of a **FileAsset** parameter.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Member parameter name, for example, **ImageVideoKey.DISPLAY_NAME**. You need to set **PhotoKeys** to be obtained in **fetchColumns** for all attributes except **uri**, **photoType**, and **displayName**. For example, **fetchColumns: ['title']**.|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| MemberType | Returns the member parameter.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fileAssetGetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let title: userFileManager.ImageVideoKey = userFileManager.ImageVideoKey.TITLE;
    let fileAssetTitle: userFileManager.MemberType = fileAsset.get(title.toString());
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void

Sets a **FileAsset** parameter.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Member parameter name, for example, **ImageVideoKey.DISPLAY_NAME**.|
| value | string | Yes   | Value to set. Only the values of **DISPLAY_NAME** and **TITLE** can be changed.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fileAssetSetDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let displayName: string = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);
  fileAsset.set(displayName, newFileAssetDisplayName);
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let commitModifyDisplayName = fileAsset.get(displayName);
      console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('commitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName: userFileManager.MemberType = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  let newFileAssetDisplayName = 'new' + fileAssetDisplayName;
  console.info('fileAsset newFileAssetDisplayName = ', newFileAssetDisplayName);
  fileAsset.set(displayName, newFileAssetDisplayName);
  try {
    await fileAsset.commitModify();
    let commitModifyDisplayName = fileAsset.get(displayName);
    console.info('fileAsset commitModify successfully, commitModifyDisplayName = ', commitModifyDisplayName);
  } catch (err) {
    console.error('commitModify failed. message = ', err);
  }
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens a file. This API uses an asynchronous callback to return the result.

**NOTE**<br>The write operations are mutually exclusive. After a write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, ohos.permission.WRITE_IMAGEVIDEO, or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | Mode of opening the file, for example, **'r'** (read-only), **'w'** (write-only), and **'rw'** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the file descriptor of the file opened.                           |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('openDemo');
   let testFileName: string = 'testFile' + Date.now() + '.jpg';
  const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
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

Opens a file. This API uses a promise to return the result.

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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
async function example(mgr: userFileManager.UserFileManager) {
  console.info('openDemo');
  try {
    let testFileName: string = 'testFile' + Date.now() + '.jpg';
    const fileAsset: userFileManager.FileAsset = await mgr.createPhotoAsset(testFileName);
    let fd: number = await fileAsset.open('rw');
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

Closes a file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | File descriptor of the file to close.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    const fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let fd: number = await fileAsset.open('rw');
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

Closes a file. This API uses a promise to return the result.

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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('closeDemo');
  try {
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let fd: number = await asset.open('rw');
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

Obtains the thumbnail of a file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes   | Callback used to return the PixelMap of the thumbnail.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| size     | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | Yes   | Size of the thumbnail.           |
| callback | AsyncCallback&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Yes   | Callback used to return the PixelMap of the thumbnail.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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
| size | [image.Size](../apis-image-kit/arkts-apis-image-i.md#size) | No   | Size of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis-image-kit/arkts-apis-image-PixelMap.md)&gt; | Promise used to return the PixelMap of the thumbnail.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { image } from '@kit.ImageKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getThumbnailDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let size: image.Size = { width: 720, height: 720 };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err: BusinessError) => {
    console.error('getThumbnail fail' + err);
  });
}
```

### favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites a file. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | Yes   | Whether to favorite or unfavorite the file. The value **true** means to favorite the file; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('favoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

Favorites or unfavorites a file. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| isFavorite | boolean | Yes   | Whether to favorite or unfavorite the file. The value **true** means to favorite the file; the value **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('favoriteDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  asset.favorite(true).then(() => {
    console.info('favorite successfully');
  }).catch((err: BusinessError) => {
    console.error('favorite failed with error:' + err);
  });
}
```

### setHidden<sup>10+</sup>

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

Sets a file to hidden state. This API uses an asynchronous callback to return the result.

The private files set to hidden state are located in the private album (in hidden state) and are not open to third-party applications. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| hiddenState | boolean                   | Yes   | Whether to hide the file. The value **true** means to hide the file; the value **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

Sets a file to hidden state. This API uses a promise to return the result.

The private files set to hidden state are located in the private album (in hidden state) and are not open to third-party applications. After obtaining private files from the private album, users can set **hiddenState** to **false** to remove them from the private album.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type     | Mandatory  | Description                                |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | Yes   | Whether to hide the file. The value **true** means to hide the file; the value **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  // Restore a file from a hidden album. Before the operation, ensure that the file exists in the hidden album.
  console.info('setHiddenDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.HIDDEN);
  const album: userFileManager.Album = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
  const asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err: BusinessError) => {
    console.error('setHidden failed with error:' + err);
  });
}
```

### getExif<sup>10+</sup>

getExif(): Promise&lt;string&gt;

Obtains a JSON string consisting of the EXIF tags of the JPG image. This API uses a promise to return the result.

**NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [ImageVideoKey.USER_COMMENT](#imagevideokey). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Promise used to return the EXIF data, in JSON strings.|

**Supported EXIF tags**

For details about the EXIF tags, see [image.PropertyKey](../apis-image-kit/arkts-apis-image-e.md#propertykey7).

| Key Value                                   | Description             |
| --------------------------------------- | ----------------- |
| BitsPerSample | Number of bits per sample.|
| Orientation | Image orientation.|
| ImageLength | Image length.|
| ImageWidth | Image width.|
| GPSLatitude | GPS latitude of the image.|
| GPSLongitude | GPS longitude of the image.|
| GPSLatitudeRef | Longitude reference, for example, W or E.|
| GPSLongitudeRef | Latitude reference, for example, N or S.|
| DateTimeOriginal | Shooting time.|
| ExposureTime | Exposure time.|
| SceneType | Scene type.|
| ISOSpeedRatings | ISO sensitivity or speed.|
| FNumber | f-number.|
| DateTime | Modification time.|
| GPSTimeStamp | GPS timestamp.|
| GPSDateStamp | GPS date stamp.|
| ImageDescription | Image description.|
| Make | Manufacturer.|
| MakeNote | Manufacturer.|
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
| UserComment | User comments.|
| PixelXDimension | Pixel X dimension.|
| PixelYDimension | Pixel Y dimension.|
| WhiteBalance | White balance.|
| FocalLengthIn35mmFilm | Focal length in 35 mm film.|
| ExposureBiasValue | Exposure compensation.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.isNotNull('all_exif')
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));
    let exifMessage: string = await fileAsset.getExif();
    let userCommentKey: string = 'UserComment';
    let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
    console.info('getExifDemo userComment: ' + JSON.stringify(userComment));
    fetchResult.close();
  } catch (err) {
    console.error('getExifDemoCallback failed with error: ' + err);
  }
}
```

### getExif<sup>10+</sup>

getExif(callback: AsyncCallback&lt;string&gt;): void

Obtains a JSON string consisting of the EXIF tags of the JPG image. This API uses a promise to return the result.

**NOTE**<br>This API returns a JSON string consisting of EXIF tags. The complete EXIF information consists of **all_exif** and [ImageVideoKey.USER_COMMENT](#imagevideokey). These two fields must be passed in via **fetchColumns**.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the EXIF data, in JSON strings.|

**Supported EXIF tags**

For details about the EXIF tags, see [image.PropertyKey](../apis-image-kit/arkts-apis-image-e.md#propertykey7).

| Key Value                                   | Description             |
| --------------------------------------- | ----------------- |
| BitsPerSample | Number of bits per sample.|
| Orientation | Image orientation.|
| ImageLength | Image length.|
| ImageWidth | Image width.|
| GPSLatitude | GPS latitude of the image.|
| GPSLongitude | GPS longitude of the image.|
| GPSLatitudeRef | Longitude reference, for example, W or E.|
| GPSLongitudeRef | Latitude reference, for example, N or S.|
| DateTimeOriginal | Shooting time.|
| ExposureTime | Exposure time.|
| SceneType | Scene type.|
| ISOSpeedRatings | ISO sensitivity or speed.|
| FNumber | f-number.|
| DateTime | Modification time.|
| GPSTimeStamp | GPS timestamp.|
| GPSDateStamp | GPS date stamp.|
| ImageDescription | Image description.|
| Make | Manufacturer.|
| MakeNote | Manufacturer.|
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
| UserComment | User comments.|
| PixelXDimension | Pixel X dimension.|
| PixelYDimension | Pixel Y dimension.|
| WhiteBalance | White balance.|
| FocalLengthIn35mmFilm | Focal length in 35 mm film.|
| ExposureBiasValue | Exposure compensation.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('getExifDemo');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    predicates.isNotNull('all_exif')
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: ['all_exif', userFileManager.ImageVideoKey.USER_COMMENT.toString()],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    console.info('getExifDemo fileAsset displayName: ' + JSON.stringify(fileAsset.displayName));
    let userCommentKey: string = 'UserComment';
    fileAsset.getExif((err, exifMessage) => {
      if (exifMessage != undefined) {
        let userComment: string = JSON.stringify(JSON.parse(exifMessage), [userCommentKey]);
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

### setUserComment<sup>10+</sup>

setUserComment(userComment: string): Promise&lt;void&gt;

Sets user comment information of an image or video. This API uses a promise to return the result.

**NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 140 characters.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let userComment: string = 'test_set_user_comment';
    await fileAsset.setUserComment(userComment);
  } catch (err) {
    console.error('setUserCommentDemoCallback failed with error: ' + err);
  }
}
```

### setUserComment<sup>10+</sup>

setUserComment(userComment: string, callback: AsyncCallback&lt;void&gt;): void

Sets user comment information of an image or video. This API uses an asynchronous callback to return the result.

**NOTE**<br>This API can be used to modify the comment information of only images or videos.

**System API**: This is a system API.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| userComment | string | Yes  | User comment information to set, which cannot exceed 140 characters.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('setUserCommentDemo')
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOptions: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOptions);
    let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    let userComment: string = 'test_set_user_comment';
    fileAsset.setUserComment(userComment, (err) => {
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getCountDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const fetchCount: number = fetchResult.getCount();
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  const fetchCount: number = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();
  if (fetchResult.isAfterLast()) {
    console.info('fileAsset isAfterLast displayName = ', fileAsset.displayName);
  } else {
    console.info('fileAsset  not isAfterLast ');
  }
}
```

### close

close(): void

Releases and invalidates the **FetchFileResult** instance. After this instance is released, the APIs in this instance cannot be invoked.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('fetchResultCloseDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback used to return the first file asset obtained.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getFirstObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getNextObject

getNextObject(callback: AsyncCallback&lt;T&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.
Before using this API, you must use [isAfterLast()](#isafterlast) to check whether the current position is the end of the result set.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback used to return the next file asset.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
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
Before using this API, you must use [isAfterLast()](#isafterlast) to check whether the current position is the end of the result set.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise used to return the next object in the result set.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getNextObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (!fetchResult.isAfterLast()) {
    let fileAsset: userFileManager.FileAsset = await fetchResult.getNextObject();
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
| callback | AsyncCallback&lt;T&gt; | Yes  | Callback used to return the last file asset obtained.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getLastObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getLastObject();
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
| callback | AsyncCallback&lt;T&gt; | Yes   | Callback used to return the file asset obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPositionObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getPositionObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getPositionObject(0);
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
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | Yes  | Callback used to return an array of all file assets in the result set.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
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

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('getAllObjectDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
  let fileAssetList: Array<userFileManager.FileAsset> = await fetchResult.getAllObject();
  console.info('fileAssetList length: ', fileAssetList.length);
}
```

## Album

Provides APIs to manage albums.

### Properties

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Read-Only  | Writable | Description  |
| ------------ | ------ | ---- | ---- | ------- |
| albumType<sup>10+</sup> | [AlbumType]( #albumtype10) | Yes   | No   | Type of the album to obtain.   |
| albumSubType<sup>10+</sup> | [AlbumSubType]( #albumsubtype10) | Yes   | No  | Subtype of the album.   |
| albumName | string | Yes   | Yes for a user album; no for a system album.  | Name of the album.   |
| albumUri | string | Yes   | No   | URI of the album.  |
| count | number | Yes   | No   |  Number of files in the album.|
| coverUri | string | Yes   | Yes for a user album; no for a system album.    | URI of the cover file of the album.|

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

Obtains image and video assets. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the albums.|
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumGetFileAssetsDemoCallback');

  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  let album: userFileManager.Album = await albumList.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumGetFileAssetsDemoPromise');

  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  const album: userFileManager.Album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getFileAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error('album getFileAssets failed with error: ' + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the album attributes to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  const albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
  const album: userFileManager.Album = await albumList.getFirstObject();
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

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('albumCommitModifyDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: userFileManager.AlbumFetchOptions = {
    predicates: predicates
  };
  try {
    let albumList: userFileManager.FetchResult<userFileManager.Album> = await mgr.getPhotoAlbums(albumFetchOptions);
    let album: userFileManager.Album = await albumList.getFirstObject();
    album.albumName = 'hello';
    album.commitModify().then(() => {
      console.info('commitModify successfully');
    }).catch((err: BusinessError) => {
      console.error('commitModify failed with error: ' + err);
    });
  } catch (err) {
    console.error('getPhotoAlbums failed. message = ', err);
  }
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Adds image and video assets to an album. Before the operation, ensure that the image and video assets to add and the album exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to add.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('addPhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

addPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('addPhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await mgr.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset]).then(() => {
      console.info('album addPhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album addPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Removes image and video assets from an album. The album and file resources must exist. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image and video assets to remove.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('removePhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

removePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('removePhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset]).then(() => {
      console.info('album removePhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album removePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Recovers image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to recover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('recoverPhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('recoverPhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset]).then(() => {
      console.info('album recoverPhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album recoverPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void

Deletes image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses an asynchronous callback to return the result.

**CAUTION**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | Yes  | Array of the image or video assets to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('deletePhotoAssetsDemoCallback');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

deletePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;

Deletes image or video assets from the recycle bin. Before the operation, ensure that the image or video assets exist in the recycle bin. This API uses a promise to return the result.

**CAUTION**<br>This operation is irreversible. The file assets deleted cannot be restored. Exercise caution when performing this operation.

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  try {
    console.info('deletePhotoAssetsDemoPromise');
    let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption: userFileManager.FetchOptions = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult: userFileManager.FetchResult<userFileManager.Album> = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album: userFileManager.Album = await albumFetchResult.getFirstObject();
    let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await album.getPhotoAssets(fetchOption);
    let asset: userFileManager.FileAsset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset]).then(() => {
      console.info('album deletePhotoAssets successfully');
    }).catch((err: BusinessError) => {
      console.error('album deletePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

## PrivateAlbum

Provides APIs for managing the system albums.

This API will be deprecated. Use [Album](#album) instead.

### Properties

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Read-Only  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | Yes   | Yes   | Name of the album.   |
| albumUri | string | Yes   | No   | URI of the album.  |
| dateModified | number | Yes   | No   | Date when the album was last modified.   |
| count | number | Yes   | No   | Number of files in the album.|
| coverUri | string | Yes   | No   | URI of the cover file of the album.|

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void

Obtains image and video assets from a system album. This API uses an asynchronous callback to return the result.

This API will be deprecated. Use [Album.getPhotoAssets](#getphotoassets-2) instead.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | Yes  | Options for fetching the image and video assets.|
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Yes  | Callback used to return the image and video assets obtained.|

**Error codes**

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumGetFileAssetsDemoCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
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

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;

Obtains image and video assets from a system album. This API uses a promise to return the result.

This API will be deprecated. Use [Album.getPhotoAssets](#getphotoassets-3) instead.

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

For details about the error codes, see [File Management Error Codes](errorcode-filemanagement.md).

| ID| Error Message|
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumGetFileAssetsDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let count = fetchResult.getCount();
  console.info('fetchResult.count = ', count);
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a file from the system album. Only the files in the trash can be deleted.

This API will be deprecated. Use [Album.deletePhotoAssets](#deletephotoassets10) instead.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumDeleteCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
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

delete(uri: string): Promise&lt;void&gt;

Deletes a file from the system album. Only the files in the trash can be deleted.

This API will be deprecated. Use [Album.deletePhotoAssets](#deletephotoassets10) instead.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to delete.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumDeleteDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri).then(() => {
    console.info('trashAlbum.delete successfully');
  }).catch((err: BusinessError) => {
    console.error('trashAlbum.delete failed, message = ', err);
  });
}
```

### recover

recover(uri: string, callback: AsyncCallback&lt;void&gt;): void

Recovers a file in the system album. Only the files in the trash can be recovered.

This API will be deprecated. Use [Album.recoverPhotoAssets](#recoverphotoassets10) instead.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to recover.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumRecoverDemoCallback');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let recoverFileUri: string = fileAsset.uri;
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

recover(uri: string): Promise&lt;void&gt;

Recovers a file in the system album. Only the files in the trash can be recovered.

This API will be deprecated. Use [Album.recoverPhotoAssets](#recoverphotoassets10) instead.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.WRITE_IMAGEVIDEO or ohos.permission.READ_AUDIO, and ohos.permission.WRITE_AUDIO

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | Yes  | URI of the file to recover.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

**Example**

For details about how to create a **userFileManager** instance, see the example in [userFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr).

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(mgr: userFileManager.UserFileManager) {
  console.info('privateAlbumRecoverDemoPromise');
  let albumList: userFileManager.FetchResult<userFileManager.PrivateAlbum> = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption: userFileManager.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let trashAlbum: userFileManager.PrivateAlbum = await albumList.getFirstObject();
  let fetchResult: userFileManager.FetchResult<userFileManager.FileAsset> = await trashAlbum.getPhotoAssets(fetchOption);
  let fileAsset: userFileManager.FileAsset = await fetchResult.getFirstObject();
  let recoverFileUri: string = fileAsset.uri;
  trashAlbum.recover(recoverFileUri).then(() => {
    console.info('trashAlbum.recover successfully');
  }).catch((err: BusinessError) => {
    console.error('trashAlbum.recover failed, message = ', err);
  });
}
```

## MemberType

Enumerates the member types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Type|  Read-Only |  Writable |  Description |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | Yes| Yes| The member is a number.|
| string |  string | Yes| Yes| The member is a string.|
| boolean |  boolean | Yes| Yes| The member is a Boolean value.|

## ChangeEvent

Enumerates the type of changes to observe.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Type|  Read-Only |  Writable |  Description|
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

| Name      | Type                      | Read-Only| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online. The value **true** means the registered device is online; the value **false** means the opposite.        |

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
| TRASH |  1028 |  Trash.|
| SCREENSHOT |  1029 |  Album for screenshots and screen recording files.|
| CAMERA |  1030 |  Album for photos and videos taken by the camera.|
| ANY |  2147483647 |  Any album.|

## PrivateAlbumType

Enumerates the system album types.

This API will be deprecated. Use [AlbumType](#albumtype10) and [AlbumSubType](#albumsubtype10) instead.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name   |  Value|   Description  |
| -----   |  ----  |   ----  |
| TYPE_FAVORITE |  0 |  Favorites.|
| TYPE_TRASH |  1 |  Trash.|

## AudioKey

Defines the key information about an audio file.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         |   Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | URI of the file.                                                  |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).|
| TITLE         | title               | Title of the file.                                                  |
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
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).|
| TITLE         | title               | Title of the file.                                                  |
| DURATION      | duration            | Duration, in ms.                                   |
| WIDTH         | width               | Image width, in pixels.                                   |
| HEIGHT        | height              | Image height, in pixels.                                     |
| DATE_TAKEN    | date_taken          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).               |
| ORIENTATION   | orientation         | Orientation of the image file.                                            |
| FAVORITE      | favorite            | Whether the file is added to favorites.                                                   |
| POSITION<sup>10+</sup>  | position            | File location type.                              |
| DATE_TRASHED<sup>10+</sup>  | date_trashed  | Date when the file was deleted. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).                |
| HIDDEN<sup>10+</sup>  | hidden            | Whether the file is hidden.                              |
| CAMERA_SHOT_KEY<sup>10+</sup>    | camera_shot_key           | Key for the Ultra Snapshot feature.<br>This parameter is available only for the system camera, and the key value is defined by the system camera.   |
| USER_COMMENT<sup>10+</sup>  | user_comment            | User comment information.                              |

## AlbumKey

Defines the key album information.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | URI of the album.                                                  |
| FILE_TYPE     | file_type           | Type of the file.                                             |
| ALBUM_NAME    | album_name          | Name of the album.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time (00:00:00 UTC on January 1, 1970).|

## PhotoCreateOptions<sup>10+</sup>

Options for creating an image or video asset.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Mandatory| Description                                             |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| subType           | [PhotoSubType](#photosubtype10) | No | Subtype of the image or video. |
| cameraShotKey           | string | No | Key for the Ultra Snapshot feature.<br>This parameter is available only for the system camera, and the key value is defined by the system camera. |

## FetchOptions

Defines the options for fetching file attributes.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Read-Only| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | Yes  | Yes  | Options for fetching files based on the attributes in columns. If this parameter is left empty, files are fetched by URI, name, and type (the specific field names vary with the file asset or album object) by default. In addition, an error will be reported if [get](#get) is called to obtain other attributes of this object. Example:<br>fetchColumns: ['uri', 'title']|
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates-sys.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## AlbumFetchOptions

Defines the options for fetching an album.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Read-Only| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](../apis-arkdata/js-apis-data-dataSharePredicates-sys.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## ChangeData<sup>10+</sup>

Defines the return value of the listener callback.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name   | Type                       | Read-Only| Writable| Description                                                        |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](#notifytype10) | Yes  | No  | Notification type.                                      |
| uris    | Array&lt;string&gt;         | Yes  | No  | Array of all file asset or album URIs with the same [NotifyType](#notifytype10).|
| subUris | Array&lt;string&gt;         | Yes  | No  | URIs of the changed files in the album. The value may be undefined. Check whether the value is undefined before using it.|

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

<!--no_check-->