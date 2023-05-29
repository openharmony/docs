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
        console.info("fileAsset.displayName : " + fileAsset.displayName);
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
        console.info("fileAsset.displayName :" + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getPhotoAssets failed, message = ', err);
  }
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

Creates an image or video asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| albumUri  | string        | Yes  | URI of the album where the image or video is located.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the image or video created.|

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
  let testFileName = "testFile" + Date.now() + ".jpg";
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

Creates an image or video asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.WRITE_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | Yes  | File name of the image or video to create.             |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | Yes  | Callback invoked to return the image or video created.|

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  let testFileName = "testFile" + Date.now() + ".jpg";
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

Creates an image or video asset. This API uses a promise to return the result.

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
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise used to return the image or video created.|

**Example**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
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
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Yes  | Callback invoked to return the albums obtained.|

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
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise used to return the albums obtained.|

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

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void;

Obtains the system album. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Required permissions**: ohos.permission.READ_IMAGEVIDEO

**Parameters**

| Name  | Type                    | Mandatory| Description                     |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | Yes  | Type of the album to obtain.             |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Yes  | Callback invoked to return the album obtained.|

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
| type  | [PrivateAlbumType](#privatealbumtype)        | Yes  | Type of the album to obtain.             |

**Return value**

| Type                       | Description          |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Promise used to return the album obtained.|

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
        console.info("fileAsset.displayName :" + fileAsset.displayName);
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
      console.info("fileAsset.displayName :" + fileAsset.displayName);
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
| uri | string | Yes  | URI of the media file to delete.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

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
      console.info("delete successfully");
    } else {
      console.error("delete failed with error: " + err);
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
| uri | string | Yes  | URI of the media file to delete.|

**Return value**

| Type                                   | Description             |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise that returns no value.|

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
    console.info("delete successfully");
  } catch (err) {
    console.error("delete failed with error: " + err);
  }
}
```

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

Subscribes to changes of the file management library. This API uses a callback to return the result.

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
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count > 0) {
    console.info("onDemo success");
  } else {
    console.error("onDemo fail");
  }
  mgr.off('imageChange', () => {
    // Unsubscription succeeds.
  });
}
```

### off

off(type: ChangeEvent, callback?: Callback&lt;void&gt;): void

