# User Data Management

> **NOTE**<br/>
> This module is supported since API Version 9. Updates will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import userFileManager from '@ohos.filemanagement.userfile_manager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

Obtains a **UserFileManager** instance. This instance can be used to access and modify user media data (such as audio and video files, images, and documents).

**Model restriction**: This API can be used only in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type   | Mandatory| Description                      |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](#../apis/js-apis-Context.md) | Yes  | Context of the ability instance.|

**Return value**

| Type                           | Description   |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | **UserFileManager** instance obtained.|

**Example**

```ts
const context = getContext(this);
let userFileMgr = userfilemanager.getUserFileMgr(context);
```

## userFileManager.getUserFileMgr

getUserFileMgr(): UserFileManager

Obtains a **UserFileManager** instance.This instance can be used to access and modify user media data (such as audio and video clips, images, and documents).

**Model restriction**: This API can be used only in the FA model.

> **NOTE**<br>You are advised to use [UserFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr), the API used in the stage model.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                         | Description      |
| ----------------------------- | :--------- |
| [UserFileManager](#userfilemanager) | **UserFileManager** instance obtained.|

**Example**

```js
let userFileMgr = userfilemanager.getUserFileMgr();
```

## UserFileManager

### getPublicDirectory

getPublicDirectory(type: DirectoryType, callback: AsyncCallback&lt;string>): void;

Obtains the preset public directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type     | [DirectoryType](#directorytype)            | Yes  | Type of the public directory.             |
| callback | AsyncCallback&lt;string> | Yes  | Callback invoked to return the public directory.|

**Example**

```ts
async function getPublicDirectoryDemoCallback() {
    console.info('getPublicDirectoryDemo');
    let DIR_CAMERA = directoryType.DIR_CAMERA;
    console.info('DIR_CAMERA', DIR_CAMERA);
    userFileMgr.getPublicDirectory(DIR_CAMERA, (err, dicResult) => {
        if (dicResult == 'Camera/') {
            console.info('mediaLibraryTest : getPublicDirectory passed');
        } else {
            console.info('mediaLibraryTest : getPublicDirectory failed');
        }
    });
}
```

### getPublicDirectory

getPublicDirectory(type: DirectoryType): Promise&lt;string>;

Obtains the preset public directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name| Type         | Mandatory| Description        |
| ------ | ------------- | ---- | ------------ |
| type   | [DirectoryType](#directorytype) | Yes  | Type of the public directory.|

**Return value**

| Type            | Description            |
| ---------------- | ---------------- |
| Promise\<string> | Promise used to return the public directory.|

**Example**

```ts
async function getPublicDirectoryDemoPromise() {
    console.info('getPublicDirectoryDemo');
    let DIR_CAMERA = directoryType.DIR_CAMERA;
    try {
    let dicResult = await userFileMgr.getPublicDirectory(DIR_CAMERA);
        console.info('mediaLibraryTest : getPublicDirectory passed, result = ', dicResult);
    } catch (err) {
        console.info('mediaLibraryTest : getPublicDirectory failed, message = ', err);
    }
}
```

### getFileAssets

getFileAssets(type: Array&lt;MediaType>, options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult>): void;

Obtains file assets. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type     | Array&lt;[MediaType](#mediatype)>      | Yes  | Type of the media data to obtain.         |
| options  | [MediaFetchOptions](#mediafetchoptions)        | Yes  | Options for fetching the files.             |
| callback | AsyncCallback&lt;string> | Yes  | Callback invoked to return the file assets obtained.|

**Example**

```ts
async function getFileAssetsDemoCallback() {
    console.info('getFileAssets');
    let fileKeyObj = userfile_manager.FileKey
    let imageType = userfile_manager.MediaType.IMAGE
    let fetchOp = {
        selections: '',
        selectionArgs: [],
    };

    userFileMgr.getFileAssets([imageType, ], fetchOp, async (err, fetchFileResult) => {
        if (fetchFileResult != undefined) {
            console.info('fetchFileResult success');
            let fileAsset = await fetchFileResult.getFirstObject();
            if (fileAsset != undefined) {
                console.info("fileAsset.displayName :" + fileAsset.displayName);
            };
        }
    })
}
```

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, options: MediaFetchOptions): Promise&lt;FetchFileResult>;

Obtains file assets. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**Parameters**

| Name | Type               | Mandatory| Description            |
| ------- | ------------------- | ---- | ---------------- |
| type    | Array&lt;[MediaType](#mediatype)> | Yes  | Type of the media type to obtain.|
| options | [MediaFetchOptions](#mediafetchoptions)   | Yes  | Options for fetching the files.    |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchFileResult](#fetchfileresult)> | Promise used to return the file assets obtained.|

**Example**

```ts
async function getFileAssetsDemoPromise() {
    console.info('getFileAssets');
    let fileKeyObj = userfile_manager.FileKey
    let imageType = userfile_manager.MediaType.IMAGE
    let fetchOp = {
        selections: '',
        selectionArgs: [],
    };
    try {
        var fetchFileResult = await userFileMgr.getFileAssets([imageType, ], fetchOp)
    } catch (err) {
        console.info('getFileAssets failed, message = ', err);
    }

    if (fetchFileResult != undefined) {
        console.info('fetchFileResult success');
        let fileAsset = await fetchFileResult.getFirstObject();
        if (fileAsset != undefined) {
            console.info("fileAsset.displayName :" + fileAsset.displayName);
        };
    }
}
```

### on

on(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback: Callback&lt;void&gt;): void

Subscribes to changes of the file management library. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Media type to subscribe to.<br>**deviceChange** indicates the device change.<br>**albumChange** indicates the album change.<br>**imageChange** indicates the image change.<br>**audioChange** indicates the audio file change.<br>**videoChange** indicates the video file change.<br>**fileChange** indicates the file change.<br>**remoteFileChange** indicates the file change on the registered device.|
| callback | Callback&lt;void&gt; | Yes  | Callback that returns no value.                                                  |

**Example**

```ts
async function onDemo() {
    console.info('onDemo')
    userFileMgr.on('imageChange', () => {
      // Image file changes. Do something.
    });
}
```

### off

off(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback?: Callback&lt;void&gt;): void

Unsubscribes from changes of the file management library. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | Yes  | Media type to unsubscribe from.<br>**deviceChange** indicates the device change.<br>**albumChange** indicates the album change.<br>**imageChange** indicates the image change.<br>**audioChange** indicates the audio file change.<br>**videoChange** indicates the video file change.<br>**fileChange** indicates the file change.<br>**remoteFileChange** indicates the file change on the registered device.|
| callback | Callback&lt;void&gt; | No  | Callback that returns no value.                                                  |

**Example**

```ts
async function offDemo() {
    console.info('offDemo')
    userFileMgr.off('imageChange', () => {
      // stop listening success
    });
}
```

### createAsset

createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void

Creates a file asset. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**Parameters**

| Name      | Type                       | Mandatory| Description                                                        |
| ------------ | --------------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype)      | Yes  | Media type.                                                    |
| displayName  | string                      | Yes  | File name to display.                                                  |
| relativePath | string                      | Yes  | File path. You can use **getPublicDirectory()** to obtain the paths for different types of files.|
| callback     | AsyncCallback&lt;[FileAsset](#fileasset)> | Yes  | Callback invoked to return the file asset created.                         |

**Example**

```ts
async function createAssetDemoCallback() {
    console.info('createAssetDemo')
    let mediaType = userfile_manager.MediaType.FILE;
    let DIR_DOC = directoryType.DIR_DOCUMENTS;
    const path = await userFileMgr.getPublicDirectory(DIR_DOC);
    userFileMgr.createAsset(mediaType, 'tesfFile.txt', path + 'myDirectory/', (err, fileAsset) => {
      if (err == undefined) {
          console.info('createAsset successfully');
      } else {
          console.info('createAsset failed, message = ', err);
      }
    })
}
```

### createAsset

createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset>;

Creates a file asset. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**Parameters**

| Name      | Type     | Mandatory| Description                                                        |
| ------------ | --------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype) | Yes  | Media type.                                                    |
| displayName  | string    | Yes  | File name to display.                                                  |
| relativePath | string    | Yes  | File path. You can use **getPublicDirectory()** to obtain the paths for different types of files.|

**Return value**

| Type                 | Description             |
| --------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)> | Promise used to return the file asset created.|

**Example**

```ts
async function createAssetDemoPromise() {
    console.info('createAssetDemo')
    let mediaType = userfile_manager.MediaType.FILE;
    let DIR_DOC = directoryType.DIR_DOCUMENTS;
    const path = await userFileMgr.getPublicDirectory(DIR_DOC);
    try {
        let fileAsset = await userFileMgr.createAsset(mediaType, 'tesfFile.txt', path + 'myDirectory/')
      console.info('createAsset successfully');
    } catch (err) {
        console.info('createAsset failed, message = ', err);
    }
}
```

### deleteAsset

deleteAsset(uri: string, callback: AsyncCallback&lt;void>): void;

Deletes a file asset. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**Parameters**

| Name  | Type                       | Mandatory| Description                  |
| -------- | --------------------------- | ---- | ---------------------- |
| uri      | string                      | Yes  | URI of the file to delete.               |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)> | Yes  | Callback invoked to return the result.|

**Example**

```ts
async function deleteAssetDemoCallback() {
    console.info('deleteAssetDemo')
    let fileKeyObj = userfile_manager.FileKey
    let fileType = userfile_manager.MediaType.FILE
    let option = {
        selections: '',
        selectionArgs: [],
    };
    try {
        const fetchFileResult = await userFileMgr.getFileAssets([fileType, ], option);
        var asset = await fetchFileResult.getFirstObject();
    } catch(err) {
        console.info('fetch failed, message =', err)
    }

    if (asset == undefined) {
        console.error('asset not exist')
        return
    }
    userFileMgr.deleteAsset(asset.uri, (err) => {
        if (err == undefined) {
            console.info("deleteAsset successfully");
        } else {
            console.info("deleteAsset failed with error:"+ err);
        }
    });
}
```

### deleteAsset

deleteAsset(uri: string): Promise&lt;void>;

Deletes a file asset. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**Parameters**

| Name| Type  | Mandatory| Description   |
| ------ | ------ | ---- | ------- |
| uri    | string | Yes  | URI of the file to delete.|

**Return value**

| Type            | Description                             |
| ---------------- | --------------------------------- |
| Promise&lt;void> | Promise used to return the result.|

**Example**

```ts
async function deleteAssetDemoPromise() {
    console.info('deleteAssetDemo')
    let fileKeyObj = userfile_manager.FileKey
    let fileType = userfile_manager.MediaType.FILE
    let option = {
        selections: '',
        selectionArgs: [],
    };
    try {
        const fetchFileResult = await userFileMgr.getFileAssets([fileType, ], option);
        var asset = await fetchFileResult.getFirstObject();
    } catch(err) {
        console.info('fetch failed, message =', err)
    }
    if (asset == undefined) {
        console.error('asset not exist')
        return
    }
    try {
        await userFileMgr.deleteAsset(asset.uri);
        console.info("deleteAsset successfully");
    } catch (err) {
        console.info("deleteAsset failed with error:"+ err);
    }
}
```

### getAlbums

getAlbums(type: Array&lt;MediaType&gt;, options: MediaFetchOptions, callback: AsyncCallback<Array&lt;Album&gt;&gt;): void;

Obtains albums. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                       |
| -------- | ------------------------------------ | ---- | --------------------------- |
| type     | Array&lt;[MediaType](#mediatype)>                  | Yes  | Type of the media data to obtain.       |
| options  | [MediaFetchOptions](#mediafetchoptions)                    | Yes  | Options for fetching the albums.               |
| callback | AsyncCallback&lt;Array&lt;[Album](#album)>&gt; | Yes  | Callback invoked to return the album list.|

**Example**

```ts
async function getAlbumsDemoCallback() {
    console.info('getAlbumsDemo')
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    userFileMgr.getAlbums([userfile_manager.MediaType.IMAGE], AlbumNoArgsfetchOp, (err, albumList) => {
        if (albumList != undefined) {
            const album = albumList[0];
            console.info('first album.albumName = ' + album.albumName);
            console.info('album.count = ' + albumList.length);
        } else {
            console.info('getAlbum fail, message = ' + err);
        }
    })
}
```

### getAlbums

getAlbums(type: Array&lt;MediaType>, options: MediaFetchOptions): Promise<Array&lt;Album>>;

Obtains albums. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type               | Mandatory| Description                |
| ------- | ------------------- | ---- | -------------------- |
| type    | Array&lt;[MediaType](#mediatype)> | Yes  | Type of the media data to obtain.|
| options | [MediaFetchOptions](#mediafetchoptions)   | Yes  | Options for fetching the albums.        |

**Return value**

| Type                    | Description                      |
| ------------------------ | -------------------------- |
| Promise<Array&lt;[Album](#album)>> | Promise used to return the album list.|

**Example**

```ts
async function getAlbumsDemoPromise() {
    console.info('getAlbumsDemo')
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    try {
        let albumList = await userFileMgr.getAlbums([userfile_manager.MediaType.IMAGE], AlbumNoArgsfetchOp);
        const album = albumList[0];
        console.info('first album.albumName = ' + album.albumName);
        console.info('album.count = ' + albumList.length);
    } catch (err) {
        console.info('getAlbum fail, message = ' + err);
    }
}
```

### getPrivateAlbum

getPrivateAlbum(type: VirtualAlbumType, callback: AsyncCallback<Array&lt;VirtualAlbum&gt;>): void

Obtains the system album. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**Parameters**

| Name  | Type                                 | Mandatory| Description                              |
| -------- | ------------------------------------- | ---- | ---------------------------------- |
| type     | [VirtualAlbumType](#virtualalbumtype)                      | Yes  | Type of the album to obtain.                      |
| callback | AsyncCallback<Array&lt;[VirtualAlbum](#virtualalbum)>> | Yes  | Callback invoked to return the system album obtained.|

**Example**

```ts
async function getPrivateAlbumDemoCallback() {
    console.info('getPrivateAlbumDemo')
    userFileMgr.getPrivateAlbum(userfile_manager.VirtualAlbumType.TYPE_TRASH, async (err, albumArray) => {
        if (err == undefined) {
            console.info('getPrivateAlbum ok');
            try {
                let fetchOpt = {
                    selections: '',
                    selectionArgs: [],
                };
                let trashAlbum = albumArray[0];
                var fetchResult = await trashAlbum.getFileAssets([userfile_manager.MediaType.IMAGE], fetchOpt);
            } catch (err) {
                console.info('getFileAssets failed. message = ', err);
            }
            // Get file count in trash album
            let count = fetchResult.getCount();
            console.info('fetchResult count = ', count)
            // Get fileAssets in trash album
            let trashAsset = await fetchResult.getFirstObject();
            // Get file trashed date
            let isTrash = trashAsset.isTrash();
            console.info('is trashed', isTrash)
        } else {
            console.info('getPrivateAlbum failed. message = ', err);
        }
    });
}
```

### getPrivateAlbum

getPrivateAlbum(type: VirtualAlbumType):  Promise<Array&lt;VirtualAlbum&gt;>

Obtains the system album. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**Parameters**

| Name| Type            | Mandatory| Description        |
| ------ | ---------------- | ---- | ------------ |
| type   | [VirtualAlbumType](#virtualalbumtype) | Yes  | Type of the album to obtain.|

**Return value**

| Type                           | Description                             |
| ------------------------------- | --------------------------------- |
| Promise<Array&lt;[VirtualAlbum](#virtualalbum)>> | Promise used to return the system album obtained.|

**Example**

```ts
async function getPrivateAlbumDemoPromise() {
    console.info('getPrivateAlbumDemo');
    try {
        var albumArray = await userFileMgr.getPrivateAlbum(userfile_manager.VirtualAlbumType.TYPE_TRASH);
    } catch(err) {
        console.info('getPrivateAlbum failed. message = ', err);
    }
    try {
        let fetchOpt = {
            selections: '',
            selectionArgs: [],
        };
        let trashAlbum = albumArray[0];
        var fetchResult = await trashAlbum.getFileAssets([userfile_manager.MediaType.IMAGE], fetchOpt);
    } catch (err) {
        console.info('getFileAssets failed. message = ', err);
    }
    // Get file count in trash album
    let count = fetchResult.getCount();
    console.info('fetchResult count = ', count)
    // Get fileAssets in trash album
    let trashAsset = await fetchResult.getFirstObject();

    // Get file trashed date
    let isTrash = trashAsset.isTrash();
    console.info('is trashed', isTrash)
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback<Array&lt;PeerInfo>>): void;

Obtains information about online peer devices. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback<Array<[PeerInfo](#peerinfo)>> | Yes  | Callback invoked to return the online device list.|

**Example**

```ts
async function getActivePeersDemoCallback() {
    console.info('getActivePeersDemo')
    var devicesInfo = userFileMgr.getActivePeers((err, devicesInfo) => {
        if (err == undefined) {
            console.log('getActivePeers succeed.')
            for (let i = 0; i < devicesInfo.length; i++) {
                console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('getActivePeers failed. message = ', err)
        }
    });
}
```

### getActivePeers

getActivePeers(): Promise<Array&lt;PeerInfo>>;

Obtains information about online peer devices. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise<Array<[PeerInfo](#peerinfo)>> | Promise used to return the online device list.|

**Example**

```ts
async function getActivePeersDemoPromise() {
    console.info('getActivePeersDemo')
    try {
        var devicesInfo = await userFileMgr.getActivePeers();
    } catch (err) {
        console.info('getActivePeers failed. message = ', err)
    }
    if (devicesInfo != undefined) {
        console.log('getActivePeers succeed.')
        for (let i = 0; i < devicesInfo.length; i++) {
            console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
        }
    } else {
        console.info('get distributed fail')
    }
}
```

### getAllPeers

getAllPeers(callback: AsyncCallback<Array&lt;PeerInfo>>): void;

Obtains information about all peer devices. This API uses an asynchronous callback to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Parameters**

| Name  | Type                             | Mandatory| Description        |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback<Array&lt;[PeerInfo](#peerinfo)>> | Yes  | Callback invoked to return the peer device list.|

**Example**

```ts
async function getAllPeersDemoCallback() {
    console.info('getAllPeersDemo')
    var devicesInfo = await userFileMgr.getAllPeers((err, devicesInfo) => {
        if (err == undefined) {
            console.log('getAllPeers succeed.')
            for (let i = 0; i < devicesInfo.length; i++) {
                console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
            }
        } else {
            console.info('getAllPeers failed. message = ', err)
        }
    });
}
```

### getAllPeers

getAllPeers(): Promise<Array&lt;PeerInfo>>;

Obtains information about all peer devices. This API uses a promise to return the result.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

**Return value**

| Type                       | Description                         |
| --------------------------- | ----------------------------- |
| Promise<Array&lt;[PeerInfo](#peerinfo)>> | Promise used to return the peer device list.|

**Example**

```ts
async function getAllPeersDemoPromise() {
    console.info('getAllPeersDemo')
    try {
        var devicesInfo = await userFileMgr.getAllPeers();
    } catch (err) {
        console.info('getAllPeers failed. message = ', err)
    }
    if (devicesInfo != undefined) {
        console.log('getAllPeers succeed.')
        for (let i = 0; i < devicesInfo.length; i++) {
            console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
        }
    } else {
        console.info('get distributed fail')
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
async function releaseDemoCallback() {
    console.info('releaseDemo');
    userFileMgr.release((err) => {
        if (err != undefined) {
            console.info('release failed. message = ', err);
        } else {
            console.info('release ok.');
        }
    })
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
| Promise&lt;void&gt; | Promise used to return the result.|

**Example**

```ts
async function releaseDemoPromise() {
    console.info('releaseDemo');
    try {
        await userFileMgr.release();
        console.info('release ok.');
    } catch (err) {
        console.info('release failed. message = ', err);
    }
}
```

## FileAsset

Provides APIs for encapsulating file asset attributes.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | Yes  | No  | File asset URI, for example, **dataability:///media/image/2**.        |
| mediaType   | [MediaType](#mediatype) | Yes  | No  | Media type.                                              |
| displayName               | string                   | Yes  | Yes  | File name, including the file name extension, to display.                                |


### isDirectory

isDirectory(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is a directory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description                 |
| -------- | ---------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the file asset is a directory, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isDirectory((err, isDirectory) => {
        // do something
    });
}
```

### isDirectory

isDirectory():Promise&lt;boolean&gt;

Checks whether this file asset is a directory. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                    | Description                          |
| ---------------------- | ---------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If the file asset is a directory, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = userfile_manager.FileKey
    let imageType = userfile_manager.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isDirectory().then(function(isDirectory){
        console.info("isDirectory result:"+ isDirectory);
    }).catch(function(err){
        console.info("isDirectory failed with error:"+ err);
    });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

Commits the modification on the file metadata to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.title = 'newtitle';
    asset.commitModify(() => {
        console.info('commitModify success');   
    });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

Commits the modification on the file metadata to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.title = 'newtitle';
    asset.commitModify();
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

Opens this file asset. This API uses an asynchronous callback to return the result.

**NOTE**<br>Currently, the write operations are mutually exclusive. After a write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, ohos.permission.READ_DOCUMENT, ohos.permission.WRITE_MEDIA, ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT


**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                         | Mandatory  | Description                                 |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback used to return the file handle.                           |

**Example**

```js
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const path = await userFileMgr.getPublicDirectory(DIR_IMAGE);
    const asset = await userFileMgr.createAsset(mediaType, "image00003.jpg", path);
    asset.open('rw', (openError, fd) => {
        if(fd > 0){
            asset.close(fd);
        }else{
            console.info('File Open Failed!' + openError);
        }
    });
}
```

### open

open(mode: string): Promise&lt;number&gt;

Opens this file asset. This API uses a promise to return the result.

**NOTE**<br>Currently, the write operations are mutually exclusive. After a write operation is complete, you must call **close** to release the resource.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, ohos.permission.READ_DOCUMENT, ohos.permission.WRITE_MEDIA, ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type    | Mandatory  | Description                                 |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | Yes   | File open mode, which can be **r** (read-only), **w** (write-only), or **rw** (read-write).|

**Return value**

| Type                   | Description           |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise used to return the file handle.|

**Example**

```js
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const path = await userFileMgr.getPublicDirectory(DIR_IMAGE);
    const asset = await userFileMgr.createAsset(mediaType, "image00003.jpg", path);
    asset.open('rw')
        .then((fd) => {
            console.info('File fd!' + fd);
        })
        .catch((err) => {
            console.info('File err!' + err);
        });
}
```

### close

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

Closes this file asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | File descriptor.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.open('rw').then((fd) => {
        console.info('File fd!' + fd);
        asset.close(fd, (closeErr) => {
            if (closeErr != undefined) {
                console.info('mediaLibraryTest : close : FAIL ' + closeErr);
                console.info('mediaLibraryTest : ASSET_CALLBACK : FAIL');
            } else {
                console.info("=======asset.close success====>");
            }
        });
    })
    .catch((err) => {
        console.info('File err!' + err);
    });
}
```

### close

close(fd: number): Promise&lt;void&gt;

Closes this file asset. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type    | Mandatory  | Description   |
| ---- | ------ | ---- | ----- |
| fd   | number | Yes   | File descriptor.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.open('rw').then((fd) => {
        console.info('File fd!' + fd);
        asset.close(fd).then((closeErr) => {
            if (closeErr != undefined) {
                console.info('mediaLibraryTest : close : FAIL ' + closeErr);
                console.info('mediaLibraryTest : ASSET_CALLBACK : FAIL');

            } else {
                console.info("=======asset.close success====>");
            }
        });
    })
    .catch((err) => {
        console.info('File err!' + err);
    });
}
```

### getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the thumbnail of this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](#../apis/js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail((err, pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successfull '+ pixelmap);
    });
}
```

### getThumbnail

getThumbnail(size: Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

Obtains the file thumbnail of the given size. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                                 | Mandatory  | Description              |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [Size](#size)                      | Yes   | Size of the thumbnail to obtain.           |
| callback | AsyncCallback&lt;[image.PixelMap](#../apis/js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let size = { width: 720, height: 720 };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail(size, (err, pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successfull '+ pixelmap);
    });
}
```

### getThumbnail

getThumbnail(size?: Size): Promise&lt;image.PixelMap&gt;

Obtains the file thumbnail of the given size. This API uses a promise to return the result.  

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type            | Mandatory  | Description   |
| ---- | -------------- | ---- | ----- |
| size | [Size](#size) | No   | Size of the thumbnail to obtain.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](#../apis/js-apis-image.md#pixelmap7)&gt; | Promise used to return the pixel map of the thumbnail.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let size = { width: 720, height: 720 };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.getThumbnail(size)
    .then((pixelmap) => {
        console.info('mediaLibraryTest : getThumbnail Successfull '+ pixelmap);
    })
    .catch((err) => {
        console.info('mediaLibraryTest : getThumbnail fail'+ err);
    });
}
```

### favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

Favorites or unfavorites this file asset. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name       | Type                       | Mandatory  | Description                                |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | Yes   | Operation to perform. The value **true** means to favorite the file asset, and **false** means the opposite.|
| callback   | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.                             |

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.favorite(true,function(err){
        // Do something.
    });
}
```

### favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;

Favorites or unfavorites this file asset. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

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

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.favorite(true).then(function() {
        console.info("favorite successfully");
    }).catch(function(err){
        console.info("favorite failed with error:"+ err);
    });
}
```

### isFavorite

isFavorite(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is favorited. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description         |
| -------- | ---------------------------- | ---- | ----------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the file asset is favorited, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isFavorite((err, isFavorite) => {
        if (isFavorite) {
            console.info('FileAsset is favorite');
        }else{
            console.info('FileAsset is not favorite');
        }
    });
}
```

### isFavorite

isFavorite():Promise&lt;boolean&gt;

Checks whether this file asset is favorited. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                    | Description                |
| ---------------------- | ------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. If the file asset is favorited, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isFavorite().then(function(isFavorite){
        console.info("isFavorite result:"+ isFavorite);
    }).catch(function(err){
        console.info("isFavorite failed with error:"+ err);
    });
}
```

### trash

trash(isTrash: boolean, callback: AsyncCallback&lt;void&gt;): void

Moves this file asset to the trash. This API uses an asynchronous callback to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description       |
| -------- | ------------------------- | ---- | --------- |
| isTrash  | boolean                   | Yes   | Whether to move the file asset to the trash. The value **true** means to move the file asset to the trash, and **false** means the opposite.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback that returns no value.    |

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.trash(true, trashCallBack);
    function trashCallBack(err, trash) {
        console.info('mediaLibraryTest : ASSET_CALLBACK ASSET_CALLBACK trash');
    }
}
```

### trash

trash(isTrash: boolean): Promise&lt;void&gt;

Moves this file asset to the trash. This API uses a promise to return the result.

Files in the trash are not actually deleted. You can set **isTrash** to **false** to restore the files from the trash.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name    | Type     | Mandatory  | Description       |
| ------- | ------- | ---- | --------- |
| isTrash | boolean | Yes   | Whether to move the file asset to the trash. The value **true** means to move the file asset to the trash, and **false** means the opposite.|

**Return value**

| Type                 | Description        |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.trash(true).then(function() {
        console.info("trash successfully");
    }).catch(function(err){
        console.info("trash failed with error:"+ err);
    });
}
```

### isTrash

isTrash(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this file asset is in the trash. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                          | Mandatory  | Description             |
| -------- | ---------------------------- | ---- | --------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes   | Callback invoked to return the result. If the file asset is in the trash, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isTrash((err, isTrash) => {
      if (isTrash == undefined) {
        console.error('Failed to get trash state: ' + err);
        return;
      }
      console.info('Get trash state success: ' + isTrash);
    });
}
```

### isTrash

isTrash():Promise&lt;boolean&gt;

Checks whether this file asset is in the trash. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description                  |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise used to return the result. If the file asset is in the trash, **true** will be returned; otherwise, **false** will be returned.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    const fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const asset = await fetchFileResult.getFirstObject();
    asset.isTrash().then(function(isTrash){
        console.info("isTrash result: " + isTrash);
    }).catch(function(err){
        console.error("isTrash failed with error: " + err);
    });
}
```

## FetchFileResult

Provides APIs to manage the file retrieval result.

### getCount

getCount(): number

Obtains the total number of files in the result set.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type    | Description      |
| ------ | -------- |
| number | Total number of files.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let fileType = mediaLibrary.MediaType.FILE;
    let getFileCountOneOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
  	let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getFileCountOneOp);
    const fetchCount = fetchFileResult.getCount();
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

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const fetchCount = fetchFileResult.getCount();
    console.info('mediaLibraryTest : count:' + fetchCount);
    let fileAsset = await fetchFileResult.getFirstObject();
    for (var i = 1; i < fetchCount; i++) {
        fileAsset = await fetchFileResult.getNextObject();
        if(i == fetchCount - 1) {
            console.info('mediaLibraryTest : isLast');
            var result = fetchFileResult.isAfterLast();
            console.info('mediaLibraryTest : isAfterLast:' + result);
            console.info('mediaLibraryTest : isAfterLast end');
            fetchFileResult.close();
        }
    }
}
```

### close

close(): void

Releases and invalidates this **FetchFileResult** instance. After this instance is released, the APIs in this instance cannot be invoked.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.close();
}
```

### getFirstObject

getFirstObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the first file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                       |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the first file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getFirstObject((err, fileAsset) => {
        if (err) {
           console.error('Failed ');
           return;
        }
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getFirstObject

getFirstObject(): Promise&lt;FileAsset&gt;

Obtains the first file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description                      |
| --------------------------------------- | -------------------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the first file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getFirstObject().then(function(fileAsset){
        console.info("getFirstObject successfully:"+ JSON.stringify(fileAsset));
    }).catch(function(err){
        console.info("getFirstObject failed with error:"+ err);
    });
}
```

### getNextObject

 getNextObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the next file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type                                         | Mandatory| Description                                     |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getNextObject

 getNextObject(): Promise&lt;FileAsset&gt;

Obtains the next file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the next file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    const fetchCount = fetchFileResult.getCount();
    console.info('mediaLibraryTest : count:' + fetchCount);
    let fileAsset = await fetchFileResult.getNextObject();
}
```

### getLastObject

getLastObject(callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains the last file asset in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                       |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the last file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getLastObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getLastObject

getLastObject(): Promise&lt;FileAsset&gt;

Obtains the last file asset in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the last file asset.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    let lastObject = await fetchFileResult.getLastObject();
}
```

### getPositionObject

getPositionObject(index: number, callback: AsyncCallback&lt;FileAsset&gt;): void

Obtains a file asset with the specified index in the result set. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name      | Type                                      | Mandatory  | Description                |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | Yes   | Index of the file asset to obtain. The value starts from **0**.    |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes   | Callback invoked to return the file asset obtained.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getPositionObject(0, (err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    })
}
```

### getPositionObject

getPositionObject(index: number): Promise&lt;FileAsset&gt;

Obtains a file asset with the specified index in the result set. This API uses a promise to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name   | Type    | Mandatory  | Description            |
| ----- | ------ | ---- | -------------- |
| index | number | Yes   | Index of the file asset to obtain. The value starts from **0**.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the file asset obtained.|

**Example**

```js
async function example() {
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let getImageOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
	  let userFileMgr = userfile_manager.getUserFileMgr(context);
    let fetchFileResult = await userFileMgr.getFileAssets(getImageOp);
    fetchFileResult.getPositionObject(1) .then(function (fileAsset){
        console.log('fileAsset.displayName : ' + fileAsset.displayName);
    }).catch(function (err) {
        console.info("getFileAssets failed with error:" + err);
    });
}
```

## Album

Provides APIs to manage albums.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Readable  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | Yes   | Yes   | Album name.   |
| albumUri | string | Yes   | No   | Album URI.  |
| dateModified | number | Yes   | No   | Date when the album was last modified.   |
| count | number | Yes   | No   | Number of files in the album.|
| relativePath | string | Yes   | No   | Relative path of the album.   |
| coverUri | string | Yes   | No   | URI of the cover file of the album.

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

Commits the modification on the album attributes to the database. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                     | Mandatory| Description      |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

**Example**

```ts
async function commitModifyDemoCallback() {
    console.info('commitModifyDemo')
    let fileKeyObj = userfile_manager.FileKey
    let imageType = userfile_manager.MediaType.IMAGE;
    let getImageOp = {
        selections: '',
        selectionArgs: [],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let fetchFileResult = await userFileMgr.getFileAssets([imageType], getImageOp);
    let asset = await fetchFileResult.getFirstObject();
    console.info('old displayName:', asset.displayName)
    asset.displayName = 'newDisplayName';
    console.info('new displayName:', asset.displayName)
    asset.commitModify((err) => {
        if (err == undefined) {
            console.info('commitModify succeed.')
        } else {
            console.info('commitModify failed, message =', err);
        }
    });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;;

Commits the modification on the album attributes to the database. This API uses a promise to return the result.

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO, ohos.permission.WRITE_AUDIO, or ohos.permission.WRITE_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Return value**

| Type                 | Description          |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
async function commitModifyDemoPromise() {
    console.info('commitModifyDemo')
    let fileKeyObj = userfile_manager.FileKey
    let imageType = userfile_manager.MediaType.IMAGE;
    let getImageOp = {
        selections: '',
        selectionArgs: [],
        order: fileKeyObj.DATE_ADDED + " DESC",
        extendArgs: "",
    };
    let fetchFileResult = await userFileMgr.getFileAssets([imageType], getImageOp);
    let asset = await fetchFileResult.getFirstObject();
    console.info('old displayName:', asset.displayName)
    asset.displayName = 'newDisplayName';
    console.info('new displayName:', asset.displayName)
    try {
        await asset.commitModify();
        console.info('commitModify succeed.')
    } catch (err) {
        console.info('commitModify failed, message =', err);
    }
}
```

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, callback: AsyncCallback&lt;FetchFileResult&gt;): void;

Obtains the file assets in this album. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | Yes  | Type of the media data to obtain.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | Yes  | Callback invoked to return the file assets obtained.|

**Example**

```ts
async function albumGetFileAssetsDemoCallback() {
    console.info('albumGetFileAssetsDemoCallback2')
    let imageType = userfile_manager.MediaType.IMAGE;
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const albumList = await userFileMgr.getAlbums([imageType], AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.getFileAssets([imageType], (err, albumFetchFileResult) => {
        if (err == undefined) {
            console.info("getFileAssets successfully:"+ JSON.stringify(albumFetchFileResult));
        } else {
            console.info("getFileAssets failed with error:"+ err);
        }
    });
}
```

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void;

Obtains the file assets in this album. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | Yes  | Type of the media data to obtain.                     |
| options  | [MediaFetchOptions](#mediafetchoptions)        | Yes  | Options for fetching the media data.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | Yes  | Callback invoked to return the file assets obtained.|

**Example**

```ts
async function albumGetFileAssetsDemoCallback() {
    console.info('albumGetFileAssetsDemoCallback')
    let imageType = userfile_manager.MediaType.IMAGE;
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    let fileNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    }
    const albumList = await userFileMgr.getAlbums([imageType], AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.getFileAssets([imageType], fileNoArgsfetchOp, (err, albumFetchFileResult) => {
        if (err == undefined) {
            console.info("getFileAssets successfully:"+ JSON.stringify(albumFetchFileResult));
        } else {
            console.info("getFileAssets failed with error:"+ err);
        }
    });
  }
```

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, options?: MediaFetchOptions): Promise&lt;FetchFileResult&gt;;

Obtains the file assets in this album. This API uses a promise to return the result.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT


**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type                                    | Mandatory| Description          |
| ------- | ---------------------------------------- | ---- | -------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | Yes  | Type of the media data to obtain.                     |
|options  | [MediaFetchOptions](#mediafetchoptions) | No  | Options for fetching the media data.|

**Return value**

| Type                                         | Description                     |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult)> | Promise used to return the file assets obtained.|

**Example**

```ts
async function albumGetFileAssetsDemoPromise() {
    console.info('albumGetFileAssetsDemoPromise')
    let imageType = userfile_manager.MediaType.IMAGE;
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    let fileNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    }
    const albumList = await userFileMgr.getAlbums([imageType], AlbumNoArgsfetchOp);
    const album = albumList[0];
    album.getFileAssets([imageType], fileNoArgsfetchOp).then(function(albumFetchFileResult){
        console.info("getFileAssets successfully:"+ JSON.stringify(albumFetchFileResult));
    }).catch(function(err){
        console.info("getFileAssets failed with error:"+ err);
    });
}
```
## VirtualAlbum
Provides APIs for managing a virtual album.

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void;

Obtains file assets in the virtual album. This API uses an asynchronous callback to return the result.

This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

> **NOTE**<br>
> The ability privilege level (APL) of the permissions required by this API is **system_basic**. Applications of the **normal** APL need to apply for these permissions through the Access Control List (ACL). For details, see [ACL](../../security/accesstoken-overview.md#acl).
>
> You are advised to use the **options** parameter to explicitly specify the type of the file access. If the file type cannot be determined, the file asset result set is returned based on the permissions of the application.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**
| Name  | Type                                               | Mandatory| Description                               |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | Yes  | Type of the media data to obtain.                     |
| options  | [MediaFetchOptions](#mediafetchoptions)        | Yes  | Options for fetching the files.                     |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | Yes  | Callback invoked to return the file assets obtained.|

**Example**

```ts
async function virtualAlbumGetFileAssetsDemoCallback() {
    console.info('virtualAlbumGetFileAssetsDemoCallback')
    try {
        var albumArray = await userFileMgr.getPrivateAlbum(userfile_manager.VirtualAlbumType.TYPE_TRASH);
    } catch (err) {
        console.info('getPrivateAlbum failed, message = ', err);
    }
    let fetchOpt = {
        selections: '',
        selectionArgs: [],
    };
    let trashAlbum = albumArray[0];

    trashAlbum.getFileAssets([userfile_manager.MediaType.IMAGE], fetchOpt, (err, fetchResult) => {
        if (err == undefined) {
            let count = fetchResult.getCount();
            console.info('fetchResult.count = ', count);
        } else {
            console.info('getFileAssets failed, message = ', err);
        }
    });
}
```

### getFileAssets
getFileAssets(type: Array&lt;MediaType&gt;, options: MediaFetchOptions): Promise&lt;FetchFileResult&gt;;

Obtains file assets in the virtual album. This API uses a promise to return the result.

This is a system API.

**Required permissions**: ohos.permission.READ_IMAGEVIDEO, ohos.permission.READ_AUDIO, or ohos.permission.READ_DOCUMENT

> **NOTE**<br>
> The APL of the permissions required by this API is **system_basic**. Applications of the **normal** APL need to apply for these permissions through the ACL. For details, see [ACL](../../security/accesstoken-overview.md#acl).
>
> You are advised to use the **options** parameter to explicitly specify the type of the file access. If the file type cannot be determined, the file asset result set is returned based on the permissions of the application.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name | Type                                    | Mandatory| Description          |
| ------- | ---------------------------------------- | ---- | -------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | Yes  | Type of the media data to obtain.                     |
|options  | [MediaFetchOptions](#mediafetchoptions) | No  | Options for fetching the files.|

**Return value**

| Type                                         | Description                     |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult)> | Promise used to return the file assets obtained.|

**Example**

```ts
async function virtualAlbumGetFileAssetsDemoPromise() {
    console.info('virtualAlbumGetFileAssetsDemoPromise')
    let albumArray = await userFileMgr.getPrivateAlbum(userfile_manager.VirtualAlbumType.TYPE_TRASH);
    let fetchOpt = {
        selections: '',
        selectionArgs: [],
    };
    let trashAlbum = albumArray[0];

    let fetchResult = await trashAlbum.getFileAssets([userfile_manager.MediaType.IMAGE], fetchOpt);
    let count = fetchResult.getCount();
    console.info('fetchResult.count = ', count);
}
```

## PeerInfo

Describes information about a registered device.
This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.DistributedCore

| Name      | Type                      | Readable| Writable| Description            |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | Yes  | No  | Name of the registered device.  |
| networkId  | string                     | Yes  | No  | Network ID of the registered device.|
| isOnline   | boolean                    | Yes  | No  | Whether the registered device is online.        |

## MediaType

Enumerates the media types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name |  Description|
| ----- |  ---- |
| FILE  |  File.|
| IMAGE |  Image.|
| VIDEO |  Video.|
| AUDIO |  Audio.|

## FileKey

Defines the key file information.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Default Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI            | uri                | File URI.                                                  |
| RELATIVE_PATH | relative_path       | Relative public directory of the file.                                          |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file was last modified. The value is the number of seconds elapsed since the Epoch time.            |
| TITLE         | title               | Title in the file.                                                  |

## AudioKey

Defines the key information about an audio file.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Default Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | Promise used to return the URI of the file created.                                                  |
| RELATIVE_PATH | relative_path       | Relative public directory of the file.                                          |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file was last modified. The value is the number of seconds elapsed since the Epoch time.            |
| TITLE         | title               | Title in the file.                                                  |
| ARTIST        | artist              | Author of the file.                                                  |
| AUDIOALBUM    | audio_album         | Audio album.                                                  |
| DURATION      | duration            | Duration, in ms.                                   |

## ImageVideoKey

Defines the key information about an image or video file.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Default Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | File URI.                                                  |
| RELATIVE_PATH | relative_path       | Relative public directory of the file.                                          |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file was last modified. The value is the number of seconds elapsed since the Epoch time.            |
| DURATION      | duration            | Duration, in ms.                                   |
| WIDTH         | width               | Image width, in pixels.                                   |
| HEIGHT        | height              | Image height, in pixels.                                     |
| DATE_TAKEN    | date_taken          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.               |

## AlbumKey

Defines the key album information.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Default Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | Album URI.                                                  |
| RELATIVE_PATH | relative_path       | Relative public directory of the album.                                          |
| DISPLAY_NAME  | display_name        | Album name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the album was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the album was last modified. The value is the number of seconds elapsed since the Epoch time.            |

## DirectoryType

Enumerates directory types.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         |  Description              |
| ------------- |  ------------------ |
| DIR_CAMERA    |  Directory of camera files.|
| DIR_VIDEO     |  Directory of video files.      |
| DIR_IMAGE     |  Directory of image files.      |
| DIR_AUDIO     |  Directory of audio files.      |
| DIR_DOCUMENTS |  Directory of documents.      |
| DIR_DOWNLOAD  |  Download directory.      |

## MediaFetchOptions

Defines the options for fetching media files.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                   | Type               | Readable| Writable| Mandatory| Description                                                        |
| ----------------------- | ------------------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| selections              | string              | Yes  | Yes  | Yes  | Conditions for fetching files. The values in [FileKey](#filekey) are used as the column names of the conditions. Example:<br>selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ? OR' +mediaLibrary.FileKey.MEDIA_TYPE + '= ?',|
| selectionArgs           | Array&lt;string&gt; | Yes  | Yes  | Yes  | Values of the conditions specified in **selections**.<br>Example:<br>selectionArgs: [mediaLibrary.MediaType.IMAGE.toString(), mediaLibrary.MediaType.VIDEO.toString()], |

## Size

Defines the image size.
**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name    | Type    | Readable  | Writable  | Description      |
| ------ | ------ | ---- | ---- | -------- |
| width  | number | Yes   | Yes   | Image width, in pixels.|
| height | number | Yes   | Yes   | Image height, in pixels.|

## VirtualAlbumType
Enumerates the system or virtual album types.

This is a system API.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         |  Description              |
| ------------- |  ------------------ |
| TYPE_FAVORITE    | Favorites album.<br>This is a system API.|
| TYPE_TRASH       | Trash album.<br>This is a system API.|
