# Interface (PhotoAccessHelper)

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
```

## getAssets

getAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;PhotoAsset&gt;&gt;): void

获取图片和视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

 通过picker的方式调用该接口来查询指定uri对应的图片或视频资源，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)        | 是   | 图片和视频检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | 是   | callback返回图片和视频检索结果集。 |

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
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  phAccessHelper.getAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName : ' + photoAsset.displayName);
      }
    } else {
      console.error(`fetchResult fail with error: ${err.code}, ${err.message}`);
    }
  });
}
```

## getAssets

getAssets(options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

获取图片和视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

 通过picker的方式调用该接口来查询指定uri对应的图片或视频资源，不需要申请'ohos.permission.READ_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-photoviewpicker.md#指定uri获取图片或视频资源)。

**参数：**

| 参数名  | 类型                | 必填 | 说明             |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)   | 是   | 图片和视频检索选项。     |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
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

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error(`getAssets failed, error: ${err.code}, ${err.message}`);
  }
}
```

## getBurstAssets<sup>12+</sup>

getBurstAssets(burstKey: string, options: FetchOptions): Promise&lt;FetchResult&lt;PhotoAsset&gt;&gt;

获取连拍照片资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名  | 类型                | 必填 | 说明             |
| ------- | ------------------- | ---- | ---------------- |
| burstKey | string   | 是   | 一组连拍照片的唯一标识：uuid(可传入[PhotoKeys](arkts-apis-photoAccessHelper-e.md#photokeys)的BURST_KEY)。字符串长度为36。 |
| options | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)   | 是   | 连拍照片检索选项。     |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[PhotoAsset](arkts-apis-photoAccessHelper-PhotoAsset.md)&gt;&gt; | Promise对象，返回连拍照片数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201   | Permission denied.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011       | Internal system error.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('getBurstAssets');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  // burstKey为36位的uuid，可以根据photoAccessHelper.PhotoKeys获取。
  let burstKey: string = "e719d696-09fa-44f8-8e9e-ec3f215aa62a";
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await 
      phAccessHelper.getBurstAssets(burstKey, fetchOptions);
    if (fetchResult !== undefined) {
      console.info('fetchResult success');
      let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
      if (photoAsset !== undefined) {
        console.info('photoAsset.displayName :' + photoAsset.displayName);
      }
    }
  } catch (err) {
    console.error(`getBurstAssets failed, error: ${err.code}, ${err.message}`);
  }
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, options: CreateOptions, callback: AsyncCallback&lt;string&gt;): void

指定文件类型、后缀和创建选项，创建图片或视频资源。使用callback方式返回结果。

在未申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'时，可以使用安全控件创建媒体资源，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-savebutton.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | 是   | 创建的文件类型，IMAGE或者VIDEO类型。              |
| extension  | string        | 是   | 文件名后缀参数，例如：'jpg'。              |
| options  | [CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions)        | 是   | 创建选项，当前仅支持'title'，例如{title: 'testPhoto'}。              |
| callback |  AsyncCallback&lt;string&gt; | 是   | callback返回创建的图片和视频的uri。 |

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
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension:string = 'jpg';
  let options: photoAccessHelper.CreateOptions = {
    title: 'testPhoto'
  }
  phAccessHelper.createAsset(photoType, extension, options, (err, uri) => {
    if (uri !== undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, callback: AsyncCallback&lt;string&gt;): void

指定文件类型和后缀，创建图片或视频资源，使用callback方式返回结果。

在未申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'时，可以使用安全控件创建媒体资源，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-savebutton.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | 是   | 创建的文件类型，IMAGE或者VIDEO类型。              |
| extension  | string        | 是   | 文件名后缀参数，例如：'jpg'。              |
| callback |  AsyncCallback&lt;string&gt; | 是   | callback返回创建的图片和视频的uri。 |

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
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
  let extension: string = 'jpg';
  phAccessHelper.createAsset(photoType, extension, (err, uri) => {
    if (uri !== undefined) {
      console.info('createAsset uri' + uri);
      console.info('createAsset successfully');
    } else {
      console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
    }
  });
}
```

## createAsset

