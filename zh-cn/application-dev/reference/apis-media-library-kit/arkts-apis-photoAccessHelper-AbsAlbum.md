# Interface (AbsAlbum)
<!--Kit: Media Library Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @yixiaoff-->
<!--SE: @liweilu1-->
<!--TSE: @xchaosioda-->

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## 属性

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

| 名称           | 类型    | 可读   | 可写  | 说明   |
| ------------ | ------ | ---- | ---- | ------- |
| albumType | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype) | 是    | 否    | 相册类型。    |
| albumSubtype | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype) | 是    | 否   | 相册子类型。    |
| albumName | string | 是    | 预置相册不可写，用户相册可写   | 相册名称。    |
| albumUri | string | 是    | 否    | 相册uri。   |
| count | number | 是    | 否    |  相册中文件数量。 |
| coverUri | string | 是    | 否    | 封面文件uri。 |

## getAssets

getAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;PhotoAsset&gt;&gt;): void

获取相册中的文件。该方法使用callback形式来返回。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | 是   | 检索选项。 |
| callback | AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | 是   | callback返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

在API 13及之前的版本，无相关权限返回错误码13900012；从API 14开始，无相关权限返回错误码201。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('albumGetAssetsDemoCallback');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.getAssets(fetchOption, (err, albumFetchResult) => {
    if (albumFetchResult !== undefined) {
      console.info('album getAssets successfully, getCount: ' + albumFetchResult.getCount());
    } else {
      console.error(`album getAssets failed with error: ${err.code}, ${err.message}`);
    }
  });
}
```

## getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

获取相册中的文件。该方法使用Promise来返回。

**原子化服务API：** 从API version 20开始，该接口支持在原子化服务中使用。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions) | 是   | 检索选项。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | Promise对象，返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

在API 13及之前的版本，无相关权限返回错误码13900012；从API 14开始，无相关权限返回错误码201。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 201     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('albumGetAssetsDemoPromise');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchOption: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, albumFetchOptions);
  let album: photoAccessHelper.Album = await albumList.getFirstObject();
  album.getAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err: BusinessError) => {
    console.error(`album getAssets failed with error: ${err.code}, ${err.message}`);
  });
}
```
