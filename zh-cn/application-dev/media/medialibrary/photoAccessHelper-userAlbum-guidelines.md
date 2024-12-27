# 用户相册资源使用指导

photoAccessHelper提供用户相册相关的接口，供开发者创建、删除用户相册，往用户相册中添加和删除图片和视频资源等。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[开发准备](photoAccessHelper-preparation.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用开发准备中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分photoAccessHelper的接口调用都是异步的。以下异步调用的API示例均采用Promise函数，更多方式可以查阅[API参考](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md)。
如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

<!--Del-->
## 创建用户相册（仅向系统应用开放）

通过[MediaAlbumChangeRequest.createAlbumRequest](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#createalbumrequest11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)接口创建用户相册。

待创建的相册名参数规格为：

- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.WRITE_IMAGEVIDEO'。

下面以创建一个用户相册为例。

**开发步骤**

1. 设置相册名。
2. 调用MediaAlbumChangeRequest.createAlbumRequest接口创建相册变更请求。
3. 调用PhotoAccessHelper.applyChanges接口提交相册变更请求。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  try {
    let albumName = 'albumName';
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = photoAccessHelper.MediaAlbumChangeRequest.createAlbumRequest(context, albumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    let album: photoAccessHelper.Album = albumChangeRequest.getAlbum();
    console.info('create album successfully, album name: ' + album.albumName + ' uri: ' + album.albumUri);
  } catch (err) {
    console.error('create album failed with err: ' + err);
  }
}
```
<!--DelEnd-->

## 获取用户相册

通过[PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getalbums-2)接口获取用户相册。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

下面以获取一个相册名为'albumName'的用户相册为例。

**开发步骤**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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

重命名用户相册修改的是相册的Album.albumName属性。

调用[MediaAlbumChangeRequest.setAlbumName](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#setalbumname11)重命名用户相册后再通过[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)更新到数据库中完成修改。

在重命名用户相册之前，需要先获取相册对象，可以通过[FetchResult](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#fetchresult)中的接口获取对应位置的用户相册。

重命名的相册名参数规格为：

- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将一个相册名为'albumName'的用户相册重命名为例。

**开发步骤**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
4. 调用MediaAlbumChangeRequest.setAlbumName接口设置新的相册名。
5. 调用PhotoAccessHelper.applyChanges接口将修改的相册属性更新到数据中完成修改。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    let newAlbumName: string = 'newAlbumName';
    albumChangeRequest.setAlbumName(newAlbumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setAlbumName successfully, new albumName: ' + album.albumName);
    fetchResult.close();
  } catch (err) {
    console.error('setAlbumName failed with err: ' + err);
  }
}
```

## 添加图片和视频到用户相册中

先[获取用户相册](#获取用户相册)对象和需要添加到相册中的图片或视频的对象数组，然后调用[MediaAlbumChangeRequest.addAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#addassets11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)接口往用户相册中添加图片或视频。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将往相册名为'albumName'的用户相册中添加一张图片为例。

**开发步骤**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一个用户相册。
5. 调用[PhotoAccessHelper.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets)接口获取图片资源。
6. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject)接口获取第一张图片。
7. 调用MediaAlbumChangeRequest.addAssets接口往用户相册中添加图片。
8. 调用PhotoAccessHelper.applyChanges接口提交相册变更请求。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.addAssets([photoAsset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to add ' + photoAsset.displayName + ' to ' + album.albumName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('addAssets failed with err: ' + err);
  }
}
```

## 获取用户相册中的图片和视频

先[获取用户相册](#获取用户相册)对象，然后调用[Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3)接口获取用户相册中的图片资源。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以获取相册名为'albumName'的用户相册中的一张图片为例。

**开发步骤**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
5. 调用Album.getAssets接口获取用户相册中的图片资源。
6. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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

先[获取用户相册](#获取用户相册)对象，然后调用[Album.getAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getassets-3)接口获取用户相册中的资源。

选择其中要移除的资源，然后调用[MediaAlbumChangeRequest.removeAssets](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#removeassets11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#applychanges11)接口移除。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将往相册名为'albumName'的用户相册中移除一张图片为例。

**开发步骤**

1. 建立相册检索条件，用于获取用户相册。
2. 建立图片检索条件，用于获取图片。
3. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一个用户相册。
5. 调用Album.getAssets接口获取图片资源。
6. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#getfirstobject-1)接口获取第一张图片。
7. 调用MediaAlbumChangeRequest.removeAssets接口从用户相册中移除图片。
8. 调用PhotoAccessHelper.applyChanges接口提交相册变更请求。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.removeAssets([photoAsset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('succeed to remove ' + photoAsset.displayName + ' from ' + album.albumName);
    albumFetchResult.close();
    photoFetchResult.close();
  } catch (err) {
    console.error('removeAssets failed with err: ' + err);
  }
}
```

<!--Del-->
## 删除用户相册（仅向系统应用开放）

先[获取用户相册](#获取用户相册)对象，然后调用[MediaAlbumChangeRequest.deleteAlbums](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#deletealbums11)删除用户相册。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以删除一个相册名为'albumName'的用户相册为例。

**开发步骤**

1. 建立检索条件，用于获取用户相册。
2. 调用PhotoAccessHelper.getAlbums接口获取用户相册资源。
3. 调用FetchResult.getFirstObject接口获取第一个用户相册。
4. 调用MediaAlbumChangeRequest.deleteAlbums接口删除第一个用户相册。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
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
    await photoAccessHelper.MediaAlbumChangeRequest.deleteAlbums(context, [album]);
    fetchResult.close();
  } catch (err) {
    console.error('deleteAlbums failed with err: ' + err);
  }
}
```
<!--DelEnd-->
