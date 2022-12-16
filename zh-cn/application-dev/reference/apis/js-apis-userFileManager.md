# @ohos.filemanagement.userFileManager (用户数据管理)

该模块提供用户数据管理能力，包括访问、修改用户等用户公共媒体数据信息等常用功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口为系统接口。

## 导入模块

```ts
import userFileManager from '@ohos.filemanagement.userFileManager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

获取用户数据管理模块的实例，用于访问和修改用户等用户公共媒体数据信息（如音频、视频、图片、文档等）。

**模型约束：** 此接口仅可在Stage模型下使用。
 
**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：** 

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](js-apis-inner-app-context.md) | 是   | 传入Ability实例的Context。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | 媒体库实例 |

**示例：**

```ts
const context = getContext(this);
let mgr = userFileManager.getUserFileMgr(context);
```

## UserFileManager

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;


获取图片和视频资源，使用callback方式返回结果。



**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 图片和视频检索选项              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback 返回图片和视频检索结果集 |

**示例：**

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
        console.info("fileAsset.displayName :" + fileAsset.displayName);
      }
    } else {
      console.info('fetchResult fail' + err);
    }
  })
}
```


### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取图片和视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名  | 类型                | 必填 | 说明             |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](#fetchoptions)   | 是   | 图片和视频检索选项     |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 图片和视频数据结果集 |

**示例：**

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
    var fetchResult = await mgr.getPhotoAssets(fetchOptions)
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info("fileAsset.displayName :" + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.info('getPhotoAssets failed, message = ', err);
  }
}
```
### createPhotoAsset

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名              |
| albumUri  | string        | 是   | 创建的图片或者视频所在相册的uri              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback 返回创建的图片和视频结果 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('createPhotoAssetDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    predicates: predicates
  };
  let albums = await mgr.getPhotoAlbums(fetchOptions)
  let album = await albums.getFirstObject()
  let testFileName = "testFile" + Date.now() + ".jpg";
  mgr.createPhotoAsset(testFileName, album.albumUri, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.info('createPhotoAsset failed, message = ', err);
    }
  })
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback 返回创建的图片和视频结果 |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo')
  let testFileName = "testFile" + Date.now() + ".jpg";
  mgr.createPhotoAsset(testFileName, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.info('createPhotoAsset failed, message = ', err);
    }
  })
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, albumUri?: string): Promise&lt;FileAsset&gt;;

创建图片或视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名              |
| albumUri  | string        | 否   | 创建的图片或者视频所在相册的uri              |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | 返回创建的图片和视频结果 |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo')
  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName)
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.info('createPhotoAsset failed, message = ', err);
  }
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;


获取相册，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | 是   | 相册检索选项              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | 是   | callback 返回相册检索结果 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo')
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
          console.info('album is undefined, err = ', err);
        }
      })
    } else {
      console.info('getPhotoAlbums fail, message = ', err);
    }
  })
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;;

获取相册，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | 是   | 相册检索选项              |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise 返回相册检索结果 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo')
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
    console.info('getPhotoAlbums fail, message = ' + err);
  }
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void;


获取系统相册，使用 callback 方式返回系统相册的数组。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | 是   | 系统相册类型              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | 是   | callback 返回相册检索结果 |

**示例：**

```ts
async function example() {
  console.info('getPrivateAlbumDemo')
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      let trashAlbum = await fetchResult.getFirstObject();
      console.info('first album.albumName = ' + trashAlbum.albumName);
    } else {
      console.info('getPrivateAlbum failed. message = ', err);
    }
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType): Promise&lt;FetchResult&lt;PrivateAlbum&gt;&gt;;


获取系统相册，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | 是   | 系统相册类型              |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Promise 返回相册检索结果 |

**示例：**

```ts
async function example() {
  console.info('getPrivateAlbumDemo');
  try {
    var fetchResult = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
    let trashAlbum = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + trashAlbum.albumName);
  } catch (err) {
    console.info('getPrivateAlbum failed. message = ', err);
  }
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;


获取音频文件，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 检索选项              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback 返回相册检索结果 |

**示例：**

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
      console.info('fetchFileResult fail' + err);
    }
  })
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;


获取音频文件，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 检索选项              |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise 返回相册检索结果 |

**示例：**

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
    var fetchResult = await mgr.getAudioAssets(fetchOptions)
  } catch (err) {
    console.info('getAudioAssets failed, message = ', err);
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

删除媒体文件,删除的文件进入到回收站。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 媒体文件uri |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteAssetDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err)
  }

  if (asset == undefined) {
    console.error('asset not exist')
    return;
  }
  mgr.delete(asset.uri, (err) => {
    if (err == undefined) {
      console.info("delete successfully");
    } else {
      console.info("delete failed with error:" + err);
    }
  });
}
```
### delete

