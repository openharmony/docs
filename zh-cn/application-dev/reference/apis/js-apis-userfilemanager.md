# 用户数据管理

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 该模块从API Version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```js
import userFileManager from '@ohos.filemanagement.userfile_manager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

获取用户数据管理模块的实例，用于访问和修改用户等用户公共媒体数据信息（如音频、视频、图片、文档等）。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：** 

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](../apis/js-apis-Context.md) | 是   | 传入Ability实例的Context。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | 媒体库实例 |

**示例：**

```ts
const context = getContext(this);
let userFileMgr = userfilemanager.getUserFileMgr(context);
```

## userFileManager.getUserFileMgr

getUserFileMgr(): UserFileManager

获取用户数据管理模块的实例，用于访问和修改用户等用户公共媒体数据信息（如音频、视频、图片、文档等）。

**模型约束：** 此接口仅可在FA模型下使用。

> **说明**： 推荐使用Stage模型接口[UserFileManager.getUserFileMgr](#userfilemanagergetuserfilemgr)。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                          | 说明       |
| ----------------------------- | :--------- |
| [UserFileManager](#userfilemanager) | 媒体库实例 |

**示例：**

```js
let userFileMgr = userfilemanager.getUserFileMgr();
```

## UserFileManager

### getPublicDirectory

getPublicDirectory(type: DirectoryType, callback: AsyncCallback&lt;string>): void;

获取系统预设的公共目录，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type     | [DirectoryType](#directorytype)            | 是   | 公共目录类型              |
| callback | AsyncCallback&lt;string> | 是   | callback 返回公共目录路径 |

**示例：**

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

获取系统预设的公共目录，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明         |
| ------ | ------------- | ---- | ------------ |
| type   | [DirectoryType](#directorytype) | 是   | 公共目录类型 |

**返回值：**

| 类型             | 说明             |
| ---------------- | ---------------- |
| Promise\<string> | 返回公共目录路径 |

**示例：**

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

获取文件资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type     | Array&lt;[MediaType](#mediatype)>      | 是   | 媒体类型检索范围          |
| options  | [MediaFetchOptions](#mediafetchoptions)        | 是   | 文件检索选项              |
| callback | AsyncCallback&lt;string> | 是   | callback 返回文件检索结果 |

**示例：**

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

获取文件资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT

**参数：**

| 参数名  | 类型                | 必填 | 说明             |
| ------- | ------------------- | ---- | ---------------- |
| type    | Array&lt;[MediaType](#mediatype)> | 是   | 媒体类型检索范围 |
| options | [MediaFetchOptions](#mediafetchoptions)   | 是   | 文件检索选项     |

**返回值**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchFileResult](#fetchfileresult)> | 文件数据结果集 |

**示例：**

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

打开文件管理库变更通知，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'fileChange'：     &nbsp;文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更 |
| callback | Callback&lt;void&gt; | 是   | 回调返回空                                                   |

**示例：**

```ts
async function onDemo() {
    console.info('onDemo')
    userFileMgr.on('imageChange', () => {
      // image file had changed, do something
    });
}
```

### off

off(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback?: Callback&lt;void&gt;): void

关闭文件管理库变更通知，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | string               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'fileChange'：     &nbsp;文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更 |
| callback | Callback&lt;void&gt; | 否   | 回调返回空                                                   |

**示例：**

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

创建文件资源，使用callback方式返回结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**参数：**

| 参数名       | 类型                        | 必填 | 说明                                                         |
| ------------ | --------------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype)      | 是   | 媒体类型                                                     |
| displayName  | string                      | 是   | 展示文件名                                                   |
| relativePath | string                      | 是   | 文件保存路径，可以通过getPublicDirectory获取不同类型文件的保存路径 |
| callback     | AsyncCallback&lt;[FileAsset](#fileasset)> | 是   | 异步获取媒体数据FileAsset之后的回调                          |

**示例：**

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

创建文件资源，使用Promise方式返回结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**参数：**

| 参数名       | 类型      | 必填 | 说明                                                         |
| ------------ | --------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#mediatype) | 是   | 媒体类型                                                     |
| displayName  | string    | 是   | 展示文件名                                                   |
| relativePath | string    | 是   | 文件保存路径，可以通过getPublicDirectory获取不同类型文件的保存路径 |

**返回值**

| 类型                  | 说明              |
| --------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)> | 媒体数据FileAsset |

**示例：**

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

删除文件资源，使用callback方式返回结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**参数：**

| 参数名   | 类型                        | 必填 | 说明                   |
| -------- | --------------------------- | ---- | ---------------------- |
| uri      | string                      | 是   | 文件URI                |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)> | 是   | 异步删除文件之后的回调 |

**示例：**

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

创建文件资源，使用Promise方式返回结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**参数：**

| 参数名 | 类型   | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| uri    | string | 是   | 文件URI |

**返回值**

| 类型             | 说明                              |
| ---------------- | --------------------------------- |
| Promise&lt;void> | Promise实例，用于获取异步返回结果 |

**示例：**

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

获取相册列表，使用callback 方式返回结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**

| 参数名   | 类型                                 | 必填 | 说明                        |
| -------- | ------------------------------------ | ---- | --------------------------- |
| type     | Array&lt;[MediaType](#mediatype)>                  | 是   | 相册媒体类型检索范围        |
| options  | [MediaFetchOptions](#mediafetchoptions)                    | 是   | 相册获取条件                |
| callback | AsyncCallback&lt;Array&lt;[Album](#album)>&gt; | 是   | 异步获取Album列表之后的回调 |

**示例：**

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

获取相册列表，使用 promise 方式返回结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**

| 参数名  | 类型                | 必填 | 说明                 |
| ------- | ------------------- | ---- | -------------------- |
| type    | Array&lt;[MediaType](#mediatype)> | 是   | 相册媒体类型检索范围 |
| options | [MediaFetchOptions](#mediafetchoptions)   | 是   | 相册获取条件         |

**返回值：**

| 类型                     | 说明                       |
| ------------------------ | -------------------------- |
| Promise<Array&lt;[Album](#album)>> | Promise实例，返回Album列表 |

**示例：**

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

获取系统相册，使用 callback 方式返回系统相册的数组。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENTS

**参数：**

| 参数名   | 类型                                  | 必填 | 说明                               |
| -------- | ------------------------------------- | ---- | ---------------------------------- |
| type     | [VirtualAlbumType](#virtualalbumtype)                      | 是   | 系统相册类型                       |
| callback | AsyncCallback<Array&lt;[VirtualAlbum](#virtualalbum)>> | 是   | 异步获取VirtualAlbum数组之后的回调 |

**示例：**

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

获取系统相册，使用 Promise 方式返回系统相册的数组。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENTS

**参数：**

| 参数名 | 类型             | 必填 | 说明         |
| ------ | ---------------- | ---- | ------------ |
| type   | [VirtualAlbumType](#virtualalbumtype) | 是   | 系统相册类型 |

**返回值：**

| 类型                            | 说明                              |
| ------------------------------- | --------------------------------- |
| Promise<Array&lt;[VirtualAlbum](#virtualalbum)>> | Promise实例，返回VirtualAlbum数组 |

**示例：**

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

获取在线对端设备的信息，使用callback方式返回异步结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback<Array<[PeerInfo](#peerinfo)>> | 是   | 系统相册类型 |

**示例：**

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

获取在线对端设备的信息，使用promise方式返回异步结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise<Array<[PeerInfo](#peerinfo)>> | Promise实例，返回在线设备列表 |

**示例：**

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

获取所有对端设备的信息，使用callback方式返回异步结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback<Array&lt;[PeerInfo](#peerinfo)>> | 是   | 系统相册类型 |

**示例：**

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

获取所有对端设备的信息，使用promise方式返回异步结果。

此接口为系统接口。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise<Array&lt;[PeerInfo](#peerinfo)>> | Promise实例，返回所有设备列表 |

**示例：**

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

释放UserFileManager实例。
当后续不需要使用UserFileManager实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败 |

**示例：**

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

释放UserFileManager实例。
当后续不需要使用UserFileManager 实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果 |

**示例：**

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

提供封装文件属性的方法。

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称                      | 类型                     | 可读 | 可写 | 说明                                                   |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | 是   | 否   | 文件资源uri（如：dataability:///media/image/2)         |
| mediaType   | [MediaType](#mediatype) | 是   | 否   | 媒体类型                                               |
| displayName               | string                   | 是   | 是   | 显示文件名，包含后缀名                                 |


### isDirectory

isDirectory(callback: AsyncCallback&lt;boolean&gt;): void

判断fileAsset是否为目录，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明                  |
| -------- | ---------------------------- | ---- | ------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 当前FileAsset是否是目录的回调 |

**示例：**

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

判断fileAsset是否为目录，使用Promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                     | 说明                           |
| ---------------------- | ---------------------------- |
| Promise&lt;boolean&gt; | Promise实例，返回当前FileAsset是否是目录 |

**示例：**

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

修改文件的元数据，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调返回空 |

**示例：**

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

修改文件的元数据，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

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

打开当前文件，使用callback方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT 或 ohos.permission.WRITE_MEDIA 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT


**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**

| 参数名      | 类型                          | 必填   | 说明                                  |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | 是    | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写） |
| callback | AsyncCallback&lt;number&gt; | 是    | 回调返回文件句柄                            |

**示例：**

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

打开当前文件，使用promise方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.READ_DOCUMENT 或 ohos.permission.WRITE_MEDIA 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

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

关闭当前文件，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | 是    | 文件描述符 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调返回空 |

**示例：**

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

获取文件的缩略图，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](../apis/js-apis-image.md#pixelmap7)&gt; | 是    | 回调返回缩略图的PixelMap |

**示例：**

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

获取文件的缩略图，传入缩略图尺寸，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [Size](#size)                      | 是    | 缩略图尺寸            |
| callback | AsyncCallback&lt;[image.PixelMap](../apis/js-apis-image.md#pixelmap7)&gt; | 是    | 回调返回缩略图的PixelMap |

**示例：**

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

获取文件的缩略图，传入缩略图尺寸，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型             | 必填   | 说明    |
| ---- | -------------- | ---- | ----- |
| size | [Size](#size) | 否    | 缩略图尺寸 |

**返回值：**

| 类型                            | 说明                    |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](../apis/js-apis-image.md#pixelmap7)&gt; | Promise返回缩略图的PixelMap |

**示例：**

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

将文件设置为收藏文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                 |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | 是    | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏 |
| callback   | AsyncCallback&lt;void&gt; | 是    | 回调返回空                              |

**示例：**

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
        // do something
    });
}
```

### favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;

将文件设置为收藏文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

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

判断该文件是否为收藏文件，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明          |
| -------- | ---------------------------- | ---- | ----------- |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 回调表示是否为收藏文件 |

**示例：**

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

判断该文件是否为收藏文件，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                     | 说明                 |
| ---------------------- | ------------------ |
| Promise&lt;boolean&gt; | Promise回调表示是否是收藏文件 |

**示例：**

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

当文件被定位时，将文件放到垃圾文件夹，使用callback方式返回异步结果。

放入垃圾文件夹的文件不会被真正删除，可以通过isTrash = false参数恢复成正常文件。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明        |
| -------- | ------------------------- | ---- | --------- |
| isTrash  | boolean                   | 是    | 是否设置为垃圾文件 |
| callback | AsyncCallback&lt;void&gt; | 是    | 回调返回空     |

**示例：**

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

当文件被定位时，将文件放到垃圾文件夹，使用promise方式返回异步结果。

放入垃圾文件夹的文件不会被真正删除，可以通过isTrash = false参数恢复成正常文件。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名     | 类型      | 必填   | 说明        |
| ------- | ------- | ---- | --------- |
| isTrash | boolean | 是    | 是否设置为垃圾文件 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

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

当文件被定位，判断文件是否为垃圾文件，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                           | 必填   | 说明              |
| -------- | ---------------------------- | ---- | --------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是    | 回调返回表示文件是否为垃圾文件 |

