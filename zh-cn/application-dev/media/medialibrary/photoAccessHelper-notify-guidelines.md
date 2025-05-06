# 媒体资源变更通知相关指导

photoAccessHelper提供监听指定媒体资源变更的接口。

> **说明：**
>
> 在进行功能开发前，请查阅[开发准备](photoAccessHelper-preparation.md)，了解如何获取相册管理模块实例和如何申请相册管理模块功能开发相关权限。
> 文档中使用到photoAccessHelper的地方默认为使用[开发准备](photoAccessHelper-preparation.md)中获取的对象，如未添加此段代码报photoAccessHelper未定义的错误请自行添加。

媒体资源变更通知相关接口的异步调用仅支持使用callback方式。以下只列出部分接口使用方式，其他使用方式可以查阅[API参考](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md)。
如无特别说明，文档中涉及的待获取资源均视为已预置且数据库中存在相应数据。若按示例代码执行后资源为空，请确认文件是否已预置，以及数据库中是否存在该文件的数据。

## 监听指定URI

通过调用[registerChange](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#registerchange)接口监听指定uri。当被监听对象发生变更时返回监听器回调函数的值。

### 对指定PhotoAsset注册监听

注册对指定PhotoAsset的监听，当监听的PhotoAsset发生变更时，返回回调。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

以对一张图片注册监听为例，通过删除图片触发回调。

**开发步骤**

1. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
2. 对指定PhotoAsset注册监听。
3. 将指定媒体资源删除。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

### 对指定Album注册监听

注册Album监听，当Album发生变更时，触发监听回调。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

以对一个用户相册注册监听为例，通过重命名相册触发回调。

**开发步骤**

1. [获取用户相册](photoAccessHelper-userAlbum-guidelines.md#获取用户相册)。
2. 对指定Album注册监听。
3. 将指定用户相册重命名。


```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
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
    console.info('getAlbums successfully, albumUri: ' + album.albumUri);

    let onCallback = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(album.albumUri, false, onCallback);
    album.albumName = 'newAlbumName' + Date.now();
    await album.commitModify();
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

## 模糊监听

1. 通过设置forChildUris值为true来注册模糊监听，uri为相册uri时，forChildUris为true能监听到相册中文件的变化，如果是false只能监听相册本身变化。
2. uri为photoAsset时，forChildUris为true、false没有区别。
3. uri为DefaultChangeUri时，forChildUris必须为true，如果为false将找不到该uri，收不到任何消息。

### 对所有PhotoAsset注册监听

对所有PhotoAsset注册监听，当被监听的PhotoAsset发生变更时，返回监听回调。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以对所有PhotoAsset注册监听，通过将被监听的PhotoAsset删除触发监听回调为例。

**开发步骤**

1. 对所有PhotoAsset注册监听。
2. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
3. 将指定媒体资源删除。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let onCallback = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback successfully, changData: ' + JSON.stringify(changeData));
  }
  phAccessHelper.registerChange(photoAccessHelper.DefaultChangeUri.DEFAULT_PHOTO_URI, true, onCallback);
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```

## 取消对指定URI的监听

取消对指定uri的监听，通过调用[unRegisterChange](../../reference/apis-media-library-kit/js-apis-photoAccessHelper.md#unregisterchange)接口取消对指定uri的监听。一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时取消该uri的所有监听。

**前提条件**

- 获取相册管理模块photoAccessHelper实例。
- [申请相册管理模块权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)'ohos.permission.READ_IMAGEVIDEO'和'ohos.permission.WRITE_IMAGEVIDEO'。

下面以取消对图片指定的监听为例，取消监听后，删除图片不再触发对应的监听回调。

**开发步骤**

1. [获取指定媒体资源](photoAccessHelper-resource-guidelines.md#获取指定媒体资源)。
2. 取消对指定媒体资源uri的监听。
3. 将指定媒体资源删除。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);

async function example() {
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo(photoAccessHelper.PhotoKeys.DISPLAY_NAME, 'test.jpg');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    console.info('getAssets photoAsset.uri : ' + photoAsset.uri);
    let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1, changData: ' + JSON.stringify(changeData));
    }
    let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2, changData: ' + JSON.stringify(changeData));
    }
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
    phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);
    phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);
    await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
    fetchResult.close();
  } catch (err) {
    console.error('onCallback failed with err: ' + err);
  }
}
```
