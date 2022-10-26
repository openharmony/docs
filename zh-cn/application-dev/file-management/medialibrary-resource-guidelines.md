# 媒体资源使用指导

应用可以通过mediaLibrary的接口，进行媒体资源（音频、视频、图片文件等）相关操作。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[媒体库开发概述](medialibrary-overview.md)，了解如何获取媒体库实例和如何申请媒体库功能开发相关权限。

为了保证应用的运行效率，大部分MediaLibrary调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-medialibrary.md)。

## 获取媒体资源

开发者可以根据特定的条件查询媒体资源，如指定类型、指定日期、指定相册等。

应用通过调用[MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1)获取媒体资源，并传入MediaFetchOptions对象指定检索条件。MediaFetchOptions.selections为检索条件，使用FileKey中的枚举值作为检索条件的列名；MediaFetchOptions.selectionArgs对应selections中检索条件列的值；除此之外，可以使用order（结果排序方式）、uri（文件URI）、networkId（注册设备网络ID）作为检索条件。

如果只想获取某个位置的对象（如第一个、最后一个、指定索引等），可以通过[FetchFileResult](../reference/apis/js-apis-medialibrary.md#fetchfileresult7)中的接口获取对应位置的媒体资源对象。本小节均采用getNextObject循环获取检索结果中的所有媒体资源。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读权限“ohos.permission.READ_MEDIA”。

### 指定媒体类型

下面以查询图片类型的媒体资源为例。

**开发步骤**

selections： FileKey.MEDIA_TYPE，根据媒体类型检索。

selectionArgs： MediaType.IMAGE，媒体类型为图片。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### 指定日期

下面以查询指定添加日期的媒体资源为例。实际开发中可以设置添加日期、修改日期、拍摄日期。

selections： FileKey.DATE_ADDED，根据文件添加日期检索。

selectionArgs：2022-8-5，具体添加时间的字符串。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let option = {
        selections: fileKeyObj.DATE_ADDED + '= ?',
        selectionArgs: ['2022-8-5'],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### 按指定顺序排列

下面以查询图片并按文件添加日期降序排列为例。实际开发中可以设置升序（AESC）和降序（DESC）。

order： FileKey.DATE_ADDED，根据文件添加日期排序；并设置排列顺序为DESC降序。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
        order: fileKeyObj.DATE_ADDED + " DESC",
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

### 指定相册

下面以指定相册myAlbum为例。

selections： FileKey.ALBUM_NAME，根据相册名称检索。

selectionArgs：'myAlbum'，具体相册名称。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.IMAGE
    let option = {
        selections: fileKeyObj.ALBUM_NAME + '= ?',
        selectionArgs: ['myAlbum'],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    for (let i = 0; i < fetchFileResult.getCount(); i++) {
        fetchFileResult.getNextObject((err, fileAsset) => {
        if (err) {
            console.error('Failed ');
            return;
        }
        console.log('fileAsset.displayName ' + i + ': ' + fileAsset.displayName);
        })
    } 
}
```

## 获取相册中的图片或视频

获取相册的媒体资源有两种方式，一是通过[MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1)指定相册以获取媒体资源，参考[获取指定相册的媒体资源](#指定相册)；二是通过[Album.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-3)使用相册Album实例获取媒体资源。

**前提条件**

- 获取媒体库mediaLibrary实例。
- 申请媒体库读权限“ohos.permission.READ_MEDIA”。

**开发步骤**

下面以获取相册名称为“新建相册1”的视频为例。

1. 建立检索条件，用于获取目的相册实例。

   ```ts
   let fileKeyObj = mediaLibrary.FileKey;
   let AlbumNoArgsFetchOp = {
       selections: fileKeyObj.ALBUM_NAME + '= ?',
       selectionArgs: ['新建相册1']
   }
   ```

2. 建立检索条件，用于获取目的相册下的视频资源。

   ```ts
   let fileKeyObj = mediaLibrary.FileKey;
   let imageType = mediaLibrary.MediaType.VIDEO;
   let imagesFetchOp  = {
       selections: fileKeyObj.MEDIA_TYPE + '= ?',
       selectionArgs: [imageType.toString()],
   }
   ```

3. 通过Album.getFileAssets获取对应的资源。

以下为**完整示例**。

```ts
async function getCameraImagePromise() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let imagesFetchOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
    }
    let AlbumNoArgsFetchOp = {
        selections: fileKeyObj.ALBUM_NAME + '= ?',
        selectionArgs: ['新建相册1']
    }

    let albumList = await media.getAlbums(AlbumNoArgsFetchOp);
    if (albumList.length > 0) {
        const album = albumList[0];
        let fetchFileResult = await album.getFileAssets(imagesFetchOp);
        let count = fetchFileResult.getCount();
        console.info("get mediaLibrary IMAGE number", count);
    } else {
        console.info('getAlbum list is: 0');
    }
}
```

## 获取图片/视频缩略图

通过接口[FileAsset.getThumbnail](../reference/apis/js-apis-medialibrary.md#getthumbnail8-2)，传入缩略图尺寸，可以获取图片/视频缩略图。缩略图常用于UI界面展示。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读权限“ohos.permission.READ_MEDIA”。

### 获取某张图片的缩略图

当需要在相册展示图片/视频、编辑预览，应用需要获取某张图片的缩略图。

下面以获取相册第一张图片的缩略图为例，缩略图尺寸为720*720。

**开发步骤**

1. 建立检索条件，用于获取目的相册下的图片资源。
2. 调用getFileAssets获取目标图片资源。
3. 调用getFirstObject获取第一张图片。
4. 调用getThumbnail获取相册中图片的缩略图。

```ts
async function getFirstThumbnailPromise() {
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let fileKeyObj = mediaLibrary.FileKey;
    let imageType = mediaLibrary.MediaType.IMAGE;
    let imagesFetchOp = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [imageType.toString()],
    }

    let size = { width: 720, height: 720 };
    const fetchFileResult = await media.getFileAssets(imagesFetchOp);
    if (fetchFileResult != undefined) {
        const asset = await fetchFileResult.getFirstObject();
        asset.getThumbnail(size).then((pixelMap) => {
          pixelMap.getImageInfo().then((info) => {
              console.info('get Thumbnail info: ' + "width: " + info.size.width + " height: " + info.size.height);
          }).catch((err) => {
              console.info("getImageInfo failed with error:" + err);
          });
        }).catch((err) => {
            console.info("getImageInfo failed with error:" + err);
        });
    } else {
        console.info("get image failed with error");
    }
}
```

## 创建媒体资源

通过接口[MediaLibrary.createAsset](../reference/apis/js-apis-medialibrary.md#createasset8-1)可以创建媒体资源。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。
- [获取公共目录路径](medialibrary-filepath-guidelines.md)。

下面以创建文件类型（MediaType.FILE）的文件为例。

```ts
async function example() {
    let mediaType = mediaLibrary.MediaType.FILE;
    let DIR_DOCUMENTS = mediaLibrary.DirectoryType.DIR_DOCUMENTS;
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const path = await media.getPublicDirectory(DIR_DOCUMENTS);
    media.createAsset(mediaType, "testFile.text", path).then ((asset) => {
        console.info("createAsset successfully:"+ JSON.stringify(asset));
    }).catch((err) => {
        console.info("createAsset failed with error:"+ err);
    });
}
```

## 将文件放入回收站

通过[FileAsset.trash](../reference/apis/js-apis-medialibrary.md#trash8)可以将文件放入回收站。

放入回收站的文件将会保存30天，在此期间，开发者可以将trash的入参isTrash设置为false将其恢复为正常文件；应用用户也可以通过系统应用“文件管理”或“图库”恢复文件。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。

下面以将文件检索结果中第一个文件放入回收站为例。

**开发步骤**

1. 建立检索条件，用于获取目的相册下的图片资源。
2. 调用getFileAssets获取目标图片资源。
3. 调用getFirstObject获取第一张图片，即要放入回收站的图片对象。
4. 调用trash将文件放入回收站。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.FILE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    let asset = await fetchFileResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist')
      return
    }
    //回调为空
    asset.trash(true).then(() => {
        console.info("trash successfully");
    }).catch((err) => {
        console.info("trash failed with error:"+ err);
    });
}
```