**示例：**

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

当文件被定位，判断文件是否为垃圾文件，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明                   |
| ------------------- | -------------------- |
| Promise&lt;void&gt; | Promise回调表示文件是否为垃圾文件 |

**示例：**

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

检查结果集是否指向最后一行。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型      | 说明                                 |
| ------- | ---------------------------------- |
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false。 |

**示例**：

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

释放 FetchFileResult 实例并使其失效。无法调用其他方法。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**示例**：

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

获取文件检索结果中的第一个文件资产。此方法使用回调返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | 异步获取结果集中第一个FileAsset完成后的回调 |

**示例**：

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

获取文件检索结果中的第一个文件资产。此方法使用Promise方式返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise方式返回FileAsset。 |

**示例**：

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

获取文件检索结果中的下一个文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名    | 类型                                          | 必填 | 说明                                      |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | 异步返回结果集中下一个FileAsset之后的回调 |

**示例**：

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

获取文件检索结果中的下一个文件资产。此方法使用promise方式来异步返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | 返回FileAsset对象 |

**示例**：

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

获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                          | 必填 | 说明                        |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | 异步返回FileAsset之后的回调 |

**示例**：

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

获取文件检索结果中的最后一个文件资产。此方法使用Promise方式来返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | 返回FileAsset对象 |

