# 用户相册资源使用指导

photoAccessHelper提供用户相册相关的接口，供开发者创建、删除用户相册，往用户相册中添加和删除图片和视频资源等。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[相册管理模块开发概述](photoAccessHelper-overview.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用相册管理模块开发概述中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分PhotoAccessHelper接口调用都是异步的，对于异步调用的API均提供了callback和Promise两种方式，以下示例均采用Promise函数，更多方式可以查阅[API参考](../reference/apis/js-apis-photoAccessHelper.md)。
如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

## 创建用户相册

通过[PhotoAccessHelper.createAlbum](../reference/apis/js-apis-photoAccessHelper.md#createalbum-1)接口创建用户相册。

待创建的相册名参数规格为：

- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'。

下面以创建一个用户相册为例。

**开发步骤：**

1. 设置相册名。
2. 调用createAlbum接口创建相册。

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let albumName = 'albumName';
    let album: photoAccessHelper.Album = await phAccessHelper.createAlbum(albumName);
    console.info('createAlbum successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  } catch (err) {
    console.error('createAlbum failed with err: ' + err);
  }
}
```

## 获取用户相册

通过[PhotoAccessHelper.getAlbums](../reference/apis/js-apis-photoAccessHelper.md#getalbums-2)接口获取用户相册。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'。

下面以获取一个相册名为'albumName'的用户相册为例。

**开发步骤：**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  predicates.equalTo(albumName, 'albumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    fetchResult.close();
  } catch (err) {
    console.error('getAlbums failed with err: ' + err);
  }
}
```

## 重命名用户相册

重命名用户相册修改的是相册的Albums.albumName属性。

修改后再通过[Album.commitModify](../reference/apis/js-apis-photoAccessHelper.md#commitmodify-3)更新到数据库中完成修改。

在重命名用户相册之前，需要先获取相册对象，可以通过[FetchResult](../reference/apis/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的用户相册。

重名名用户相册的相册名同样遵循[创建用户相册](#创建用户相册)的参数规格。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将一个相册名为'albumName'的用户相册重命名为例。

**开发步骤：**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
4. 设置新的相册名。
5. 调用Album.commitModify接口将修改的相册属性更新到数据中完成修改。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  predicates.equalTo(albumName, 'albumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    album.albumName = 'newAlbumName';
    await album.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('commitModify failed with err: ' + err);
  }
}
```

## 添加图片和视频到用户相册中

先[获取用户相册](#获取用户相册)对象和需要添加到相册中的图片或视频的对象数组，然后调用[Album.addAssets](../reference/apis/js-apis-photoAccessHelper.md#addassets-1)接口往用户相册中添加图片或视频。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将往相册名为'albumName'的用户相册中添加一张图片为例。

**开发步骤：**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一个用户相册。
5. 调用[PhotoAccessHelper.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets)接口获取图片资源。
6. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一张图片。
7. 调用Album.addAssets接口往用户相册中添加图片。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(photoFetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('getAssets successfully, albumName: ' + photoAsset.displayName);
    await album.addAssets([photoAsset]);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('addAssets failed with err: ' + err);
  }
}
```

## 获取用户相册中的图片和视频

先[获取用户相册](#获取用户相册)对象，然后调用[Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-3)接口获取用户相册中的图片资源。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以获取相册名为'albumName'的用户相册中的一张图片为例。

**开发步骤：**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
5. 调用Album.getAssets接口获取用户相册中的图片资源。
6. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult = await album.getAssets(photoFetchOptions);
    let photoAsset = await photoFetchResult.getFirstObject();
    console.info('album getAssets successfully, albumName: ' + photoAsset.displayName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('album getAssets failed with err: ' + err);
  }
}
```

## 从用户相册中移除图片和视频

先[获取用户相册](#获取用户相册)对象，然后调用[Album.getAssets](../reference/apis/js-apis-photoAccessHelper.md#getassets-3)接口获取用户相册中的资源。

选择其中要移除的图片调用[Album.removeAssets](../reference/apis/js-apis-photoAccessHelper.md#removeassets-1)接口移除。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将往相册名为'albumName'的用户相册中移除一张图片为例。

**开发步骤：**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
5. 调用Album.getAssets接口获取图片资源。
6. 调用[FetchResult.getFirstObject](../reference/apis/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片。
7. 调用Album.removeAssets接口从用户相册中移除图片。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let albumPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  albumPredicates.equalTo(albumName, 'albumName');
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: albumPredicates
  };

  let photoPredicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let photoFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: photoPredicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    let photoFetchResult = await album.getAssets(photoFetchOptions);
    let photoAsset = await photoFetchResult.getFirstObject();
    console.info('album getAssets successfully, albumName: ' + photoAsset.displayName);
    await album.removeAssets([photoAsset]);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('removeAssets failed with err: ' + err);
  }
}
```

## 删除用户相册

先[获取用户相册](#获取用户相册)对象，然后调用[PhotoAccessHelper.deleteAlbums](../reference/apis/js-apis-photoAccessHelper.md#deletealbums-1)删除用户相册。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以删除一个相册名为'albumName'的用户相册为例。

**开发步骤：**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用FetchResult.getFirstObject接口获取第一个用户相册。
4. 调用PhotoAccessHelper.deleteAlbums接口删除第一个用户相册。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import photoAccessHelper from '@ohos.file.photoAccessHelper';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumName: photoAccessHelper.AlbumKeys = photoAccessHelper.AlbumKeys.ALBUM_NAME;
  predicates.equalTo(albumName, '%albumName%');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbums successfully, albumName: ' + album.albumName);
    phAccessHelper.deleteAlbums([album]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAlbums failed with err: ' + err);
  }
}
```