## 重命名媒体资源

重命名修改的是文件的FileAsset.displayName属性，即文件的显示文件名，包含文件后缀。

修改后再通过[FileAsset.commitModify](../reference/apis/js-apis-medialibrary.md#commitmodify8-1)更新到数据库中。

在重命名文件之前，需要先获取文件对象，可以通过[FetchFileResult](../reference/apis/js-apis-medialibrary.md#fetchfileresult7)中的接口获取对应位置的文件。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。

下面以将文件检索结果中第一个文件重命名为“newtitle.text”为例。

**开发步骤**

1. 建立检索条件，用于获取目的相册下的图片资源。
2. 调用getFileAssets获取目标图片资源。
3. 调用getFirstObject获取第一张图片，即要重命名的图片对象。
4. 将图片重命名为“newImage.jpg“。
5. 调用FileAsset.commitModify将更新的图片属性修改到数据库中。

```ts
async function example() {
    let fileKeyObj = mediaLibrary.FileKey
    let fileType = mediaLibrary.MediaType.FILE
    let option = {
        selections: fileKeyObj.MEDIA_TYPE + '= ?',
        selectionArgs: [fileType.toString()],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const fetchFileResult = await media.getFileAssets(option);
    let asset = await fetchFileResult.getFirstObject();
    if (asset == undefined) {
      console.error('asset not exist')
      return
    }
    asset.displayName = 'newImage.jpg';
    //回调为空
    asset.commitModify((err) => {
       if (err) {
           console.error('fileRename Failed ');
           return;
       }
       console.log('fileRename successful.');
    })
}
```