delete(uri: string): Promise&lt;void&gt;;

删除媒体文件,删除的文件进入到回收站。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 媒体文件uri |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| 回调返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err)
  }

  if (asset == undefined) {
    console.error('asset not exist')
    return;
  }
  try {
    await mgr.delete(asset.uri);
    console.info("delete successfully");
  } catch (err) {
    console.info("delete failed with error:" + err);
  }
}
```

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

打开文件管理库变更通知，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更 |
| callback | Callback&lt;void&gt; | 是   | 回调返回空                                                   |

**示例：**

```ts
async function example() {
  console.info('onDemo')
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // image file had changed, do something
  });
  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.info('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count > 0) {
    console.info("onDemo success");
  } else {
    console.info("onDemo fail");
  }
  mgr.off('imageChange', () => {
    // stop listening success
  });
}
```

### off

off(type: ChangeEvent, callback?: Callback&lt;void&gt;): void

关闭文件管理库变更通知，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更 |
| callback | Callback&lt;void&gt; | 否   | 回调返回空                                                   |

**示例：**

```ts
async function example() {
  console.info('offDemo')
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // image file had changed, do something
  });

  mgr.off('imageChange', () => {
    // stop listening success
  });

  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.info('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count == 0) {
    console.info("offDemo success");
  } else {
    console.info("offDemo fail");
  }
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

获取在线对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表 |

**示例：**

```ts
async function example() {
  console.info('getActivePeersDemo')
  mgr.getActivePeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
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

getActivePeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

获取在线对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise实例，返回在线设备列表 |

**示例：**

```ts
async function example() {
  console.info('getActivePeersDemo')
  try {
    var devicesInfo = await mgr.getActivePeers();
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

getAllPeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

获取所有对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表 |

**示例：**

```ts
async function example() {
  console.info('getAllPeersDemo')
  mgr.getAllPeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
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

getAllPeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

获取所有对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise实例，返回所有设备列表 |

**示例：**

```ts
async function example() {
  console.info('getAllPeersDemo')
  try {
    var devicesInfo = await mgr.getAllPeers();
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

释放UserFileManager实例。
当后续不需要使用UserFileManager实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败 |

**示例：**

```ts
async function example() {
  console.info('releaseDemo');
  mgr.release((err) => {
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

释放UserFileManager实例。
当后续不需要使用UserFileManager 实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果 |

**示例：**

```ts
async function example() {
  console.info('releaseDemo');
  try {
    await mgr.release();
    console.info('release ok.');
  } catch (err) {
    console.info('release failed. message = ', err);
  }
}
```

## FileAsset

提供封装文件属性的方法。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称                      | 类型                     | 可读 | 可写 | 说明                                                   |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | 是   | 否   | 文件资源uri（如：dataability:///media/image/2)         |
| fileType   | [FileType](#filetype) | 是   | 否   | 媒体文件类型                                               |
| displayName               | string                   | 是   | 是   | 显示文件名，包含后缀名                                 |


### get

get(member: string): MemberType;

获取FileAsset成员参数

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.URI |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetGetDemo')
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let title = userFileManager.ImageVideoKey.TITLE
    let fileAssetTitle = fileAsset.get(title.toString())
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  } catch (err) {
    console.info('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void;

设置FileAsset成员参数

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.URI |
| value | string | 是    | 设置成员参数名称，只能修改ImageVideoKey.TITLE的值 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetSetDemo')
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let title = userFileManager.ImageVideoKey.TITLE
    fileAsset.set(title.toString(), "newTitle")
  } catch (err) {
    console.info('release failed. message = ', err);
  }
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

修改文件的元数据，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调返回空 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let title = userFileManager.ImageVideoKey.TITLE
  let fileAssetTitle = fileAsset.get(title.toString())
  console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  fileAsset.set(title.toString(), "newTitle")
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let newFileAssetTitle = fileAsset.get(title.toString())
      console.info('fileAsset Get newFileAssetTitle = ', newFileAssetTitle);
    } else {
      console.info('commitModify failed, message =', err);
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

修改文件的元数据，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**  

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let title = userFileManager.ImageVideoKey.TITLE
  let fileAssetTitle = fileAsset.get(title.toString())
  console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  fileAsset.set(title.toString(), "newTitle")
  try {
    await fileAsset.commitModify()
    let newFileAssetTitle = fileAsset.get(title.toString())
    console.info('fileAsset Get newFileAssetTitle = ', newFileAssetTitle);
  } catch (err) {
    console.info('release failed. message = ', err);
  }
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

打开当前文件，使用callback方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO


**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**

| 参数名      | 类型                          | 必填   | 说明                                  |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | 是    | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写） |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调返回文件句柄                            |

**示例：**

```ts
async function example() {
  console.info('openDemo')
   let testFileName = "testFile" + Date.now() + ".jpg";
  const fileAsset = await mgr.createPhotoAsset(testFileName);
  fileAsset.open('rw', (err, fd) => {
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd)
    } else {
      console.info('File err' + err);
    }
  });
}
```

### open

open(mode: string): Promise&lt;number&gt;

打开当前文件，使用promise方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明                                  |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | 是    | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写） |

**返回值：**

| 类型                    | 说明            |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise返回文件句柄 |

**示例：**

```ts
async function example() {
  console.info('openDemo')
  try {
    let testFileName = "testFile" + Date.now() + ".jpg";
    const fileAsset = await mgr.createPhotoAsset(testFileName);
    let fd = await fileAsset.open('rw')
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd)
    } else {
      console.info(' open File fail');
    }
  } catch (err) {
    console.info('open Demo err' + err);
  }
}
```

### close

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

关闭当前文件，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | 是    | 文件描述符 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调返回空 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo')
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
        console.info('close failed, message = ' + err);
      }
    });
  } catch (err) {
    console.info('close failed, message = ' + err);
  }
}
```

