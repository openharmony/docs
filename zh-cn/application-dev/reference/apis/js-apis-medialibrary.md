媒体库管理
==========

 导入模块
---------

```
import medialibrary from '@ohos.multimedia.medialibrary';
```


## getMediaLibrary

function getMediaLibrary(context: Context): MediaLibrary;

获取媒体库。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：** 

| 参数名  | 类型    | 必填 | 说明                 |
| ------- | ------- | ---- | -------------------- |
| context | Context | 是 | API 8接口此参数是必填参数，传入Ability实例的context，获取媒体库 |

**返回值：**

| 类型         | 说明   |
| ------------ | :----- |
| MediaLibrary | 媒体库实例 |

**示例：**

```
import featureAbility from '@ohos.ability.featureAbility';
var context = featureAbility.getContext()
var media = mediaLibrary.getMediaLibrary(context);
```

## medialibrary.getFileAssets


getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void;    

获取文件资源，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                              |
| -------- | ----------------------------------------------------------- | ---- | --------------------------------- |
| options  | [MediaFetchOptions](#MediaFetchOptions)                     | 是   | 媒体获取选项                      |
| callback | AsyncCallback<[FetchFileResult](#FetchFileResult.getCount)> | 是   | 异步获取FetchFileResult之后的回调 |

**示例：**

```
let fileKeyObj = mediaLibrary.FileKey
let imageType = mediaLibrary.MediaType.IMAGE
let imagesfetchOp = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
};
medialibrary.getFileAssets(imagesfetchOp, (error, fetchFileResult) => {
    if (fetchFileResult != undefined) {
        console.info('MediaLibraryTest : ASSET_CALLBACK fetchFileResult success');
        fetchFileResult.getAllObject((err, fileAssetList) => {
            if (fileAssetList != undefined) {
                fileAssetList.forEach(getAllObjectInfo);
            }
    });
});
```
## medialibrary.getFileAssets

getFileAssets(options: MediaFetchOptions): Promise&lt;FetchFileResult&gt;;

获取文件资源，使用Promise方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名  | 类型                                    | 必填 | 说明         |
| ------- | --------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#MediaFetchOptions) | 是   | 媒体检索选项 |

**返回值**

| 类型                                         | 说明           |
| -------------------------------------------- | -------------- |
| [FetchFileResult](#FetchFileResult.getCount) | 媒体数据结果集 |

**示例：**

```
let fileKeyObj = mediaLibrary.FileKey
let imageType = mediaLibrary.MediaType.IMAGE
let imagesfetchOp = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [imageType.toString()],
};
medialibrary.getFileAssets(imagesfetchOp).then(function(fetchFileResult){
    console.info("getFileAssets successfully:"+ JSON.stringify(dir));
}).catch(function(err){
    console.info("getFileAssets failed with error:"+ err);
});
```

## medialibrary.on

on(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback: Callback&lt;void&gt;): void;

打开媒体媒体库变更通知，使用callback方式返回异步结果。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                   |
| -------- | ---------------- | ---- | ------------------- |
| type  | type   | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>’audioChange‘： &nbsp;音频文件变更<br/>‘videoChange’：  &nbsp;视频文件变更<br/>‘'fileChange'：     &nbsp;文件变更<br/>‘remoteFileChange’：&nbsp;注册设备上文件变更 |
| callback | callback&lt;void&gt; | 是   | 回调返回空 |

**示例：**

```
medialibrary.on('imageChange', () => {
    this.sendNotify('image');
})
```
## medialibrary.off

off(type: 'deviceChange'|'albumChange'|'imageChange'|'audioChange'|'videoChange'|'fileChange'|'remoteFileChange', callback?: Callback&lt;void&gt;): void;

关闭媒体媒体库变更通知，使用callback方式返回异步结果。

变更通知类型包括：注册设备变更，相册变更，图片文件变更，音频文件变更，视频文件变更，文件变更，远端文件变更。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                   |
| -------- | ---------------- | ---- | ------------------- |
| type  | type   | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>’audioChange‘： &nbsp;音频文件变更<br/>‘videoChange’：  &nbsp;视频文件变更<br/>‘'fileChange'：     &nbsp;文件变更<br/>‘remoteFileChange’：&nbsp;注册设备上文件变更         |
| callback | callback&lt;void&gt; | 否   | 回调返回空 |

**示例：**

```
medialibrary.off('imageChange', () => {
    this.sendNotify('image');
})
```

## medialibrary.createAsset

createAsset(mediaType: MediaType, displayName: string, relativePath: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

创建媒体资源，使用callback方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名       | 类型                                   | 必填 | 说明                                                         |
| ------------ | -------------------------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#MediaType)                | 是   | 媒体类型                                                     |
| displayName  | string                                 | 是   | 展示文件名                                                   |
| relativePath | string                                 | 是   | 相对路径，可以通过getPublicDirectory获取不同类型媒体文件的一层目录的relative path |
| callback     | AsyncCallback<[FileAsset](#FileAsset)> | 是   | 异步获取媒体数据FileAsset之后的回调                          |

**示例：**

```
// 使用Callback方式创建Image类型文件
let mediaType = mediaLibrary.MediaType.IMAGE;
let path = "Pictures/";
medialibrary.createAsset(mediaType, “imageCallBack.jpg”, path, (err, albumFetchFileResult) => {
    if (albumFetchFileResult != undefined) {
        console.info('MediaLibraryTest : ALBUM_CALLBACK getFileAssets success');
        albumFetchFileResult.getAllObject((err, fileAssetList) => {
            if (fileAssetList != undefined) {
                fileAssetList.forEach(getAllObjectInfo);
            } else {
                console.info('getFileAssets fail, message = ' + err);
                console.info('getFileAssets getFileAssets :No data');
            }
        });
    } else {
        console.info('getFileAssets failed, message = ' + err);
    }
});
```

## medialibrary.createAsset

createAsset(mediaType: MediaType, displayName: string, relativePath: string): Promise&lt;FileAsset&gt;;

创建媒体资源，使用Promise方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名       | 类型                    | 必填 | 说明                                                         |
| ------------ | ----------------------- | ---- | ------------------------------------------------------------ |
| mediaType    | [MediaType](#MediaType) | 是   | 媒体类型                                                     |
| displayName  | string                  | 是   | 展示文件名                                                   |
| relativePath | string                  | 是   | 相对路径，可以通过getPublicDirectory获取不同类型媒体文件的一层目录的relative path |

**返回值**

| 类型                    | 说明              |
| ----------------------- | ----------------- |
| [FileAsset](#FileAsset) | 媒体数据FileAsset |

**示例：**

```
// 使用Promise方式创建Image类型文件
let mediaType = mediaLibrary.MediaType.IMAGE;
let path = "Pictures/";
medialibrary.createAsset(mediaType, "image01.jpg", path).then(function(asset){
    console.info("createAsset successfully:"+ JSON.stringify(asset));
}).catch(function(err){
    console.info("createAsset failed with error:"+ err);
});
```

## medialibrary.deleteAsset

deleteAsset(uri: string, callback: AsyncCallback&lt;void&gt;): void;

删除媒体资源，使用callback方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                | 必填 | 说明                   |
| -------- | ------------------- | ---- | ---------------------- |
| uri      | string              | 是   | 文件uri             |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
medialibrary.deleteAsset(asset.uri, (deleteAssetErr, deleteRows) => {
            // do something
});
```

## medialibrary.deleteAsset

deleteAsset(uri: string): Promise&lt;void&gt;;

删除媒体资源，使用promise方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明    |
| ------ | ------ | ---- | ------- |
| uri    | string | 是   | 文件uri |

**返回值：**

| 类型          | 说明                                              |
| ------------- | ------------------------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于异步获取结果。本调用将返回空值 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
medialibrary.deleteAsset(asset.uri).then(()=>{
    console.info("deleteAsset successfully");
}).catch(function(err){
    console.info("deleteAsset failed with error:"+ err);
});
```

## medialibrary.getPublicDirectory

getPublicDirectory(type: DirectoryType, callback: AsyncCallback<string>): void;

获取公共目录路径

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明         |
| ------ | ------------------------------- | ---- | ------------ |
| type   | [DirectoryType](#DirectoryType) | 是   | 公共目录类型 |
| callback   |AsyncCallback&lt;string&gt; | 是   | callback 返回公共目录路径 |


**示例：**

```
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
media.getPublicDirectory(DIR_CAMERA，(err, dicResult) => {
    if (dicResult == 'camera/') {
        console.info('MediaLibraryTest : getPublicDirectory passed');
    } else {
        console.info('MediaLibraryTest : getPublicDirectory failed');
    }
});
```

## medialibrary.getPublicDirectory

getPublicDirectory(type: DirectoryType): Promise<string>;

获取公共目录路径

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型                            | 必填 | 说明         |
| ------ | ------------------------------- | ---- | ------------ |
| type   | [DirectoryType](#DirectoryType) | 是   | 公共目录类型 |

**返回值：**

| 类型            | 说明             |
| --------------- | ---------------- |
| Promise<string> | 返回公共目录路径 |

**示例：**

```
let DIR_CAMERA = mediaLibrary.DirectoryType.DIR_CAMERA;
const dicResult = await media.getPublicDirectory(DIR_CAMERA);
if (dicResult == 'camera/') {
    console.info('MediaLibraryTest : getPublicDirectory passed');    
} else {
    console.info('MediaLibraryTest : getPublicDirectory failed');
}
```

## medialibrary.getAlbums

getAlbums(options: MediaFetchOptions, callback: AsyncCallback<Array&lt;Album&gt;>): void;

获取实体相册，使用callback 方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**

| 参数名   | 类型                                        | 必填 | 说明                        |
| -------- | ------------------------------------------- | ---- | --------------------------- |
| options  | [MediaFetchOptions](#MediaFetchOptions)     | 是   | 媒体文件获取条件            |
| callback | AsyncCallback&lt;Array<[Album](#Album)>&gt; | 是   | 异步获取Album列表之后的回调 |

**示例：**

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
medialibrary.AlbumNoArgsfetchOp, (err, albumList) => {
    if (albumList != undefined) {
        const album = albumList[0];
        console.info('album.albumName = ' + album.albumName);
        console.info('album.count = ' + album.count);
        done();
     } else {
        console.info('getAlbum fail, message = ' + err);
        done();
     }
});
```

## medialibrary.getAlbums

getAlbums(options: MediaFetchOptions): Promise<Array&lt;Album&gt;>;

获取实体相册，使用 promise 方式返回结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名  | 类型                                    | 必填 | 说明             |
| ------- | --------------------------------------- | ---- | ---------------- |
| options | [MediaFetchOptions](#MediaFetchOptions) | 是   | 媒体文件获取条件 |

**返回值：**

| 类型                            | 说明          |
| ------------------------------- | ------------- |
| Promise<Array<[Album](#Album)>> | 返回Album列表 |

**示例：**

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
medialibrary.getAlbums(AlbumNoArgsfetchOp).then(function(albumList){
    console.info("getAlbums successfully:"+ JSON.stringify(albumList));
}).catch(function(err){
    console.info("getAlbums failed with error:"+ err);
});
```

## medialibrary.getActivePeers

getActivePeers(callback: AsyncCallback<Array&lt;PeerInfo&gt;>): void;

获取活动注册设备

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**参数：**

| 参数名   | 类型                            | 必填 | 说明                   |
| -------- | ------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback<Array<[PeerInfo](#PeerInfo)>> | 是   | 回调表示成功还是失败 |

**示例：**

```
medialibrary.getActivePeers((err, data) => {
    // do something    
});
```

## medialibrary.getActivePeers

getActivePeers(): Promise<Array&lt;PeerInfo&gt;>;

获取活动注册设备

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**参数：**

返回值：

| 类型                                  | 说明                              |
| ------------------------------------- | --------------------------------- |
| Promise<Array<[PeerInfo](#PeerInfo)>> | Promise实例，用于获取异步返回结果 |

**示例：**

```
peerInfoList = medialibrary.getActivePeers();
```

## medialibrary.getAllPeers

getAllPeers(callback: AsyncCallback<Array&lt;PeerInfo&gt;>): void;

获取所有注册设备

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**参数：**

| 参数名   | 类型                            | 必填 | 说明                   |
| -------- | ------------------------------ | ---- | ---------------------- |
| callback | AsyncCallback<Array<[PeerInfo](#PeerInfo)>> | 是   | 回调表示成功还是失败 |

**示例：**

```
medialibrary.getAllPeers((err, data) => {
    // do something
});
```

## medialibrary.getAllPeers

getAllPeers(): Promise<Array&lt;PeerInfo&gt;>;

获取所有注册设备

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.DistributedCore

**返回值：**

| 类型                                  | 说明                              |
| ------------------------------------- | --------------------------------- |
| Promise<Array<[PeerInfo](#PeerInfo)>> | Promise实例，用于获取异步返回结果 |

**示例：**

peerInfoList = media.getAllPeers();

## medialibrary.release

release(callback: AsyncCallback&lt;void&gt;): void;

释放MediaLibrary实例

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                   |
| -------- | ------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败 |

**示例：**

```
medialibrary.release((err, data) => {
    // do something
});
```

## medialibrary.release

release(): Promise&lt;void&gt;;

释放MediaLibrary实例 (补充说明)

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值：**

| 类型          | 说明                                |
| ------------- | ----------------------------------- |
| Promise&lt;void&gt; | Promise实例，用于获取异步返回结果 |

**示例：**

```
medialibrary.release()
```

## FileAsset.isDirectory

isDirectory(callback: AsyncCallback&lt;boolean&gt;): void;

判断fileAsset是否为目录，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                          |
| -------- | ---------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 当前FileAsset是否是目录的回调 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isDirectory((err, isDirectory) => {
    // do something
});
```

## FileAsset.isDirectory

isDirectory():Promise&lt;boolean&gt;;

判断fileAsset是否为目录，使用Promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值：**

| 类型             | 说明                                       |
| ---------------- | ------------------------------------------ |
| Promise&lt;boolean&gt; | Promise实例，返回当前FileAsset是否是目录 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isDirectory().then(function(isDirectory){
    console.info("isDirectory result:"+ isDirectory);
}).catch(function(err){
    console.info("isDirectory failed with error:"+ err);
});
```

## FileAsset.commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

修改文件的元数据，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.title = ‘newtitle';
asset.commitModify(() => {
    console.info('commitModify success');   
}
```

## FileAsset.commitModify

commitModify(): Promise&lt;void&gt;;

修改文件的元数据，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.title = ‘newtitle';
asset.commitModify();
```

## FileAsset.open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void;

打开当前文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA（'r'模式打开），ohos.permission.MEDIA_WRITE（‘w’模式打开）

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| mode     | string                 | 是   | 打开文件方式，如：'r', 'w', 'rw' |
| callback | AsyncCallback&lt;number&gt; | 是   | 回调返回文件句柄 |

**示例：**

```
let mediaType = mediaLibrary.MediaType.IMAGE;
let path = "Pictures/";
asset = await media.createAsset(mediaType, "image00003.jpg", path);
asset.open('rw', (openError, fd) => {
        if(fd > 0){
            asset.close(fd);
        }else{
            console.info('File Open Failed!' + openError);
        }
});
```

## FileAsset.open

open(mode: string): Promise&lt;number&gt;;

打开当前文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA（'r'模式打开），ohos.permission.MEDIA_WRITE（‘w’模式打开）

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                             |
| ------ | ------ | ---- | -------------------------------- |
| mode   | string | 是   | 打开文件方式，如：'r', 'w', 'rw' |

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;number&gt; | Promise返回文件句柄 |

**示例：**

```
let mediaType = mediaLibrary.MediaType.IMAGE;
let path = "Pictures/";
asset = await media.createAsset(mediaType, "image00003.jpg", path);
asset.open('rw').then((openError, fd) => {
        if(fd > 0){
            asset.close(fd);
        }else{
            console.info('File Open Failed!' + openError);
        }
});
```

## FileAsset.close

close(fd: number, callback: AsyncCallback&lt;void&gt;): void;

关闭当前文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| fd       | number                 | 是   | 文件描述符          |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.close(fd, (closeErr) => {
    if (closeErr != undefined) {
        console.info('MediaLibraryTest : close : FAIL ' + closeErr.message);
        console.info('MediaLibraryTest : ASSET_CALLBACK : FAIL');
    } else {
        console.info("=======asset.close success====>");
    }
});
```

## FileAsset.close

close(fd: number): Promise&lt;void&gt;;

关闭当前文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| fd     | number | 是   | 文件描述符 |

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.close(fd).then((closeErr) => {
    if (closeErr != undefined) {
        console.info('MediaLibraryTest : close : FAIL ' + closeErr.message);
        console.info('MediaLibraryTest : ASSET_CALLBACK : FAIL');

    } else {
        console.info("=======asset.close success====>");
    }
});
```

## FileAsset.getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void;

获取文件的缩略图，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;image.PixelMap&gt; | 是   | 回调返回缩略图的PixelMap |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.getThumbnail((err, pixelmap) => {
	console.info('MediaLibraryTest : getThumbnail Successfull '+ pixelmap);
});
```

## FileAsset.getThumbnail

getThumbnail(size: Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void;

获取文件的缩略图，传入缩略图尺寸，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| size     | [Size](#Size)          | 是   | 缩略图尺寸          |
| callback | AsyncCallback&lt;image.PixelMap&gt; | 是   | 回调返回缩略图的PixelMap |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.getThumbnail(size, (err, pixelmap) => {
	console.info('MediaLibraryTest : getThumbnail Successfull '+ pixelmap);
});
```

## FileAsset.getThumbnail

getThumbnail(size?: Size): Promise&lt;image.PixelMap&gt;;

获取文件的缩略图，传入缩略图尺寸，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名 | 类型          | 必填 | 说明       |
| ------ | ------------- | ---- | ---------- |
| size   | [Size](#Size) | 否   | 缩略图尺寸 |

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;image.PixelMap&gt; | Promise返回缩略图的PixelMap |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.getThumbnail(size, (err, pixelmap) => {
	console.info('MediaLibraryTest : getThumbnail Successfull '+ pixelmap);
});
```

## FileAsset.favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void;

将文件设置为收藏文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名     | 类型                | 必填 | 说明           |
| ---------- | ------------------- | ---- | -------------- |
| isFavorite | boolean             | 是   | 是否设置为收藏文件, true：设置为收藏文件，false：取消收藏 |
| callback   | AsyncCallback&lt;void&gt; | 是   | 回调返回空    |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.favorite(true,function(err){
    // do something
});
```

## FileAsset.favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;;

将文件设置为收藏文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名     | 类型    | 必填 | 说明                                                      |
| ---------- | ------- | ---- | --------------------------------------------------------- |
| isFavorite | boolean | 是   | 是否设置为收藏文件, true：设置为收藏文件，false：取消收藏 |

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.favorite(true).then(function() {
    console.info("favorite successfully");
}).catch(function(err){
    console.info("favorite failed with error:"+ err);
});
```

## FileAsset.isFavorite

isFavorite(callback: AsyncCallback&lt;boolean&gt;): void;

判断该文件是否为收藏文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                   |
| -------- | ---------------------- | ---- | ---------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调表示是否为收藏文件 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isFavorite((err, isFavorite) => {
    if (isFavorite) {
        console.info('FileAsset is favorite');
    }else{
        console.info('FileAsset is not favorite');
    }
});
```

## FileAsset.isFavorite

isFavorite():Promise&lt;boolean&gt;;

判断该文件是否为收藏文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;boolean&gt; | Promise回调表示是否是收藏文件 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isFavorite().then(function(isFavorite){
    console.info("isFavorite result:"+ isFavorite);
}).catch(function(err){
    console.info("isFavorite failed with error:"+ err);
});
```

## FileAsset.trash

trash(isTrash: boolean, callback: AsyncCallback&lt;void&g;): void;

当文件被定位时，将文件放到垃圾文件夹，使用callback方式返回异步结果。

放入垃圾文件夹的文件不会被真正删除，可以通过isTrash = false参数恢复成正常文件。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| isTrash  | boolean                | 是   | 是否设置为垃圾文件    |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.trash(true, trashCallBack);
function trashCallBack(err, trash) {
    console.info('MediaLibraryTest : ASSET_CALLBACK ASSET_CALLBACK trash');
}
```

## FileAsset.trash

trash(isTrash: boolean,): Promise&lt;void&gt;;

当文件被定位时，将文件放到垃圾文件夹，使用promise方式返回异步结果。

放入垃圾文件夹的文件不会被真正删除，可以通过isTrash = false参数恢复成正常文件。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明               |
| ------- | ------- | ---- | ------------------ |
| isTrash | boolean | 是   | 是否设置为垃圾文件 |

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise返回空 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.trash(true).then(function() {
    console.info("trash successfully");
}).catch(function(err){
    console.info("trash failed with error:"+ err);
});
```

## FileAsset.isTrash

isTrash(callback: AsyncCallback&lt;boolean&gt;): void;

当文件被定位，判断文件是否为垃圾文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                 |
| -------- | ---------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调返回表示文件是否为垃圾文件 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isTrash(isTrashCallBack);
function isTrashCallBack(err, isTrash) {
        if (isTrash == true) {
            console.info('MediaLibraryTest : ASSET_CALLBACK ASSET_CALLBACK isTrash = ' + isTrash);
            asset.trash(true, trashCallBack);
            
        } else {
            console.info('MediaLibraryTest : ASSET_CALLBACK isTrash Unsuccessfull = ' + err);
            console.info('MediaLibraryTest : ASSET_CALLBACK isTrash : FAIL');
            
        }
}
```

## FileAsset.isTrash

isTrash():Promise&lt;boolean&gt;;

当文件被定位，设置文件为垃圾文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值：**

| 类型          | 说明                          |
| ------------- | ----------------------------- |
| Promise&lt;void&gt; | Promise回调表示文件是否为垃圾文件 |

**示例：**

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
const fetchFileResult = await media.getFileAssets(getImageOp);
const asset = await fetchFileResult.getFirstObject();
asset.isTrash().then(function(isTrash){
    console.info("isTrash result:"+ isTrash);
}).catch(function(err){
    console.info("isTrash failed with error:"+ err);
});
```

**FetchFileResult**

文件检索结果集。

## FetchFileResult.getCount

getCount(): number;

获取文件检索结果中的文件总数。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| number | 检索到的文件总数 |

**示例**：

```
let getFileCountOneOp = {
    selections: fileKeyObj.MEDIA_TYPE + '= ?',
    selectionArgs: [fileType.toString()],
    order: fileKeyObj.DATE_ADDED,
    extendArgs: "LIMIT 0,1",
};
let fetchFileResult = await media.getFileAssets(getFileCountOneOp);
const fetchCount = fetchFileResult.getCount();
```

## FetchFileResult.isAfterLast

isAfterLast(): boolean;

检查结果集是否指向最后一行。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 当读到最后一条记录后，再继续读就到结果集尾了，没有记录了，执行isAfterLast()方法就返回true，否则返回false |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
const fetchCount = fetchFileResult.getCount();
console.info('MediaLibraryTest : count:' + fetchCount);
let fileAsset = await fetchFileResult.getFirstObject();
for (var i = 1; i < fetchCount; i++) {
        fileAsset = await fetchFileResult.getNextObject();
        if(i == fetchCount - 1) {
          console.info('MediaLibraryTest : isLast');
          var result = fetchFileResult.isAfterLast();
          console.info('MediaLibraryTest : isAfterLast:' + result);
          console.info('MediaLibraryTest : isAfterLast end');
          fetchFileResult.close();
          
        }
}
```

## FetchFileResult.close

close(): void;

释放 FetchFileResult 实例并使其失效。无法调用其他方法。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.close();
```

## FetchFileResult.getFirstObject

getFirstObject(callback: AsyncCallback&lt;FileAsset&gt;): void;

获取文件检索结果中的第一个文件资产。此方法使用回调返回FileAsset。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数名   | 类型                                         | 必填 | 说明                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#FileAsset)&gt; | 是   | 异步获取结果集中第一个FileAsset完成后的回调 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getFirstObject((err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getFirstObject

getFirstObject(): Promise&lt;FileAsset&gt;;

获取文件检索结果中的第一个文件资产。此方法使用返回FileAsset。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型                | 说明                                   |
| ------------------ | -------------------------------------- |
| Promise&lt;[FileAsset](#FileAsset)&gt; | Promise方式返回FileAsset               |


**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getFirstObject().then(function(fileAsset){
    console.info("getFirstObject successfully:"+ JSON.stringify(fileAsset));
}).catch(function(err){
    console.info("getFirstObject failed with error:"+ err);
});
```

## FetchFileResult.getNextObject

 getNextObject(callback: AsyncCallback&lt;FileAsset&gt;): void;

获取文件检索结果中的下一个文件资产。此方法使用callback形式返回结果。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数名    | 类型                                         | 必填 | 说明                                      |
| --------- | -------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;[FileAsset](#FileAsset)&gt; | 是   | 异步返回结果集中下一个FileAsset之后的回调 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getNextObject((err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getNextObject

 getNextObject(): Promise&lt;FileAsset&gt;;

获取文件检索结果中的下一个文件资产。此方法使用promise方式来异步返回FileAsset。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型                             | 说明                |
| -------------------------------- | ------------------- |
| Promise&lt;[FileAsset](#FileAsset)&gt; | 返回FileAsset对象 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
const fetchCount = fetchFileResult.getCount();
console.info('MediaLibraryTest : count:' + fetchCount);
fileAsset = await fetchFileResult.getNextObject();
```

## FetchFileResult.getLastObject

getLastObject(callback: AsyncCallback&lt;FileAsset&gt;): void;

获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回FileAsset。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数     | 类型                                         | 必填 | 说明                        |
| -------- | -------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;[FileAsset](#FileAsset)&gt; | 是   | 异步返回FileAsset之后的回调 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getLastObject((err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getLastObject

getLastObject(): Promise&lt;FileAsset&gt;;

获取文件检索结果中的最后一个文件资产。此方法使用Promise方式来返回FileAsset。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型                             | 说明                |
| -------------------------------- | ------------------- |
| Promise&lt;[FileAsset](#FileAsset)&gt; | 返回FileAsset对象 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
let lastObject = await fetchFileResult.getLastObject();
```

## FetchFileResult.getPositionObject

getPositionObject(index: number, callback: AsyncCallback&lt;FileAsset&gt;): void;

获取文件检索结果中具有指定索引的文件资产。此方法使用回调来返回FileAsset。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数     | 类型                                         | 必填 | 说明                        |
| -------- | -------------------------------------------- | ---- | --------------------------- |
| index    | number                                       | 是   | 要获取的文件的索引，从0开始 |
| callback | AsyncCallback&lt;[FileAsset](#FileAsset)&gt; | 是   | 异步返回FileAsset之后的回调 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getPositionObject(1，(err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getPositionObject

getPositionObject(index: number): Promise&lt;FileAsset&gt;;

获取文件检索结果中具有指定索引的文件资产。此方法使用Promise形式返回文件Asset。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数  | 类型   | 必填 | 说明                 |
| ----- | ------ | ---- | -------------------- |
| index | number | 是   | 要获取的文件的索引，从0开始 |

**返回值**：

| 类型                             | 说明                |
| -------------------------------- | ------------------- |
| Promise&lt;[FileAsset](#FileAsset)&gt; | 返回FileAsset对象 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getPositionObject(1，(err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getAllObject

getAllObject(callback: AsyncCallback&lt;Array&lt;FileAsset&gt;&gt;): void;

获取文件检索结果中的所有文件资产。此方法使用Callback回调来返回FileAsset结果集。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数     | 类型                                          | 必填 | 说明                            |
| -------- | --------------------------------------------- | ---- | ------------------------------- |
| callback | AsyncCallback<Array<[FileAsset](#FileAsset)>> | 是   | 异步返回FileAsset列表之后的回调 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
fetchFileResult.getAllObject((err, value) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log(value);
})
```

## FetchFileResult.getAllObject

getAllObject(): Promise&lt;Array&lt;FileAsset&gt;&gt;;

获取文件检索结果中的所有文件资产。此方法使用Promise来返回FileAsset结果集。

**需要权限**：无

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型                                    | 说明                  |
| --------------------------------------- | --------------------- |
| Promise<Array<[FileAsset](#FileAsset)>> | 返回FileAsset对象列表 |

**示例**：

```
let imageType = mediaLibrary.MediaType.IMAGE;
let getImageOp = {
  selections: fileKeyObj.MEDIA_TYPE + '= ?',
  selectionArgs: [imageType.toString()],
  order: fileKeyObj.DATE_ADDED,
  extendArgs: "LIMIT 0,10",
};
let fetchFileResult = await media.getFileAssets(getImageOp);
var data = fetchFileResult.getAllObject();
```

## Album.commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数     | 类型                | 必填 | 说明                          |
| -------- | ------------------- | ---- | ----------------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调返回空                  |

**示例**：

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
const album = albumList[0];
album.albumName = 'hello';
album.commitModify((err) => {
   if (err) {
	   console.error('Failed ');
	   return;
   }
   console.log('Modify successful.');
})
```

## Album.commitModify

commitModify(): Promise&lt;void&gt;;

更新相册属性修改到数据库中。

**需要权限**：ohos.permission.READ_MEDIA，ohos.permission.MEDIA_WRITE

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**返回值**：

| 类型          | 说明                                                 |
| ------------- | ---------------------------------------------------- |
| Promise&lt;void&gt; | Promise调用返回空 |

**示例**：

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
const album = albumList[0];
album.albumName = 'hello';
album.commitModify().then(function() {
    console.info("commitModify successfully");
}).catch(function(err){
    console.info("commitModify failed with error:"+ err);
});
```

## Album.getFileAssets

getFileAssets(options: MediaFetchOptions, callback: AsyncCallback&lt;FetchFileResult&gt;): void;

按照检索条件获取相册中的文件。此方法使用Callback回调来返回文件结果集。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数     | 类型                                                        | 必填 | 说明                              |
| -------- | ----------------------------------------------------------- | ---- | --------------------------------- |
| options  | [MediaFetchOptions](#MediaFetchOptions)                     | 是   | 媒体检索选项                      |
| callback | AsyncCallback<[FetchFileResult](#FetchFileResult.getCount)> | 是   | 异步返回FetchFileResult之后的回调 |

**示例**：

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
const album = albumList[0];
album.getFileAssets(fileNoArgsfetchOp, getFileAssetsCallBack);
})
function getFileAssetsCallBack(err, fetchFileResult) {
    // do something
}
```

## Album.getFileAssets

 getFileAssets(options?: MediaFetchOptions): Promise&lt;FetchFileResult&gt;;

按照检索条件获取相册中的文件。此方法使用异步回调来返回文件结果集。

**需要权限**：ohos.permission.READ_MEDIA

**系统能力**：SystemCapability.Multimedia.MediaLibrary.Core

**参数**：

| 参数    | 类型                                    | 必填 | 说明         |
| ------- | --------------------------------------- | ---- | ------------ |
| options | [MediaFetchOptions](#MediaFetchOptions) | 否   | 媒体检索选项 |

**返回值**：

| 类型                                                  | 说明                    |
| ----------------------------------------------------- | ----------------------- |
| Promise<[FetchFileResult](#FetchFileResult.getCount)> | 返回FetchFileResult对象 |

**示例**：

```
let AlbumNoArgsfetchOp = {
    selections: '',
    selectionArgs: [],
};
const albumList = await media.getAlbums(AlbumNoArgsfetchOp);
const album = albumList[0];
album.getFileAssets(fileNoArgsfetchOp).then(function(albumFetchFileResult){
    console.info("getFileAssets successfully:"+ JSON.stringify(albumFetchFileResult));
}).catch(function(err){
    console.info("getFileAssets failed with error:"+ err);
});
```

## PeerInfo

注册设备信息。

| 名称       | 类型       | 可读 | 可写 | 说明           |
| ---------- | ---------- | ---- | ---- | -------------- |
| deviceName | string     | 是   | 否   | 注册设备名称   |
| networkId  | string     | 是   | 否   | 注册设备网络ID |
| deviceType | DeviceType | 是   | 否   | 设备类型       |
| isOnline   | boolean    | 是   | 否   | 是否在线       |

FileAsset
---------

**属性：**

| 名称         | 类型      | 可读 | 可写 | 说明                                                   |
| ------------ | --------- | ---- | ---- | ------------------------------------------------------ |
| id           | number    | 是   | 否   | 文件资源编号                                           |
| uri          | string    | 是   | 否   | 文件资源uri（如：dataability:///media/image/2)         |
| mimeType     | string    | 是   | 否   | 文件扩展属性                                           |
| mediaType    | MediaType | 是   | 否   | 媒体类型                                               |
| displayName  | string    | 是   | 是   | 显示文件名                                             |
| title        | string    | 是   | 是   | 文件标题                                               |
| relativePath | string    | 是   | 是   | 相对路径                                               |
| parent       | number    | 是   | 否   | 父目录id                                               |
| size         | number    | 是   | 否   | 文件大小(单位：字节)                                   |
| dateAdded    | number    | 是   | 否   | 添加日期（添加文件时间到1970年1月1日的秒数值）         |
| dateModified | number    | 是   | 否   | 修改日期（修改文件时间到1970年1月1日的秒数值）         |
| dateTaken    | number    | 是   | 否   | 拍摄日期（文件拍照时间到1970年1月1日的秒数值）         |
| artist       | string    | 是   | 否   | 作者                                                   |
| audioAlbum   | string    | 是   | 否   | 专辑                                                   |
| width        | number    | 是   | 否   | 图片宽度（单位：像素）                                 |
| height       | number    | 是   | 否   | 图片高度（单位：像素）                                 |
| orientation  | number    | 是   | 是   | 图片显示方向（顺时针旋转角度，如0，90，180  单位：度） |
| duration     | number    | 是   | 否   | 持续时间（单位：秒）                                   |
| albumId      | number    | 是   | 否   | 文件所归属的相册编号                                   |
| albumUri     | string    | 是   | 否   | 文件所归属相册uri                                      |
| albumName    | string    | 是   | 否   | 文件所归属相册名称                                     |

Album
---------

实体相册。

**属性**

| 名称         | 参数型 | 可读 | 可写 | 说明           |
| ------------ | ------ | ---- | ---- | -------------- |
| albumId      | number | 是   | 否   | 相册编号       |
| albumName    | string | 是   | 是   | 相册名称       |
| albumUri     | string | 是   | 否   | 相册Uri        |
| dateModified | number | 是   | 否   | 修改日期       |
| count        | number | 是   | 否   | 相册中文件数量 |
| relativePath | string | 是   | 否   | 相对路径       |
| coverUri     | string | 是   | 否   | 封面文件Uri    |

MediaType
---------

枚举，媒体类型。

| 名称  | 默认值 | 描述 |
| ----- | ------ | ---- |
| FILE  | 0      | 文件 |
| IMAGE | 1      | 图片 |
| VIDEO | 2      | 视频 |
| AUDIO | 3      | 音频 |

FileKey
-------

枚举，文件关键信息。

| 名称          | 默认值              | 描述                                                   |
| ------------- | ------------------- |  ------------------------------------------------------ |
| ID            | file_id             | 文件编号                                               |
| RELATIVE_PATH | relative_path       |  相对路径                                               |
| DISPLAY_NAME  | display_name        |  显示名字                                               |
| PARENT        | parent              |  父目录id                                               |
| MIME_TYPE     | mime_type           | 文件扩展属性                                           |
| MEDIA_TYPE    | media_type          |  媒体类型                                               |
| SIZE          | size                |  文件大小                                               |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间到1970年1月1日的秒数值）         |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间到1970年1月1日的秒数值）         |
| DATE_TAKEN    | date_taken          | 拍摄日期（文件拍照时间到1970年1月1日的秒数值）         |
| TITLE         | title               |  文件标题                                               |
| ARTIST        | artist              |  作者                                                   |
| AUDIOALBUM    | audio_album         | 专辑                                                   |
| DURATION      | duration            |  持续时间（单位：秒）                                   |
| WIDTH         | width               | 图片宽度（单位：像素）                                 |
| HEIGHT        | height              |  图片高度（单位：像素）                                 |
| ORIENTATION   | orientation         | 图片显示方向（顺时针旋转角度，如0，90，180  单位：度） |
| ALBUM_ID      | bucket_id           | 文件所归属的相册编号                                   |
| ALBUM_NAME    | bucket_display_name | 文件所归属相册名称                                     |

DirectoryType
-------------

枚举，目录类型。

| 名称          | 默认值 | 描述               |
| ------------- | ------ | ------------------ |
| DIR_CAMERA    | 0      | 表示Camera文件路径 |
| DIR_VIDEO     | 1      | 表示视频路径       |
| DIR_IMAGE     | 2      | 表示图片路径       |
| DIR_AUDIO     | 3      | 表示音频路径       |
| DIR_DOCUMENTS | 4      | 表示文档路径       |
| DIR_DOWNLOAD  | 5      | 表示下载路径       |

DeviceType 
-----------

枚举，设备类型。

| 名称         | 默认值 | 描述       |
| ------------ | ------ | ---------- |
| TYPE_UNKNOWN | 0      | 未识别设备 |
| TYPE_LAPTOP  | 1      | 笔记本电脑 |
| TYPE_PHONE   | 2      | 手机       |
| TYPE_TABLET  | 3      | 平板电脑   |
| TYPE_WATCH   | 4      | 智能手表   |
| TYPE_CAR     | 5      | 车载设备   |
| TYPE_TV      | 6      | 电视设备   |

## MediaFetchOptions  

检索条件。

| 名称          | 类型          | 可读 | 可写 |  必填 |说明             |
| ------------- | ------------- | ---- | ---- |  ---- |---------------- |
| selections    | string        | 是   | 是   |是   | 检索条件         |
| selectionArgs | Array<string> | 是   | 是   |是   | 检索条件的值     |
| order         | string        | 是   | 是   | 否   |检索结果排序方式 |
| uri           | string        | 是   | 是   | 否   |文件URI          |
| networkId     | string        | 是   | 是   | 否   |注册设备网络ID   |
| extendArgs    | string        | 是   | 是   | 否   |扩展的检索参数   |

## Size

图片尺寸。

| 名称   | 类型   | 可读 | 可写 | 说明             |
| ------ | ------ | ---- | ---- | ---------------- |
| width  | number | 是   | 是   | 宽（单位：像素） |
| height | number | 是   | 是   | 高（单位：像素） |