createAsset(photoType: PhotoType, extension: string, options?: CreateOptions): Promise&lt;string&gt;

指定文件类型、后缀和创建选项，创建图片或视频资源，以Promise方式返回结果。

在未申请相册管理模块权限'ohos.permission.WRITE_IMAGEVIDEO'时，可以使用安全控件创建媒体资源，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-savebutton.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| photoType  | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype)        | 是   | 创建的文件类型，IMAGE或者VIDEO类型。              |
| extension  | string        | 是   | 文件名后缀参数，例如：'jpg'。              |
| options  | [CreateOptions](arkts-apis-photoAccessHelper-i.md#createoptions)        | 否   | 创建选项，当前仅支持'title'，例如{title: 'testPhoto'}。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;string&gt; | Promise对象，返回创建的图片和视频的uri。 |

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
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createAssetDemo');
  try {
    let photoType: photoAccessHelper.PhotoType = photoAccessHelper.PhotoType.IMAGE;
    let extension: string = 'jpg';
    let options: photoAccessHelper.CreateOptions = {
      title: 'testPhoto'
    }
    let uri: string = await phAccessHelper.createAsset(photoType, extension, options);
    console.info('createAsset uri' + uri);
    console.info('createAsset successfully');
  } catch (err) {
    console.error(`createAsset failed, error: ${err.code}, ${err.message}`);
  }
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

根据检索选项和相册类型获取相册，使用callback方式返回结果。

获取相册前，确保相册已存在。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | 是   | 相册类型。              |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | 是   | 相册子类型。              |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | 是   |  检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | 是   | callback返回获取相册的结果集。 |

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
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions, async (err, fetchResult) => {
    if (err) {
      console.error(`getAlbumsCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    if (fetchResult === undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void

根据相册类型获取相册，使用callback方式返回结果。

获取相册前需先保证相册存在。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | 是   | 相册类型。              |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | 是   | 相册子类型。              |
| callback |  AsyncCallback&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | 是   | callback返回获取相册的结果集。 |

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
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  // 示例代码中为获取统相册VIDEO，默认已预置。
  console.info('getAlbumsDemo');
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.SYSTEM, photoAccessHelper.AlbumSubtype.VIDEO, async (err, fetchResult) => {
    if (err) {
      console.error(`getAlbumsCallback failed with err: ${err.code}, ${err.message}`);
      return;
    }
    if (fetchResult === undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

## getAlbums

getAlbums(type: AlbumType, subtype: AlbumSubtype, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;

根据检索选项和相册类型获取相册，使用Promise方式返回结果。

在获取相册之前，确保相册已存在。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](arkts-apis-photoAccessHelper-e.md#albumtype)         | 是   | 相册类型。              |
| subtype  | [AlbumSubtype](arkts-apis-photoAccessHelper-e.md#albumsubtype)         | 是   | 相册子类型。              |
| options  | [FetchOptions](arkts-apis-photoAccessHelper-i.md#fetchoptions)         | 否   |  检索选项，不填时默认根据相册类型检索。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](arkts-apis-photoAccessHelper-FetchResult.md)&lt;[Album](arkts-apis-photoAccessHelper-Album.md)&gt;&gt; | Promise对象，返回获取相册的结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

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
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  phAccessHelper.getAlbums(photoAccessHelper.AlbumType.USER, photoAccessHelper.AlbumSubtype.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult === undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album: photoAccessHelper.Album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err: BusinessError) => {
    console.error(`getAlbumsPromise failed with err: ${err.code}, ${err.message}`);
  });
}
```

## registerChange

registerChange(uri: string, forChildUris: boolean, callback: Callback&lt;ChangeData&gt;) : void

注册指定uri的监听，并通过callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名    | 类型                                        | 必填 | 说明                                                         |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | 是   | PhotoAsset的uri, Album的uri或[DefaultChangeUri](arkts-apis-photoAccessHelper-e.md#defaultchangeuri)的值。 |
| forChildUris | boolean                                     | 是   | 是否模糊监听。uri为相册uri时：forChildUris为true，能监听到相册中文件的变化。如果是false，只能监听相册本身变化；uri为photoAsset时：forChildUris为true、false没有区别；uri为DefaultChangeUri时：forChildUris必须为true，如果为false将找不到该uri，收不到任何消息。 |
| callback  | Callback&lt;[ChangeData](arkts-apis-photoAccessHelper-i.md#changedata)&gt; | 是   | 返回要监听的[ChangeData](arkts-apis-photoAccessHelper-i.md#changedata)。注：uri可以注册多个不同的callback监听，[unRegisterChange](#unregisterchange)可以关闭该uri所有监听，也可以关闭指定callback的监听。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('registerChangeDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset !== undefined) {
    console.info('photoAsset.displayName : ' + photoAsset.displayName);
  }
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something.
  }
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something.
  }
  // 注册onCallback1监听。
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
  // 注册onCallback2监听。
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);

  await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
}
```

## unRegisterChange

unRegisterChange(uri: string, callback?: Callback&lt;ChangeData&gt;): void

取消指定uri的监听，一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时取消该uri的所有监听。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | 是   | PhotoAsset的uri, Album的uri或[DefaultChangeUri](arkts-apis-photoAccessHelper-e.md#defaultchangeuri)的值。 |
| callback | Callback&lt;[ChangeData](arkts-apis-photoAccessHelper-i.md#changedata)&gt; | 否   | 取消[registerChange](#registerchange)注册时的callback的监听，不填时，取消该uri的所有监听。注：off指定注册的callback后不会进入此回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('offDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
  let photoAsset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
  if (photoAsset !== undefined) {
    console.info('photoAsset.displayName : ' + photoAsset.displayName);
  }
  let onCallback1 = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData: photoAccessHelper.ChangeData) => {
    console.info('onCallback2 on');
  }
  // 注册onCallback1监听。
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback1);
  // 注册onCallback2监听。
  phAccessHelper.registerChange(photoAsset.uri, false, onCallback2);
  // 关闭onCallback1监听，onCallback2 继续监听。
  phAccessHelper.unRegisterChange(photoAsset.uri, onCallback1);
  await photoAccessHelper.MediaAssetChangeRequest.deleteAssets(context, [photoAsset]);
}
```

## applyChanges<sup>11+</sup>

applyChanges(mediaChangeRequest: MediaChangeRequest): Promise&lt;void&gt;

提交媒体变更请求，使用Promise方式返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

提交创建资产的变更请求时，使用安全控件调用接口创建媒体资源，无需申请'ohos.permission.WRITE_IMAGEVIDEO'权限，详情请参考[开发指南](../../media/medialibrary/photoAccessHelper-savebutton.md)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| mediaChangeRequest  | [MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11)  | 是  |  媒体变更请求，支持资产变更请求和相册变更请求。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201   | Permission denied.         |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 14000011  | System inner fail.     |

**示例：**

该接口依赖于[MediaChangeRequest](arkts-apis-photoAccessHelper-i.md#mediachangerequest11)对象，详细代码示例请参见[MediaAssetChangeRequest](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md)和[MediaAlbumChangeRequest](arkts-apis-photoAccessHelper-MediaAlbumChangeRequest.md)中的接口示例。

## release

release(callback: AsyncCallback&lt;void&gt;): void

释放PhotoAccessHelper实例，使用callback方式返回结果。
当后续不需要使用PhotoAccessHelper实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('releaseDemo');
  phAccessHelper.release((err) => {
    if (err !== undefined) {
      console.error(`release failed. error: ${err.code}, ${err.message}`);
    } else {
      console.info('release ok.');
    }
  });
}
```

## release

release(): Promise&lt;void&gt;

释放PhotoAccessHelper实例，使用Promise方式返回结果。
当后续不需要使用PhotoAccessHelper 实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401    | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('releaseDemo');
  try {
    await phAccessHelper.release();
    console.info('release ok.');
  } catch (err) {
    console.error(`release failed. error: ${err.code}, ${err.message}`);
  }
}
```

## showAssetsCreationDialog<sup>12+</sup>

showAssetsCreationDialog(srcFileUris: Array&lt;string&gt;, photoCreationConfigs: Array&lt;PhotoCreationConfig&gt;): Promise&lt;Array&lt;string&gt;&gt;

调用接口拉起保存确认弹窗。用户同意保存后，返回已创建并授予保存权限的uri列表，该列表永久生效，应用可使用该uri写入图片/视频。如果用户拒绝保存，将返回空列表。弹框需要显示应用名称，无法直接获取应用名称，依赖于配置项的label和icon，因此调用此接口时请确保module.json5文件中的abilities标签中配置了label和icon项。

> **说明：**
> 当传入uri为沙箱路径时，可正常保存图片/视频，但无界面预览。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| srcFileUris | Array&lt;string&gt; | 是 | 需保存到媒体库中的图片/视频文件对应的[媒体库uri](../../file-management/user-file-uri-intro.md#媒体文件uri)。<br>**注意：**<br>- 一次弹窗最多保存100张图片。<br>- 仅支持处理图片、视频uri。<br>- 不支持手动拼接的uri，需调用接口获取，获取方式参考[媒体文件uri获取方式](../../file-management/user-file-uri-intro.md#媒体文件uri获取方式)。  |
| photoCreationConfigs | Array&lt;[PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12)&gt; | 是 | 保存图片或视频到媒体库的配置，包括文件名等，与srcFileUris保持一一对应。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回给应用的媒体库文件uri列表。uri已对应用授权，支持应用写入数据。如果生成uri异常，则返回批量创建错误码。<br>返回-3006表示不允许出现非法字符；返回-2004表示图片类型和后缀不符；返回-203表示文件操作异常。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('ShowAssetsCreationDialogDemo.');

  try {
    // 获取需要保存到媒体库的位于应用沙箱的图片/视频uri。
    let srcFileUris: Array<string> = [
      'file://fileUriDemo1' // 实际场景请使用真实的uri。
    ];
    let photoCreationConfigs: Array<photoAccessHelper.PhotoCreationConfig> = [
      {
        title: 'test2', // 可选。
        fileNameExtension: 'jpg',
        photoType: photoAccessHelper.PhotoType.IMAGE,
        subtype: photoAccessHelper.PhotoSubtype.DEFAULT, // 可选。
      }
    ];
    let desFileUris: Array<string> = await phAccessHelper.showAssetsCreationDialog(srcFileUris, photoCreationConfigs);
    console.info('showAssetsCreationDialog success, data is ' + desFileUris);
  } catch (err) {
    console.error('showAssetsCreationDialog failed, errCode is ' + err.code + ', errMsg is ' + err.message);
  }
}
```

## createAssetWithShortTermPermission<sup>12+</sup>

createAssetWithShortTermPermission(photoCreationConfig: PhotoCreationConfig): Promise&lt;string&gt;

接口提供给应用调用，支持首次调用后拉起保存确认弹框。在用户同意保存后返回已创建并授予保存权限的uri，支持应用使用uri写入图片/视频；
在用户"同意"后的5min之内，同一个应用再次调用接口，支持无需弹框确认自动返回已授权的uri给应用，支持应用保存图片/视频。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**需要权限：** ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| photoCreationConfig | [PhotoCreationConfig](arkts-apis-photoAccessHelper-i.md#photocreationconfig12); | 是 | 保存图片/视频到媒体库的配置，包括保存的文件名等。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;string&gt; | Promise对象，返回给应用的媒体库文件uri。uri已对应用授权，支持应用写入数据。如果生成uri异常，则返回批量创建错误码。<br>返回-3006表示不允许出现非法字符；返回-2004表示图片类型和后缀不符；返回-203表示文件操作异常。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { fileIo } from '@kit.CoreFileKit';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
    console.info('createAssetWithShortTermPermissionDemo.');
    
    try {
        let photoCreationConfig: photoAccessHelper.PhotoCreationConfig = {
            title: '123456', 
            fileNameExtension: 'jpg',
            photoType: photoAccessHelper.PhotoType.IMAGE,
            subtype: photoAccessHelper.PhotoSubtype.DEFAULT, 
        };

        let resultUri: string = await phAccessHelper.createAssetWithShortTermPermission(photoCreationConfig);
        let resultFile: fileIo.File = fileIo.openSync(resultUri, fileIo.OpenMode.READ_WRITE);
        // 实际场景请使用真实的uri和文件大小。
        let srcFile:  fileIo.File = fileIo.openSync("file://test.jpg", fileIo.OpenMode.READ_ONLY);
        let bufSize: number = 2000000;
        let readSize: number = 0;
        let buf = new ArrayBuffer(bufSize);
        let readLen = fileIo.readSync(srcFile.fd, buf, {
            offset: readSize,
            length: bufSize
        });
        if (readLen > 0) {
            readSize += readLen;
            fileIo.writeSync(resultFile.fd, buf, { length: readLen });
        }
        fileIo.closeSync(srcFile);
        fileIo.closeSync(resultFile);
    } catch (err) {
        console.error('createAssetWithShortTermPermission failed, errCode is ' + err.code + ', errMsg is ' + err.message);
    }
    
}
```

## requestPhotoUrisReadPermission<sup>14+</sup>

requestPhotoUrisReadPermission(srcFileUris: Array&lt;string&gt;): Promise&lt;Array&lt;string&gt;&gt;

<!--RP1--><!--RP1End-->调用接口给未授权的uri进行授权，返回已创建并授予保存权限的uri列表。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                                                                   | 必填 | 说明                      |
| -------- |----------------------------------------------------------------------| ---- | ------------------------- |
| srcFileUris | Array&lt;string&gt; | 是 | 需进行授权的图片/视频文件对应的[媒体库uri](../../file-management/user-file-uri-intro.md#媒体文件uri)。<br>**注意：** 仅支持处理图片、视频uri。|

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回已授权的uri列表。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 |  Internal system error |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context) {
  console.info('requestPhotoUrisReadPermissionDemo.');

  try {
    let phAccessHelper: photoAccessHelper.PhotoAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
    // 获取需要进行授权的图片/视频uri。
    let srcFileUris: Array<string> = [
      'file://fileUriDemo1' // 实际场景请使用真实的uri。
    ];
    let desFileUris: Array<string> = await phAccessHelper.requestPhotoUrisReadPermission(srcFileUris);
    console.info('requestPhotoUrisReadPermission success, data is ' + desFileUris);
  } catch (err) {
    console.error('requestPhotoUrisReadPermission failed, errCode is ' + err.code + ', errMsg is ' + err.message);
  }
}
```

## getSupportedPhotoFormats<sup>18+</sup> 

getSupportedPhotoFormats(photoType: PhotoType): Promise&lt;Array&lt;string&gt;&gt;

接口提供给应用调用，获取媒体库支持的图片或者视频后缀列表。

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明      |
|-----------|-------------------------|-----------|-----------------|
| photoType | [PhotoType](arkts-apis-photoAccessHelper-e.md#phototype) | 是   | 媒体文件类型。 |

**返回值：**

| 类型                                     | 说明              |
|------------------------------------------|-------------------------|
| Promise&lt;Array&lt;string&gt;&gt; | Promise对象，返回支持的图片或者视频后缀列表。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14000011 | Internal system error. It is recommended to retry and check the logs. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, photoTypeNumber: number){
  console.info('getSupportedPhotoFormatsDemo.');

  try {
    let outputText: string;
    if (photoTypeNumber !== 1 && photoTypeNumber !== 2) {
      outputText = 'Does not support querying formats other than images or videos';
      return;
    }
    outputText = 'The supported types are:\n';
    let imageFormat  = await phAccessHelper.getSupportedPhotoFormats(photoTypeNumber);
    let result = "";
    for (let i = 0; i < imageFormat.length; i++) {
      result += imageFormat[i];
      if (i !== imageFormat.length - 1) {
        result += ', ';
      }
    }
    outputText += result;
    console.info('getSupportedPhotoFormats success, data is ' + outputText);
  } catch (error) {
    console.error('getSupportedPhotoFormats failed, errCode is', error);
  }
}
```

## on('photoChange')<sup>20+</sup> 

on(type: 'photoChange', callback: Callback&lt;PhotoAssetChangeInfos&gt;): void

注册'photoChange'监听媒体资产，并通过callback方式返回资产变化结果，可以注册多个callback。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明      |
|-----------|-------------------------|-----------|-----------------|
| type | string | 是   | 注册监听媒体资产，取值为'photoChange'。注册完成后，有资产发生变化时，通过callback返回变更信息。 |
| callback  | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | 是   | 返回变更的媒体资产信息[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)。<br>**注意：** 该接口可以注册多个不同的callback监听，[off('photoChange')](#offphotochange20)即可以关闭所有监听，也可以关闭指定callback监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoChangeDemo.');

  try {
    // 注册onCallback1监听。
    phAccessHelper.on('photoChange', onCallback1);
    // 注册onCallback2监听。
    phAccessHelper.on('photoChange', onCallback2);
  } catch (error) {
    console.error('onPhotoChangeDemo failed, errCode is', error);
  }
}
```

## off('photoChange')<sup>20+</sup> 

off(type: 'photoChange', callback?: Callback&lt;PhotoAssetChangeInfos&gt;): void

取消对'photoChange'媒体资产的监听。存在多个callback监听时，可以取消指定注册的callback监听；不指定callback时取消所有监听。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明      |
|-----------|-------------------------|-----------|-----------------|
| type | string | 是   | 取消监听媒体资产，取值为'photoChange'。取消监听后，有资产发生变化时，不再通过callback返回变更信息。 |
| callback | Callback&lt;[PhotoAssetChangeInfos](arkts-apis-photoAccessHelper-i.md#photoassetchangeinfos20)&gt; | 否   | 取消[on('photoChange')](#onphotochange20)注册时指定的callback监听；不填时，则取消对'photoChange'的所有监听。<br>**注意：** 取消注册的callback后，有资产发生变化时，不会进入此回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.PhotoAssetChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('offPhotoChangeDemo.');

  try {
    // 注册onCallback1监听。
    phAccessHelper.on('photoChange', onCallback1);
    // 注册onCallback2监听。
    phAccessHelper.on('photoChange', onCallback2);

    // 关闭onCallback1监听，onCallback2继续监听。
    phAccessHelper.off('photoChange', onCallback1);
  } catch (error) {
    console.error('offPhotoChangeDemo failed, errCode is', error);
  }
}
```

## on('photoAlbumChange')<sup>20+</sup> 

on(type: 'photoAlbumChange', callback: Callback&lt;AlbumChangeInfos&gt;): void

注册'photoAlbumChange'监听相册，并通过callback方式返回相册变化结果，可以注册多个callback。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明      |
|-----------|-------------------------|-----------|-----------------|
| type | string | 是   | 注册监听相册，取值为'photoAlbumChange'。注册完成后，有相册发生变化时，通过callback返回变更信息。 |
| callback  | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | 是   | 返回变更的相册信息[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)。<br>**注意：** 该接口可以注册多个不同的callback监听，[off('photoAlbumChange')](#offphotoalbumchange20)即可以关闭所有监听，也可以关闭指定callback监听。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoAlbumChange'; 2. The same callback is registered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoAlbumChangeDemo.');

  try {
    // 注册onCallback1监听。
    phAccessHelper.on('photoAlbumChange', onCallback1);
    // 注册onCallback2监听。
    phAccessHelper.on('photoAlbumChange', onCallback2);
  } catch (error) {
    console.error('onPhotoAlbumChangeDemo failed, errCode is', error);
  }
}
```

## off('photoAlbumChange')<sup>20+</sup> 

off(type: 'photoAlbumChange', callback?: Callback&lt;AlbumChangeInfos&gt;): void

取消对'photoAlbumChange'相册的监听。存在多个callback监听时，可以取消指定注册的callback监听；不指定callback时取消所有监听。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明      |
|-----------|-------------------------|-----------|-----------------|
| type | string | 是   | 取消监听相册，取值为'photoAlbumChange'。取消监听后，有相册发生变化时，不再通过callback返回变更信息。 |
| callback | Callback&lt;[AlbumChangeInfos](arkts-apis-photoAccessHelper-i.md#albumchangeinfos20)&gt; | 否   | 取消[on('photoAlbumChange')](#onphotoalbumchange20)注册时指定的callback监听；不填时，则取消对'photoAlbumChange'的所有监听。<br>**注意：** 取消注册的callback后，有相册发生变化时，不会进入此回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 201 | Permission denied. |
| 23800151 | The scenario parameter verification fails.<br>Possible causes: 1. The type is not fixed at 'photoAlbumChange'; 2. The same callback is unregistered repeatedly. |
| 23800301 | Internal system error. You are advised to retry and check the logs.<br>Possible causes: 1. The database is corrupted. 2. The file system is abnormal. 3. The IPC request timed out. |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData'

let onCallback1 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}
let onCallback2 = (changeData: photoAccessHelper.AlbumChangeInfos) => {
    console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
  // file had changed, do something.
}

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper, context: Context){
  console.info('onPhotoAlbumChangeDemo.');

  try {
    // 注册onCallback1监听。
    phAccessHelper.on('photoAlbumChange', onCallback1);
    // 注册onCallback2监听。
    phAccessHelper.on('photoAlbumChange', onCallback2);

    // 关闭onCallback1监听，onCallback2继续监听。
    phAccessHelper.off('photoAlbumChange', onCallback1);
  } catch (error) {
    console.error('onPhotoAlbumChangeDemo failed, errCode is', error);
  }
}
```

## createDeleteRequest<sup>(deprecated)</sup>

createDeleteRequest(uriList: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

创建一个弹出框来删除照片，删除的文件进入到回收站，使用callback方式返回结果。

> **说明：** 
>
> 从API version 10开始支持，从API version 11开始废弃。建议使用[MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11-1)替代。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | 是   | 待删除的媒体文件uri数组，最大删除数量300。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset === undefined) {
      console.error('asset not exist');
      return;
    }
    phAccessHelper.createDeleteRequest([asset.uri], (err) => {
      if (err === undefined) {
        console.info('createDeleteRequest successfully');
      } else {
        console.error(`createDeleteRequest failed with error: ${err.code}, ${err.message}`);
      }
    });
  } catch (err) {
    console.error(`fetch failed, error: ${err.code}, ${err.message}`);
  }
}
```

## createDeleteRequest<sup>(deprecated)</sup>

createDeleteRequest(uriList: Array&lt;string&gt;): Promise&lt;void&gt;

创建一个弹出框来删除照片，删除的文件进入到回收站，使用Promise方式返回结果。

> **说明：**
>
> 从API version 10开始支持，从API version 11开始废弃。建议使用[MediaAssetChangeRequest.deleteAssets](arkts-apis-photoAccessHelper-MediaAssetChangeRequest.md#deleteassets11-1)替代。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.PhotoAccessHelper.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uriList | Array&lt;string&gt; | 是   | 待删除的媒体文件uri数组，最大删除数量300。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[文件管理错误码](../apis-core-file-kit/errorcode-filemanagement.md)。

错误码13900012，请参考[开发准备](../../media/medialibrary/photoAccessHelper-preparation.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. | 
| 13900012     | Permission denied.         |
| 13900020     | Invalid argument.         |
| 14000011       | System inner fail.         |

**示例：**

phAccessHelper的创建请参考[photoAccessHelper.getPhotoAccessHelper](arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)的示例使用。

```ts
import { dataSharePredicates } from '@kit.ArkData';

async function example(phAccessHelper: photoAccessHelper.PhotoAccessHelper) {
  console.info('createDeleteRequestDemo');
  let predicates: dataSharePredicates.DataSharePredicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions: photoAccessHelper.FetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult: photoAccessHelper.FetchResult<photoAccessHelper.PhotoAsset> = await phAccessHelper.getAssets(fetchOptions);
    let asset: photoAccessHelper.PhotoAsset = await fetchResult.getFirstObject();
    if (asset === undefined) {
      console.error('asset not exist');
      return;
    }
    await phAccessHelper.createDeleteRequest([asset.uri]);
    console.info('createDeleteRequest successfully');
  } catch (err) {
    console.error(`createDeleteRequest failed with error: ${err.code}, ${err.message}`);
  }
}
```
