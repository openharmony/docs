# 系统相册资源使用指导
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--Designer: @liweilu1-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

photoAccessHelper提供对收藏夹、视频相册、截屏和录屏相册的相关操作。

> **说明：**
>
> 在进行功能开发前，请查阅[开发准备](photoAccessHelper-preparation.md)，了解如何获取相册管理模块实例及申请相关权限。
> 文档中使用到PhotoAccessHelper的地方，默认使用[开发准备](photoAccessHelper-preparation.md)中获取的对象，如未添加此段代码提示PhotoAccessHelper未定义的错误请自行添加。

为了保证应用的运行效率，大部分photoAccessHelper的接口调用都是异步的。以下异步调用的API示例均采用Promise函数，更多方式可以查阅[API参考](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper.md)。
如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况，请确认文件是否已预置，数据库中是否存在该文件的数据。

## 收藏夹

收藏夹属于系统相册，对图片或视频设置收藏时会自动将其加入到收藏夹中，取消收藏则会从收藏夹中移除。

### 获取收藏夹对象

通过[PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getalbums-2)接口获取收藏夹对象。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

**开发步骤**

1. 设置获取收藏夹的参数为photoAccessHelper.AlbumType.SYSTEM和photoAccessHelper.AlbumSubtype.FAVORITE。
2. 调用PhotoAccessHelper.getAlbums接口获取收藏夹对象。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get favorite album failed with err: ' + err);
  }
}
```

<!--Del-->
### 收藏图片和视频（仅向系统应用开放）

通过[MediaAssetChangeRequest.setFavorite](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#setfavorite11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11)接口将图片或视频设置为收藏。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面将以收藏一张图片为例。

**开发步骤**

1. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
2. 调用MediaAssetChangeRequest.setFavorite接口将图片设置为收藏。
3. 调用PhotoAccessHelper.applyChanges接口提交收藏图片的变更请求。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    let favoriteState = true;
    assetChangeRequest.setFavorite(favoriteState);
    await phAccessHelper.applyChanges(assetChangeRequest);
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```
<!--DelEnd-->

### 获取收藏夹中的图片和视频

先[获取收藏夹对象](#获取收藏夹对象)。然后调用[Album.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-AbsAlbum.md#getassets-1)接口获取收藏夹中的资源。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

下面以获取收藏夹中的一张图片为例。

**开发步骤**

1. [获取收藏夹对象](#获取收藏夹对象)。
2. 建立图片检索条件，用于获取图片。
3. 调用Album.getAssets接口获取图片资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1)接口获取第一张图片。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('favorite failed with err: ' + err);
  }
}
```

<!--Del-->
### 取消收藏图片或视频（仅向系统应用开放）

通过[MediaAssetChangeRequest.setFavorite](../../reference/apis-media-library-kit/js-apis-photoAccessHelper-sys.md#setfavorite11)和[PhotoAccessHelper.applyChanges](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11)接口将图片或视频取消收藏。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以将一张图片取消收藏为例。

**开发步骤**

1. [获取收藏夹中的图片和视频](#获取收藏夹中的图片和视频)。
2. 调用MediaAssetChangeRequest.setFavorite接口将图片设置为取消收藏。
3. 调用PhotoAccessHelper.applyChanges接口提交取消收藏图片的变更请求。


```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.FAVORITE);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get favorite album successfully, albumUri: ' + album.albumUri);

    let photoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await photoFetchResult.getFirstObject();
    console.info('favorite album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);

    let assetChangeRequest: photoAccessHelper.MediaAssetChangeRequest = new photoAccessHelper.MediaAssetChangeRequest(photoAsset);
    let favoriteState = false;
    assetChangeRequest.setFavorite(favoriteState);
    await phAccessHelper.applyChanges(assetChangeRequest);
    photoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('setFavorite failed with err: ' + err);
  }
}
```
<!--DelEnd-->

## 视频相册

视频相册属于系统相册，用户文件中属于视频类型的媒体文件会自动加入到视频相册中。

### 获取视频相册对象

通过[PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getalbums-2)接口获取视频相册对象。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

**开发步骤**

1. 设置获取视频相册的参数为photoAccessHelper.AlbumType.SYSTEM和photoAccessHelper.AlbumSubtype.VIDEO。
2. 调用PhotoAccessHelper.getAlbums接口获取视频相册。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get video album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get video album failed with err: ' + err);
  }
}
```

### 获取视频相册中的视频

先[获取视频相册对象](#获取视频相册对象)。然后调用[Album.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-AbsAlbum.md#getassets-1)接口获取视频相册对象中的视频资源。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

下面以获取视频相册中的一个视频为例。

**开发步骤**

1. 先[获取视频相册对象](#获取视频相册对象)。
2. 建立视频检索条件，用于获取视频。
3. 调用Album.getAssets接口获取视频资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1)接口获取第一个视频。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get video album successfully, albumUri: ' + album.albumUri);

    let videoFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await videoFetchResult.getFirstObject();
    console.info('video album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    videoFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('video failed with err: ' + err);
  }
}
```

<!--Del-->
## 截屏和录屏相册（仅向系统应用开放）

截屏和录屏相册属于系统相册，用户文件中属于截屏和录屏的媒体文件会自动加入到截屏和录屏相册中。

### 获取截屏和录屏相册对象

通过[PhotoAccessHelper.getAlbums](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-PhotoAccessHelper.md#getalbums-2)接口获取截屏和录屏相册对象。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

**开发步骤**

1. 设置获取截屏和录屏相册的参数为photoAccessHelper.AlbumType.SYSTEM和photoAccessHelper.AlbumSubtype.SCREENSHOT。
2. 调用PhotoAccessHelper.getAlbums接口获取截屏和录屏相册。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('get screenshot album successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  } catch (err) {
    console.error('get screenshot album failed with err: ' + err);
  }
}
```

### 获取截屏和录屏相册中的媒体资源

先[获取截屏和录屏相册对象](#获取截屏和录屏相册对象)。然后调用[Album.getAssets](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-AbsAlbum.md#getassets-1)接口获取截屏和录屏相册对象中的媒体资源。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'。

下面以获取截屏和录屏相册中的一个媒体资源为例。

**开发步骤**

1. 先[获取截屏和录屏相册对象](#获取截屏和录屏相册对象)。
2. 建立检索条件，用于获取媒体资源。
3. 调用Album.getAssets接口获取媒体资源。
4. 调用[FetchResult.getFirstObject](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-FetchResult.md#getfirstobject-1)接口获取第一个媒体资源。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.SCREENSHOT);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    console.info('get screenshot album successfully, albumUri: ' + album.albumUri);

    let screenshotFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await screenshotFetchResult.getFirstObject();
    console.info('screenshot album getAssets successfully, photoAsset displayName: ' + photoAsset.displayName);
    screenshotFetchResult.close();
    albumFetchResult.close();
  } catch (err) {
    console.error('screenshot album failed with err: ' + err);
  }
}
```
<!--DelEnd-->
