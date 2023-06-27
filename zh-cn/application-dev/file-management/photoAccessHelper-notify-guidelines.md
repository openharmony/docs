# 媒体资源变更通知相关

photoAccessHelper提供监听媒体资源变更的接口，供开发者对指定媒体资源变更进行监听。

> **说明：**
>
> 在进行功能开发前，请开发者查阅[相册管理模块开发概述](photoAccessHelper-overview.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用相册管理模块开发概述中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

媒体资源变更通知相关接口的异步调用仅支持使用callback方式。以下只列出部分接口使用方式，其他使用方式可以查阅[API参考](../reference/apis/js-apis-photoAccessHelper.md)。
如无特别说明，文档中涉及的待获取的资源均视为已经预置且在数据库中存在相应数据。如出现按照示例代码执行出现获取资源为空的情况请确认文件是否已预置，数据库中是否存在该文件的数据。

## 监听指定URI

通过调用[registerChange](../reference/apis/js-apis-photoAccessHelper.md#registerchange)接口监听指定URI。当被监听对象发生变更时返回监听器回调函数的值。

### 打开对FileAsset的URI的监听

打开对FileAsset的URI的进行监听，当目的FileAsset发生变更时，返回监听器回调函数的值。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以打开对一张图片的URI的监听，通过将这张图片设置为收藏触发监听回调为例。

**开发步骤：**

1. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
2. 打开对指定媒体资源URI的监听。
3. 将指定媒体资源设置为收藏。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo(photoAccessHelper.ImageVideoKey.DISPLAY_NAME, 'test.jpg');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);

  let onCallback = (changeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback);

  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

### 打开对Album的URI的监听

打开对Album的URI的进行监听，当目的Album发生变更时，返回监听器回调函数的值。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以打开对一个用户相册的URI的监听，通过将重名名这个相册触发监听回调为例。

**开发步骤：**

1. [获取用户相册](photoAccessHelper-userAlbum-guidelines.md#获取用户相册)。
2. 打开对指定用户相册URI的监听。
3. 将指定用户相册重名名。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
let albumName = photoAccessHelper.AlbumKey.ALBUM_NAME;
predicates.equalTo(albumName, 'albumName');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  console.info('getAlbums successfullyfully, albumName: ' + album.albumUri);

  let onCallback = (changeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(album.albumUri, false, onCallback);

  album.albumName = 'newAlbumName' + Date.now();
  await album.commitModify();
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

## 模糊监听

通过设置forChildUris值为true来打开模糊监听，URI为相册URI时，forChildUris为true能监听到相册中文件的变化，如果是false只能监听相册本身变化。URI为fileAsset时，forChildUris为true、false没有区别，URI为DefaultChangeUri时，forChildUris必须为true，如果为false将找不到该URI，收不到任何消息。

### 打开对所有FileAsset的URI的监听

打开对所有FileAsset的URI的进行监听，当有FileAsset发生变更时，返回监听器回调函数的值。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以打开所有FileAsset的URI的监听，通过将一张图片进行设置和取消收藏触发监听回调为例。

**开发步骤：**

1. 打开对所有FileAsset的URI的监听。
2. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
3. 将指定媒体资源设置为收藏。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let onCallback = (changeData) => {
  console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
}
phAccessHelper.registerChange(photoAccessHelper.DefaultChangeUri.DEFAULT_PHOTO_URI, true, onCallback);

let predicates = new dataSharePredicates.DataSharePredicates();
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);
  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```

## 关闭对指定URI的监听

关闭指定URI的监听，通过调用[unRegisterChange](../reference/apis/js-apis-photoAccessHelper.md#unregisterchange)接口关闭对指定URI的监听。一个URI可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时解除该URI的所有监听。

**前提条件：**

- 获取相册管理模块photoAccessHelper实例。
- 申请相册管理模块权限'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以一张图片的URI的监听中某一个callback监听进行关闭，通过将这张图片设置为收藏实现关闭的callback监听不再触发监听回调为例。

**开发步骤：**

1. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
2. 关闭对指定媒体资源URI的监听。
3. 将指定媒体资源设置为收藏。

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo(photoAccessHelper.ImageVideoKey.DISPLAY_NAME, 'test.jpg');
let fetchOptions = {
  fetchColumns: [],
  predicates: predicates
};

try {
  let fetchResult = await phAccessHelper.getAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('getAssets fileAsset.uri : ' + fileAsset.uri);

  let onCallback1 = (changeData) => {
    console.info('onCallback1, changData: ' + JSON.stringify(changeData));
  }
  let onCallback2 = (changeData) => {
    console.info('onCallback2, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback1);
  phAccessHelper.registerChange(fileAsset.uri, false, onCallback2);
  phAccessHelper.unRegisterChange(fileAsset.uri, onCallback1);

  await fileAsset.favorite(true);
  fetchResult.close();
} catch (err) {
  console.error('onCallback failed with err: ' + err);
}
```