### close

close(fd: number): Promise&lt;void&gt;

关闭当前文件，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| fd   | number | 是    | 文件描述符 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo')
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
    await asset.close(fd)
    console.info('asset close succeed.');
  } catch (err) {
    console.info('close failed, message = ' + err);
  }
}
```

### getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是    | 回调返回缩略图的PixelMap |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName)
  asset.getThumbnail((err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.info('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size: image.Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，传入缩略图尺寸，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [image.Size](js-apis-image.md#size) | 是    | 缩略图尺寸            |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是    | 回调返回缩略图的PixelMap |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName)
  asset.getThumbnail(size, (err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.info('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size?: image.Size): Promise&lt;image.PixelMap&gt;

获取文件的缩略图，传入缩略图尺寸，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型             | 必填   | 说明    |
| ---- | -------------- | ---- | ----- |
| size | [image.Size](js-apis-image.md#size) | 否    | 缩略图尺寸 |

**返回值：**

| 类型                            | 说明                    |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise返回缩略图的PixelMap |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName)
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err) => {
    console.info('getThumbnail fail' + err);
  });
}
```

### favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

将文件设置为收藏文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                 |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | 是    | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调返回空                              |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo')
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
      console.info("favorite failed with error:" + err);
    }
  });
}
```

### favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;

将文件设置为收藏文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| isFavorite | boolean | 是    | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo')
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
    console.info("favorite failed with error:" + err);
  });
}
```

## FetchResult

文件检索结果集。

### getCount

getCount(): number

获取文件检索结果中的文件总数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型     | 说明       |
| ------ | -------- |
| number | 检索到的文件总数 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getCountDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('fetchCount = ', fetchCount)
}
```

### isAfterLast

isAfterLast(): boolean

检查结果集是否指向最后一行。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型      | 说明                                 |
| ------- | ---------------------------------- |
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false。 |

**示例**：

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

释放 FetchFileResult 实例并使其失效。无法调用其他方法。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fetchResultCloseDemo')
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
    console.info('close fail. message = ' + err);
  }
}
```

### getFirstObject

getFirstObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的第一个文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | 是   | 异步获取结果集中的第一个完成后的回调 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getFirstObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName)
    } else {
      console.info("fileAsset failed with err:" + err);
    }
  });
}
```

### getFirstObject

getFirstObject(): Promise&lt;T&gt;

获取文件检索结果中的第一个文件资产。此方法使用promise方式来异步返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise&lt;T&gt; | Promise方式返回。 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('fileAsset displayName: ', fileAsset.displayName)
}
```

