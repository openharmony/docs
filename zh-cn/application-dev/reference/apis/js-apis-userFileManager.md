# @ohos.filemanagement.userFileManager (用户数据管理)

该模块提供用户数据管理能力，包括访问、修改用户等用户公共媒体数据信息等常用功能。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。

## 导入模块

```ts
import userFileManager from '@ohos.filemanagement.userFileManager';
```

## userFileManager.getUserFileMgr

getUserFileMgr(context: Context): UserFileManager

获取用户数据管理模块的实例，用于访问和修改用户等用户公共媒体数据信息（如音频、视频、图片、文档等）。

**模型约束**： 此接口仅可在Stage模型下使用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明                       |
| ------- | ------- | ---- | -------------------------- |
| context | [Context](js-apis-inner-app-context.md) | 是   | 传入Ability实例的Context。 |

**返回值：**

| 类型                            | 说明    |
| ----------------------------- | :---- |
| [UserFileManager](#userfilemanager) | 媒体库实例。 |

**示例：**

```ts
//此处获取的userFileManager实例mgr为全局对象，后续使用到mgr的地方默认为使用此处获取的对象，如未添加此段代码报mgr未定义的错误请自行添加
const context = getContext(this);
let mgr = userFileManager.getUserFileMgr(context);
```

## UserFileManager

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取图片和视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 图片和视频检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频检索结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getPhotoAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName : ' + fileAsset.displayName);
      }
    } else {
      console.error('fetchResult fail' + err);
    }
  });
}
```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取图片和视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名  | 类型                | 必填 | 说明             |
| ------- | ------------------- | ---- | ---------------- |
| options | [FetchOptions](#fetchoptions)   | 是   | 图片和视频检索选项。     |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise对象，返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAssets(fetchOptions);
    if (fetchResult != undefined) {
      console.info('fetchResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    }
  } catch (err) {
    console.error('getPhotoAssets failed, message = ', err);
  }
}
```
### createPhotoAsset

createPhotoAsset(displayName: string, albumUri: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

指定待创建的图片或者视频的文件名和所在相册的uri，创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| albumUri  | string        | 是   | 创建的图片或者视频所在相册的uri。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('createPhotoAssetDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    predicates: predicates
  };
  let albums = await mgr.getPhotoAlbums(fetchOptions);
  let album = await albums.getFirstObject();
  let testFileName = 'testFile' + Date.now() + '.jpg';
  mgr.createPhotoAsset(testFileName, album.albumUri, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

指定待创建的图片或者视频的文件名，创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.jpg';
  mgr.createPhotoAsset(testFileName, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, albumUri?: string): Promise&lt;FileAsset&gt;;

指定待创建的图片或者视频的文件名和所在相册的uri，创建图片或视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| albumUri  | string        | 否   | 创建的图片或者视频所在相册的uri。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise对象，返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName or albumUri is not string.         |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions, callback: AsyncCallback&lt;FileAsset&gt;): void;

指定待创建的图片或者视频的文件名和创建选项，创建图片或视频资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| createOption  | [PhotoCreateOptions](#photocreateoptions10)        | 是   | 图片或视频的创建选项。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.jpg';
  let createOption = {
    subType: userFileManager.PhotoSubType.DEFAULT
  }
  mgr.createPhotoAsset(testFileName, createOption, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createPhotoAsset file displayName' + fileAsset.displayName);
      console.info('createPhotoAsset successfully');
    } else {
      console.error('createPhotoAsset failed, message = ', err);
    }
  });
}
```

### createPhotoAsset

createPhotoAsset(displayName: string, createOption: PhotoCreateOptions): Promise&lt;FileAsset&gt;;

指定待创建的图片或者视频的文件名和创建选项，创建图片或视频资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的图片或者视频文件名。              |
| createOption  |  [PhotoCreateOptions](#photocreateoptions10)       | 是   | 图片或视频的创建选项。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise对象，返回创建的图片和视频结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**示例：**

```ts
async function example() {
  console.info('createPhotoAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let createOption = {
      subType: userFileManager.PhotoSubType.DEFAULT
    }
    let fileAsset = await mgr.createPhotoAsset(testFileName, createOption);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ', err);
  }
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string, callback: AsyncCallback&lt;FileAsset&gt;): void;

创建音频文件资源，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的音频文件名。              |
| callback |  AsyncCallback&lt;[FileAsset](#fileasset)&gt; | 是   | callback返回创建的音频资源结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |
| 14000001   | if type displayName invalid.         |

**示例：**

```ts
async function example() {
  console.info('createAudioAssetDemo');
  let testFileName = 'testFile' + Date.now() + '.mp3';
  mgr.createAudioAsset(testFileName, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('createAudioAsset file displayName' + fileAsset.displayName);
      console.info('createAudioAsset successfully');
    } else {
      console.error('createAudioAsset failed, message = ', err);
    }
  });
}
```

### createAudioAsset<sup>10+</sup>

createAudioAsset(displayName: string): Promise&lt;FileAsset&gt;;

创建音频文件资源，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| displayName  | string        | 是   | 创建的音频文件名。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FileAsset](#fileasset)&gt; | Promise对象，返回创建的音频资源结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type displayName is not string.         |

**示例：**

```ts
async function example() {
  console.info('createAudioAssetDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.mp3';
    let fileAsset = await mgr.createAudioAsset(testFileName);
    console.info('createAudioAsset file displayName' + fileAsset.displayName);
    console.info('createAudioAsset successfully');
  } catch (err) {
    console.error('createAudioAsset failed, message = ', err);
  }
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;


获取相册，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | 是   | 相册检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | 是   | callback返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };

  mgr.getPhotoAlbums(albumFetchOptions, (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('albums.count = ' + fetchResult.getCount());
      fetchResult.getFirstObject((err, album) => {
        if (album != undefined) {
          console.info('first album.albumName = ' + album.albumName);
        } else {
          console.error('album is undefined, err = ', err);
        }
      });
    } else {
      console.error('getPhotoAlbums fail, message = ', err);
    }
  });
}
```

### getPhotoAlbums

getPhotoAlbums(options: AlbumFetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;;

获取相册，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [AlbumFetchOptions](#albumfetchoptions)        | 是   | 相册检索选项。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise对象，返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not AlbumFetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPhotoAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAlbums(albumFetchOptions);
    console.info('album.count = ' + fetchResult.getCount());
    const album = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + album.albumName);
  } catch (err) {
    console.error('getPhotoAlbums fail, message = ' + err);
  }
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string, callback: AsyncCallback&lt;Album&gt;): void;

创建相册，使用callback方式返回结果。

