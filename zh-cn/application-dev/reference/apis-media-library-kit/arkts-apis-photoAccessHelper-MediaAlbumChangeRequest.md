# Class (MediaAlbumChangeRequest)

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

MediaAlbumChangeRequest implements [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11)

相册变更请求。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

## 导入模块

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## constructor<sup>11+</sup>

constructor(album: Album)

构造函数用于初始化新创建的对象。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| album | [Album](arkts-apis-photoAccessHelper-Album.md) | 是   | 需要变更的相册。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.          |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('MediaAlbumChangeRequest constructorDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions);
  let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
  let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
}
```

## getAlbum<sup>11+</sup>

getAlbum(): Album

获取当前相册变更请求中的相册。

**注意**：对于创建相册的变更请求，在调用[applyChanges](arkts-apis-photoAccessHelper-PhotoAccessHelper.md#applychanges11)提交生效之前，该接口返回null。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| [Album](arkts-apis-photoAccessHelper-Album.md) | 返回当前相册变更请求中的相册。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14000011 |  System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getAlbumDemo');
  try {
    // 请确保图库内存在用户相册。
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    let changeRequestAlbum: photoAccessHelper.Album = albumChangeRequest.getAlbum();
    console.info('change request album uri: ' + changeRequestAlbum.albumUri);
  } catch (err) {
    console.error(`getAlbumDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## setAlbumName<sup>11+</sup>

setAlbumName(name: string): void

设置相册名称。

相册名参数规格：
- 相册名字符串长度为1~255。
- 不允许出现非法字符，包括：<br> . \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| name | string | 是   | 待设置的相册名称。|

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('setAlbumNameDemo');
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    let newAlbumName: string = 'newAlbumName' + new Date().getTime();
    albumChangeRequest.setAlbumName(newAlbumName);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('setAlbumName successfully');
  } catch (err) {
    console.error(`setAlbumNameDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## addAssets<sup>11+</sup>

addAssets(assets: Array&lt;PhotoAsset&gt;): void

向相册中添加资产。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt; | 是   | 待添加到相册中的资产数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016 |  Operation Not Support.     |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('addAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    // 请确保图库内存在用户相册和照片。
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.addAssets([asset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('addAssets successfully');
  } catch (err) {
    console.error(`addAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```

## removeAssets<sup>11+</sup>

removeAssets(assets: Array&lt;PhotoAsset&gt;): void

从相册中移除资产。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| assets | Array&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt; | 是   | 待从相册中移除的资产数组。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | System inner fail.         |
| 14000016 |  Operation Not Support.     |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('removeAssetsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let albumFetchResult: photoAccessHelper.FetchResult<photoAccessHelper.Album> = await phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC);
    let album: photoAccessHelper.Album = await albumFetchResult.getFirstObject();
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await album.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();

    let albumChangeRequest: photoAccessHelper.MediaAlbumChangeRequest = new photoAccessHelper.MediaAlbumChangeRequest(album);
    albumChangeRequest.removeAssets([asset]);
    await phAccessHelper.applyChanges(albumChangeRequest);
    console.info('removeAssets successfully');
  } catch (err) {
    console.error(`removeAssetsDemo failed with error: ${err.code}, ${err.message}`);
  }
}
```