**示例**：

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

获取文件检索结果中具有指定索引的文件资产。此方法使用回调来返回FileAsset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名       | 类型                                       | 必填   | 说明                 |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | 是    | 要获取的文件的索引，从0开始     |
| callback | AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是    | 异步返回FileAsset之后的回调 |

**示例**：

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

获取文件检索结果中具有指定索引的文件资产。此方法使用Promise形式返回文件Asset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名    | 类型     | 必填   | 说明             |
| ----- | ------ | ---- | -------------- |
| index | number | 是    | 要获取的文件的索引，从0开始 |

**返回值**：

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | 返回FileAsset对象 |

**示例**：

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

实体相册

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 可读   | 可写   | 说明      |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | 是    | 是    | 相册名称    |
| albumUri | string | 是    | 否    | 相册Uri   |
| dateModified | number | 是    | 否    | 修改日期    |
| count | number | 是    | 否    | 相册中文件数量 |
| relativePath | string | 是    | 否    | 相对路径    |
| coverUri | string | 是    | 否    | 封面文件Uri 

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例**：

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

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO 或 ohos.permission.WRITE_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值**：

| 类型                  | 说明           |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise调用返回空 |

**示例**：

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

按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                                | 必填 | 说明                                |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | 是   | 媒体类型检索选项。                      |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | 是   | 异步返回FetchFileResult之后的回调。 |

**示例**：

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