待创建的相册名参数规格为：
- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . .. \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | 是   | 待创建相册的相册名。              |
| callback |  AsyncCallback&lt;[Album](#album)&gt; | 是   | callback返回创建的相册实例。 |

**示例：**

```ts
async function example() {
  console.info('createAlbumDemo');
  let albumName = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName, (err, album) => {
    if (err) {
      console.error('createAlbumCallback failed with err: ' + err);
      return;
    }
    console.info('createAlbumCallback successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  });
}
```

### createAlbum<sup>10+</sup>

createAlbum(name: string): Promise&lt;Album&gt;;

创建相册，使用Promise方式返回结果。

待创建的相册名参数规格为：
- 相册名字符串长度为1~255。
- 不允许出现的非法英文字符，包括：<br> . .. \ / : * ? " ' ` < > | { } [ ]
- 英文字符大小写不敏感。
- 相册名不允许重名。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| name  | string         | 是   | 待创建相册的相册名。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[Album](#album)&gt; | Promise对象，返回创建的相册实例。 |

**示例：**

```ts
async function example() {
  console.info('createAlbumDemo');
  let albumName = 'newAlbumName' + new Date().getTime();
  mgr.createAlbum(albumName).then((album) => {
    console.info('createAlbumPromise successfully, album: ' + album.albumName + ' album uri: ' + album.albumUri);
  }).catch((err) => {
    console.error('createAlbumPromise failed with err: ' + err);
  });
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;, callback: AsyncCallback&lt;void&gt;): void;

删除相册，使用callback方式返回结果。

删除相册前需先确保相册存在，只能删除用户相册。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  | Array&lt;[Album](#album)&gt;         | 是   | 待删除相册的数组。              |
| callback |  AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // 示例代码为删除相册名为newAlbumName的相册。
  console.info('deleteAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album], (err) => {
    if (err) {
      console.error('deletePhotoAlbumsCallback failed with err: ' + err);
      return;
    }
    console.info('deletePhotoAlbumsCallback successfully');
  });
  fetchResult.close();
}
```

### deleteAlbums<sup>10+</sup>

deleteAlbums(albums: Array&lt;Album&gt;): Promise&lt;void&gt;;

删除相册，使用Promise方式返回结果。

删除相册前需先确保相册存在，只能删除用户相册。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| albums  |  Array&lt;[Album](#album)&gt;          | 是   | 待删除相册的数组。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // 示例代码为删除相册名为newAlbumName的相册。
  console.info('deleteAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions);
  let album = await fetchResult.getFirstObject();
  mgr.deleteAlbums([album]).then(() => {
    console.info('deletePhotoAlbumsPromise successfully');
    }).catch((err) => {
      console.error('deletePhotoAlbumsPromise failed with err: ' + err);
  });
  fetchResult.close();
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;

根据检索选项和相册类型获取相册，使用callback方式返回结果。

获取相册前需先保证相册存在。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | 是   | 相册类型。              |
| subType  | [AlbumSubType](#albumsubtype10)         | 是   | 相册子类型。              |
| options  | [FetchOptions](#fetchoptions)         | 是   |  检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | 是   | callback返回获取相册的结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions, async (err, fetchResult) => {
    if (err) {
      console.error('getAlbumsCallback failed with err: ' + err);
      return;
    }
    if (fetchResult == undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumName: ' + album.albumName);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, callback: AsyncCallback&lt;FetchResult&lt;Album&gt;&gt;): void;

根据相册类型获取相册，使用callback方式返回结果。

获取相册前需先保证相册存在。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | 是   | 相册类型。              |
| subType  | [AlbumSubType](#albumsubtype10)         | 是   | 相册子类型。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | 是   | callback返回获取相册的结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

```ts
async function example() {
  // 示例代码中为获取统相册VIDEO，默认已预置。
  console.info('getAlbumsDemo');
  mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.VIDEO, async (err, fetchResult) => {
    if (err) {
      console.error('getAlbumsCallback failed with err: ' + err);
      return;
    }
    if (fetchResult == undefined) {
      console.error('getAlbumsCallback fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsCallback successfully, albumUri: ' + album.albumUri);
    fetchResult.close();
  });
}
```

### getAlbums<sup>10+</sup>

getAlbums(type: AlbumType, subType: AlbumSubType, options?: FetchOptions): Promise&lt;FetchResult&lt;Album&gt;&gt;;

根据检索选项和相册类型获取相册，使用Promise方式返回结果。

获取相册前需先保证相册存在。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [AlbumType](#albumtype10)         | 是   | 相册类型。              |
| subType  | [AlbumSubType](#albumsubtype10)         | 是   | 相册子类型。              |
| options  | [FetchOptions](#fetchoptions)         | 否   |  检索选项，不填时默认根据相册类型检索。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[Album](#album)&gt;&gt; | Promise对象，返回获取相册的结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOption.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // 示例代码中为获取相册名为newAlbumName的相册。
  console.info('getAlbumsDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  predicates.equalTo('album_name', 'newAlbumName');
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC, fetchOptions).then( async (fetchResult) => {
    if (fetchResult == undefined) {
      console.error('getAlbumsPromise fetchResult is undefined');
      return;
    }
    let album = await fetchResult.getFirstObject();
    console.info('getAlbumsPromise successfully, albumName: ' + album.albumName);
    fetchResult.close();
  }).catch((err) => {
    console.error('getAlbumsPromise failed with err: ' + err);
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType, callback: AsyncCallback&lt;FetchResult&lt;PrivateAlbum&gt;&gt;): void;

获取系统相册，使用 callback 方式返回系统相册的数组。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | 是   | 系统相册类型。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | 是   | callback返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**示例：**

```ts
async function example() {
  console.info('getPrivateAlbumDemo');
  mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      let trashAlbum = await fetchResult.getFirstObject();
      console.info('first album.albumName = ' + trashAlbum.albumName);
    } else {
      console.error('getPrivateAlbum failed. message = ', err);
    }
  });
}
```

### getPrivateAlbum

getPrivateAlbum(type: PrivateAlbumType): Promise&lt;FetchResult&lt;PrivateAlbum&gt;&gt;;

获取系统相册，使用Promise方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| type  | [PrivateAlbumType](#privatealbumtype)        | 是   | 系统相册类型。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[PrivateAlbum](#privatealbum)&gt;&gt; | Promise对象，返回相册检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type type is not PrivateAlbumType.         |

**示例：**

```ts
async function example() {
  console.info('getPrivateAlbumDemo');
  try {
    let fetchResult = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
    let trashAlbum = await fetchResult.getFirstObject();
    console.info('first album.albumName = ' + trashAlbum.albumName);
  } catch (err) {
    console.error('getPrivateAlbum failed. message = ', err);
  }
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取音频文件，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 检索选项。              |
| callback |  AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回音频检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAudioAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };

  mgr.getAudioAssets(fetchOptions, async (err, fetchResult) => {
    if (fetchResult != undefined) {
      console.info('fetchFileResult success');
      let fileAsset = await fetchResult.getFirstObject();
      if (fileAsset != undefined) {
        console.info('fileAsset.displayName :' + fileAsset.displayName);
      }
    } else {
      console.error('fetchFileResult fail' + err);
    }
  });
}
```

### getAudioAssets

getAudioAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;


获取音频文件，使用callback方式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**需要权限**：ohos.permission.READ_AUDIO

**参数：**

| 参数名   | 类型                     | 必填 | 说明                      |
| -------- | ------------------------ | ---- | ------------------------- |
| options  | [FetchOptions](#fetchoptions)        | 是   | 检索选项。              |

**返回值：**

| 类型                        | 说明           |
| --------------------------- | -------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise对象，返回音频检索结果。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAudioAssets');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    var fetchResult = await mgr.getAudioAssets(fetchOptions);
  } catch (err) {
    console.error('getAudioAssets failed, message = ', err);
  }

  if (fetchResult != undefined) {
    console.info('fetchFileResult success');
    let fileAsset = await fetchResult.getFirstObject();
    if (fileAsset != undefined) {
      console.info('fileAsset.displayName :' + fileAsset.displayName);
    }
  }
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void;

删除媒体文件，删除的文件进入到回收站。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 媒体文件uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteAssetDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err);
  }

  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  mgr.delete(asset.uri, (err) => {
    if (err == undefined) {
      console.info('delete successfully');
    } else {
      console.error('delete failed with error: ' + err);
    }
  });
}
```

### delete

delete(uri: string): Promise&lt;void&gt;;

删除媒体文件,删除的文件进入到回收站。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 媒体文件uri。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type uri is not string.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('deleteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    const fetchResult = await mgr.getPhotoAssets(fetchOptions);
    var asset = await fetchResult.getFirstObject();
  } catch (err) {
    console.info('fetch failed, message =', err);
  }

  if (asset == undefined) {
    console.error('asset not exist');
    return;
  }
  try {
    await mgr.delete(asset.uri);
    console.info('delete successfully');
  } catch (err) {
    console.error('delete failed with error: ' + err);
  }
}
```

### on

on(type: ChangeEvent, callback: Callback&lt;void&gt;): void

打开文件管理库变更通知，使用callback方式返回异步结果。

此接口即将废弃，请使用[on<sup>10+</sup>](#on10)的新接口

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更 |
| callback | Callback&lt;void&gt; | 是   | callback返回void                                                   |

**示例：**

```ts
async function example() {
  console.info('onDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // image file had changed, do something
  });
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count > 0) {
    console.info('onDemo success');
  } else {
    console.error('onDemo fail');
  }
  mgr.off('imageChange', () => {
    // stop listening success
  });
}
```

### off

off(type: ChangeEvent, callback?: Callback&lt;void&gt;): void

关闭文件管理库变更通知，使用callback方式返回异步结果。

此接口即将废弃，请使用[off<sup>10+</sup>](#off10)的新接口

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                                         |
| -------- | -------------------- | ---- | ------------------------------------------------------------ |
| type     | [ChangeEvent](#changeevent)               | 是   | 媒体类型 <br/>'deviceChange'：&nbsp;注册设备变更 <br/>'albumChange'：&nbsp;相册变更<br/>'imageChange'：&nbsp;图片文件变更<br/>'audioChange'： &nbsp;音频文件变更<br/>'videoChange'：  &nbsp;视频文件变更<br/>'remoteFileChange'：&nbsp;注册设备上文件变更。 |
| callback | Callback&lt;void&gt; | 否   | callback返回void。                                                   |

**示例：**

```ts
async function example() {
  console.info('offDemo');
  let count = 0;
  mgr.on('imageChange', () => {
    count++;
    // image file had changed, do something
  });

  mgr.off('imageChange', () => {
    // stop listening success
  });

  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    let fileAsset = await mgr.createPhotoAsset(testFileName);
    console.info('createPhotoAsset file displayName' + fileAsset.displayName);
    console.info('createPhotoAsset successfully');
  } catch (err) {
    console.error('createPhotoAsset failed, message = ' + err);
  }
  //sleep 1s
  if (count == 0) {
    console.info('offDemo success');
  } else {
    console.error('offDemo fail');
  }
}
```

### getActivePeers

getActivePeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

获取在线对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表。 |

**示例：**

```ts
async function example() {
  console.info('getActivePeersDemo');
  mgr.getActivePeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.log('getActivePeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('getActivePeers failed. message = ', err);
    }
  });
}
```

### getActivePeers

getActivePeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

获取在线对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise对象，返回在线设备列表。 |

**示例：**

```ts
async function example() {
  console.info('getActivePeersDemo');
  try {
    var devicesInfo = await mgr.getActivePeers();
  } catch (err) {
    console.error('getActivePeers failed. message = ', err);
  }
  if (devicesInfo != undefined) {
    console.log('getActivePeers succeed.');
    for (let i = 0; i < devicesInfo.length; i++) {
      console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
    }
  } else {
    console.error('get distributed fail');
  }
}
```

### getAllPeers

getAllPeers(callback: AsyncCallback&lt;Array&lt;PeerInfo&gt;&gt;): void;

获取所有对端设备的信息，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**参数：**

| 参数名   | 类型                              | 必填 | 说明         |
| -------- | --------------------------------- | ---- | ------------ |
| callback | AsyncCallback&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | 是   | 返回在线设备列表。 |

**示例：**

```ts
async function example() {
  console.info('getAllPeersDemo');
  mgr.getAllPeers((err, devicesInfo) => {
    if (devicesInfo != undefined) {
      console.log('getAllPeers succeed.');
      for (let i = 0; i < devicesInfo.length; i++) {
        console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
      }
    } else {
      console.error('getAllPeers failed. message = ', err);
    }
  });
}
```

### getAllPeers

getAllPeers(): Promise&lt;Array&lt;PeerInfo&gt;&gt;;

获取所有对端设备的信息，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

**返回值：**

| 类型                        | 说明                          |
| --------------------------- | ----------------------------- |
| Promise&lt;Array&lt;[PeerInfo](#peerinfo)&gt;&gt; | Promise对象，返回所有设备列表。 |

**示例：**

```ts
async function example() {
  console.info('getAllPeersDemo');
  try {
    var devicesInfo = await mgr.getAllPeers();
  } catch (err) {
    console.error('getAllPeers failed. message = ', err);
  }
  if (devicesInfo != undefined) {
    console.log('getAllPeers succeed.');
    for (let i = 0; i < devicesInfo.length; i++) {
      console.info('get distributed info ' + devicesInfo[i].deviceName + devicesInfo[i].networkId);
    }
  } else {
    console.error('get distributed fail');
  }
}
```

### release

release(callback: AsyncCallback&lt;void&gt;): void

释放UserFileManager实例。
当后续不需要使用UserFileManager实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调表示成功还是失败。 |

**示例：**

```ts
async function example() {
  console.info('releaseDemo');
  mgr.release((err) => {
    if (err != undefined) {
      console.error('release failed. message = ', err);
    } else {
      console.info('release ok.');
    }
  });
}
```

### release

release(): Promise&lt;void&gt;

释放UserFileManager实例。
当后续不需要使用UserFileManager 实例中的方法时调用。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                | 说明                              |
| ------------------- | --------------------------------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

```ts
async function example() {
  console.info('releaseDemo');
  try {
    await mgr.release();
    console.info('release ok.');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### on<sup>10+</sup>

on(uri: string, forSubUri: boolean, callback: Callback&lt;ChangeData&gt;) : void

打开对指定uri的监听，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名    | 类型                                        | 必填 | 说明                                                         |
| --------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri       | string                                      | 是   | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |
| forSubUri | boolean                                     | 是   | 是否模糊监听，uri为相册uri时，forSubUri 为true能监听到相册中文件的变化，如果是false只能监听相册本身变化。uri为fileAsset时，forSubUri 为true、false没有区别，uri为DefaultChangeUri时，forSubUri必须为true，如果为false将找不到该uri，收不到任何消息。 |
| callback  | Callback&lt;[ChangeData](#changedata10)&gt; | 是   | 返回要监听的[ChangeData](#changedata10)。注：uri可以注册多个不同的callback监听，[off<sup>10+</sup>](#off10)可以关闭该uri所有监听，也可以关闭指定callback的监听。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('onDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData) => {
      console.info('onCallback1 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  let onCallback2 = (changeData) => {
      console.info('onCallback2 success, changData: ' + JSON.stringify(changeData));
    //file had changed, do something
  }
  // 注册onCallback1监听
  mgr.on(fileAsset.uri, false, onCallback1); 
  // 注册onCallback2监听
  mgr.on(fileAsset.uri, false, onCallback2);

  fileAsset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

### off<sup>10+</sup>

 off(uri: string, callback?: Callback&lt;ChangeData&gt;): void

关闭指定uri的监听，一个uri可以注册多个监听，存在多个callback监听时，可以取消指定注册的callback的监听；不指定callback时解除该uri的所有监听。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                         |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                      | 是   | FileAsset的uri, Album的uri或[DefaultChangeUri](#defaultchangeuri10)的值。 |
| callback | Callback&lt;[ChangeData](#changedata10)&gt; | 否   | 解除[on<sup>10+</sup>](#on10)注册时的callback的监听，不填时，解除该uri的所有监听。注：off指定注册的callback后不会进入此回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if parameter is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('offDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOptions = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOptions);
  let fileAsset = await fetchResult.getFirstObject();
  if (fileAsset != undefined) {
    console.info('fileAsset.displayName : ' + fileAsset.displayName);
  }
  let onCallback1 = (changeData) => {
    console.info('onCallback1 on');
  }
  let onCallback2 = (changeData) => {
    console.info('onCallback2 on');
  }
  // 注册onCallback1监听
  mgr.on(fileAsset.uri, false, onCallback1);
  // 注册onCallback2监听
  mgr.on(fileAsset.uri, false, onCallback2);
  // 关闭onCallback1监听，onCallback2 继续监听
  mgr.off(fileAsset.uri, onCallback1);
  fileAsset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

## FileAsset

提供封装文件属性的方法。

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                      | 类型                     | 可读 | 可写 | 说明                                                   |
| ------------------------- | ------------------------ | ---- | ---- | ------------------------------------------------------ |
| uri                       | string                   | 是   | 否   | 文件资源uri（如：file://media/image/2）。         |
| fileType   | [FileType](#filetype) | 是   | 否   | 媒体文件类型                                               |
| displayName               | string                   | 是   | 是   | 显示文件名，包含后缀名。                                 |

### get

get(member: string): MemberType;

获取FileAsset成员参数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.URI。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetGetDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: ['title'],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let title = userFileManager.ImageVideoKey.TITLE;
    let fileAssetTitle = fileAsset.get(title.toString());
    console.info('fileAsset Get fileAssetTitle = ', fileAssetTitle);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### set

set(member: string, value: string): void;

设置FileAsset成员参数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| member | string | 是    | 成员参数名称例如：ImageVideoKey.URI。 |
| value | string | 是    | 设置成员参数名称，只能修改ImageVideoKey.DISPLAY_NAME的值。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fileAssetSetDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let fileAsset = await fetchResult.getFirstObject();
    let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
    fileAsset.set(displayName, 'newDisplayName1');
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void

修改文件的元数据，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| callback | AsyncCallback&lt;void&gt; | 是    | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  fileAsset.set(displayName, 'newDisplayName2');
  fileAsset.commitModify((err) => {
    if (err == undefined) {
      let newFileAssetDisplayName = fileAsset.get(displayName);
      console.info('fileAsset get newFileAssetDisplayName = ', newFileAssetDisplayName);
    } else {
      console.error('commitModify failed, message =', err);
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;

修改文件的元数据，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**  

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('commitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  let displayName = userFileManager.ImageVideoKey.DISPLAY_NAME.toString();
  let fileAssetDisplayName = fileAsset.get(displayName);
  console.info('fileAsset get fileAssetDisplayName = ', fileAssetDisplayName);
  fileAsset.set(displayName, 'newDisplayName3');
  try {
    await fileAsset.commitModify();
    let newFileAssetDisplayName = fileAsset.get(displayName);
    console.info('fileAsset get newFileAssetDisplayName = ', newFileAssetDisplayName);
  } catch (err) {
    console.error('release failed. message = ', err);
  }
}
```

### open

open(mode: string, callback: AsyncCallback&lt;number&gt;): void

打开当前文件，使用callback方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                          | 必填   | 说明                                  |
| -------- | --------------------------- | ---- | ----------------------------------- |
| mode     | string                      | 是    | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |
| callback | AsyncCallback&lt;number&gt; | 是    | callback返回文件描述符。                            |

**示例：**

```ts
async function example() {
  console.info('openDemo');
   let testFileName = 'testFile' + Date.now() + '.jpg';
  const fileAsset = await mgr.createPhotoAsset(testFileName);
  fileAsset.open('rw', (err, fd) => {
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd);
    } else {
      console.error('File err' + err);
    }
  });
}
```

### open

open(mode: string): Promise&lt;number&gt;

打开当前文件，使用promise方式返回异步结果。

**注意**：当前写操作是互斥的操作，写操作完成后需要调用close进行释放。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 或 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明                                  |
| ---- | ------ | ---- | ----------------------------------- |
| mode | string | 是    | 打开文件方式，如：'r'（只读）, 'w'（只写）, 'rw'（读写）。 |

**返回值：**

| 类型                    | 说明            |
| --------------------- | ------------- |
| Promise&lt;number&gt; | Promise对象，返回文件描述符。 |

**示例：**

```ts
async function example() {
  console.info('openDemo');
  try {
    let testFileName = 'testFile' + Date.now() + '.jpg';
    const fileAsset = await mgr.createPhotoAsset(testFileName);
    let fd = await fileAsset.open('rw');
    if (fd != undefined) {
      console.info('File fd' + fd);
      fileAsset.close(fd);
    } else {
      console.error(' open File fail');
    }
  } catch (err) {
    console.error('open Demo err' + err);
  }
}
```

### close

close(fd: number, callback: AsyncCallback&lt;void&gt;): void

关闭当前文件，使用callback方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                        | 必填   | 说明    |
| -------- | ------------------------- | ---- | ----- |
| fd       | number                    | 是    | 文件描述符。 |
| callback | AsyncCallback&lt;void&gt; | 是    | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    const fileAsset = await fetchResult.getFirstObject();
    let fd = await fileAsset.open('rw');
    console.info('file fd', fd);
    fileAsset.close(fd, (err) => {
      if (err == undefined) {
        console.info('asset close succeed.');
      } else {
        console.error('close failed, message = ' + err);
      }
    });
  } catch (err) {
    console.error('close failed, message = ' + err);
  }
}
```

### close

close(fd: number): Promise&lt;void&gt;

关闭当前文件，使用promise方式返回异步结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型     | 必填   | 说明    |
| ---- | ------ | ---- | ----- |
| fd   | number | 是    | 文件描述符。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('closeDemo');
  try {
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    const asset = await fetchResult.getFirstObject();
    let fd = await asset.open('rw');
    console.info('file fd', fd);
    await asset.close(fd);
    console.info('asset close succeed.');
  } catch (err) {
    console.error('close failed, message = ' + err);
  }
}
```

### getThumbnail

getThumbnail(callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是    | callback返回缩略图的PixelMap。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail((err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size: image.Size, callback: AsyncCallback&lt;image.PixelMap&gt;): void

获取文件的缩略图，传入缩略图尺寸，使用callback方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名      | 类型                                  | 必填   | 说明               |
| -------- | ----------------------------------- | ---- | ---------------- |
| size     | [image.Size](js-apis-image.md#size) | 是    | 缩略图尺寸。            |
| callback | AsyncCallback&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | 是    | callback返回缩略图的PixelMap。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size, (err, pixelMap) => {
    if (err == undefined) {
      console.info('getThumbnail successful ' + pixelMap);
    } else {
      console.error('getThumbnail fail', err);
    }
  });
}
```

### getThumbnail

getThumbnail(size?: image.Size): Promise&lt;image.PixelMap&gt;

获取文件的缩略图，传入缩略图尺寸，使用promise方式返回异步结果。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 或 ohos.permission.READ_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名  | 类型             | 必填   | 说明    |
| ---- | -------------- | ---- | ----- |
| size | [image.Size](js-apis-image.md#size) | 否    | 缩略图尺寸。 |

**返回值：**

| 类型                            | 说明                    |
| ----------------------------- | --------------------- |
| Promise&lt;[image.PixelMap](js-apis-image.md#pixelmap7)&gt; | Promise对象，返回缩略图的PixelMap。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getThumbnailDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let size = { width: 720, height: 720 };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  console.info('asset displayName = ', asset.displayName);
  asset.getThumbnail(size).then((pixelMap) => {
    console.info('getThumbnail successful ' + pixelMap);
  }).catch((err) => {
    console.error('getThumbnail fail' + err);
  });
}
```

### favorite

favorite(isFavorite: boolean, callback: AsyncCallback&lt;void&gt;): void

将文件设置为收藏文件，使用callback方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                 |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| isFavorite | boolean                   | 是    | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | callback返回void。                              |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.favorite(true, (err) => {
    if (err == undefined) {
      console.info('favorite successfully');
    } else {
      console.error('favorite failed with error:' + err);
    }
  });
}
```

### favorite

favorite(isFavorite: boolean): Promise&lt;void&gt;

将文件设置为收藏文件，使用promise方式返回异步结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| isFavorite | boolean | 是    | 是否设置为收藏文件， true：设置为收藏文件，false：取消收藏。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('favoriteDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.favorite(true).then(function () {
    console.info('favorite successfully');
  }).catch(function (err) {
    console.error('favorite failed with error:' + err);
  });
}
```

### setHidden<sup>10+</sup>

setHidden(hiddenState: boolean, callback: AsyncCallback&lt;void&gt;): void

将文件设置为隐私文件，使用callback方式返回异步结果。

隐私文件存在隐私相册中，对三方应用不开放，用户通过隐私相册去获取隐私文件后可以通过设置hiddenState为false来从隐私相册中移除。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型                        | 必填   | 说明                                 |
| ---------- | ------------------------- | ---- | ---------------------------------- |
| hiddenState | boolean                   | 是    | 是否设置为隐藏文件，true:将文件资产放入隐藏相册;false:从隐藏相册中恢复。 |
| callback   | AsyncCallback&lt;void&gt; | 是    | callback返回void。                              |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)和[通用错误码](../errorcodes/errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('setHiddenDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setHidden(true, (err) => {
    if (err == undefined) {
      console.info('setHidden successfully');
    } else {
      console.error('setHidden failed with error:' + err);
    }
  });
}
```

### setHidden<sup>10+</sup>

setHidden(hiddenState: boolean): Promise&lt;void&gt;

将文件设置为隐私文件，使用promise方式返回异步结果。

隐私文件存在隐私相册中，对三方应用不开放，用户通过隐私相册去获取隐私文件后可以通过设置hiddenState为false来从隐私相册中移除。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名        | 类型      | 必填   | 说明                                 |
| ---------- | ------- | ---- | ---------------------------------- |
| hiddenState | boolean | 是    | 是否设置为隐藏文件，true:将文件资产放入隐藏相册;false:从隐藏相册中恢复。 |

**返回值：**

| 类型                  | 说明         |
| ------------------- | ---------- |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)和[通用错误码](../errorcodes/errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 202   | Called by non-system application.                |
| 13900020   | if parameter is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  // 示例代码为将文件从隐藏相册中恢复，需要先在隐藏相册预置资源
  console.info('setHiddenDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let albumList = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.HIDDEN);
  const album = await albumList.getFirstObject();
  let fetchResult = await album.getPhotoAssets(fetchOption);
  const asset = await fetchResult.getFirstObject();
  asset.setHidden(false).then(() => {
    console.info('setHidden successfully');
  }).catch((err) => {
    console.error('setHidden failed with error:' + err);
  });
}
```

## FetchResult

文件检索结果集。

### getCount

getCount(): number

获取文件检索结果中的文件总数。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型     | 说明       |
| ------ | -------- |
| number | 检索到的文件总数。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getCountDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('fetchCount = ', fetchCount);
}
```

### isAfterLast

isAfterLast(): boolean

检查结果集是否指向最后一行。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型      | 说明                                 |
| ------- | ---------------------------------- |
| boolean | 当读到最后一条记录后，后续没有记录返回true，否则返回false。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  const fetchCount = fetchResult.getCount();
  console.info('count:' + fetchCount);
  let fileAsset = await fetchResult.getLastObject();
  if (fetchResult.isAfterLast()) {
    console.info('fileAsset isAfterLast displayName = ', fileAsset.displayName);
  } else {
    console.info('fileAsset  not isAfterLast ');
  }
}
```

### close

close(): void

释放 FetchFileResult 实例并使其失效。无法调用其他方法。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('fetchResultCloseDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  try {
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    await fetchResult.close();
    console.info('close succeed.');
  } catch (err) {
    console.error('close fail. message = ' + err);
  }
}
```

### getFirstObject

getFirstObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的第一个文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;T&gt; | 是   | 异步获取结果集中的第一个完成后的回调。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getFirstObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err:' + err);
    }
  });
}
```

### getFirstObject

getFirstObject(): Promise&lt;T&gt;

获取文件检索结果中的第一个文件资产。此方法使用promise方式来异步返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise&lt;T&gt; | Promise对象，返回结果集中第一个对象。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getFirstObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getFirstObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getNextObject

 getNextObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的下一个文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名    | 类型                                          | 必填 | 说明                                      |
| --------- | --------------------------------------------- | ---- | ----------------------------------------- |
| callbacke | AsyncCallback&lt;T&gt; | 是   | 异步返回结果集中下一个之后的回调。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (fetchResult.isAfterLast()) {
    fetchResult.getNextObject((err, fileAsset) => {
      if (fileAsset != undefined) {
        console.info('fileAsset displayName: ', fileAsset.displayName);
      } else {
        console.error('fileAsset failed with err: ' + err);
      }
    });
  }
}
```

### getNextObject

 getNextObject(): Promise&lt;T&gt;

获取文件检索结果中的下一个文件资产。此方法使用promise方式来异步返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise对象，返回结果集中下一个对象。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getNextObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  await fetchResult.getFirstObject();
  if (fetchResult.isAfterLast()) {
    let fileAsset = await fetchResult.getNextObject();
    console.info('fileAsset displayName: ', fileAsset.displayName);
  }
}
```

### getLastObject

getLastObject(callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中的最后一个文件资产。此方法使用callback回调来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                        |
| -------- | --------------------------------------------- | ---- | --------------------------- |
| callback | AsyncCallback&lt;T&gt; | 是   | 异步返回结果集中最后一个的回调。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getLastObject((err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err: ' + err);
    }
  });
}
```

### getLastObject

getLastObject(): Promise&lt;T&gt;

获取文件检索结果中的最后一个文件资产。此方法使用Promise方式来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise对象，返回结果集中最后一个对象。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getLastObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getLastObject();
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getPositionObject

getPositionObject(index: number, callback: AsyncCallback&lt;T&gt;): void

获取文件检索结果中具有指定索引的文件资产。此方法使用callback来返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名       | 类型                                       | 必填   | 说明                 |
| -------- | ---------------------------------------- | ---- | ------------------ |
| index    | number                                   | 是    | 要获取的文件的索引，从0开始。     |
| callback | AsyncCallback&lt;T&gt; | 是    | 异步返回指定索引的文件资产的回调。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getPositionObject(0, (err, fileAsset) => {
    if (fileAsset != undefined) {
      console.info('fileAsset displayName: ', fileAsset.displayName);
    } else {
      console.error('fileAsset failed with err: ' + err);
    }
  });
}
```

### getPositionObject

getPositionObject(index: number): Promise&lt;T&gt;

获取文件检索结果中具有指定索引的文件资产。此方法使用Promise形式返回文件Asset。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名    | 类型     | 必填   | 说明             |
| ----- | ------ | ---- | -------------- |
| index | number | 是    | 要获取的文件的索引，从0开始。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;T&gt; | Promise对象，返回结果集中指定索引的一个对象。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type index is not number.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getPositionObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAsset = await fetchResult.getPositionObject(0);
  console.info('fileAsset displayName: ', fileAsset.displayName);
}
```

### getAllObject<sup>10+</sup>

getAllObject(callback: AsyncCallback&lt;Array&lt;T&gt;&gt;): void

获取文件检索结果中的所有文件资产。此方法使用callback形式返回结果。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                                          | 必填 | 说明                                        |
| -------- | --------------------------------------------- | ---- | ------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;T&gt;&gt; | 是   | 异步获取结果集中的所有文件资产完成后的回调。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  fetchResult.getAllObject((err, fileAssetList) => {
    if (fileAssetList != undefined) {
      console.info('fileAssetList length: ', fileAssetList.length);
    } else {
      console.error('fileAssetList failed with err:' + err);
    }
  });
}
```

### getAllObject<sup>10+</sup>

getAllObject(): Promise&lt;Array&lt;T&gt;&gt;

获取文件检索结果中的所有文件资产。此方法使用promise方式来异步返回。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                                    | 说明                       |
| --------------------------------------- | -------------------------- |
| Promise&lt;Array&lt;T&gt;&gt; | Promise对象，返回结果集中所有文件资产数组。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('getAllObjectDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  let fetchResult = await mgr.getPhotoAssets(fetchOption);
  let fileAssetList = await fetchResult.getAllObject();
  console.info('fileAssetList length: ', fileAssetList.length);
}
```

## Album

实体相册

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 可读   | 可写  | 说明   |
| ------------ | ------ | ---- | ---- | ------- |
| albumType<sup>10+</sup> | [AlbumType]( #albumtype10) | 是    | 否    | 相册类型。    |
| albumSubType<sup>10+</sup> | [AlbumSubType]( #albumsubtype10) | 是    | 否   | 相册子类型。    |
| albumName | string | 是    | 用户相册可写，预置相册不可写   | 相册名称。    |
| albumUri | string | 是    | 否    | 相册Uri。   |
| count | number | 是    | 否    |  相册中文件数量。 |
| coverUri | string | 是    | 用户相册可写，预置相册不可写	    | 封面文件Uri。 |

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取相册中的文件。该方法使用callback形式来返回文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoCallback');

  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption, (err, albumFetchResult) => {
    if (albumFetchResult != undefined) {
      console.info('album getPhotoAssets successfully, getCount: ' + albumFetchResult.getCount());
    } else {
      console.error('album getPhotoAssets failed with error: ' + err);
    }
  });
}
```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取相册中的文件。该方法使用Promise来返回文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | Promise对象，返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumGetFileAssetsDemoPromise');

  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.getPhotoAssets(fetchOption).then((albumFetchResult) => {
    console.info('album getFileAssets successfully, getCount: ' + albumFetchResult.getCount());
  }).catch((err) => {
    console.error('album getFileAssets failed with error: ' + err);
  });
}
```

### commitModify

commitModify(callback: AsyncCallback&lt;void&gt;): void;

更新相册属性修改到数据库中。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  const albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  const album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify((err) => {
    if (err != undefined) {
      console.error('commitModify failed with error: ' + err);
    } else {
      console.info('commitModify successfully');
    }
  });
}
```

### commitModify

commitModify(): Promise&lt;void&gt;;

更新相册属性修改到数据库中。该方法使用Promise来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**返回值：**

| 类型                  | 说明           |
| ------------------- | ------------ |
| Promise&lt;void&gt; | Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('albumCommitModifyDemo');
  let predicates = new dataSharePredicates.DataSharePredicates();
  let albumFetchOptions = {
    predicates: predicates
  };
  try {
    var albumList = await mgr.getPhotoAlbums(albumFetchOptions);
  } catch (err) {
    console.error('getPhotoAlbums failed. message = ', err);
  }
  const album = await albumList.getFirstObject();
  album.albumName = 'hello';
  album.commitModify().then(() => {
    console.info('commitModify successfully');
  }).catch((err) => {
    console.error('commitModify failed with error: ' + err);
  });
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

往相册中添加图片或者视频，需要先预置相册和文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 待添加到相册中的图片或视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('addPhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album addPhotoAssets successfully');
      } else {
        console.error('album addPhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### addPhotoAssets<sup>10+</sup>

addPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

往相册中添加图片或者视频，需要先预置相册和文件资源。该方法使用Promise来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 待添加到相册中的图片或视频数组。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('addPhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await mgr.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.addPhotoAssets([asset]).then(() => {
      console.info('album addPhotoAssets successfully');
    }).catch((err) => {
      console.error('album addPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('addPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

从相册中移除图片或者视频，需要先预置相册和文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 相册中待移除的图片或视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('removePhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album removePhotoAssets successfully');
      } else {
        console.error('album removePhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### removePhotoAssets<sup>10+</sup>

removePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

从相册中移除图片或者视频，需要先预置相册和文件资源。该方法使用Promise来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 相册中待移除的图片或视频数组。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('removePhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.USER, userFileManager.AlbumSubType.USER_GENERIC);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.removePhotoAssets([asset]).then(() => {
      console.info('album removePhotoAssets successfully');
    }).catch((err) => {
      console.error('album removePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('removePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

从回收站中恢复图片或者视频，需要先在回收站中预置文件资源。该方法使用callback形式来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 回收站中待恢复图片或者视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('recoverPhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album recoverPhotoAssets successfully');
      } else {
        console.error('album recoverPhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### recoverPhotoAssets<sup>10+</sup>

recoverPhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

从回收站中恢复图片或者视频，需要先在回收站中预置文件资源。该方法使用Promise来返回结果。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 回收站中待恢复图片或者视频数组。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('recoverPhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.recoverPhotoAssets([asset]).then(() => {
      console.info('album recoverPhotoAssets successfully');
    }).catch((err) => {
      console.error('album recoverPhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('recoverPhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;, callback: AsyncCallback&lt;void&gt;): void;

从回收站中彻底删除图片或者视频，需要先在回收站中预置文件资源。该方法使用callback形式来返回结果。

**注意**：此操作不可逆，执行此操作后文件资源将彻底删除，请谨慎操作。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 回收站中待彻底删除图片或者视频数组。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('deletePhotoAssetsDemoCallback');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset], (err) => {
      if (err === undefined) {
        console.info('album deletePhotoAssets successfully');
      } else {
        console.error('album deletePhotoAssets failed with error: ' + err);
      }
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoCallback failed with error: ' + err);
  }
}
```

### deletePhotoAssets<sup>10+</sup>

deletePhotoAssets(assets: Array&lt;FileAsset&gt;): Promise&lt;void&gt;;

从回收站中彻底删除图片或者视频，需要先在回收站中预置文件资源。该方法使用Promise来返回结果。

**注意**：此操作不可逆，执行此操作后文件资源将彻底删除，请谨慎操作。

**需要权限**：ohos.permission.WRITE_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| assets | Array&lt;[FileAsset](#fileasset)&gt; | 是   | 回收站中待彻底删除图片或者视频数组。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
|Promise&lt;void&gt; | Promise对象，返回void。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if PhotoAssets is invalid.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  try {
    console.info('deletePhotoAssetsDemoPromise');
    let predicates = new dataSharePredicates.DataSharePredicates();
    let fetchOption = {
      fetchColumns: [],
      predicates: predicates
    };
    let albumFetchResult = await mgr.getAlbums(userFileManager.AlbumType.SYSTEM, userFileManager.AlbumSubType.TRASH);
    let album = await albumFetchResult.getFirstObject();
    let fetchResult = await album.getPhotoAssets(fetchOption);
    let asset = await fetchResult.getFirstObject();
    album.deletePhotoAssets([asset]).then(() => {
      console.info('album deletePhotoAssets successfully');
    }).catch((err) => {
      console.error('album deletePhotoAssets failed with error: ' + err);
    });
  } catch (err) {
    console.error('deletePhotoAssetsDemoPromise failed with error: ' + err);
  }
}
```

## PrivateAlbum

系统相册。

### 属性

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称           | 类型    | 可读   | 可写   | 说明      |
| ------------ | ------ | ---- | ---- | ------- |
| albumName | string | 是    | 是    | 相册名称。    |
| albumUri | string | 是    | 否    | 相册Uri。   |
| dateModified | number | 是    | 否    | 修改日期。    |
| count | number | 是    | 否    | 相册中文件数量。 |
| coverUri | string | 是    | 否    | 封面文件Uri。 |

### getPhotoAssets

getPhotoAssets(options: FetchOptions, callback: AsyncCallback&lt;FetchResult&lt;FileAsset&gt;&gt;): void;

获取系统相册中的文件。该方法使用callback形式来返回文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |
| callback | AsyncCallback&lt;[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;&gt; | 是   | callback返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  trashAlbum.getPhotoAssets(fetchOption, (err, fetchResult) => {
    if (fetchResult != undefined) {
      let count = fetchResult.getCount();
      console.info('fetchResult.count = ', count);
    } else {
      console.error('getFileAssets failed, message = ', err);
    }
  });
}

```

### getPhotoAssets

getPhotoAssets(options: FetchOptions): Promise&lt;FetchResult&lt;FileAsset&gt;&gt;;

获取系统相册中的文件。该方法使用Promise来返回文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| options | [FetchOptions](#fetchoptions) | 是   | 检索选项。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise:[FetchResult](#fetchresult)&lt;[FileAsset](#fileasset)&gt;| Promise对象，返回图片和视频数据结果集。 |

**错误码：**

接口抛出错误码的详细介绍请参见[文件管理错误码](../errorcodes/errorcode-filemanagement.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------------------- |
| 13900020   | if type options is not FetchOptions.         |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumGetFileAssetsDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  let count = fetchResult.getCount();
  console.info('fetchResult.count = ', count);
}
```

### delete

delete(uri: string, callback: AsyncCallback&lt;void&gt;): void;

删除系统相册中的文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumDeleteCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri, (err) => {
    if (err != undefined) {
      console.error('trashAlbum.delete failed, message = ', err);
    } else {
      console.info('trashAlbum.delete successfully');
    }
  });
}
```

### delete

delete(uri: string): Promise&lt;void&gt;;

删除系统相册中的文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumDeleteDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let deleteFileUri = fileAsset.uri;
  trashAlbum.delete(deleteFileUri).then(() => {
    console.info('trashAlbum.delete successfully');
  }).catch((err) => {
    console.error('trashAlbum.delete failed, message = ', err);
  });
}   
```

### recover

recover(uri: string, callback: AsyncCallback&lt;void&gt;): void;

恢复系统相册中的文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri。 |
| callback | AsyncCallback&lt;void&gt; | 是   | callback返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumRecoverDemoCallback');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let recoverFileUri = fileAsset.uri;
  trashAlbum.recover(recoverFileUri, (err) => {
    if (err != undefined) {
      console.error('trashAlbum.recover failed, message = ', err);
    } else {
      console.info('trashAlbum.recover successfully');
    }
  });
}
```

### recover

recover(uri: string): Promise&lt;void&gt;;

恢复系统相册中的文件。

**需要权限**：ohos.permission.READ_IMAGEVIDEO 和 ohos.permission.WRITE_IMAGEVIDEO 或 ohos.permission.READ_AUDIO 和 ohos.permission.WRITE_AUDIO

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

**参数：**

| 参数名   | 类型                      | 必填 | 说明       |
| -------- | ------------------------- | ---- | ---------- |
| uri | string | 是   | 相册uri。 |

**返回值：**

| 类型                                    | 说明              |
| --------------------------------------- | ----------------- |
| Promise&lt;void&gt;| Promise对象，返回void。 |

**示例：**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

async function example() {
  console.info('privateAlbumRecoverDemoPromise');
  let albumList = await mgr.getPrivateAlbum(userFileManager.PrivateAlbumType.TYPE_TRASH);
  let predicates = new dataSharePredicates.DataSharePredicates();
  let fetchOption = {
    fetchColumns: [],
    predicates: predicates
  };
  const trashAlbum = await albumList.getFirstObject();
  let fetchResult = await trashAlbum.getPhotoAssets(fetchOption);
  const fileAsset = await fetchResult.getFirstObject();
  let recoverFileUri = fileAsset.uri;
  trashAlbum.recover(recoverFileUri).then(() => {
    console.info('trashAlbum.recover successfully');
  }).catch((err) => {
    console.error('trashAlbum.recover failed, message = ', err);
  });
}
```

## MemberType

成员类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  类型 |  可读  |  可写  |  说明  |
| ----- |  ---- |  ---- |  ---- |  ---- |
| number |  number | 是 | 是 | number类型。 |
| string |  string | 是 | 是 | string类型。|
| boolean |  boolean | 是 | 是 | boolean类型。 |

## ChangeEvent

变更监听的媒体文件类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  类型 |  可读  |  可写  |  说明 |
| ----- |  ---- |  ---- |  ---- |  ---- |
| deviceChange |  string | 是 | 是 |  设备。 |
| albumChange |  string | 是 | 是 |  相册。 |
| imageChange |  string | 是 | 是 |  图片。 |
| audioChange |  string | 是 | 是 |  音频。 |
| videoChange |  string | 是 | 是 |  视频。 |
| remoteFileChange |  string | 是 | 是 |  远程文件。 |

## PeerInfo

注册设备的信息。

**系统能力**：SystemCapability.FileManagement.UserFileManager.DistributedCore

| 名称       | 类型                       | 可读 | 可写 | 说明             |
| ---------- | -------------------------- | ---- | ---- | ---------------- |
| deviceName | string                     | 是   | 否   | 注册设备的名称。   |
| networkId  | string                     | 是   | 否   | 注册设备的网络ID。 |
| isOnline   | boolean                    | 是   | 否   | 是否在线。         |

## FileType

枚举，媒体文件类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| IMAGE |  1 |  图片。 |
| VIDEO |  2 |  视频。 |
| AUDIO |  3 |  音频。 |

## PhotoSubType<sup>10+</sup>

枚举，不同[FileAsset](#fileasset)的类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| DEFAULT |  0 |  默认照片类型。 |
| SCREENSHOT |  1 |  截屏录屏文件类型。 |
| CAMERA |  2 |  相机拍摄的照片和视频类型。 |

## PositionType<sup>10+</sup>

枚举，文件位置，表示文件在本地或云端。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| LOCAL |  1 |  文件只存在于本端设备。 |
| CLOUD |  2 |  文件只存在于云端。 |
| BOTH |  3 |  文件在本地和云中都存在。 |

## AlbumType<sup>10+</sup>

枚举，相册类型，表示是用户相册还是系统预置相册。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| USER |  0 |  用户相册。 |
| SYSTEM |  1024 |  系统预置相册。 |

## AlbumSubType<sup>10+</sup>

枚举，相册子类型，表示具体的相册类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称  |  值 |  说明 |
| ----- |  ---- |  ---- |
| USER_GENERIC |  1 |  用户相册。 |
| FAVORITE |  1025 |  收藏夹。 |
| VIDEO |  1026 |  视频相册。 |
| HIDDEN |  1027 |  隐藏相册。 |
| TRASH |  1028 |  回收站。 |
| SCREENSHOT |  1029 |  截屏和录屏相册。 |
| CAMERA |  1030 |  相机拍摄的照片和视频相册。 |
| ANY |  2147483647 |  任意相册。 |

## PrivateAlbumType

枚举，系统相册类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称    |  值 |   说明   |
| -----   |  ----  |   ----  |
| TYPE_FAVORITE |  0 |  收藏夹相册。 |
| TYPE_TRASH |  1 |  回收站相册。 |

## AudioKey

枚举，音频文件关键信息。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称          |   值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri。                                                   |
| DISPLAY_NAME  | display_name        | 显示名字。                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间距1970年1月1日的秒数值）。             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |
| TITLE         | title               | 文件标题。                                                   |
| ARTIST        | artist              | 作者。                                                   |
| AUDIOALBUM    | audio_album         | 专辑。                                                   |
| DURATION      | duration            | 持续时间（单位：毫秒）。                                    |
| FAVORITE      | favorite            | 收藏。                                                   |

## ImageVideoKey

枚举，图片和视频文件关键信息。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 文件uri。                                                   |
| FILE_TYPE     | file_type           | 媒体文件类型。                                              |
| DISPLAY_NAME  | display_name        | 显示名字。                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间距1970年1月1日的秒数值）。             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |
| TITLE         | title               | 文件标题。                                                   |
| DURATION      | duration            | 持续时间（单位：毫秒）。                                    |
| WIDTH         | width               | 图片宽度（单位：像素）。                                    |
| HEIGHT        | height              | 图片高度（单位：像素）。                                      |
| DATE_TAKEN    | date_taken          | 拍摄日期（文件拍照时间距1970年1月1日的秒数值）。                |
| ORIENTATION   | orientation         | 图片文件的方向。                                             |
| FAVORITE      | favorite            | 收藏。                                                    |
| POSITION<sup>10+</sup>  | position            | 文件位置类型。                               |
| DATE_TRASHED<sup>10+</sup>  | date_trashed  | 删除日期（删除文件时间距1970年1月1日的秒数值）。                 |
| HIDDEN<sup>10+</sup>  | hidden            | 文件的隐藏状态。                               |

## AlbumKey

枚举，相册关键信息。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称          | 值              | 说明                                                       |
| ------------- | ------------------- | ---------------------------------------------------------- |
| URI           | uri                 | 相册uri。                                                   |
| FILE_TYPE     | file_type           | 媒体文件类型。                                              |
| ALBUM_NAME    | album_name          | 相册名字。                                                   |
| DATE_ADDED    | date_added          | 添加日期（添加文件时间距1970年1月1日的秒数值）。             |
| DATE_MODIFIED | date_modified       | 修改日期（修改文件时间距1970年1月1日的秒数值，修改文件名不会改变此值，当文件内容发生修改时才会更新）。 |

## PhotoCreateOptions<sup>10+</sup>

图片或视频的创建选项。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 必填 | 说明                                              |
| ---------------------- | ------------------- | ---- | ------------------------------------------------ |
| subType           | [PhotoSubType](#photosubtype10) | 否  | 图片或者视频的子类型。  |

## FetchOptions

检索条件。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 可读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| fetchColumns           | Array&lt;string&gt; | 是   | 是   | 检索条件，指定列名查询，如果该参数为空时默认查询uri、name、fileType（具体字段名称以检索对象定义为准）。示例：<br />fetchColumns: ['uri', 'title']。 |
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | 是   | 是   | 谓词查询，显示过滤条件。 |

## AlbumFetchOptions

相册检索条件。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                   | 类型                | 可读 | 可写 | 说明                                              |
| ---------------------- | ------------------- | ---- |---- | ------------------------------------------------ |
| predicates           | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md) | 是   | 是   | 谓词查询，显示过滤条件。 |

## ChangeData<sup>10+</sup>

监听器回调函数的值。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称    | 类型                        | 可读 | 可写 | 说明                                                         |
| ------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| type    | [NotifyType](#notifytype10) | 是   | 否   | ChangeData的通知类型。                                       |
| uris    | Array&lt;string&gt;         | 是   | 否   | 相同[NotifyType](#notifytype10)的所有uri，可以是FileAsset或Album。 |
| subUris | Array&lt;string&gt;         | 是   | 否   | 相册中变动文件的uri数组。                                    |

## NotifyType<sup>10+</sup>

枚举，通知事件的类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称                      | 值   | 说明                             |
| ------------------------- | ---- | -------------------------------- |
| NOTIFY_ADD                | 0    | 添加文件集或相册通知的类型。     |
| NOTIFY_UPDATE             | 1    | 文件集或相册的更新通知类型。     |
| NOTIFY_REMOVE             | 2    | 删除文件集或相册的通知类型。     |
| NOTIFY_ALBUM_ADD_ASSET    | 3    | 在相册中添加的文件集的通知类型。 |
| NOTIFY_ALBUM_REMOVE_ASSET | 4    | 在相册中删除的文件集的通知类型。 |

## DefaultChangeUri<sup>10+</sup>

枚举，DefaultChangeUri子类型。

**系统能力**：SystemCapability.FileManagement.UserFileManager.Core

| 名称              | 值                      | 说明                                                         |
| ----------------- | ----------------------- | ------------------------------------------------------------ |
| DEFAULT_PHOTO_URI | file://media/Photo      | 默认PhotoAsset的Uri，与forSubUri{true}一起使用，将接收所有PhotoAsset的更改通知。 |
| DEFAULT_ALBUM_URI | file://media/PhotoAlbum | 默认相册的Uri，与forSubUri{true}一起使用，将接收所有相册的更改通知。 |
| DEFAULT_AUDIO_URI | file://media/Audio      | 默认AudioAsset的Uri，与forSubUri{true}一起使用，将接收所有AudioAsset的更改通知。 |

