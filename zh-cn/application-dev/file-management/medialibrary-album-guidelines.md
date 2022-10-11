# 相册资源使用指导

mediaLibrary提供相册相关的接口，供开发者创建、删除相册，获取相册中的图片资源等。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[媒体库开发概述](medialibrary-overview.md)，了解如何获取媒体库实例和如何申请媒体库功能开发相关权限。

为了保证应用的运行效率，大部分MediaLibrary调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-medialibrary.md)。

## 获取相册中的图片/视频

获取相册中的图片、视频有两种方式：

一是通过[MediaLibrary.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-1)指定相册以获取媒体资源，参考[获取指定相册的媒体资源](medialibrary-resource-guidelines#指定相册)；

二是通过[Album.getFileAssets](../reference/apis/js-apis-medialibrary.md#getfileassets7-3)使用相册Album实例获取媒体资源，参考[获取相册中的图片或视频](medialibrary-resource-guidelines#获取相册中的图片或视频)。

## 创建相册

通过[MediaLibrary.createAsset](../reference/apis/js-apis-medialibrary.md#createasset8-1)可以创建媒体资源，可以通过创建图片或视频文件时设置的相对路径，创建出相册，相对路径的命名即为相册名称。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。

下面以创建相册myAlbum为例。

**开发步骤**

1. 调用getPublicDirectory获取文件公共路径。

   获取文件公共路径的更多指导可参考[获取文件保存的公共目录](medialibrary-filepath-guidelines.md#获取文件保存的公共目录)。

2. 调用createAsset新建图片，并设置相对路径为path+'myAlbum/'。

   即在创建相册的同时，往里面放了一张图片。

```ts
async function example() {
    let mediaType = mediaLibrary.MediaType.IMAGE;
    let DIR_IMAGE = mediaLibrary.DirectoryType.DIR_IMAGE;
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    const path = await media.getPublicDirectory(DIR_IMAGE)
    //myAlbum为新建文件保存路径，也是新建相册的名称
    media.createAsset(mediaType, 'test.jpg', path + 'myAlbum/', (err, fileAsset) => {
        if (fileAsset != undefined) {
        console.info('createAlbum successfully, message = ' + fileAsset);
        } else {
        console.info('createAlbum failed, message = ' + err);
        }
    });
}
```

## 删除相册

当删除相册的所有媒体资源时，相册自动删除，通过[FileAsset.deleteAsset](../reference/apis/js-apis-medialibrary.md#deleteasset8-1)可以删除媒体资源。

> **说明：**<br/>
>
> deleteAsset为系统接口，仅限系统应用使用。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。

**开发步骤**

1. 建立检索条件，用于获取目标相册。
2. 调用getAlbums获取相册列表。
3. 建立检索条件，用于获取相册下的目标图片资源。
4. 调用getFileAssets获取目标图片资源。
5. 调用getAllObject获取相册下的全部图片。
6. 调用deleteAsset删除全部图片。

```ts
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    let album = albumList[0];
    if (album != undefined) {
        let fetchOpt = {
            selections: mediaLibrary.FileKey.MEDIA_TYPE + '= ?',
            selectionArgs: [mediaLibrary.MediaType.IMAGE.toString()],
        };
        let fetchFileResult = await album.getFileAssets(fetchOpt);
        fetchFileResult.getAllObject().then(function(fileAssetList){
            for (let i = 0; i < fileAssetList.length; ++i) {
                media.deleteAsset(fileAssetList[i].uri).then(function() {
                    console.info("removeAlbum successfully");
                }).catch(function(err){
                    console.info("removeAlbum failed with error:"+ err);
                });
            }
        })
    }
}
```

## 重命名相册

重命名修改的是相册的FileAsset.albumName属性，即相册名称。修改后再通过[Album.commitModify](../reference/apis/js-apis-medialibrary.md#commitmodify8-3)更新到数据库中。

**前提条件** 

- 获取媒体库mediaLibrary实例。
- 申请媒体库读写权限“ohos.permission.WRITE_MEDIA”。

下面以重命名相册为“newAlbum“为例。

**开发步骤**

1. 建立检索条件，用于获取目标相册。
2. 调用getAlbums获取相册列表。
3. 将相册重命名为“newAlbum“。
4. 调用Album.commitModify将更新的相册属性修改到数据库中。

```ts
async function example() {
    let AlbumNoArgsfetchOp = {
        selections: '',
        selectionArgs: [],
    };
    const context = getContext(this);
    var media = mediaLibrary.getMediaLibrary(context);
    let albumList = await media.getAlbums(AlbumNoArgsfetchOp);
    let album = albumList[0];
    album.albumName = 'newAlbum';
    //回调返回空
    album.commitModify().then(function() {
        console.info("albumRename successfully");
    }).catch(function(err){
        console.info("albumRename failed with error:"+ err);
    });
}
```

