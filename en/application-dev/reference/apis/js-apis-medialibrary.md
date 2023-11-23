# @ohos.multimedia.medialibrary (Media Library Management)

> **NOTE**
>
> - The APIs of this module are supported since API version 6. Updates will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are deprecated since API version 9. For details about the substitute APIs, see the API description.

## Modules to Import

```ts
import mediaLibrary from '@ohos.multimedia.mediaLibrary';
```

## mediaLibrary.getMediaLibrary<sup>8+</sup>

getMediaLibrary(context: Context): MediaLibrary

Obtains a **MediaLibrary** instance, which is used to access and modify personal media data such as audios, videos, images, and documents.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getPhotoAccessHelper](js-apis-photoAccessHelper.md#photoaccesshelpergetphotoaccesshelper) instead.

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | Context | Yes  | Context of the ability.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [MediaLibrary](#medialibrary) | **MediaLibrary** instance obtained.|

**Example**

```ts
// Obtain a MediaLibrary instance. The instance obtained here is used in later.
const context = getContext(this);
let media: mediaLibrary.MediaLibrary = mediaLibrary.getMediaLibrary(context);
```

## mediaLibrary.getMediaLibrary

getMediaLibrary(): MediaLibrary

Obtains a **MediaLibrary** instance, which is used to access and modify personal media data such as audios, videos, images, and documents.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Model restriction**: This API can be used only in the FA model.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                         | Description      |
| ----------------------------- | :--------- |
| [MediaLibrary](#medialibrary) | **MediaLibrary** instance obtained.|

**Example**

```ts
let media: mediaLibrary.MediaLibrary = mediaLibrary.getMediaLibrary();
```

## MediaLibrary

### getFileAssets<sup>7+</sup>

getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void 

Obtains file assets (also called files). This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [getAssets](js-apis-photoAccessHelper.md#getassets) instead.
> - From API version 10, the albums represented by physical directories are replaced by logical albums, which allow multiple files in an album and presence of a file in multiple albums. This design, however, makes **parent**, **albumId**, **albumUri**, and **albumName** incompatible. They cannot be used as parameters of **MediaFetchOptions** in **getFileAssets()**. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                             |
| -------- | --------------------------------------------------- | ---- | --------------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)            | Yes  | Options for fetching the files.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult7)> | Yes  | Callback invoked to return the file retrieval result set.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  // Create options for fetching the files of the image type.
  let imagesFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
  };
  // Obtain the files in asynchronous callback mode.
  media.getFileAssets(imagesFetchOp, async (error, fetchFileResult) => {
    // Check whether the result set of the obtained files is undefined. If yes, the API call fails.
    if (fetchFileResult == undefined) {
      console.error('get fetchFileResult failed with error: ' + error);
      return;
    }
    // Obtain the total number of files in the result set.
    const count = fetchFileResult.getCount();
    // Check whether the number is less than 0. If yes, the API call fails.
    if (count < 0) {
      console.error('get count from fetchFileResult failed, count: ' + count);
      return;
    }
    // Check whether the number is 0. If yes, the API call is successful, but the result set is empty. Check whether the options for fetching the files are correctly set and whether the corresponding files exist on the device.
    if (count == 0) {
      console.info('The count of fetchFileResult is zero');
      return;
    }
    console.info('Get fetchFileResult successfully, count: ' + count);
    // Obtain the first file in the result set in asynchronous callback mode. If there are a large number of files, use getAllObject() instead.
    fetchFileResult.getFirstObject(async (error, fileAsset) => {
      // Check whether the first file is undefined. If yes, the API call fails.
      if (fileAsset == undefined) {
        console.error('get first object failed with error: ' + error);
        return;
      }
      console.info('fileAsset.displayName ' + '0 : ' + fileAsset.displayName);
      // Call getNextObject to obtain the next file until the last one.
      for (let i = 1; i < count; i++) {
        let fileAsset = await fetchFileResult.getNextObject();
        console.info('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
      }
      // Release the FetchFileResult instance and invalidate it. Other APIs can no longer be called.
      fetchFileResult.close();
    });
  });
}
```

### getFileAssets<sup>7+</sup>

getFileAssets(options: MediaFetchOptions): Promise&lt;FetchFileResult&gt;

Obtains file assets. This API uses a promise to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [getAssets](js-apis-photoAccessHelper.md#getassets-1) instead.
> - From API version 10, the albums represented by physical directories are replaced by logical albums, which allow multiple files in an album and presence of a file in multiple albums. This design, however, makes **parent**, **albumId**, **albumUri**, and **albumName** incompatible. They cannot be used as parameters of **MediaFetchOptions** in **getFileAssets()**. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description        |
| ------- | ---------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#mediafetchoptions7) | Yes  | Options for fetching the files.|

**Return value**

| Type                                | Description          |
| ------------------------------------ | -------------- |
| Promise&lt;[FetchFileResult](#fetchfileresult7)&gt; | Promise used to return the file retrieval result set.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  // Create options for fetching the files of the image type.
  let imagesFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
  };
  // Obtain the files in promise mode.
  media.getFileAssets(imagesFetchOp).then(async (fetchFileResult) => {
    // Obtain the total number of files in the result set.
    const count = fetchFileResult.getCount();
    // Check whether the number is less than 0. If yes, the API call fails.
    if (count < 0) {
      console.error('get count from fetchFileResult failed, count: ' + count);
      return;
    }
    // Check whether the number is 0. If yes, the API call is successful, but the result set is empty. Check whether the options for fetching the files are correctly set and whether the corresponding files exist on the device.
    if (count == 0) {
      console.info('The count of fetchFileResult is zero');
      return;
    }
    console.info('Get fetchFileResult successfully, count: ' + count);
    // Obtain the first file in the result set in promise mode. If there are a large number of files, use getAllObject instead.
    fetchFileResult.getFirstObject().then(async (fileAsset) => {
      console.info('fileAsset.displayName ' + '0 : ' + fileAsset.displayName);
      // Call getNextObject to obtain the next file until the last one.
      for (let i = 1; i < count; i++) {
        let fileAsset = await fetchFileResult.getNextObject();
        console.info('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
      }
      // Release the FetchFileResult instance and invalidate it. Other APIs can no longer be called.
      fetchFileResult.close();
    }).catch((error: BusinessError) => {
      // Calling getFirstObject fails.
      console.error('get first object failed with error: ' + error);
    });
  }).catch((error: BusinessError) => {
    // Calling getFileAssets fails.
    console.error('get file assets failed with error: ' + error);
  });
}
```

### on<sup>8+</sup>

on(type: 'deviceChange'&#124;'albumChange'&#124;'imageChange'&#124;'audioChange'&#124;'videoChange'&#124;'fileChange'&#124;'remoteFileChange', callback: Callback&lt;void&gt;): void

Subscribes to the media library changes. This API uses a callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [registerChange](js-apis-photoAccessHelper.md#registerchange) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| type     | 'deviceChange'&#124;<br>'albumChange'&#124;<br>'imageChange'&#124;<br>'audioChange'&#124;<br>'videoChange'&#124;<br>'fileChange'&#124;<br>'remoteFileChange'               | Yes   | Type of the event to subscribe to.<br>'deviceChange': registered device change<br>'albumChange': album change<br>'imageChange': image file change<br>'audioChange': audio file change<br>'videoChange': video file change<br>'fileChange': file change<br>'remoteFileChange': file change on the registered device|
| callback | Callback&lt;void&gt; | Yes   | Callback that returns no value.                                   |

**Example**

```ts
media.on('imageChange', () => {
  // image file had changed, do something.
});
```

### off<sup>8+</sup>

off(type: 'deviceChange'&#124;'albumChange'&#124;'imageChange'&#124;'audioChange'&#124;'videoChange'&#124;'fileChange'&#124;'remoteFileChange', callback?: Callback&lt;void&gt;): void

Unsubscribes from the media library changes. This API uses a callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [unRegisterChange](js-apis-photoAccessHelper.md#unregisterchange) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                  | Mandatory  | Description                                      |
| -------- | -------------------- | ---- | ---------------------------------------- |
| type     | 'deviceChange'&#124;<br>'albumChange'&#124;<br>'imageChange'&#124;<br>'audioChange'&#124;<br>'videoChange'&#124;<br>'fileChange'&#124;<br>'remoteFileChange'               | Yes   | Type of the event to unsubscribe from.<br>'deviceChange': registered device change<br>'albumChange': album change<br>'imageChange': image file change<br>'audioChange': audio file change<br>'videoChange': video file change<br>'fileChange': file change<br>'remoteFileChange': file change on the registered device|
| callback | Callback&lt;void&gt; | No   | Callback that returns no value.                                   |

**Example**

```ts
media.off('imageChange', () => {
  // stop listening successfully.
});
```

### createAsset<sup>8+</sup>

createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates a media asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [createAsset](js-apis-photoAccessHelper.md#createasset) instead.
> - From the SDK of API version 10, **relativePath** is no longer associated with an album. After a file is created, the last-level directory of **relativePath** is not displayed. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                                                        |
| ------------ | --------------------------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype8)                | Yes  | Media type.                                                    |
| displayName  | string                                  | Yes  | File name to display.                                                  |
| relativePath | string                                  | Yes  | Path of the file, which can be obtained by using [getPublicDirectory](#getpublicdirectory8).|
| callback     | AsyncCallback<[FileAsset](#fileasset7)> | Yes  | Callback invoked to return the **FileAsset** instance created.                         |

**Example**

```ts
async function example() {
  // Create an image file in callback mode.
  let mediaType = mediaLibrary.MediaType.IMAGE;
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
  const path = await media.getPublicDirectory(DIR_IMAGE);
  media.createAsset(mediaType, 'imageCallBack.jpg', path + 'myPicture/', (error, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createAsset successfully, message');
    } else {
      console.error('createAsset failed with error: ' + error);
    }
  });
}
```

### createAsset<sup>8+</sup>

createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset&gt;

Creates a media asset. This API uses a promise to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [createAsset](js-apis-photoAccessHelper.md#createasset-1) instead.
> - From the SDK of API version 10, **relativePath** is no longer associated with an album. After a file is created, the last-level directory of **relativePath** is not displayed. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                    | Mandatory| Description                                                        |
| ------------ | ------------------------ | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype8) | Yes  | Media type.                                                    |
| displayName  | string                   | Yes  | File name to display.                                                  |
| relativePath | string                   | Yes  | Relative path of the file, which can be obtained by **getPublicDirectory**.|

**Return value**

| Type                    | Description             |
| ------------------------ | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the **FileAsset** instance created.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  // Create an image file in promise mode.
  let mediaType = mediaLibrary.MediaType.IMAGE;
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
  const path = await media.getPublicDirectory(DIR_IMAGE);
  media.createAsset(mediaType, 'imagePromise.jpg', path + 'myPicture/').then((fileAsset) => {
    console.info('createAsset successfully, message = ' + JSON.stringify(fileAsset));
  }).catch((error: BusinessError) => {
    console.error('createAsset failed with error: ' + error);
  });
}
```

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string): Promise\<void>

Deletes a file asset. This API uses a promise to return the result.

Before calling this API, call [FileAsset.trash](#trash8) to move the file to the trash. Otherwise, the file fails to be deleted.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper.md#deleteassets-3) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri).then(() => {
    console.info('deleteAsset successfully');
  }).catch((error: BusinessError) => {
    console.error('deleteAsset failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### deleteAsset<sup>8+</sup>

deleteAsset(uri: string, callback: AsyncCallback\<void>): void

Deletes a file asset. This API uses an asynchronous callback to return the result.

Before calling this API, call [FileAsset.trash](#trash8) to move the file to the trash. Otherwise, the file fails to be deleted.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper.md#deleteassets-2) instead.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| uri | string | Yes   | URI of the file asset to delete.|
|callback |AsyncCallback\<void>| Yes |Callback that returns no value.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let option: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
  };
  const fetchFileResult = await media.getFileAssets(option);
  let asset = await fetchFileResult.getFirstObject();
  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  media.deleteAsset(asset.uri, (error) => {
    if (error != undefined) {
      console.error('deleteAsset failed with error: ' + error);
    } else {
      console.info('deleteAsset successfully');
    }
  });
  fetchFileResult.close();
}
```

### getPublicDirectory<sup>8+</sup>

getPublicDirectory(type: DirectoryType, callback: AsyncCallback&lt;string&gt;): void

Obtains a user directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                            | Mandatory| Description                     |
| -------- | -------------------------------- | ---- | ------------------------- |
| type     | [DirectoryType](#directorytype8) | Yes  | Type of the user directory.             |
| callback | AsyncCallback&lt;string&gt;      | Yes  | Callback invoked to return the user directory obtained.|

**Example**

```ts
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
media.getPublicDirectory(DIR_CAMERA, (error, dicResult) => {
  if (dicResult == 'Camera/') {
    console.info('getPublicDirectory DIR_CAMERA successfully');
  } else {
    console.error('getPublicDirectory DIR_CAMERA failed with error: ' + error);
  }
});
```

### getPublicDirectory<sup>8+</sup>

getPublicDirectory(type: DirectoryType): Promise&lt;string&gt;

Obtains a user directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name| Type                            | Mandatory| Description        |
| ------ | -------------------------------- | ---- | ------------ |
| type   | [DirectoryType](#directorytype8) | Yes  | Type of the user directory.|

**Return value**

| Type            | Description            |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the user directory obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
  media.getPublicDirectory(DIR_CAMERA).then((dicResult) => {
    if (dicResult == 'Camera/') {
      console.info('getPublicDirectory DIR_CAMERA successfully');
    } else {
      console.error('getPublicDirectory DIR_CAMERA failed');
    }
  }).catch((error: BusinessError) => {
    console.error('getPublicDirectory failed with error: ' + error);
  });
}
```

### getAlbums<sup>7+</sup>

getAlbums(options: MediaFetchOptions, callback: AsyncCallback&lt;Array&lt;Album&gt;&gt;): void

Obtains albums. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [getAlbums](js-apis-photoAccessHelper.md#getalbums) instead.
> - From the SDK of API version 10, **relativePath** is no longer associated with an album and cannot be used in **getAlbums**. Currently, only **Camera** and **ScreenShots** albums are supported. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                       |
| -------- | -------------------------------------------- | ---- | --------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)     | Yes  | Options for fetching albums.               |
| callback | AsyncCallback&lt;Array<[Album](#album7)>&gt; | Yes  | Callback invoked to return the albums.|

**Example**

```ts
async function example() {
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs: ['Camera'],
  };
  media.getAlbums(albumFetchOp, (error, albumList) => {
    if (albumList != undefined) {
      console.info('getAlbums successfully: ' + JSON.stringify(albumList));
    } else {
      console.error('getAlbums failed with error: ' + error);
    }
  });
}
```

### getAlbums<sup>7+</sup>

getAlbums(options: MediaFetchOptions): Promise&lt;Array&lt;Album&gt;&gt;

Obtains albums. This API uses a promise to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [getAlbums](js-apis-photoAccessHelper.md#getalbums-2) instead.
> - From the SDK of API version 10, **relativePath** is no longer associated with an album and cannot be used in **getAlbums**. Currently, only **Camera** and **ScreenShots** albums are supported. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description        |
| ------- | ---------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#mediafetchoptions7) | Yes  | Options for fetching the albums.|

**Return value**

| Type                            | Description         |
| -------------------------------- | ------------- |
| Promise<Array<[Album](#album7)>> | Promise used to return the albums.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs: ['Camera'],
  };
  media.getAlbums(albumFetchOp).then((albumList) => {
    console.info('getAlbums successfully: ' + JSON.stringify(albumList));
  }).catch((error: BusinessError) => {
    console.error('getAlbums failed with error: ' + error);
  });
}
```

### release<sup>8+</sup>

release(callback: AsyncCallback&lt;void&gt;): void

Releases this **MediaLibrary** instance.
Call this API when you no longer need to use the APIs in the **MediaLibrary** instance.

> **NOTE**
>
> This API is deprecated since API version 9. Use [release](js-apis-photoAccessHelper.md#release) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description        |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```ts
media.release(() => {
  // do something.
});
```

### release<sup>8+</sup>

release(): Promise&lt;void&gt;

Releases this **MediaLibrary** instance.
Call this API when you no longer need to use the APIs in the **MediaLibrary** instance.

> **NOTE**
>
> This API is deprecated since API version 9. Use [release](js-apis-photoAccessHelper.md#release-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
media.release();
```

### storeMediaAsset

storeMediaAsset(option: MediaAssetOption, callback: AsyncCallback&lt;string&gt;): void

Stores a media asset. This API uses an asynchronous callback to return the URI of the media asset.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. Use [save](js-apis-file-picker.md#save-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                   | Mandatory  | Description                     |
| -------- | ------------------------------------- | ---- | ----------------------- |
| option   | [MediaAssetOption](#mediaassetoption) | Yes   | Media asset option.                |
| callback | AsyncCallback&lt;string&gt;           | Yes   | Callback invoked to return the URI of the media resource saved.|

**Example**

```ts
let option: mediaLibrary.MediaAssetOption = {
  src : '/data/storage/el2/base/haps/entry/image.png',
  mimeType : 'image/*',
  relativePath : 'Pictures/'
};
mediaLibrary.getMediaLibrary().storeMediaAsset(option, (error, value) => {
  if (error) {
    console.error('storeMediaAsset failed with error: ' + error);
    return;
  }
  console.info('Media resources stored. ');
  // Obtain the URI of the media asset.
});
```

### storeMediaAsset

storeMediaAsset(option: MediaAssetOption): Promise&lt;string&gt;

Stores a media asset. This API uses a promise to return the URI of the media asset.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. Use [save](js-apis-file-picker.md#save) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                   | Mandatory  | Description     |
| ------ | ------------------------------------- | ---- | ------- |
| option | [MediaAssetOption](#mediaassetoption) | Yes   | Media asset option.|

**Return value**

| Type                   | Description                          |
| --------------------- | ---------------------------- |
| Promise&lt;string&gt; | Promise used to return the URI of the media asset saved.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let option: mediaLibrary.MediaAssetOption = {
  src : '/data/storage/el2/base/haps/entry/image.png',
  mimeType : 'image/*',
  relativePath : 'Pictures/'
};
mediaLibrary.getMediaLibrary().storeMediaAsset(option).then((value) => {
  console.info('Media resources stored.');
  // Obtain the URI that stores media resources.
}).catch((error: BusinessError) => {
  console.error('storeMediaAsset failed with error: ' + error);
});
```

### startImagePreview

startImagePreview(images: Array&lt;string&gt;, index: number, callback: AsyncCallback&lt;void&gt;): void

Starts image preview, with the first image to preview specified. This API can be used to preview a local image (**file://**) or all online images (**https://**). It uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead.<br>The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| images   | Array&lt;string&gt;       | Yes   | Images to preview. You can preview a local image (**file://**) or all online images (**https://**).|
| index    | number                    | Yes   | Index of the first image to preview.                              |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                       |

**Example**

```ts
let images = [
  'file://media/xxxx/2',
  'file://media/xxxx/3'
];
/* Preview online images.
let images = [
  'https://media.xxxx.com/image1.jpg',
  'https://media.xxxx.com/image2.jpg'
];
*/
let index = 1;
mediaLibrary.getMediaLibrary().startImagePreview(images, index, (error) => {
  if (error) {
    console.error('startImagePreview failed with error: ' + error);
    return;
  }
  console.info('Succeeded in previewing the images.');
});
```

### startImagePreview

startImagePreview(images: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Starts image preview. This API can be used to preview the first local image (**file://**) or all online images (**https://**). It uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead.<br>The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description                                      |
| -------- | ------------------------- | ---- | ---------------------------------------- |
| images   | Array&lt;string&gt;       | Yes   | Images to preview. You can preview a local image (**file://**) or all online images (**https://**).|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                       |

**Example**

```ts
let images = [
  'file://media/xxxx/2',
  'file://media/xxxx/3'
];
/* Preview online images.
let images = [
  'https://media.xxxx.com/image1.jpg',
  'https://media.xxxx.com/image2.jpg'
];
*/
mediaLibrary.getMediaLibrary().startImagePreview(images, (error) => {
  if (error) {
    console.error('startImagePreview failed with error: ' + error);
    return;
  }
  console.info('Succeeded in previewing the images.');
});
```

### startImagePreview

startImagePreview(images: Array&lt;string&gt;, index?: number): Promise&lt;void&gt;

Starts image preview, with the first image to preview specified. This API can be used to preview a local image (**file://**) or all online images (**https://**). It uses a promise to return the execution result.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. You are advised to use the **\<[Image](../arkui-ts/ts-basic-components-image.md)>** component instead.<br>The **\<Image>** component can be used to render and display local and online images.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                 | Mandatory  | Description                                      |
| ------ | ------------------- | ---- | ---------------------------------------- |
| images | Array&lt;string&gt; | Yes   | Images to preview. You can preview a local image (**file://**) or all online images (**https://**).|
| index  | number              | No   | Index of the first image to preview. If this parameter is not specified, the default value **0** is used.                     |

**Return value**

| Type                 | Description                             |
| ------------------- | ------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let images = [
  'file://media/xxxx/2',
  'file://media/xxxx/3'
];
/* Preview online images.
let images = [
  'https://media.xxxx.com/image1.jpg',
  'https://media.xxxx.com/image2.jpg'
];
*/
let index = 1;
mediaLibrary.getMediaLibrary().startImagePreview(images, index).then(() => {
  console.info('Succeeded in previewing the images.');
}).catch((error: BusinessError) => {
  console.error('startImagePreview failed with error: ' + error);
});
```

### startMediaSelect

startMediaSelect(option: MediaSelectOption, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Starts media selection. This API uses an asynchronous callback to return the URIs of the selected media assets.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. Use [select](js-apis-file-picker.md#select-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                      | Mandatory  | Description                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------ |
| option   | [MediaSelectOption](#mediaselectoption)  | Yes   | Media selection option.                             |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes   | Callback invoked to return the URIs of the selected media assets.|

**Example**

```ts
let option : mediaLibrary.MediaSelectOption = {
  type : 'media',
  count : 2
};
mediaLibrary.getMediaLibrary().startMediaSelect(option, (error, value) => {
  if (error) {
    console.error('startMediaSelect failed with error: ' + error);
    return;
  }
  console.info('Media resources selected.');
  // Obtain the media selection value.
});
```

### startMediaSelect

startMediaSelect(option: MediaSelectOption): Promise&lt;Array&lt;string&gt;&gt;

Starts media selection. This API uses a promise to return the URIs of the selected media assets.

> **NOTE**
>
> - This API is supported since API version 6 and can be used only in the FA model.
> - This API is deprecated since API version 9. Use [select](js-apis-file-picker.md#select) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                     | Mandatory  | Description     |
| ------ | --------------------------------------- | ---- | ------- |
| option | [MediaSelectOption](#mediaselectoption) | Yes   | Media selection option.|

**Return value**

| Type                                | Description                                      |
| ---------------------------------- | ---------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the URIs of the selected media assets.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

let option : mediaLibrary.MediaSelectOption = {
  type : 'media',
  count : 2
};
mediaLibrary.getMediaLibrary().startMediaSelect(option).then((value) => {
  console.info('Media resources selected.');
  // Obtain the media selection value.
}).catch((error: BusinessError) => {
  console.error('startMediaSelect failed with error: ' + error);
});
```

### getActivePeers<sup>8+</sup>

getActivePeers(): Promise\<Array\<PeerInfo>>;

Obtains information about online peer devices. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise used to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getActivePeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getActivePeers<sup>8+</sup>

getActivePeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | Callback invoked to return the online peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
async function example() {
  media.getActivePeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(): Promise\<Array\<PeerInfo>>;

Obtains information about all peer devices. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
|  Promise\<Array\<[PeerInfo](#peerinfo8)>> | Promise used to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  media.getAllPeers().then((devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.info('get distributed info is undefined!');
    }
  }).catch((error: BusinessError) => {
    console.error('get distributed info failed with error: ' + error);
  });
}
```

### getAllPeers<sup>8+</sup>

getAllPeers(callback: AsyncCallback\<Array\<PeerInfo>>): void;

Obtains information about all peer devices. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| callback: AsyncCallback\<Array\<[PeerInfo](#peerinfo8)>> | Callback invoked to return all peer devices, in an array of **PeerInfo** objects.|

**Example**

```ts
async function example() {
  media.getAllPeers((error, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.info('get distributed info ' + JSON.stringify(devicesInfo));
    } else {
      console.error('get distributed failed with error: ' + error);
    }
  });
}
```

## FileAsset<sup>7+</sup>

Provides APIs for encapsulating file asset attributes.

> **NOTE**
>
> - The system attempts to parse the file content if the file is an audio or video file. The actual field values will be restored from the passed values during scanning on some devices.
> - Some devices may not support the modification of **orientation**. You are advised to use [ModifyImageProperty](js-apis-image.md#modifyimageproperty9) of the **image** module.
> - This API is deprecated since API version 9. Use [PhotoAsset](js-apis-photoAccessHelper.md#photoasset) instead.

### Attributes

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| id                        | number                   | Yes  | No  | File asset ID.                                          |
| uri                       | string                   | Yes  | No  | File asset URI, for example, **file://media/image/2**.        |
| mimeType                  | string                   | Yes  | No  | Extended file attributes.                                          |
| mediaType<sup>8+</sup>    | [MediaType](#mediatype8) | Yes  | No  | Media type.                                              |
| displayName               | string                   | Yes  | Yes  | File name, including the file name extension, to display.                                |
| title                     | string                   | Yes  | Yes  | Title in the file.                                              |
| relativePath<sup>8+</sup> | string                   | Yes  | Yes  | Relative path of the user directory.                                      |
| parent<sup>8+</sup>       | number                   | Yes  | No  | Parent directory ID. Since SDK of API version 10, an asset can exist in multiple albums. Therefore, this attribute is incompatible. The obtained value is always **0**.                       |
| size                      | number                   | Yes  | No  | File size, in bytes.                                |
| dateAdded                 | number                   | Yes  | No  | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.        |
| dateModified              | number                   | Yes  | No  | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| dateTaken                 | number                   | Yes  | No  | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.        |
| artist<sup>8+</sup>       | string                   | Yes  | No  | Artist of the file.                                                  |
| audioAlbum<sup>8+</sup>   | string                   | Yes  | No  | Audio album.                                                  |
| width                     | number                   | Yes  | No  | Image width, in pixels.                                |
| height                    | number                   | Yes  | No  | Image height, in pixels.                                |
| orientation               | number                   | Yes  | Yes  | Image display direction (clockwise rotation angle, for example, 0, 90, or 180, in degrees).|
| duration<sup>8+</sup>     | number                   | Yes  | No  | Duration, in ms.                                  |
| albumId                   | number                   | Yes  | No  | ID of the album to which the file belongs. Since SDK of API version 10, an asset can exist in multiple albums. Therefore, this attribute is incompatible. The obtained value is always **0**.                  |
| albumUri<sup>8+</sup>     | string                   | Yes  | No  | URI of the album to which the file belongs. Since SDK of API version 10, an asset can exist in multiple albums. Therefore, this attribute is incompatible. The obtained value is always an empty string.                     |
| albumName                 | string                   | Yes  | No  | Name of the album to which the file belongs. Since SDK of API version 10, an asset can exist in multiple albums. Therefore, this attribute is incompatible. The obtained value is always an empty string.                    |

### isDirectory<sup>8+</sup>

isDirectory(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is a directory. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                 |
| -------- | ---------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means the file asset is a directory; the value false means the opposite.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isDirectory((error, isDirectory) => {
    if (error) {
      console.error('isDirectory failed with error: ' + error);
    } else {
      console.info('isDirectory result:' + isDirectory);
    }
  });
  fetchFileResult.close();
}
```

### isDirectory<sup>8+</sup>

isDirectory():Promise&lt;boolean&gt;

Checks whether this file asset is a directory. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                    | Description                          |
| ---------------------- | ---------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file asset is a directory; the value **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isDirectory().then((isDirectory) => {
    console.info('isDirectory result:' + isDirectory);
  }).catch((error: BusinessError) => {
    console.error('isDirectory failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### commitModify<sup>8+</sup>

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the file metadata to the database. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [commitModify](js-apis-photoAccessHelper.md#commitmodify) instead.
> - Since the SDK of API version 10, **audio** does not have the **orientation** attribute. Therefore, the **orientation** attribute of the audio resource cannot be modified by **commitModify()**. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.title = 'newtitle';
  asset.commitModify(() => {
    console.info('commitModify successfully');
  });
  fetchFileResult.close();
}
```

### commitModify<sup>8+</sup>

commitModify(): Promise&lt;void&gt;

Commits the modification on the file asset to the database. This API uses a promise to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [commitModify](js-apis-photoAccessHelper.md#commitmodify-1) instead.
> Since the SDK of API version 10, **audio** does not have the **orientation** attribute. Therefore, the **orientation** attribute of the audio resource cannot be modified by **commitModify()**. For details, see [Change of the mediaLibrary Interface Compatibility](../../../release-notes/changelogs/v4.0-beta2/changelogs-medialibrary.md).

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.title = 'newtitle';
  await asset.commitModify();
  fetchFileResult.close();
}
```

### open<sup>8+</sup>

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [open](js-apis-photoAccessHelper.md#open) instead.
> - If a file is opened in 'w' mode, the returned file descriptor (FD) cannot be used to read the file. However, due to the implementation differences of file systems, some user-mode files opened in 'w' mode can be read by using FD. To perform the read or write operation on a file by using FD, you are advised to open the file in 'rw' mode.
> - The write operations are mutually exclusive. After a write operation is complete, you must call **close** to close the file.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the FD of the file opened.                           |

**Example**

```ts
async function example() {
  let mediaType = mediaLibrary.MediaType.IMAGE;
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
  const path = await media.getPublicDirectory(DIR_IMAGE);
  const asset = await media.createAsset(mediaType, 'image00003.jpg', path);
  asset.open('rw', (error, fd) => {
    if (fd > 0) {
      asset.close(fd);
    } else {
      console.error('File Open failed with error: ' + error);
    }
  });
}
```

### open<sup>8+</sup>

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

> **NOTE**
>
> - This API is deprecated since API version 9. Use [open](js-apis-photoAccessHelper.md#open-1) instead.
> - If a file is opened in 'w' mode, the returned FD cannot be used to read the file. However, due to the implementation differences of file systems, some user-mode files opened in 'w' mode can be read by using FD. To perform the read or write operation on a file by using FD, you are advised to open the file in 'rw' mode. 
> - The write operations are mutually exclusive. After a write operation is complete, you must call **close** to close the file.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the FD of the file opened.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let mediaType = mediaLibrary.MediaType.IMAGE;
  let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
  const path = await media.getPublicDirectory(DIR_IMAGE);
  const asset = await media.createAsset(mediaType, 'image00003.jpg', path);
  asset.open('rw').then((fd) => {
    console.info('File open fd: ' + fd);
  }).catch((error: BusinessError) => {
    console.error('File open failed with error: ' + error);
  });
}
```

### close<sup>8+</sup>

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes a file. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#close) instead.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | FD of the file to close.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.open('rw').then((fd) => {
    console.info('File open fd: ' + fd);
    asset.close(fd, (error) => {
      if (error) {
        console.error('asset.close failed with error: ' + error);
      } else {
        console.info('asset.close successfully');
      }
    });
  }).catch((error: BusinessError) => {
    console.error('File open failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### close<sup>8+</sup>

close(fd: number): Promise&lt;void&gt;

Closes a file. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#close-1) instead.

**Required permissions**: ohos.permission.READ_MEDIA or ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| fd   | number | Yes   | FD of the file to close.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.open('rw').then((fd) => {
    console.info('File fd!' + fd);
    asset.close(fd).then(() => {
      console.info('asset.close successfully');
    }).catch((closeErr) => {
      console.error('asset.close fail, closeErr: ' + closeErr);
    });
  }).catch((error: BusinessError) => {
    console.error('open File failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the thumbnail of this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#getThumbnail) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.getThumbnail((error, pixelmap) => {
    if (error) {
      console.error('mediaLibrary getThumbnail failed with error: ' + error);
    } else {
      console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));
    }
  });
  fetchFileResult.close();
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(size: Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the file thumbnail of the given size. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#getThumbnail-1) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [Size](#size8)                      | Yes   | Size of the thumbnail.           |
| callback | AsyncCallback&lt;image.PixelMap&gt; | Yes   | Callback invoked to return the PixelMap of the thumbnail.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let size: mediaLibrary.Size = { width: 720, height: 720 };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.getThumbnail(size, (error, pixelmap) => {
    if (error) {
      console.error('mediaLibrary getThumbnail failed with error: ' + error);
    } else {
      console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));
    }
  });
  fetchFileResult.close();
}
```

### getThumbnail<sup>8+</sup>

getThumbnail(size?: Size): Promise&lt;image.PixelMap&gt;

Obtains the file thumbnail of the given size. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#getThumbnail-2) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| size | [Size](#size8) | No   | Size of the thumbnail.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;image.PixelMap&gt; | Promise used to return the PixelMap of the thumbnail.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let size: mediaLibrary.Size = { width: 720, height: 720 };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.getThumbnail(size).then((pixelmap) => {
    console.info('mediaLibrary getThumbnail Successful, pixelmap ' + JSON.stringify(pixelmap));
  }).catch((error: BusinessError) => {
    console.error('mediaLibrary getThumbnail failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### favorite<sup>8+</sup>

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file asset. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [setFavorite](js-apis-photoAccessHelper.md#setfavorite) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.favorite(true,(error) => {
    if (error) {
      console.error('mediaLibrary favorite failed with error: ' + error);
    } else {
      console.info('mediaLibrary favorite Successful');
    }
  });
  fetchFileResult.close();
}
```

### favorite<sup>8+</sup>

favorite(isFavorite: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [setFavorite](js-apis-photoAccessHelper.md#setfavorite-1) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

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
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.favorite(true).then(() => {
    console.info('mediaLibrary favorite Successful');
  }).catch((error: BusinessError) => {
    console.error('mediaLibrary favorite failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### isFavorite<sup>8+</sup>

isFavorite(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is favorited. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description         |
| -------- | ---------------------------- | ---- | ----------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means the file asset is favorited; the value **false** means the opposite.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isFavorite((error, isFavorite) => {
    if (error) {
      console.error('mediaLibrary favoriisFavoritete failed with error: ' + error);
    } else {
      console.info('mediaLibrary isFavorite Successful, isFavorite result: ' + isFavorite);
    }
  });
  fetchFileResult.close();
}
```

### isFavorite<sup>8+</sup>

isFavorite():Promise&lt;boolean&gt;

Checks whether this file asset is favorited. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                    | Description                |
| ---------------------- | ------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the file asset is favorited; the value **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isFavorite().then((isFavorite) => {
    console.info('mediaLibrary isFavorite Successful, isFavorite result: ' + isFavorite);
  }).catch((error: BusinessError) => {
    console.error('mediaLibrary favoriisFavoritete failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### trash<sup>8+</sup>

trash(isTrash: boolean, callback: AsyncCallback&lt;void&gt;): void

Moves this file asset to the trash. This API uses an asynchronous callback to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper.md#deleteAssets) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description       |
| -------- | ------------------------- | ---- | --------- |
| isTrash  | boolean                   | Yes   | Whether to move the file asset to the trash.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.    |

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.trash(true, (error) => {
    if (error) {
      console.error('mediaLibrary trash failed with error: ' + error);
    } else {
      console.info('mediaLibrary trash Successful');
    }
  });
  fetchFileResult.close();
}
```

### trash<sup>8+</sup>

trash(isTrash: boolean): Promise&lt;void&gt;

Moves this file asset to the trash. This API uses a promise to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

> **NOTE**
>
> This API is deprecated since API version 9. Use [deleteAssets](js-apis-photoAccessHelper.md#deleteAssets-1) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name    | Type     | Mandatory  | Description       |
| ------- | ------- | ---- | --------- |
| isTrash | boolean | Yes   | Whether to move the file asset to the trash.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.trash(true).then(() => {
    console.info('trash successfully');
  }).catch((error: BusinessError) => {
    console.error('trash failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

### isTrash<sup>8+</sup>

isTrash(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is in the trash. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. The value **true** means the file is in the trash; the value **false** means the opposite.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isTrash((error, isTrash) => {
    if (error) {
      console.error('Failed to get trash state failed with error: ' + error);
      return;
    }
    console.info('Get trash state successfully, isTrash result: ' + isTrash);
  });
  fetchFileResult.close();
}
```

### isTrash<sup>8+</sup>

isTrash():Promise&lt;boolean&gt;

Checks whether this file asset is in the trash. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the result. The value **true** means the file is in the trash; the value **false** means the opposite.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  const fetchFileResult = await media.getFileAssets(getImageOp);
  const asset = await fetchFileResult.getFirstObject();
  asset.isTrash().then((isTrash) => {
    console.info('isTrash result: ' + isTrash);
  }).catch((error: BusinessError) => {
    console.error('isTrash failed with error: ' + error);
  });
  fetchFileResult.close();
}
```

## FetchFileResult<sup>7+</sup>

Provides APIs to manage the file retrieval result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [FetchResult](js-apis-photoAccessHelper.md#fetchresult) instead.

### getCount<sup>7+</sup>

getCount(): number

Obtains the total number of files in the result set.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getCount](js-apis-photoAccessHelper.md#getcount) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Returns the total number of files obtained.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let fileType = mediaLibrary.MediaType.FILE;
  let getFileCountOneOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getFileCountOneOp);
  const fetchCount = fetchFileResult.getCount();
  console.info('fetchCount result: ' + fetchCount);
  fetchFileResult.close();
}
```

### isAfterLast<sup>7+</sup>

isAfterLast(): boolean

Checks whether the cursor is in the last row of the result set.

> **NOTE**
>
> This API is deprecated since API version 9. Use [isAfterLast](js-apis-photoAccessHelper.md#isafterlast) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type     | Description                                |
| ------- | ---------------------------------- |
| boolean | Returns **true** if the cursor is in the last row of the result set; returns **false** otherwise.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  const fetchCount = fetchFileResult.getCount();
  console.info('mediaLibrary fetchFileResult.getCount, count:' + fetchCount);
  let fileAsset = await fetchFileResult.getFirstObject();
  for (let i = 1; i < fetchCount; i++) {
    fileAsset = await fetchFileResult.getNextObject();
    if(i == fetchCount - 1) {
      let result = fetchFileResult.isAfterLast();
      console.info('mediaLibrary fileAsset isAfterLast result: ' + result);
      fetchFileResult.close();
    }
  }
}
```

### close<sup>7+</sup>

close(): void

Releases and invalidates this **FetchFileResult** instance. After this instance is released, the APIs in this instance cannot be invoked.

> **NOTE**
>
> This API is deprecated since API version 9. Use [close](js-apis-photoAccessHelper.md#close) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.close();
}
```

### getFirstObject<sup>7+</sup>

getFirstObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the first file asset in the result set. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getFirstObject](js-apis-photoAccessHelper.md#getfirstobject) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback invoked to return the first **FileAsset** object in the result set.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getFirstObject((error, fileAsset) => {
    if (error) {
      console.error('fetchFileResult getFirstObject failed with error: ' + error);
      return;
    }
    console.info('getFirstObject successfully, displayName : ' + fileAsset.displayName);
    fetchFileResult.close();
  })
}
```

### getFirstObject<sup>7+</sup>

getFirstObject(): Promise&lt;FileAsset&gt;

Obtains the first file asset in the result set. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getFirstObject](js-apis-photoAccessHelper.md#getfirstobject-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the first **FileAsset** object in the result set.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getFirstObject().then((fileAsset) => {
    console.info('getFirstObject successfully, displayName: ' + fileAsset.displayName);
    fetchFileResult.close();
  }).catch((error: BusinessError) => {
    console.error('getFirstObject failed with error: ' + error);
  });
}
```

### getNextObject<sup>7+</sup>

getNextObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> - Before using this API, you must use [getFirstObject](#getfirstobject7) to obtain the first file asset and then use [isAfterLast](#isafterlast7) to check that the cursor does not point to the last file asset in the result set.
> - This API is deprecated since API version 9. Use [getNextObject](js-apis-photoAccessHelper.md#getnextobject) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback invoked to return the next **FileAsset** object in the result set.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  let fileAsset = await fetchFileResult.getFirstObject();
  console.log('fetchFileResult getFirstObject successfully, displayName: ' + fileAsset.displayName);
  if (!fetchFileResult.isAfterLast()) {
    fetchFileResult.getNextObject((error, fileAsset) => {
      if (error) {
        console.error('fetchFileResult getNextObject failed with error: ' + error);
        return;
      }
      console.log('fetchFileResult getNextObject successfully, displayName: ' + fileAsset.displayName);
      fetchFileResult.close();
    })
  }
}

```

### getNextObject<sup>7+</sup>

getNextObject(): Promise&lt;FileAsset&gt;

Obtains the next file asset in the result set. This API uses a promise to return the result.

> **NOTE**
>
> - Before using this API, you must use [getFirstObject](#getfirstobject7) to obtain the first file asset and then use [isAfterLast](#isafterlast7) to check that the cursor does not point to the last file asset in the result set.
> - This API is deprecated since API version 9. Use [getNextObject](js-apis-photoAccessHelper.md#getnextobject-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the next **FileAsset** object in the result set.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  let fileAsset = await fetchFileResult.getFirstObject();
  console.log('fetchFileResult getFirstObject successfully, displayName: ' + fileAsset.displayName);
  if (!fetchFileResult.isAfterLast()) {
    fetchFileResult.getNextObject().then((fileAsset) => {
      console.info('fetchFileResult getNextObject successfully, displayName: ' + fileAsset.displayName);
      fetchFileResult.close();
    }).catch((error: BusinessError) => {
      console.error('fetchFileResult getNextObject failed with error: ' + error);
    })
  }
}
```

### getLastObject<sup>7+</sup>

getLastObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the last file asset in the result set. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getLastObject](js-apis-photoAccessHelper.md#getlastobject) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                       |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes  | Callback invoked to return the last **FileAsset** object in the result set.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getLastObject((error, fileAsset) => {
    if (error) {
      console.error('getLastObject failed with error: ' + error);
      return;
    }
    console.info('getLastObject successfully, displayName: ' + fileAsset.displayName);
    fetchFileResult.close();
  })
}
```

### getLastObject<sup>7+</sup>

getLastObject(): Promise&lt;FileAsset&gt;

Obtains the last file asset in the result set. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getLastObject](js-apis-photoAccessHelper.md#getlastobject-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the last **FileAsset** object in the result set.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getLastObject().then((fileAsset) => {
    console.info('getLastObject successfully, displayName: ' + fileAsset.displayName);
    fetchFileResult.close();
  }).catch((error: BusinessError) => {
    console.error('getLastObject failed with error: ' + error);
  });
}
```

### getPositionObject<sup>7+</sup>

getPositionObject(index: number, callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains a file asset with the specified index in the result set. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getObjectByPosition](js-apis-photoAccessHelper.md#getobjectbyposition) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | Yes   | Index of the file to obtain. The value starts from 0 and must be smaller than the **count** value of the result set.    |
| callback | AsyncCallback&lt;[FileAsset](#fileasset7)&gt; | Yes   | Callback invoked to return the **FileAsset** object with the specified index obtained.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getPositionObject(0, (error, fileAsset) => {
    if (error) {
      console.error('getPositionObject failed with error: ' + error);
      return;
    }
    console.info('getPositionObject successfully, displayName: ' + fileAsset.displayName);
    fetchFileResult.close();
  })
}
```

### getPositionObject<sup>7+</sup>

getPositionObject(index: number): Promise&lt;FileAsset&gt;

Obtains a file asset with the specified index in the result set. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getObjectByPosition](js-apis-photoAccessHelper.md#getobjectbyposition-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name   | Type    | Mandatory  | Description            |
| ----- | ------ | ---- | -------------- |
| index | number | Yes   | Index of the file to obtain. The value starts from 0 and must be smaller than the **count** value of the result set.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset7)&gt; | Promise used to return the **FileAsset** object with the specified index obtained.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getPositionObject(0).then((fileAsset) => {
    console.info('getPositionObject successfully, displayName: ' + fileAsset.displayName);
    fetchFileResult.close();
  }).catch((error: BusinessError) => {
    console.error('getPositionObject failed with error: ' + error);
  });
}
```

### getAllObject<sup>7+</sup>

getAllObject(callback: AsyncCallback&lt;Array&lt;FileAsset&gt;&gt;): void

Obtains all the file assets in the result set. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getAllObjects](js-apis-photoAccessHelper.md#getallobjects) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                  |
| -------- | ---------------------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;Array&lt;[FileAsset](#fileasset7)&gt;&gt; | Yes   | Callback invoked to return all the **FileAsset** objects in the result reset.|

**Example**

```ts
async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getAllObject((error, fileAssetList) => {
    if (error) {
      console.error('getAllObject failed with error: ' + error);
      return;
    }
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
      console.info('getAllObject fileAssetList ' + i + ' displayName: ' + fileAssetList[i].displayName);
    }
    fetchFileResult.close();
  })
}
```

### getAllObject<sup>7+</sup>

getAllObject(): Promise&lt;Array&lt;FileAsset&gt;&gt;

Obtains all the file assets in the result set. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getAllObjects](js-apis-photoAccessHelper.md#getallobjects-1) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                                    | Description                 |
| ---------------------------------------- | --------------------- |
| Promise&lt;Array&lt;[FileAsset](#fileasset7)&gt;&gt; | Promise used to return all the **FileAsset** objects in the result reset.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  let fileKeyObj = mediaLibrary.FileKey;
  let imageType = mediaLibrary.MediaType.IMAGE;
  let getImageOp: mediaLibrary.MediaFetchOptions = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
    order: fileKeyObj.DATE_ADDED + ' DESC',
  };
  let fetchFileResult = await media.getFileAssets(getImageOp);
  fetchFileResult.getAllObject().then((fileAssetList) => {
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
      console.info('getAllObject fileAssetList ' + i + ' displayName: ' + fileAssetList[i].displayName);
    } 
    fetchFileResult.close();
  }).catch((error: BusinessError) => {
    console.error('getAllObject failed with error: ' + error);
  });
}
```

## Album<sup>7+</sup>

Provides APIs to manage albums.

> **NOTE**
>
> This API is deprecated since API version 9. Use [Album](js-apis-photoAccessHelper.md#album) instead.

### Attributes

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name          | Type   | Readable  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumId | number | Yes   | No   | Album ID.   |
| albumName | string | Yes   | Yes   | Name of the album.   |
| albumUri<sup>8+</sup> | string | Yes   | No   | URI of the album.  |
| dateModified | number | Yes   | No   | Date when the album was last modified.   |
| count<sup>8+</sup> | number | Yes   | No   | Number of files in the album.|
| relativePath<sup>8+</sup> | string | Yes   | No   | Relative path of the album.   |
| coverUri<sup>8+</sup> | string | Yes   | No   | URI of the cover file of the album.|

### commitModify<sup>8+</sup>

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the album attributes to the database.

> **NOTE**
>
> This API is deprecated since API version 9. Use [commitModify](js-apis-photoAccessHelper.md#commitmodify-2) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
async function example() {
  // To obtain the file assets in an album, you must preset the album and resources. The sample code below presets 'New Album 1'.
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs:['New Album 1'],
  };
  const albumList = await media.getAlbums(albumFetchOp);
  const album = albumList[0];
  album.albumName = 'hello';
  album.commitModify((error) => {
    if (error) {
      console.error('commitModify failed with error: ' + error);
      return;
    }
    console.info('commitModify successful.');
  });
}
```

### commitModify<sup>8+</sup>

commitModify(): Promise&lt;void&gt;

Commits the modification on the album attributes to the database.

> **NOTE**
>
> This API is deprecated since API version 9. Use [commitModify](js-apis-photoAccessHelper.md#commitmodify-3) instead.

**Required permissions**: ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  // To obtain the file assets in an album, you must preset the album and resources. The sample code below presets 'New Album 1'.
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs:['New Album 1'],
  };
  const albumList = await media.getAlbums(albumFetchOp);
  const album = albumList[0];
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info('commitModify successfully');
  }).catch((error: BusinessError) => {
    console.error('commitModify failed with error: ' + error);
  });
}
```

### getFileAssets<sup>7+</sup>

getFileAssets(callback: AsyncCallback&lt;FetchFileResult&gt;): void

Obtains the file assets in this album. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getAssets](js-apis-photoAccessHelper.md#getassets) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult7)> | Yes  | Callback invoked to return the file retrieval result set of the album.|

**Example**

```ts
async function example() {
  // To obtain the file assets in an album, you must preset the album and resources. The sample code below presets 'New Album 1'.
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs:['New Album 1'],
  };
  // Obtain the albums that meet the retrieval options and return the album list.
  const albumList = await media.getAlbums(albumFetchOp);
  const album = albumList[0];
  // Obtain an album from the album list and obtain all media assets that meet the retrieval options in the album.
  album.getFileAssets((error, fetchFileResult) => {
    if (error) {
      console.error('album getFileAssets failed with error: ' + error);
      return;
    }
    let count = fetchFileResult.getCount();
    console.info('album getFileAssets successfully, count: ' + count);
    fetchFileResult.close();
  });
}
```

### getFileAssets<sup>7+</sup>

getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void

Obtains the file assets in this album based on specified conditions. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getAssets](js-apis-photoAccessHelper.md#getassets) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| options  | [MediaFetchOptions](#mediafetchoptions7)            | Yes  | Options for fetching the files.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult7)> | Yes  | Callback invoked to return the file retrieval result set of the album.|

**Example**

```ts
async function example() {
  // To obtain the file assets in an album, you must preset the album and resources. The sample code below presets 'New Album 1'.
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs:['New Album 1'],
  };
  let fileNoArgsfetchOp: mediaLibrary.MediaFetchOptions = {
    selections: '',
    selectionArgs: [],
  };
  // Obtain the albums that meet the retrieval options and return the album list.
  const albumList = await media.getAlbums(albumFetchOp);
  const album = albumList[0];
  // Obtain an album from the album list and obtain all media assets that meet the retrieval options in the album.
  album.getFileAssets(fileNoArgsfetchOp, (error, fetchFileResult) => {
    if (error) {
      console.error('album getFileAssets failed with error: ' + error);
      return;
    }
    let count = fetchFileResult.getCount();
    console.info('album getFileAssets successfully, count: ' + count);
    fetchFileResult.close();
  });
}
```

### getFileAssets<sup>7+</sup>

 getFileAssets(options?: MediaFetchOptions): Promise&lt;FetchFileResult&gt;

Obtains the file assets in this album based on specified conditions. This API uses a promise to return the result.

> **NOTE**
>
> This API is deprecated since API version 9. Use [getAssets](js-apis-photoAccessHelper.md#getassets-1) instead.

**Required permissions**: ohos.permission.READ_MEDIA

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

**Parameters**

| Name | Type                                    | Mandatory| Description          |
| ------- | ---------------------------------------- | ---- | -------------- |
| options | [MediaFetchOptions](#mediafetchoptions7) | No  | Options for fetching the files.|

**Return value**

| Type                                         | Description                     |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult7)> | Promise used to return the file retrieval result set of the album.|

**Example**

```ts
import { BusinessError } from '@ohos.base';

async function example() {
  // To obtain the file assets in an album, you must preset the album and resources. The sample code below presets 'New Album 1'.
  let albumFetchOp: mediaLibrary.MediaFetchOptions = {
    selections: mediaLibrary.FileKey.ALBUM_NAME + '= ?',
    selectionArgs:['New Album 1'],
  };
  let fileNoArgsfetchOp: mediaLibrary.MediaFetchOptions = {
    selections: '',
    selectionArgs: [],
  };
  // Obtain the albums that meet the retrieval options and return the album list.
  const albumList = await media.getAlbums(albumFetchOp);
  const album = albumList[0];
  // Obtain an album from the album list and obtain all media assets that meet the retrieval options in the album.
  album.getFileAssets(fileNoArgsfetchOp).then((fetchFileResult) => {
    let count = fetchFileResult.getCount();
    console.info('album getFileAssets successfully, count: ' + count);
    fetchFileResult.close();
  }).catch((error: BusinessError) => {
    console.error('album getFileAssets failed with error: ' + error);
  });
}
```

## PeerInfo<sup>8+</sup>

Defines information about a registered device.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name      | Type                      | Readable| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| deviceType | [DeviceType](#devicetype8) | Yes  | No  | Type of the registered device.        |
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online.        |

## MediaType<sup>8+</sup>

Enumerates media types.

> **NOTE**
>
> This API is deprecated since API version 9. Use [PhotoType](js-apis-photoAccessHelper.md#phototype) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name |  Value|  Description|
| ----- |  ---- | ---- |
| FILE  |  0 | File.|
| IMAGE |  1 | Image.|
| VIDEO |  2 | Video.|
| AUDIO |  3 | Audio.|

## FileKey<sup>8+</sup>

Enumerates key file information.

> **NOTE**
>
> - The **bucket_id** field may change after file rename or movement. Therefore, you must obtain the field again before using it.
> - This API is deprecated since API version 9. Use [PhotoKeys](js-apis-photoAccessHelper.md#photokeys) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| ID            | 'file_id'             | File ID.                                                  |
| RELATIVE_PATH | 'relative_path'       | Relative path of the user directory.                                          |
| DISPLAY_NAME  | 'display_name'        | File name displayed.                                                  |
| PARENT        | 'parent'              | Parent directory ID.                                                  |
| MIME_TYPE     | 'mime_type'           | Extended file attributes, such as image/, video/, and file/*.                                            |
| MEDIA_TYPE    | 'media_type'          | Media type.                                                  |
| SIZE          | 'size'                | File size, in bytes.                                    |
| DATE_ADDED    | 'date_added'          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | 'date_modified'       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| DATE_TAKEN    | 'date_taken'          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.            |
| TITLE         | 'title'               | Title in the file.                                                  |
| ARTIST        | 'artist'              | Artist of the file.                                                      |
| AUDIOALBUM    | 'audio_album'         | Audio album.                                                      |
| DURATION      | 'duration'            | Duration, in ms.                                      |
| WIDTH         | 'width'               | Image width, in pixels.                                    |
| HEIGHT        | 'height'              | Image height, in pixels.                                    |
| ORIENTATION   | 'orientation'         | Image display direction (clockwise rotation angle, for example, 0, 90, and 180, in degrees).|
| ALBUM_ID      | 'bucket_id'           | ID of the album to which the file belongs.                                      |
| ALBUM_NAME    | 'bucket_display_name' | Name of the album to which the file belongs.                                        |

## DirectoryType<sup>8+</sup>

Enumerates directory types.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name         | Value|  Description              |
| ------------- | --- | ------------------ |
| DIR_CAMERA    |  0 | Directory of camera files.|
| DIR_VIDEO     |  1 |  Directory of video files.      |
| DIR_IMAGE     |  2 | Directory of image files.      |
| DIR_AUDIO     |  3 | Directory of audio files.      |
| DIR_DOCUMENTS |  4 | Directory of documents.      |
| DIR_DOWNLOAD  |  5 |  Download directory.      |

## DeviceType<sup>8+</sup>

Enumerates the device types.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System API**: This is a system API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.DistributedCore

| Name        |  Value| Description      |
| ------------ | --- | ---------- |
| TYPE_UNKNOWN |  0 | Unknown.|
| TYPE_LAPTOP  |  1 | Laptop.|
| TYPE_PHONE   |  2 | Phone.      |
| TYPE_TABLET  |  3 | Tablet.  |
| TYPE_WATCH   |  4 | Smart watch.  |
| TYPE_CAR     |  5 | Vehicle-mounted device.  |
| TYPE_TV      |  6 | TV.  |

## MediaFetchOptions<sup>7+</sup>

Defines the options for fetching media files.

> **NOTE**
>
> This API is deprecated since API version 9. Use [FetchOptions](js-apis-photoAccessHelper.md#fetchoptions) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name                   | Type               | Readable| Writable| Description                                                        |
| ----------------------- | ------------------- | ---- | ---- | ------------------------------------------------------------ |
| selections              | string              | Yes  | Yes  | Conditions for fetching files. The enumerated values in [FileKey](#filekey8) are used as the column names when files are fetched. <br/>Example:<br>selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ? OR ' + mediaLibrary.FileKey.MEDIA_TYPE + '= ?', |
| selectionArgs           | Array&lt;string&gt; | Yes  | Yes  | Values of the conditions specified in **selections**.<br>Example:<br>selectionArgs: [mediaLibrary.MediaType.IMAGE.toString(), mediaLibrary.MediaType.VIDEO.toString()], |
| order                   | string              | Yes  | Yes  | Sorting mode of the search results, which can be ascending or descending. The enumerated values in [FileKey](#filekey8) are used as the columns for sorting the search results. <br/>Example:<br>Ascending: order: mediaLibrary.FileKey.DATE_ADDED + ' ASC'<br>Descending: order: mediaLibrary.FileKey.DATE_ADDED + ' DESC' |
| uri<sup>8+</sup>        | string              | Yes  | Yes  | URI of the file.                                                     |
| networkId<sup>8+</sup>  | string              | Yes  | Yes  | Network ID of the registered device.                                              |
| extendArgs<sup>8+</sup> | string              | Yes  | Yes  | Extended parameters for fetching the files. Currently, no extended parameters are available.                        |

## Size<sup>8+</sup>

Defines the image size.

> **NOTE**
>
> This API is deprecated since API version 9. Use [image.Size](js-apis-image.md#size) instead.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name    | Type    | Readable  | Writable  | Description      |
| ------ | ------ | ---- | ---- | -------- |
| width  | number | Yes   | Yes   | Image width, in pixels.|
| height | number | Yes   | Yes   | Image height, in pixels.|

## MediaAssetOption

Defines the media asset option.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name        | Type  | Readable| Writable| Description                                                        |
| ------------ | ------ | ---- | ---- | ------------------------------------------------------------ |
| src          | string | Yes  | Yes  | Application sandbox oath of the local file.                                      |
| mimeType     | string | Yes  | Yes  | Multipurpose Internet Mail Extensions (MIME) type of the media.<br>The value can be **'image/\*'**, **'video/\*'**, **'audio/\*'**, or **'file/\*'**.|
| relativePath | string | Yes  | Yes  | Customized path of media assets, for example, **Pictures/**. If this parameter is unspecified, the default paths of media assets are as follows:<br>Default path of images: **'Pictures/'**<br>Default path of videos: **'Videos/'**<br>Default path of audio files: **'Audios/'**<br>Default path of documents: **'Documents/'** |

## MediaSelectOption

Defines the media selection option.

> **NOTE**
>
> This API is deprecated since API version 9. There is no substitute API.

**System capability**: SystemCapability.Multimedia.MediaLibrary.Core

| Name   | Type    | Readable| Writable| Description                  |
| ----- | ------ | ---- | ---- | -------------------- |
| type  | 'image' &#124; 'video' &#124; 'media' | Yes   | Yes | Media type, which can be **image**, **media**, or **video**. Currently, only **media** is supported.|
| count | number | Yes   | Yes | Maximum number of media assets that can be selected.<br>The value **1** means to select only one media asset; the value greater than **1** means to select multiple media assets.           |