### getNextObject

 getNextObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的下一个文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名    | 类型                                          | 必填 | 说明                                      |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;T&gt; | 是   | 异步返回结果集中下一个之后的回调 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo')
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
        console.info('fileAsset displayName: ', fileAsset.displayName)
      } else {
        console.info("fileAsset failed with err:" + err);
      }
    });
  }
}
```

### getNextObject

 getNextObject(): Promise&lt;T&gt;

获取文件检索结果中的下一个文件资产。此方法使用promise方式来异步返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | 返回结果集中下一个对象 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (fetchResult.isAfterLast()) {
    let fileAsset = await fetchResult.getNextObject();
    console.info('fileAsset displayName: ', fileAsset.displayName)
  }
}
```

### getLastObject

getLastObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                        |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;T&gt; | 是   | 异步返回结果集中最后一个的回调 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getLastObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName)
    } else {
      console.info("fileAsset failed with err:" + err);
    }
  });
}
```

### getLastObject

getLastObject(): Promise&lt;T&gt;

获取文件检索结果中的最后一个文件资产。此方法使用Promise方式来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | 返回结果集中最后一个对象 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getLastObject();
  console.info('fileAsset displayName: ', fileAsset.displayName)
}
```

### getPositionObject

getPositionObject(index: number, callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中具有指定索引的文件资产。此方法使用callback来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名       | 类型                                       | 必填   | 说明                 |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | 是    | 要获取的文件的索引，从0开始     |
| callback | AsyncCallback&lt;T&gt; | 是    | 异步返回指定索引的文件资产的回调 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getPositionObject(0, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName)
    } else {
      console.info("fileAsset failed with err:" + err);
    }
  });
}
```

### getPositionObject

getPositionObject(index: number): Promise&lt;T&gt;

获取文件检索结果中具有指定索引的文件资产。此方法使用Promise形式返回文件Asset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名    | 类型     | 必填   | 说明             |
| ----- | ------ | ---- | -------------- |
| index | number | 是    | 要获取的文件的索引，从0开始 |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | 返回指定索引的文件资产的对象 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getPositionObject(0);
  console.info('fileAsset displayName: ', fileAsset.displayName)
}
```

## Album

实体相册

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 可读   | 可写   | 说明      |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | 是    | 是    | 相册名称    |
| albumUri | string | 是    | 否    | 相册Uri   |
| dateModified | number | 是    | 否    | 修改日期    |
| count | number | 是    | 否    | 相册中文件数量 |
| coverUri | string | 是    | 否    | 封面文件Uri 

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取相册中的文件。该方法使用callback形式来返回文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback 返回图片和视频数据结果集|

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoCallback')

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
      console.info("album getPhotoAssets successfully, getCount:" + albumFetchResult.getCount());
    } else {
      console.info("album getPhotoAssets failed with error:" + err);
    }
  });
}
```
### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取相册中的文件。该方法使用Promise来返回文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项 |
| Promise | [FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt; | 是   | 图片和视频数据结果集 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoPromise')

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
    console.info("album getFileAssets successfully, getCount:" + albumFetchResult.getCount());
  }).catch((err) => {
    console.info("album getFileAssets failed with error:" + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify((err) => {
    if (err != undefined) {
      console.info("commitModify failed with error:" + err);
    } else {
      console.info("commitModify successfully");
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;;

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                  | 说明           |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise调用返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo')
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  try {
    var albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  } catch (err) {
    console.info('getPhotoAlbums failed. message = ', err);
  }
  const album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info("commitModify successfully");
  }).catch((err) => {
    console.info("commitModify failed with error:" + err);
  });
}
```

## PrivateAlbum
系统相册

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 可读   | 可写   | 说明      |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | 是    | 是    | 相册名称    |
| albumUri | string | 是    | 否    | 相册Uri   |
| dateModified | number | 是    | 否    | 修改日期    |
| count | number | 是    | 否    | 相册中文件数量 |
| coverUri | string | 是    | 否    | 封面文件Uri 

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取系统相册中的文件。该方法使用callback形式来返回文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频数据结果集 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoCallback')
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
      console.info('getFileAssets failed, message = ', err);
    }
  });
}