Unsubscribes from changes of the file management library. This API uses a callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name  | Type                | Mandatory| Description                                                        |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | Yes  | Type of event to subscribe to.<br>**deviceChange** indicates the device change.<br>**albumChange** indicates the album change.<br>**imageChange** indicates the image change.<br>**audioChange** indicates the audio file change.<br>**videoChange** indicates the video file change.<br>**remoteFileChange** indicates the file change on the registered device.|
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
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count == 0) {
    console.info("offDemo success");
  } else {
    console.error("offDemo fail");
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
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback invoked to return the online peer device list.|

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
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return the online device list.|

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
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Yes  | Callback invoked to return the online peer device list.|

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
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise used to return the peer device list.|

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
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback that returns no value.|

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

## FileAsset

Provides APIs for encapsulating file asset attributes.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                     | Type                    | Readable| Writable| Description                                                  |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | Yes  | No  | File asset URI, for example, **dataability:///media/image/2**.        |
| fileType   | [FileType](#filetype) | Yes  | No  | Type of the file.                                              |
| displayName               | string                   | Yes  | Yes  | File name, including the file name extension, to display.                                |


### get

get(member: string): MemberType;

Obtains the value of a **FileAsset** parameter.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| member | string | Yes   | Name of the parameter to obtain, for example, **ImageVideoKey.URI**.|

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetGetDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
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
| member | string | Yes   | Name of the parameter to set, for example, **ImageVideoKey.URI**.|
| value | string | Yes   | Value to set. Only the value of **ImageVideoKey.TITLE** can be changed.|

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
    let title = userFileManager.ImageVideoKey.TITLE;
    fileAsset.set(title.toString(), "newTitle");
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
  let title = userFileManager.ImageVideoKey.TITLE;
  let fileAssetTitle = fileAsset.get(title.toString());
  console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  fileAsset.set(title.toString(), "newTitle");
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let newFileAssetTitle = fileAsset.get(title.toString());
      console.info('fileAsset Get newFileAssetTitle = ', newFileAssetTitle);
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
  let title = userFileManager.ImageVideoKey.TITLE;
  let fileAssetTitle = fileAsset.get(title.toString());
  console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  fileAsset.set(title.toString(), "newTitle");
  try {
    await fileAsset.commitModify();
    let newFileAssetTitle = fileAsset.get(title.toString());
    console.info('fileAsset Get newFileAssetTitle = ', newFileAssetTitle);
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
| callback | AsyncCallback&lt;number&gt; | Yes   | Callback invoked to return the file descriptor.                           |

**Example**

```ts
async function example() {
  console.info('openDemo');
   let testFileName = "testFile" + Date.now() + ".jpg";
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
| Promise&lt;number&gt; | Promise used to return the file descriptor.|

**Example**

```ts
async function example() {
  console.info('openDemo');
  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
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

Closes this file asset. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

**Parameters**

| Name     | Type                       | Mandatory  | Description   |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | Yes   | File descriptor.|
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
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the pixel map of the thumbnail.|

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
| size     | [image.Size](js-apis-image.md#size) | Yes   | Size of the thumbnail to obtain.           |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Yes   | Callback invoked to return the pixel map of the thumbnail.|

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
| size | [image.Size](js-apis-image.md#size) | No   | Size of the thumbnail to obtain.|

**Return value**

| Type                           | Description                   |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise used to return the pixel map of the thumbnail.|

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
      console.info("favorite successfully");
    } else {
      console.error("favorite failed with error:" + err);
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
    console.info("favorite successfully");
  }).catch(function (err) {
    console.error("favorite failed with error:" + err);
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
| number | Total number of files.|

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
  if (!fetchResult.isAfterLast()) {
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
      console.error("fileAsset failed with err:" + err);
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
| Promise&lt;T&gt; | Promise used to return the first file asset.|

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
        console.error("fileAsset failed with err: " + err);
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
| Promise&lt;T&gt; | Promise used to return the next file asset obtained.|

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
      console.error("fileAsset failed with err: " + err);
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
| Promise&lt;T&gt; | Promise used to return the last file asset obtained.|

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
      console.error("fileAsset failed with err: " + err);
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
| coverUri | string | Yes   | No   | URI of the cover file of the album.

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
      console.info("album getPhotoAssets successfully, getCount: " + albumFetchResult.getCount());
    } else {
      console.error("album getPhotoAssets failed with error: " + err);
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
| Promise | [FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt; | Yes  | Promise used to return the image and video assets obtained.|

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
    console.info("album getFileAssets successfully, getCount: " + albumFetchResult.getCount());
  }).catch((err) => {
    console.error("album getFileAssets failed with error: " + err);
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
      console.error("commitModify failed with error: " + err);
    } else {
      console.info("commitModify successfully");
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
    console.info("commitModify successfully");
  }).catch((err) => {
    console.error("commitModify failed with error: " + err);
  });
}
```

## PrivateAlbum

Provides APIs for managing the system albums.

### Attributes

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name          | Type   | Readable  | Writable  | Description     |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | Yes   | Yes   | Album name.   |
| albumUri | string | Yes   | No   | Album URI.  |
| dateModified | number | Yes   | No   | Date when the album was last modified.   |
| count | number | Yes   | No   | Number of files in the album.|
| coverUri | string | Yes   | No   | URI of the cover file of the album.

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
| uri | string | Yes  | Album URI.|
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
| uri | string | Yes  | Album URI.|

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
| uri | string | Yes  | Album URI.|
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
| uri | string | Yes  | Album URI.|

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
| deviceChange |  string | Yes| Yes|  Device.|
| albumChange |  string | Yes| Yes|  Album.|
| imageChange |  string | Yes| Yes|  Image.|
| audioChange |  string | Yes| Yes|  Audio.|
| videoChange |  string | Yes| Yes|  Video.|
| remoteFileChange |  string | Yes| Yes|  Remote file.|

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
| URI           | uri                 | File URI.                                                  |
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
| URI           | uri                 | File URI.                                                  |
| FILE_TYPE     | file_type           | Type of the file.                                             |
| DISPLAY_NAME  | display_name        | File name displayed.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|
| TITLE         | title               | Title in the file.                                                  |
| DURATION      | duration            | Duration, in ms.                                   |
| WIDTH         | width               | Image width, in pixels.                                   |
| HEIGHT        | height              | Image height, in pixels.                                     |
| DATE_TAKEN    | date_taken          | Date when the file (photo) was taken. The value is the number of seconds elapsed since the Epoch time.               |
| ORIENTATION   | orientation         | Orientation of the image file.                                            |
| FAVORITE      | favorite            | Whether the file is added to favorites.                                                   |

## AlbumKey

Defines the key album information.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name         | Value             | Description                                                      |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | Album URI.                                                  |
| FILE_TYPE     | file_type           | Type of the file.                                             |
| ALBUM_NAME    | album_name          | Name of the album.                                                  |
| DATE_ADDED    | date_added          | Date when the file was added. The value is the number of seconds elapsed since the Epoch time.            |
| DATE_MODIFIED | date_modified       | Date when the file content (not the file name) was last modified. The value is the number of seconds elapsed since the Epoch time.|

## FetchOptions

Defines the options for fetching media files.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Readable| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | Yes  | Yes  | Columns to fetch. If this parameter is left empty, data is fetched by URI, name, and file type by default. For example,<br>**fetchColumns: "uri"**.|
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|

## AlbumFetchOptions

Defines the options for fetching an album.

**System capability**: SystemCapability.FileManagement.UserFileManager.Core

| Name                  | Type               | Readable| Writable| Description                                             |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | Yes  | Yes  | Predicates that specify the fetch criteria.|