按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名   | 类型                                                | 必填 | 说明                                |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | 是   | 媒体类型检索选项。                      |
| options  | [MediaFetchOptions](#mediafetchoptions)        | 是   | 媒体检索选项。                      |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | 是   | 异步返回FetchFileResult之后的回调。 |

**示例**：

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

按照检索条件获取相册中的文件。此方法使用异步Promise来返回文件结果集。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENT


**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名  | 类型                                     | 必填 | 说明           |
| ------- | ---------------------------------------- | ---- | -------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | 是   | 媒体类型检索选项。                      |
|options  | [MediaFetchOptions](#mediafetchoptions) | 否   | 媒体检索选项。 |

**返回值**：

| 类型                                          | 说明                      |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult)> | 返回FetchFileResult对象。 |

**示例**：

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
虚拟相册

### getFileAssets

getFileAssets(type: Array&lt;MediaType&gt;, options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void;

按照检索条件获取虚拟相册中的文件。此方法使用Callback回调来返回文件结果集。

此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENTS

> 说明：
> 本接口所需申请的分类的权限APL等级为system_basic。APL等级为normal的应用需要通过ACL证书方式申请，申请方式请参考[ACL说明](../../security/accesstoken-overview.md#访问控制列表acl说明)
>
> 建议通过options参数显式地指定要访问的文件类型。若无法判断文件类型，则会根据应用实际申请的权限返回对应的文件资源结果集。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：
| 参数名   | 类型                                                | 必填 | 说明                                |
| -------- | --------------------------------------------------- | ---- | ----------------------------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | 是   | 媒体类型检索选项。                      |
| options  | [MediaFetchOptions](#mediafetchoptions)        | 是   | 媒体检索选项。                      |
| callback | AsyncCallback<[FetchFileResult](#fetchfileresult)> | 是   | 异步返回FetchFileResult之后的回调。 |

**示例**：

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

按照检索条件获取虚拟相中的文件。此方法使用异步Promise来返回文件结果集。

此接口为系统接口。

**需要权限**：ohos.permission.READ_IMAGEVIDEO or ohos.permission.READ_AUDIO or ohos.permission.READ_DOCUMENTS

> 说明：
> 本接口所需申请的分类的权限APL等级为system_basic。APL等级为normal的应用需要通过ACL证书方式申请，申请方式请参考[ACL说明](../../security/accesstoken-overview.md#访问控制列表acl说明)
>
> 建议通过options参数显式地指定要访问的文件类型。若无法判断文件类型，则会根据应用实际申请的权限返回对应的文件资源结果集。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数**：

| 参数名  | 类型                                     | 必填 | 说明           |
| ------- | ---------------------------------------- | ---- | -------------- |
| type  | Array&lt;[MediaType](#mediatype)&gt;        | 是   | 媒体类型检索选项。                      |
|options  | [MediaFetchOptions](#mediafetchoptions) | 否   | 媒体检索选项。 |

**返回值**：

| 类型                                          | 说明                      |
| --------------------------------------------- | ------------------------- |
| Promise<[FetchFileResult](#fetchfileresult)> | 返回FetchFileResult对象。 |

**示例**：

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

注册设备的信息。
此接口为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.DistributedCore

| 名称       | 类型                       | 可读 | 可写 | 说明             |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | 是   | 否   | 注册设备的名称   |
| networkId  | string                     | 是   | 否   | 注册设备的网络ID |
| isOnline   | boolean                    | 是   | 否   | 是否在线         |

## MediaType

枚举，媒体类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  说明 |
| ----- |  ---- |
| FILE  |  文件 |
| IMAGE |  图片 |
| VIDEO |  视频 |
| AUDIO |  音频 |

## FileKey

枚举，文件关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 默认值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI            | uri                | 文件uri                                                   |
| RELATIVE_PATH | relative_path       | 相对公共目录路径                                           |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |
| TITLE         | title               | 文件标题                                                   |

## AudioKey

枚举，音频文件关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 默认值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri                                                   |
| RELATIVE_PATH | relative_path       | 相对公共目录路径                                           |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |
| TITLE         | title               | 文件标题                                                   |
| ARTIST        | artist              | 作者                                                   |
| AUDIOALBUM    | audio_album         | 专辑                                                   |
| DURATION      | duration            | 持续时间（单位：毫秒）                                    |

## ImageVideoKey

枚举，图片和视频文件关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 默认值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri                                                   |
| RELATIVE_PATH | relative_path       | 相对公共目录路径                                           |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |
| DURATION      | duration            | 持续时间（单位：毫秒）                                    |
| WIDTH         | width               | 图片宽度（单位：像素）                                    |
| HEIGHT        | height              | 图片高度（单位：像素）                                      |
| DATE_TAKEN    | date_taken          | 拍摄日期（文件拍照时间到1970年1月1日的秒数值）                |

## AlbumKey

枚举，相册关键信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 默认值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 相册uri                                                   |
| RELATIVE_PATH | relative_path       | 相对公共目录路径                                           |
| DISPLAY_NAME  | display_name        | 显示名字                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）             |

## DirectoryType

枚举，目录类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          |  说明               |
| ------------- |  ------------------ |
| DIR_CAMERA    |  表示Camera文件路径 |
| DIR_VIDEO     |  表示视频路径       |
| DIR_IMAGE     |  表示图片路径       |
| DIR_AUDIO     |  表示音频路径       |
| DIR_DOCUMENTS |  表示文档路径       |
| DIR_DOWNLOAD  |  表示下载路径       |

## MediaFetchOptions

检索条件。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称                    | 类型                | 可读 | 可写 | 必填 | 说明                                                         |
| ----------------------- | ------------------- | ---- | ---- | ---- | ------------------------------------------------------------ |
| selections              | string              | 是   | 是   | 是   | 检索条件，使用[FileKey](#filekey)中的枚举值作为检索条件的列名。示例：<br />selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ? OR' +mediaLibrary.FileKey.MEDIA_TYPE + '= ?‘, |
| selectionArgs           | Array&lt;string&gt; | 是   | 是   | 是   | 检索条件的值，对应selections中检索条件列的值。<br />示例：<br />selectionArgs: [mediaLibrary.MediaType.IMAGE.toString(), mediaLibrary.MediaType.VIDEO.toString()], |

## Size

图片尺寸。
**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称     | 类型     | 可读   | 可写   | 说明       |
| ------ | ------ | ---- | ---- | -------- |
| width  | number | 是    | 是    | 宽（单位：像素） |
| height | number | 是    | 是    | 高（单位：像素） |

## VirtualAlbumType
枚举，系统相册或虚拟相册类型

以下接口均为系统接口。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.FileManagement.UserFileManager.Core

| 名称          |  说明               |
| ------------- |  ------------------ |
| TYPE_FAVORITE    | 系统相册：收藏夹相册<br/>该接口为系统接口。 |
| TYPE_TRASH       | 系统相册：回收站相册<br/>该接口为系统接口。 |