```
### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取系统相册中的文件。该方法使用Promise来返回文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项 |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise:[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;| 图片和视频数据结果集 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoPromise')
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

删除系统相册中的文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例**：

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
      console.info('trashAlbum.delete failed, message = ', err);
    } else {
      console.info('trashAlbum.delete successfully');
    }
  });
}
```
### delete

delete(uri: string): Promise&lt;void&gt;;

删除系统相册中的文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| 回调返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumDeleteDemoPromise')
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
    console.info('trashAlbum.delete failed, message = ', err);
  });
}   
```

### recover

recover(uri: string, callback: AsyncCallback&lt;void&gt;): void;

恢复系统相册中的文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例**：

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
      console.info('trashAlbum.recover failed, message = ', err);
    } else {
      console.info('trashAlbum.recover successfully');
    }
  });
}
```
### recover

recover(uri: string): Promise&lt;void&gt;;

恢复系统相册中的文件

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| 回调返回空 |

**示例**：

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumRecoverDemoPromise')
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
    console.info('trashAlbum.recover failed, message = ', err);
  });
}
```

## MemberType

成员类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core
 
| 名称  |  类型 |  可读  |  可写  |  说明  |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | 是 | 是 | number类型 | 
| string |  string | 是 | 是 | string类型 | 
| boolean |  boolean | 是 | 是 | boolean类型 | 

## ChangeEvent

变更监听的媒体文件类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  类型 |  可读  |  可写    说明 |
| ----- |  ---- |  ---- |  ---- |  ---- |
| deviceChange |  string | 是 | 是 |  设备 |
| albumChange |  string | 是 | 是 |  相册 |
| imageChange |  string | 是 | 是 |  图片 |
| audioChange |  string | 是 | 是 |  音频 |
| videoChange |  string | 是 | 是 |  视频 |
| remoteFileChange |  string | 是 | 是 |  远程文件 |

## PeerInfo

注册设备的信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.DistributedCore

| 名称       | 类型                       | 可读 | 可写 | 说明             |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | 是   | 否   | 注册设备的名称   |
| networkId  | string                     | 是   | 否   | 注册设备的网络ID |
| isOnline   | boolean                    | 是   | 否   | 是否在线         |


## FileType

枚举，媒体文件类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| IMAGE |  1 |  图片 |
| VIDEO |  2 |  视频 |
| AUDIO |  3 |  音频 |

## PrivateAlbumType

枚举，系统相册类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称    |  值 |   说明   |
| -----   |  ----  |   ----  |
| TYPE_FAVORITE |  0 |  收藏夹相册 |
| TYPE_TRASH |  1 |  回收站相册 |



## AudioKey

枚举，音频文件关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          |   值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri                                                   |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |
| TITLE         | title               | 文件标题                                                   |
| ARTIST        | artist              | 作者                                                   |
| AUDIOALBUM    | audio_album         | 专辑                                                   |
| DURATION      | duration            | 持续时间（单位：毫秒）                                    |
| FAVORITE      | favorite            | 收藏                                                   |

## ImageVideoKey

枚举，图片和视频文件关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri                                                   |
| FILE_TYPE     | file_type           | 媒体文件类型                                              |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |
| TITLE         | title               | 文件标题                                                   |
| DURATION      | duration            | 持续时间（单位：毫秒）                                    |
| WIDTH         | width               | 图片宽度（单位：像素）                                    |
| HEIGHT        | height              | 图片高度（单位：像素）                                      |
| DATE_TAKEN    | date_taken          | 拍摄日期（文件拍照时间到1970年1月1日的秒数值）                |
| ORIENTATION   | orientation         | 图片文件的方向                                             |
| FAVORITE      | favorite            | 收藏                                                    |

## AlbumKey

枚举，相册关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 相册uri                                                   |
| FILE_TYPE     | file_type           | 媒体文件类型                                              |
| ALBUM_NAME    | album_name          | 相册名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |


## FetchOptions

检索条件。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 可读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | 是   | 是   | 检索条件，指定列名查询，如果该参数为空时默认查询uri、name、fileType。示例：<br />fetchColumns: "uri"|
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | 是   | 是   | 谓词查询，显示过滤条件 |

## AlbumFetchOptions

相册检索条件。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 可读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | 是   | 是   | 谓词查询，显示过滤条件 |

